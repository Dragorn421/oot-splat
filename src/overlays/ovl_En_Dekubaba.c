#include "z_en_dekubaba.h"
// #include "objects/gameplay_keep/gameplay_keep.h"

#define FLAGS 0x00000005

#define THIS ((EnDekubaba*)thisx)

void EnDekubaba_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDekubaba_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDekubaba_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDekubaba_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_809E5A38(EnDekubaba* this);
void func_809E5ABC(EnDekubaba* this);
void func_809E5D28(EnDekubaba* this);
void func_809E5E58(EnDekubaba* this);
void func_809E5F44(EnDekubaba* this);
void func_809E5F9C(EnDekubaba* this);
void func_809E5FBC(EnDekubaba* this);
void func_809E6000(EnDekubaba* this);
void func_809E6078(EnDekubaba* this);
void func_809E60A8(EnDekubaba* this, s32 arg1);
void func_809E6170(EnDekubaba* this);
void func_809E61E0(EnDekubaba* this);
void func_809E6264(EnDekubaba* this);
void func_809E63EC(EnDekubaba* this);
void func_809E645C(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E64F4(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E65A0(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E6A04(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E6DCC(EnDekubaba* this);
void func_809E6ED4(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E7104(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E738C(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E7458(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E77E4(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E78DC(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E79EC(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E7A88(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E7BB0(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E7F14(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E80D8(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E8140(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E858C(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E86B8(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E89E4(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E8AD8(EnDekubaba* this, GlobalContext* globalCtx);
void func_809E8C0C(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3s* arg3, EnDekubaba* this);

extern Gfx D_4049210[];
extern AnimationHeader D_6000208;
extern AnimationHeader D_60002B8;
extern Gfx D_60010F0[];
extern Gfx D_6001330[];
extern Gfx D_6001828[];
extern SkeletonHeader D_6002A40;
extern Gfx D_6003070[];

static Vec3f D_809E8EA0 = { 0.0f, 0.0f, 0.0f };

const ActorInit En_Dekubaba_InitVars = {
    ACTOR_EN_DEKUBABA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DEKUBABA,
    sizeof(EnDekubaba),
    (ActorFunc)EnDekubaba_Init,
    (ActorFunc)EnDekubaba_Destroy,
    (ActorFunc)EnDekubaba_Update,
    (ActorFunc)EnDekubaba_Draw,
};

static ColliderJntSphElementInit D_809E8ECC[7] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_HARD,
            BUMP_ON,
            OCELEM_ON,
        },
        { 1, { { 0, 100, 1000 }, 15 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 51, { { 0, 0, 1500 }, 8 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 52, { { 0, 0, 500 }, 8 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 53, { { 0, 0, 1500 }, 8 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 54, { { 0, 0, 500 }, 8 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 55, { { 0, 0, 1500 }, 8 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 56, { { 0, 0, 500 }, 8 }, 100 },
    },
};

static ColliderJntSphInit D_809E8FC8 = {
    {
        COLTYPE_HIT6,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    7,
    D_809E8ECC,
};

static CollisionCheckInfoInit D_809E8FD8 = { 2, 0x19, 0x19, 0xFF };
static DamageTable D_809E8FE0 = {
    {
        0x10, 2,    1, 2, 0xE2, 2, 2,    2,    0xF1, 0xF2, 0xF4, 0x24, 2, 2, 2, 2,
        2,    0x24, 0, 0, 0,    0, 0xF1, 0xF4, 0xF2, 0xF2, 0xF8, 0xF4, 0, 0, 4, 0,
    },
};
static DamageTable D_809E9000 = {
    {
        0x10, 2,    1, 2, 0xE2, 2, 2,    0x10, 0xF1, 0xF2, 0xF4, 0x24, 2, 2, 2, 2,
        2,    0x24, 0, 0, 0,    0, 0xF1, 0xF4, 0xF2, 0xF2, 0xF8, 0xF4, 0, 0, 4, 0,
    },
};
static InitChainEntry D_809E9020[] = {
    ICHAIN_F32(targetArrowOffset, 1500, ICHAIN_STOP),
};
static Color_RGBA8 D_809E9024 = { 0x69, 0xFF, 0x69, 0xFF };
static Color_RGBA8 D_809E9028 = { 0x96, 0xFA, 0x96, 0 };
static u32 D_809E902C[5] = { (u32)D_6001330, 0x06001628, (u32)D_6001828, 0, 0 };

void EnDekubaba_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 var_a0;
    EnDekubaba* this = (EnDekubaba*)thisx;

    Actor_ProcessInitChain(&this->actor, D_809E9020);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 22.0f);
    SkelAnime_Init(globalCtx, &this->unk17C, &D_6002A40, &D_60002B8, this->unk1D0, this->unk200, 8);
    Collider_InitJntSph(globalCtx, &this->unk238);
    Collider_SetJntSph(globalCtx, &this->unk238, &this->actor, &D_809E8FC8, this->unk258);
    if (this->actor.params == 1) {
        this->unk230 = 2.50f;
        for (var_a0 = 0; var_a0 < D_809E8FC8.count; var_a0++) {
            this->unk238.elements[var_a0].dim.worldSphere.radius /*unk36*/ =
                this->unk238.elements[var_a0].dim.modelSphere.radius /*unk2E*/ =
                    (s16)(s32)(D_809E8ECC[var_a0].dim.modelSphere.radius * 2.5f);
        }
        if (gSaveContext.linkAge != 0) {
            D_809E9000.table[0x1B] = 4;
        }
        CollisionCheck_SetInfo(&this->actor.colChkInfo, &D_809E9000, &D_809E8FD8);
        this->actor.colChkInfo.health = 4;
        this->actor.naviEnemyId = 8;
        this->actor.targetMode = 2;
    } else {
        this->unk230 = 1.0f;
        for (var_a0 = 0; var_a0 < D_809E8FC8.count; var_a0++) {
            this->unk238.elements[var_a0].dim.worldSphere.radius /*unk36*/ =
                this->unk238.elements[var_a0].dim.modelSphere.radius /*unk2E*/;
        }
        if (gSaveContext.linkAge != 0) {
            D_809E8FE0.table[0x1B] = 4;
        }
        CollisionCheck_SetInfo(&this->actor.colChkInfo, &D_809E8FE0, &D_809E8FD8);
        this->actor.naviEnemyId = 7;
        this->actor.targetMode = 1;
    }
    func_809E5ABC(this);
    this->unk1C6 = 0;
    this->unk170 = this->actor.home.pos;
    this->unk234 = NULL;
}

void EnDekubaba_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnDekubaba* this = (EnDekubaba*)thisx;
    Collider_DestroyJntSph(globalCtx, &this->unk238);
}

void func_809E5A38(EnDekubaba* this) {
    s32 i;

    for (i = 1; i < 7; i++) {
        this->unk238.elements[i].info.bumperFlags &= ~1;
    }
}

void func_809E5ABC(EnDekubaba* this) {
    ColliderJntSphElement* temp_v0_2;
    s16 temp_v0;
    s32 i;

    this->actor.shape.rot.x = -0x4000;
    temp_v0 = this->actor.shape.rot.x;
    this->unk1CE = temp_v0;
    this->unk1CC = temp_v0;
    this->unk1CA = temp_v0;
    this->actor.world.pos.x = this->actor.home.pos.x;
    this->actor.world.pos.z = this->actor.home.pos.z;
    this->actor.world.pos.y = this->actor.home.pos.y + (14.0f * this->unk230);
    Actor_SetScale(&this->actor, this->unk230 * 0.01f * 0.5f);
    this->unk238.base.colType = 0xC;
    this->unk238.base.acFlags |= 4;
    this->unk1C6 = 0x2D;
    for (i = 1; i < 7; i++) {
        temp_v0_2 = &this->unk238.elements[i];
        temp_v0_2->dim.worldSphere.center.x = (s16)(s32)this->actor.world.pos.x;
        temp_v0_2->dim.worldSphere.center.y = (s16)this->actor.world.pos.y - 7;
        temp_v0_2->dim.worldSphere.center.z = (s16)(s32)this->actor.world.pos.z;
    }
    this->unk1C0 = func_809E64F4;
}

void func_809E5D28(EnDekubaba* this) {
    s32 i;

    Animation_Change(&this->unk17C, &D_60002B8, (f32)Animation_GetLastFrame(&D_60002B8) * 0.06666667f, 0.0f,
                     (f32)Animation_GetLastFrame(&D_60002B8), 2U, 0.0f);
    this->unk1C6 = 0xF;
    for (i = 2; i < 7; i++) {
        this->unk238.elements[i].info.ocElemFlags |= 1;
    }
    this->unk238.base.colType = 6;
    this->unk238.base.acFlags &= ~4;
    Audio_PlayActorSound2(&this->actor, 0x39E2U);
    this->unk1C0 = func_809E65A0;
}

void func_809E5E58(EnDekubaba* this) {
    s32 i;

    Animation_Change(&this->unk17C, &D_60002B8, -1.5f, (f32)Animation_GetLastFrame(&D_60002B8), 0.0f, 2U, -3.0f);
    this->unk1C6 = 0xF;
    for (i = 2; i < 7; i++) {
        this->unk238.elements[i].info.ocElemFlags &= ~1;
    }
    this->unk1C0 = func_809E6A04;
}

void func_809E5F44(EnDekubaba* this) {
    this->unk1C6 = Animation_GetLastFrame(&D_60002B8) * 2;
    Animation_MorphToLoop(&this->unk17C, &D_60002B8, -3.0f);
    this->unk1C0 = func_809E6ED4;
}

void func_809E5F9C(EnDekubaba* this) {
    this->unk1C6 = 8;
    this->unk1C0 = func_809E738C;
    this->unk17C.playSpeed = 0.0f;
}

void func_809E5FBC(EnDekubaba* this) {
    Animation_PlayOnce(&this->unk17C, &D_6000208);
    this->unk1C6 = 0;
    this->unk1C0 = func_809E7104;
}

void func_809E6000(EnDekubaba* this) {
    Animation_Change(&this->unk17C, &D_6000208, 1.0f, 15.0f, (f32)Animation_GetLastFrame(&D_6000208), 2U, -3.0f);
    this->unk1C6 = 0;
    this->unk1C0 = func_809E7458;
}

void func_809E6078(EnDekubaba* this) {
    this->unk1C6 = 9;
    this->unk238.base.acFlags |= 1;
    this->unk1C0 = func_809E77E4;
    this->unk17C.playSpeed = -1.0f;
}

void func_809E60A8(EnDekubaba* this, s32 arg1) {
    Animation_MorphToPlayOnce(&this->unk17C, &D_6000208, -5.0f);
    this->unk1C6 = (s16)arg1;
    this->unk238.base.acFlags &= 0xFFFE;
    Actor_SetScale(&this->actor, this->unk230 * 0.01f);
    if (arg1 == 2) {
        Actor_SetColorFilter(&this->actor, 0, 0x9B, 0, 0x3E);
    } else {
        Actor_SetColorFilter(&this->actor, 0x4000, 0xFF, 0, 0x2A);
    }
    this->unk1C0 = func_809E78DC;
}

void func_809E6170(EnDekubaba* this) {
    this->unk1C6 = 0;
    this->unk17C.playSpeed = 0.0f;
    this->actor.gravity = -0.8f;
    this->actor.velocity.y = 4.0f;
    this->actor.world.rot.y = this->actor.shape.rot.y + 0x8000;
    this->actor.speedXZ = this->unk230 * 3.0f;
    this->unk238.base.acFlags &= 0xFFFE;
    this->actor.flags |= 0x30;
    this->unk1C0 = func_809E7BB0;
}

void func_809E61E0(EnDekubaba* this) {
    Animation_Change(&this->unk17C, &D_60002B8, -1.5f, (f32)Animation_GetLastFrame(&D_60002B8), 0.0f, 2U, -3.0f);
    this->unk238.base.acFlags &= 0xFFFE;
    this->unk1C0 = func_809E7F14;
}

void func_809E6264(EnDekubaba* this) {
    s32 i;

    for (i = 1; i < 7; i++) {
        this->unk238.elements[i].info.bumperFlags |= 1;
    }
    if (this->unk1C6 == 1) {
        Animation_Change(&this->unk17C, &D_60002B8, 4.0f, 0.0f, (f32)Animation_GetLastFrame(&D_60002B8), 0U, -3.0f);
        this->unk1C6 = 0x28;
    } else {
        Animation_Change(&this->unk17C, &D_60002B8, 0.0f, 0.0f, (f32)Animation_GetLastFrame(&D_60002B8), 0U, -3.0f);
        this->unk1C6 = 0x3C;
    }
    this->actor.world.pos.x = this->actor.home.pos.x;
    this->actor.world.pos.y = this->actor.home.pos.y + (60.0f * this->unk230);
    this->actor.world.pos.z = this->actor.home.pos.z;
    this->unk1C0 = func_809E79EC;
}

void func_809E63EC(EnDekubaba* this) {
    this->unk1C8 = -0x6000;
    this->unk1CE = -0x5000;
    this->unk1CC = -0x4800;
    func_809E5A38(this);
    Actor_SetColorFilter(&this->actor, 0x4000, 0xFF, 0, 0x23);
    this->unk238.base.acFlags &= 0xFFFE;
    this->unk1C0 = func_809E7A88;
}

void func_809E645C(EnDekubaba* this, GlobalContext* arg1) {
    Actor_SetScale(&this->actor, 0.03f);
    this->actor.shape.rot.x -= 0x4000;
    this->actor.shape.yOffset = 1000.0f;
    this->actor.gravity = 0.0f;
    this->actor.velocity.y = 0.0f;
    this->actor.shape.shadowScale = 3.0f;
    Actor_ChangeCategory(arg1, &arg1->actorCtx, &this->actor, 8U);
    this->actor.flags &= ~0x20;
    this->unk1C6 = 0xC8;
    this->unk1C0 = func_809E80D8;
}

void func_809E64F4(EnDekubaba* this, GlobalContext* arg1) {
    f32 temp_fv1;

    if (this->unk1C6 != 0) {
        this->unk1C6 -= 1;
    }
    temp_fv1 = this->unk230;
    this->actor.world.pos.x = this->actor.home.pos.x;
    this->actor.world.pos.z = this->actor.home.pos.z;
    this->actor.world.pos.y = this->actor.home.pos.y + (14.0f * temp_fv1);
    if ((this->unk1C6 == 0) && (this->actor.xzDistToPlayer < (200.0f * temp_fv1)) &&
        (fabsf(this->actor.yDistToPlayer) < (30.0f * temp_fv1))) {
        func_809E5D28(this);
    }
}

#ifdef NON_MATCHING

void func_809E65A0(EnDekubaba* this, GlobalContext* globalCtx) {
    Actor* sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    PosRot* sp38;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 var_fa0;
    f32 var_fa1;
    s16 temp_v0;
    s16 temp_v0_2;

    sp64 = globalCtx->actorCtx.actorLists[2].head;
    temp_v0 = this->unk1C6;
    if (temp_v0 != 0) {
        this->unk1C6 = temp_v0 - 1;
    }
    SkelAnime_Update(&this->unk17C);
    temp_fv1 = this->unk230 * 0.01f * (0.5f + (((f32)(0xF - this->unk1C6) * 0.5f) / 15.0f));
    this->actor.scale.z = temp_fv1;
    this->actor.scale.y = temp_fv1;
    this->actor.scale.x = temp_fv1;
    Math_ScaledStepToS(&this->actor.shape.rot.x, 0x1800, 0x800);
    temp_fv0 = (f32)(0xF - this->unk1C6) * 0.06666667f;
    if (temp_fv0 > 0.7f) {
        var_fa1 = 0.7f;
    } else {
        var_fa1 = temp_fv0;
    }
    sp5C = (sinf(var_fa1 * 3.1415927f) * 32.0f) + 14.0f;
    temp_v0_2 = this->actor.shape.rot.x;
    if (temp_v0_2 < -0x38E3) {
        var_fa0 = 0.0f;
    } else if (temp_v0_2 < -0x238E) {
        Math_ScaledStepToS(&this->unk1CA, -0x5555, 0x38E);
        var_fa0 = Math_CosS(this->unk1CA) * 20.0f;
    } else if (temp_v0_2 < -0xE38) {
        Math_ScaledStepToS(&this->unk1CA, -0xAAA, 0x38E);
        Math_ScaledStepToS(&this->unk1CC, -0x5555, 0x38E);
        Math_ScaledStepToS(&this->unk1CE, -0x5555, 0x222);
        sp40 = Math_CosS(this->unk1CC);
        sp44 = Math_CosS(this->unk1CA);
        sp48 = Math_CosS(this->unk1CE);
        sp4C = Math_SinS(this->unk1CC);
        sp50 = Math_SinS(this->unk1CA);
        var_fa0 = (((sp5C - (20.0f * (-sp50 - sp4C))) * sp48) / -Math_SinS(this->unk1CE)) + (20.0f * (sp44 + sp40));
    } else {
        Math_ScaledStepToS(&this->unk1CA, -0xAAA, 0x38E);
        Math_ScaledStepToS(&this->unk1CC, -0x31C7, 0x222);
        Math_ScaledStepToS(&this->unk1CE, -0x5555, 0x222);
        sp40 = Math_CosS(this->unk1CC);
        sp44 = Math_CosS(this->unk1CA);
        sp48 = Math_CosS(this->unk1CE);
        sp4C = Math_SinS(this->unk1CC);
        sp50 = Math_SinS(this->unk1CA);
        var_fa0 = (((sp5C - (20.0f * (-sp50 - sp4C))) * sp48) / -Math_SinS(this->unk1CE)) + (20.0f * (sp44 + sp40));
    }
    if (this->unk1C6 < 0xA) {
        sp60 = var_fa0;
        Math_ApproachS(&this->actor.shape.rot.y, Math_Vec3f_Yaw(&this->actor.home.pos, &sp64->world.pos), 2, 0xE38);
    }
    this->actor.world.pos.y = this->actor.home.pos.y + (sp5C * this->unk230);
    sp60 = var_fa0;
    sp38 = &this->actor.home;
    sp58 = Math_SinS(this->actor.shape.rot.y) * (var_fa0 * this->unk230);
    temp_ft4 = this->unk230;
    temp_ft5 = Math_CosS(this->actor.shape.rot.y) * (sp60 * temp_ft4);
    this->actor.world.pos.x = this->actor.home.pos.x + sp58;
    this->actor.world.pos.z = this->actor.home.pos.z + temp_ft5;
    EffectSsHahen_SpawnBurst(globalCtx, &sp38->pos, temp_ft4 * 3.0f, 0, (s16)(s32)(temp_ft4 * 12.0f),
                             (s16)(s32)(temp_ft4 * 5.0f), 1, -1, 0xA, NULL);
    if (this->unk1C6 == 0) {
        if (Math_Vec3f_DistXZ(&sp38->pos, &sp64->world.pos) < (240.0f * this->unk230)) {
            func_809E5F9C(this);
            return;
        }
        func_809E5E58(this);
    }
}

void func_809E6A04(EnDekubaba* this, GlobalContext* globalCtx) {
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 var_fa0;
    f32 var_fa1;
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = this->unk1C6;
    if (temp_v0 != 0) {
        this->unk1C6 = temp_v0 - 1;
    }
    SkelAnime_Update(&this->unk17C);
    temp_fv1 = this->unk230 * 0.01f * (0.5f + ((f32)this->unk1C6 * 0.033333335f));
    this->actor.scale.z = temp_fv1;
    this->actor.scale.y = temp_fv1;
    this->actor.scale.x = temp_fv1;
    Math_ScaledStepToS(&this->actor.shape.rot.x, -0x4000, 0x300);
    temp_fv0 = (f32)this->unk1C6 * 0.033f;
    if (temp_fv0 > 0.7f) {
        var_fa1 = 0.7f;
    } else {
        var_fa1 = temp_fv0;
    }
    sp58 = (sinf(var_fa1 * 3.1415927f) * 32.0f) + 14.0f;
    temp_v0_2 = this->actor.shape.rot.x;
    if (temp_v0_2 < -0x38E3) {
        var_fa0 = 0.0f;
    } else if (temp_v0_2 < -0x238E) {
        Math_ScaledStepToS(&this->unk1CA, -0x4000, 0x555);
        var_fa0 = Math_CosS(this->unk1CA) * 20.0f;
    } else if (temp_v0_2 < -0xE38) {
        Math_ScaledStepToS(&this->unk1CA, -0x5555, 0x555);
        Math_ScaledStepToS(&this->unk1CC, -0x4000, 0x555);
        Math_ScaledStepToS(&this->unk1CE, -0x4000, 0x333);
        sp3C = Math_CosS(this->unk1CC);
        sp40 = Math_CosS(this->unk1CA);
        sp44 = Math_CosS(this->unk1CE);
        sp48 = Math_SinS(this->unk1CC);
        sp4C = Math_SinS(this->unk1CA);
        var_fa0 = (((sp58 - (20.0f * (-sp4C - sp48))) * sp44) / -Math_SinS(this->unk1CE)) + (20.0f * (sp40 + sp3C));
    } else {
        Math_ScaledStepToS(&this->unk1CA, -0x5555, 0x555);
        Math_ScaledStepToS(&this->unk1CC, -0x5555, 0x333);
        Math_ScaledStepToS(&this->unk1CE, -0x4000, 0x333);
        sp3C = Math_CosS(this->unk1CC);
        sp40 = Math_CosS(this->unk1CA);
        sp44 = Math_CosS(this->unk1CE);
        sp48 = Math_SinS(this->unk1CC);
        sp4C = Math_SinS(this->unk1CA);
        var_fa0 = (((sp58 - (20.0f * (-sp4C - sp48))) * sp44) / -Math_SinS(this->unk1CE)) + (20.0f * (sp40 + sp3C));
    }
    this->actor.world.pos.y = this->actor.home.pos.y + (sp58 * this->unk230);
    sp5C = var_fa0;
    sp54 = Math_SinS(this->actor.shape.rot.y) * (var_fa0 * this->unk230);
    temp_ft4 = this->unk230;
    temp_ft5 = Math_CosS(this->actor.shape.rot.y) * (sp5C * temp_ft4);
    this->actor.world.pos.x = this->actor.home.pos.x + sp54;
    this->actor.world.pos.z = this->actor.home.pos.z + temp_ft5;
    EffectSsHahen_SpawnBurst(globalCtx, &this->actor.home.pos, temp_ft4 * 3.0f, 0, (s16)(s32)(temp_ft4 * 12.0f),
                             (s16)(s32)(temp_ft4 * 5.0f), 1, -1, 0xA, NULL);
    if (this->unk1C6 == 0) {
        func_809E5ABC(this);
    }
}

void func_809E6DCC(EnDekubaba* this) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    sp24 = Math_CosS(this->unk1CC);
    sp28 = Math_CosS(this->unk1CA);
    sp2C = (Math_CosS(this->unk1CE) + (sp28 + sp24)) * 20.0f;
    this->actor.world.pos.x = (Math_SinS(this->actor.shape.rot.y) * (sp2C * this->unk230)) + this->actor.home.pos.x;
    sp24 = Math_SinS(this->unk1CC);
    sp28 = Math_SinS(this->unk1CA);
    this->actor.world.pos.y =
        this->actor.home.pos.y - ((Math_SinS(this->unk1CE) + (sp28 + sp24)) * 20.0f * this->unk230);
    this->actor.world.pos.z = (Math_CosS(this->actor.shape.rot.y) * (sp2C * this->unk230)) + this->actor.home.pos.z;
}

void func_809E6ED4(EnDekubaba* this, GlobalContext* globalCtx) {
    Actor* sp34;
    SkelAnime* sp2C;
    PosRot* sp28;
    PosRot* sp24;
    PosRot* temp_a0_2;
    PosRot* temp_a1;
    SkelAnime* temp_a0;
    f32 temp_fv1;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 var_t2;

    temp_a0 = &this->unk17C;
    sp2C = temp_a0;
    sp34 = globalCtx->actorCtx.actorLists[2].head;
    SkelAnime_Update(temp_a0);
    if ((Animation_OnFrame(temp_a0, 0.0f) != 0) || (Animation_OnFrame(temp_a0, 12.0f) != 0)) {
        if (this->actor.params == 1) {
            Audio_PlayActorSound2(&this->actor, 0x385CU);
        } else {
            Audio_PlayActorSound2(&this->actor, 0x3860U);
        }
    }
    temp_v0 = this->unk1C6;
    if (temp_v0 != 0) {
        this->unk1C6 = temp_v0 - 1;
    }
    temp_a0_2 = &this->actor.home;
    sp28 = temp_a0_2;
    temp_a1 = &sp34->world;
    sp24 = temp_a1;
    Math_ApproachS(&this->actor.shape.rot.y, Math_Vec3f_Yaw(&temp_a0_2->pos, &temp_a1->pos), 2,
                   (s16)(((s16)this->unk1C6 % 5) * 0x222));
    temp_v0_2 = this->unk1C6;
    if (temp_v0_2 < 0xA) {
        this->unk1CA += 0x16C;
        this->unk1CC += 0x16C;
        this->unk1CE += 0xB6;
        this->actor.shape.rot.x += 0x222;
    } else {
        if (temp_v0_2 < 0x14) {
            var_t2 = this->actor.shape.rot.x + 0x16C;
            this->unk1CA -= 0x16C;
            this->unk1CC += 0x111;
            goto block_14;
        }
        if (temp_v0_2 < 0x1E) {
            this->unk1CC -= 0x111;
            this->actor.shape.rot.x -= 0xB6;
        } else {
            var_t2 = this->actor.shape.rot.x - 0x16C;
            this->unk1CC -= 0xB6;
            this->unk1CE += 0xB6;
        block_14:
            this->actor.shape.rot.x = var_t2;
        }
    }
    func_809E6DCC(this);
    temp_fv1 = this->unk230;
    if ((240.0f * temp_fv1) < Math_Vec3f_DistXZ(&sp28->pos, &sp24->pos)) {
        func_809E5E58(this);
        return;
    }
    if ((this->unk1C6 == 0) || (this->actor.xzDistToPlayer < (80.0f * temp_fv1))) {
        func_809E5F9C(this);
    }
}

void func_809E7104(EnDekubaba* this, GlobalContext* globalCtx) {
    s32 sp4C;
    s16 sp4A;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    SkelAnime* sp34;
    SkelAnime* temp_a0;
    f32 temp_ft5;
    s16 temp_v1;
    s32 temp_ft3;
    s32 temp_v1_2;
    s32 temp_v1_3;

    temp_a0 = &this->unk17C;
    sp34 = temp_a0;
    SkelAnime_Update(temp_a0);
    temp_v1 = this->unk1C6;
    if (temp_v1 == 0) {
        if (Animation_OnFrame(temp_a0, 1.0f) != 0) {
            if (this->actor.params == 1) {
                Audio_PlayActorSound2(&this->actor, 0x385DU);
            } else {
                Audio_PlayActorSound2(&this->actor, 0x3861U);
            }
        }
        Math_ScaledStepToS(&this->actor.shape.rot.x, 0, 0x222);
        temp_ft3 = (s32)(this->unk17C.curFrame * 10.0f);
        sp4A = (s16)temp_ft3;
        temp_v1_2 = Math_ScaledStepToS(&this->unk1CA, -0xE38, (s16)((s16)temp_ft3 + 0x38E)) & 1;
        sp4C = temp_v1_2;
        temp_v1_3 = temp_v1_2 & Math_ScaledStepToS(&this->unk1CC, -0xE38, (s16)(sp4A + 0x71C));
        sp4C = temp_v1_3;
        if (temp_v1_3 & Math_ScaledStepToS(&this->unk1CE, -0xE38, (s16)(sp4A + 0xE38))) {
            Animation_PlayLoopSetSpeed(sp34, &D_60002B8, 4.0f);
            temp_ft5 = Math_SinS(this->actor.shape.rot.y) * 5.0f;
            sp40 = 0.0f;
            sp3C = temp_ft5;
            sp44 = Math_CosS(this->actor.shape.rot.y) * 5.0f;
            func_8002829C(globalCtx, &this->actor.world.pos, (Vec3f*)&sp3C, &D_809E8EA0, &D_809E9024, &D_809E9028, 1,
                          (s16)(s32)(this->unk230 * 100.0f));
            this->unk1C6 = 1;
            this->unk238.base.acFlags |= 1;
        }
    } else if (temp_v1 >= 0xB) {
        func_809E6000(this);
    } else {
        this->unk1C6 = temp_v1 + 1;
        if ((this->unk1C6 >= 4) && (Actor_IsFacingPlayer(&this->actor, 0x16C) == 0)) {
            Math_ApproachS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 0xF, 0x71C);
        }
        if ((Animation_OnFrame(sp34, 0.0f) != 0) || (Animation_OnFrame(sp34, 12.0f) != 0)) {
            if (this->actor.params == 1) {
                Audio_PlayActorSound2(&this->actor, 0x385CU);
            } else {
                Audio_PlayActorSound2(&this->actor, 0x3860U);
            }
        }
    }
    func_809E6DCC(this);
}

void func_809E738C(EnDekubaba* this, GlobalContext* globalCtx) {
    Actor* sp2C;
    Actor* temp_v1;
    s16 temp_v0;

    temp_v0 = this->unk1C6;
    temp_v1 = globalCtx->actorCtx.actorLists[2].head;
    if (temp_v0 != 0) {
        this->unk1C6 = temp_v0 - 1;
    }
    sp2C = temp_v1;
    Math_SmoothStepToS(&this->actor.shape.rot.x, 0x1800, 2, 0xE38, 0x71C);
    Math_ApproachS(&this->actor.shape.rot.y, Math_Vec3f_Yaw(&this->actor.home.pos, &temp_v1->world.pos), 2, 0xE38);
    Math_ScaledStepToS(&this->unk1CA, 0xAAA, 0x444);
    Math_ScaledStepToS(&this->unk1CC, -0x4718, 0x888);
    Math_ScaledStepToS(&this->unk1CE, -0x6AA4, 0x888);
    if (this->unk1C6 == 0) {
        func_809E5FBC(this);
    }
    func_809E6DCC(this);
}

void func_809E7458(EnDekubaba* this, GlobalContext* globalCtx) {
    Vec3f sp3C;
    f32 sp38;
    f32 sp34;
    s32 sp30;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 var_fv1;
    s16 temp_v1;
    s32 var_v0;

    SkelAnime_Update(&this->unk17C);
    temp_v1 = this->unk1C6;
    if (temp_v1 == 0) {
        Math_ScaledStepToS(&this->actor.shape.rot.x, -0x93E, 0x38E);
        Math_ScaledStepToS(&this->unk1CA, -0x888, 0x16C);
        Math_ScaledStepToS(&this->unk1CC, -0x888, 0x16C);
        if (Math_ScaledStepToS(&this->unk1CE, -0x888, 0x16C) != 0) {
            sp38 = Math_SinS(this->actor.shape.rot.y) * 30.0f * this->unk230;
            temp_ft5 = Math_CosS(this->actor.shape.rot.y) * 30.0f;
            sp3C.x = this->actor.home.pos.x;
            sp3C.y = this->actor.home.pos.y;
            var_fv1 = temp_ft5 * this->unk230;
            var_v0 = 0;
            sp3C.z = this->actor.home.pos.z;
            do {
                temp_fv0 = this->unk230;
                sp34 = var_fv1;
                sp30 = var_v0;
                func_800286CC(globalCtx, &sp3C, &D_809E8EA0, &D_809E8EA0, (s16)(s32)(temp_fv0 * 500.0f),
                              (s16)(s32)(temp_fv0 * 50.0f));
                var_fv1 = sp34;
                var_v0 = sp30 + 1;
                sp3C.x = sp3C.x + sp38;
                sp3C.z += var_fv1;
            } while (var_v0 != 3);
            this->unk1C6 = 1;
        }
    } else if (temp_v1 == 0xB) {
        Math_ScaledStepToS(&this->actor.shape.rot.x, -0x93E, 0x200);
        Math_ScaledStepToS(&this->unk1CA, -0xAAA, 0x200);
        Math_ScaledStepToS(&this->unk1CE, -0x5C71, 0x200);
        if (Math_ScaledStepToS(&this->unk1CC, 0x238C, 0x200) != 0) {
            this->unk1C6 = 0xC;
        }
    } else if (temp_v1 == 0x12) {
        Math_ScaledStepToS(&this->actor.shape.rot.x, 0x2AA8, 0xAAA);
        if (Math_ScaledStepToS(&this->unk1CA, 0x1554, 0x5B0) != 0) {
            this->unk1C6 = 0x19;
        }
        Math_ScaledStepToS(&this->unk1CC, -0x38E3, 0xAAA);
        Math_ScaledStepToS(&this->unk1CE, -0x5C71, 0x2D8);
    } else if (temp_v1 == 0x19) {
        Math_ScaledStepToS(&this->actor.shape.rot.x, -0x5550, 0xAAA);
        if (Math_ScaledStepToS(&this->unk1CA, -0x6388, 0x93E) != 0) {
            this->unk1C6 = 0x1A;
        }
        Math_ScaledStepToS(&this->unk1CC, -0x3FFC, 0x4FA);
        Math_ScaledStepToS(&this->unk1CE, -0x238C, 0x444);
    } else if (temp_v1 == 0x1A) {
        Math_ScaledStepToS(&this->actor.shape.rot.x, 0x1800, 0x93E);
        if (Math_ScaledStepToS(&this->unk1CA, -0x1555, 0x71C) != 0) {
            this->unk1C6 = 0x1B;
        }
        Math_ScaledStepToS(&this->unk1CC, -0x38E3, 0x2D8);
        Math_ScaledStepToS(&this->unk1CE, -0x5C71, 0x5B0);
    } else if (temp_v1 >= 0x1B) {
        this->unk1C6 = temp_v1 + 1;
        if (this->unk1C6 >= 0x1F) {
            if (this->actor.xzDistToPlayer < (80.0f * this->unk230)) {
                func_809E5F9C(this);
            } else {
                func_809E5F44(this);
            }
        }
    } else {
        this->unk1C6 = temp_v1 + 1;
        if (this->unk1C6 == 0xA) {
            Audio_PlayActorSound2(&this->actor, 0x3863U);
        }
        if (this->unk1C6 >= 0xC) {
            Math_ScaledStepToS(&this->unk1CE, -0x5C71, 0x88);
        }
    }
    func_809E6DCC(this);
}

void func_809E77E4(EnDekubaba* this, GlobalContext* globalCtx) {
    s16 temp_s0;
    s16 temp_v1;
    s32 temp_s0_2;
    s32 temp_s0_3;

    SkelAnime_Update(&this->unk17C);
    temp_v1 = this->unk1C6;
    if (temp_v1 >= 9) {
        temp_s0 = Math_SmoothStepToS(&this->actor.shape.rot.x, 0x1800, 1, 0x11C6, 0x71C);
        temp_s0_2 = temp_s0 | Math_SmoothStepToS(&this->unk1CA, -0x1555, 1, 0xAAA, 0x71C);
        temp_s0_3 = temp_s0_2 | Math_SmoothStepToS(&this->unk1CC, -0x38E3, 1, 0xE38, 0x71C);
        if ((temp_s0_3 | Math_SmoothStepToS(&this->unk1CE, -0x5C71, 1, 0x11C6, 0x71C)) == 0) {
            this->unk1C6 = 8;
        }
    } else {
        if (temp_v1 != 0) {
            this->unk1C6 = temp_v1 - 1;
        }
        if (this->unk1C6 == 0) {
            func_809E5F44(this);
        }
    }
    func_809E6DCC(this);
}

void func_809E78DC(EnDekubaba* this, GlobalContext* globalCtx) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;

    SkelAnime_Update(&this->unk17C);
    temp_s0 = Math_ScaledStepToS(&this->actor.shape.rot.x, -0x4000, 0xE38) & 1;
    temp_s0_2 = temp_s0 & Math_ScaledStepToS(&this->unk1CA, -0x4000, 0xE38);
    temp_s0_3 = temp_s0_2 & Math_ScaledStepToS(&this->unk1CC, -0x4000, 0xE38);
    if (temp_s0_3 & Math_ScaledStepToS(&this->unk1CE, -0x4000, 0xE38)) {
        if (this->actor.colChkInfo.health == 0) {
            func_809E61E0(this);
        } else {
            this->unk238.base.acFlags |= 1;
            if (this->unk1C6 == 0) {
                if (this->actor.xzDistToPlayer < (80.0f * this->unk230)) {
                    func_809E5F9C(this);
                } else {
                    func_809E6078(this);
                }
            } else {
                func_809E6264(this);
            }
        }
    }
    func_809E6DCC(this);
}

void func_809E79EC(EnDekubaba* this, GlobalContext* globalCtx) {
    s16 temp_v0;

    SkelAnime_Update(&this->unk17C);
    temp_v0 = this->unk1C6;
    if (temp_v0 != 0) {
        this->unk1C6 = temp_v0 - 1;
    }
    if (this->unk1C6 == 0) {
        func_809E5A38(this);
        if (this->actor.xzDistToPlayer < (80.0f * this->unk230)) {
            func_809E5F9C(this);
            return;
        }
        func_809E6078(this);
    }
}

void func_809E7A88(EnDekubaba* this, GlobalContext* globalCtx) {
    s16 temp_v0;
    s16 var_v1;

    SkelAnime_Update(&this->unk17C);
    Math_ScaledStepToS(&this->actor.shape.rot.x, this->unk1CA, 0x71C);
    Math_ScaledStepToS(&this->unk1CA, this->unk1CC, 0x71C);
    Math_ScaledStepToS(&this->unk1CC, this->unk1CE, 0x71C);
    if (Math_ScaledStepToS(&this->unk1CE, this->unk1C8, 0x71C) != 0) {
        this->unk1C8 = (s16)(s32)(-16384.0f - ((f32)(this->unk1C8 + 0x4000) * 0.8f));
    }
    temp_v0 = this->unk1C8 + 0x4000;
    var_v1 = -temp_v0;
    if (temp_v0 >= 0) {
        var_v1 = temp_v0;
    }
    if (var_v1 < 0x100) {
        this->unk238.base.acFlags |= 1;
        if (this->actor.xzDistToPlayer < (80.0f * this->unk230)) {
            func_809E5F9C(this);
        } else {
            func_809E6078(this);
        }
    }
    func_809E6DCC(this);
}

void func_809E7BB0(EnDekubaba* this, GlobalContext* globalCtx) {
    Vec3f sp78;
    f32 sp68;
    PosRot* temp_s0;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    s16 temp_v0;
    s32 var_s0;
    u16 temp_v0_2;

    Math_StepToF(&this->actor.speedXZ, 0.0f, this->unk230 * 0.1f);
    temp_v0 = this->unk1C6;
    if (temp_v0 == 0) {
        Math_ScaledStepToS(&this->actor.shape.rot.x, 0x4800, 0x71C);
        Math_ScaledStepToS(&this->unk1CA, 0x4800, 0x71C);
        Math_ScaledStepToS(&this->unk1CC, 0x4800, 0x71C);
        temp_fv0 = this->unk230;
        temp_s0 = &this->actor.world;
        EffectSsHahen_SpawnBurst(globalCtx, &temp_s0->pos, temp_fv0 * 3.0f, 0, (s16)(s32)(temp_fv0 * 12.0f),
                                 (s16)(s32)(temp_fv0 * 5.0f), 1, -1, 0xA, NULL);
        if ((this->actor.scale.x > 0.005f) &&
            ((temp_v0_2 = this->actor.bgCheckFlags, ((temp_v0_2 & 2) != 0)) || (temp_v0_2 & 8))) {
            temp_fv0_2 = this->unk230;
            this->actor.scale.z = 0.0f;
            this->actor.scale.y = 0.0f;
            this->actor.scale.x = 0.0f;
            this->actor.speedXZ = 0.0f;
            this->actor.flags &= ~5;
            EffectSsHahen_SpawnBurst(globalCtx, &temp_s0->pos, temp_fv0_2 * 3.0f, 0, (s16)(s32)(temp_fv0_2 * 12.0f),
                                     (s16)(s32)(temp_fv0_2 * 5.0f), 0xF, -1, 0xA, NULL);
        }
        if (this->actor.bgCheckFlags & 2) {
            Audio_PlayActorSound2(&this->actor, 0x387BU);
            this->unk1C6 = 1;
        }
    } else if (temp_v0 == 1) {
        sp78.x = this->actor.world.pos.x;
        sp78.y = this->actor.world.pos.y;
        sp78.z = this->actor.world.pos.z;
        temp_fs2 = Math_SinS(this->actor.shape.rot.x) * 20.0f;
        sp68 = Math_CosS(this->actor.shape.rot.x);
        temp_fs0 = Math_SinS(this->actor.shape.rot.y) * (-20.0f * sp68);
        sp68 = Math_CosS(this->actor.shape.rot.x);
        var_s0 = 0;
        temp_fs1 = Math_CosS(this->actor.shape.rot.y) * (-20.0f * sp68);
        do {
            func_800286CC(globalCtx, &sp78, &D_809E8EA0, &D_809E8EA0, 0x1F4, 0x32);
            var_s0 += 1;
            sp78.x = sp78.x + temp_fs0;
            sp78.y += temp_fs2;
            sp78.z += temp_fs1;
        } while (var_s0 != 4);
        temp_fv0_3 = this->unk230;
        func_800286CC(globalCtx, &this->actor.home.pos, &D_809E8EA0, &D_809E8EA0, (s16)(s32)(temp_fv0_3 * 500.0f),
                      (s16)(s32)(temp_fv0_3 * 100.0f));
        func_809E645C(this, globalCtx);
    }
}

void func_809E7F14(EnDekubaba* this, GlobalContext* globalCtx) {
    PosRot* sp38;
    PosRot* temp_a1;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv1;

    Math_StepToF(&this->actor.world.pos.y, this->actor.home.pos.y, this->unk230 * 5.0f);
    temp_fv0 = this->unk230 * 0.1f * 0.01f;
    if (Math_StepToF(&this->actor.scale.x, temp_fv0, temp_fv0) != 0) {
        temp_fv0_2 = this->unk230;
        func_800286CC(globalCtx, &this->actor.home.pos, &D_809E8EA0, &D_809E8EA0, (s16)(s32)(temp_fv0_2 * 500.0f),
                      (s16)(s32)(temp_fv0_2 * 100.0f));
        if (this->actor.dropFlag == 0) {
            temp_a1 = &this->actor.world;
            sp38 = temp_a1;
            Item_DropCollectible(globalCtx, &temp_a1->pos, 0xC);
            if (this->actor.params == 1) {
                Item_DropCollectible(globalCtx, &temp_a1->pos, 0xC);
                Item_DropCollectible(globalCtx, &sp38->pos, 0xC);
            }
        } else {
            Item_DropCollectibleRandom(globalCtx, &this->actor, &this->actor.world.pos, 0x30);
        }
        Actor_Kill(&this->actor);
    }
    temp_fv0_3 = this->unk230;
    temp_fv1 = this->actor.scale.x;
    this->actor.shape.rot.z += 0x1C70;
    this->actor.scale.z = temp_fv1;
    this->actor.scale.y = temp_fv1;
    EffectSsHahen_SpawnBurst(globalCtx, &this->actor.home.pos, temp_fv0_3 * 3.0f, 0, (s16)(s32)(temp_fv0_3 * 12.0f),
                             (s16)(s32)(temp_fv0_3 * 5.0f), 1, -1, 0xA, NULL);
}

void func_809E80D8(EnDekubaba* this, GlobalContext* globalCtx) {
    s16 temp_v0;

    temp_v0 = this->unk1C6;
    if (temp_v0 != 0) {
        this->unk1C6 = temp_v0 - 1;
    }
    if ((Actor_HasParent(&this->actor, globalCtx) != 0) || (this->unk1C6 == 0)) {
        Actor_Kill(&this->actor);
        return;
    }
    func_8002F554(&this->actor, globalCtx, 7);
}

void func_809E8140(EnDekubaba* this, GlobalContext* globalCtx) {
    PosRot* sp38;
    s32 sp34;
    s32 var_s0;
    s32 var_s0_2;
    u8 temp_a0;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    void (*temp_v1)(EnDekubaba*, GlobalContext*);
    void (*temp_v1_2)(EnDekubaba*, GlobalContext*);

    temp_v0 = this->unk238.base.acFlags;
    if (temp_v0 & 2) {
        this->unk238.base.acFlags = temp_v0 & 0xFFFD;
        Actor_SetDropFlagJntSph(&this->actor, &this->unk238, 1);
        if ((this->unk238.base.colType != 0xC) &&
            ((temp_v0_2 = this->actor.colChkInfo.damageEffect, (temp_v0_2 != 0)) ||
             (this->actor.colChkInfo.damage != 0))) {
            temp_v1 = this->unk1C0;
            temp_a0 = this->actor.colChkInfo.health;
            var_s0 = temp_a0 - this->actor.colChkInfo.damage;
            if (func_809E79EC != temp_v1) {
                if ((temp_v0_2 == 0xE) || (temp_v0_2 == 1)) {
                    if (temp_v0_2 == 0xE) {
                        var_s0 = (s32)temp_a0;
                    }
                    func_809E60A8(this, 2);
                } else if (func_809E7458 == temp_v1) {
                    if (var_s0 <= 0) {
                        var_s0 = 1;
                    }
                    func_809E60A8(this, 1);
                } else {
                    func_809E60A8(this, 0);
                }
                goto block_22;
            }
            if ((temp_v0_2 == 0xE) || (temp_v0_2 == 0xF)) {
                if (var_s0 > 0) {
                    func_809E63EC(this);
                } else {
                    func_809E6170(this);
                }
                goto block_22;
            }
            if (temp_v0_2 != 1) {
                func_809E60A8(this, 0);
            block_22:
                if (var_s0 < 0) {
                    this->actor.colChkInfo.health = 0;
                } else {
                    this->actor.colChkInfo.health = (u8)var_s0;
                }
                if (this->actor.colChkInfo.damageEffect == 2) {
                    sp38 = &this->actor.world;
                    var_s0_2 = 0;
                    sp34 = (s32)(s16)(s32)(this->unk230 * 70.0f);
                    do {
                        EffectSsEnFire_SpawnVec3f(globalCtx, &this->actor, &sp38->pos, (s16)sp34, 0, 0, (s16)var_s0_2);
                        var_s0_2 += 1;
                    } while (var_s0_2 != 4);
                }
                goto block_35;
            }
        }
    } else if ((globalCtx->actorCtx.unk_02 != 0) && (this->unk238.base.colType != 0xC) &&
               (temp_v1_2 = this->unk1C0, (func_809E79EC != temp_v1_2)) && (func_809E78DC != temp_v1_2) &&
               (temp_v0_3 = this->actor.colChkInfo.health, (temp_v0_3 != 0))) {
        this->actor.colChkInfo.health = temp_v0_3 - 1;
        this->actor.dropFlag = 0;
        func_809E60A8(this, 1);
    block_35:
        if (this->actor.colChkInfo.health != 0) {
            if (this->unk1C6 == 2) {
                Audio_PlayActorSound2(&this->actor, 0x389EU);
                return;
            }
            Audio_PlayActorSound2(&this->actor, 0x385EU);
            return;
        }
        Enemy_StartFinishingBlow(globalCtx, &this->actor);
        if (this->actor.params == 1) {
            Audio_PlayActorSound2(&this->actor, 0x385FU);
            return;
        }
        Audio_PlayActorSound2(&this->actor, 0x3862U);
    }
}

void EnDekubaba_Update(Actor* thisx, GlobalContext* globalCtx) {
    void (*sp2C)(EnDekubaba*, GlobalContext*);
    u8 temp_v0;
    void (*temp_v0_2)(EnDekubaba*, GlobalContext*);
    void (*var_v1)(EnDekubaba*, GlobalContext*);
    EnDekubaba* this = (EnDekubaba*)thisx;

    temp_v0 = this->unk238.base.atFlags;
    if (temp_v0 & 2) {
        this->unk238.base.atFlags = temp_v0 & 0xFFFD;
        func_809E6078(this);
    }
    func_809E8140(this, globalCtx);
    this->unk1C0(this, globalCtx);
    temp_v0_2 = this->unk1C0;
    if (func_809E7BB0 == temp_v0_2) {
        Actor_MoveForward(&this->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &this->actor, 10.0f, this->unk230 * 15.0f, 10.0f, 5);
        var_v1 = func_809E80D8;
    } else {
        var_v1 = func_809E80D8;
        if (func_809E80D8 != temp_v0_2) {
            sp2C = func_809E80D8;
            Actor_UpdateBgCheckInfo(globalCtx, &this->actor, 0.0f, 0.0f, 0.0f, 4);
            var_v1 = func_809E80D8;
            if (this->unk234 == NULL) {
                this->unk234 = this->actor.floorPoly;
            }
        }
    }
    if (func_809E7104 == this->unk1C0) {
        sp2C = func_809E80D8;
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &this->unk238.base);
        var_v1 = func_809E80D8;
        this->actor.flags |= 0x01000000;
    }
    if (this->unk238.base.acFlags & 1) {
        sp2C = var_v1;
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->unk238.base);
    }
    if (var_v1 != this->unk1C0) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->unk238.base);
    }
}

void func_809E858C(EnDekubaba* this, GlobalContext* globalCtx) {
    f32 sp44;
    Gfx* sp30;
    Gfx* sp2C;
    Gfx* temp_v0;
    Gfx* temp_v0_2;
    GraphicsContext* temp_a1;
    f32 temp_fv0;

    temp_a1 = globalCtx->state.gfxCtx;
    Graph_OpenDisps(&sp30, temp_a1, "../z_en_dekubaba.c", 0x98D);
    temp_fv0 = this->unk230;
    sp44 = temp_fv0 * 0.01f;
    Matrix_Translate(this->actor.home.pos.x, this->actor.home.pos.y + (-6.0f * temp_fv0), this->actor.home.pos.z, 0U);
    Matrix_RotateRPY(this->unk1CA, this->actor.shape.rot.y, 0, 1U);
    Matrix_Scale(sp44, sp44, sp44, 1U);
    temp_v0 = temp_a1->polyOpa.p;
    temp_a1->polyOpa.p = temp_v0 + 8;
    temp_v0->words.w0 = 0xDA380003;
    sp2C = temp_v0;
    sp2C->words.w1 = Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0x99D);
    temp_v0_2 = temp_a1->polyOpa.p;
    temp_a1->polyOpa.p = temp_v0_2 + 8;
    temp_v0_2->words.w1 = (u32)D_6001330;
    temp_v0_2->words.w0 = 0xDE000000;
    Actor_SetFocus(&this->actor, 0.0f);
    Graph_CloseDisps(&sp30, globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0x9A4);
}

void func_809E86B8(EnDekubaba* this, GlobalContext* globalCtx) {
    MtxF spB0;
    f32 spA4;
    s32 sp9C;
    Gfx* sp88;
    ColliderJntSph* temp_fp;
    EnDekubaba* var_s3;
    Gfx* temp_v0;
    Gfx* temp_v0_2;
    GraphicsContext* temp_a1;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs3;
    s32 var_s2;
    s32 var_s6;
    s32 var_s7;
    u32* var_s5;
    void* temp_v0_3;

    temp_a1 = globalCtx->state.gfxCtx;
    Graph_OpenDisps(&sp88, temp_a1, "../z_en_dekubaba.c", 0x9B7);
    if (func_809E7BB0 == this->unk1C0) {
        sp9C = 2;
    } else {
        sp9C = 3;
    }
    temp_fs0 = this->unk230 * 0.01f;
    Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, 0U);
    Matrix_Scale(temp_fs0, temp_fs0, temp_fs0, 1U);
    Matrix_Get(&spB0);
    var_s2 = 0;
    var_s3 = this;
    if (this->actor.colorFilterTimer != 0) {
        temp_fs3 = this->unk230 * 20.0f;
        this->unk164.x = this->actor.world.pos.x;
        this->unk164.z = this->actor.world.pos.z;
        this->unk164.y = this->actor.world.pos.y - temp_fs3;
        spA4 = temp_fs3;
    }
    if (sp9C > 0) {
        var_s5 = D_809E902C;
        var_s6 = 0x33;
        temp_fp = &this->unk238;
        var_s7 = 0x34;
        do {
            spB0.mf[3][1] += 20.0f * Math_SinS(var_s3->unk1CA) * this->unk230;
            temp_fs0_2 = Math_CosS(var_s3->unk1CA) * 20.0f * this->unk230;
            spB0.mf[3][0] -= temp_fs0_2 * Math_SinS(this->actor.shape.rot.y);
            spB0.mf[3][2] -= temp_fs0_2 * Math_CosS(this->actor.shape.rot.y);
            Matrix_Put(&spB0);
            Matrix_RotateRPY(var_s3->unk1CA, this->actor.shape.rot.y, 0, 1U);
            temp_v0 = temp_a1->polyOpa.p;
            temp_a1->polyOpa.p = temp_v0 + 8;
            temp_v0->words.w0 = 0xDA380003;
            temp_v0->words.w1 = Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0x9E5);
            temp_v0_2 = temp_a1->polyOpa.p;
            temp_a1->polyOpa.p = temp_v0_2 + 8;
            temp_v0_2->words.w0 = 0xDE000000;
            temp_v0_2->words.w1 = *var_s5;
            Collider_UpdateSpheres(var_s6, temp_fp);
            Collider_UpdateSpheres(var_s7, temp_fp);
            if (var_s2 == 0) {
                if (func_809E7A88 != this->unk1C0) {
                    this->actor.focus.pos.x = spB0.mf[3][0];
                    this->actor.focus.pos.y = spB0.mf[3][1];
                    this->actor.focus.pos.z = spB0.mf[3][2];
                } else {
                    this->actor.focus.pos.x = this->actor.home.pos.x;
                    this->actor.focus.pos.z = this->actor.home.pos.z;
                    this->actor.focus.pos.y = this->actor.home.pos.y + (40.0f * this->unk230);
                }
            }
            var_s3 += 2;
            if ((var_s2 < 2) && (this->actor.colorFilterTimer != 0)) {
                temp_v0_3 = this + (var_s2 * 0xC);
                *(f32*)((char*)temp_v0_3 + 0x14C) /*temp_v0_3->unk14C*/ = spB0.mf[3][0];
                *(f32*)((char*)temp_v0_3 + 0x150) /*temp_v0_3->unk150*/ = (f32)(spB0.mf[3][1] - spA4);
                *(f32*)((char*)temp_v0_3 + 0x154) /*temp_v0_3->unk154*/ = spB0.mf[3][2];
            }
            var_s2 += 1;
            var_s5 += 4;
            var_s6 += 2;
            var_s7 += 2;
        } while (var_s2 != sp9C);
    }
    Graph_CloseDisps(&sp88, globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xA09);
}

void func_809E89E4(EnDekubaba* this, GlobalContext* globalCtx) {
    Gfx* sp2C;
    Gfx* sp28;
    ColliderJntSph* temp_s0;
    Gfx* temp_v0;
    Gfx* temp_v0_2;
    GraphicsContext* temp_a1;

    temp_a1 = globalCtx->state.gfxCtx;
    Graph_OpenDisps(&sp2C, temp_a1, "../z_en_dekubaba.c", 0xA13);
    Matrix_RotateRPY(this->unk1CE, this->actor.shape.rot.y, 0, 1U);
    temp_v0 = temp_a1->polyOpa.p;
    temp_a1->polyOpa.p = temp_v0 + 8;
    temp_v0->words.w0 = 0xDA380003;
    sp28 = temp_v0;
    sp28->words.w1 = Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xA1A);
    temp_v0_2 = temp_a1->polyOpa.p;
    temp_a1->polyOpa.p = temp_v0_2 + 8;
    temp_v0_2->words.w1 = (u32)D_6001828;
    temp_v0_2->words.w0 = 0xDE000000;
    temp_s0 = &this->unk238;
    Collider_UpdateSpheres(0x37, temp_s0);
    Collider_UpdateSpheres(0x38, temp_s0);
    Graph_CloseDisps(&sp2C, globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xA24);
}

void func_809E8AD8(EnDekubaba* this, GlobalContext* globalCtx) {
    MtxF sp50;
    Gfx* sp38;
    Gfx* temp_v0;
    Gfx* temp_v0_2;
    Gfx* temp_v0_3;
    GraphicsContext* temp_a1;
    f32 temp_fa0;

    temp_a1 = globalCtx->state.gfxCtx;
    Graph_OpenDisps(&sp38, temp_a1, "../z_en_dekubaba.c", 0xA84);
    func_80094044(globalCtx->state.gfxCtx);
    temp_v0 = temp_a1->polyXlu.p;
    temp_a1->polyXlu.p = temp_v0 + 8;
    temp_v0->words.w1 = 0xFF;
    temp_v0->words.w0 = 0xFA000000;
    func_80038A28(this->unk234, this->actor.home.pos.x, this->actor.home.pos.y, this->actor.home.pos.z, &sp50);
    Matrix_Mult(&sp50, 0U);
    temp_fa0 = this->unk230 * 0.15f;
    Matrix_Scale(temp_fa0, 1.0f, temp_fa0, 1U);
    temp_v0_2 = temp_a1->polyXlu.p;
    temp_a1->polyXlu.p = temp_v0_2 + 8;
    temp_v0_2->words.w0 = 0xDA380003;
    temp_v0_2->words.w1 = Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xA96);
    temp_v0_3 = temp_a1->polyXlu.p;
    temp_a1->polyXlu.p = temp_v0_3 + 8;
    temp_v0_3->words.w0 = 0xDE000000;
    temp_v0_3->words.w1 = (u32)D_4049210;
    Graph_CloseDisps(&sp38, globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xA9B);
}

void func_809E8C0C(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3s* arg3, EnDekubaba* this) {
    if (arg1 == 1) {
        Collider_UpdateSpheres(arg1, &this->unk238);
    }
}

void EnDekubaba_Draw(Actor* thisx, GlobalContext* globalCtx) {
    f32 sp50;
    GraphicsContext* sp4C;
    Gfx* sp3C;
    Gfx* sp38;
    Gfx* temp_v0;
    Gfx* temp_v0_2;
    Gfx* temp_v0_4;
    Gfx* temp_v0_5;
    GraphicsContext* temp_a1;
    s16 temp_v0_3;
    EnDekubaba* this = (EnDekubaba*)thisx;

    temp_a1 = globalCtx->state.gfxCtx;
    sp4C = temp_a1;
    Graph_OpenDisps(&sp3C, temp_a1, "../z_en_dekubaba.c", 0xAC0);
    func_80093D18(globalCtx->state.gfxCtx);
    if (func_809E80D8 != this->unk1C0) {
        SkelAnime_DrawOpa(globalCtx, this->unk17C.skeleton, this->unk17C.jointTable, NULL,
                          (void (*)(GlobalContext*, s32, Gfx**, Vec3s*, void*))func_809E8C0C, this);
        if (func_809E64F4 == this->unk1C0) {
            func_809E858C(this, globalCtx);
        } else {
            func_809E86B8(this, globalCtx);
        }
        sp50 = this->unk230 * 0.01f;
        Matrix_Translate(this->actor.home.pos.x, this->actor.home.pos.y, this->actor.home.pos.z, 0U);
        Matrix_RotateY((f32)this->actor.home.rot.y * 0.0000958738f, 1U);
        Matrix_Scale(sp50, sp50, sp50, 1U);
        temp_v0 = sp4C->polyOpa.p;
        sp4C->polyOpa.p = temp_v0 + 8;
        temp_v0->words.w0 = 0xDA380003;
        sp38 = temp_v0;
        sp38->words.w1 = Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xADC);
        temp_v0_2 = sp4C->polyOpa.p;
        sp4C->polyOpa.p = temp_v0_2 + 8;
        temp_v0_2->words.w1 = (u32)D_60010F0;
        temp_v0_2->words.w0 = 0xDE000000;
        if (func_809E7BB0 == this->unk1C0) {
            func_809E89E4(this, globalCtx);
        }
        if (this->unk234 != NULL) {
            func_809E8AD8(this, globalCtx);
        }
    } else {
        temp_v0_3 = this->unk1C6;
        if ((temp_v0_3 >= 0x29) || (temp_v0_3 & 1)) {
            Matrix_Translate(0.0f, 0.0f, 200.0f, 1U);
            temp_v0_4 = sp4C->polyOpa.p;
            sp4C->polyOpa.p = temp_v0_4 + 8;
            temp_v0_4->words.w0 = 0xDA380003;
            temp_v0_4->words.w1 = Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xAED);
            temp_v0_5 = sp4C->polyOpa.p;
            sp4C->polyOpa.p = temp_v0_5 + 8;
            temp_v0_5->words.w1 = (u32)D_6003070;
            temp_v0_5->words.w0 = 0xDE000000;
        }
    }
    Graph_CloseDisps(&sp3C, globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xAF4);
}

#else

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E65A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E6A04.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E6DCC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E6ED4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E7104.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E738C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E7458.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E77E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E78DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E79EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E7A88.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E7BB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E7F14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E80D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E8140.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/EnDekubaba_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E858C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E86B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E89E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E8AD8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E8C0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/EnDekubaba_Draw.s")

#endif
