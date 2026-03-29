#include "z_bg_spot08_iceblock.h"

#define FLAGS 0x00000000

#define THIS ((BgSpot08Iceblock*)thisx)

void BgSpot08Iceblock_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot08Iceblock_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot08Iceblock_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot08Iceblock_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808B0960(BgSpot08Iceblock* this, void (*arg1)(BgSpot08Iceblock*, GlobalContext*));
void func_808B0968(BgSpot08Iceblock* this, GlobalContext* globalCtx, CollisionHeader* arg2, s32 arg3);
void func_808B09F0(BgSpot08Iceblock* this);
void func_808B0A84(BgSpot08Iceblock* this);
void func_808B0AE0(BgSpot08Iceblock* this);
void func_808B0B8C(BgSpot08Iceblock* this);
void func_808B0BA8(Vec3f* arg0, Vec3f* arg1, f32 arg2);
void func_808B0BD4(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2);
s32 func_808B0C44(Vec3f* arg0, Vec3f* arg1);
void func_808B0CE0(BgSpot08Iceblock* this, GlobalContext* globalCtx);
void func_808B1054(BgSpot08Iceblock* this, GlobalContext* globalCtx);
void func_808B1388(BgSpot08Iceblock* this);
void func_808B13AC(BgSpot08Iceblock* this, GlobalContext* globalCtx);
void func_808B13FC(BgSpot08Iceblock* this);
void func_808B1420(BgSpot08Iceblock* this, GlobalContext* globalCtx);
void func_808B147C(BgSpot08Iceblock* this);
void func_808B14A0(BgSpot08Iceblock* this, GlobalContext* globalCtx);
void func_808B1574(BgSpot08Iceblock* this);

extern Gfx D_6000DE0[];
extern CollisionHeader D_6001904;
extern Gfx D_6002BD0[];
extern CollisionHeader D_6002FD8;

/*
const ActorInit Bg_Spot08_Iceblock_InitVars = {
    ACTOR_BG_SPOT08_ICEBLOCK,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT08_OBJ,
    sizeof(BgSpot08Iceblock),
    (ActorFunc)BgSpot08Iceblock_Init,
    (ActorFunc)BgSpot08Iceblock_Destroy,
    (ActorFunc)BgSpot08Iceblock_Update,
    (ActorFunc)BgSpot08Iceblock_Draw,
};
*/

extern Vec3f D_808B16BC;
extern f32 D_808B16D4[3];
extern f32 D_808B16E0[3];
extern f32 D_808B16EC[3];

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B0960.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B0968.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B09F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B0A84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B0AE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B0B8C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B0BA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B0BD4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B0C44.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B0CE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B1054.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/BgSpot08Iceblock_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/BgSpot08Iceblock_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B1388.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B13AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B13FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B1420.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B147C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B14A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/func_808B1574.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/BgSpot08Iceblock_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Spot08_Iceblock/BgSpot08Iceblock_Draw.s")
