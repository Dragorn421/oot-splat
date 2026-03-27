#include "z_demo_ext.h"

#define FLAGS 0x00000010

#define THIS ((DemoExt*)thisx)

void DemoExt_Init(Actor* thisx, GlobalContext* globalCtx);
void DemoExt_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DemoExt_Update(Actor* thisx, GlobalContext* globalCtx);
void DemoExt_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80977450(DemoExt* arg0);
CsCmdActorAction* func_809774D8(GlobalContext* arg0, s32 arg1);
void func_809774FC(DemoExt* arg0);
void func_80977508(DemoExt* arg0, GlobalContext* arg1);
void func_80977590(DemoExt* arg0);
void func_809775A4(DemoExt* arg0);
void func_80977610(DemoExt* arg0, GlobalContext* arg1);
void func_809776D0(DemoExt* arg0);
void func_8097771C(DemoExt* arg0);
void func_80977854(DemoExt*, GlobalContext*);
void func_80977874(DemoExt* arg0, GlobalContext* arg1);
void func_809778AC(DemoExt* arg0, GlobalContext* arg1);
void func_80977944(DemoExt* arg0, GlobalContext* arg1);
void func_80977950(DemoExt* arg0, GlobalContext* arg1);

extern Gfx D_600FAA0[];

void (*D_80977C70[3])(DemoExt*, GlobalContext*) = {
    func_80977854,
    func_80977874,
    func_809778AC,
};
void (*D_80977C7C[2])(DemoExt*, GlobalContext*) = {
    func_80977944,
    func_80977950,
};
const ActorInit Demo_Ext_InitVars = {
    ACTOR_DEMO_EXT,
    ACTORTYPE_NPC,
    FLAGS,
    OBJECT_FHG,
    sizeof(DemoExt),
    (ActorFunc)DemoExt_Init,
    (ActorFunc)DemoExt_Destroy,
    (ActorFunc)DemoExt_Update,
    (ActorFunc)DemoExt_Draw,
};

void DemoExt_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    DemoExt* this = (DemoExt*)thisx;
}

void DemoExt_Init(Actor* thisx, GlobalContext* globalCtx) {
    DemoExt* this = (DemoExt*)thisx;
    this->unk158[0] = 0x19;
    this->unk158[1] = 0x28;
    this->unk158[2] = 5;
    this->unk158[3] = 0x1E;
    this->unk170 = gGameInfo->data[0xA3C] + 0xFF;
    this->unk174 = gGameInfo->data[0xA40] + 0xFF;
    this->unk178.x = (f32)gGameInfo->data[0xA33] + 400.0f;
    this->unk178.y = (f32)gGameInfo->data[0xA34] + 100.0f;
    this->unk178.z = (f32)gGameInfo->data[0xA35] + 400.0f;
}

void func_80977450(DemoExt* arg0) {
    if (arg0->unk16C <= (((f32)gGameInfo->data[0xA43] + 40.0f) - 15.0f)) {
        Audio_PlaySoundGeneral(0x2040U, &arg0->actor.projectedPos, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
    }
}

CsCmdActorAction* func_809774D8(GlobalContext* arg0, s32 arg1) {
    if (arg0->csCtx.state != 0) {
        return arg0->csCtx.npcActions[arg1];
    }
    return NULL;
}

void func_809774FC(DemoExt* arg0) {
    arg0->unk14C = 0;
    arg0->unk150 = 0;
}

void func_80977508(DemoExt* arg0, GlobalContext* arg1) {
    CsCmdActorAction* temp_v0;
    s16 temp_v1;

    temp_v0 = func_809774D8(arg1, 5);
    if (temp_v0 != NULL) {
        arg0->actor.posRot.pos.x = (f32)temp_v0->startPos.x;
        arg0->actor.posRot.pos.y = (f32)temp_v0->startPos.y;
        arg0->actor.posRot.pos.z = (f32)temp_v0->startPos.z;
        temp_v1 = temp_v0->rot.y;
        arg0->actor.shape.rot.y = temp_v1;
        arg0->actor.posRot.rot.y = temp_v1;
    }
    arg0->unk14C = 1;
    arg0->unk150 = 1;
}

void func_80977590(DemoExt* arg0) {
    arg0->unk14C = 2;
    arg0->unk150 = 1;
}

void func_809775A4(DemoExt* arg0) {
    arg0->unk16C += 1.0f;
    if (((f32)gGameInfo->data[0xA43] + 40.0f) <= arg0->unk16C) {
        Actor_Kill(&arg0->actor);
    }
}

void func_80977610(DemoExt* arg0, GlobalContext* arg1) {
    CsCmdActorAction* temp_v0;
    s32 temp_a2;
    s32 v;

    temp_v0 = func_809774D8(arg1, 5);
    if (temp_v0 != NULL) {
        temp_a2 = temp_v0->action;
        v = arg0->unk154;
        if (temp_a2 != v) {
            switch (temp_a2) {
                case 1:
                    func_809774FC(arg0);
                    break;
                case 2:
                    func_80977508(arg0, arg1);
                    break;
                case 3:
                    func_80977590(arg0);
                    break;
                default:
                    osSyncPrintf("Demo_Ext_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
                    break;
            }
            arg0->unk154 = temp_a2;
        }
    }
}

void func_809776D0(DemoExt* arg0) {
    s16* p1 = arg0->unk160;
    s16* p2 = arg0->unk158;
    s32 var_v0;

    for (var_v0 = 3; var_v0 != 0; var_v0--) {
        p1[var_v0] += p2[var_v0];
    }
    arg0->unk168 += (s16)(gGameInfo->data[0xA42] + 0x3E8);
}

void func_8097771C(DemoExt* arg0) {
    Vec3f* temp_v0;
    f32 var_fv0;

    temp_v0 = &arg0->unk178;
    var_fv0 = (((f32)gGameInfo->data[0xA43] + 40.0f) - arg0->unk16C) / ((f32)gGameInfo->data[0xA43] + 40.0f);
    if (var_fv0 < 0.0f) {
        var_fv0 = 0.0f;
    }
    arg0->unk170 = (s32)((u32)(gGameInfo->data[0xA3C] + 0xFF) * var_fv0);
    arg0->unk174 = (s32)((u32)(gGameInfo->data[0xA40] + 0xFF) * var_fv0);
    temp_v0->x = ((f32)gGameInfo->data[0xA33] + 400.0f) * var_fv0;
    temp_v0->y = (f32)(((f32)gGameInfo->data[0xA34] + 100.0f) * var_fv0);
    temp_v0->z = (f32)(((f32)gGameInfo->data[0xA35] + 400.0f) * var_fv0);
}

void func_80977854(DemoExt* arg0, GlobalContext* arg1) {
    func_80977610(arg0, arg1);
}

void func_80977874(DemoExt* arg0, GlobalContext* arg1) {
    func_80977450(arg0);
    func_809776D0(arg0);
    func_80977610(arg0, arg1);
}

void func_809778AC(DemoExt* arg0, GlobalContext* arg1) {
    func_80977450(arg0);
    func_809776D0(arg0);
    func_8097771C(arg0);
    func_809775A4(arg0);
}

void DemoExt_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 temp_v0;
    void (*temp_v1)(DemoExt*, GlobalContext*);
    DemoExt* this = (DemoExt*)thisx;

    temp_v0 = this->unk14C;
    if ((temp_v0 < 0) || (temp_v0 >= 3) || (temp_v1 = D_80977C70[temp_v0], (temp_v1 == NULL))) {
        osSyncPrintf("\x1b[31mメインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n\x1b[m");
        return;
    }
    temp_v1(this, globalCtx);
}

void func_80977944(DemoExt* arg0, GlobalContext* arg1) {
}

void func_80977950(DemoExt* arg0, GlobalContext* arg1) {
    GraphicsContext* temp_s0;
    Mtx* sp80;
    Vec3f* temp_v0;
    s16* temp_v0_2;
    s32 pad;

    temp_s0 = arg1->state.gfxCtx;
    temp_v0_2 = arg0->unk160;
    temp_v0 = &arg0->unk178;
    sp80 = Graph_Alloc(temp_s0, 0x40U);
    OPEN_DISPS(temp_s0, "../z_demo_ext.c", 0x1CC);
    Matrix_Push();
    Matrix_Scale(temp_v0->x, temp_v0->y, temp_v0->z, 1U);
    Matrix_RotateRPY((s16)(gGameInfo->data[0xA30] + 0x4000), arg0->unk168, gGameInfo->data[0xA32], 1U);
    Matrix_Translate((f32)gGameInfo->data[0xA36], (f32)gGameInfo->data[0xA37], (f32)gGameInfo->data[0xA38], 1U);
    Matrix_ToMtx(sp80, "../z_demo_ext.c", 0x1DC);
    Matrix_Pull();
    func_80093D84(temp_s0);
    gDPSetPrimColor(POLY_XLU_DISP++, 0x00, gGameInfo->data[0xA41] + 0x80, gGameInfo->data[0xA39] + 0x8C,
                    gGameInfo->data[0xA3A] + 0x50, gGameInfo->data[0xA3B] + 0x8C, arg0->unk170);
    gDPSetEnvColor(POLY_XLU_DISP++, gGameInfo->data[0xA3D] + 0x5A, gGameInfo->data[0xA3E] + 0x32,
                   gGameInfo->data[0xA3F] + 0x5F, arg0->unk174);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(temp_s0, 0, (u32)temp_v0_2[0], (u32)temp_v0_2[1], 0x40, 0x40, 1, (u32)temp_v0_2[2],
                                (u32)temp_v0_2[3], 0x40, 0x40));
    gSPMatrix(POLY_XLU_DISP++, sp80, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, D_600FAA0);
    gSPPopMatrix(POLY_XLU_DISP++, G_MTX_MODELVIEW);
    CLOSE_DISPS(temp_s0, "../z_demo_ext.c", 0x200);
}

void DemoExt_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 temp_v0;
    void (*temp_v1)(DemoExt*, GlobalContext*);
    DemoExt* this = (DemoExt*)thisx;

    temp_v0 = this->unk150;
    if ((temp_v0 < 0) || (temp_v0 >= 2) || (temp_v1 = D_80977C7C[temp_v0], (temp_v1 == NULL))) {
        osSyncPrintf("\x1b[31m描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n\x1b[m");
        return;
    }
    temp_v1(this, globalCtx);
}
