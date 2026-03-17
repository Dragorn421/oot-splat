#include "z_en_dns.h"

#define FLAGS 0x00000009

#define THIS ((EnDns*)thisx)

void EnDns_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDns_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDns_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDns_Draw(Actor* thisx, GlobalContext* globalCtx);

u32 func_809EF5A4_8t0(EnDns* arg0);
u32 func_809EF658_8t1(EnDns* arg0);
u32 func_809EF70C_8t2910(EnDns* arg0);
u32 func_809EF73C_8t3(EnDns* arg0);
u32 func_809EF800_8t4(EnDns* arg0);
u32 func_809EF854_8t5(EnDns* arg0);
u32 func_809EF8F4_8t6(EnDns* arg0);
u32 func_809EF9A4_8t78(EnDns* arg0);
void func_809EF9F8_Ct13478(EnDns* arg0);
void func_809EFA28_Ct0(EnDns* arg0);
void func_809EFA58_Ct2(EnDns* arg0);
void func_809EFA9C_Ct5(EnDns* arg0);
void func_809EFACC_Ct6(EnDns* arg0);
void func_809EFAFC_Ct9(EnDns* arg0);
void func_809EFB40_Ct10(EnDns* arg0);
void func_809EFB84(EnDns*, GlobalContext*);
void func_809EFBC8(EnDns*, GlobalContext*);
void func_809EFC9C(EnDns*, GlobalContext*);
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
static u16 D_809F040C[] = {
    0x10A0, // EN_DNS_TYPE_DEKU_NUTS
    0x10A1, // EN_DNS_TYPE_DEKU_STICKS
    0x10A2, // EN_DNS_TYPE_HEART_PIECE
    0x10CA, // EN_DNS_TYPE_DEKU_SEEDS
    0x10CB, // EN_DNS_TYPE_DEKU_SHIELD
    0x10CC, // EN_DNS_TYPE_BOMBS
    0x10CD, // EN_DNS_TYPE_ARROWS
    0x10CE, // EN_DNS_TYPE_RED_POTION
    0x10CF, // EN_DNS_TYPE_GREEN_POTION
    0x10DC, // EN_DNS_TYPE_DEKU_STICKS_CAPACITY
    0x10DD, // EN_DNS_TYPE_DEKU_NUTS_CAPACITY
};
static char* D_809F0424[] = {
    "デクの実売り            ", // EN_DNS_TYPE_DEKU_NUTS
    "デクの棒売り            ", // EN_DNS_TYPE_DEKU_STICKS
    "ハートの欠片売り        ", // EN_DNS_TYPE_HEART_PIECE
    "デクの種売り            ", // EN_DNS_TYPE_DEKU_SEEDS
    "デクの盾売り            ", // EN_DNS_TYPE_DEKU_SHIELD
    "バクダン売り            ", // EN_DNS_TYPE_BOMBS
    "矢売り                  ", // EN_DNS_TYPE_ARROWS
    "赤のくすり売り          ", // EN_DNS_TYPE_RED_POTION
    "緑のくすり売り          ", // EN_DNS_TYPE_GREEN_POTION
    "デクの棒持てる数を増やす", // EN_DNS_TYPE_DEKU_STICKS_CAPACITY
    "デクの実持てる数を増やす", // EN_DNS_TYPE_DEKU_NUTS_CAPACITY
};
static struct_EnDns_2C0ptr D_809F0450_t0_dekunuts = {
    20, 5, GI_NUTS_5_2, func_809EF5A4_8t0, func_809EFA28_Ct0,
};
static struct_EnDns_2C0ptr D_809F0460_t1_dekusticks = {
    15, 1, GI_STICKS_1, func_809EF658_8t1, func_809EF9F8_Ct13478,
};
static struct_EnDns_2C0ptr D_809F0470_t2_heartpiece = {
    10, 1, GI_HEART_PIECE, func_809EF70C_8t2910, func_809EFA58_Ct2,
};
static struct_EnDns_2C0ptr D_809F0480_t3_dekuseeds = {
    40, 30, GI_SEEDS_30, func_809EF73C_8t3, func_809EF9F8_Ct13478,
};
static struct_EnDns_2C0ptr D_809F0490_t4_dekushield = {
    50, 1, GI_SHIELD_DEKU, func_809EF800_8t4, func_809EF9F8_Ct13478,
};
static struct_EnDns_2C0ptr D_809F04A0_t5_bombs = {
    40, 5, GI_BOMBS_5, func_809EF854_8t5, func_809EFA9C_Ct5,
};
static struct_EnDns_2C0ptr D_809F04B0_t6_arrows = {
    70, 20, GI_ARROWS_LARGE, func_809EF8F4_8t6, func_809EFACC_Ct6,
};
static struct_EnDns_2C0ptr D_809F04C0_t7_redpotion = {
    40, 1, GI_POTION_RED, func_809EF9A4_8t78, func_809EF9F8_Ct13478,
};
static struct_EnDns_2C0ptr D_809F04D0_t8_greenpotion = {
    40, 1, GI_POTION_GREEN, func_809EF9A4_8t78, func_809EF9F8_Ct13478,
};
static struct_EnDns_2C0ptr D_809F04E0_t9_stickscapacity = {
    40, 1, GI_STICK_UPGRADE_20, func_809EF70C_8t2910, func_809EFAFC_Ct9,
};
static struct_EnDns_2C0ptr D_809F04F0_t10_nutscapacity = {
    40, 1, GI_NUT_UPGRADE_30, func_809EF70C_8t2910, func_809EFB40_Ct10,
};
static struct_EnDns_2C0ptr* D_809F0500[] = {
    &D_809F0450_t0_dekunuts,       // EN_DNS_TYPE_DEKU_NUTS
    &D_809F0460_t1_dekusticks,     // EN_DNS_TYPE_DEKU_STICKS
    &D_809F0470_t2_heartpiece,     // EN_DNS_TYPE_HEART_PIECE
    &D_809F0480_t3_dekuseeds,      // EN_DNS_TYPE_DEKU_SEEDS
    &D_809F0490_t4_dekushield,     // EN_DNS_TYPE_DEKU_SHIELD
    &D_809F04A0_t5_bombs,          // EN_DNS_TYPE_BOMBS
    &D_809F04B0_t6_arrows,         // EN_DNS_TYPE_ARROWS
    &D_809F04C0_t7_redpotion,      // EN_DNS_TYPE_RED_POTION
    &D_809F04D0_t8_greenpotion,    // EN_DNS_TYPE_GREEN_POTION
    &D_809F04E0_t9_stickscapacity, // EN_DNS_TYPE_DEKU_STICKS_CAPACITY
    &D_809F04F0_t10_nutscapacity,  // EN_DNS_TYPE_DEKU_NUTS_CAPACITY
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
    if ((this->actor.params == EN_DNS_TYPE_ARROWS) && (LINK_AGE_IN_YEARS == 5)) {
        this->actor.params = EN_DNS_TYPE_DEKU_SEEDS;
    }
    osSyncPrintf("\x1b[32m◆◆◆ 売りナッツ『%s』 ◆◆◆\x1b[m\n", D_809F0424[this->actor.params]);
    Actor_ProcessInitChain(&this->actor, D_809F052C);
    SkelAnime_InitSV(globalCtx, &this->unk14C, &D_60041A8, &D_60009A0, this->unk190, this->unk1FC, 0x12);
    Collider_InitCylinder(globalCtx, &this->unk26C);
    Collider_LoadCylinderAlt(globalCtx, &this->unk26C, &this->actor, &D_809F03E0);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 35.0f);
    this->actor.textId = D_809F040C[this->actor.params];
    Actor_SetScale(&this->actor, 0.01f);
    this->actor.collideData.mass = MASS_IMMOVABLE;
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

u32 func_809EF5A4_8t0(EnDns* arg0) {
    if ((CUR_CAPACITY(UPG_NUTS) != 0) && (AMMO(ITEM_NUT) >= (s32)CUR_CAPACITY(UPG_NUTS))) {
        return EN_DNS_UNK8RESULT_1;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return EN_DNS_UNK8RESULT_0;
    }
    if (Item_CheckObtainability(ITEM_NUT) == ITEM_NONE) {
        return EN_DNS_UNK8RESULT_2;
    }
    return EN_DNS_UNK8RESULT_4;
}

u32 func_809EF658_8t1(EnDns* arg0) {
    if ((CUR_CAPACITY(UPG_STICKS) != 0) && (AMMO(ITEM_STICK) >= (s32)CUR_CAPACITY(UPG_STICKS))) {
        return EN_DNS_UNK8RESULT_1;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return EN_DNS_UNK8RESULT_0;
    }
    if (Item_CheckObtainability(ITEM_STICK) == ITEM_NONE) {
        return EN_DNS_UNK8RESULT_2;
    }
    return EN_DNS_UNK8RESULT_4;
}

u32 func_809EF70C_8t2910(EnDns* arg0) {
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return EN_DNS_UNK8RESULT_0;
    }
    return EN_DNS_UNK8RESULT_4;
}

u32 func_809EF73C_8t3(EnDns* arg0) {
    if (INV_CONTENT(ITEM_SLINGSHOT) == ITEM_NONE) {
        return EN_DNS_UNK8RESULT_3;
    }
    if (AMMO(ITEM_SLINGSHOT) >= CUR_CAPACITY(UPG_BULLET_BAG)) {
        return EN_DNS_UNK8RESULT_1;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return EN_DNS_UNK8RESULT_0;
    }
    if (Item_CheckObtainability(ITEM_SEEDS) == ITEM_NONE) {
        return EN_DNS_UNK8RESULT_2;
    }
    return EN_DNS_UNK8RESULT_4;
}

u32 func_809EF800_8t4(EnDns* arg0) {
    if (gBitFlags[4] & gSaveContext.inventory.equipment) {
        return EN_DNS_UNK8RESULT_1;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return EN_DNS_UNK8RESULT_0;
    }
    return EN_DNS_UNK8RESULT_4;
}

u32 func_809EF854_8t5(EnDns* arg0) {
    if (!CHECK_QUEST_ITEM(QUEST_GORON_RUBY)) {
        return EN_DNS_UNK8RESULT_3;
    }
    if (AMMO(ITEM_BOMB) >= CUR_CAPACITY(UPG_BOMB_BAG)) {
        return EN_DNS_UNK8RESULT_1;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return EN_DNS_UNK8RESULT_0;
    }
    return EN_DNS_UNK8RESULT_4;
}

u32 func_809EF8F4_8t6(EnDns* arg0) {
    if (Item_CheckObtainability(ITEM_BOW) == ITEM_NONE) {
        return EN_DNS_UNK8RESULT_3;
    }
    if (AMMO(ITEM_BOW) >= CUR_CAPACITY(UPG_QUIVER)) {
        return EN_DNS_UNK8RESULT_1;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return EN_DNS_UNK8RESULT_0;
    }
    return EN_DNS_UNK8RESULT_4;
}

u32 func_809EF9A4_8t78(EnDns* arg0) {
    if (!Inventory_HasEmptyBottle()) {
        return EN_DNS_UNK8RESULT_1;
    }
    if (gSaveContext.rupees < arg0->unk2C0->unk0) {
        return EN_DNS_UNK8RESULT_0;
    }
    return EN_DNS_UNK8RESULT_4;
}

void func_809EF9F8_Ct13478(EnDns* arg0) {
    Rupees_ChangeBy(-arg0->unk2C0->unk0);
}

void func_809EFA28_Ct0(EnDns* arg0) {
    Rupees_ChangeBy(-arg0->unk2C0->unk0);
}

void func_809EFA58_Ct2(EnDns* arg0) {
    gSaveContext.itemGetInf[0] |= 0x800;
    Rupees_ChangeBy(-arg0->unk2C0->unk0);
}

void func_809EFA9C_Ct5(EnDns* arg0) {
    Rupees_ChangeBy(-arg0->unk2C0->unk0);
}

void func_809EFACC_Ct6(EnDns* arg0) {
    Rupees_ChangeBy(-arg0->unk2C0->unk0);
}

void func_809EFAFC_Ct9(EnDns* arg0) {
    gSaveContext.infTable[0x19] |= 4;
    Rupees_ChangeBy(-arg0->unk2C0->unk0);
}

void func_809EFB40_Ct10(EnDns* arg0) {
    gSaveContext.infTable[0x19] |= 8;
    Rupees_ChangeBy(-arg0->unk2C0->unk0);
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
    } else {
        if ((arg0->unk26C.base.ocFlags1 & 2) || (arg0->actor.unk_10C != 0)) {
            arg0->actor.flags |= 0x10000;
        } else {
            arg0->actor.flags &= ~0x10000;
        }
        if (arg0->actor.xzDistFromLink < 130.0f) {
            func_8002F2F4(&arg0->actor, arg1);
        }
    }
}

void func_809EFC9C(EnDns* arg0, GlobalContext* arg1) {
    if ((func_8010BDBC(&arg1->msgCtx) == 4) && (func_80106BC8(arg1) != 0)) {
        switch (arg1->msgCtx.choiceIndex) {
            case 0:
                switch (arg0->unk2C0->unk8(arg0)) {
                    case EN_DNS_UNK8RESULT_0:
                        func_8010B720(arg1, 0x10A5);
                        arg0->unk268 = func_809F008C;
                        return;
                    case EN_DNS_UNK8RESULT_1:
                        func_8010B720(arg1, 0x10A6);
                        arg0->unk268 = func_809F008C;
                        return;
                    case EN_DNS_UNK8RESULT_3:
                        func_8010B720(arg1, 0x10DE);
                        arg0->unk268 = func_809F008C;
                        return;
                    case EN_DNS_UNK8RESULT_2:
                    case EN_DNS_UNK8RESULT_4:
                        func_8010B720(arg1, 0x10A7);
                        arg0->unk268 = func_809EFEE8;
                        return;
                }
                break;
            case 1:
                func_8010B720(arg1, 0x10A4);
                arg0->unk268 = func_809F008C;
                break;
        }
    }
}

void func_809EFDD0(EnDns* arg0, GlobalContext* arg1) {
    if (arg0->actor.params == EN_DNS_TYPE_DEKU_STICKS_CAPACITY) {
        if (CUR_UPG_VALUE(UPG_STICKS) < 2) {
            func_8002F434(&arg0->actor, arg1, GI_STICK_UPGRADE_20, 130.0f, 100.0f);
        } else {
            func_8002F434(&arg0->actor, arg1, GI_STICK_UPGRADE_30, 130.0f, 100.0f);
        }
    } else if (arg0->actor.params == EN_DNS_TYPE_DEKU_NUTS_CAPACITY) {
        if (CUR_UPG_VALUE(UPG_NUTS) < 2) {
            func_8002F434(&arg0->actor, arg1, GI_NUT_UPGRADE_30, 130.0f, 100.0f);
        } else {
            func_8002F434(&arg0->actor, arg1, GI_NUT_UPGRADE_40, 130.0f, 100.0f);
        }
    } else {
        func_8002F434(&arg0->actor, arg1, arg0->unk2C0->unk4_gid, 130.0f, 100.0f);
    }
}

void func_809EFEE8(EnDns* arg0, GlobalContext* arg1) {
    if ((func_8010BDBC(&arg1->msgCtx) == 5) && (func_80106BC8(arg1) != 0)) {
        func_80106CCC(arg1);
        func_809EFDD0(arg0, arg1);
        arg0->unk268 = func_809EFF50;
    }
}

void func_809EFF50(EnDns* arg0, GlobalContext* arg1) {
    if (Actor_HasParent(&arg0->actor, arg1) != 0) {
        arg0->actor.parent = NULL;
        arg0->unk268 = func_809EFF98;
    } else {
        func_809EFDD0(arg0, arg1);
    }
}

void func_809EFF98(EnDns* arg0, GlobalContext* globalCtx) {
    Player* player = PLAYER;

    if (player->stateFlags1 & 0x400) {
        if ((func_8010BDBC(&globalCtx->msgCtx) == 6) && (func_80106BC8(globalCtx) != 0)) {
            arg0->unk2C0->unkC(arg0);
            arg0->unk2BD = 1;
            arg0->unk2BB = 0;
            arg0->actor.flags &= ~1;
            func_809EF51C(arg0, 1);
            arg0->unk268 = func_809F0100;
        }
    } else {
        arg0->unk2C0->unkC(arg0);
        arg0->unk2BD = 1;
        arg0->unk2BB = 0;
        arg0->actor.flags &= ~1;
        func_809EF51C(arg0, 1);
        arg0->unk268 = func_809F0100;
    }
}

void func_809F008C(EnDns* arg0, GlobalContext* arg1) {
    if ((func_8010BDBC(&arg1->msgCtx) == 6) && (func_80106BC8(arg1) != 0)) {
        arg0->unk2BB = 0;
        arg0->actor.flags &= ~1;
        func_809EF51C(arg0, 1);
        arg0->unk268 = func_809F0100;
    }
}

void func_809F0100(EnDns* arg0, GlobalContext* arg1) {
    f32 f = SkelAnime_GetFrameCount(&D_6004404);

    if (arg0->unk14C.animCurrentFrame == f) {
        Audio_PlayActorSound2(&arg0->actor, NA_SE_EN_AKINDONUTS_HIDE);
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
    if ((arg0->unk2B8 % 4) == 0) {
        sp38.x = arg0->actor.posRot.pos.x;
        sp38.y = arg0->unk2C4;
        sp38.z = arg0->actor.posRot.pos.z;
        func_80028990(arg1, 20.0f, &sp38);
    }
    arg0->actor.shape.rot.y += 0x2000;
    if (var_fv0 > 400.0f) {
        if (arg0->unk2BD != 0) {
            sp38.x = arg0->actor.posRot.pos.x;
            sp38.y = arg0->unk2C4;
            sp38.z = arg0->actor.posRot.pos.z;
            for (var_s0 = 0; var_s0 < 3; var_s0++) {
                Item_DropCollectible(arg1, &sp38, 3);
            }
        }
        Actor_Kill(&arg0->actor);
    }
}

void EnDns_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnDns* this = (EnDns*)thisx;
    s32 pad;

    this->unk2B8++;
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
    SkelAnime_DrawSV(globalCtx, this->unk14C.skeleton, this->unk14C.limbDrawTbl, this->unk14C.dListCount, NULL, NULL,
                     &this->actor);
}
