#include "common.h"

extern vu16 LEOrw_flags;

void leoRead(void) {
    LEOrw_flags = 0;
    leoRead_common(0x18U);
}

// https://decomp.me/scratch/L0MQ0
#pragma GLOBAL_ASM("asm/nonmatchings/B8FC10/leoRead_common.s")
