#include "global.h"
#include "ovl_Bg_Haka_Trap.h"

#define FLAGS 0

void BgHakaTrap_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTrap_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTrap_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTrap_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808801B8();
void func_80880484();
void func_808806BC();
void func_808808F4();
void func_808809B0();

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

extern ColliderCylinderSrc D_80880F54;
extern ColliderTrisSrc D_80880FF8;
extern CollideDataInit D_80881008;
extern InitChainEntry D_80881010;
extern s32 D_80881014;

void BgHakaTrap_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32* new_var;
    BgHakaTrap* this = (BgHakaTrap*)thisx;
    s32 sp2C;

    sp2C = 0;
    Actor_ProcessInitChain(&this->actor, &D_80881010);
    this->actor.params &= 0xFF;
    new_var = &D_80881014;
    if (this->actor.params != 4) {
        Collider_InitCylinder(globalCtx, &this->unk178);
        Collider_LoadCylinder(globalCtx, &this->unk178, &this->actor, &D_80880F54);
        if ((this->actor.params == 0) || (this->actor.params == 5)) {
            this->unk168 = 0x14;
            do {
            } while (0);
            this->unk178.shape.yShift = 0xA;
            this->actor.velocity.y = 0.1f;
            if (this->actor.params == 5) {
                this->actor.params = 0;
                this->unk16A = 1;
            }
            this->unk164 = &func_80880484;
        } else {
            DynaPolyInfo_SetActorMove((DynaPolyActor*)this, DPM_PLAYER);
            this->actor.flags |= 0x10;
            if (this->actor.params == 1) {
                DynaPolyInfo_Alloc(&D_6009CD0, &sp2C);
                this->unk168 = 0x1E;
                if (*new_var != 0) {
                    this->unk164 = &func_808808F4;
                    D_80881014 = 0;
                } else {
                    D_80881014 = 1;
                    this->unk164 = &func_808806BC;
                    this->actor.velocity.y = 0.5f;
                }
                this->actor.unk_80 = this->actor.initPosRot.pos.y - 225.0f;
                this->unk16A = this->actor.unk_80 + 50.0f - 25.0f;
                this->unk178.shape.radius = 0xA;
                this->unk178.shape.height = 0x28;
            } else {
                if (this->actor.params == 2) {
                    DynaPolyInfo_Alloc(&D_60081D0, &sp2C);
                    this->actor.initPosRot.pos.x -= 200.0f;
                } else {
                    this->actor.initPosRot.pos.x += 200.0f;
                    DynaPolyInfo_Alloc(&D_6008D10, &sp2C);
                }
                func_8005C7E0(globalCtx, &this->unk1C4);
                Collider_LoadTris(globalCtx, (ColliderTris*)&this->unk1C4, &this->actor, &D_80880FF8, &this->unk1E4);
                this->unk178.shape.radius = 0x12;
                this->unk178.shape.height = 0x73;
                this->unk178.elem.atElemFlags |= 0;
                this->unk178.elem.atElemFlags |= 0x10;
                this->unk164 = &func_808801B8;
            }
            this->unk14C = DynaPolyInfo_RegisterActor(globalCtx, &globalCtx->colCtx.dyna, &this->actor, sp2C);
        }
    } else {
        this->unk168 = 0x28;
        this->unk164 = &func_808809B0;
        this->actor.unk_F8 = 500.0f;
    }
    func_80061ED4(&this->actor.collideData, NULL, &D_80881008);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/BgHakaTrap_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_8087FFC0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808801B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808802D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_80880484.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808805C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808806BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808808F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808809B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808809E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_80880AE8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_80880C0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/BgHakaTrap_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_80880D68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/BgHakaTrap_Draw.s")
