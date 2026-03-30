#include "z_en_fish.h"
// #include "objects/gameplay_keep/gameplay_keep.h"

#define FLAGS 0x00000000

#define THIS ((EnFish*)thisx)

void EnFish_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFish_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFish_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFish_Draw(Actor* thisx, GlobalContext* globalCtx);

f32 func_80A15280(Vec3f* arg0, Vec3f* arg1);
void func_80A152AC(EnFish* this);
void func_80A15310(EnFish* this);
void func_80A15374(EnFish* this);
void func_80A153AC(EnFish* this);
void func_80A15444(EnFish* this);
void func_80A155D0(EnFish* this);
s32 func_80A15688(EnFish* this, GlobalContext* globalCtx);
s16 func_80A15774(EnFish* this, GlobalContext* globalCtx);
void func_80A157A4(EnFish* this);
void func_80A157FC(EnFish* this, GlobalContext* globalCtx);
void func_80A158EC(EnFish* this);
void func_80A15944(EnFish* this, GlobalContext* globalCtx);
void func_80A15AD4(EnFish* this);
void func_80A15B2C(EnFish* this, GlobalContext* globalCtx);
void func_80A15D18(EnFish* this);
void func_80A15D68(EnFish* this, GlobalContext* globalCtx);
void func_80A15F24(EnFish* this);
void func_80A15F84(EnFish* this, GlobalContext* globalCtx);
void func_80A160BC(EnFish* this);
void func_80A16200(EnFish* this, GlobalContext* globalCtx);
void func_80A163DC(EnFish* this);
void func_80A16450(EnFish* this, GlobalContext* globalCtx);
void func_80A16618(EnFish* this);
void func_80A16670(EnFish* this, GlobalContext* globalCtx);
void func_80A16898(EnFish* this, GlobalContext* globalCtx);
void func_80A169C8(EnFish* this, GlobalContext* globalCtx);
void func_80A16A64(EnFish* this, GlobalContext* globalCtx);
void func_80A16C68(EnFish* this, GlobalContext* globalCtx);
void func_80A16DEC(EnFish* this, GlobalContext* globalCtx);

extern AnimationHeader D_40185FC;
extern FlexSkeletonHeader D_4018FE0;
extern AnimationHeader D_401909C;

static EnFish* D_80A17010 = NULL;
static f32 D_80A17014 = 0.0f;
static f32 D_80A17018 = 0.0f;

static ColliderJntSphElementInit D_80A1701C[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 5 }, 100 },
    },
};

static ColliderJntSphInit D_80A17040 = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    D_80A1701C,
};

const ActorInit En_Fish_InitVars = {
    ACTOR_EN_FISH,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnFish),
    (ActorFunc)EnFish_Init,
    (ActorFunc)EnFish_Destroy,
    (ActorFunc)EnFish_Update,
    (ActorFunc)EnFish_Draw,
};

static InitChainEntry D_80A17070[4] = {
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 900, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 40, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 700, ICHAIN_STOP),
};

typedef struct struct_80A17080 {
    /* 0x0 */ f32 unk0;
    /* 0x4 */ f32 unk4;
    /* 0x8 */ f32 unk8;
} struct_80A17080; // size = 0xC
static struct_80A17080 D_80A17080 = { 0.0f, 0.04f, 0.09f };
static struct_80A17080 D_80A1708C = { 0.5f, 0.1f, 0.15f };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15280.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A152AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15310.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15374.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A153AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15444.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/EnFish_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/EnFish_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A155D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15688.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15774.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A157A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A157FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A158EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15944.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15AD4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15B2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15D18.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15D68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15F24.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A15F84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A160BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A16200.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A163DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A16450.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A16618.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A16670.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A16898.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A169C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A16A64.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A16C68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/func_80A16DEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/EnFish_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Fish/EnFish_Draw.s")
