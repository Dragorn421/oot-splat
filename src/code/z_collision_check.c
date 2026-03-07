#include <ultra64.h>
#include <global.h>

void func_8005B280(GraphicsContext* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {
    func_8005B2AC(arg0, arg1, arg2, arg3, 0xFFU, 0U, 0U);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005B2AC.s")

typedef struct struct_8011DE00 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} struct_8011DE00;

extern struct_8011DE00 D_8011DE00;

s32 func_8005B65C(GlobalContext* arg0, struct_8011DE00* arg1) {
    *arg1 = D_8011DE00;
    return 1;
}

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

s32 func_8005B6B0(s32 arg0, struct_8005B6B0_arg1* arg1, struct_8005B6B0_arg2* arg2) {
    arg1->unk0 = arg2->unk0;
    arg1->unk10 = arg2->unk4;
    arg1->unk11 = arg2->unk5;
    arg1->unk12 = arg2->unk6;
    arg1->unk13 = 0x10;
    arg1->unk15 = arg2->unk7;
    return 1;
}

s32 func_8005B6EC(GlobalContext* globalCtx, Collider* collision, Actor* actor, ColliderBodyInfo* src) {
    collision->actor = actor;
    collision->unk_14 = src->unk_00;
    collision->colliderFlags = src->colliderFlags;
    collision->collideFlags = src->collideFlags;
    collision->maskA = src->maskA;
    collision->maskB = 0x10;
    collision->type = src->maskB;
    return 1;
}

s32 func_8005B72C(GlobalContext* globalCtx, Collider* collision, Actor* actor, ColliderBodyInfo* src) {
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
} struct_8011DE18;

extern struct_8011DE18 D_8011DE18;

s32 func_8005B7C0(s32 arg0, struct_8011DE18* arg1) {
    *arg1 = D_8011DE18;
    return 1;
}

s32 func_8005B7E4(GlobalContext* globalCtx, ColliderTouch* touch) {
    return 1;
}

typedef struct struct_8005B7F4_arg1 {
    s32 unk0;
    u8 unk4;
    u8 unk5;
} struct_8005B7F4_arg1;

typedef struct struct_8005B7F4_arg2 {
    s32 unk0;
    u8 unk4;
    u8 unk5;
} struct_8005B7F4_arg2;

s32 func_8005B7F4(s32 arg0, struct_8005B7F4_arg1* arg1, struct_8005B7F4_arg2* arg2) {
    arg1->unk0 = (s32)arg2->unk0;
    arg1->unk4 = (u8)arg2->unk4;
    arg1->unk5 = (u8)arg2->unk5;
    return 1;
}

void func_8005B818(GlobalContext* globalCtx, ColliderBody* body) {
}

typedef struct struct_8011DE20 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} struct_8011DE20;

extern struct_8011DE20 D_8011DE20;

s32 func_8005B824(s32 arg0, struct_8011DE20* arg1) {
    *arg1 = D_8011DE20;
    return 1;
}

s32 func_8005B850(GlobalContext* globalCtx, ColliderBump* bump) {
    return 1;
}

typedef struct struct_8005B860_arg1 {
    s32 unk0;
    u8 unk4;
    u8 unk5;
} struct_8005B860_arg1;

typedef struct struct_8005B860_arg2 {
    s32 unk0;
    u8 unk4;
    u8 unk5;
} struct_8005B860_arg2;

s32 func_8005B860(s32 arg0, struct_8005B860_arg1* arg1, struct_8005B860_arg2* arg2) {
    arg1->unk0 = (s32)arg2->unk0;
    arg1->unk4 = (u8)arg2->unk4;
    arg1->unk5 = (u8)arg2->unk5;
    return 1;
}

typedef struct struct_8011DE2C {
    struct_8011DE18 unk0;
    struct_8011DE20 unk8;
    char unk_14[0x14];
} struct_8011DE2C;

extern struct_8011DE2C D_8011DE2C;

s32 func_8005B884(GlobalContext* arg0, struct_8011DE2C* arg1) {
    *arg1 = D_8011DE2C;
    func_8005B7C0(arg0, &arg1->unk0);
    func_8005B824(arg0, &arg1->unk8);
    return 1;
}

s32 func_8005B904(GlobalContext* globalCtx, ColliderBody* body) {
    func_8005B7E4(globalCtx, &body->toucher);
    func_8005B850(globalCtx, &body->bumper);
    return 1;
}

s32 func_8005B93C(GlobalContext* globalCtx, ColliderBody* body, ColliderBodyInfoInner* bodyInfoInner) {
    body->flags = bodyInfoInner->bodyFlags;
    func_8005B7F4(globalCtx, &body->toucher, &bodyInfoInner->toucherMask);
    func_8005B860(globalCtx, &body->bumper, &bodyInfoInner->bumperMask);
    body->toucherFlags = bodyInfoInner->toucherFlags;
    body->bumperFlags = bodyInfoInner->bumperFlags;
    body->flags2 = bodyInfoInner->bodyFlags2;
    return 1;
}

void func_8005B9B0(GlobalContext* globalCtx, ColliderBody* body) {
    body->unk_18 = 0;
    body->unk_20 = 0;
    body->toucherFlags &= ~0x2;
    body->toucherFlags &= ~0x40;
    func_8005B818(globalCtx, body);
}

void func_8005B9E8(GlobalContext* globalCtx, ColliderBody* body) {
    body->bumper.unk_0A = 0;
    body->bumperFlags &= ~0x2;
    body->bumperFlags &= ~0x80;
    body->colBuf = NULL;
    body->colliding = NULL;
    body->bumper.unk_08 = body->bumper.unk_0A;
    body->bumper.unk_06 = body->bumper.unk_0A;
}

void func_8005BA1C(GlobalContext* globalCtx, ColliderBody* body) {
    body->flags2 &= ~0x2;
}

typedef struct struct_8011DE54 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} struct_8011DE54;

extern struct_8011DE54 D_8011DE54;

s32 func_8005BA30(s32 arg0, struct_8011DE54* arg1) {
    *arg1 = D_8011DE54;
    return 1;
}

s32 func_8005BA74(UNK_TYPE arg0, UNK_TYPE arg1) {
    return 1;
}

typedef struct struct_8005BA84_arg1_sub {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} struct_8005BA84_arg1_sub;

typedef struct struct_8005BA84_arg1 {
    struct_8005BA84_arg1_sub unk0;
    char unk_8[8];
    f32 unk10;
    u8 unk14;
} struct_8005BA84_arg1;

typedef struct struct_8005BA84_arg2 {
    u8 unk0;
    struct_8005BA84_arg1_sub unk2;
    s16 unkA;
} struct_8005BA84_arg2;

s32 func_8005BA84(s32 arg0, struct_8005BA84_arg1* arg1, struct_8005BA84_arg2* arg2) {
    arg1->unk14 = (u8)arg2->unk0;
    arg1->unk0 = arg2->unk2;
    arg1->unk10 = (f32)((f32)arg2->unkA * 0.01f);
    return 1;
}

typedef struct struct_8005BAD8 {
    struct_8011DE2C unk0;
    struct_8011DE54 unk28;
} struct_8005BAD8;

s32 func_8005BAD8(s32 arg0, struct_8005BAD8* arg1) {
    func_8005B884(arg0, &arg1->unk0);
    func_8005BA30(arg0, &arg1->unk28);
    return 1;
}

typedef struct struct_8005BB10_sub {
    char unk_0[1];
} struct_8005BB10_sub;

typedef struct struct_8005BB10 {
    ColliderBody unk0;
    struct_8005BB10_sub unk28;
} struct_8005BB10;

s32 func_8005BB10(GlobalContext* arg0, struct_8005BB10* arg1) {
    func_8005B904(arg0, &arg1->unk0);
    func_8005BA74((s32)arg0, &arg1->unk28);
    return 1;
}

typedef struct struct_8005BB48_arg1 {
    ColliderBody unk0;
    struct_8005BA84_arg1 unk28;
} struct_8005BB48_arg1;

typedef struct struct_8005BB48_arg2 {
    ColliderBodyInfoInner unk0;
    struct_8005BA84_arg2 unk18;
} struct_8005BB48_arg2;

s32 func_8005BB48(GlobalContext* arg0, struct_8005BB48_arg1* arg1, struct_8005BB48_arg2* arg2) {
    func_8005B93C(arg0, &arg1->unk0, &arg2->unk0);
    func_8005BA84((s32)arg0, &arg1->unk28, &arg2->unk18);
    return 1;
}

s32 func_8005BB8C(GlobalContext* arg0, ColliderBody* arg1) {
    func_8005B9B0(arg0, arg1);
    return 1;
}

s32 func_8005BBB0(GlobalContext* arg0, ColliderBody* arg1) {
    func_8005B9E8(arg0, arg1);
    return 1;
}

s32 func_8005BBD4(GlobalContext* arg0, ColliderBody* arg1) {
    func_8005BA1C(arg0, arg1);
    return 1;
}

typedef struct struct_8005BBF8 {
    struct_8011DE00 unk0;
    s32 unk18;
    s32 unk1C;
} struct_8005BBF8;

s32 func_8005BBF8(s32 arg0, struct_8005BBF8* arg1) {
    func_8005B65C(arg0, &arg1->unk0);
    arg1->unk18 = 0;
    arg1->unk1C = 0;
    return 1;
}

typedef struct struct_8005BC28 {
    Collider unk0;
    s32 unk18;
    void* unk1C;
} struct_8005BC28;

s32 func_8005BC28(GlobalContext* arg0, struct_8005BC28* arg1) {
    u32 temp_a0;
    u32 var_s0;

    func_8005B6A0(arg0, &arg1->unk0);
    temp_a0 = arg1->unk1C;
    var_s0 = temp_a0;
    if (var_s0 < (u32)((char*)arg1->unk1C + (arg1->unk18 << 6))) {
        do {
            func_8005BB10(arg0, (struct_8005BB10*)var_s0);
            var_s0 += 0x40;
        } while (var_s0 < (u32)((char*)arg1->unk1C + (arg1->unk18 << 6)));
    }
    arg1->unk18 = 0;
    if ((void*)arg1->unk1C != NULL) {
        ZeldaArena_FreeDebug((void*)arg1->unk1C, "../z_collision_check.c", 0x571);
    }
    arg1->unk1C = 0U;
    return 1;
}

typedef struct struct_8005BCC8 {
    Collider unk0;
    u32 unk18;
    u32 unk1C;
} struct_8005BCC8;

s32 func_8005BCC8(GlobalContext* arg0, struct_8005BCC8* arg1) {
    u32 var_s0;

    func_8005B6A0(arg0, &arg1->unk0);
    var_s0 = arg1->unk1C;
    if (var_s0 < (u32)(arg1->unk1C + (arg1->unk18 << 6))) {
        do {
            func_8005BB10(arg0, (struct_8005BB10*)var_s0);
            var_s0 += 0x40;
        } while (var_s0 < (u32)(arg1->unk1C + (arg1->unk18 << 6)));
    }
    arg1->unk18 = 0;
    arg1->unk1C = 0U;
    return 1;
}

typedef struct struct_8005BD50_arg1 {
    struct_8005B6B0_arg1 unk0;
    s32 unk18;
    s32 unk1C;
} struct_8005BD50_arg1;

typedef struct struct_8005BD50_arg2 {
    struct_8005B6B0_arg2 unk0;
    s32 unk8;
    s32 unkC;
} struct_8005BD50_arg2;

s32 func_8005BD50(GlobalContext* arg0, struct_8005BD50_arg1* arg1, struct_8005BD50_arg2* arg2) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    func_8005B6B0((s32)arg0, &arg1->unk0, &arg2->unk0);
    arg1->unk18 = arg2->unk8;
    temp_v0 = ZeldaArena_MallocDebug(arg2->unk8 << 6, "../z_collision_check.c", 0x5A3);
    arg1->unk1C = temp_v0;
    if (temp_v0 == 0) {
        arg1->unk18 = 0;
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjJntSph_set():zelda_malloc()出来ません。\n");
        osSyncPrintf("\x1b[m");
        return 0;
    }
    var_s0 = arg1->unk1C;
    var_s1 = arg2->unkC;
    if ((u32)var_s0 < (u32)(var_s0 + (arg1->unk18 << 6))) {
        do {
            func_8005BAD8((s32)arg0, (struct_8005BAD8*)var_s0);
            func_8005BB48(arg0, (struct_8005BB48_arg1*)var_s0, (struct_8005BB48_arg2*)var_s1);
            var_s0 += 0x40;
            var_s1 += 0x24;
        } while ((u32)var_s0 < (u32)(arg1->unk1C + (arg1->unk18 << 6)));
    }
    return 1;
}

typedef struct struct_8005BE50_arg1 {
    Collider unk0;
    s32 unk18;
    s32 unk1C;
} struct_8005BE50_arg1;

typedef struct struct_8005BE50_arg3 {
    ColliderBodyInfo unk0;
    s32 unk8;
    s32 unkC;
} struct_8005BE50_arg3;

s32 func_8005BE50(GlobalContext* arg0, struct_8005BE50_arg1* arg1, Actor* arg2, struct_8005BE50_arg3* arg3) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    func_8005B6EC(arg0, &arg1->unk0, arg2, &arg3->unk0);
    arg1->unk18 = arg3->unk8;
    temp_v0 = ZeldaArena_MallocDebug(arg3->unk8 << 6, "../z_collision_check.c", 0x5D2);
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
    if ((u32)var_s0 < (u32)(var_s0 + (arg1->unk18 << 6))) {
        do {
            func_8005BAD8((s32)arg0, (struct_8005BAD8*)var_s0);
            func_8005BB48(arg0, (struct_8005BB48_arg1*)var_s0, (struct_8005BB48_arg2*)var_s1);
            var_s0 += 0x40;
            var_s1 += 0x24;
        } while ((u32)var_s0 < (u32)(arg1->unk1C + (arg1->unk18 << 6)));
    }
    return 1;
}

typedef struct struct_8005BF50_arg1 {
    Collider unk0;
    s32 unk18;
    s32 unk1C;
} struct_8005BF50_arg1;

typedef struct struct_8005BF50_arg3 {
    ColliderBodyInfo unk0;
    s32 unk8;
    s32 unkC;
} struct_8005BF50_arg3;

s32 func_8005BF50(GlobalContext* arg0, struct_8005BF50_arg1* arg1, Actor* arg2, struct_8005BF50_arg3* arg3) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    func_8005B72C(arg0, &arg1->unk0, arg2, &arg3->unk0);
    arg1->unk18 = arg3->unk8;
    temp_v0 = ZeldaArena_MallocDebug(arg3->unk8 << 6, "../z_collision_check.c", 0x60F);
    arg1->unk1C = temp_v0;
    if (temp_v0 == 0) {
        arg1->unk18 = 0;
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjJntSph_set5():zelda_malloc出来ません\n");
        osSyncPrintf("\x1b[m");
        return 0;
    }
    var_s0 = arg1->unk1C;
    var_s1 = arg3->unkC;
    if ((u32)var_s0 < (u32)(var_s0 + (arg1->unk18 << 6))) {
        do {
            func_8005BAD8((s32)arg0, (struct_8005BAD8*)var_s0);
            func_8005BB48(arg0, (struct_8005BB48_arg1*)var_s0, (struct_8005BB48_arg2*)var_s1);
            var_s0 += 0x40;
            var_s1 += 0x24;
        } while ((u32)var_s0 < (u32)(arg1->unk1C + (arg1->unk18 << 6)));
    }
    return 1;
}

typedef struct struct_8005C050_arg1 {
    Collider unk0;
    s32 unk18;
    struct_8005BB48_arg1* unk1C;
} struct_8005C050_arg1;

typedef struct struct_8005C050_arg3 {
    ColliderBodyInfo unk0;
    s32 unk8;
    struct_8005BB48_arg2* unkC;
} struct_8005C050_arg3;

s32 func_8005C050(GlobalContext* globalCtx, struct_8005C050_arg1* collision, Actor* actor, struct_8005C050_arg3* arg3,
                  s32 arg4) {
    struct_8005BB48_arg1* var_s0;
    struct_8005BB48_arg2* var_s1;

    func_8005B72C(globalCtx, &collision->unk0, actor, &arg3->unk0);
    collision->unk18 = arg3->unk8;
    collision->unk1C = arg4;
    if (arg4 == 0) {
        func_80001FF0("pclobj_jntsph->elem_tbl != NULL", "../z_collision_check.c", 0x643);
    }
    var_s0 = collision->unk1C;
    var_s1 = arg3->unkC;
    while (var_s0 < (collision->unk1C + (collision->unk18))) {
        func_8005BAD8((s32)globalCtx, (struct_8005BAD8*)var_s0);
        func_8005BB48(globalCtx, var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

typedef struct struct_8005C124_arg1 {
    Collider unk0;
    s32 unk18;
    s32 unk1C;
} struct_8005C124_arg1;

s32 func_8005C124(GlobalContext* arg0, struct_8005C124_arg1* arg1) {
    struct_8005C124_arg1* new_var;
    s32 var_s0;

    new_var = arg1;
    func_8005B76C(arg0, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (((u32)var_s0) < ((u32)(new_var->unk1C + (new_var->unk18 << 6)))) {
        func_8005BB8C(arg0, (ColliderBody*)var_s0);
        var_s0 += 0x40;
    }

    return 1;
}

typedef struct struct_8005C1AC {
    Collider unk0;
    s32 unk18;
    s32 unk1C;
} struct_8005C1AC;

s32 func_8005C1AC(GlobalContext* arg0, struct_8005C1AC* arg1) {
    struct_8005C1AC* new_var;
    s32 var_s0;

    new_var = arg1;
    func_8005B784(arg0, &arg1->unk0);
    var_s0 = new_var->unk1C;
    if ((u32)var_s0 < (u32)(var_s0 + (new_var->unk18 << 6))) {
        do {
            func_8005BBB0(arg0, (ColliderBody*)var_s0);
            var_s0 += 0x40;
        } while ((u32)var_s0 < (u32)(new_var->unk1C + (new_var->unk18 << 6)));
    }
    return 1;
}

typedef struct struct_8005C234 {
    Collider unk0;
    s32 unk18;
    s32 unk1C;
} struct_8005C234;

s32 func_8005C234(GlobalContext* arg0, struct_8005C234* arg1) {
    struct_8005C234* new_var;
    s32 var_s0;

    new_var = arg1;
    func_8005B79C(arg0, &arg1->unk0);
    var_s0 = new_var->unk1C;
    if ((u32)var_s0 < (u32)(var_s0 + (new_var->unk18 << 6))) {
        do {
            func_8005BBD4(arg0, (ColliderBody*)var_s0);
            var_s0 += 0x40;
        } while ((u32)var_s0 < (u32)(new_var->unk1C + (new_var->unk18 << 6)));
    }
    return 1;
}

typedef struct struct_8011DE6C {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} struct_8011DE6C;

extern struct_8011DE6C D_8011DE6C;

s32 func_8005C2BC(s32 arg0, struct_8011DE6C* arg1) {
    struct_8011DE6C sp4;

    sp4 = D_8011DE6C;
    *arg1 = sp4;
    return 1;
}

s32 func_8005C318(GlobalContext* globalCtx, ColliderDimensions* dim) {
    return 1;
}

s32 func_8005C328(GlobalContext* globalCtx, ColliderDimensions* dest, ColliderDimensions* src) {
    *dest = *src;
    return 1;
}

s32 ActorCollider_AllocCylinder(GlobalContext* globalCtx, ColliderCylinderMain* collision) {
    func_8005B65C(globalCtx, &collision->base);
    func_8005B884(globalCtx, &collision->body);
    func_8005C2BC(globalCtx, &collision->dim);
    return 1;
}

s32 ActorCollider_FreeCylinder(GlobalContext* globalCtx, ColliderCylinderMain* collision) {
    func_8005B6A0(globalCtx, &collision->base);
    func_8005B904(globalCtx, &collision->body);
    func_8005C318(globalCtx, &collision->dim);
    return 1;
}

s32 func_8005C3F4(GlobalContext* globalCtx, ColliderCylinderMain* collision, ColliderCylinderInit* src) {
    func_8005B6B0(globalCtx, &collision->base, &src->body);
    func_8005B93C(globalCtx, &collision->body, &src->inner);
    func_8005C328(globalCtx, &collision->dim, &src->dim);
    return 1;
}

s32 func_8005C450(GlobalContext* globalCtx, ColliderCylinderMain* collision, Actor* actor, ColliderCylinderInit* src) {
    func_8005B6EC(globalCtx, &collision->base, actor, &src->body);
    func_8005B93C(globalCtx, &collision->body, &src->inner);
    func_8005C328(globalCtx, &collision->dim, &src->dim);
    return 1;
}

s32 ActorCollider_InitCylinder(GlobalContext* globalCtx, ColliderCylinderMain* collision, Actor* actor,
                               ColliderCylinderInit* src) {
    func_8005B72C(globalCtx, &collision->base, actor, &src->body);
    func_8005B93C(globalCtx, &collision->body, &src->inner);
    func_8005C328(globalCtx, &collision->dim, &src->dim);
    return 1;
}

s32 func_8005C508(GlobalContext* globalCtx, ColliderCylinderMain* collision) {
    func_8005B76C(globalCtx, &collision->base);
    func_8005B9B0(globalCtx, &collision->body);
    return 1;
}

s32 func_8005C540(GlobalContext* globalCtx, ColliderCylinderMain* collision) {
    func_8005B784(globalCtx, &collision->base);
    func_8005B9E8(globalCtx, &collision->body);
    return 1;
}

s32 func_8005C578(GlobalContext* globalCtx, ColliderCylinderMain* collision) {
    func_8005B79C(globalCtx, &collision->base);
    func_8005BA1C(globalCtx, &collision->body);
    return 1;
}

typedef struct struct_8011DE78 {
    s32 unk0[0x34 / 4];
} struct_8011DE78;

extern struct_8011DE78 D_8011DE78;

s32 func_8005C5B0(s32 arg0, struct_8011DE78* arg1) {
    *arg1 = D_8011DE78;
    return 1;
}

s32 func_8005C5F8(UNK_TYPE arg0, UNK_TYPE arg1) {
    return 1;
}

typedef struct struct_8005C608_arg1 {
    /* 0x00 */ Vec3f unk0[3];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
} struct_8005C608_arg1;

s32 func_8005C608(s32 arg0, struct_8005C608_arg1* arg1, Vec3f* arg2) {
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
    struct_8011DE2C unk0;
    struct_8011DE78 unk28;
} struct_8005C6C0;

s32 func_8005C6C0(s32 arg0, struct_8005C6C0* arg1) {
    func_8005B884(arg0, &arg1->unk0);
    func_8005C5B0(arg0, &arg1->unk28);
    return 1;
}

typedef struct struct_8005C6F8 {
    ColliderBody unk0;
    char unk_28[0x5C - 0x28];
} struct_8005C6F8;

s32 func_8005C6F8(GlobalContext* arg0, struct_8005C6F8* arg1) {
    func_8005B904(arg0, &arg1->unk0);
    func_8005C5F8((s32)arg0, arg1->unk_28);
    return 1;
}

typedef struct struct_8005C730_arg1 {
    ColliderBody unk0;
    struct_8005C608_arg1 unk28;
} struct_8005C730_arg1;

typedef struct struct_8005C730_arg2 {
    ColliderBodyInfoInner unk0;
    Vec3f unk18;
    char unk_24[0x18];
} struct_8005C730_arg2;

s32 func_8005C730(GlobalContext* arg0, struct_8005C730_arg1* arg1, struct_8005C730_arg2* arg2) {
    func_8005B93C(arg0, &arg1->unk0, &arg2->unk0);
    func_8005C608((s32)arg0, &arg1->unk28, &arg2->unk18);
    return 1;
}

s32 func_8005C774(GlobalContext* arg0, ColliderBody* arg1) {
    func_8005B9B0(arg0, arg1);
    return 1;
}

s32 func_8005C798(GlobalContext* arg0, ColliderBody* arg1) {
    func_8005B9E8(arg0, arg1);
    return 1;
}

s32 func_8005C7BC(GlobalContext* arg0, ColliderBody* arg1) {
    func_8005BA1C(arg0, arg1);
    return 1;
}

typedef struct struct_8005C7E0 {
    struct_8011DE00 unk0;
    s32 unk18;
    s32 unk1C;
} struct_8005C7E0;

s32 func_8005C7E0(s32 arg0, struct_8005C7E0* arg1) {
    func_8005B65C(arg0, &arg1->unk0);
    arg1->unk18 = 0;
    arg1->unk1C = 0;
    return 1;
}

typedef struct struct_8005C810 {
    Collider unk0;
    s32 unk18;
    struct_8005C6F8* unk1C;
} struct_8005C810;

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
    ColliderBodyInfo unk0;
    s32 unk8;
    struct_8005C730_arg2* unkC;
} struct_8005C964_arg3;

s32 func_8005C964(GlobalContext* arg0, struct_8005C964_arg1* arg1, Actor* arg2, struct_8005C964_arg3* arg3) {
    struct_8005C6C0* var_s0;
    struct_8005C730_arg2* var_s1;

    func_8005B6EC(arg0, &arg1->unk0, arg2, &arg3->unk0);
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
        func_8005C6C0((s32)arg0, var_s0);
        func_8005C730(arg0, (struct_8005C730_arg1*)var_s0, var_s1);
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
    ColliderBodyInfo unk0;
    s32 unk8;
    struct_8005C730_arg2* unkC;
} struct_8005CA88_arg3;

s32 func_8005CA88(GlobalContext* arg0, struct_8005CA88_arg1* arg1, Actor* arg2, struct_8005CA88_arg3* arg3) {
    struct_8005C6C0* temp_v0;
    struct_8005C6C0* var_s0;
    struct_8005C730_arg2* var_s1;

    func_8005B72C(arg0, &arg1->unk0, arg2, &arg3->unk0);
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
        func_8005C6C0((s32)arg0, var_s0);
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
    ColliderBodyInfo unk0;
    s32 unk8;
    struct_8005C730_arg2* unkC;
} struct_8005CBAC_arg3;

s32 func_8005CBAC(GlobalContext* arg0, struct_8005CBAC_arg1* arg1, Actor* arg2, struct_8005CBAC_arg3* arg3, u32 arg4) {
    struct_8005C6C0* var_s0;
    struct_8005C730_arg2* var_s1;

    func_8005B72C(arg0, &arg1->unk0, arg2, &arg3->unk0);
    arg1->unk18 = arg3->unk8;
    arg1->unk1C = (struct_8005C6C0*)arg4;
    if (arg1->unk1C == 0) {
        func_80001FF0("pclobj_tris->elem_tbl != NULL", "../z_collision_check.c", 0x8D2);
    }
    var_s0 = arg1->unk1C;
    var_s1 = arg3->unkC;
    while (var_s0 < &arg1->unk1C[arg1->unk18]) {
        func_8005C6C0((s32)arg0, var_s0);
        func_8005C730(arg0, (struct_8005C730_arg1*)var_s0, var_s1);
        var_s0++;
        var_s1++;
    }
    return 1;
}

typedef struct struct_8005CC98_ptr {
    char unk_0[0x5C];
} struct_8005CC98_ptr;

typedef struct struct_8005CC98 {
    Collider unk0;
    s32 unk18;
    struct_8005CC98_ptr* unk1C;
} struct_8005CC98;

s32 func_8005CC98(GlobalContext* arg0, struct_8005CC98* arg1) {
    struct_8005CC98_ptr* var_s0;
    struct_8005CC98* new_var;

    new_var = arg1;
    func_8005B76C(arg0, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (((u32)var_s0) < ((u32)(new_var->unk1C + new_var->unk18))) {
        func_8005C774(arg0, var_s0);
        var_s0++;
    }
    return 1;
}

typedef struct struct_8005CD34_ptr {
    char unk_0[0x5C];
} struct_8005CD34_ptr;

typedef struct struct_8005CD34 {
    Collider unk0;
    s32 unk18;
    struct_8005CD34_ptr* unk1C;
} struct_8005CD34;

s32 func_8005CD34(GlobalContext* arg0, struct_8005CD34* arg1) {
    struct_8005CD34_ptr* var_s0;
    struct_8005CD34* new_var;

    new_var = arg1;
    func_8005B784(arg0, &new_var->unk0);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005C798(arg0, (ColliderBody*)var_s0);
        var_s0++;
    }
    return 1;
}

typedef struct struct_8005CDD0_ptr {
    char unk_0[0x5C];
} struct_8005CDD0_ptr;

typedef struct struct_8005CDD0 {
    Collider unk0;
    s32 unk18;
    struct_8005CDD0_ptr* unk1C;
} struct_8005CDD0;

s32 func_8005CDD0(GlobalContext* arg0, struct_8005CDD0* arg1) {
    struct_8005CDD0* new_var;
    struct_8005CDD0_ptr* var_s0;

    new_var = arg1;
    func_8005B79C(arg0, new_var);
    var_s0 = new_var->unk1C;
    while (var_s0 < (new_var->unk1C + new_var->unk18)) {
        func_8005C7BC(arg0, (ColliderBody*)var_s0);
        var_s0++;
    }
    return 1;
}

typedef struct struct_8011DEAC {
    s32 unk_0[0x40 / 4];
} struct_8011DEAC;

extern struct_8011DEAC D_8011DEAC;

s32 func_8005CE6C(GlobalContext* arg0, struct_8011DEAC* arg1) {
    *arg1 = D_8011DEAC;
    return 1;
}

s32 func_8005CEB4(GlobalContext* globalCtx, ColliderDimensions* dim) {
    return 1;
}

typedef struct struct_8005CEC4 {
    char unk_0[0x3C];
    f32 unk3C;
} struct_8005CEC4;

s32 func_8005CEC4(s32 arg0, struct_8005CEC4* arg1) {
    arg1->unk3C = 1e38f;
    return 1;
}

typedef struct struct_8005CEDC {
    /* 0x00 */ Vec3f unk0;
    /* 0x0C */ Vec3f unkC;
    /* 0x18 */ Vec3f unk18;
    /* 0x24 */ Vec3f unk24;
    /* 0x30 */ Vec3s unk30;
    /* 0x36 */ Vec3s unk36;
} struct_8005CEDC;

void func_8005CEDC(struct_8005CEDC* arg0) {
    arg0->unk30.x = (s16)(s32)((arg0->unk18.x + arg0->unk24.x) * 0.5f);
    arg0->unk30.y = (s16)(s32)((arg0->unk18.y + arg0->unk24.y) * 0.5f);
    arg0->unk30.z = (s16)(s32)((arg0->unk18.z + arg0->unk24.z) * 0.5f);
    arg0->unk36.x = (s16)(s32)((arg0->unk0.x + arg0->unkC.x) * 0.5f);
    arg0->unk36.y = (s16)(s32)((arg0->unk0.y + arg0->unkC.y) * 0.5f);
    arg0->unk36.z = (s16)(s32)((arg0->unk0.z + arg0->unkC.z) * 0.5f);
}

s32 func_8005CF90(s32 arg0, struct_8005CEDC* arg1, Vec3f* arg2) {
    arg1->unk0 = arg2[0];
    arg1->unkC = arg2[1];
    arg1->unk18 = arg2[2];
    arg1->unk24 = arg2[3];
    func_8005CEDC(arg1);
    return 1;
}

s32 func_8005D018(GlobalContext* globalCtx, ColliderCylinderMain* collision) {
    func_8005B65C(globalCtx, &collision->base);
    func_8005B884(globalCtx, &collision->body);
    func_8005CE6C(globalCtx, &collision->dim);
    return 1;
}

s32 func_8005D060(GlobalContext* globalCtx, ColliderCylinderMain* collision) {
    func_8005B6A0(globalCtx, &collision->base);
    func_8005B904(globalCtx, &collision->body);
    func_8005CEB4(globalCtx, &collision->dim);
    return 1;
}

s32 func_8005D0A8(GlobalContext* globalCtx, ColliderCylinderMain* collision, Actor* actor, ColliderCylinderInit* src) {
    func_8005B6EC(globalCtx, &collision->base, actor, &src->body);
    func_8005B93C(globalCtx, &collision->body, &src->inner);
    func_8005CF90(globalCtx, &collision->dim, &src->dim);
    return 1;
}

s32 func_8005D104(GlobalContext* globalCtx, ColliderCylinderMain* collision, Actor* actor, ColliderCylinderInit* src) {
    func_8005B72C(globalCtx, &collision->base, actor, &src->body);
    func_8005B93C(globalCtx, &collision->body, &src->inner);
    func_8005CF90(globalCtx, &collision->dim, &src->dim);
    return 1;
}

s32 func_8005D160(GlobalContext* globalCtx, ColliderCylinderMain* collision) {
    func_8005B76C(globalCtx, &collision->base);
    func_8005B9B0(globalCtx, &collision->body);
    func_8005CEC4(globalCtx, &collision->dim);
    return 1;
}

s32 func_8005D1A8(GlobalContext* globalCtx, ColliderCylinderMain* collision) {
    func_8005B784(globalCtx, &collision->base);
    func_8005B9E8(globalCtx, &collision->body);
    return 1;
}

s32 func_8005D1E0(GlobalContext* globalCtx, ColliderCylinderMain* collision) {
    func_8005B79C(globalCtx, &collision->base);
    func_8005BA1C(globalCtx, &collision->body);
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

s32 func_8005D3A4(s32 arg0, struct_8005D3A4* arg1) {
    arg1->unk18 = (u16)(arg1->unk18 & 0xFFFE);
    return 1;
}

typedef struct struct_8005D40C {
    s16 unk0;
    u16 unk2;
    s32 unk4[0xC8 / 4];
    s32 unkCC;
    s32 unkD0[(0x1C0 - 0xD0) / 4];
    s32 unk1C0;
    s32 unk1C4[(0x28C - 0x1C4) / 4];
    s32 unk28C;
    s32 unk290[0xC / 4];
} struct_8005D40C;

void func_8005D40C(s32 arg0, struct_8005D40C* arg1);

void func_8005D3BC(s32 arg0, struct_8005D40C* arg1) {
    arg1->unk2 = 0;
    func_8005D40C(arg0, arg1);
    gGameInfo->data[0x735] = 1;
    gGameInfo->data[0x736] = 1;
    gGameInfo->data[0x737] = 1;
}

void func_8005D400(GlobalContext* globalCtx, SubGlobalContext11E60* sub_11E60) {
}

void func_8005D40C(s32 arg0, struct_8005D40C* arg1) {
    s32* var_v0;

    if (!(arg1->unk2 & 1)) {
        arg1->unk0 = 0;
        arg1->unkCC = 0;
        arg1->unk1C0 = 0;
        arg1->unk28C = 0;
        // clang-format off
        var_v0 = arg1->unk4; while ((u32)var_v0 < (u32)&arg1->unkCC) {
            // clang-format on
            *var_v0 = 0;
            var_v0++;
        }
        var_v0 = arg1->unkD0;
        while ((u32)var_v0 < (u32)&arg1->unk1C0) {
            *var_v0 = 0;
            var_v0++;
        }
        var_v0 = arg1->unk1C4;
        while ((u32)var_v0 < (u32)&arg1->unk28C) {
            *var_v0 = 0;
            var_v0++;
        }
        var_v0 = arg1->unk290;
        while ((u32)var_v0 < (u32)((s32)arg1 + 0x29C)) {
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
    char unk_0[0x12];
    u8 unk12;
    char unk_13[2];
    u8 unk15;
    char unk_16[2];
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

void func_8005D4DC(GraphicsContext** arg0, struct_8005D4DC* arg1) {
    struct_8005D4DC* new_var;
    s32 var_s0;

    if (arg1 != NULL) {
        switch (arg1->unk15) {
            case 0:
                new_var = arg1;
                var_s0 = 0;
                while (var_s0 < new_var->unk18) {
                    func_800D05D0((s32)arg0, (s32)((s32)&arg1->unk1C.b[var_s0] + 0x30));
                    var_s0 += 1;
                    if (!arg1) {}
                }
                break;

            case 1:
                func_800D05DC((s32)arg0, (s32)&arg1->unk40);
                break;

            case 2:
                new_var = arg1;
                var_s0 = 0;
                while (var_s0 < new_var->unk18) {
                    func_8005B280(*arg0, &arg1->unk1C.a[var_s0].unk28, &arg1->unk1C.a[var_s0].unk34,
                                  &arg1->unk1C.a[var_s0].unk40);
                    var_s0 += 1;
                }
                break;

            case 3:
                func_8005B280(*arg0, &arg1->unk58, &arg1->unk64, &arg1->unk4C);
                func_8005B280(*arg0, &arg1->unk4C, &arg1->unk40, &arg1->unk58);
                break;
        }
    }
}

typedef struct struct_8005D62C {
    s16 unk0;
    struct_8005D4DC* unk4[(0xCC - 4) / 4];
    s32 unkCC;
    struct_8005D4DC* unkD0[(0x1C0 - 0xD0) / 4];
    s32 unk1C0;
    struct_8005D4DC* unk1C4[1];
} struct_8005D62C;

void func_8005D62C(GlobalContext* arg0, struct_8005D62C* arg1) {
    s32 var_s1;

    if (gGameInfo->data[0x72F] != 0) {
        if (gGameInfo->data[0x735] != 0) {
            var_s1 = 0;
            while (var_s1 < arg1->unk0) {
                func_8005D4DC(arg0, arg1->unk4[var_s1]);
                var_s1 += 1;
            }
        }
        if (gGameInfo->data[0x736] != 0) {
            var_s1 = 0;
            while (var_s1 < arg1->unkCC) {
                func_8005D4DC(arg0, arg1->unkD0[var_s1]);
                var_s1 += 1;
            }
        }
        if (gGameInfo->data[0x737] != 0) {
            var_s1 = 0;
            while (var_s1 < arg1->unk1C0) {
                if (arg1->unk1C4[var_s1]->unk12 & 1) {
                    func_8005D4DC(arg0, arg1->unk1C4[var_s1]);
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

typedef void (*callback_8011DEF8)(GlobalContext*, void*);
extern callback_8011DEF8 D_8011DEF8[];

s32 Actor_CollisionCheck_SetAT(GlobalContext* globalCtx, SubGlobalContext11E60* simpleBodyGroups,
                               ColliderCylinderMain* collision) {
    s16 temp_v1;
    Actor* new_var;

    if (1) {}
    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collision->base.type >= 4) {
        func_80001FF0("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xBB5, simpleBodyGroups);
        if (1) {}
    }
    D_8011DEF8[collision->base.type](globalCtx, collision);
    new_var = collision->base.actor;
    if ((new_var != NULL) && (collision->base.actor->update == NULL)) {
        return -1;
    }
    temp_v1 = simpleBodyGroups->unk0;
    if (temp_v1 >= 0x32) {
        osSyncPrintf("CollisionCheck_setAT():インデックスがオーバーして追加不能\n");
        return -1;
    }
    if (simpleBodyGroups->unk2 & 1) {
        return -1;
    }
    simpleBodyGroups->unk4[temp_v1] = collision;
    simpleBodyGroups->unk0 += 1;
    return temp_v1;
}

typedef struct struct_8005D8AC_arg1 {
    /* 0x000 */ s16 unk0;
    /* 0x002 */ u16 unk2;
    void* unk4[UNK_SIZE];
    char unk_8[0xC4]; /* maybe part of unk4[0x32]? */
    /* 0x00CC */ s32 unkCC;
    void* unkD0[UNK_SIZE];
    /* 0x00D4 */ char unk_D4[0xEC];
    /* 0x01C0 */ s32 unk1C0;
    void* unk1C4[UNK_SIZE];
} struct_8005D8AC_arg1;

typedef struct struct_8005D8AC_arg2 {
    /* 0x000 */ void* unk0;
    /* 0x004 */ char pad4[0x11];
    /* 0x015 */ u8 unk15;
} struct_8005D8AC_arg2;

s32 func_8005D8AC(GlobalContext* arg0, struct_8005D8AC_arg1* arg1, struct_8005D8AC_arg2* arg2, s32 arg3) {
    Actor* temp_v1;

    if (arg2->unk15 >= 4) {
        func_80001FF0("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xBDD);
    }
    if (func_800C0D28(arg0) == 1) {
        return -1;
    }
    D_8011DEF8[arg2->unk15](arg0, arg2);
    temp_v1 = arg2->unk0;
    if ((temp_v1 != NULL) && (((Actor*)arg2->unk0)->update == 0)) {
        return -1;
    }
    if (arg1->unk2 & 1) {
        if (arg3 >= arg1->unk0) {
            osSyncPrintf("CollisionCheck_setAT_SAC():全データ数より大きいところに登録しようとしている。\n");
            return -1;
        }
        arg1->unk4[arg3] = arg2;
    } else {
        if (arg1->unk0 >= 0x32) {
            osSyncPrintf("CollisionCheck_setAT():インデックスがオーバーして追加不能\n");
            return -1;
        }
        arg3 = arg1->unk0;
        arg1->unk4[arg1->unk0] = arg2;
        arg1->unk0 += 1;
    }
    return arg3;
}

extern callback_8011DEF8 D_8011DF08[];

s32 Actor_CollisionCheck_SetAC(GlobalContext* globalCtx, SubGlobalContext11E60* simpleBodyGroups,
                               ColliderCylinderMain* collision) {
    Actor* temp_v1_2;
    s32 temp_v1;

    if (1) {}
    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collision->base.type >= 4) {
        func_80001FF0("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xC2A, simpleBodyGroups);
        if (1) {}
    }
    D_8011DF08[collision->base.type](globalCtx, collision);
    temp_v1_2 = collision->base.actor;
    if ((temp_v1_2 != NULL) && (collision->base.actor->update == NULL)) {
        return -1;
    }
    temp_v1 = simpleBodyGroups->unkCC;
    if (temp_v1 >= 0x3C) {
        osSyncPrintf("CollisionCheck_setAC():インデックスがオーバして追加不能\n");
        return -1;
    }
    if (simpleBodyGroups->unk2 & 1) {
        return -1;
    }
    simpleBodyGroups->unkD0[temp_v1] = collision;
    simpleBodyGroups->unkCC += 1;
    return temp_v1;
}

s32 func_8005DB04(GlobalContext* arg0, struct_8005D8AC_arg1* arg1, struct_8005D8AC_arg2* arg2, s32 arg3) {
    Actor* temp_v1;

    if ((s32)arg2->unk15 >= 4) {
        func_80001FF0("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xC51);
    }
    if (func_800C0D28(arg0) == 1) {
        return -1;
    }
    D_8011DF08[arg2->unk15](arg0, arg2);
    temp_v1 = arg2->unk0;
    if ((temp_v1 != NULL) && (((Actor*)arg2->unk0)->update == 0)) {
        return -1;
    }
    if (arg1->unk2 & 1) {
        if (arg3 >= arg1->unkCC) {
            osSyncPrintf("CollisionCheck_setAC_SAC():全データ数より大きいところに登録しようとしている。\n");
            return -1;
        }
        arg1->unkD0[arg3] = arg2;
    } else {
        if (arg1->unkCC >= 0x3C) {
            osSyncPrintf("CollisionCheck_setAC():インデックスがオーバして追加不能\n");
            return -1;
        }
        arg3 = arg1->unkCC;
        arg1->unkD0[arg3] = arg2;
        arg1->unkCC += 1;
    }
    return arg3;
}

extern callback_8011DEF8 D_8011DF18[];

s32 Actor_CollisionCheck_SetOT(GlobalContext* globalCtx, SubGlobalContext11E60* simpleBodyGroups,
                               ColliderCylinderMain* collision) {
    Actor* temp_v1_2;
    s32 temp_v1;

    if (1) {}
    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collision->base.type >= 4) {
        func_80001FF0("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xC9D, simpleBodyGroups);
        if (1) {}
    }
    D_8011DF18[collision->base.type](globalCtx, collision);
    temp_v1_2 = collision->base.actor;
    if ((temp_v1_2 != NULL) && (collision->base.actor->update == NULL)) {
        return -1;
    }
    temp_v1 = simpleBodyGroups->unk1C0;
    if (temp_v1 >= 0x32) {
        osSyncPrintf("CollisionCheck_setOC():インデックスがオーバして追加不能\n");
        return -1;
    }
    if (simpleBodyGroups->unk2 & 1) {
        return -1;
    }
    simpleBodyGroups->unk_1C4[temp_v1] = collision;
    simpleBodyGroups->unk1C0 += 1;
    return temp_v1;
}

s32 func_8005DD5C(GlobalContext* arg0, struct_8005D8AC_arg1* arg1, struct_8005D8AC_arg2* arg2, s32 arg3) {
    Actor* temp_v1;

    if (func_800C0D28(arg0) == 1) {
        return -1;
    }
    if (arg2->unk15 >= 4) {
        func_80001FF0("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xCCA);
        if (1) {}
    }
    D_8011DF18[arg2->unk15](arg0, arg2);
    temp_v1 = arg2->unk0;
    if ((temp_v1 != NULL) && (((Actor*)arg2->unk0)->update == 0)) {
        return -1;
    }
    if (arg1->unk2 & 1) {
        if (arg3 >= arg1->unk1C0) {
            osSyncPrintf("CollisionCheck_setOC_SAC():全データ数より大きいところに登録しようとしている。\n");
            return -1;
        }
        arg1->unk4[arg3] = arg2;
    } else {
        if (arg1->unk1C0 >= 0x32) {
            osSyncPrintf("CollisionCheck_setOC():インデックスがオーバして追加不能\n");
            return -1;
        }
        arg3 = arg1->unk1C0;
        arg1->unk1C4[arg3] = arg2;
        arg1->unk1C0 += 1;
    }
    return arg3;
}

typedef struct struct_8005DE9C {
    char unk_0[0x28C];
    s32 unk28C;
    void* unk_290[UNK_SIZE];
} struct_8005DE9C;

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

typedef struct struct_8005DF2C {
    char unk_0[0x15];
    u8 unk15;
} struct_8005DF2C;

s32 func_8005DF2C(struct_8005DF2C* arg0) {
    if (!(arg0->unk15 & 1)) {
        return 1;
    }
    return 0;
}

typedef struct struct_8005DF50 {
    char unk_0[0x16];
    u8 unk16;
} struct_8005DF50;

s32 func_8005DF50(struct_8005DF50* arg0) {
    if (!(arg0->unk16 & 1)) {
        return 1;
    }
    return 0;
}

typedef struct struct_8005DF74 {
    char unk_0[8];
    s32 unk8;
} struct_8005DF74;

s32 func_8005DF74(s32* arg0, struct_8005DF74* arg1) {
    if (!(*arg0 & arg1->unk8)) {
        return 1;
    }

    return 0;
}

void func_8005DF9C(s32 arg0, s32 arg1, s32 arg2) {
}

typedef struct struct_8015D8A0 {
    /* 0x000 */ Vec3s unk0;
    /* 0x006 */ char unk_2[0x486];
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

extern struct_8015D8A0 D_8015D8A0;

#ifdef NON_MATCHING
void func_8005DFAC(GlobalContext* arg0, s32 arg1, Vec3f* arg2) {
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

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005E10C.s")

void func_8005E26C(s32 arg0, s32 arg1, s32 arg2) {
    func_800299AC(arg0, arg2);
    func_80062B80(arg0, arg2);
}

void func_8005E2A4(s32 arg1, s32 arg2, s32 arg3) {
    func_80062A28(arg1, arg3);
}

void func_8005E2C8(s32 arg1, s32 arg2, s32 arg3) {
    func_80062A28(arg1, arg3);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005E2EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005E4F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005E604.s")

typedef struct struct_8005E800 {
    char unk_0[0x10];
    u8 unk10;
    u8 unk11;
} struct_8005E800;

void func_8005E800(struct_8005E800* arg0, struct_8005E800* arg1) {
    arg0->unk10 |= 4;
    arg1->unk11 |= 0x80;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005E81C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005E9C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005EC6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005EEE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005F17C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005F39C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005F5B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005F7D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005FA30.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005FC04.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005FDCC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005FF90.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80060204.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800604B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80060704.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80060994.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80060C2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80060EBC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80060F94.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061028.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8006110C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800611A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061274.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8006139C.s")

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

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80061F64.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8006216C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062210.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062230.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800622C4.s")

typedef struct sub_struct_800622E4 {
    /* 0x00 */ char unk0[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12[3];
    /* 0x15 */ u8 unk15;
} sub_struct_800622E4;

typedef void (*func_ptr_800622E4)(GlobalContext*, SubGlobalContext11E60*, sub_struct_800622E4*);
extern func_ptr_800622E4 D_8011E008[];

void func_800622E4(GlobalContext* globalCtx, SubGlobalContext11E60* subContext) {
    sub_struct_800622E4* entry;
    s32 i;

    for (i = 0; i < subContext->unkCC; i++) {
        entry = subContext->unkD0[i];

        if (entry == NULL) {
        } else if (entry->unk11 & 0x40) {
        } else {
            D_8011E008[entry->unk15](globalCtx, subContext, entry);
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

void ActorCollider_Cylinder_Update(Actor* actor, ColliderCylinderMain* collision) {
    collision->dim.position.x = actor->posRot.pos.x;
    collision->dim.position.y = actor->posRot.pos.y;
    collision->dim.position.z = actor->posRot.pos.z;
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

void func_80062718(struct_80062718_1* arg0, struct_80062718_2* arg1) {
    arg0->unk46 = arg1->unk0;
    arg0->unk48 = arg1->unk2;
    arg0->unk4A = arg1->unk4;
}

typedef struct struct_80062734 {
    char unk_0[0x40];
    struct_8005CEDC unk40;
} struct_80062734;

void func_80062734(struct_80062734* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, Vec3f* arg4) {
    Math_Vec3f_Copy(&arg0->unk40.unk18, arg3);
    Math_Vec3f_Copy(&arg0->unk40.unk24, arg4);
    Math_Vec3f_Copy(&arg0->unk40.unk0, arg1);
    Math_Vec3f_Copy(&arg0->unk40.unkC, arg2);
    func_8005CEDC(&arg0->unk40);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800627A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8006285C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800628A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062A28.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062B80.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062CD4.s")

void func_80062D60(GlobalContext* arg0, Vec3f* arg1) {
    func_80062CD4(arg0, arg1);
    Audio_PlaySoundGeneral(0x1808U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
}

void func_80062DAC(s32 arg0, s32 arg1, Vec3f* arg2) {
    func_80062CD4(arg0, arg1);
    Audio_PlaySoundGeneral(0x1808U, arg2, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
}

void func_80062DF4(GlobalContext* globalCtx, Vec3f* arg1) {
    func_80062D60(globalCtx, arg1);
}

typedef struct struct_8011E068 {
    /* 0x00 */ char unk_0[2];
    /* 0x02 */ Vec3s unk2;
    /* 0x08 */ char unk_4[0x26];
    /* 0x2E */ Vec3s unk2E;
} struct_8011E068;

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
