#include <ultra64.h>
#include <global.h>

void func_8005B280(GraphicsContext* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {
    func_8005B2AC(arg0, arg1, arg2, arg3, 0xFFU, 0U, 0U);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005B2AC.s")

extern Collider D_8011DE00;

s32 func_8005B65C_InitColliderDefault(GlobalContext* arg0, Collider* arg1) {
    *arg1 = D_8011DE00;
    return 1;
}

// multi-type
s32 func_8005B6A0(GlobalContext* globalCtx, Collider* collision) {
    return 1;
}

typedef struct struct_8005B6B0_arg1 {
    s32 unk0;
    char unk_4[0xC];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    char unk_14[1];
    u8 unk15;
} struct_8005B6B0_arg1;

typedef struct struct_8005B6B0_arg2 {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
} struct_8005B6B0_arg2;

s32 func_8005B6B0(GlobalContext* arg0, struct_8005B6B0_arg1* arg1, struct_8005B6B0_arg2* arg2) {
    arg1->unk0 = arg2->unk0;
    arg1->unk10 = arg2->unk4;
    arg1->unk11 = arg2->unk5;
    arg1->unk12 = arg2->unk6;
    arg1->unk13 = 0x10;
    arg1->unk15 = arg2->unk7;
    return 1;
}

// is this type 1 only?
s32 func_8005B6EC(GlobalContext* globalCtx, Collider* collision, Actor* actor, struct_8005C450_Type1_suba* src) {
    collision->actor = actor;
    collision->unk_14 = src->unk0;
    collision->colliderFlags = src->unk1;
    collision->collideFlags = src->unk2;
    collision->maskA = src->unk3;
    collision->maskB = 0x10;
    collision->type = src->unk4;
    return 1;
}

s32 func_8005B72C_InitColliderFromSrc(GlobalContext* globalCtx, Collider* collision, Actor* actor, ColliderSrc* src) {
    collision->actor = actor;
    collision->unk_14 = src->unk_00;
    collision->colliderFlags = src->colliderFlags;
    collision->collideFlags = src->collideFlags;
    collision->maskA = src->maskA;
    collision->maskB = src->maskB;
    collision->type = src->type;
    return 1;
}

void func_8005B76C(GlobalContext* globalCtx, Collider* collision) {
    collision->at = NULL;
    collision->colliderFlags &= ~0x6;
}

void func_8005B784(GlobalContext* globalCtx, Collider* collision) {
    collision->ac = NULL;
    collision->collideFlags &= ~0x82;
}

void func_8005B79C(GlobalContext* globalCtx, Collider* collision) {
    collision->ot = NULL;
    collision->maskA &= ~0x2;
    collision->maskB &= ~0x1;
}

typedef struct struct_8011DE18 {
    s32 unk0;
    s32 unk4;
} struct_8011DE18; /* size = 0x8 */

extern ColliderTouch D_8011DE18;

s32 func_8005B7C0(s32 arg0, ColliderTouch* arg1) {
    *arg1 = D_8011DE18;
    return 1;
}

s32 func_8005B7E4(GlobalContext* globalCtx, ColliderTouch* touch) {
    return 1;
}

s32 func_8005B7F4(s32 arg0, ColliderTouch* arg1, ColliderTouchSrc* arg2) {
    arg1->flags = arg2->toucherMask;
    arg1->unk_04 = arg2->bumperEffect;
    arg1->damage = arg2->toucherDamage;
    return 1;
}

void func_8005B818(GlobalContext* globalCtx, UNK_PTR body) {
}

typedef struct struct_8011DE20 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} struct_8011DE20; /* size = 0xC */

extern struct_8011DE20 D_8011DE20;

s32 func_8005B824(s32 arg0, struct_8011DE20* arg1) {
    *arg1 = D_8011DE20;
    return 1;
}

s32 func_8005B850(GlobalContext* globalCtx, UNK_PTR bump) {
    return 1;
}

s32 func_8005B860(s32 arg0, ColliderBump* arg1, ColliderBumpSrc* arg2) {
    arg1->flags = arg2->bumperMask;
    arg1->effect = arg2->unk4;
    arg1->unk_05 = arg2->unk5;
    return 1;
}

typedef struct struct_8011DE2C {
    struct_8011DE18 unk0;
    struct_8011DE20 unk8;
    char unk_14[0x14];
} struct_8011DE2C; /* size = 0x28 */

extern ColliderBody D_8011DE2C;

s32 func_8005B884(GlobalContext* arg0, ColliderBody* arg1) {
    *arg1 = D_8011DE2C;
    func_8005B7C0(arg0, &arg1->toucher);
    func_8005B824(arg0, &arg1->bumper);
    return 1;
}

// multi-type
s32 func_8005B904(GlobalContext* globalCtx, ColliderBody* body) {
    func_8005B7E4(globalCtx, &body->toucher);
    func_8005B850(globalCtx, &body->bumper);
    return 1;
}

// multi-type
s32 func_8005B93C(GlobalContext* globalCtx, ColliderBody* body, ColliderBodySrc* bodyInfoInner) {
    body->flags = bodyInfoInner->bodyFlags;
    func_8005B7F4(globalCtx, &body->toucher, &bodyInfoInner->unk4);
    func_8005B860(globalCtx, &body->bumper, &bodyInfoInner->unkC);
    body->toucherFlags = bodyInfoInner->toucherFlags;
    body->bumperFlags = bodyInfoInner->bumperFlags;
    body->flags2 = bodyInfoInner->bodyFlags2;
    return 1;
}

// multi-type
void func_8005B9B0(GlobalContext* globalCtx, ColliderBody* body) {
    body->unk_18 = 0;
    body->unk_20 = 0;
    body->toucherFlags &= ~0x2;
    body->toucherFlags &= ~0x40;
    func_8005B818(globalCtx, body);
}

// multi-type
void func_8005B9E8(GlobalContext* globalCtx, ColliderBody* body) {
    body->bumperFlags &= ~0x2;
    body->bumperFlags &= ~0x80;
    body->colBuf = NULL;
    body->colliding = NULL;
    body->bumper.unk_06.x = body->bumper.unk_06.y = body->bumper.unk_06.z = 0;
}

void func_8005BA1C(GlobalContext* globalCtx, ColliderBody* body) {
    body->flags2 &= ~0x2;
}

extern struct_8011DE54 D_8011DE54;

s32 func_8005BA30(GlobalContext* arg0, struct_8011DE54* arg1) {
    *arg1 = D_8011DE54;
    return 1;
}

s32 func_8005BA74(GlobalContext* arg0, UNK_TYPE arg1) {
    return 1;
}

s32 func_8005BA84_Type0(GlobalContext* arg0, struct_8011DE54* arg1, ColliderSrc_Type0_ptrC_sub18* arg2) {
    arg1->unk14 = (u8)arg2->unk0;
    arg1->unk0 = arg2->unk2;
    arg1->unk10 = (f32)((f32)arg2->unkA * 0.01f);
    return 1;
}

s32 func_8005BAD8_Type0(GlobalContext* arg0, Collider_Type0_ptr1C* arg1) {
    func_8005B884(arg0, &arg1->unk0);
    func_8005BA30(arg0, &arg1->unk28);
    return 1;
}

s32 func_8005BB10_Type0(GlobalContext* arg0, Collider_Type0_ptr1C* arg1) {
    func_8005B904(arg0, &arg1->unk0);
    func_8005BA74(arg0, &arg1->unk28);
    return 1;
}

s32 func_8005BB48_Type0(GlobalContext* arg0, Collider_Type0_ptr1C* arg1, ColliderSrc_Type0_ptrC* arg2) {
    func_8005B93C(arg0, &arg1->unk0, &arg2->unk0);
    func_8005BA84_Type0(arg0, &arg1->unk28, &arg2->unk18);
    return 1;
}

s32 func_8005BB8C_SetAT_sub_0(GlobalContext* arg0, Collider_Type0_ptr1C* arg1) {
    func_8005B9B0(arg0, &arg1->unk0);
    return 1;
}

s32 func_8005BBB0_SetAC_sub_0(GlobalContext* arg0, Collider_Type0_ptr1C* arg1) {
    func_8005B9E8(arg0, &arg1->unk0);
    return 1;
}

s32 func_8005BBD4_SetOT_sub_0(GlobalContext* arg0, Collider_Type0_ptr1C* arg1) {
    func_8005BA1C(arg0, &arg1->unk0);
    return 1;
}

s32 func_8005BBF8_Type0(GlobalContext* arg0, Collider_Type0* arg1) {
    func_8005B65C_InitColliderDefault(arg0, &arg1->unk0);
    arg1->unk18 = 0;
    arg1->unk1C = 0;
    return 1;
}

// only used by EnNwc
s32 func_8005BC28(GlobalContext* arg0, Collider_Type0* arg1) {
    Collider_Type0_ptr1C* var_s0;

    func_8005B6A0(arg0, &arg1->unk0);
    var_s0 = arg1->unk1C;
    while (var_s0 < (arg1->unk1C + arg1->unk18)) {
        func_8005BB10_Type0(arg0, var_s0);
        var_s0++;
    }
    arg1->unk18 = 0;
    if (arg1->unk1C != NULL) {
        ZeldaArena_FreeDebug((void*)arg1->unk1C, "../z_collision_check.c", 0x571);
    }
    arg1->unk1C = NULL;
    return 1;
}

s32 func_8005BCC8_Type0(GlobalContext* arg0, Collider_Type0* arg1) {
    Collider_Type0_ptr1C* var_s0;

    func_8005B6A0(arg0, &arg1->unk0);
    var_s0 = arg1->unk1C;
    while (var_s0 < (arg1->unk1C + arg1->unk18)) {
        func_8005BB10_Type0(arg0, var_s0);
        var_s0++;
    }
    arg1->unk18 = 0;
    arg1->unk1C = NULL;
    return 1;
}

// unused
s32 func_8005BD50_jntsph(GlobalContext* arg0, Collider_Type0* arg1, ColliderSrc_Type0* arg2) {
    Collider_Type0_ptr1C* var_s0;
    ColliderSrc_Type0_ptrC* var_s1;

    func_8005B6B0(arg0, &arg1->unk0, &arg2->unk0);
    arg1->unk18 = arg2->unk8;
    arg1->unk1C = ZeldaArena_MallocDebug(arg2->unk8 << 6, "../z_collision_check.c", 0x5A3);
    if (arg1->unk1C == 0) {
        arg1->unk18 = 0;
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjJntSph_set():zelda_malloc()出来ません。\n");
        osSyncPrintf("\x1b[m");
        return 0;
    }
    var_s0 = arg1->unk1C;
    var_s1 = arg2->unkC;
    while (var_s0 < (arg1->unk1C + (arg1->unk18))) {
        func_8005BAD8_Type0(arg0, var_s0);
        func_8005BB48_Type0(arg0, var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

// only used by EnNwc
s32 func_8005BE50_jntsph(GlobalContext* arg0, Collider_Type0* arg1, Actor* arg2, ColliderSrc_Type0* arg3) {
    s32 temp_v0;
    Collider_Type0_ptr1C* var_s0;
    ColliderSrc_Type0_ptrC* var_s1;

    func_8005B6EC(arg0, &arg1->unk0, arg2, &arg3->unk0);
    arg1->unk18 = arg3->unk8;
    temp_v0 = ZeldaArena_MallocDebug(arg3->unk8 * 0x40, "../z_collision_check.c", 0x5D2);
    arg1->unk1C = temp_v0;
    if (temp_v0 == 0) {
        arg1->unk18 = 0;
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjJntSph_set3():zelda_malloc_出来ません。\n");
        osSyncPrintf("\x1b[m");
        return 0;
    }
    var_s0 = arg1->unk1C;
    var_s1 = arg3->unkC;
    while (var_s0 < (arg1->unk1C + arg1->unk18)) {
        func_8005BAD8_Type0(arg0, var_s0);
        func_8005BB48_Type0(arg0, var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

// unused
s32 func_8005BF50_jntsph(GlobalContext* arg0, Collider_Type0* arg1, Actor* arg2, ColliderSrc_Type0* arg3) {
    s32 temp_v0;
    Collider_Type0_ptr1C* var_s0;
    ColliderSrc_Type0_ptrC* var_s1;

    func_8005B72C_InitColliderFromSrc(arg0, &arg1->unk0, arg2, &arg3->unk0);
    arg1->unk18 = arg3->unk8;
    arg1->unk1C = ZeldaArena_MallocDebug(arg3->unk8 * 0x40, "../z_collision_check.c", 0x60F);
    if (arg1->unk1C == NULL) {
        arg1->unk18 = 0;
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjJntSph_set5():zelda_malloc出来ません\n");
        osSyncPrintf("\x1b[m");
        return 0;
    }
    var_s0 = arg1->unk1C;
    var_s1 = arg3->unkC;
    while (var_s0 < (arg1->unk1C + arg1->unk18)) {
        func_8005BAD8_Type0(arg0, var_s0);
        func_8005BB48_Type0(arg0, var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

s32 func_8005C050_jntsph_Type0(GlobalContext* globalCtx, Collider_Type0* collision, Actor* actor,
                               ColliderSrc_Type0* arg3, Collider_Type0_ptr1C* arg4) {
    Collider_Type0_ptr1C* var_s0;
    ColliderSrc_Type0_ptrC* var_s1;

    func_8005B72C_InitColliderFromSrc(globalCtx, &collision->unk0, actor, &arg3->unk0);
    collision->unk18 = arg3->unk8;
    collision->unk1C = arg4;
    if (arg4 == NULL) {
        func_80001FF0("pclobj_jntsph->elem_tbl != NULL", "../z_collision_check.c", 0x643);
    }
    var_s0 = collision->unk1C;
    var_s1 = arg3->unkC;
    while (var_s0 < (collision->unk1C + collision->unk18)) {
        func_8005BAD8_Type0(globalCtx, var_s0);
        func_8005BB48_Type0(globalCtx, var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

s32 func_8005C124_SetAT_0(GlobalContext* arg0, Collider* arg1) {
    Collider_Type0* new_var;
    Collider_Type0_ptr1C* var_s0;

    new_var = arg1;
    func_8005B76C(arg0, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005BB8C_SetAT_sub_0(arg0, var_s0);
        var_s0++;
    }

    return 1;
}

s32 func_8005C1AC_SetAC_0(GlobalContext* arg0, Collider* arg1) {
    Collider_Type0* new_var;
    Collider_Type0_ptr1C* var_s0;

    new_var = arg1;
    func_8005B784(arg0, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005BBB0_SetAC_sub_0(arg0, var_s0);
        var_s0++;
    }
    return 1;
}

s32 func_8005C234_SetOT_0(GlobalContext* arg0, Collider* arg1) {
    Collider_Type0* new_var;
    Collider_Type0_ptr1C* var_s0;

    new_var = arg1;
    func_8005B79C(arg0, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005BBD4_SetOT_sub_0(arg0, var_s0);
        var_s0++;
    }
    return 1;
}

extern Cylinder16 D_8011DE6C;

s32 func_8005C2BC(s32 arg0, Cylinder16* arg1) {
    Cylinder16 sp4;

    sp4 = D_8011DE6C;
    *arg1 = sp4;
    return 1;
}

s32 func_8005C318(GlobalContext* globalCtx, UNK_PTR dim) {
    return 1;
}

s32 func_8005C328_Type1(GlobalContext* globalCtx, Cylinder16* dest, Cylinder16* src) {
    *dest = *src;
    return 1;
}

s32 ActorCollider_AllocThing_Type1(GlobalContext* globalCtx, Collider_Type1* collision) {
    func_8005B65C_InitColliderDefault(globalCtx, &collision->unk0);
    func_8005B884(globalCtx, &collision->unk18);
    func_8005C2BC(globalCtx, &collision->unk40);
    return 1;
}

s32 ActorCollider_FreeThing_Type1(GlobalContext* globalCtx, Collider_Type1* collision) {
    func_8005B6A0(globalCtx, &collision->unk0);
    func_8005B904(globalCtx, &collision->unk18);
    func_8005C318(globalCtx, &collision->unk40);
    return 1;
}

typedef struct struct_8005C3F4_arg1 {
    /* 0x00 */ char unk0[0x18];
    /* 0x18 */ char unk18[0x28];
    /* 0x40 */ Cylinder16 unk40;
} struct_8005C3F4_arg1;

typedef struct struct_8005C3F4_arg2 {
    /* 0x00 */ char unk0[0x8];
    /* 0x08 */ char unk8[0x18];
    /* 0x20 */ Cylinder16 unk20;
} struct_8005C3F4_arg2;

// only used by ObjDekujr
s32 func_8005C3F4(GlobalContext* globalCtx, struct_8005C3F4_arg1* collision, struct_8005C3F4_arg2* src) {
    func_8005B6B0(globalCtx, &collision->unk0, &src->unk0);
    func_8005B93C(globalCtx, &collision->unk18, &src->unk8);
    func_8005C328_Type1(globalCtx, &collision->unk40, &src->unk20);
    return 1;
}

s32 func_8005C450_Type1(GlobalContext* globalCtx, Collider_Type1* collision, Actor* actor,
                        struct_8005C450_Type1_ColliderSrc* src) {
    func_8005B6EC(globalCtx, &collision->unk0, actor, &src->unk0);
    func_8005B93C(globalCtx, &collision->unk18, &src->unk8);
    func_8005C328_Type1(globalCtx, &collision->unk40, &src->unk20);
    return 1;
}

s32 ActorCollider_InitThing_Type1(GlobalContext* globalCtx, Collider_Type1* collision, Actor* actor,
                                  Type1_ColliderSrc_alt* src) {
    func_8005B72C_InitColliderFromSrc(globalCtx, &collision->unk0, actor, &src->unk0);
    func_8005B93C(globalCtx, &collision->unk18, &src->unk8);
    func_8005C328_Type1(globalCtx, &collision->unk40, &src->unk20);
    return 1;
}

s32 func_8005C508_SetAT_1(GlobalContext* globalCtx, Collider* collision_) {
    Collider_Type1* collision = collision_;

    func_8005B76C(globalCtx, &collision->unk0);
    func_8005B9B0(globalCtx, &collision->unk18);
    return 1;
}

s32 func_8005C540_SetAC_1(GlobalContext* globalCtx, Collider* collision_) {
    Collider_Type1* collision = collision_;

    func_8005B784(globalCtx, &collision->unk0);
    func_8005B9E8(globalCtx, &collision->unk18);
    return 1;
}

s32 func_8005C578_SetOT_1(GlobalContext* globalCtx, Collider* collision_) {
    Collider_Type1* collision = collision_;

    func_8005B79C(globalCtx, &collision->unk0);
    func_8005BA1C(globalCtx, &collision->unk18);
    return 1;
}

typedef struct struct_8011DE78 {
    s32 unk0[0x34 / 4];
} struct_8011DE78; /* size = 0x34 */

extern struct_8011DE78 D_8011DE78;

s32 func_8005C5B0(GlobalContext* arg0, struct_8011DE78* arg1) {
    *arg1 = D_8011DE78;
    return 1;
}

s32 func_8005C5F8(GlobalContext* arg0, UNK_TYPE arg1) {
    return 1;
}

typedef struct struct_8005C608_arg1 {
    /* 0x00 */ Vec3f unk0[3];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
} struct_8005C608_arg1;

s32 func_8005C608(GlobalContext* arg0, struct_8005C608_arg1* arg1, Vec3f* arg2) {
    Vec3f* var_v1;
    Vec3f* var_v0;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    var_v0 = arg1->unk0;
    var_v1 = arg2;
    while (var_v0 < arg1->unk0 + 3) {
        *var_v0 = *var_v1;
        var_v0++;
        var_v1++;
    }

    func_800CC8B4(arg2, arg2 + 1, arg2 + 2, &sp44, &sp40, &sp3C, &sp38);
    arg1->unk24 = sp44;
    arg1->unk28 = sp40;
    arg1->unk2C = sp3C;
    arg1->unk30 = sp38;
    return 1;
}

typedef struct struct_8005C6C0 {
    ColliderBody unk0;
    struct_8011DE78 unk28;
} struct_8005C6C0; /* size = 0x5C */

s32 func_8005C6C0_tris(GlobalContext* arg0, struct_8005C6C0* arg1) {
    func_8005B884(arg0, &arg1->unk0);
    func_8005C5B0(arg0, &arg1->unk28);
    return 1;
}

typedef struct struct_8005C6F8 {
    ColliderBody unk0;
    char unk_28[0x5C - 0x28];
} struct_8005C6F8; /* size = 0x5C */

s32 func_8005C6F8(GlobalContext* arg0, struct_8005C6F8* arg1) {
    func_8005B904(arg0, &arg1->unk0);
    func_8005C5F8(arg0, arg1->unk_28);
    return 1;
}

typedef struct struct_8005C730_arg1 {
    ColliderBody unk0;
    struct_8005C608_arg1 unk28;
} struct_8005C730_arg1;

typedef struct struct_8005C730_arg2 {
    char unk_0[0x18];
    Vec3f unk18;
    char unk_24[0x18];
} struct_8005C730_arg2;

s32 func_8005C730(GlobalContext* arg0, struct_8005C730_arg1* arg1, struct_8005C730_arg2* arg2) {
    func_8005B93C(arg0, &arg1->unk0, arg2->unk_0);
    func_8005C608(arg0, &arg1->unk28, &arg2->unk18);
    return 1;
}

s32 func_8005C774(GlobalContext* arg0, ColliderBody* arg1) {
    func_8005B9B0(arg0, arg1);
    return 1;
}

s32 func_8005C798_SetAC_sub_2(GlobalContext* arg0, ColliderBody* arg1) {
    func_8005B9E8(arg0, arg1);
    return 1;
}

s32 func_8005C7BC_Type2(GlobalContext* arg0, Collider_Type2_ptr1C* arg1) {
    func_8005BA1C(arg0, arg1);
    return 1;
}

typedef struct struct_8005C7E0 {
    Collider unk0;
    s32 unk18;
    s32 unk1C;
} struct_8005C7E0;

// uses not decompiled
s32 func_8005C7E0(GlobalContext* arg0, struct_8005C7E0* arg1) {
    func_8005B65C_InitColliderDefault(arg0, &arg1->unk0);
    arg1->unk18 = 0;
    arg1->unk1C = 0;
    return 1;
}

typedef struct struct_8005C810 {
    Collider unk0;
    s32 unk18;
    struct_8005C6F8* unk1C;
} struct_8005C810;

// unused
s32 func_8005C810(GlobalContext* arg0, struct_8005C810* arg1) {
    struct_8005C6F8* var_s0;

    func_8005B6A0(arg0, &arg1->unk0);
    var_s0 = arg1->unk1C;
    while (var_s0 < (arg1->unk1C + arg1->unk18)) {
        func_8005C6F8(arg0, (struct_8005C6F8*)var_s0);
        var_s0++;
    }
    arg1->unk18 = 0;
    if (arg1->unk1C != NULL) {
        ZeldaArena_FreeDebug(arg1->unk1C, "../z_collision_check.c", 0x833);
    }
    arg1->unk1C = 0;
    return 1;
}

typedef struct struct_8005C8C8 {
    Collider unk0;
    s32 unk18;
    struct_8005C6F8* unk1C;
} struct_8005C8C8;

// uses not decompiled
s32 func_8005C8C8(GlobalContext* arg0, struct_8005C8C8* arg1) {
    struct_8005C6F8* var_s0;

    func_8005B6A0(arg0, &arg1->unk0);
    var_s0 = arg1->unk1C;
    if ((u32)var_s0 < (u32)&var_s0[arg1->unk18]) {
        do {
            func_8005C6F8(arg0, var_s0);
            var_s0++;
        } while ((u32)var_s0 < (u32)&arg1->unk1C[arg1->unk18]);
    }
    arg1->unk18 = 0;
    arg1->unk1C = NULL;
    return 1;
}

typedef struct struct_8005C964_arg1 {
    Collider unk0;
    s32 unk18;
    struct_8005C6C0* unk1C;
} struct_8005C964_arg1;

typedef struct struct_8005C964_arg3 {
    char unk_0[8];
    s32 unk8;
    struct_8005C730_arg2* unkC;
} struct_8005C964_arg3;

// unused
s32 func_8005C964_tris(GlobalContext* arg0, struct_8005C964_arg1* arg1, Actor* arg2, struct_8005C964_arg3* arg3) {
    struct_8005C6C0* var_s0;
    struct_8005C730_arg2* var_s1;

    func_8005B6EC(arg0, &arg1->unk0, arg2, arg3->unk_0);
    arg1->unk18 = arg3->unk8;
    arg1->unk1C = ZeldaArena_MallocDebug((u32)arg1->unk18 * 0x5C, "../z_collision_check.c", 0x86C);
    if (arg1->unk1C == 0) {
        arg1->unk18 = 0;
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjTris_set3():zelda_malloc()出来ません\n");
        osSyncPrintf("\x1b[m");
        return 0;
    }
    var_s0 = arg1->unk1C;
    var_s1 = arg3->unkC;
    while (var_s0 < (arg1->unk1C + arg1->unk18)) {
        func_8005C6C0_tris(arg0, var_s0);
        func_8005C730(arg0, var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

typedef struct struct_8005CA88_arg1 {
    Collider unk0;
    s32 unk18;
    struct_8005C6C0* unk1C;
} struct_8005CA88_arg1;

typedef struct struct_8005CA88_arg3 {
    char unk_0[8];
    s32 unk8;
    struct_8005C730_arg2* unkC;
} struct_8005CA88_arg3;

// unused
s32 func_8005CA88_tris(GlobalContext* arg0, struct_8005CA88_arg1* arg1, Actor* arg2, struct_8005CA88_arg3* arg3) {
    struct_8005C6C0* temp_v0;
    struct_8005C6C0* var_s0;
    struct_8005C730_arg2* var_s1;

    func_8005B72C_InitColliderFromSrc(arg0, &arg1->unk0, arg2, arg3->unk_0);
    arg1->unk18 = arg3->unk8;
    temp_v0 = ZeldaArena_MallocDebug((u32)arg1->unk18 * 0x5C, "../z_collision_check.c", 0x89F);
    arg1->unk1C = temp_v0;
    if (temp_v0 == NULL) {
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjTris_set5():zelda_malloc出来ません\n");
        osSyncPrintf("\x1b[m");
        arg1->unk18 = 0;
        return 0;
    }
    var_s0 = arg1->unk1C;
    var_s1 = arg3->unkC;
    while ((u32)var_s0 < (u32)&arg1->unk1C[arg1->unk18]) {
        func_8005C6C0_tris((s32)arg0, var_s0);
        func_8005C730(arg0, (struct_8005C730_arg1*)var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

typedef struct struct_8005CBAC_arg1 {
    Collider unk0;
    s32 unk18;
    struct_8005C6C0* unk1C;
} struct_8005CBAC_arg1;

typedef struct struct_8005CBAC_arg3 {
    char unk_0[8];
    s32 unk8;
    struct_8005C730_arg2* unkC;
} struct_8005CBAC_arg3;

// uses not decompiled
s32 func_8005CBAC_tris(GlobalContext* arg0, struct_8005CBAC_arg1* arg1, Actor* arg2, struct_8005CBAC_arg3* arg3,
                       struct_8005C6C0* arg4) {
    struct_8005C6C0* var_s0;
    struct_8005C730_arg2* var_s1;

    func_8005B72C_InitColliderFromSrc(arg0, &arg1->unk0, arg2, arg3->unk_0);
    arg1->unk18 = arg3->unk8;
    arg1->unk1C = arg4;
    if (arg1->unk1C == 0) {
        func_80001FF0("pclobj_tris->elem_tbl != NULL", "../z_collision_check.c", 0x8D2);
    }
    var_s0 = arg1->unk1C;
    var_s1 = arg3->unkC;
    while (var_s0 < &arg1->unk1C[arg1->unk18]) {
        func_8005C6C0_tris(arg0, var_s0);
        func_8005C730(arg0, var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

s32 func_8005CC98_SetAT_2(GlobalContext* arg0, Collider* arg1) {
    Collider_Type2_ptr1C* var_s0;
    Collider_Type2* new_var;

    new_var = arg1;
    func_8005B76C(arg0, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (((u32)var_s0) < ((u32)(new_var->unk1C + new_var->unk18))) {
        func_8005C774(arg0, var_s0);
        var_s0++;
    }
    return 1;
}

s32 func_8005CD34_SetAC_2(GlobalContext* arg0, Collider* arg1) {
    Collider_Type2_ptr1C* var_s0;
    Collider_Type2* new_var;

    new_var = arg1;
    func_8005B784(arg0, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005C798_SetAC_sub_2(arg0, var_s0);
        var_s0++;
    }
    return 1;
}

s32 func_8005CDD0_SetOT_2(GlobalContext* arg0, Collider* arg1) {
    Collider_Type2* new_var;
    Collider_Type2_ptr1C* var_s0;

    new_var = arg1;
    func_8005B79C(arg0, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005C7BC_Type2(arg0, var_s0);
        var_s0++;
    }
    return 1;
}

extern struct_Collider_Type3_subc D_8011DEAC;

s32 func_8005CE6C(GlobalContext* arg0, struct_Collider_Type3_subc* arg1) {
    *arg1 = D_8011DEAC;
    return 1;
}

s32 func_8005CEB4_Type3(GlobalContext* globalCtx, struct_Collider_Type3_subc* dim) {
    return 1;
}

s32 func_8005CEC4(s32 arg0, struct_Collider_Type3_subc* arg1) {
    arg1->unk3C = 1e38f;
    return 1;
}

void func_8005CEDC(struct_Collider_Type3_subc* arg0) {
    arg0->unk30.x = (s16)(s32)((arg0->unk18.x + arg0->unk24.x) * 0.5f);
    arg0->unk30.y = (s16)(s32)((arg0->unk18.y + arg0->unk24.y) * 0.5f);
    arg0->unk30.z = (s16)(s32)((arg0->unk18.z + arg0->unk24.z) * 0.5f);
    arg0->unk36.x = (s16)(s32)((arg0->unk0.x + arg0->unkC.x) * 0.5f);
    arg0->unk36.y = (s16)(s32)((arg0->unk0.y + arg0->unkC.y) * 0.5f);
    arg0->unk36.z = (s16)(s32)((arg0->unk0.z + arg0->unkC.z) * 0.5f);
}

s32 func_8005CF90_Type3(s32 arg0, struct_Collider_Type3_subc* arg1, Vec3f* arg2) {
    arg1->unk0 = arg2[0];
    arg1->unkC = arg2[1];
    arg1->unk18 = arg2[2];
    arg1->unk24 = arg2[3];
    func_8005CEDC(arg1);
    return 1;
}

s32 func_8005D018_Type3(GlobalContext* globalCtx, Collider_Type3* collision) {
    func_8005B65C_InitColliderDefault(globalCtx, &collision->unk0);
    func_8005B884(globalCtx, &collision->unk18);
    func_8005CE6C(globalCtx, &collision->unk40);
    return 1;
}

s32 func_8005D060_Type3(GlobalContext* globalCtx, Collider_Type3* collision) {
    func_8005B6A0(globalCtx, &collision->unk0);
    func_8005B904(globalCtx, &collision->unk18);
    func_8005CEB4_Type3(globalCtx, &collision->unk40);
    return 1;
}

typedef struct struct_8005D0A8_arg1 {
    /* 0x00 */ Collider unk0;
    /* 0x18 */ ColliderBody unk18;
    /* 0x40 */ struct_Collider_Type3_subc unk40;
} struct_8005D0A8_arg1;

typedef struct struct_8005D0A8_arg3 {
    /* 0x00 */ struct_8005C450_Type1_suba unk0;
    /* 0x08 */ ColliderBodySrc unk8;
    /* 0x20 */ Vec3f unk20[4];
} struct_8005D0A8_arg3;

// unused
s32 func_8005D0A8(GlobalContext* globalCtx, struct_8005D0A8_arg1* collision, Actor* actor, struct_8005D0A8_arg3* src) {
    func_8005B6EC(globalCtx, &collision->unk0, actor, &src->unk0);
    func_8005B93C(globalCtx, &collision->unk18, &src->unk8);
    func_8005CF90_Type3(globalCtx, &collision->unk40, &src->unk20);
    return 1;
}

s32 func_8005D104_Type3(GlobalContext* globalCtx, Collider_Type3* collision, Actor* actor, ColliderSrc_Type3* src) {
    func_8005B72C_InitColliderFromSrc(globalCtx, &collision->unk0, actor, &src->unk0);
    func_8005B93C(globalCtx, &collision->unk18, &src->unk8);
    func_8005CF90_Type3(globalCtx, &collision->unk40, src->unk20);
    return 1;
}

s32 func_8005D160_SetAT_3(GlobalContext* globalCtx, Collider* collision_) {
    Collider_Type3* collision = collision_;

    func_8005B76C(globalCtx, &collision->unk0);
    func_8005B9B0(globalCtx, &collision->unk18);
    func_8005CEC4(globalCtx, &collision->unk40);
    return 1;
}

s32 func_8005D1A8_SetAC_3(GlobalContext* globalCtx, Collider* collision_) {
    Collider_Type3* collision = collision_;

    func_8005B784(globalCtx, &collision->unk0);
    func_8005B9E8(globalCtx, &collision->unk18);
    return 1;
}

s32 func_8005D1E0_SetOT_3(GlobalContext* globalCtx, Collider* collision_) {
    Collider_Type3* collision = collision_;

    func_8005B79C(globalCtx, &collision->unk0);
    func_8005BA1C(globalCtx, &collision->unk18);
    return 1;
}

typedef struct struct_8005D218 {
    /* 0x00 */ char unk_0[0x2D];
    /* 0x2D */ u8 unk2D;
    /* 0x2E */ char unk_2E[2];
    /* 0x30 */ Collider* unk30;
    /* 0x34 */ char unk_34[4];
    /* 0x38 */ ColliderBody* unk38;
    /* 0x3C */ char unk_3C[0x34];
    /* 0x70 */ Vec3s unk70;
    /* 0x76 */ char unk_76[6];
    /* 0x7C */ f32 unk7C;
} struct_8005D218;

s32 func_8005D218(GlobalContext* arg0, struct_8005D218* arg1, Vec3f* arg2) {
    f32 temp_fv0;
    Vec3f sp20;

    if (!(arg1->unk2D & 4)) {
        return 1;
    }
    Math_Vec3s_ToVec3f(&sp20, &arg1->unk70);
    temp_fv0 = func_800CB650(&sp20, arg2);
    if (temp_fv0 < arg1->unk7C) {
        arg1->unk7C = temp_fv0;
        if (arg1->unk30 != NULL) {
            func_8005B784(arg0, arg1->unk30);
        }
        if (arg1->unk38 != NULL) {
            func_8005B9E8(arg0, arg1->unk38);
        }
        return 1;
    } else {
        return 0;
    }
}

extern Vec3f D_8011DEEC;

s32 func_8005D2C4(s32 arg0, Vec3f* arg1) {
    Vec3f sp1C;

    sp1C = D_8011DEEC;
    Math_Vec3f_Copy(arg1, &sp1C);
    Math_Vec3f_Copy(arg1 + 1, &sp1C);
    return 1;
}

s32 func_8005D324(s32 arg0, s32 arg1) {
    return 1;
}

s32 func_8005D334(s32 arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {
    Math_Vec3f_Copy(arg1, arg2);
    Math_Vec3f_Copy(arg1 + 1, arg3);
    return 1;
}

typedef struct struct_8005D378_arg1 {
    Vec3f unk0;
    char unk_C[0xC];
    u16 unk18;
} struct_8005D378_arg1;

typedef struct struct_8005D378_arg2 {
    Vec3f unk0;
    Vec3f unkC;
    u16 unk18;
} struct_8005D378_arg2;

s32 func_8005D378(s32 arg0, struct_8005D378_arg1* arg1, struct_8005D378_arg2* arg2) {
    arg1->unk18 = (u16)arg2->unk18;
    func_8005D334(arg0, &arg1->unk0, &arg2->unk0, &arg2->unkC);
    return 1;
}

typedef struct struct_8005D3A4 {
    char unk_0[0x18];
    u16 unk18;
} struct_8005D3A4;

s32 func_8005D3A4(GlobalContext* arg0, struct_8005D3A4* arg1) {
    arg1->unk18 = (u16)(arg1->unk18 & 0xFFFE);
    return 1;
}

void func_8005D40C(GlobalContext* arg0, SubGlobalContext11E60* arg1);

void func_8005D3BC(GlobalContext* arg0, SubGlobalContext11E60* arg1) {
    arg1->unk2 = 0;
    func_8005D40C(arg0, arg1);
    gGameInfo->data[0x735] = 1;
    gGameInfo->data[0x736] = 1;
    gGameInfo->data[0x737] = 1;
}

void func_8005D400(GlobalContext* globalCtx, SubGlobalContext11E60* sub_11E60) {
}

void func_8005D40C(GlobalContext* arg0, SubGlobalContext11E60* arg1) {
    s32* var_v0;

    if (!(arg1->unk2 & 1)) {
        arg1->unk0_nAT = 0;
        arg1->unkCC_nAC = 0;
        arg1->unk1C0_nOT = 0;
        arg1->unk28C = 0;
        // clang-format off
        var_v0 = arg1->unk4_AT; while ((u32)var_v0 < (u32)(arg1->unk4_AT + ARRAY_COUNT(arg1->unk4_AT))) {
            // clang-format on
            *var_v0 = 0;
            var_v0++;
        }
        var_v0 = arg1->unkD0_AC;
        while ((u32)var_v0 < (u32)(arg1->unkD0_AC + ARRAY_COUNT(arg1->unkD0_AC))) {
            *var_v0 = 0;
            var_v0++;
        }
        var_v0 = arg1->unk1C4_OT;
        while ((u32)var_v0 < (u32)(arg1->unk1C4_OT + ARRAY_COUNT(arg1->unk1C4_OT))) {
            *var_v0 = 0;
            var_v0++;
        }
        var_v0 = arg1->unk290;
        while ((u32)var_v0 < (u32)(arg1->unk290 + ARRAY_COUNT(arg1->unk290))) {
            *var_v0 = 0;
            var_v0++;
        }
    }
}

typedef struct struct_8005D4B4 {
    char unk_0[2];
    u16 unk2;
} struct_8005D4B4;

void func_8005D4B4(s32 arg0, struct_8005D4B4* arg1) {
    arg1->unk2 = (u16)(arg1->unk2 | 1);
}

typedef struct struct_8005D4C8 {
    char unk_0[2];
    u16 unk2;
} struct_8005D4C8;

void func_8005D4C8(s32 arg0, struct_8005D4C8* arg1) {
    arg1->unk2 = (u16)(arg1->unk2 & 0xFFFE);
}

typedef struct struct_8005D4DC_ptr1C_a {
    char unk_0[0x28];
    Vec3f unk28;
    Vec3f unk34;
    Vec3f unk40;
    char unk_4C[0x10];
} struct_8005D4DC_ptr1C_a;

typedef struct struct_8005D4DC_ptr1C_b {
    char unk_0[0x40];
} struct_8005D4DC_ptr1C_b;

typedef struct struct_8005D4DC {
    Collider unk0;
    s32 unk18;
    union {
        struct_8005D4DC_ptr1C_a* a;
        struct_8005D4DC_ptr1C_b* b;
    } unk1C;
    char unk_20[0x20];
    Vec3f unk40;
    Vec3f unk4C;
    Vec3f unk58;
    Vec3f unk64;
} struct_8005D4DC;

void func_8005D4DC(GraphicsContext** arg0, Collider* arg1) {
    struct_8005D4DC* new_var;
    s32 var_s0;

    if (arg1 != NULL) {
        switch (arg1->type) {
            case 0:
                new_var = arg1;
                var_s0 = 0;
                while (var_s0 < new_var->unk18) {
                    func_800D05D0((s32)arg0, (s32)((s32)&new_var->unk1C.b[var_s0] + 0x30));
                    var_s0 += 1;
                    if (!arg1) {}
                }
                break;

            case 1:
                new_var = arg1;
                func_800D05DC((s32)arg0, (s32)&new_var->unk40);
                break;

            case 2:
                new_var = arg1;
                var_s0 = 0;
                while (var_s0 < new_var->unk18) {
                    func_8005B280(*arg0, &new_var->unk1C.a[var_s0].unk28, &new_var->unk1C.a[var_s0].unk34,
                                  &new_var->unk1C.a[var_s0].unk40);
                    var_s0 += 1;
                }
                break;

            case 3:
                new_var = arg1;
                func_8005B280(*arg0, &new_var->unk58, &new_var->unk64, &new_var->unk4C);
                func_8005B280(*arg0, &new_var->unk4C, &new_var->unk40, &new_var->unk58);
                break;
        }
    }
}

void func_8005D62C(GlobalContext* arg0, SubGlobalContext11E60* arg1) {
    s32 var_s1;

    if (gGameInfo->data[0x72F] != 0) {
        if (gGameInfo->data[0x735] != 0) {
            var_s1 = 0;
            while (var_s1 < arg1->unk0_nAT) {
                func_8005D4DC(arg0, arg1->unk4_AT[var_s1]);
                var_s1 += 1;
            }
        }
        if (gGameInfo->data[0x736] != 0) {
            var_s1 = 0;
            while (var_s1 < arg1->unkCC_nAC) {
                func_8005D4DC(arg0, arg1->unkD0_AC[var_s1]);
                var_s1 += 1;
            }
        }
        if (gGameInfo->data[0x737] != 0) {
            var_s1 = 0;
            while (var_s1 < arg1->unk1C0_nOT) {
                if (arg1->unk1C4_OT[var_s1]->maskA & 1) {
                    func_8005D4DC(arg0, arg1->unk1C4_OT[var_s1]);
                }
                var_s1 += 1;
            }
        }
        if (gGameInfo->data[0x738] != 0) {
            func_80042C3C(arg0, &arg0->colCtx);
        }
        if (gGameInfo->data[0x739] != 0) {
            func_80042FC4(arg0, &arg0->colCtx);
        }
    }
}

typedef void (*callback_8011DEF8)(GlobalContext*, Collider*);
extern callback_8011DEF8 D_8011DEF8[];

void func_8005C234_SetAT_0(GlobalContext*, Collider*);
void func_8005C578_SetAT_1(GlobalContext*, Collider*);
void func_8005CDD0_SetAT_2(GlobalContext*, Collider*);
void func_8005D1E0_SetAT_3(GlobalContext*, Collider*);

#if 0
extern callback_8011DEF8 D_8011DEF8[] = {
    func_8005C124_SetAT_0,
    func_8005C508_SetAT_1,
    func_8005CC98_SetAT_2,
    func_8005D160_SetAT_3,
};
#endif

s32 Actor_CollisionCheck_SetAT(GlobalContext* globalCtx, SubGlobalContext11E60* simpleBodyGroups, Collider* collision) {
    s16 temp_v1;
    Actor* new_var;

    if (1) {}
    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collision->type >= 4) {
        func_80001FF0("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xBB5, simpleBodyGroups);
        if (1) {}
    }
    D_8011DEF8[collision->type](globalCtx, collision);
    new_var = collision->actor;
    if ((new_var != NULL) && (collision->actor->update == NULL)) {
        return -1;
    }
    temp_v1 = simpleBodyGroups->unk0_nAT;
    if (temp_v1 >= 0x32) {
        osSyncPrintf("CollisionCheck_setAT():インデックスがオーバーして追加不能\n");
        return -1;
    }
    if (simpleBodyGroups->unk2 & 1) {
        return -1;
    }
    simpleBodyGroups->unk4_AT[temp_v1] = collision;
    simpleBodyGroups->unk0_nAT += 1;
    return temp_v1;
}

// unused
s32 func_8005D8AC(GlobalContext* arg0, SubGlobalContext11E60* arg1, Collider* arg2, s32 arg3) {
    Actor* temp_v1;

    if (arg2->type >= 4) {
        func_80001FF0("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xBDD);
    }
    if (func_800C0D28(arg0) == 1) {
        return -1;
    }
    D_8011DEF8[arg2->type](arg0, arg2);
    temp_v1 = arg2->actor;
    if ((temp_v1 != NULL) && ((arg2->actor)->update == 0)) {
        return -1;
    }
    if (arg1->unk2 & 1) {
        if (arg3 >= arg1->unk0_nAT) {
            osSyncPrintf("CollisionCheck_setAT_SAC():全データ数より大きいところに登録しようとしている。\n");
            return -1;
        }
        arg1->unk4_AT[arg3] = arg2;
    } else {
        if (arg1->unk0_nAT >= ARRAY_COUNT(arg1->unk4_AT)) {
            osSyncPrintf("CollisionCheck_setAT():インデックスがオーバーして追加不能\n");
            return -1;
        }
        arg3 = arg1->unk0_nAT;
        arg1->unk4_AT[arg1->unk0_nAT] = arg2;
        arg1->unk0_nAT += 1;
    }
    return arg3;
}

extern callback_8011DEF8 D_8011DF08[];

s32 func_8005C1AC_SetAC_0(GlobalContext*, Collider*);
s32 func_8005C540_SetAC_1(GlobalContext*, Collider*);
s32 func_8005CD34_SetAC_2(GlobalContext*, Collider*);
s32 func_8005D1A8_SetAC_3(GlobalContext*, Collider*);

#if 0
callback_8011DEF8 D_8011DF08[] = {
    func_8005C1AC_SetAC_0,
    func_8005C540_SetAC_1,
    func_8005CD34_SetAC_2,
    func_8005D1A8_SetAC_3,
};
#endif

s32 Actor_CollisionCheck_SetAC(GlobalContext* globalCtx, SubGlobalContext11E60* simpleBodyGroups, Collider* collision) {
    Actor* temp_v1_2;
    s32 temp_v1;

    if (1) {}
    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collision->type >= 4) {
        func_80001FF0("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xC2A, simpleBodyGroups);
        if (1) {}
    }
    D_8011DF08[collision->type](globalCtx, collision);
    temp_v1_2 = collision->actor;
    if ((temp_v1_2 != NULL) && (collision->actor->update == NULL)) {
        return -1;
    }
    temp_v1 = simpleBodyGroups->unkCC_nAC;
    if (temp_v1 >= ARRAY_COUNT(simpleBodyGroups->unkD0_AC)) {
        osSyncPrintf("CollisionCheck_setAC():インデックスがオーバして追加不能\n");
        return -1;
    }
    if (simpleBodyGroups->unk2 & 1) {
        return -1;
    }
    simpleBodyGroups->unkD0_AC[temp_v1] = collision;
    simpleBodyGroups->unkCC_nAC += 1;
    return temp_v1;
}

// unused
s32 func_8005DB04(GlobalContext* arg0, SubGlobalContext11E60* arg1, Collider* arg2, s32 arg3) {
    Actor* temp_v1;

    if (arg2->type >= 4) {
        func_80001FF0("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xC51);
    }
    if (func_800C0D28(arg0) == 1) {
        return -1;
    }
    D_8011DF08[arg2->type](arg0, arg2);
    temp_v1 = arg2->actor;
    if ((temp_v1 != NULL) && (arg2->actor->update == NULL)) {
        return -1;
    }
    if (arg1->unk2 & 1) {
        if (arg3 >= arg1->unkCC_nAC) {
            osSyncPrintf("CollisionCheck_setAC_SAC():全データ数より大きいところに登録しようとしている。\n");
            return -1;
        }
        arg1->unkD0_AC[arg3] = arg2;
    } else {
        if (arg1->unkCC_nAC >= ARRAY_COUNT(arg1->unkD0_AC)) {
            osSyncPrintf("CollisionCheck_setAC():インデックスがオーバして追加不能\n");
            return -1;
        }
        arg3 = arg1->unkCC_nAC;
        arg1->unkD0_AC[arg3] = arg2;
        arg1->unkCC_nAC += 1;
    }
    return arg3;
}

extern callback_8011DEF8 D_8011DF18[];

s32 func_8005C234_SetOT_0(GlobalContext*, Collider*);
s32 func_8005C578_SetOT_1(GlobalContext*, Collider*);
s32 func_8005CDD0_SetOT_2(GlobalContext*, Collider*);
s32 func_8005D1E0_SetOT_3(GlobalContext*, Collider*);

#if 0
callback_8011DEF8 D_8011DF18[] = {
    func_8005C234_SetOT_0,
    func_8005C578_SetOT_1,
    func_8005CDD0_SetOT_2,
    func_8005D1E0_SetOT_3,
};
#endif

s32 Actor_CollisionCheck_SetOT(GlobalContext* globalCtx, SubGlobalContext11E60* simpleBodyGroups, Collider* collision) {
    Actor* temp_v1_2;
    s32 temp_v1;

    if (1) {}
    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collision->type >= 4) {
        func_80001FF0("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xC9D, simpleBodyGroups);
        if (1) {}
    }
    D_8011DF18[collision->type](globalCtx, collision);
    temp_v1_2 = collision->actor;
    if ((temp_v1_2 != NULL) && (collision->actor->update == NULL)) {
        return -1;
    }
    temp_v1 = simpleBodyGroups->unk1C0_nOT;
    if (temp_v1 >= 0x32) {
        osSyncPrintf("CollisionCheck_setOC():インデックスがオーバして追加不能\n");
        return -1;
    }
    if (simpleBodyGroups->unk2 & 1) {
        return -1;
    }
    simpleBodyGroups->unk1C4_OT[temp_v1] = collision;
    simpleBodyGroups->unk1C0_nOT += 1;
    return temp_v1;
}

// unused
s32 func_8005DD5C(GlobalContext* arg0, SubGlobalContext11E60* arg1, Collider* arg2, s32 arg3) {
    Actor* temp_v1;

    if (func_800C0D28(arg0) == 1) {
        return -1;
    }
    if (arg2->type >= 4) {
        func_80001FF0("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xCCA);
        if (1) {}
    }
    D_8011DF18[arg2->type](arg0, arg2);
    temp_v1 = arg2->actor;
    if ((temp_v1 != NULL) && (arg2->actor->update == NULL)) {
        return -1;
    }
    if (arg1->unk2 & 1) {
        if (arg3 >= arg1->unk1C0_nOT) {
            osSyncPrintf("CollisionCheck_setOC_SAC():全データ数より大きいところに登録しようとしている。\n");
            return -1;
        }
        arg1->unk4_AT[arg3] = arg2;
    } else {
        if (arg1->unk1C0_nOT >= ARRAY_COUNT(arg1->unk1C4_OT)) {
            osSyncPrintf("CollisionCheck_setOC():インデックスがオーバして追加不能\n");
            return -1;
        }
        arg3 = arg1->unk1C0_nOT;
        arg1->unk1C4_OT[arg3] = arg2;
        arg1->unk1C0_nOT += 1;
    }
    return arg3;
}

typedef struct struct_8005DE9C {
    char unk_0[0x28C];
    s32 unk28C;
    void* unk_290[UNK_SIZE];
} struct_8005DE9C;

// unused
s32 func_8005DE9C(GlobalContext* arg0, struct_8005DE9C* arg1, struct_8005D3A4* arg2) {
    s32 temp_v1;

    if (func_800C0D28(arg0) == 1) {
        return -1;
    }
    func_8005D3A4((s32)arg0, arg2);
    temp_v1 = arg1->unk28C;
    if (temp_v1 >= 3) {
        osSyncPrintf("CollisionCheck_setOCLine():インデックスがオーバして追加不能\n");
        return -1;
    }
    arg1->unk_290[temp_v1] = arg2;
    arg1->unk28C = (s32)(arg1->unk28C + 1);
    return temp_v1;
}

s32 func_8005DF2C(ColliderBody* arg0) {
    if (!(arg0->toucherFlags & 1)) {
        return 1;
    }
    return 0;
}

s32 func_8005DF50(ColliderBody* arg0) {
    if (!(arg0->bumperFlags & 1)) {
        return 1;
    }
    return 0;
}

s32 func_8005DF74(ColliderBody* arg0, ColliderBody* arg1) {
    if (!(arg0->toucher.flags & arg1->bumper.flags)) {
        return 1;
    }

    return 0;
}

void func_8005DF9C(s32 arg0, s32 arg1, s32 arg2) {
}

typedef struct struct_8015D8A0 {
    /* 0x000 */ Vec3s unk0;
    /* 0x006 */ char unk_6[0x486];
    /* 0x48C */ f32 unk48C;
    /* 0x490 */ f32 unk490;
    /* 0x494 */ s32 unk494;
    /* 0x498 */ s32 unk498;
    /* 0x49C */ s8 unk49C;
    /* 0x49D */ s8 unk49D;
    /* 0x49E */ s8 unk49E;
    /* 0x49F */ s8 unk49F;
    /* 0x4A0 */ s8 unk4A0;
    /* 0x4A1 */ s8 unk4A1;
    /* 0x4A2 */ s8 unk4A2;
    /* 0x4A3 */ s8 unk4A3;
    /* 0x4A4 */ s8 unk4A4;
    /* 0x4A5 */ s8 unk4A5;
    /* 0x4A6 */ s8 unk4A6;
    /* 0x4A7 */ s8 unk4A7;
    /* 0x4A8 */ s8 unk4A8;
    /* 0x4A9 */ s8 unk4A9;
    /* 0x4AA */ s8 unk4AA;
    /* 0x4AB */ s8 unk4AB;
    /* 0x4AC */ s8 unk4AC;
    /* 0x4AD */ s8 unk4AD;
    /* 0x4AE */ s8 unk4AE;
    /* 0x4AF */ s8 unk4AF;
    /* 0x4B0 */ s8 unk4B0;
    /* 0x4B1 */ s8 unk4B1;
    /* 0x4B2 */ s8 unk4B2;
    /* 0x4B3 */ s8 unk4B3;
    /* 0x4B4 */ s8 unk4B4;
    /* 0x4B5 */ s8 unk4B5;
    /* 0x4B6 */ s8 unk4B6;
    /* 0x4B7 */ s8 unk4B7;
    /* 0x4B8 */ s8 unk4B8;
    /* 0x4B9 */ s8 unk4B9;
    /* 0x4BA */ s8 unk4BA;
    /* 0x4BB */ s8 unk4BB;
    s32 unk4BC;
    s32 unk4C0;
} struct_8015D8A0;

#ifdef NON_MATCHING
// https://decomp.me/scratch/aKq4j
void func_8005DFAC(GlobalContext* arg0, s32 arg1, Vec3f* arg2) {
    static struct_8015D8A0 D_8015D8A0;

    s32 sp24;

    D_8015D8A0.unk0.x = (s16)(s32)arg2->x;
    D_8015D8A0.unk0.y = (s16)(s32)arg2->y;
    D_8015D8A0.unk0.z = (s16)(s32)arg2->z;
    D_8015D8A0.unk494 = 5;
    D_8015D8A0.unk498 = 5;
    D_8015D8A0.unk49C = 0xA;
    D_8015D8A0.unk49D = 0xA;
    D_8015D8A0.unk49E = -0x38;
    D_8015D8A0.unk49F = -1;
    D_8015D8A0.unk4A0 = 0;
    D_8015D8A0.unk4A1 = 0;
    D_8015D8A0.unk4A2 = 0x80;
    D_8015D8A0.unk4A3 = -1;
    D_8015D8A0.unk4A4 = 0;
    D_8015D8A0.unk4A5 = 0;
    D_8015D8A0.unk4A6 = 0x80;
    D_8015D8A0.unk4A7 = -1;
    D_8015D8A0.unk4A8 = 0;
    D_8015D8A0.unk4A9 = 0;
    D_8015D8A0.unk4AA = 0x80;
    D_8015D8A0.unk4AB = -1;
    D_8015D8A0.unk4AC = 0;
    D_8015D8A0.unk4AD = 0;
    D_8015D8A0.unk4AE = 0x20;
    D_8015D8A0.unk4AF = 0;
    D_8015D8A0.unk4B0 = 0;
    D_8015D8A0.unk4B1 = 0;
    D_8015D8A0.unk4B2 = 0x20;
    D_8015D8A0.unk4B3 = 0;
    D_8015D8A0.unk4B4 = 0;
    D_8015D8A0.unk4B5 = 0;
    D_8015D8A0.unk4B6 = 0x40;
    D_8015D8A0.unk4B7 = 0;
    D_8015D8A0.unk4B8 = 0;
    D_8015D8A0.unk4B9 = 0;
    D_8015D8A0.unk4BA = 0x40;
    D_8015D8A0.unk4BB = 0;
    D_8015D8A0.unk4BC = 0;
    D_8015D8A0.unk4C0 = 0x10;
    D_8015D8A0.unk48C = 8.0f;
    D_8015D8A0.unk490 = -1.0f;
    Effect_Add(arg0, &sp24, 0, 0U, 1U, &D_8015D8A0);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005DFAC.s")
#endif

#ifdef NON_MATCHING
void func_8005E10C(GlobalContext* arg0, s32 arg1, Vec3f* arg2) {
    static struct_8015D8A0 D_8015DD68;
    s32 sp24;

    D_8015DD68.unk0.x = (s16)(s32)arg2->x;
    D_8015DD68.unk0.y = (s16)(s32)arg2->y;
    D_8015DD68.unk0.z = (s16)(s32)arg2->z;
    D_8015DD68.unk494 = 5;
    D_8015DD68.unk498 = 5;
    D_8015DD68.unk49C = 0xA;
    D_8015DD68.unk49D = -0x38;
    D_8015DD68.unk49E = 0xA;
    D_8015DD68.unk49F = -1;
    D_8015DD68.unk4A0 = 0;
    D_8015DD68.unk4A1 = 0x80;
    D_8015DD68.unk4A2 = 0;
    D_8015DD68.unk4A3 = -1;
    D_8015DD68.unk4A4 = 0;
    D_8015DD68.unk4A5 = 0x80;
    D_8015DD68.unk4A6 = 0;
    D_8015DD68.unk4A7 = -1;
    D_8015DD68.unk4A8 = 0;
    D_8015DD68.unk4A9 = 0x80;
    D_8015DD68.unk4AA = 0;
    D_8015DD68.unk4AB = -1;
    D_8015DD68.unk4AC = 0;
    D_8015DD68.unk4AD = 0x20;
    D_8015DD68.unk4AE = 0;
    D_8015DD68.unk4AF = 0;
    D_8015DD68.unk4B0 = 0;
    D_8015DD68.unk4B1 = 0x20;
    D_8015DD68.unk4B2 = 0;
    D_8015DD68.unk4B3 = 0;
    D_8015DD68.unk4B4 = 0;
    D_8015DD68.unk4B5 = 0x40;
    D_8015DD68.unk4B6 = 0;
    D_8015DD68.unk4B7 = 0;
    D_8015DD68.unk4B8 = 0;
    D_8015DD68.unk4B9 = 0x40;
    D_8015DD68.unk4BA = 0;
    D_8015DD68.unk4BB = 0;
    D_8015DD68.unk4BC = 0;
    D_8015DD68.unk4C0 = 0x10;
    D_8015DD68.unk48C = 8.0f;
    D_8015DD68.unk490 = -1.0f;
    Effect_Add(arg0, &sp24, 0, 0U, 1U, &D_8015DD68);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005E10C.s")
#endif

void func_80062B80(GlobalContext* arg0, Vec3f* arg1);

void func_8005E26C(s32 arg0, s32 arg1, s32 arg2) {
    func_800299AC(arg0, arg2);
    func_80062B80(arg0, arg2);
}

void func_80062A28(GlobalContext* arg0, Vec3f* arg1);

void func_8005E2A4(GlobalContext* arg1, s32 arg2, Vec3f* arg3) {
    func_80062A28(arg1, arg3);
}

void func_8005E2C8(GlobalContext* arg1, s32 arg2, Vec3f* arg3) {
    func_80062A28(arg1, arg3);
}

void func_80062D60(GlobalContext* arg0, Vec3f* arg1);
void func_80062DAC(GlobalContext* arg0, Vec3f* arg1, Vec3f* arg2);

void func_8005E2EC(GlobalContext* arg0, ColliderBody* arg1, Collider* arg2, Vec3f* arg3) {
    if (((arg1->toucherFlags & 0x18) == 0) && (arg2->unk_14 != 9)) {
        func_80029CA4(arg0, 0, arg3);
        if (arg2->actor == NULL) {
            Audio_PlaySoundGeneral(0x1806U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else {
            Audio_PlaySoundGeneral(0x1806U, &arg2->actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    } else if ((arg1->toucherFlags & 0x18) == 0) {
        func_80029CA4(arg0, 3, arg3);
        if (arg2->actor == NULL) {
            func_80062D60(arg0, arg3);
        } else {
            func_80062DAC(arg0, arg3, &arg2->actor->unk_E4);
        }
    } else if ((arg1->toucherFlags & 0x18) == 8) {
        func_80029CA4(arg0, 0, arg3);
        if (arg2->actor == NULL) {
            Audio_PlaySoundGeneral(0x1806U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else {
            Audio_PlaySoundGeneral(0x1806U, &arg2->actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    } else if ((arg1->toucherFlags & 0x18) == 0x10) {
        func_80029CA4(arg0, 1, arg3);
        if (arg2->actor == NULL) {
            Audio_PlaySoundGeneral(0x1837U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else {
            Audio_PlaySoundGeneral(0x1837U, &arg2->actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    }
}

s32 func_8005E4F8(Collider* arg0, ColliderBody* arg1) {
    Actor* temp_v1;

    temp_v1 = arg0->actor;
    if ((temp_v1 != NULL) && (temp_v1->type == 2)) {
        if (arg1->flags == 0) {
            Audio_PlaySoundGeneral(0x1811U, &temp_v1->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else if (arg1->flags == 1) {
            Audio_PlaySoundGeneral(0x1824U, &temp_v1->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else if (arg1->flags == 2) {
            Audio_PlaySoundGeneral(0U, &temp_v1->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else if (arg1->flags == 3) {
            Audio_PlaySoundGeneral(0U, &temp_v1->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    }
    return 1;
}

typedef void (*callback_8011DF28)(GlobalContext*, Collider*, Vec3f*);
extern callback_8011DF28 D_8011DF28[];
extern u8 D_8011DF40[][2];

void func_80062CD4(GlobalContext* arg0, Vec3f* arg1);
void func_80062E14(GlobalContext* arg0, Vec3f* arg1, Vec3f* arg2);

void func_8005E604(GlobalContext* arg0, Collider* arg1, ColliderBody* arg2, Collider* arg3, ColliderBody* arg4,
                   Vec3f* arg5) {
    if (!(arg4->bumperFlags & 0x40) && ((((arg2->toucherFlags & 0x20) != 0)) || !(arg2->toucherFlags & 0x40))) {
        if (arg3->actor != NULL) {
            D_8011DF28[D_8011DF40[arg3->unk_14][0]](arg0, arg3, arg5);
        }
        do {
        } while (0);
        if (arg3->actor != NULL) {
            if (D_8011DF40[arg3->unk_14][1] == 3) {
                func_8005E2EC(arg0, arg2, arg3, arg5);
            } else if (D_8011DF40[arg3->unk_14][1] == 4) {
                if (arg1->actor == NULL) {
                    func_80062CD4(arg0, arg5);
                    Audio_PlaySoundGeneral(0x1837U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
                } else {
                    func_80062E14(arg0, arg5, &arg1->actor->unk_E4);
                }
            } else if (D_8011DF40[arg3->unk_14][1] != 5) {
                func_80029CA4(arg0, D_8011DF40[arg3->unk_14][1], arg5);
                if (!(arg4->bumperFlags & 0x20)) {
                    func_8005E4F8(arg1, arg4);
                }
            }
        } else {
            func_80029CA4(arg0, 0U, arg5);
            if (arg3->actor == NULL) {
                Audio_PlaySoundGeneral(0x1806U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
            } else {
                Audio_PlaySoundGeneral(0x1806U, &arg3->actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
            }
        }
    }
}

void func_8005E800(Collider* arg0, Collider* arg1) {
    arg0->colliderFlags |= 4;
    arg1->collideFlags |= 0x80;
}

s32 func_8005E81C(GlobalContext* arg0, Collider* arg1, ColliderBody* arg2, s32 arg3, Collider* arg4, ColliderBody* arg5,
                  s32 arg6, Vec3f* arg7) {
    if ((arg4->collideFlags & 4) && (arg1->actor != NULL) && (arg4->actor != NULL)) {
        func_8005E800(arg1, arg4);
    }
    if (!(arg5->bumperFlags & 8)) {
        arg1->colliderFlags |= 2;
        arg1->at = arg4->actor;
        arg2->unk_18 = (s32)arg4;
        arg2->unk_20 = (s32)arg5;
        arg2->toucherFlags |= 2;
        if (arg1->actor != NULL) {
            arg1->actor->sub_98.impactEffect = arg5->bumper.effect;
        }
    }
    arg4->collideFlags |= 2;
    arg4->ac = arg1->actor;
    arg5->colBuf = (struct Collider*)arg1;
    arg5->colliding = arg2;
    arg5->bumperFlags |= 2;
    if (arg4->actor != NULL) {
        arg4->actor->sub_98.unk_1B = arg2->toucher.unk_04;
    }
    arg5->bumper.unk_06.x = (s16)(s32)arg7->x;
    arg5->bumper.unk_06.y = (s16)(s32)arg7->y;
    arg5->bumper.unk_06.z = (s16)(s32)arg7->z;
    if (!(arg2->toucherFlags & 0x20) && ((arg4->unk_14 != 9)) && (arg4->unk_14 != 0xB) && (arg4->unk_14 != 0xC)) {
        arg5->bumperFlags |= 0x80;
    } else {
        func_8005E604(arg0, arg1, arg2, arg4, arg5, arg7);
        arg2->toucherFlags |= 0x40;
    }
    return 1;
}

#ifdef NON_MATCHING
void func_8005E9C0_0vs0(GlobalContext* arg0, SubGlobalContext11E60* arg1, Collider* arg2, Collider* arg3) {
    f32 sp8C;
    f32 sp88;
    Vec3f sp78;
    Vec3f sp6C;
    Vec3f sp60;
    f32 temp_fv0_2;
    Collider_Type0_ptr1C* var_s1;
    Collider_Type0_ptr1C* var_s0;
    Collider_Type0* arg2_0 = (Collider_Type0*)arg2;
    Collider_Type0* arg3_0 = (Collider_Type0*)arg3;

    if ((((arg2_0->unk18 > 0) && (arg2_0->unk1C != NULL)) && (arg3_0->unk18 > 0)) && (arg3_0->unk1C != NULL)) {
        for (var_s1 = arg2_0->unk1C; ((u32)var_s1) < ((u32)(arg2_0->unk1C + arg2_0->unk18)); var_s1++) {
            if (func_8005DF2C(&var_s1->unk0) != 1) {
                for (var_s0 = arg3_0->unk1C; ((u32)var_s0) < ((u32)(arg3_0->unk1C + arg3_0->unk18)); var_s0++) {
                    if (((func_8005DF50(&var_s0->unk0) != 1) && (func_8005DF74(&var_s1->unk0, &var_s0->unk0) != 1)) &&
                        (Math3D_SpheresTouchingSurfaceCenter(&var_s1->unk28.unk8, &var_s0->unk28.unk8, &sp8C, &sp88) ==
                         1)) {
                        sp6C.x = (f32)var_s1->unk28.unk8.center.x;
                        sp6C.y = (f32)var_s1->unk28.unk8.center.y;
                        sp6C.z = (f32)var_s1->unk28.unk8.center.z;
                        sp60.x = (f32)var_s0->unk28.unk8.center.x;
                        sp60.y = (f32)var_s0->unk28.unk8.center.y;
                        sp60.z = (f32)var_s0->unk28.unk8.center.z;
                        if (!(fabsf(sp88) < 0.008f)) {
                            temp_fv0_2 = ((f32)var_s0->unk28.unk8.radius) / sp88;
                            sp78.x = ((sp6C.x - sp60.x) * temp_fv0_2) + sp60.x;
                            sp78.y = ((sp6C.y - sp60.y) * temp_fv0_2) + sp60.y;
                            sp78.z = ((sp6C.z - sp60.z) * temp_fv0_2) + sp60.z;
                        } else {
                            Math_Vec3f_Copy(&sp78, &sp6C);
                        }
                        func_8005E81C(arg0, &arg2_0->unk0, &var_s1->unk0, (s32)&sp6C, &arg3_0->unk0, &var_s0->unk0,
                                      (s32)(&sp60), &sp78);
                        if (!(arg3_0->unk0.maskB & 0x40)) {
                            return;
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005E9C0_0vs0.s")
#endif

#ifdef NON_MATCHING
void func_8005EC6C_0vs1(GlobalContext* arg0, SubGlobalContext11E60* arg1, Collider* arg2, Collider* arg3) {
    f32 sp80;
    f32 sp7C;
    Vec3f sp70;
    Vec3f sp64;
    Vec3f sp58;
    f32 temp_fv0_2;
    ColliderBody* temp_s6;
    Collider_Type0_ptr1C* var_s0;
    Collider_Type0* arg2_0 = arg2;
    Collider_Type1* arg3_1 = arg3;

    if ((arg2_0->unk18 > 0) && (arg2_0->unk1C != NULL) && (arg3_1->unk40.radius > 0)) {
        temp_s6 = &arg3_1->unk18;
        if (((arg3_1->unk40.height > 0)) && (func_8005DF50(temp_s6) != 1)) {
            for (var_s0 = arg2_0->unk1C; ((((u32)var_s0 < (u32)&var_s0[arg2_0->unk18]))); var_s0++) {
                if ((func_8005DF2C(&var_s0->unk0) != 1) && (func_8005DF74(&var_s0->unk0, temp_s6) != 1) &&
                    (func_800CFDA4(&var_s0->unk28.unk8, &arg3_1->unk40, &sp80, &sp7C) != 0)) {
                    sp64.x = (f32)var_s0->unk28.unk8.center.x;
                    sp64.y = (f32)var_s0->unk28.unk8.center.y;
                    sp64.z = (f32)var_s0->unk28.unk8.center.z;
                    sp58.x = (f32)arg3_1->unk40.pos.x;
                    sp58.y = (f32)arg3_1->unk40.pos.y;
                    sp58.z = (f32)arg3_1->unk40.pos.z;
                    if (!(fabsf(sp7C) < 0.008f)) {
                        temp_fv0_2 = (f32)arg3_1->unk40.radius / sp7C;
                        if (temp_fv0_2 <= 1.0f) {
                            sp70.x = ((sp64.x - sp58.x) * temp_fv0_2) + sp58.x;
                            sp70.y = ((sp64.y - sp58.y) * temp_fv0_2) + sp58.y;
                            sp70.z = ((sp64.z - sp58.z) * temp_fv0_2) + sp58.z;
                        } else {
                            Math_Vec3f_Copy((Vec3f*)&sp70, (Vec3f*)&sp64);
                        }
                    } else {
                        Math_Vec3f_Copy((Vec3f*)&sp70, (Vec3f*)&sp64);
                    }
                    func_8005E81C(arg0, &arg2_0->unk0, &var_s0->unk0, &sp64, &arg3_1->unk0, temp_s6, &sp58, &sp70);
                    return;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005EC6C_0vs1.s")
#endif

#ifdef NON_MATCHING
void func_8005EEE0_1vs0(GlobalContext* arg0, SubGlobalContext11E60* arg1, Collider* arg2, Collider* arg3) {
    f32 sp9C;
    f32 sp98;
    Vec3f sp88;
    Vec3f sp7C;
    Vec3f sp70;
    f32 temp_fv0_2;
    ColliderBody* temp_s4;
    Collider_Type0_ptr1C* var_s0;
    Collider_Type1* arg2_1 = arg2;
    Collider_Type0* arg3_0 = arg3;

    if ((arg3_0->unk18 > 0) && (arg3_0->unk1C != 0) && (arg2_1->unk40.radius > 0)) {
        temp_s4 = &arg2_1->unk18;
        if ((arg2_1->unk40.height > 0) && (func_8005DF2C(temp_s4) != 1)) {
            var_s0 = arg3_0->unk1C;
            while (var_s0 < (arg3_0->unk1C + (arg3_0->unk18))) {
                if ((func_8005DF50(&var_s0->unk0) != 1) && (func_8005DF74(temp_s4, &var_s0->unk0) != 1) &&
                    (func_800CFDA4(&var_s0->unk28.unk8, &arg2_1->unk40, &sp9C, &sp98) != 0)) {
                    sp7C.x = (f32)arg2_1->unk40.pos.x;
                    sp7C.y = (f32)arg2_1->unk40.pos.y;
                    sp7C.z = (f32)arg2_1->unk40.pos.z;
                    sp70.x = (f32)var_s0->unk28.unk8.center.x;
                    sp70.y = (f32)var_s0->unk28.unk8.center.y;
                    sp70.z = (f32)var_s0->unk28.unk8.center.z;
                    if (!(fabsf(sp98) < 0.008f)) {
                        temp_fv0_2 = (f32)var_s0->unk28.unk8.radius / sp98;
                        if (temp_fv0_2 <= 1.0f) {
                            sp88.x = ((sp7C.x - sp70.x) * temp_fv0_2) + sp70.x;
                            sp88.y = ((sp7C.y - sp70.y) * temp_fv0_2) + sp70.y;
                            sp88.z = ((sp7C.z - sp70.z) * temp_fv0_2) + sp70.z;
                        } else {
                            Math_Vec3f_Copy(&sp88, &sp7C);
                        }
                    } else {
                        Math_Vec3f_Copy(&sp88, &sp7C);
                    }
                    func_8005E81C(arg0, arg2, temp_s4, &sp7C, &arg3_0->unk0, var_s0, &sp70, &sp88);
                    if (!(arg3_0->unk0.maskB & 0x40)) {
                        return;
                    }
                }
                var_s0++;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005EEE0_1vs0.s")
#endif

#ifdef NON_MATCHING
void func_8005F17C_0vs2(GlobalContext* arg0, SubGlobalContext11E60* arg1, Collider* arg2, Collider* arg3) {
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;
    Collider_Type2_ptr1C* var_s0;
    Collider_Type0_ptr1C* var_s2;
    Collider_Type0* arg2_0 = arg2;
    Collider_Type2* arg3_2 = arg3;

    if ((arg2_0->unk18 > 0)) {
        if (((arg2_0->unk1C != 0)) && (arg3_2->unk18 > 0) && (arg3_2->unk1C != 0)) {
            var_s2 = arg2_0->unk1C;
            while ((((arg2_0->unk1C < (arg2_0->unk1C + (arg2_0->unk18)))))) {
                if (func_8005DF2C(var_s2) != 1) {
                    var_s0 = arg3_2->unk1C;
                    while (var_s0 < (arg3_2->unk1C + (arg3_2->unk18))) {
                        if ((func_8005DF50(&var_s0->unk_0) != 1) &&
                            (func_8005DF74(&var_s2->unk0, &var_s0->unk_0) != 1) &&
                            (func_800CE934(&var_s2->unk28.unk8, &var_s0->unk28, &sp6C) == 1)) {
                            sp60.x = (f32)var_s2->unk28.unk8.center.x;
                            sp60.y = (f32)var_s2->unk28.unk8.center.y;
                            sp60.z = (f32)var_s2->unk28.unk8.center.z;
                            sp54.x = (var_s0->unk28.vtx[2].x + (var_s0->unk28.vtx[0].x + var_s0->unk28.vtx[1].x)) *
                                     0.33333334f;
                            sp54.y = (var_s0->unk28.vtx[2].y + (var_s0->unk28.vtx[0].y + var_s0->unk28.vtx[1].y)) *
                                     0.33333334f;
                            sp54.z = (var_s0->unk28.vtx[2].z + (var_s0->unk28.vtx[0].z + var_s0->unk28.vtx[1].z)) *
                                     0.33333334f;
                            func_8005E81C(arg0, &arg2_0->unk0, var_s2, &sp60, &arg3_2->unk0, var_s0, &sp54, &sp6C);
                            return;
                        }
                        var_s0 += 1;
                    }
                }
                var_s2++;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005F17C_0vs2.s")
#endif

#ifdef NON_MATCHING
void func_8005F39C(GlobalContext* arg0, SubGlobalContext11E60* arg1, Collider* arg2, Collider* arg3) {
    Vec3f sp7C;
    Vec3f sp70;
    Vec3f sp64;
    Collider_Type0_ptr1C* var_s3;
    Collider_Type2_ptr1C* var_s0;
    Collider_Type2* arg2_2 = arg2;
    Collider_Type0* arg3_0 = arg3;

    if (arg3_0->unk18 > 0) {
        if ((arg3_0->unk1C != NULL) && (arg2_2->unk18 > 0) && (arg2_2->unk1C != 0)) {
            for (var_s3 = arg3_0->unk1C; (u32)var_s3 < (u32)(arg3_0->unk1C + arg3_0->unk18); var_s3++) {
                if ((func_8005DF50(var_s3) != 1)) {
                    for (var_s0 = arg2_2->unk1C; ((((u32)var_s0 < (u32)(arg2_2->unk1C + (arg2_2->unk18))))); var_s0++) {
                        if (((func_8005DF2C(&var_s0->unk0) != 1))) {
                            if ((((func_8005DF74(&var_s0->unk0, &var_s3->unk0) != 1)) &&
                                 (func_800CE934(&var_s3->unk28.unk8, &var_s0->unk28, &sp7C) == 1))) {
                                Math_Vec3s_ToVec3f(&sp64, &var_s3->unk28.unk8.center);
                                sp70.x = (var_s0->unk28.vtx[2].x + (var_s0->unk28.vtx[0].x + var_s0->unk28.vtx[1].x)) *
                                         0.33333334f;
                                sp70.y = (var_s0->unk28.vtx[2].y + (var_s0->unk28.vtx[0].y + var_s0->unk28.vtx[1].y)) *
                                         0.33333334f;
                                sp70.z = (var_s0->unk28.vtx[2].z + (var_s0->unk28.vtx[0].z + var_s0->unk28.vtx[1].z)) *
                                         0.33333334f;
                                func_8005E81C(arg0, &arg2_2->unk0, var_s0, (s32)&sp70, &arg3_0->unk0, var_s3,
                                              (s32)&sp64, &sp7C);
                                if (((((arg3_0->unk0.maskB & 0x40) == 0)))) {
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005F39C.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005F5B0_0vs3.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005F7D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005FA30_1vs1.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005FC04.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005FDCC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005FF90.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80060204.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800604B0_2vs2.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80060704.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80060994.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80060C2C_3vs3.s")

#if 0

#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80060EBC.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80060F94.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061028.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8006110C.s")

typedef void (*callback_800611A0)(GlobalContext*, SubGlobalContext11E60*, Collider*);

extern callback_800611A0 D_8011DF5C[];

void func_80060EBC(GlobalContext*, SubGlobalContext11E60*, Collider*);
void func_80060F94(GlobalContext*, SubGlobalContext11E60*, Collider*);
void func_80061028(GlobalContext*, SubGlobalContext11E60*, Collider*);
void func_8006110C(GlobalContext*, SubGlobalContext11E60*, Collider*);

#if 0
callback_800611A0 D_8011DF5C[] = {
    func_80060EBC,
    func_80060F94,
    func_80061028,
    func_8006110C,
};
#endif

void func_800611A0(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx) {
    Collider** var_s0;
    Collider* temp_a2;

    var_s0 = colChkCtx->unkD0_AC;
    while (var_s0 < &colChkCtx->unkD0_AC[colChkCtx->unkCC_nAC]) {
        temp_a2 = *var_s0;
        if ((temp_a2 != NULL) && (temp_a2->collideFlags & 1) &&
            (((temp_a2->actor == NULL)) || (temp_a2->actor->update != NULL))) {
            D_8011DF5C[temp_a2->type](globalCtx, colChkCtx, temp_a2);
        }
        var_s0++;
    }
}

typedef void (*callback_8011DF6C)(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);

extern callback_8011DF6C D_8011DF6C[4][4];

void func_8005E9C0_0vs0(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005EC6C_0vs1(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005F17C_0vs2(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005F5B0_0vs3(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005EEE0_1vs0(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005FA30_1vs1(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005FC04(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005FF90(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005F39C(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005FDCC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_800604B0_2vs2(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_80060704(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005F7D0(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_80060204(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_80060994(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_80060C2C_3vs3(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);

#if 0
callback_8011DF6C D_8011DF6C[4][4] = {
    { func_8005E9C0_0vs0, func_8005EC6C_0vs1, func_8005F17C_0vs2, func_8005F5B0_0vs3 },
    { func_8005EEE0_1vs0, func_8005FA30_1vs1, func_8005FC04, func_8005FF90 },
    { func_8005F39C, func_8005FDCC, func_800604B0_2vs2, func_80060704 },
    { func_8005F7D0, func_80060204, func_80060994, func_80060C2C_3vs3 },
};
#endif

void func_80061274(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2) {
    Collider** var_s1;
    Collider* temp_a3;

    var_s1 = colChkCtx->unkD0_AC;
    while ((u32)var_s1 < (u32)&colChkCtx->unkD0_AC[colChkCtx->unkCC_nAC]) {
        temp_a3 = *var_s1;
        if (temp_a3 != NULL) {
            if ((temp_a3->collideFlags & 1) && (((temp_a3->actor == NULL)) || (temp_a3->actor->update != NULL))) {
                if ((temp_a3->collideFlags & arg2->colliderFlags & 0x38) && (arg2 != temp_a3) &&
                    ((arg2->colliderFlags & 0x40) || ((arg2->actor == NULL)) || (temp_a3->actor != arg2->actor))) {
                    D_8011DF6C[arg2->type][temp_a3->type](globalCtx, colChkCtx, arg2, temp_a3);
                }
            }
        }
        var_s1++;
    }
}

void func_8006139C(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx) {
    Actor* temp_v0;
    Collider** var_s0;
    Collider* temp_a2_2;

    if ((colChkCtx->unk0_nAT != 0) && (colChkCtx->unkCC_nAC != 0)) {
        for (var_s0 = colChkCtx->unk4_AT; (u32)var_s0 < (u32)&colChkCtx->unk4_AT[colChkCtx->unk0_nAT]; var_s0 += 1) {
            temp_a2_2 = *var_s0;
            if ((temp_a2_2 != NULL) && (temp_a2_2->colliderFlags & 1) &&
                (((temp_a2_2->actor == NULL)) || (temp_a2_2->actor->update != NULL))) {
                func_80061274(globalCtx, colChkCtx, temp_a2_2);
            }
        }
        func_800611A0(globalCtx, colChkCtx);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8006146C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800614A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800617D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8006199C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061AF8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061B24.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061BF4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061C18.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061C98.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061E48.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061E8C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061EB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061ED4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061EFC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061F2C.s")

typedef struct sub_struct_80061F64_3 {
    /* 0x00 */ char unk0[0x98];
    /* 0x98 */ u8* unk98;
    /* 0x9C */ char unk9C[0x14];
    /* 0xB1 */ u8 unkB0;
    /* 0xB1 */ u8 unkB1;
} sub_struct_80061F64_3;

typedef struct sub_struct_80061F64_2 {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
} sub_struct_80061F64_2;

typedef struct sub_struct_80061F64_1 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ void* unk4;
    /* 0x08 */ char unk8[5];
    /* 0x0D */ u8 unkD;
    /* 0x0E */ char unkE[8];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ char unk17[0xD];
    /* 0x24 */ sub_struct_80061F64_2* ac_hit_elem;
} sub_struct_80061F64_1;

typedef struct struct_80061F64 {
    /* 0x00 */ sub_struct_80061F64_3* unk0;
    /* 0x04 */ char unk4[0xD];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ char unk12[6];
    /* 0x18 */ sub_struct_80061F64_1 unk18;
} struct_80061F64;

void func_80061F64(s32 arg0, void* arg1, struct_80061F64* arg2, sub_struct_80061F64_1* obj_elem) {
    f32 unkf;
    s32 i;
    u32 unk0;

    if (arg2->unk0 != NULL && (arg2->unk11 & 2)) {
        if ((obj_elem->unk16 & 2) && !(obj_elem->unk16 & 0x10)) {

            if (obj_elem->ac_hit_elem == NULL) {
                func_80001FF0("pclobj_elem->ac_hit_elem != NULL", "../z_collision_check.c", 0x195D);
            }

            if (arg2->unk0->unk98 == NULL) {
                unkf = (f32)obj_elem->ac_hit_elem->unk5 - (f32)obj_elem->unkD;
                if (unkf < 0.0f) {
                    unkf = 0.0f;
                }
            } else {
                unk0 = obj_elem->ac_hit_elem->unk0;

                for (i = 0; i < 32; i++) {
                    if (unk0 == 1) {
                        break;
                    }

                    unk0 >>= 1;
                }

                unkf = arg2->unk0->unk98[i] & 0xF;
                arg2->unk0->unkB1 = (arg2->unk0->unk98[i] >> 4) & 0xF;
            }

            if (!(arg2->unk11 & 4)) {
                arg2->unk0->unkB0 += unkf;
            }
            if (1) {}
            if (1) {}
        }
    }
}

void func_8006216C_Type0(GlobalContext* arg0, SubGlobalContext11E60* arg1, Collider* arg2) {
    Collider_Type0* new_var2 = arg2;
    Collider_Type0* new_var = arg2;
    s32 i;

    if (new_var->unk18 <= 0 || new_var->unk1C == NULL) {
        return;
    }

    for (i = 0; i < new_var2->unk18; i++) {
        func_80061F64(arg0, arg1, new_var, (void*)(new_var->unk1C + i));
    }
}

void func_80062210_Type1(GlobalContext* arg0, SubGlobalContext11E60* arg1, Collider* arg2) {
    Collider_Type1* new_var = arg2;

    func_80061F64(arg0, arg1, arg2, &new_var->unk18);
}

void func_80062230_Type2(GlobalContext* arg0, SubGlobalContext11E60* arg1, Collider* arg2) {
    s32 i;
    struct_80061F64* new_var = arg2;

    for (i = 0; i < new_var->unk18.unk0; i++) {
        func_80061F64(arg0, arg1, new_var, (void*)((u8*)new_var->unk18.unk4 + (i * 0x5C)));
    }
}

void func_800622C4_Type3(GlobalContext* arg0, SubGlobalContext11E60* arg1, Collider* arg2) {
    Collider_Type3* new_var = arg2;

    func_80061F64(arg0, arg1, arg2, &new_var->unk18);
}

typedef struct sub_struct_800622E4 {
    /* 0x00 */ char unk0[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12[3];
    /* 0x15 */ u8 unk15;
} sub_struct_800622E4;

typedef void (*func_ptr_800622E4)(GlobalContext*, SubGlobalContext11E60*, sub_struct_800622E4*);
extern func_ptr_800622E4 D_8011E008[];

void func_8006216C_Type0(GlobalContext*, SubGlobalContext11E60*, Collider*);
void func_80062210_Type1(GlobalContext*, SubGlobalContext11E60*, Collider*);
void func_80062230_Type2(GlobalContext*, SubGlobalContext11E60*, Collider*);
void func_800622C4_Type3(GlobalContext*, SubGlobalContext11E60*, Collider*);

#if 0
func_ptr_800622E4 D_8011E008[] = {
    func_8006216C_Type0,
    func_80062210_Type1,
    func_80062230_Type2,
    func_800622C4_Type3,
};
#endif

void func_800622E4(GlobalContext* globalCtx, SubGlobalContext11E60* subContext) {
    Collider* entry;
    s32 i;

    for (i = 0; i < subContext->unkCC_nAC; i++) {
        entry = subContext->unkD0_AC[i];

        if (entry == NULL) {
        } else if (entry->collideFlags & 0x40) {
        } else {
            D_8011E008[entry->type](globalCtx, subContext, entry);
        }
    }
}

typedef struct sub_struct_800623A4 {
    /* 0x00 */ char unk0[0x17];
    /* 0x17 */ u8 unk17;
    /* 0x18 */ char unk18[0x18];
    /* 0x30 */ Sphere16 sphere;
    /* 0x38 */ char unk38[0x8];
} sub_struct_800623A4; // size = 0x40

typedef struct struct_800623A4_1 {
    /* 0x00 */ char unk0[0x18];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ sub_struct_800623A4* unk1C;
} struct_800623A4_1;

typedef struct struct_800623A4_2 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
} struct_800623A4_2;

typedef struct struct_800623A4_3 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
} struct_800623A4_3;

extern Linef D_8015E610;
extern struct_800623A4_2 D_8015E61C;

s32 func_800623A4(s32 arg0, s32 arg1, struct_800623A4_1* arg2, Vec3f* arg3, struct_800623A4_2* arg4) {
    struct_800623A4_1* new_var;
    s32 i;
    sub_struct_800623A4* entry;

    new_var = arg2;
    for (i = 0; i < new_var->unk18; i++) {
        entry = arg2->unk1C + i;

        if (!(entry->unk17 & 1)) {
            continue;
        }

        D_8015E610.a = *arg3;
        D_8015E61C = *arg4;

        if (func_800CE600(&entry->sphere, &D_8015E610) == 1) {
            return 1;
        }
    }

    return 0;
}

typedef struct struct_800624BC {
    /* 0x00 */ char unk0[0x2F];
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ char unk30[0x10];
    /* 0x40 */ Cylinder16 cylinder;
} struct_800624BC;

s32 func_800624BC(s32 arg0, s32 arg1, struct_800624BC* arg2, Vec3f* arg3, Vec3f* arg4) {
    extern Vec3f D_8015E628;
    extern Vec3f D_8015E638;
    if (!(arg2->unk2F & 1)) {
        return 0;
    }

    if (func_800CEE0C(&arg2->cylinder, arg3, arg4, &D_8015E628, &D_8015E638) != 0) {
        return 1;
    }

    return 0;
}

typedef struct sub_struct_80062530 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ char unk4[0x11];
    /* 0x15 */ u8 unk15;
} sub_struct_80062530;

typedef struct struct_80062530 {
    /* 0x000 */ char unk0[0x1C0];
    /* 0x1C0 */ s32 unk1C0;
    /* 0x1C4 */ sub_struct_80062530* unk1C4[1];
} struct_80062530;

typedef s32 (*func_ptr_80062530)(void*, void*, sub_struct_80062530*, s32, s32);
extern func_ptr_80062530 D_8011E018[];

s32 func_80062530(void* arg0, struct_80062530* arg1, s32 arg2, s32 arg3, s32* unkList, s32 unkListCount) {
    func_ptr_80062530 func;
    s32 condition;
    s32 result = 0;
    s32 j;
    sub_struct_80062530** entryPtr = arg1->unk1C4;
    sub_struct_80062530* entry;

    for (; entryPtr < arg1->unk1C4 + arg1->unk1C0; entryPtr++) {
        if (func_80061BF4(*entryPtr) == 1) {
            continue;
        }

        condition = 0;
        for (j = 0; j < unkListCount; j++) {
            if ((*entryPtr)->unk0 == unkList[j]) {
                condition = true;
                break;
            }
        }

        if (condition == true) {
            continue;
        }

        entry = *entryPtr;
        func = D_8011E018[entry->unk15];

        if (func == NULL) {
            osSyncPrintf("CollisionCheck_generalLineOcCheck():未対応 %dタイプ\n", entry->unk15);
            continue;
        }

        result = func(arg0, arg1, entry, arg2, arg3);

        if (result != 0) {
            break;
        }
    }

    return result;
}

void func_8006268C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80062530(arg0, arg1, arg2, arg3, 0, 0);
}

void func_800626B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_80062530(arg0, arg1, arg2, arg3, arg4, arg5);
}

void ActorCollider_Type1_Update(Actor* actor, Collider_Type1* collision);
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/ActorCollider_Type1_Update.s")

typedef struct struct_80062718_1 {
    /* 0x00 */ char unk0[0x46];
    /* 0x46 */ s16 unk46;
    /* 0x48 */ s16 unk48;
    /* 0x4A */ s16 unk4A;
} struct_80062718_1;

typedef struct struct_80062718_2 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} struct_80062718_2;

// uses not decompiled
void func_80062718(struct_80062718_1* arg0, struct_80062718_2* arg1) {
    arg0->unk46 = arg1->unk0;
    arg0->unk48 = arg1->unk2;
    arg0->unk4A = arg1->unk4;
}

typedef struct struct_80062734 {
    char unk_0[0x40];
    struct_Collider_Type3_subc unk40;
} struct_80062734;

// uses not decompiled
void func_80062734(struct_80062734* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, Vec3f* arg4) {
    Math_Vec3f_Copy(&arg0->unk40.unk18, arg3);
    Math_Vec3f_Copy(&arg0->unk40.unk24, arg4);
    Math_Vec3f_Copy(&arg0->unk40.unk0, arg1);
    Math_Vec3f_Copy(&arg0->unk40.unkC, arg2);
    func_8005CEDC(&arg0->unk40);
}

typedef struct struct_800627A0_ptr {
    /* 0x00 */ char unk_0[0x28];
    /* 0x28 */ Vec3f unk28;
    /* 0x34 */ Vec3f unk34;
    /* 0x40 */ Vec3f unk40;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ f32 unk50;
    /* 0x54 */ f32 unk54;
    /* 0x58 */ f32 unk58;
} struct_800627A0_ptr;

typedef struct struct_800627A0 {
    char unk_0[0x1C];
    struct_800627A0_ptr* unk1C;
} struct_800627A0;

// uses not decompiled
void func_800627A0(struct_800627A0* arg0, s32 arg1, Vec3f* arg2, Vec3f* arg3, Vec3f* arg4) {
    struct_800627A0_ptr* temp_s0;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    temp_s0 = &arg0->unk1C[arg1];
    Math_Vec3f_Copy(&temp_s0->unk28, arg2);
    Math_Vec3f_Copy(&temp_s0->unk34, arg3);
    Math_Vec3f_Copy(&temp_s0->unk40, arg4);
    func_800CC8B4(arg2, arg3, arg4, &sp40, &sp3C, &sp38, &sp34);
    temp_s0->unk4C = sp40;
    temp_s0->unk50 = sp3C;
    temp_s0->unk54 = sp38;
    temp_s0->unk58 = sp34;
}

// unused
void func_8006285C(GlobalContext* arg0, struct_800627A0* arg1, s32 arg2, Vec3f* arg3) {
    struct_800627A0_ptr* new_var;

    new_var = &arg1->unk1C[arg2];
    func_8005C608(arg0, (struct_8005C608_arg1*)&new_var->unk28, arg3);
}

typedef struct struct_800628A4_ptr {
    char unk_0[0x28];
    Vec3s unk28;
    s16 unk2E;
    Vec3s unk30;
    s16 unk36;
    f32 unk38;
    u8 unk3C;
    char unk_3D[3];
} struct_800628A4_ptr;

typedef struct struct_800628A4 {
    char unk_0[0x18];
    s32 unk18;
    struct_800628A4_ptr* unk1C;
} struct_800628A4;

void func_800628A4_Type0(s32 arg0, struct_800628A4* arg1);
#ifdef NON_MATCHING
// need import bss
void func_800628A4_Type0(s32 arg0, struct_800628A4* arg1) {
    static Vec3f D_8015CF00;
    static Vec3f D_8015E648;

    s32 i;

    for (i = 0; i < arg1->unk18; i++) {
        if (arg0 == arg1->unk1C[i].unk3C) {
            D_8015E648.x = arg1->unk1C[i].unk28.x;
            D_8015E648.y = arg1->unk1C[i].unk28.y;
            D_8015E648.z = arg1->unk1C[i].unk28.z;
            Matrix_MultVec3f(&D_8015E648, &D_8015CF00);
            arg1->unk1C[i].unk30.x = D_8015CF00.x;
            arg1->unk1C[i].unk30.y = D_8015CF00.y;
            arg1->unk1C[i].unk30.z = D_8015CF00.z;
            arg1->unk1C[i].unk36 = (arg1->unk1C[i].unk2E * arg1->unk1C[i].unk38);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800628A4_Type0.s")
#endif

#ifdef NON_MATCHING
void func_80062A28(GlobalContext* arg0, Vec3f* arg1) {
    static struct_8015D8A0 D_8015CF10;
    s32 sp24;

    D_8015CF10.unk0.x = (s16)(s32)arg1->x;
    D_8015CF10.unk0.y = (s16)(s32)arg1->y;
    D_8015CF10.unk0.z = (s16)(s32)arg1->z;
    D_8015CF10.unk494 = 5;
    D_8015CF10.unk498 = 5;
    D_8015CF10.unk49C = 0x80;
    D_8015CF10.unk49D = 0;
    D_8015CF10.unk49E = 0x40;
    D_8015CF10.unk49F = -1;
    D_8015CF10.unk4A0 = 0x80;
    D_8015CF10.unk4A1 = 0;
    D_8015CF10.unk4A2 = 0x40;
    D_8015CF10.unk4A3 = -1;
    D_8015CF10.unk4A4 = -1;
    D_8015CF10.unk4A5 = 0x80;
    D_8015CF10.unk4A6 = 0;
    D_8015CF10.unk4A7 = -1;
    D_8015CF10.unk4A8 = -1;
    D_8015CF10.unk4A9 = 0x80;
    D_8015CF10.unk4AA = 0;
    D_8015CF10.unk4AB = -1;
    D_8015CF10.unk4AC = 0x40;
    D_8015CF10.unk4AD = 0;
    D_8015CF10.unk4AE = 0x20;
    D_8015CF10.unk4AF = 0;
    D_8015CF10.unk4B0 = 0x40;
    D_8015CF10.unk4B1 = 0;
    D_8015CF10.unk4B2 = 0x20;
    D_8015CF10.unk4B3 = 0;
    D_8015CF10.unk4B4 = 0x80;
    D_8015CF10.unk4B5 = 0;
    D_8015CF10.unk4B6 = 0x40;
    D_8015CF10.unk4B7 = 0;
    D_8015CF10.unk4B8 = 0x80;
    D_8015CF10.unk4B9 = 0;
    D_8015CF10.unk4BA = 0x40;
    D_8015CF10.unk4BB = 0;
    D_8015CF10.unk4BC = 0;
    D_8015CF10.unk4C0 = 0x10;
    D_8015CF10.unk48C = 8.0f;
    D_8015CF10.unk490 = -1.0f;
    Effect_Add(arg0, &sp24, 0, 0U, 1U, &D_8015CF10);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062A28.s")
#endif

#ifdef NON_MATCHING
void func_80062B80(GlobalContext* arg0, Vec3f* arg1) {
    static struct_8015D8A0 D_8015D3D8;
    s32 sp24;

    D_8015D3D8.unk0.x = (s16)(s32)arg1->x;
    D_8015D3D8.unk0.y = (s16)(s32)arg1->y;
    D_8015D3D8.unk0.z = (s16)(s32)arg1->z;
    D_8015D3D8.unk494 = 5;
    D_8015D3D8.unk498 = 5;
    D_8015D3D8.unk49C = -1;
    D_8015D3D8.unk49D = -1;
    D_8015D3D8.unk49E = -1;
    D_8015D3D8.unk49F = -1;
    D_8015D3D8.unk4A0 = 0x64;
    D_8015D3D8.unk4A1 = 0x64;
    D_8015D3D8.unk4A2 = 0x64;
    D_8015D3D8.unk4A3 = 0x64;
    D_8015D3D8.unk4A4 = 0x64;
    D_8015D3D8.unk4A5 = 0x64;
    D_8015D3D8.unk4A6 = 0x64;
    D_8015D3D8.unk4A7 = 0x64;
    D_8015D3D8.unk4A8 = 0x64;
    D_8015D3D8.unk4A9 = 0x64;
    D_8015D3D8.unk4AA = 0x64;
    D_8015D3D8.unk4AB = 0x64;
    D_8015D3D8.unk4AC = 0x32;
    D_8015D3D8.unk4AD = 0x32;
    D_8015D3D8.unk4AE = 0x32;
    D_8015D3D8.unk4AF = 0x32;
    D_8015D3D8.unk4B0 = 0x32;
    D_8015D3D8.unk4B1 = 0x32;
    D_8015D3D8.unk4B2 = 0x32;
    D_8015D3D8.unk4B3 = 0x32;
    D_8015D3D8.unk4B4 = 0x32;
    D_8015D3D8.unk4B5 = 0x32;
    D_8015D3D8.unk4B6 = 0x32;
    D_8015D3D8.unk4B7 = 0x32;
    D_8015D3D8.unk4B8 = 0;
    D_8015D3D8.unk4B9 = 0;
    D_8015D3D8.unk4BA = 0;
    D_8015D3D8.unk4BB = 0;
    D_8015D3D8.unk4BC = 0;
    D_8015D3D8.unk4C0 = 0x10;
    D_8015D3D8.unk48C = 8.0f;
    D_8015D3D8.unk490 = -1.0f;
    Effect_Add(arg0, &sp24, 0, 0U, 1U, &D_8015D3D8);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062B80.s")
#endif

typedef struct struct_8011E068 {
    /* 0x00 */ char unk_0[2];
    /* 0x02 */ Vec3s unk2;
    /* 0x08 */ char unk_4[0x26];
    /* 0x2E */ Vec3s unk2E;
} struct_8011E068;

#ifdef NON_MATCHING
void func_80062CD4(GlobalContext* arg0, Vec3f* arg1) {
    static struct_8011E068 D_8011E028 = { 0 /* TODO import data */ };
    s32 sp24;

    D_8011E028.unk2.x = (s16)(s32)arg1->x;
    D_8011E028.unk2.y = (s16)(s32)arg1->y;
    D_8011E028.unk2.z = (s16)(s32)arg1->z;
    D_8011E028.unk2E.x = D_8011E028.unk2.x;
    D_8011E028.unk2E.y = D_8011E028.unk2.y;
    D_8011E028.unk2E.z = D_8011E028.unk2.z;
    Effect_Add(arg0, &sp24, 3, 0U, 1U, &D_8011E028);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062CD4.s")
#endif

void func_80062D60(GlobalContext* arg0, Vec3f* arg1) {
    func_80062CD4(arg0, arg1);
    Audio_PlaySoundGeneral(0x1808U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
}

void func_80062DAC(GlobalContext* arg0, Vec3f* arg1, Vec3f* arg2) {
    func_80062CD4(arg0, arg1);
    Audio_PlaySoundGeneral(0x1808U, arg2, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
}

void func_80062DF4(GlobalContext* globalCtx, Vec3f* arg1) {
    func_80062D60(globalCtx, arg1);
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/swbpd
void func_80062E14(GlobalContext* arg0, Vec3f* arg1, Vec3f* arg2) {
    static struct_8011E068 D_8011E068 = { 0 /* TODO import .data */ };
    s32 sp24;

    D_8011E068.unk2.x = arg1->x;
    D_8011E068.unk2.y = arg1->y;
    D_8011E068.unk2.z = arg1->z;
    D_8011E068.unk2E.x = D_8011E068.unk2.x;
    D_8011E068.unk2E.y = D_8011E068.unk2.y;
    D_8011E068.unk2E.z = D_8011E068.unk2.z;
    Effect_Add(arg0, &sp24, 3, 0U, 1U, &D_8011E068);
    Audio_PlaySoundGeneral(0x1837U, arg2, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062E14.s")
#endif

#ifdef NON_MATCHING
// https://decomp.me/scratch/OTLXt
s32 func_80062ECC(f32 arg0, f32 arg1, f32 arg2, Vec3f* arg3, Vec3f* arg4, Vec3f* arg5, Vec3f* arg6_out,
                  Vec3f* arg7_out) {
    Vec3f sp6C;
    Vec3f* new_var;
    Vec3f sp60;
    Vec3f sp54;
    f32 sp4C;
    f32 temp_fa0;
    float new_var2;
    f32 temp_fa1_2;
    f32 temp_fv0_2;
    f32 temp_fv1;
    f32 var_ft4_real;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_v0_2;
    s32 var_v1_2;

    new_var = arg6_out;
    sp6C.x = arg4->x - arg3->x;
    sp6C.y = (arg4->y - arg3->y) - arg2;
    sp6C.z = arg4->z - arg3->z;
    sp60.x = arg5->x - arg3->x;
    sp60.y = (arg5->y - arg3->y) - arg2;
    sp60.z = arg5->z - arg3->z;
    sp54.x = sp60.x - sp6C.x;
    sp54.y = sp60.y - sp6C.y;
    sp54.z = sp60.z - sp6C.z;
    if (((sp6C.y > 0.0f) && (sp6C.y < arg1)) && (sqrtf((sp6C.x * sp6C.x) + (sp6C.z * sp6C.z)) < arg0)) {
        return 3;
    }
    if (((sp60.y > 0.0f) && (sp60.y < arg1)) && (sqrtf((sp60.x * sp60.x) + (sp60.z * sp60.z)) < arg0)) {
        return 3;
    }
    new_var2 = 0.0f;
    temp_fa0 = ((sp6C.x * sp6C.x) + (sp6C.z * sp6C.z)) - (arg0 * arg0);
    temp_fv1 = (sp54.x * sp54.x) + (sp54.z * sp54.z);
    if (!(fabsf(temp_fv1) < 0.008f)) {
        temp_fa1_2 = ((2.0f * sp54.x) * sp6C.x) + ((2.0f * sp54.z) * sp6C.z);
        if ((temp_fa1_2 * temp_fa1_2) < ((4.0f * temp_fv1) * temp_fa0)) {
            return 0;
        }
        if (((temp_fa1_2 * temp_fa1_2) - ((4.0f * temp_fv1) * temp_fa0)) > new_var2) {
            var_v1_2 = (var_v0_2 = 1);
        } else {
            var_v1_2 = 1;
            var_v0_2 = 0;
        }
        do {
            temp_fv0_2 = sqrtf((temp_fa1_2 * temp_fa1_2) - ((4.0f * temp_fv1) * temp_fa0));
        } while (0);
        var_ft4_real = (temp_fv0_2 - temp_fa1_2) / (2.0f * temp_fv1);
        if (var_v0_2 == 1) {
            sp4C = ((-temp_fa1_2) - temp_fv0_2) / (2.0f * temp_fv1);
        }
    } else if (!(fabsf(((2.0f * sp54.x) * sp6C.x) + ((2.0f * sp54.z) * sp6C.z)) < 0.008f)) {
        var_v1_2 = 1;
        var_v0_2 = 0;
        var_ft4_real = (-temp_fa0) / (((2.0f * sp54.x) * sp6C.x) + ((2.0f * sp54.z) * sp6C.z));
    } else {
        if (temp_fa0 <= new_var2) {
            var_a0 = (sp6C.y > new_var2) && (sp6C.y < arg1);
            var_a0_2 = (sp60.y > new_var2) && (sp60.y < arg1);
            if ((var_a0 != 0) && (var_a0_2 != 0)) {
                *new_var = sp6C;
                *arg7_out = sp60;
                return 2;
            }
            if (var_a0 != 0) {
                *new_var = sp6C;
                return 1;
            }
            if (var_a0_2 != 0) {
                *new_var = sp60;
                return 1;
            }
        }
        return 0;
    }
    {
        if (var_v0_2 == 0) {
            if ((var_ft4_real < new_var2) || (var_ft4_real > 1.0f)) {
                return 0;
            }
        } else {
            var_a0 = (var_ft4_real < new_var2) || (var_ft4_real > 1.0f);
            var_a0_2 = (sp4C < 0.0f) || (sp4C > 1.0f);
            if ((var_a0 != 0) && (var_a0_2 != 0)) {
                return 0;
            }
            if (var_a0 != 0) {
                var_v1_2 = 0;
            }
            if (0 != var_a0_2) {
                var_v0_2 = 0;
            }
        }
        if (var_v1_2 == 1) {
            if ((((var_ft4_real * sp54.y) + sp6C.y) < 0.0f) || (arg1 < ((var_ft4_real * sp54.y) + sp6C.y))) {
                var_v1_2 = 0;
            }
        }
        if (var_v0_2 == 1) {
            if ((((sp4C * sp54.y) + sp6C.y) < 0.0f) || (arg1 < ((sp4C * sp54.y) + sp6C.y))) {
                var_v0_2 = 0;
            }
        }
        if ((var_v1_2 == 0) && (var_v0_2 == 0)) {
            return 0;
        }
        if ((var_v1_2 == 1) && (var_v0_2 == 1)) {
            new_var->x = ((var_ft4_real * sp54.x) + sp6C.x) + arg3->x;
            new_var->y = ((var_ft4_real * sp54.y) + sp6C.y) + arg3->y;
            new_var->z = ((var_ft4_real * sp54.z) + sp6C.z) + arg3->z;
            arg7_out->x = ((sp4C * sp54.x) + sp6C.x) + arg3->x;
            arg7_out->y = ((sp4C * sp54.y) + sp6C.y) + arg3->y;
            arg7_out->z = ((sp4C * sp54.z) + sp6C.z) + arg3->z;
            return 2;
        }
        if (var_v1_2 == 1) {
            new_var->x = ((var_ft4_real * sp54.x) + sp6C.x) + arg3->x;
            new_var->y = ((var_ft4_real * sp54.y) + sp6C.y) + arg3->y;
            new_var->z = ((var_ft4_real * sp54.z) + sp6C.z) + arg3->z;
            return 1;
        }
        if (var_v0_2 == 1) {
            new_var->x = ((sp4C * sp54.x) + sp6C.x) + arg3->x;
            new_var->y = ((sp4C * sp54.y) + sp6C.y) + arg3->y;
            new_var->z = ((sp4C * sp54.z) + sp6C.z) + arg3->z;
            return 1;
        }
        return 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062ECC.s")
#endif

s16 func_800635D0(s32 arg0) {
    s16 var_v1;

    var_v1 = 0;
    if (arg0 & 0x400100) {
        var_v1 = 1;
    } else if (arg0 & 0x03000242) {
        var_v1 = 2;
    } else if (arg0 & 0x48800400) {
        var_v1 = 4;
    } else if (arg0 & 0x04000000) {
        var_v1 = 8;
    }
    gGameInfo->data[0x4E7] = var_v1;
    return var_v1;
}
