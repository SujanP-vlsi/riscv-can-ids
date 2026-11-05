OUTPUT_ARCH("riscv")
ENTRY(_start)

MEMORY
{
  sram (rwx) : ORIGIN = 0x00000000, LENGTH = 64K
}

SECTIONS
{
  .text : {
    *(.text.start)
    *(.text*)
  } > sram

  .rodata : {
    *(.rodata*)
  } > sram

  .data : {
    *(.data*)
  } > sram

  .bss : {
    *(.bss*)
    *(COMMON)
  } > sram

  _stack_top = ORIGIN(sram) + LENGTH(sram);
}
