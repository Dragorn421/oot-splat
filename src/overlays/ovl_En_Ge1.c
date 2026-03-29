#include "z_en_ge1.h"

#define FLAGS 0x00000009

#define THIS ((EnGe1*)thisx)

void EnGe1_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGe1_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGe1_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGe1_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 func_80A30C70(EnGe1* arg0, GlobalContext* arg1, u16 arg2, f32 arg3, void (*arg4)(EnGe1*, GlobalContext*));
void func_80A30D48(EnGe1* arg0);
s32 func_80A30DCC(void);
void func_80A30E08(EnGe1* arg0, GlobalContext* arg1);
void func_80A30EE8(EnGe1* arg0, GlobalContext* arg1);
void func_80A30F48(EnGe1* arg0, GlobalContext* arg1);
void func_80A31000(EnGe1* arg0, GlobalContext* arg1);
void func_80A31094(EnGe1* arg0, GlobalContext* arg1);
void func_80A310C4(EnGe1* arg0, GlobalContext* arg1);
void func_80A3118C(EnGe1* arg0, GlobalContext* arg1);
void func_80A311E0(EnGe1* arg0, GlobalContext* arg1);
void func_80A31234(EnGe1* arg0, GlobalContext* arg1);
void func_80A312E4(EnGe1* arg0, GlobalContext* arg1);
void func_80A313A0(EnGe1* arg0, GlobalContext* arg1);
void func_80A313E0(EnGe1* arg0, GlobalContext* arg1);
void func_80A314D0(EnGe1* arg0, GlobalContext* arg1);
void func_80A31514(EnGe1* arg0, GlobalContext* arg1);
void func_80A3157C(EnGe1* arg0, GlobalContext* arg1);
void func_80A315F0(EnGe1* arg0, GlobalContext* arg1);
void func_80A31644(EnGe1* arg0, GlobalContext* arg1);
void func_80A316F4(EnGe1* arg0, GlobalContext* arg1);
void func_80A317C0(EnGe1* arg0, GlobalContext* arg1);
void func_80A3183C(EnGe1* arg0, GlobalContext* arg1);
void func_80A31880(EnGe1* arg0, GlobalContext* arg1);
void func_80A31934(EnGe1* arg0, GlobalContext* arg1);
void func_80A3196C(EnGe1* arg0, GlobalContext* arg1);
void func_80A31A5C(EnGe1* arg0, GlobalContext* arg1);
void func_80A31B20(EnGe1* arg0, GlobalContext* arg1);
void func_80A31B7C(EnGe1* arg0, GlobalContext* arg1);
void func_80A31BDC(EnGe1* arg0, GlobalContext* arg1);
void func_80A31BE8(EnGe1* arg0, GlobalContext* arg1);
void func_80A31D88(EnGe1* arg0, GlobalContext* arg1);
void func_80A31DE4(EnGe1* arg0, GlobalContext* arg1);
void func_80A31E2C(EnGe1* arg0, GlobalContext* arg1);
void func_80A31F9C(EnGe1* arg0, GlobalContext* arg1);
void func_80A31FE0(EnGe1* arg0, GlobalContext* arg1);
void func_80A32078(EnGe1* arg0, GlobalContext* arg1);
void func_80A32190(EnGe1* arg0, GlobalContext* arg1);
void func_80A323B0(EnGe1* arg0);
void func_80A323EC(EnGe1* arg0);
s32 func_80A32444(GlobalContext* arg0, s32 arg1, Gfx** arg2, Vec3f* arg3, Vec3s* arg4, EnGe1* this);
void func_80A32598(GlobalContext* arg0, s32 arg1, Gfx** arg2, Vec3s* arg3, EnGe1* this);

extern AnimationHeader D_6000228;
extern FlexSkeletonHeader D_6000330;
extern Gfx D_6009198[];
extern Gfx D_6009430[];
extern Gfx D_6009690[];
extern AnimationHeader D_600A048;
extern AnimationHeader D_600A498;

const ActorInit En_Ge1_InitVars = {
    ACTOR_EN_GE1,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GE1,
    sizeof(EnGe1),
    (ActorFunc)EnGe1_Init,
    (ActorFunc)EnGe1_Destroy,
    (ActorFunc)EnGe1_Update,
    (ActorFunc)EnGe1_Draw,
};

static ColliderCylinderInit D_80A32770 = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_ENEMY,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000702, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 20, 40, 0, { 0, 0, 0 } },
};

static u32 D_80A3279C[3] = { (u32)D_6009198, (u32)D_6009430, (u32)D_6009690 };
static Vec3f D_80A327A8 = { 600.0f, 700.0f, 0.0f };
static s32 D_80A327B4[3] = { 0x06000708, 0x06000F08, 0x06001708 };

void EnGe1_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 temp_v0;
    EnGe1* this = (EnGe1*)thisx;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    SkelAnime_InitFlex(globalCtx, &this->unk198, &D_6000330, &D_6000228, this->unk1DC, this->unk23C, 0x10);
    Animation_PlayOnce(&this->unk198, &D_6000228);
    Collider_InitCylinder(globalCtx, &this->unk14C);
    Collider_SetCylinder(globalCtx, &this->unk14C, &this->actor, &D_80A32770);
    this->actor.colChkInfo.mass = 0xFF;
    this->unk2B0 = &D_6000228;
    this->unk2B8 = func_80A323B0;
    this->actor.targetMode = 6;
    Actor_SetScale(&this->actor, 0.01f);
    if (globalCtx->sceneNum == 0x5A) {
        this->actor.uncullZoneForward = 1000.0f;
    } else {
        this->actor.uncullZoneForward = 1200.0f;
    }
    temp_v0 = this->actor.params & 0xFF;
    switch (temp_v0) { /* irregular */
        case 0x0:
            this->unk2AE = 2;
            this->unk2B4 = func_80A31880;
            break;
        case 0x1:
            this->unk2AE = 1;
            if (func_80A30DCC() != 0) {
                this->unk2B4 = func_80A317C0;
            } else {
                this->unk2B4 = func_80A30F48;
            }
            break;
        case 0x4:
            this->unk2AE = 1;
            if (func_80A30DCC() != 0) {
                this->unk2B4 = func_80A31094;
            } else {
                this->unk2B4 = func_80A310C4;
            }
            break;
        case 0x5:
            if (gSaveContext.linkAge == 0) {
                osSyncPrintf("\x1b[36m谷底 ゲルド 撤退 \n\x1b[m");
                Actor_Kill(&this->actor);
                return;
            }
            this->unk2AE = 0;
            this->unk2B4 = func_80A3118C;
            break;
        case 0x45:
            if (gSaveContext.inventory.items[gItemSlots[3]] == 0xFF) {
                Actor_Kill(&this->actor);
                return;
            }
            this->actor.targetMode = 3;
            this->unk2AE = 0;
            osSyncPrintf("\x1b[36mやぶさめ ゲルド EVENT_INF(0) = %x\n\x1b[m", gSaveContext.eventInf[0]);
            if (gSaveContext.eventInf[0] & 0x100) {
                this->unk2B4 = func_80A31E2C;
            } else if (func_80A30DCC() != 0) {
                this->unk2B4 = func_80A31FE0;
            } else {
                this->unk2B4 = func_80A30F48;
            }
            break;
        case 0x46:
            this->unk2AE = 1;
            if (func_80A30DCC() != 0) {
                this->unk2B4 = func_80A31514;
            } else {
                this->unk2B4 = func_80A30F48;
            }
            break;
    }
    this->unk2AC = 0;
}

void EnGe1_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnGe1* this = (EnGe1*)thisx;

    Collider_DestroyCylinder(globalCtx, &this->unk14C);
}

s32 func_80A30C70(EnGe1* arg0, GlobalContext* arg1, u16 arg2, f32 arg3, void (*arg4)(EnGe1*, GlobalContext*)) {
    if (func_8002F194(&arg0->actor, arg1) != 0) {
        arg0->unk2B4 = arg4;
        arg0->unk2B8 = func_80A323EC;
        arg0->unk2AC &= 0xFFFB;
        arg0->unk2B0 = &D_6000228;
        Animation_Change(&arg0->unk198, &D_6000228, 1.0f, 0.0f, (f32)Animation_GetLastFrame(&D_6000228), 2U, -8.0f);
        return 1;
    }
    arg0->actor.textId = arg2;
    if (arg0->actor.xzDistToPlayer < arg3) {
        func_8002F2CC(&arg0->actor, arg1, arg3);
    }
    return 0;
}

void func_80A30D48(EnGe1* arg0) {
    Animation_Change(&arg0->unk198, &D_6000228, -1.0f, (f32)Animation_GetLastFrame(&D_6000228), 0.0f, 2U, 8.0f);
    arg0->unk2B0 = &D_6000228;
    arg0->unk2B8 = func_80A323B0;
}

s32 func_80A30DCC(void) {
    u16 temp_v0;

    temp_v0 = gSaveContext.eventChkInf[9];
    if (!(temp_v0 & 1) || !(temp_v0 & 2) || !(temp_v0 & 4) || !(temp_v0 & 8)) {
        return 0;
    }
    return 1;
}

void func_80A30E08(EnGe1* arg0, GlobalContext* arg1) {
    u8 temp_v0;

    temp_v0 = arg0->unk2AF;
    arg0->unk2AC |= 1;
    if ((s32)temp_v0 > 0) {
        arg0->unk2AF = temp_v0 - 1;
        return;
    }
    func_8006D074(arg1);
    if ((gSaveContext.inventory.items[gItemSlots[0xA]] == 0xFF) ||
        (gSaveContext.inventory.items[gItemSlots[0xB]] == 0xFF)) {
        arg1->nextEntranceIndex = 0x1A5;
    } else if (gSaveContext.eventChkInf[0xC] & 0x80) {
        arg1->nextEntranceIndex = 0x5F8;
    } else {
        arg1->nextEntranceIndex = 0x3B4;
    }
    arg1->fadeTransition = 0x26;
    arg1->sceneLoadFlag = 0x14;
}

void func_80A30EE8(EnGe1* arg0, GlobalContext* arg1) {
    arg0->unk2AF = 0x1E;
    arg0->unk2B4 = func_80A30E08;
    func_8002DF54(arg1, &arg0->actor, 0x5FU);
    func_80078884(0x482CU);
    func_8010B680(arg1, 0x6000U, &arg0->actor);
}

void func_80A30F48(EnGe1* arg0, GlobalContext* arg1) {
    s16 temp_v0;
    s32 var_v1;

    temp_v0 = arg0->actor.yawTowardsPlayer - arg0->actor.shape.rot.y;
    if (temp_v0 >= 0) {
        var_v1 = temp_v0;
    } else {
        var_v1 = -temp_v0;
    }
    if ((var_v1 < 0x4301) && (arg0->actor.xzDistToPlayer < 100.0f)) {
        func_80A30EE8(arg0, arg1);
    }
    if (arg0->unk14C.base.acFlags & 2) {
        func_80A30EE8(arg0, arg1);
    }
    CollisionCheck_SetAC(arg1, &arg1->colChkCtx, &arg0->unk14C.base);
}

void func_80A31000(EnGe1* arg0, GlobalContext* arg1) {
    arg0->unk2AC |= 1;
    if (func_8002F334(&arg0->actor, arg1) != 0) {
        switch (arg0->actor.textId) { /* irregular */
            default:
                arg0->unk2B4 = func_80A3118C;
                return;
            case 0x6001:
                arg0->unk2B4 = func_80A31094;
                return;
            case 0x6019:
            case 0x601A:
                arg0->unk2B4 = func_80A3118C;
                return;
            case 0x6018:
                arg0->unk2B4 = func_80A317C0;
                break;
        }
    }
}

void func_80A31094(EnGe1* arg0, GlobalContext* arg1) {
    func_80A30C70(arg0, arg1, 0x6001U, 100.0f, func_80A31000);
}

void func_80A310C4(EnGe1* arg0, GlobalContext* arg1) {
    s16 temp_v0;
    s32 var_v1;

    temp_v0 = arg0->actor.yawTowardsPlayer - arg0->actor.shape.rot.y;
    if (!(arg0->actor.xzDistToPlayer < 50.0f)) {
        if (temp_v0 >= 0) {
            var_v1 = temp_v0;
        } else {
            var_v1 = -temp_v0;
        }
        if ((var_v1 < 0x4301) && (arg0->actor.xzDistToPlayer < 400.0f)) {
            goto block_5;
        }
    } else {
    block_5:
        func_80A30EE8(arg0, arg1);
    }
    if (arg0->unk14C.base.acFlags & 2) {
        func_80A30EE8(arg0, arg1);
    }
    CollisionCheck_SetAC(arg1, &arg1->colChkCtx, &arg0->unk14C.base);
}

void func_80A3118C(EnGe1* arg0, GlobalContext* arg1) {
    u16 temp_v0;

    temp_v0 = Text_GetFaceReaction(arg1, 0x22U);
    if (temp_v0 == 0) {
        temp_v0 = 0x6019;
    }
    func_80A30C70(arg0, arg1, temp_v0, 100.0f, func_80A31000);
}

void func_80A311E0(EnGe1* arg0, GlobalContext* arg1) {
    u8 temp_v0;

    temp_v0 = arg0->unk2AF;
    if ((s32)temp_v0 > 0) {
        arg0->unk2AF = temp_v0 - 1;
    } else {
        func_80A30D48(arg0);
        arg0->unk2B4 = func_80A31094;
    }
    arg0->unk2AC |= 8;
}

void func_80A31234(EnGe1* arg0, GlobalContext* arg1) {
    if (arg0->unk2AC & 4) {
        arg0->unk2B4 = func_80A311E0;
        Flags_SetSwitch(arg1, ((s16)arg0->actor.params >> 8) & 0x3F);
        arg0->unk2AF = 0x32;
        func_80106CCC(arg1);
        return;
    }
    if ((arg0->unk198.curFrame == 15.0f) || (arg0->unk198.curFrame == 19.0f)) {
        Audio_PlayActorSound2(&arg0->actor, 0x184DU);
    }
}

void func_80A312E4(EnGe1* arg0, GlobalContext* arg1) {
    if ((func_8010BDBC(&arg1->msgCtx) == 5) && (func_80106BC8(arg1) != 0)) {
        arg0->unk2B4 = func_80A31234;
        Animation_Change(&arg0->unk198, &D_600A048, 1.0f, 0.0f, (f32)Animation_GetLastFrame(&D_600A048), 2U, -3.0f);
        arg0->unk2B0 = &D_600A048;
        arg0->unk2B8 = func_80A323EC;
        arg0->unk2AC &= 0xFFFB;
    }
}

void func_80A313A0(EnGe1* arg0, GlobalContext* arg1) {
    if (func_8010BDBC(&arg1->msgCtx) == 2) {
        arg0->unk2B4 = func_80A31514;
        func_80A30D48(arg0);
    }
}

void func_80A313E0(EnGe1* arg0, GlobalContext* arg1) {
    u8 temp_v0;

    arg0->unk2AC |= 1;
    if ((func_8010BDBC(&arg1->msgCtx) == 4) && (func_80106BC8(arg1) != 0)) {
        func_80106CCC(arg1);
        temp_v0 = arg1->msgCtx.choiceIndex;
        switch (temp_v0) { /* irregular */
            case 0:
                if (gSaveContext.rupees < 0xA) {
                    func_8010B720(arg1, 0x6016U);
                    arg0->unk2B4 = func_80A313A0;
                    return;
                }
                Rupees_ChangeBy(-0xA);
                func_8010B720(arg1, 0x6015U);
                arg0->unk2B4 = func_80A312E4;
                return;
            case 1:
                arg0->unk2B4 = func_80A31514;
                func_80A30D48(arg0);
                break;
        }
    }
}

void func_80A314D0(EnGe1* arg0, GlobalContext* arg1) {
    arg0->unk2AC |= 1;
    if (func_8002F334(&arg0->actor, arg1) != 0) {
        arg0->unk2B4 = func_80A31514;
        func_80A30D48(arg0);
    }
}

void func_80A31514(EnGe1* arg0, GlobalContext* arg1) {
    if (gBitFlags[0x16] & gSaveContext.inventory.questItems) {
        func_80A30C70(arg0, arg1, 0x6014U, 100.0f, func_80A313E0);
        return;
    }
    func_80A30C70(arg0, arg1, 0x6013U, 100.0f, func_80A314D0);
}

void func_80A3157C(EnGe1* arg0, GlobalContext* arg1) {
    arg0->unk2AC |= 1;
    if ((func_8010BDBC(&arg1->msgCtx) == 5) && (func_80106BC8(arg1) != 0)) {
        func_80106CCC(arg1);
        arg0->unk2B4 = func_80A317C0;
        func_80A30D48(arg0);
    }
}

void func_80A315F0(EnGe1* arg0, GlobalContext* arg1) {
    u8 temp_v0;

    temp_v0 = arg0->unk2AF;
    if ((s32)temp_v0 > 0) {
        arg0->unk2AF = temp_v0 - 1;
    } else {
        func_80A30D48(arg0);
        arg0->unk2B4 = func_80A317C0;
    }
    arg0->unk2AC |= 8;
}

void func_80A31644(EnGe1* arg0, GlobalContext* arg1) {
    if (arg0->unk2AC & 4) {
        arg0->unk2B4 = func_80A315F0;
        Flags_SetSwitch(arg1, ((s16)arg0->actor.params >> 8) & 0x3F);
        arg0->unk2AF = 0x32;
        func_80106CCC(arg1);
        return;
    }
    if ((arg0->unk198.curFrame == 15.0f) || (arg0->unk198.curFrame == 19.0f)) {
        Audio_PlayActorSound2(&arg0->actor, 0x184DU);
    }
}

void func_80A316F4(EnGe1* arg0, GlobalContext* arg1) {
    arg0->unk2AC |= 1;
    if ((func_8010BDBC(&arg1->msgCtx) == 5) && (func_80106BC8(arg1) != 0)) {
        arg0->unk2B4 = func_80A31644;
        Animation_Change(&arg0->unk198, &D_600A048, 1.0f, 0.0f, (f32)Animation_GetLastFrame(&D_600A048), 2U, -3.0f);
        arg0->unk2B0 = &D_600A048;
        arg0->unk2B8 = func_80A323EC;
        arg0->unk2AC &= 0xFFFB;
    }
}

void func_80A317C0(EnGe1* arg0, GlobalContext* arg1) {
    if (Flags_GetSwitch(arg1, ((s16)arg0->actor.params >> 8) & 0x3F) != 0) {
        func_80A30C70(arg0, arg1, 0x6018U, 100.0f, func_80A3157C);
        return;
    }
    func_80A30C70(arg0, arg1, 0x6017U, 100.0f, func_80A316F4);
}

void func_80A3183C(EnGe1* arg0, GlobalContext* arg1) {
    arg0->unk2AC |= 1;
    if (func_8002F334(&arg0->actor, arg1) != 0) {
        arg0->unk2B4 = func_80A31880;
        func_80A30D48(arg0);
    }
}

void func_80A31880(EnGe1* arg0, GlobalContext* arg1) {
    u16 temp_v0;

    temp_v0 = Text_GetFaceReaction(arg1, 0x22U);
    if (temp_v0 == 0) {
        temp_v0 = 0x6069;
    }
    if (func_80A30C70(arg0, arg1, temp_v0, 100.0f, func_80A3183C) != 0) {
        arg0->unk2B8 = func_80A323B0;
        arg0->unk2B0 = &D_600A498;
        Animation_Change(&arg0->unk198, &D_600A498, 1.0f, 0.0f, (f32)Animation_GetLastFrame(&D_600A498), 2U, -8.0f);
    }
}

void func_80A31934(EnGe1* arg0, GlobalContext* arg1) {
    if (func_8002F334(&arg0->actor, arg1) != 0) {
        arg0->unk2B4 = func_80A31FE0;
        func_80A30D48(arg0);
    }
}

void func_80A3196C(EnGe1* arg0, GlobalContext* arg1) {
    s32 var_a2;

    if (Actor_HasParent(&arg0->actor, arg1) != 0) {
        arg0->unk2B4 = func_80A31934;
        if (arg0->unk2AC & 2) {
            gSaveContext.itemGetInf[0] |= 0x8000;
            return;
        } else {
            gSaveContext.infTable[0x19] |= 1;
        }
        return;
    }
    if (arg0->unk2AC & 2) {
        switch ((s32)(gSaveContext.inventory.upgrades & *gUpgradeMasks) >> *gUpgradeShifts) {
            case 1:
                var_a2 = 0x30;
                break;
            case 2:
                var_a2 = 0x31;
                break;
        }
    } else {
        var_a2 = 0x3E;
    }
    func_8002F434(&arg0->actor, arg1, var_a2, 10000.0f, 50.0f);
}

void func_80A31A5C(EnGe1* arg0, GlobalContext* arg1) {
    s32 var_a2;

    if (func_8002F334(&arg0->actor, arg1) != 0) {
        arg0->actor.flags &= 0xFFFEFFFF;
        arg0->unk2B4 = func_80A3196C;
    }
    if (arg0->unk2AC & 2) {
        switch ((s32)(gSaveContext.inventory.upgrades & *gUpgradeMasks) >> *gUpgradeShifts) {
            case 1:
                var_a2 = 0x30;
                break;
            case 2:
                var_a2 = 0x31;
                break;
        }
    } else {
        var_a2 = 0x3E;
    }
    func_8002F434(&arg0->actor, arg1, var_a2, 10000.0f, 50.0f);
}

void func_80A31B20(EnGe1* arg0, GlobalContext* arg1) {
    if (func_8002F194(&arg0->actor, arg1) != 0) {
        arg0->unk2B4 = func_80A31A5C;
        arg0->actor.flags &= 0xFFFEFFFF;
        return;
    }
    func_8002F2CC(&arg0->actor, arg1, 200.0f);
}

void func_80A31B7C(EnGe1* arg0, GlobalContext* arg1) {
    if ((func_8010BDBC(&arg1->msgCtx) == 5) && (func_80106BC8(arg1) != 0)) {
        func_80106CCC(arg1);
        arg0->unk2B4 = func_80A31FE0;
        func_80A30D48(arg0);
    }
}

void func_80A31BDC(EnGe1* arg0, GlobalContext* arg1) {
}

void func_80A31BE8(EnGe1* arg0, GlobalContext* arg1) {
    Player* sp2C;
    Actor* temp_v0_2;
    u8 temp_v0;

    sp2C = arg1->actorCtx.actorLists[2].head;
    if ((func_8010BDBC(&arg1->msgCtx) == 4) && (func_80106BC8(arg1) != 0)) {
        arg0->actor.flags &= 0xFFFEFFFF;
        temp_v0 = arg1->msgCtx.choiceIndex;
        switch (temp_v0) { /* irregular */
            case 0:
                if (gSaveContext.rupees < 0x14) {
                    func_8010B720(arg1, 0x85U);
                    arg0->unk2B4 = func_80A31B7C;
                    return;
                }
                Rupees_ChangeBy(-0x14);
                arg1->nextEntranceIndex = 0x129;
                gSaveContext.nextCutsceneIndex = 0xFFF0;
                arg1->fadeTransition = 0x26;
                arg1->sceneLoadFlag = 0x14;
                gSaveContext.eventInf[0] |= 0x100;
                gSaveContext.eventChkInf[6] |= 0x100;
                if (!(sp2C->stateFlags1 & 0x800000)) {
                    func_8002DF54(arg1, &arg0->actor, 1U);
                } else {
                    temp_v0_2 = Actor_FindNearby(arg1, sp2C, 0x14, 1U, 1200.0f);
                    sp2C->actor.freezeTimer = 0x4B0;
                    if (temp_v0_2 != NULL) {
                        temp_v0_2->freezeTimer = 0x4B0;
                    }
                }
                arg0->unk2B4 = func_80A31BDC;
                return;
            case 1:
                arg0->unk2B4 = func_80A31FE0;
                func_80106CCC(arg1);
                break;
        }
    }
}

void func_80A31D88(EnGe1* arg0, GlobalContext* arg1) {
    if ((func_8010BDBC(&arg1->msgCtx) == 5) && (func_80106BC8(arg1) != 0)) {
        func_8010B720(arg1, 0x6041U);
        arg0->unk2B4 = func_80A31BE8;
    }
}

void func_80A31DE4(EnGe1* arg0, GlobalContext* arg1) {
    if (func_8002F194(&arg0->actor, arg1) != 0) {
        arg0->unk2B4 = func_80A31D88;
        return;
    }
    func_8002F2CC(&arg0->actor, arg1, 300.0f);
}

void func_80A31E2C(EnGe1* arg0, GlobalContext* arg1) {
    gSaveContext.eventInf[0] &= 0xFEFF;
    LogUtils_LogThreadId("../z_en_ge1.c", 0x456);
    osSyncPrintf("z_common_data.yabusame_total = %d\n", gSaveContext.minigameScore);
    if (1) {}
    if (1) {}
    if (1) {}
    LogUtils_LogThreadId("../z_en_ge1.c", 0x457);
    osSyncPrintf("z_common_data.memory.information.room_inf[127][ 0 ] = %d\n", gSaveContext.highScores[0]);
    arg0->actor.flags |= 0x10000;
    if (gSaveContext.highScores[0] < (s32)gSaveContext.minigameScore) {
        gSaveContext.highScores[0] = (s32)gSaveContext.minigameScore;
    }
    if ((s32)gSaveContext.minigameScore < 0x3E8) {
        arg0->actor.textId = 0x6045;
        arg0->unk2B4 = func_80A31DE4;
        return;
    }
    if (!(gSaveContext.infTable[0x19] & 1)) {
        arg0->actor.textId = 0x6046;
        arg0->unk2B4 = func_80A31B20;
        arg0->unk2AC &= 0xFFFD;
        return;
    }
    if ((s32)gSaveContext.minigameScore < 0x5DC) {
        arg0->actor.textId = 0x6047;
        arg0->unk2B4 = func_80A31DE4;
        return;
    }
    if (gSaveContext.itemGetInf[0] & 0x8000) {
        arg0->actor.textId = 0x6047;
        arg0->unk2B4 = func_80A31DE4;
        return;
    }
    arg0->actor.textId = 0x6044;
    arg0->unk2B4 = func_80A31B20;
    arg0->unk2AC |= 2;
}

void func_80A31F9C(EnGe1* arg0, GlobalContext* arg1) {
    arg0->unk2AC |= 1;
    if (func_8002F334(&arg0->actor, arg1) != 0) {
        arg0->unk2B4 = func_80A31FE0;
        func_80A30D48(arg0);
    }
}

void func_80A31FE0(EnGe1* arg0, GlobalContext* arg1) {
    Player* player = arg1->actorCtx.actorLists[2].head;
    u16 var_a2;

    if (!(player->stateFlags1 & 0x800000)) {
        func_80A30C70(arg0, arg1, 0x603FU, 100.0f, func_80A31F9C);
        return;
    }
    if (gSaveContext.eventChkInf[6] & 0x100) {
        if (gSaveContext.infTable[0x19] & 1) {
            var_a2 = 0x6042;
        } else {
            var_a2 = 0x6043;
        }
    } else {
        var_a2 = 0x6040;
    }
    func_80A30C70(arg0, arg1, var_a2, 200.0f, func_80A31D88);
}

void func_80A32078(EnGe1* arg0, GlobalContext* arg1) {
    s32 pad;
    s16 temp_v0;
    s32 var_v1;

    temp_v0 = arg0->actor.yawTowardsPlayer - arg0->actor.shape.rot.y;
    if (temp_v0 >= 0) {
        var_v1 = temp_v0;
    } else {
        var_v1 = -temp_v0;
    }
    if (var_v1 < 0x4001) {
        Math_SmoothStepToS(&arg0->actor.shape.rot.y, arg0->actor.yawTowardsPlayer, 6, 0xFA0, 0x64);
        arg0->actor.world.rot.y = arg0->actor.shape.rot.y;
        func_80038290(arg1, &arg0->actor, &arg0->unk29C, &arg0->unk2A2, arg0->actor.focus.pos);
        return;
    }
    if (temp_v0 < 0) {
        Math_SmoothStepToS(&arg0->unk29C.y, -0x2000, 6, 0x1838, 0x100);
    } else {
        Math_SmoothStepToS(&arg0->unk29C.y, 0x2000, 6, 0x1838, 0x100);
    }
    Math_SmoothStepToS(&arg0->actor.shape.rot.y, arg0->actor.yawTowardsPlayer, 0xC, 0x3E8, 0x64);
    arg0->actor.world.rot.y = arg0->actor.shape.rot.y;
}

void func_80A32190(EnGe1* arg0, GlobalContext* arg1) {
    s16 temp_v0;
    s32 var_v1;

    temp_v0 = arg0->actor.yawTowardsPlayer - arg0->actor.shape.rot.y;
    if (temp_v0 >= 0) {
        var_v1 = temp_v0;
    } else {
        var_v1 = -temp_v0;
    }
    if ((var_v1 < 0x4301) && (arg0->actor.xzDistToPlayer < 100.0f)) {
        func_80038290(arg1, &arg0->actor, &arg0->unk29C, &arg0->unk2A2, arg0->actor.focus.pos);
        return;
    }
    Math_SmoothStepToS(&arg0->unk29C.x, 0, 6, 0x1838, 0x64);
    Math_SmoothStepToS(&arg0->unk29C.y, 0, 6, 0x1838, 0x64);
}

void EnGe1_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    s16 temp_v0;
    EnGe1* this = (EnGe1*)thisx;

    Collider_UpdateCylinder(&this->actor, &this->unk14C);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->unk14C.base);
    Actor_MoveForward(&this->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &this->actor, 40.0f, 25.0f, 40.0f, 5);
    this->unk2B8(this);
    this->unk2B4(this, globalCtx);
    if (this->unk2AC & 1) {
        func_80A32078(this, globalCtx);
        this->unk2AC &= 0xFFFE;
    } else {
        func_80A32190(this, globalCtx);
    }
    this->unk2A2.z = 0;
    temp_v0 = this->unk2A2.z;
    this->unk2A2.y = temp_v0;
    this->unk2A2.x = temp_v0;
    if (DECR(this->unk2AA) == 0) {
        this->unk2AA = Rand_S16Offset(0x3C, 0x3C);
    }
    this->unk2A8 = this->unk2AA;
    if (this->unk2A8 >= 3) {
        this->unk2A8 = 0;
    }
}

void func_80A323B0(EnGe1* arg0) {
    if (SkelAnime_Update(&arg0->unk198) != 0) {
        Animation_PlayOnce(&arg0->unk198, arg0->unk2B0);
    }
}

void func_80A323EC(EnGe1* arg0) {
    if (!(arg0->unk2AC & 4)) {
        if (SkelAnime_Update(&arg0->unk198) != 0) {
            arg0->unk2AC |= 4;
        }
        arg0->unk2AC |= 8;
    }
}

s32 func_80A32444(GlobalContext* arg0, s32 arg1, Gfx** arg2, Vec3f* arg3, Vec3s* arg4, EnGe1* thisx) {
    EnGe1* this = thisx;
    s32 temp_v1;

    if (arg1 == 0xF) {
        arg4->x += this->unk29C.y;
        arg4->z += this->unk29C.x;
    }
    if (this->unk2AC & 8) {
        this->unk2AC &= 0xFFF7;
        return 0;
    }
    if ((arg1 == 8) || (arg1 == 0xA) || (arg1 == 0xD)) {
        temp_v1 = arg1 * 0x32;
        arg4->y += (Math_SinS((s16)(arg0->state.frames * (temp_v1 + 0x814))) * 200.0f);
        arg4->z += (Math_CosS((s16)(arg0->state.frames * (temp_v1 + 0x940))) * 200.0f);
    }
    return 0;
}

void func_80A32598(GlobalContext* arg0, s32 arg1, Gfx** arg2, Vec3s* arg3, EnGe1* thisx) {
    EnGe1* this = thisx;

    OPEN_DISPS(arg0->state.gfxCtx, "../z_en_ge1.c", 0x58B);
    if (arg1 == 0xF) {
        gSPDisplayList(POLY_OPA_DISP++, D_80A3279C[this->unk2AE]);
        Matrix_MultVec3f(&D_80A327A8, &this->actor.focus.pos);
    }
    CLOSE_DISPS(arg0->state.gfxCtx, "../z_en_ge1.c", 0x593);
}

void EnGe1_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnGe1* this = (EnGe1*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ge1.c", 0x5A2);
    func_800943C8(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 8, SEGMENTED_TO_VIRTUAL(D_80A327B4[this->unk2A8]));
    SkelAnime_DrawFlexOpa(globalCtx, this->unk198.skeleton, this->unk198.jointTable, (s32)this->unk198.dListCount,
                          (s32(*)(GlobalContext*, s32, Gfx**, Vec3f*, Vec3s*, void*))func_80A32444,
                          (void (*)(GlobalContext*, s32, Gfx**, Vec3s*, void*))func_80A32598, this);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ge1.c", 0x5B3);
}
