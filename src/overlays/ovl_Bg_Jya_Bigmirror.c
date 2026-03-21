#include "z_bg_jya_bigmirror.h"

#define FLAGS 0x00000030

#define THIS ((BgJyaBigmirror*)thisx)

void BgJyaBigmirror_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBigmirror_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBigmirror_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBigmirror_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808936E0(BgJyaBigmirror* this, GlobalContext* globalCtx);
void func_80893750(BgJyaBigmirror* this, GlobalContext* globalCtx);
void func_8089394C(BgJyaBigmirror* this, GlobalContext* globalCtx);
void func_8089399C(BgJyaBigmirror* this, GlobalContext* globalCtx);
void func_80893C68(BgJyaBigmirror* this, GlobalContext* globalCtx);

extern Gfx D_600BC70[];
extern Gfx D_600BD80[];
extern Gfx D_600E1B0[];
extern Gfx D_600E2D0[];

static u8 D_80893ED0 = 0;

const ActorInit Bg_Jya_Bigmirror_InitVars = {
    ACTOR_BG_JYA_BIGMIRROR,
    ACTORTYPE_BG,
    FLAGS,
    OBJECT_JYA_OBJ,
    sizeof(BgJyaBigmirror),
    (ActorFunc)BgJyaBigmirror_Init,
    (ActorFunc)BgJyaBigmirror_Destroy,
    (ActorFunc)BgJyaBigmirror_Update,
    (ActorFunc)BgJyaBigmirror_Draw,
};

typedef struct struct_80893EF4 {
    /* 0x00 */ Vec3f unk0;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ char pad12[2];
} struct_80893EF4;
static struct_80893EF4 D_80893EF4[2] = {
    { { -560.0f, 1743.0f, -310.0f }, -0xFF, 0x4000, 0x8000 },
    { { 60.0f, 1743.0f, -310.0f }, -0xFE, 0x8000, 0xA000 },
};
static u8 D_80893F1C[4] = { 1, 2, 0, 0 };
static s16 D_80893F20[4] = { 5, 7, 8, 0 };
static Vec3f D_80893F28[3] = {
    { 60.0f, 1802.0f, -1102.0f },
    { -560.0f, 1800.0f, -310.0f },
    { 60.0f, 1800.0f, -310.0f },
};
static Vec3s D_80893F4C = { 0, 0, 0 };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Bigmirror/func_808936E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Bigmirror/func_80893750.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Bigmirror/func_8089394C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Bigmirror/func_8089399C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Bigmirror/BgJyaBigmirror_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Bigmirror/BgJyaBigmirror_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Bigmirror/BgJyaBigmirror_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Bigmirror/func_80893C68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Bigmirror/BgJyaBigmirror_Draw.s")
