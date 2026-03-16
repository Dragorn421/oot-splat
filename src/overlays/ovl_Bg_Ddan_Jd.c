/*
 * File: z_bg_ddan_jd.c
 * Overlay: ovl_Bg_Ddan_Jd
 * Description: Rising stone platform (Dodongo's Cavern)
 */

#include "z_bg_ddan_jd.h"

#define FLAGS 0x00000030

#define THIS ((BgDdanJd*)thisx)

void BgDdanJd_Init(Actor* thisx, GlobalContext* globalCtx);
void BgDdanJd_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgDdanJd_Update(Actor* thisx, GlobalContext* globalCtx);
void BgDdanJd_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80870B88(BgDdanJd* this, GlobalContext* globalCtx);
void func_80870D2C(BgDdanJd* this, GlobalContext* globalCtx);
void func_80870F00(BgDdanJd* this, GlobalContext* globalCtx);

extern Gfx D_60037B8;
extern UNK_TYPE D_6003CE0;

const ActorInit Bg_Ddan_Jd_InitVars = {
    ACTOR_BG_DDAN_JD,
    ACTORTYPE_BG,
    FLAGS,
    OBJECT_DDAN_OBJECTS,
    sizeof(BgDdanJd),
    (ActorFunc)BgDdanJd_Init,
    (ActorFunc)BgDdanJd_Destroy,
    (ActorFunc)BgDdanJd_Update,
    (ActorFunc)BgDdanJd_Draw,
};

static InitChainEntry D_80871080[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgDdanJd_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgDdanJd* this = (BgDdanJd*)thisx;
    s32 pad;
    s32 sp24;

    sp24 = 0;
    Actor_ProcessInitChain(&this->dyna.actor, D_80871080);
    DynaPolyInfo_SetActorMove(&this->dyna, DPM_PLAYER);
    DynaPolyInfo_Alloc(&D_6003CE0, &sp24);
    this->dyna.dynaPolyId = DynaPolyInfo_RegisterActor(globalCtx, &globalCtx->colCtx.dyna, &this->dyna.actor, sp24);
    this->unk16A = 0x64;
    this->unk168 = 0;
    if (Flags_GetSwitch(globalCtx, this->dyna.actor.params)) {
        this->unk169 = 5;
    } else {
        this->unk169 = 1;
    }
    this->actionFunc = func_80870B88;
}

void BgDdanJd_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgDdanJd* this = (BgDdanJd*)thisx;

    DynaPolyInfo_Free(globalCtx, &globalCtx->colCtx.dyna, this->dyna.dynaPolyId);
}

void func_80870B88(BgDdanJd* this, GlobalContext* globalCtx) {
    if (this->unk16A != 0) {
        this->unk16A--;
    }
    if (this->unk169 == 1) {
        if ((this->dyna.actor.params < 0x40) && (Flags_GetSwitch(globalCtx, this->dyna.actor.params))) {
            this->unk169 = 5;
            this->unk168 = 1;
            this->unk16A = 0;
            this->dyna.actor.posRot.pos.y = this->dyna.actor.initPosRot.pos.y + 140.0f;
            func_800800F8(globalCtx, 0xBF4, -0x63, &this->dyna.actor, 0);
        }
    }
    if (this->unk16A == 0) {
        this->unk16A = 0x64;
        if (this->unk168 == 0) {
            this->unk168 = 1;
            this->unk16C = this->dyna.actor.initPosRot.pos.y + 140.0f;
        } else if (this->unk168 == 1) {
            if (this->unk169 != 1) {
                this->unk168 = 3;
                this->unk16C = this->dyna.actor.initPosRot.pos.y + 700.0f;
            } else {
                this->unk168 = 0;
                this->unk16C = this->dyna.actor.initPosRot.pos.y;
            }
        } else if (this->unk168 == 2) {
            if (this->unk169 != 1) {
                this->unk168 = 3;
                this->unk16C = this->dyna.actor.initPosRot.pos.y + 700.0f;
            } else {
                this->unk168 = 0;
                this->unk16C = this->dyna.actor.initPosRot.pos.y;
            }
        } else if (this->unk168 == 3) {
            this->unk168 = 2;
            this->unk16C = this->dyna.actor.initPosRot.pos.y + 140.0f;
        }
        this->actionFunc = func_80870F00;
    }
}

void func_80870D2C(BgDdanJd* this, GlobalContext* globalCtx) {
    Vec3f sp34;

    sp34.y = this->dyna.actor.initPosRot.pos.y;
    if (globalCtx->gameplayFrames & 1) {
        sp34.x = this->dyna.actor.posRot.pos.x + 65.0f;
        sp34.z = Math_Rand_CenteredFloat(110.0f) + this->dyna.actor.posRot.pos.z;
        func_80033480(globalCtx, &sp34, 5.0f, 1, 0x14, 0x3C, 1U);
        sp34.x = this->dyna.actor.posRot.pos.x - 65.0f;
        sp34.z = Math_Rand_CenteredFloat(110.0f) + this->dyna.actor.posRot.pos.z;
        func_80033480(globalCtx, &sp34, 5.0f, 1, 0x14, 0x3C, 1U);
    } else {
        sp34.x = Math_Rand_CenteredFloat(110.0f) + this->dyna.actor.posRot.pos.x;
        sp34.z = this->dyna.actor.posRot.pos.z + 65.0f;
        func_80033480(globalCtx, &sp34, 5.0f, 1, 0x14, 0x3C, 1U);
        sp34.x = Math_Rand_CenteredFloat(110.0f) + this->dyna.actor.posRot.pos.x;
        sp34.z = this->dyna.actor.posRot.pos.z - 65.0f;
        func_80033480(globalCtx, &sp34, 5.0f, 1, 0x14, 0x3C, 1U);
    }
    if (this->unk169 == 5) {
        func_8002F974(&this->dyna.actor, NA_SE_EV_ELEVATOR_MOVE - SFX_FLAG);
    }
}

void func_80870F00(BgDdanJd* this, GlobalContext* globalCtx) {
    if ((this->unk169 == 1) && (this->dyna.actor.params < 0x40) &&
        Flags_GetSwitch(globalCtx, this->dyna.actor.params)) {
        this->unk169 = 5;
        this->unk168 = 1;
        this->dyna.actor.posRot.pos.y = this->dyna.actor.initPosRot.pos.y + 140.0f;
        this->unk16A = 0;
        this->actionFunc = func_80870B88;
        func_800800F8(globalCtx, 0xBF4, -0x63, &this->dyna.actor, 0);
    } else {
        if (Math_ApproxF(&this->dyna.actor.posRot.pos.y, this->unk16C, this->unk169)) {
            Audio_PlayActorSound2(&this->dyna.actor, NA_SE_EV_PILLAR_MOVE_STOP);
            this->actionFunc = func_80870B88;
        }
    }
    func_80870D2C(this, globalCtx);
}

void BgDdanJd_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgDdanJd* this = (BgDdanJd*)thisx;

    this->actionFunc(this, globalCtx);
}

void BgDdanJd_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgDdanJd* this = (BgDdanJd*)thisx;

    Gfx_DrawDListOpa(globalCtx, &D_60037B8);
}
