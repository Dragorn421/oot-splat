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

s32 func_8005B65C(s32 arg0, struct_8011DE00* arg1) {
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

s32 func_8005B884(s32 arg0, struct_8011DE2C* arg1) {
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

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005CBAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005CC98.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005CD34.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005CDD0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005CE6C.s")

s32 func_8005CEB4(GlobalContext* globalCtx, ColliderDimensions* dim) {
    return 1;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005CEC4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005CEDC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005CF90.s")

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

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D218.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D2C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D324.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D334.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D378.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D3A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D3BC.s")

void func_8005D400(GlobalContext* globalCtx, SubGlobalContext11E60* sub_11E60) {
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D40C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D4B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D4C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D4DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D62C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/Actor_CollisionCheck_SetAT.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005D8AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/Actor_CollisionCheck_SetAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005DB04.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/Actor_CollisionCheck_SetOT.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005DD5C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005DE9C.s")

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

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005DFAC.s")

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

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800622E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800623A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800624BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062530.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8006268C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800626B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/ActorCollider_Cylinder_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062718.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062734.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800627A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8006285C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800628A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062A28.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062B80.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062CD4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062D60.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062DAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062DF4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062E14.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_80062ECC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_800635D0.s")
