/*
 * File: z_en_wf.c
 * Overlay: ovl_En_Wf
 * Description: Wolfos
 */

#include "z_en_wf.h"

#define FLAGS 0x00000015

#define THIS ((EnWf*)thisx)

void EnWf_Init(Actor* thisx, GlobalContext* globalCtx);
void EnWf_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnWf_Update(Actor* thisx, GlobalContext* globalCtx);
void EnWf_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B33CB0(EnWf* this, void (*arg1)(EnWf*, GlobalContext*));
s32 func_80B33FB0(GlobalContext* arg0, EnWf* this, s16 arg2);
void func_80B34380(EnWf* this);
void func_80B34428(EnWf* this, GlobalContext* globalCtx);
void func_80B3455C(EnWf* this);
void func_80B345E4(EnWf* this, GlobalContext* globalCtx);
void func_80B347FC(EnWf* this, GlobalContext* globalCtx);
void func_80B3487C(EnWf* this, GlobalContext* globalCtx);
void func_80B34CFC(EnWf* this);
void func_80B34D48(EnWf* this, GlobalContext* globalCtx);
void func_80B34F28(EnWf* this);
void func_80B35024(EnWf* this, GlobalContext* globalCtx);
void func_80B35540(EnWf* this);
void func_80B355BC(EnWf* this, GlobalContext* globalCtx);
void func_80B3590C(EnWf* this);
void func_80B359A8(EnWf* this, GlobalContext* globalCtx);
void func_80B35B94(EnWf* this);
void func_80B35C10(EnWf* this, GlobalContext* globalCtx);
void func_80B35D18(EnWf* this);
void func_80B35D90(EnWf* this, GlobalContext* globalCtx);
void func_80B35E4C(EnWf* this);
void func_80B35EE4(EnWf* this, GlobalContext* globalCtx);
void func_80B360E8(EnWf* this);
void func_80B361A0(EnWf* this, GlobalContext* globalCtx);
void func_80B36288(EnWf* this);
void func_80B36328(EnWf* this, GlobalContext* globalCtx);
void func_80B365A8(EnWf* this, GlobalContext* globalCtx);
void func_80B36740(EnWf* this, GlobalContext* globalCtx);
void func_80B36C8C(EnWf* this);
void func_80B36D3C(EnWf* this, GlobalContext* globalCtx);
void func_80B36F40(EnWf* this, GlobalContext* globalCtx);
void func_80B37038(EnWf* this, GlobalContext* globalCtx);
s32 func_80B37454(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3f* arg3, Vec3s* arg4, EnWf* this);
void func_80B37494(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3s* arg3, EnWf* this);
s32 func_80B37830(GlobalContext* globalCtx, EnWf* this);

extern FlexSkeletonHeader D_6003BC0;
extern AnimationHeader D_6004638;
extern AnimationHeader D_6004AD0;
extern AnimationHeader D_6004CA4;
extern AnimationHeader D_6005430;
extern AnimationHeader D_60057A0;
extern FlexSkeletonHeader D_6009690;
extern AnimationHeader D_60098C8;
extern AnimationHeader D_6009B20;
extern AnimationHeader D_600A4AC;

static ColliderJntSphElementInit D_80B37990[4] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x04 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 15, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x04 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 21, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK1,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFC1FFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 17, { { 800, 0, 0 }, 25 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK1,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFC1FFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 12, { { 0, 0, 0 }, 30 }, 100 },
    },
};

static ColliderJntSphInit D_80B37A20 = {
    {
        COLTYPE_METAL,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    4,
    D_80B37990,
};

static ColliderCylinderInit D_80B37A30 = {
    {
        COLTYPE_HIT5,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK1,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 20, 50, 0, { 0, 0, 0 } },
};

static ColliderCylinderInit D_80B37A5C = {
    {
        COLTYPE_HIT5,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK1,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 15, 20, -15, { 0, 0, 0 } },
};

static DamageTable D_80B37A88 = {
    {
        0x10, 2,    1,    2,    0x10, 2, 2, 0x10, 1, 2, 4, 0xE4, 2, 2, 2, 2,
        2,    0xE4, 0x60, 0xD3, 0,    0, 1, 4,    2, 2, 8, 4,    0, 0, 4, 0,
    },
};

const ActorInit En_Wf_InitVars = {
    ACTOR_EN_WF,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_WF,
    sizeof(EnWf),
    (ActorFunc)EnWf_Init,
    (ActorFunc)EnWf_Destroy,
    (ActorFunc)EnWf_Update,
    (ActorFunc)EnWf_Draw,
};

static InitChainEntry D_80B37AC8[2] = {
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -3000, ICHAIN_STOP),
};
static Vec3f D_80B37AD0 = { 0.0f, 0.5f, 0.0f };
static Vec3f D_80B37ADC = { 1200.0f, 0.0f, 0.0f };
static Vec3f D_80B37AE8 = { 0.0f, 0.0f, 0.0f };
static s32 D_80B37AF4[4] = { 0x06007B68, 0x06008368, 0x06008568, 0x06008368 };
static s32 D_80B37B04[7] = { 0x06000300, 0x060027D8, 0x060029D8, 0x060027D8, 0, 0, 0 };

void func_80B33CB0(EnWf* this, void (*arg1)(EnWf*, GlobalContext*)) {
    this->unk2DC = arg1;
}

void EnWf_Init(Actor* thisx, GlobalContext* globalCtx) {
    ColliderJntSphElement* temp_v0;
    EnWf* this = (EnWf*)thisx;

    Actor_ProcessInitChain(&this->actor, D_80B37AC8);
    this->actor.colChkInfo.damageTable = &D_80B37A88;
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 0.0f);
    this->actor.focus.pos = this->actor.world.pos;
    this->actor.colChkInfo.mass = 0xFE;
    this->actor.colChkInfo.health = 8;
    this->actor.colChkInfo.cylRadius = 0x32;
    this->actor.colChkInfo.cylHeight = 0x64;
    this->unk2FC = ((s16)thisx->params >> 8) & 0xFF;
    this->actor.params &= 0xFF;
    this->unk302 = 0;
    this->unk2F4 = 10.0f;
    Collider_InitJntSph(globalCtx, &this->unk304);
    Collider_SetJntSph(globalCtx, &this->unk304, &this->actor, &D_80B37A20, this->unk324);
    Collider_InitCylinder(globalCtx, &this->unk424);
    Collider_SetCylinder(globalCtx, &this->unk424, &this->actor, &D_80B37A30);
    Collider_InitCylinder(globalCtx, &this->unk470);
    Collider_SetCylinder(globalCtx, &this->unk470, &this->actor, &D_80B37A5C);
    if (this->actor.params == 0) {
        SkelAnime_InitFlex(globalCtx, &this->unk188, &D_6009690, &D_600A4AC, this->unk1CC, this->unk250, 0x16);
        Actor_SetScale(&this->actor, 0.0075f);
        this->actor.naviEnemyId = 0x4C;
    } else {
        SkelAnime_InitFlex(globalCtx, &this->unk188, &D_6003BC0, &D_600A4AC, this->unk1CC, this->unk250, 0x16);
        Actor_SetScale(&this->actor, 0.01f);
        this->unk304.elements[1].info.toucher.damage = 8U;
        temp_v0 = this->unk304.elements;
        temp_v0->info.toucher.damage = temp_v0[1].info.toucher.damage;
        this->actor.naviEnemyId = 0x57;
    }
    func_80B34380(this);
    if ((this->unk2FC != 0xFF) && (Flags_GetSwitch(globalCtx, (s32)this->unk2FC) != 0)) {
        Actor_Kill(&this->actor);
    }
}

typedef struct UnkActor {
    Actor actor;
    char pad14C[0x152 - 0x14C];
    s16 unk152;
} UnkActor;

void EnWf_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnWf* this = (EnWf*)thisx;
    UnkActor* temp_v1;

    Collider_DestroyJntSph(globalCtx, &this->unk304);
    Collider_DestroyCylinder(globalCtx, &this->unk424);
    Collider_DestroyCylinder(globalCtx, &this->unk470);
    if ((this->actor.params != 0) && (this->unk2FC != 0xFF)) {
        func_800F5B58();
    }
    if ((this->actor.parent != NULL)) {
        temp_v1 = this->actor.parent;
        if ((temp_v1->actor.update != NULL)) {

            if (temp_v1->unk152 > 0) {
                temp_v1->unk152 -= 1;
            }
            osSyncPrintf("\n\n");
            osSyncPrintf("\x1b[32m☆☆☆☆☆ 同時発生数 ☆☆☆☆☆%d\n\x1b[m", temp_v1->unk152);
            osSyncPrintf("\n\n");
        }
    }
}

s32 func_80B33FB0(GlobalContext* arg0, EnWf* this, s16 arg2) {
    Player* temp_t1;
    s32 temo;
    s16 var_t0;
    s16 var_v1;
    Actor* temp_v0_2;
    s16 temp_v1_3;

    temp_t1 = arg0->actorCtx.actorLists[2].head;

    var_t0 = this->actor.wallYaw - this->actor.shape.rot.y;
    if (var_t0 < 0) {
        var_t0 *= -1;
    }
    var_v1 = this->actor.yawTowardsPlayer - this->actor.shape.rot.y;
    if (var_v1 < 0) {
        var_v1 *= -1;
    }

    if (func_800354B4(arg0, &this->actor, 100.0f, 0x2710, 0x2EE0, this->actor.shape.rot.y) != 0) {
        if (temp_t1->swordAnimation == 0x11) {
            func_80B36288(this);
            return 1;
        }
        if (arg0->gameplayFrames & 1) {
            func_80B36288(this);
            return 1;
        }
    }

    if (func_800354B4(arg0, &this->actor, 100.0f, 0x5DC0, 0x2AA8, (s16)((s32)this->actor.shape.rot.y)) != 0) {
        this->actor.shape.rot.y = this->actor.world.rot.y = this->actor.yawTowardsPlayer;
        if (this->actor.bgCheckFlags & 8) {
            if ((ABS(var_t0) < 0x2EE0) && (this->actor.xzDistToPlayer < 120.0f)) {
                func_80B360E8(this);
                return 1;
            }
        }
        if (temp_t1->swordAnimation == 0x11) {
            func_80B36288(this);
            return 1;
        }
        if ((this->actor.xzDistToPlayer < 80.0f) && (arg0->gameplayFrames & 1)) {
            func_80B36288(this);
            return 1;
        }
        func_80B35B94(this);
        return 1;
    }

    temp_v0_2 = Actor_FindNearby(arg0, &this->actor, -1, 3U, 80.0f);
    if (temp_v0_2 != NULL) {
        this->actor.shape.rot.y = this->actor.world.rot.y = this->actor.yawTowardsPlayer;
        if (((this->actor.bgCheckFlags & 8) && (var_t0 < 0x2EE0)) || (temp_v0_2->id == 0xDA)) {
            if (temp_v0_2->id == 0xDA) {
                if ((Actor_WorldDistXYZToActor(&this->actor, temp_v0_2) < 80.0f) &&
                    (((s16)((this->actor.shape.rot.y - temp_v0_2->world.rot.y) + 0x8000)) < 0x3E80)) {
                    func_80B360E8(this);
                    return 1;
                }
            }
            func_80B365A8(this, arg0);
            return 1;
        }
        func_80B35B94(this);
        return 1;
    }

    if (arg2 != 0) {
        if (var_v1 >= 0x1B58) {
            func_80B365A8(this, arg0);
            return 1;
        }
        temp_v1_3 = temp_t1->actor.shape.rot.y - this->actor.shape.rot.y;
        if (this->actor.xzDistToPlayer <= 80.0f) {
            if (Actor_OtherIsTargeted(arg0, &this->actor) == 0) {

                if ((arg0->gameplayFrames & 7) || (ABS(temp_v1_3) < 0x38E0)) {
                    func_80B35540(this);
                    return 1;
                }
            }
        }
        func_80B34F28(this);

        return 1;
    }
    return 0;
}

void func_80B34380(EnWf* this) {
    Animation_Change(&this->unk188, &D_6005430, 0.5f, 0.0f, 7.0f, 3U, 0.0f);
    this->actor.world.pos.y = this->actor.home.pos.y - 5.0f;
    this->unk2E8 = 0x14;
    this->unk300 = 0;
    this->unk2D4 = 0;
    this->actor.flags &= ~1;
    this->actor.scale.y = 0.0f;
    this->actor.gravity = 0.0f;
    func_80B33CB0(this, func_80B34428);
}

void func_80B34428(EnWf* this, GlobalContext* globalCtx) {

    if (this->unk2E8 >= 6) {
        this->actor.world.pos.y = this->actor.home.pos.y - 5.0f;
        if (this->actor.xzDistToPlayer < 240.0f) {
            this->unk2E8 = 5;
            this->actor.flags |= 1;
            if ((this->actor.params != 0) && (this->unk2FC != 0xFF)) {
                func_800F5ACC(0x38U);
            }
        }
    } else if (this->unk2E8 != 0) {
        this->actor.scale.y += this->actor.scale.x * 0.2f;
        this->actor.world.pos.y += 0.5f;
        Math_SmoothStepToF(&this->actor.shape.shadowScale, 70.0f, 1.0f, 14.0f, 0.0f);
        this->unk2E8 -= 1;
        if (this->unk2E8 == 0) {
            Audio_PlayActorSound2(&this->actor, 0x383CU);
        }
    } else if (SkelAnime_Update(&this->unk188) != 0) {
        this->actor.scale.y = this->actor.scale.x;
        this->actor.gravity = -2.0f;
        func_80B3455C(this);
    }
}

void func_80B3455C(EnWf* this) {
    Animation_MorphToLoop(&this->unk188, &D_600A4AC, -4.0f);
    this->unk2D4 = 6;
    this->unk2E8 = (s32)((Rand_ZeroOne() * 10.0f) + 2.0f);
    this->actor.speedXZ = 0.0f;
    this->actor.world.rot.y = this->actor.shape.rot.y;
    func_80B33CB0(this, func_80B345E4);
}

#ifdef NON_MATCHING
void func_80B345E4(EnWf* this, GlobalContext* globalCtx) {
    Player* sp2C;
    s16 sp26;
    s16 temp_a0;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v1;
    s16 var_v0;
    s16 var_v1;
    s16 var_v1_2;
    s32 temp_t0;

    sp2C = globalCtx->actorCtx.actorLists[2].head;
    SkelAnime_Update(&this->unk188);
    temp_a0 = this->unk2E2;
    if (temp_a0 != 0) {
        temp_v1 = (this->actor.yawTowardsPlayer - this->actor.shape.rot.y) - this->unk4D6;
        var_v0 = -temp_v1;
        if (temp_v1 >= 0) {
            var_v0 = temp_v1;
        }
        if (var_v0 >= 0x2001) {
            this->unk2E2 = temp_a0 - 1;
            return;
        }
        this->unk2E2 = 0;
    }
    var_v1 = this->actor.yawTowardsPlayer - this->actor.shape.rot.y;
    if (var_v1 < 0) {
        var_v1 *= -1;
    }
    sp26 = var_v1;
    if (func_80B37830(globalCtx, this) == 0) {
        temp_v0 = this->unk2E0;
        if (temp_v0 != 0) {
            this->unk2E0 = temp_v0 - 1;
            if (var_v1 < 0x1FFE) {
                this->unk2E0 = 0;
                goto block_13;
            }
        } else if (func_80B33FB0(globalCtx, this, 0) == 0) {
        block_13:
            var_v1_2 = sp2C->actor.shape.rot.y - this->actor.shape.rot.y;
            if (var_v1_2 < 0) {
                var_v1_2 *= -1;
            }
            if ((this->actor.xzDistToPlayer < 80.0f) && (sp2C->swordState != 0) && (var_v1_2 >= 0x1F40)) {
                temp_v0_2 = this->actor.yawTowardsPlayer;
                this->actor.world.rot.y = temp_v0_2;
                this->actor.shape.rot.y = temp_v0_2;
                func_80B34F28(this);
                return;
            }
            temp_t0 = this->unk2E8 - 1;
            this->unk2E8 = temp_t0;
            if (temp_t0 == 0) {
                if (Actor_IsFacingPlayer(&this->actor, 0x1555) != 0) {
                    if (Rand_ZeroOne() > 0.3f) {
                        func_80B347FC(this, globalCtx);
                    } else {
                        func_80B34F28(this);
                    }
                } else {
                    func_80B34CFC(this);
                }
                if (!(globalCtx->gameplayFrames & 0x5F)) {
                    Audio_PlayActorSound2(&this->actor, 0x383EU);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B345E4.s")
#endif

void func_80B347FC(EnWf* this, GlobalContext* globalCtx) {
    Animation_Change(&this->unk188, &D_60057A0, 1.0f, 0.0f, (f32)Animation_GetLastFrame(&D_60057A0), 1U, -4.0f);
    this->unk2D4 = 9;
    func_80B33CB0(this, func_80B3487C);
}

#ifdef NON_MATCHING
void func_80B3487C(EnWf* this, GlobalContext* globalCtx) {
    s32 sp5C;
    s32 sp58;
    f32 sp50;
    Player* sp48;
    s16 sp42;
    f32 sp3C;
    f32 temp_fv0;
    f32 temp_fv0_2;
    s16 temp_v0;
    s16 temp_v1;
    s16 var_v0;
    s16 var_v0_2;

    sp50 = 0.0f;
    sp48 = globalCtx->actorCtx.actorLists[2].head;
    if (func_80B37830(globalCtx, this) == 0) {
        Math_SmoothStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 1, 0x2EE, 0);
        this->actor.world.rot.y = this->actor.shape.rot.y;
        if (Actor_OtherIsTargeted(globalCtx, &this->actor) != 0) {
            sp50 = 150.0f;
        }
        temp_fv0 = this->actor.xzDistToPlayer;
        if (temp_fv0 <= (50.0f + sp50)) {
            Math_SmoothStepToF(&this->actor.speedXZ, -8.0f, 1.0f, 1.5f, 0.0f);
        } else if ((65.0f + sp50) < temp_fv0) {
            Math_SmoothStepToF(&this->actor.speedXZ, 8.0f, 1.0f, 1.5f, 0.0f);
        } else {
            Math_SmoothStepToF(&this->actor.speedXZ, 0.0f, 1.0f, 6.65f, 0.0f);
        }
        this->unk188.playSpeed = this->actor.speedXZ * 0.175f;
        var_v0 = sp48->actor.shape.rot.y - this->actor.shape.rot.y;
        if (var_v0 < 0) {
            var_v0 *= -1;
        }
        if ((this->actor.xzDistToPlayer < (150.0f + sp50)) && (sp48->swordState != 0) && (var_v0 >= 0x1F40)) {
            temp_v0 = this->actor.yawTowardsPlayer;
            this->actor.world.rot.y = temp_v0;
            this->actor.shape.rot.y = temp_v0;
            if (Rand_ZeroOne() > 0.7f) {
                func_80B34F28(this);
                return;
            }
        }
        sp5C = (s32)this->unk188.curFrame;
        SkelAnime_Update(&this->unk188);
        temp_fv0_2 = this->unk188.playSpeed;
        if (temp_fv0_2 >= 0.0f) {
            sp3C = temp_fv0_2;
        } else {
            sp3C = -temp_fv0_2;
        }
        sp58 = (s32)(this->unk188.curFrame - sp3C);
        if (temp_fv0_2 >= 0.0f) {
            sp3C = temp_fv0_2;
        } else {
            sp3C = -temp_fv0_2;
        }
        if (Actor_IsFacingPlayer(&this->actor, 0x11C7) == 0) {
            if (Rand_ZeroOne() > 0.5f) {
                func_80B34F28(this);
            } else {
                func_80B3455C(this);
            }
        } else if (this->actor.xzDistToPlayer < (90.0f + sp50)) {
            temp_v1 = sp48->actor.shape.rot.y - this->actor.shape.rot.y;
            sp42 = temp_v1;
            if (Actor_OtherIsTargeted(globalCtx, &this->actor) == 0) {
                sp42 = temp_v1;
                if (!(Rand_ZeroOne() > 0.03f)) {
                    if (this->actor.xzDistToPlayer <= 80.0f) {
                        var_v0_2 = -temp_v1;
                        if (temp_v1 >= 0) {
                            var_v0_2 = temp_v1;
                        }
                        if (var_v0_2 < 0x38E0) {
                            goto block_32;
                        }
                        goto block_33;
                    }
                    goto block_33;
                }
            block_32:
                func_80B35540(this);
            } else {
            block_33:
                if ((Actor_OtherIsTargeted(globalCtx, &this->actor) != 0) && (Rand_ZeroOne() > 0.5f)) {
                    func_80B35B94(this);
                } else {
                    func_80B34F28(this);
                }
            }
        }
        if (func_80B33FB0(globalCtx, this, 0) == 0) {
            if (!(globalCtx->gameplayFrames & 0x5F)) {
                Audio_PlayActorSound2(&this->actor, 0x383EU);
            }
            if ((sp5C != (s32)this->unk188.curFrame) && (sp58 <= 0) && (((s32)sp3C + sp5C) > 0)) {
                Audio_PlayActorSound2(&this->actor, 0x385AU);
                Actor_SpawnFloorDustRing(globalCtx, &this->actor, &this->actor.world.pos, 20.0f, 3, 3.0f, 0x32, 0x32,
                                         1U);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B3487C.s")
#endif

void func_80B34CFC(EnWf* this) {
    Animation_MorphToLoop(&this->unk188, &D_60098C8, -4.0f);
    this->unk2D4 = 0xA;
    func_80B33CB0(this, func_80B34D48);
}

void func_80B34D48(EnWf* this, GlobalContext* globalCtx) {
    f32 var_fa0;
    f32 var_fv1;
    s16 temp_a0;
    s16 temp_v0;
    s16 temp_v1;

    if ((func_80B37830(globalCtx, this) == 0) && (func_80B33FB0(globalCtx, this, 0) == 0)) {
        temp_a0 = this->actor.shape.rot.y;
        temp_v0 = this->actor.yawTowardsPlayer - temp_a0;
        if (temp_v0 > 0) {
            temp_v1 = (s32)(((f32)temp_v0 * 0.25f) + 2000.0f);
        } else {
            temp_v1 = (s32)(((f32)temp_v0 * 0.25f) - 2000.0f);
        }
        this->actor.shape.rot.y = temp_a0 + temp_v1;
        this->actor.world.rot.y = this->actor.shape.rot.y;
        if (temp_v0 > 0) {
            var_fa0 = 1.0f;
            var_fv1 = (f32)temp_v1 * 0.5f;
            if (var_fv1 > 1.0f) {
                goto block_9;
            }
        } else {
            var_fa0 = -1.0f;
            var_fv1 = (f32)temp_v1 * 0.5f;
            if (var_fv1 < -1.0f) {
            block_9:
                var_fv1 = var_fa0;
            }
        }
        this->unk188.playSpeed = -var_fv1;
        SkelAnime_Update(&this->unk188);
        if (Actor_IsFacingPlayer(&this->actor, 0x1555) != 0) {
            if (Rand_ZeroOne() > 0.8f) {
                func_80B34F28(this);
            } else {
                func_80B347FC(this, globalCtx);
            }
        }
        if (!(globalCtx->gameplayFrames & 0x5F)) {
            Audio_PlayActorSound2(&this->actor, 0x383EU);
        }
    }
}

void func_80B34F28(EnWf* this) {
    Animation_Change(&this->unk188, &D_60057A0, 1.0f, 0.0f, (f32)Animation_GetLastFrame(&D_60057A0), 1U, -4.0f);
    if (Rand_ZeroOne() > 0.5f) {
        this->unk2FE = 0x3E80;
    } else {
        this->unk2FE = -0x3E80;
    }
    this->actor.speedXZ = 6.0f;
    this->unk188.playSpeed = this->actor.speedXZ * 0.175f;
    this->actor.world.rot.y = this->actor.shape.rot.y;
    this->unk2E8 = (s32)((Rand_ZeroOne() * 30.0f) + 30.0f);
    this->unk2D4 = 0xB;
    this->unk2EC = 0.0f;
    func_80B33CB0(this, func_80B35024);
}

#ifdef NON_MATCHING
void func_80B35024(EnWf* this, GlobalContext* globalCtx) {
    s16 sp56;
    f32 sp4C;
    s32 sp48;
    Actor* sp3C;
    f32 temp_fa0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 var_fa1;
    f32 var_fv1;
    f32 var_fv1_2;
    f32 var_fv1_3;
    f32 var_fv1_4;
    s16 temp_a3;
    s16 var_v0_2;
    s16 var_v1;
    s32 temp_ft2;
    s32 temp_t9;
    s32 var_v0;

    sp4C = 0.0f;
    sp3C = globalCtx->actorCtx.actorLists[2].head;
    Math_SmoothStepToS(&this->actor.shape.rot.y, (s16)(this->actor.yawTowardsPlayer + this->unk2FE), 1, 0xFA0, 1);
    if ((func_80B37830(globalCtx, this) == 0) && (func_80B33FB0(globalCtx, this, 0) == 0)) {
        temp_a3 = this->actor.shape.rot.y;
        this->actor.world.rot.y = temp_a3;
        sp56 = sp3C->shape.rot.y + this->unk2FE + 0x8000;
        var_v0 = this->actor.bgCheckFlags & 8;
        if (var_v0 == 0) {
            if (Actor_TestFloorInDirection(&this->actor, globalCtx, this->actor.speedXZ, temp_a3) == 0) {
                var_v0 = this->actor.bgCheckFlags & 8;
                goto block_5;
            }
        } else {
        block_5:
            if (var_v0 != 0) {
                var_v0_2 = (this->actor.wallYaw - this->actor.yawTowardsPlayer) - this->unk2FE;
            } else {
                var_v0_2 = 0;
            }
            var_v1 = -var_v0_2;
            if (var_v0_2 >= 0) {
                var_v1 = var_v0_2;
            }
            if (var_v1 >= 0x2EE1) {
                this->unk2FE = -this->unk2FE;
            }
        }
        if (Actor_OtherIsTargeted(globalCtx, &this->actor) != 0) {
            sp4C = 150.0f;
        }
        temp_fv0 = this->actor.xzDistToPlayer;
        if (temp_fv0 <= (60.0f + sp4C)) {
            Math_SmoothStepToF(&this->unk2EC, -4.0f, 1.0f, 1.5f, 0.0f);
        } else if ((80.0f + sp4C) < temp_fv0) {
            Math_SmoothStepToF(&this->unk2EC, 4.0f, 1.0f, 1.5f, 0.0f);
        } else {
            Math_SmoothStepToF(&this->unk2EC, 0.0f, 1.0f, 6.65f, 0.0f);
        }
        if (this->unk2EC != 0.0f) {
            this->actor.world.pos.x += Math_SinS(this->actor.shape.rot.y) * this->unk2EC;
            this->actor.world.pos.z += Math_CosS(this->actor.shape.rot.y) * this->unk2EC;
        }
        if (this->unk2EC >= 0.0f) {
            var_fa1 = this->unk2EC;
        } else {
            var_fa1 = -this->unk2EC;
        }
        temp_fv0_2 = this->actor.speedXZ;
        if (temp_fv0_2 >= 0.0f) {
            var_fv1 = temp_fv0_2;
        } else {
            var_fv1 = -temp_fv0_2;
        }
        if (var_fa1 < var_fv1) {
            this->unk188.playSpeed = temp_fv0_2 * 0.175f;
        } else {
            this->unk188.playSpeed = this->unk2EC * 0.175f;
        }
        var_fv1_2 = -3.0f;
        temp_fv0_3 = this->unk188.playSpeed;
        if (temp_fv0_3 < -3.0f) {

        } else if (temp_fv0_3 > 3.0f) {
            var_fv1_2 = 3.0f;
        } else {
            var_fv1_2 = temp_fv0_3;
        }
        this->unk188.playSpeed = var_fv1_2;
        temp_ft2 = (s32)this->unk188.curFrame;
        sp48 = temp_ft2;
        SkelAnime_Update(&this->unk188);
        temp_fv0_4 = this->unk188.playSpeed;
        if (temp_fv0_4 >= 0.0f) {
            var_fv1_3 = temp_fv0_4;
        } else {
            var_fv1_3 = -temp_fv0_4;
        }
        temp_fa0 = this->unk188.curFrame;
        if (temp_fv0_4 >= 0.0f) {
            var_fv1_4 = temp_fv0_4;
        } else {
            var_fv1_4 = -temp_fv0_4;
        }
        if ((temp_ft2 != (s32)temp_fa0) && ((s32)(temp_fa0 - var_fv1_3) <= 0) && (((s32)var_fv1_4 + temp_ft2) > 0)) {
            Audio_PlayActorSound2(&this->actor, 0x385AU);
            Actor_SpawnFloorDustRing(globalCtx, &this->actor, &this->actor.world.pos, 20.0f, 3, 3.0f, 0x32, 0x32, 1U);
        }
        if (!(globalCtx->gameplayFrames & 0x5F)) {
            Audio_PlayActorSound2(&this->actor, 0x383EU);
        }
        if ((Math_CosS((s16)(sp56 - this->actor.shape.rot.y)) < -0.85f) &&
            (Actor_OtherIsTargeted(globalCtx, &this->actor) == 0) && (this->actor.xzDistToPlayer <= 80.0f)) {
            func_80B35540(this);
            return;
        }
        temp_t9 = this->unk2E8 - 1;
        this->unk2E8 = temp_t9;
        if (temp_t9 == 0) {
            if ((Actor_OtherIsTargeted(globalCtx, &this->actor) != 0) && (Rand_ZeroOne() > 0.5f)) {
                func_80B35B94(this);
                return;
            }
            func_80B3455C(this);
            this->unk2E8 = (s32)((Rand_ZeroOne() * 3.0f) + 1.0f);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B35024.s")
#endif

void func_80B35540(EnWf* this) {
    Animation_PlayOnce(&this->unk188, &D_6004638);
    this->unk304.base.atFlags &= ~4;
    this->actor.shape.rot.y = this->actor.yawTowardsPlayer;
    this->unk2D4 = 8;
    this->unk2FA = 0;
    this->unk2E8 = 7;
    this->unk188.endFrame = 20.0f;
    this->actor.speedXZ = 0.0f;
    func_80B33CB0(this, func_80B355BC);
}

#ifdef NON_MATCHING
void func_80B355BC(EnWf* this, GlobalContext* globalCtx) {
    s16 sp42;
    s16 sp40;
    s32 sp3C;
    s16 temp_v0;
    s32 temp_v0_2;
    s32 var_a2;

    temp_v0 = this->actor.shape.rot.y;
    sp42 = globalCtx->actorCtx.actorLists[2].head->shape.rot.y - temp_v0;
    sp40 = this->actor.yawTowardsPlayer - temp_v0;
    var_a2 = (s32)this->unk188.curFrame;
    if (sp42 < 0) {
        sp42 = -sp42;
    }
    if (sp40 < 0) {
        sp40 = -sp40;
    }
    this->actor.speedXZ = 0.0f;
    if (((var_a2 >= 9) && (var_a2 < 0xD)) || ((var_a2 >= 0x11) && (var_a2 < 0x14))) {
        if (this->unk2F8 == 0) {
            sp3C = var_a2;
            Audio_PlayActorSound2(&this->actor, 0x383FU);
        }
        this->unk2F8 = 1;
    } else {
        this->unk2F8 = 0;
    }
    if (((var_a2 == 0xF) && (sp3C = var_a2, (Actor_IsTargeted(globalCtx, &this->actor) == 0)) &&
         ((sp3C = var_a2, (Actor_IsFacingPlayer(&this->actor, 0x2000) == 0)) ||
          (this->actor.xzDistToPlayer >= 100.0f))) ||
        (sp3C = var_a2, (SkelAnime_Update(&this->unk188) != 0))) {
        if (var_a2 != 0xF) {
            temp_v0_2 = this->unk2E8;
            if (temp_v0_2 != 0) {
                this->actor.shape.rot.y += (s32)(3276.0f * (1.5f + ((f32)(temp_v0_2 - 4) * 0.4f)));
                Actor_SpawnFloorDustRing(globalCtx, &this->actor, &this->actor.world.pos, 15.0f, 1, 2.0f, 0x32, 0x32,
                                         1U);
                this->unk2E8 -= 1;
                return;
            }
        }
        sp3C = var_a2;
        if ((Actor_IsFacingPlayer(&this->actor, 0x1554) == 0) && (var_a2 != 0xF)) {
            func_80B3455C(this);
            this->unk2E8 = (s32)((Rand_ZeroOne() * 5.0f) + 5.0f);
            if (sp40 >= 0x32C9) {
                this->unk2E2 = 7;
            }
        } else {
            if ((Rand_ZeroOne() > 0.7f) || (this->actor.xzDistToPlayer >= 120.0f)) {
                func_80B3455C(this);
                this->unk2E8 = (s32)((Rand_ZeroOne() * 5.0f) + 5.0f);
                return;
            }
            this->actor.world.rot.y = this->actor.yawTowardsPlayer;
            if (Rand_ZeroOne() > 0.7f) {
                func_80B365A8(this, globalCtx);
                return;
            }
            if (sp42 < 0x2711) {
                if (sp40 >= 0x3E81) {
                    this->actor.world.rot.y = this->actor.yawTowardsPlayer;
                    func_80B34F28(this);
                    return;
                }
                func_80B33FB0(globalCtx, this, 1);
                return;
            }
            func_80B34F28(this);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B355BC.s")
#endif

#ifdef NON_MATCHING
void func_80B3590C(EnWf* this) {
    f32 temp_fv1;
    f32 var_fv0;

    temp_fv1 = this->unk188.curFrame;
    var_fv0 = 1.0f;
    if ((s32)temp_fv1 >= 0x10) {
        var_fv0 = 15.0f;
    }
    Animation_Change(&this->unk188, &D_6004638, -0.5f, temp_fv1 - 1.0f, var_fv0, 3U, 0.0f);
    this->unk2D4 = 0xC;
    this->unk2F8 = 0;
    func_80B33CB0(this, func_80B359A8);
}

void func_80B359A8(EnWf* this, GlobalContext* globalCtx) {
    s16 sp22;
    s16 sp20;
    s16 temp_v0;
    s16 var_a2;
    s16 var_a3;

    temp_v0 = this->actor.shape.rot.y;
    var_a2 = globalCtx->actorCtx.actorLists[2].head->shape.rot.y - temp_v0;
    var_a3 = this->actor.yawTowardsPlayer - temp_v0;
    if (var_a2 < 0) {
        var_a2 *= -1;
    }
    if (var_a3 < 0) {
        var_a3 *= -1;
    }
    sp22 = var_a2;
    sp20 = var_a3;
    if (SkelAnime_Update(&this->unk188) != 0) {
        sp22 = var_a2;
        if (Actor_IsFacingPlayer(&this->actor, 0x1554) == 0) {
            func_80B3455C(this);
            this->unk2E8 = (s32)((Rand_ZeroOne() * 5.0f) + 5.0f);
            if (sp20 >= 0x32C9) {
                this->unk2E2 = 0x1E;
            }
        } else {
            sp22 = var_a2;
            if ((Rand_ZeroOne() > 0.7f) || (this->actor.xzDistToPlayer >= 120.0f)) {
                func_80B3455C(this);
                this->unk2E8 = (s32)((Rand_ZeroOne() * 5.0f) + 5.0f);
                return;
            }
            this->actor.world.rot.y = this->actor.yawTowardsPlayer;
            sp22 = var_a2;
            if (Rand_ZeroOne() > 0.7f) {
                func_80B365A8(this, globalCtx);
                return;
            }
            if (var_a2 < 0x2711) {
                if (sp20 >= 0x3E81) {
                    this->actor.world.rot.y = this->actor.yawTowardsPlayer;
                    func_80B34F28(this);
                    return;
                }
                func_80B33FB0(globalCtx, this, 1);
                return;
            }
            func_80B34F28(this);
        }
    }
}

void func_80B35B94(EnWf* this) {
    s16 temp_v0;

    Animation_MorphToPlayOnce(&this->unk188, &D_6004AD0, -3.0f);
    temp_v0 = this->actor.yawTowardsPlayer;
    this->unk2E8 = 0;
    this->unk300 = 1;
    this->unk2D4 = 5;
    this->actor.speedXZ = -6.0f;
    this->actor.world.rot.y = temp_v0;
    this->actor.shape.rot.y = temp_v0;
    Audio_PlayActorSound2(&this->actor, 0x386CU);
    func_80B33CB0(this, func_80B35C10);
}

void func_80B35C10(EnWf* this, GlobalContext* globalCtx) {
    f32 temp_fv0;

    if (SkelAnime_Update(&this->unk188) != 0) {
        if ((Actor_OtherIsTargeted(globalCtx, &this->actor) == 0) &&
            (temp_fv0 = this->actor.xzDistToPlayer, (temp_fv0 < 170.0f)) && (temp_fv0 > 140.0f) &&
            (Rand_ZeroOne() < 0.2f)) {
            func_80B347FC(this, globalCtx);
        } else if (globalCtx->gameplayFrames & 1) {
            func_80B365A8(this, globalCtx);
        } else {
            func_80B3455C(this);
        }
    }
    if (!(globalCtx->state.frames & 0x5F)) {
        Audio_PlayActorSound2(&this->actor, 0x383EU);
    }
}

void func_80B35D18(EnWf* this) {
    if (this->actor.bgCheckFlags & 1) {
        this->actor.speedXZ = 0.0f;
    }
    Audio_PlayActorSound2(&this->actor, 0x389EU);
    Animation_PlayOnceSetSpeed(&this->unk188, &D_6009B20, 0.0f);
    this->unk2D4 = 0xF;
    func_80B33CB0(this, func_80B35D90);
}

void func_80B35D90(EnWf* this, GlobalContext* globalCtx) {
    f32 temp_fv0;

    if (this->actor.bgCheckFlags & 2) {
        this->actor.speedXZ = 0.0f;
    }
    if (this->actor.bgCheckFlags & 1) {
        temp_fv0 = this->actor.speedXZ;
        if (temp_fv0 < 0.0f) {
            this->actor.speedXZ = temp_fv0 + 0.05f;
        }
        this->unk300 = 0;
    }
    if ((this->actor.colorFilterTimer == 0) && (this->actor.bgCheckFlags & 1)) {
        if (this->actor.colChkInfo.health == 0) {
            func_80B36C8C(this);
            return;
        }
        func_80B33FB0(globalCtx, this, 1);
    }
}

void func_80B35E4C(EnWf* this) {
    Animation_MorphToPlayOnce(&this->unk188, &D_6009B20, -4.0f);
    if (this->actor.bgCheckFlags & 1) {
        this->unk300 = 0;
        this->actor.speedXZ = -4.0f;
    } else {
        this->unk300 = 1;
    }
    this->unk2E2 = 0;
    this->actor.world.rot.y = this->actor.yawTowardsPlayer;
    Audio_PlayActorSound2(&this->actor, 0x3843U);
    this->unk2D4 = 3;
    func_80B33CB0(this, func_80B35EE4);
}

void func_80B35EE4(EnWf* this, GlobalContext* globalCtx) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    s16 var_v0;
    s16 var_v1;
    u16 temp_v0;

    if (this->actor.bgCheckFlags & 2) {
        this->actor.speedXZ = 0.0f;
    }
    if (this->actor.bgCheckFlags & 1) {
        temp_fv0 = this->actor.speedXZ;
        if (temp_fv0 < 0.0f) {
            this->actor.speedXZ = temp_fv0 + 0.05f;
        }
        this->unk300 = 0;
    }
    Math_SmoothStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 1, 0x1194, 0);
    if ((func_80B33FB0(globalCtx, this, 0) == 0) && (SkelAnime_Update(&this->unk188) != 0) &&
        (temp_v0 = this->actor.bgCheckFlags, ((temp_v0 & 1) != 0))) {
        var_v1 = this->actor.wallYaw - this->actor.shape.rot.y;
        if (var_v1 < 0) {
            var_v1 *= -1;
        }
        if (temp_v0 & 8) {
            var_v0 = -var_v1;
            if (var_v1 >= 0) {
                var_v0 = var_v1;
            }
            if ((var_v0 < 0x2EE0) && (this->actor.xzDistToPlayer < 120.0f)) {
                func_80B360E8(this);
                return;
            }
            goto block_17;
        }
    block_17:
        if (func_80B37830(globalCtx, this) == 0) {
            if ((this->actor.xzDistToPlayer <= 80.0f) && (Actor_OtherIsTargeted(globalCtx, &this->actor) == 0) &&
                (globalCtx->gameplayFrames & 7)) {
                func_80B35540(this);
                return;
            }
            if (Rand_ZeroOne() > 0.5f) {
                func_80B3455C(this);
                temp_fv0_2 = Rand_ZeroOne();
                this->unk2E2 = 0x1E;
                this->unk2E8 = (s32)((temp_fv0_2 * 5.0f) + 5.0f);
                return;
            }
            func_80B35B94(this);
        }
    }
}

void func_80B360E8(EnWf* this) {
    Animation_Change(&this->unk188, &D_6004AD0, -1.0f, (f32)Animation_GetLastFrame(&D_6004AD0), 0.0f, 2U, -3.0f);
    this->unk2E8 = 0;
    this->unk300 = 0;
    this->unk2D4 = 4;
    this->actor.speedXZ = 6.5f;
    this->actor.velocity.y = 15.0f;
    Audio_PlayActorSound2(&this->actor, 0x386CU);
    this->actor.world.rot.y = this->actor.shape.rot.y;
    func_80B33CB0(this, func_80B361A0);
}

void func_80B361A0(EnWf* this, GlobalContext* globalCtx) {
    s16 temp_v0;

    Math_SmoothStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 1, 0xFA0, 1);
    if (this->actor.velocity.y >= 5.0f) {
        func_800355B8(globalCtx, &this->unk4C8);
        func_800355B8(globalCtx, &this->unk4BC);
    }
    if ((SkelAnime_Update(&this->unk188) != 0) && (this->actor.bgCheckFlags & 3)) {
        temp_v0 = this->actor.yawTowardsPlayer;
        this->actor.shape.rot.x = 0;
        this->actor.shape.rot.y = temp_v0;
        this->actor.world.rot.y = temp_v0;
        this->actor.velocity.y = 0.0f;
        this->actor.speedXZ = 0.0f;
        this->actor.world.pos.y = this->actor.floorHeight;
        if (Actor_OtherIsTargeted(globalCtx, &this->actor) == 0) {
            func_80B35540(this);
            return;
        }
        func_80B3455C(this);
    }
}

void func_80B36288(EnWf* this) {
    f32 temp_fv1;

    temp_fv1 = (f32)Animation_GetLastFrame(&D_6004CA4);
    if (this->unk2F8 != 0) {
        this->unk2F8 = -1;
    }
    this->actor.speedXZ = 0.0f;
    this->unk2D4 = 7;
    this->unk2E8 = 0xA;
    Animation_Change(&this->unk188, &D_6004CA4, 0.0f, 0.0f, temp_fv1, 3U, -4.0f);
    func_80B33CB0(this, func_80B36328);
}

void func_80B36328(EnWf* this, GlobalContext* globalCtx) {
    Player* sp34;
    s16 sp2C;
    Player* temp_t1;
    f32 temp_fv0;
    f32 var_fv1;
    s16 temp_a2;
    s16 temp_t0;
    s16 temp_v0_2;
    s16 var_v1;
    s16 var_v1_2;
    s32 temp_v0;

    temp_v0 = this->unk2E8;
    temp_t1 = globalCtx->actorCtx.actorLists[2].head;
    if (temp_v0 != 0) {
        this->unk2E8 = temp_v0 - 1;
    } else {
        this->unk188.playSpeed = 1.0f;
    }
    sp34 = temp_t1;
    if (SkelAnime_Update(&this->unk188) != 0) {
        temp_t0 = this->actor.shape.rot.y;
        temp_v0_2 = this->actor.yawTowardsPlayer - temp_t0;
        var_v1 = -temp_v0_2;
        if (temp_v0_2 >= 0) {
            var_v1 = temp_v0_2;
        }
        if ((var_v1 < 0x4001) && (this->actor.xzDistToPlayer < 60.0f)) {
            temp_fv0 = this->actor.yDistToPlayer;
            if (temp_fv0 >= 0.0f) {
                var_fv1 = temp_fv0;
            } else {
                var_fv1 = -temp_fv0;
            }
            if (var_fv1 < 50.0f) {
                sp34 = temp_t1;
                if (func_800354B4(globalCtx, &this->actor, 100.0f, 0x2710, 0x4000, (s16)(s32)temp_t0) != 0) {
                    if (temp_t1->swordAnimation == 0x11) {
                        func_80B36288(this);
                        return;
                    }
                    if (globalCtx->gameplayFrames & 1) {
                        func_80B36288(this);
                        return;
                    }
                    func_80B35B94(this);
                    return;
                }
                temp_a2 = temp_t1->actor.shape.rot.y - this->actor.shape.rot.y;
                sp2C = temp_a2;
                if (Actor_OtherIsTargeted(globalCtx, &this->actor) == 0) {
                    if (!(globalCtx->gameplayFrames & 1)) {
                        var_v1_2 = -temp_a2;
                        if (temp_a2 >= 0) {
                            var_v1_2 = temp_a2;
                        }
                        if (var_v1_2 < 0x38E0) {
                            goto block_23;
                        }
                        goto block_24;
                    }
                block_23:
                    func_80B35540(this);
                    return;
                }
            block_24:
                func_80B34F28(this);
                return;
            }
            goto block_25;
        }
    block_25:
        func_80B34F28(this);
        return;
    }
    if ((this->unk2E8 == 0) && (sp34 = temp_t1, (func_800354B4(globalCtx, &this->actor, 100.0f, 0x2710, 0x4000,
                                                               (s16)(s32)this->actor.shape.rot.y) != 0))) {
        if (temp_t1->swordAnimation == 0x11) {
            func_80B36288(this);
            return;
        }
        if (globalCtx->gameplayFrames & 1) {
            func_80B36288(this);
            return;
        }
        func_80B35B94(this);
    }
}

void func_80B365A8(EnWf* this, GlobalContext* globalCtx) {
    s16 sp36;
    f32 temp_ft4;
    s16 temp_v1;

    Animation_Change(&this->unk188, &D_60057A0, 1.0f, 0.0f, (f32)Animation_GetLastFrame(&D_60057A0), 1U, -4.0f);
    temp_v1 = globalCtx->actorCtx.actorLists[2].head->shape.rot.y + this->unk2FE;
    sp36 = temp_v1;
    if (Math_SinS((s16)(temp_v1 - this->actor.yawTowardsPlayer)) > 0.0f) {
        this->unk2FE = 0x3E80;
    } else if (Math_SinS((s16)(temp_v1 - this->actor.yawTowardsPlayer)) < 0.0f) {
        this->unk2FE = -0x3E80;
    } else if (Rand_ZeroOne() > 0.5f) {
        this->unk2FE = 0x3E80;
    } else {
        this->unk2FE = -0x3E80;
    }
    this->actor.speedXZ = 6.0f;
    this->actor.world.rot.y = this->actor.shape.rot.y;
    this->unk2EC = 0.0f;
    this->unk188.playSpeed = 6.0f * 0.175f;
    temp_ft4 = Rand_ZeroOne() * 10.0f;
    this->unk2D4 = 0xE;
    this->unk2E8 = (s32)(temp_ft4 + 5.0f);
    func_80B33CB0(this, func_80B36740);
}

void func_80B36740(EnWf* this, GlobalContext* globalCtx) {
    Actor* sp68;
    s32 sp64;
    s32 sp60;
    f32 sp58;
    s16 sp4E;
    f32 sp44;
    void* sp3C;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 var_fa0;
    f32 var_fa0_2;
    f32 var_fa0_3;
    f32 var_fa0_4;
    f32 var_fa0_5;
    f32 var_fa1;
    s16 temp_a2;
    s16 temp_v1;
    s16 var_v0;
    s16 var_v0_2;
    s16 var_v1_2;
    s16 var_v1_3;
    s32 temp_t3;
    s32 var_v1;

    sp68 = globalCtx->actorCtx.actorLists[2].head;
    sp58 = 0.0f;
    Math_SmoothStepToS(&this->actor.shape.rot.y, (s16)(this->actor.yawTowardsPlayer + this->unk2FE), 1, 0xBB8, 1);
    var_v1 = this->actor.bgCheckFlags & 8;
    if (var_v1 == 0) {
        if (Actor_TestFloorInDirection(&this->actor, globalCtx, this->actor.speedXZ, this->actor.shape.rot.y) == 0) {
            var_v1 = this->actor.bgCheckFlags & 8;
            goto block_3;
        }
    } else {
    block_3:
        var_v0 = 0;
        if (var_v1 != 0) {
            var_v0 = (this->actor.wallYaw - this->actor.yawTowardsPlayer) - this->unk2FE;
        }
        var_v1_2 = -var_v0;
        if (var_v0 >= 0) {
            var_v1_2 = var_v0;
        }
        if (var_v1_2 >= 0x2EE1) {
            this->unk2FE = -this->unk2FE;
        }
    }
    this->actor.world.rot.y = this->actor.shape.rot.y;
    if (Actor_OtherIsTargeted(globalCtx, &this->actor) != 0) {
        sp58 = 150.0f;
    }
    temp_fv0 = this->actor.xzDistToPlayer;
    if (temp_fv0 <= (60.0f + sp58)) {
        Math_SmoothStepToF(&this->unk2EC, -4.0f, 1.0f, 1.5f, 0.0f);
    } else if ((80.0f + sp58) < temp_fv0) {
        Math_SmoothStepToF(&this->unk2EC, 4.0f, 1.0f, 1.5f, 0.0f);
    } else {
        Math_SmoothStepToF(&this->unk2EC, 0.0f, 1.0f, 6.65f, 0.0f);
    }
    if (this->unk2EC != 0.0f) {
        this->actor.world.pos.x += Math_SinS(this->actor.shape.rot.y) * this->unk2EC;
        this->actor.world.pos.z += Math_CosS(this->actor.shape.rot.y) * this->unk2EC;
    }
    if (this->unk2EC >= 0.0f) {
        var_fa1 = this->unk2EC;
    } else {
        var_fa1 = -this->unk2EC;
    }
    temp_fv0_2 = this->actor.speedXZ;
    if (temp_fv0_2 >= 0.0f) {
        var_fa0 = temp_fv0_2;
    } else {
        var_fa0 = -temp_fv0_2;
    }
    if (var_fa1 < var_fa0) {
        this->unk188.playSpeed = temp_fv0_2 * 0.175f;
    } else {
        this->unk188.playSpeed = this->unk2EC * 0.175f;
    }
    temp_fv0_3 = this->unk188.playSpeed;
    if (temp_fv0_3 < -3.0f) {
        this->unk188.playSpeed = -3.0f;
    } else {
        if (temp_fv0_3 > 3.0f) {
            var_fa0_2 = 3.0f;
        } else {
            var_fa0_2 = temp_fv0_3;
        }
        this->unk188.playSpeed = var_fa0_2;
    }
    sp64 = (s32)this->unk188.curFrame;
    SkelAnime_Update(&this->unk188);
    temp_fv0_4 = this->unk188.playSpeed;
    if (temp_fv0_4 >= 0.0f) {
        var_fa0_3 = temp_fv0_4;
    } else {
        var_fa0_3 = -temp_fv0_4;
    }
    sp60 = (s32)(this->unk188.curFrame - var_fa0_3);
    if (temp_fv0_4 >= 0.0f) {
        var_fa0_4 = temp_fv0_4;
    } else {
        var_fa0_4 = -temp_fv0_4;
    }
    sp44 = var_fa0_4;
    var_fa0_5 = var_fa0_4;
    if (func_80B33FB0(globalCtx, this, 0) == 0) {
        temp_t3 = this->unk2E8 - 1;
        this->unk2E8 = temp_t3;
        if (temp_t3 == 0) {
            temp_v1 = this->actor.yawTowardsPlayer;
            var_v0_2 = sp68->shape.rot.y - temp_v1;
            if (var_v0_2 < 0) {
                var_v0_2 *= -1;
            }
            if (var_v0_2 >= 0x3A98) {
                sp44 = var_fa0_5;
                func_80B3455C(this);
                this->unk2E8 = (s32)((Rand_ZeroOne() * 3.0f) + 1.0f);
            } else {
                temp_a2 = globalCtx->actorCtx.actorLists[2].head->shape.rot.y - temp_v1;
                this->actor.world.rot.y = this->actor.shape.rot.y;
                if ((this->actor.xzDistToPlayer <= 80.0f) &&
                    (sp4E = temp_a2, sp44 = var_fa0_5, (Actor_OtherIsTargeted(globalCtx, &this->actor) == 0))) {
                    if (globalCtx->gameplayFrames & 3) {
                        var_v1_3 = -temp_a2;
                        if (temp_a2 >= 0) {
                            var_v1_3 = temp_a2;
                        }
                        if (var_v1_3 < 0x38E0) {
                            goto block_51;
                        }
                        goto block_52;
                    }
                block_51:
                    sp44 = var_fa0_5;
                    func_80B35540(this);
                } else {
                block_52:
                    sp44 = var_fa0_5;
                    func_80B347FC(this, globalCtx);
                }
                var_fa0_5 = sp44;
            }
        }
        sp3C = globalCtx + 0x10000;
        if ((sp64 != (s32)this->unk188.curFrame) && (sp60 <= 0) && (((s32)var_fa0_5 + sp64) > 0)) {
            Audio_PlayActorSound2(&this->actor, 0x385AU);
            Actor_SpawnFloorDustRing(globalCtx, &this->actor, &this->actor.world.pos, 20.0f, 3, 3.0f, 0x32, 0x32, 1U);
        }
        if (!(/*sp3C->unk1DE4*/ globalCtx->gameplayFrames & 0x5F)) {
            Audio_PlayActorSound2(&this->actor, 0x383EU);
        }
    }
}

void func_80B36C8C(EnWf* this) {
    Animation_MorphToPlayOnce(&this->unk188, &D_6005430, -4.0f);
    this->actor.world.rot.y = this->actor.yawTowardsPlayer;
    if (this->actor.bgCheckFlags & 1) {
        this->unk300 = 0;
        this->actor.speedXZ = -6.0f;
    } else {
        this->unk300 = 1;
    }
    this->unk2D4 = 2;
    this->actor.flags &= ~1;
    this->unk2E8 = (s32)this->unk188.animLength;
    Audio_PlayActorSound2(&this->actor, 0x384BU);
    func_80B33CB0(this, func_80B36D3C);
}

void func_80B36D3C(EnWf* this, GlobalContext* globalCtx) {
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    Vec3f sp7C;
    s16 temp_a1;
    s32 temp_t2;
    s32 var_s0;

    if (this->actor.bgCheckFlags & 2) {
        this->actor.speedXZ = 0.0f;
    }
    if (this->actor.bgCheckFlags & 1) {
        Math_SmoothStepToF(&this->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
        this->unk300 = 0;
    }
    if (SkelAnime_Update(&this->unk188) != 0) {
        Item_DropCollectibleRandom(globalCtx, &this->actor, &this->actor.world.pos, 0xD0);
        temp_a1 = this->unk2FC;
        if (temp_a1 != 0xFF) {
            Flags_SetSwitch(globalCtx, (s32)temp_a1);
        }
        Actor_Kill(&this->actor);
        return;
    }
    sp7C.x = D_80B37AD0.x;
    sp7C.y = D_80B37AD0.y;
    sp7C.z = D_80B37AD0.z;
    temp_t2 = this->unk2E8 - 1;
    this->unk2E8 = temp_t2;
    var_s0 = (s32)((s32)this->unk188.animLength - temp_t2) >> 1;
    if (var_s0 >= 0) {
        do {
            sp88 = Rand_CenteredFloat(60.0f) + this->actor.world.pos.x;
            sp90 = Rand_CenteredFloat(60.0f) + this->actor.world.pos.z;
            sp8C = Rand_CenteredFloat(50.0f) + (this->actor.world.pos.y + 20.0f);
            EffectSsDeadDb_Spawn(globalCtx, (Vec3f*)&sp88, &sp7C, &sp7C, 0x64, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0xFF, 1,
                                 9, 1);
            var_s0 -= 1;
        } while (var_s0 >= 0);
    }
}

void func_80B36F40(EnWf* this, GlobalContext* globalCtx) {
    s16 temp_v0_2;
    s16 temp_v1;
    s16 var_v1;
    s32 temp_v0;

    temp_v0 = this->unk2D4;
    if (temp_v0 == 6) {
        temp_v1 = this->unk2E2;
        if (temp_v1 != 0) {
            this->unk4D6 = (s16)(s32)(Math_SinS((s16)(temp_v1 * 0x1068)) * 8920.0f);
            return;
        }
    }
    if (temp_v0 != 0xF) {
        if (temp_v0 != 8) {
            Math_SmoothStepToS(&this->unk4D6, (s16)(this->actor.yawTowardsPlayer - this->actor.shape.rot.y), 1, 0x5DC,
                               0);
            temp_v0_2 = this->unk4D6;
            if (temp_v0_2 < -0x3127) {
                this->unk4D6 = -0x3127;
                return;
            }
            var_v1 = temp_v0_2;
            if (temp_v0_2 >= 0x3128) {
                var_v1 = 0x3127;
            }
            this->unk4D6 = var_v1;
            return;
        }
        this->unk4D6 = 0;
    }
}

void func_80B37038(EnWf* this, GlobalContext* globalCtx) {
    s16 temp_v1;
    s16 var_v0;
    s32 temp_v0_2;
    u8 temp_v0;
    u8 temp_v0_3;
    u8 temp_v0_4;

    temp_v0 = this->unk304.base.acFlags;
    if (temp_v0 & 0x80) {
        this->unk304.base.acFlags = temp_v0 & 0xFF7D;
        this->unk424.base.acFlags &= 0xFFFD;
        this->unk470.base.acFlags &= 0xFFFD;
        return;
    }
    temp_v0_2 = this->unk424.base.acFlags & 2;
    if (((temp_v0_2 != 0) || (this->unk470.base.acFlags & 2)) && (this->unk2D4 >= 6)) {
        temp_v1 = this->actor.yawTowardsPlayer - this->actor.shape.rot.y;
        if ((temp_v0_2 != 0) || !(this->unk470.base.acFlags & 2)) {
            var_v0 = -temp_v1;
            if (temp_v1 >= 0) {
                var_v0 = temp_v1;
            }
            if (var_v0 >= 0x4A39) {
                goto block_10;
            }
        } else {
        block_10:
            this->actor.colChkInfo.damage *= 4;
        }
        temp_v0_3 = this->actor.colChkInfo.damageEffect;
        this->unk424.base.acFlags &= 0xFFFD;
        this->unk470.base.acFlags &= 0xFFFD;
        if (temp_v0_3 != 6) {
            this->unk2E6 = temp_v0_3;
            Actor_SetDropFlag(&this->actor, &this->unk424.info, 1);
            temp_v0_4 = this->actor.colChkInfo.damageEffect;
            this->unk2F8 = 0;
            if ((temp_v0_4 == 1) || (temp_v0_4 == 0xF)) {
                if (this->unk2D4 != 0xF) {
                    Actor_SetColorFilter(&this->actor, 0, 0x78, 0, 0x50);
                    Actor_ApplyDamage(&this->actor);
                    func_80B35D18(this);
                }
            } else {
                Actor_SetColorFilter(&this->actor, 0x4000, 0xFF, 0, 8);
                if (this->unk2E6 == 0xE) {
                    this->unk2E4 = 0x28;
                }
                if (Actor_ApplyDamage(&this->actor) == 0) {
                    func_80B36C8C(this);
                    Enemy_StartFinishingBlow(globalCtx, &this->actor);
                    return;
                }
                func_80B35E4C(this);
            }
        }
    }
}

void EnWf_Update(Actor* thisx, GlobalContext* globalCtx) {
    CollisionCheckContext* sp34;
    ColliderJntSph* sp30;
    ColliderCylinder* sp2C;
    ColliderCylinder* temp_a1_2;
    ColliderJntSph* temp_a2;
    CollisionCheckContext* temp_a1;
    u8 temp_v0;
    EnWf* this = (EnWf*)thisx;

    func_80B37038(this, globalCtx);
    if (this->actor.colChkInfo.damageEffect != 6) {
        Actor_MoveForward(&this->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &this->actor, 32.0f, 30.0f, 60.0f, 0x1D);
        this->unk2DC(this, globalCtx);
        func_80B36F40(this, globalCtx);
    }
    if (this->actor.bgCheckFlags & 3) {
        func_800359B8(&this->actor, this->actor.shape.rot.y, &this->actor.shape.rot);
    } else {
        Math_SmoothStepToS(&this->actor.shape.rot.x, 0, 1, 0x3E8, 0);
        Math_SmoothStepToS(&this->actor.shape.rot.z, 0, 1, 0x3E8, 0);
    }
    temp_a1 = &globalCtx->colChkCtx;
    temp_a2 = &this->unk304;
    sp30 = temp_a2;
    sp34 = temp_a1;
    CollisionCheck_SetOC(globalCtx, temp_a1, &temp_a2->base);
    if ((this->unk2D4 >= 6) && ((temp_a1_2 = &this->unk424, (this->actor.colorFilterTimer == 0)) ||
                                !(this->actor.colorFilterParams & 0x4000))) {
        sp2C = temp_a1_2;
        Collider_UpdateCylinder(&this->actor, temp_a1_2);
        CollisionCheck_SetAC(globalCtx, sp34, &this->unk470.base);
        CollisionCheck_SetAC(globalCtx, sp34, &sp2C->base);
    }
    if (this->unk2D4 == 7) {
        CollisionCheck_SetAC(globalCtx, sp34, &sp30->base);
    }
    if (this->unk2F8 > 0) {
        if (!(this->unk304.base.atFlags & 4)) {
            CollisionCheck_SetAT(globalCtx, sp34, &sp30->base);
        } else {
            func_80B3590C(this);
        }
    }
    this->actor.focus.pos.y = this->actor.world.pos.y;
    temp_v0 = this->unk302;
    this->actor.focus.pos.x = this->actor.world.pos.x;
    this->actor.focus.pos.y += 25.0f;
    this->actor.focus.pos.z = this->actor.world.pos.z;
    if (temp_v0 == 0) {
        if ((Rand_ZeroOne() < 0.2f) && !(globalCtx->gameplayFrames & 3) && (this->actor.colorFilterTimer == 0)) {
            this->unk302 += 1;
        }
    } else {
        this->unk302 = (temp_v0 + 1) & 3;
    }
}

s32 func_80B37454(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3f* arg3, Vec3s* arg4, EnWf* this) {
    if ((arg1 == 0x11) || (arg1 == 0x12)) {
        arg4->y -= this->unk4D6;
    }
    return 0;
}

void func_80B37494(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3s* arg3, EnWf* this) {
    s32 sp30;
    Vec3f sp24;
    Vec3f sp18;
    s32 var_v1;
    void* temp_v0;

    sp30 = -1;
    Collider_UpdateSpheres(arg1, &this->unk304);
    var_v1 = -1;
    if (arg1 == 6) {
        sp30 = -1;
        Matrix_MultVec3f(&D_80B37ADC, &sp24);
        var_v1 = sp30;
        this->unk470.dim.pos.x = (s16)(s32)sp24.x;
        this->unk470.dim.pos.y = (s16)(s32)sp24.y;
        this->unk470.dim.pos.z = (s16)(s32)sp24.z;
    }
    if ((this->unk2E4 != 0) || ((this->actor.colorFilterTimer != 0) && (this->actor.colorFilterParams & 0x4000))) {
        switch (arg1) {
            case 18:
                var_v1 = 0;
                break;
            case 14:
                var_v1 = 1;
                break;
            case 20:
                var_v1 = 2;
                break;
            case 12:
                var_v1 = 3;
                break;
            case 7:
                var_v1 = 4;
                break;
            case 6:
                var_v1 = 5;
                break;
            case 9:
                var_v1 = 6;
                break;
            case 37:
                var_v1 = 7;
                break;
            case 10:
                var_v1 = 8;
                break;
            case 5:
                var_v1 = 9;
                break;
        }
        if (var_v1 >= 0) {
            sp30 = var_v1;
            Matrix_MultVec3f(&D_80B37AE8, &sp18);
            // temp_v0 = this + (sp30 * 6);
            this->unk14C[sp30].x = (s16)(s32)sp18.x;
            this->unk14C[sp30].y = (s16)(s32)sp18.y;
            this->unk14C[sp30].z = (s16)(s32)sp18.z;
        }
    }
}

void EnWf_Draw(Actor* thisx, GlobalContext* globalCtx) {
    GraphicsContext* sp50;
    Gfx* sp40;
    Gfx* temp_v1;
    Gfx* temp_v1_2;
    GraphicsContext* temp_a1;
    s16 temp_v1_3;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v0;
    EnWf* this = (EnWf*)thisx;

    temp_a1 = globalCtx->state.gfxCtx;
    sp50 = temp_a1;
    Graph_OpenDisps(&sp40, temp_a1, "../z_en_wf.c", 0x86D);
    if ((this->unk2D4 != 0) || (this->unk300 == 0)) {
        func_80093D18(globalCtx->state.gfxCtx);
        if (this->actor.params == 0) {
            temp_v1 = sp50->polyOpa.p;
            sp50->polyOpa.p = temp_v1 + 8;
            temp_v1->words.w0 = 0xDB060020;
            temp_a0 = D_80B37AF4[this->unk302];
            temp_v1->words.w1 = (temp_a0 & 0xFFFFFF) + gSegments[(u32)(temp_a0 * 0x10) >> 0x1C] + 0x80000000;
        } else {
            temp_v1_2 = sp50->polyOpa.p;
            sp50->polyOpa.p = temp_v1_2 + 8;
            temp_v1_2->words.w0 = 0xDB060020;
            temp_a0_2 = D_80B37B04[this->unk302];
            temp_v1_2->words.w1 = (temp_a0_2 & 0xFFFFFF) + gSegments[(u32)(temp_a0_2 * 0x10) >> 0x1C] + 0x80000000;
        }
        SkelAnime_DrawFlexOpa(globalCtx, this->unk188.skeleton, this->unk188.jointTable, (s32)this->unk188.dListCount,
                              (s32(*)(GlobalContext*, s32, Gfx**, Vec3f*, Vec3s*, void*))func_80B37454,
                              (void (*)(GlobalContext*, s32, Gfx**, Vec3s*, void*))func_80B37494, this);
        if (this->unk2E4 != 0) {
            this->unk2E4 -= 1;
            temp_v1_3 = this->unk2E4;
            this->actor.colorFilterTimer += 1;
            temp_v0 = temp_v1_3 >> 2;
            if (!(temp_v1_3 & 3)) {
                EffectSsEnFire_SpawnVec3s(globalCtx, &this->actor, this + (temp_v0 * 6) + 0x14C, 0x4B, 0, 0,
                                          (s16)temp_v0);
            }
        }
    }
    Graph_CloseDisps(&sp40, globalCtx->state.gfxCtx, "../z_en_wf.c", 0x88E);
}

s32 func_80B37830(GlobalContext* globalCtx, EnWf* this) {
    Actor* sp24;
    s16 sp22;
    Actor* temp_v0;
    f32 temp_fv1;
    s16 temp_a2;
    s16 temp_t7;
    s16 var_v0;
    s16 var_v0_2;
    s16 var_v0_3;
    s16 var_v0_4;

    temp_v0 = Actor_GetProjectileActor(globalCtx, &this->actor, 600.0f);
    if (temp_v0 != NULL) {
        sp24 = temp_v0;
        temp_t7 = this->actor.shape.rot.y;
        temp_a2 = Actor_WorldYawTowardActor(&this->actor, temp_v0) - temp_t7;
        this->actor.world.rot.y = temp_t7;
        sp22 = temp_a2;
        temp_fv1 = Actor_WorldDistXYZToPoint(&this->actor, &sp24->world.pos);
        var_v0 = -temp_a2;
        if (temp_a2 >= 0) {
            var_v0 = temp_a2;
        }
        if ((var_v0 < 0x2EE0) && (sqrt((f64)temp_fv1) < 400.0)) {
            func_80B36288(this);
            return 1;
        }
        var_v0_2 = -temp_a2;
        this->actor.world.rot.y = this->actor.shape.rot.y + 0x3FFF;
        if (temp_a2 >= 0) {
            var_v0_2 = temp_a2;
        }
        if (var_v0_2 >= 0x2000) {
            var_v0_3 = -temp_a2;
            if (temp_a2 >= 0) {
                var_v0_3 = temp_a2;
            }
            if (var_v0_3 >= 0x6000) {
                goto block_12;
            }
            var_v0_4 = -temp_a2;
            if (temp_a2 >= 0) {
                var_v0_4 = temp_a2;
            }
            if (var_v0_4 < 0x5FFF) {
                func_80B35B94(this);
            }
            return 1;
        }
    block_12:
        func_80B365A8(this, globalCtx);
        this->actor.speedXZ *= 2.0f;
        return 1;
    }
    return 0;
}

#else

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B3590C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B359A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B35B94.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B35C10.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B35D18.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B35D90.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B35E4C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B35EE4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B360E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B361A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B36288.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B36328.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B365A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B36740.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B36C8C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B36D3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B36F40.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B37038.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/EnWf_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B37454.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B37494.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/EnWf_Draw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wf/func_80B37830.s")

#endif
