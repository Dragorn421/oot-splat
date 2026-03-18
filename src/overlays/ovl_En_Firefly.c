#include "z_en_firefly.h"

#define FLAGS 0x00005005

#define THIS ((EnFirefly*)thisx)

void EnFirefly_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFirefly_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFirefly_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFirefly_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A13070(EnFirefly* arg0);
void func_80A13098(EnFirefly* arg0);
void func_80A132F4(EnFirefly* arg0);
void func_80A133A0(EnFirefly* arg0);
void func_80A13444(EnFirefly* arg0);
void func_80A13464(EnFirefly* arg0);
void func_80A1349C(EnFirefly* arg0);
void func_80A1350C(EnFirefly* arg0);
void func_80A13538(EnFirefly* arg0);
void func_80A135A8(EnFirefly* arg0, GlobalContext* arg1);
void func_80A13744(EnFirefly* arg0);
void func_80A13764(EnFirefly* arg0);
s32 func_80A1379C(EnFirefly* arg0, GlobalContext* arg1);
s32 func_80A138B8(EnFirefly* arg0, GlobalContext* arg1);
void func_80A13A08(EnFirefly* arg0, GlobalContext* arg1);
void func_80A13C98(EnFirefly* arg0, GlobalContext* arg1);
void func_80A13D68(EnFirefly* arg0, GlobalContext* arg1);
void func_80A13DE4(EnFirefly* arg0, GlobalContext* arg1);
void func_80A13FF4(EnFirefly* arg0, GlobalContext* arg1);
void func_80A14088(EnFirefly* arg0, GlobalContext* arg1);
void func_80A141F0(EnFirefly* arg0, GlobalContext* arg1);
void func_80A14294(EnFirefly* arg0, GlobalContext* arg1);
void func_80A142F4(EnFirefly* arg0, GlobalContext* arg1);
void func_80A143B4(EnFirefly* arg0, GlobalContext* arg1);
void func_80A1448C(EnFirefly* arg0, GlobalContext* arg1);
void func_80A1450C(EnFirefly* arg0, GlobalContext* arg1);
s32 func_80A14960(GlobalContext* arg0, s32 arg1, Gfx** arg2, Vec3f* arg3, Vec3s* arg5, EnFirefly* this, Gfx** gfx);
void func_80A149B4(GlobalContext* arg0, s32 arg1, Gfx** arg2, Vec3s* arg3, EnFirefly* this, Gfx** arg5);
void func_80A14E28(Actor*, GlobalContext*);

extern AnimationHeader D_600017C;
extern Gfx D_6001678[];
extern SkeletonHeader D_60018B8;

const ActorInit En_Firefly_InitVars = {
    ACTOR_EN_FIREFLY,
    ACTORTYPE_ENEMY,
    FLAGS,
    OBJECT_FIREFLY,
    sizeof(EnFirefly),
    (ActorFunc)EnFirefly_Init,
    (ActorFunc)EnFirefly_Destroy,
    (ActorFunc)EnFirefly_Update,
    (ActorFunc)EnFirefly_Draw,
};
static ColliderSpheresElementSrc D_80A14F30 = {
    { 0, { 0xFFCFFFFF, 1, 8 }, { 0xFFCFFFFF, 0, 0 }, 9, 1, 1 },
    { 1, { { 0, 0x3E8, 0 }, 0xF }, 0x64 },
};
static ColliderSpheresSrc D_80A14F54 = { { 3, 0x11, 9, 0x39, 0x10, 0 }, 1, &D_80A14F30 };
static CollideDataInit D_80A14F64 = { 1, 0xA, 0xA, 0x1E };
static ActorDamageChart D_80A14F6C = {
    {
        { 0x10 }, { 2 },    { 1 }, { 2 }, { 1 }, { 2 }, { 2 },    { 2 },    { 1 }, { 2 }, { 4 },
        { 0xF2 }, { 0x34 }, { 2 }, { 2 }, { 2 }, { 2 }, { 0x20 }, { 0x34 }, { 0 }, { 0 }, { 0 },
        { 1 },    { 4 },    { 2 }, { 2 }, { 8 }, { 4 }, { 0 },    { 0 },    { 4 }, { 0 },
    },
};
static InitChainEntry D_80A14F8C[5] = {
    ICHAIN_VEC3F_DIV1000(scale, 5, ICHAIN_CONTINUE), ICHAIN_F32_DIV1000(gravity, -500, ICHAIN_CONTINUE),
    ICHAIN_F32(minVelocityY, -4, ICHAIN_CONTINUE),   ICHAIN_U8(unk_1F, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(unk_4C, 4000, ICHAIN_STOP),
};
static Color_RGBA8 D_80A14FA0 = { 0xFF, 0xFF, 0x64, 0xFF };
static Color_RGBA8 D_80A14FA4 = { 0xFF, 0x32, 0, 0 };
static Color_RGBA8 D_80A14FA8 = { 0x64, 0xC8, 0xFF, 0xFF };
static Color_RGBA8 D_80A14FAC = { 0, 0, 0xFF, 0 };
static Vec3f D_80A14FB0 = { 0.0f, 0.5f, 0.0f };
static Vec3f D_80A14FBC = { 0.0f, 0.5f, 0.0f };
static Vec3f D_80A14FC8 = { 0.0f, 0.0f, 0.0f };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A13070.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A13098.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/EnFirefly_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/EnFirefly_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A132F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A133A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A13444.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A13464.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A1349C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A1350C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A13538.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A135A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A13744.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A13764.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A1379C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A138B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A13A08.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A13C98.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A13D68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A13DE4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A13FF4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A14088.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A141F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A14294.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A142F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A143B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A1448C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A1450C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/EnFirefly_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A14960.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A149B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/EnFirefly_Draw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Firefly/func_80A14E28.s")
