#include "z_en_bom_bowl_man.h"

#define FLAGS 0x08000039

#define THIS ((EnBomBowlMan*)thisx)

void EnBomBowlMan_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBomBowlMan_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBomBowlMan_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBomBowlMan_Draw(Actor* thisx, GlobalContext* globalCtx);

extern AnimationHeader D_6000080;
extern AnimationHeader D_6000710;
extern FlexSkeletonHeader D_6006EB0;
extern AnimationHeader D_60072AC;

const ActorInit En_Bom_Bowl_Man_InitVars = {
    ACTOR_EN_BOM_BOWL_MAN,
    ACTORTYPE_NPC,
    FLAGS,
    OBJECT_BG,
    sizeof(EnBomBowlMan),
    (ActorFunc)EnBomBowlMan_Init,
    (ActorFunc)EnBomBowlMan_Destroy,
    (ActorFunc)EnBomBowlMan_Update,
    (ActorFunc)EnBomBowlMan_Draw,
};

typedef struct struct_809C4A10 {
    f32 unk0;
    f32 unk4;
    s32 unk8; // unused?
} struct_809C4A10;
struct_809C4A10 D_809C4A10[2] = { { 16.0f, 46.0f, 0 }, { 36.0f, 56.0f, 0 } };
f32 D_809C4A28[6] = { 60.0f, -60.0f, -430.0f, 0.0f, -120.0f, -620.0f }; // unused?
f32 D_809C4A40[2] = { 0.01f, 0.03f };
Vec3f D_809C4A48 = { 0.0f, 0.1f, 0.0f };
Vec3f D_809C4A54 = { 0.0f, 0.0f, 0.0f };
Vec3f D_809C4A60[5] = {
    { 0.0f, 22.0f, 0.0f }, { 0.0f, 22.0f, 0.0f }, { 0.0f, 8.0f, 0.0f }, { 0.0f, 9.0f, 0.0f }, { 0.0f, -2.0f, 0.0f },
};
static s16 D_809C4A9C[6] = { 0x4268, 0x4268, -0x3E8, 0, 0x4268, 0 };
static s32 D_809C4AA8[6] = { 0x06004110, 0x06004910, 0x06005110, 0, 0, 0 };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/EnBomBowlMan_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/EnBomBowlMan_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C3820.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C38A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C395C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C39D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C3A54.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C3B50.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C3C7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C3CD4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C3D40.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C3DC4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C4040.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C41FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C4318.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C441C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C4664.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/EnBomBowlMan_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/func_809C48A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Man/EnBomBowlMan_Draw.s")
