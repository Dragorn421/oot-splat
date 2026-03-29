#include "z_bg_haka_huta.h"

#define FLAGS 0x00000010

#define THIS ((BgHakaHuta*)thisx)

void BgHakaHuta_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaHuta_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaHuta_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaHuta_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8087D0AC(BgHakaHuta* this, GlobalContext* globalCtx);
void func_8087D268(BgHakaHuta* this, GlobalContext* globalCtx, s32 arg2);
void func_8087D2F0(BgHakaHuta* this, GlobalContext* globalCtx);
void func_8087D5B8(BgHakaHuta* this, GlobalContext* globalCtx);
void func_8087D66C(BgHakaHuta* this, GlobalContext* globalCtx);
void func_8087D720(BgHakaHuta* this, GlobalContext* globalCtx);
void func_8087D8C0(BgHakaHuta* this, GlobalContext* globalCtx);

extern Gfx D_60006B0[];
extern CollisionHeader D_6000870;

const ActorInit Bg_Haka_Huta_InitVars = {
    ACTOR_BG_HAKA_HUTA,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKACH_OBJECTS,
    sizeof(BgHakaHuta),
    (ActorFunc)BgHakaHuta_Init,
    (ActorFunc)BgHakaHuta_Destroy,
    (ActorFunc)BgHakaHuta_Update,
    (ActorFunc)BgHakaHuta_Draw,
};
static InitChainEntry D_8087D940[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};
static Vec3f D_8087D944 = { 0.0f, 0.0f, 0.0f };
static Color_RGBA8 D_8087D950 = { 30, 20, 50, 255 };
static Color_RGBA8 D_8087D954 = { 0, 0, 0, 255 };
static Vec3f D_8087D958 = { 30.0f, 0.0f, 0.0f };
static Vec3f D_8087D964 = { 0.03258f, 0.3258f, -0.9449f };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Huta/BgHakaHuta_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Huta/BgHakaHuta_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Huta/func_8087D0AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Huta/func_8087D268.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Huta/func_8087D2F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Huta/func_8087D5B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Huta/func_8087D66C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Huta/func_8087D720.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Huta/func_8087D8C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Huta/BgHakaHuta_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Huta/BgHakaHuta_Draw.s")
