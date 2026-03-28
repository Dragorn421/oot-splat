/*
 * File: z_en_tr.c
 * Overlay: ovl_En_Tr
 * Description: Koume and Kotake
 */

#include "z_en_tr.h"

#define FLAGS 0x00000010

#define THIS ((EnTr*)thisx)

void EnTr_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTr_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnTr_Update(Actor* thisx, GlobalContext* globalCtx);
void EnTr_Draw(Actor* thisx, GlobalContext* globalCtx);

extern AnimationHeader D_6000BFC;
extern AnimationHeader D_60013CC;
extern UNK_TYPE D_6001CDC;
extern AnimationHeader D_60035CC;
extern UNK_TYPE D_6003FC8;
extern AnimationHeader D_60049C8;
extern UNK_TYPE D_600C530;
extern UNK_TYPE D_6011688;

const ActorInit En_Tr_InitVars = {
    ACTOR_EN_TR,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_TR,
    sizeof(EnTr),
    (ActorFunc)EnTr_Init,
    (ActorFunc)EnTr_Destroy,
    (ActorFunc)EnTr_Update,
    (ActorFunc)EnTr_Draw,
};
static UNK_PTR D_80B24360[2] = { &D_6003FC8, &D_6001CDC };
static AnimationHeader* D_80B24368[2] = { (AnimationHeader*)0x06002BC4, &D_6000BFC };
static AnimationHeader* D_80B24370[2] = { &D_60035CC, &D_60013CC };
static AnimationHeader* D_80B24378[2] = { &D_60049C8, &D_60049C8 };
static AnimationHeader* D_80B24380[2] = { (AnimationHeader*)0x06012E1C, (AnimationHeader*)0x06012E1C };
static f32 D_80B24388[7] = { 0.0f, 20.0f, -30.0f, 20.0f, -20.0f, -20.0f, 30.0f };
static f32 D_80B243A4[7] = { 0.0f, 30.0f, 0.0f, -30.0f, 30.0f, -30.0f, 0.0f };
typedef struct _struct_D_80B243C0_0x8 {
    /* 0x0 */ Color_RGBA8 unk0;
    /* 0x4 */ Color_RGBA8 unk4;
} _struct_D_80B243C0_0x8; // size = 0x8
static _struct_D_80B243C0_0x8 D_80B243C0[2] = {
    { { 0xFF, 0xC8, 0, 0xFF }, { 0xFF, 0, 0, 0xFF } },
    { { 0xFF, 0xFF, 0xFF, 0xFF }, { 0, 0, 0xFF, 0xFF } },
};
static s32 D_80B243D0[3] = { 0x060086D8, 0x060094D8, 0x060098D8 };
static Vec3f D_80B243DC = { 2300.0f, 0.0f, -600.0f };
static Vec3f D_80B243E8 = { 0.0f, 0.0f, 0.0f };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B22CF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/EnTr_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/EnTr_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B22E6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B22F1C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B22F28.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B230D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B23254.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B234D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B23690.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B23820.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B238E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B239A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B23A88.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/EnTr_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B23D74.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/EnTr_Draw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B23FDC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B24038.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B24230.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tr/func_80B242B4.s")
