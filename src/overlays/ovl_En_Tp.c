/*
 * File: z_en_tp.c
 * Overlay: ovl_En_Tp
 * Description: Electric Tailpasaran
 */

#include "z_en_tp.h"

#define FLAGS 0x00000000

#define THIS ((EnTp*)thisx)

void EnTp_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTp_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnTp_Update(Actor* thisx, GlobalContext* globalCtx);
void EnTp_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B20DE0(EnTp* this, void (*arg1)(EnTp*, GlobalContext*));
void func_80B21084(EnTp* this);
void func_80B210B0(EnTp* this, GlobalContext* globalCtx);
void func_80B2128C(EnTp* this);
void func_80B212C0(EnTp* this, GlobalContext* globalCtx);
void func_80B21454(EnTp* this);
void func_80B214CC(EnTp* this, GlobalContext* globalCtx);
void func_80B217FC(EnTp* this);
void func_80B21900(EnTp* this, GlobalContext* globalCtx);
void func_80B2194C(EnTp* this);
void func_80B219A8(EnTp* this, GlobalContext* globalCtx);
void func_80B21B90(EnTp* this);
void func_80B21BDC(EnTp* this, GlobalContext* globalCtx);
void func_80B21EE8(EnTp* this);
void func_80B21F18(EnTp* this, GlobalContext* globalCtx);
void func_80B221E8(EnTp* this, GlobalContext* globalCtx);

extern Gfx D_6000000[];
extern Gfx D_60008D0[];
extern UNK_TYPE D_6000C68;

/*
const ActorInit En_Tp_InitVars = {
    ACTOR_EN_TP,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_TP,
    sizeof(EnTp),
    (ActorFunc)EnTp_Init,
    (ActorFunc)EnTp_Destroy,
    (ActorFunc)EnTp_Update,
    (ActorFunc)EnTp_Draw,
};

static ColliderJntSphElementInit D_80B22A90[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x03, 0x08 },
            { 0xFFCFFFFF, 0x01, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 0, { { 0, 0, 0 }, 4 }, 100 },
    },
};

static ColliderJntSphInit D_80B22AB4 = {
    {
        COLTYPE_HIT1,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    D_80B22A90,
};
*/

extern Vec3f D_80B22AE8;
extern Vec3f D_80B22AF4;
extern Vec3f D_80B22B14;
extern Vec3f D_80B22B20;
extern Color_RGBA8 D_80B22B2C;
extern Color_RGBA8 D_80B22B30;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B20DE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/EnTp_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/EnTp_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B21084.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B210B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B2128C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B212C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B21454.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B214CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B217FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B21900.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B2194C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B219A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B21B90.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B21BDC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B21EE8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B21F18.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/func_80B221E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/EnTp_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tp/EnTp_Draw.s")
