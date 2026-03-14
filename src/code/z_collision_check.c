#include <ultra64.h>
#include <global.h>

void func_8005B280(GraphicsContext* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {
    func_8005B2AC(arg0, arg1, arg2, arg3, 255, 0, 0);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005B2AC.s")

Collider D_8011DE00 = {
    NULL, NULL, NULL, NULL, 0, 0, 0, 0, 3, 4,
};

// multi-type
s32 func_8005B65C_InitColliderDefault(GlobalContext* globalCtx, Collider* arg1) {
    *arg1 = D_8011DE00;
    return 1;
}

// multi-type
s32 func_8005B6A0(GlobalContext* globalCtx, Collider* collision) {
    return 1;
}

// multi-type
s32 func_8005B6B0(GlobalContext* globalCtx, Collider* arg1, ColliderSrc_8005B6B0* arg2) {
    arg1->actor = arg2->unk0;
    arg1->colliderFlags = arg2->unk4;
    arg1->collideFlags = arg2->unk5;
    arg1->maskA = arg2->unk6;
    arg1->maskB = 0x10;
    arg1->type = arg2->unk7;
    return 1;
}

// multi-type
s32 func_8005B6EC(GlobalContext* globalCtx, Collider* collision, Actor* actor, ColliderSrc_8005B6EC* src) {
    collision->actor = actor;
    collision->unk_14 = src->unk0;
    collision->colliderFlags = src->unk1;
    collision->collideFlags = src->unk2;
    collision->maskA = src->unk3;
    collision->maskB = 0x10;
    collision->type = src->unk4;
    return 1;
}

// multi-type
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

// multi-type
void func_8005B76C(GlobalContext* globalCtx, Collider* collision) {
    collision->at = NULL;
    collision->colliderFlags &= ~0x6;
}

// multi-type
void func_8005B784(GlobalContext* globalCtx, Collider* collision) {
    collision->ac = NULL;
    collision->collideFlags &= ~0x82;
}

// multi-type
void func_8005B79C(GlobalContext* globalCtx, Collider* collision) {
    collision->ot = NULL;
    collision->maskA &= ~0x2;
    collision->maskB &= ~0x1;
}

ColliderTouch D_8011DE18 = { 0, 0, 0 };

// multi-type
s32 func_8005B7C0(GlobalContext* globalCtx, ColliderTouch* arg1) {
    *arg1 = D_8011DE18;
    return 1;
}

// multi-type
s32 func_8005B7E4(GlobalContext* globalCtx, ColliderTouch* touch) {
    return 1;
}

// multi-type
s32 func_8005B7F4(GlobalContext* globalCtx, ColliderTouch* arg1, ColliderTouchSrc* arg2) {
    arg1->flags = arg2->toucherMask;
    arg1->unk_04 = arg2->bumperEffect;
    arg1->damage = arg2->toucherDamage;
    return 1;
}

// multi-type
void func_8005B818(GlobalContext* globalCtx, UNK_PTR body) {
}

ColliderBump D_8011DE20 = { 0xFFCFFFFF, 0, 0, { 0, 0, 0 } };

// multi-type
s32 func_8005B824(GlobalContext* globalCtx, ColliderBump* arg1) {
    *arg1 = D_8011DE20;
    return 1;
}

// multi-type
s32 func_8005B850(GlobalContext* globalCtx, UNK_PTR bump) {
    return 1;
}

// multi-type
s32 func_8005B860(GlobalContext* globalCtx, ColliderBump* arg1, ColliderBumpSrc* arg2) {
    arg1->flags = arg2->bumperMask;
    arg1->effect = arg2->unk4;
    arg1->unk_05 = arg2->unk5;
    return 1;
}

ColliderBody D_8011DE2C = {
    { 0, 0, 0 }, { 0xFFCFFFFF, 0, 0, { 0, 0, 0 } }, 0, 0, 0, 0, NULL, NULL, NULL, NULL,
};

// multi-type
s32 func_8005B884(GlobalContext* globalCtx, ColliderBody* arg1) {
    *arg1 = D_8011DE2C;
    func_8005B7C0(globalCtx, &arg1->toucher);
    func_8005B824(globalCtx, &arg1->bumper);
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

struct_8011DE54 D_8011DE54 = { { { 0, 0, 0 }, 0 }, { { 0, 0, 0 }, 0 }, 0.0f, 0 };

s32 func_8005BA30_Type0(GlobalContext* globalCtx, struct_8011DE54* arg1) {
    *arg1 = D_8011DE54;
    return 1;
}

s32 func_8005BA74(GlobalContext* globalCtx, struct_8011DE54* arg1) {
    return 1;
}

s32 func_8005BA84_Type0(GlobalContext* globalCtx, struct_8011DE54* arg1, ColliderSrc_Type0_ptrC_sub18* arg2) {
    arg1->unk14 = arg2->unk0;
    arg1->unk0 = arg2->unk2;
    arg1->unk10 = arg2->unkA * 0.01f;
    return 1;
}

s32 func_8005BAD8_Type0(GlobalContext* globalCtx, Collider_Type0_ptr1C* arg1) {
    func_8005B884(globalCtx, &arg1->unk0);
    func_8005BA30_Type0(globalCtx, &arg1->unk28);
    return 1;
}

s32 func_8005BB10_Type0(GlobalContext* globalCtx, Collider_Type0_ptr1C* arg1) {
    func_8005B904(globalCtx, &arg1->unk0);
    func_8005BA74(globalCtx, &arg1->unk28);
    return 1;
}

s32 func_8005BB48_Type0(GlobalContext* globalCtx, Collider_Type0_ptr1C* arg1, ColliderSrc_Type0_ptrC* arg2) {
    func_8005B93C(globalCtx, &arg1->unk0, &arg2->unk0);
    func_8005BA84_Type0(globalCtx, &arg1->unk28, &arg2->unk18);
    return 1;
}

s32 func_8005BB8C_SetAT_sub_0(GlobalContext* globalCtx, Collider_Type0_ptr1C* arg1) {
    func_8005B9B0(globalCtx, &arg1->unk0);
    return 1;
}

s32 func_8005BBB0_SetAC_sub_0(GlobalContext* globalCtx, Collider_Type0_ptr1C* arg1) {
    func_8005B9E8(globalCtx, &arg1->unk0);
    return 1;
}

s32 func_8005BBD4_SetOT_sub_0(GlobalContext* globalCtx, Collider_Type0_ptr1C* arg1) {
    func_8005BA1C(globalCtx, &arg1->unk0);
    return 1;
}

s32 func_8005BBF8_Type0(GlobalContext* globalCtx, Collider_Type0* arg1) {
    func_8005B65C_InitColliderDefault(globalCtx, &arg1->unk0);
    arg1->unk18 = 0;
    arg1->unk1C = 0;
    return 1;
}

// only used by EnNwc
s32 func_8005BC28(GlobalContext* globalCtx, Collider_Type0* arg1) {
    Collider_Type0_ptr1C* var_s0;

    func_8005B6A0(globalCtx, &arg1->unk0);
    var_s0 = arg1->unk1C;
    while (var_s0 < (arg1->unk1C + arg1->unk18)) {
        func_8005BB10_Type0(globalCtx, var_s0);
        var_s0++;
    }
    arg1->unk18 = 0;
    if (arg1->unk1C != NULL) {
        ZeldaArena_FreeDebug((void*)arg1->unk1C, "../z_collision_check.c", 0x571);
    }
    arg1->unk1C = NULL;
    return 1;
}

s32 func_8005BCC8_Type0(GlobalContext* globalCtx, Collider_Type0* arg1) {
    Collider_Type0_ptr1C* var_s0;

    func_8005B6A0(globalCtx, &arg1->unk0);
    var_s0 = arg1->unk1C;
    while (var_s0 < (arg1->unk1C + arg1->unk18)) {
        func_8005BB10_Type0(globalCtx, var_s0);
        var_s0++;
    }
    arg1->unk18 = 0;
    arg1->unk1C = NULL;
    return 1;
}

// unused
s32 func_8005BD50_jntsph(GlobalContext* globalCtx, Collider_Type0* arg1, ColliderSrc_Type0_8005B6B0* arg2) {
    Collider_Type0_ptr1C* var_s0;
    ColliderSrc_Type0_ptrC* var_s1;

    func_8005B6B0(globalCtx, &arg1->unk0, &arg2->unk0);
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
        func_8005BAD8_Type0(globalCtx, var_s0);
        func_8005BB48_Type0(globalCtx, var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

// only used by EnNwc
s32 func_8005BE50_jntsph(GlobalContext* globalCtx, Collider_Type0* arg1, Actor* arg2,
                         ColliderSrc_Type0_8005B6EC* arg3) {
    Collider_Type0_ptr1C* var_s0;
    ColliderSrc_Type0_ptrC* var_s1;

    func_8005B6EC(globalCtx, &arg1->unk0, arg2, &arg3->unk0);
    arg1->unk18 = arg3->unk8;
    arg1->unk1C = ZeldaArena_MallocDebug(arg3->unk8 * 0x40, "../z_collision_check.c", 0x5D2);
    if (arg1->unk1C == 0) {
        arg1->unk18 = 0;
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjJntSph_set3():zelda_malloc_出来ません。\n");
        osSyncPrintf("\x1b[m");
        return 0;
    }
    var_s0 = arg1->unk1C;
    var_s1 = arg3->unkC;
    while (var_s0 < (arg1->unk1C + arg1->unk18)) {
        func_8005BAD8_Type0(globalCtx, var_s0);
        func_8005BB48_Type0(globalCtx, var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

// unused
s32 func_8005BF50_jntsph(GlobalContext* globalCtx, Collider_Type0* arg1, Actor* arg2, ColliderSrc_Type0* arg3) {
    s32 temp_v0;
    Collider_Type0_ptr1C* var_s0;
    ColliderSrc_Type0_ptrC* var_s1;

    func_8005B72C_InitColliderFromSrc(globalCtx, &arg1->unk0, arg2, &arg3->unk0);
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
        func_8005BAD8_Type0(globalCtx, var_s0);
        func_8005BB48_Type0(globalCtx, var_s0, var_s1);
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
        __assert("pclobj_jntsph->elem_tbl != NULL", "../z_collision_check.c", 0x643);
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

s32 func_8005C124_SetAT_0(GlobalContext* globalCtx, Collider* arg1) {
    Collider_Type0* new_var;
    Collider_Type0_ptr1C* var_s0;

    new_var = (Collider_Type0*)arg1;
    func_8005B76C(globalCtx, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005BB8C_SetAT_sub_0(globalCtx, var_s0);
        var_s0++;
    }

    return 1;
}

s32 func_8005C1AC_SetAC_0(GlobalContext* globalCtx, Collider* arg1) {
    Collider_Type0* new_var;
    Collider_Type0_ptr1C* var_s0;

    new_var = (Collider_Type0*)arg1;
    func_8005B784(globalCtx, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005BBB0_SetAC_sub_0(globalCtx, var_s0);
        var_s0++;
    }
    return 1;
}

s32 func_8005C234_SetOT_0(GlobalContext* globalCtx, Collider* arg1) {
    Collider_Type0* new_var;
    Collider_Type0_ptr1C* var_s0;

    new_var = (Collider_Type0*)arg1;
    func_8005B79C(globalCtx, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005BBD4_SetOT_sub_0(globalCtx, var_s0);
        var_s0++;
    }
    return 1;
}

Cylinder16 D_8011DE6C = { 0, 0, 0, { 0, 0, 0 } };

s32 func_8005C2BC(GlobalContext* globalCtx, Cylinder16* arg1) {
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

// only used by ObjDekujr
s32 func_8005C3F4(GlobalContext* globalCtx, Collider_Type1* collision, ColliderSrc_Type1_8005B6B0* src) {
    func_8005B6B0(globalCtx, &collision->unk0, &src->unk0);
    func_8005B93C(globalCtx, &collision->unk18, &src->unk8);
    func_8005C328_Type1(globalCtx, &collision->unk40, &src->unk20);
    return 1;
}

s32 func_8005C450_Type1(GlobalContext* globalCtx, Collider_Type1* collision, Actor* actor,
                        ColliderSrc_Type1_8005B6EC* src) {
    func_8005B6EC(globalCtx, &collision->unk0, actor, &src->unk0);
    func_8005B93C(globalCtx, &collision->unk18, &src->unk8);
    func_8005C328_Type1(globalCtx, &collision->unk40, &src->unk20);
    return 1;
}

s32 ActorCollider_InitThing_Type1(GlobalContext* globalCtx, Collider_Type1* collision, Actor* actor,
                                  ColliderSrc_Type1* src) {
    func_8005B72C_InitColliderFromSrc(globalCtx, &collision->unk0, actor, &src->unk0);
    func_8005B93C(globalCtx, &collision->unk18, &src->unk8);
    func_8005C328_Type1(globalCtx, &collision->unk40, &src->unk20);
    return 1;
}

s32 func_8005C508_SetAT_1(GlobalContext* globalCtx, Collider* collision_) {
    Collider_Type1* collision = (Collider_Type1*)collision_;

    func_8005B76C(globalCtx, &collision->unk0);
    func_8005B9B0(globalCtx, &collision->unk18);
    return 1;
}

s32 func_8005C540_SetAC_1(GlobalContext* globalCtx, Collider* collision_) {
    Collider_Type1* collision = (Collider_Type1*)collision_;

    func_8005B784(globalCtx, &collision->unk0);
    func_8005B9E8(globalCtx, &collision->unk18);
    return 1;
}

s32 func_8005C578_SetOT_1(GlobalContext* globalCtx, Collider* collision_) {
    Collider_Type1* collision = (Collider_Type1*)collision_;

    func_8005B79C(globalCtx, &collision->unk0);
    func_8005BA1C(globalCtx, &collision->unk18);
    return 1;
}

TriNorm D_8011DE78 = {
    { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { { 0.0f, 0.0f, 0.0f }, 0.0f },
};

s32 func_8005C5B0(GlobalContext* globalCtx, TriNorm* arg1) {
    *arg1 = D_8011DE78;
    return 1;
}

s32 func_8005C5F8(GlobalContext* globalCtx, UNK_PTR arg1) {
    return 1;
}

typedef struct struct_8005C608_arg1 {
    /* 0x00 */ Vec3f unk0[3];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
} struct_8005C608_arg1;

s32 func_8005C608(GlobalContext* globalCtx, TriNorm* arg1, Vec3f* arg2) {
    Vec3f* var_v1;
    Vec3f* var_v0;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    var_v0 = &arg1->vtx[0];
    var_v1 = arg2;
    while (var_v0 < arg1->vtx + 3) {
        *var_v0 = *var_v1;
        var_v0++;
        var_v1++;
    }

    func_800CC8B4(arg2, arg2 + 1, arg2 + 2, &sp44, &sp40, &sp3C, &sp38);
    arg1->plane.normal.x = sp44;
    arg1->plane.normal.y = sp40;
    arg1->plane.normal.z = sp3C;
    arg1->plane.originDist = sp38;
    return 1;
}

s32 func_8005C6C0_tris(GlobalContext* globalCtx, Collider_Type2_ptr1C* arg1) {
    func_8005B884(globalCtx, &arg1->unk0);
    func_8005C5B0(globalCtx, &arg1->unk28);
    return 1;
}

typedef struct struct_8005C6F8 {
    ColliderBody unk0;
    char unk_28[0x5C - 0x28];
} struct_8005C6F8; /* size = 0x5C */

s32 func_8005C6F8(GlobalContext* globalCtx, struct_8005C6F8* arg1) {
    func_8005B904(globalCtx, &arg1->unk0);
    func_8005C5F8(globalCtx, arg1->unk_28);
    return 1;
}

s32 func_8005C730(GlobalContext* globalCtx, Collider_Type2_ptr1C* arg1, ColliderSrc_Type2_ptrC* arg2) {
    func_8005B93C(globalCtx, &arg1->unk0, &arg2->unk0);
    func_8005C608(globalCtx, &arg1->unk28, &arg2->unk18);
    return 1;
}

s32 func_8005C774(GlobalContext* globalCtx, ColliderBody* arg1) {
    func_8005B9B0(globalCtx, arg1);
    return 1;
}

s32 func_8005C798_SetAC_sub_2(GlobalContext* globalCtx, ColliderBody* arg1) {
    func_8005B9E8(globalCtx, arg1);
    return 1;
}

s32 func_8005C7BC_Type2(GlobalContext* globalCtx, Collider_Type2_ptr1C* arg1) {
    func_8005BA1C(globalCtx, &arg1->unk0);
    return 1;
}

typedef struct struct_8005C7E0 {
    Collider unk0;
    s32 unk18;
    s32 unk1C;
} struct_8005C7E0;

// uses not decompiled
s32 func_8005C7E0(GlobalContext* globalCtx, struct_8005C7E0* arg1) {
    func_8005B65C_InitColliderDefault(globalCtx, &arg1->unk0);
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
s32 func_8005C810(GlobalContext* globalCtx, struct_8005C810* arg1) {
    struct_8005C6F8* var_s0;

    func_8005B6A0(globalCtx, &arg1->unk0);
    var_s0 = arg1->unk1C;
    while (var_s0 < (arg1->unk1C + arg1->unk18)) {
        func_8005C6F8(globalCtx, var_s0);
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
s32 func_8005C8C8(GlobalContext* globalCtx, struct_8005C8C8* arg1) {
    struct_8005C6F8* var_s0;

    func_8005B6A0(globalCtx, &arg1->unk0);
    var_s0 = arg1->unk1C;
    if ((u32)var_s0 < (u32)&var_s0[arg1->unk18]) {
        do {
            func_8005C6F8(globalCtx, var_s0);
            var_s0++;
        } while ((u32)var_s0 < (u32)&arg1->unk1C[arg1->unk18]);
    }
    arg1->unk18 = 0;
    arg1->unk1C = NULL;
    return 1;
}

// unused
s32 func_8005C964_tris(GlobalContext* globalCtx, Collider_Type2* arg1, Actor* arg2, ColliderSrc_Type2_8005B6EC* arg3) {
    Collider_Type2_ptr1C* var_s0;
    ColliderSrc_Type2_ptrC* var_s1;

    func_8005B6EC(globalCtx, &arg1->unk0, arg2, &arg3->unk0);
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
        func_8005C6C0_tris(globalCtx, var_s0);
        func_8005C730(globalCtx, var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

// unused
s32 func_8005CA88_tris(GlobalContext* globalCtx, Collider_Type2* arg1, Actor* arg2, ColliderSrc_Type2* arg3) {
    Collider_Type2_ptr1C* temp_v0;
    Collider_Type2_ptr1C* var_s0;
    ColliderSrc_Type2_ptrC* var_s1;

    func_8005B72C_InitColliderFromSrc(globalCtx, &arg1->unk0, arg2, &arg3->unk0);
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
    while (var_s0 < &arg1->unk1C[arg1->unk18]) {
        func_8005C6C0_tris(globalCtx, var_s0);
        func_8005C730(globalCtx, var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

// uses not decompiled
s32 func_8005CBAC_tris(GlobalContext* globalCtx, Collider_Type2* arg1, Actor* arg2, ColliderSrc_Type2* arg3,
                       Collider_Type2_ptr1C* arg4) {
    Collider_Type2_ptr1C* var_s0;
    ColliderSrc_Type2_ptrC* var_s1;

    func_8005B72C_InitColliderFromSrc(globalCtx, &arg1->unk0, arg2, &arg3->unk0);
    arg1->unk18 = arg3->unk8;
    arg1->unk1C = arg4;
    if (arg1->unk1C == 0) {
        __assert("pclobj_tris->elem_tbl != NULL", "../z_collision_check.c", 0x8D2);
    }
    var_s0 = arg1->unk1C;
    var_s1 = arg3->unkC;
    while (var_s0 < &arg1->unk1C[arg1->unk18]) {
        func_8005C6C0_tris(globalCtx, var_s0);
        func_8005C730(globalCtx, var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

s32 func_8005CC98_SetAT_2(GlobalContext* globalCtx, Collider* arg1) {
    Collider_Type2_ptr1C* var_s0;
    Collider_Type2* new_var;

    new_var = (Collider_Type2*)arg1;
    func_8005B76C(globalCtx, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005C774(globalCtx, &var_s0->unk0);
        var_s0++;
    }
    return 1;
}

s32 func_8005CD34_SetAC_2(GlobalContext* globalCtx, Collider* arg1) {
    Collider_Type2_ptr1C* var_s0;
    Collider_Type2* new_var;

    new_var = (Collider_Type2*)arg1;
    func_8005B784(globalCtx, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005C798_SetAC_sub_2(globalCtx, &var_s0->unk0);
        var_s0++;
    }
    return 1;
}

s32 func_8005CDD0_SetOT_2(GlobalContext* globalCtx, Collider* arg1) {
    Collider_Type2* new_var;
    Collider_Type2_ptr1C* var_s0;

    new_var = (Collider_Type2*)arg1;
    func_8005B79C(globalCtx, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005C7BC_Type2(globalCtx, var_s0);
        var_s0++;
    }
    return 1;
}

struct_Collider_Type3_subc D_8011DEAC = {
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0, 0, 0 },
    { 0, 0, 0 },
    1e38f,
};

s32 func_8005CE6C(GlobalContext* globalCtx, struct_Collider_Type3_subc* arg1) {
    *arg1 = D_8011DEAC;
    return 1;
}

s32 func_8005CEB4_Type3(GlobalContext* globalCtx, struct_Collider_Type3_subc* dim) {
    return 1;
}

s32 func_8005CEC4(GlobalContext* globalCtx, struct_Collider_Type3_subc* arg1) {
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

s32 func_8005CF90_Type3(GlobalContext* globalCtx, struct_Collider_Type3_subc* arg1, Vec3f* arg2) {
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
    /* 0x00 */ ColliderSrc_8005B6EC unk0;
    /* 0x08 */ ColliderBodySrc unk8;
    /* 0x20 */ Vec3f unk20[4];
} struct_8005D0A8_arg3;

// unused
s32 func_8005D0A8(GlobalContext* globalCtx, struct_8005D0A8_arg1* collision, Actor* actor, struct_8005D0A8_arg3* src) {
    func_8005B6EC(globalCtx, &collision->unk0, actor, &src->unk0);
    func_8005B93C(globalCtx, &collision->unk18, &src->unk8);
    func_8005CF90_Type3(globalCtx, &collision->unk40, src->unk20);
    return 1;
}

s32 func_8005D104_Type3(GlobalContext* globalCtx, Collider_Type3* collision, Actor* actor, ColliderSrc_Type3* src) {
    func_8005B72C_InitColliderFromSrc(globalCtx, &collision->unk0, actor, &src->unk0);
    func_8005B93C(globalCtx, &collision->unk18, &src->unk8);
    func_8005CF90_Type3(globalCtx, &collision->unk40, src->unk20);
    return 1;
}

s32 func_8005D160_SetAT_3(GlobalContext* globalCtx, Collider* collision_) {
    Collider_Type3* collision = (Collider_Type3*)collision_;

    func_8005B76C(globalCtx, &collision->unk0);
    func_8005B9B0(globalCtx, &collision->unk18);
    func_8005CEC4(globalCtx, &collision->unk40);
    return 1;
}

s32 func_8005D1A8_SetAC_3(GlobalContext* globalCtx, Collider* collision_) {
    Collider_Type3* collision = (Collider_Type3*)collision_;

    func_8005B784(globalCtx, &collision->unk0);
    func_8005B9E8(globalCtx, &collision->unk18);
    return 1;
}

s32 func_8005D1E0_SetOT_3(GlobalContext* globalCtx, Collider* collision_) {
    Collider_Type3* collision = (Collider_Type3*)collision_;

    func_8005B79C(globalCtx, &collision->unk0);
    func_8005BA1C(globalCtx, &collision->unk18);
    return 1;
}

s32 func_8005D218(GlobalContext* globalCtx, Collider_Type3* arg1, Vec3f* arg2) {
    f32 temp_fv0;
    Vec3f sp20;

    if (!(arg1->unk18.toucherFlags & 4)) {
        return 1;
    }
    Math_Vec3s_ToVec3f(&sp20, &arg1->unk40.unk30);
    temp_fv0 = func_800CB650(&sp20, arg2);
    if (temp_fv0 < arg1->unk40.unk3C) {
        arg1->unk40.unk3C = temp_fv0;
        if (arg1->unk18.unk_18 != NULL) {
            func_8005B784(globalCtx, arg1->unk18.unk_18);
        }
        if (arg1->unk18.unk_20 != NULL) {
            func_8005B9E8(globalCtx, arg1->unk18.unk_20);
        }
        return 1;
    } else {
        return 0;
    }
}

Vec3f D_8011DEEC = { 0.0f, 0.0f, 0.0f };

// unused
s32 func_8005D2C4(s32 arg0, Vec3f* arg1) {
    Vec3f sp1C;

    sp1C = D_8011DEEC;
    Math_Vec3f_Copy(arg1, &sp1C);
    Math_Vec3f_Copy(arg1 + 1, &sp1C);
    return 1;
}

// unused
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

// unused
s32 func_8005D378(s32 arg0, struct_8005D378_arg1* arg1, struct_8005D378_arg2* arg2) {
    arg1->unk18 = (u16)arg2->unk18;
    func_8005D334(arg0, &arg1->unk0, &arg2->unk0, &arg2->unkC);
    return 1;
}

typedef struct struct_8005D3A4 {
    char unk_0[0x18];
    u16 unk18;
} struct_8005D3A4;

s32 func_8005D3A4(GlobalContext* globalCtx, struct_8005D3A4* arg1) {
    arg1->unk18 = (u16)(arg1->unk18 & 0xFFFE);
    return 1;
}

void func_8005D40C(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx);

void func_8005D3BC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx) {
    colChkCtx->unk2 = 0;
    func_8005D40C(globalCtx, colChkCtx);
    gGameInfo->data[0x735] = 1;
    gGameInfo->data[0x736] = 1;
    gGameInfo->data[0x737] = 1;
}

void func_8005D400(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx) {
}

void func_8005D40C(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx) {
    Collider** var_v0;

    if (!(colChkCtx->unk2 & 1)) {
        colChkCtx->unk0_nAT = 0;
        colChkCtx->unkCC_nAC = 0;
        colChkCtx->unk1C0_nOT = 0;
        colChkCtx->unk28C = 0;
        for (var_v0 = colChkCtx->unk4_AT; var_v0 < (colChkCtx->unk4_AT + ARRAY_COUNT(colChkCtx->unk4_AT)); var_v0++) {
            *var_v0 = NULL;
        }
        var_v0 = colChkCtx->unkD0_AC;
        while (var_v0 < (colChkCtx->unkD0_AC + ARRAY_COUNT(colChkCtx->unkD0_AC))) {
            *var_v0 = NULL;
            var_v0++;
        }
        var_v0 = colChkCtx->unk1C4_OT;
        while (var_v0 < (colChkCtx->unk1C4_OT + ARRAY_COUNT(colChkCtx->unk1C4_OT))) {
            *var_v0 = NULL;
            var_v0++;
        }
        var_v0 = colChkCtx->unk290;
        while ((u32)var_v0 < (u32)(colChkCtx->unk290 + ARRAY_COUNT(colChkCtx->unk290))) {
            *var_v0 = NULL;
            var_v0++;
        }
    }
}

typedef struct struct_8005D4B4 {
    char unk_0[2];
    u16 unk2;
} struct_8005D4B4;

// unused
void func_8005D4B4(s32 arg0, struct_8005D4B4* arg1) {
    arg1->unk2 |= 1;
}

typedef struct struct_8005D4C8 {
    char unk_0[2];
    u16 unk2;
} struct_8005D4C8;

// unused
void func_8005D4C8(s32 arg0, struct_8005D4C8* arg1) {
    arg1->unk2 &= ~1;
}

void func_8005D4DC(GlobalContext* globalCtx, Collider* arg1) {
    Collider_Type0* arg1_0;
    Collider_Type1* arg1_1;
    Collider_Type2* arg1_2;
    Collider_Type3* arg1_3;
    s32 var_s0;

    if (arg1 != NULL) {
        switch (arg1->type) {
            case 0:
                arg1_0 = (Collider_Type0*)arg1;

                for (var_s0 = 0; var_s0 < arg1_0->unk18; var_s0++) {
                    func_800D05D0(globalCtx, &arg1_0->unk1C[var_s0].unk28.unk8);
                }
                break;

            case 1:
                arg1_1 = (Collider_Type1*)arg1;
                func_800D05DC(globalCtx, &arg1_1->unk40);
                break;

            case 2:
                arg1_2 = (Collider_Type2*)arg1;
                for (var_s0 = 0; var_s0 < arg1_2->unk18; var_s0++) {
                    func_8005B280(globalCtx->state.gfxCtx, &arg1_2->unk1C[var_s0].unk28.vtx[0],
                                  &arg1_2->unk1C[var_s0].unk28.vtx[1], &arg1_2->unk1C[var_s0].unk28.vtx[2]);
                }
                break;

            case 3:
                arg1_3 = (Collider_Type3*)arg1;
                func_8005B280(globalCtx->state.gfxCtx, &arg1_3->unk40.unk18, &arg1_3->unk40.unk24, &arg1_3->unk40.unkC);
                func_8005B280(globalCtx->state.gfxCtx, &arg1_3->unk40.unkC, &arg1_3->unk40.unk0, &arg1_3->unk40.unk18);
                break;
        }
    }
}

void func_8005D62C(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx) {
    s32 var_s1;

    if (gGameInfo->data[0x72F] != 0) {
        if (gGameInfo->data[0x735] != 0) {
            var_s1 = 0;
            while (var_s1 < colChkCtx->unk0_nAT) {
                func_8005D4DC(globalCtx, colChkCtx->unk4_AT[var_s1]);
                var_s1 += 1;
            }
        }
        if (gGameInfo->data[0x736] != 0) {
            var_s1 = 0;
            while (var_s1 < colChkCtx->unkCC_nAC) {
                func_8005D4DC(globalCtx, colChkCtx->unkD0_AC[var_s1]);
                var_s1 += 1;
            }
        }
        if (gGameInfo->data[0x737] != 0) {
            var_s1 = 0;
            while (var_s1 < colChkCtx->unk1C0_nOT) {
                if (colChkCtx->unk1C4_OT[var_s1]->maskA & 1) {
                    func_8005D4DC(globalCtx, colChkCtx->unk1C4_OT[var_s1]);
                }
                var_s1 += 1;
            }
        }
        if (gGameInfo->data[0x738] != 0) {
            func_80042C3C(globalCtx, &globalCtx->colCtx);
        }
        if (gGameInfo->data[0x739] != 0) {
            func_80042FC4(globalCtx, &globalCtx->colCtx);
        }
    }
}

typedef s32 (*callback_8011DEF8)(GlobalContext*, Collider*);

s32 func_8005C234_SetAT_0(GlobalContext*, Collider*);
s32 func_8005C578_SetAT_1(GlobalContext*, Collider*);
s32 func_8005CDD0_SetAT_2(GlobalContext*, Collider*);
s32 func_8005D1E0_SetAT_3(GlobalContext*, Collider*);

callback_8011DEF8 D_8011DEF8_SetAT[] = {
    func_8005C124_SetAT_0,
    func_8005C508_SetAT_1,
    func_8005CC98_SetAT_2,
    func_8005D160_SetAT_3,
};

s32 Actor_CollisionCheck_SetAT(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* collision) {
    s16 temp_v1;

    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collision->type >= COLTYPE_MAX) {
        __assert("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xBB5);
    }
    D_8011DEF8_SetAT[collision->type](globalCtx, collision);
    if ((collision->actor != NULL) && (collision->actor->update == NULL)) {
        return -1;
    }
    temp_v1 = colChkCtx->unk0_nAT;
    if (temp_v1 >= ARRAY_COUNT(colChkCtx->unk4_AT)) {
        osSyncPrintf("CollisionCheck_setAT():インデックスがオーバーして追加不能\n");
        return -1;
    }
    if (colChkCtx->unk2 & 1) {
        return -1;
    }
    colChkCtx->unk4_AT[temp_v1] = collision;
    colChkCtx->unk0_nAT += 1;
    return temp_v1;
}

// unused
s32 func_8005D8AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2, s32 arg3) {
    if (arg2->type >= COLTYPE_MAX) {
        __assert("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xBDD);
    }
    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    D_8011DEF8_SetAT[arg2->type](globalCtx, arg2);
    if ((arg2->actor != NULL) && ((arg2->actor)->update == 0)) {
        return -1;
    }
    if (colChkCtx->unk2 & 1) {
        if (arg3 >= colChkCtx->unk0_nAT) {
            osSyncPrintf("CollisionCheck_setAT_SAC():全データ数より大きいところに登録しようとしている。\n");
            return -1;
        }
        colChkCtx->unk4_AT[arg3] = arg2;
    } else {
        if (colChkCtx->unk0_nAT >= ARRAY_COUNT(colChkCtx->unk4_AT)) {
            osSyncPrintf("CollisionCheck_setAT():インデックスがオーバーして追加不能\n");
            return -1;
        }
        arg3 = colChkCtx->unk0_nAT;
        colChkCtx->unk4_AT[colChkCtx->unk0_nAT] = arg2;
        colChkCtx->unk0_nAT += 1;
    }
    return arg3;
}

typedef s32 (*callback_8011DF08)(GlobalContext*, Collider*);

s32 func_8005C1AC_SetAC_0(GlobalContext*, Collider*);
s32 func_8005C540_SetAC_1(GlobalContext*, Collider*);
s32 func_8005CD34_SetAC_2(GlobalContext*, Collider*);
s32 func_8005D1A8_SetAC_3(GlobalContext*, Collider*);

callback_8011DF08 D_8011DF08_SetAC[] = {
    func_8005C1AC_SetAC_0,
    func_8005C540_SetAC_1,
    func_8005CD34_SetAC_2,
    func_8005D1A8_SetAC_3,
};

s32 Actor_CollisionCheck_SetAC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* collision) {
    s32 temp_v1;

    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collision->type >= COLTYPE_MAX) {
        __assert("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xC2A);
    }
    D_8011DF08_SetAC[collision->type](globalCtx, collision);
    if ((collision->actor != NULL) && (collision->actor->update == NULL)) {
        return -1;
    }
    temp_v1 = colChkCtx->unkCC_nAC;
    if (temp_v1 >= ARRAY_COUNT(colChkCtx->unkD0_AC)) {
        osSyncPrintf("CollisionCheck_setAC():インデックスがオーバして追加不能\n");
        return -1;
    }
    if (colChkCtx->unk2 & 1) {
        return -1;
    }
    colChkCtx->unkD0_AC[temp_v1] = collision;
    colChkCtx->unkCC_nAC++;
    return temp_v1;
}

// unused
s32 func_8005DB04(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2, s32 arg3) {
    if (arg2->type >= 4) {
        __assert("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xC51);
    }
    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    D_8011DF08_SetAC[arg2->type](globalCtx, arg2);
    if ((arg2->actor != NULL) && (arg2->actor->update == NULL)) {
        return -1;
    }
    if (colChkCtx->unk2 & 1) {
        if (arg3 >= colChkCtx->unkCC_nAC) {
            osSyncPrintf("CollisionCheck_setAC_SAC():全データ数より大きいところに登録しようとしている。\n");
            return -1;
        }
        colChkCtx->unkD0_AC[arg3] = arg2;
    } else {
        if (colChkCtx->unkCC_nAC >= ARRAY_COUNT(colChkCtx->unkD0_AC)) {
            osSyncPrintf("CollisionCheck_setAC():インデックスがオーバして追加不能\n");
            return -1;
        }
        arg3 = colChkCtx->unkCC_nAC;
        colChkCtx->unkD0_AC[arg3] = arg2;
        colChkCtx->unkCC_nAC += 1;
    }
    return arg3;
}

typedef s32 (*callback_8011DF18)(GlobalContext*, Collider*);

s32 func_8005C234_SetOT_0(GlobalContext*, Collider*);
s32 func_8005C578_SetOT_1(GlobalContext*, Collider*);
s32 func_8005CDD0_SetOT_2(GlobalContext*, Collider*);
s32 func_8005D1E0_SetOT_3(GlobalContext*, Collider*);

callback_8011DF18 D_8011DF18[] = {
    func_8005C234_SetOT_0,
    func_8005C578_SetOT_1,
    func_8005CDD0_SetOT_2,
    func_8005D1E0_SetOT_3,
};

s32 Actor_CollisionCheck_SetOT(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* collision) {
    s32 temp_v1;

    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collision->type >= 4) {
        __assert("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xC9D);
    }
    D_8011DF18[collision->type](globalCtx, collision);
    if ((collision->actor != NULL) && (collision->actor->update == NULL)) {
        return -1;
    }
    temp_v1 = colChkCtx->unk1C0_nOT;
    if (temp_v1 >= 0x32) {
        osSyncPrintf("CollisionCheck_setOC():インデックスがオーバして追加不能\n");
        return -1;
    }
    if (colChkCtx->unk2 & 1) {
        return -1;
    }
    colChkCtx->unk1C4_OT[temp_v1] = collision;
    colChkCtx->unk1C0_nOT += 1;
    return temp_v1;
}

// unused
s32 func_8005DD5C(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2, s32 arg3) {
    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (arg2->type >= 4) {
        __assert("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xCCA);
        if (1) {}
    }
    D_8011DF18[arg2->type](globalCtx, arg2);
    if ((arg2->actor != NULL) && (arg2->actor->update == NULL)) {
        return -1;
    }
    if (colChkCtx->unk2 & 1) {
        if (arg3 >= colChkCtx->unk1C0_nOT) {
            osSyncPrintf("CollisionCheck_setOC_SAC():全データ数より大きいところに登録しようとしている。\n");
            return -1;
        }
        colChkCtx->unk4_AT[arg3] = arg2;
    } else {
        if (colChkCtx->unk1C0_nOT >= ARRAY_COUNT(colChkCtx->unk1C4_OT)) {
            osSyncPrintf("CollisionCheck_setOC():インデックスがオーバして追加不能\n");
            return -1;
        }
        arg3 = colChkCtx->unk1C0_nOT;
        colChkCtx->unk1C4_OT[arg3] = arg2;
        colChkCtx->unk1C0_nOT += 1;
    }
    return arg3;
}

typedef struct struct_8005DE9C {
    char unk_0[0x28C];
    s32 unk28C;
    void* unk_290[UNK_SIZE];
} struct_8005DE9C;

// unused
s32 func_8005DE9C(GlobalContext* globalCtx, struct_8005DE9C* arg1, struct_8005D3A4* arg2) {
    s32 temp_v1;

    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    func_8005D3A4(globalCtx, arg2);
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

void func_8005DF9C(GlobalContext* globalCtx, Collider* arg1, Vec3f* arg2) {
}

typedef struct struct_8015D8A0 {
    /* 0x000 */ Vec3s unk0;
    /* 0x006 */ char unk_6[0x486];
    /* 0x48C */ f32 unk48C;
    /* 0x490 */ f32 unk490;
    /* 0x494 */ s32 unk494;
    /* 0x498 */ s32 unk498;
    Color_RGBA8 unk49C[4];
    Color_RGBA8 unk4AC[4];
    s32 unk4BC;
    s32 unk4C0;
} struct_8015D8A0;

#ifndef GLUE
#define GLUE(a, b) a##b
#endif
#ifndef GLUE2
#define GLUE2(a, b) GLUE(a, b)
#endif
#define BSS_DUMMY GLUE2(s8 sBssDummy, __LINE__)

void func_8005DFAC(GlobalContext* globalCtx, Collider* arg1, Vec3f* arg2) {
    static struct_8015D8A0 D_8015D8A0;

    s32 sp24;

    D_8015D8A0.unk0.x = (s16)(s32)arg2->x;
    D_8015D8A0.unk0.y = (s16)(s32)arg2->y;
    D_8015D8A0.unk0.z = (s16)(s32)arg2->z;
    D_8015D8A0.unk494 = 5;
    D_8015D8A0.unk498 = 5;
    D_8015D8A0.unk49C[0].r = 0xA;
    D_8015D8A0.unk49C[0].g = 0xA;
    D_8015D8A0.unk49C[0].b = 0xC8;
    D_8015D8A0.unk49C[0].a = 0xFF;
    D_8015D8A0.unk49C[1].r = 0;
    D_8015D8A0.unk49C[1].g = 0;
    D_8015D8A0.unk49C[1].b = 0x80;
    D_8015D8A0.unk49C[1].a = 0xFF;
    D_8015D8A0.unk49C[2].r = 0;
    D_8015D8A0.unk49C[2].g = 0;
    D_8015D8A0.unk49C[2].b = 0x80;
    D_8015D8A0.unk49C[2].a = 0xFF;
    D_8015D8A0.unk49C[3].r = 0;
    D_8015D8A0.unk49C[3].g = 0;
    D_8015D8A0.unk49C[3].b = 0x80;
    D_8015D8A0.unk49C[3].a = 0xFF;
    D_8015D8A0.unk4AC[0].r = 0;
    D_8015D8A0.unk4AC[0].g = 0;
    D_8015D8A0.unk4AC[0].b = 0x20;
    D_8015D8A0.unk4AC[0].a = 0;
    D_8015D8A0.unk4AC[1].r = 0;
    D_8015D8A0.unk4AC[1].g = 0;
    D_8015D8A0.unk4AC[1].b = 0x20;
    D_8015D8A0.unk4AC[1].a = 0;
    D_8015D8A0.unk4AC[2].r = 0;
    D_8015D8A0.unk4AC[2].g = 0;
    D_8015D8A0.unk4AC[2].b = 0x40;
    D_8015D8A0.unk4AC[2].a = 0;
    D_8015D8A0.unk4AC[3].r = 0;
    D_8015D8A0.unk4AC[3].g = 0;
    D_8015D8A0.unk4AC[3].b = 0x40;
    D_8015D8A0.unk4AC[3].a = 0;
    D_8015D8A0.unk4BC = 0;
    D_8015D8A0.unk4C0 = 0x10;
    D_8015D8A0.unk48C = 8.0f;
    D_8015D8A0.unk490 = -1.0f;
    Effect_Add(globalCtx, &sp24, 0, 0U, 1U, &D_8015D8A0);
}

BSS_DUMMY;
BSS_DUMMY;
BSS_DUMMY;
BSS_DUMMY;

void func_8005E10C(GlobalContext* globalCtx, Collider* arg1, Vec3f* arg2) {
    static struct_8015D8A0 D_8015DD68;
    s32 sp24;

    D_8015DD68.unk0.x = (s16)(s32)arg2->x;
    D_8015DD68.unk0.y = (s16)(s32)arg2->y;
    D_8015DD68.unk0.z = (s16)(s32)arg2->z;
    D_8015DD68.unk494 = 5;
    D_8015DD68.unk498 = 5;
    D_8015DD68.unk49C[0].r = 0xA;
    D_8015DD68.unk49C[0].g = 0xC8;
    D_8015DD68.unk49C[0].b = 0xA;
    D_8015DD68.unk49C[0].a = 0xFF;
    D_8015DD68.unk49C[1].r = 0;
    D_8015DD68.unk49C[1].g = 0x80;
    D_8015DD68.unk49C[1].b = 0;
    D_8015DD68.unk49C[1].a = 0xFF;
    D_8015DD68.unk49C[2].r = 0;
    D_8015DD68.unk49C[2].g = 0x80;
    D_8015DD68.unk49C[2].b = 0;
    D_8015DD68.unk49C[2].a = 0xFF;
    D_8015DD68.unk49C[3].r = 0;
    D_8015DD68.unk49C[3].g = 0x80;
    D_8015DD68.unk49C[3].b = 0;
    D_8015DD68.unk49C[3].a = 0xFF;
    D_8015DD68.unk4AC[0].r = 0;
    D_8015DD68.unk4AC[0].g = 0x20;
    D_8015DD68.unk4AC[0].b = 0;
    D_8015DD68.unk4AC[0].a = 0;
    D_8015DD68.unk4AC[1].r = 0;
    D_8015DD68.unk4AC[1].g = 0x20;
    D_8015DD68.unk4AC[1].b = 0;
    D_8015DD68.unk4AC[1].a = 0;
    D_8015DD68.unk4AC[2].r = 0;
    D_8015DD68.unk4AC[2].g = 0x40;
    D_8015DD68.unk4AC[2].b = 0;
    D_8015DD68.unk4AC[2].a = 0;
    D_8015DD68.unk4AC[3].r = 0;
    D_8015DD68.unk4AC[3].g = 0x40;
    D_8015DD68.unk4AC[3].b = 0;
    D_8015DD68.unk4AC[3].a = 0;
    D_8015DD68.unk4BC = 0;
    D_8015DD68.unk4C0 = 0x10;
    D_8015DD68.unk48C = 8.0f;
    D_8015DD68.unk490 = -1.0f;
    Effect_Add(globalCtx, &sp24, 0, 0U, 1U, &D_8015DD68);
}

void func_80062B80(GlobalContext* globalCtx, Vec3f* arg1);

void func_8005E26C(GlobalContext* globalCtx, Collider* arg1, Vec3f* arg2) {
    func_800299AC(globalCtx, arg2);
    func_80062B80(globalCtx, arg2);
}

void func_80062A28(GlobalContext* globalCtx, Vec3f* arg1);

void func_8005E2A4(GlobalContext* globalCtx, Collider* arg2, Vec3f* arg3) {
    func_80062A28(globalCtx, arg3);
}

void func_8005E2C8(GlobalContext* globalCtx, Collider* arg2, Vec3f* arg3) {
    func_80062A28(globalCtx, arg3);
}

void func_80062D60(GlobalContext* globalCtx, Vec3f* arg1);
void func_80062DAC(GlobalContext* globalCtx, Vec3f* arg1, Vec3f* arg2);

void func_8005E2EC(GlobalContext* globalCtx, ColliderBody* arg1, Collider* arg2, Vec3f* arg3) {
    if (((arg1->toucherFlags & 0x18) == 0) && (arg2->unk_14 != 9)) {
        func_80029CA4(globalCtx, 0, arg3);
        if (arg2->actor == NULL) {
            Audio_PlaySoundGeneral(0x1806U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else {
            Audio_PlaySoundGeneral(0x1806U, &arg2->actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    } else if ((arg1->toucherFlags & 0x18) == 0) {
        func_80029CA4(globalCtx, 3, arg3);
        if (arg2->actor == NULL) {
            func_80062D60(globalCtx, arg3);
        } else {
            func_80062DAC(globalCtx, arg3, &arg2->actor->unk_E4);
        }
    } else if ((arg1->toucherFlags & 0x18) == 8) {
        func_80029CA4(globalCtx, 0, arg3);
        if (arg2->actor == NULL) {
            Audio_PlaySoundGeneral(0x1806U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else {
            Audio_PlaySoundGeneral(0x1806U, &arg2->actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    } else if ((arg1->toucherFlags & 0x18) == 0x10) {
        func_80029CA4(globalCtx, 1, arg3);
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

callback_8011DF28 D_8011DF28[] = {
    func_8005DF9C, func_8005DFAC, func_8005E10C, func_8005E26C, func_8005E2A4, func_8005E2C8,
};
u8 D_8011DF40[][2] = {
    { 0x01, 0x00 }, { 0x00, 0x01 }, { 0x02, 0x01 }, { 0x00, 0x00 }, { 0x03, 0x05 }, { 0x00, 0x02 }, { 0x02, 0x00 },
    { 0x04, 0x00 }, { 0x01, 0x02 }, { 0x00, 0x03 }, { 0x00, 0x05 }, { 0x00, 0x03 }, { 0x00, 0x03 }, { 0x00, 0x04 },
};

void func_80062CD4(GlobalContext* globalCtx, Vec3f* arg1);
void func_80062E14(GlobalContext* globalCtx, Vec3f* arg1, Vec3f* arg2);

void func_8005E604(GlobalContext* globalCtx, Collider* arg1, ColliderBody* arg2, Collider* arg3, ColliderBody* arg4,
                   Vec3f* arg5) {
    if (!(arg4->bumperFlags & 0x40) && ((((arg2->toucherFlags & 0x20) != 0)) || !(arg2->toucherFlags & 0x40))) {
        if (arg3->actor != NULL) {
            D_8011DF28[D_8011DF40[arg3->unk_14][0]](globalCtx, arg3, arg5);
        }
        do {
        } while (0);
        if (arg3->actor != NULL) {
            if (D_8011DF40[arg3->unk_14][1] == 3) {
                func_8005E2EC(globalCtx, arg2, arg3, arg5);
            } else if (D_8011DF40[arg3->unk_14][1] == 4) {
                if (arg1->actor == NULL) {
                    func_80062CD4(globalCtx, arg5);
                    Audio_PlaySoundGeneral(0x1837U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
                } else {
                    func_80062E14(globalCtx, arg5, &arg1->actor->unk_E4);
                }
            } else if (D_8011DF40[arg3->unk_14][1] != 5) {
                func_80029CA4(globalCtx, D_8011DF40[arg3->unk_14][1], arg5);
                if (!(arg4->bumperFlags & 0x20)) {
                    func_8005E4F8(arg1, arg4);
                }
            }
        } else {
            func_80029CA4(globalCtx, 0U, arg5);
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

s32 func_8005E81C(GlobalContext* globalCtx, Collider* arg1, ColliderBody* arg2, Vec3f* arg3, Collider* arg4,
                  ColliderBody* arg5, Vec3f* arg6, Vec3f* arg7) {
    if ((arg4->collideFlags & 4) && (arg1->actor != NULL) && (arg4->actor != NULL)) {
        func_8005E800(arg1, arg4);
    }
    if (!(arg5->bumperFlags & 8)) {
        arg1->colliderFlags |= 2;
        arg1->at = arg4->actor;
        arg2->unk_18 = arg4;
        arg2->unk_20 = arg5;
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
        func_8005E604(globalCtx, arg1, arg2, arg4, arg5, arg7);
        arg2->toucherFlags |= 0x40;
    }
    return 1;
}

void func_8005E9C0_0ATvs0AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2,
                            Collider* arg3) {
    Collider_Type0* arg2_0 = (Collider_Type0*)arg2;
    Collider_Type0* arg3_0 = (Collider_Type0*)arg3;
    Collider_Type0_ptr1C* var_s1;
    Collider_Type0_ptr1C* var_s0;
    f32 sp8C;
    f32 sp88;
    f32 temp_fv0_2;
    Vec3f sp78;
    Vec3f sp6C;
    Vec3f sp60;

    if ((((arg2_0->unk18 > 0) && (arg2_0->unk1C != NULL)) && (arg3_0->unk18 > 0)) && (arg3_0->unk1C != NULL)) {
        for (var_s1 = arg2_0->unk1C; var_s1 < (arg2_0->unk1C + arg2_0->unk18); var_s1++) {
            if (func_8005DF2C(&var_s1->unk0) != 1) {
                for (var_s0 = arg3_0->unk1C; var_s0 < (arg3_0->unk1C + arg3_0->unk18); var_s0++) {
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
                        func_8005E81C(globalCtx, &arg2_0->unk0, &var_s1->unk0, &sp6C, &arg3_0->unk0, &var_s0->unk0,
                                      &sp60, &sp78);
                        if (!(arg3_0->unk0.maskB & 0x40)) {
                            return;
                        }
                    }
                }
            }
        }
    }
}

void func_8005EC6C_0ATvs1AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2,
                            Collider* arg3) {
    Collider_Type0* arg2_0 = (Collider_Type0*)arg2;
    Collider_Type1* arg3_1 = (Collider_Type1*)arg3;
    Collider_Type0_ptr1C* var_s0;
    f32 sp80;
    f32 sp7C;
    Vec3f sp70;
    Vec3f sp64;
    Vec3f sp58;
    f32 temp_fv0_2;

    if ((arg2_0->unk18 > 0) && (arg2_0->unk1C != NULL) && (arg3_1->unk40.radius > 0)) {
        if (((arg3_1->unk40.height > 0)) && (func_8005DF50(&arg3_1->unk18) != 1)) {
            if (&var_s0->unk28 && &var_s0->unk28) {}
            for (var_s0 = arg2_0->unk1C; var_s0 < &arg2_0->unk1C[arg2_0->unk18]; var_s0++) {
                if ((func_8005DF2C(&var_s0->unk0) != 1) && (func_8005DF74(&var_s0->unk0, &arg3_1->unk18) != 1) &&
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
                    func_8005E81C(globalCtx, &arg2_0->unk0, &var_s0->unk0, &sp64, &arg3_1->unk0, &arg3_1->unk18, &sp58,
                                  &sp70);
                    return;
                }
            }
        }
    }
}

void func_8005EEE0_1ATvs0AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2,
                            Collider* arg3) {
    Collider_Type1* arg2_1 = (Collider_Type1*)arg2;
    Collider_Type0* arg3_0 = (Collider_Type0*)arg3;
    f32 sp9C;
    f32 sp98;
    Collider_Type0_ptr1C* var_s0;
    Vec3f sp88;
    Vec3f sp7C;
    Vec3f sp70;
    f32 temp_fv0_2;

    if ((arg3_0->unk18 > 0) && (arg3_0->unk1C != 0) && (arg2_1->unk40.radius > 0)) {
        if ((arg2_1->unk40.height > 0) && (func_8005DF2C(&arg2_1->unk18) != 1)) {
            var_s0 = arg3_0->unk1C;
            while (var_s0 < (arg3_0->unk1C + (arg3_0->unk18))) {
                if ((func_8005DF50(&var_s0->unk0) != 1) && (func_8005DF74(&arg2_1->unk18, &var_s0->unk0) != 1) &&
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
                    func_8005E81C(globalCtx, &arg2_1->unk0, &arg2_1->unk18, &sp7C, &arg3_0->unk0, &var_s0->unk0, &sp70,
                                  &sp88);
                    if (!(arg3_0->unk0.maskB & 0x40)) {
                        return;
                    }
                }
                var_s0++;
            }
        }
    }
}

void func_8005F17C_0ATvs2AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2,
                            Collider* arg3) {
    Collider_Type0* arg2_0 = (Collider_Type0*)arg2;
    Collider_Type2* arg3_2 = (Collider_Type2*)arg3;
    Collider_Type0_ptr1C* var_s2;
    Collider_Type2_ptr1C* var_s0;
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;

    if ((arg2_0->unk18 > 0)) {
        if ((arg2_0->unk1C != NULL) && (arg3_2->unk18 > 0) && (arg3_2->unk1C != NULL)) {
            for (var_s2 = arg2_0->unk1C; var_s2 < (arg2_0->unk1C + arg2_0->unk18); var_s2++) {
                if (func_8005DF2C(&var_s2->unk0) != 1) {
                    for (var_s0 = arg3_2->unk1C; var_s0 < (arg3_2->unk1C + arg3_2->unk18); var_s0++) {
                        if ((func_8005DF50(&var_s0->unk0) != 1) && (func_8005DF74(&var_s2->unk0, &var_s0->unk0) != 1) &&
                            (func_800CE934(&var_s2->unk28.unk8, &var_s0->unk28, &sp6C) == 1)) {
                            sp60.x = (f32)var_s2->unk28.unk8.center.x;
                            sp60.y = (f32)var_s2->unk28.unk8.center.y;
                            sp60.z = (f32)var_s2->unk28.unk8.center.z;
                            sp54.x = (var_s0->unk28.vtx[0].x + var_s0->unk28.vtx[1].x + var_s0->unk28.vtx[2].x) *
                                     0.33333334f;
                            sp54.y = (var_s0->unk28.vtx[0].y + var_s0->unk28.vtx[1].y + var_s0->unk28.vtx[2].y) *
                                     0.33333334f;
                            sp54.z = (var_s0->unk28.vtx[0].z + var_s0->unk28.vtx[1].z + var_s0->unk28.vtx[2].z) *
                                     0.33333334f;
                            func_8005E81C(globalCtx, &arg2_0->unk0, &var_s2->unk0, &sp60, &arg3_2->unk0, &var_s0->unk0,
                                          &sp54, &sp6C);
                            return;
                        }
                    }
                }
                if (0) {}
            }
        }
    }
}

void func_8005F39C_2ATvs0AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2,
                            Collider* arg3) {
    Collider_Type2* arg2_2 = (Collider_Type2*)arg2;
    Collider_Type2_ptr1C* var_s0;
    Collider_Type0* arg3_0 = (Collider_Type0*)arg3;
    Collider_Type0_ptr1C* var_s3;
    Vec3f sp7C;
    Vec3f sp70;
    Vec3f sp64;

    if (arg3_0->unk18 > 0) {
        if ((arg3_0->unk1C != NULL) && (arg2_2->unk18 > 0) && (arg2_2->unk1C != 0)) {
            for (var_s3 = arg3_0->unk1C; var_s3 < (arg3_0->unk1C + arg3_0->unk18); var_s3++) {
                if ((func_8005DF50(&var_s3->unk0) != 1)) {
                    for (var_s0 = arg2_2->unk1C; var_s0 < (arg2_2->unk1C + arg2_2->unk18); var_s0++) {
                        if (((func_8005DF2C(&var_s0->unk0) != 1))) {
                            if ((((func_8005DF74(&var_s0->unk0, &var_s3->unk0) != 1)) &&
                                 (func_800CE934(&var_s3->unk28.unk8, &var_s0->unk28, &sp7C) == 1))) {
                                Math_Vec3s_ToVec3f(&sp64, &var_s3->unk28.unk8.center);
                                sp70.x = (var_s0->unk28.vtx[0].x + var_s0->unk28.vtx[1].x + var_s0->unk28.vtx[2].x) *
                                         0.33333334f;
                                sp70.y = (var_s0->unk28.vtx[0].y + var_s0->unk28.vtx[1].y + var_s0->unk28.vtx[2].y) *
                                         0.33333334f;
                                sp70.z = (var_s0->unk28.vtx[0].z + var_s0->unk28.vtx[1].z + var_s0->unk28.vtx[2].z) *
                                         0.33333334f;
                                func_8005E81C(globalCtx, &arg2_2->unk0, &var_s0->unk0, &sp70, &arg3_0->unk0,
                                              &var_s3->unk0, &sp64, &sp7C);
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

TriNorm D_8015E230;
BSS_DUMMY;
BSS_DUMMY;
BSS_DUMMY;
BSS_DUMMY;
TriNorm D_8015E268;
BSS_DUMMY;
BSS_DUMMY;
BSS_DUMMY;
BSS_DUMMY;

void func_8005F5B0_0ATvs3AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type0* arg2 = (Collider_Type0*)arg2_;
    Collider_Type3* arg3 = (Collider_Type3*)arg3_;
    Vec3f sp7C;
    Collider_Type0_ptr1C* var_s0;
    Vec3f sp6C;
    Vec3f sp60;

    if ((arg2->unk18 > 0) && ((arg2->unk1C != NULL)) && (func_8005DF50(&arg3->unk18) != 1)) {
        Math3D_TriNorm(&D_8015E230, &arg3->unk40.unk18, &arg3->unk40.unk24, &arg3->unk40.unkC);
        Math3D_TriNorm(&D_8015E268, &arg3->unk40.unkC, &arg3->unk40.unk0, &arg3->unk40.unk18);
        var_s0 = arg2->unk1C;
        while (var_s0 < &arg2->unk1C[arg2->unk18]) {
            if (func_8005DF2C(&var_s0->unk0) != 1) {
                if ((func_8005DF74(&var_s0->unk0, &arg3->unk18) != 1) &&
                    ((func_800CE934(&var_s0->unk28.unk8, &D_8015E230, &sp7C) == 1) ||
                     (func_800CE934(&var_s0->unk28.unk8, &D_8015E268, &sp7C) == 1))) {
                    Math_Vec3s_ToVec3f(&sp6C, &var_s0->unk28.unk8.center);
                    sp60.x =
                        (arg3->unk40.unk18.x + arg3->unk40.unk24.x + arg3->unk40.unkC.x + arg3->unk40.unk0.x) * 0.25f;
                    sp60.y =
                        (arg3->unk40.unk18.y + arg3->unk40.unk24.y + arg3->unk40.unkC.y + arg3->unk40.unk0.y) * 0.25f;
                    sp60.z =
                        (arg3->unk40.unk18.z + arg3->unk40.unk24.z + arg3->unk40.unkC.z + arg3->unk40.unk0.z) * 0.25f;
                    func_8005E81C(globalCtx, &arg2->unk0, &var_s0->unk0, &sp6C, &arg3->unk0, &arg3->unk18, &sp60,
                                  &sp7C);
                    return;
                }
            }
            var_s0++;
            if (1) {}
        }
    }
}

TriNorm D_8015E2A0;
TriNorm D_8015E2D8;

void func_8005F7D0_3ATvs0AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type3* arg2 = (Collider_Type3*)arg2_;
    Vec3f sp88;
    Collider_Type0* arg3 = (Collider_Type0*)arg3_;
    Collider_Type0_ptr1C* var_s1;
    Vec3f sp74;
    Vec3f sp68;

    if (arg3->unk18 > 0) {
        if ((arg3->unk1C != NULL) && (func_8005DF2C(&arg2->unk18) != 1)) {
            Math3D_TriNorm(&D_8015E2A0, &arg2->unk40.unk18, &arg2->unk40.unk24, &arg2->unk40.unkC);
            Math3D_TriNorm(&D_8015E2D8, &arg2->unk40.unk18, &arg2->unk40.unkC, &arg2->unk40.unk0);
            var_s1 = arg3->unk1C;
            while (var_s1 < &arg3->unk1C[arg3->unk18]) {
                if ((func_8005DF50(&var_s1->unk0) != 1) && ((func_8005DF74(&arg2->unk18, &var_s1->unk0) != 1)) &&
                    ((func_800CE934(&var_s1->unk28.unk8, &D_8015E2A0, &sp88) == 1) ||
                     (func_800CE934(&var_s1->unk28.unk8, &D_8015E2D8, &sp88) == 1)) &&
                    (func_8005D218(globalCtx, arg2, &sp88) != 0)) {
                    sp68.x = var_s1->unk28.unk8.center.x;
                    sp68.y = var_s1->unk28.unk8.center.y;
                    sp68.z = var_s1->unk28.unk8.center.z;
                    sp74.x =
                        (arg2->unk40.unk18.x + arg2->unk40.unk24.x + arg2->unk40.unkC.x + arg2->unk40.unk0.x) * 0.25f;
                    sp74.y =
                        (arg2->unk40.unk18.y + arg2->unk40.unk24.y + arg2->unk40.unkC.y + arg2->unk40.unk0.y) * 0.25f;
                    sp74.z =
                        (arg2->unk40.unk18.z + arg2->unk40.unk24.z + arg2->unk40.unkC.z + arg2->unk40.unk0.z) * 0.25f;
                    func_8005E81C(globalCtx, &arg2->unk0, &arg2->unk18, &sp74, &arg3->unk0, &var_s1->unk0, &sp68,
                                  &sp88);
                    if (!(arg3->unk0.maskB & 0x40)) {
                        return;
                    }
                }
                var_s1++;
                if (1) {}
            }
        }
    }
}

void func_8005FA30_1ATvs1AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type1* arg2 = (Collider_Type1*)arg2_;
    Collider_Type1* arg3 = (Collider_Type1*)arg3_;
    f32 sp6C;
    f32 sp68;
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;
    f32 temp_fv0;

    if ((arg2->unk40.radius > 0) && (arg2->unk40.height > 0) && (arg3->unk40.radius > 0)) {
        if (arg3->unk40.height > 0) {
            if (func_8005DF50(&arg3->unk18) != 1) {
                if ((func_8005DF2C(&arg2->unk18) != 1) && (func_8005DF74(&arg2->unk18, &arg3->unk18) != 1) &&
                    (Math3D_CylinderOutCylinderDist(&arg2->unk40, &arg3->unk40, &sp6C, &sp68) == 1)) {
                    Math_Vec3s_ToVec3f(&sp50, &arg2->unk40.pos);
                    Math_Vec3s_ToVec3f(&sp44, &arg3->unk40.pos);
                    if (!(fabsf(sp68) < 0.008f)) {
                        temp_fv0 = (f32)arg3->unk40.radius / sp68;
                        sp5C.y = (f32)arg3->unk40.pos.y + (f32)arg3->unk40.yShift + ((f32)arg3->unk40.height * 0.5f);
                        sp5C.x =
                            (((f32)arg2->unk40.pos.x - (f32)arg3->unk40.pos.x) * temp_fv0) + (f32)arg3->unk40.pos.x;
                        sp5C.z =
                            (((f32)arg2->unk40.pos.z - (f32)arg3->unk40.pos.z) * temp_fv0) + (f32)arg3->unk40.pos.z;
                    } else {
                        Math_Vec3s_ToVec3f((Vec3f*)&sp5C, &arg3->unk40.pos);
                    }
                    func_8005E81C(globalCtx, &arg2->unk0, &arg2->unk18, &sp50, &arg3->unk0, &arg3->unk18, &sp44, &sp5C);
                }
            }
        }
    }
}

void func_8005FC04_1ATvs2AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type1* arg2 = (Collider_Type1*)arg2_;
    Collider_Type2* arg3 = (Collider_Type2*)arg3_;
    Collider_Type2_ptr1C* var_s0;
    Vec3f sp68;
    Vec3f sp5C;
    Vec3f sp50;

    if ((arg2->unk40.radius > 0) && (arg2->unk40.height > 0) && (arg3->unk18 > 0) && ((arg3->unk1C != NULL)) &&
        (func_8005DF2C(&arg2->unk18) != 1)) {
        for (var_s0 = arg3->unk1C; var_s0 < &arg3->unk1C[arg3->unk18]; var_s0++) {
            if ((func_8005DF50(&var_s0->unk0) != 1) && (func_8005DF74(&arg2->unk18, &var_s0->unk0) != 1) &&
                (Math3D_CylTriTouchingIntersect(&arg2->unk40, &var_s0->unk28, &sp68) == 1)) {
                Math_Vec3s_ToVec3f(&sp5C, &arg2->unk40.pos);
                sp50.x = (var_s0->unk28.vtx[0].x + var_s0->unk28.vtx[1].x + var_s0->unk28.vtx[2].x) * 0.33333334f;
                sp50.y = (var_s0->unk28.vtx[0].y + var_s0->unk28.vtx[1].y + var_s0->unk28.vtx[2].y) * 0.33333334f;
                sp50.z = (var_s0->unk28.vtx[0].z + var_s0->unk28.vtx[1].z + var_s0->unk28.vtx[2].z) * 0.33333334f;
                func_8005E81C(globalCtx, &arg2->unk0, &arg2->unk18, &sp5C, &arg3->unk0, &var_s0->unk0, &sp50, &sp68);
                return;
            }
            if (1) {}
            if (1) {}
        }
    }
}

Vec3f D_8015E310;

void func_8005FDCC_2ATvs1AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type2* arg2 = (Collider_Type2*)arg2_;
    Collider_Type1* arg3 = (Collider_Type1*)arg3_;
    Collider_Type2_ptr1C* var_s0;
    Vec3f sp60;
    Vec3f sp54;

    if ((arg3->unk40.radius > 0) && (arg3->unk40.height > 0) && (arg2->unk18 > 0) && ((arg2->unk1C != NULL)) &&
        (func_8005DF50(&arg3->unk18) != 1)) {
        var_s0 = arg2->unk1C;
        while (var_s0 < &arg2->unk1C[arg2->unk18]) {
            if ((func_8005DF2C(&var_s0->unk0) != 1) && (func_8005DF74(&var_s0->unk0, &arg3->unk18) != 1) &&
                (Math3D_CylTriTouchingIntersect(&arg3->unk40, &var_s0->unk28, &D_8015E310) == 1)) {
                sp60.x = (var_s0->unk28.vtx[0].x + var_s0->unk28.vtx[1].x + var_s0->unk28.vtx[2].x) * 0.33333334f;
                sp60.y = (var_s0->unk28.vtx[0].y + var_s0->unk28.vtx[1].y + var_s0->unk28.vtx[2].y) * 0.33333334f;
                sp60.z = (var_s0->unk28.vtx[0].z + var_s0->unk28.vtx[1].z + var_s0->unk28.vtx[2].z) * 0.33333334f;
                Math_Vec3s_ToVec3f(&sp54, &arg3->unk40.pos);
                func_8005E81C(globalCtx, &arg2->unk0, &var_s0->unk0, &sp60, &arg3->unk0, &arg3->unk18, &sp54,
                              &D_8015E310);
                return;
            }
            var_s0++;
            if (1) {}
            if (1) {}
        }
    }
}

TriNorm D_8015E320;
TriNorm D_8015E358;
Vec3f D_8015E390;

void func_8005FF90_1ATvs3AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type1* arg2 = (Collider_Type1*)arg2_;
    Collider_Type3* arg3 = (Collider_Type3*)arg3_;
    Vec3f sp64;
    Vec3f sp58;
    Vec3f sp4C;
    Vec3f sp40;

    if ((arg2->unk40.height > 0) && ((arg2->unk40.radius > 0)) && ((func_8005DF2C(&arg2->unk18) != 1)) &&
        ((func_8005DF50(&arg3->unk18) != 1)) && (func_8005DF74(&arg2->unk18, &arg3->unk18) != 1)) {
        Math3D_TriNorm(&D_8015E320, &arg3->unk40.unk18, &arg3->unk40.unk24, &arg3->unk40.unkC);
        Math3D_TriNorm(&D_8015E358, &arg3->unk40.unkC, &arg3->unk40.unk0, &arg3->unk40.unk18);
        if (Math3D_CylTriTouchingIntersect(&arg2->unk40, &D_8015E320, &D_8015E390) == 1) {
            Math_Vec3s_ToVec3f(&sp64, &arg2->unk40.pos);
            sp58.x = (arg3->unk40.unk18.x + arg3->unk40.unk24.x + arg3->unk40.unkC.x + arg3->unk40.unk0.x) * 0.25f;
            sp58.y = (arg3->unk40.unk18.y + arg3->unk40.unk24.y + arg3->unk40.unkC.y + arg3->unk40.unk0.y) * 0.25f;
            sp58.z = (arg3->unk40.unk18.z + arg3->unk40.unk24.z + arg3->unk40.unkC.z + arg3->unk40.unk0.z) * 0.25f;
            func_8005E81C(globalCtx, &arg2->unk0, &arg2->unk18, &sp64, &arg3->unk0, &arg3->unk18, &sp58, &D_8015E390);
        } else if (Math3D_CylTriTouchingIntersect(&arg2->unk40, &D_8015E358, &D_8015E390) == 1) {
            Math_Vec3s_ToVec3f(&sp4C, &arg2->unk40.pos);
            sp40.x = (arg3->unk40.unk18.x + arg3->unk40.unk24.x + arg3->unk40.unkC.x + arg3->unk40.unk0.x) * 0.25f;
            sp40.y = (arg3->unk40.unk18.y + arg3->unk40.unk24.y + arg3->unk40.unkC.y + arg3->unk40.unk0.y) * 0.25f;
            sp40.z = (arg3->unk40.unk18.z + arg3->unk40.unk24.z + arg3->unk40.unkC.z + arg3->unk40.unk0.z) * 0.25f;
            func_8005E81C(globalCtx, &arg2->unk0, &arg2->unk18, &sp4C, &arg3->unk0, &arg3->unk18, &sp40, &D_8015E390);
        }
    }
}

TriNorm D_8015E3A0;
TriNorm D_8015E3D8;
Vec3f D_8015E410;

void func_80060204_3ATvs1AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type3* arg2 = (Collider_Type3*)arg2_;
    Collider_Type1* arg3 = (Collider_Type1*)arg3_;
    Vec3f sp64;
    Vec3f sp58;
    Vec3f sp4C;
    Vec3f sp40;

    if ((arg3->unk40.height > 0) && ((arg3->unk40.radius > 0)) && ((func_8005DF50(&arg3->unk18) != 1)) &&
        ((func_8005DF2C(&arg2->unk18) != 1)) && (func_8005DF74(&arg2->unk18, &arg3->unk18) != 1)) {
        Math3D_TriNorm(&D_8015E3A0, &arg2->unk40.unk18, &arg2->unk40.unk24, &arg2->unk40.unkC);
        Math3D_TriNorm(&D_8015E3D8, &arg2->unk40.unk18, &arg2->unk40.unkC, &arg2->unk40.unk0);
        if ((Math3D_CylTriTouchingIntersect(&arg3->unk40, &D_8015E3A0, &D_8015E410) == 1) &&
            (func_8005D218(globalCtx, arg2, &D_8015E410) != 0)) {
            sp64.x = (arg2->unk40.unk18.x + arg2->unk40.unk24.x + arg2->unk40.unkC.x + arg2->unk40.unk0.x) * 0.25f;
            sp64.y = (arg2->unk40.unk18.y + arg2->unk40.unk24.y + arg2->unk40.unkC.y + arg2->unk40.unk0.y) * 0.25f;
            sp64.z = (arg2->unk40.unk18.z + arg2->unk40.unk24.z + arg2->unk40.unkC.z + arg2->unk40.unk0.z) * 0.25f;
            Math_Vec3s_ToVec3f(&sp58, &arg3->unk40.pos);
            func_8005E81C(globalCtx, &arg2->unk0, &arg2->unk18, &sp64, &arg3->unk0, &arg3->unk18, &sp58, &D_8015E410);
        } else if ((Math3D_CylTriTouchingIntersect(&arg3->unk40, &D_8015E3D8, &D_8015E410) == 1) &&
                   (func_8005D218(globalCtx, arg2, &D_8015E410) != 0)) {
            sp4C.x = (arg2->unk40.unk18.x + arg2->unk40.unk24.x + arg2->unk40.unkC.x + arg2->unk40.unk0.x) * 0.25f;
            sp4C.y = (arg2->unk40.unk18.y + arg2->unk40.unk24.y + arg2->unk40.unkC.y + arg2->unk40.unk0.y) * 0.25f;
            sp4C.z = (arg2->unk40.unk18.z + arg2->unk40.unk24.z + arg2->unk40.unkC.z + arg2->unk40.unk0.z) * 0.25f;
            Math_Vec3s_ToVec3f(&sp40, &arg3->unk40.pos);
            func_8005E81C(globalCtx, &arg2->unk0, &arg2->unk18, &sp4C, &arg3->unk0, &arg3->unk18, &sp40, &D_8015E410);
        }
    }
}

Vec3f D_8015E420;

void func_800604B0_2ATvs2AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type2* arg2 = (Collider_Type2*)arg2_;
    Collider_Type2* arg3 = (Collider_Type2*)arg3_;
    Collider_Type2_ptr1C* var_s0;
    Collider_Type2_ptr1C* var_s2;
    Vec3f sp5C;
    Vec3f sp50;

    if ((arg3->unk18 > 0) && ((arg3->unk1C != NULL)) && (arg2->unk18 > 0) && (arg2->unk1C != NULL)) {

        for (var_s2 = arg3->unk1C; (((var_s2 < &arg3->unk1C[arg3->unk18]))); var_s2++) {
            if (func_8005DF50(&var_s2->unk0) != 1) {
                for (var_s0 = arg2->unk1C; var_s0 < &arg2->unk1C[arg2->unk18]; var_s0++) {
                    if (0) {}
                    if ((func_8005DF2C(&var_s0->unk0) != 1) && (func_8005DF74(&var_s0->unk0, &var_s2->unk0) != 1) &&
                        (Math3D_TrisIntersect(&var_s0->unk28, &var_s2->unk28, &D_8015E420) == 1)) {
                        sp5C.x =
                            (var_s0->unk28.vtx[0].x + var_s0->unk28.vtx[1].x + var_s0->unk28.vtx[2].x) * 0.33333334f;
                        sp5C.y =
                            (var_s0->unk28.vtx[0].y + var_s0->unk28.vtx[1].y + var_s0->unk28.vtx[2].y) * 0.33333334f;
                        sp5C.z =
                            (var_s0->unk28.vtx[0].z + var_s0->unk28.vtx[1].z + var_s0->unk28.vtx[2].z) * 0.33333334f;
                        sp50.x =
                            (var_s2->unk28.vtx[0].x + var_s2->unk28.vtx[1].x + var_s2->unk28.vtx[2].x) * 0.33333334f;
                        sp50.y =
                            (var_s2->unk28.vtx[0].y + var_s2->unk28.vtx[1].y + var_s2->unk28.vtx[2].y) * 0.33333334f;
                        sp50.z =
                            (var_s2->unk28.vtx[0].z + var_s2->unk28.vtx[1].z + var_s2->unk28.vtx[2].z) * 0.33333334f;
                        func_8005E81C(globalCtx, &arg2->unk0, &var_s0->unk0, &sp5C, &arg3->unk0, &var_s2->unk0, &sp50,
                                      &D_8015E420);
                        return;
                    }
                }
            }
        }
    }
}

Vec3f D_8015E430;
TriNorm D_8015E440;
TriNorm D_8015E478;

void func_80060704_2ATvs3AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type2* arg2 = (Collider_Type2*)arg2_;
    Collider_Type3* arg3 = (Collider_Type3*)arg3_;
    Collider_Type2_ptr1C* var_s1;
    Vec3f sp68;
    Vec3f sp5C;

    if ((arg2->unk18 > 0) && ((arg2->unk1C != NULL)) && (func_8005DF50(&arg3->unk18) != 1)) {
        Math3D_TriNorm(&D_8015E440, &arg3->unk40.unk18, &arg3->unk40.unk24, &arg3->unk40.unkC);
        Math3D_TriNorm(&D_8015E478, &arg3->unk40.unkC, &arg3->unk40.unk0, &arg3->unk40.unk18);
        for (var_s1 = arg2->unk1C; var_s1 < &arg2->unk1C[arg2->unk18]; var_s1++) {
            if ((func_8005DF2C(&var_s1->unk0) != 1) && (func_8005DF74(&var_s1->unk0, &arg3->unk18) != 1) &&
                (((Math3D_TrisIntersect(&D_8015E440, &var_s1->unk28, &D_8015E430) == 1)) ||
                 (Math3D_TrisIntersect(&D_8015E478, &var_s1->unk28, &D_8015E430) == 1))) {
                sp68.x = (var_s1->unk28.vtx[0].x + var_s1->unk28.vtx[1].x + var_s1->unk28.vtx[2].x) * 0.33333334f;
                sp68.y = (var_s1->unk28.vtx[0].y + var_s1->unk28.vtx[1].y + var_s1->unk28.vtx[2].y) * 0.33333334f;
                sp68.z = (var_s1->unk28.vtx[0].z + var_s1->unk28.vtx[1].z + var_s1->unk28.vtx[2].z) * 0.33333334f;
                sp5C.x = (arg3->unk40.unk18.x + arg3->unk40.unk24.x + arg3->unk40.unkC.x + arg3->unk40.unk0.x) * 0.25f;
                sp5C.y = (arg3->unk40.unk18.y + arg3->unk40.unk24.y + arg3->unk40.unkC.y + arg3->unk40.unk0.y) * 0.25f;
                sp5C.z = (arg3->unk40.unk18.z + arg3->unk40.unk24.z + arg3->unk40.unkC.z + arg3->unk40.unk0.z) * 0.25f;
                func_8005E81C(globalCtx, &arg2->unk0, &var_s1->unk0, &sp68, &arg3->unk0, &arg3->unk18, &sp5C,
                              &D_8015E430);
                return;
            }
            if (1) {}
            if (1) {}
            if (1) {}
            if (1) {}
            if (1) {}
            if (1) {}
        }
    }
}

Vec3f D_8015E4B0;
TriNorm D_8015E4C0;
TriNorm D_8015E4F8;

void func_80060994_3ATvs2AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type3* arg2 = (Collider_Type3*)arg2_;
    Collider_Type2* arg3 = (Collider_Type2*)arg3_;
    Collider_Type2_ptr1C* var_s1;
    Vec3f sp68;
    Vec3f sp5C;

    if ((arg3->unk18 > 0) && ((arg3->unk1C != NULL)) && (func_8005DF2C(&arg2->unk18) != 1)) {
        Math3D_TriNorm(&D_8015E4C0, &arg2->unk40.unk18, &arg2->unk40.unk24, &arg2->unk40.unkC);
        Math3D_TriNorm(&D_8015E4F8, &arg2->unk40.unkC, &arg2->unk40.unk0, &arg2->unk40.unk18);
        if (var_s1 && var_s1) {}
        for (var_s1 = arg3->unk1C; var_s1 < &arg3->unk1C[arg3->unk18]; var_s1++) {
            if ((func_8005DF50(&var_s1->unk0) != 1) && (func_8005DF74(&arg2->unk18, &var_s1->unk0) != 1) &&
                (((Math3D_TrisIntersect(&D_8015E4C0, &var_s1->unk28, &D_8015E4B0) == 1)) ||
                 (Math3D_TrisIntersect(&D_8015E4F8, &var_s1->unk28, &D_8015E4B0) == 1)) &&
                (func_8005D218(globalCtx, arg2, &D_8015E4B0) != 0)) {
                sp5C.x = (var_s1->unk28.vtx[0].x + var_s1->unk28.vtx[1].x + var_s1->unk28.vtx[2].x) * 0.33333334f;
                sp5C.y = (var_s1->unk28.vtx[0].y + var_s1->unk28.vtx[1].y + var_s1->unk28.vtx[2].y) * 0.33333334f;
                sp5C.z = (var_s1->unk28.vtx[0].z + var_s1->unk28.vtx[1].z + var_s1->unk28.vtx[2].z) * 0.33333334f;
                sp68.x = (arg2->unk40.unk18.x + arg2->unk40.unk24.x + arg2->unk40.unkC.x + arg2->unk40.unk0.x) * 0.25f;
                sp68.y = (arg2->unk40.unk18.y + arg2->unk40.unk24.y + arg2->unk40.unkC.y + arg2->unk40.unk0.y) * 0.25f;
                sp68.z = (arg2->unk40.unk18.z + arg2->unk40.unk24.z + arg2->unk40.unkC.z + arg2->unk40.unk0.z) * 0.25f;
                func_8005E81C(globalCtx, &arg2->unk0, &arg2->unk18, &sp68, &arg3->unk0, &var_s1->unk0, &sp5C,
                              &D_8015E4B0);
                return;
            }
        }
    }
}

TriNorm D_8015E530[2];
Vec3f D_8015E598;
TriNorm D_8015E5A8[2];

void func_80060C2C_3ATvs3AC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type3* arg2 = (Collider_Type3*)arg2_;
    Collider_Type3* arg3 = (Collider_Type3*)arg3_;
    s32 i;
    s32 j;
    Vec3f sp6C;
    Vec3f sp60;

    if ((func_8005DF2C(&arg2->unk18) != 1) && ((func_8005DF50(&arg3->unk18) != 1)) &&
        (func_8005DF74(&arg2->unk18, &arg3->unk18) != 1)) {
        Math3D_TriNorm(&D_8015E5A8[0], &arg2->unk40.unk18, &arg2->unk40.unk24, &arg2->unk40.unkC);
        Math3D_TriNorm(&D_8015E5A8[1], &arg2->unk40.unk18, &arg2->unk40.unkC, &arg2->unk40.unk0);
        Math3D_TriNorm(&D_8015E530[0], &arg3->unk40.unk18, &arg3->unk40.unk24, &arg3->unk40.unkC);
        Math3D_TriNorm(&D_8015E530[1], &arg3->unk40.unk18, &arg3->unk40.unkC, &arg3->unk40.unk0);

        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                if ((Math3D_TrisIntersect(&D_8015E5A8[j], &D_8015E530[i], &D_8015E598) == 1) &&
                    (func_8005D218(globalCtx, arg2, &D_8015E598) != 0)) {
                    sp6C.x =
                        (arg2->unk40.unk18.x + arg2->unk40.unk24.x + arg2->unk40.unkC.x + arg2->unk40.unk0.x) * 0.25f;
                    sp6C.y =
                        (arg2->unk40.unk18.y + arg2->unk40.unk24.y + arg2->unk40.unkC.y + arg2->unk40.unk0.y) * 0.25f;
                    sp6C.z =
                        (arg2->unk40.unk18.z + arg2->unk40.unk24.z + arg2->unk40.unkC.z + arg2->unk40.unk0.z) * 0.25f;
                    sp60.x =
                        (arg3->unk40.unk18.x + arg3->unk40.unk24.x + arg3->unk40.unkC.x + arg3->unk40.unk0.x) * 0.25f;
                    sp60.y =
                        (arg3->unk40.unk18.y + arg3->unk40.unk24.y + arg3->unk40.unkC.y + arg3->unk40.unk0.y) * 0.25f;
                    sp60.z =
                        (arg3->unk40.unk18.z + arg3->unk40.unk24.z + arg3->unk40.unkC.z + arg3->unk40.unk0.z) * 0.25f;
                    func_8005E81C(globalCtx, &arg2->unk0, &arg2->unk18, &sp6C, &arg3->unk0, &arg3->unk18, &sp60,
                                  &D_8015E598);
                    return;
                }
            }
        }
    }
}

void func_80060EBC_Type0_processAC_(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2) {
    Collider_Type0* arg2_0 = (Collider_Type0*)arg2;
    Collider_Type0_ptr1C* var_v0;
    Vec3f sp24;

    var_v0 = arg2_0->unk1C;
    while (var_v0 < (arg2_0->unk1C + (arg2_0->unk18))) {
        if (var_v0->unk0.bumperFlags & 0x80) {
            if ((var_v0->unk0.colliding != NULL) && !(var_v0->unk0.colliding->toucherFlags & 0x40)) {
                Math_Vec3s_ToVec3f(&sp24, &var_v0->unk0.bumper.unk_06);
                func_8005E604(globalCtx, var_v0->unk0.colBuf, var_v0->unk0.colliding, &arg2_0->unk0, &var_v0->unk0,
                              &sp24);
                var_v0->unk0.colliding->toucherFlags |= 0x40;
                return;
            }
        }
        var_v0++;
    }
}

void func_80060F94_Type1_processAC_(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_) {
    Collider_Type1* arg2 = (Collider_Type1*)arg2_;
    Vec3f sp28;

    if (arg2->unk18.bumperFlags & 0x80) {
        if ((arg2->unk18.colliding != NULL) && !(arg2->unk18.colliding->toucherFlags & 0x40)) {
            Math_Vec3s_ToVec3f(&sp28, &arg2->unk18.bumper.unk_06);
            func_8005E604(globalCtx, arg2->unk18.colBuf, arg2->unk18.colliding, &arg2->unk0, &arg2->unk18, &sp28);
            arg2->unk18.colliding->toucherFlags |= 0x40;
        }
    }
}

void func_80061028_Type2_processAC_(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_) {
    Collider_Type2* arg2 = (Collider_Type2*)arg2_;
    Collider_Type2_ptr1C* var_v0;
    Vec3f sp24;

    var_v0 = arg2->unk1C;
    while (var_v0 < &arg2->unk1C[arg2->unk18]) {
        if (var_v0->unk0.bumperFlags & 0x80) {
            if ((var_v0->unk0.colliding != NULL) && !(var_v0->unk0.colliding->toucherFlags & 0x40)) {
                Math_Vec3s_ToVec3f(&sp24, &var_v0->unk0.bumper.unk_06);
                func_8005E604(globalCtx, var_v0->unk0.colBuf, var_v0->unk0.colliding, &arg2->unk0, &var_v0->unk0,
                              &sp24);
                var_v0->unk0.colliding->toucherFlags |= 0x40;
                return;
            }
        }
        var_v0++;
    }
}

void func_8006110C_Type3_processAC_(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_) {
    Collider_Type3* arg2 = (Collider_Type3*)arg2_;
    Vec3f sp28;

    if (arg2->unk18.bumperFlags & 0x80) {
        if ((arg2->unk18.colliding != NULL) && !(arg2->unk18.colliding->toucherFlags & 0x40)) {
            Math_Vec3s_ToVec3f(&sp28, &arg2->unk18.bumper.unk_06);
            func_8005E604(globalCtx, arg2->unk18.colBuf, arg2->unk18.colliding, &arg2->unk0, &arg2->unk18, &sp28);
            arg2->unk18.colliding->toucherFlags |= 0x40;
        }
    }
}

typedef void (*callback_800611A0)(GlobalContext*, SubGlobalContext11E60*, Collider*);

void func_80060EBC_Type0_processAC_(GlobalContext*, SubGlobalContext11E60*, Collider*);
void func_80060F94_Type1_processAC_(GlobalContext*, SubGlobalContext11E60*, Collider*);
void func_80061028_Type2_processAC_(GlobalContext*, SubGlobalContext11E60*, Collider*);
void func_8006110C_Type3_processAC_(GlobalContext*, SubGlobalContext11E60*, Collider*);

callback_800611A0 D_8011DF5C_processAC_[] = {
    func_80060EBC_Type0_processAC_,
    func_80060F94_Type1_processAC_,
    func_80061028_Type2_processAC_,
    func_8006110C_Type3_processAC_,
};

void func_800611A0_processAC_(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx) {
    Collider** var_s0;
    Collider* temp_a2;

    var_s0 = colChkCtx->unkD0_AC;
    while (var_s0 < &colChkCtx->unkD0_AC[colChkCtx->unkCC_nAC]) {
        temp_a2 = *var_s0;
        if ((temp_a2 != NULL) && (temp_a2->collideFlags & 1) &&
            (((temp_a2->actor == NULL)) || (temp_a2->actor->update != NULL))) {
            D_8011DF5C_processAC_[temp_a2->type](globalCtx, colChkCtx, temp_a2);
        }
        var_s0++;
    }
}

typedef void (*callback_8011DF6C)(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);

void func_8005E9C0_0ATvs0AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005EC6C_0ATvs1AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005F17C_0ATvs2AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005F5B0_0ATvs3AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005EEE0_1ATvs0AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005FA30_1ATvs1AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005FC04_1ATvs2AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005FF90_1ATvs3AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005F39C_2ATvs0AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005FDCC_2ATvs1AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_800604B0_2ATvs2AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_80060704_2ATvs3AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8005F7D0_3ATvs0AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_80060204_3ATvs1AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_80060994_3ATvs2AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_80060C2C_3ATvs3AC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);

callback_8011DF6C D_8011DF6C_ATvsAC[4][4] = {
    { func_8005E9C0_0ATvs0AC, func_8005EC6C_0ATvs1AC, func_8005F17C_0ATvs2AC, func_8005F5B0_0ATvs3AC },
    { func_8005EEE0_1ATvs0AC, func_8005FA30_1ATvs1AC, func_8005FC04_1ATvs2AC, func_8005FF90_1ATvs3AC },
    { func_8005F39C_2ATvs0AC, func_8005FDCC_2ATvs1AC, func_800604B0_2ATvs2AC, func_80060704_2ATvs3AC },
    { func_8005F7D0_3ATvs0AC, func_80060204_3ATvs1AC, func_80060994_3ATvs2AC, func_80060C2C_3ATvs3AC },
};

void func_80061274_processATvsAC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2) {
    Collider** var_s1;
    Collider* temp_a3;

    var_s1 = colChkCtx->unkD0_AC;
    while ((u32)var_s1 < (u32)&colChkCtx->unkD0_AC[colChkCtx->unkCC_nAC]) {
        temp_a3 = *var_s1;
        if (temp_a3 != NULL) {
            if ((temp_a3->collideFlags & 1) && (((temp_a3->actor == NULL)) || (temp_a3->actor->update != NULL))) {
                if ((temp_a3->collideFlags & arg2->colliderFlags & 0x38) && (arg2 != temp_a3) &&
                    ((arg2->colliderFlags & 0x40) || ((arg2->actor == NULL)) || (temp_a3->actor != arg2->actor))) {
                    D_8011DF6C_ATvsAC[arg2->type][temp_a3->type](globalCtx, colChkCtx, arg2, temp_a3);
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
        for (var_s0 = colChkCtx->unk4_AT; var_s0 < &colChkCtx->unk4_AT[colChkCtx->unk0_nAT]; var_s0++) {
            temp_a2_2 = *var_s0;
            if ((temp_a2_2 != NULL) && (temp_a2_2->colliderFlags & 1) &&
                (((temp_a2_2->actor == NULL)) || (temp_a2_2->actor->update != NULL))) {
                func_80061274_processATvsAC(globalCtx, colChkCtx, temp_a2_2);
            }
        }
        func_800611A0_processAC_(globalCtx, colChkCtx);
    }
}

s32 func_8006146C(u8 arg0) {
    if (arg0 == 0xFF) {
        return 0;
    }
    if (arg0 == 0xFE) {
        return 1;
    }
    return 2;
}

void func_800614A4(Collider* arg0, ColliderBody* arg1, Vec3f* arg2, Collider* arg3, ColliderBody* arg4, Vec3f* arg5,
                   f32 arg6) {
    s32 pad;
    s32 pad2;
    s32 pad3;
    f32 sp40;
    f32 var_ft5;
    f32 sp38;
    f32 sp34;
    f32 new_var;
    f32 var_fa0;
    f32 var_fv1;
    Actor* temp_t0;
    Actor* temp_t1;
    s32 temp_v0;
    s32 sp18;
    f32 dx;
    f32 dz;

    temp_t0 = arg0->actor;
    temp_t1 = arg3->actor;
    arg0->maskA |= 2;
    arg0->ot = temp_t1;
    arg1->flags2 |= 2;
    if (arg3->maskB & 8) {
        arg0->maskB |= 1;
    }
    arg3->ot = temp_t0;
    arg3->maskA |= 2;
    arg4->flags2 |= 2;
    if (arg0->maskB & 8) {
        arg3->maskB |= 1;
    }
    if ((temp_t0 != NULL) && (temp_t1 != NULL) && !(arg0->maskA & 4) && !(arg3->maskA & 4)) {
        sp18 = func_8006146C(temp_t0->sub_98.mass);
        temp_v0 = func_8006146C(temp_t1->sub_98.mass);
        var_ft5 = temp_t0->sub_98.mass;
        sp38 = temp_t1->sub_98.mass;
        sp34 = var_ft5 + sp38;
        if (fabsf(sp34) < 0.008f) {
            var_ft5 = 1.0f;
            sp38 = 1.0f;
            sp34 = 2.0f;
        }
        dx = arg5->x - arg2->x;
        dz = arg5->z - arg2->z;
        sp40 = sqrtf((dx * dx) + (dz * dz));
        if (sp18 == 0) {
            if (temp_v0 != 0) {
                var_fv1 = 0;
                var_fa0 = 1;
            } else {
                return;
            }
        } else if (sp18 == 1) {
            if (temp_v0 == 0) {
                var_fv1 = 1;
                var_fa0 = 0;
            } else if (temp_v0 == 1) {
                var_fa0 = var_fv1 = 0.5f;
            } else {
                var_fv1 = 0;
                var_fa0 = 1;
            }
        } else {
            if (temp_v0 == 2) {
                new_var = 1 / sp34;
                var_fv1 = sp38 * new_var;
                var_fa0 = var_ft5 * new_var;
            } else {
                var_fv1 = 1;
                var_fa0 = 0;
            }
        }
        if (!(fabsf(sp40) < 0.008f)) {
            dx *= arg6 / sp40;
            dz *= arg6 / sp40;
            temp_t0->sub_98.displacement.x += (-dx) * var_fv1;
            temp_t0->sub_98.displacement.z += (-dz) * var_fv1;
            temp_t1->sub_98.displacement.x += dx * var_fa0;
            temp_t1->sub_98.displacement.z += dz * var_fa0;
        } else {
            if (arg6 != 0.0f) {
                temp_t0->sub_98.displacement.x += (-arg6) * var_fv1;
                temp_t1->sub_98.displacement.x += arg6 * var_fa0;
            } else {
                temp_t0->sub_98.displacement.x -= var_fv1;
                temp_t1->sub_98.displacement.x += var_fa0;
            }
        }
    }
}

void func_800617D4_0OCvs0OC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type0* arg2 = (Collider_Type0*)arg2_;
    Collider_Type0* arg3 = (Collider_Type0*)arg3_;
    Collider_Type0_ptr1C* var_s0;
    Collider_Type0_ptr1C* var_s4;
    f32 sp74;
    Vec3f sp68;
    Vec3f sp5C;

    if (arg2->unk18 > 0) {
        if ((arg2->unk1C != NULL) && (arg3->unk18 > 0) && (arg3->unk1C != NULL)) {
            for (var_s4 = arg2->unk1C; var_s4 < &arg2->unk1C[arg2->unk18]; var_s4++) {
                if (!(var_s4->unk0.flags2 & 1)) {
                    continue;
                }
                for (var_s0 = arg3->unk1C; var_s0 < &arg3->unk1C[arg3->unk18]; var_s0++) {
                    if (!(var_s0->unk0.flags2 & 1)) {
                        continue;
                    }
                    if (Math3D_SpheresTouchingSurface(&var_s4->unk28.unk8, &var_s0->unk28.unk8, &sp74) == 1) {
                        Math_Vec3s_ToVec3f(&sp68, &var_s4->unk28.unk8.center);
                        Math_Vec3s_ToVec3f(&sp5C, &var_s0->unk28.unk8.center);
                        func_800614A4(&arg2->unk0, &var_s4->unk0, &sp68, &arg3->unk0, &var_s0->unk0, &sp5C, sp74);
                    }
                }
            }
        }
    }
}

void func_8006199C_0OCvs1OC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type0* arg2 = (Collider_Type0*)arg2_;
    Collider_Type1* arg3 = (Collider_Type1*)arg3_;
    Collider_Type0_ptr1C* var_s0;
    f32 sp78;
    Vec3f sp6C;
    Vec3f sp60;

    if (arg2->unk18 > 0) {
        if ((arg2->unk1C != NULL) && (arg3->unk0.maskA & 1) && (arg3->unk18.flags2 & 1)) {
            for (var_s0 = arg2->unk1C; var_s0 < &arg2->unk1C[arg2->unk18]; var_s0++) {
                if (!(var_s0->unk0.flags2 & 1)) {
                    continue;
                }
                if (func_800CFD84(&var_s0->unk28.unk8, &arg3->unk40, &sp78) == 1) {
                    Math_Vec3s_ToVec3f(&sp6C, &var_s0->unk28.unk8.center);
                    Math_Vec3s_ToVec3f(&sp60, &arg3->unk40.pos);
                    func_800614A4(&arg2->unk0, &var_s0->unk0, &sp6C, &arg3->unk0, &arg3->unk18, &sp60, sp78);
                }
            }
        }
    }
}

void func_80061AF8_1OCvs0OC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2,
                            Collider* arg3) {
    func_8006199C_0OCvs1OC(globalCtx, colChkCtx, arg3, arg2);
}

void func_80061B24_1OCvs1OC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_,
                            Collider* arg3_) {
    Collider_Type1* arg2 = (Collider_Type1*)arg2_;
    Collider_Type1* arg3 = (Collider_Type1*)arg3_;
    f32 sp4C;
    Vec3f sp40;
    Vec3f sp34;

    if ((arg2->unk0.maskA & 1) && (arg3->unk0.maskA & 1) && (arg2->unk18.flags2 & 1) && (arg3->unk18.flags2 & 1) &&
        (Math3D_CylinderOutCylinder(&arg2->unk40, &arg3->unk40, &sp4C) == 1)) {
        Math_Vec3s_ToVec3f(&sp40, &arg2->unk40.pos);
        Math_Vec3s_ToVec3f(&sp34, &arg3->unk40.pos);
        func_800614A4(&arg2->unk0, &arg2->unk18, &sp40, &arg3->unk0, &arg3->unk18, &sp34, sp4C);
    }
}

s32 func_80061BF4(Collider* arg0) {
    if (!(arg0->maskA & 1)) {
        return 1;
    }
    return 0;
}

s32 func_80061C18(Collider* arg0, Collider* arg1) {
    if (!(arg0->maskA & arg1->maskB & 0x38) || (((arg0->maskB & arg1->maskA & 0x38) == 0)) ||
        ((arg0->maskB & 2) && (arg1->maskB & 4)) || ((arg1->maskB & 2) && (arg0->maskB & 4))) {
        return 1;
    }
    if (arg0->actor == arg1->actor) {
        return 1;
    }
    return 0;
}

typedef void (*callback_8011DFAC)(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);

void func_800617D4_0OCvs0OC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_8006199C_0OCvs1OC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_80061AF8_1OCvs0OC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);
void func_80061B24_1OCvs1OC(GlobalContext*, SubGlobalContext11E60*, Collider*, Collider*);

callback_8011DFAC D_8011DFAC[4][4] = {
    { func_800617D4_0OCvs0OC, func_8006199C_0OCvs1OC, NULL, NULL },
    { func_80061AF8_1OCvs0OC, func_80061B24_1OCvs1OC, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
};

void func_80061C98_OC(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx) {
    Collider** var_s0;
    Collider** var_s2;
    callback_8011DFAC temp_v0;

    for (var_s2 = colChkCtx->unk1C4_OT; var_s2 < &colChkCtx->unk1C4_OT[colChkCtx->unk1C0_nOT]; var_s2++) {
        if ((*var_s2 == NULL) || (func_80061BF4(*var_s2) == 1)) {
            continue;
        }
        for (var_s0 = var_s2 + 1; var_s0 < &colChkCtx->unk1C4_OT[colChkCtx->unk1C0_nOT]; var_s0++) {
            if ((*var_s0 == NULL) || (func_80061BF4(*var_s0) == 1) || (func_80061C18(*var_s2, *var_s0) == 1)) {
                continue;
            }
            temp_v0 = D_8011DFAC[(*var_s2)->type][(*var_s0)->type];
            if (temp_v0 == NULL) {
                osSyncPrintf("CollisionCheck_OC():未対応 %d, %d\n", (*var_s2)->type, (*var_s0)->type);
                continue;
            }
            temp_v0(globalCtx, colChkCtx, *var_s2, *var_s0);
        }
    }
}

SubActorStruct98 D_8011DFEC = {
    NULL, { 0.0f, 0.0f, 0.0f }, 0xA, 0xA, 0, 0x32, 8, 0, 0, 0, 0,
};

void func_80061E48(SubActorStruct98* arg0) {
    *arg0 = D_8011DFEC;
}

void func_80061E8C(SubActorStruct98* arg0) {
    arg0->damage = 0;
    arg0->damageEffect = 0;
    arg0->impactEffect = 0;
    arg0->unk_1B = 0;
    arg0->displacement.x = arg0->displacement.y = arg0->displacement.z = 0.0f;
}

typedef struct struct_80061EB0_arg0 {
    /* 0x00 */ char unk_0[0x10];
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ char unk_14[2];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
} struct_80061EB0_arg0;

typedef struct struct_80061EB0_arg1 {
    /* 0x00 */ u8 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u8 unk6;
} struct_80061EB0_arg1;

// unused
void func_80061EB0(struct_80061EB0_arg0* arg0, struct_80061EB0_arg1* arg1) {
    arg0->unk17 = arg1->unk0;
    arg0->unk10 = arg1->unk2;
    arg0->unk12 = arg1->unk4;
    arg0->unk16 = arg1->unk6;
}

void func_80061ED4(SubActorStruct98* sub98, ActorDamageChart* damageChart, Sub98Init4* sub98Init) {
    sub98->health = sub98Init->health;
    sub98->damageChart = damageChart;
    sub98->unk_10 = sub98Init->unk_02;
    sub98->unk_12 = sub98Init->unk_04;
    sub98->mass = sub98Init->mass;
}

void func_80061EFC(SubActorStruct98* sub98, ActorDamageChart* damageChart, Sub98Init5* sub98Init) {
    sub98->health = sub98Init->health;
    sub98->damageChart = damageChart;
    sub98->unk_10 = sub98Init->unk_10;
    sub98->unk_12 = sub98Init->unk_12;
    sub98->unk_14 = sub98Init->unk_14;
    sub98->mass = sub98Init->mass;
}

// unused
void func_80061F2C(SubActorStruct98* arg0, s32 arg1, Sub98Init5* arg2) {
    func_80061EFC(arg0, CollisionBtlTbl_Get(arg1), arg2);
}

void func_80061F64(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2, ColliderBody* obj_elem) {
    f32 unkf;
    s32 i;
    u32 unk0;

    if (arg2->actor != NULL && (arg2->collideFlags & 2)) {
        if ((obj_elem->bumperFlags & 2) && !(obj_elem->bumperFlags & 0x10)) {

            if (obj_elem->colliding == NULL) {
                __assert("pclobj_elem->ac_hit_elem != NULL", "../z_collision_check.c", 0x195D);
            }

            if (arg2->actor->sub_98.damageChart == NULL) {
                unkf = (f32)obj_elem->colliding->toucher.damage - (f32)obj_elem->bumper.unk_05;
                if (unkf < 0.0f) {
                    unkf = 0.0f;
                }
            } else {
                unk0 = obj_elem->colliding->toucher.flags;

                for (i = 0; i < 32; i++) {
                    if (unk0 == 1) {
                        break;
                    }

                    unk0 >>= 1;
                }

                unkf = arg2->actor->sub_98.damageChart->attack[i].raw & 0xF;
                arg2->actor->sub_98.damageEffect = (arg2->actor->sub_98.damageChart->attack[i].raw >> 4) & 0xF;
            }

            if (!(arg2->collideFlags & 4)) {
                arg2->actor->sub_98.damage += unkf;
            }
            if (1) {}
            if (1) {}
        }
    }
}

void func_8006216C_Type0(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2) {
    Collider_Type0* new_var2 = (Collider_Type0*)arg2;
    Collider_Type0* new_var = (Collider_Type0*)arg2;
    s32 i;

    if (new_var->unk18 <= 0 || new_var->unk1C == NULL) {
        return;
    }

    for (i = 0; i < new_var2->unk18; i++) {
        func_80061F64(globalCtx, colChkCtx, &new_var->unk0, &new_var->unk1C[i].unk0);
    }
}

void func_80062210_Type1(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2) {
    Collider_Type1* new_var = (Collider_Type1*)arg2;

    func_80061F64(globalCtx, colChkCtx, arg2, &new_var->unk18);
}

void func_80062230_Type2(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2) {
    s32 i;
    Collider_Type2* new_var = (Collider_Type2*)arg2;

    for (i = 0; i < new_var->unk18; i++) {
        func_80061F64(globalCtx, colChkCtx, &new_var->unk0, &new_var->unk1C[i].unk0);
    }
}

void func_800622C4_Type3(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2) {
    Collider_Type3* new_var = (Collider_Type3*)arg2;

    func_80061F64(globalCtx, colChkCtx, arg2, &new_var->unk18);
}

typedef void (*func_ptr_800622E4)(GlobalContext*, SubGlobalContext11E60*, Collider*);

void func_8006216C_Type0(GlobalContext*, SubGlobalContext11E60*, Collider*);
void func_80062210_Type1(GlobalContext*, SubGlobalContext11E60*, Collider*);
void func_80062230_Type2(GlobalContext*, SubGlobalContext11E60*, Collider*);
void func_800622C4_Type3(GlobalContext*, SubGlobalContext11E60*, Collider*);

func_ptr_800622E4 D_8011E008[] = {
    func_8006216C_Type0,
    func_80062210_Type1,
    func_80062230_Type2,
    func_800622C4_Type3,
};

void func_800622E4(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx) {
    Collider* entry;
    s32 i;

    for (i = 0; i < colChkCtx->unkCC_nAC; i++) {
        entry = colChkCtx->unkD0_AC[i];

        if (entry == NULL) {
        } else if (entry->collideFlags & 0x40) {
        } else {
            D_8011E008[entry->type](globalCtx, colChkCtx, entry);
        }
    }
}

Linef D_8015E610;

s32 func_800623A4_Type0(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2, Vec3f* arg3,
                        Vec3f* arg4) {
    Collider_Type0* new_var;
    s32 i;
    Collider_Type0_ptr1C* entry;

    new_var = (Collider_Type0*)arg2;
    for (i = 0; i < new_var->unk18; i++) {
        entry = new_var->unk1C + i;

        if (!(entry->unk0.flags2 & 1)) {
            continue;
        }

        D_8015E610.a = *arg3;
        D_8015E610.b = *arg4;

        if (func_800CE600(&entry->unk28.unk8, &D_8015E610) == 1) {
            return 1;
        }
    }

    return 0;
}

Vec3f D_8015E628;
Vec3f D_8015E638;

s32 func_800624BC_Type1(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Collider* arg2_, Vec3f* arg3,
                        Vec3f* arg4) {
    Collider_Type1* arg2 = (Collider_Type1*)arg2_;

    if (!(arg2->unk18.flags2 & 1)) {
        return 0;
    }

    if (func_800CEE0C(&arg2->unk40, arg3, arg4, &D_8015E628, &D_8015E638) != 0) {
        return 1;
    }

    return 0;
}

typedef s32 (*func_ptr_80062530)(GlobalContext*, SubGlobalContext11E60*, Collider*, Vec3f*, Vec3f*);

func_ptr_80062530 D_8011E018[] = {
    func_800623A4_Type0,
    func_800624BC_Type1,
    NULL,
    NULL,
};

s32 func_80062530(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Vec3f* arg2, Vec3f* arg3, Actor** unkList,
                  s32 unkListCount) {
    func_ptr_80062530 func;
    s32 condition;
    s32 result = 0;
    s32 j;
    Collider** entryPtr = colChkCtx->unk1C4_OT;
    Collider* entry;

    for (; entryPtr < colChkCtx->unk1C4_OT + colChkCtx->unk1C0_nOT; entryPtr++) {
        if (func_80061BF4(*entryPtr) == 1) {
            continue;
        }

        condition = 0;
        for (j = 0; j < unkListCount; j++) {
            if ((*entryPtr)->actor == unkList[j]) {
                condition = true;
                break;
            }
        }

        if (condition == true) {
            continue;
        }

        entry = *entryPtr;
        func = D_8011E018[entry->type];

        if (func == NULL) {
            osSyncPrintf("CollisionCheck_generalLineOcCheck():未対応 %dタイプ\n", entry->type);
            continue;
        }

        result = func(globalCtx, colChkCtx, entry, arg2, arg3);

        if (result != 0) {
            break;
        }
    }

    return result;
}

// unused
void func_8006268C(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Vec3f* arg2, Vec3f* arg3) {
    func_80062530(globalCtx, colChkCtx, arg2, arg3, NULL, 0);
}

void func_800626B0(GlobalContext* globalCtx, SubGlobalContext11E60* colChkCtx, Vec3f* arg2, Vec3f* arg3, Actor** arg4,
                   s32 arg5) {
    func_80062530(globalCtx, colChkCtx, arg2, arg3, arg4, arg5);
}

void ActorCollider_Type1_Update(Actor* actor, Collider_Type1* collision) {
    collision->unk40.pos.x = (s16)(s32)actor->posRot.pos.x;
    collision->unk40.pos.y = (s16)(s32)actor->posRot.pos.y;
    collision->unk40.pos.z = (s16)(s32)actor->posRot.pos.z;
}

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
    /* 0x28 */ TriNorm unk28;
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
    Math_Vec3f_Copy(&temp_s0->unk28.vtx[0], arg2);
    Math_Vec3f_Copy(&temp_s0->unk28.vtx[1], arg3);
    Math_Vec3f_Copy(&temp_s0->unk28.vtx[2], arg4);
    func_800CC8B4(arg2, arg3, arg4, &sp40, &sp3C, &sp38, &sp34);
    temp_s0->unk28.plane.normal.x = sp40;
    temp_s0->unk28.plane.normal.y = sp3C;
    temp_s0->unk28.plane.normal.z = sp38;
    temp_s0->unk28.plane.originDist = sp34;
}

// unused
void func_8006285C(GlobalContext* globalCtx, struct_800627A0* arg1, s32 arg2, Vec3f* arg3) {
    struct_800627A0_ptr* new_var;

    new_var = &arg1->unk1C[arg2];
    func_8005C608(globalCtx, &new_var->unk28, arg3);
}

void func_800628A4_Type0(s32 arg0, Collider_Type0* arg1) {
    static Vec3f D_8015CF00;
    // bss block number rollover!
    static Vec3f D_8015E648;

    s32 i;

    for (i = 0; i < arg1->unk18; i++) {
        if (arg0 == arg1->unk1C[i].unk28.unk14) {
            D_8015CF00.x = arg1->unk1C[i].unk28.unk0.unk0.x;
            D_8015CF00.y = arg1->unk1C[i].unk28.unk0.unk0.y;
            D_8015CF00.z = arg1->unk1C[i].unk28.unk0.unk0.z;
            Matrix_MultVec3f(&D_8015CF00, &D_8015E648);
            arg1->unk1C[i].unk28.unk8.center.x = D_8015E648.x;
            arg1->unk1C[i].unk28.unk8.center.y = D_8015E648.y;
            arg1->unk1C[i].unk28.unk8.center.z = D_8015E648.z;
            arg1->unk1C[i].unk28.unk8.radius = (arg1->unk1C[i].unk28.unk0.unk6 * arg1->unk1C[i].unk28.unk10);
        }
    }
}

void func_80062A28(GlobalContext* globalCtx, Vec3f* arg1) {
    static struct_8015D8A0 D_8015CF10;
    s32 sp24;

    D_8015CF10.unk0.x = (s16)(s32)arg1->x;
    D_8015CF10.unk0.y = (s16)(s32)arg1->y;
    D_8015CF10.unk0.z = (s16)(s32)arg1->z;
    D_8015CF10.unk494 = 5;
    D_8015CF10.unk498 = 5;
    D_8015CF10.unk49C[0].r = 0x80;
    D_8015CF10.unk49C[0].g = 0;
    D_8015CF10.unk49C[0].b = 0x40;
    D_8015CF10.unk49C[0].a = 0xFF;
    D_8015CF10.unk49C[1].r = 0x80;
    D_8015CF10.unk49C[1].g = 0;
    D_8015CF10.unk49C[1].b = 0x40;
    D_8015CF10.unk49C[1].a = 0xFF;
    D_8015CF10.unk49C[2].r = 0xFF;
    D_8015CF10.unk49C[2].g = 0x80;
    D_8015CF10.unk49C[2].b = 0;
    D_8015CF10.unk49C[2].a = 0xFF;
    D_8015CF10.unk49C[3].r = 0xFF;
    D_8015CF10.unk49C[3].g = 0x80;
    D_8015CF10.unk49C[3].b = 0;
    D_8015CF10.unk49C[3].a = 0xFF;
    D_8015CF10.unk4AC[0].r = 0x40;
    D_8015CF10.unk4AC[0].g = 0;
    D_8015CF10.unk4AC[0].b = 0x20;
    D_8015CF10.unk4AC[0].a = 0;
    D_8015CF10.unk4AC[1].r = 0x40;
    D_8015CF10.unk4AC[1].g = 0;
    D_8015CF10.unk4AC[1].b = 0x20;
    D_8015CF10.unk4AC[1].a = 0;
    D_8015CF10.unk4AC[2].r = 0x80;
    D_8015CF10.unk4AC[2].g = 0;
    D_8015CF10.unk4AC[2].b = 0x40;
    D_8015CF10.unk4AC[2].a = 0;
    D_8015CF10.unk4AC[3].r = 0x80;
    D_8015CF10.unk4AC[3].g = 0;
    D_8015CF10.unk4AC[3].b = 0x40;
    D_8015CF10.unk4AC[3].a = 0;
    D_8015CF10.unk4BC = 0;
    D_8015CF10.unk4C0 = 0x10;
    D_8015CF10.unk48C = 8.0f;
    D_8015CF10.unk490 = -1.0f;
    Effect_Add(globalCtx, &sp24, 0, 0U, 1U, &D_8015CF10);
}

void func_80062B80(GlobalContext* globalCtx, Vec3f* arg1) {
    static struct_8015D8A0 D_8015D3D8;
    s32 sp24;

    D_8015D3D8.unk0.x = (s16)(s32)arg1->x;
    D_8015D3D8.unk0.y = (s16)(s32)arg1->y;
    D_8015D3D8.unk0.z = (s16)(s32)arg1->z;
    D_8015D3D8.unk494 = 5;
    D_8015D3D8.unk498 = 5;
    D_8015D3D8.unk49C[0].r = 0xFF;
    D_8015D3D8.unk49C[0].g = 0xFF;
    D_8015D3D8.unk49C[0].b = 0xFF;
    D_8015D3D8.unk49C[0].a = 0xFF;
    D_8015D3D8.unk49C[1].r = 0x64;
    D_8015D3D8.unk49C[1].g = 0x64;
    D_8015D3D8.unk49C[1].b = 0x64;
    D_8015D3D8.unk49C[1].a = 0x64;
    D_8015D3D8.unk49C[2].r = 0x64;
    D_8015D3D8.unk49C[2].g = 0x64;
    D_8015D3D8.unk49C[2].b = 0x64;
    D_8015D3D8.unk49C[2].a = 0x64;
    D_8015D3D8.unk49C[3].r = 0x64;
    D_8015D3D8.unk49C[3].g = 0x64;
    D_8015D3D8.unk49C[3].b = 0x64;
    D_8015D3D8.unk49C[3].a = 0x64;
    D_8015D3D8.unk4AC[0].r = 0x32;
    D_8015D3D8.unk4AC[0].g = 0x32;
    D_8015D3D8.unk4AC[0].b = 0x32;
    D_8015D3D8.unk4AC[0].a = 0x32;
    D_8015D3D8.unk4AC[1].r = 0x32;
    D_8015D3D8.unk4AC[1].g = 0x32;
    D_8015D3D8.unk4AC[1].b = 0x32;
    D_8015D3D8.unk4AC[1].a = 0x32;
    D_8015D3D8.unk4AC[2].r = 0x32;
    D_8015D3D8.unk4AC[2].g = 0x32;
    D_8015D3D8.unk4AC[2].b = 0x32;
    D_8015D3D8.unk4AC[2].a = 0x32;
    D_8015D3D8.unk4AC[3].r = 0;
    D_8015D3D8.unk4AC[3].g = 0;
    D_8015D3D8.unk4AC[3].b = 0;
    D_8015D3D8.unk4AC[3].a = 0;
    D_8015D3D8.unk4BC = 0;
    D_8015D3D8.unk4C0 = 0x10;
    D_8015D3D8.unk48C = 8.0f;
    D_8015D3D8.unk490 = -1.0f;
    Effect_Add(globalCtx, &sp24, 0, 0U, 1U, &D_8015D3D8);
}

typedef struct struct_8011E068 {
    /* 0x00 */ char unk_0[2];
    /* 0x02 */ Vec3s unk2;
    /* 0x08 */ char unk_8[0x26];
    /* 0x2E */ Vec3s unk2E;
    /* 0x34 */ char unk_34[0xC];
} struct_8011E068;

void func_80062CD4(GlobalContext* globalCtx, Vec3f* arg1) {
    static struct_8011E068 D_8011E028 = {
        { 0x10, 0 },
        { 0, 0, 0 },
        {
            0,    0xC8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF,
            0xFF, 0,    0xFF, 0xFF, 0x40, 0,    0xC8, 0xFF, 0,    0,    0xFF, 0x40, 6,
            0x66, 0x66, 0x42, 0xC,  0,    0,    0x41, 0xF0, 0,    0,    8,    0,
        },
        { 0, 0, 0 },
        { 0, 0x80, 0xFF, 0, 1, 0x2C, 0, 0, 0, 0, 0, 1 },
    };
    s32 sp24;

    D_8011E028.unk2.x = (s16)(s32)arg1->x;
    D_8011E028.unk2.y = (s16)(s32)arg1->y;
    D_8011E028.unk2.z = (s16)(s32)arg1->z;
    D_8011E028.unk2E.x = D_8011E028.unk2.x;
    D_8011E028.unk2E.y = D_8011E028.unk2.y;
    D_8011E028.unk2E.z = D_8011E028.unk2.z;
    Effect_Add(globalCtx, &sp24, 3, 0U, 1U, &D_8011E028);
}

void func_80062D60(GlobalContext* globalCtx, Vec3f* arg1) {
    func_80062CD4(globalCtx, arg1);
    Audio_PlaySoundGeneral(0x1808U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
}

void func_80062DAC(GlobalContext* globalCtx, Vec3f* arg1, Vec3f* arg2) {
    func_80062CD4(globalCtx, arg1);
    Audio_PlaySoundGeneral(0x1808U, arg2, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
}

void func_80062DF4(GlobalContext* globalCtx, Vec3f* arg1) {
    func_80062D60(globalCtx, arg1);
}

void func_80062E14(GlobalContext* globalCtx, Vec3f* arg1, Vec3f* arg2) {
    static struct_8011E068 D_8011E068 = {
        { 0x10, 0 },
        { 0, 0, 0 },
        {
            0,    0xC8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF,
            0xFF, 0,    0xFF, 0xFF, 0x40, 0,    0xC8, 0xFF, 0,    0,    0xFF, 0x40, 6,
            0x66, 0x66, 0x42, 0xC,  0,    0,    0x41, 0xF0, 0,    0,    8,    0,
        },
        { 0, 0, 0 },
        { 0, 0x80, 0xFF, 0, 1, 0x2C, 0, 0, 0, 0, 0, 0 },
    };
    s32 sp24;

    D_8011E068.unk2.x = arg1->x;
    D_8011E068.unk2.y = arg1->y;
    D_8011E068.unk2.z = arg1->z;
    D_8011E068.unk2E.x = D_8011E068.unk2.x;
    D_8011E068.unk2E.y = D_8011E068.unk2.y;
    D_8011E068.unk2E.z = D_8011E068.unk2.z;
    Effect_Add(globalCtx, &sp24, 3, 0U, 1U, &D_8011E068);
    Audio_PlaySoundGeneral(0x1837U, arg2, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
}

s32 func_80062ECC(f32 arg0, f32 arg1, f32 arg2, Vec3f* arg3, Vec3f* arg4, Vec3f* arg5, Vec3f* arg6_out,
                  Vec3f* arg7_out) {
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;
    f32 var_ft4_real;
    f32 sp4C;
    float new_var2;
    f32 temp_fa1_2;
    f32 temp_fv0_2;
    f32 temp_fv1;
    f32 temp_fa0;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_v0_2;
    s32 var_v1_2;
    s32 pad;

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
    new_var2 = 0.0f; // fake?
    temp_fa0 = ((sp6C.x * sp6C.x) + (sp6C.z * sp6C.z)) - (arg0 * arg0);
    temp_fv1 = (sp54.x * sp54.x) + (sp54.z * sp54.z);
    if (!(fabsf(temp_fv1) < 0.008f)) {
        temp_fa1_2 = ((2.0f * sp54.x) * sp6C.x) + ((2.0f * sp54.z) * sp6C.z);
        if ((temp_fa1_2 * temp_fa1_2) < ((4.0f * temp_fv1) * temp_fa0)) {
            return 0;
        }
        if (((temp_fa1_2 * temp_fa1_2) - ((4.0f * temp_fv1) * temp_fa0)) > new_var2) {
            var_v1_2 = var_v0_2 = 1;
        } else {
            var_v1_2 = 1;
            var_v0_2 = 0;
        }
        temp_fv0_2 = sqrtf((temp_fa1_2 * temp_fa1_2) - ((4.0f * temp_fv1) * temp_fa0));
        if (var_v1_2 == 1) {
            var_ft4_real = (temp_fv0_2 - temp_fa1_2) / (2.0f * temp_fv1);
        }
        if (var_v0_2 == 1) {
            sp4C = ((-temp_fa1_2) - temp_fv0_2) / (2.0f * temp_fv1);
        }
    } else if (!(fabsf(((2.0f * sp54.x) * sp6C.x) + ((2.0f * sp54.z) * sp6C.z)) < 0.008f)) {
        var_v1_2 = 1;
        var_v0_2 = 0;
        var_ft4_real = (-temp_fa0) / (((2.0f * sp54.x) * sp6C.x) + ((2.0f * sp54.z) * sp6C.z));
    } else {
        if (temp_fa0 <= 0.0f) {
            var_a0 = (sp6C.y > 0.0f) && (sp6C.y < arg1);
            var_a0_2 = (sp60.y > 0.0f) && (sp60.y < arg1);
            if ((var_a0 != 0) && (var_a0_2 != 0)) {
                *arg6_out = sp6C;
                *arg7_out = sp60;
                return 2;
            }
            if (var_a0 != 0) {
                *arg6_out = sp6C;
                return 1;
            }
            if (var_a0_2 != 0) {
                *arg6_out = sp60;
                return 1;
            }
        }
        return 0;
    }
    {
        if (var_v0_2 == 0) {
            if ((var_ft4_real < 0.0f) || (var_ft4_real > 1.0f)) {
                return 0;
            }
        } else {
            var_a0 = (var_ft4_real < 0.0f) || (var_ft4_real > 1.0f);
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
            arg6_out->x = ((var_ft4_real * sp54.x) + sp6C.x) + arg3->x;
            arg6_out->y = ((var_ft4_real * sp54.y) + sp6C.y) + arg3->y;
            arg6_out->z = ((var_ft4_real * sp54.z) + sp6C.z) + arg3->z;
            arg7_out->x = ((sp4C * sp54.x) + sp6C.x) + arg3->x;
            arg7_out->y = ((sp4C * sp54.y) + sp6C.y) + arg3->y;
            arg7_out->z = ((sp4C * sp54.z) + sp6C.z) + arg3->z;
            return 2;
        }
        if (var_v1_2 == 1) {
            arg6_out->x = ((var_ft4_real * sp54.x) + sp6C.x) + arg3->x;
            arg6_out->y = ((var_ft4_real * sp54.y) + sp6C.y) + arg3->y;
            arg6_out->z = ((var_ft4_real * sp54.z) + sp6C.z) + arg3->z;
            return 1;
        }
        if (var_v0_2 == 1) {
            arg6_out->x = ((sp4C * sp54.x) + sp6C.x) + arg3->x;
            arg6_out->y = ((sp4C * sp54.y) + sp6C.y) + arg3->y;
            arg6_out->z = ((sp4C * sp54.z) + sp6C.z) + arg3->z;
            return 1;
        }
        return 1;
    }
}

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
