#include "z_bg_spot08_iceblock.h"

#define FLAGS 0x00000000

#define THIS ((BgSpot08Iceblock*)thisx)

void BgSpot08Iceblock_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot08Iceblock_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot08Iceblock_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot08Iceblock_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808B0960(BgSpot08Iceblock* this, void (*arg1)(BgSpot08Iceblock*, GlobalContext*));
void func_808B0968(BgSpot08Iceblock* this, GlobalContext* globalCtx, CollisionHeader* arg2, s32 arg3);
void func_808B09F0(BgSpot08Iceblock* this);
void func_808B0A84(BgSpot08Iceblock* this);
void func_808B0AE0(BgSpot08Iceblock* this);
void func_808B0B8C(BgSpot08Iceblock* this);
void func_808B0BA8(Vec3f* arg0, Vec3f* arg1, f32 arg2);
void func_808B0BD4(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2);
s32 func_808B0C44(Vec3f* arg0, Vec3f* arg1);
void func_808B0CE0(BgSpot08Iceblock* this, GlobalContext* globalCtx);
void func_808B1054(BgSpot08Iceblock* this, GlobalContext* globalCtx);
void func_808B1388(BgSpot08Iceblock* this);
void func_808B13AC(BgSpot08Iceblock* this, GlobalContext* globalCtx);
void func_808B13FC(BgSpot08Iceblock* this);
void func_808B1420(BgSpot08Iceblock* this, GlobalContext* globalCtx);
void func_808B147C(BgSpot08Iceblock* this);
void func_808B14A0(BgSpot08Iceblock* this, GlobalContext* globalCtx);
void func_808B1574(BgSpot08Iceblock* this);

extern Gfx D_6000DE0[];
extern CollisionHeader D_6001904;
extern Gfx D_6002BD0[];
extern CollisionHeader D_6002FD8;

const ActorInit Bg_Spot08_Iceblock_InitVars = {
    ACTOR_BG_SPOT08_ICEBLOCK,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT08_OBJ,
    sizeof(BgSpot08Iceblock),
    (ActorFunc)BgSpot08Iceblock_Init,
    (ActorFunc)BgSpot08Iceblock_Destroy,
    (ActorFunc)BgSpot08Iceblock_Update,
    (ActorFunc)BgSpot08Iceblock_Draw,
};

static Vec3f D_808B16B0 = { 0.0f, 1.0f, 0.0f };
static Vec3f D_808B16BC = { 0.0f, 0.0f, 0.0f };
static f32 D_808B16C8[3] = { 1.4285714e-8f, 5.714286e-9f, 1.4285715e-9f };
static f32 D_808B16D4[3] = { 0.96f, 0.96f, 0.98f };
static f32 D_808B16E0[3] = { 0.22495104f, 0.22495104f, 0.03489947f };
static f32 D_808B16EC[3] = { 0.97437006f, 0.97437006f, 0.99939084f };
static InitChainEntry D_808B16F8[] = {
    ICHAIN_F32(uncullZoneForward, 3000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 2200, ICHAIN_STOP),
};

void func_808B0960(BgSpot08Iceblock* this, void (*arg1)(BgSpot08Iceblock*, GlobalContext*)) {
    this->unk164 = arg1;
}

void func_808B0968(BgSpot08Iceblock* this, GlobalContext* globalCtx, CollisionHeader* arg2, s32 arg3) {
    s32 pad;
    CollisionHeader* sp30;
    s32 pad2;

    sp30 = NULL;
    DynaPolyActor_Init(&this->dyna, arg3);
    CollisionHeader_GetVirtual(arg2, &sp30);
    this->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &this->dyna.actor, sp30);
    if (this->dyna.bgId == 0x32) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_spot08_iceblock.c", 0xD9,
                     this->dyna.actor.id, (s32)this->dyna.actor.params);
    }
}

void func_808B09F0(BgSpot08Iceblock* this) {
    s16 temp_a3;
    s32 temp_v0;

    temp_a3 = this->dyna.actor.params;
    temp_v0 = temp_a3 & 0xFF;
    switch (temp_v0) { /* irregular */
        case 0xFF:
            this->dyna.actor.params = 0x10;
            return;
        default:
        case 0x2:
        case 0x3:
        case 0x5:
        case 0x6:
        case 0x7:
        case 0x8:
        case 0x9:
        case 0xA:
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
        case 0x13:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x21:
        case 0x22:
            osSyncPrintf("Error : arg_data 設定ミスです。(%s %d)(arg_data 0x%04x)\n", "../z_bg_spot08_iceblock.c", 0xF6,
                         temp_a3);
            this->dyna.actor.params = 0x10;
            /* fallthrough */
        case 0x1:
        case 0x4:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x14:
        case 0x20:
        case 0x23:
        case 0x24:
            return;
    }
}

void func_808B0A84(BgSpot08Iceblock* this) {
    f32 sp1C;

    sp1C = Math_SinS(this->unk18C);
    this->unk198 = (Math_SinS(this->unk18E) * 3.0f) + (sp1C * 4.0f);
}

void func_808B0AE0(BgSpot08Iceblock* this) {
    f32 var_fv0;
    f32 sp18;
    s32 temp_v0;

    temp_v0 = this->dyna.actor.params & 0xF0;
    switch (temp_v0) { /* irregular */
        case 0:
            sp18 = 0.15f;
            break;
        case 16:
            sp18 = 0.2f;
            break;
        case 32:
            sp18 = 0.4f;
            break;
    }
    if (func_80043548(&this->dyna) != 0) {
        var_fv0 = -4.0f;
    } else {
        var_fv0 = 0.0f;
    }
    Math_StepToF(&this->unk194, var_fv0, sp18);
}

void func_808B0B8C(BgSpot08Iceblock* this) {
    this->dyna.actor.world.pos.y = this->unk194 + this->unk198 + this->dyna.actor.home.pos.y;
}

void func_808B0BA8(Vec3f* arg0, Vec3f* arg1, f32 arg2) {
    arg0->x = arg1->x * arg2;
    arg0->y = arg1->y * arg2;
    arg0->z = arg1->z * arg2;
}

void func_808B0BD4(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    arg0->x = (arg1->y * arg2->z) - (arg1->z * arg2->y);
    arg0->y = (arg1->z * arg2->x) - (arg1->x * arg2->z);
    arg0->z = (arg1->x * arg2->y) - (arg1->y * arg2->x);
}

s32 func_808B0C44(Vec3f* arg0, Vec3f* arg1) {
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 = Math3D_Vec3fMagnitude(arg1);
    if (temp_fv0 < 0.001f) {
        arg0->y = 0.0f;
        arg0->x = 0.0f;
        arg0->z = 1.0f;
        return 0;
    }
    temp_fv1 = 1.0f / temp_fv0;
    arg0->x = arg1->x * temp_fv1;
    arg0->y = arg1->y * temp_fv1;
    arg0->z = arg1->z * temp_fv1;
    return 1;
}

void func_808B0CE0(BgSpot08Iceblock* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;
    s32 pad;
    Vec3f spD4;
    Vec3f spC8;
    Vec3f spBC;
    Vec3f spB0;
    Vec3f spA4;
    Vec3f sp98;
    Vec3f sp8C;
    f32 sp88;
    s32 sp84;
    MtxF sp44;
    f32 temp_fv0_2;
    f32 temp_fv1;

    switch (this->dyna.actor.params & 0xFF) {
        case 0x11:
            sp84 = 0;
            break;
        case 1:
            sp84 = 1;
            break;
        default:
            sp84 = 2;
            break;
    }
    Math_Vec3f_Diff(&player->actor.world.pos, &this->dyna.actor.world.pos, &spC8);
    spC8.y -= 150.0f * this->dyna.actor.scale.y;
    sp88 = Math3D_Vec3fMagnitude(&spC8);
    spA4.x = (Rand_ZeroOne() - 0.5f) * 0.0016f;
    spA4.y = 0.0f;
    spA4.z = (Rand_ZeroOne() - 0.5f) * 0.0016f;
    spD4.x = this->unk168.x;
    spD4.y = 0.0f;
    spD4.z = this->unk168.z;
    if ((func_8004356C(&this->dyna) != 0) && (sp88 > 3.0f)) {
        Math_Vec3f_Diff(&spC8, (Vec3f*)&spD4, &spBC);
        func_808B0BA8(&spBC, &spBC, (D_808B16C8[sp84] * sp88) / this->dyna.actor.scale.x);
    } else {
        spBC = D_808B16BC;
    }
    func_808B0BA8(&spB0, (Vec3f*)&spD4, -0.01f);
    Math_Vec3f_Sum(&this->unk174, &spBC, &this->unk174);
    Math_Vec3f_Sum(&this->unk174, &spB0, &this->unk174);
    Math_Vec3f_Sum(&this->unk174, (Vec3f*)&spA4, &this->unk174);
    this->unk174.y = 0.0f;
    Math_Vec3f_Sum(&this->unk168, &this->unk174, &sp98);
    sp98.x *= D_808B16D4[sp84];
    sp98.z *= D_808B16D4[sp84];
    if (func_808B0C44(&this->unk168, &sp98) != 0) {
        temp_fv0_2 = Math3D_Dist1DSq(this->unk168.z, this->unk168.x);
        if (D_808B16E0[sp84] < temp_fv0_2) {
            temp_fv1 = D_808B16E0[sp84] / temp_fv0_2;
            this->unk168.x *= temp_fv1;
            this->unk168.y = D_808B16EC[sp84];
            this->unk168.z *= temp_fv1;
        }
        func_808B0BD4(&sp98, &D_808B16B0, &this->unk168);
        if (func_808B0C44(&sp8C, &sp98) != 0) {
            this->unk180 = sp8C;
        }
    } else {
        this->unk168 = D_808B16B0;
    }
    func_800D23FC(Math_FAcosF(Math3D_Cos(&D_808B16B0, &this->unk168)), (Vec3f*)&this->unk180, 0U);
    Matrix_RotateY((f32)this->dyna.actor.shape.rot.y * 0.0000958738f, 1U);
    Matrix_Get(&sp44);
    func_800D20CC(&sp44, &this->dyna.actor.shape.rot, 0);
}

void func_808B1054(BgSpot08Iceblock* this, GlobalContext* globalCtx) {
    s32 pad[2];
    f32 sp44;
    f32 temp_fv1;

    sp44 = Math_SinS(this->dyna.actor.home.rot.y) * 100.0f;
    temp_fv1 = Math_CosS(this->dyna.actor.home.rot.y) * 100.0f;
    if (!(this->dyna.actor.params & 0x100)) {
        Actor_SpawnAsChild(&globalCtx->actorCtx, &this->dyna.actor, globalCtx, 0xD1, this->dyna.actor.home.pos.x,
                           this->dyna.actor.home.pos.y, this->dyna.actor.home.pos.z,
                           (s16)(s32)this->dyna.actor.home.rot.x, (s16)(s32)this->dyna.actor.home.rot.y,
                           (s16)(s32)this->dyna.actor.home.rot.z, 0x123);
        this->dyna.actor.world.pos.x += sp44;
        this->dyna.actor.world.pos.z += temp_fv1;
    } else {
        this->dyna.actor.world.pos.x -= sp44;
        this->dyna.actor.world.pos.z -= temp_fv1;
    }
    func_808B147C(this);
}

void BgSpot08Iceblock_Init(Actor* thisx, GlobalContext* globalCtx) {
    s16 temp_v1;
    CollisionHeader* var_a2;
    s32 temp_v0;
    s32 temp_v0_2;
    BgSpot08Iceblock* this = (BgSpot08Iceblock*)thisx;

    osSyncPrintf("(spot08 流氷)(arg_data 0x%04x)\n", this->dyna.actor.params);
    func_808B09F0(this);
    switch (this->dyna.actor.params & 0x200) {
        case 0:
            var_a2 = &D_6002FD8;
            break;

        case 0x200:
            var_a2 = &D_6001904;
            break;
    }
    temp_v0_2 = this->dyna.actor.params & 0xF;
    if ((temp_v0_2 == 2) || (temp_v0_2 == 3)) {
        func_808B0968(this, globalCtx, var_a2, DPM_UNK3);
    } else {
        func_808B0968(this, globalCtx, var_a2, DPM_UNK);
    }
    if (LINK_AGE_IN_YEARS == YEARS_CHILD) {
        Actor_Kill(&this->dyna.actor);
        return;
    }
    Actor_ProcessInitChain(&this->dyna.actor, D_808B16F8);
    switch (this->dyna.actor.params & 0xF0) {
        case 0:
            Actor_SetScale(&this->dyna.actor, 0.2f);
            break;
        case 0x10:
            Actor_SetScale(&this->dyna.actor, 0.1f);
            break;
        case 0x20:
            Actor_SetScale(&this->dyna.actor, 0.05f);
            break;
    }
    this->unk18C = (s16)(s32)(Rand_ZeroOne() * 65535.5f);
    this->unk18E = (s16)(s32)(Rand_ZeroOne() * 65535.5f);
    this->unk168.y = 1.0f;
    this->unk180.x = 1.0f;
    switch (this->dyna.actor.params & 0xF) {
        case 0:
        case 1:
            func_808B1388(this);
            return;
        case 2:
            func_808B13FC(this);
            return;
        case 3:
            func_808B1054(this, globalCtx);
            return;
        case 4:
            func_808B1574(this);
            /* fallthrough */
        default:
            return;
    }
}

void BgSpot08Iceblock_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot08Iceblock* this = (BgSpot08Iceblock*)thisx;
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, this->dyna.bgId);
}

void func_808B1388(BgSpot08Iceblock* this) {
    func_808B0960(this, func_808B13AC);
}

void func_808B13AC(BgSpot08Iceblock* this, GlobalContext* globalCtx) {
    func_808B0A84(this);
    func_808B0AE0(this);
    func_808B0B8C(this);
    this->dyna.actor.shape.rot.y = this->dyna.actor.home.rot.y;
    func_808B0CE0(this, globalCtx);
}

void func_808B13FC(BgSpot08Iceblock* this) {
    func_808B0960(this, func_808B1420);
}

void func_808B1420(BgSpot08Iceblock* this, GlobalContext* globalCtx) {
    func_808B0A84(this);
    func_808B0AE0(this);
    func_808B0B8C(this);
    this->dyna.actor.world.rot.y += 0x190;
    this->dyna.actor.shape.rot.y = this->dyna.actor.world.rot.y;
    func_808B0CE0(this, globalCtx);
}

void func_808B147C(BgSpot08Iceblock* this) {
    func_808B0960(this, func_808B14A0);
}

void func_808B14A0(BgSpot08Iceblock* this, GlobalContext* globalCtx) {
    f32 temp_fa0;
    f32 temp_fv1;

    func_808B0A84(this);
    func_808B0AE0(this);
    func_808B0B8C(this);
    if (!(this->dyna.actor.params & 0x100)) {
        this->dyna.actor.world.rot.y += 0x190;
        temp_fv1 = Math_SinS(this->dyna.actor.world.rot.y) * 100.0f;
        temp_fa0 = Math_CosS(this->dyna.actor.world.rot.y) * 100.0f;
        this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x + temp_fv1;
        this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z + temp_fa0;
        if (this->dyna.actor.child != NULL) {
            this->dyna.actor.child->world.pos.x = this->dyna.actor.home.pos.x - temp_fv1;
            this->dyna.actor.child->world.pos.z = this->dyna.actor.home.pos.z - temp_fa0;
        }
    }
    this->dyna.actor.shape.rot.y = this->dyna.actor.home.rot.y;
    func_808B0CE0(this, globalCtx);
}

void func_808B1574(BgSpot08Iceblock* this) {
    func_808B0960(this, NULL);
}

void BgSpot08Iceblock_Update(Actor* thisx, GlobalContext* globalCtx) {
    void (*temp_v0)(BgSpot08Iceblock*, GlobalContext*);
    BgSpot08Iceblock* this = (BgSpot08Iceblock*)thisx;

    if (Rand_ZeroOne() < 0.05f) {
        this->unk190 = Rand_S16Offset(0x12C, 0x64);
        this->unk192 = Rand_S16Offset(0x320, 0x190);
    }
    temp_v0 = this->unk164;
    this->unk18C += this->unk190;
    this->unk18E += this->unk192;
    if (temp_v0 != NULL) {
        temp_v0(this, globalCtx);
    }
}

void BgSpot08Iceblock_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx* sp1C;
    s32 temp_v0;
    BgSpot08Iceblock* this = (BgSpot08Iceblock*)thisx;

    temp_v0 = this->dyna.actor.params & 0x200;
    switch (temp_v0) { /* irregular */
        case 0x0:
            sp1C = D_6002BD0;
            break;
        case 0x200:
            sp1C = D_6000DE0;
            break;
    }
    Gfx_DrawDListOpa(globalCtx, sp1C);
}
