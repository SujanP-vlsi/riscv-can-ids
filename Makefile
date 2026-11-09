PREFIX  ?= riscv-none-elf-
CC      := $(PREFIX)gcc
OBJCOPY := $(PREFIX)objcopy
OBJDUMP := $(PREFIX)objdump
SIZE    := $(PREFIX)size

VERILATOR := verilator

CFLAGS  := -O2 -march=rv32i -mabi=ilp32 -ffreestanding -nostdlib
LDFLAGS := -T sw/link.ld -nostdlib

SRCS    := sw/crt0.S sw/main.c
OBJS    := sw/crt0.o sw/main.o
ELF     := sw/firmware.elf
HEX     := sw/firmware.hex
DIS     := sw/firmware.dis

SIM_DIR := sim
SIM_SV  := $(abspath $(SIM_DIR)/tb_top.sv)
SIM_CPP := $(abspath $(SIM_DIR)/tb_top.cpp)

all: $(HEX) $(DIS) size

sw/crt0.o: sw/crt0.S
	$(CC) $(CFLAGS) -c $< -o $@

sw/main.o: sw/main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ELF): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(HEX): $(ELF)
	$(OBJCOPY) -O verilog $< $@

$(DIS): $(ELF)
	$(OBJDUMP) -d $< > $@

size: $(ELF)
	$(SIZE) $<

sim-build: $(HEX)
	$(VERILATOR) --trace -Wall -Wno-UNUSEDSIGNAL -Wno-UNDRIVEN --cc $(SIM_SV) --exe $(SIM_CPP) --Mdir sim/obj_dir -o Vtb_top
	make -C sim/obj_dir -f Vtb_top.mk Vtb_top

sim: sim-build
	./sim/obj_dir/Vtb_top

clean:
	rm -f sw/*.o sw/*.elf sw/*.hex sw/*.dis sim/*.vcd setup_fix.py
	rm -rf sim/obj_dir

.PHONY: all clean size sim-build sim
