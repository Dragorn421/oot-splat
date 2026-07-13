#include "common.h"

int func_801C9CB0(char* arg0) {
    if (((*arg0 >= 0x8E) && (*arg0 < 0xFF)) || ((*arg0 != 0x8F) && (*arg0 != 0xA0))) {
        arg0++;
        return (*arg0 >= 0xA0) && (*arg0 < 0xFF);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8D310/func_801C9D04.s")

void func_801C9D68(char* arg0, u16 arg1) {
    arg0[0] = arg1 >> 8;
    arg0[1] = arg1 & 0xFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8D310/func_801C9D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8D310/func_801C9DA4.s")

void func_801C9E30(void* arg0, uintptr_t arg1, size_t arg2) {
    if (D_801D3740 != NULL) {
        D_801D3740(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8D310/func_801C9E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8D310/func_801C9EAC.s")

s32 func_801C9F0C(void* arg0, s32* arg1, s32* arg2, s32* arg3, char* arg4) {
    s32 sp24;
    s32 var_v1;

    if (func_801C9CB0(arg4) != 0) {
        sp24 = func_801C9E60(arg4);
        *arg1 = 0x10;
        var_v1 = 0;
        *arg2 = 0x10;
        *arg3 = 0xB;
    } else {
        var_v1 = func_801C9EAC(&sp24, arg1, arg2, arg3, *arg4);
    }
    func_801C9E30(arg0, sp24, 0x80);
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8D310/func_801C9FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8D310/func_801C9FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8D310/func_801CA034.s")

void func_801CA1C4(char* arg0, s32* arg1, s32* arg2) {
    char v1, v2;

    if (func_801C9CB0(arg0) != 0) {
        *arg2 = 0;
        *arg1 = 0;
        return;
    }
    *arg2 = 0;
    *arg1 = 0;
    v1 = arg0[-1];
    v2 = arg0[1];
    switch ((u8)arg0[0]) {
        case 0x20:
            *arg2 = 0;
            *arg1 = 0;
            break;
        case 0x49:
        case 0x69:
            *arg2 = 2;
            if (1) {}
            *arg1 = 2;
            *arg2 = 2;
            if (v1 == 0x20) {
                *arg1 = 0;
            }
            if (v2 == 0x20) {
                *arg2 = 0;
            }
            break;
        default:
            *arg2 = 1;
            if (1) {}
            *arg1 = 1;
            *arg2 = 1;
            break;
    }
}

// unknown sp construct
#pragma GLOBAL_ASM("asm/nonmatchings/B8D310/func_801CA280.s")

void func_801CA3C0(s32 arg0, void (*arg1)(void*, uintptr_t, size_t)) {
    D_801E17F0 = arg0;
    D_801D3740 = arg1;
}
