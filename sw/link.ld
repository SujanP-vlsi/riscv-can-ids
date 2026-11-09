OUTPUT_ARCH("riscv")
ENTRY(_start)

MEMORY
{
  ram (rwx) : ORIGIN = 0x00000000, LENGTH = 0x4000
}

SECTIONS
{
  .text : {
    *(.text._start)
    *(.text*)
  } > ram

  .rodata : {
    *(.rodata*)
  } > ram

  .data : {
    *(.data*)
  } > ram

  .bss : {
    *(.bss*)
  } > ram

  _stack_top = ORIGIN(ram) + LENGTH(ram);
}
