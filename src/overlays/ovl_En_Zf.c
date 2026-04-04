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

// non-equivalent, even
#ifdef NON_MATCHING

void func_80B44050(EnZf* this, void (*arg1)(EnZf*, GlobalContext*)) {
    this->unk3E8 = arg1;
}

s16 func_80B44058(EnZf* this, GlobalContext* globalCtx, f32 arg2) {
    u16 sp44;
    f32 sp40;
    Vec3f sp30;
    PosRot* sp28;
    PosRot* temp_v0;
    f32 temp_ft2;
    f32 var_fa0;
    f32 var_fa0_2;
    u16 temp_v1;

    var_fa0 = arg2;
    temp_v0 = &this->actor.world;
    if (var_fa0 == 0.0f) {
        if (this->actor.speedXZ >= 0.0f) {
            var_fa0_2 = 1.0f;
        } else {
            var_fa0_2 = -1.0f;
        }
        if (this->actor.params >= 0) {
            var_fa0 = var_fa0_2 * 45.0f;
        } else {
            var_fa0 = var_fa0_2 * 30.0f;
        }
    }
    sp30.x = (f32)temp_v0->pos.x;
    sp30.y = (f32)temp_v0->pos.y;
    sp30.z = (f32)temp_v0->pos.z;
    sp44 = this->actor.bgCheckFlags;
    arg2 = var_fa0;
    sp28 = temp_v0;
    sp40 = Math_SinS(this->actor.world.rot.y) * arg2;
    temp_ft2 = Math_CosS(this->actor.world.rot.y) * arg2;
    this->actor.world.pos.x += sp40;
    this->actor.world.pos.z += temp_ft2;
    Actor_UpdateBgCheckInfo(globalCtx, &this->actor, 0.0f, 0.0f, 0.0f, 0x1C);
    sp28->pos.x = sp30.x;
    sp28->pos.y = sp30.y;
    sp28->pos.z = sp30.z;
    temp_v1 = this->actor.bgCheckFlags;
    this->actor.bgCheckFlags = (u16)(s16)sp44;
    return (s16)((temp_v1 & 1) == 0);
}

s16 func_80B441C4(EnZf* this, GlobalContext* globalCtx, f32 arg2) {
    u16 sp44;
    f32 sp40;
    Vec3f sp30;
    PosRot* sp28;
    PosRot* temp_v0_2;
    f32 temp_fv0;
    f32 temp_fv0_2;
    s16 temp_v0;

    temp_fv0 = this->actor.speedXZ;
    if ((temp_fv0 != 0.0f) && (func_80B44058(this, globalCtx, temp_fv0) != 0)) {
        return 1;
    }
    temp_v0_2 = &this->actor.world;
    sp30.x = (f32)temp_v0_2->pos.x;
    sp30.y = (f32)temp_v0_2->pos.y;
    sp30.z = (f32)temp_v0_2->pos.z;
    sp44 = this->actor.bgCheckFlags;
    sp28 = temp_v0_2;
    sp40 = Math_SinS(this->actor.shape.rot.y) * arg2;
    temp_fv0_2 = Math_CosS(this->actor.shape.rot.y);
    this->actor.world.pos.x += sp40;
    this->actor.world.pos.z += temp_fv0_2 * arg2;
    Actor_UpdateBgCheckInfo(globalCtx, &this->actor, 0.0f, 0.0f, 0.0f, 0x1C);
    sp28->pos.x = sp30.x;
    sp28->pos.y = sp30.y;
    sp28->pos.z = sp30.z;
    temp_v0 = (this->actor.bgCheckFlags & 1) == 0;
    this->actor.bgCheckFlags = (u16)(s16)sp44;
    return temp_v0;
}

struct _m2c_stack_EnZf_Init {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ ColliderCylinder* sp30; /* inferred */
    /* 0x034 */ char pad34[0x18];       /* maybe part of sp30[7]? */
    /* 0x04C */ EffectBlureInit1 sp4C;
    /* 0x1EC */ Actor* sp1EC; /* inferred */
    /* 0x1F0 */ char pad1F0[8];
};
void EnZf_Init(Actor* thisx, GlobalContext* globalCtx) {
    Actor* sp1EC;
    EffectBlureInit1 sp4C;
    ColliderCylinder* sp30; /* compiler-managed */
    ColliderCylinder* temp_a1;
    ColliderQuad* temp_a1_2;
    f32 temp_fv0;
    f32 var_fv1;
    s16 temp_t8;
    s16 temp_v0;
    s16 temp_v0_2;
    EnZf* this = (EnZf*)thisx;

    sp1EC = globalCtx->actorCtx.actorLists[2].head;
    Actor_ProcessInitChain(&this->actor, D_80B4A274);
    temp_t8 = this->actor.params;
    this->actor.params &= 0xFF;
    temp_v0 = this->actor.params;
    this->actor.targetMode = 3;
    this->unk3FC = (s16)((s32)(temp_t8 & 0xFF00) >> 8);
    if (temp_v0 & 0x80) {
        this->actor.params = temp_v0 | 0xFF00;
    }
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFeet, 90.0f);
    this->unk3E0 = 0;
    this->actor.colChkInfo.mass = 0xFE;
    this->actor.colChkInfo.damageTable = &D_80B4A254;
    sp4C.p2EndColor[2] = 0xFF;
    sp4C.p2EndColor[1] = 0xFF;
    sp4C.p2EndColor[0] = 0xFF;
    sp4C.p1EndColor[2] = 0xFF;
    sp4C.p1EndColor[1] = 0xFF;
    sp4C.p1EndColor[0] = 0xFF;
    sp4C.p2StartColor[2] = 0xFF;
    sp4C.p2StartColor[1] = 0xFF;
    sp4C.p2StartColor[0] = 0xFF;
    sp4C.p1StartColor[3] = 0xFF;
    sp4C.p1StartColor[2] = 0xFF;
    sp4C.p1StartColor[1] = 0xFF;
    sp4C.p1StartColor[0] = 0xFF;
    sp4C.p2StartColor[3] = 0x40;
    sp4C.p1EndColor[3] = 0;
    sp4C.p2EndColor[3] = 0;
    sp4C.elemDuration = 8;
    sp4C.unkFlag = 0;
    sp4C.calcMode = 2;
    Effect_Add(globalCtx, &this->unk414, 1, 0U, 0U, &sp4C);
    Actor_UpdateBgCheckInfo(globalCtx, &this->actor, 75.0f, 45.0f, 45.0f, 0x1D);
    this->unk404 = 0xFF;
    this->actor.colChkInfo.cylRadius = 0x28;
    this->actor.colChkInfo.cylHeight = 0x64;
    temp_a1 = &this->unk418;
    sp30 = temp_a1;
    Collider_InitCylinder(globalCtx, temp_a1);
    Collider_SetCylinder(globalCtx, temp_a1, &this->actor, &D_80B4A1D8);
    temp_a1_2 = &this->unk464;
    sp30 = temp_a1_2;
    Collider_InitQuad(globalCtx, temp_a1_2);
    Collider_SetQuad(globalCtx, temp_a1_2, &this->actor, &D_80B4A204);
    if (this->actor.params == -2) {
        this->actor.colChkInfo.health = 0xC;
        this->actor.naviEnemyId = 0x10;
        SkelAnime_Init(globalCtx, &this->unk14C, &D_6006690, &D_600B10C, this->unk190, this->unk2B6, 0x31);
    } else {
        this->actor.colChkInfo.health = 6;
        this->actor.naviEnemyId = 0xF;
        SkelAnime_Init(globalCtx, &this->unk14C, &D_60104B8, &D_600B10C, this->unk190, this->unk2B6, 0x31);
    }
    if (this->actor.params < 0) {
        this->unk3FE = -1;
        this->unk400 = this->unk3FE;
        D_80B4A1B4 = -1;
        this->unk3E4 = 1;
        if (this->actor.params == -1) {
            func_80B450AC(this);
            return;
        }
        func_80B45384(this);
        return;
    }
    temp_fv0 = sp1EC->world.pos.y - this->actor.world.pos.y;
    if (temp_fv0 >= 0.0f) {
        var_fv1 = temp_fv0;
    } else {
        var_fv1 = -temp_fv0;
    }
    if ((var_fv1 <= 100.0f) && (Flags_GetSwitch(globalCtx, (s32)this->unk3FC) == 0)) {
        temp_v0_2 = func_80B446A8(&this->actor.world.pos, 0);
        this->unk3FE = temp_v0_2;
        this->unk400 = temp_v0_2;
        func_80B450AC(this);
        D_80B4A1B4 = 1;
        return;
    }
    Actor_Kill(&this->actor);
}

void EnZf_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnZf* this = (EnZf*)thisx;
    if ((this->actor.params >= 0) && (Actor_FindNearby(globalCtx, &this->actor, 0x25, 5U, 10000.0f) == NULL)) {
        func_800F5B58();
    }
    Effect_Delete(globalCtx, this->unk414);
    Collider_DestroyCylinder(globalCtx, &this->unk418);
    Collider_DestroyQuad(globalCtx, &this->unk464);
}

s16 func_80B446A8(Vec3f* arg0, s16 arg1) {
    Vec3f* temp_v0;
    Vec3f* temp_v0_2;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fa0_3;
    f32 temp_fa0_4;
    f32 temp_fa0_5;
    f32 temp_fa0_6;
    f32 temp_fa1;
    f32 temp_fa1_2;
    f32 temp_fa1_3;
    f32 temp_fa1_4;
    f32 temp_fv1;
    f32 var_fv0;
    s16 var_v1;

    var_fv0 = 210.0f;
    temp_fv1 = arg0->y;
    var_v1 = 0x17;
    if (temp_fv1 >= 420.0f) {
        var_fv0 = 110.0f;
    }
    if (arg1 != -1) {
        temp_v0 = &D_80B4A090[arg1];
        temp_fa0 = temp_v0->y;
        if (((temp_fa0 - 150.0f) <= temp_fv1) && (temp_fv1 <= (temp_fa0 + 150.0f))) {
            temp_fa1 = temp_v0->x;
            temp_fa0_2 = arg0->x;
            if (((temp_fa1 - var_fv0) <= temp_fa0_2) && (temp_fa0_2 <= (temp_fa1 + var_fv0))) {
                temp_fa1_2 = temp_v0->z;
                temp_fa0_3 = arg0->z;
                if (((temp_fa1_2 - var_fv0) <= temp_fa0_3) && (temp_fa0_3 <= (temp_fa1_2 + var_fv0))) {
                    return arg1;
                }
            }
        }
    }
loop_11:
    temp_v0_2 = &D_80B4A090[var_v1];
    temp_fa0_4 = temp_v0_2->y;
    if (!((temp_fa0_4 - 150.0f) <= temp_fv1) || !(temp_fv1 <= (temp_fa0_4 + 150.0f)) ||
        (temp_fa1_3 = temp_v0_2->x, temp_fa0_5 = arg0->x, !((temp_fa1_3 - var_fv0) <= temp_fa0_5)) ||
        !(temp_fa0_5 <= (temp_fa1_3 + var_fv0)) ||
        (temp_fa1_4 = temp_v0_2->z, temp_fa0_6 = arg0->z, !((temp_fa1_4 - var_fv0) <= temp_fa0_6)) ||
        !(temp_fa0_6 <= (temp_fa1_4 + var_fv0))) {
        var_v1 -= 1;
        if (var_v1 >= 0) {
            goto loop_11;
        }
    }
    return var_v1;
}

s16 func_80B44870(Vec3f* arg0, s16 arg1, s16 arg2, GlobalContext* globalCtx) {
    PosRot* sp64;
    PosRot* temp_a0;
    Vec3f* temp_s0;
    f32 temp_fv0;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_fs3;
    s16 temp_s0_2;
    s16 temp_s3;
    s16 temp_v1;
    s16 var_s0;
    s16 var_s4;
    s16 var_s5;
    s16 var_v0;
    s32 var_s7;

    var_fs2 = 585.0f;
    var_fs3 = 400.0f;
    var_fs0 = 99998.0f;
    temp_a0 = &globalCtx->actorCtx.actorLists[2].head->world;
    var_s0 = 5;
    var_s7 = 0;
    var_fs1 = 99999.0f;
    var_s4 = -1;
    var_s5 = -1;
    sp64 = temp_a0;
    temp_s3 = func_80B446A8(&temp_a0->pos, arg1);
    if (arg0->y > 420.0f) {
        var_fs3 = 50.0f;
        var_s7 = 8;
        if (arg1 >= 0xF) {
            var_fs2 = 400.0f;
            var_s0 = 0x17;
        } else {
            var_fs2 = 380.0f;
            var_s0 = 0xE;
        }
    }
    if (var_s0 >= var_s7) {
        do {
            if ((var_s0 != arg1) && (var_s0 != temp_s3) &&
                ((temp_s3 != -1) || !(Math_Vec3f_DistXYZ(&sp64->pos, &D_80B4A090[var_s0]) < var_fs3))) {
                temp_fv0 = Math_Vec3f_DistXYZ(arg0, &D_80B4A090[var_s0]);
                if (!(var_fs2 < temp_fv0)) {
                    if (temp_fv0 < var_fs0) {
                        var_fs1 = var_fs0;
                        var_s4 = var_s5;
                        var_fs0 = temp_fv0;
                        var_s5 = var_s0;
                    } else if (temp_fv0 < var_fs1) {
                        var_fs1 = temp_fv0;
                        var_s4 = var_s0;
                    }
                }
            }
            var_s0 -= 1;
        } while (var_s0 >= var_s7);
    }
    temp_s0 = &D_80B4A090[var_s5];
    Math_Vec3f_DistXYZ(&sp64->pos, temp_s0);
    Math_Vec3f_DistXYZ(&sp64->pos, &D_80B4A090[var_s4]);
    if (var_s4 > 0) {
        temp_s0_2 = Math_Vec3f_Yaw(arg0, temp_s0);
        temp_v1 = temp_s0_2 - Math_Vec3f_Yaw(arg0, &sp64->pos);
        var_v0 = -temp_v1;
        if (temp_v1 >= 0) {
            var_v0 = temp_v1;
        }
        if (var_v0 < 0x36B0) {
            var_s5 = var_s4;
        }
    }
    if (var_s5 < 0) {
        var_s5 = arg2;
    }
    return var_s5;
}

s32 func_80B44B14(Vec3f* arg0, s16 arg1, s16 arg2, GlobalContext* globalCtx) {
    PosRot* temp_s7;
    Vec3f* temp_s0;
    f32 temp_fv0;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    s16 temp_fp;
    s16 var_s1;
    s16 var_s2;
    s16 var_s3;
    s32 var_fp;
    s32 var_s4;

    temp_s7 = &globalCtx->actorCtx.actorLists[2].head->world;
    var_s1 = 7;
    var_s4 = 0;
    var_fs2 = 500.0f;
    var_fs0 = 99998.0f;
    var_fs1 = 99999.0f;
    temp_fp = func_80B446A8(&temp_s7->pos, -1);
    var_s2 = arg1;
    var_s3 = arg2;
    if (arg0->y > 200.0f) {
        var_fs2 = 290.0f;
        var_s1 = 0x17;
        var_s4 = 8;
    }
    if (var_s1 >= var_s4) {
    loop_4:
        temp_s0 = &D_80B4A090[var_s1];
        if (!(var_fs2 < Math_Vec3f_DistXYZ(arg0, temp_s0))) {
            if (var_s1 != temp_fp) {
                temp_fv0 = Math_Vec3f_DistXYZ(&temp_s7->pos, temp_s0);
                if (temp_fv0 < var_fs0) {
                    var_fs1 = var_fs0;
                    var_s3 = var_s2;
                    var_fs0 = temp_fv0;
                    var_s2 = var_s1;
                } else if (temp_fv0 < var_fs1) {
                    var_fs1 = temp_fv0;
                    var_s3 = var_s1;
                }
                goto block_11;
            }
            var_s2 = temp_fp;
        } else {
        block_11:
            var_s1 -= 1;
            if (var_s1 >= var_s4) {
                goto loop_4;
            }
        }
    }
    if (var_s3 != temp_fp) {
        var_fp = var_s2 << 0x10;
    } else {
        var_fp = var_s3 << 0x10;
    }
    return var_fp >> 0x10;
}

s32 func_80B44CF0(GlobalContext* globalCtx, EnZf* this) {
    Player* sp18;
    Player* temp_v1;
    Actor* temp_v0;

    temp_v1 = globalCtx->actorCtx.actorLists[2].head;
    if (this->actor.params >= 0) {
        if (temp_v1->stateFlags1 & 0x6000) {
            goto block_15;
        }
        return 1;
    }
    sp18 = temp_v1;
    if (Actor_OtherIsTargeted(globalCtx, &this->actor) == 0) {
        return 1;
    }
    if (this->actor.params == -2) {
        temp_v0 = temp_v1->unk_664;
        if (temp_v0 == NULL) {
            goto block_15;
        }
        if (temp_v0->category != 5) {
            return 1;
        }
        if (temp_v0->id != 0x25) {
            goto block_15;
        }
        if (temp_v0->colorFilterTimer != 0) {
            return 1;
        }
        goto block_15;
    }
block_15:
    return 0;
}

void func_80B44DC4(EnZf* this, GlobalContext* globalCtx) {
    s16 var_v0;

    var_v0 = this->actor.yawTowardsPlayer - this->actor.shape.rot.y;
    if (var_v0 < 0) {
        var_v0 *= -1;
    }
    if (var_v0 >= 0x1B58) {
        func_80B483E4(this, globalCtx);
        return;
    }
    if ((this->actor.xzDistToPlayer <= 100.0f) && (globalCtx->gameplayFrames & 7) &&
        (func_80B44CF0(globalCtx, this) != 0)) {
        func_80B46A24(this);
        return;
    }
    func_80B45384(this);
}

s32 func_80B44E8C(GlobalContext* globalCtx, EnZf* this) {
    s16 sp2E;
    Actor* sp28;
    Actor* temp_v0_2;
    s16 temp_v0;
    s16 temp_v1;
    s16 temp_v1_2;
    s16 var_t0;
    s16 var_v0;

    temp_v0 = this->actor.shape.rot.y;
    var_t0 = this->actor.wallYaw - temp_v0;
    if (var_t0 < 0) {
        var_t0 *= -1;
    }
    sp2E = var_t0;
    if (func_800354B4(globalCtx, &this->actor, 100.0f, 0x5DC0, 0x2AA8, (s16)(s32)temp_v0) != 0) {
        temp_v1 = this->actor.yawTowardsPlayer;
        this->actor.world.rot.y = temp_v1;
        this->actor.shape.rot.y = temp_v1;
        if (this->actor.bgCheckFlags & 8) {
            var_v0 = -var_t0;
            if (var_t0 >= 0) {
                var_v0 = var_t0;
            }
            if ((var_v0 < 0x2EE0) && (this->actor.xzDistToPlayer < 80.0f)) {
                func_80B48210(this);
                return 1;
            }
            goto block_9;
        }
    block_9:
        if ((this->actor.xzDistToPlayer < 90.0f) && (globalCtx->gameplayFrames & 1)) {
            func_80B48210(this);
            return 1;
        }
        func_80B46E8C(this);
        return 1;
    }
    sp2E = var_t0;
    temp_v0_2 = Actor_FindNearby(globalCtx, &this->actor, -1, 3U, 80.0f);
    if (temp_v0_2 != NULL) {
        temp_v1_2 = this->actor.yawTowardsPlayer;
        this->actor.world.rot.y = temp_v1_2;
        this->actor.shape.rot.y = temp_v1_2;
        if (((this->actor.bgCheckFlags & 8) && (var_t0 < 0x2EE0)) || (temp_v0_2->id == 0xDA)) {
            if (temp_v0_2->id == 0xDA) {
                sp28 = temp_v0_2;
                if ((Actor_WorldDistXYZToActor(&this->actor, temp_v0_2) < 80.0f) &&
                    ((s16)((this->actor.shape.rot.y - temp_v0_2->world.rot.y) + 0x8000) < 0x3E80)) {
                    func_80B48210(this);
                    return 1;
                }
            }
            func_80B49B60(this, 4.0f);
            return 1;
        }
        func_80B46E8C(this);
        return 1;
    }
    return 0;
}

void func_80B450AC(EnZf* this) {
    s16 temp_v0;

    Animation_Change(&this->unk14C, &D_6009530, 0.0f, 9.0f, (f32)Animation_GetLastFrame(&D_6009530), 0U, 0.0f);
    temp_v0 = this->actor.yawTowardsPlayer;
    this->actor.world.pos.y = this->actor.floorHeight + 300.0f;
    this->actor.shape.shadowAlpha = 0;
    this->unk404 = 0;
    this->unk3F0 = 0xA;
    this->unk3E4 = 1;
    this->unk3DC = 0;
    this->actor.bgCheckFlags &= 0xFFFD;
    this->actor.flags &= ~1;
    this->actor.world.rot.y = temp_v0;
    this->actor.shape.rot.y = temp_v0;
    func_80B44050(this, func_80B45174);
}

void func_80B45174(EnZf* this, GlobalContext* globalCtx) {
    s32 temp_v0;
    u8 temp_v0_2;

    if (this->unk3F0 == 1) {
        Audio_PlayActorSound2(&this->actor, 0x3829U);
        this->actor.flags |= 1;
        if (this->actor.params == 0) {
            func_800F5ACC(0x38U);
        }
    }
    temp_v0 = this->unk3F0;
    if (temp_v0 != 0) {
        if (this->actor.params != -1) {
            this->unk3F0 = temp_v0 - 1;
        } else if (this->actor.xzDistToPlayer <= 160.0f) {
            this->unk3F0 = 0;
            this->actor.flags |= 1;
            Audio_PlayActorSound2(&this->actor, 0x3829U);
        }
        this->actor.world.pos.y = this->actor.floorHeight + 300.0f;
    } else {
        temp_v0_2 = this->unk404;
        if ((s32)temp_v0_2 < 0xFF) {
            this->unk404 = temp_v0_2 + 0x33;
        }
    }
    if ((this->actor.bgCheckFlags & 3) && (this->unk3E4 != 0)) {
        Audio_PlayActorSound2(&this->actor, 0x3828U);
        Animation_Change(&this->unk14C, &D_6008C6C, 1.0f, 0.0f, 17.0f, 2U, 0.0f);
        this->unk3E4 = 0;
        this->actor.bgCheckFlags &= 0xFFFD;
        this->actor.world.pos.y = this->actor.floorHeight;
        this->actor.velocity.y = 0.0f;
        Actor_SpawnFloorDustRing(globalCtx, &this->actor, &this->unk4F0, 3.0f, 2, 2.0f, 0, 0, 0U);
        Actor_SpawnFloorDustRing(globalCtx, &this->actor, &this->unk4E4, 3.0f, 2, 2.0f, 0, 0, 0U);
    }
    if (SkelAnime_Update(&this->unk14C) != 0) {
        this->unk404 = 0xFF;
        if (this->actor.params > 0) {
            func_80B47360(this, globalCtx);
        } else {
            func_80B45384(this);
        }
    }
    this->actor.shape.shadowAlpha = this->unk404;
}

void func_80B45384(EnZf* this) {
    f32 temp_ft4;

    Animation_Change(&this->unk14C, &D_600B10C, 1.0f, 0.0f, (f32)Animation_GetLastFrame(&D_600B10C), 1U, -4.0f);
    this->unk3DC = 3;
    temp_ft4 = Rand_ZeroOne() * 10.0f;
    this->actor.speedXZ = 0.0f;
    this->actor.world.rot.y = this->actor.shape.rot.y;
    this->unk3F0 = (s32)(temp_ft4 + 5.0f);
    func_80B44050(this, func_80B4543C);
}

void func_80B4543C(EnZf* this, GlobalContext* globalCtx) {
    Player* sp2C;
    s16 sp26;
    f32 temp_fv0;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_4;
    s16 var_v1;
    s16 var_v1_2;
    s32 temp_v0_3;

    sp2C = globalCtx->actorCtx.actorLists[2].head;
    var_v1 = (this->actor.yawTowardsPlayer - this->unk3EC) - this->actor.shape.rot.y;
    if (var_v1 < 0) {
        var_v1 *= -1;
    }
    sp26 = var_v1;
    SkelAnime_Update(&this->unk14C);
    if (func_80B49C2C(globalCtx, this) == 0) {
        if (this->actor.params == -2) {
            temp_v0 = this->unk3F4;
            if (temp_v0 != 0) {
                this->unk3F4 = temp_v0 - 1;
                if (var_v1 < 0x1FFE) {
                    this->unk3F4 = 0;
                    goto block_8;
                }
            } else if (func_80B44E8C(globalCtx, this) == 0) {
                goto block_8;
            }
        } else {
        block_8:
            var_v1_2 = sp2C->actor.shape.rot.y - this->actor.shape.rot.y;
            if (var_v1_2 < 0) {
                var_v1_2 *= -1;
            }
            if ((this->actor.xzDistToPlayer < 100.0f) && (sp2C->swordState != 0) && (var_v1_2 >= 0x1F40)) {
                temp_v0_2 = this->actor.yawTowardsPlayer;
                this->actor.world.rot.y = temp_v0_2;
                this->actor.shape.rot.y = temp_v0_2;
                func_80B483E4(this, globalCtx);
                return;
            }
            temp_v0_3 = this->unk3F0;
            if (temp_v0_3 != 0) {
                this->unk3F0 = temp_v0_3 - 1;
                return;
            }
            if (Actor_IsFacingPlayer(&this->actor, 0x1555) != 0) {
                temp_fv0 = this->actor.xzDistToPlayer;
                if ((temp_fv0 < 200.0f) && (temp_fv0 > 100.0f) && (Rand_ZeroOne() < 0.3f)) {
                    if (this->actor.params == -2) {
                        temp_v0_4 = this->actor.yawTowardsPlayer;
                        this->actor.shape.rot.y = temp_v0_4;
                        this->actor.world.rot.y = temp_v0_4;
                        func_80B45E30(this);
                    } else {
                        func_80B483E4(this, globalCtx);
                    }
                } else if (Rand_ZeroOne() > 0.3f) {
                    func_80B456B4(this, globalCtx);
                } else {
                    func_80B483E4(this, globalCtx);
                }
            } else {
                func_80B4604C(this);
            }
            if (!(globalCtx->gameplayFrames & 0x5F)) {
                Audio_PlayActorSound2(&this->actor, 0x3829U);
            }
        }
    }
}

void func_80B456B4(EnZf* this, GlobalContext* globalCtx) {
    PosRot* sp24;
    PosRot* temp_a0;

    Animation_MorphToLoop(&this->unk14C, &D_6008138, -4.0f);
    this->unk3DC = 5;
    temp_a0 = &this->actor.world;
    if (this->actor.params >= 0) {
        sp24 = temp_a0;
        this->unk3FE = func_80B446A8(&temp_a0->pos, this->unk3FE);
        this->unk402 = func_80B44B14(&temp_a0->pos, this->unk3FE, this->unk400, globalCtx);
        this->unk3E4 = 0;
    }
    this->actor.speedXZ = 0.0f;
    func_80B44050(this, func_80B45748);
}

void func_80B45748(EnZf* this, GlobalContext* globalCtx) {
    s32 sp54;
    s32 sp50;
    s16 sp48;
    f32 sp44;
    f32 sp40;
    Player* sp3C;
    f32 sp30;
    f32* sp2C;
    Player* temp_t8;
    f32 temp_fv0;
    f32 temp_fv0_2;
    s16 temp_a1;
    s16 temp_a1_2;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s16 var_v1;
    s16 var_v1_2;

    sp48 = -1;
    sp44 = 350.0f;
    sp40 = 0.0f;
    temp_t8 = globalCtx->actorCtx.actorLists[2].head;
    sp3C = temp_t8;
    if (this->actor.params >= 0) {
        temp_v0 = func_80B446A8(&temp_t8->actor.world.pos, -1);
        sp48 = temp_v0;
        this->unk3FE = func_80B446A8(&this->actor.world.pos, temp_v0);
        if (this->actor.world.pos.y >= 420.0f) {
            sp44 = 270.0f;
        }
    }
    if (func_80B49C2C(globalCtx, this) == 0) {
        temp_a1 = this->unk3FE;
        if (sp48 != temp_a1) {
            this->unk402 = func_80B44B14(&this->actor.world.pos, temp_a1, this->unk400, globalCtx);
            if (sp48 < 0) {
                temp_a1_2 = this->unk3FE;
                if (temp_a1_2 == this->unk402) {
                    sp48 = temp_a1_2;
                    temp_v0_2 = this->actor.yawTowardsPlayer;
                    this->actor.world.rot.y = temp_v0_2;
                    this->actor.shape.rot.y = temp_v0_2;
                    goto block_20;
                }
            }
            temp_v0_3 = Actor_WorldYawTowardPoint(&this->actor, &D_80B4A090[this->unk402]);
            this->actor.shape.rot.y = temp_v0_3;
            this->actor.yawTowardsPlayer = temp_v0_3;
            this->actor.world.rot.y = temp_v0_3;
            var_v1 = this->actor.wallYaw - this->actor.shape.rot.y;
            if (var_v1 < 0) {
                var_v1 *= -1;
            }
            if (((this->unk3F8 != 0) && (this->actor.speedXZ > 0.0f)) ||
                ((this->actor.bgCheckFlags & 8) && (var_v1 >= 0x5C19))) {
                if ((Actor_WorldDistXZToPoint(&this->actor, &D_80B4A090[this->unk402]) < sp44) &&
                    (func_80B44058(this, globalCtx, 191.9956f) == 0)) {
                    func_80B45E30(this);
                    if (this->actor.bgCheckFlags & 8) {
                        this->actor.velocity.y = 20.0f;
                    }
                } else {
                    this->actor.world.rot.y = Actor_WorldYawTowardPoint(&this->actor, &D_80B4A090[this->unk3FE]);
                    goto block_20;
                }
            } else {
                temp_v0_4 = this->actor.yawTowardsPlayer;
                this->actor.world.rot.y = temp_v0_4;
                this->actor.shape.rot.y = temp_v0_4;
                Math_SmoothStepToF(&this->actor.speedXZ, 8.0f, 1.0f, 1.5f, 0.0f);
                goto block_20;
            }
        } else {
        block_20:
            sp2C = &this->actor.speedXZ;
            if (Actor_OtherIsTargeted(globalCtx, &this->actor) != 0) {
                sp40 = 100.0f;
            }
            if (this->actor.xzDistToPlayer <= (70.0f + sp40)) {
                Math_SmoothStepToF(sp2C, -8.0f, 1.0f, 0.5f, 0.0f);
            } else {
                Math_SmoothStepToF(sp2C, 8.0f, 1.0f, 0.5f, 0.0f);
            }
            this->unk14C.playSpeed = this->actor.speedXZ * 1.2f;
            var_v1_2 = sp3C->actor.shape.rot.y - this->actor.shape.rot.y;
            if (var_v1_2 < 0) {
                var_v1_2 *= -1;
            }
            if ((sp48 == this->unk3FE) && (this->actor.xzDistToPlayer < 150.0f) && (sp3C->swordState != 0) &&
                (var_v1_2 >= 0x1F40)) {
                temp_v0_5 = this->actor.yawTowardsPlayer;
                this->actor.world.rot.y = temp_v0_5;
                this->actor.shape.rot.y = temp_v0_5;
                if (Rand_ZeroOne() > 0.7f) {
                    func_80B483E4(this, globalCtx);
                    return;
                }
            }
            sp54 = (s32)this->unk14C.curFrame;
            SkelAnime_Update(&this->unk14C);
            temp_fv0 = this->unk14C.playSpeed;
            if (temp_fv0 >= 0.0f) {
                sp30 = temp_fv0;
            } else {
                sp30 = -temp_fv0;
            }
            sp50 = (s32)(this->unk14C.curFrame - sp30);
            if (temp_fv0 >= 0.0f) {
                sp30 = temp_fv0;
            } else {
                sp30 = -temp_fv0;
            }
            if (sp48 == this->unk3FE) {
                if (Actor_IsFacingPlayer(&this->actor, 0x11C7) == 0) {
                    if (Rand_ZeroOne() > 0.5f) {
                        func_80B462E4(this, globalCtx);
                    } else {
                        func_80B45384(this);
                    }
                } else if (this->actor.xzDistToPlayer < 100.0f) {
                    if ((Rand_ZeroOne() > 0.05f) && (func_80B44CF0(globalCtx, this) != 0)) {
                        func_80B46A24(this);
                    } else if (Rand_ZeroOne() > 0.5f) {
                        func_80B483E4(this, globalCtx);
                    } else {
                        func_80B45384(this);
                    }
                } else if (this->unk3F8 != 0) {
                    func_80B462E4(this, globalCtx);
                } else if (Rand_ZeroOne() < 0.1f) {
                    func_80B45384(this);
                }
            }
            if (this->actor.params == -2) {
                if (func_80B44E8C(globalCtx, this) == 0) {
                    temp_fv0_2 = this->actor.xzDistToPlayer;
                    if ((temp_fv0_2 < 180.0f) && (temp_fv0_2 > 160.0f) &&
                        (Actor_IsFacingPlayer(&this->actor, 0x71C) != 0)) {
                        if (Actor_IsTargeted(globalCtx, &this->actor) != 0) {
                            if (Rand_ZeroOne() < 0.1f) {
                                temp_v0_6 = this->actor.yawTowardsPlayer;
                                this->actor.shape.rot.y = temp_v0_6;
                                this->actor.world.rot.y = temp_v0_6;
                                func_80B45E30(this);
                                return;
                            }
                            goto block_64;
                        }
                        func_80B483E4(this, globalCtx);
                        return;
                    }
                    goto block_64;
                }
            } else {
            block_64:
                if (!(globalCtx->gameplayFrames & 0x5F)) {
                    Audio_PlayActorSound2(&this->actor, 0x3829U);
                }
                if ((sp54 != (s32)this->unk14C.curFrame) &&
                    (((sp50 < 2) && (((s32)sp30 + sp54) >= 4)) || ((sp50 < 0x20) && (((s32)sp30 + sp54) >= 0x22)))) {
                    Audio_PlayActorSound2(&this->actor, 0x382EU);
                }
            }
        }
    }
}

void func_80B45E30(EnZf* this) {
    Animation_Change(&this->unk14C, &D_6009530, 1.0f, 0.0f, 3.0f, 2U, -3.0f);
    this->unk3F0 = 0;
    this->unk3E4 = 1;
    this->actor.velocity.y = 15.0f;
    if (this->actor.params >= 0) {
        this->actor.speedXZ = 16.0f;
    } else {
        this->actor.speedXZ = 10.0f;
    }
    this->unk3DC = 0xD;
    Audio_PlayActorSound2(&this->actor, 0x382FU);
    func_80B44050(this, func_80B45EF0);
}

void func_80B45EF0(EnZf* this, GlobalContext* globalCtx) {
    SkelAnime* sp34;
    SkelAnime* temp_a0;
    f32 temp_fv0;

    if (this->unk3F0 != 0) {
        temp_fv0 = this->actor.floorHeight;
        if (this->actor.world.pos.y <= temp_fv0) {
            this->actor.world.pos.y = temp_fv0;
            this->unk3E4 = 0;
            this->actor.velocity.y = 0.0f;
            this->actor.speedXZ = 0.0f;
        }
    }
    temp_a0 = &this->unk14C;
    sp34 = temp_a0;
    if (SkelAnime_Update(temp_a0) != 0) {
        if (this->unk3F0 == 0) {
            Animation_Change(temp_a0, &D_6008C6C, 3.0f, 0.0f, 17.0f, 2U, -3.0f);
            this->unk3F0 = 0xA;
            Audio_PlayActorSound2(&this->actor, 0x382FU);
        } else {
            this->actor.speedXZ = 0.0f;
            this->unk3E4 = 0;
            func_80B456B4(this, globalCtx);
        }
    }
    if (!(globalCtx->gameplayFrames & 0x5F)) {
        Audio_PlayActorSound2(&this->actor, 0x3829U);
    }
    if ((this->actor.params == -2) && (this->actor.bgCheckFlags & 3)) {
        if (func_80B44CF0(globalCtx, this) != 0) {
            func_80B46A24(this);
            return;
        }
        func_80B483E4(this, globalCtx);
    }
}

void func_80B4604C(EnZf* this) {
    Animation_MorphToLoop(&this->unk14C, &D_6008138, -4.0f);
    this->unk3DC = 6;
    func_80B44050(this, func_80B46098);
}

void func_80B46098(EnZf* this, GlobalContext* globalCtx) {
    Actor* sp24;
    f32 var_fa0;
    f32 var_fv1;
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_v1;
    s32 var_v1;

    sp24 = globalCtx->actorCtx.actorLists[2].head;
    if ((func_80B49C2C(globalCtx, this) == 0) &&
        ((this->actor.params != -2) || (func_80B44E8C(globalCtx, this) == 0))) {
        temp_a0 = this->actor.shape.rot.y;
        temp_v0 = this->actor.yawTowardsPlayer - temp_a0;
        if (temp_v0 > 0) {
            var_v1 = (s32)(((f32)temp_v0 * 0.25f) + 2000.0f) << 0x10;
        } else {
            var_v1 = (s32)(((f32)temp_v0 * 0.25f) - 2000.0f) << 0x10;
        }
        temp_v1 = var_v1 >> 0x10;
        this->actor.shape.rot.y = temp_a0 + temp_v1;
        this->actor.world.rot.y = this->actor.shape.rot.y;
        if (temp_v0 > 0) {
            var_fa0 = 2.0f;
            var_fv1 = (f32)temp_v1 * 1.5f;
            if (var_fv1 > 2.0f) {
                goto block_10;
            }
        } else {
            var_fa0 = -2.0f;
            var_fv1 = (f32)temp_v1 * 1.5f;
            if (var_fv1 < -2.0f) {
            block_10:
                var_fv1 = var_fa0;
            }
        }
        this->unk14C.playSpeed = -var_fv1;
        SkelAnime_Update(&this->unk14C);
        if (this->actor.params >= 0) {
            this->unk3FE = func_80B446A8(&this->actor.world.pos, this->unk3FE);
            if (func_80B446A8(&sp24->world.pos, -1) != this->unk3FE) {
                func_80B456B4(this, globalCtx);
                return;
            }
        }
        if (Actor_IsFacingPlayer(&this->actor, 0x1555) != 0) {
            if (Rand_ZeroOne() > 0.8f) {
                func_80B462E4(this, globalCtx);
            } else {
                func_80B456B4(this, globalCtx);
            }
        }
        if (!(globalCtx->gameplayFrames & 0x5F)) {
            Audio_PlayActorSound2(&this->actor, 0x3829U);
        }
    }
}

void func_80B462E4(EnZf* this, GlobalContext* globalCtx) {
    f32 temp_ft1;

    if ((this->actor.params < 0) ||
        (Actor_TestFloorInDirection(&this->actor, globalCtx, 40.0f, (s16)(this->actor.shape.rot.y + 0x3FFF)) != 0) ||
        (Actor_TestFloorInDirection(&this->actor, globalCtx, -40.0f, (s16)(this->actor.shape.rot.y + 0x3FFF)) != 0)) {
        Animation_PlayLoop(&this->unk14C, &D_6016388);
        this->actor.speedXZ = Rand_CenteredFloat(12.0f);
        this->actor.world.rot.y = this->actor.shape.rot.y;
        temp_ft1 = Rand_ZeroOne() * 10.0f;
        this->unk3E4 = 0;
        this->unk3DC = 7;
        this->unk408 = 0.0f;
        this->unk3F0 = (s32)(temp_ft1 + 20.0f);
        func_80B44050(this, func_80B463E4);
        return;
    }
    func_80B456B4(this, globalCtx);
}

void func_80B463E4(EnZf* this, GlobalContext* globalCtx) {
    s16 sp56;
    s32 sp4C;
    Actor* sp40;
    f32 sp3C;
    void* sp28;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 var_fa0;
    f32 var_fa0_2;
    f32 var_fa0_3;
    f32 var_fa1;
    f32 var_fv0;
    s16 temp_v0;
    s16 temp_v1;
    s16 var_v0_3;
    s16 var_v1;
    s32 temp_ft3;
    s32 temp_ft5;
    s32 temp_v0_2;
    s32 var_v0;
    s32 var_v0_2;
    void* temp_v1_2;

    sp40 = globalCtx->actorCtx.actorLists[2].head;
    sp3C = 0.0f;
    Math_SmoothStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 1, 0xFA0, 1);
    if ((func_80B49C2C(globalCtx, this) == 0) &&
        ((this->actor.params != -2) || (func_80B44E8C(globalCtx, this) == 0))) {
        temp_v0 = this->actor.shape.rot.y;
        this->actor.world.rot.y = temp_v0 + 0x3A98;
        temp_v1 = sp40->shape.rot.y + 0x8000;
        sp56 = temp_v1;
        if (Math_SinS((s16)(temp_v1 - temp_v0)) >= 0.0f) {
            var_fv0 = -8.0f;
            this->actor.speedXZ -= 0.25f;
            if (this->actor.speedXZ < -8.0f) {
                goto block_8;
            }
        } else if (Math_SinS((s16)(sp56 - this->actor.shape.rot.y)) < 0.0f) {
            var_fv0 = 8.0f;
            this->actor.speedXZ += 0.25f;
            if (this->actor.speedXZ > 8.0f) {
            block_8:
                this->actor.speedXZ = var_fv0;
            }
        }
        if (this->actor.params >= 0) {
            if (this->unk3F8 != 0) {
                this->actor.speedXZ = -this->actor.speedXZ;
            }
        } else {
            var_v0 = this->actor.bgCheckFlags & 8;
            if (var_v0 == 0) {
                if (Actor_TestFloorInDirection(&this->actor, globalCtx, this->actor.speedXZ,
                                               (s16)(this->actor.shape.rot.y + 0x3FFF)) == 0) {
                    var_v0 = this->actor.bgCheckFlags & 8;
                    goto block_15;
                }
            } else {
            block_15:
                if (var_v0 != 0) {
                    if (this->actor.speedXZ >= 0.0f) {
                        var_v0_2 = (this->actor.shape.rot.y + 0x3FFF) << 0x10;
                    } else {
                        var_v0_2 = (this->actor.shape.rot.y - 0x3FFF) << 0x10;
                    }
                    var_v0_3 = this->actor.wallYaw - (var_v0_2 >> 0x10);
                } else {
                    var_v0_3 = 0;
                    this->actor.speedXZ *= -0.8f;
                }
                var_v1 = -var_v0_3;
                if (var_v0_3 >= 0) {
                    var_v1 = var_v0_3;
                }
                if (var_v1 >= 0x4001) {
                    this->actor.speedXZ *= -0.8f;
                    temp_fv0 = this->actor.speedXZ;
                    if (temp_fv0 < 0.0f) {
                        this->actor.speedXZ = temp_fv0 - 0.5f;
                    } else {
                        this->actor.speedXZ = temp_fv0 + 0.5f;
                    }
                }
            }
        }
        if (Actor_OtherIsTargeted(globalCtx, &this->actor) != 0) {
            sp3C = 100.0f;
        }
        temp_fv0_2 = this->actor.xzDistToPlayer;
        if (temp_fv0_2 <= (70.0f + sp3C)) {
            Math_SmoothStepToF(&this->unk408, -4.0f, 1.0f, 1.5f, 0.0f);
        } else if ((90.0f + sp3C) < temp_fv0_2) {
            Math_SmoothStepToF(&this->unk408, 4.0f, 1.0f, 1.5f, 0.0f);
        } else {
            Math_SmoothStepToF(&this->unk408, 0.0f, 1.0f, 5.65f, 0.0f);
        }
        temp_fv1 = this->unk408;
        if ((temp_fv1 != 0.0f) && (func_80B441C4(this, globalCtx, temp_fv1) == 0)) {
            this->actor.world.pos.x += Math_SinS(this->actor.shape.rot.y) * this->unk408;
            this->actor.world.pos.z += Math_CosS(this->actor.shape.rot.y) * this->unk408;
        }
        temp_fv0_3 = this->actor.speedXZ;
        temp_fv1_2 = this->unk408;
        if (temp_fv0_3 >= 0.0f) {
            var_fa1 = temp_fv0_3;
        } else {
            var_fa1 = -temp_fv0_3;
        }
        if (temp_fv1_2 >= 0.0f) {
            var_fa0 = temp_fv1_2;
        } else {
            var_fa0 = -temp_fv1_2;
        }
        if (var_fa0 <= var_fa1) {
            this->unk14C.playSpeed = temp_fv0_3 * 0.75f;
        } else if (this->unk14C.playSpeed < 0.0f) {
            this->unk14C.playSpeed = temp_fv1_2 * -0.75f;
        } else {
            this->unk14C.playSpeed = temp_fv1_2 * 0.75f;
        }
        temp_ft5 = (s32)this->unk14C.curFrame;
        sp4C = temp_ft5;
        SkelAnime_Update(&this->unk14C);
        temp_fv0_4 = this->unk14C.playSpeed;
        if (temp_fv0_4 >= 0.0f) {
            var_fa0_2 = temp_fv0_4;
        } else {
            var_fa0_2 = -temp_fv0_4;
        }
        temp_fv1_3 = this->unk14C.curFrame;
        temp_ft3 = (s32)(temp_fv1_3 - var_fa0_2);
        if (temp_fv0_4 >= 0.0f) {
            var_fa0_3 = temp_fv0_4;
        } else {
            var_fa0_3 = -temp_fv0_4;
        }
        if ((temp_ft5 != (s32)temp_fv1_3) && (((temp_ft3 < 0xE) && (((s32)var_fa0_3 + temp_ft5) >= 0x10)) ||
                                              ((temp_ft3 < 0x1B) && (((s32)var_fa0_3 + temp_ft5) >= 0x1D)))) {
            Audio_PlayActorSound2(&this->actor, 0x382EU);
        }
        temp_v1_2 = globalCtx + 0x10000;
        if (!(globalCtx->gameplayFrames & 0x5F)) {
            sp28 = temp_v1_2;
            Audio_PlayActorSound2(&this->actor, 0x3829U);
        }
        sp28 = temp_v1_2;
        if ((Math_CosS((s16)(sp56 - this->actor.shape.rot.y)) < -0.85f) ||
            (temp_v0_2 = this->unk3F0, (temp_v0_2 == 0))) {
            this->actor.world.rot.y = this->actor.shape.rot.y;
            if ((this->actor.xzDistToPlayer <= 100.0f) && !(globalCtx->gameplayFrames & 3) &&
                (func_80B44CF0(globalCtx, this) != 0)) {
                func_80B46A24(this);
                return;
            }
            func_80B45384(this);
            return;
        }
        if (temp_v0_2 != 0) {
            this->unk3F0 = temp_v0_2 - 1;
        }
    }
}

void func_80B46A24(EnZf* this) {
    Animation_Change(&this->unk14C, &D_600A3D4, 1.25f, 0.0f, (f32)Animation_GetLastFrame(&D_600A3D4), 2U, -4.0f);
    if (this->actor.params == -2) {
        this->unk14C.playSpeed = 1.75f;
    }
    this->unk3DC = 9;
    this->unk464.base.atFlags &= 0xFFFB;
    Audio_PlayActorSound2(&this->actor, 0x3829U);
    this->actor.speedXZ = 0.0f;
    func_80B44050(this, func_80B46AE0);
}

void func_80B46AE0(EnZf* this, GlobalContext* globalCtx) {
    Player* sp24;
    s16 temp_a0;
    s16 temp_v1;
    s16 var_v0;
    s16 var_v0_2;

    sp24 = globalCtx->actorCtx.actorLists[2].head;
    this->actor.speedXZ = 0.0f;
    if ((s32)this->unk14C.curFrame == 0xA) {
        Audio_PlayActorSound2(&this->actor, 0x382AU);
    }
    if (SkelAnime_Update(&this->unk14C) != 0) {
        EffectBlure_AddSpace(Effect_GetByIndex(this->unk414));
        if ((this->actor.params == -2) && (Actor_IsFacingPlayer(&this->actor, 0x1554) == 0)) {
            func_80B45384(this);
            this->unk3F0 = (s32)((Rand_ZeroOne() * 5.0f) + 5.0f);
            this->unk3F4 = (s16)(s32)((Rand_ZeroOne() * 20.0f) + 100.0f);
            return;
        }
        if ((Rand_ZeroOne() > 0.7f) || (this->actor.xzDistToPlayer >= 120.0f)) {
            func_80B45384(this);
            this->unk3F0 = (s32)((Rand_ZeroOne() * 5.0f) + 5.0f);
            return;
        }
        this->actor.world.rot.y = this->actor.yawTowardsPlayer;
        if (Rand_ZeroOne() > 0.7f) {
            func_80B483E4(this, globalCtx);
            return;
        }
        temp_a0 = this->actor.shape.rot.y;
        var_v0 = sp24->actor.shape.rot.y - temp_a0;
        if (var_v0 < 0) {
            var_v0 *= -1;
        }
        if (var_v0 < 0x2711) {
            temp_v1 = this->actor.yawTowardsPlayer;
            var_v0_2 = temp_v1 - temp_a0;
            if (var_v0_2 < 0) {
                var_v0_2 *= -1;
            }
            if (var_v0_2 >= 0x3E81) {
                this->actor.world.rot.y = temp_v1;
                func_80B483E4(this, globalCtx);
                return;
            }
            if (sp24->stateFlags1 & 0x6010) {
                if (this->actor.isTargeted != 0) {
                    func_80B46A24(this);
                    return;
                }
                func_80B483E4(this, globalCtx);
                return;
            }
            func_80B46A24(this);
            return;
        }
        func_80B483E4(this, globalCtx);
    }
}

void func_80B46D64(EnZf* this) {
    Animation_Change(&this->unk14C, &D_600A3D4, -1.0f, this->unk14C.curFrame - 3.0f, 0.0f, 2U, 0.0f);
    this->unk3DC = 8;
    func_80B44050(this, func_80B46DD4);
}

void func_80B46DD4(EnZf* this, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&this->unk14C) != 0) {
        if (Rand_ZeroOne() > 0.7f) {
            func_80B45384(this);
            return;
        }
        if ((Rand_ZeroOne() > 0.2f) && (func_80B44CF0(globalCtx, this) != 0)) {
            func_80B46A24(this);
            return;
        }
        func_80B483E4(this, globalCtx);
    }
}

void func_80B46E8C(EnZf* this) {
    Animation_Change(&this->unk14C, &D_6009530, -1.0f, 3.0f, 0.0f, 2U, -3.0f);
    this->unk3F0 = 0;
    this->unk3E4 = 1;
    this->unk3DC = 0xB;
    this->actor.velocity.y = 15.0f;
    this->actor.speedXZ = -15.0f;
    Audio_PlayActorSound2(&this->actor, 0x382FU);
    func_80B44050(this, func_80B46F2C);
}

void func_80B46F2C(EnZf* this, GlobalContext* globalCtx) {
    SkelAnime* sp34;
    SkelAnime* temp_a0;
    f32 temp_fv0;

    if (this->unk3F0 != 0) {
        temp_fv0 = this->actor.floorHeight;
        if (this->actor.world.pos.y <= temp_fv0) {
            this->actor.world.pos.y = temp_fv0;
            this->unk3E4 = 0;
            this->actor.velocity.y = 0.0f;
            this->actor.speedXZ = 0.0f;
        }
    }
    temp_a0 = &this->unk14C;
    sp34 = temp_a0;
    if (SkelAnime_Update(temp_a0) != 0) {
        if (this->unk3F0 == 0) {
            Animation_Change(temp_a0, &D_6008C6C, 3.0f, 0.0f, 17.0f, 2U, -3.0f);
            this->unk3F0 = 0xA;
            Audio_PlayActorSound2(&this->actor, 0x382FU);
        } else if (globalCtx->gameplayFrames & 1) {
            func_80B483E4(this, globalCtx);
        } else {
            func_80B45384(this);
        }
    }
    if (!(globalCtx->state.frames & 0x5F)) {
        Audio_PlayActorSound2(&this->actor, 0x3829U);
    }
}

void func_80B47050(EnZf* this) {
    f32 temp_fv0;

    if ((this->actor.bgCheckFlags & 1) &&
        ((temp_fv0 = this->actor.velocity.y, (temp_fv0 == 0.0f)) || (temp_fv0 == -4.0f))) {
        this->actor.speedXZ = 0.0f;
        this->unk3E4 = 0;
    } else {
        this->unk3E4 = 1;
    }
    if (this->unk410 == 0xF) {
        this->unk3F6 = 0x24;
    } else {
        Animation_PlayOnceSetSpeed(&this->unk14C, &D_60157F8, 0.0f);
    }
    Audio_PlayActorSound2(&this->actor, 0x389EU);
    this->unk3DC = 0xE;
    func_80B44050(this, func_80B47120);
}

void func_80B47120(EnZf* this, GlobalContext* globalCtx) {
    f32 temp_fv0;
    s16 temp_a1;
    s16 var_v0;
    s16 var_v1;

    if (this->actor.bgCheckFlags & 2) {
        this->actor.speedXZ = 0.0f;
    }
    if (this->actor.bgCheckFlags & 1) {
        temp_fv0 = this->actor.speedXZ;
        if (temp_fv0 < 0.0f) {
            this->actor.speedXZ = temp_fv0 + 0.05f;
        }
        this->unk3E4 = 0;
    }
    if ((this->actor.colorFilterTimer == 0) && (this->actor.bgCheckFlags & 1)) {
        if (this->actor.colChkInfo.health == 0) {
            func_80B48CEC(this);
            return;
        }
        if ((this->actor.params != -2) || (func_80B44E8C(globalCtx, this) == 0)) {
            if (D_80B4A1B4 != -1) {
                func_80B44DC4(this, globalCtx);
                return;
            }
            temp_a1 = this->actor.shape.rot.y;
            var_v0 = this->actor.wallYaw - temp_a1;
            if (var_v0 < 0) {
                var_v0 *= -1;
            }
            if ((this->actor.params == -2) && (this->actor.bgCheckFlags & 8)) {
                var_v1 = -var_v0;
                if (var_v0 >= 0) {
                    var_v1 = var_v0;
                }
                if ((var_v1 < 0x2EE0) && (this->actor.xzDistToPlayer < 90.0f)) {
                    this->actor.world.rot.y = temp_a1;
                    func_80B48210(this);
                    return;
                }
                goto block_23;
            }
        block_23:
            if (func_80B49C2C(globalCtx, this) == 0) {
                if (this->actor.params != -2) {
                    func_80B44DC4(this, globalCtx);
                    return;
                }
                if ((this->actor.xzDistToPlayer <= 100.0f) && (globalCtx->gameplayFrames & 3) &&
                    (func_80B44CF0(globalCtx, this) != 0)) {
                    func_80B46A24(this);
                    return;
                }
                func_80B44DC4(this, globalCtx);
            }
        }
    }
}

void func_80B47360(EnZf* this, GlobalContext* globalCtx) {
    f32 sp3C;
    PosRot* sp34;
    PosRot* temp_a0;
    f32 temp_fv1;
    f32 var_fv0;

    sp3C = 0.0f;
    var_fv0 = 0.0f;
    temp_fv1 = (f32)Animation_GetLastFrame(&D_60119F4);
    if (this->unk3DC < 0x11) {
        var_fv0 = -4.0f;
    }
    Animation_Change(&this->unk14C, &D_60119F4, 2.0f, 0.0f, temp_fv1, 2U, var_fv0);
    this->unk3DC = 0x12;
    temp_a0 = &this->actor.world;
    this->actor.speedXZ = 0.0f;
    sp34 = temp_a0;
    this->unk3FE = func_80B446A8(&temp_a0->pos, this->unk3FE);
    this->unk402 = func_80B44870(&temp_a0->pos, this->unk3FE, this->unk400, globalCtx);
    this->actor.world.rot.y = this->actor.shape.rot.y;
    func_80B44050(this, func_80B4743C);
}

void func_80B4743C(EnZf* this, GlobalContext* globalCtx) {
    s16 sp2E;
    s16 temp_v1;

    temp_v1 = Actor_WorldYawTowardPoint(&this->actor, &D_80B4A090[this->unk402]) + 0x8000;
    sp2E = temp_v1;
    Math_SmoothStepToS(&this->actor.world.rot.y, temp_v1, 1, 0x3E8, 0);
    this->actor.shape.rot.y = this->actor.world.rot.y;
    if (SkelAnime_Update(&this->unk14C) != 0) {
        this->actor.world.rot.y = sp2E - 0x8000;
        func_80B4779C(this, globalCtx);
        this->unk3FA = 1;
    }
}

void func_80B474E4(EnZf* this) {
    this->unk3E4 = 0;
    Animation_MorphToPlayOnce(&this->unk14C, *D_80B4A280, -4.0f);
    this->unk3DC = 0x14;
    this->actor.speedXZ = 0.0f;
    this->unk40C = 0.0f;
    this->unk408 = 0.0f;
    func_80B44050(this, func_80B47544);
}

void func_80B47544(EnZf* this, GlobalContext* globalCtx) {
    f32 sp40;
    SkelAnime* sp34;
    SkelAnime* temp_a0;
    f32 temp_ft0;
    f32 temp_ft1;
    f32 var_fv0;
    s32 temp_t0;
    s32 temp_v1;

    sp40 = 400.0f;
    Math_SmoothStepToF(&this->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
    Math_SmoothStepToS(&this->actor.shape.rot.y, (s16)(this->actor.yawTowardsPlayer + 0x8000), 1, 0xFA0, 0);
    if (this->actor.world.pos.y >= 420.0f) {
        sp40 = 250.0f;
    }
    if ((this->actor.xzDistToPlayer < sp40) && (this->unk3E4 != 1)) {
        this->actor.shape.rot.y = this->actor.world.rot.y;
        func_80B47360(this, globalCtx);
        return;
    }
    if (this->unk3E4 != 1) {
        func_80B49E4C(globalCtx, this);
    }
    temp_a0 = &this->unk14C;
    sp34 = temp_a0;
    if (SkelAnime_Update(temp_a0) != 0) {
        temp_t0 = this->unk3E4 + 1;
        this->unk3E4 = temp_t0;
        if (temp_t0 >= 3) {
            this->unk3E4 = 0;
        }
        if ((this->unk408 != 0.0f) || (this->unk40C != 0.0f)) {
            this->unk3E4 = 1;
        }
        temp_v1 = this->unk3E4;
        var_fv0 = (f32)Animation_GetLastFrame(D_80B4A280[this->unk3E4]);
        switch (temp_v1) { /* irregular */
            case 0:
                this->actor.velocity.y = 0.0f;
                this->actor.world.pos.y = this->actor.floorHeight;
                break;
            case 1:
                temp_ft1 = this->unk408;
                this->unk408 = 0.0f;
                temp_ft0 = this->unk40C + 10.0f;
                this->unk40C = 0.0f;
                this->actor.speedXZ = temp_ft1;
                this->actor.velocity.y = temp_ft0;
                break;
            case 2:
                var_fv0 = 3.0f;
                this->actor.world.pos.y = this->actor.floorHeight;
                break;
        }
        Animation_Change(sp34, D_80B4A280[this->unk3E4], 1.5f, 0.0f, var_fv0, 2U, 0.0f);
    }
    if (!(globalCtx->gameplayFrames & 0x5F)) {
        Audio_PlayActorSound2(&this->actor, 0x3829U);
    }
}

void func_80B4779C(EnZf* this, GlobalContext* globalCtx) {
    PosRot* sp24;
    PosRot* temp_a0;

    this->unk3E4 = 0;
    Animation_PlayOnce(&this->unk14C, *D_80B4A280);
    this->unk3DC = 0x13;
    temp_a0 = &this->actor.world;
    sp24 = temp_a0;
    this->unk3FE = func_80B446A8(&temp_a0->pos, this->unk3FE);
    this->unk402 = func_80B44870(&temp_a0->pos, this->unk3FE, this->unk400, globalCtx);
    func_80B44050(this, func_80B4781C);
}

void func_80B4781C(EnZf* this, GlobalContext* globalCtx) {
    f32 sp74;
    f32 sp70;
    f32 sp60;
    s16 sp5A;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    PosRot* sp44;
    PosRot* temp_a0;
    f32 var_fs0;
    f32 var_fs0_2;
    f32 var_fv0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a3;
    s32 var_v1;
    u16 temp_v0;

    sp70 = 1.0f;
    var_fs0 = 550.0f;
    sp74 = Actor_WorldDistXZToPoint(&this->actor, &D_80B4A090[this->unk402]);
    sp54 = this->unk3E4;
    if (!(globalCtx->gameplayFrames & 0x5F)) {
        Audio_PlayActorSound2(&this->actor, 0x3829U);
    }
    if (this->actor.world.pos.y >= 420.0f) {
        var_fs0 = 280.0f;
    }
    sp5A = Actor_WorldYawTowardPoint(&this->actor, &D_80B4A090[this->unk402]);
    var_a3 = this->unk3E4;
    switch (var_a3) { /* irregular */
        case 0:
            this->actor.world.rot.y = sp5A;
            this->actor.shape.rot.y = sp5A + 0x8000;
            D_80B4AB30 = 0;
            this->unk400 = this->unk3FE;
            temp_v1 = func_80B44058(this, globalCtx, 107.0f) == 0;
            sp50 = temp_v1;
            temp_v1_2 = temp_v1 | ((func_80B44058(this, globalCtx, 220.0f) == 0) * 2);
            this->unk3E4 += 1;
            if (temp_v1_2 != 1) {
                if (temp_v1_2 != 2) {
                    if (temp_v1_2 == 3) {
                        goto block_11;
                    }
                    var_v1 = 0x14;
                    var_fs0_2 = 107.0f + 10.0f;
                    var_fv0 = 8.0f + 1.2f;
                loop_16:
                    sp4C = var_v1;
                    sp60 = var_fv0;
                    if (func_80B44058(this, globalCtx, var_fs0_2) == 0) {
                        this->actor.speedXZ = var_fv0;
                        this->actor.velocity.y = 12.0f;
                    } else {
                        var_fs0_2 += 10.0f;
                        var_v1 -= 1;
                        var_fv0 += 1.2f;
                        if (var_v1 >= 0) {
                            goto loop_16;
                        }
                    }
                    if (this->actor.speedXZ == 0.0f) {
                        func_80B474E4(this);
                    }
                } else {
                    this->actor.velocity.y = 15.0f;
                    this->actor.speedXZ = 20.0f;
                }
            } else {
            block_11:
                this->actor.velocity.y = 12.0f;
                if (this->actor.bgCheckFlags & 8) {
                    this->actor.velocity.y += 8.0f;
                }
                this->actor.speedXZ = 8.0f;
            }
            var_a3 = this->unk3E4;
            break;
        case 1:
            temp_v0 = this->actor.bgCheckFlags;
            if ((temp_v0 & 2) || (temp_v0 & 1)) {
                Audio_PlayActorSound2(&this->actor, 0x3828U);
                this->actor.velocity.y = 0.0f;
                this->actor.world.pos.y = this->actor.floorHeight;
                this->actor.speedXZ = 0.0f;
                Actor_SpawnFloorDustRing(globalCtx, &this->actor, &this->unk4F0, 3.0f, 2, 2.0f, 0, 0, 0U);
                Actor_SpawnFloorDustRing(globalCtx, &this->actor, &this->unk4E4, 3.0f, 2, 2.0f, 0, 0, 0U);
                if (var_fs0 <= this->actor.xzDistToPlayer) {
                    func_80B474E4(this);
                } else {
                    temp_a0 = &this->actor.world;
                    if (sp74 < 80.0f) {
                        sp44 = temp_a0;
                        this->unk3FE = func_80B446A8(&temp_a0->pos, this->unk3FE);
                        this->unk402 = func_80B44870(&temp_a0->pos, this->unk3FE, this->unk400, globalCtx);
                    }
                }
                this->unk3E4 = 0;
                sp70 = 2.0f;
            } else {
                Math_SmoothStepToS(&this->actor.world.rot.y, sp5A, 1, 0xFA0, 0);
                this->actor.shape.rot.y = this->actor.world.rot.y + 0x8000;
                D_80B4AB30 += 1;
            }
            var_a3 = this->unk3E4;
            break;
        case 2:
            if (this->unk14C.endFrame == this->unk14C.curFrame) {
                this->unk3E4 = 0;
                var_a3 = 0;
            }
            break;
    }
    if (sp54 != var_a3) {
        Animation_PlayOnceSetSpeed(&this->unk14C, D_80B4A280[var_a3], sp70);
    }
    SkelAnime_Update(&this->unk14C);
}

void func_80B47C64(EnZf* this, GlobalContext* globalCtx) {
    PosRot* sp24;
    PosRot* temp_a0;

    Animation_PlayOnce(&this->unk14C, &D_601366C);
    this->actor.world.rot.y += 0x8000;
    this->unk3DC = 0x15;
    temp_a0 = &this->actor.world;
    this->actor.speedXZ = 0.0f;
    sp24 = temp_a0;
    this->unk3FE = func_80B446A8(&temp_a0->pos, this->unk3FE);
    this->unk402 = func_80B44870(&temp_a0->pos, this->unk3FE, this->unk400, globalCtx);
    func_80B44050(this, func_80B47CF8);
}

void func_80B47CF8(EnZf* this, GlobalContext* globalCtx) {
    s16 sp2E;

    sp2E = this->actor.yawTowardsPlayer;
    if (this->unk14C.curFrame >= 26.0f) {
        Math_SmoothStepToS(&this->actor.shape.rot.y, sp2E, 1, 0x1770, 0);
    }
    if (SkelAnime_Update(&this->unk14C) != 0) {
        Audio_PlayActorSound2(&this->actor, 0x3829U);
        this->unk3E4 = -1;
        this->actor.world.rot.y = sp2E;
        func_80B45384(this);
    }
    if (this->unk14C.curFrame == 22.0f) {
        this->unk3FA = 0;
    }
}

void func_80B47DA8(EnZf* this) {
    f32 temp_fv0;

    Animation_Change(&this->unk14C, &D_60157F8, 1.5f, 0.0f, (f32)Animation_GetLastFrame(&D_60157F8), 2U, -4.0f);
    if ((this->actor.bgCheckFlags & 1) &&
        ((temp_fv0 = this->actor.velocity.y, (temp_fv0 == 0.0f)) || (temp_fv0 == -4.0f))) {
        this->actor.speedXZ = -4.0f;
        this->unk3E4 = 0;
    } else {
        this->unk3E4 = 1;
    }
    if (this->actor.params == -2) {
        this->unk14C.playSpeed = 4.5f;
    }
    if (this->actor.params < 0) {
        this->actor.world.rot.y = this->actor.yawTowardsPlayer;
    }
    Audio_PlayActorSound2(&this->actor, 0x382BU);
    this->unk3DC = 0x10;
    func_80B44050(this, func_80B47EB4);
}

void func_80B47EB4(EnZf* this, GlobalContext* globalCtx) {
    f32 temp_fv0;
    s16 var_v0;
    s16 var_v1;
    u16 temp_v1;

    if (this->actor.bgCheckFlags & 2) {
        this->actor.speedXZ = 0.0f;
    }
    if (this->actor.bgCheckFlags & 1) {
        temp_fv0 = this->actor.speedXZ;
        if (temp_fv0 < 0.0f) {
            this->actor.speedXZ = temp_fv0 + 0.05f;
        }
        this->unk3E4 = 0;
    }
    Math_SmoothStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 1, 0x1194, 0);
    if (((this->actor.params != -2) || (func_80B44E8C(globalCtx, this) == 0)) &&
        (SkelAnime_Update(&this->unk14C) != 0) && (temp_v1 = this->actor.bgCheckFlags, ((temp_v1 & 1) != 0))) {
        if (D_80B4A1B4 != -1) {
            if (this->unk410 == 0xD) {
                D_80B4A1B0 += 1;
                return;
            }
            this->actor.world.rot.y = this->actor.shape.rot.y;
            if ((func_80B44058(this, globalCtx, 135.0f) == 0) && (this->actor.xzDistToPlayer < 90.0f)) {
                func_80B48210(this);
                return;
            }
            if ((this->actor.xzDistToPlayer <= 100.0f) && !(globalCtx->gameplayFrames & 3)) {
                func_80B46A24(this);
                return;
            }
            func_80B44DC4(this, globalCtx);
            return;
        }
        var_v0 = this->actor.wallYaw - this->actor.shape.rot.y;
        if (var_v0 < 0) {
            var_v0 *= -1;
        }
        if ((this->actor.params == -2) && (temp_v1 & 8)) {
            var_v1 = -var_v0;
            if (var_v0 >= 0) {
                var_v1 = var_v0;
            }
            if ((var_v1 < 0x2EE0) && (this->actor.xzDistToPlayer < 90.0f)) {
                func_80B48210(this);
                return;
            }
            goto block_29;
        }
    block_29:
        if (func_80B49C2C(globalCtx, this) == 0) {
            if (this->actor.params != -2) {
                this->actor.world.rot.y = this->actor.shape.rot.y;
                if ((func_80B44058(this, globalCtx, 135.0f) == 0) && (this->actor.xzDistToPlayer < 90.0f)) {
                    func_80B48210(this);
                    return;
                }
                if ((this->actor.xzDistToPlayer <= 100.0f) && !(globalCtx->gameplayFrames & 3)) {
                    func_80B46A24(this);
                    return;
                }
                func_80B44DC4(this, globalCtx);
                return;
            }
            if ((this->actor.xzDistToPlayer <= 100.0f) && !(globalCtx->gameplayFrames & 3) &&
                (func_80B44CF0(globalCtx, this) != 0)) {
                func_80B46A24(this);
                return;
            }
            func_80B44DC4(this, globalCtx);
        }
    }
}

void func_80B48210(EnZf* this) {
    Animation_Change(&this->unk14C, &D_6009530, 1.0f, 0.0f, 3.0f, 2U, 0.0f);
    this->unk3F0 = 0;
    this->unk3E4 = 1;
    this->unk3DC = 0x16;
    this->actor.velocity.y = 22.0f;
    this->actor.speedXZ = 7.5f;
    Audio_PlayActorSound2(&this->actor, 0x382FU);
    this->actor.world.rot.y = this->actor.shape.rot.y;
    func_80B44050(this, func_80B482B8);
}

void func_80B482B8(EnZf* this, GlobalContext* globalCtx) {
    SkelAnime* sp30;
    SkelAnime* temp_a0;
    s16 temp_v0;

    Math_SmoothStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 1, 0xFA0, 1);
    if (this->actor.velocity.y >= 5.0f) {
        func_800355B8(globalCtx, &this->unk4F0);
        func_800355B8(globalCtx, &this->unk4E4);
    }
    temp_a0 = &this->unk14C;
    sp30 = temp_a0;
    if (SkelAnime_Update(temp_a0) != 0) {
        if (this->unk3F0 == 0) {
            Animation_Change(temp_a0, &D_600A3D4, 3.0f, 0.0f, 13.0f, 2U, -4.0f);
            this->unk3F0 = 0xA;
            return;
        }
        if (this->actor.bgCheckFlags & 3) {
            temp_v0 = this->actor.yawTowardsPlayer;
            this->actor.velocity.y = 0.0f;
            this->actor.shape.rot.y = temp_v0;
            this->actor.world.rot.y = temp_v0;
            this->actor.speedXZ = 0.0f;
            this->actor.world.pos.y = this->actor.floorHeight;
            func_80B46A24(this);
            Audio_PlayActorSound2(&this->actor, 0x382AU);
            this->unk14C.curFrame = 13.0f;
        }
    }
}

void func_80B483E4(EnZf* this, GlobalContext* globalCtx) {
    s16 sp2E;
    Actor* sp28;
    f32 temp_ft3;
    s16 temp_v1;

    if ((this->actor.params < 0) ||
        (Actor_TestFloorInDirection(&this->actor, globalCtx, 40.0f, (s16)(this->actor.shape.rot.y + 0x3FFF)) != 0) ||
        (Actor_TestFloorInDirection(&this->actor, globalCtx, -40.0f, (s16)(this->actor.shape.rot.y + 0x3FFF)) != 0)) {
        Animation_PlayLoop(&this->unk14C, &D_6016388);
        sp28 = globalCtx->actorCtx.actorLists[2].head;
        Math_SmoothStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 1, 0xFA0, 1);
        temp_v1 = sp28->shape.rot.y;
        sp2E = temp_v1;
        if (Math_SinS((s16)(temp_v1 - this->actor.shape.rot.y)) >= 0.0f) {
            this->actor.speedXZ = -6.0f;
        } else if (Math_SinS((s16)(temp_v1 - this->actor.shape.rot.y)) < 0.0f) {
            this->actor.speedXZ = 6.0f;
        }
        this->unk408 = 0.0f;
        this->unk3E4 = 0;
        this->actor.world.rot.y = this->actor.shape.rot.y + 0x3FFF;
        temp_ft3 = Rand_ZeroOne() * 10.0f;
        this->unk3DC = 0xC;
        this->unk3F0 = (s32)(temp_ft3 + 5.0f);
        func_80B44050(this, func_80B48578);
        return;
    }
    func_80B456B4(this, globalCtx);
}

void func_80B48578(EnZf* this, GlobalContext* globalCtx) {
    s16 sp56;
    Actor* sp50;
    s32 sp4C;
    s32 sp48;
    f32 sp40;
    f32 sp34;
    void* sp28;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 var_fa0;
    f32 var_ft2;
    s16 temp_a0;
    s16 temp_t0;
    s16 temp_v1;
    s16 temp_v1_2;
    s16 var_v0_3;
    s16 var_v0_4;
    s16 var_v1;
    s32 temp_v0;
    s32 var_v0;
    s32 var_v0_2;
    void* temp_v1_3;
    void* temp_v1_4;
    void* var_v1_2;

    sp50 = globalCtx->actorCtx.actorLists[2].head;
    sp40 = 0.0f;
    Math_SmoothStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 1, 0xBB8, 1);
    temp_t0 = sp50->shape.rot.y;
    if (this->actor.params >= 0) {
        if (this->unk3F8 != 0) {
            this->actor.speedXZ = -this->actor.speedXZ;
        }
    } else {
        var_v0 = this->actor.bgCheckFlags & 8;
        if (var_v0 == 0) {
            sp56 = temp_t0;
            if (Actor_TestFloorInDirection(&this->actor, globalCtx, this->actor.speedXZ,
                                           (s16)(this->actor.shape.rot.y + 0x3FFF)) == 0) {
                var_v0 = this->actor.bgCheckFlags & 8;
                goto block_6;
            }
        } else {
        block_6:
            if (var_v0 != 0) {
                if (this->actor.speedXZ >= 0.0f) {
                    var_v0_2 = (this->actor.shape.rot.y + 0x3FFF) << 0x10;
                } else {
                    var_v0_2 = (this->actor.shape.rot.y - 0x3FFF) << 0x10;
                }
                var_v0_3 = this->actor.wallYaw - (var_v0_2 >> 0x10);
            } else {
                var_v0_3 = 0;
                this->actor.speedXZ *= -0.8f;
            }
            var_v1 = -var_v0_3;
            if (var_v0_3 >= 0) {
                var_v1 = var_v0_3;
            }
            if (var_v1 >= 0x4001) {
                this->actor.speedXZ *= -0.8f;
                temp_fv0 = this->actor.speedXZ;
                if (temp_fv0 < 0.0f) {
                    this->actor.speedXZ = temp_fv0 - 0.5f;
                } else {
                    this->actor.speedXZ = temp_fv0 + 0.5f;
                }
            }
        }
    }
    if (Math_SinS((s16)(temp_t0 - this->actor.shape.rot.y)) >= 0.0f) {
        this->actor.speedXZ += 0.125f;
    } else {
        this->actor.speedXZ -= 0.125f;
    }
    this->actor.world.rot.y = this->actor.shape.rot.y + 0x4000;
    if (Actor_OtherIsTargeted(globalCtx, &this->actor) != 0) {
        sp40 = 100.0f;
    }
    temp_fv0_2 = this->actor.xzDistToPlayer;
    if (temp_fv0_2 <= (70.0f + sp40)) {
        Math_SmoothStepToF(&this->unk408, -4.0f, 1.0f, 1.5f, 0.0f);
    } else if ((90.0f + sp40) < temp_fv0_2) {
        Math_SmoothStepToF(&this->unk408, 4.0f, 1.0f, 1.5f, 0.0f);
    } else {
        Math_SmoothStepToF(&this->unk408, 0.0f, 1.0f, 5.65f, 0.0f);
    }
    temp_fv1 = this->unk408;
    if ((temp_fv1 != 0.0f) && (func_80B441C4(this, globalCtx, temp_fv1) == 0)) {
        this->actor.world.pos.x += Math_SinS(this->actor.shape.rot.y) * this->unk408;
        this->actor.world.pos.z += Math_CosS(this->actor.shape.rot.y) * this->unk408;
    }
    temp_fv0_3 = this->actor.speedXZ;
    temp_fv1_2 = this->unk408;
    if (temp_fv0_3 >= 0.0f) {
        var_fa0 = temp_fv0_3;
    } else {
        var_fa0 = -temp_fv0_3;
    }
    if (temp_fv1_2 >= 0.0f) {
        sp34 = temp_fv1_2;
    } else {
        sp34 = -temp_fv1_2;
    }
    if (sp34 <= var_fa0) {
        var_ft2 = -temp_fv0_3 * 0.75f;
        goto block_42;
    }
    if (this->unk14C.playSpeed < 0.0f) {
        this->unk14C.playSpeed = temp_fv1_2 * -0.75f;
    } else {
        var_ft2 = temp_fv1_2 * 0.75f;
    block_42:
        this->unk14C.playSpeed = var_ft2;
    }
    sp4C = (s32)this->unk14C.curFrame;
    SkelAnime_Update(&this->unk14C);
    temp_fv0_4 = this->unk14C.playSpeed;
    if (temp_fv0_4 >= 0.0f) {
        sp34 = temp_fv0_4;
    } else {
        sp34 = -temp_fv0_4;
    }
    sp48 = (s32)(this->unk14C.curFrame - sp34);
    if (temp_fv0_4 >= 0.0f) {
        sp34 = temp_fv0_4;
    } else {
        sp34 = -temp_fv0_4;
    }
    this->unk3FE = func_80B446A8(&this->actor.world.pos, this->unk3FE);
    if (func_80B446A8(&sp50->world.pos, -1) != this->unk3FE) {
        temp_v1 = this->actor.params;
        this->actor.speedXZ = 0.0f;
        if ((temp_v1 >= 0) && (temp_v1 == D_80B4A1B4)) {
            func_80B474E4(this);
            return;
        }
        func_80B456B4(this, globalCtx);
        return;
    }
    if ((this->actor.params != -2) || (func_80B44E8C(globalCtx, this) == 0)) {
        temp_v0 = this->unk3F0;
        if (temp_v0 == 0) {
            temp_a0 = this->actor.shape.rot.y;
            temp_v1_2 = this->actor.params;
            var_v0_4 = sp50->shape.rot.y - temp_a0;
            if (var_v0_4 < 0) {
                var_v0_4 *= -1;
            }
            if (var_v0_4 >= 0x3A98) {
                if ((temp_v1_2 >= 0) && (temp_v1_2 == D_80B4A1B4)) {
                    func_80B474E4(this);
                } else {
                    func_80B45384(this);
                    this->unk3F0 = (s32)((Rand_ZeroOne() * 5.0f) + 1.0f);
                }
                goto block_79;
            }
            if ((temp_v1_2 >= 0) && (temp_v1_2 == D_80B4A1B4)) {
                func_80B474E4(this);
                goto block_79;
            }
            this->actor.world.rot.y = temp_a0;
            temp_v1_3 = globalCtx + 0x10000;
            if ((this->actor.xzDistToPlayer <= 100.0f) && !(globalCtx->gameplayFrames & 3) &&
                (sp28 = temp_v1_3, (func_80B44CF0(globalCtx, this) != 0))) {
                sp28 = temp_v1_3;
                func_80B46A24(this);
                var_v1_2 = temp_v1_3;
            } else {
                temp_fv0_5 = this->actor.xzDistToPlayer;
                temp_v1_4 = globalCtx + 0x10000;
                if ((temp_fv0_5 < 280.0f) && (temp_fv0_5 > 240.0f) &&
                    (sp28 = temp_v1_4, (func_80B44058(this, globalCtx, 191.9956f) == 0)) &&
                    !(globalCtx->gameplayFrames & 1)) {
                    sp28 = temp_v1_4;
                    func_80B45E30(this);
                    var_v1_2 = temp_v1_4;
                } else {
                    sp28 = temp_v1_4;
                    func_80B456B4(this, globalCtx);
                    var_v1_2 = temp_v1_4;
                }
            }
        } else {
            this->unk3F0 = temp_v0 - 1;
        block_79:
            var_v1_2 = globalCtx + 0x10000;
        }
        if ((sp4C != (s32)this->unk14C.curFrame) &&
            (((sp48 < 0xE) && (((s32)sp34 + sp4C) >= 0x10)) || ((sp48 < 0x1B) && (((s32)sp34 + sp4C) >= 0x1D)))) {
            sp28 = var_v1_2;
            Audio_PlayActorSound2(&this->actor, 0x382EU);
        }
        if (!(/*var_v1_2->unk1DE4*/ globalCtx->gameplayFrames & 0x5F)) {
            Audio_PlayActorSound2(&this->actor, 0x3829U);
        }
    }
}

typedef struct UnkActor {
    Actor actor;
    char pad14C[0x3F4 - 0x14C];
    UNK_TYPE unk3F4;
} UnkActor;

void func_80B48CEC(EnZf* this) {
    Actor* temp_v0;
    Actor* temp_v0_2;
    Actor* temp_v0_3;
    f32 temp_fv0;

    Animation_Change(&this->unk14C, &D_6014E60, 1.5f, 0.0f, (f32)Animation_GetLastFrame(&D_6014E60), 2U, -4.0f);
    if ((this->actor.bgCheckFlags & 1) &&
        ((temp_fv0 = this->actor.velocity.y, (temp_fv0 == 0.0f)) || (temp_fv0 == -4.0f))) {
        this->actor.speedXZ = 0.0f;
        this->unk3E4 = 0;
    } else {
        this->unk3E4 = 1;
    }
    this->unk3DC = 0xF;
    this->actor.flags &= ~1;
    if (D_80B4A1B4 != -1) {
        temp_v0 = this->actor.prev;
        if (temp_v0 != NULL) {
            ((UnkActor*)temp_v0)->unk3F4 = 0x5A;
            temp_v0_2 = this->actor.prev;
            if ((s32)temp_v0_2->colChkInfo.health < 3) {
                temp_v0_2->colChkInfo.health = 3;
            }
        } else {
            ((UnkActor*)this->actor.next)->unk3F4 = 0x5A;
            temp_v0_3 = this->actor.next;
            if ((s32)temp_v0_3->colChkInfo.health < 3) {
                temp_v0_3->colChkInfo.health = 3;
            }
        }
    }
    D_80B4A1B0 = 0;
    Audio_PlayActorSound2(&this->actor, 0x382DU);
    func_80B44050(this, func_80B48E50);
}

void func_80B48E50(EnZf* this, GlobalContext* globalCtx) {
    s32 temp_ft1;
    u8 temp_t4;
    u8 temp_v0;

    if (this->actor.bgCheckFlags & 2) {
        this->actor.speedXZ = 0.0f;
    }
    if (this->actor.bgCheckFlags & 1) {
        Math_SmoothStepToF(&this->actor.speedXZ, 0.0f, 1.0f, 0.15f, 0.0f);
        this->unk3E4 = 0;
    }
    if (SkelAnime_Update(&this->unk14C) != 0) {
        if (this->actor.category != 6) {
            if ((this->actor.params >= 0) && (D_80B4A1B4 == -1)) {
                Flags_SetSwitch(globalCtx, (s32)this->unk3FC);
                func_800F5B58();
            } else {
                D_80B4A1B4 = -1;
            }
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &this->actor, 6U);
        }
        temp_v0 = this->unk404;
        temp_t4 = temp_v0 - 5;
        if (temp_v0 != 0) {
            this->unk404 = temp_t4;
            this->actor.shape.shadowAlpha = temp_t4;
            return;
        }
        Actor_Kill(&this->actor);
        return;
    }
    temp_ft1 = (s32)this->unk14C.curFrame;
    if ((temp_ft1 == 0xA) || (temp_ft1 == 0x12)) {
        Audio_PlayActorSound2(&this->actor, 0x387AU);
    }
}

void func_80B48F90(EnZf* this, GlobalContext* globalCtx) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 var_v1;
    s16 var_v1_2;

    if ((this->actor.params == -2) && (this->unk3DC == 3)) {
        temp_v0 = this->unk3F4;
        if (temp_v0 != 0) {
            this->unk3EC = (s16)(s32)(Math_SinS((s16)(temp_v0 * 0x578)) * 10920.0f);
            return;
        }
    }
    temp_v0_2 = this->actor.yawTowardsPlayer - (this->unk3EC + this->actor.shape.rot.y);
    if (temp_v0_2 < -0x7D0) {
        this->unk3EE = -0x7D0;
    } else {
        var_v1 = temp_v0_2;
        if (temp_v0_2 >= 0x7D1) {
            var_v1 = 0x7D0;
        }
        this->unk3EE = var_v1;
    }
    this->unk3EC += this->unk3EE;
    temp_v0_3 = this->unk3EC;
    if (temp_v0_3 < -0x1CD7) {
        this->unk3EC = -0x1CD7;
        return;
    }
    var_v1_2 = temp_v0_3;
    if (temp_v0_3 >= 0x1CD8) {
        var_v1_2 = 0x1CD7;
    }
    this->unk3EC = var_v1_2;
}

void func_80B490B4(EnZf* this, GlobalContext* globalCtx) {
    s16 sp2A;
    s16 temp_v1;
    s16 var_a3;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v0_4;

    temp_v0 = this->unk418.base.acFlags;
    if ((temp_v0 & 2) && (this->unk3DC < 0xF) &&
        ((temp_v1 = this->actor.params, this->unk418.base.acFlags = temp_v0 & 0xFFFD, (temp_v1 < 0)) ||
         (temp_v1 != D_80B4A1B4)) &&
        (temp_v0_2 = this->actor.colChkInfo.damageEffect, (temp_v0_2 != 6))) {
        this->unk410 = temp_v0_2;
        Actor_SetDropFlag(&this->actor, &this->unk418.info, 0);
        temp_v0_3 = this->actor.colChkInfo.damageEffect;
        if ((temp_v0_3 == 1) || (temp_v0_3 == 0xF)) {
            if (this->unk3DC != 0xE) {
                Actor_SetColorFilter(&this->actor, 0, 0x78, 0, 0x50);
                Actor_ApplyDamage(&this->actor);
                func_80B47050(this);
            }
        } else {
            Audio_PlayActorSound2(&this->actor, 0x3829U);
            Actor_SetColorFilter(&this->actor, 0x4000, 0xFF, 0, 8);
            if (Actor_ApplyDamage(&this->actor) == 0) {
                sp2A = 0x40;
                func_80B48CEC(this);
                var_a3 = 0x40;
                if (this->actor.params == -2) {
                    var_a3 = 0xE0;
                }
                Item_DropCollectibleRandom(globalCtx, &this->actor, &this->actor.world.pos, var_a3);
                Enemy_StartFinishingBlow(globalCtx, &this->actor);
                return;
            }
            if (D_80B4A1B4 != -1) {
                temp_v0_4 = this->actor.colChkInfo.health;
                if (((temp_v0_4 + this->actor.colChkInfo.damage) >= 4) && ((s32)temp_v0_4 < 4)) {
                    this->unk410 = 0xD;
                }
            }
            func_80B47DA8(this);
        }
    }
}

void EnZf_Update(Actor* thisx, GlobalContext* globalCtx) {
    ColliderCylinder* sp28;
    Actor* temp_v0_2;
    ColliderCylinder* temp_a1;
    f32 temp_fv0;
    f32 temp_fv0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s32 temp_v0;
    u8 temp_v0_5;
    EnZf* this = (EnZf*)thisx;

    func_80B490B4(this, globalCtx);
    if (this->actor.colChkInfo.damageEffect != 6) {
        this->unk3F8 = 0;
        if ((this->unk3E4 != 1) && (this->unk3DC != 0x13)) {
            temp_fv0 = this->actor.speedXZ;
            if (temp_fv0 != 0.0f) {
                this->unk3F8 = func_80B44058(this, globalCtx, temp_fv0 * 1.5f);
            }
            if (this->unk3F8 == 0) {
                this->unk3F8 = func_80B44058(this, globalCtx, 0.0f);
            }
        }
        if (this->unk3F8 == 0) {
            Actor_MoveForward(&this->actor);
        }
        Actor_UpdateBgCheckInfo(globalCtx, &this->actor, 25.0f, 30.0f, 60.0f, 0x1D);
        if (!(this->actor.bgCheckFlags & 1)) {
            this->unk3E4 = 1;
        }
        this->unk3E8(this, globalCtx);
    }
    if ((s32)this->actor.colChkInfo.health > 0) {
        temp_v0 = this->unk3DC;
        if ((temp_v0 != 9) && (temp_v0 != 0xE)) {
            func_80B48F90(this, globalCtx);
        }
        if ((D_80B4A1B0 != 0) && (this->actor.params != D_80B4A1B4)) {
            func_80B47360(this, globalCtx);
            D_80B4A1B4 = this->actor.params;
            D_80B4A1B0 = 0;
            temp_v0_2 = this->actor.prev;
            if (temp_v0_2 != NULL) {
                ((UnkActor*)temp_v0_2)->unk3F4 = 0x5A;
            } else {
                ((UnkActor*)this->actor.next)->unk3F4 = 0x5A;
            }
        }
    }
    if (this->unk3DC >= 0xF) {
        Math_SmoothStepToS(&this->unk3EC, 0, 1, 0x7D0, 0);
        if ((this->unk3DC < 0x15) && (this->unk3F4 == 1) && (this->actor.bgCheckFlags & 1)) {
            if ((s32)this->actor.colChkInfo.health > 0) {
                func_80B47C64(this, globalCtx);
            }
            this->unk3F4 -= 1;
        }
        temp_v0_3 = this->unk3F4;
        if (temp_v0_3 >= 2) {
            this->unk3F4 = temp_v0_3 - 1;
        }
    }
    this->actor.focus.pos.y = this->actor.world.pos.y;
    this->actor.focus.pos.x = this->actor.world.pos.x;
    this->actor.focus.pos.y += 40.0f;
    this->actor.focus.pos.z = this->actor.world.pos.z;
    if ((s32)this->actor.colChkInfo.health > 0) {
        temp_a1 = &this->unk418;
        if (this->unk404 == 0xFF) {
            sp28 = temp_a1;
            Collider_UpdateCylinder(&this->actor, temp_a1);
            if ((this->actor.floorHeight == this->actor.world.pos.y) && (this->unk3DC < 0x11)) {
                CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &sp28->base);
            }
            temp_v0_4 = this->actor.params;
            if (((temp_v0_4 < 0) || (temp_v0_4 != D_80B4A1B4)) &&
                ((this->actor.colorFilterTimer == 0) || !(this->actor.colorFilterParams & 0x4000))) {
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &sp28->base);
            }
        }
    }
    if ((this->unk3DC == 9) && (temp_fv0_2 = this->unk14C.curFrame, (temp_fv0_2 >= 14.0f)) && (temp_fv0_2 <= 20.0f)) {
        temp_v0_5 = this->unk464.base.atFlags;
        if (!(temp_v0_5 & 4) && !(this->unk464.base.acFlags & 2)) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &this->unk464.base);
            return;
        }
        this->unk464.base.atFlags = temp_v0_5 & 0xFFFB;
        this->unk464.base.acFlags &= 0xFFFD;
        func_80B46D64(this);
    }
}

s32 func_80B495FC(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3f* arg3, Vec3s* arg4, EnZf* this, Gfx** gfx) {
    switch (arg1) { /* irregular */
        default:
            return 0;
        case 5:
            arg4->y -= this->unk3EC;
            return 0;
        case 15:
            if (this->unk3FA != 0) {
                *arg2 = D_600E198;
                return 0;
            }
            return 0;
        case 33:
            if (this->unk3FA != 0) {
                *arg2 = D_6010060;
            }
            /* Duplicate return node #9. Try simplifying control flow for better match */
            return 0;
    }
}

void func_80B49688(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3s* arg3, EnZf* this) {
    Vec3f sp54;
    Vec3f sp48;
    ColliderQuadDim* sp38;
    Vec3f* sp34;
    Vec3f* sp30;
    Vec3f* sp2C;
    ColliderQuadDim* temp_a1_2;
    Vec3f* temp_a1;
    Vec3f* temp_a1_3;
    Vec3f* temp_a3;
    f32 temp_fv0;
    s32 var_s1;

    var_s1 = -1;
    if (arg1 == 0xF) {
        temp_a1 = &this->unk464.dim.quad[1];
        sp34 = temp_a1;
        Matrix_MultVec3f(&D_80B4A2BC, temp_a1);
        temp_a1_2 = &this->unk464.dim;
        sp38 = temp_a1_2;
        Matrix_MultVec3f(&D_80B4A2C8, temp_a1_2->quad);
        temp_a1_3 = &this->unk464.dim.quad[3];
        sp2C = temp_a1_3;
        Matrix_MultVec3f(&D_80B4A2D4, temp_a1_3);
        temp_a3 = &this->unk464.dim.quad[2];
        sp30 = temp_a3;
        Matrix_MultVec3f(&D_80B4A2E0, temp_a3);
        Collider_SetQuadVertices(&this->unk464, temp_a1_2->quad, sp34, temp_a3, sp2C);
        Matrix_MultVec3f(&D_80B4A2A4, &sp54);
        Matrix_MultVec3f(&D_80B4A2B0, &sp48);
        if (this->unk3DC == 9) {
            temp_fv0 = this->unk14C.curFrame;
            if (temp_fv0 < 14.0f) {
                EffectBlure_AddSpace(Effect_GetByIndex(this->unk414));
            } else if (temp_fv0 < 20.0f) {
                EffectBlure_AddVertex(Effect_GetByIndex(this->unk414), &sp54, &sp48);
            }
        }
    } else {
        Actor_SetFeetPos(&this->actor, arg1, 0x2D, &D_80B4A298, 0x26, &D_80B4A298);
    }
    if (arg1 != 0x26) {
        if (arg1 == 0x2D) {
            Matrix_MultVec3f(&D_80B4A298, this + 0x4F0);
        }
    } else {
        Matrix_MultVec3f(&D_80B4A298, this + 0x4E4);
    }
    if (this->unk3F6 != 0) {
        switch (arg1) {
            case 9:
                var_s1 = 0;
                break;
            case 10:
                var_s1 = 1;
                break;
            case 25:
                var_s1 = 2;
                break;
            case 16:
                var_s1 = 3;
                break;
            case 23:
                var_s1 = 4;
                break;
            case 48:
                var_s1 = 5;
                break;
            case 14:
                var_s1 = 6;
                break;
            case 39:
                var_s1 = 7;
                break;
            case 43:
                var_s1 = 8;
                break;
        }
        if (var_s1 >= 0) {
            Matrix_MultVec3f(&D_80B4A2EC, this + (var_s1 * 0xC) + 0x4FC);
        }
    }
}

void EnZf_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx* sp64;
    Gfx* temp_v0;
    Gfx* temp_v0_2;
    Gfx* temp_v0_3;
    Gfx* temp_v0_4;
    Gfx* temp_v0_5;
    Gfx* temp_v0_6;
    GraphicsContext* temp_a1;
    s16 temp_v1;
    EnZf* this = (EnZf*)thisx;

    temp_a1 = globalCtx->state.gfxCtx;
    Graph_OpenDisps(&sp64, temp_a1, "../z_en_zf.c", 0xDCD);
    func_8002EBCC(&this->actor, globalCtx, 1);
    D_80B4A2F8->words.w0 = 0xD7000002;
    D_80B4A2F8->words.w1 = (gGameInfo->data[0x361] & 0xFFFF) | (gGameInfo->data[0x360] << 0x10);
    temp_v0 = temp_a1->polyOpa.p;
    temp_a1->polyOpa.p = temp_v0 + 8;
    temp_v0->words.w1 = (u32)D_80B4A2F8;
    temp_v0->words.w0 = 0xDB060020;
    if (this->unk404 == 0xFF) {
        func_80093D18(globalCtx->state.gfxCtx);
        temp_v0_2 = temp_a1->polyOpa.p;
        temp_a1->polyOpa.p = temp_v0_2 + 8;
        temp_v0_2->words.w0 = 0xFB000000;
        temp_v0_2->words.w1 = (u32)this->unk404;
        temp_v0_3 = temp_a1->polyOpa.p;
        temp_a1->polyOpa.p = temp_v0_3 + 8;
        temp_v0_3->words.w1 = (u32)&D_80116280[2];
        temp_v0_3->words.w0 = 0xDB060024;
        temp_a1->polyOpa.p = SkelAnime_Draw(
            globalCtx, this->unk14C.skeleton, this->unk14C.jointTable,
            (s32(*)(GlobalContext*, s32, Gfx**, Vec3f*, Vec3s*, void*, Gfx**))func_80B495FC,
            (void (*)(GlobalContext*, s32, Gfx**, Vec3s*, void*, Gfx**))func_80B49688, this, temp_a1->polyOpa.p);
        if (this->unk3F6 != 0) {
            this->unk3F6 -= 1;
            temp_v1 = this->unk3F6;
            this->actor.colorFilterTimer += 1;
            if (!(temp_v1 & 3)) {
                EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &this->actor, this + ((temp_v1 >> 2) * 0xC) + 0x4FC, 0x96,
                                               0x96, 0x96, 0xFA, 0xEB, 0xF5, 0xFF, 1.4f);
            }
        }
    } else {
        func_80093D84(globalCtx->state.gfxCtx);
        temp_v0_4 = temp_a1->polyXlu.p;
        temp_a1->polyXlu.p = temp_v0_4 + 8;
        temp_v0_4->words.w1 = 0;
        temp_v0_4->words.w0 = 0xE7000000;
        temp_v0_5 = temp_a1->polyXlu.p;
        temp_a1->polyXlu.p = temp_v0_5 + 8;
        temp_v0_5->words.w0 = 0xFB000000;
        temp_v0_5->words.w1 = (u32)this->unk404;
        temp_v0_6 = temp_a1->polyXlu.p;
        temp_a1->polyXlu.p = temp_v0_6 + 8;
        temp_v0_6->words.w1 = (u32)D_80116280;
        temp_v0_6->words.w0 = 0xDB060024;
        temp_a1->polyXlu.p = SkelAnime_Draw(
            globalCtx, this->unk14C.skeleton, this->unk14C.jointTable,
            (s32(*)(GlobalContext*, s32, Gfx**, Vec3f*, Vec3s*, void*, Gfx**))func_80B495FC,
            (void (*)(GlobalContext*, s32, Gfx**, Vec3s*, void*, Gfx**))func_80B49688, this, temp_a1->polyXlu.p);
    }
    Graph_CloseDisps(&sp64, globalCtx->state.gfxCtx, "../z_en_zf.c", 0xE11);
}

void func_80B49B60(EnZf* this, f32 arg1) {
    s32 temp_ft4;

    Animation_MorphToLoop(&this->unk14C, &D_6016388, -1.0f);
    temp_ft4 = (s32)((Rand_ZeroOne() * 10.0f) + 8.0f);
    this->unk3F0 = temp_ft4;
    if (this->actor.params == -2) {
        this->actor.speedXZ = 2.0f * arg1;
        this->unk3F0 = temp_ft4 / 2;
    } else {
        this->actor.speedXZ = arg1;
    }
    this->unk3E4 = 0;
    this->unk3DC = 0xC;
    this->actor.world.rot.y = this->actor.shape.rot.y + 0x3FFF;
    func_80B44050(this, func_80B48578);
}

s32 func_80B49C2C(GlobalContext* globalCtx, EnZf* this) {
    Actor* sp1C;
    s16 sp1A;
    s16 sp18;
    Actor* temp_v0;
    s16 temp_t7;
    s16 var_t0;
    s16 var_t0_2;
    s16 var_v1;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;

    temp_v0 = Actor_GetProjectileActor(globalCtx, &this->actor, 600.0f);
    if (temp_v0 != NULL) {
        sp1C = temp_v0;
        temp_t7 = this->actor.shape.rot.y;
        temp_t1 = (Actor_WorldYawTowardActor(&this->actor, temp_v0) - temp_t7) << 0x10;
        this->actor.world.rot.y = temp_t7 + 0x3FFF;
        temp_t1_2 = temp_t1 >> 0x10;
        sp1A = (s16)temp_t1_2;
        sp18 = 0;
        var_t0 = sp18;
        if (func_80B44058(this, globalCtx, -8.0f) != 0) {
            var_t0 = 1;
        }
        sp18 = var_t0;
        sp1A = (s16)temp_t1_2;
        var_t0_2 = var_t0;
        if (func_80B44058(this, globalCtx, 8.0f) != 0) {
            var_t0_2 |= 2;
        }
        this->actor.world.rot.y = this->actor.shape.rot.y;
        if ((((this->actor.xzDistToPlayer < 90.0f) || (var_t0_2 == 3)) &&
             (sp18 = var_t0_2, sp1A = (s16)temp_t1_2, (func_80B44058(this, globalCtx, 135.0f) == 0))) ||
            (sp1C->id == 0x66)) {
            func_80B48210(this);
            return 1;
        }
        var_v1 = var_t0_2;
        this->actor.world.rot.y = this->actor.shape.rot.y + 0x3FFF;
        if (var_t0_2 == 0) {
            var_v1 = globalCtx->gameplayFrames & 1;
        }
        var_v0 = -temp_t1_2;
        if (temp_t1_2 >= 0) {
            var_v0 = temp_t1_2;
        }
        if (var_v0 >= 0x2000) {
            var_v0_2 = -temp_t1_2;
            if (temp_t1_2 >= 0) {
                var_v0_2 = temp_t1_2;
            }
            if (var_v0_2 >= 0x6000) {
                goto block_18;
            }
            var_v0_3 = -temp_t1_2;
            if (temp_t1_2 >= 0) {
                var_v0_3 = temp_t1_2;
            }
            if (var_v0_3 < 0x5FFF) {
                if (var_v1 & 1) {
                    func_80B49B60(this, 4.0f);
                    return 1;
                }
                func_80B49B60(this, -4.0f);
                goto block_27;
            }
        block_27:
            return 1;
        }
    block_18:
        if (var_v1 & 1) {
            func_80B49B60(this, 8.0f);
            return 1;
        }
        func_80B49B60(this, -8.0f);
        return 1;
    }
    return 0;
}

s32 func_80B49E4C(GlobalContext* globalCtx, EnZf* this) {
    s16 sp22;
    s16 sp20;
    s16 sp1E;
    s16 sp1C;
    Actor* temp_v0;
    s16 temp_t7;
    s16 var_t0;
    s16 var_t0_2;
    s16 var_v1;
    s16 var_v1_2;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;

    sp1C = 0;
    temp_v0 = Actor_GetProjectileActor(globalCtx, &this->actor, 600.0f);
    if (temp_v0 != NULL) {
        temp_t7 = this->actor.shape.rot.y;
        temp_a3 = (Actor_WorldYawTowardActor(&this->actor, temp_v0) - temp_t7) << 0x10;
        this->actor.world.rot.y = temp_t7 + 0x3FFF;
        temp_a3_2 = temp_a3 >> 0x10;
        sp22 = (s16)temp_a3_2;
        sp20 = 0;
        var_t0 = sp20;
        if (func_80B44058(this, globalCtx, -70.0f) != 0) {
            var_t0 = 1;
        }
        sp22 = (s16)temp_a3_2;
        sp20 = var_t0;
        var_t0_2 = var_t0;
        if (func_80B44058(this, globalCtx, 70.0f) != 0) {
            var_t0_2 |= 2;
        }
        var_v0 = -temp_a3_2;
        this->actor.speedXZ = 0.0f;
        if (temp_a3_2 >= 0) {
            var_v0 = temp_a3_2;
        }
        if (var_v0 >= 0x2000) {
            var_v0_2 = -temp_a3_2;
            if (temp_a3_2 >= 0) {
                var_v0_2 = temp_a3_2;
            }
            if (var_v0_2 >= 0x6000) {
                goto block_11;
            }
            var_v0_3 = -temp_a3_2;
            if (temp_a3_2 >= 0) {
                var_v0_3 = temp_a3_2;
            }
            if (var_v0_3 < 0x5FFF) {
                if (var_t0_2 == 0) {
                    var_v1 = -6;
                    if (globalCtx->gameplayFrames & 1) {
                        var_v1 = 6;
                    }
                    sp1E = var_v1;
                } else {
                    switch (var_t0_2) { /* switch 2; irregular */
                        case 1:         /* switch 2 */
                            sp1E = 6;
                            break;
                        case 2: /* switch 2 */
                            sp1E = -6;
                            break;
                        case 3: /* switch 2 */
                            sp1C = 0xA;
                            sp1E = 0;
                            break;
                    }
                }
            }
        } else {
        block_11:
            if (var_t0_2 == 0) {
                var_v1_2 = -6;
                if (globalCtx->gameplayFrames & 1) {
                    var_v1_2 = 6;
                }
                sp1E = var_v1_2;
            } else {
                switch (var_t0_2) { /* switch 1; irregular */
                    case 1:         /* switch 1 */
                        sp1E = 6;
                        break;
                    case 2: /* switch 1 */
                        sp1E = -6;
                        break;
                    case 3: /* switch 1 */
                        sp1C = 5;
                        sp1E = 0;
                        break;
                }
            }
        }
        this->unk408 = (f32)sp1E;
        this->unk40C = (f32)sp1C;
        return 1;
    }
    return 0;
}

#else

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

#endif
