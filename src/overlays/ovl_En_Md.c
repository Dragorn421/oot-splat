#include "global.h"
#include "ovl_En_Md.h"

void EnMd_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMd_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMd_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMd_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 func_80AAB03C(EnMd*, GlobalContext*);
void func_80AAB4DC(EnMd*, GlobalContext*);
void func_80AAB874(EnMd*, GlobalContext*);
void func_80AAB948(EnMd*, GlobalContext*);

extern SkeletonHeader D_6007FB8;

extern ColliderCylinderSrc D_80AAC310;
extern CollideDataInitAlt D_80AAC33C;
extern struct_80034EC0_Entry D_80AAC348[];

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA250.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA274.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA308.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA39C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA474.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA508.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA5A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA638.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA6D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA768.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA7FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA890.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA92C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAA93C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAAA24.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAAC78.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAACF8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAADE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAAE14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAAE94.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAAF04.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAB03C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAB0E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAB158.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAB370.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAB4DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAB5A4.s")

void EnMd_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnMd* this = (EnMd*)thisx;
    s32 pad;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 24.0f);
    SkelAnime_InitSV(globalCtx, &this->unk14C, &D_6007FB8, NULL, this->unk258, this->unk2BE, 0x11);
    Collider_InitCylinder(globalCtx, &this->unk194);
    Collider_LoadCylinder(globalCtx, &this->unk194, &this->actor, &D_80AAC310);
    func_80061EFC(&this->actor.collideData, NULL, &D_80AAC33C);
    if (func_80AAB03C(this, globalCtx) == 0) {
        Actor_Kill(&this->actor);
        return;
    }
    func_80034EC0(&this->unk14C, D_80AAC348, 0);
    Actor_SetScale(&this->actor, 0.01f);
    this->actor.unk_1F = 6;
    this->unk210 = 0xFF;
    Actor_SpawnAttached(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_EN_ELF, this->actor.posRot.pos.x,
                        this->actor.posRot.pos.y, this->actor.posRot.pos.z, 0, 0, 0, 3);
    if (((globalCtx->sceneNum == SCENE_SPOT04) && !(gSaveContext.eventChkInf[0] & 0x10)) ||
        ((globalCtx->sceneNum == SCENE_SPOT04) && (gSaveContext.eventChkInf[0] & 0x10) &&
         (gBitFlags[0x12] & gSaveContext.questItems)) ||
        ((globalCtx->sceneNum == SCENE_SPOT10) && !(gSaveContext.eventChkInf[0] & 0x400))) {
        this->actor.initPosRot.pos = this->actor.posRot.pos;
        this->unk190 = func_80AAB948;
    } else {
        if (globalCtx->sceneNum != SCENE_KOKIRI_HOME4) {
            func_80AAB4DC(this, globalCtx);
        }
        this->unk190 = func_80AAB874;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/EnMd_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAB874.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAB8F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAB948.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AABC10.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AABD0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/EnMd_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AABEF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/func_80AAC104.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Md/EnMd_Draw.s")
