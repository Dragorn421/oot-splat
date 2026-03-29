/*
 * File: z_bg_dy_yoseizo.c
 * Overlay: ovl_Bg_Dy_Yoseizo
 * Description: Great Fairy
 */

#include "z_bg_dy_yoseizo.h"

#define FLAGS 0x02000030

#define THIS ((BgDyYoseizo*)thisx)

void BgDyYoseizo_Init(Actor* thisx, GlobalContext* globalCtx);
void BgDyYoseizo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgDyYoseizo_Update(Actor* thisx, GlobalContext* globalCtx);

void func_80872960(BgDyYoseizo* this, GlobalContext* globalCtx, s16 arg2);
void func_80872C58(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80872D20(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80872DE4(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_8087328C(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873380(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_808734DC(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_8087358C(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_808736A4(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873780(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873868(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873B3C(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873C14(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873D14(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873E04(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873EA4(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873FD8(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80874304(BgDyYoseizo* this, GlobalContext* globalCtx);
s32 func_80874B7C(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, BgDyYoseizo* this);
void func_80874BE0(BgDyYoseizo* this, GlobalContext* globalCtx);
// func_80874D9C
void func_80874EAC(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_808751A0(BgDyYoseizo* this, GlobalContext* globalCtx);

extern UNK_TYPE D_02000130;
extern UNK_TYPE D_02000160;
extern UNK_TYPE D_02001020;
extern UNK_TYPE D_020013E0;
extern UNK_TYPE D_02001F40;
extern UNK_TYPE D_020025D0;
extern UNK_TYPE D_0600092C;
extern UNK_TYPE D_06001DF0;
extern UNK_TYPE D_060031C0;
extern UNK_TYPE D_06004344;
extern UNK_TYPE D_06005810;
extern UNK_TYPE D_06005860;
extern UNK_TYPE D_06005868;
extern UNK_TYPE D_060058D8;
extern UNK_TYPE D_06005E60;
extern UNK_TYPE D_060069E8;
extern UNK_TYPE D_06007CA8;
extern UNK_TYPE D_06008698;
extern UNK_TYPE D_0601C450;
extern UNK_TYPE D_0601D514;

static s32 D_80875440[3] = { 0x5D, 0x5E, 0x5C };
const ActorInit Bg_Dy_Yoseizo_InitVars = {
    ACTOR_BG_DY_YOSEIZO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DY_OBJ,
    sizeof(BgDyYoseizo),
    (ActorFunc)BgDyYoseizo_Init,
    (ActorFunc)BgDyYoseizo_Destroy,
    (ActorFunc)BgDyYoseizo_Update,
    NULL,
};
static Color_RGB8 D_8087546C[9] = {
    { 0xFF, 0xFF, 0xFF }, { 0xFF, 0xFF, 0x64 }, { 0x64, 0xFF, 0x64 }, { 0xFF, 0x64, 0x64 }, { 0xFF, 0xFF, 0xAA },
    { 0xFF, 0xFF, 0x64 }, { 0x64, 0xFF, 0x64 }, { 0xFF, 0x64, 0x64 }, { 0xFF, 0xFF, 0xAA },
};
static Color_RGB8 D_80875488[9] = {
    { 0x9B, 0xFF, 0xFF }, { 0xFF, 0xFF, 0x64 }, { 0x64, 0xFF, 0x64 }, { 0xFF, 0x64, 0x64 }, { 0xFF, 0x64, 0xFF },
    { 0xFF, 0xFF, 0x64 }, { 0x64, 0xFF, 0x64 }, { 0xFF, 0x64, 0x64 }, { 0x64, 0xFF, 0xFF },
};
static Vec3f D_808754A4 = { 0.0f, 0.0f, 0.0f };
static s16 D_808754B0[4] = { 2, 0, 1, 0 };
static s16 D_808754B8[4] = { 0x11, 0x10, 0x12, 0 };
static s16 D_808754C0[4] = { 0x100, 0x200, 0x400, 0 };
static u8 D_808754C8[4] = { 0xD, 5, 0x13, 0 };
static s32 D_808754CC[3] = { 0x06017930, 0x06018130, 0x06018930 };
static s32 D_808754D8[2] = { 0x06019130, 0x0601A130 };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/BgDyYoseizo_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/BgDyYoseizo_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80872960.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80872C58.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80872D20.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80872DE4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_8087328C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80873380.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_808734DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_8087358C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_808736A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80873780.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80873868.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80873B3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80873C14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80873D14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80873E04.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80873EA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80873FD8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80874304.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/BgDyYoseizo_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80874B7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80874BE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80874D9C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_80874EAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Dy_Yoseizo/func_808751A0.s")
