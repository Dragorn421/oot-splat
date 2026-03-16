#include "global.h"
#include "z_bg_hidan_rsekizou.h"

void BgHidanRsekizou_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHidanRsekizou_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHidanRsekizou_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHidanRsekizou_Draw(Actor* thisx, GlobalContext* globalCtx);

extern Gfx D_600AD00[];
extern UNK_TYPE D_600D5C0;
extern Gfx D_600DC30[];
extern ColliderSpheresSrc D_8088CD58;
extern InitChainEntry D_8088CD68;
extern s32 D_8088CD74[];

void BgHidanRsekizou_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanRsekizou* this = (BgHidanRsekizou*)thisx;
    s32 i;
    s32 pad;
    s32 sp30;

    sp30 = 0;
    Actor_ProcessInitChain(&this->dyna.actor, &D_8088CD68);
    DynaPolyInfo_SetActorMove((DynaPolyActor*)this, DPM_UNK);
    DynaPolyInfo_Alloc(&D_600D5C0, &sp30);
    this->dyna.dynaPolyId = DynaPolyInfo_RegisterActor(globalCtx, &globalCtx->colCtx.dyna, &this->dyna.actor, sp30);
    Collider_InitSpheres(globalCtx, &this->unk168);
    Collider_LoadSpheres(globalCtx, &this->unk168, &this->dyna.actor, &D_8088CD58, this->unk188);
    for (i = 0; i < 6; i++) {
        this->unk168.elements[i].shape.world.radius = this->unk168.elements[i].shape.model.radius;
    }
    this->unk166 = 0;
    this->unk164 = 0;
}

void BgHidanRsekizou_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanRsekizou* this = (BgHidanRsekizou*)thisx;

    DynaPolyInfo_Free(globalCtx, &globalCtx->colCtx.dyna, (s32)this->dyna.dynaPolyId);
    Collider_DestroySpheres(globalCtx, &this->unk168);
}

void BgHidanRsekizou_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad[4];
    f32 sp24;
    s32 i;
    ColliderSpheresElement* temp_v0_2;
    f32 temp_fv0;
    BgHidanRsekizou* this = (BgHidanRsekizou*)thisx;

    this->unk166 = (this->unk166 + 1) % 8;
    if (this->unk164 != 0) {
        this->unk164 = this->unk164 - 1;
    }
    if (this->unk164 == 0) {
        this->unk164 = 3;
    }
    this->dyna.actor.shape.rot.y += 0x180;
    sp24 = Math_Sins(this->dyna.actor.shape.rot.y);
    temp_fv0 = Math_Coss(this->dyna.actor.shape.rot.y);
    for (i = 0; i < 6; i++) {
        temp_v0_2 = &this->unk168.elements[i];
        temp_v0_2->shape.world.center.x = this->dyna.actor.initPosRot.pos.x +
                                          (temp_fv0 * temp_v0_2->shape.model.center.x) +
                                          (sp24 * temp_v0_2->shape.model.center.z);
        temp_v0_2->shape.world.center.y = (s16)this->dyna.actor.initPosRot.pos.y + temp_v0_2->shape.model.center.y;
        temp_v0_2->shape.world.center.z = this->dyna.actor.initPosRot.pos.z - (sp24 * temp_v0_2->shape.model.center.x) +
                                          (temp_fv0 * temp_v0_2->shape.model.center.z);
    }
    Collider_AddAT(globalCtx, &globalCtx->colliderCtx, &this->unk168.base);
    func_8002F974(&this->dyna.actor, 0x2033U);
}

Gfx* func_8088C70C(GraphicsContext** arg0, BgHidanRsekizou* arg1, s16 arg2, MtxF* arg3, s32 arg4, Gfx* arg5) {
    s32 i;
    f32 sp58;
    f32 temp_fv0;
    f32 var_fa1;
    f32 var_fa0;
    f32 temp_fv1;

    i = (s32)((f32)(((s32)(arg1->unk166 + arg2) % 8) * 7) * 0.14285715f);
    gSPSegment(arg5++, 9, SEGMENTED_TO_VIRTUAL(D_8088CD74[i]));
    arg2 = arg2 + 1;
    if (arg2 != 4) {
        var_fa1 = (f32)arg2 + ((f32)(3 - arg1->unk164) * 0.33333334f);
    } else {
        var_fa1 = (f32)arg2;
    }
    gDPSetPrimColor(arg5++, 0x00, 0x01, 255, 255, 0, 150);
    gDPSetEnvColor(arg5++, 255, 0, 0, 255);
    if (arg4 == 0) {
        sp58 = -Math_Sins((s16)(arg1->dyna.actor.shape.rot.y - (arg2 * 0x5DC)));
        var_fa0 = -Math_Coss((s16)(arg1->dyna.actor.shape.rot.y - (arg2 * 0x5DC)));
    } else {
        sp58 = Math_Sins((s16)(arg1->dyna.actor.shape.rot.y - (arg2 * 0x5DC)));
        var_fa0 = Math_Coss((s16)(arg1->dyna.actor.shape.rot.y - (arg2 * 0x5DC)));
    }
    temp_fv0 = (0.7f * var_fa1) + 0.5f;
    arg3->mf[0][0] = arg3->mf[1][1] = arg3->mf[2][2] = temp_fv0;
    temp_fv1 = (temp_fv0 * 10.0f * var_fa1) + 20.0f;
    arg3->mf[3][0] = (temp_fv1 * sp58) + arg1->dyna.actor.posRot.pos.x;
    arg3->mf[3][1] = arg1->dyna.actor.posRot.pos.y + 30.0f + (0.70f * var_fa1);
    arg3->mf[3][2] = (temp_fv1 * var_fa0) + arg1->dyna.actor.posRot.pos.z;
    gSPMatrix(arg5++,
              Matrix_MtxFToMtx(Matrix_CheckFloats(arg3, "../z_bg_hidan_rsekizou.c", 0x21F), Graph_Alloc(*arg0, 0x40U)),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(arg5++, D_600DC30);
    return arg5;
}

void BgHidanRsekizou_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanRsekizou* this = (BgHidanRsekizou*)thisx;
    s32 pad;
    s32 var_s0;
    MtxF sp5C;
    GraphicsContext* temp_a1;
    Gfx* sp48[4];

    temp_a1 = globalCtx->state.gfxCtx;
    Graph_OpenDisps(sp48, globalCtx->state.gfxCtx, "../z_bg_hidan_rsekizou.c", 0x234);
    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(temp_a1->polyOpa.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_hidan_rsekizou.c", 0x238),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(temp_a1->polyOpa.p++, D_600AD00);
    Matrix_MtxFCopy(&sp5C, &gMtxFClear);
    temp_a1->polyXlu.p = Gfx_CallSetupDL(temp_a1->polyXlu.p, 0x14U);
    if ((s16)((func_8005A9F4(globalCtx->cameraPtrs[globalCtx->activeCamera]) - this->dyna.actor.shape.rot.y) -
              0x2E6C) >= 0) {
        for (var_s0 = 3; var_s0 >= 0; var_s0--) {
            temp_a1->polyXlu.p = func_8088C70C(&globalCtx->state.gfxCtx, this, var_s0, &sp5C, 0, temp_a1->polyXlu.p);
        }
        for (var_s0 = 0; var_s0 < 4; var_s0++) {
            temp_a1->polyXlu.p = func_8088C70C(&globalCtx->state.gfxCtx, this, var_s0, &sp5C, 1, temp_a1->polyXlu.p);
        }
    } else {
        for (var_s0 = 3; var_s0 >= 0; var_s0--) {
            temp_a1->polyXlu.p = func_8088C70C(&globalCtx->state.gfxCtx, this, var_s0, &sp5C, 1, temp_a1->polyXlu.p);
        }
        for (var_s0 = 0; var_s0 < 4; var_s0++) {
            temp_a1->polyXlu.p = func_8088C70C(&globalCtx->state.gfxCtx, this, var_s0, &sp5C, 0, temp_a1->polyXlu.p);
        }
    }
    Graph_CloseDisps(sp48, globalCtx->state.gfxCtx, "../z_bg_hidan_rsekizou.c", 0x258);
}
