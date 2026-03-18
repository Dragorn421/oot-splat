#include "z_en_firefly.h"

#define FLAGS 0x00005005

#define THIS ((EnFirefly*)thisx)

void EnFirefly_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFirefly_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFirefly_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFirefly_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A13070(EnFirefly* arg0);
void func_80A13098(EnFirefly* arg0);
void func_80A132F4(EnFirefly* arg0);
void func_80A133A0(EnFirefly* arg0);
void func_80A13444(EnFirefly* arg0);
void func_80A13464(EnFirefly* arg0);
void func_80A1349C(EnFirefly* arg0);
void func_80A1350C(EnFirefly* arg0);
void func_80A13538(EnFirefly* arg0);
void func_80A135A8(EnFirefly* arg0, GlobalContext* arg1);
void func_80A13744(EnFirefly* arg0);
void func_80A13764(EnFirefly* arg0);
s32 func_80A1379C(EnFirefly* arg0, GlobalContext* arg1);
s32 func_80A138B8(EnFirefly* arg0, GlobalContext* arg1);
void func_80A13A08(EnFirefly* arg0, GlobalContext* arg1);
void func_80A13C98(EnFirefly* arg0, GlobalContext* arg1);
void func_80A13D68(EnFirefly* arg0, GlobalContext* arg1);
void func_80A13DE4(EnFirefly* arg0, GlobalContext* arg1);
void func_80A13FF4(EnFirefly* arg0, GlobalContext* arg1);
void func_80A14088(EnFirefly* arg0, GlobalContext* arg1);
void func_80A141F0(EnFirefly* arg0, GlobalContext* arg1);
void func_80A14294(EnFirefly* arg0, GlobalContext* arg1);
void func_80A142F4(EnFirefly* arg0, GlobalContext* arg1);
void func_80A143B4(EnFirefly* arg0, GlobalContext* arg1);
void func_80A1448C(EnFirefly* arg0, GlobalContext* arg1);
void func_80A1450C(EnFirefly* arg0, GlobalContext* arg1);
void func_80A14E28(Actor*, GlobalContext*);

extern AnimationHeader D_600017C;
extern Gfx D_6001678[];
extern SkeletonHeader D_60018B8;

const ActorInit En_Firefly_InitVars = {
    ACTOR_EN_FIREFLY,
    ACTORTYPE_ENEMY,
    FLAGS,
    OBJECT_FIREFLY,
    sizeof(EnFirefly),
    (ActorFunc)EnFirefly_Init,
    (ActorFunc)EnFirefly_Destroy,
    (ActorFunc)EnFirefly_Update,
    (ActorFunc)EnFirefly_Draw,
};
static ColliderSpheresElementSrc D_80A14F30 = {
    { 0, { 0xFFCFFFFF, 1, 8 }, { 0xFFCFFFFF, 0, 0 }, 9, 1, 1 },
    { 1, { { 0, 0x3E8, 0 }, 0xF }, 0x64 },
};
static ColliderSpheresSrc D_80A14F54 = { { 3, 0x11, 9, 0x39, 0x10, 0 }, 1, &D_80A14F30 };
static CollideDataInit D_80A14F64 = { 1, 0xA, 0xA, 0x1E };
static ActorDamageChart D_80A14F6C = {
    {
        { 0x10 }, { 2 },    { 1 }, { 2 }, { 1 }, { 2 }, { 2 },    { 2 },    { 1 }, { 2 }, { 4 },
        { 0xF2 }, { 0x34 }, { 2 }, { 2 }, { 2 }, { 2 }, { 0x20 }, { 0x34 }, { 0 }, { 0 }, { 0 },
        { 1 },    { 4 },    { 2 }, { 2 }, { 8 }, { 4 }, { 0 },    { 0 },    { 4 }, { 0 },
    },
};
static InitChainEntry D_80A14F8C[5] = {
    ICHAIN_VEC3F_DIV1000(scale, 5, ICHAIN_CONTINUE), ICHAIN_F32_DIV1000(gravity, -500, ICHAIN_CONTINUE),
    ICHAIN_F32(minVelocityY, -4, ICHAIN_CONTINUE),   ICHAIN_U8(unk_1F, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(unk_4C, 4000, ICHAIN_STOP),
};
static Color_RGBA8 D_80A14FA0 = { 0xFF, 0xFF, 0x64, 0xFF };
static Color_RGBA8 D_80A14FA4 = { 0xFF, 0x32, 0, 0 };
static Color_RGBA8 D_80A14FA8 = { 0x64, 0xC8, 0xFF, 0xFF };
static Color_RGBA8 D_80A14FAC = { 0, 0, 0xFF, 0 };
static Vec3f D_80A14FB0 = { 0.0f, 0.5f, 0.0f };
static Vec3f D_80A14FBC = { 0.0f, 0.5f, 0.0f };
static Vec3f D_80A14FC8 = { 0.0f, 0.0f, 0.0f };

void func_80A13070(EnFirefly* arg0) {
    arg0->actor.params += 2;
    arg0->unk314.elements->base.atDmgInfo.hitSpecialEffect = 0;
    arg0->unk1B8 = 0;
    arg0->unk1B9 = 0;
    arg0->actor.naviEnemyId = 0x12;
}

void func_80A13098(EnFirefly* arg0) {
    if (arg0->actor.params == 4) {
        arg0->actor.params = 0;
    } else {
        arg0->actor.params -= 2;
    }
    arg0->unk314.elements->base.atDmgInfo.hitSpecialEffect = 1;
    arg0->unk1B8 = 1;
    arg0->unk1B9 = 1;
    arg0->actor.naviEnemyId = 0x11;
}

void EnFirefly_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnFirefly* this = (EnFirefly*)thisx;

    Actor_ProcessInitChain(&this->actor, D_80A14F8C);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 25.0f);
    SkelAnime_Init(globalCtx, &this->unk170, &D_60018B8, &D_600017C, &this->unk1BE, &this->unk266, 0x1C);
    Collider_InitSpheres(globalCtx, &this->unk314);
    Collider_LoadSpheres(globalCtx, &this->unk314, &this->actor, &D_80A14F54, &this->unk334);
    func_80061ED4(&this->actor.collideData, &D_80A14F6C, &D_80A14F64);
    if (this->actor.params & 0x8000) {
        this->actor.flags |= 0x80;
        thisx->draw = func_80A14E28;
        this->actor.params &= 0x7FFF;
    }
    if (this->actor.params < 2) {
        this->unk1B9 = 1;
    } else {
        this->unk1B9 = 0;
    }
    if (this->unk1B9 != 0) {
        this->unk1B4 = func_80A13A08;
        this->unk1BA = Math_Rand_S16Offset(0x14, 0x3C);
        this->actor.shape.rot.x = 0x1554;
        this->unk1B8 = 1;
        this->actor.naviEnemyId = 0x11;
        this->unk310 = this->actor.initPosRot.pos.y;
    } else {
        if (this->actor.params == 3) {
            this->unk1B4 = func_80A142F4;
        } else {
            this->unk1B4 = func_80A13A08;
        }
        if (this->actor.params == 4) {
            this->unk314.elements->base.atDmgInfo.hitSpecialEffect = 2;
            this->actor.naviEnemyId = 0x56;
        } else {
            this->unk314.elements->base.atDmgInfo.hitSpecialEffect = 0;
            this->actor.naviEnemyId = 0x12;
        }
        this->unk310 = this->actor.initPosRot.pos.y + 100.0f;
        if (this->actor.params == 4) {
            this->unk1B8 = 2;
        } else {
            this->unk1B8 = 0;
        }
    }
    this->unk314.elements->shape.world.radius = D_80A14F54.elements->shape.unk2.radius;
}

void EnFirefly_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnFirefly* this = (EnFirefly*)thisx;

    Collider_DestroySpheres(globalCtx, &this->unk314);
}

void func_80A132F4(EnFirefly* arg0) {
    s32 var_v0;

    arg0->unk1BA = Math_Rand_S16Offset(0x46, 0x64);
    arg0->actor.speedXZ = (Math_Rand_ZeroOne() * 1.5f) + 1.5f;
    Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.y, func_8002DAC0(&arg0->actor, &arg0->actor.initPosRot.pos), 0x300);
    if (arg0->unk310 < arg0->actor.posRot.pos.y) {
        var_v0 = 0xC00;
    } else {
        var_v0 = -0xC00;
    }
    arg0->unk1BC = var_v0 + 0x1554;
    arg0->unk170.animPlaybackSpeed = 1.0f;
    arg0->unk1B4 = func_80A13A08;
}

void func_80A133A0(EnFirefly* arg0) {
    arg0->unk1BA = 0x28;
    arg0->actor.velocity.y = 0.0f;
    SkelAnime_ChangeAnim(&arg0->unk170, &D_600017C, 0.5f, 0.0f, 0.0f, 1U, -3.0f);
    Audio_PlayActorSound2(&arg0->actor, 0x3842U);
    arg0->actor.flags |= 0x10;
    func_8003426C(&arg0->actor, 0x4000, 0xFF, 0, 0x28);
    arg0->unk1B4 = func_80A13C98;
}

void func_80A13444(EnFirefly* arg0) {
    arg0->unk1BA = 0xF;
    arg0->unk1B4 = func_80A13D68;
    arg0->actor.speedXZ = 0.0f;
}

void func_80A13464(EnFirefly* arg0) {
    arg0->actor.posRot.rot.x = 0x7000;
    arg0->unk1BA = 0x12;
    arg0->unk1B4 = func_80A13FF4;
    arg0->unk170.animPlaybackSpeed = 1.0f;
    arg0->actor.speedXZ = 2.5f;
}

void func_80A1349C(EnFirefly* arg0) {
    s32 var_v0;

    arg0->unk1BA = Math_Rand_S16Offset(0x46, 0x64);
    arg0->unk170.animPlaybackSpeed = 1.0f;
    if (arg0->actor.yDistFromLink > 0.0f) {
        var_v0 = -0xC00;
    } else {
        var_v0 = 0xC00;
    }
    arg0->unk1BC = var_v0 + 0x1554;
    arg0->unk1B4 = func_80A13DE4;
}

void func_80A1350C(EnFirefly* arg0) {
    arg0->unk1BA = 0x96;
    arg0->unk1BC = 0x954;
    arg0->unk1B4 = func_80A14088;
    arg0->unk170.animPlaybackSpeed = 1.0f;
}

void func_80A13538(EnFirefly* arg0) {
    arg0->unk1BA = 0x50;
    func_8003426C(&arg0->actor, 0, 0xFF, 0, 0x50);
    arg0->unk1B8 = 0;
    arg0->actor.velocity.y = 0.0f;
    arg0->unk170.animPlaybackSpeed = 3.0f;
    Audio_PlayActorSound2(&arg0->actor, 0x389EU);
    arg0->unk1B4 = func_80A141F0;
}

void func_80A135A8(EnFirefly* arg0, GlobalContext* arg1) {
    f32 var_fv0;
    Vec3f sp78;
    s32 var_s0;

    arg0->actor.flags |= 0x10;
    arg0->unk1B8 = 0;
    arg0->actor.speedXZ = 0.0f;
    func_8003426C(&arg0->actor, 0, 0xFF, 0, 0xFF);
    Audio_PlayActorSound2(&arg0->actor, 0x3842U);
    var_s0 = 0;
    do {
        sp78.x = arg0->actor.posRot.pos.x + ((var_s0 & 1) ? 7.0f : -7.0f);
        sp78.y = arg0->actor.posRot.pos.y + ((var_s0 & 2) ? 7.0f : -7.0f);
        sp78.z = arg0->actor.posRot.pos.z + ((var_s0 & 4) ? 7.0f : -7.0f);
        EffectSsEnIce_SpawnFlyingVec3f(arg1, &arg0->actor, (Vec3f*)&sp78, 0x96, 0x96, 0x96, 0xFA, 0xEB, 0xF5, 0xFF,
                                       (Math_Rand_ZeroOne() * 0.15f) + 0.85f);
        var_s0 += 1;
    } while (var_s0 != 8);
    arg0->unk1B4 = func_80A14294;
}

void func_80A13744(EnFirefly* arg0) {
    arg0->unk1BA = 1;
    arg0->unk1B4 = func_80A142F4;
    arg0->actor.speedXZ = 0.0f;
}

void func_80A13764(EnFirefly* arg0) {
    arg0->actor.shape.rot.x = 0x1554;
    arg0->unk170.animPlaybackSpeed = 3.0f;
    arg0->actor.shape.rot.y = arg0->actor.yawTowardsLink;
    arg0->unk1BA = 0x32;
    arg0->actor.speedXZ = 3.0f;
    arg0->unk1B4 = func_80A143B4;
}

s32 func_80A1379C(EnFirefly* arg0, GlobalContext* arg1) {
    Actor* new_var = arg1->actorCtx.actorList[2].first;
    f32 temp_fv0;
    f32 temp_fv1;

    if (arg0->actor.params != 3) {
        return 0;
    }
    if (func_8002DBB0(new_var, &arg0->actor.initPosRot.pos) > 300.0f) {
        temp_fv0 = func_8002DB6C(&arg0->actor, &arg0->actor.initPosRot.pos);
        if (temp_fv0 < 5.0f) {
            func_80A13744(arg0);
            return 1;
        }
        temp_fv1 = temp_fv0 * 0.05f;
        if (temp_fv1 < 1.0f) {
            arg0->actor.speedXZ *= temp_fv1;
        }
        Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.y, func_8002DAC0(&arg0->actor, &arg0->actor.initPosRot.pos),
                                 0x300);
        Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.x,
                                 (s16)(func_8002DB28(&arg0->actor, &arg0->actor.initPosRot.pos) + 0x1554), 0x100);
        return 1;
    }
    return 0;
}

typedef struct struct_actor5E {
    char unk0[0x1E4];
    s16 unk1E4;
} struct_actor5E;

s32 func_80A138B8(EnFirefly* arg0, GlobalContext* arg1) {
    Actor* var_s0;
    f32 var_fs0;
    f32 temp_fv0;
    Actor* var_s1;
    Vec3f sp34;

    var_s0 = arg1->actorCtx.actorList[6].first;
    var_s1 = NULL;
    var_fs0 = 35000.0f;
    if (var_s0 != NULL) {
        do {
            if ((var_s0->id == 0x5E) && (((struct_actor5E*)var_s0)->unk1E4 != 0)) {
                temp_fv0 = func_8002DB48(&arg0->actor, var_s0);
                if (temp_fv0 < var_fs0) {
                    var_fs0 = temp_fv0;
                    var_s1 = var_s0;
                }
            }
            var_s0 = var_s0->next;
        } while (var_s0 != NULL);
    }
    if (var_s1 != NULL) {
        sp34.x = var_s1->posRot.pos.x;
        sp34.y = var_s1->posRot.pos.y + 52.0f + 15.0f;
        sp34.z = var_s1->posRot.pos.z;
        if (func_8002DB6C(&arg0->actor, (Vec3f*)&sp34) < 15.0f) {
            func_80A13098(arg0);
            return 1;
        }
        Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.y, func_8002DA78(&arg0->actor, var_s1), 0x300);
        Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.x, (s16)(func_8002DB28(&arg0->actor, (Vec3f*)&sp34) + 0x1554),
                                 0x100);
        return 1;
    }
    return 0;
}

void func_80A13A08(EnFirefly* arg0, GlobalContext* arg1) {
    s32 sp3C;
    f32 temp_fv0;

    SkelAnime_FrameUpdateMatrix(&arg0->unk170);
    if (arg0->unk1BA != 0) {
        arg0->unk1BA -= 1;
    }
    sp3C = func_800A56C8(&arg0->unk170, 0.0f);
    arg0->actor.speedXZ = (Math_Rand_ZeroOne() * 1.5f) + 1.5f;
    if ((arg0->unk1B9 != 0) || (arg0->actor.params == 4) ||
        ((func_80A1379C(arg0, arg1) == 0) && (func_80A138B8(arg0, arg1) == 0))) {
        if (sp3C != 0) {
            temp_fv0 = Math_Rand_ZeroOne();
            if (temp_fv0 < 0.5f) {
                Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.y,
                                         func_8002DAC0(&arg0->actor, &arg0->actor.initPosRot.pos), 0x300);
            } else if (temp_fv0 < 0.8f) {
                f32 new_var = Math_Rand_CenteredFloat(1536.0f);

                arg0->actor.shape.rot.y = (s16)(s32)((f32)arg0->actor.shape.rot.y + new_var);
            }
            if (arg0->actor.posRot.pos.y < (arg0->actor.groundY + 20.0f)) {
                arg0->unk1BC = 0x954;
            } else if (arg0->unk310 < arg0->actor.posRot.pos.y) {
                arg0->unk1BC = 0x2154;
            } else if (Math_Rand_ZeroOne() > 0.35f) {
                arg0->unk1BC = 0x954;
            } else {
                arg0->unk1BC = 0x2154;
            }
        } else {
            if (arg0->actor.bgCheckFlags & 1) {
                arg0->unk1BC = 0x954;
            } else if ((arg0->actor.bgCheckFlags & 0x10) || (arg0->unk310 < arg0->actor.posRot.pos.y)) {
                arg0->unk1BC = 0x2154;
            }
        }
        Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.x, arg0->unk1BC, 0x100);
    }
    if (arg0->actor.bgCheckFlags & 8) {
        Math_SmoothScaleMaxMinS(&arg0->actor.shape.rot.y, arg0->actor.wallPolyRot, 2, 0xC00, 0x300);
    }
    if ((arg0->unk1BA == 0) && (arg0->actor.xzDistFromLink < 200.0f) && (Player_GetMask(arg1) != 2)) {
        func_80A1349C(arg0);
    }
}

void func_80A13C98(EnFirefly* arg0, GlobalContext* arg1) {
    if (func_800A56C8(&arg0->unk170, 6.0f) != 0) {
        arg0->unk170.animPlaybackSpeed = 0.0f;
    }
    arg0->actor.dmgEffectTimer = 0x28;
    SkelAnime_FrameUpdateMatrix(&arg0->unk170);
    Math_ApproxF(&arg0->actor.speedXZ, 0.0f, 0.5f);
    if (arg0->actor.flags & 0x8000) {
        arg0->actor.dmgEffectTimer = 0x28;
        return;
    }
    Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.x, 0x6800, 0x200);
    arg0->actor.shape.rot.y -= 0x300;
    if (arg0->unk1BA != 0) {
        arg0->unk1BA -= 1;
    }
    if ((arg0->actor.bgCheckFlags & 1) || (arg0->unk1BA == 0)) {
        func_80A13444(arg0);
    }
}

void func_80A13D68(EnFirefly* arg0, GlobalContext* arg1) {
    f32 temp_fv0;
    s16 temp_v0;

    temp_v0 = arg0->unk1BA;
    if (temp_v0 != 0) {
        arg0->unk1BA = temp_v0 - 1;
    }
    Math_ApproxF(&arg0->actor.scale.x, 0.0f, 0.00034f);
    temp_fv0 = arg0->actor.scale.x;
    arg0->actor.scale.z = temp_fv0;
    arg0->actor.scale.y = temp_fv0;
    if (arg0->unk1BA == 0) {
        Item_DropCollectibleRandom(arg1, &arg0->actor, &arg0->actor.posRot.pos, 0xE0);
        Actor_Kill(&arg0->actor);
    }
}

void func_80A13DE4(EnFirefly* arg0, GlobalContext* arg1) {
    Actor* sp44;
    Vec3f sp38;

    sp44 = arg1->actorCtx.actorList[2].first;
    SkelAnime_FrameUpdateMatrix(&arg0->unk170);
    if (arg0->unk1BA != 0) {
        arg0->unk1BA -= 1;
    }
    Math_ApproxF(&arg0->actor.speedXZ, 4.0f, 0.5f);
    if (arg0->actor.bgCheckFlags & 8) {
        Math_SmoothScaleMaxMinS(&arg0->actor.shape.rot.y, arg0->actor.wallPolyRot, 2, 0xC00, 0x300);
        Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.x, arg0->unk1BC, 0x100);
    } else if (func_8002E084(&arg0->actor, 0x2800) != 0) {
        if (func_800A56C8(&arg0->unk170, 4.0f) != 0) {
            arg0->unk170.animPlaybackSpeed = 0.0f;
            arg0->unk170.animCurrentFrame = 4.0f;
        }
        Math_SmoothScaleMaxMinS(&arg0->actor.shape.rot.y, arg0->actor.yawTowardsLink, 2, 0xC00, 0x300);
        sp38.x = sp44->posRot.pos.x;
        sp38.y = sp44->posRot.pos.y + 20.0f;
        sp38.z = sp44->posRot.pos.z;
        Math_SmoothScaleMaxMinS(&arg0->actor.shape.rot.x, (s16)(func_8002DB28(&arg0->actor, (Vec3f*)&sp38) + 0x1554), 2,
                                0x400, 0x100);
    } else {
        arg0->unk170.animPlaybackSpeed = 1.5f;
        if (arg0->actor.xzDistFromLink > 80.0f) {
            Math_SmoothScaleMaxMinS(&arg0->actor.shape.rot.y, arg0->actor.yawTowardsLink, 2, 0xC00, 0x300);
        }
        if (arg0->actor.bgCheckFlags & 1) {
            arg0->unk1BC = 0x954;
        }
        if ((arg0->actor.bgCheckFlags & 0x10) || (arg0->unk310 < arg0->actor.posRot.pos.y)) {
            arg0->unk1BC = 0x2154;
        } else {
            arg0->unk1BC = 0x954;
        }
        Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.x, arg0->unk1BC, 0x100);
    }
    if ((arg0->unk1BA == 0) || (Player_GetMask(arg1) == 2)) {
        func_80A1350C(arg0);
    }
}

void func_80A13FF4(EnFirefly* arg0, GlobalContext* arg1) {
    SkelAnime_FrameUpdateMatrix(&arg0->unk170);
    Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.x, 0, 0x100);
    Math_ApproxF(&arg0->actor.velocity.y, 0.0f, 0.4f);
    if (Math_ApproxF(&arg0->actor.speedXZ, 0.0f, 0.15f) != 0) {
        if (arg0->unk1BA != 0) {
            arg0->unk1BA -= 1;
        }
        if (arg0->unk1BA == 0) {
            func_80A1350C(arg0);
        }
    }
}

void func_80A14088(EnFirefly* arg0, GlobalContext* arg1) {
    SkelAnime_FrameUpdateMatrix(&arg0->unk170);
    if (arg0->unk1BA != 0) {
        arg0->unk1BA -= 1;
    }
    if (((fabsf(arg0->actor.posRot.pos.y - arg0->unk310) < 10.0f) &&
         (Math_Vec3f_DistXZ(&arg0->actor.posRot.pos, &arg0->actor.initPosRot.pos) < 20.0f)) ||
        (arg0->unk1BA == 0)) {
        func_80A132F4(arg0);
        return;
    }
    Math_ApproxF(&arg0->actor.speedXZ, 3.0f, 0.3f);
    if (arg0->actor.bgCheckFlags & 1) {
        arg0->unk1BC = 0x954;
    } else if ((arg0->actor.bgCheckFlags & 0x10) || (arg0->unk310 < arg0->actor.posRot.pos.y)) {
        arg0->unk1BC = 0x2154;
    } else {
        arg0->unk1BC = 0x954;
    }
    if (arg0->actor.bgCheckFlags & 8) {
        Math_SmoothScaleMaxMinS(&arg0->actor.shape.rot.y, arg0->actor.wallPolyRot, 2, 0xC00, 0x300);
    } else {
        Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.y, func_8002DAC0(&arg0->actor, &arg0->actor.initPosRot.pos),
                                 0x300);
    }
    Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.x, arg0->unk1BC, 0x100);
}

void func_80A141F0(EnFirefly* arg0, GlobalContext* arg1) {
    SkelAnime_FrameUpdateMatrix(&arg0->unk170);
    Math_ApproxF(&arg0->actor.speedXZ, 0.0f, 0.5f);
    Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.x, 0x1554, 0x100);
    if (arg0->unk1BA != 0) {
        arg0->unk1BA -= 1;
    }
    if (arg0->unk1BA == 0) {
        if (arg0->unk1B9 != 0) {
            arg0->unk1B8 = 1;
        } else if (arg0->actor.params == 4) {
            arg0->unk1B8 = 2;
        }
        func_80A132F4(arg0);
    }
}

void func_80A14294(EnFirefly* arg0, GlobalContext* arg1) {
    if ((arg0->actor.bgCheckFlags & 1) || (arg0->actor.groundY == -32000.0f)) {
        arg0->actor.dmgEffectTimer = 0;
        func_80A13444(arg0);
        return;
    }
    arg0->actor.dmgEffectTimer = 0xFF;
}

void func_80A142F4(EnFirefly* arg0, GlobalContext* arg1) {
    Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.x, 0, 0x100);
    if (arg0->unk1BA != 0) {
        SkelAnime_FrameUpdateMatrix(&arg0->unk170);
        if (func_800A56C8(&arg0->unk170, 6.0f) != 0) {
            arg0->unk1BA -= 1;
        }
    } else if (Math_Rand_ZeroOne() < 0.02f) {
        arg0->unk1BA = 1;
    }
    if (arg0->actor.xzDistFromLink < 120.0f) {
        func_80A13764(arg0);
    }
}

void func_80A143B4(EnFirefly* arg0, GlobalContext* arg1) {
    Actor* temp_a2;
    Vec3f sp28;

    temp_a2 = arg1->actorCtx.actorList[2].first;
    SkelAnime_FrameUpdateMatrix(&arg0->unk170);
    if (arg0->unk1BA != 0) {
        arg0->unk1BA -= 1;
    }
    if (arg0->unk1BA < 0x28) {
        Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.x, -0xAAC, 0x100);
    } else {
        sp28.x = temp_a2->posRot.pos.x;
        sp28.y = temp_a2->posRot.pos.y + 20.0f;
        sp28.z = temp_a2->posRot.pos.z;
        Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.x, (s16)(func_8002DB28(&arg0->actor, (Vec3f*)&sp28) + 0x1554),
                                 0x100);
        Math_ApproxUpdateScaledS(&arg0->actor.shape.rot.y, arg0->actor.yawTowardsLink, 0x300);
    }
    if (arg0->unk1BA == 0) {
        func_80A132F4(arg0);
    }
}

void func_80A1448C(EnFirefly* arg0, GlobalContext* arg1) {
    s32 var_s0;

    var_s0 = 0;
    do {
        EffectSsEnFire_SpawnVec3f(arg1, &arg0->actor, &arg0->actor.posRot.pos, 0x28, 0, 0, (s16)var_s0);
        var_s0 += 1;
    } while (var_s0 != 3);
    arg0->unk1B8 = 0;
}

void func_80A1450C(EnFirefly* arg0, GlobalContext* arg1) {
    if ((arg0->unk314.base.acFlags & 2)) {
        arg0->unk314.base.acFlags &= 0xFFFD;
        func_80035650(&arg0->actor, &arg0->unk314.elements->base, 1);
        if ((((arg0->actor.collideData.damageEffect != 0)) || (arg0->actor.collideData.damage != 0))) {
            if (Actor_ApplyDamage(&arg0->actor) == 0) {
                func_80032C7C(arg1, &arg0->actor);
                arg0->actor.flags &= ~1;
            }
            if (arg0->actor.collideData.damageEffect == 2) {
                if (arg0->actor.params == 4) {
                    arg0->actor.collideData.health = 0;
                    func_80032C7C(arg1, &arg0->actor);
                    func_80A1448C(arg0, arg1);
                    func_80A133A0(arg0);
                    return;
                }
                if (arg0->unk1B9 == 0) {
                    func_80A13098(arg0);
                    if (arg0->unk1B4 == func_80A142F4) {
                        func_80A132F4(arg0);
                    }
                }
            } else {
                if (arg0->actor.collideData.damageEffect == 3) {
                    if (arg0->actor.params == 4) {
                        func_80A133A0(arg0);
                        return;
                    }
                    func_80A135A8(arg0, arg1);
                    return;
                }
                if (arg0->actor.collideData.damageEffect == 1) {
                    if (arg0->unk1B4 != func_80A141F0) {
                        func_80A13538(arg0);
                    }
                } else {
                    if ((arg0->actor.collideData.damageEffect == 0xF) && (arg0->actor.params == 4)) {
                        func_80A1448C(arg0, arg1);
                    }
                    func_80A133A0(arg0);
                }
            }
        }
    }
}

void EnFirefly_Update(Actor* thisx, GlobalContext* globalCtx2) {
    EnFirefly* this = (EnFirefly*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    f32 sp34;

    if (this->unk314.base.atFlags & 2) {
        this->unk314.base.atFlags &= 0xFFFD;
        Audio_PlayActorSound2(&this->actor, 0x3840U);
        if (this->unk1B9 != 0) {
            func_80A13070(this);
        }
        if (this->unk1B4 != func_80A143B4) {
            func_80A13464(this);
        }
    }
    func_80A1450C(this, globalCtx);
    this->unk1B4(this, globalCtx);
    if (!(this->actor.flags & 0x8000)) {
        if ((this->actor.collideData.health == 0) || ((this->unk1B4 == func_80A141F0))) {
            Actor_MoveForward(&this->actor);
        } else {
            if (this->unk1B4 != func_80A13FF4) {
                this->actor.posRot.rot.x = 0x1554 - this->actor.shape.rot.x;
            }
            func_8002D97C(&this->actor);
        }
    }
    func_8002E4B4(globalCtx, &this->actor, 10.0f, 10.0f, 15.0f, 7);
    this->unk314.elements->shape.world.center.x = (s16)(s32)this->actor.posRot.pos.x;
    this->unk314.elements->shape.world.center.y = (s16)(s32)(this->actor.posRot.pos.y + 10.0f);
    this->unk314.elements->shape.world.center.z = (s16)(s32)this->actor.posRot.pos.z;
    if ((this->unk1B4 == func_80A13DE4) || (this->unk1B4 == func_80A143B4)) {
        Collider_AddAT(globalCtx, &globalCtx->colliderCtx, &this->unk314.base);
    }
    if (this->actor.collideData.health != 0) {
        Collider_AddAC(globalCtx, &globalCtx->colliderCtx, &this->unk314.base);
        this->actor.posRot.rot.y = this->actor.shape.rot.y;
        if (func_800A56C8(&this->unk170, 5.0f) != 0) {
            Audio_PlayActorSound2(&this->actor, 0x3841U);
        }
    }
    Collider_AddOC(globalCtx, &globalCtx->colliderCtx, &this->unk314.base);
    sp34 = Math_Sins(this->actor.shape.rot.x);
    this->actor.posRot2.pos.x = (Math_Sins(this->actor.shape.rot.y) * (10.0f * sp34)) + this->actor.posRot.pos.x;
    this->actor.posRot2.pos.y = (Math_Coss(this->actor.shape.rot.x) * 10.0f) + this->actor.posRot.pos.y;
    sp34 = Math_Sins(this->actor.shape.rot.x);
    this->actor.posRot2.pos.z = (Math_Coss(this->actor.shape.rot.y) * (10.0f * sp34)) + this->actor.posRot.pos.z;
}

s32 func_80A14960(GlobalContext* arg0, s32 arg1, Gfx** arg2, Vec3f* arg3, Vec3s* arg5, void* thisx, Gfx** gfx) {
    EnFirefly* this = thisx;
    if ((this->actor.draw == func_80A14E28) && (arg0->actorCtx.unk_03 == 0)) {
        *arg2 = NULL;
    } else if (arg1 == 1) {
        arg3->y += 2300.0f;
    }
    return 0;
}

void func_80A149B4(GlobalContext* arg0, s32 arg1, Gfx** arg2, Vec3s* arg3, void* thisx, Gfx** arg5) {
    Vec3f sp94;
    Vec3f* var_a1;
    Color_RGBA8* var_v1;
    Color_RGBA8* var_v0;
    MtxF sp48;
    EnFirefly* this = thisx;
    s16 var_t0;
    s16 var_t1;

    if ((this->unk1B9 == 0) && (arg1 == 0x1B)) {
        gSPDisplayList((*arg5)++, D_6001678);
    } else {
        if (((this->unk1B8 == 1) || (this->unk1B8 == 2)) && ((arg1 == 0xF) || (arg1 == 0x15))) {
            if (this->unk1B4 != func_80A13D68) {
                Matrix_Get(&sp48);
                sp94.x = (Math_Rand_ZeroOne() * 5.0f) + sp48.wx;
                sp94.y = (Math_Rand_ZeroOne() * 5.0f) + sp48.wy;
                sp94.z = (Math_Rand_ZeroOne() * 5.0f) + sp48.wz;
                var_t0 = -0x28;
                var_t1 = 3;
            } else {
                if (arg1 == 0xF) {
                    sp94.x = (Math_Sins((s16)(this->unk1BA * 0x238C)) * (f32)this->unk1BA) + this->actor.posRot.pos.x;
                    sp94.z = (Math_Coss((s16)(this->unk1BA * 0x238C)) * (f32)this->unk1BA) + this->actor.posRot.pos.z;
                } else {
                    sp94.x = this->actor.posRot.pos.x - (Math_Sins((s16)(this->unk1BA * 0x238C)) * (f32)this->unk1BA);
                    sp94.z = this->actor.posRot.pos.z - (Math_Coss((s16)(this->unk1BA * 0x238C)) * (f32)this->unk1BA);
                }
                var_t0 = -5;
                var_t1 = 0xA;
                sp94.y = this->actor.posRot.pos.y + ((f32)(0xF - this->unk1BA) * 1.5f);
            }
            if ((u8)this->unk1B8 == 1) {
                var_v0 = &D_80A14FA0;
                var_v1 = &D_80A14FA4;
            } else {
                var_v0 = &D_80A14FA8;
                var_v1 = &D_80A14FAC;
            }
            func_8002843C(arg0, (Vec3f*)&sp94, &D_80A14FB0, &D_80A14FBC, var_v0, var_v1, 0xFA, (s16)var_t0,
                          (s16)var_t1);
        }
    }
    if ((arg1 == 0xF) || (arg1 == 0x15) || (arg1 == 0xA)) {
        if (arg1 == 0xF) {
            var_a1 = &this->unk14C;
        } else if (arg1 == 0x15) {
            var_a1 = &this->unk158;
        } else {
            var_a1 = &this->unk164;
        }
        Matrix_MultVec3f(&D_80A14FC8, var_a1);
        var_a1->y -= 5.0f;
    }
}

void EnFirefly_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnFirefly* this = (EnFirefly*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_firefly.c", 0x6C5);
    func_80093D18(globalCtx->state.gfxCtx);
    if (this->unk1B9 != 0) {
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);
    } else {
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    }
    POLY_OPA_DISP =
        SkelAnime_Draw(globalCtx, this->unk170.skeleton, this->unk170.limbDrawTbl,
                       (s32(*)(GlobalContext*, s32, Gfx**, Vec3f*, Vec3s*, void*, Gfx**))func_80A14960,
                       (void (*)(GlobalContext*, s32, Gfx**, Vec3s*, void*, Gfx**))func_80A149B4, this, POLY_OPA_DISP);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_firefly.c", 0x6E3);
}

void func_80A14E28(Actor* arg0, GlobalContext* arg1) {
    EnFirefly* this = (EnFirefly*)arg0;

    OPEN_DISPS(arg1->state.gfxCtx, "../z_en_firefly.c", 0x6EF);
    func_80093D84(arg1->state.gfxCtx);
    if (this->unk1B9 != 0) {
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, 0);
    } else {
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, 255);
    }
    POLY_XLU_DISP =
        SkelAnime_Draw(arg1, this->unk170.skeleton, this->unk170.limbDrawTbl,
                       (s32(*)(GlobalContext*, s32, Gfx**, Vec3f*, Vec3s*, void*, Gfx**))func_80A14960,
                       (void (*)(GlobalContext*, s32, Gfx**, Vec3s*, void*, Gfx**))func_80A149B4, arg0, POLY_XLU_DISP);
    CLOSE_DISPS(arg1->state.gfxCtx, "../z_en_firefly.c", 0x70D);
}
