#include "z_en_kusa.h"

#define FLAGS 0x00800010

#define THIS ((EnKusa*)thisx)

void EnKusa_Init(Actor* thisx, GlobalContext* globalCtx);
void EnKusa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnKusa_Update(Actor* thisx, GlobalContext* globalCtx);

void func_80A9AFA0(EnKusa* this, EnKusaActionFunc actionFunc);
s32 func_80A9AFAC(EnKusa* this, GlobalContext* globalCtx, f32 arg2);
void func_80A9B07C(EnKusa* this, GlobalContext* globalCtx);
void func_80A9B140(EnKusa* this);
void func_80A9B174(Vec3f* arg0, f32 arg1);
void func_80A9B1FC(EnKusa* this);
void func_80A9B21C(EnKusa* this, GlobalContext* globalCtx);
void func_80A9B574(EnKusa* this, GlobalContext* globalCtx);
void func_80A9B630(EnKusa* this, GlobalContext* globalCtx);
void func_80A9B7EC(EnKusa* this);
void func_80A9B810(EnKusa* this, GlobalContext* globalCtx);
void func_80A9B89C(EnKusa* this);
void func_80A9B8D8(EnKusa* this, GlobalContext* globalCtx);
void func_80A9BA98(EnKusa* this);
void func_80A9BAD8(EnKusa* this, GlobalContext* globalCtx);
void func_80A9BBB0(EnKusa* this);
void func_80A9BC1C(EnKusa* this, GlobalContext* globalCtx);
void func_80A9BEAC(EnKusa* this);
void func_80A9BEFC(EnKusa* this, GlobalContext* globalCtx);
void func_80A9BF30(EnKusa* this, GlobalContext* globalCtx);
void func_80A9BF3C(EnKusa* this);
void func_80A9BFA8(EnKusa* this, GlobalContext* globalCtx);
void func_80A9C00C(EnKusa* this);
void func_80A9C068(EnKusa* this, GlobalContext* globalCtx);
void func_80A9C164(Actor* thisx, GlobalContext* globalCtx);

extern Gfx D_40355E0[];
extern Gfx D_40356A0[];
extern Gfx D_6000140[];
extern Gfx D_60002E0[];

extern Vec3f D_80A9C23C[4];

static s16 D_80A9C1D0 = 0;
static s16 D_80A9C1D4 = 0;
static s16 D_80A9C1D8 = 0;
static s16 D_80A9C1DC = 0;
const ActorInit En_Kusa_InitVars = {
    ACTOR_EN_KUSA,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnKusa),
    (ActorFunc)EnKusa_Init,
    (ActorFunc)EnKusa_Destroy,
    (ActorFunc)EnKusa_Update,
    NULL,
};
static s16 D_80A9C200[4] = { 2, 0x12B, 0x12B, 0 };
static ColliderCylinderSrc D_80A9C208 = {
    { 0xA, 0, 9, 0x29, 0x20, 1 },
    { 0, { 0, 0, 0 }, { 0x4FC00758, 0, 0 }, 0, 1, 1 },
    { 0xC, 0x2C, 0, { 0, 0, 0 } },
};
static CollideDataInit D_80A9C234 = { 0, 0xC, 0x1E, 0xFF };
Vec3f D_80A9C23C[4] = {
    { 0.0f, 0.7071f, 0.7071f },
    { 0.7071f, 0.7071f, 0.0f },
    { 0.0f, 0.7071f, -0.7071f },
    { -0.7071f, 0.7071f, 0.0f },
};
static s16 D_80A9C26C[8] = { 0x6C, 0x66, 0x60, 0x54, 0x42, 0x37, 0x2A, 0x26 };
static InitChainEntry D_80A9C27C[6] = {
    ICHAIN_VEC3F_DIV1000(scale, 400, ICHAIN_CONTINUE),         ICHAIN_F32_DIV1000(gravity, -3200, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(minVelocityY, -17000, ICHAIN_CONTINUE), ICHAIN_F32(uncullZoneForward, 1200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 100, ICHAIN_CONTINUE),         ICHAIN_F32(uncullZoneDownward, 120, ICHAIN_STOP)
};
static Gfx* D_80A9C294[3] = { (Gfx*)0x0500B9D0, D_6000140, D_6000140 };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9AFA0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9AFAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9B07C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9B140.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9B174.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9B1FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9B21C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9B574.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9B630.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/EnKusa_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/EnKusa_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9B7EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9B810.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9B89C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9B8D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9BA98.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9BAD8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9BBB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9BC1C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9BEAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9BEFC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9BF30.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9BF3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9BFA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9C00C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9C068.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/EnKusa_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kusa/func_80A9C164.s")
