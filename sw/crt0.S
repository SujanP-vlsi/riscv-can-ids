.section .text._start
.global _start

_start:
    la sp, _stack_top
    jal main
1:  j 1b
