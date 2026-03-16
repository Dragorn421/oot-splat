#include "global.h"
#include "ovl_En_Md.h"

void EnMd_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMd_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMd_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMd_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80AAAA24(EnMd* this);      // TODO
void func_80AAA92C(EnMd* this, s32); // TODO
void func_80AAA93C(EnMd* this);      // TODO
s16 func_80AAAC78(Actor* thisx, GlobalContext* globalCtx);
u16 func_80AAACF8(GlobalContext* globalCtx, EnMd* this);
u16 func_80AAADE0(GlobalContext* globalCtx, EnMd* this);
u16 func_80AAAE14(GlobalContext* globalCtx, EnMd* this);
u16 func_80AAAE94(GlobalContext* globalCtx, Actor* thisx);
s16 func_80AAAF04(GlobalContext* globalCtx, Actor* thisx);
s32 func_80AAB03C(EnMd* this, GlobalContext* globalCtx);
void func_80AAB0E0(EnMd* this);
void func_80AAB158(EnMd* this, GlobalContext* globalCtx);
void func_80AAB5A4(EnMd* this, GlobalContext* globalCtx);
void func_80AAB874(EnMd* this, GlobalContext* globalCtx);
void func_80AAB8F8(EnMd* this, GlobalContext* globalCtx);
void func_80AAB948(EnMd* this, GlobalContext* globalCtx); // TODO
void func_80AABC10(EnMd* this, GlobalContext* globalCtx); // TODO
void func_80AABD0C(EnMd* this, GlobalContext* globalCtx); // TODO

extern AnimationHeader D_60002C8;
extern SkeletonHeader D_6007FB8;

extern ColliderCylinderSrc D_80AAC310;
extern CollideDataInitAlt D_80AAC33C;
extern struct_80034EC0_Entry D_80AAC348[];

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA250.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA274.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA308.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA39C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA474.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA508.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA5A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA638.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA6D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA768.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA7FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA890.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA92C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA93C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAAA24.s")

s16 func_80AAAC78(Actor* thisx, GlobalContext* globalCtx) {
    EnMd* this = (EnMd*)thisx;
    s16 temp_v0;

    temp_v0 = func_8010BDBC(&globalCtx->msgCtx);
    if (((this->unk209 == 0xA) || (this->unk209 == 5) || (this->unk209 == 2) || (this->unk209 == 1)) &&
        (this->unk209 != temp_v0)) {
        this->unk208++;
    }
    this->unk209 = temp_v0;
    return temp_v0;
}

u16 func_80AAACF8(GlobalContext* globalCtx, EnMd* this) {
    u16 temp_v0;

    temp_v0 = Text_GetFaceReaction(globalCtx, 0x11);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    this->unk208 = 0;
    this->unk209 = 0;
    if (gBitFlags[0x12] & gSaveContext.questItems) {
        return 0x1045;
    }
    if (gSaveContext.eventChkInf[0] & 0x10) {
        return 0x1034;
    }
    if ((((s32)(gSaveContext.equips.equipment & gEquipMasks[1]) >> gEquipShifts[1]) == 1) &&
        (((s32)(gSaveContext.equips.equipment & gEquipMasks[0]) >> gEquipShifts[0]) == 1)) {
        return 0x1033;
    }
    if (gSaveContext.infTable[0] & 0x1000) {
        return 0x1030;
    }
    return 0x102F;
}

u16 func_80AAADE0(GlobalContext* globalCtx, EnMd* this) {
    this->unk208 = 0;
    this->unk209 = 0;
    if (gSaveContext.eventChkInf[4] & 1) {
        return 0x1028;
    }
    return 0x1046;
}

u16 func_80AAAE14(GlobalContext* globalCtx, EnMd* this) {
    this->unk208 = 0;
    this->unk209 = 0;
    if (gSaveContext.eventChkInf[4] & 0x100) {
        if (gSaveContext.infTable[1] & 0x200) {
            return 0x1071;
        } else {
            return 0x1070;
        }
    } else if (gSaveContext.eventChkInf[0] & 0x400) {
        return 0x1068;
    } else if (gSaveContext.infTable[1] & 0x20) {
        return 0x1061;
    } else {
        return 0x1060;
    }
}

u16 func_80AAAE94(GlobalContext* globalCtx, Actor* thisx) {
    EnMd* this = (EnMd*)thisx;

    switch (globalCtx->sceneNum) {
        case 0x55:
            return func_80AAACF8(globalCtx, this);
        case 0x28:
            return func_80AAADE0(globalCtx, this);
        case 0x5B:
            return func_80AAAE14(globalCtx, this);
        default:
            return 0;
    }
}

s16 func_80AAAF04(GlobalContext* globalCtx, Actor* thisx) {
    switch (func_80AAAC78(thisx, globalCtx)) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 6:
        case 7:
        case 8:
        case 9:
            return 1;

        case 2:
            switch (thisx->textId) {
                case 0x1028:
                    gSaveContext.eventChkInf[0] |= 0x8000;
                    break;
                case 0x102F:
                    gSaveContext.eventChkInf[0] |= 4;
                    gSaveContext.infTable[0] |= 0x1000;
                    break;
                case 0x1060:
                    gSaveContext.infTable[1] |= 0x20;
                    break;
                case 0x1070:
                    gSaveContext.infTable[1] |= 0x200;
                    break;
                case 0x1033:
                case 0x1067:
                    return 2;
            }
            return 0;

        case 5:
            if (func_80106BC8(globalCtx) != 0) {
                return 2;
            }
            break;
    }
    return 1;
}

s32 func_80AAB03C(EnMd* this, GlobalContext* globalCtx) {
    if ((globalCtx->sceneNum == 0x55) && !(gSaveContext.eventChkInf[1] & 0x1000) &&
        !(gSaveContext.eventChkInf[4] & 1)) {
        return 1;
    }
    if ((globalCtx->sceneNum == 0x28) &&
        ((gSaveContext.eventChkInf[1] & 0x1000) || (gSaveContext.eventChkInf[4] & 1)) && LINK_IS_CHILD) {
        return 1;
    }
    if (globalCtx->sceneNum == 0x5B) {
        return 1;
    }
    return 0;
}

void func_80AAB0E0(EnMd* arg0) {
    if (DECR(arg0->unk20C) == 0) {
        arg0->unk20E += 1;
        if (arg0->unk20E >= 3) {
            arg0->unk20C = Math_Rand_S16Offset(0x1E, 0x1E);
            arg0->unk20E = 0;
        }
    }
}

void func_80AAB158(EnMd* this, GlobalContext* globalCtx) {
    Player* temp_a2;
    s16 temp_v1;
    s16 temp_ft1;
    s16 var_v1_real;
    s16 var_a3_real;

    temp_a2 = PLAYER;
    if (this->actor.xzDistFromLink < 170.0f) {
        temp_ft1 = (f32)this->actor.yawTowardsLink - (f32)this->actor.shape.rot.y;
        temp_v1 = ABS(temp_ft1);
        if (temp_v1 <= func_800347E8(2)) {
            var_a3_real = 2;
            var_v1_real = 1;
        } else {
            var_a3_real = 1;
            var_v1_real = 1;
        }
    } else {
        var_a3_real = 1;
        var_v1_real = 0;
    }
    if (this->unk1E0.unk_00 != 0) {
        var_a3_real = 4;
    }
    if (this->unk190 == func_80AABD0C) {
        var_a3_real = 1;
        var_v1_real = 0;
    }
    if (this->unk190 == func_80AAB8F8) {
        var_a3_real = 4;
        var_v1_real = 1;
    }
    if ((globalCtx->csCtx.state != 0) || (D_8011D394 != 0)) {
        this->unk1E0.unk_18 = globalCtx->view.eye;
        this->unk1E0.unk_14 = 40.0f;
        var_a3_real = 2;
    } else {
        this->unk1E0.unk_18 = temp_a2->actor.posRot.pos;
        if (gSaveContext.linkAge > 0) {
            this->unk1E0.unk_14 = 0.0f;
        } else {
            this->unk1E0.unk_14 = -18.0f;
        }
    }
    func_80034A14(&this->actor, &this->unk1E0, 2, var_a3_real);
    if ((this->unk190 != func_80AABC10) && (var_v1_real != 0)) {
        func_800343CC(globalCtx, &this->actor, &this->unk1E0.unk_00, this->unk194.shape.radius + 30.0f, func_80AAAE94,
                      func_80AAAF04);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAB370.s")

s32 func_80AAB4DC(EnMd* this, GlobalContext* globalCtx) {
    Path* temp_a1;
    s32 temp_v1;
    Vec3s* temp_a3;

    temp_v1 = this->actor.params & 0xFF00;
    if (temp_v1 == 0xFF00) {
        return 0;
    }
    temp_a1 = &globalCtx->setupPathList[temp_v1 >> 8];
    temp_a3 = SEGMENTED_TO_VIRTUAL(temp_a1->points);
    temp_a3 += temp_a1->count - 1;
    this->actor.posRot.pos.x = (f32)temp_a3->x; // unk-6;
    this->actor.posRot.pos.y = (f32)temp_a3->y;
    this->actor.posRot.pos.z = (f32)temp_a3->z;
    return 1;
}

void func_80AAB5A4(EnMd* this, GlobalContext* globalCtx) {
    f32 var_fv0;

    if (globalCtx->sceneNum != 0x28) {
        if ((gBitFlags[0x12] & gSaveContext.questItems) && !(gSaveContext.eventChkInf[1] & 0x1000) &&
            (globalCtx->sceneNum == 0x55)) {
            var_fv0 = 100.0f;
        } else {
            var_fv0 = 400.0f;
        }
        this->unk210 = func_80034DD4(&this->actor, globalCtx, this->unk210, var_fv0);
        this->actor.shape.unk_14 = (u8)this->unk210;
    } else {
        this->unk210 = 0xFF;
        this->actor.shape.unk_14 = (u8)this->unk210;
    }
}

void EnMd_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnMd* this = (EnMd*)thisx;
    s32 pad;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 24.0f);
    SkelAnime_InitSV(globalCtx, &this->unk14C, &D_6007FB8, NULL, this->unk258, this->unk2BE, 0x11);
    Collider_InitCylinder(globalCtx, &this->unk194);
    Collider_LoadCylinder(globalCtx, &this->unk194, &this->actor, &D_80AAC310);
    func_80061EFC(&this->actor.collideData, NULL, &D_80AAC33C);
    if (func_80AAB03C(this, globalCtx) == 0) {
        Actor_Kill(&this->actor);
        return;
    }
    func_80034EC0(&this->unk14C, D_80AAC348, 0);
    Actor_SetScale(&this->actor, 0.01f);
    this->actor.unk_1F = 6;
    this->unk210 = 0xFF;
    Actor_SpawnAttached(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_EN_ELF, this->actor.posRot.pos.x,
                        this->actor.posRot.pos.y, this->actor.posRot.pos.z, 0, 0, 0, 3);
    if (((globalCtx->sceneNum == SCENE_SPOT04) && !(gSaveContext.eventChkInf[0] & 0x10)) ||
        ((globalCtx->sceneNum == SCENE_SPOT04) && (gSaveContext.eventChkInf[0] & 0x10) &&
         (gBitFlags[0x12] & gSaveContext.questItems)) ||
        ((globalCtx->sceneNum == SCENE_SPOT10) && !(gSaveContext.eventChkInf[0] & 0x400))) {
        this->actor.initPosRot.pos = this->actor.posRot.pos;
        this->unk190 = func_80AAB948;
    } else {
        if (globalCtx->sceneNum != SCENE_KOKIRI_HOME4) {
            func_80AAB4DC(this, globalCtx);
        }
        this->unk190 = func_80AAB874;
    }
}

void EnMd_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnMd* this = (EnMd*)thisx;

    Collider_DestroyCylinder(globalCtx, &this->unk194);
}

void func_80AAB874(EnMd* this, GlobalContext* globalCtx) {
    if (this->unk14C.animCurrentSeg == &D_60002C8) {
        func_80034F54(globalCtx, &this->unk214, &this->unk236, 0x11);
    } else if ((this->unk1E0.unk_00 == 0) && (this->unk20B != 7)) {
        func_80AAA92C(this, 7);
    }
    func_80AAAA24(this);
}

void func_80AAB8F8(EnMd* this, GlobalContext* globalCtx) {
    if (this->unk14C.animCurrentSeg == &D_60002C8) {
        func_80034F54(globalCtx, &this->unk214, &this->unk236, 0x11);
    }
    func_80AAA93C(this);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAB948.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AABC10.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AABD0C.s")

void EnMd_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnMd* this = (EnMd*)thisx;
    s32 pad;

    Collider_UpdateCylinderShape(&this->actor, &this->unk194);
    Collider_AddOC(globalCtx, &globalCtx->colliderCtx, &this->unk194.base);
    SkelAnime_FrameUpdateMatrix(&this->unk14C);
    func_80AAB0E0(this);
    func_80AAB5A4(this, globalCtx);
    Actor_MoveForward(&this->actor);
    func_80AAB158(this, globalCtx);
    func_8002E4B4(globalCtx, &this->actor, 0.0f, 0.0f, 0.0f, 4);
    this->unk190(this, globalCtx);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AABEF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAC104.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/EnMd_Draw.s")
