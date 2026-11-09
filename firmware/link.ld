OUTPUT_ARCH( "riscv" )
ENTRY(_start)

MEMORY
{
  bram (rx) : ORIGIN = 0x00000000, LENGTH = 64K
  ram  (rw) : ORIGIN = 0x00008000, LENGTH = 32K
}

SECTIONS
{
  .text : {
    *(.text._start)
    *(.text*)
  } > bram

  .rodata : {
    *(.rodata*)
  } > bram

  .data : {
    *(.data*)
  } > ram

  .bss : {
    __bss_start = .;
    *(.bss*)
    __bss_end = .;
  } > ram

  _stack_top = ORIGIN(ram) + LENGTH(ram);
}
