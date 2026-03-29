/*
 * File: z_obj_tsubo.c
 * Overlay: ovl_Obj_Tsubo
 * Description: Breakable pot
 */

#include "z_obj_tsubo.h"

#define FLAGS 0x00800010

#define THIS ((ObjTsubo*)thisx)

void ObjTsubo_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjTsubo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjTsubo_Update(Actor* thisx, GlobalContext* globalCtx);

void func_80BA0D60(ObjTsubo* this, GlobalContext* globalCtx);
void func_80BA0DC0(ObjTsubo* this, GlobalContext* globalCtx);
s32 func_80BA0DF4(ObjTsubo* this, GlobalContext* globalCtx);
void func_80BA0E98(ObjTsubo* this, GlobalContext* globalCtx);
void func_80BA100C(ObjTsubo* this, GlobalContext* globalCtx);
void func_80BA1294(ObjTsubo* this, GlobalContext* globalCtx);
void func_80BA152C(ObjTsubo* this);
void func_80BA153C(ObjTsubo* this, GlobalContext* globalCtx);
void func_80BA15AC(ObjTsubo* this);
void func_80BA15BC(ObjTsubo* this, GlobalContext* globalCtx);
void func_80BA17C4(ObjTsubo* this);
void func_80BA180C(ObjTsubo* this, GlobalContext* globalCtx);
void func_80BA188C(ObjTsubo* this);
void func_80BA1958(ObjTsubo* this, GlobalContext* globalCtx);
void func_80BA1B0C(ObjTsubo* this, GlobalContext* globalCtx);

extern Gfx D_5017870[];
extern Gfx D_5017A60[];
extern Gfx D_60017C0[];
extern Gfx D_6001960[];

/*
const ActorInit Obj_Tsubo_InitVars = {
    ACTOR_OBJ_TSUBO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjTsubo),
    (ActorFunc)ObjTsubo_Init,
    (ActorFunc)ObjTsubo_Destroy,
    (ActorFunc)ObjTsubo_Update,
    NULL,
};

static ColliderCylinderInit D_80BA1B94 = {
    {
        COLTYPE_HARD,
        AT_ON | AT_TYPE_PLAYER,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000002, 0x00, 0x01 },
        { 0x4FC1FFFE, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 9, 26, 0, { 0, 0, 0 } },
};
*/

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA0D60.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA0DC0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA0DF4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA0E98.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/ObjTsubo_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/ObjTsubo_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA100C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA1294.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA152C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA153C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA15AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA15BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA17C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA180C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA188C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA1958.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/ObjTsubo_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tsubo/func_80BA1B0C.s")
