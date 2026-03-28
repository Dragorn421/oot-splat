#include "z_en_m_thunder.h"

#define FLAGS 0x00000000

#define THIS ((EnMThunder*)thisx)

void EnMThunder_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMThunder_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMThunder_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMThunder_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A9EFE0(EnMThunder* arg0, void (*arg1)(EnMThunder*, GlobalContext*));
void func_80A9F314(GlobalContext* arg0, f32 arg1);
void func_80A9F350(EnMThunder* arg0, GlobalContext* arg1);
void func_80A9F408(EnMThunder* arg0, GlobalContext* arg1);
void func_80A9F938(EnMThunder* arg0, GlobalContext* arg1);
void func_80A9F9B4(EnMThunder* arg0, GlobalContext* arg1);

extern Gfx D_4012570[];
extern Gfx D_4012690[];
extern Gfx D_4012AF0[];
extern Gfx D_4012C10[];
extern Gfx D_4013610[];

const ActorInit En_M_Thunder_InitVars = {
    ACTOR_EN_M_THUNDER,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnMThunder),
    (ActorFunc)EnMThunder_Init,
    (ActorFunc)EnMThunder_Destroy,
    (ActorFunc)EnMThunder_Update,
    (ActorFunc)EnMThunder_Draw,
};

static ColliderCylinderInit D_80AA0420 = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_PLAYER,
        AC_NONE,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK2,
        { 0x00000001, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 200, 200, 0, { 0, 0, 0 } },
};

static u32 D_80AA044C[3] = { 0x01000000, 0x400000, 0x800000 };
static u32 D_80AA0458[3] = { 0x08000000, 0x02000000, 0x04000000 };
static u16 D_80AA0464[4] = { 0x182F, 0x182E, 0x182F, 0x182E };
static f32 D_80AA046C[9] = { 0.1f, 0.15f, 0.2f, 0.25f, 0.3f, 0.25f, 0.2f, 0.15f, 0.0f };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_M_Thunder/func_80A9EFE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_M_Thunder/EnMThunder_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_M_Thunder/EnMThunder_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_M_Thunder/func_80A9F314.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_M_Thunder/func_80A9F350.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_M_Thunder/func_80A9F408.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_M_Thunder/func_80A9F938.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_M_Thunder/func_80A9F9B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_M_Thunder/EnMThunder_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_M_Thunder/EnMThunder_Draw.s")
