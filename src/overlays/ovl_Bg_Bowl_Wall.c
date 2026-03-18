/*
 * File: z_bg_bowl_wall.c
 * Overlay: Bg_Bowl_Wall
 * Description: Bombchu Bowling Alley Wall
 */

#include "z_bg_bowl_wall.h"

#define FLAGS 0x00000030

#define THIS ((BgBowlWall*)thisx)

void BgBowlWall_Init(Actor* thisx, GlobalContext* globalCtx);
void BgBowlWall_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgBowlWall_Update(Actor* thisx, GlobalContext* globalCtx);
void BgBowlWall_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8086F260(BgBowlWall* this, GlobalContext* globalCtx);
void func_8086F440(BgBowlWall* this, GlobalContext* globalCtx);
void func_8086F464(BgBowlWall* this, GlobalContext* globalCtx);
void func_8086F718(BgBowlWall* this, GlobalContext* globalCtx);
void func_8086F7F8(BgBowlWall* this, GlobalContext* globalCtx);

extern Gfx D_6000610[];
extern UNK_TYPE D_6000CB8;
extern Gfx D_6001390[];
extern UNK_TYPE D_6001B00;

const ActorInit Bg_Bowl_Wall_InitVars = {
    ACTOR_BG_BOWL_WALL,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_BOWL,
    sizeof(BgBowlWall),
    (ActorFunc)BgBowlWall_Init,
    (ActorFunc)BgBowlWall_Destroy,
    (ActorFunc)BgBowlWall_Update,
    (ActorFunc)BgBowlWall_Draw,
};
Vec3f D_8086FA40[4] = {
    { 0.0f, 210.0f, -20.0f },
    { 0.0f, 170.0f, -20.0f },
    { -170.0f, 0.0f, -20.0f },
    { 170.0f, 0.0f, -20.0f },
};
s16 D_8086FA70[4] = { 0, 0, 0x3FFF, -0x3FFF };
Vec3f D_8086FA78 = { 0.0f, 0.1f, 0.0f };
Vec3f D_8086FA84 = { 0.0f, 0.0f, 0.0f };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/BgBowlWall_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/BgBowlWall_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/func_8086F260.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/func_8086F440.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/func_8086F464.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/func_8086F718.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/func_8086F7F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/BgBowlWall_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/BgBowlWall_Draw.s")
