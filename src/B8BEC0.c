#include "common.h"

s32 func_801C8860(struct_801DA5D0* arg0) {
    s32 temp_v0_2;
    s8 temp_v0;

    switch (arg0->unk0) {
        case 0:
            if (func_801C90A4() != 0) {
                return 1;
            }
            func_801C8DB4();
            return 0;
        case 1:
            func_801C8DD8(arg0->unk1C_1.unk1C, arg0->unk1C_1.unk20, arg0->unk1C_1.unk24, arg0->unk1C_1.unk28,
                          arg0->unk1C_1.unk2C);
            return 0;
        case 2:
            func_801C8E98(arg0->unkC, arg0->unk10, arg0->unk14);
            return 0;
        case 3:
            if (func_801C90A4() != 0) {
                return 1;
            }
            func_801C8EEC(arg0->unk18, arg0->unk1C_3_4.unk1C, arg0->unk1C_3_4.unk20, 1);
            return 0;
        case 4:
            if (func_801C90A4() != 0) {
                return 1;
            }
            func_801C8EEC(arg0->unk18, arg0->unk1C_3_4.unk1C, arg0->unk1C_3_4.unk20, 2);
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

void func_801C89FC(s32 arg0) {
    if (arg0 != 0) {
        D_801D36E0 = 1;
        return;
    }
    D_801D36E0 = 2;
}

s32 func_801C8A24(void) {
    return D_801D36E0;
}

s32 func_801C8A34(void) {
    return D_801D36E4 == 1;
}

extern OSMesg D_801E1608;
extern OSMesg D_801E1610[8];

void func_801C8A4C(struct_801E1598* arg0) {
    s32 temp_v0;

    osCreateMesgQueue(&arg0->unk1C, &D_801E1608, 1);
    if (gCurrentRegion == 1) {
        arg0->unk68 = LeoCJCreateLeoManager(0x95, 0x96, D_801E1610, 8);
    } else {
        arg0->unk68 = LeoCACreateLeoManager(0x95, 0x96, D_801E1610, 8);
    }
    temp_v0 = arg0->unk68;
    if ((temp_v0 == 0x29) || (temp_v0 == 0)) {
        D_801D36E4 = 1;
    }
}

void func_801C8AF8(struct_801E1598* arg0) {
    LEOCmd sp1C;

    LeoReadDiskID(&sp1C, &arg0->unk38, &arg0->unk1C);
    osRecvMesg(&arg0->unk1C, (OSMesg*)&arg0->unk68, OS_MESG_BLOCK);
}

void func_801C8B40(struct_801E1598* arg0) {
    LEOCmd sp1C;

    LeoSpdlMotor(&sp1C, 4U, &arg0->unk1C);
    osRecvMesg(&arg0->unk1C, (OSMesg*)&arg0->unk68, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8C74.s")

void func_801C8C84(void*);
#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8C84.s")

void func_801C8D34(void* arg0) {
    void* sp24;

    while (true) {
        osRecvMesg(D_801E1590.unk0, &sp24, OS_MESG_BLOCK);
        func_801C8C84(sp24);
        osSendMesg(D_801E1590.unk4, NULL, OS_MESG_BLOCK);
    }
}

void func_801C8DB4(void) {
    osDestroyThread(&D_801E1630);
}

void func_801C8DD8(OSMesgQueue* arg0, OSMesgQueue* arg1, s32 arg2, void* arg3, s32 arg4) {
    D_801E1590.unk0 = arg0;
    D_801E1590.unk4 = arg1;
    osCreateThread(&D_801E1630, arg2, func_801C8D34, NULL, arg3, arg4);
    osStartThread(&D_801E1630);
}

void func_801C8E50(void* arg0, s32 arg1) {
    if (arg1 == 1) {
        func_801C8C84(arg0);
        return;
    }
    osSendMesg(D_801E1590.unk0, arg0, 1);
}

#ifdef NON_MATCHING
void func_801C8E98(void (*arg0)(s32, s32, s32), s32 arg1, void (*arg2)(void*, uintptr_t, size_t)) {
    // static struct_801E15FC D_801E15FC; // must be in-function bss to match

    func_801CA3C0(arg1, arg2);
    D_801D3734 = arg0;
    D_801E15FC.unk0 = 0;
    D_801E15FC.unk1 = 0;
    func_801C8E50(&D_801E1598, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8E98.s")
#endif

#ifdef NON_MATCHING
// struct_801E1598 D_801E1598; // must be migrated (to this file)
void func_801C8EEC(void* arg0, s32 arg1, s32 arg2, u8 arg3) {
    struct_801E1598* var = &D_801E1598;

    if (D_801D3710 == 1) {
        D_801D3710 = 0;
        var->unk64 = 4;
        func_801C8E50(var, 1);
        if ((D_801E1604 == 3) || (D_801E1604 == 4)) {
            return;
        }
    }
    var->unk58 = arg0;
    var->unk5C = (void*)arg1;
    var->unk60 = arg2;
    var->unk64 = (u8)arg3;
    func_801C8E50(var, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/B8BEC0/func_801C8EEC.s")
#endif

s32 func_801C8F9C(struct_801E1598* arg0) {
    u8 sp1F;

    arg0->unk68 = LeoTestUnitReady(&sp1F);
    return (sp1F & 1) == 0;
}

s8 func_801C8FD0(void) {
    s32 temp_v0;

    temp_v0 = func_801C8F9C(&D_801E1598);
    if (D_801E1598.unk68 == 8) {
        return 0;
    }
    if (temp_v0 == 0) {
        return 2;
    }
    return 1;
}

s32 func_801C9020(void) {
    if ((func_801C90A4() == 0) && (D_801E1598.unk68 != 0)) {
        return D_801E1598.unk68;
    }
    return -1;
}

s32 func_801C905C(void) {
    if ((func_801C90A4() == 0) && ((D_801E1604 == 3) || (D_801E1604 == 4))) {
        return D_801E1598.unk68;
    }
    return 0;
}

s32 func_801C90A4(void) {
    return D_801E1598.unk66 == 1;
}

s32 func_801C90BC(void) {
    D_801E1598.unk64 = 3;
    func_801C8E50(&D_801E1598, 1);
    D_801D3710 = 0;
    if ((D_801E1604 == 3) || (D_801E1604 == 4)) {
        return -1;
    } else {
        return D_801E1604 == 0;
    }
}

s32 func_801C9114(void) {
    D_801E1598.unk64 = 4;
    func_801C8E50(&D_801E1598, 1);
    D_801D3710 = 0;
    if ((D_801E1604 == 3) || (D_801E1604 == 4)) {
        return -1;
    } else {
        return D_801E1604 == 0;
    }
}

s32 func_801C916C(void) {
    s32 var_v1;

    if (LeoDriveExist() != 0) {
        var_v1 = 8;
    } else {
        var_v1 = 0;
    }
    if (var_v1 == 0) {}
    D_801E1598.unk68 = var_v1;
    return var_v1 == 0;
}
