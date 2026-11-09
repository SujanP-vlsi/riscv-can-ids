#ifndef SIMD_MAC_H
#define SIMD_MAC_H

#include <stdint.h>

#ifdef __riscv
static inline int32_t asm_simd_mac(uint32_t val1, uint32_t val2) {
    int32_t result;
    __asm__ __volatile__ (
        ".insn r 0x0B, 0x0, 0x00, %0, %1, %2\n\t"
        : "=r" (result)
        : "r" (val1), "r" (val2)
    );
    return result;
}
#endif

#endif // SIMD_MAC_H
