/*
 * File: z_en_zf.c
 * Overlay: ovl_En_Zf
 * Description: Lizalfos and Dinolfos
 */

#include "z_en_zf.h"

#define FLAGS 0x00000015

#define THIS ((EnZf*)thisx)

void EnZf_Init(Actor* thisx, GlobalContext* globalCtx);
void EnZf_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnZf_Update(Actor* thisx, GlobalContext* globalCtx);
void EnZf_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B44050(EnZf* this, void (*arg1)(EnZf*, GlobalContext*));
s16 func_80B44058(EnZf* this, GlobalContext* globalCtx, f32 arg2);
s16 func_80B441C4(EnZf* this, GlobalContext* globalCtx, f32 arg2);
s16 func_80B446A8(Vec3f* arg0, s16 arg1);
s16 func_80B44870(Vec3f* arg0, s16 arg1, s16 arg2, GlobalContext* globalCtx);
s32 func_80B44B14(Vec3f* arg0, s16 arg1, s16 arg2, GlobalContext* globalCtx);
s32 func_80B44CF0(GlobalContext* globalCtx, EnZf* this);
void func_80B44DC4(EnZf* this, GlobalContext* globalCtx);
s32 func_80B44E8C(GlobalContext* globalCtx, EnZf* this);
void func_80B450AC(EnZf* this);
void func_80B45174(EnZf* this, GlobalContext* globalCtx);
void func_80B45384(EnZf* this);
void func_80B4543C(EnZf* this, GlobalContext* globalCtx);
void func_80B456B4(EnZf* this, GlobalContext* globalCtx);
void func_80B45748(EnZf* this, GlobalContext* globalCtx);
void func_80B45E30(EnZf* this);
void func_80B45EF0(EnZf* this, GlobalContext* globalCtx);
void func_80B4604C(EnZf* this);
void func_80B46098(EnZf* this, GlobalContext* globalCtx);
void func_80B462E4(EnZf* this, GlobalContext* globalCtx);
void func_80B463E4(EnZf* this, GlobalContext* globalCtx);
void func_80B46A24(EnZf* this);
void func_80B46AE0(EnZf* this, GlobalContext* globalCtx);
void func_80B46D64(EnZf* this);
void func_80B46DD4(EnZf* this, GlobalContext* globalCtx);
void func_80B46E8C(EnZf* this);
void func_80B46F2C(EnZf* this, GlobalContext* globalCtx);
void func_80B47050(EnZf* this);
void func_80B47120(EnZf* this, GlobalContext* globalCtx);
void func_80B47360(EnZf* this, GlobalContext* globalCtx);
void func_80B4743C(EnZf* this, GlobalContext* globalCtx);
void func_80B474E4(EnZf* this);
void func_80B47544(EnZf* this, GlobalContext* globalCtx);
void func_80B4779C(EnZf* this, GlobalContext* globalCtx);
void func_80B4781C(EnZf* this, GlobalContext* globalCtx);
void func_80B47C64(EnZf* this, GlobalContext* globalCtx);
void func_80B47CF8(EnZf* this, GlobalContext* globalCtx);
void func_80B47DA8(EnZf* this);
void func_80B47EB4(EnZf* this, GlobalContext* globalCtx);
void func_80B48210(EnZf* this);
void func_80B482B8(EnZf* this, GlobalContext* globalCtx);
void func_80B483E4(EnZf* this, GlobalContext* globalCtx);
void func_80B48578(EnZf* this, GlobalContext* globalCtx);
void func_80B48CEC(EnZf* this);
void func_80B48E50(EnZf* this, GlobalContext* globalCtx);
void func_80B48F90(EnZf* this, GlobalContext* globalCtx);
void func_80B490B4(EnZf* this, GlobalContext* globalCtx);
s32 func_80B495FC(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3f* arg3, Vec3s* arg4, EnZf* this, Gfx** gfx);
void func_80B49688(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3s* arg3, EnZf* this);
void func_80B49B60(EnZf* this, f32 arg1);
s32 func_80B49C2C(GlobalContext* globalCtx, EnZf* this);
s32 func_80B49E4C(GlobalContext* globalCtx, EnZf* this);

extern SkeletonHeader D_6006690;
extern AnimationHeader D_6008138;
extern AnimationHeader D_6008C6C;
extern AnimationHeader D_6009530;
extern AnimationHeader D_600A3D4;
extern AnimationHeader D_600B10C;
extern Gfx D_600E198[];
extern Gfx D_6010060[];
extern SkeletonHeader D_60104B8;
extern AnimationHeader D_6011070;
extern AnimationHeader D_60119F4;
extern AnimationHeader D_601366C;
extern AnimationHeader D_6014E60;
extern AnimationHeader D_60157F8;
extern AnimationHeader D_6016388;

static Vec3f D_80B4A090[0x18] = {
    { 3560.0f, 100.0f, -1517.0f }, { 3170.0f, 100.0f, -1767.0f }, { 3165.0f, 100.0f, -2217.0f },
    { 3563.0f, 100.0f, -2437.0f }, { 3946.0f, 100.0f, -2217.0f }, { 3942.0f, 100.0f, -1765.0f },
    { 2861.0f, 100.0f, -2394.0f }, { 2776.0f, 100.0f, -1987.0f }, { 4527.0f, 531.0f, -1146.0f },
    { 4442.0f, 531.0f, -1405.0f }, { 4170.0f, 531.0f, -1395.0f }, { 4030.0f, 531.0f, -1162.0f },
    { 4010.0f, 531.0f, -883.0f },  { 4270.0f, 531.0f, -810.0f },  { 4520.0f, 531.0f, -880.0f },
    { 4260.0f, 531.0f, -1035.0f }, { 4757.0f, 531.0f, -1146.0f }, { 3850.0f, 531.0f, -883.0f },
    { 4380.0f, 531.0f, -690.0f },  { 4197.0f, 531.0f, -646.0f },  { 4070.0f, 531.0f, -1575.0f },
    { 3930.0f, 531.0f, -1705.0f }, { 3780.0f, 531.0f, -1835.0f }, { 3560.0f, 531.0f, -1985.0f },
};
static s16 D_80B4A1B0 = 0;
static s16 D_80B4A1B4 = 1;

const ActorInit En_Zf_InitVars = {
    ACTOR_EN_ZF,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_ZF,
    sizeof(EnZf),
    (ActorFunc)EnZf_Init,
    (ActorFunc)EnZf_Destroy,
    (ActorFunc)EnZf_Update,
    (ActorFunc)EnZf_Draw,
};

static ColliderCylinderInit D_80B4A1D8 = {
    {
        COLTYPE_HIT0,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK1,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 20, 70, 0, { 0, 0, 0 } },
};

static ColliderQuadInit D_80B4A204 = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7,
        BUMP_ON,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static DamageTable D_80B4A254 = {
    {
        0x10, 2,    0xD1, 2,    0x10, 2, 2, 0x10, 1, 2, 4, 0xD2, 0xF4, 0xD2, 0xD2, 0xD2,
        0xD2, 0x60, 0xF3, 0x60, 0,    0, 1, 4,    2, 2, 8, 4,    0,    0,    4,    0,
    },
};
static InitChainEntry D_80B4A274[3] = {
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 15, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -3500, ICHAIN_STOP),
};
static AnimationHeader* D_80B4A280[6] = {
    (AnimationHeader*)0x0601081C, (AnimationHeader*)0x06010CAC, &D_6011070,
    (AnimationHeader*)0x44898000, (AnimationHeader*)0xC42F0000, NULL,
};
static Vec3f D_80B4A298 = { 300.0f, 0.0f, 0.0f };
static Vec3f D_80B4A2A4 = { 300.0f, -1700.0f, 0.0f };
static Vec3f D_80B4A2B0 = { -600.0f, 300.0f, 0.0f };
static Vec3f D_80B4A2BC = { 0.0f, 1500.0f, 0.0f };
static Vec3f D_80B4A2C8 = { -600.0f, -3000.0f, 1000.0f };
static Vec3f D_80B4A2D4 = { -600.0f, -3000.0f, -1000.0f };
static Vec3f D_80B4A2E0 = { 1500.0f, -3000.0f, 0.0f };
static Vec3f D_80B4A2EC = { 0.0f, 0.0f, 0.0f };
static Gfx D_80B4A2F8[3] = { { { 0xD7000002, 0x0A000A00 } }, { { 0xDF000000, 0 } }, { { 0, 0 } } };
static s32 D_80B4AB30;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B44050.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B44058.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B441C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/EnZf_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/EnZf_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B446A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B44870.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B44B14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B44CF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B44DC4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B44E8C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B450AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B45174.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B45384.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B4543C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B456B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B45748.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B45E30.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B45EF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B4604C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B46098.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B462E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B463E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B46A24.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B46AE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B46D64.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B46DD4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B46E8C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B46F2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B47050.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B47120.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B47360.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B4743C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B474E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B47544.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B4779C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B4781C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B47C64.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B47CF8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B47DA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B47EB4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B48210.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B482B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B483E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B48578.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B48CEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B48E50.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B48F90.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B490B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/EnZf_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B495FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B49688.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/EnZf_Draw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B49B60.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B49C2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zf/func_80B49E4C.s")
