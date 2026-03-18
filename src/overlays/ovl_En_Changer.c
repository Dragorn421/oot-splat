#include "z_en_changer.h"

#define FLAGS 0x00000000

#define THIS ((EnChanger*)thisx)

void EnChanger_Init(Actor* thisx, GlobalContext* globalCtx);
void EnChanger_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnChanger_Update(Actor* thisx, GlobalContext* globalCtx);

void func_809D2CCC(EnChanger* this, GlobalContext* globalCtx);
void func_809D2D70(EnChanger* this, GlobalContext* globalCtx);
void func_809D2F74(EnChanger* this, GlobalContext* globalCtx);

const ActorInit En_Changer_InitVars = {
    ACTOR_EN_CHANGER,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnChanger),
    (ActorFunc)EnChanger_Init,
    (ActorFunc)EnChanger_Destroy,
    (ActorFunc)EnChanger_Update,
    NULL,
};
static Vec3f D_809D30A0[6] = {
    { 0.0f, 0.0f, 0.0f },         { -100.0f, 20.0f, -245.0f },  { -100.0f, 20.0f, -685.0f },
    { -100.0f, 20.0f, -1125.0f }, { -100.0f, 20.0f, -1565.0f }, { -100.0f, 20.0f, -2005.0f },
};
static Vec3f D_809D30E8[6] = {
    { 0.0f, 0.0f, 0.0f },        { 140.0f, 20.0f, -245.0f },  { 140.0f, 20.0f, -685.0f },
    { 140.0f, 20.0f, -1125.0f }, { 140.0f, 20.0f, -1565.0f }, { 140.0f, 20.0f, -2005.0f },
};
static s32 D_809D3130[6] = { 0, 0x72, 0x72, 0x73, 0x73, 0x74 };
static s32 D_809D3148[6] = { 0, 8, 8, 9, 9, 0xA };
static s32 D_809D3160[5] = { 0, 2, 4, 6, 8 };
static s32 D_809D3174 = 0xA;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Changer/EnChanger_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Changer/EnChanger_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Changer/func_809D2CCC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Changer/func_809D2D70.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Changer/func_809D2F74.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Changer/EnChanger_Update.s")
