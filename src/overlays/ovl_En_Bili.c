#include "z_en_bili.h"

#define FLAGS 0x00005005

#define THIS ((EnBili*)thisx)

void EnBili_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBili_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBili_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBili_Draw(Actor* thisx, GlobalContext* globalCtx);

extern UNK_TYPE D_06000024;
extern UNK_TYPE D_06000064;
extern UNK_TYPE D_060000A4;
extern UNK_TYPE D_6004408;
extern UNK_TYPE D_06005848;

const ActorInit En_Bili_InitVars = {
    ACTOR_EN_BILI,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_BL,
    sizeof(EnBili),
    (ActorFunc)EnBili_Init,
    (ActorFunc)EnBili_Destroy,
    (ActorFunc)EnBili_Update,
    (ActorFunc)EnBili_Draw,
};

static ColliderCylinderInit D_809C1640 = {
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
        { 0xFFCFFFFF, 0x03, 0x08 },
        { 0xFFCFFFFF, 0x01, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 9, 28, -20, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 D_809C166C = { 1, 9, 0x1C, -0x14, 0x1E };
static DamageTable D_809C1678 = {
    {
        0x10, 2,    0xE0, 2, 1, 2, 2, 2, 0xF1, 0xF2, 0xF4, 0x24, 0x34, 2, 2, 2,
        2,    0x24, 0x34, 0, 0, 0, 1, 4, 2,    2,    8,    4,    0,    0, 4, 0,
    },
};
static InitChainEntry D_809C1698[] = {
    ICHAIN_S8(naviEnemyId, 23, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_STOP),
};
static Color_RGBA8 D_809C16A0 = { 0xFF, 0xFF, 0xFF, 0xFF };
static Color_RGBA8 D_809C16A4 = { 0xC8, 0xFF, 0xFF, 0xFF };
static Vec3f D_809C16A8 = { 0.0f, 0.0f, 0.0f };
static Vec3f D_809C16B4 = { 0.0f, 0.0f, 0.0f };
static Vec3f D_809C16C0 = { 1.0f, 1.0f, 1.0f };
static s32 D_809C16CC[9] = {
    0x06000E08, 0x06001708, 0x06002008, 0x06002908, 0x06003208, 0x06003B08, (s32)&D_6004408, 0x06004D08, 0,
};
static Gfx D_809C16F0[] = {
    gsDPSetCombineLERP(1, TEXEL0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, COMBINED, 0, PRIMITIVE, 0, TEXEL1, 0,
                       PRIM_LOD_FRAC, COMBINED),
    gsSPEndDisplayList(),
};
static Gfx D_809C1700[] = {
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, COMBINED, 0, PRIMITIVE, 0, TEXEL1, 0,
                       PRIM_LOD_FRAC, COMBINED),
    gsSPEndDisplayList(),
};

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/EnBili_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/EnBili_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809BF9BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809BFA14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809BFA8C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809BFAE8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809BFB40.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809BFB5C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809BFBC4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809BFC48.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809BFCE8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809BFD18.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809BFD94.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809BFF6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C008C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C0174.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C0260.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C02B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C04B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C0570.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C0600.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C067C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C06E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C0754.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C0980.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C09E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C0A70.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/EnBili_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C0E08.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C1020.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C1240.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/func_809C13A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bili/EnBili_Draw.s")
