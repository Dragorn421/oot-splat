#include "global.h"
#include "ovl_Bg_Haka_Trap.h"

#define FLAGS 0

void BgHakaTrap_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTrap_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTrap_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTrap_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808801B8(BgHakaTrap* this, GlobalContext* globalCtx);
void func_808802D8(BgHakaTrap* this, GlobalContext* globalCtx);
void func_80880484(BgHakaTrap* this, GlobalContext* globalCtx);
void func_808806BC(BgHakaTrap* this, GlobalContext* globalCtx);
void func_808808F4(BgHakaTrap* this, GlobalContext* globalCtx);
void func_808809B0(BgHakaTrap* this, GlobalContext* globalCtx);

extern const ActorInit Bg_Haka_Trap_InitVars;
#if 0
const ActorInit Bg_Haka_Trap_InitVars = {
    /**/ ACTOR_BG_HAKA_TRAP,
    /**/ ACTORTYPE_BG,
    /**/ FLAGS,
    /**/ OBJECT_HAKA_OBJECTS,
    /**/ sizeof(BgHakaTrap),
    /**/ BgHakaTrap_Init,
    /**/ BgHakaTrap_Destroy,
    /**/ BgHakaTrap_Update,
    /**/ BgHakaTrap_Draw,
};
#endif

extern UNK_TYPE D_60081D0;
extern UNK_TYPE D_6008D10;
extern UNK_TYPE D_6009CD0;

extern s32 D_80880F30;
extern ColliderCylinderSrc D_80880F54;
extern ColliderTrisSrc D_80880FF8;
extern CollideDataInit D_80881008;
extern InitChainEntry D_80881010;
extern s32 D_80881014;
extern s32 D_80881018;

void BgHakaTrap_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32* new_var;
    BgHakaTrap* this = (BgHakaTrap*)thisx;
    s32 sp2C;

    sp2C = 0;
    Actor_ProcessInitChain(&this->dyna.actor, &D_80881010);
    this->dyna.actor.params &= 0xFF;
    new_var = &D_80881014;
    if (this->dyna.actor.params != 4) {
        Collider_InitCylinder(globalCtx, &this->unk178);
        Collider_LoadCylinder(globalCtx, &this->unk178, &this->dyna.actor, &D_80880F54);
        if ((this->dyna.actor.params == 0) || (this->dyna.actor.params == 5)) {
            this->unk168 = 0x14;
            do {
            } while (0);
            this->unk178.shape.yShift = 0xA;
            this->dyna.actor.velocity.y = 0.1f;
            if (this->dyna.actor.params == 5) {
                this->dyna.actor.params = 0;
                this->unk16A = 1;
            }
            this->unk164 = &func_80880484;
        } else {
            DynaPolyInfo_SetActorMove((DynaPolyActor*)this, DPM_PLAYER);
            this->dyna.actor.flags |= 0x10;
            if (this->dyna.actor.params == 1) {
                DynaPolyInfo_Alloc(&D_6009CD0, &sp2C);
                this->unk168 = 0x1E;
                if (*new_var != 0) {
                    this->unk164 = &func_808808F4;
                    D_80881014 = 0;
                } else {
                    D_80881014 = 1;
                    this->unk164 = &func_808806BC;
                    this->dyna.actor.velocity.y = 0.5f;
                }
                this->dyna.actor.unk_80 = this->dyna.actor.initPosRot.pos.y - 225.0f;
                this->unk16A = this->dyna.actor.unk_80 + 50.0f - 25.0f;
                this->unk178.shape.radius = 0xA;
                this->unk178.shape.height = 0x28;
            } else {
                if (this->dyna.actor.params == 2) {
                    DynaPolyInfo_Alloc(&D_60081D0, &sp2C);
                    this->dyna.actor.initPosRot.pos.x -= 200.0f;
                } else {
                    this->dyna.actor.initPosRot.pos.x += 200.0f;
                    DynaPolyInfo_Alloc(&D_6008D10, &sp2C);
                }
                func_8005C7E0(globalCtx, &this->unk1C4);
                Collider_LoadTris(globalCtx, (ColliderTris*)&this->unk1C4, &this->dyna.actor, &D_80880FF8,
                                  &this->unk1E4);
                this->unk178.shape.radius = 0x12;
                this->unk178.shape.height = 0x73;
                this->unk178.elem.atElemFlags |= 0;
                this->unk178.elem.atElemFlags |= 0x10;
                this->unk164 = &func_808801B8;
            }
            this->dyna.dynaPolyId =
                DynaPolyInfo_RegisterActor(globalCtx, &globalCtx->colCtx.dyna, &this->dyna.actor, sp2C);
        }
    } else {
        this->unk168 = 0x28;
        this->unk164 = &func_808809B0;
        this->dyna.actor.unk_F8 = 500.0f;
    }
    func_80061ED4(&this->dyna.actor.collideData, NULL, &D_80881008);
}

void BgHakaTrap_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaTrap* this = (BgHakaTrap*)thisx;

    if (this->dyna.actor.params != 4) {
        if (this->dyna.actor.params != 0) {
            DynaPolyInfo_Free(globalCtx, &globalCtx->colCtx.dyna, this->dyna.dynaPolyId);
            if ((this->dyna.actor.params == 2) || (this->dyna.actor.params == 3)) {
                func_8005C8C8(globalCtx, (struct_8005C8C8*)&this->unk1C4);
            }
        }
        Collider_DestroyCylinder(globalCtx, &this->unk178);
    }
    func_800F89E8(&this->unk16C);
}

void func_8087FFC0(BgHakaTrap* this, GlobalContext* globalCtx) {
    f32 temp_fv0_cosShapeRotY;
    Vec3f sp28;
    f32 sp24_sinShapeRotY;
    Player* player = PLAYER;

    func_8002DBD0(&this->dyna.actor, &sp28, &player->actor.posRot.pos);
    sp24_sinShapeRotY = Math_Sins(this->dyna.actor.shape.rot.y);
    temp_fv0_cosShapeRotY = Math_Coss(this->dyna.actor.shape.rot.y);
    if (this->dyna.actor.params == 0) {
        sp28.x = CLAMP(sp28.x, -50.0f, 50.0f);
        sp28.z = ((sp28.z >= 0.0f) ? 1.0f : -1.0f) * -15.0f;
    } else {
        sp28.x = -CLAMP(sp28.x, -162.0f, 162.0f);
        sp28.z = ((sp28.z >= 0.0f) ? 1.0f : -1.0f) * 15.0f;
    }
    this->unk178.shape.pos.x =
        this->dyna.actor.posRot.pos.x + (sp28.x * temp_fv0_cosShapeRotY) + (sp28.z * sp24_sinShapeRotY);
    this->unk178.shape.pos.z =
        this->dyna.actor.posRot.pos.z + (sp28.x * sp24_sinShapeRotY) + (sp28.z * temp_fv0_cosShapeRotY);
}

#if 0
// need import data for in-function data
void func_808801B8(BgHakaTrap* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;

    if ((D_80880F30 == 0) && (func_8008E988(globalCtx) == 0)) {
        if (Math_ApproxF(&this->dyna.actor.posRot.pos.x, this->dyna.actor.initPosRot.pos.x, 0.5f) == 0) {
            func_8002F974(&this->dyna.actor, 0x2058U);
        } else {
            if (this->dyna.actor.params == 2) {
                D_80881018 |= 1;
            } else if (this->dyna.actor.params == 3) {
                D_80881018 |= 2;
            }
        }
    }
    func_8087FFC0(this, globalCtx);
    if (this->unk1C4.unk0.acFlags & 2) {
        this->unk168 = 0x14;
        D_80880F30 = 1;
        this->unk164 = func_808802D8;
    } else if (D_80881018 == 3) {
        D_80881018 = 4;
        player->actor.bgCheckFlags |= 0x100;
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808801B8.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808802D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_80880484.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808805C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808806BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808808F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808809B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808809E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_80880AE8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_80880C0C.s")

void BgHakaTrap_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaTrap* this = (BgHakaTrap*)thisx;
    s32 pad;

    this->unk164(this, globalCtx);

    if ((thisx->params != 4) && (thisx->params != 1)) {
        this->unk178.shape.pos.y = this->dyna.actor.posRot.pos.y;
        if ((thisx->params == 0) || (thisx->params == 5)) {
            Collider_AddAC(globalCtx, &globalCtx->colliderCtx, &this->unk178.base);
            Collider_AddOC(globalCtx, &globalCtx->colliderCtx, &this->unk178.base);
        } else {
            if (this->unk164 == func_808801B8) {
                Collider_AddAC(globalCtx, &globalCtx->colliderCtx, &this->unk1C4.unk0);
            }
            Collider_AddAT(globalCtx, &globalCtx->colliderCtx, &this->unk178.base);
        }
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_80880D68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/BgHakaTrap_Draw.s")
