#include "common.h"

s32 func_801CA920(s32 arg0, u8* arg1, int* arg2, int* arg3, int* arg4) {
    s32 var_s0;
    OSPiHandle* sp58;
    OSMesgQueue sp40;
    void* sp3C;
    OSIoMesg sp24;

    sp58 = osDriveRomInit();
    if ((arg0 >= 0x20) && (arg0 < 0x7F)) {
        var_s0 = LeoGetAAdr2(D_801D93E0[arg0], arg2, arg3, arg4);
    } else if (arg0 >= 0x8140) {
        var_s0 = LeoGetKAdr(arg0);
        *arg2 = 0x10;
        *arg3 = 0x10;
        *arg4 = 0xB;
    } else {
        return -1;
    }
    osCreateMesgQueue(&sp40, &sp3C, 1);
    // clang-format off
    sp24.hdr.retQueue = &sp40; sp24.devAddr = var_s0 + 0xA0000; sp24.dramAddr = (void*)arg1; sp24.hdr.pri = 0; sp24.size = 0x80;
    // clang-format on
    sp58->transferInfo.cmdType = 2;
    osEPiStartDma(sp58, &sp24, 0);
    osRecvMesg(&sp40, NULL, 1);
    return 0;
}

extern u16 D_801D9C10[];
u16 func_801CAA44(s32 arg0) {
    return D_801D9C10[arg0 & 0xF];
}

void func_801CAA60(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16* arg6, s32 arg7) {
    s32 var_a0;
    s32 var_s0;
    u8* var_s1;
    s32 var_s5;
    s16* var_s2;

    var_s1 = arg0;
    var_s2 = arg6;
    for (var_s5 = 0; var_s5 < arg4; var_s5++) {
        for (var_s0 = 0; var_s0 < arg3; var_s0++) {
            if (!(var_s0 & 1)) {
                var_a0 = (s32)*var_s1 >> 4;
            } else {
                var_a0 = *var_s1 & 0xF;
                var_s1 += 1;
            }
            var_s2[arg1 + (((arg2 - arg5) + var_s5 + 0xB) * arg7) + var_s0] = func_801CAA44(var_a0);
        }
        if (arg3 & 1) {
            var_s1 += 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8DF80/func_801CAB68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8DF80/func_801CAB84.s")

void func_801CABA4(struct_801CAF10* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->unk14 = (u16)arg1;
    arg0->unk16 = (u16)arg2;
    arg0->unk18 = (u16)arg3;
    arg0->unk1A = (u16)arg4;
}

void func_801CABC0(struct_801CAF10* arg0, s16* arg1, s32 arg2, s32 arg3) {
    arg0->unk20 = (s16*)((uintptr_t)arg1 + 0x20000000);
    arg0->unk24 = (u16)arg2;
    arg0->unk26 = (u16)arg3;
    func_801CABA4(arg0, 0, 0, arg2 - 1, arg3 - 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8DF80/func_801CAC24.s")

void func_801CAC3C(struct_801CAF10* arg0, u8 arg1) {
    s32 var_a0;
    int sp48;
    int sp44;
    int sp40;
    s32 var_v0;

    if (arg0->unk1C != 0) {
        var_a0 = (arg0->unk1C << 8) | arg1;
    } else {
        if ((arg1 >= 0x80) && (arg1 < 0x99)) {
            arg0->unk1C = (u8)arg1;
            return;
        }
        var_a0 = arg1;
    }
    arg0->unk1C = 0;
    if (func_801CA920(var_a0, arg0->unk4, &sp48, &sp44, &sp40) == 0) {
        if ((s32)arg0->unk18 < (arg0->unkA + sp48)) {
            arg0->unkA = arg0->unk14;
            if ((s32)arg0->unk1A < arg0->unkC + 0x10) {
                arg0->unkC = arg0->unk16;
            } else {
                arg0->unkC = arg0->unkC + 0x10;
            }
        }
        func_801CAA60(arg0->unk4, arg0->unkA, arg0->unkC, sp48, sp44, sp40, arg0->unk20, (s32)arg0->unk24);
        if (sp48 == 0x10) {
            var_v0 = sp48;
        } else {
            var_v0 = sp48 + 2;
        }
        arg0->unkA += var_v0;
    }
}

void func_801CAD64(struct_801CAF10* arg0, u8 arg1) {
    if ((arg1 >= 0x20) && (arg1 < 0x100)) {
        func_801CAC3C(arg0, arg1);
    } else {
        switch (arg1) {
            case 0:
                break;
            case 0xA:
                arg0->unkC += 0x20;
                FALLTHROUGH;
            case 0xD:
                arg0->unkA = arg0->unk14;
                break;
            case 9:
                do {
                    func_801CAC3C(arg0, 0x20);
                } while ((arg0->unkA - arg0->unk14) % 256);
                break;
        }
    }
}

void func_801CAE2C(struct_801CAF10* arg0, u8* arg1, s32 arg2, s32 arg3) {
    u8* var_s0;
    s32 var_s1;

    var_s0 = arg1;
    for (var_s1 = arg2 * arg3; var_s1 != 0; var_s1--) {
        func_801CAD64(arg0, *var_s0++);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8DF80/func_801CAE88.s")

struct_801CAF10* func_801CAEE0(struct_801CAF10* arg0, u8* arg1, s32 arg2) {
    func_801CAE2C(arg0, arg1, 1, arg2);
    return arg0;
}

void func_801CAF10(struct_801CAF10* arg0) {
    arg0->unk0 = func_801CAEE0;
    arg0->unkA = 0;
    arg0->unkC = 0;
    arg0->unk14 = 0;
    arg0->unk16 = 0;
    arg0->unk18 = 0;
    arg0->unk1A = 0;
    arg0->unk10 = 0;
    arg0->unk1C = 0;
    arg0->unk4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8DF80/func_801CAF48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8DF80/func_801CAF54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8DF80/func_801CAF74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8DF80/D_801D9C10.s")
