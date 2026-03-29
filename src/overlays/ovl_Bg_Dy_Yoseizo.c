/*
 * File: z_bg_dy_yoseizo.c
 * Overlay: ovl_Bg_Dy_Yoseizo
 * Description: Great Fairy
 */

#include "z_bg_dy_yoseizo.h"

// TODO remove EnDyExtra struct and use include:
// #include "overlays/actors/ovl_En_Dy_Extra/z_en_dy_extra.h"
struct EnDyExtra;
typedef void (*EnDyExtraActionFunc)(struct EnDyExtra*, GlobalContext*);
typedef struct EnDyExtra {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ EnDyExtraActionFunc actionFunc;
    /* 0x0150 */ s16 type;
    /* 0x0152 */ s16 unk_152;
    /* 0x0154 */ s16 unk_154;
    /* 0x0158 */ f32 unk_158;
    /* 0x015C */ Vec3f unk_15C;
    /* 0x0168 */ Vec3f unk_168;
} EnDyExtra; // size = 0x0174

// TODO remove EnExItem struct and use include:
// #include "overlays/actors/ovl_En_Ex_Item/z_en_ex_item.h"
struct EnExItem;
typedef void (*EnExItemActionFunc)(struct EnExItem* this, GlobalContext* globalCtx);
typedef void (*EnExItemLightFunc)(Actor*, GlobalContext*, s32);
typedef struct EnExItem {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ EnExItemActionFunc actionFunc;
    /* 0x0150 */ s16 getItemObjId;
    /* 0x0152 */ s16 type;
    /* 0x0152 */ s16 unusedParam;
    /* 0x0156 */ s16 drawItemId;
    /* 0x0158 */ s16 stopRotate;
    /* 0x015A */ s16 timer;
    /* 0x015A */ s16 chestKillTimer;
    /* 0x015A */ s16 prizeRotateTimer;
    /* 0x0160 */ s16 killItem;
    /* 0x0164 */ f32 scale;
    /* 0x0168 */ f32 unkFloat; // set to the same value as scale, but unused
    /* 0x016C */ s8 objectIdx;
    /* 0x0170 */ Vec3f initPos; // unused
    /* 0x017C */ EnExItemLightFunc unk_17C;
    /* 0x0180 */ EnExItemLightFunc unk_180;
} EnExItem; // size = 0x0184

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
void func_80874D9C(BgDyYoseizo* this, Vec3f*, Vec3f*, Vec3f*, Color_RGB8*, Color_RGB8*, f32, s32, s32);
void func_80874EAC(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_808751A0(BgDyYoseizo* this, GlobalContext* globalCtx);

extern CutsceneData D_2000130;
extern CutsceneData D_2000160;
extern CutsceneData D_2001020;
extern CutsceneData D_20013E0;
extern CutsceneData D_2001F40;
extern CutsceneData D_20025D0;
extern AnimationHeader D_600092C;
extern AnimationHeader D_6001DF0;
extern AnimationHeader D_60031C0;
extern AnimationHeader D_6004344;
extern AnimationHeader D_6005810;
extern Gfx D_6005860[];
extern Gfx D_60058D8[];
extern AnimationHeader D_6005E60;
extern AnimationHeader D_60069E8;
extern AnimationHeader D_6007CA8;
extern AnimationHeader D_6008698;
extern FlexSkeletonHeader D_601C450;
extern AnimationHeader D_601D514;

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
