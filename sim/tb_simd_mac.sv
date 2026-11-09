`timescale 1ns/1ps

module tb_simd_mac;

    logic [31:0] operand_a;
    logic [31:0] operand_b;
    logic [31:0] result;

    // Instantiate DUT
    simd_mac_unit dut (
        .operand_a_i (operand_a),
        .operand_b_i (operand_b),
        .result_o    (result)
    );

    int errors = 0;

    // Function calculating expected software sum
    function automatic logic signed [31:0] ref_simd_mac(input logic [31:0] a, input logic [31:0] b);
        logic signed [7:0]  a_b[4];
        logic signed [7:0]  b_b[4];
        logic signed [31:0] sum;
        sum = 0;
        for (int k = 0; k < 4; k++) begin
            a_b[k] = $signed(a[8*k +: 8]);
            b_b[k] = $signed(b[8*k +: 8]);
            sum = sum + (a_b[k] * b_b[k]);
        end
        return sum;
    endfunction

    initial begin
        $display("==========================================================================");
        $display("   PHASE 2 / TRACK B: SIMD MAC HARDWARE EXECUTION UNIT RTL TESTBENCH     ");
        $display("==========================================================================");

        // Test 1: Known Vector Test
        // Vector A: [10, -5, 20,  2]  -> 0x0A, 0xFB, 0x14, 0x02 -> 0x0AFB1402
        // Vector B: [ 3,  4, -2, 12]  -> 0x03, 0x04, 0xFE, 0x0C -> 0x0304FE0C
        // Expected: (10*3) + (-5*4) + (20*-2) + (2*12) = 30 - 20 - 40 + 24 = -6
        operand_a = 32'h0AFB1402;
        operand_b = 32'h0304FE0C;
        #10;
        if ($signed(result) === -6) begin
            $display("[PASS Test 1] Known Operands -> Result: %d (Expected: -6)", $signed(result));
        end else begin
            $display("[FAIL Test 1] Result: %d (Expected: -6)", $signed(result));
            errors++;
        end

        // Test 2: Max Positive Bounds
        operand_a = 32'h7F7F7F7F; // [127, 127, 127, 127]
        operand_b = 32'h7F7F7F7F; // [127, 127, 127, 127]
        #10;
        // 4 * (127 * 127) = 64516
        if ($signed(result) === 64516) begin
            $display("[PASS Test 2] Max Bounds -> Result: %d (Expected: 64516)", $signed(result));
        end else begin
            $display("[FAIL Test 2] Result: %d", $signed(result));
            errors++;
        end

        // Test 3: Random Vector Stimulus Sweep
        for (int t = 0; t < 100; t++) begin
            operand_a = $random;
            operand_b = $random;
            #10;
            if (result !== ref_simd_mac(operand_a, operand_b)) begin
                $display("[FAIL Random Test %0d] A=0x%0h B=0x%0h RTL=%d Ref=%d", 
                         t, operand_a, operand_b, $signed(result), ref_simd_mac(operand_a, operand_b));
                errors++;
            end
        end

        $display("--------------------------------------------------------------------------");
        if (errors == 0) begin
            $display("   ALL 102 RTL STIMULUS TESTS PASSED. HARDWARE MAC UNIT VERIFIED.");
        end else begin
            $display("   TEST SUITE FAILED WITH %0d ERRORS.", errors);
        end
        $display("==========================================================================");
        $finish;
    end

endmodule
