/*
 * File: z_en_vali.c
 * Overlay: ovl_En_Vali
 * Description: Bari (Big Jellyfish)
 */

#include "z_en_vali.h"

#define FLAGS 0x00001015

#define THIS ((EnVali*)thisx)

void EnVali_Init(Actor* thisx, GlobalContext* globalCtx);
void EnVali_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnVali_Update(Actor* thisx, GlobalContext* globalCtx);
void EnVali_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B26878(EnVali* this);
void func_80B268C8(EnVali* this);
void func_80B268FC(EnVali* this);
void func_80B26B18(EnVali* this);
void func_80B26B4C(EnVali* this);
void func_80B26BBC(EnVali* this);
void func_80B26BF8(EnVali* this);
void func_80B26C50(EnVali* this, GlobalContext* globalCtx);
void func_80B26D54(EnVali* this);
void func_80B26DE0(EnVali* this);
void func_80B26E40(EnVali* this);
void func_80B26E9C(EnVali* this, GlobalContext* globalCtx);
void func_80B27098(EnVali* this, GlobalContext* globalCtx);
void func_80B270D8(EnVali* this, GlobalContext* globalCtx);
void func_80B2716C(EnVali* this, GlobalContext* globalCtx);
void func_80B27318(EnVali* this, GlobalContext* globalCtx);
void func_80B273D0(EnVali* this, GlobalContext* globalCtx);
void func_80B2742C(EnVali* this, GlobalContext* globalCtx);
void func_80B27464(EnVali* this, GlobalContext* globalCtx);
void func_80B274A0(EnVali* this, GlobalContext* globalCtx);
void func_80B27654(EnVali* this, GlobalContext* globalCtx);
void func_80B27710(EnVali* this, GlobalContext* globalCtx);
void func_80B278A0(EnVali* this, GlobalContext* globalCtx);
void func_80B2790C(EnVali* this, GlobalContext* globalCtx);
void func_80B27C1C(EnVali* this, f32 arg1, Vec3f* arg2);
void func_80B27E38(EnVali* this, f32 arg1, Vec3f* arg2);
s32 func_80B28054(EnVali* this, f32 arg1);
s32 func_80B281F0(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3f* arg3, Vec3s* arg4, EnVali* this, Gfx** gfx);
void func_80B28280(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3s* arg3, EnVali* this, Gfx** gfx);
void func_80B28344(EnVali* this, GlobalContext* globalCtx);

extern AnimationHeader D_6000710;
extern AnimationHeader D_6000854;
extern AnimationHeader D_6000B34;
extern AnimationHeader D_60014AC;
extern Gfx D_6002610[];
extern Gfx D_6002740[];
extern Gfx D_60027D8[];
extern SkeletonHeader D_6004848;

const ActorInit En_Vali_InitVars = {
    ACTOR_EN_VALI,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_VALI,
    sizeof(EnVali),
    (ActorFunc)EnVali_Init,
    (ActorFunc)EnVali_Destroy,
    (ActorFunc)EnVali_Update,
    (ActorFunc)EnVali_Draw,
};

static ColliderQuadInit D_80B288A0 = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x07, 0x08 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static ColliderCylinderInit D_80B288F0 = {
    {
        COLTYPE_HIT8,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x07, 0x08 },
        { 0xFFCFFFFF, 0x01, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 17, 35, -15, { 0, 0, 0 } },
};

static CollisionCheckInfoInit D_80B2891C = { 2, 0x12, 0x20, 0xFE };
static DamageTable D_80B28924 = {
    {
        0x10, 2,    0xE0, 2, 0x10, 2, 2, 2, 0xF1, 0xF2, 0xF4, 0x24, 0x34, 2, 2, 2,
        2,    0x24, 0x34, 0, 0,    0, 1, 4, 2,    2,    8,    4,    0,    0, 4, 0,
    },
};
static InitChainEntry D_80B28944[3] = {
    ICHAIN_S8(naviEnemyId, 24, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 5000, ICHAIN_STOP),
};
static Color_RGBA8 D_80B28950 = { 0xFF, 0xFF, 0xFF, 0xFF };
static Color_RGBA8 D_80B28954 = { 0xC8, 0xFF, 0xFF, 0xFF };

void EnVali_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnVali* this = (EnVali*)thisx;
    s32 sp34;

    Actor_ProcessInitChain(&this->actor, D_80B28944);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 27.0f);
    this->actor.shape.shadowAlpha = 0x9B;
    SkelAnime_Init(globalCtx, &this->unk14C, &D_6004848, &D_60014AC, this->unk198, this->unk246, 0x1D);
    Collider_InitQuad(globalCtx, &this->unk2FC);
    Collider_SetQuad(globalCtx, &this->unk2FC, &this->actor, &D_80B288A0);
    Collider_InitQuad(globalCtx, &this->unk37C);
    Collider_SetQuad(globalCtx, &this->unk37C, &this->actor, &D_80B288A0);
    Collider_InitCylinder(globalCtx, &this->unk3FC);
    Collider_SetCylinder(globalCtx, &this->unk3FC, &this->actor, &D_80B288F0);
    CollisionCheck_SetInfo(&this->actor.colChkInfo, &D_80B28924, &D_80B2891C);
    func_80B26878(this);
    this->actor.flags &= ~1;
    this->actor.floorHeight = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &this->actor.floorPoly, &sp34,
                                                          &this->actor, &this->actor.world.pos);
    this->actor.params = 0;
    if (this->actor.floorHeight == -32000.0f) {
        Actor_Kill(&this->actor);
    }
}

void EnVali_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnVali* this = (EnVali*)thisx;
    Collider_DestroyQuad(globalCtx, &this->unk2FC);
    Collider_DestroyQuad(globalCtx, &this->unk37C);
    Collider_DestroyCylinder(globalCtx, &this->unk3FC);
}

void func_80B26878(EnVali* this) {
    Animation_PlayLoop(&this->unk14C, &D_60014AC);
    this->actor.draw = NULL;
    this->unk3FC.base.acFlags &= ~1;
    this->unk190 = func_80B27098;
}

void func_80B268C8(EnVali* this) {
    this->actor.draw = EnVali_Draw;
    this->actor.flags |= 1;
    this->unk190 = func_80B270D8;
    this->actor.velocity.y = 1.0f;
}

void func_80B268FC(EnVali* this) {
    Vec3f sp84;
    Vec3f sp78;
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;
    Vec3f sp48;
    Vec3f sp3C;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 pad[6];

    Animation_MorphToLoop(&this->unk14C, &D_6000710, -3.0f);
    sp3C = this->actor.world.pos;
    this->unk37C.dim.quad[1] = sp3C;
    sp48 = sp3C;
    this->unk37C.dim.quad[0] = sp48;
    sp54 = sp48;
    this->unk2FC.dim.quad[1] = sp54;
    sp60 = sp54;
    this->unk2FC.dim.quad[0] = sp60;
    sp6C = sp60;
    this->unk37C.dim.quad[3] = sp6C;
    sp78 = sp6C;
    this->unk37C.dim.quad[2] = sp78;
    sp84 = sp78;
    this->unk2FC.dim.quad[3] = sp84;
    temp_fv1 = this->actor.world.pos.y;
    temp_fv0 = temp_fv1 - 10.0f;
    this->unk2FC.dim.quad[2] = sp84;
    this->unk2FC.dim.quad[2].y = temp_fv0;
    this->unk2FC.dim.quad[3].y = temp_fv0;
    this->unk37C.dim.quad[2].y = temp_fv0;
    this->unk37C.dim.quad[3].y = temp_fv0;
    this->unk2FC.dim.quad[0].y = temp_fv0;
    this->unk2FC.dim.quad[1].y = temp_fv0;
    this->unk37C.dim.quad[0].y = temp_fv0;
    this->unk37C.dim.quad[1].y = temp_fv0;
    this->actor.flags &= ~0x10;
    this->unk3FC.base.acFlags |= 1;
    this->unk195 = 0;
    this->unk190 = func_80B2716C;
    this->unk2F8 = temp_fv1;
}

void func_80B26B18(EnVali* this) {
    this->unk194 = 0x14;
    this->actor.flags &= ~1;
    this->unk3FC.base.acFlags &= ~1;
    this->unk190 = func_80B27318;
}

void func_80B26B4C(EnVali* this) {
    Animation_MorphToPlayOnce(&this->unk14C, &D_6000854, -5.0f);
    Actor_SetColorFilter(&this->actor, 0x4000, 0x96, 0x2000, 0x1E);
    this->actor.params = 0;
    this->unk3FC.base.acFlags &= 0xFFFE;
    this->unk190 = func_80B273D0;
}

void func_80B26BBC(EnVali* this) {
    Animation_PlayOnce(&this->unk14C, &D_6000B34);
    this->unk190 = func_80B2742C;
}

void func_80B26BF8(EnVali* this) {
    this->unk196 = 2;
    this->unk3FC.base.acFlags &= 0xFFFE;
    Actor_SetColorFilter(&this->actor, 0x4000, 0x96, 0x2000, 0x1E);
    this->unk190 = func_80B27464;
}

void func_80B26C50(EnVali* this, GlobalContext* globalCtx) {
    PosRot* temp_s1;
    s32 var_s1;

    var_s1 = 0;
    do {
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, 0x34, this->actor.world.pos.x, this->actor.world.pos.y,
                    this->actor.world.pos.z, 0, (s16)(s32)this->actor.world.rot.y, 0, 0);
        var_s1 += 1;
        this->actor.world.rot.y += 0x5555;
    } while (var_s1 != 3);
    temp_s1 = &this->actor.world;
    Item_DropCollectibleRandom(globalCtx, &this->actor, &temp_s1->pos, 0x50);
    this->unk196 = Rand_S16Offset(0xA, 0xA);
    this->unk3FC.base.acFlags &= 0xFFFE;
    Audio_PlaySoundAtPosition(globalCtx, &temp_s1->pos, 0x28, 0x3887U);
    this->actor.flags &= ~1;
    this->actor.draw = NULL;
    this->unk190 = func_80B274A0;
}

void func_80B26D54(EnVali* this) {
    Animation_MorphToPlayOnce(&this->unk14C, &D_6000710, 10.0f);
    this->unk196 = 0x50;
    this->actor.velocity.y = 0.0f;
    Actor_SetColorFilter(&this->actor, 0, 0xFF, 0x2000, 0x50);
    this->unk3FC.info.bumper.effect = 0;
    Audio_PlayActorSound2(&this->actor, 0x389EU);
    this->unk190 = func_80B27654;
    this->actor.velocity.y = 1.0f;
}

void func_80B26DE0(EnVali* this) {
    this->actor.velocity.y = 0.0f;
    Actor_SetColorFilter(&this->actor, 0, 0xFF, 0x2000, 0x24);
    this->unk3FC.base.acFlags &= ~1;
    this->unk196 = 0x24;
    this->unk190 = func_80B27710;
}

void func_80B26E40(EnVali* this) {
    u32 temp_t7;

    Animation_MorphToPlayOnce(&this->unk14C, &D_60014AC, 10.0f);
    this->actor.flags |= 0x10;
    this->actor.flags &= ~1;
    this->unk190 = func_80B278A0;
}

void func_80B26E9C(EnVali* this, GlobalContext* globalCtx) {
    Vec3f sp8C;
    f32 temp_fs1;
    f32 temp_fs2;
    s32 var_s1;
    s16 temp_v0;

    for (var_s1 = 0; var_s1 < 4; var_s1++) {
        temp_fs1 = -Math_CosS(Camera_GetCamDirYaw(globalCtx->cameraPtrs[globalCtx->activeCamera]));
        temp_fs2 = Math_SinS(Camera_GetCamDirYaw(globalCtx->cameraPtrs[globalCtx->activeCamera]));
        if (!((s32)(this->unk194 + (var_s1 << 1)) % 4)) {
            temp_v0 = (s16)Rand_CenteredFloat(12288.0f) + (var_s1 * 0x4000) + 0x2000;
            sp8C.x = (Math_SinS(temp_v0) * 12.0f * temp_fs1) + this->actor.world.pos.x;
            sp8C.y = (this->actor.world.pos.y - (Math_CosS(temp_v0) * 12.0f)) + 10.0f;
            sp8C.z = (Math_SinS(temp_v0) * 12.0f * temp_fs2) + this->actor.world.pos.z;
            EffectSsLightning_Spawn(globalCtx, (Vec3f*)&sp8C, &D_80B28950, &D_80B28954, 0x11, (s16)(s32)temp_v0, 6, 2);
        }
    }
    func_8002F974(&this->actor, 0x309AU);
}

void func_80B27098(EnVali* this, GlobalContext* globalCtx) {
    if (this->actor.xzDistToPlayer < 150.0f) {
        func_80B268C8(this);
    }
}

void func_80B270D8(EnVali* this, GlobalContext* globalCtx) {
    f32 temp_fv0;

    SkelAnime_Update(&this->unk14C);
    this->actor.velocity.y *= 1.5f;
    temp_fv0 = this->actor.velocity.y;
    if (temp_fv0 > 40.0f) {
        this->actor.velocity.y = 40.0f;
    } else {
        this->actor.velocity.y = temp_fv0;
    }
    if (Math_StepToF(&this->actor.world.pos.y, this->actor.floorHeight, this->actor.velocity.y) != 0) {
        Audio_PlayActorSound2(&this->actor, 0x387BU);
        func_80B268FC(this);
    }
}

void func_80B2716C(EnVali* this, GlobalContext* globalCtx) {
    s32 var_v1;

    SkelAnime_Update(&this->unk14C);
    if (this->unk195 != 0) {
        this->unk195 -= 1;
    }
    var_v1 = (s32)this->unk14C.curFrame;
    Math_StepToF(&this->unk2F8, this->actor.floorHeight + 40.0f, 1.2f);
    this->actor.world.pos.y = this->unk2F8 - (sinf((f32)var_v1 * 3.1415927f * 0.0125f) * 8.0f);
    if (this->unk195 != 0) {
        this->actor.shape.rot.y += 0x800;
        if ((((s32)this->unk195 % 6) == 0) && (var_v1 >= 0x10) && (var_v1 < 0x38)) {
            Audio_PlayActorSound2(&this->actor, 0x389DU);
        }
    } else if ((var_v1 == 0x10) || (var_v1 == 0x1E) || (var_v1 == 0x2A) || (var_v1 == 0x37)) {
        Audio_PlayActorSound2(&this->actor, 0x389DU);
    }
    if (var_v1 >= 0x29) {
        var_v1 = 0x50 - var_v1;
    }
    this->actor.shape.rot.y += (s16)(s32)((f32)(var_v1 + 4) * 0.4f * 182.04445f);
    if (this->actor.xzDistToPlayer > 250.0f) {
        func_80B26E40(this);
    }
}

void func_80B27318(EnVali* this, GlobalContext* globalCtx) {
    if (this->unk194 != 0) {
        this->unk194 -= 1;
    }
    func_80B26E9C(this, globalCtx);
    if (this->unk194 == 0) {
        this->actor.flags |= 1;
        this->unk3FC.base.acFlags |= 1;
        if (this->actor.params == 1) {
            func_80B26B4C(this);
            return;
        }
        this->unk190 = func_80B2716C;
        return;
    }
    if (this->unk194 & 1) {
        this->actor.world.pos.y += 1.0f;
        return;
    }
    this->actor.world.pos.y -= 1.0f;
}

void func_80B273D0(EnVali* this, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&this->unk14C) != 0) {
        if (this->actor.colChkInfo.health != 0) {
            func_80B26BBC(this);
            return;
        }
        func_80B26C50(this, globalCtx);
    }
}

void func_80B2742C(EnVali* this, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&this->unk14C) != 0) {
        func_80B268FC(this);
    }
}

void func_80B27464(EnVali* this, GlobalContext* globalCtx) {
    if (this->unk196 != 0) {
        this->unk196 -= 1;
    }
    if (this->unk196 == 0) {
        func_80B26C50(this, globalCtx);
    }
}

void func_80B274A0(EnVali* this, GlobalContext* globalCtx) {
    static Vec3f D_80B28958 = { 0.0f, 0.0f, 0.0f };
    static Vec3f D_80B28964 = { 0.0f, 0.0f, 0.0f };
    s16 temp_s0;
    Vec3f sp70;
    s32 var_s1;

    if (this->unk196 != 0) {
        this->unk196 -= 1;
    }
    for (var_s1 = 0; var_s1 < 2; var_s1++) {
        sp70.x = Rand_CenteredFloat(20.0f) + this->actor.world.pos.x;
        sp70.y = Rand_CenteredFloat(8.0f) + this->actor.world.pos.y;
        sp70.z = Rand_CenteredFloat(20.0f) + this->actor.world.pos.z;
        D_80B28958.y = Rand_ZeroOne() + 1.0f;
        temp_s0 = Rand_S16Offset(0x28, 0x28);
        if (Rand_ZeroOne() < 0.7f) {
            EffectSsDtBubble_SpawnColorProfile(globalCtx, (Vec3f*)&sp70, &D_80B28958, &D_80B28964, (s16)(s32)temp_s0,
                                               0x19, 2, 1);
        } else {
            EffectSsDtBubble_SpawnColorProfile(globalCtx, (Vec3f*)&sp70, &D_80B28958, &D_80B28964, (s16)(s32)temp_s0,
                                               0x19, 0, 1);
        }
    }
    if (this->unk196 == 0) {
        Actor_Kill(&this->actor);
    }
}

static Vec3f D_80B28970 = { 3000.0f, 0.0f, 0.0f };
static Vec3f D_80B2897C = { -1000.0f, 0.0f, 0.0f };
static Vec3f D_80B28988 = { 1.0f, 1.0f, 1.0f };
static Gfx D_80B28998[2] = { { { 0xFC621603, 0x1F5BFFF8 } }, { { 0xDF000000, 0 } } };
static Gfx D_80B289A8[3] = { { { 0xFC121603, 0xFF5BFFF8 } }, { { 0xDF000000, 0 } }, { { 0, 0 } } };

void func_80B27654(EnVali* this, GlobalContext* globalCtx) {
    s16 temp_v1;

    SkelAnime_Update(&this->unk14C);
    temp_v1 = this->unk196;
    if (temp_v1 != 0) {
        this->unk196 = temp_v1 - 1;
    }
    if (this->actor.velocity.y != 0.0f) {
        if (Math_StepToF(&this->actor.world.pos.y, this->actor.floorHeight, this->actor.velocity.y) != 0) {
            this->actor.velocity.y = 0.0f;
            Audio_PlayActorSound2(&this->actor, 0x387BU);
        } else {
            this->actor.velocity.y += 1.0f;
        }
    }
    if (this->unk196 == 0) {
        this->unk3FC.info.bumper.effect = 1;
        func_80B268FC(this);
    }
}

void func_80B27710(EnVali* this, GlobalContext* globalCtx) {
    Vec3f sp54;
    s32 temp_v0_2;
    s32 temp_v1;

    if (this->unk196 != 0) {
        this->unk196 -= 1;
    }
    temp_v1 = this->unk196 - 0x14;
    this->actor.colorFilterTimer = 0x24;
    if (temp_v1 > 0) {
        temp_v0_2 = temp_v1 >> 1;
        if (this->unk196 & 1) {
            sp54.y = (this->actor.world.pos.y - 20.0f) + ((-temp_v0_2 * 5) + 0x28);
            sp54.x = this->actor.world.pos.x + ((temp_v0_2 & 2) ? 12.0f : -12.0f);
            sp54.z = this->actor.world.pos.z + ((temp_v0_2 & 1) ? 12.0f : -12.0f);
            EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &this->actor, (Vec3f*)&sp54, 0x96, 0x96, 0x96, 0xFA, 0xEB, 0xF5,
                                           0xFF, (Rand_ZeroOne() * 0.2f) + 1.3f);
        }
    } else if (this->unk196 == 0) {
        this->actor.velocity.y += 1.0f;
        if (Math_StepToF(&this->actor.world.pos.y, this->actor.floorHeight, this->actor.velocity.y) != 0) {
            func_80B26C50(this, globalCtx);
            this->actor.colorFilterTimer = 0;
        }
    }
}

void func_80B278A0(EnVali* this, GlobalContext* globalCtx) {
    SkelAnime_Update(&this->unk14C);
    if (Math_SmoothStepToF(&this->actor.world.pos.y, this->actor.home.pos.y, 0.5f, 15.0f, 0.1f) < 0.01f) {
        func_80B26878(this);
    }
}

void func_80B2790C(EnVali* this, GlobalContext* globalCtx) {
    if ((this->unk3FC.base.acFlags & 2)) {
        this->unk3FC.base.acFlags &= 0xFFFD;
        if (((func_80035650(&this->actor, &this->unk3FC.info, 1), (this->actor.colChkInfo.damageEffect != 0)) ||
             (this->actor.colChkInfo.damage != 0))) {
            if (Actor_ApplyDamage(&this->actor) == 0) {
                Audio_PlayActorSound2(&this->actor, 0x389FU);
                func_80032C7C(globalCtx, &this->actor);
                this->actor.flags &= ~1;
            } else {
                if ((this->actor.colChkInfo.damageEffect != 1) && (this->actor.colChkInfo.damageEffect != 0xE)) {
                    Audio_PlayActorSound2(&this->actor, 0x38DCU);
                }
            }
            if (this->actor.colChkInfo.damageEffect == 1) {
                if (this->unk190 != func_80B27654) {
                    func_80B26D54(this);
                }
            } else {
                if (this->actor.colChkInfo.damageEffect == 0xF) {
                    if (this->unk190 != func_80B27654) {
                        Actor_SetColorFilter(&this->actor, 0x4000, 0x96, 0x2000, 0x1E);
                        this->actor.params = 1;
                        func_80B26B18(this);
                        return;
                    }
                    func_80B26B4C(this);
                    return;
                }
                if (this->actor.colChkInfo.damageEffect == 2) {
                    func_80B26BF8(this);
                    return;
                }
                if (this->actor.colChkInfo.damageEffect == 3) {
                    func_80B26DE0(this);
                    return;
                }
                if (this->actor.colChkInfo.damageEffect == 0xE) {
                    if (this->unk195 == 0) {
                        this->unk195 = 0x14;
                    }
                } else {
                    func_80B26B4C(this);
                }
            }
        }
    }
}

void EnVali_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnVali* this = (EnVali*)thisx;
    s32 pad;

    if ((this->unk3FC.base.atFlags & 2) || (this->unk2FC.base.atFlags & 2) || (this->unk37C.base.atFlags & 2)) {
        this->unk2FC.base.atFlags &= ~2;
        this->unk37C.base.atFlags &= ~2;
        this->unk3FC.base.atFlags &= ~2;
        func_80B26B18(this);
    }
    func_80B2790C(this, globalCtx);
    this->unk190(this, globalCtx);
    if ((this->unk190 != func_80B274A0) && (this->unk190 != func_80B27098)) {
        Collider_UpdateCylinder(&this->actor, &this->unk3FC);
        if (this->unk190 == func_80B2716C) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &this->unk2FC.base);
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &this->unk37C.base);
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &this->unk3FC.base);
        }
        if (this->unk3FC.base.acFlags & 1) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->unk3FC.base);
        }
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->unk3FC.base);
        Actor_SetFocus(&this->actor, 0.0f);
    }
}

void func_80B27C1C(EnVali* this, f32 arg1, Vec3f* arg2) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;
    s32 var_v0;

    if (this->unk190 == func_80B27318) {
        var_v0 = 0x14 - ((s32)this->unk194 % 20);
        if (var_v0 >= 0xA) {
            var_v0 -= 0xA;
        }
        arg2->y -= 0.2f * sinf((f32)var_v0 * 0.31415927f);
        return;
    }
    if (this->unk190 == func_80B273D0) {
        temp_fv0 = sinf(0.31415927f * arg1);
        arg2->y -= 0.24f * temp_fv0;
        arg2->x -= 0.13f * temp_fv0;
        arg2->z = arg2->x;
        return;
    }
    if (this->unk190 == func_80B2742C) {
        temp_fv0_2 = cosf(0.06283186f * arg1);
        arg2->y -= 0.24f * temp_fv0_2;
        arg2->x -= 0.13f * temp_fv0_2;
        arg2->z = arg2->x;
        return;
    }
    if (this->unk190 == func_80B27654) {
        temp_fv1 = sinf((f32)this->unk196 * 0.31415927f) * 0.08f;
        arg2->x += temp_fv1;
        arg2->y -= temp_fv1;
        arg2->z += temp_fv1;
        return;
    }
    if (arg1 >= 40.0f) {
        arg1 -= 40.0f;
    }
    arg2->y -= 0.2f * sinf(0.07853982f * arg1);
}

void func_80B27E38(EnVali* this, f32 arg1, Vec3f* arg2) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;
    s32 var_v0;

    if (this->unk190 == func_80B27318) {
        var_v0 = 0x14 - ((s32)this->unk194 % 20);
        if (var_v0 >= 0xA) {
            var_v0 -= 0xA;
        }
        arg2->y -= 0.13f * sinf((f32)var_v0 * 0.31415927f);
        return;
    }
    if (this->unk190 == func_80B273D0) {
        temp_fv0 = sinf(0.31415927f * arg1);
        arg2->y -= 0.18f * temp_fv0;
        arg2->x -= 0.1f * temp_fv0;
        arg2->z = arg2->x;
        return;
    }
    if (this->unk190 == func_80B2742C) {
        temp_fv0_2 = cosf(0.06283186f * arg1);
        arg2->y -= 0.18f * temp_fv0_2;
        arg2->x -= 0.1f * temp_fv0_2;
        arg2->z = arg2->x;
        return;
    }
    if (this->unk190 == func_80B27654) {
        temp_fv1 = sinf((f32)this->unk196 * 0.31415927f) * 0.08f;
        arg2->x -= temp_fv1;
        arg2->y += temp_fv1;
        arg2->z -= temp_fv1;
        return;
    }
    if (arg1 >= 40.0f) {
        arg1 -= 40.0f;
    }
    arg2->y -= 0.13f * sinf(0.07853982f * arg1);
}

s32 func_80B28054(EnVali* this, f32 arg1) {
    f32 var_fv1;

    if (this->unk190 == func_80B2716C) {
        if (arg1 <= 10.0f) {
            var_fv1 = (arg1 * 0.05f) + 1.0f;
        } else if (arg1 > 70.0f) {
            var_fv1 = ((80.0f - arg1) * 0.05f) + 1.0f;
        } else {
            var_fv1 = 1.5f;
        }
    } else if (this->unk190 == func_80B273D0) {
        var_fv1 = 1.0f - (sinf(0.31415927f * arg1) * 0.35f);
    } else if (this->unk190 == func_80B2742C) {
        var_fv1 = 1.0f - (cosf(0.06283186f * arg1) * 0.35f);
    } else if ((this->unk190 == func_80B27318) || (this->unk190 == func_80B27710)) {
        var_fv1 = this->unk2F4;
    } else {
        var_fv1 = 1.0f;
    }
    Math_StepToF(&this->unk2F4, var_fv1, 0.1f);
    if (this->unk2F4 == 1.0f) {
        return 0;
    } else {
        return 1;
    }
}

s32 func_80B281F0(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3f* arg3, Vec3s* arg4, EnVali* thisx, Gfx** gfx) {
    EnVali* this = thisx;
    f32 new_var;

    if ((arg1 == 2) || (arg1 == 0x1C) || (arg1 == 0x1B)) {
        *arg2 = NULL;
        return 0;
    } else {
        new_var = this->unk14C.curFrame;
        if (((arg1 == 9) || (arg1 == 0x12)) && (func_80B28054(this, new_var) != 0)) {
            Matrix_Scale(this->unk2F4, 1.0f, 1.0f, 1U);
        }
        return 0;
    }
}

void func_80B28280(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3s* arg3, EnVali* this, Gfx** gfx) {
    Vec3f sp3C;
    Vec3f sp30;

    if (this->unk190 == func_80B2716C) {
        switch (arg1) {
            case 0xB:
            case 0x14:
                Matrix_MultVec3f(&D_80B28970, &sp3C);
                Matrix_MultVec3f(&D_80B2897C, &sp30);
                if (arg1 == 0xB) {
                    Collider_SetQuadVertices(&this->unk2FC, &sp30, &sp3C, this->unk2FC.dim.quad,
                                             &this->unk2FC.dim.quad[1]);
                    return;
                }
                Collider_SetQuadVertices(&this->unk37C, &sp30, &sp3C, this->unk37C.dim.quad, &this->unk37C.dim.quad[1]);
                break;
        }
    }
}

void func_80B28344(EnVali* this, GlobalContext* globalCtx) {
    MtxF sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    Vec3f sp68;

    sp68 = D_80B28988;
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_vali.c", 0x594);
    Matrix_Get(&sp80);
    sp74 = this->unk14C.curFrame;
    func_80B27E38(this, sp74, &sp68);
    Matrix_Scale(sp68.x, sp68.y, sp68.z, 1U);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vali.c", 0x59C),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, D_6002610);
    Matrix_Put(&sp80);
    Matrix_RotateY((f32) - this->actor.shape.rot.y * 0.0000958738f, 1U);
    sp7C = Math_CosS(this->actor.shape.rot.y);
    sp78 = Math_SinS(this->actor.shape.rot.y);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vali.c", 0x5A6),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, D_6002740);
    Matrix_Translate((506.0f * sp7C) + (372.0f * sp78), 1114.0f, (372.0f * sp7C) - (506.0f * sp78), 1U);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vali.c", 0x5AF),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, D_6002740);
    Matrix_Translate((-964.0f * sp7C) - (804.0f * sp78), -108.0f, (-804.0f * sp7C) + (964.0f * sp78), 1U);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vali.c", 0x5B7),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, D_6002740);
    Matrix_Put(&sp80);
    sp68.z = 1.0f;
    sp68.y = 1.0f;
    sp68.x = 1.0f;
    func_80B27C1C(this, sp74, &sp68);
    Matrix_Scale(sp68.x, sp68.y, sp68.z, 1U);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vali.c", 0x5BF),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, D_60027D8);
    Matrix_Put(&sp80);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_vali.c", 0x5C5);
}

void EnVali_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnVali* this = (EnVali*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_vali.c", 0x5E1);
    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(
        POLY_XLU_DISP++, 8,
        Gfx_TexScroll(globalCtx->state.gfxCtx, 0U, (0x7F - (globalCtx->gameplayFrames * 0xC)) & 0x7F, 0x20, 0x20));
    if (this->unk194 & 1) {
        gSPSegment(POLY_XLU_DISP++, 9, D_80B28998);
    } else {
        gSPSegment(POLY_XLU_DISP++, 9, D_80B289A8);
    }
    func_80B28344(this, globalCtx);
    POLY_XLU_DISP =
        SkelAnime_Draw(globalCtx, this->unk14C.skeleton, this->unk14C.jointTable,
                       (s32(*)(GlobalContext*, s32, Gfx**, Vec3f*, Vec3s*, void*, Gfx**))func_80B281F0,
                       (void (*)(GlobalContext*, s32, Gfx**, Vec3s*, void*, Gfx**))func_80B28280, this, POLY_XLU_DISP);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_vali.c", 0x602);
}
