/*
 * File: z_bg_jya_haheniron
 * Overlay: ovl_Bg_Jya_Haheniron
 * Description: Chunks of Iron Knucle Chair and Pillar
 */

#include "z_bg_jya_haheniron.h"

#define FLAGS 0x00000010

#define THIS ((BgJyaHaheniron*)thisx)

void BgJyaHaheniron_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJyaHaheniron_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJyaHaheniron_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJyaHaheniron_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808980C0(BgJyaHaheniron* this, GlobalContext* globalCtx);
void func_80898114(GlobalContext* globalCtx, Vec3f* arg1, Vec3f* arg2);
void func_8089843C(BgJyaHaheniron* this);
void func_8089844C(BgJyaHaheniron* this, GlobalContext* globalCtx);
void func_80898588(BgJyaHaheniron* this);
void func_80898598(BgJyaHaheniron* this, GlobalContext* globalCtx);
void func_8089861C(BgJyaHaheniron* this);
void func_8089862C(BgJyaHaheniron* this, GlobalContext* globalCtx);

extern Gfx D_6000600[];
extern Gfx D_6000880[];

const ActorInit Bg_Jya_Haheniron_InitVars = {
    ACTOR_BG_JYA_HAHENIRON,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_JYA_IRON,
    sizeof(BgJyaHaheniron),
    (ActorFunc)BgJyaHaheniron_Init,
    (ActorFunc)BgJyaHaheniron_Destroy,
    (ActorFunc)BgJyaHaheniron_Update,
    (ActorFunc)BgJyaHaheniron_Draw,
};
static ColliderSpheresElementSrc D_80898740[1] = {
    {
        { 0, { 0xFFCFFFFF, 0, 4 }, { 0, 0, 0 }, 1, 0, 0 },
        { 0, { { 0, 0, 0 }, 0xA }, 0x64 },
    },
};
static ColliderSpheresSrc D_80898764 = { { 0xA, 0x11, 1, 0, 0, 0 }, 1, D_80898740 };
static s16 D_80898774[5] = { 5, 8, 0xB, 0xE, 0x11 };
static InitChainEntry D_80898780[5] = {
    ICHAIN_F32_DIV1000(gravity, -2000, ICHAIN_CONTINUE),  ICHAIN_F32_DIV1000(minVelocityY, -15000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE), ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};
static f32 D_80898794[3] = { 0.13f, 0.1f, 0.1f };
static Vec3f D_808987A0 = { 0.0f, 14.0f, 0.0f };
static Vec3f D_808987AC = { 0.0f, 8.0f, 0.0f };
static Gfx* D_808987B8[6] = { D_6000880, (Gfx*)0x06000AE0, D_6000600, NULL, NULL, NULL };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Haheniron/func_808980C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Haheniron/func_80898114.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Haheniron/BgJyaHaheniron_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Haheniron/BgJyaHaheniron_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Haheniron/func_8089843C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Haheniron/func_8089844C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Haheniron/func_80898588.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Haheniron/func_80898598.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Haheniron/func_8089861C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Haheniron/func_8089862C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Haheniron/BgJyaHaheniron_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Jya_Haheniron/BgJyaHaheniron_Draw.s")
