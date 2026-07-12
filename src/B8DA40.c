#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/B8DA40/func_801CA3E0.s")

s32 func_801CA4B8(void) {
    return gCurrentRegion == 1 ? 0 : 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8DA40/func_801CA4E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8DA40/func_801CA514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8DA40/func_801CA544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8DA40/func_801CA5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8DA40/func_801CA628.s")

void* func_801CA698(s32 arg0) {
    func_801CA730();
    if (arg0 == 0x29) {
        return (func_801CA4B8() * 0x600) + (char*)&D_801D3860;
    }
    if (((arg0 >= 0x25) && (arg0 < 0x29)) || (arg0 == 0x1F) || (arg0 == 0x20)) {
        return &D_801E1800;
    } else {
        func_801CA628(&D_801E1800, arg0);
        return &D_801E1800;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8DA40/func_801CA730.s")

void func_801CA764(void* arg0, s32 arg1, s32 arg2) {
    s32 var_s0;

    for (var_s0 = 0; var_s0 < arg2; var_s0++) {
        func_801CA280(arg0, 0x140, D_801D3760[func_801CA4B8()][arg1][var_s0]);
        arg0 = (char*)arg0 + 0xA00;
        if (1) {}
    }
}

void* func_801CA800(s32 arg0) {
    func_801CA86C();
    if (arg0 == 3) {
        return (func_801CA4B8() * 0x2800) + (char*)&D_801D4460;
    }
    func_801CA764(&D_801E1E00, arg0, 4);
    return &D_801E1E00;
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8DA40/func_801CA86C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8DA40/func_801CA8A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8DA40/func_801CA8E0.s")
