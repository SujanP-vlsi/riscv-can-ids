PREFIX  ?= riscv-none-elf-
CC      := $(PREFIX)gcc
OBJCOPY := $(PREFIX)objcopy
OBJDUMP := $(PREFIX)objdump
SIZE    := $(PREFIX)size

CFLAGS  := -O2 -march=rv32i -mabi=ilp32 -ffreestanding -nostdlib
LDFLAGS := -T sw/link.ld -nostdlib

SRCS    := sw/crt0.S sw/main.c
OBJS    := sw/crt0.o sw/main.o
ELF     := sw/firmware.elf
HEX     := sw/firmware.hex
DIS     := sw/firmware.dis

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

clean:
	rm -f sw/*.o sw/*.elf sw/*.hex sw/*.dis

.PHONY: all clean size
