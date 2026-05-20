#include "common.h"

s32 func_801C8860(struct_801DA5D0* arg0) {
    s32 temp_v0_2;
    s8 temp_v0;

    switch ((u8)arg0->unk0) {
        case 0:
            if (func_801C90A4() != 0) {
                return 1;
            }
            func_801C8DB4();
            return 0;
        case 1:
            func_801C8DD8(arg0->unk1C, arg0->unk20, arg0->unk24, arg0->unk28, arg0->unk2C);
            return 0;
        case 2:
            func_801C8E98(arg0->unkC, arg0->unk10, arg0->unk14);
            return 0;
        case 3:
            if (func_801C90A4() != 0) {
                return 1;
            }
            func_801C8EEC(arg0->unk18, arg0->unk1C, arg0->unk20, 1);
            return 0;
        case 4:
            if (func_801C90A4() != 0) {
                return 1;
            }
            func_801C8EEC(arg0->unk18, arg0->unk1C, arg0->unk20, 2);
            return 0;
        case 5:
            temp_v0 = func_801C8FD0();
            arg0->unk8 = temp_v0;
            return temp_v0 & 0xFF;
        case 7:
            return func_801C905C();
        case 6:
            return func_801C90A4();
        case 8:
            temp_v0_2 = func_801C9020();
            arg0->unk4 = temp_v0_2;
            return temp_v0_2;
        case 9:
            return func_801C90BC();
        case 10:
            return func_801C9114();
        case 11:
            return func_801C916C();
        case 12:
            D_801D3720 = 0;
            break;
        case 13:
            D_801D3720 = 1;
            break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C89FC.s")

s32 func_801C8A24(void) {
    return D_801D36E0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8A34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8A4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8AF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8C74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8D34.s")

void func_801C8DB4(void) {
    osDestroyThread(&D_801E1630);
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8DD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8E50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8EEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C9020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C905C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C90A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C90BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C9114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C916C.s")
