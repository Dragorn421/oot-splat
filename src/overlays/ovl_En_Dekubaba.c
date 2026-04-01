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

void func_809E65A0(EnDekubaba* this, GlobalContext* globalCtx) {
    Actor* sp64;
    f32 var_fa0;
    f32 sp5C;
    f32 sp58;
    f32 temp_ft5;

    sp64 = globalCtx->actorCtx.actorLists[2].head;

    if (this->unk1C6 != 0) {
        this->unk1C6--;
    }
    SkelAnime_Update(&this->unk17C);

    this->actor.scale.x = this->actor.scale.y = this->actor.scale.z =
        (this->unk230 * 0.01f) * (0.5f + ((((f32)(0xF - this->unk1C6)) * 0.5f) / 15.0f));
    Math_ScaledStepToS(&this->actor.shape.rot.x, 0x1800, 0x800);

    sp5C = (sinf(MIN(0.7f, ((0xF - this->unk1C6)) * 0.06666667014f) * 3.1415927f) * 32.0f) + 14.0f;

    if (this->actor.shape.rot.x < (-0x38E3)) {
        var_fa0 = 0.0f;
    } else if (this->actor.shape.rot.x < (-0x238E)) {
        Math_ScaledStepToS(&this->unk1CA, -0x5555, 0x38E);
        var_fa0 = 20.0f * Math_CosS(this->unk1CA);
    } else if (this->actor.shape.rot.x < (-0xE38)) {
        Math_ScaledStepToS(&this->unk1CA, -0xAAA, 0x38E);
        Math_ScaledStepToS(&this->unk1CC, -0x5555, 0x38E);
        Math_ScaledStepToS(&this->unk1CE, -0x5555, 0x222);
        var_fa0 =
            (20.0f * (Math_CosS(this->unk1CA) + Math_CosS(this->unk1CC))) +
            (((sp5C - (20.0f * ((-Math_SinS(this->unk1CA)) - Math_SinS(this->unk1CC)))) * Math_CosS(this->unk1CE)) /
             (-Math_SinS(this->unk1CE)));
    } else {
        Math_ScaledStepToS(&this->unk1CA, -0xAAA, 0x38E);
        Math_ScaledStepToS(&this->unk1CC, -0x31C7, 0x222);
        Math_ScaledStepToS(&this->unk1CE, -0x5555, 0x222);
        var_fa0 =
            (20.0f * (Math_CosS(this->unk1CA) + Math_CosS(this->unk1CC))) +
            (((sp5C - (20.0f * ((-Math_SinS(this->unk1CA)) - Math_SinS(this->unk1CC)))) * Math_CosS(this->unk1CE)) /
             (-Math_SinS(this->unk1CE)));
    }

    if (this->unk1C6 < 0xA) {
        Math_ApproachS(&this->actor.shape.rot.y, Math_Vec3f_Yaw(&this->actor.home.pos, &sp64->world.pos), 2, 0xE38);
    }

    this->actor.world.pos.y = this->actor.home.pos.y + (sp5C * this->unk230);
    sp58 = Math_SinS(this->actor.shape.rot.y) * (var_fa0 * this->unk230);
    temp_ft5 = var_fa0;
    temp_ft5 = Math_CosS(this->actor.shape.rot.y) * (temp_ft5 * this->unk230);
    this->actor.world.pos.x = this->actor.home.pos.x + sp58;
    this->actor.world.pos.z = this->actor.home.pos.z + temp_ft5;
    EffectSsHahen_SpawnBurst(globalCtx, &this->actor.home.pos, this->unk230 * 3.0f, 0, ((s32)(this->unk230 * 12.0f)),
                             ((s32)(this->unk230 * 5.0f)), 1, -1, 0xA, NULL);
    if (this->unk1C6 == 0) {
        if (Math_Vec3f_DistXZ(&this->actor.home.pos, &sp64->world.pos) < (240.0f * this->unk230)) {
            func_809E5F9C(this);
        } else {
            func_809E5E58(this);
        }
    }
}

void func_809E6A04(EnDekubaba* this, GlobalContext* globalCtx) {
    f32 var_fa0;
    f32 sp58;
    f32 sp54;
    f32 temp_ft5;

    if (this->unk1C6 != 0) {
        this->unk1C6 -= 1;
    }
    SkelAnime_Update(&this->unk17C);
    this->actor.scale.x = this->actor.scale.y = this->actor.scale.z =
        this->unk230 * 0.01f * (0.5f + ((f32)this->unk1C6 * 0.033333335f));
    Math_ScaledStepToS(&this->actor.shape.rot.x, -0x4000, 0x300);
    sp58 = (sinf(CLAMP_MAX(this->unk1C6 * 0.033f, 0.7f) * 3.1415927f) * 32.0f) + 14.0f;
    if (this->actor.shape.rot.x < -0x38E3) {
        var_fa0 = 0.0f;
    } else if (this->actor.shape.rot.x < -0x238E) {
        Math_ScaledStepToS(&this->unk1CA, -0x4000, 0x555);
        var_fa0 = Math_CosS(this->unk1CA) * 20.0f;
    } else if (this->actor.shape.rot.x < -0xE38) {
        Math_ScaledStepToS(&this->unk1CA, -0x5555, 0x555);
        Math_ScaledStepToS(&this->unk1CC, -0x4000, 0x555);
        Math_ScaledStepToS(&this->unk1CE, -0x4000, 0x333);
        var_fa0 =
            (20.0f * (Math_CosS(this->unk1CA) + Math_CosS(this->unk1CC))) +
            (((sp58 - (20.0f * ((-Math_SinS(this->unk1CA)) - Math_SinS(this->unk1CC)))) * Math_CosS(this->unk1CE)) /
             (-Math_SinS(this->unk1CE)));
    } else {
        Math_ScaledStepToS(&this->unk1CA, -0x5555, 0x555);
        Math_ScaledStepToS(&this->unk1CC, -0x5555, 0x333);
        Math_ScaledStepToS(&this->unk1CE, -0x4000, 0x333);
        var_fa0 =
            (20.0f * (Math_CosS(this->unk1CA) + Math_CosS(this->unk1CC))) +
            (((sp58 - (20.0f * ((-Math_SinS(this->unk1CA)) - Math_SinS(this->unk1CC)))) * Math_CosS(this->unk1CE)) /
             (-Math_SinS(this->unk1CE)));
    }
    this->actor.world.pos.y = this->actor.home.pos.y + (sp58 * this->unk230);
    sp54 = Math_SinS(this->actor.shape.rot.y) * (var_fa0 * this->unk230);
    temp_ft5 = Math_CosS(this->actor.shape.rot.y) * (var_fa0 * this->unk230);
    this->actor.world.pos.x = this->actor.home.pos.x + sp54;
    this->actor.world.pos.z = this->actor.home.pos.z + temp_ft5;
    EffectSsHahen_SpawnBurst(globalCtx, &this->actor.home.pos, this->unk230 * 3.0f, 0, (s16)(s32)(this->unk230 * 12.0f),
                             (s16)(s32)(this->unk230 * 5.0f), 1, -1, 0xA, NULL);
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

    sp34 = globalCtx->actorCtx.actorLists[2].head;
    SkelAnime_Update(&this->unk17C);
    if ((Animation_OnFrame(&this->unk17C, 0.0f) != 0) || (Animation_OnFrame(&this->unk17C, 12.0f) != 0)) {
        if (this->actor.params == 1) {
            Audio_PlayActorSound2(&this->actor, 0x385CU);
        } else {
            Audio_PlayActorSound2(&this->actor, 0x3860U);
        }
    }
    if (this->unk1C6 != 0) {
        this->unk1C6 -= 1;
    }
    Math_ApproachS(&this->actor.shape.rot.y, Math_Vec3f_Yaw(&this->actor.home.pos, &sp34->world.pos), 2,
                   (s16)(((s16)this->unk1C6 % 5) * 0x222));
    if (this->unk1C6 < 0xA) {
        this->unk1CA += 0x16C;
        this->unk1CC += 0x16C;
        this->unk1CE += 0xB6;
        this->actor.shape.rot.x += 0x222;
    } else {
        if (this->unk1C6 < 0x14) {
            this->unk1CA -= 0x16C;
            this->unk1CC += 0x111;
            this->actor.shape.rot.x += 0x16C;
        } else if (this->unk1C6 < 0x1E) {
            this->unk1CC -= 0x111;
            this->actor.shape.rot.x -= 0xB6;
        } else {
            this->unk1CC -= 0xB6;
            this->unk1CE += 0xB6;
            this->actor.shape.rot.x -= 0x16C;
        }
    }
    func_809E6DCC(this);
    if ((240.0f * this->unk230) < Math_Vec3f_DistXZ(&this->actor.home.pos, &sp34->world.pos)) {
        func_809E5E58(this);
        return;
    }
    if ((this->unk1C6 == 0) || (this->actor.xzDistToPlayer < (80.0f * this->unk230))) {
        func_809E5F9C(this);
    }
}

void func_809E7104(EnDekubaba* this, GlobalContext* globalCtx) {
    s32 sp4C;
    s16 sp4A;
    Vec3f sp3C;

    SkelAnime_Update(&this->unk17C);
    if (this->unk1C6 == 0) {
        if (Animation_OnFrame(&this->unk17C, 1.0f) != 0) {
            if (this->actor.params == 1) {
                Audio_PlayActorSound2(&this->actor, 0x385DU);
            } else {
                Audio_PlayActorSound2(&this->actor, 0x3861U);
            }
        }
        Math_ScaledStepToS(&this->actor.shape.rot.x, 0, 0x222);
        sp4A = (s16)(s32)(this->unk17C.curFrame * 10.0f);
        sp4C = 1;
        sp4C &= Math_ScaledStepToS(&this->unk1CA, -0xE38, (s16)(sp4A + 0x38E));
        sp4C &= Math_ScaledStepToS(&this->unk1CC, -0xE38, (s16)(sp4A + 0x71C));
        sp4C &= Math_ScaledStepToS(&this->unk1CE, -0xE38, (s16)(sp4A + 0xE38));
        if (sp4C) {
            Animation_PlayLoopSetSpeed(&this->unk17C, &D_60002B8, 4.0f);
            sp3C.x = Math_SinS(this->actor.shape.rot.y) * 5.0f;
            sp3C.y = 0.0f;
            sp3C.z = Math_CosS(this->actor.shape.rot.y) * 5.0f;
            func_8002829C(globalCtx, &this->actor.world.pos, (Vec3f*)&sp3C, &D_809E8EA0, &D_809E9024, &D_809E9028, 1,
                          (s16)(s32)(this->unk230 * 100.0f));
            this->unk1C6 = 1;
            this->unk238.base.acFlags |= 1;
        }
    } else if (this->unk1C6 >= 0xB) {
        func_809E6000(this);
    } else {
        this->unk1C6 += 1;
        if ((this->unk1C6 >= 4) && (Actor_IsFacingPlayer(&this->actor, 0x16C) == 0)) {
            Math_ApproachS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 0xF, 0x71C);
        }
        if ((Animation_OnFrame(&this->unk17C, 0.0f) != 0) || (Animation_OnFrame(&this->unk17C, 12.0f) != 0)) {
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
    Actor* temp_v1;

    temp_v1 = globalCtx->actorCtx.actorLists[2].head;
    if (this->unk1C6 != 0) {
        this->unk1C6 -= 1;
    }
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
    f32 var_fv1;
    s32 var_v0;

    SkelAnime_Update(&this->unk17C);
    if (this->unk1C6 == 0) {
        Math_ScaledStepToS(&this->actor.shape.rot.x, -0x93E, 0x38E);
        Math_ScaledStepToS(&this->unk1CA, -0x888, 0x16C);
        Math_ScaledStepToS(&this->unk1CC, -0x888, 0x16C);
        if (Math_ScaledStepToS(&this->unk1CE, -0x888, 0x16C) != 0) {
            sp38 = Math_SinS(this->actor.shape.rot.y) * 30.0f * this->unk230;
            var_fv1 = Math_CosS(this->actor.shape.rot.y) * 30.0f * this->unk230;
            sp3C = this->actor.home.pos;
            for (var_v0 = 0; var_v0 < 3; var_v0++) {
                func_800286CC(globalCtx, &sp3C, &D_809E8EA0, &D_809E8EA0, (s16)(s32)(this->unk230 * 500.0f),
                              (s16)(s32)(this->unk230 * 50.0f));
                sp3C.x += sp38;
                sp3C.z += var_fv1;
            }
            this->unk1C6 = 1;
        }
    } else if (this->unk1C6 == 0xB) {
        Math_ScaledStepToS(&this->actor.shape.rot.x, -0x93E, 0x200);
        Math_ScaledStepToS(&this->unk1CA, -0xAAA, 0x200);
        Math_ScaledStepToS(&this->unk1CE, -0x5C71, 0x200);
        if (Math_ScaledStepToS(&this->unk1CC, 0x238C, 0x200) != 0) {
            this->unk1C6 = 0xC;
        }
    } else if (this->unk1C6 == 0x12) {
        Math_ScaledStepToS(&this->actor.shape.rot.x, 0x2AA8, 0xAAA);
        if (Math_ScaledStepToS(&this->unk1CA, 0x1554, 0x5B0) != 0) {
            this->unk1C6 = 0x19;
        }
        Math_ScaledStepToS(&this->unk1CC, -0x38E3, 0xAAA);
        Math_ScaledStepToS(&this->unk1CE, -0x5C71, 0x2D8);
    } else if (this->unk1C6 == 0x19) {
        Math_ScaledStepToS(&this->actor.shape.rot.x, -0x5550, 0xAAA);
        if (Math_ScaledStepToS(&this->unk1CA, -0x6388, 0x93E) != 0) {
            this->unk1C6 = 0x1A;
        }
        Math_ScaledStepToS(&this->unk1CC, -0x3FFC, 0x4FA);
        Math_ScaledStepToS(&this->unk1CE, -0x238C, 0x444);
    } else if (this->unk1C6 == 0x1A) {
        Math_ScaledStepToS(&this->actor.shape.rot.x, 0x1800, 0x93E);
        if (Math_ScaledStepToS(&this->unk1CA, -0x1555, 0x71C) != 0) {
            this->unk1C6 = 0x1B;
        }
        Math_ScaledStepToS(&this->unk1CC, -0x38E3, 0x2D8);
        Math_ScaledStepToS(&this->unk1CE, -0x5C71, 0x5B0);
    } else if (this->unk1C6 >= 0x1B) {
        this->unk1C6 += 1;
        if (this->unk1C6 >= 0x1F) {
            if (this->actor.xzDistToPlayer < (80.0f * this->unk230)) {
                func_809E5F9C(this);
            } else {
                func_809E5F44(this);
            }
        }
    } else {
        this->unk1C6 += 1;
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
    s32 temp_s0;

    SkelAnime_Update(&this->unk17C);
    if (this->unk1C6 >= 9) {
        temp_s0 = 0;
        temp_s0 |= Math_SmoothStepToS(&this->actor.shape.rot.x, 0x1800, 1, 0x11C6, 0x71C);
        temp_s0 |= Math_SmoothStepToS(&this->unk1CA, -0x1555, 1, 0xAAA, 0x71C);
        temp_s0 |= Math_SmoothStepToS(&this->unk1CC, -0x38E3, 1, 0xE38, 0x71C);
        temp_s0 |= Math_SmoothStepToS(&this->unk1CE, -0x5C71, 1, 0x11C6, 0x71C);
        if (temp_s0 == 0) {
            this->unk1C6 = 8;
        }
    } else {
        if (this->unk1C6 != 0) {
            this->unk1C6 -= 1;
        }
        if (this->unk1C6 == 0) {
            func_809E5F44(this);
        }
    }
    func_809E6DCC(this);
}

void func_809E78DC(EnDekubaba* this, GlobalContext* globalCtx) {
    s32 temp_s0;

    SkelAnime_Update(&this->unk17C);
    temp_s0 = 1;
    temp_s0 &= Math_ScaledStepToS(&this->actor.shape.rot.x, -0x4000, 0xE38);
    temp_s0 &= Math_ScaledStepToS(&this->unk1CA, -0x4000, 0xE38);
    temp_s0 &= Math_ScaledStepToS(&this->unk1CC, -0x4000, 0xE38);
    temp_s0 &= Math_ScaledStepToS(&this->unk1CE, -0x4000, 0xE38);
    if (temp_s0) {
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
    SkelAnime_Update(&this->unk17C);
    if (this->unk1C6 != 0) {
        this->unk1C6 -= 1;
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

    SkelAnime_Update(&this->unk17C);
    Math_ScaledStepToS(&this->actor.shape.rot.x, this->unk1CA, 0x71C);
    Math_ScaledStepToS(&this->unk1CA, this->unk1CC, 0x71C);
    Math_ScaledStepToS(&this->unk1CC, this->unk1CE, 0x71C);
    if (Math_ScaledStepToS(&this->unk1CE, this->unk1C8, 0x71C) != 0) {
        this->unk1C8 = (s16)(s32)(-16384.0f - ((f32)(this->unk1C8 + 0x4000) * 0.8f));
    }
    temp_v0 = this->unk1C8 + 0x4000;
    if (ABS(temp_v0) < 0x100) {
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
    s32 var_s0;
    Vec3f sp78;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;

    Math_StepToF(&this->actor.speedXZ, 0.0f, this->unk230 * 0.1f);
    if (this->unk1C6 == 0) {
        Math_ScaledStepToS(&this->actor.shape.rot.x, 0x4800, 0x71C);
        Math_ScaledStepToS(&this->unk1CA, 0x4800, 0x71C);
        Math_ScaledStepToS(&this->unk1CC, 0x4800, 0x71C);
        EffectSsHahen_SpawnBurst(globalCtx, &this->actor.world.pos, this->unk230 * 3.0f, 0,
                                 (s16)(s32)(this->unk230 * 12.0f), (s16)(s32)(this->unk230 * 5.0f), 1, -1, 0xA, NULL);
        if ((this->actor.scale.x > 0.005f) &&
            ((((this->actor.bgCheckFlags & 2) != 0)) || (this->actor.bgCheckFlags & 8))) {
            this->actor.scale.z = 0.0f;
            this->actor.scale.y = 0.0f;
            this->actor.scale.x = 0.0f;
            this->actor.speedXZ = 0.0f;
            this->actor.flags &= ~5;
            EffectSsHahen_SpawnBurst(globalCtx, &this->actor.world.pos, this->unk230 * 3.0f, 0,
                                     (s16)(s32)(this->unk230 * 12.0f), (s16)(s32)(this->unk230 * 5.0f), 0xF, -1, 0xA,
                                     NULL);
        }
        if (this->actor.bgCheckFlags & 2) {
            Audio_PlayActorSound2(&this->actor, 0x387BU);
            this->unk1C6 = 1;
        }
    } else if (this->unk1C6 == 1) {
        sp78 = this->actor.world.pos;
        temp_fs2 = Math_SinS(this->actor.shape.rot.x) * 20.0f;
        temp_fs0 = (-20.0f * Math_CosS(this->actor.shape.rot.x)) * Math_SinS(this->actor.shape.rot.y);
        temp_fs1 = (-20.0f * Math_CosS(this->actor.shape.rot.x)) * Math_CosS(this->actor.shape.rot.y);
        for (var_s0 = 0; var_s0 < 4; var_s0++) {
            func_800286CC(globalCtx, &sp78, &D_809E8EA0, &D_809E8EA0, 0x1F4, 0x32);
            sp78.x += temp_fs0;
            sp78.y += temp_fs2;
            sp78.z += temp_fs1;
        }
        func_800286CC(globalCtx, &this->actor.home.pos, &D_809E8EA0, &D_809E8EA0, (s16)(s32)(this->unk230 * 500.0f),
                      (s16)(s32)(this->unk230 * 100.0f));
        func_809E645C(this, globalCtx);
    }
}

void func_809E7F14(EnDekubaba* this, GlobalContext* globalCtx) {
    Math_StepToF(&this->actor.world.pos.y, this->actor.home.pos.y, this->unk230 * 5.0f);
    if (Math_StepToF(&this->actor.scale.x, this->unk230 * 0.1f * 0.01f, this->unk230 * 0.1f * 0.01f) != 0) {
        func_800286CC(globalCtx, &this->actor.home.pos, &D_809E8EA0, &D_809E8EA0, (s16)(s32)(this->unk230 * 500.0f),
                      (s16)(s32)(this->unk230 * 100.0f));
        if (this->actor.dropFlag == 0) {
            Item_DropCollectible(globalCtx, &this->actor.world.pos, 0xC);
            if (this->actor.params == 1) {
                Item_DropCollectible(globalCtx, &this->actor.world.pos, 0xC);
                Item_DropCollectible(globalCtx, &this->actor.world.pos, 0xC);
            }
        } else {
            Item_DropCollectibleRandom(globalCtx, &this->actor, &this->actor.world.pos, 0x30);
        }
        Actor_Kill(&this->actor);
    }
    this->actor.scale.y = this->actor.scale.z = this->actor.scale.x;
    this->actor.shape.rot.z += 0x1C70;
    EffectSsHahen_SpawnBurst(globalCtx, &this->actor.home.pos, this->unk230 * 3.0f, 0, (s16)(s32)(this->unk230 * 12.0f),
                             (s16)(s32)(this->unk230 * 5.0f), 1, -1, 0xA, NULL);
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
    float new_var2;
    s32 var_s0;
    s32 i;

    if (this->unk238.base.acFlags & 2) {
        this->unk238.base.acFlags &= ~2;
        Actor_SetDropFlagJntSph(&this->actor, &this->unk238, 1);
        if ((this->unk238.base.colType != 0xC) &&
            (((this->actor.colChkInfo.damageEffect != 0)) || (this->actor.colChkInfo.damage != 0))) {
            var_s0 = this->actor.colChkInfo.health - this->actor.colChkInfo.damage;
            if (this->unk1C0 != func_809E79EC) {
                if ((this->actor.colChkInfo.damageEffect == 0xE) || (this->actor.colChkInfo.damageEffect == 1)) {
                    if (this->actor.colChkInfo.damageEffect == 0xE) {
                        var_s0 = (s32)this->actor.colChkInfo.health;
                    }
                    func_809E60A8(this, 2);
                } else if (this->unk1C0 == func_809E7458) {
                    if (var_s0 <= 0) {
                        var_s0 = 1;
                    }
                    func_809E60A8(this, 1);
                } else {
                    func_809E60A8(this, 0);
                }
            } else if ((this->actor.colChkInfo.damageEffect == 0xE) || (this->actor.colChkInfo.damageEffect == 0xF)) {
                if (var_s0 > 0) {
                    func_809E63EC(this);
                } else {
                    func_809E6170(this);
                }
            } else if (this->actor.colChkInfo.damageEffect != 1) {
                func_809E60A8(this, 0);
            } else {
                return;
            }
            if (var_s0 < 0) {
                this->actor.colChkInfo.health = 0;
            } else {
                this->actor.colChkInfo.health = (u8)var_s0;
            }
            if (this->actor.colChkInfo.damageEffect == 2) {
                new_var2 = this->unk230 * 70.0f;
                for (i = 0; i < 4; i++) {
                    EffectSsEnFire_SpawnVec3f(globalCtx, &this->actor, &this->actor.world.pos, (s16)new_var2, 0, 0,
                                              (s16)i);
                }
            }
        } else {
            return;
        }
    } else if ((globalCtx->actorCtx.unk_02 != 0) && (this->unk238.base.colType != 0xC) &&
               ((this->unk1C0 != func_809E79EC)) && (this->unk1C0 != func_809E78DC) &&
               (((this->actor.colChkInfo.health) != 0))) {
        this->actor.colChkInfo.health--;
        this->actor.dropFlag = 0;
        func_809E60A8(this, 1);
    } else {
        return;
    }
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

void EnDekubaba_Update(Actor* thisx, GlobalContext* globalCtx) {
    u8 temp_v0;
    EnDekubaba* this = (EnDekubaba*)thisx;

    temp_v0 = this->unk238.base.atFlags;
    if (temp_v0 & 2) {
        this->unk238.base.atFlags = temp_v0 & 0xFFFD;
        func_809E6078(this);
    }
    func_809E8140(this, globalCtx);
    this->unk1C0(this, globalCtx);
    if (this->unk1C0 == func_809E7BB0) {
        Actor_MoveForward(&this->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &this->actor, 10.0f, this->unk230 * 15.0f, 10.0f, 5);
    } else {
        if (this->unk1C0 != func_809E80D8) {
            Actor_UpdateBgCheckInfo(globalCtx, &this->actor, 0.0f, 0.0f, 0.0f, 4);
            if (this->unk234 == NULL) {
                this->unk234 = this->actor.floorPoly;
            }
        }
    }
    if (this->unk1C0 == func_809E7104) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &this->unk238.base);
        this->actor.flags |= 0x01000000;
    }
    if (this->unk238.base.acFlags & 1) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->unk238.base);
    }
    if (this->unk1C0 != func_809E80D8) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->unk238.base);
    }
}

void func_809E858C(EnDekubaba* this, GlobalContext* globalCtx) {
    f32 sp44;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0x98D);
    sp44 = this->unk230 * 0.01f;
    Matrix_Translate(this->actor.home.pos.x, this->actor.home.pos.y + (-6.0f * this->unk230), this->actor.home.pos.z,
                     0U);
    Matrix_RotateRPY(this->unk1CA, this->actor.shape.rot.y, 0, 1U);
    Matrix_Scale(sp44, sp44, sp44, 1U);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0x99D),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, D_6001330);
    Actor_SetFocus(&this->actor, 0.0f);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0x9A4);
}

#if 0
void func_809E86B8(EnDekubaba* this, GlobalContext* globalCtx) {
    MtxF spB0_real;
    f32 spA4_real;
    s32 sp9C_real;
    f32 temp_fs0_real;
    f32 temp_fs0_2_real;
    s32 var_s2_real;
    s32 var_s6;
    s32 var_s7;
    u32* var_s5;
    void* temp_v0_3;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0x9B7);
    if (func_809E7BB0 == this->unk1C0) {
        sp9C_real = 2;
    } else {
        sp9C_real = 3;
    }
    temp_fs0_real = this->unk230 * 0.01f;
    Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, 0U);
    Matrix_Scale(temp_fs0_real, temp_fs0_real, temp_fs0_real, 1U);
    Matrix_Get(&spB0_real);
    var_s2_real = 0;
    this = this;
    if (this->actor.colorFilterTimer != 0) {
        spA4_real = this->unk230 * 20.0f;
        this->unk164.x = this->actor.world.pos.x;
        this->unk164.z = this->actor.world.pos.z;
        this->unk164.y = this->actor.world.pos.y - spA4_real;
    }
    if (sp9C_real > 0) {
        var_s5 = D_809E902C;
        var_s6 = 0x33;
        var_s7 = 0x34;
        do {
            spB0_real.mf[3][1] += 20.0f * Math_SinS(this->unk1CA) * this->unk230;
            temp_fs0_2_real = Math_CosS(this->unk1CA) * 20.0f * this->unk230;
            spB0_real.mf[3][0] -= temp_fs0_2_real * Math_SinS(this->actor.shape.rot.y);
            spB0_real.mf[3][2] -= temp_fs0_2_real * Math_CosS(this->actor.shape.rot.y);
            Matrix_Put(&spB0_real);
            Matrix_RotateRPY(this->unk1CA, this->actor.shape.rot.y, 0, 1U);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0x9E5),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, *var_s5);
            Collider_UpdateSpheres(var_s6, &this->unk238);
            Collider_UpdateSpheres(var_s7, &this->unk238);
            if (var_s2_real == 0) {
                if (func_809E7A88 != this->unk1C0) {
                    this->actor.focus.pos.x = spB0_real.mf[3][0];
                    this->actor.focus.pos.y = spB0_real.mf[3][1];
                    this->actor.focus.pos.z = spB0_real.mf[3][2];
                } else {
                    this->actor.focus.pos.x = this->actor.home.pos.x;
                    this->actor.focus.pos.z = this->actor.home.pos.z;
                    this->actor.focus.pos.y = this->actor.home.pos.y + (40.0f * this->unk230);
                }
            }
            this += 2;
            if ((var_s2_real < 2) && (this->actor.colorFilterTimer != 0)) {
                temp_v0_3 = this + (var_s2_real * 0xC);
                *(f32*)((char*)temp_v0_3 + 0x14C) /*temp_v0_3->unk14C*/ = spB0_real.mf[3][0];
                *(f32*)((char*)temp_v0_3 + 0x150) /*temp_v0_3->unk150*/ = (f32)(spB0_real.mf[3][1] - spA4_real);
                *(f32*)((char*)temp_v0_3 + 0x154) /*temp_v0_3->unk154*/ = spB0_real.mf[3][2];
            }
            var_s2_real += 1;
            var_s5 += 4;
            var_s6 += 2;
            var_s7 += 2;
        } while (var_s2_real != sp9C_real);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xA09);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dekubaba/func_809E86B8.s")
#endif

void func_809E89E4(EnDekubaba* this, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xA13);
    Matrix_RotateRPY(this->unk1CE, this->actor.shape.rot.y, 0, 1U);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xA1A),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, D_6001828);
    Collider_UpdateSpheres(0x37, &this->unk238);
    Collider_UpdateSpheres(0x38, &this->unk238);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xA24);
}

void func_809E8AD8(EnDekubaba* this, GlobalContext* globalCtx) {
    MtxF sp50;
    f32 temp_fa0;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xA84);
    func_80094044(globalCtx->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x00, 0, 0, 0, 255);
    func_80038A28(this->unk234, this->actor.home.pos.x, this->actor.home.pos.y, this->actor.home.pos.z, &sp50);
    Matrix_Mult(&sp50, 0U);
    temp_fa0 = this->unk230 * 0.15f;
    Matrix_Scale(temp_fa0, 1.0f, temp_fa0, 1U);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xA96),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, D_4049210);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xA9B);
}

void func_809E8C0C(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3s* arg3, EnDekubaba* this) {
    if (arg1 == 1) {
        Collider_UpdateSpheres(arg1, &this->unk238);
    }
}

void EnDekubaba_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDekubaba* this = (EnDekubaba*)thisx;
    f32 sp50;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xAC0);
    func_80093D18(globalCtx->state.gfxCtx);
    if (this->unk1C0 != func_809E80D8) {
        SkelAnime_DrawOpa(globalCtx, this->unk17C.skeleton, this->unk17C.jointTable, NULL,
                          (void (*)(GlobalContext*, s32, Gfx**, Vec3s*, void*))func_809E8C0C, this);
        if (this->unk1C0 == func_809E64F4) {
            func_809E858C(this, globalCtx);
        } else {
            func_809E86B8(this, globalCtx);
        }
        sp50 = this->unk230 * 0.01f;
        Matrix_Translate(this->actor.home.pos.x, this->actor.home.pos.y, this->actor.home.pos.z, 0U);
        Matrix_RotateY((f32)this->actor.home.rot.y * 0.0000958738f, 1U);
        Matrix_Scale(sp50, sp50, sp50, 1U);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xADC),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, D_60010F0);
        if (this->unk1C0 == func_809E7BB0) {
            func_809E89E4(this, globalCtx);
        }
        if (this->unk234 != NULL) {
            func_809E8AD8(this, globalCtx);
        }
    } else {
        if ((this->unk1C6 >= 0x29) || (this->unk1C6 & 1)) {
            Matrix_Translate(0.0f, 0.0f, 200.0f, 1U);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xAED),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, D_6003070);
        };
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 0xAF4);
}
