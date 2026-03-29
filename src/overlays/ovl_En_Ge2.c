#include "z_en_ge2.h"

#define FLAGS 0x00000019

#define THIS ((EnGe2*)thisx)

void EnGe2_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGe2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGe2_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGe2_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A32BD0(EnGe2* this, s32 arg1);
s32 func_80A32ECC(GlobalContext* globalCtx, EnGe2* this);
s32 func_80A32F74(GlobalContext* globalCtx, EnGe2* this, Vec3f* arg2, s16 arg3, f32 arg4);
s32 func_80A330A0(void);
void func_80A330CC(EnGe2* this, GlobalContext* globalCtx);
void func_80A331A0(EnGe2* this, GlobalContext* globalCtx);
void func_80A332D4(EnGe2* this, GlobalContext* globalCtx);
void func_80A3334C(EnGe2* this, GlobalContext* globalCtx);
void func_80A33444(EnGe2* this, GlobalContext* globalCtx);
void func_80A3354C(EnGe2* this, GlobalContext* globalCtx);
void func_80A33600(EnGe2* this, GlobalContext* globalCtx);
void func_80A336C4(EnGe2* this, GlobalContext* globalCtx);
void func_80A33704(EnGe2* this, GlobalContext* globalCtx);
void func_80A3381C(EnGe2* this, GlobalContext* globalCtx);
void func_80A33930(EnGe2* this, GlobalContext* globalCtx);
void func_80A339EC(EnGe2* this, GlobalContext* globalCtx);
void func_80A33A0C(EnGe2* this, GlobalContext* globalCtx);
void func_80A33A6C(EnGe2* this, GlobalContext* globalCtx);
void func_80A33AFC(EnGe2* this, GlobalContext* globalCtx);
void func_80A33B7C(EnGe2* this, GlobalContext* globalCtx);
void func_80A33BE8(EnGe2* this, GlobalContext* globalCtx);
void func_80A33C8C(EnGe2* this, GlobalContext* globalCtx);
void func_80A33D10(Actor* thisx, GlobalContext* globalCtx);
void func_80A33DE0(Actor* thisx, GlobalContext* globalCtx);
void func_80A3402C(Actor* thisx, GlobalContext* globalCtx);
s32 func_80A3415C(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3f* arg3, Vec3s* arg4, EnGe2* this);
void func_80A341A0(GlobalContext* globalCtx, s32 arg1, Gfx** arg2, Vec3s* arg3, EnGe2* this);

extern FlexSkeletonHeader D_6008968;
extern AnimationHeader D_6009ED4;

const ActorInit En_Ge2_InitVars = {
    ACTOR_EN_GE2,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GLA,
    sizeof(EnGe2),
    (ActorFunc)EnGe2_Init,
    (ActorFunc)EnGe2_Destroy,
    (ActorFunc)EnGe2_Update,
    (ActorFunc)EnGe2_Draw,
};

static ColliderCylinderInit D_80A34310 = {
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
        { 0x000007A2, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 20, 60, 0, { 0, 0, 0 } },
};

static void (*D_80A3433C[9])(EnGe2*, GlobalContext*) = {
    func_80A33600, func_80A3354C, func_80A33444, func_80A3334C, func_80A332D4,
    func_80A331A0, func_80A330CC, func_80A336C4, func_80A339EC,
};
static AnimationHeader* D_80A34360[9] = {
    &D_6009ED4,
    (AnimationHeader*)0x060098AC,
    (AnimationHeader*)0x060098AC,
    (AnimationHeader*)0x060011F4,
    (AnimationHeader*)0x060098AC,
    (AnimationHeader*)0x06008D60,
    (AnimationHeader*)0x060098AC,
    (AnimationHeader*)0x060098AC,
    (AnimationHeader*)0x060098AC,
};
static u8 D_80A34384[0xC] = { 0, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0 };
static Vec3f D_80A34390 = { 0.0f, -0.05f, 0.0f };
static Vec3f D_80A3439C = { 0.0f, -0.025f, 0.0f };
static Color_RGBA8 D_80A343A8 = { 0xFF, 0xFF, 0xFF, 0 };
static Color_RGBA8 D_80A343AC = { 0xFF, 0x96, 0, 0 };
static Vec3f D_80A343B0 = { 600.0f, 700.0f, 0.0f };
static s32 D_80A343BC[5] = { 0x06004F78, 0x06005578, 0x06005BF8, 0, 0 };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A32BD0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/EnGe2_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/EnGe2_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A32ECC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A32F74.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A330A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A330CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A331A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A332D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A3334C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A33444.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A3354C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A33600.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A336C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A33704.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A3381C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A33930.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A339EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A33A0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A33A6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A33AFC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A33B7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A33BE8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A33C8C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A33D10.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A33DE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/EnGe2_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A3402C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A3415C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/func_80A341A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Ge2/EnGe2_Draw.s")
