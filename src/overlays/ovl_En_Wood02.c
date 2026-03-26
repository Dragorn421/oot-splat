/*
 * File: z_en_wood02.c
 * Overlay: ovl_En_Wood02
 * Description: Trees & Bushes
 */

#include "z_en_wood02.h"

#define FLAGS 0x00000000

#define THIS ((EnWood02*)thisx)

void EnWood02_Init(Actor* thisx, GlobalContext* globalCtx);
void EnWood02_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnWood02_Update(Actor* thisx, GlobalContext* globalCtx);
void EnWood02_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 func_80B3AF70(EnWood02* this, GlobalContext* globalCtx, Vec3f* arg2);
void func_80B3B094(EnWood02* this, GlobalContext* globalCtx);

extern Gfx D_6000090[];
extern Gfx D_6000340[];
extern Gfx D_6000440[];
extern Gfx D_6000700[];
extern Gfx D_6007E20[];

const ActorInit En_Wood02_InitVars = {
    ACTOR_EN_WOOD02,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_WOOD02,
    sizeof(EnWood02),
    (ActorFunc)EnWood02_Init,
    (ActorFunc)EnWood02_Destroy,
    (ActorFunc)EnWood02_Update,
    (ActorFunc)EnWood02_Draw,
};
static ColliderCylinderInit D_80B3BF00 = {
    { 0xD, 0, 0xD, 0x39, 0x10, 1 },
    { 5, { 0, 0, 0 }, { 0x0FC0074A, 0, 0 }, 0, 1, 1 },
    { 0x12, 0x3C, 0, { 0, 0, 0 } },
};
static f32 D_80B3BF2C[] = { 707.0f, 525.0f, 510.0f, 500.0f, 566.0f, 141.0f };
static s16 D_80B3BF44[] = { 0x1FFF, 0x4C9E, 0x77F5, 0xA5C9, -0x293D, 0xA000 };
static InitChainEntry D_80B3BF50[] = {
    ICHAIN_F32(unk_4C, 5600, ICHAIN_STOP),
};
static Gfx* D_80B3BF54[7] = {
    (Gfx*)0x060078D0, (Gfx*)0x06007CA0, (Gfx*)0x060080D0, D_6000090, D_6000340, D_6000340, D_6000700,
};
static Gfx* D_80B3BF70[0xC] = {
    (Gfx*)0x06007968, (Gfx*)0x06007D38, (Gfx*)0x060081A8, NULL,      NULL,      NULL, (Gfx*)0x06007AD0,
    D_6007E20,        (Gfx*)0x06008350, (Gfx*)0x06000160, D_6000440, D_6000700,
};
static f32 D_80B3C1D0;
static f32 D_80B3C1D4;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wood02/func_80B3AF70.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wood02/func_80B3B094.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wood02/EnWood02_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wood02/EnWood02_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wood02/EnWood02_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Wood02/EnWood02_Draw.s")
