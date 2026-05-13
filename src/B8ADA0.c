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

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C84E0.s")

#ifdef NON_MATCHING
void func_801C7C1C(void* dest, s32 offset, s32 size) {
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    void* sp34;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s1;

    func_801C7898();
    func_801C77F0();
    D_801DA638 = 1;
    D_801DA640.unk0 = 0;
    D_801DA640.unk4 = 0;
    func_801C843C(offset, &sp44, &sp3C);
    func_801C843C(offset + size, &sp40, &sp38);
    sp34 = D_801D36D0;
    if (sp44 == sp40) {
        func_801C8214(sp44, sp34, func_801C84E0(sp44));
        bcopy((char*)sp34 + sp3C, dest, size);
    } else {
        var_s1 = 0;
        func_801C8214(sp44, sp34, func_801C84E0(sp44));
        bcopy((char*)sp34 + sp3C, dest, func_801C84E0(sp44) - sp3C);
        temp_v0 = sp44 + 1;
        if (temp_v0 < sp40) {
            var_s0 = temp_v0;
            if (temp_v0 < sp40) {
                do {
                    temp_v0_2 = func_801C84E0(var_s0);
                    var_s0 += 1;
                    var_s1 += temp_v0_2;
                } while (var_s0 < sp40);
            }
            func_801C8214(sp44 + 1, (void*)((func_801C84E0(sp44) + (s32)dest) - sp3C), var_s1);
        }
        if (sp38 > 0) {
            func_801C8214(sp40, sp34, func_801C84E0(sp40));
            bcopy(sp34, (void*)(((func_801C84E0(sp44) + (s32)dest) - sp3C) + var_s1), sp38);
        }
    }
    func_801C7B28();
    func_801C78D8();
    func_801C7838();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C7C1C.s")
#endif

void func_801C7E78(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C86F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/func_801C879C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8ADA0/n64dd_SetDiskVersion.s")
