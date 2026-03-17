#include "z_en_dns.h"

#define FLAGS 0x00000009

#define THIS ((EnDns*)thisx)

void EnDns_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDns_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDns_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDns_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_809EF51C(EnDns* arg0, u8 arg1);
u32 func_809EF5A4(EnDns* arg0);
u32 func_809EF658(EnDns* arg0);
u32 func_809EF70C(EnDns* arg0);
u32 func_809EF73C(EnDns* arg0);
u32 func_809EF800(EnDns* arg0);
u32 func_809EF854(EnDns* arg0);
u32 func_809EF8F4(EnDns* arg0);
u32 func_809EF9A4(EnDns* arg0);
void func_809EF9F8(EnDns* arg0);
void func_809EFA28(EnDns* arg0);
void func_809EFA58(EnDns* arg0);
void func_809EFA9C(EnDns* arg0);
void func_809EFACC(EnDns* arg0);
void func_809EFAFC(EnDns* arg0);
void func_809EFB40(EnDns* arg0);
void func_809EFB84(EnDns*, GlobalContext*);
void func_809EFBC8(EnDns*, GlobalContext*);
void func_809EFC9C(EnDns*, GlobalContext*);
void func_809EFDD0(Actor* arg0, GlobalContext* arg1);
void func_809EFEE8(EnDns*, GlobalContext*);
void func_809EFF50(EnDns*, GlobalContext*);
void func_809EFF98(EnDns*, GlobalContext*);
void func_809F008C(EnDns*, GlobalContext*);
void func_809F0100(EnDns*, GlobalContext*);
void func_809F017C(EnDns*, GlobalContext*);

typedef struct _struct_D_809F0538_0xC {
    /* 0x0 */ GenericAnimationHeader* unk0; /* inferred */
    /* 0x4 */ u8 unk4;                      /* inferred */
    /* 0x5 */ char pad5[3];                 /* maybe part of unk4[4]? */
    /* 0x8 */ f32 unk8;                     /* inferred */
} _struct_D_809F0538_0xC;

extern AnimationHeader D_60009A0;
extern SkeletonHeader D_60041A8;
extern GenericAnimationHeader D_6004404;

const ActorInit En_Dns_InitVars = {
    ACTOR_EN_DNS,
    ACTORTYPE_BG,
    FLAGS,
    OBJECT_SHOPNUTS,
    sizeof(EnDns),
    (ActorFunc)EnDns_Init,
    (ActorFunc)EnDns_Destroy,
    (ActorFunc)EnDns_Update,
    (ActorFunc)EnDns_Draw,
};
static ColliderCylinderSrcAlt D_809F03E0 = {
    { 0xA, 0, 9, 0x39, 1 },
    { 0, { 0, 0, 0 }, { 0xFFCFFFFF, 0, 0 }, 0, 1, 1 },
    { 0x12, 0x20, 0, { 0, 0, 0 } },
};
static u16 D_809F040C[0xC] = {
    0x10A0, 0x10A1, 0x10A2, 0x10CA, 0x10CB, 0x10CC, 0x10CD, 0x10CE, 0x10CF, 0x10DC, 0x10DD, 0,
};
static char* D_809F0424[0xB] = {
    "デクの実売り            ", "デクの棒売り            ", "ハートの欠片売り        ", "デクの種売り            ",
    "デクの盾売り            ", "バクダン売り            ", "矢売り                  ", "赤のくすり売り          ",
    "緑のくすり売り          ", "デクの棒持てる数を増やす", "デクの実持てる数を増やす",
};
static struct_EnDns_2C0ptr D_809F0450 = { 0x14, 0x0005, 0x63, func_809EF5A4, func_809EFA28 };
static struct_EnDns_2C0ptr D_809F0460 = { 0xF, 0x0001, 7, func_809EF658, func_809EF9F8 };
static struct_EnDns_2C0ptr D_809F0470 = { 0xA, 0x0001, 0x3E, func_809EF70C, func_809EFA58 };
static struct_EnDns_2C0ptr D_809F0480 = { 0x28, 0x001E, 0x69, func_809EF73C, func_809EF9F8 };
static struct_EnDns_2C0ptr D_809F0490 = { 0x32, 0x0001, 0x29, func_809EF800, func_809EF9F8 };
static struct_EnDns_2C0ptr D_809F04A0 = { 0x28, 0x0005, 1, func_809EF854, func_809EFA9C };
static struct_EnDns_2C0ptr D_809F04B0 = { 0x46, 0x0014, 0x4B, func_809EF8F4, func_809EFACC };
static struct_EnDns_2C0ptr D_809F04C0 = { 0x28, 0x0001, 0x10, func_809EF9A4, func_809EF9F8 };
static struct_EnDns_2C0ptr D_809F04D0 = { 0x28, 0x0001, 0x11, func_809EF9A4, func_809EF9F8 };
static struct_EnDns_2C0ptr D_809F04E0 = { 0x28, 0x0001, 0x77, func_809EF70C, func_809EFAFC };
static struct_EnDns_2C0ptr D_809F04F0 = { 0x28, 0x0001, 0x79, func_809EF70C, func_809EFB40 };
static struct_EnDns_2C0ptr* D_809F0500[0xB] = {
    &D_809F0450, &D_809F0460, &D_809F0470, &D_809F0480, &D_809F0490, &D_809F04A0,
    &D_809F04B0, &D_809F04C0, &D_809F04D0, &D_809F04E0, &D_809F04F0,
};
static InitChainEntry D_809F052C[3] = {
    ICHAIN_S8(naviEnemyId, 78, ICHAIN_CONTINUE),
    ICHAIN_U8(unk_1F, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(unk_4C, 30, ICHAIN_STOP),
};
static struct _struct_D_809F0538_0xC D_809F0538[3] = {
    { (GenericAnimationHeader*)0x06001108, 0, 0.0f },
    { (GenericAnimationHeader*)0x06004404, 2, 0.0f },
    { (GenericAnimationHeader*)0x060009A0, 2, 0.0f },
};

void EnDns_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDns* this = (EnDns*)thisx;

    if (this->actor.params < 0) {
        osSyncPrintf("\x1b[31m引数エラー（売りナッツ）[ arg_data = %d ]\x1b[m\n", this->actor.params);
        Actor_Kill(&this->actor);
        return;
    }
    if (this->actor.params == 6) {
        if (LINK_AGE_IN_YEARS == 5) {
            this->actor.params = 3;
        }
    }
    osSyncPrintf("\x1b[32m◆◆◆ 売りナッツ『%s』 ◆◆◆\x1b[m\n", D_809F0424[this->actor.params]);
    Actor_ProcessInitChain(&this->actor, D_809F052C);
    SkelAnime_InitSV(globalCtx, &this->unk14C, &D_60041A8, &D_60009A0, &this->unk190, &this->unk1FC, 0x12);
    Collider_InitCylinder(globalCtx, &this->unk26C);
    Collider_LoadCylinderAlt(globalCtx, &this->unk26C, &this->actor, &D_809F03E0);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 35.0f);
    this->actor.textId = D_809F040C[this->actor.params];
    Actor_SetScale(&this->actor, 0.01f);
    this->actor.collideData.mass = 0xFF;
    this->unk2BB = 1;
    this->unk2BC = 1;
    this->unk2BD = 0;
    this->actor.speedXZ = 0.0f;
    this->actor.velocity.y = 0.0f;
    this->actor.gravity = -1.0f;
    this->unk2C0 = D_809F0500[this->actor.params];
    this->unk268 = func_809EFB84;
}

void EnDns_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnDns* this = (EnDns*)thisx;

    Collider_DestroyCylinder(globalCtx, &this->unk26C);
}

void func_809EF51C(EnDns* arg0, u8 arg1) {
    s16 temp_ft0;

    temp_ft0 = SkelAnime_GetFrameCount(D_809F0538[arg1].unk0);
    arg0->unk2BA = arg1;
    SkelAnime_ChangeAnim(&arg0->unk14C, (AnimationHeader*)D_809F0538[arg1].unk0, 1.0f, 0.0f, (f32)temp_ft0,
                         (u8)(s32)D_809F0538[arg1].unk4, D_809F0538[arg1].unk8);
}

u32 func_809EF5A4(EnDns* arg0) {
    if ((CUR_CAPACITY(7) != 0) && (gSaveContext.inventory.ammo[gItemSlots[1]] >= (s32)CUR_CAPACITY(7))) {
        return 1U;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return 0U;
    }
    if (Item_CheckObtainability(1U) == 0xFF) {
        return 2U;
    }
    return 4U;
}

u32 func_809EF658(EnDns* arg0) {
    if ((CUR_CAPACITY(6) != 0) && (gSaveContext.inventory.ammo[*gItemSlots] >= (s32)CUR_CAPACITY(6))) {
        return 1U;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return 0U;
    }
    if (Item_CheckObtainability(0U) == 0xFF) {
        return 2U;
    }
    return 4U;
}

u32 func_809EF70C(EnDns* arg0) {
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return 0U;
    }
    return 4U;
}

u32 func_809EF73C(EnDns* arg0) {
    if (INV_CONTENT(6) == 0xFF) {
        return 3U;
    }
    if (AMMO(6) >= CUR_CAPACITY(5)) {
        return 1U;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return 0U;
    }
    if (Item_CheckObtainability(0x58U) == 0xFF) {
        return 2U;
    }
    return 4U;
}

u32 func_809EF800(EnDns* arg0) {
    if (gBitFlags[4] & gSaveContext.inventory.equipment) {
        return 1U;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return 0U;
    }
    return 4U;
}

u32 func_809EF854(EnDns* arg0) {
    if (!(gBitFlags[0x13] & gSaveContext.inventory.questItems)) {
        return 3U;
    }
    if (gSaveContext.inventory.ammo[gItemSlots[2]] >=
        (s32)gUpgradeCapacities[1][(s32)(gSaveContext.inventory.upgrades & gUpgradeMasks[1]) >> gUpgradeShifts[1]]) {
        return 1U;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return 0U;
    }
    return 4U;
}

u32 func_809EF8F4(EnDns* arg0) {
    if (Item_CheckObtainability(3U) == 0xFF) {
        return 3U;
    }
    if (gSaveContext.inventory.ammo[gItemSlots[3]] >= CUR_CAPACITY(0)) {
        return 1U;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return 0;
    } else {
        return 4;
    }
}

u32 func_809EF9A4(EnDns* arg0) {
    u32 var_v0;

    if (Inventory_HasEmptyBottle() == 0) {
        return 1U;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return 0;
    }
    return 4;
}

void func_809EF9F8(EnDns* arg0) {
    Rupees_ChangeBy((s16)(arg0->unk2C0->unk0 * -1));
}

void func_809EFA28(EnDns* arg0) {
    Rupees_ChangeBy((s16)(arg0->unk2C0->unk0 * -1));
}

void func_809EFA58(EnDns* arg0) {
    gSaveContext.itemGetInf[0] |= 0x800;
    Rupees_ChangeBy((s16)(arg0->unk2C0->unk0 * -1));
}

void func_809EFA9C(EnDns* arg0) {
    Rupees_ChangeBy((s16)(arg0->unk2C0->unk0 * -1));
}

void func_809EFACC(EnDns* arg0) {
    Rupees_ChangeBy((s16)(arg0->unk2C0->unk0 * -1));
}

void func_809EFAFC(EnDns* arg0) {
    gSaveContext.infTable[0x19] |= 4;
    Rupees_ChangeBy((s16)(arg0->unk2C0->unk0 * -1));
}

void func_809EFB40(EnDns* arg0) {
    gSaveContext.infTable[0x19] |= 8;
    Rupees_ChangeBy((s16)(arg0->unk2C0->unk0 * -1));
}

void func_809EFB84(EnDns* arg0, GlobalContext* arg1) {
    if (arg0->unk14C.animCurrentFrame == arg0->unk14C.animFrameCount) {
        arg0->unk268 = func_809EFBC8;
        func_809EF51C(arg0, 0);
    }
}

void func_809EFBC8(EnDns* arg0, GlobalContext* arg1) {
    Math_SmoothScaleMaxMinS(&arg0->actor.shape.rot.y, arg0->actor.yawTowardsLink, 3, 0x7D0, 0);
    arg0->actor.posRot.rot.y = arg0->actor.shape.rot.y;
    if (func_8002F194(&arg0->actor, arg1) != 0) {
        arg0->unk268 = func_809EFC9C;
        return;
    }
    if ((arg0->unk26C.base.ocFlags1 & 2) || (arg0->actor.unk_10C != 0)) {
        arg0->actor.flags |= 0x10000;
    } else {
        arg0->actor.flags &= 0xFFFEFFFF;
    }
    if (arg0->actor.xzDistFromLink < 130.0f) {
        func_8002F2F4(&arg0->actor, arg1);
    }
}

void func_809EFC9C(EnDns* arg0, GlobalContext* arg1) {
    u32 temp_v0_2;
    u8 temp_v0;

    if ((func_8010BDBC(&arg1->msgCtx) == 4) && (func_80106BC8(arg1) != 0)) {
        temp_v0 = arg1->msgCtx.choiceIndex;
        switch (temp_v0) { /* switch 1; irregular */
            case 0:        /* switch 1 */
                temp_v0_2 = arg0->unk2C0->unk8(arg0);
                switch (temp_v0_2) { /* switch 2 */
                    case 0:          /* switch 2 */
                        func_8010B720(arg1, 0x10A5U);
                        arg0->unk268 = func_809F008C;
                        return;
                    case 1: /* switch 2 */
                        func_8010B720(arg1, 0x10A6U);
                        arg0->unk268 = func_809F008C;
                        return;
                    case 3: /* switch 2 */
                        func_8010B720(arg1, 0x10DEU);
                        arg0->unk268 = func_809F008C;
                        return;
                    case 2: /* switch 2 */
                    case 4: /* switch 2 */
                        func_8010B720(arg1, 0x10A7U);
                        arg0->unk268 = func_809EFEE8;
                        return;
                }
                break;
            case 1: /* switch 1 */
                func_8010B720(arg1, 0x10A4U);
                arg0->unk268 = func_809F008C;
                break;
        }
    } else {
        // default:                                        /* switch 2 */
    }
}

void func_809EFDD0(Actor* arg0, GlobalContext* arg1) {
    s16 temp_v0;

    temp_v0 = arg0->params;
    if (temp_v0 == 9) {
        if (((s32)(gSaveContext.inventory.upgrades & gUpgradeMasks[6]) >> gUpgradeShifts[6]) < 2) {
            func_8002F434(arg0, arg1, 0x77, 130.0f, 100.0f);
            return;
        }
        func_8002F434(arg0, arg1, 0x78, 130.0f, 100.0f);
        return;
    }
    if (temp_v0 == 0xA) {
        if (((s32)(gSaveContext.inventory.upgrades & gUpgradeMasks[7]) >> gUpgradeShifts[7]) < 2) {
            func_8002F434(arg0, arg1, 0x79, 130.0f, 100.0f);
            return;
        }
        func_8002F434(arg0, arg1, 0x7A, 130.0f, 100.0f);
        return;
    }
    func_8002F434(arg0, arg1, ((EnDns*)arg0)->unk2C0->unk4, 130.0f, 100.0f);
}

void func_809EFEE8(EnDns* arg0, GlobalContext* arg1) {
    if ((func_8010BDBC(&arg1->msgCtx) == 5) && (func_80106BC8(arg1) != 0)) {
        func_80106CCC(arg1);
        func_809EFDD0(&arg0->actor, arg1);
        arg0->unk268 = func_809EFF50;
    }
}

void func_809EFF50(EnDns* arg0, GlobalContext* arg1) {
    if (Actor_HasParent(&arg0->actor, arg1) != 0) {
        arg0->actor.parent = NULL;
        arg0->unk268 = func_809EFF98;
        return;
    }
    func_809EFDD0(&arg0->actor, arg1);
}

void func_809EFF98(EnDns* arg0, GlobalContext* globalCtx) {
    Player* player = PLAYER;

    if (player->stateFlags1 & 0x400) {
        if ((func_8010BDBC(&globalCtx->msgCtx) == 6) && (func_80106BC8(globalCtx) != 0)) {
            arg0->unk2C0->unkC(arg0);
            arg0->unk2BD = 1;
            arg0->unk2BB = 0;
            arg0->actor.flags &= ~1;
            func_809EF51C(arg0, 1U);
            arg0->unk268 = func_809F0100;
        }
    } else {
        arg0->unk2C0->unkC(arg0);
        arg0->unk2BD = 1;
        arg0->unk2BB = 0;
        arg0->actor.flags &= ~1;
        func_809EF51C(arg0, 1U);
        arg0->unk268 = func_809F0100;
    }
}

void func_809F008C(EnDns* arg0, GlobalContext* arg1) {
    if ((func_8010BDBC(&arg1->msgCtx) == 6) && (func_80106BC8(arg1) != 0)) {
        arg0->unk2BB = 0;
        arg0->actor.flags &= ~1;
        func_809EF51C(arg0, 1U);
        arg0->unk268 = func_809F0100;
    }
}

void func_809F0100(EnDns* arg0, GlobalContext* arg1) {
    f32 f = SkelAnime_GetFrameCount(&D_6004404);

    if (arg0->unk14C.animCurrentFrame == f) {
        Audio_PlayActorSound2(&arg0->actor, 0x3987U);
        arg0->unk268 = func_809F017C;
        arg0->unk2BC = 0;
        arg0->unk2C4 = arg0->actor.posRot.pos.y;
    }
}

void func_809F017C(EnDns* arg0, GlobalContext* arg1) {
    f32 var_fv0;
    Vec3f sp38;
    s32 var_s0;

    var_fv0 = arg0->unk2C4 - arg0->actor.posRot.pos.y;
    if (!(arg0->unk2B8 & 3)) {
        sp38.x = arg0->actor.posRot.pos.x;
        sp38.y = arg0->unk2C4;
        sp38.z = arg0->actor.posRot.pos.z;
        func_80028990(arg1, 20.0f, (Vec3f*)&sp38);
    }
    arg0->actor.shape.rot.y += 0x2000;
    if (var_fv0 > 400.0f) {
        if ((u8)arg0->unk2BD != 0) {
            sp38.x = arg0->actor.posRot.pos.x;
            sp38.y = arg0->unk2C4;
            sp38.z = arg0->actor.posRot.pos.z;
            var_s0 = 0;
            do {
                Item_DropCollectible(arg1, (Vec3f*)&sp38, 3);
                var_s0 += 1;
            } while (var_s0 != 3);
        }
        Actor_Kill(&arg0->actor);
    }
}

void EnDns_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnDns* this = (EnDns*)thisx;
    s32 pad;

    this->unk2B8 += 1;
    this->actor.textId = D_809F040C[this->actor.params];
    Actor_SetHeight(&this->actor, 60.0f);
    Actor_SetScale(&this->actor, 0.01f);
    SkelAnime_FrameUpdateMatrix(&this->unk14C);
    Actor_MoveForward(&this->actor);
    this->unk268(this, globalCtx);
    if (this->unk2BC != 0) {
        func_8002E4B4(globalCtx, &this->actor, 20.0f, 20.0f, 20.0f, 4);
    }
    if (this->unk2BB != 0) {
        Collider_UpdateCylinderShape(&this->actor, &this->unk26C);
        Collider_AddOC(globalCtx, &globalCtx->colliderCtx, &this->unk26C.base);
    }
}

void EnDns_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDns* this = (EnDns*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawSV(globalCtx, this->unk14C.skeleton, this->unk14C.limbDrawTbl, (s32)this->unk14C.dListCount, NULL,
                     NULL, &this->actor);
}
