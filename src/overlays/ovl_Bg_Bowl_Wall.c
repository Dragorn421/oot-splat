/*
 * File: z_bg_bowl_wall.c
 * Overlay: Bg_Bowl_Wall
 * Description: Bombchu Bowling Alley Wall
 */

#include "z_bg_bowl_wall.h"
#include "z_en_bom_bowl_man.h"

#define FLAGS 0x00000030

#define THIS ((BgBowlWall*)thisx)

void BgBowlWall_Init(Actor* thisx, GlobalContext* globalCtx);
void BgBowlWall_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgBowlWall_Update(Actor* thisx, GlobalContext* globalCtx);
void BgBowlWall_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8086F260(BgBowlWall* this, GlobalContext* globalCtx);
void func_8086F440(BgBowlWall* this, GlobalContext* globalCtx);
void func_8086F464(BgBowlWall* this, GlobalContext* globalCtx);
void func_8086F718(BgBowlWall* this, GlobalContext* globalCtx);
void func_8086F7F8(BgBowlWall* this, GlobalContext* globalCtx);

extern Gfx D_6000610[];
extern UNK_TYPE D_6000CB8;
extern Gfx D_6001390[];
extern UNK_TYPE D_6001B00;

const ActorInit Bg_Bowl_Wall_InitVars = {
    ACTOR_BG_BOWL_WALL,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_BOWL,
    sizeof(BgBowlWall),
    (ActorFunc)BgBowlWall_Init,
    (ActorFunc)BgBowlWall_Destroy,
    (ActorFunc)BgBowlWall_Update,
    (ActorFunc)BgBowlWall_Draw,
};
Vec3f D_8086FA40[4] = {
    { 0.0f, 210.0f, -20.0f },
    { 0.0f, 170.0f, -20.0f },
    { -170.0f, 0.0f, -20.0f },
    { 170.0f, 0.0f, -20.0f },
};
s16 D_8086FA70[4] = { 0, 0, 0x3FFF, -0x3FFF };
Vec3f D_8086FA78 = { 0.0f, 0.1f, 0.0f };
Vec3f D_8086FA84 = { 0.0f, 0.0f, 0.0f };

void BgBowlWall_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgBowlWall* this = (BgBowlWall*)thisx;
    s32 pad1[2];
    s32 sp28;
    s32 pad2[2];

    sp28 = 0;
    DynaPolyInfo_SetActorMove(&this->dyna, DPM_UNK);
    if (this->dyna.actor.params == 0) {
        DynaPolyInfo_Alloc(&D_6000CB8, &sp28);
    } else {
        DynaPolyInfo_Alloc(&D_6001B00, &sp28);
    }
    this->dyna.dynaPolyId = DynaPolyInfo_RegisterActor(globalCtx, &globalCtx->colCtx.dyna, &this->dyna.actor, sp28);
    this->unk168 = this->dyna.actor.posRot.pos;
    osSyncPrintf("\n\n");
    osSyncPrintf("\x1b[32m ☆☆☆☆☆ ボーリングおじゃま壁発生 ☆☆☆☆☆ %d\n\x1b[m", this->dyna.actor.params);
    this->actionFunc = func_8086F260;
    this->dyna.actor.scale.z = 1.0f;
    this->dyna.actor.scale.y = 1.0f;
    this->dyna.actor.scale.x = 1.0f;
}

void BgBowlWall_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgBowlWall* this = (BgBowlWall*)thisx;

    DynaPolyInfo_Free(globalCtx, &globalCtx->colCtx.dyna, (s32)this->dyna.dynaPolyId);
}

typedef struct Actor1BE {
    Actor actor;
    char unk14C[0x154 - 0x14C];
    Vec3f unk154;
} Actor1BE;

void func_8086F260(BgBowlWall* this, GlobalContext* globalCtx) {
    Actor* var_v0_2;
    Actor1BE* temp_v0_2;
    s32 pad;
    s16 params = this->dyna.actor.params;

    if (params != 0) {
        params += (s16)Math_Rand_ZeroFloat(2.99f);
        this->dyna.actor.shape.rot.z = this->dyna.actor.posRot.rot.z = D_8086FA70[params];
        osSyncPrintf("\n\n");
    }
    this->unk174.x = D_8086FA40[params].x + this->dyna.actor.posRot.pos.x;
    this->unk174.y = D_8086FA40[params].y + this->dyna.actor.posRot.pos.y;
    this->unk174.z = D_8086FA40[params].z + this->dyna.actor.posRot.pos.z;
    if (0) {}
    temp_v0_2 = (Actor1BE*)Actor_SpawnAsChild(&globalCtx->actorCtx, &this->dyna.actor, globalCtx, ACTOR_EN_WALL_TUBO,
                                              this->unk174.x, this->unk174.y, this->unk174.z, 0, 0, 0,
                                              (s16)(s32)this->dyna.actor.params);
    if (temp_v0_2 != NULL) {
        temp_v0_2->unk154 = this->unk174;
        if (params != 0) {
            temp_v0_2->unk154 = this->unk174 = this->dyna.actor.posRot.pos;
        }
        if (this->unk184 == NULL) {
            var_v0_2 = globalCtx->actorCtx.actorList[4].first;
            while (var_v0_2 != NULL) {
                if (var_v0_2->id != ACTOR_EN_BOM_BOWL_MAN) {
                    var_v0_2 = var_v0_2->next;
                    continue;
                }
                this->unk184 = (EnBomBowlMan*)var_v0_2;
                break;
            }
        }
        this->actionFunc = func_8086F440;
    }
}

void func_8086F440(BgBowlWall* this, GlobalContext* globalCtx) {
    if (this->unk180 != 0) {
        this->actionFunc = func_8086F464;
    }
}

void func_8086F464(BgBowlWall* this, GlobalContext* globalCtx) {
    s32 var_s0;
    Vec3f spA0;
    Vec3f sp94;
    Vec3f sp88;
    s16 temp_v0;
    s32 var_s0_2;

    spA0 = D_8086FA78;
    var_s0 = 0;
    sp94 = D_8086FA84;
    if (this->dyna.actor.params == 0) {
        Math_SmoothScaleMaxMinS(&this->dyna.actor.shape.rot.x, -0x3E80, 3, 0x1F4, 0);
        this->dyna.actor.posRot.rot.x = this->dyna.actor.shape.rot.x;
        if (this->dyna.actor.shape.rot.x < -0x3C1E) {
            var_s0 = 1;
        }
    } else {
        Math_SmoothScaleMaxF(&this->dyna.actor.posRot.pos.y, this->unk168.y - 450.0f, 0.3f, 10.0f);
        if (this->dyna.actor.posRot.pos.y < (this->unk168.y - 400.0f)) {
            var_s0 = 1;
        }
    }
    if (var_s0 != 0) {
        for (var_s0_2 = 0; var_s0_2 < 15; var_s0_2++) {
            sp88.x = Math_Rand_CenteredFloat(300.0f) + this->unk174.x;
            sp88.y = -100.0f;
            sp88.z = Math_Rand_CenteredFloat(400.0f) + this->unk174.z;
            EffectSsBomb2_SpawnLayered(globalCtx, (Vec3f*)&sp88, &sp94, &spA0, 0x64, 0x1E);
            sp88.y = -50.0f;
            EffectSsHahen_SpawnBurst(globalCtx, (Vec3f*)&sp88, 10.0f, 0, 0x32, 0xF, 3, -1, 0xA, NULL);
            Audio_PlayActorSound2(&this->dyna.actor, 0x180EU);
        }
        temp_v0 = Quake_Add(globalCtx->cameraPtrs[globalCtx->activeCamera], 1U);
        Quake_SetSpeed(temp_v0, 0x7FFF);
        Quake_SetQuakeValues(temp_v0, 0x12C, 0, 0, 0);
        Quake_SetCountdown(temp_v0, 0x1E);
        this->unk182 = 0x14;
        this->actionFunc = func_8086F718;
    }
}

void func_8086F718(BgBowlWall* this, GlobalContext* globalCtx) {
    if (this->unk182 >= 2) {
        if (this->dyna.actor.params == 0) {
            Math_SmoothScaleMaxMinS(&this->dyna.actor.shape.rot.x, -0x3E80, 1, 0xC8, 0);
            return;
        }
        Math_SmoothScaleMaxF(&this->dyna.actor.posRot.pos.y, this->unk168.y - 450.0f, 0.3f, 10.0f);
        return;
    }
    if (this->unk182 == 1) {
        this->dyna.actor.posRot.pos.y = this->unk168.y - 450.0f;
        this->dyna.actor.posRot.rot.x = this->dyna.actor.shape.rot.x = 0;
        this->unk184->unk23E_arr[this->dyna.actor.params] = 2;
        this->actionFunc = func_8086F7F8;
    }
}

void func_8086F7F8(BgBowlWall* this, GlobalContext* globalCtx) {
    f32 temp_fv1;

    if ((this->unk184)->unk23E_arr[this->dyna.actor.params] != 2) {
        Math_SmoothScaleMaxF(&this->dyna.actor.posRot.pos.y, this->unk168.y, 0.3f, 50.0f);
        temp_fv1 = this->unk168.y;
        if (fabsf(this->dyna.actor.posRot.pos.y - temp_fv1) <= 10.0f) {
            this->dyna.actor.posRot.pos.y = temp_fv1;
            this->unk180 = 0;
            this->actionFunc = func_8086F260;
        }
    }
}

void BgBowlWall_Update(Actor* thisx, GlobalContext* globalCtx) {
    s16 temp_v0;
    BgBowlWall* this = (BgBowlWall*)thisx;

    temp_v0 = this->unk182;
    if (temp_v0 != 0) {
        this->unk182 = temp_v0 - 1;
    }
    this->actionFunc(this, globalCtx);
}

void BgBowlWall_Draw(Actor* thisx, GlobalContext* globalCtx) {
    u32 new_var2;
    BgBowlWall* this = (BgBowlWall*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_bowl_wall.c", 0x1B9);
    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x8,
               Gfx_TexScroll(globalCtx->state.gfxCtx, 0U, (s32)(new_var2 = globalCtx->state.frames) * -2, 0x10, 0x10));
    gDPPipeSync(POLY_OPA_DISP++);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_bowl_wall.c", 0x1C5),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    if (this->dyna.actor.params == 0) {
        gSPDisplayList(POLY_OPA_DISP++, D_6000610);
    } else {
        gSPDisplayList(POLY_OPA_DISP++, D_6001390);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_bowl_wall.c", 0x1D0);
}

/*
#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/BgBowlWall_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/BgBowlWall_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/func_8086F260.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/func_8086F440.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/func_8086F464.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/func_8086F718.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/func_8086F7F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/BgBowlWall_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Bowl_Wall/BgBowlWall_Draw.s")
*/
