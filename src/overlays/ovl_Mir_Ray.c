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

typedef struct struct_80B8D8A0_4C {
    char pad0[8];
    s16 unk8; // s16?
    s16 unkA; // s16?
    s16 unkC; // s16?
    s16 unkE; // s16?
    char pad10[UNK_SIZE];
} struct_80B8D8A0_4C;

typedef struct struct_80B8D8A0 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ MtxF unkC;
    /* 0x4C */ struct_80B8D8A0_4C* unk4C;
    /* 0x50 */ u8 unk50;
} struct_80B8D8A0; // size = 0x54

s32 func_80B8E404(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5, s16 arg6);

extern UNK_TYPE D_60000B0;
extern UNK_TYPE D_6000C50;

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

static u8 D_80B8E670 = false;
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

void func_80B8D050(MirRay* this) {
    Vec3f vec;
    struct_80B8E6F8* temp_v0;
    ColliderSpheresElement* new_var;

    temp_v0 = &D_80B8E6F8[this->actor.params];
    vec.x = (this->unk288.x - this->unk27C.x) * temp_v0->unk10;
    vec.y = (this->unk288.y - this->unk27C.y) * temp_v0->unk10;
    vec.z = (this->unk288.z - this->unk27C.z) * temp_v0->unk10;
    this->unk14C.elements[0].shape.world.center.x = this->unk27C.x + vec.x;
    this->unk14C.elements[0].shape.world.center.y = this->unk27C.y + vec.y;
    this->unk14C.elements[0].shape.world.center.z = this->unk27C.z + vec.z;
    new_var = &this->unk14C.elements[0];
    new_var->shape.world.radius = temp_v0->unk14 * new_var->shape.unkRadiusScale;
}

void func_80B8D110(MirRay* this, GlobalContext* globalCtx) {
    Player* player;
    struct_80B8E6F8* temp_s1;
    Vec3f sp44;
    Vec3s sp3C;

    player = PLAYER;
    temp_s1 = &D_80B8E6F8[this->actor.params];
    if (func_80B8E404(&this->unk27C, &this->unk288, player->actor.posRot.pos.x, player->actor.posRot.pos.y + 30.0f,
                      player->actor.posRot.pos.z, this->unk294, this->unk296)) {
        if (temp_s1->unk1F & 8) {
            Math_Vec3f_Diff(&player->actor.posRot.pos, &this->unk27C, &sp44);
        } else {
            Math_Vec3f_Diff(&this->unk288, &this->unk27C, &sp44);
        }
        sp3C.x = (temp_s1->unk18 * sp44.x) + this->unk27C.x;
        sp3C.y = (temp_s1->unk18 * sp44.y) + this->unk27C.y;
        sp3C.z = (temp_s1->unk18 * sp44.z) + this->unk27C.z;
        Math_ApproxS(&this->unk298, temp_s1->unk16, 6);
        Lights_PointNoGlowSetInfo(&this->unk2A0, sp3C.x, sp3C.y, sp3C.z, temp_s1->unk1C.r, temp_s1->unk1C.g,
                                  temp_s1->unk1C.b, this->unk298);
    } else {
        Math_ApproxS(&this->unk298, 0, 6);
        Lights_PointSetColorAndRadius(&this->unk2A0, temp_s1->unk1C.r, temp_s1->unk1C.g, temp_s1->unk1C.b,
                                      this->unk298);
    }
}

void MirRay_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    struct_80B8E6F8* temp_s1;
    MirRay* this = (MirRay*)thisx;

    temp_s1 = &D_80B8E6F8[this->actor.params];
    Actor_ProcessInitChain(&this->actor, D_80B8E838);
    ActorShape_Init(&this->actor.shape, 0.0f, NULL, 0.0f);
    osSyncPrintf("反射用 光の発生!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    LogUtils_LogThreadId("../z_mir_ray.c", 0x206);
    osSyncPrintf("this->actor.arg_data = %d\n", this->actor.params);
    if (this->actor.params >= 0xA) {
        LogUtils_LogThreadId("../z_mir_ray.c", 0x209);
        osSyncPrintf("\"反射光 発生失敗\" = %s\n", "反射光 発生失敗");
        Actor_Kill(&this->actor);
    }
    this->unk27C.x = temp_s1->unk0.x;
    this->unk27C.y = temp_s1->unk0.y;
    this->unk27C.z = temp_s1->unk0.z;
    this->unk294 = temp_s1->unkC;
    this->unk288.x = temp_s1->unk6.x;
    this->unk288.y = temp_s1->unk6.y;
    this->unk288.z = temp_s1->unk6.z;
    this->unk296 = temp_s1->unkE;
    Lights_PointNoGlowSetInfo(&this->unk2A0, (s16)(s32)this->unk27C.x, (s16)(s32)this->unk27C.y,
                              (s16)(s32)this->unk27C.z, 0xFFU, 0xFFU, 0xFFU, 0x64);
    this->unk29C = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &this->unk2A0);
    this->unk230[0].x = -536.0f;
    this->unk230[0].y = -939.0f;
    this->unk230[1].x = -1690.0f;
    this->unk230[1].y = 0.0f;
    this->unk230[2].x = -536.0f;
    this->unk230[2].y = 938.0f;
    this->unk230[3].x = 921.0f;
    this->unk230[3].y = 0.0f;
    this->unk230[4].x = 758.0f;
    this->unk230[4].y = 800.0f;
    this->unk230[5].x = 758.0f;
    this->unk230[5].y = -800.0f;
    if (temp_s1->unk1F & 2) {
        Collider_InitSpheres(globalCtx, &this->unk14C);
        Collider_LoadSpheres(globalCtx, &this->unk14C, &this->actor, &D_80B8E6E8, &this->unk16C);
        if (!(temp_s1->unk1F & 4)) {
            func_80B8D050(this);
        }
    }
    Collider_InitQuad(globalCtx, &this->unk1AC);
    Collider_LoadQuad(globalCtx, &this->unk1AC, &this->actor, &D_80B8E674);
    if ((this->actor.params == 5) || (this->actor.params == 7) || (this->actor.params == 8)) {
        this->actor.room = -1;
    }
}

void MirRay_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    MirRay* this = (MirRay*)thisx;

    LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, this->unk29C);
    if (D_80B8E6F8[this->actor.params].unk1F & 2) {
        Collider_DestroySpheres(globalCtx, &this->unk14C);
    }
    Collider_DestroyQuad(globalCtx, &this->unk1AC);
}

void MirRay_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad[2];
    Player* player;
    u8 temp_v0;
    MirRay* this = (MirRay*)thisx;

    player = PLAYER;
    D_80B8E670 = false;
    if (this->unk2AE == 0) {
        temp_v0 = D_80B8E6F8[this->actor.params].unk1F;
        if (temp_v0 & 2) {
            if (temp_v0 & 4) {
                func_80B8D050(this);
            }
            Collider_AddAT(globalCtx, &globalCtx->colliderCtx, &this->unk14C.base);
        }
        if (this->unk22C > 0.0f) {
            Collider_AddAT(globalCtx, &globalCtx->colliderCtx, &this->unk1AC.base);
        }
        func_80B8D110(this, globalCtx);
        if (this->unk22C > 0.0f) {
            func_8002F8F0(&player->actor, NA_SE_IT_SHIELD_BEAM - SFX_FLAG);
        }
    }
}

void func_80B8D6F0(MirRay* this, GlobalContext* globalCtx) {
    Vec3f sp4C;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1_2;
    MtxF* shieldMf;
    Player* player;

    player = PLAYER;
    this->unk22C = 0.0f;
    shieldMf = &player->shieldMf;
    if (func_80B8E404(&this->unk27C, &this->unk288, player->shieldMf.wx, player->shieldMf.wy, player->shieldMf.wz,
                      this->unk294, this->unk296)) {
        temp_fv0 =
            sqrtf((shieldMf->zz * shieldMf->zz) + ((shieldMf->zx * shieldMf->zx) + (shieldMf->zy * shieldMf->zy)));
        if (temp_fv0 == 0.0f) {
            this->unk278 = 1.0f;
        } else {
            this->unk278 = 1.0f / temp_fv0;
        }
        if (D_80B8E6F8[this->actor.params].unk1F & 1) {
            this->unk22C = 1.0f;
        } else {
            sp4C.x = this->unk288.x - this->unk27C.x;
            sp4C.y = this->unk288.y - this->unk27C.y;
            sp4C.z = this->unk288.z - this->unk27C.z;
            sp4C = sp4C; //! FAKE
            temp_fv1_2 = ((-shieldMf->zx * sp4C.x) - (shieldMf->zy * sp4C.y)) - (sp4C.z * shieldMf->zz);
            if (temp_fv1_2 < 0.0f) {
                temp_fv0_2 = sqrtf((sp4C.z * sp4C.z) + ((sp4C.x * sp4C.x) + (sp4C.y * sp4C.y)));
                if ((temp_fv0 != 0.0f) && (temp_fv0_2 != 0.0f)) {
                    this->unk22C = -temp_fv1_2 / (temp_fv0 * temp_fv0_2);
                }
            }
        }
    }
}

void func_80B8D8A0(MirRay* this, GlobalContext* globalCtx, struct_80B8D8A0* arg2) {
    s32 pad[2];
    s32 i;
    Vec3f sp88;
    Vec3f sp7C;
    Player* temp_v0;
    MtxF* temp_s0;
    UNK_TYPE sp70;
    void* sp6C;
    Vec3f sp60;

    temp_v0 = PLAYER;
    temp_s0 = &temp_v0->shieldMf;
    sp60.x = -(temp_s0->zx * this->unk278) * this->unk22C * 400.0f;
    sp60.y = -(temp_s0->zy * this->unk278) * this->unk22C * 400.0f;
    sp60.z = -(temp_s0->zz * this->unk278) * this->unk22C * 400.0f;
    for (i = 0; i < 6; i++) {
        if (!(&sp60) != 0) {} //! FAKE
        //! FAKE (*temp_s0)
        sp88.x = temp_s0->wx + (this->unk230[i].x * temp_s0->xx) + (this->unk230[i].y * (*temp_s0).yx);
        sp88.y = temp_s0->wy + (this->unk230[i].x * temp_s0->xy) + (this->unk230[i].y * (*temp_s0).yy);
        sp88.z = temp_s0->wz + (this->unk230[i].x * temp_s0->xz) + (this->unk230[i].y * (*temp_s0).yz);
        sp7C.x = sp60.x + sp88.x;
        sp7C.y = sp60.y + sp88.y;
        sp7C.z = sp60.z + sp88.z;
        if (func_8003E0B8(&globalCtx->colCtx, &sp88, &sp7C, &sp70, &sp6C, 1) != 0) {
            arg2[i].unk4C = sp6C;
        } else {
            arg2[i].unk4C = NULL;
        }
    }
}

void func_80B8DA78(struct_80B8D8A0* arg0) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        for (j = i + 1; j < 6; j++) {
            if ((arg0[i].unk4C != NULL) && (arg0[j].unk4C != NULL) &&
                (ABS(arg0[i].unk4C->unk8 - arg0[j].unk4C->unk8) < 100) &&
                (ABS(arg0[i].unk4C->unkA - arg0[j].unk4C->unkA) < 100) &&
                (ABS(arg0[i].unk4C->unkC - arg0[j].unk4C->unkC) < 100) &&
                (arg0[i].unk4C->unkE == arg0[j].unk4C->unkE)) {
                arg0[j].unk4C = NULL;
            }
        }
    }
}

void func_80B8DB7C(MirRay* this, GlobalContext* globalCtx, struct_80B8D8A0* arg2) {
    s32 pad[2];
    MtxF* temp_s1;
    Vec3f sp130;
    Vec3f sp124;
    Vec3f sp118;
    Vec3f sp10C;
    Vec3f sp100;
    Vec3f spF4;
    Vec3f spE8;
    Vec3f spDC;
    Player* temp_s3;
    Vec3f spCC;
    Vec3f spC0;
    s32 var_s2;
    struct_80B8D8A0* var_s0;
    float new_var3;
    f32* new_var;
    f32 sp80;
    float new_var2;
    f32 temp_fv0;

    temp_s3 = globalCtx->actorCtx.actorList[2].first;
    temp_s1 = &temp_s3->shieldMf;
    spE8.x = -(temp_s1->zx * this->unk278) * this->unk22C * 400.0f;
    new_var2 = 100.0f;
    spE8.y = -(temp_s1->zy * this->unk278) * this->unk22C * 400.0f;
    spE8.z = -(temp_s1->zz * this->unk278) * this->unk22C * 400.0f;
    sp130.x = temp_s1->wx;
    sp130.y = temp_s1->wy;
    sp130.z = temp_s1->wz;
    sp124.x = spE8.x + sp130.x;
    sp124.y = spE8.y + sp130.y;
    sp124.z = spE8.z + sp130.z;
    spCC.x = (temp_s1->xx * 300.0f) + sp130.x;
    spCC.y = (temp_s1->xy * 300.0f) + sp130.y;
    spCC.z = (temp_s1->xz * 300.0f) + sp130.z;
    spC0.x = (temp_s1->xx * 300.0f) + sp124.x;
    spC0.y = (temp_s1->xy * 300.0f) + sp124.y;
    spC0.z = (temp_s1->xz * 300.0f) + sp124.z;
    func_80062734(&this->unk1AC, &spCC, &sp130, &spC0, &sp124);
    for (var_s2 = 0; var_s2 < 6; var_s2++) {
        new_var = &spDC.x; //! FAKE
        var_s0 = &arg2[var_s2];
        if (var_s0->unk4C != NULL) {
            if (&spE8) {} //! FAKE
            spDC.x = var_s0->unk4C->unk8 * 0.00003051851f;
            spDC.y = var_s0->unk4C->unkA * 0.00003051851f;
            spDC.z = var_s0->unk4C->unkC * 0.00003051851f;
            if (Math3D_LineSegVsPlane(*new_var, spDC.y, spDC.z, var_s0->unk4C->unkE, &sp130, &sp124, &sp118, 1)) {
                var_s0->unk0 = sp118.x;
                var_s0->unk4 = sp118.y;
                var_s0->unk8 = sp118.z;
                temp_fv0 = sqrtf(SQ(sp118.x - sp130.x) + SQ(sp118.y - sp130.y) + SQ(sp118.z - sp130.z));
                if (temp_fv0 < (this->unk22C * 600.0f)) {
                    var_s0->unk50 = 0xC8;
                } else {
                    var_s0->unk50 = (u8)(s32)(800.0f - temp_fv0);
                }
                sp10C.x = (temp_s1->xx * new_var2) + sp130.x;
                sp10C.y = (temp_s1->xy * new_var2) + sp130.y;
                sp10C.z = (temp_s1->xz * 100.0f) + sp130.z;
                sp100.x = (spE8.x * 4.0f) + sp10C.x;
                sp100.y = (spE8.y * 4.0f) + sp10C.y;
                sp100.z = (spE8.z * 4.0f) + sp10C.z;
                var_s0->unkC.xx = var_s0->unkC.yy = var_s0->unkC.zz = var_s0->unkC.ww = 1.0f;

                //! FAKE
                sp80 = var_s0->unkC.wz = 0.0f;
                new_var3 = var_s0->unkC.zx = var_s0->unkC.zy = var_s0->unkC.zw = var_s0->unkC.wx = var_s0->unkC.wy =
                    sp80;
                var_s0->unkC.xy = var_s0->unkC.xz = var_s0->unkC.xw = var_s0->unkC.yx = var_s0->unkC.yz =
                    var_s0->unkC.yw = new_var3;
                if (Math3D_LineSegVsPlane(spDC.x, spDC.y, spDC.z, var_s0->unk4C->unkE, &sp10C, &sp100, &spF4, true)) {
                    do {
                    } while (0); //! FAKE
                    var_s0->unkC.xx = spF4.x - sp118.x;
                    var_s0->unkC.xy = spF4.y - sp118.y;
                    var_s0->unkC.xz = spF4.z - sp118.z;
                }
                sp10C.x = (temp_s1->yx * 100.0f) + sp130.x;
                sp10C.y = (temp_s1->yy * 100.0f) + sp130.y;
                sp10C.z = (temp_s1->yz * 100.0f) + sp130.z;
                sp100.x = (spE8.x * 4.0f) + sp10C.x;
                sp100.y = (spE8.y * 4.0f) + sp10C.y;
                sp100.z = (spE8.z * 4.0f) + sp10C.z;
                if (Math3D_LineSegVsPlane(spDC.x, spDC.y, spDC.z, var_s0->unk4C->unkE, &sp10C, &sp100, &spF4, true)) {
                    if (!sp118.z) {} //! FAKE
                    var_s0->unkC.yx = /*(bitwise f32)spF4*/ spF4.x - /*(bitwise f32)sp118*/ sp118.x;
                    var_s0->unkC.yy = spF4.y - sp118.y;
                    var_s0->unkC.yz = spF4.z - sp118.z;
                }
            } else {
                var_s0->unk4C = NULL;
            }
        }
    }
}

void MirRay_Draw(Actor* thisx, GlobalContext* globalCtx) {
    MirRay* this = (MirRay*)thisx;
    s32 i;
    s32 pad;
    struct_80B8D8A0 sp7C[6];
    Player* player;

    player = PLAYER;
    this->unk22C = 0.0f;
    if (!D_80B8E670 && (this->unk2AE == 0) && (Player_HasMirrorShieldSetToDraw(globalCtx) != 0)) {
        Matrix_Mult(&player->shieldMf, MTXMODE_NEW);
        func_80B8D6F0(this, globalCtx);
        if (!(this->unk22C <= 0.0f)) {
            OPEN_DISPS(globalCtx->state.gfxCtx, "../z_mir_ray.c", 0x3C6);
            func_80093D84(globalCtx->state.gfxCtx);
            Matrix_Scale(1.0f, 1.0f, this->unk22C * 5.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_mir_ray.c", 0x3CC),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x00, 255, 255, 150, (u8)(s32)(this->unk22C * 100.0f));
            gSPDisplayList(POLY_XLU_DISP++, &D_6000C50);
            func_80B8D8A0(this, globalCtx, sp7C);
            func_80B8DA78(sp7C);
            func_80B8DB7C(this, globalCtx, sp7C);
            if (sp7C[0].unk4C == NULL) {
                sp7C[0].unk50 = 0;
            }
            for (i = 1; i < ARRAY_COUNT(sp7C); i++) {
                if (sp7C[i].unk4C != 0) {
                    if ((s32)sp7C[0].unk50 < (s32)sp7C[i].unk50) {
                        sp7C[0].unk50 = sp7C[i].unk50;
                    }
                }
            }
            for (i = 0; i < ARRAY_COUNT(sp7C); i++) {
                if (sp7C[i].unk4C != NULL) {
                    Matrix_Translate(sp7C[i].unk0, sp7C[i].unk4, sp7C[i].unk8, MTXMODE_NEW);
                    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);
                    Matrix_Mult(&sp7C[i].unkC, MTXMODE_APPLY);
                    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_mir_ray.c", 0x3EE),
                              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gDPSetRenderMode(POLY_XLU_DISP++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2);
                    gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x00, 255, 255, 0x96, sp7C[0].unk50);
                    gSPDisplayList(POLY_XLU_DISP++, &D_60000B0);
                }
            }
            D_80B8E670 = true;
            CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_mir_ray.c", 0x403);
        }
    }
}

s32 func_80B8E404(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5, s16 arg6) {
    f32 temp_fv0;
    f32 sp80_x;
    f32 sp7C_y;
    f32 sp78_z;
    Vec3f vec_1minus0;
    f32 temp_fv1_2;
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;

    vec_1minus0.x = arg1->x - arg0->x;
    vec_1minus0.y = arg1->y - arg0->y;
    vec_1minus0.z = arg1->z - arg0->z;
    temp_fv0 = SQ(vec_1minus0.x) + SQ(vec_1minus0.y) + SQ(vec_1minus0.z);
    if (temp_fv0 == 0.0f) {
        return false;
    }
    temp_fv0 =
        (((arg2 - arg0->x) * vec_1minus0.x) + ((arg3 - arg0->y) * vec_1minus0.y) + ((arg4 - arg0->z) * vec_1minus0.z)) /
        temp_fv0;
    sp80_x = (vec_1minus0.x * temp_fv0) + arg0->x;
    sp7C_y = (vec_1minus0.y * temp_fv0) + arg0->y;
    sp78_z = (vec_1minus0.z * temp_fv0) + arg0->z;
    temp_fv1_2 = ((f32)((s16)arg6 - (s16)arg5) * temp_fv0) + (f32)(s16)arg5;
    if ((SQ(sp80_x - arg2) + SQ(sp7C_y - arg3) + SQ(sp78_z - arg4)) <= SQ(temp_fv1_2)) {
        Math_Vec3f_Diff(arg1, arg0, &sp5C);
        sp50.x = arg2 - arg0->x;
        sp50.y = arg3 - arg0->y;
        sp50.z = arg4 - arg0->z;
        if (Math3D_Cos(&sp5C, &sp50) < 0.0f) {
            return false;
        }
        sp44.x = arg2 - arg1->x;
        sp44.y = arg3 - arg1->y;
        sp44.z = arg4 - arg1->z;
        if (Math3D_Cos(&sp5C, &sp44) > 0.0f) {
            return false;
        }
        return true;
    }
    return false;
}
