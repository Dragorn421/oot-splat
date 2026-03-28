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

void func_80A9EFE0(EnMThunder* arg0, void (*arg1)(EnMThunder*, GlobalContext*)) {
    arg0->unk1C0 = arg1;
}

void EnMThunder_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnMThunder* this = (EnMThunder*)thisx;
    Player* temp_s1;

    temp_s1 = globalCtx->actorCtx.actorLists[2].head;
    Collider_InitCylinder(globalCtx, &this->unk14C);
    Collider_SetCylinder(globalCtx, &this->unk14C, &this->actor, &D_80AA0420);
    this->unk1C7 = (this->actor.params & 0xFF) - 1;
    Lights_PointNoGlowSetInfo(&this->unk19C, (s16)(s32)this->actor.world.pos.x, (s16)(s32)this->actor.world.pos.y,
                              (s16)(s32)this->actor.world.pos.z, 0xFFU, 0xFFU, 0xFFU, 0);
    this->unk198 = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &this->unk19C);
    this->unk14C.dim.radius = 0;
    this->unk14C.dim.height = 0x28;
    this->unk14C.dim.yShift = -0x14;
    this->unk1C4 = 8;
    this->unk1B4 = 0.0f;
    this->actor.world.pos = temp_s1->bodyPartsPos[0];
    this->unk1AC = 0.0f;
    this->unk1BC = 0.0f;
    this->actor.shape.rot.y = temp_s1->actor.shape.rot.y + 0x8000;
    this->actor.room = -1;
    Actor_SetScale(&this->actor, 0.1f);
    this->unk1CA = 0;
    if (temp_s1->stateFlags2 & 0x20000) {
        if (((gSaveContext.magicAcquired) == 0) || (gSaveContext.unk_13F0 != 0) ||
            (((((this->actor.params & 0xFF00) >> 8) != 0)) &&
             (func_80087708(globalCtx, (s16)((this->actor.params & 0xFF00) >> 8), 0) == 0))) {
            Audio_PlaySoundGeneral(0x1823U, &temp_s1->actor.projectedPos, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
            Audio_PlaySoundGeneral(0x1818U, &temp_s1->actor.projectedPos, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
            Actor_Kill(&this->actor);
            return;
        }
        temp_s1->stateFlags2 = (s32)(temp_s1->stateFlags2 & 0xFFFDFFFF);
        this->unk1CA = 1;
        this->unk14C.info.toucher.dmgFlags = D_80AA044C[this->unk1C7];
        this->unk1C6 = 1;
        if (this->unk1C7 == 1) {
            this->unk1C9 = 2;
        } else {
            this->unk1C9 = 4;
        }
        func_80A9EFE0(this, func_80A9F9B4);
        this->unk1C4 = 8;
        Audio_PlaySoundGeneral(0x182EU, &temp_s1->actor.projectedPos, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        this->unk1AC = 1.0f;
    } else {
        func_80A9EFE0(this, func_80A9F408);
    }
    this->actor.child = NULL;
}

void EnMThunder_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnMThunder* this = (EnMThunder*)thisx;

    if (this->unk1CA != 0) {
        func_800876C8(globalCtx);
    }
    Collider_DestroyCylinder(globalCtx, &this->unk14C);
    func_80A9F314(globalCtx, 0.0f);
    LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, this->unk198);
}

void func_80A9F314(GlobalContext* arg0, f32 arg1) {
    func_800773A8(arg0, arg1, 850.0f, 0.2f, 0.0f);
}

void func_80A9F350(EnMThunder* arg0, GlobalContext* arg1) {
    Player* temp_v0;

    temp_v0 = arg1->actorCtx.actorLists[2].head;
    if (temp_v0->stateFlags2 & 0x20000) {
        if (temp_v0->swordAnimation >= 0x18) {
            Audio_PlaySoundGeneral(0x1823U, &temp_v0->actor.projectedPos, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
            Audio_PlaySoundGeneral(0x1818U, &temp_v0->actor.projectedPos, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        }
        Actor_Kill(&arg0->actor);
        return;
    }
    if (!(temp_v0->stateFlags1 & 0x1000)) {
        Actor_Kill(&arg0->actor);
    }
}

void func_80A9F408(EnMThunder* arg0, GlobalContext* arg1) {
    Player* var_v1_sp4C;
    Actor* var_t0_sp48;

    var_v1_sp4C = arg1->actorCtx.actorLists[2].head;
    var_t0_sp48 = arg0->actor.child;
    arg0->unk1B8 = var_v1_sp4C->unk_858;
    arg0->actor.world.pos = var_v1_sp4C->bodyPartsPos[0];
    arg0->actor.shape.rot.y = var_v1_sp4C->actor.shape.rot.y + 0x8000;
    if ((arg0->unk1CA == 0) && (var_v1_sp4C->unk_858 >= 0.10f)) {
        if ((gSaveContext.unk_13F0 != 0) ||
            (((((s32)(arg0->actor.params & 0xFF00) >> 8) != 0)) &&
             ((func_80087708(arg1, (s16)((s32)(arg0->actor.params & 0xFF00) >> 8), 4) == 0)))) {
            func_80A9F350(arg0, arg1);
            func_80A9EFE0(arg0, func_80A9F350);
            arg0->unk1C8 = 0;
            arg0->unk1BC = 0;
            arg0->unk1AC = 0.0f;
            return;
        }
        arg0->unk1CA = 1;
    }
    if (var_v1_sp4C->unk_858 >= 0.10f) {
        func_800AA000(0.0f, (u8)(s32)(var_v1_sp4C->unk_858 * 150.0f), 2U, (u8)(s32)(var_v1_sp4C->unk_858 * 150.0f));
    }
    if (var_v1_sp4C->stateFlags2 & 0x20000) {
        if ((var_t0_sp48 != NULL) && (var_t0_sp48->update != NULL)) {
            var_t0_sp48->parent = NULL;
        }
        if (var_v1_sp4C->unk_858 <= 0.15f) {
            if ((var_v1_sp4C->unk_858 >= 0.10f) && (var_v1_sp4C->swordAnimation >= 0x18)) {
                Audio_PlaySoundGeneral(0x1823U, &var_v1_sp4C->actor.projectedPos, 4U, &D_801333E0, &D_801333E0,
                                       &D_801333E8);
                Audio_PlaySoundGeneral(0x1818U, &var_v1_sp4C->actor.projectedPos, 4U, &D_801333E0, &D_801333E0,
                                       &D_801333E8);
            }
            Actor_Kill(&arg0->actor);
            return;
        }
        var_v1_sp4C->stateFlags2 = (s32)(var_v1_sp4C->stateFlags2 & 0xFFFDFFFF);
        if (((s32)(arg0->actor.params & 0xFF00) >> 8) != 0) {
            gSaveContext.unk_13F0 = 1;
        }
        if (var_v1_sp4C->unk_858 < 0.85f) {
            arg0->unk14C.info.toucher.dmgFlags = D_80AA044C[arg0->unk1C7];
            arg0->unk1C6 = 1;
            if (arg0->unk1C7 == 1) {
                arg0->unk1C9 = 2;
            } else {
                arg0->unk1C9 = 4;
            }
        } else {
            arg0->unk14C.info.toucher.dmgFlags = D_80AA0458[arg0->unk1C7];
            arg0->unk1C6 = 0;
            if (arg0->unk1C7 == 1) {
                arg0->unk1C9 = 4;
            } else {
                arg0->unk1C9 = 8;
            }
        }
        func_80A9EFE0(arg0, func_80A9F9B4);
        arg0->unk1C4 = 8;
        Audio_PlaySoundGeneral(D_80AA0464[arg0->unk1C6], &var_v1_sp4C->actor.projectedPos, 4U, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        arg0->unk1AC = 1.0f;
        return;
    }
    if (!(var_v1_sp4C->stateFlags1 & 0x1000)) {
        if (arg0->actor.child != NULL) {
            arg0->actor.child->parent = NULL;
        }
        Actor_Kill(&arg0->actor);
        return;
    }
    if (var_v1_sp4C->unk_858 > 0.15f) {
        arg0->unk1C8 = 0xFF;
        if (arg0->actor.child == NULL) {
            Actor_SpawnAsChild(&arg1->actorCtx, &arg0->actor, arg1, 0x101, arg0->actor.world.pos.x,
                               arg0->actor.world.pos.y, arg0->actor.world.pos.z, 0, (s16)(s32)arg0->actor.shape.rot.y,
                               0, (s16)(arg0->unk1C7 + 2));
        }
        arg0->unk1BC = arg0->unk1BC + ((((var_v1_sp4C->unk_858 - 0.15f) * 1.5f) - arg0->unk1BC) * 0.5f);
    } else if (var_v1_sp4C->unk_858 > 0.1f) {
        arg0->unk1C8 = (u8)(s32)((var_v1_sp4C->unk_858 - 0.1f) * 255.0f * 20.0f);
        arg0->unk1AC = (var_v1_sp4C->unk_858 - 0.1f) * 10.0f;
    } else {
        arg0->unk1C8 = 0;
    }
    if (var_v1_sp4C->unk_858 > 0.85f) {
        func_800F4254(&var_v1_sp4C->actor.projectedPos, 2U);
    } else if (var_v1_sp4C->unk_858 > 0.15f) {
        func_800F4254(&var_v1_sp4C->actor.projectedPos, 1U);
    } else if (var_v1_sp4C->unk_858 > 0.10f) {
        func_800F4254(&var_v1_sp4C->actor.projectedPos, 0U);
    }
    if (Gameplay_InCsMode(arg1) != 0) {
        Actor_Kill(&arg0->actor);
    }
}

void func_80A9F938(EnMThunder* arg0, GlobalContext* arg1) {
    if ((s32)arg0->unk1C4 < 2) {
        if ((s32)arg0->unk1C8 < 0x28) {
            arg0->unk1C8 = 0;
        } else {
            arg0->unk1C8 = arg0->unk1C8 - 0x28;
        }
    }
    arg0->unk1B4 += 2.0f * arg0->unk1B0;
    if (arg0->unk1BC < arg0->unk1AC) {
        arg0->unk1BC = arg0->unk1BC + ((arg0->unk1AC - arg0->unk1BC) * 0.1f);
    } else {
        arg0->unk1BC = arg0->unk1AC;
    }
}

void func_80A9F9B4(EnMThunder* arg0, GlobalContext* arg1) {
    Player* sp2C;

    sp2C = arg1->actorCtx.actorLists[2].head;
    if (Math_StepToF(&arg0->unk1AC, 0.0f, 0.0625f) != 0) {
        Actor_Kill(&arg0->actor);
    } else {
        Math_SmoothStepToF(&arg0->actor.scale.x, (f32)(s32)arg0->unk1C9, 0.6f, 0.8f, 0.0f);
        Actor_SetScale(&arg0->actor, arg0->actor.scale.x);
        arg0->unk14C.dim.radius = (s16)(s32)(arg0->actor.scale.x * 25.0f);
        Collider_UpdateCylinder(&arg0->actor, &arg0->unk14C);
        CollisionCheck_SetAT(arg1, &arg1->colChkCtx, &arg0->unk14C.base);
    }
    if ((s32)arg0->unk1C4 > 0) {
        arg0->actor.world.pos.x = sp2C->bodyPartsPos[0].x;
        arg0->actor.world.pos.z = sp2C->bodyPartsPos[0].z;
        arg0->unk1C4 = arg0->unk1C4 - 1;
    }
    if (arg0->unk1AC > 0.6f) {
        arg0->unk1B0 = 1.0f;
    } else {
        arg0->unk1B0 = arg0->unk1AC * 1.6666666f;
    }
    func_80A9F938(arg0, arg1);
    if (Gameplay_InCsMode(arg1) != 0) {
        Actor_Kill(&arg0->actor);
    }
}

void EnMThunder_Update(Actor* thisx, GlobalContext* globalCtx) {
    f32 temp_fv0;
    s32 temp_v0;
    EnMThunder* this = (EnMThunder*)thisx;

    this->unk1C0(this, globalCtx);
    func_80A9F314(globalCtx, this->unk1BC);
    temp_fv0 = this->unk1AC;
    temp_v0 = (u32)(temp_fv0 * 255.0f) & 0xFF;
    Lights_PointNoGlowSetInfo(&this->unk19C, (s16)(s32)this->actor.world.pos.x, (s16)(s32)this->actor.world.pos.y,
                              (s16)(s32)this->actor.world.pos.z, (u8)temp_v0, (u8)temp_v0, (u8)(u32)(temp_fv0 * 100.0f),
                              (s16)(s32)(temp_fv0 * 800.0f));
}

void EnMThunder_Draw(Actor* thisx, GlobalContext* globalCtx2) {
    f32 var_fa1;
    GlobalContext* globalCtx = globalCtx2;
    Player* spA4;
    EnMThunder* this = (EnMThunder*)thisx;
    s32 var_t1;

    spA4 = globalCtx->actorCtx.actorLists[2].head;
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_m_thunder.c", 0x34C);
    func_80093D84(globalCtx->state.gfxCtx);
    Matrix_Scale(0.02f, 0.02f, 0.02f, 1U);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_m_thunder.c", 0x355),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    switch (this->unk1C6) {
        case 0:
        case 1:
            gSPSegment(POLY_XLU_DISP++, 8,
                       Gfx_TwoTexScroll(
                        globalCtx->state.gfxCtx, 
                        0, 
                        0xFF - ((u8)(s32)(this->unk1B4 * 30.0f) & 0xFF), 
                        0,
                        0x40, 
                        0x20, 
                        1, 
                        0xFF - ((u8)(s32)(this->unk1B4 * 20.0f) & 0xFF), 
                        0, 
                        8, 
                        8));
            break;
    }
    switch (this->unk1C6) {
        case 0:
            gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x80, 255, 255, 0xAA, (u8)(this->unk1B0 * 255.0f));
            gSPDisplayList(POLY_XLU_DISP++, D_4012AF0);
            gSPDisplayList(POLY_XLU_DISP++, D_4012C10);
            break;
        case 1:
            gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x80, 0xAA, 255, 255, (u8)(this->unk1B0 * 255.0f));
            gSPDisplayList(POLY_XLU_DISP++, D_4012570);
            gSPDisplayList(POLY_XLU_DISP++, D_4012690);
            break;
    }
    Matrix_Mult(&spA4->mf_9E0, 0U);
    switch (this->unk1C7) {
        case 1:
            Matrix_Translate(0.0f, 220.0f, 0.0f, 1U);
            Matrix_Scale(-0.7f, -0.6f, -0.4f, 1U);
            Matrix_RotateX(16384.0f, 1U);
            break;
        case 0:
            Matrix_Translate(0.0f, 300.0f, -100.0f, 1U);
            Matrix_Scale(-1.2f, -1.0f, -0.7f, 1U);
            Matrix_RotateX(16384.0f, 1U);
            break;
        case 2:
            Matrix_Translate(200.0f, 350.0f, 0.0f, 1U);
            Matrix_Scale(-1.8f, -1.4f, -0.7f, 1U);
            Matrix_RotateX(16384.0f, 1U);
            break;
    }
    if (this->unk1B8 >= 0.85f) {
        var_fa1 = (D_80AA046C[globalCtx->gameplayFrames & 7] * 6.0f) + 1.0f;
        gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x80, 255, 255, 0xAA, this->unk1C8);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 100, 0, 128);
        var_t1 = 0x28;
    } else {
        var_fa1 = (2.0f * D_80AA046C[globalCtx->gameplayFrames & 7]) + 1.0f;
        gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x80, 0xAA, 255, 255, this->unk1C8);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 100, 255, 128);
        var_t1 = 0x14;
    }
    Matrix_Scale(1.0f, var_fa1, var_fa1, 1U);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_m_thunder.c", 0x3C0),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPSegment(POLY_XLU_DISP++, 9,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (globalCtx->gameplayFrames * 5) & 0xFF, 0U, 0x20, 0x20, 1,
                                (globalCtx->gameplayFrames * 0x14) & 0xFF, (globalCtx->gameplayFrames * var_t1) & 0xFF,
                                8, 8));
    gSPDisplayList(POLY_XLU_DISP++, D_4013610);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_m_thunder.c", 0x407);
}
