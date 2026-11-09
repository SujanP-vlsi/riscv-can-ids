module simd_mac_unit (
    input  wire [31:0] operand_a,
    input  wire [31:0] operand_b,
    output wire [31:0] mac_result
);
    wire signed [7:0] a0 = operand_a[7:0];
    wire signed [7:0] a1 = operand_a[15:8];
    wire signed [7:0] a2 = operand_a[23:16];
    wire signed [7:0] a3 = operand_a[31:24];

    wire signed [7:0] b0 = operand_b[7:0];
    wire signed [7:0] b1 = operand_b[15:8];
    wire signed [7:0] b2 = operand_b[23:16];
    wire signed [7:0] b3 = operand_b[31:24];

    wire signed [31:0] p0 = a0 * b0;
    wire signed [31:0] p1 = a1 * b1;
    wire signed [31:0] p2 = a2 * b2;
    wire signed [31:0] p3 = a3 * b3;

    assign mac_result = p0 + p1 + p2 + p3;
endmodule
