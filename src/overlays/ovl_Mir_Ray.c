/*
 * File: z_mir_ray.c
 * Overlay: ovl_Mir_Ray
 * Description: Reflectable Light Beam
 */

#include "z_mir_ray.h"

#define FLAGS 0x00000030

#define THIS ((MirRay*)thisx)

void MirRay_Init(Actor* thisx, GlobalContext* globalCtx);
void MirRay_Destroy(Actor* thisx, GlobalContext* globalCtx);
void MirRay_Update(Actor* thisx, GlobalContext* globalCtx);
void MirRay_Draw(Actor* thisx, GlobalContext* globalCtx);

typedef struct struct_80B8D8A0 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ MtxF unkC;
    /* 0x4C */ void* unk4C;
    /* 0x50 */ u8 unk50;
    /* 0x51 */ char pad51[3]; /* maybe part of unk50[4]? */
} struct_80B8D8A0;            // size = 0x54

void func_80B8D050(MirRay* arg0);
void func_80B8D110(MirRay* arg0, GlobalContext* arg1);
void func_80B8D6F0(MirRay* arg0, GlobalContext* arg1);
void func_80B8D8A0(MirRay* arg0, GlobalContext* arg1, struct_80B8D8A0* arg2);
void func_80B8DA78(struct_80B8D8A0* arg0);
void func_80B8DB7C(MirRay* arg0, GlobalContext* arg1, struct_80B8D8A0* arg2);
s32 func_80B8E404(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6);

extern UNK_TYPE D_060000B0;
extern UNK_TYPE D_06000C50;

const ActorInit Mir_Ray_InitVars = {
    ACTOR_MIR_RAY,
    ACTORTYPE_ITEMACTION,
    FLAGS,
    OBJECT_MIR_RAY,
    sizeof(MirRay),
    (ActorFunc)MirRay_Init,
    (ActorFunc)MirRay_Destroy,
    (ActorFunc)MirRay_Update,
    (ActorFunc)MirRay_Draw,
};

static u8 D_80B8E670 = 0;
static ColliderQuadSrc D_80B8E674 = {
    { 0xA, 9, 0, 0, 0, 3 },
    { 0, { 0x200000, 0, 0 }, { 0xFFCFFFFF, 0, 0 }, 1, 0, 0 },
    {
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
    },
};
static ColliderSpheresElementSrc D_80B8E6C4 = {
    { 0, { 0x200000, 0, 0 }, { 0, 0, 0 }, 1, 0, 0 },
    { 0, { { 0, 0, 0 }, 0x32 }, 0x64 },
};
static ColliderSpheresSrc D_80B8E6E8 = { { 0xA, 9, 0, 0, 0, 0 }, 1, &D_80B8E6C4 };
typedef struct struct_80B8E6F8 {
    /* 0x00 */ Vec3s unk0;
    /* 0x06 */ Vec3s unk6;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ Color_RGB8 unk1C;
    /* 0x1F */ u8 unk1F;
} struct_80B8E6F8;
static struct_80B8E6F8 D_80B8E6F8[0xA] = {
    {
        { -0x488, 0x2AE, -0x370 },
        { -0x398, 0x1E0, -0x379 },
        0x1E,
        0x32,
        1.0f,
        0x32,
        0x96,
        0.8f,
        { 0xFF, 0xFF, 0xFF },
        2,
    },
    {
        { -0x740, 0x444, -0xBE },
        { -0x6A7, 0x349, -0xBA },
        0x1E,
        0x46,
        0.88f,
        0x36,
        0x96,
        0.8f,
        { 0xFF, 0xFF, 0xFF },
        2,
    },
    {
        { 0x557, 0x2E2, -0x35C },
        { 0x443, 0x1DC, -0x35C },
        0x1E,
        0x55,
        0.0f,
        0,
        0x96,
        0.8f,
        { 0xFF, 0xFF, 0xFF },
        0,
    },
    {
        { 0x898, 0x44F, -0xDC },
        { 0x7F8, 0x34B, -0xDC },
        0x1E,
        0x3C,
        0.0f,
        0,
        0x96,
        0.8f,
        { 0xFF, 0xFF, 0xFF },
        1,
    },
    {
        { -0x230, 0x879, -0x136 },
        { -0x230, 0x6CF, -0x136 },
        0x1E,
        0x46,
        0.0f,
        0,
        0x96,
        0.8f,
        { 0xFF, 0xFF, 0xFF },
        0,
    },
    {
        { 0x3C, 0x70A, -0x442 },
        { 0x3C, 0x3CD, -0x442 },
        0x1E,
        0x46,
        0.0f,
        0,
        0x96,
        0.9f,
        { 0xFF, 0xFF, 0xFF },
        0xD,
    },
    {
        { 0x474, 0x1E0, -0x35C },
        { 0x474, 0x1E0, -0x35C },
        0x1E,
        0x1E,
        1.0f,
        0xA,
        0x64,
        0.9f,
        { 0xFF, 0xFF, 0xFF },
        0xE,
    },
    {
        { -0x230, 0x6CF, -0x136 },
        { -0x230, 0x6CF, -0x136 },
        0x1E,
        0x1E,
        0.0f,
        0,
        0x64,
        0.94f,
        { 0xFF, 0xFF, 0xFF },
        0xC,
    },
    {
        { 0x3C, 0x6CF, -0x136 },
        { 0x3C, 0x6CF, -0x136 },
        0x1E,
        0x1E,
        0.0f,
        0,
        0x64,
        0.94f,
        { 0xFF, 0xFF, 0xFF },
        0xC,
    },
    {
        { -0x496, 0x1C0, 0x4AA },
        { -0x496, 0x94, 0x4AA },
        0x32,
        0x64,
        1.0f,
        0x32,
        0x96,
        0.8f,
        { 0xFF, 0xFF, 0xFF },
        3,
    },
};
static InitChainEntry D_80B8E838[] = {
    ICHAIN_VEC3F_DIV1000(scale, 0, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 4000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Mir_Ray/func_80B8D050.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Mir_Ray/func_80B8D110.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Mir_Ray/MirRay_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Mir_Ray/MirRay_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Mir_Ray/MirRay_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Mir_Ray/func_80B8D6F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Mir_Ray/func_80B8D8A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Mir_Ray/func_80B8DA78.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Mir_Ray/func_80B8DB7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Mir_Ray/MirRay_Draw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Mir_Ray/func_80B8E404.s")
