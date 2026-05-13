#include "common.h"

u32 func_801C6E80(void) {
    return LeoDriveExist();
}

void func_801C6EA0(Gfx** gfxP) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C776C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C77B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C77C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C77F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C786C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C78D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C79A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C70FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C79DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7B28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7CB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7E94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C81AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C81E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C8214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C82C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C8304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C8310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C843C.s")

s32 func_801C84E0(s32 arg0) {
    s32 sp1C;

    if (LeoLBAToByte(arg0, 1U, &sp1C) == 0) {
        return sp1C;
    }
    return 0;
}

void func_801C7C1C(void* arg0, s32 arg1, s32 arg2) {
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    void* sp34;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    func_801C7898();
    func_801C77F0();
    D_801DA638 = 1;
    D_801DA640 = 0;
    func_801C843C(arg1, &sp44, &sp3C);
    func_801C843C(arg1 + arg2, &sp40, &sp38);
    sp34 = D_801D36D0;
    if (sp44 == sp40) {
        func_801C8214(sp44, sp34, func_801C84E0(sp44));
        bcopy((char*)sp34 + sp3C, arg0, arg2);
    } else {
        var_s1 = 0;
        func_801C8214(sp44, sp34, func_801C84E0(sp44));
        bcopy((char*)sp34 + sp3C, arg0, func_801C84E0(sp44) - sp3C);
        temp_v0 = sp44 + 1;
        if (temp_v0 < sp40) {
            var_s0 = temp_v0;
            if (temp_v0 < sp40) {
                do {
                    var_s1 += func_801C84E0(var_s0);
                    var_s0 += 1;
                } while (var_s0 < sp40);
            }
            func_801C8214(sp44 + 1, (void*)((func_801C84E0(sp44) + (s32)arg0) - sp3C), var_s1);
        }
        if (sp38 > 0) {
            func_801C8214(sp40, sp34, func_801C84E0(sp40));
            bcopy(sp34, (void*)(((func_801C84E0(sp44) + (s32)arg0) - sp3C) + var_s1), sp38);
        }
    }
    func_801C7B28();
    func_801C78D8();
    func_801C7838();
}

void func_801C7E78(void) {
}

s32 func_801C86F8(void) {
    s32 sp24;
    s32 sp20;
    s32 pad;
    void* sp18;

    if (D_801DA5C8 != NULL) {
        return -1;
    }
    D_801DA5C8 = &D_801DA4B0;
    func_801C7C1C(D_801DA5C8, 0x1060, sizeof(*D_801DA5C8));
    sp24 = D_801DA5C8->unk4 - D_801DA5C8->unk0;
    sp20 = (char*)D_801DA5C8->unkC - (char*)D_801DA5C8->unk8;
    sp18 = (char*)D_801DA5C8->unk8 + sp24;
    func_801C7C1C(D_801DA5C8->unk8, D_801DA5C8->unk0, sp24);
    bzero(sp18, sp20 - sp24);
    func_800AD4C0(D_801DA5C8->unk10);
    return 0;
}

s32 func_801C879C(void) {
    if (D_801DA5C8 == NULL) {
        return -1;
    }
    func_800AD51C();
    bzero(D_801DA5C8->unk8, (char*)D_801DA5C8->unkC - (char*)D_801DA5C8->unk8);
    bzero(D_801DA5C8, sizeof(*D_801DA5C8));
    D_801DA5C8 = NULL;
    return 0;
}

void n64dd_SetDiskVersion(s32 arg0) {
    if (arg0 != 0) {
        if (D_801DA5C8 == 0) {
            func_801C86F8();
        }
    } else if (D_801DA5C8 != 0) {
        func_801C879C();
    }
}
