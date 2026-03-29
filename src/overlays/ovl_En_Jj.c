/*
 * File: z_en_jj.c
 * Overlay: ovl_En_Jj
 * Description: Lord Jabu-Jabu
 */

#include "z_en_jj.h"

#define FLAGS 0x00000030

#define THIS ((EnJj*)thisx)

void EnJj_Init(Actor* thisx, GlobalContext* globalCtx);
void EnJj_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnJj_Update(Actor* thisx, GlobalContext* globalCtx);
void EnJj_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A87800(EnJj* this, void (*arg1)(EnJj*, GlobalContext*));
void func_80A87B1C(EnJj* this);
void func_80A87B9C(EnJj* this, GlobalContext* globalCtx);
void func_80A87BEC(EnJj* this, GlobalContext* globalCtx);
void func_80A87C30(EnJj* this, GlobalContext* globalCtx);
void func_80A87CEC(EnJj* this, GlobalContext* globalCtx);
void func_80A87D94(EnJj* this, GlobalContext* globalCtx);
void func_80A87EF0(EnJj* this, GlobalContext* globalCtx);
void func_80A87F44(EnJj* this, GlobalContext* globalCtx);

extern CollisionHeader D_6000A1C;
extern CollisionHeader D_6001830;
extern AnimationHeader D_6001F4C;
extern FlexSkeletonHeader D_600B9A8;
extern CollisionHeader D_600BA8C;

/*
const ActorInit En_Jj_InitVars = {
    ACTOR_EN_JJ,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_JJ,
    sizeof(EnJj),
    (ActorFunc)EnJj_Init,
    (ActorFunc)EnJj_Destroy,
    (ActorFunc)EnJj_Update,
    (ActorFunc)EnJj_Draw,
};

static ColliderCylinderInit D_80A88CB4 = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000004, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 170, 150, 0, { 0, 0, 0 } },
};
*/

extern CutsceneData D_80A88164[];

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/func_80A87800.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/EnJj_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/EnJj_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/func_80A87B1C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/func_80A87B9C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/func_80A87BEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/func_80A87C30.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/func_80A87CEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/func_80A87D94.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/func_80A87EF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/func_80A87F44.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/EnJj_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Jj/EnJj_Draw.s")
