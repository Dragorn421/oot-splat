#include "z_en_bom_bowl_pit.h"

#define FLAGS 0x00000010

#define THIS ((EnBomBowlPit*)thisx)

void EnBomBowlPit_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBomBowlPit_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBomBowlPit_Update(Actor* thisx, GlobalContext* globalCtx);

void func_809C4E60(EnBomBowlPit* this, GlobalContext* globalCtx);
void func_809C4E8C(EnBomBowlPit* this, GlobalContext* globalCtx);
void func_809C5184(EnBomBowlPit* this, GlobalContext* globalCtx);
void func_809C5360(EnBomBowlPit* this, GlobalContext* globalCtx);
void func_809C53F0(EnBomBowlPit* this, GlobalContext* globalCtx);
void func_809C54A8(EnBomBowlPit* this, GlobalContext* globalCtx);
void func_809C55B0(EnBomBowlPit* this, GlobalContext* globalCtx);
void func_809C5608(EnBomBowlPit* this, GlobalContext* globalCtx);

static s32 D_809C56E0[5] = { 0x33, 0x3E, 3, 0x65, 0x55 };

const ActorInit En_Bom_Bowl_Pit_InitVars = {
    ACTOR_EN_BOM_BOWL_PIT,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnBomBowlPit),
    (ActorFunc)EnBomBowlPit_Init,
    (ActorFunc)EnBomBowlPit_Destroy,
    (ActorFunc)EnBomBowlPit_Update,
    NULL,
};

void EnBomBowlPit_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnBomBowlPit* this = (EnBomBowlPit*)thisx;

    this->unk14C = func_809C4E60;
}

void EnBomBowlPit_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void func_809C4E60(EnBomBowlPit* this, GlobalContext* globalCtx) {
    if (this->unk15C != 0) {
        this->unk15C = this->unk164 = 0;
        this->unk14C = func_809C4E8C;
    }
}

typedef struct ActorDA {
    Actor actor;
    char pad14C[4];
    s16 unk150;
} ActorDA;

void func_809C4E8C(EnBomBowlPit* this, GlobalContext* globalCtx) {
    Actor* var_v1;
    ActorDA* sp24;
    Vec3f diff;

    if (globalCtx->cameraPtrs[0]->setting == 0x15) {
        var_v1 = globalCtx->actorCtx.actorList[3].first;
        while (var_v1 != NULL) {
            if (((var_v1 + 0) == &this->actor) || (var_v1->id != ACTOR_EN_BOM_CHU)) {
                var_v1 = var_v1->next;
                continue;
            }
            diff.x = var_v1->posRot.pos.x - this->actor.posRot.pos.x;
            diff.y = var_v1->posRot.pos.y - this->actor.posRot.pos.y;
            diff.z = var_v1->posRot.pos.z - this->actor.posRot.pos.z;
            if (((fabsf(diff.x) < 40.0f) || (gGameInfo->data[0x962] != 0)) &&
                ((fabsf(diff.y) < 40.0f) || (gGameInfo->data[0x962] != 0)) &&
                ((fabsf(diff.z) < 40.0f) || (gGameInfo->data[0x962] != 0))) {
                sp24 = (ActorDA*)var_v1;
                func_8002DF54(globalCtx, NULL, 8U);
                sp24->unk150 = 1;
                this->unk152 = Gameplay_CreateSubCamera(globalCtx);
                Gameplay_ChangeCameraStatus(globalCtx, 0, 1);
                Gameplay_ChangeCameraStatus(globalCtx, this->unk152, 7);
                this->unk1A4 = this->unk1A8 = this->unk1AC = this->unk1C8 = this->unk1CC = this->unk1D0 = 0.1f;
                this->unk180.x = this->unk168.x = globalCtx->view.lookAt.x;
                this->unk180.y = this->unk168.y = globalCtx->view.lookAt.y;
                this->unk180.z = this->unk168.z = globalCtx->view.lookAt.z;
                this->unk18C.x = this->unk174.x = globalCtx->view.eye.x;
                this->unk18C.y = this->unk174.y = globalCtx->view.eye.y;
                this->unk18C.z = this->unk174.z = globalCtx->view.eye.z;
                this->unk1BC = 20.0f;
                this->unk1C0 = 100.0f;
                this->unk1C4 = -800.0f;
                this->unk198 = 20.0f;
                this->unk19C = 50.0f;
                this->unk1A0 = -485.0f;
                this->unk1B0 = fabsf(this->unk18C.x - 20.0f) * 0.02f;
                this->unk1B4 = fabsf(this->unk18C.y - 50.0f) * 0.02f;
                this->unk1B8 = fabsf(this->unk18C.z - -485.0f) * 0.02f;
                this->unk1D4 = fabsf(this->unk180.x - this->unk1BC) * 0.02f;
                this->unk1D8 = fabsf(this->unk180.y - this->unk1C0) * 0.02f;
                this->unk1DC = fabsf(this->unk180.z - this->unk1C4) * 0.02f;
                func_800C04D8(globalCtx, this->unk152, (Vec3f*)&this->unk180, (Vec3f*)&this->unk18C);
                this->actor.textId = 0xF;
                func_8010B680(globalCtx, this->actor.textId, NULL);
                this->unk154 = 5;
                func_80078884(0x28D3U);
                func_8002DF54(globalCtx, NULL, 8U);
                this->unk164 = 1;
                this->unk14C = func_809C5184;
                return;
            }
            var_v1 = var_v1->next;
        }
    }
}

void func_809C5184(EnBomBowlPit* this, GlobalContext* globalCtx) {
    if (this->unk152 != 0) {
        Math_SmoothScaleMaxF(&this->unk180.x, this->unk1BC, this->unk1C8, this->unk1D4);
        Math_SmoothScaleMaxF(&this->unk180.y, this->unk1C0, this->unk1CC, this->unk1D8);
        Math_SmoothScaleMaxF(&this->unk180.z, this->unk1C4, this->unk1D0, this->unk1DC);
        Math_SmoothScaleMaxF(&this->unk18C.x, this->unk198, this->unk1A4, this->unk1B0);
        Math_SmoothScaleMaxF(&this->unk18C.y, this->unk19C, this->unk1A8, this->unk1B4);
        Math_SmoothScaleMaxF(&this->unk18C.z, this->unk1A0, this->unk1AC, this->unk1B8);
    }
    func_800C04D8(globalCtx, this->unk152, (Vec3f*)&this->unk180, (Vec3f*)&this->unk18C);
    if ((this->unk154 == func_8010BDBC(&globalCtx->msgCtx)) && (func_80106BC8(globalCtx) != 0)) {
        func_80106CCC(globalCtx);
    }
    if ((fabsf(this->unk18C.x - this->unk198) < 5.0f) && (fabsf(this->unk18C.y - this->unk19C) < 5.0f) &&
        (fabsf(this->unk18C.z - this->unk1A0) < 5.0f) && (fabsf(this->unk180.x - this->unk1BC) < 5.0f) &&
        (fabsf(this->unk180.y - this->unk1C0) < 5.0f) && (fabsf(this->unk180.z - this->unk1C4) < 5.0f)) {
        func_80106CCC(globalCtx);
        this->unk158 = 0x1E;
        this->unk14C = func_809C5360;
    }
}

void func_809C5360(EnBomBowlPit* this, GlobalContext* globalCtx) {
    if (this->unk158 == 0) {
        this->unk1E0 =
            Actor_SpawnAsChild(&globalCtx->actorCtx, &this->actor, globalCtx, 0x168, this->actor.posRot.pos.x,
                               this->actor.posRot.pos.y, this->actor.posRot.pos.z - 70.0f, 0, 0, 0, this->unk15A);
        if (this->unk1E0 != NULL) {
            this->unk14C = func_809C53F0;
        }
    }
}

void func_809C53F0(EnBomBowlPit* this, GlobalContext* globalCtx) {
    if (this->unk156 != 0) {
        switch (this->unk15A) { /* irregular */
            case 0:
                gSaveContext.itemGetInf[1] |= 2;
                break;
            case 1:
                gSaveContext.itemGetInf[1] |= 4;
                break;
        }
        Gameplay_ClearCamera(globalCtx, this->unk152);
        Gameplay_ChangeCameraStatus(globalCtx, 0, 7);
        func_8002DF54(globalCtx, NULL, 8U);
        this->unk14C = func_809C54A8;
    }
}

void func_809C54A8(EnBomBowlPit* this, GlobalContext* globalCtx) {
    Player* temp_v0;

    temp_v0 = PLAYER;
    func_8002DF54(globalCtx, NULL, 7U);
    this->unk160 = D_809C56E0[this->unk15A];
    if ((this->unk160 == 0x33) &&
        (gUpgradeCapacities[1][(s32)(gSaveContext.inventory.upgrades & gUpgradeMasks[1]) >> gUpgradeShifts[1]] ==
         0x1E)) {
        this->unk160 = 0x34;
    }
    temp_v0->stateFlags1 &= 0xDFFFFFFF;
    this->actor.parent = NULL;
    func_8002F434(&this->actor, globalCtx, this->unk160, 2000.0f, 1000.0f);
    temp_v0->stateFlags1 |= 0x20000000;
    this->unk14C = func_809C55B0;
}

void func_809C55B0(EnBomBowlPit* this, GlobalContext* globalCtx) {
    if (Actor_HasParent(&this->actor, globalCtx) != 0) {
        this->unk14C = func_809C5608;
        return;
    }
    func_8002F434(&this->actor, globalCtx, this->unk160, 2000.0f, 1000.0f);
}

void func_809C5608(EnBomBowlPit* this, GlobalContext* globalCtx) {
    if ((func_8010BDBC(&globalCtx->msgCtx) == 6) && (func_80106BC8(globalCtx) != 0)) {
        osSyncPrintf("\x1b[32m☆☆☆☆☆ 正常終了 ☆☆☆☆☆ \n\x1b[m");
        if (this->unk160 == 0x3E) {
            gSaveContext.healthAccumulator = 0x140;
            osSyncPrintf("\x1b[32m☆☆☆☆☆ あぁ回復！ ☆☆☆☆☆ \n\x1b[m");
        }
        this->unk156 = 0;
        this->unk164 = 2;
        this->unk14C = func_809C4E60;
    }
}

void EnBomBowlPit_Update(Actor* thisx, GlobalContext* globalCtx) {
    s16 temp_v0;
    EnBomBowlPit* this = (EnBomBowlPit*)thisx;

    this->unk14C(this, globalCtx);
    temp_v0 = this->unk158;
    if (temp_v0 != 0) {
        this->unk158 = temp_v0 - 1;
    }
}

/*
#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Pit/EnBomBowlPit_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Pit/EnBomBowlPit_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Pit/func_809C4E60.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Pit/func_809C4E8C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Pit/func_809C5184.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Pit/func_809C5360.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Pit/func_809C53F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Pit/func_809C54A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Pit/func_809C55B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Pit/func_809C5608.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bom_Bowl_Pit/EnBomBowlPit_Update.s")
*/
