#include "ultra64.h"
#include "global.h"
#include "z64collision_check.h"

void func_8005B280(GraphicsContext* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {
    func_8005B2AC(arg0, arg1, arg2, arg3, 255, 0, 0);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_collision_check/func_8005B2AC.s")

static Collider sColliderInit = {
    NULL, NULL, NULL, NULL, AT_NONE, AC_NONE, OC1_NONE, OC2_NONE, COL_MATERIAL_HIT3, COLTYPE_MAX,
};

// multi-type
s32 func_8005B65C_InitColliderDefault(GlobalContext* globalCtx, Collider* collider) {
    *collider = sColliderInit;
    return 1;
}

// multi-type
s32 func_8005B6A0(GlobalContext* globalCtx, Collider* collider) {
    return 1;
}

// multi-type
s32 func_8005B6B0_LoadColliderAltWithActor(GlobalContext* globalCtx, Collider* collider, ColliderSrcAltWithActor* src) {
    collider->actor = src->actor;
    collider->atFlags = src->atFlags;
    collider->acFlags = src->acFlags;
    collider->ocFlags1 = src->ocFlags1;
    collider->ocFlags2 = OC2_TYPE_1;
    collider->colType = src->colType;
    return 1;
}

// multi-type
s32 func_8005B6B0_LoadColliderAlt(GlobalContext* globalCtx, Collider* collider, Actor* actor, ColliderSrcAlt* src) {
    collider->actor = actor;
    collider->colMaterial = src->colMaterial;
    collider->atFlags = src->atFlags;
    collider->acFlags = src->acFlags;
    collider->ocFlags1 = src->ocFlags1;
    collider->ocFlags2 = OC2_TYPE_1;
    collider->colType = src->colType;
    return 1;
}

// multi-type
s32 func_8005B72C_LoadCollider(GlobalContext* globalCtx, Collider* collider, Actor* actor, ColliderSrc* src) {
    collider->actor = actor;
    collider->colMaterial = src->colMaterial;
    collider->atFlags = src->atFlags;
    collider->acFlags = src->acFlags;
    collider->ocFlags1 = src->ocFlags1;
    collider->ocFlags2 = src->ocFlags2;
    collider->colType = src->colType;
    return 1;
}

// multi-type
void func_8005B76C_ClearColliderATHit(GlobalContext* globalCtx, Collider* collider) {
    collider->at = NULL;
    collider->atFlags &= ~(AT_HIT | AT_BOUNCED);
}

// multi-type
void func_8005B784_ClearColliderACHit(GlobalContext* globalCtx, Collider* collider) {
    collider->ac = NULL;
    collider->acFlags &= ~(AC_HIT | AC_BOUNCED);
}

// multi-type
void func_8005B79C_ClearColliderOCHit(GlobalContext* globalCtx, Collider* collider) {
    collider->oc = NULL;
    collider->ocFlags1 &= ~OC1_HIT;
    collider->ocFlags2 &= ~OC2_HIT_PLAYER;
}

static ColliderElementDamageInfoAT sATDmgInfoInit = {
    0,
    HIT_SPECIAL_EFFECT_NONE,
    0,
};

// multi-type
s32 func_8005B7C0_InitATDmgInfo(GlobalContext* globalCtx, ColliderElementDamageInfoAT* atDmgInfo) {
    *atDmgInfo = sATDmgInfoInit;
    return 1;
}

// multi-type
s32 func_8005B7E4(GlobalContext* globalCtx, ColliderElementDamageInfoAT* atDmgInfo) {
    return 1;
}

// multi-type
s32 func_8005B7F4_LoadATDmgInfo(GlobalContext* globalCtx, ColliderElementDamageInfoAT* arg1,
                                ColliderElementDamageInfoAT* atDmgInfo) {
    arg1->dmgFlags = atDmgInfo->dmgFlags;
    arg1->hitSpecialEffect = atDmgInfo->hitSpecialEffect;
    arg1->damage = atDmgInfo->damage;
    return 1;
}

// multi-type
void func_8005B818(GlobalContext* globalCtx, ColliderElementDamageInfoAT* atDmgInfo) {
}

static ColliderElementDamageInfoAC sACDmgInfoInit = {
    0xFFCFFFFF,
    HIT_BACKLASH_NONE,
    0,
    { 0, 0, 0 },
};

// multi-type
s32 func_8005B824_InitACDmgInfo(GlobalContext* globalCtx, ColliderElementDamageInfoAC* acDmgInfo) {
    *acDmgInfo = sACDmgInfoInit;
    return 1;
}

// multi-type
s32 func_8005B850(GlobalContext* globalCtx, ColliderElementDamageInfoAC* acDmgInfo) {
    return 1;
}

// multi-type
s32 func_8005B860_LoadACDmgInfo(GlobalContext* globalCtx, ColliderElementDamageInfoAC* acDmgInfo,
                                ColliderElementDamageInfoACSrc* acDmgInfoSrc) {
    acDmgInfo->dmgFlags = acDmgInfoSrc->dmgFlags;
    acDmgInfo->hitBacklash = acDmgInfoSrc->hitBacklash;
    acDmgInfo->unk_05 = acDmgInfoSrc->unk5;
    return 1;
}

static ColliderElement sElemInit = {
    { 0, HIT_SPECIAL_EFFECT_NONE, 0 },
    {
        0xFFCFFFFF,
        HIT_BACKLASH_NONE,
        0,
        { 0, 0, 0 },
    },
    ELEM_MATERIAL_UNK0,
    ATELEM_NONE,
    ACELEM_NONE,
    OCELEM_NONE,
    NULL,
    NULL,
    NULL,
    NULL,
};

// multi-type
s32 func_8005B884_InitElement(GlobalContext* globalCtx, ColliderElement* elem) {
    *elem = sElemInit;
    func_8005B7C0_InitATDmgInfo(globalCtx, &elem->atDmgInfo);
    func_8005B824_InitACDmgInfo(globalCtx, &elem->acDmgInfo);
    return 1;
}

// multi-type
s32 func_8005B904_DestroyElement(GlobalContext* globalCtx, ColliderElement* elem) {
    func_8005B7E4(globalCtx, &elem->atDmgInfo);
    func_8005B850(globalCtx, &elem->acDmgInfo);
    return 1;
}

// multi-type
s32 func_8005B93C_LoadElement(GlobalContext* globalCtx, ColliderElement* elem, ColliderElementSrc* elemSrc) {
    elem->elemMaterial = elemSrc->elemMaterial;
    func_8005B7F4_LoadATDmgInfo(globalCtx, &elem->atDmgInfo, &elemSrc->atDmgInfo);
    func_8005B860_LoadACDmgInfo(globalCtx, &elem->acDmgInfo, &elemSrc->acDmgInfo);
    elem->atElemFlags = elemSrc->atElemFlags;
    elem->acElemFlags = elemSrc->acElemFlags;
    elem->ocElemFlags = elemSrc->ocElemFlags;
    return 1;
}

// multi-type
void func_8005B9B0_ClearColliderElementATHit(GlobalContext* globalCtx, ColliderElement* elem) {
    elem->atHit = NULL;
    elem->atHitElem = NULL;
    elem->atElemFlags &= ~ATELEM_HIT;
    elem->atElemFlags &= ~ATELEM_DREW_HITMARK;
    func_8005B818(globalCtx, &elem->atDmgInfo);
}

// multi-type
void func_8005B9E8_ClearColliderElementACHit(GlobalContext* globalCtx, ColliderElement* elem) {
    elem->acElemFlags &= ~ACELEM_HIT;
    elem->acElemFlags &= ~ACELEM_DRAW_HITMARK;
    elem->acHit = NULL;
    elem->acHitElem = NULL;
    elem->acDmgInfo.unk_06.x = elem->acDmgInfo.unk_06.y = elem->acDmgInfo.unk_06.z = 0;
}

void func_8005BA1C_ClearColliderElementOCHit(GlobalContext* globalCtx, ColliderElement* elem) {
    elem->ocElemFlags &= ~OCELEM_HIT;
}

ColliderSpheresElementShape D_8011DE54 = {
    {
        { 0, 0, 0 },
        0,
    },
    {
        { 0, 0, 0 },
        0,
    },
    0.0f,
    0,
};

s32 func_8005BA30_Type0(GlobalContext* globalCtx, ColliderSpheresElementShape* arg1) {
    *arg1 = D_8011DE54;
    return 1;
}

s32 func_8005BA74(GlobalContext* globalCtx, ColliderSpheresElementShape* arg1) {
    return 1;
}

s32 func_8005BA84_Type0(GlobalContext* globalCtx, ColliderSpheresElementShape* arg1,
                        ColliderSrc_Type0_ptrC_sub18* arg2) {
    arg1->unk14 = arg2->unk0;
    arg1->unk0 = arg2->unk2;
    arg1->unk10 = arg2->unkA * 0.01f;
    return 1;
}

s32 func_8005BAD8_InitJntSphElement(GlobalContext* globalCtx, ColliderSpheresElement* jntSphElem) {
    func_8005B884_InitElement(globalCtx, &jntSphElem->base);
    func_8005BA30_Type0(globalCtx, &jntSphElem->unk28);
    return 1;
}

s32 func_8005BB10_Type0(GlobalContext* globalCtx, ColliderSpheresElement* jntSphElem) {
    func_8005B904_DestroyElement(globalCtx, &jntSphElem->base);
    func_8005BA74(globalCtx, &jntSphElem->unk28);
    return 1;
}

s32 func_8005BAD8_LoadJntSphElement(GlobalContext* globalCtx, ColliderSpheresElement* jntSphElem,
                                    ColliderSpheresElementSrc* jntSphElemSrc) {
    func_8005B93C_LoadElement(globalCtx, &jntSphElem->base, &jntSphElemSrc->base);
    func_8005BA84_Type0(globalCtx, &jntSphElem->unk28, &jntSphElemSrc->unk18);
    return 1;
}

s32 func_8005BB8C_SetAT_sub_0(GlobalContext* globalCtx, ColliderSpheresElement* jntSphElem) {
    func_8005B9B0_ClearColliderElementATHit(globalCtx, &jntSphElem->base);
    return 1;
}

s32 func_8005BBB0_SetAC_sub_0(GlobalContext* globalCtx, ColliderSpheresElement* jntSphElem) {
    func_8005B9E8_ClearColliderElementACHit(globalCtx, &jntSphElem->base);
    return 1;
}

s32 func_8005BBD4_SetOT_sub_0(GlobalContext* globalCtx, ColliderSpheresElement* jntSphElem) {
    func_8005BA1C_ClearColliderElementOCHit(globalCtx, &jntSphElem->base);
    return 1;
}

s32 func_8005BBF8_InitJntSph(GlobalContext* globalCtx, ColliderSpheres* arg1) {
    func_8005B65C_InitColliderDefault(globalCtx, &arg1->base);
    arg1->nElements = 0;
    arg1->elements = 0;
    return 1;
}

// only used by EnNwc
s32 func_8005BC28(GlobalContext* globalCtx, ColliderSpheres* arg1) {
    ColliderSpheresElement* var_s0;

    func_8005B6A0(globalCtx, &arg1->base);
    for (var_s0 = arg1->elements; var_s0 < (arg1->elements + arg1->nElements); var_s0++) {
        func_8005BB10_Type0(globalCtx, var_s0);
    }
    arg1->nElements = 0;
    if (arg1->elements != NULL) {
        ZeldaArena_FreeDebug((void*)arg1->elements, "../z_collision_check.c", 0x571);
    }
    arg1->elements = NULL;
    return 1;
}

s32 func_8005BCC8_Type0(GlobalContext* globalCtx, ColliderSpheres* arg1) {
    ColliderSpheresElement* var_s0;

    func_8005B6A0(globalCtx, &arg1->base);
    for (var_s0 = arg1->elements; var_s0 < (arg1->elements + arg1->nElements); var_s0++) {
        func_8005BB10_Type0(globalCtx, var_s0);
    }
    arg1->nElements = 0;
    arg1->elements = NULL;
    return 1;
}

// unused
s32 func_8005BD50_jntsph(GlobalContext* globalCtx, ColliderSpheres* arg1, ColliderSpheresSrcAltWithActor* arg2) {
    ColliderSpheresElement* var_s0;
    ColliderSpheresElementSrc* var_s1;

    func_8005B6B0_LoadColliderAltWithActor(globalCtx, &arg1->base, &arg2->base);
    arg1->nElements = arg2->nElements;
    arg1->elements = ZeldaArena_MallocDebug(arg2->nElements << 6, "../z_collision_check.c", 0x5A3);
    if (arg1->elements == 0) {
        arg1->nElements = 0;
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjJntSph_set():zelda_malloc()出来ません。\n");
        osSyncPrintf("\x1b[m");
        return 0;
    }
    for (var_s0 = arg1->elements, var_s1 = arg2->elements; var_s0 < (arg1->elements + arg1->nElements);
         var_s0++, var_s1++) {
        func_8005BAD8_InitJntSphElement(globalCtx, var_s0);
        func_8005BAD8_LoadJntSphElement(globalCtx, var_s0, var_s1);
    }
    return 1;
}

// only used by EnNwc
s32 func_8005BE50_jntsph(GlobalContext* globalCtx, ColliderSpheres* arg1, Actor* arg2, ColliderSpheresSrcAlt* arg3) {
    ColliderSpheresElement* var_s0;
    ColliderSpheresElementSrc* var_s1;

    func_8005B6B0_LoadColliderAlt(globalCtx, &arg1->base, arg2, &arg3->base);
    arg1->nElements = arg3->nElements;
    arg1->elements = ZeldaArena_MallocDebug(arg3->nElements * 0x40, "../z_collision_check.c", 0x5D2);
    if (arg1->elements == 0) {
        arg1->nElements = 0;
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjJntSph_set3():zelda_malloc_出来ません。\n");
        osSyncPrintf("\x1b[m");
        return 0;
    }
    for (var_s0 = arg1->elements, var_s1 = arg3->elements; var_s0 < (arg1->elements + arg1->nElements);
         var_s0++, var_s1++) {
        func_8005BAD8_InitJntSphElement(globalCtx, var_s0);
        func_8005BAD8_LoadJntSphElement(globalCtx, var_s0, var_s1);
    }
    return 1;
}

// unused
s32 func_8005BF50_jntsph(GlobalContext* globalCtx, ColliderSpheres* arg1, Actor* arg2, ColliderSpheresSrc* arg3) {
    s32 temp_v0;
    ColliderSpheresElement* var_s0;
    ColliderSpheresElementSrc* var_s1;

    func_8005B72C_LoadCollider(globalCtx, &arg1->base, arg2, &arg3->base);
    arg1->nElements = arg3->nElements;
    arg1->elements = ZeldaArena_MallocDebug(arg3->nElements * 0x40, "../z_collision_check.c", 0x60F);
    if (arg1->elements == NULL) {
        arg1->nElements = 0;
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjJntSph_set5():zelda_malloc出来ません\n");
        osSyncPrintf("\x1b[m");
        return 0;
    }
    for (var_s0 = arg1->elements, var_s1 = arg3->elements; var_s0 < (arg1->elements + arg1->nElements);
         var_s0++, var_s1++) {
        func_8005BAD8_InitJntSphElement(globalCtx, var_s0);
        func_8005BAD8_LoadJntSphElement(globalCtx, var_s0, var_s1);
    }
    return 1;
}

s32 func_8005C050_jntsph_Type0(GlobalContext* globalCtx, ColliderSpheres* jntSph, Actor* actor,
                               ColliderSpheresSrc* jntSphSrc, ColliderSpheresElement* jntSphElements) {
    ColliderSpheresElement* jntSphElem;
    ColliderSpheresElementSrc* jntSphElemSrc;

    func_8005B72C_LoadCollider(globalCtx, &jntSph->base, actor, &jntSphSrc->base);
    jntSph->nElements = jntSphSrc->nElements;
    jntSph->elements = jntSphElements;
    if (jntSph->elements == NULL) {
        __assert("pclobj_jntsph->elem_tbl != NULL", "../z_collision_check.c", 1603);
    }
    for (jntSphElem = jntSph->elements, jntSphElemSrc = jntSphSrc->elements;
         jntSphElem < (jntSph->elements + jntSph->nElements); jntSphElem++, jntSphElemSrc++) {
        func_8005BAD8_InitJntSphElement(globalCtx, jntSphElem);
        func_8005BAD8_LoadJntSphElement(globalCtx, jntSphElem, jntSphElemSrc);
    }
    return 1;
}

s32 func_8005C124_SetAT_0(GlobalContext* globalCtx, Collider* collider) {
    ColliderSpheres* new_var = (ColliderSpheres*)collider;
    ColliderSpheresElement* var_s0;

    func_8005B76C_ClearColliderATHit(globalCtx, &new_var->base);
    for (var_s0 = new_var->elements; var_s0 < (new_var->elements + new_var->nElements); var_s0++) {
        func_8005BB8C_SetAT_sub_0(globalCtx, var_s0);
    }

    return 1;
}

s32 func_8005C1AC_SetAC_0(GlobalContext* globalCtx, Collider* collider) {
    ColliderSpheres* new_var = (ColliderSpheres*)collider;
    ColliderSpheresElement* var_s0;

    func_8005B784_ClearColliderACHit(globalCtx, &new_var->base);
    for (var_s0 = new_var->elements; var_s0 < (new_var->elements + new_var->nElements); var_s0++) {
        func_8005BBB0_SetAC_sub_0(globalCtx, var_s0);
    }
    return 1;
}

s32 func_8005C234_SetOT_0(GlobalContext* globalCtx, Collider* collider) {
    ColliderSpheres* new_var = (ColliderSpheres*)collider;
    ColliderSpheresElement* var_s0;

    func_8005B79C_ClearColliderOCHit(globalCtx, &new_var->base);
    for (var_s0 = new_var->elements; var_s0 < (new_var->elements + new_var->nElements); var_s0++) {
        func_8005BBD4_SetOT_sub_0(globalCtx, var_s0);
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

s32 ActorCollider_AllocThing_Type1(GlobalContext* globalCtx, ColliderCylinder* collision) {
    func_8005B65C_InitColliderDefault(globalCtx, &collision->base);
    func_8005B884_InitElement(globalCtx, &collision->elem);
    func_8005C2BC(globalCtx, &collision->unk40);
    return 1;
}

s32 ActorCollider_DestroyCylinder(GlobalContext* globalCtx, ColliderCylinder* collision) {
    func_8005B6A0(globalCtx, &collision->base);
    func_8005B904_DestroyElement(globalCtx, &collision->elem);
    func_8005C318(globalCtx, &collision->unk40);
    return 1;
}

// only used by ObjDekujr
s32 func_8005C3F4(GlobalContext* globalCtx, ColliderCylinder* collision, ColliderCylinderSrcAltWithActor* src) {
    func_8005B6B0_LoadColliderAltWithActor(globalCtx, &collision->base, &src->base);
    func_8005B93C_LoadElement(globalCtx, &collision->elem, &src->elem);
    func_8005C328_Type1(globalCtx, &collision->unk40, &src->unk20);
    return 1;
}

s32 func_8005C450_Type1(GlobalContext* globalCtx, ColliderCylinder* collision, Actor* actor,
                        ColliderCylinderSrcAlt* src) {
    func_8005B6B0_LoadColliderAlt(globalCtx, &collision->base, actor, &src->base);
    func_8005B93C_LoadElement(globalCtx, &collision->elem, &src->elem);
    func_8005C328_Type1(globalCtx, &collision->unk40, &src->unk20);
    return 1;
}

s32 ActorCollider_InitThing_Type1(GlobalContext* globalCtx, ColliderCylinder* collision, Actor* actor,
                                  ColliderCylinderSrc* src) {
    func_8005B72C_LoadCollider(globalCtx, &collision->base, actor, &src->base);
    func_8005B93C_LoadElement(globalCtx, &collision->elem, &src->elem);
    func_8005C328_Type1(globalCtx, &collision->unk40, &src->unk20);
    return 1;
}

s32 func_8005C508_SetAT_1(GlobalContext* globalCtx, Collider* collider) {
    ColliderCylinder* collision = (ColliderCylinder*)collider;

    func_8005B76C_ClearColliderATHit(globalCtx, &collision->base);
    func_8005B9B0_ClearColliderElementATHit(globalCtx, &collision->elem);
    return 1;
}

s32 func_8005C540_SetAC_1(GlobalContext* globalCtx, Collider* collider) {
    ColliderCylinder* collision = (ColliderCylinder*)collider;

    func_8005B784_ClearColliderACHit(globalCtx, &collision->base);
    func_8005B9E8_ClearColliderElementACHit(globalCtx, &collision->elem);
    return 1;
}

s32 func_8005C578_SetOT_1(GlobalContext* globalCtx, Collider* collider) {
    ColliderCylinder* collision = (ColliderCylinder*)collider;

    func_8005B79C_ClearColliderOCHit(globalCtx, &collision->base);
    func_8005BA1C_ClearColliderElementOCHit(globalCtx, &collision->elem);
    return 1;
}

static TriNorm sTriNormInit = {
    {
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
    },
    {
        { 0.0f, 0.0f, 0.0f },
        0.0f,
    },
};

s32 func_8005C5B0_InitTriNorm(GlobalContext* globalCtx, TriNorm* arg1) {
    *arg1 = sTriNormInit;
    return 1;
}

s32 func_8005C5F8(GlobalContext* globalCtx, UNK_PTR arg1) {
    return 1;
}

s32 func_8005C608(GlobalContext* globalCtx, TriNorm* arg1, Vec3f* arg2) {
    Vec3f* var_v1;
    Vec3f* var_v0;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    for (var_v0 = &arg1->vtx[0], var_v1 = arg2; var_v0 < arg1->vtx + 3; var_v0++, var_v1++) {
        *var_v0 = *var_v1;
    }

    func_800CC8B4(arg2, arg2 + 1, arg2 + 2, &sp44, &sp40, &sp3C, &sp38);
    arg1->plane.normal.x = sp44;
    arg1->plane.normal.y = sp40;
    arg1->plane.normal.z = sp3C;
    arg1->plane.originDist = sp38;
    return 1;
}

s32 func_8005C6C0_InitTrisElement(GlobalContext* globalCtx, ColliderTrisElement* arg1) {
    func_8005B884_InitElement(globalCtx, &arg1->base);
    func_8005C5B0_InitTriNorm(globalCtx, &arg1->unk28);
    return 1;
}

typedef struct struct_8005C6F8 {
    ColliderElement base;
    char unk_28[0x5C - 0x28];
} struct_8005C6F8; /* size = 0x5C */

s32 func_8005C6F8(GlobalContext* globalCtx, struct_8005C6F8* arg1) {
    func_8005B904_DestroyElement(globalCtx, &arg1->base);
    func_8005C5F8(globalCtx, arg1->unk_28);
    return 1;
}

s32 func_8005C730(GlobalContext* globalCtx, ColliderTrisElement* arg1, ColliderTrisElementSrc* arg2) {
    func_8005B93C_LoadElement(globalCtx, &arg1->base, &arg2->base);
    func_8005C608(globalCtx, &arg1->unk28, arg2->unk18);
    return 1;
}

s32 func_8005C774(GlobalContext* globalCtx, ColliderElement* elem) {
    func_8005B9B0_ClearColliderElementATHit(globalCtx, elem);
    return 1;
}

s32 func_8005C798_SetAC_sub_2(GlobalContext* globalCtx, ColliderElement* elem) {
    func_8005B9E8_ClearColliderElementACHit(globalCtx, elem);
    return 1;
}

s32 func_8005C7BC_Type2(GlobalContext* globalCtx, ColliderTrisElement* arg1) {
    func_8005BA1C_ClearColliderElementOCHit(globalCtx, &arg1->base);
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
    for (var_s0 = arg1->unk1C; var_s0 < (arg1->unk1C + arg1->unk18); var_s0++) {
        func_8005C6F8(globalCtx, var_s0);
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
    for (var_s0 = arg1->unk1C; var_s0 < &arg1->unk1C[arg1->unk18]; var_s0++) {
        func_8005C6F8(globalCtx, var_s0);
    }
    arg1->unk18 = 0;
    arg1->unk1C = NULL;
    return 1;
}

// unused
s32 func_8005C964_tris(GlobalContext* globalCtx, ColliderTris* arg1, Actor* arg2, ColliderTrisSrcAlt* arg3) {
    ColliderTrisElement* var_s0;
    ColliderTrisElementSrc* var_s1;

    func_8005B6B0_LoadColliderAlt(globalCtx, &arg1->base, arg2, &arg3->base);
    arg1->nElements = arg3->nElements;
    arg1->elements = ZeldaArena_MallocDebug((u32)arg1->nElements * 0x5C, "../z_collision_check.c", 0x86C);
    if (arg1->elements == 0) {
        arg1->nElements = 0;
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjTris_set3():zelda_malloc()出来ません\n");
        osSyncPrintf("\x1b[m");
        return 0;
    }
    for (var_s0 = arg1->elements, var_s1 = arg3->elements; var_s0 < (arg1->elements + arg1->nElements);
         var_s0++, var_s1++) {
        func_8005C6C0_InitTrisElement(globalCtx, var_s0);
        func_8005C730(globalCtx, var_s0, var_s1);
    }
    return 1;
}

// unused
s32 func_8005CA88_tris(GlobalContext* globalCtx, ColliderTris* arg1, Actor* arg2, ColliderTrisSrc* arg3) {
    ColliderTrisElement* temp_v0;
    ColliderTrisElement* var_s0;
    ColliderTrisElementSrc* var_s1;

    func_8005B72C_LoadCollider(globalCtx, &arg1->base, arg2, &arg3->base);
    arg1->nElements = arg3->nElements;
    temp_v0 = ZeldaArena_MallocDebug((u32)arg1->nElements * 0x5C, "../z_collision_check.c", 0x89F);
    arg1->elements = temp_v0;
    if (temp_v0 == NULL) {
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("ClObjTris_set5():zelda_malloc出来ません\n");
        osSyncPrintf("\x1b[m");
        arg1->nElements = 0;
        return 0;
    }
    for (var_s0 = arg1->elements, var_s1 = arg3->elements; var_s0 < &arg1->elements[arg1->nElements];
         var_s0++, var_s1++) {
        func_8005C6C0_InitTrisElement(globalCtx, var_s0);
        func_8005C730(globalCtx, var_s0, var_s1);
    }
    return 1;
}

// uses not decompiled
s32 func_8005CBAC_tris(GlobalContext* globalCtx, ColliderTris* arg1, Actor* arg2, ColliderTrisSrc* arg3,
                       ColliderTrisElement* arg4) {
    ColliderTrisElement* var_s0;
    ColliderTrisElementSrc* var_s1;

    func_8005B72C_LoadCollider(globalCtx, &arg1->base, arg2, &arg3->base);
    arg1->nElements = arg3->nElements;
    arg1->elements = arg4;
    if (arg1->elements == 0) {
        __assert("pclobj_tris->elem_tbl != NULL", "../z_collision_check.c", 0x8D2);
    }
    for (var_s0 = arg1->elements, var_s1 = arg3->elements; var_s0 < &arg1->elements[arg1->nElements];
         var_s0++, var_s1++) {
        func_8005C6C0_InitTrisElement(globalCtx, var_s0);
        func_8005C730(globalCtx, var_s0, var_s1);
    }
    return 1;
}

s32 func_8005CC98_SetAT_2(GlobalContext* globalCtx, Collider* collider) {
    ColliderTrisElement* trisElem;
    ColliderTris* tris;

    tris = (ColliderTris*)collider;
    func_8005B76C_ClearColliderATHit(globalCtx, &tris->base);
    for (trisElem = tris->elements; trisElem < (tris->elements + tris->nElements); trisElem++) {
        func_8005C774(globalCtx, &trisElem->base);
    }
    return 1;
}

s32 func_8005CD34_SetAC_2(GlobalContext* globalCtx, Collider* collider) {
    ColliderTrisElement* trisElem;
    ColliderTris* tris;

    tris = (ColliderTris*)collider;
    func_8005B784_ClearColliderACHit(globalCtx, &tris->base);
    for (trisElem = tris->elements; trisElem < (tris->elements + tris->nElements); trisElem++) {
        func_8005C798_SetAC_sub_2(globalCtx, &trisElem->base);
    }
    return 1;
}

s32 func_8005CDD0_SetOT_2(GlobalContext* globalCtx, Collider* collider) {
    ColliderTris* tris;
    ColliderTrisElement* trisElem;

    tris = (ColliderTris*)collider;
    func_8005B79C_ClearColliderOCHit(globalCtx, &tris->base);

    for (trisElem = tris->elements; trisElem < (tris->elements + tris->nElements); trisElem++) {
        func_8005C7BC_Type2(globalCtx, trisElem);
    }
    return 1;
}

ColliderQuadShape D_8011DEAC = {
    {
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
    },
    { 0, 0, 0 },
    { 0, 0, 0 },
    1e38f,
};

s32 func_8005CE6C(GlobalContext* globalCtx, ColliderQuadShape* arg1) {
    *arg1 = D_8011DEAC;
    return 1;
}

s32 func_8005CEB4_Type3(GlobalContext* globalCtx, ColliderQuadShape* dim) {
    return 1;
}

s32 func_8005CEC4(GlobalContext* globalCtx, ColliderQuadShape* arg1) {
    arg1->unk3C = 1e38f;
    return 1;
}

void func_8005CEDC(ColliderQuadShape* arg0) {
    arg0->middleAB.x = (arg0->corners.cornerA.x + arg0->corners.cornerB.x) * 0.5f;
    arg0->middleAB.y = (arg0->corners.cornerA.y + arg0->corners.cornerB.y) * 0.5f;
    arg0->middleAB.z = (arg0->corners.cornerA.z + arg0->corners.cornerB.z) * 0.5f;
    arg0->middleCD.x = (arg0->corners.cornerD.x + arg0->corners.cornerC.x) * 0.5f;
    arg0->middleCD.y = (arg0->corners.cornerD.y + arg0->corners.cornerC.y) * 0.5f;
    arg0->middleCD.z = (arg0->corners.cornerD.z + arg0->corners.cornerC.z) * 0.5f;
}

s32 func_8005CF90_Type3(GlobalContext* globalCtx, ColliderQuadShape* quadShape, ColliderQuadShapeCorners* cornersSrc) {
    quadShape->corners.cornerD = cornersSrc->cornerD;
    quadShape->corners.cornerC = cornersSrc->cornerC;
    quadShape->corners.cornerA = cornersSrc->cornerA;
    quadShape->corners.cornerB = cornersSrc->cornerB;
    func_8005CEDC(quadShape);
    return 1;
}

s32 func_8005D018_Type3(GlobalContext* globalCtx, ColliderQuad* collision) {
    func_8005B65C_InitColliderDefault(globalCtx, &collision->base);
    func_8005B884_InitElement(globalCtx, &collision->elem);
    func_8005CE6C(globalCtx, &collision->unk40);
    return 1;
}

s32 func_8005D060_Type3(GlobalContext* globalCtx, ColliderQuad* collision) {
    func_8005B6A0(globalCtx, &collision->base);
    func_8005B904_DestroyElement(globalCtx, &collision->elem);
    func_8005CEB4_Type3(globalCtx, &collision->unk40);
    return 1;
}

// unused
s32 func_8005D0A8(GlobalContext* globalCtx, ColliderQuad* collision, Actor* actor, ColliderQuadSrcAlt* src) {
    func_8005B6B0_LoadColliderAlt(globalCtx, &collision->base, actor, &src->base);
    func_8005B93C_LoadElement(globalCtx, &collision->elem, &src->elem);
    func_8005CF90_Type3(globalCtx, &collision->unk40, &src->corners);
    return 1;
}

s32 func_8005D104_Type3(GlobalContext* globalCtx, ColliderQuad* collision, Actor* actor, ColliderQuadSrc* src) {
    func_8005B72C_LoadCollider(globalCtx, &collision->base, actor, &src->base);
    func_8005B93C_LoadElement(globalCtx, &collision->elem, &src->elem);
    func_8005CF90_Type3(globalCtx, &collision->unk40, &src->corners);
    return 1;
}

s32 func_8005D160_SetAT_3(GlobalContext* globalCtx, Collider* collider) {
    ColliderQuad* collision = (ColliderQuad*)collider;

    func_8005B76C_ClearColliderATHit(globalCtx, &collision->base);
    func_8005B9B0_ClearColliderElementATHit(globalCtx, &collision->elem);
    func_8005CEC4(globalCtx, &collision->unk40);
    return 1;
}

s32 func_8005D1A8_SetAC_3(GlobalContext* globalCtx, Collider* collider) {
    ColliderQuad* collision = (ColliderQuad*)collider;

    func_8005B784_ClearColliderACHit(globalCtx, &collision->base);
    func_8005B9E8_ClearColliderElementACHit(globalCtx, &collision->elem);
    return 1;
}

s32 func_8005D1E0_SetOT_3(GlobalContext* globalCtx, Collider* collider) {
    ColliderQuad* collision = (ColliderQuad*)collider;

    func_8005B79C_ClearColliderOCHit(globalCtx, &collision->base);
    func_8005BA1C_ClearColliderElementOCHit(globalCtx, &collision->elem);
    return 1;
}

s32 func_8005D218(GlobalContext* globalCtx, ColliderQuad* arg1, Vec3f* arg2) {
    f32 temp_fv0;
    Vec3f sp20;

    if (!(arg1->elem.atElemFlags & ATELEM_NEAREST)) {
        return true;
    }
    Math_Vec3s_ToVec3f(&sp20, &arg1->unk40.middleAB);
    temp_fv0 = func_800CB650(&sp20, arg2);
    if (temp_fv0 < arg1->unk40.unk3C) {
        arg1->unk40.unk3C = temp_fv0;
        if (arg1->elem.atHit != NULL) {
            func_8005B784_ClearColliderACHit(globalCtx, arg1->elem.atHit);
        }
        if (arg1->elem.atHitElem != NULL) {
            func_8005B9E8_ClearColliderElementACHit(globalCtx, arg1->elem.atHitElem);
        }
        return true;
    } else {
        return false;
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
    Vec3f unk0[2];
    u16 unk18;
} struct_8005D378_arg1;

typedef struct struct_8005D378_arg2 {
    Vec3f unk0;
    Vec3f unkC;
    u16 unk18;
} struct_8005D378_arg2;

// unused
s32 func_8005D378(s32 arg0, struct_8005D378_arg1* arg1, struct_8005D378_arg2* arg2) {
    arg1->unk18 = arg2->unk18;
    func_8005D334(arg0, arg1->unk0, &arg2->unk0, &arg2->unkC);
    return 1;
}

s32 func_8005D3A4(GlobalContext* globalCtx, struct_ColChkCtx_290* arg1) {
    arg1->unk18 &= ~1;
    return 1;
}

void func_8005D40C(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);

void func_8005D3BC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    colChkCtx->unk2 = 0;
    func_8005D40C(globalCtx, colChkCtx);
    gGameInfo->data[0x735] = 1;
    gGameInfo->data[0x736] = 1;
    gGameInfo->data[0x737] = 1;
}

void func_8005D400(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
}

void func_8005D40C(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    Collider** colliderP;
    struct_ColChkCtx_290** var;

    if (!(colChkCtx->unk2 & 1)) {
        colChkCtx->nATColliders = 0;
        colChkCtx->nACColliders = 0;
        colChkCtx->nOCColliders = 0;
        colChkCtx->unk28C = 0;
        for (colliderP = colChkCtx->atColliders;
             colliderP < (colChkCtx->atColliders + ARRAY_COUNT(colChkCtx->atColliders)); colliderP++) {
            *colliderP = NULL;
        }

        for (colliderP = colChkCtx->acColliders;
             colliderP < (colChkCtx->acColliders + ARRAY_COUNT(colChkCtx->acColliders)); colliderP++) {
            *colliderP = NULL;
        }
        for (colliderP = colChkCtx->ocColliders;
             colliderP < (colChkCtx->ocColliders + ARRAY_COUNT(colChkCtx->ocColliders)); colliderP++) {
            *colliderP = NULL;
        }
        for (var = colChkCtx->unk290; var < (colChkCtx->unk290 + ARRAY_COUNT(colChkCtx->unk290)); var++) {
            *var = NULL;
        }
    }
}

// unused
void func_8005D4B4(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    colChkCtx->unk2 |= 1;
}

// unused
void func_8005D4C8(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    colChkCtx->unk2 &= ~1;
}

void func_8005D4DC(GlobalContext* globalCtx, Collider* collider) {
    ColliderSpheres* jntSph;
    ColliderCylinder* cylinder;
    ColliderTris* tris;
    ColliderQuad* quad;
    s32 i;

    if (collider != NULL) {
        switch (collider->colType) {
            case COLTYPE_JNTSPH:
                jntSph = (ColliderSpheres*)collider;

                for (i = 0; i < jntSph->nElements; i++) {
                    func_800D05D0(globalCtx, &jntSph->elements[i].unk28.unk8);
                }
                break;

            case COLTYPE_CYLINDER:
                cylinder = (ColliderCylinder*)collider;
                func_800D05DC(globalCtx, &cylinder->unk40);
                break;

            case COLTYPE_TRIANGLES:
                tris = (ColliderTris*)collider;
                for (i = 0; i < tris->nElements; i++) {
                    func_8005B280(globalCtx->state.gfxCtx, &tris->elements[i].unk28.vtx[0],
                                  &tris->elements[i].unk28.vtx[1], &tris->elements[i].unk28.vtx[2]);
                }
                break;

            case COLTYPE_QUAD:
                quad = (ColliderQuad*)collider;
                func_8005B280(globalCtx->state.gfxCtx, &quad->unk40.corners.cornerA, &quad->unk40.corners.cornerB,
                              &quad->unk40.corners.cornerC);
                func_8005B280(globalCtx->state.gfxCtx, &quad->unk40.corners.cornerC, &quad->unk40.corners.cornerD,
                              &quad->unk40.corners.cornerA);
                break;
        }
    }
}

void func_8005D62C(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    s32 i;

    if (gGameInfo->data[0x72F] != 0) {
        if (gGameInfo->data[0x735] != 0) {
            for (i = 0; i < colChkCtx->nATColliders; i++) {
                func_8005D4DC(globalCtx, colChkCtx->atColliders[i]);
            }
        }
        if (gGameInfo->data[0x736] != 0) {
            for (i = 0; i < colChkCtx->nACColliders; i++) {
                func_8005D4DC(globalCtx, colChkCtx->acColliders[i]);
            }
        }
        if (gGameInfo->data[0x737] != 0) {
            for (i = 0; i < colChkCtx->nOCColliders; i++) {
                if (colChkCtx->ocColliders[i]->ocFlags1 & 1) {
                    func_8005D4DC(globalCtx, colChkCtx->ocColliders[i]);
                }
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

callback_8011DEF8 D_8011DEF8_SetAT[] = {
    func_8005C124_SetAT_0, // COLTYPE_JNTSPH
    func_8005C508_SetAT_1, // COLTYPE_CYLINDER
    func_8005CC98_SetAT_2, // COLTYPE_TRIANGLES
    func_8005D160_SetAT_3, // COLTYPE_QUAD
};

s32 Actor_CollisionCheck_SetAT(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    s16 i;

    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collider->colType >= COLTYPE_MAX) {
        __assert("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xBB5);
    }
    D_8011DEF8_SetAT[collider->colType](globalCtx, collider);
    if ((collider->actor != NULL) && (collider->actor->update == NULL)) {
        return -1;
    }
    i = colChkCtx->nATColliders;
    if (i >= ARRAY_COUNT(colChkCtx->atColliders)) {
        osSyncPrintf("CollisionCheck_setAT():インデックスがオーバーして追加不能\n");
        return -1;
    }
    if (colChkCtx->unk2 & 1) {
        return -1;
    }
    colChkCtx->atColliders[i] = collider;
    colChkCtx->nATColliders++;
    return i;
}

// unused
s32 func_8005D8AC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, s32 i) {
    if (collider->colType >= COLTYPE_MAX) {
        __assert("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xBDD);
    }
    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    D_8011DEF8_SetAT[collider->colType](globalCtx, collider);
    if ((collider->actor != NULL) && ((collider->actor)->update == 0)) {
        return -1;
    }
    if (colChkCtx->unk2 & 1) {
        if (i >= colChkCtx->nATColliders) {
            osSyncPrintf("CollisionCheck_setAT_SAC():全データ数より大きいところに登録しようとしている。\n");
            return -1;
        }
        colChkCtx->atColliders[i] = collider;
    } else {
        if (colChkCtx->nATColliders >= ARRAY_COUNT(colChkCtx->atColliders)) {
            osSyncPrintf("CollisionCheck_setAT():インデックスがオーバーして追加不能\n");
            return -1;
        }
        i = colChkCtx->nATColliders;
        colChkCtx->atColliders[colChkCtx->nATColliders] = collider;
        colChkCtx->nATColliders++;
    }
    return i;
}

typedef s32 (*callback_8011DF08)(GlobalContext*, Collider*);

callback_8011DF08 D_8011DF08_SetAC[] = {
    func_8005C1AC_SetAC_0, // COLTYPE_JNTSPH
    func_8005C540_SetAC_1, // COLTYPE_CYLINDER
    func_8005CD34_SetAC_2, // COLTYPE_TRIANGLES
    func_8005D1A8_SetAC_3, // COLTYPE_QUAD
};

s32 Actor_CollisionCheck_SetAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    s32 i;

    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collider->colType >= COLTYPE_MAX) {
        __assert("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xC2A);
    }
    D_8011DF08_SetAC[collider->colType](globalCtx, collider);
    if ((collider->actor != NULL) && (collider->actor->update == NULL)) {
        return -1;
    }
    i = colChkCtx->nACColliders;
    if (i >= ARRAY_COUNT(colChkCtx->acColliders)) {
        osSyncPrintf("CollisionCheck_setAC():インデックスがオーバして追加不能\n");
        return -1;
    }
    if (colChkCtx->unk2 & 1) {
        return -1;
    }
    colChkCtx->acColliders[i] = collider;
    colChkCtx->nACColliders++;
    return i;
}

// unused
s32 func_8005DB04(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, s32 i) {
    if (collider->colType >= COLTYPE_MAX) {
        __assert("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 3153);
    }
    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    D_8011DF08_SetAC[collider->colType](globalCtx, collider);
    if ((collider->actor != NULL) && (collider->actor->update == NULL)) {
        return -1;
    }
    if (colChkCtx->unk2 & 1) {
        if (i >= colChkCtx->nACColliders) {
            osSyncPrintf("CollisionCheck_setAC_SAC():全データ数より大きいところに登録しようとしている。\n");
            return -1;
        }
        colChkCtx->acColliders[i] = collider;
    } else {
        if (colChkCtx->nACColliders >= ARRAY_COUNT(colChkCtx->acColliders)) {
            osSyncPrintf("CollisionCheck_setAC():インデックスがオーバして追加不能\n");
            return -1;
        }
        i = colChkCtx->nACColliders;
        colChkCtx->acColliders[i] = collider;
        colChkCtx->nACColliders++;
    }
    return i;
}

typedef s32 (*callback_8011DF18)(GlobalContext*, Collider*);

callback_8011DF18 D_8011DF18[] = {
    func_8005C234_SetOT_0, // COLTYPE_JNTSPH
    func_8005C578_SetOT_1, // COLTYPE_CYLINDER
    func_8005CDD0_SetOT_2, // COLTYPE_TRIANGLES
    func_8005D1E0_SetOT_3, // COLTYPE_QUAD
};

s32 Actor_CollisionCheck_SetOC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    s32 i;

    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collider->colType >= COLTYPE_MAX) {
        __assert("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 3229);
    }
    D_8011DF18[collider->colType](globalCtx, collider);
    if ((collider->actor != NULL) && (collider->actor->update == NULL)) {
        return -1;
    }
    i = colChkCtx->nOCColliders;
    if (i >= ARRAY_COUNT(colChkCtx->ocColliders)) {
        osSyncPrintf("CollisionCheck_setOC():インデックスがオーバして追加不能\n");
        return -1;
    }
    if (colChkCtx->unk2 & 1) {
        return -1;
    }
    colChkCtx->ocColliders[i] = collider;
    colChkCtx->nOCColliders++;
    return i;
}

// unused
s32 func_8005DD5C(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, s32 i) {
    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    if (collider->colType >= COLTYPE_MAX) {
        __assert("pcl_obj->data_type <= CL_DATA_LBL_SWRD", "../z_collision_check.c", 0xCCA);
        if (1) {}
    }
    D_8011DF18[collider->colType](globalCtx, collider);
    if ((collider->actor != NULL) && (collider->actor->update == NULL)) {
        return -1;
    }
    if (colChkCtx->unk2 & 1) {
        if (i >= colChkCtx->nOCColliders) {
            osSyncPrintf("CollisionCheck_setOC_SAC():全データ数より大きいところに登録しようとしている。\n");
            return -1;
        }
        colChkCtx->atColliders[i] = collider;
    } else {
        if (colChkCtx->nOCColliders >= ARRAY_COUNT(colChkCtx->ocColliders)) {
            osSyncPrintf("CollisionCheck_setOC():インデックスがオーバして追加不能\n");
            return -1;
        }
        i = colChkCtx->nOCColliders;
        colChkCtx->ocColliders[i] = collider;
        colChkCtx->nOCColliders++;
    }
    return i;
}

// unused
s32 func_8005DE9C(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, struct_ColChkCtx_290* arg2) {
    s32 i;

    if (func_800C0D28(globalCtx) == 1) {
        return -1;
    }
    func_8005D3A4(globalCtx, arg2);
    i = colChkCtx->unk28C;
    if (i >= ARRAY_COUNT(colChkCtx->unk290)) {
        osSyncPrintf("CollisionCheck_setOCLine():インデックスがオーバして追加不能\n");
        return -1;
    }
    colChkCtx->unk290[i] = arg2;
    colChkCtx->unk28C++;
    return i;
}

s32 func_8005DF2C_IsElementATOff(ColliderElement* elem) {
    if (!(elem->atElemFlags & ATELEM_ON)) {
        return 1;
    }
    return 0;
}

s32 func_8005DF50_IsElementACOff(ColliderElement* elem) {
    if (!(elem->acElemFlags & ACELEM_ON)) {
        return 1;
    }
    return 0;
}

s32 func_8005DF74_AreDmgFlagsDisjoint(ColliderElement* atElem, ColliderElement* acElem) {
    if ((atElem->atDmgInfo.dmgFlags & acElem->acDmgInfo.dmgFlags) == 0) {
        return 1;
    }

    return 0;
}

void func_8005DF9C(GlobalContext* globalCtx, Collider* collider, Vec3f* arg2) {
}

#ifndef GLUE
#define GLUE(a, b) a##b
#endif
#ifndef GLUE2
#define GLUE2(a, b) GLUE(a, b)
#endif
#define BSS_DUMMY GLUE2(s8 sBssDummy, __LINE__)

void func_8005DFAC(GlobalContext* globalCtx, Collider* collider, Vec3f* arg2) {
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
    D_8015D8A0.unk49C[1].b = 128;
    D_8015D8A0.unk49C[1].a = 0xFF;
    D_8015D8A0.unk49C[2].r = 0;
    D_8015D8A0.unk49C[2].g = 0;
    D_8015D8A0.unk49C[2].b = 128;
    D_8015D8A0.unk49C[2].a = 0xFF;
    D_8015D8A0.unk49C[3].r = 0;
    D_8015D8A0.unk49C[3].g = 0;
    D_8015D8A0.unk49C[3].b = 128;
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

void func_8005E10C(GlobalContext* globalCtx, Collider* collider, Vec3f* arg2) {
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
    D_8015DD68.unk49C[1].g = 128;
    D_8015DD68.unk49C[1].b = 0;
    D_8015DD68.unk49C[1].a = 0xFF;
    D_8015DD68.unk49C[2].r = 0;
    D_8015DD68.unk49C[2].g = 128;
    D_8015DD68.unk49C[2].b = 0;
    D_8015DD68.unk49C[2].a = 0xFF;
    D_8015DD68.unk49C[3].r = 0;
    D_8015DD68.unk49C[3].g = 128;
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

void func_8005E26C(GlobalContext* globalCtx, Collider* collider, Vec3f* arg2) {
    func_800299AC(globalCtx, arg2);
    func_80062B80(globalCtx, arg2);
}

void func_80062A28(GlobalContext* globalCtx, Vec3f* arg1);

void func_8005E2A4(GlobalContext* globalCtx, Collider* collider, Vec3f* arg3) {
    func_80062A28(globalCtx, arg3);
}

void func_8005E2C8(GlobalContext* globalCtx, Collider* collider, Vec3f* arg3) {
    func_80062A28(globalCtx, arg3);
}

void func_80062D60(GlobalContext* globalCtx, Vec3f* arg1);
void func_80062DAC(GlobalContext* globalCtx, Vec3f* arg1, Vec3f* arg2);

void func_8005E2EC(GlobalContext* globalCtx, ColliderElement* arg1, Collider* collider, Vec3f* arg3) {
    if (((arg1->atElemFlags & 0x18) == 0) && (collider->colMaterial != 9)) {
        func_80029CA4(globalCtx, 0, arg3);
        if (collider->actor == NULL) {
            Audio_PlaySoundGeneral(0x1806U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else {
            Audio_PlaySoundGeneral(0x1806U, &collider->actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    } else if ((arg1->atElemFlags & 0x18) == 0) {
        func_80029CA4(globalCtx, 3, arg3);
        if (collider->actor == NULL) {
            func_80062D60(globalCtx, arg3);
        } else {
            func_80062DAC(globalCtx, arg3, &collider->actor->unk_E4);
        }
    } else if ((arg1->atElemFlags & 0x18) == 8) {
        func_80029CA4(globalCtx, 0, arg3);
        if (collider->actor == NULL) {
            Audio_PlaySoundGeneral(0x1806U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else {
            Audio_PlaySoundGeneral(0x1806U, &collider->actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    } else if ((arg1->atElemFlags & 0x18) == 0x10) {
        func_80029CA4(globalCtx, 1, arg3);
        if (collider->actor == NULL) {
            Audio_PlaySoundGeneral(0x1837U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else {
            Audio_PlaySoundGeneral(0x1837U, &collider->actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    }
}

s32 func_8005E4F8(Collider* collider, ColliderElement* arg1) {
    Actor* actor;

    actor = collider->actor;
    if ((actor != NULL) && (actor->type == ACTORTYPE_PLAYER)) {
        if (arg1->elemMaterial == 0) {
            Audio_PlaySoundGeneral(0x1811U, &actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else if (arg1->elemMaterial == 1) {
            Audio_PlaySoundGeneral(0x1824U, &actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else if (arg1->elemMaterial == 2) {
            Audio_PlaySoundGeneral(0U, &actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
        } else if (arg1->elemMaterial == 3) {
            Audio_PlaySoundGeneral(0U, &actor->unk_E4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
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

void func_8005E604(GlobalContext* globalCtx, Collider* arg1, ColliderElement* arg2, Collider* arg3,
                   ColliderElement* arg4, Vec3f* arg5) {
    if (!(arg4->acElemFlags & 0x40) && ((((arg2->atElemFlags & 0x20) != 0)) || !(arg2->atElemFlags & 0x40))) {
        if (arg3->actor != NULL) {
            D_8011DF28[D_8011DF40[arg3->colMaterial][0]](globalCtx, arg3, arg5);
        }
        do {
        } while (0);
        if (arg3->actor != NULL) {
            if (D_8011DF40[arg3->colMaterial][1] == 3) {
                func_8005E2EC(globalCtx, arg2, arg3, arg5);
            } else if (D_8011DF40[arg3->colMaterial][1] == 4) {
                if (arg1->actor == NULL) {
                    func_80062CD4(globalCtx, arg5);
                    Audio_PlaySoundGeneral(0x1837U, &D_801333D4, 4U, &D_801333E0, &D_801333E0, &D_801333E8);
                } else {
                    func_80062E14(globalCtx, arg5, &arg1->actor->unk_E4);
                }
            } else if (D_8011DF40[arg3->colMaterial][1] != 5) {
                func_80029CA4(globalCtx, D_8011DF40[arg3->colMaterial][1], arg5);
                if (!(arg4->acElemFlags & 0x20)) {
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
    arg0->atFlags |= AT_BOUNCED;
    arg1->acFlags |= AC_BOUNCED;
}

s32 func_8005E81C(GlobalContext* globalCtx, Collider* atCollider, ColliderElement* atElem, Vec3f* atElemPos,
                  Collider* acCollider, ColliderElement* acElem, Vec3f* acElemPos, Vec3f* arg7) {
    if ((acCollider->acFlags & AC_HARD) && (atCollider->actor != NULL) && (acCollider->actor != NULL)) {
        func_8005E800(atCollider, acCollider);
    }
    if (!(acElem->acElemFlags & ACELEM_NO_AT_INFO)) {
        atCollider->atFlags |= AT_HIT;
        atCollider->at = acCollider->actor;
        atElem->atHit = acCollider;
        atElem->atHitElem = acElem;
        atElem->atElemFlags |= ATELEM_HIT;
        if (atCollider->actor != NULL) {
            atCollider->actor->sub_98.impactEffect = acElem->acDmgInfo.hitBacklash;
        }
    }
    acCollider->acFlags |= AC_HIT;
    acCollider->ac = atCollider->actor;
    acElem->acHit = (struct Collider*)atCollider;
    acElem->acHitElem = atElem;
    acElem->acElemFlags |= ACELEM_HIT;
    if (acCollider->actor != NULL) {
        acCollider->actor->sub_98.unk_1B = atElem->atDmgInfo.hitSpecialEffect;
    }
    acElem->acDmgInfo.unk_06.x = arg7->x;
    acElem->acDmgInfo.unk_06.y = arg7->y;
    acElem->acDmgInfo.unk_06.z = arg7->z;
    if (!(atElem->atElemFlags & ATELEM_AT_HITMARK) && ((acCollider->colMaterial != COL_MATERIAL_METAL)) &&
        (acCollider->colMaterial != COL_MATERIAL_WOOD) && (acCollider->colMaterial != COL_MATERIAL_HARD)) {
        acElem->acElemFlags |= ACELEM_DRAW_HITMARK;
    } else {
        func_8005E604(globalCtx, atCollider, atElem, acCollider, acElem, arg7);
        atElem->atElemFlags |= ATELEM_DREW_HITMARK;
    }
    return 1;
}

void CollisionCheck_ATJntSphVsACJntSph(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                       Collider* acCollider) {
    ColliderSpheres* atJntSph = (ColliderSpheres*)atCollider;
    ColliderSpheres* acJntSph = (ColliderSpheres*)acCollider;
    ColliderSpheresElement* atJntSphElem;
    ColliderSpheresElement* acJntSphElem;
    f32 sp8C;
    f32 sp88;
    f32 temp_fv0_2;
    Vec3f sp78;
    Vec3f atJntSphElemPos;
    Vec3f acJntSphElemPos;

    if ((((atJntSph->nElements > 0) && (atJntSph->elements != NULL)) && (acJntSph->nElements > 0)) &&
        (acJntSph->elements != NULL)) {
        for (atJntSphElem = atJntSph->elements; atJntSphElem < (atJntSph->elements + atJntSph->nElements);
             atJntSphElem++) {
            if (func_8005DF2C_IsElementATOff(&atJntSphElem->base) != 1) {
                for (acJntSphElem = acJntSph->elements; acJntSphElem < (acJntSph->elements + acJntSph->nElements);
                     acJntSphElem++) {
                    if (((func_8005DF50_IsElementACOff(&acJntSphElem->base) != 1) &&
                         (func_8005DF74_AreDmgFlagsDisjoint(&atJntSphElem->base, &acJntSphElem->base) != 1)) &&
                        (Math3D_SpheresTouchingSurfaceCenter(&atJntSphElem->unk28.unk8, &acJntSphElem->unk28.unk8,
                                                             &sp8C, &sp88) == 1)) {
                        atJntSphElemPos.x = atJntSphElem->unk28.unk8.center.x;
                        atJntSphElemPos.y = atJntSphElem->unk28.unk8.center.y;
                        atJntSphElemPos.z = atJntSphElem->unk28.unk8.center.z;
                        acJntSphElemPos.x = acJntSphElem->unk28.unk8.center.x;
                        acJntSphElemPos.y = acJntSphElem->unk28.unk8.center.y;
                        acJntSphElemPos.z = acJntSphElem->unk28.unk8.center.z;
                        if (!(fabsf(sp88) < 0.008f)) {
                            temp_fv0_2 = ((f32)acJntSphElem->unk28.unk8.radius) / sp88;
                            sp78.x = ((atJntSphElemPos.x - acJntSphElemPos.x) * temp_fv0_2) + acJntSphElemPos.x;
                            sp78.y = ((atJntSphElemPos.y - acJntSphElemPos.y) * temp_fv0_2) + acJntSphElemPos.y;
                            sp78.z = ((atJntSphElemPos.z - acJntSphElemPos.z) * temp_fv0_2) + acJntSphElemPos.z;
                        } else {
                            Math_Vec3f_Copy(&sp78, &atJntSphElemPos);
                        }
                        func_8005E81C(globalCtx, &atJntSph->base, &atJntSphElem->base, &atJntSphElemPos,
                                      &acJntSph->base, &acJntSphElem->base, &acJntSphElemPos, &sp78);
                        if (!(acJntSph->base.ocFlags2 & OC2_FIRST_ONLY)) {
                            return;
                        }
                    }
                }
            }
        }
    }
}

void CollisionCheck_ATJntSphVsACCyl(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                    Collider* acCollider) {
    ColliderSpheres* atJntSph = (ColliderSpheres*)atCollider;
    ColliderCylinder* acCylinder = (ColliderCylinder*)acCollider;
    ColliderSpheresElement* atJntSphElem;
    f32 sp80;
    f32 sp7C;
    Vec3f sp70;
    Vec3f atJntSphElemPos;
    Vec3f acCylinderPos;
    f32 temp_fv0_2;

    if ((atJntSph->nElements > 0) && (atJntSph->elements != NULL) && (acCylinder->unk40.radius > 0)) {
        if (((acCylinder->unk40.height > 0)) && (func_8005DF50_IsElementACOff(&acCylinder->elem) != 1)) {
            if (&atJntSphElem->unk28 && &atJntSphElem->unk28) {}
            for (atJntSphElem = atJntSph->elements; atJntSphElem < &atJntSph->elements[atJntSph->nElements];
                 atJntSphElem++) {
                if ((func_8005DF2C_IsElementATOff(&atJntSphElem->base) != 1) &&
                    (func_8005DF74_AreDmgFlagsDisjoint(&atJntSphElem->base, &acCylinder->elem) != 1) &&
                    (func_800CFDA4(&atJntSphElem->unk28.unk8, &acCylinder->unk40, &sp80, &sp7C) != 0)) {
                    atJntSphElemPos.x = (f32)atJntSphElem->unk28.unk8.center.x;
                    atJntSphElemPos.y = (f32)atJntSphElem->unk28.unk8.center.y;
                    atJntSphElemPos.z = (f32)atJntSphElem->unk28.unk8.center.z;
                    acCylinderPos.x = (f32)acCylinder->unk40.pos.x;
                    acCylinderPos.y = (f32)acCylinder->unk40.pos.y;
                    acCylinderPos.z = (f32)acCylinder->unk40.pos.z;
                    if (!(fabsf(sp7C) < 0.008f)) {
                        temp_fv0_2 = (f32)acCylinder->unk40.radius / sp7C;
                        if (temp_fv0_2 <= 1.0f) {
                            sp70.x = ((atJntSphElemPos.x - acCylinderPos.x) * temp_fv0_2) + acCylinderPos.x;
                            sp70.y = ((atJntSphElemPos.y - acCylinderPos.y) * temp_fv0_2) + acCylinderPos.y;
                            sp70.z = ((atJntSphElemPos.z - acCylinderPos.z) * temp_fv0_2) + acCylinderPos.z;
                        } else {
                            Math_Vec3f_Copy(&sp70, &atJntSphElemPos);
                        }
                    } else {
                        Math_Vec3f_Copy(&sp70, &atJntSphElemPos);
                    }
                    func_8005E81C(globalCtx, &atJntSph->base, &atJntSphElem->base, &atJntSphElemPos, &acCylinder->base,
                                  &acCylinder->elem, &acCylinderPos, &sp70);
                    return;
                }
            }
        }
    }
}

void CollisionCheck_ATCylVsACJntSph(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                    Collider* acCollider) {
    ColliderCylinder* atCylinder = (ColliderCylinder*)atCollider;
    ColliderSpheres* acJntSph = (ColliderSpheres*)acCollider;
    f32 sp9C;
    f32 sp98;
    ColliderSpheresElement* acJntSphElem;
    Vec3f sp88;
    Vec3f atCylinderPos;
    Vec3f acJntSphElemPos;
    f32 temp_fv0_2;

    if ((acJntSph->nElements > 0) && (acJntSph->elements != 0) && (atCylinder->unk40.radius > 0)) {
        if ((atCylinder->unk40.height > 0) && (func_8005DF2C_IsElementATOff(&atCylinder->elem) != 1)) {
            for (acJntSphElem = acJntSph->elements; acJntSphElem < (acJntSph->elements + (acJntSph->nElements));
                 acJntSphElem++) {
                if ((func_8005DF50_IsElementACOff(&acJntSphElem->base) != 1) &&
                    (func_8005DF74_AreDmgFlagsDisjoint(&atCylinder->elem, &acJntSphElem->base) != 1) &&
                    (func_800CFDA4(&acJntSphElem->unk28.unk8, &atCylinder->unk40, &sp9C, &sp98) != 0)) {
                    atCylinderPos.x = (f32)atCylinder->unk40.pos.x;
                    atCylinderPos.y = (f32)atCylinder->unk40.pos.y;
                    atCylinderPos.z = (f32)atCylinder->unk40.pos.z;
                    acJntSphElemPos.x = (f32)acJntSphElem->unk28.unk8.center.x;
                    acJntSphElemPos.y = (f32)acJntSphElem->unk28.unk8.center.y;
                    acJntSphElemPos.z = (f32)acJntSphElem->unk28.unk8.center.z;
                    if (!(fabsf(sp98) < 0.008f)) {
                        temp_fv0_2 = (f32)acJntSphElem->unk28.unk8.radius / sp98;
                        if (temp_fv0_2 <= 1.0f) {
                            sp88.x = ((atCylinderPos.x - acJntSphElemPos.x) * temp_fv0_2) + acJntSphElemPos.x;
                            sp88.y = ((atCylinderPos.y - acJntSphElemPos.y) * temp_fv0_2) + acJntSphElemPos.y;
                            sp88.z = ((atCylinderPos.z - acJntSphElemPos.z) * temp_fv0_2) + acJntSphElemPos.z;
                        } else {
                            Math_Vec3f_Copy(&sp88, &atCylinderPos);
                        }
                    } else {
                        Math_Vec3f_Copy(&sp88, &atCylinderPos);
                    }
                    func_8005E81C(globalCtx, &atCylinder->base, &atCylinder->elem, &atCylinderPos, &acJntSph->base,
                                  &acJntSphElem->base, &acJntSphElemPos, &sp88);
                    if (!(acJntSph->base.ocFlags2 & OC2_FIRST_ONLY)) {
                        return;
                    }
                }
            }
        }
    }
}

void CollisionCheck_ATJntSphVsACTris(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                     Collider* acCollider) {
    ColliderSpheres* atJntSph = (ColliderSpheres*)atCollider;
    ColliderTris* acTris = (ColliderTris*)acCollider;
    ColliderSpheresElement* atJntSphElem;
    ColliderTrisElement* acTrisElem;
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;

    if ((atJntSph->nElements > 0)) {
        if ((atJntSph->elements != NULL) && (acTris->nElements > 0) && (acTris->elements != NULL)) {
            for (atJntSphElem = atJntSph->elements; atJntSphElem < (atJntSph->elements + atJntSph->nElements);
                 atJntSphElem++) {
                if (func_8005DF2C_IsElementATOff(&atJntSphElem->base) != 1) {
                    for (acTrisElem = acTris->elements; acTrisElem < (acTris->elements + acTris->nElements);
                         acTrisElem++) {
                        if ((func_8005DF50_IsElementACOff(&acTrisElem->base) != 1) &&
                            (func_8005DF74_AreDmgFlagsDisjoint(&atJntSphElem->base, &acTrisElem->base) != 1) &&
                            (func_800CE934(&atJntSphElem->unk28.unk8, &acTrisElem->unk28, &sp6C) == 1)) {
                            sp60.x = atJntSphElem->unk28.unk8.center.x;
                            sp60.y = atJntSphElem->unk28.unk8.center.y;
                            sp60.z = atJntSphElem->unk28.unk8.center.z;
                            sp54.x =
                                (acTrisElem->unk28.vtx[0].x + acTrisElem->unk28.vtx[1].x + acTrisElem->unk28.vtx[2].x) *
                                (1.0f / 3.0f);
                            sp54.y =
                                (acTrisElem->unk28.vtx[0].y + acTrisElem->unk28.vtx[1].y + acTrisElem->unk28.vtx[2].y) *
                                (1.0f / 3.0f);
                            sp54.z =
                                (acTrisElem->unk28.vtx[0].z + acTrisElem->unk28.vtx[1].z + acTrisElem->unk28.vtx[2].z) *
                                (1.0f / 3.0f);
                            func_8005E81C(globalCtx, &atJntSph->base, &atJntSphElem->base, &sp60, &acTris->base,
                                          &acTrisElem->base, &sp54, &sp6C);
                            return;
                        }
                    }
                }
                if (0) {}
            }
        }
    }
}

void CollisionCheck_ATTrisVsACJntSph(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                     Collider* acCollider) {
    ColliderTris* atTris = (ColliderTris*)atCollider;
    ColliderTrisElement* atTrisElem;
    ColliderSpheres* acJntSph = (ColliderSpheres*)acCollider;
    ColliderSpheresElement* acJntSphElem;
    Vec3f sp7C;
    Vec3f atTrisElemPos;
    Vec3f acJntSphElemPos;

    if (acJntSph->nElements > 0) {
        if ((acJntSph->elements != NULL) && (atTris->nElements > 0) && (atTris->elements != 0)) {
            for (acJntSphElem = acJntSph->elements; acJntSphElem < (acJntSph->elements + acJntSph->nElements);
                 acJntSphElem++) {
                if ((func_8005DF50_IsElementACOff(&acJntSphElem->base) != 1)) {
                    for (atTrisElem = atTris->elements; atTrisElem < (atTris->elements + atTris->nElements);
                         atTrisElem++) {
                        if (((func_8005DF2C_IsElementATOff(&atTrisElem->base) != 1))) {
                            if (((func_8005DF74_AreDmgFlagsDisjoint(&atTrisElem->base, &acJntSphElem->base) != 1) &&
                                 (func_800CE934(&acJntSphElem->unk28.unk8, &atTrisElem->unk28, &sp7C) == 1))) {
                                Math_Vec3s_ToVec3f(&acJntSphElemPos, &acJntSphElem->unk28.unk8.center);
                                atTrisElemPos.x = (atTrisElem->unk28.vtx[0].x + atTrisElem->unk28.vtx[1].x +
                                                   atTrisElem->unk28.vtx[2].x) *
                                                  (1.0f / 3.0f);
                                atTrisElemPos.y = (atTrisElem->unk28.vtx[0].y + atTrisElem->unk28.vtx[1].y +
                                                   atTrisElem->unk28.vtx[2].y) *
                                                  (1.0f / 3.0f);
                                atTrisElemPos.z = (atTrisElem->unk28.vtx[0].z + atTrisElem->unk28.vtx[1].z +
                                                   atTrisElem->unk28.vtx[2].z) *
                                                  (1.0f / 3.0f);
                                func_8005E81C(globalCtx, &atTris->base, &atTrisElem->base, &atTrisElemPos,
                                              &acJntSph->base, &acJntSphElem->base, &acJntSphElemPos, &sp7C);
                                if (!(acJntSph->base.ocFlags2 & OC2_FIRST_ONLY)) {
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

void CollisionCheck_ATJntSphVsACQuad(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                     Collider* acCollider) {
    ColliderSpheres* atJntSph = (ColliderSpheres*)atCollider;
    ColliderQuad* acQuad = (ColliderQuad*)acCollider;
    Vec3f sp7C;
    ColliderSpheresElement* atJntSphElem;
    Vec3f atJntSphElemPos;
    Vec3f acQuadPos;

    if ((atJntSph->nElements > 0) && ((atJntSph->elements != NULL)) &&
        (func_8005DF50_IsElementACOff(&acQuad->elem) != 1)) {
        Math3D_TriNorm(&D_8015E230, &acQuad->unk40.corners.cornerA, &acQuad->unk40.corners.cornerB,
                       &acQuad->unk40.corners.cornerC);
        Math3D_TriNorm(&D_8015E268, &acQuad->unk40.corners.cornerC, &acQuad->unk40.corners.cornerD,
                       &acQuad->unk40.corners.cornerA);
        for (atJntSphElem = atJntSph->elements; atJntSphElem < &atJntSph->elements[atJntSph->nElements];
             atJntSphElem++) {
            if (func_8005DF2C_IsElementATOff(&atJntSphElem->base) != 1) {
                if ((func_8005DF74_AreDmgFlagsDisjoint(&atJntSphElem->base, &acQuad->elem) != 1) &&
                    ((func_800CE934(&atJntSphElem->unk28.unk8, &D_8015E230, &sp7C) == 1) ||
                     (func_800CE934(&atJntSphElem->unk28.unk8, &D_8015E268, &sp7C) == 1))) {
                    Math_Vec3s_ToVec3f(&atJntSphElemPos, &atJntSphElem->unk28.unk8.center);
                    acQuadPos.x = (acQuad->unk40.corners.cornerA.x + acQuad->unk40.corners.cornerB.x +
                                   acQuad->unk40.corners.cornerC.x + acQuad->unk40.corners.cornerD.x) *
                                  0.25f;
                    acQuadPos.y = (acQuad->unk40.corners.cornerA.y + acQuad->unk40.corners.cornerB.y +
                                   acQuad->unk40.corners.cornerC.y + acQuad->unk40.corners.cornerD.y) *
                                  0.25f;
                    acQuadPos.z = (acQuad->unk40.corners.cornerA.z + acQuad->unk40.corners.cornerB.z +
                                   acQuad->unk40.corners.cornerC.z + acQuad->unk40.corners.cornerD.z) *
                                  0.25f;
                    func_8005E81C(globalCtx, &atJntSph->base, &atJntSphElem->base, &atJntSphElemPos, &acQuad->base,
                                  &acQuad->elem, &acQuadPos, &sp7C);
                    return;
                }
            }
            if (1) {}
        }
    }
}

TriNorm D_8015E2A0;
TriNorm D_8015E2D8;

void CollisionCheck_ATQuadVsACJntSph(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                     Collider* acCollider) {
    ColliderQuad* atQuad = (ColliderQuad*)atCollider;
    Vec3f sp88;
    ColliderSpheres* acJntSph = (ColliderSpheres*)acCollider;
    ColliderSpheresElement* acJntSphElem;
    Vec3f atQuadPos;
    Vec3f acJntSphElemPos;

    if (acJntSph->nElements > 0) {
        if ((acJntSph->elements != NULL) && (func_8005DF2C_IsElementATOff(&atQuad->elem) != 1)) {
            Math3D_TriNorm(&D_8015E2A0, &atQuad->unk40.corners.cornerA, &atQuad->unk40.corners.cornerB,
                           &atQuad->unk40.corners.cornerC);
            Math3D_TriNorm(&D_8015E2D8, &atQuad->unk40.corners.cornerA, &atQuad->unk40.corners.cornerC,
                           &atQuad->unk40.corners.cornerD);

            for (acJntSphElem = acJntSph->elements; acJntSphElem < &acJntSph->elements[acJntSph->nElements];
                 acJntSphElem++) {
                if ((func_8005DF50_IsElementACOff(&acJntSphElem->base) != 1) &&
                    ((func_8005DF74_AreDmgFlagsDisjoint(&atQuad->elem, &acJntSphElem->base) != 1)) &&
                    ((func_800CE934(&acJntSphElem->unk28.unk8, &D_8015E2A0, &sp88) == 1) ||
                     (func_800CE934(&acJntSphElem->unk28.unk8, &D_8015E2D8, &sp88) == 1)) &&
                    func_8005D218(globalCtx, atQuad, &sp88)) {
                    acJntSphElemPos.x = acJntSphElem->unk28.unk8.center.x;
                    acJntSphElemPos.y = acJntSphElem->unk28.unk8.center.y;
                    acJntSphElemPos.z = acJntSphElem->unk28.unk8.center.z;
                    atQuadPos.x = (atQuad->unk40.corners.cornerA.x + atQuad->unk40.corners.cornerB.x +
                                   atQuad->unk40.corners.cornerC.x + atQuad->unk40.corners.cornerD.x) *
                                  0.25f;
                    atQuadPos.y = (atQuad->unk40.corners.cornerA.y + atQuad->unk40.corners.cornerB.y +
                                   atQuad->unk40.corners.cornerC.y + atQuad->unk40.corners.cornerD.y) *
                                  0.25f;
                    atQuadPos.z = (atQuad->unk40.corners.cornerA.z + atQuad->unk40.corners.cornerB.z +
                                   atQuad->unk40.corners.cornerC.z + atQuad->unk40.corners.cornerD.z) *
                                  0.25f;
                    func_8005E81C(globalCtx, &atQuad->base, &atQuad->elem, &atQuadPos, &acJntSph->base,
                                  &acJntSphElem->base, &acJntSphElemPos, &sp88);
                    if (!(acJntSph->base.ocFlags2 & OC2_FIRST_ONLY)) {
                        return;
                    }
                }
                if (1) {}
            }
        }
    }
}

void CollisionCheck_ATCylVsACCyl(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                 Collider* acCollider) {
    ColliderCylinder* atCylinder = (ColliderCylinder*)atCollider;
    ColliderCylinder* acCylinder = (ColliderCylinder*)acCollider;
    f32 sp6C;
    f32 sp68;
    Vec3f sp5C;
    Vec3f atCylinderPos;
    Vec3f acCylinderPos;
    f32 temp_fv0;

    if ((atCylinder->unk40.radius > 0) && (atCylinder->unk40.height > 0) && (acCylinder->unk40.radius > 0) &&
        (acCylinder->unk40.height > 0)) {
        if (func_8005DF50_IsElementACOff(&acCylinder->elem) != 1) {
            if ((func_8005DF2C_IsElementATOff(&atCylinder->elem) != 1) &&
                (func_8005DF74_AreDmgFlagsDisjoint(&atCylinder->elem, &acCylinder->elem) != 1) &&
                (Math3D_CylinderOutCylinderDist(&atCylinder->unk40, &acCylinder->unk40, &sp6C, &sp68) == 1)) {
                Math_Vec3s_ToVec3f(&atCylinderPos, &atCylinder->unk40.pos);
                Math_Vec3s_ToVec3f(&acCylinderPos, &acCylinder->unk40.pos);
                if (!(fabsf(sp68) < 0.008f)) {
                    temp_fv0 = (f32)acCylinder->unk40.radius / sp68;
                    sp5C.y = (f32)acCylinder->unk40.pos.y + (f32)acCylinder->unk40.yShift +
                             ((f32)acCylinder->unk40.height * 0.5f);
                    sp5C.x = (((f32)atCylinder->unk40.pos.x - (f32)acCylinder->unk40.pos.x) * temp_fv0) +
                             (f32)acCylinder->unk40.pos.x;
                    sp5C.z = (((f32)atCylinder->unk40.pos.z - (f32)acCylinder->unk40.pos.z) * temp_fv0) +
                             (f32)acCylinder->unk40.pos.z;
                } else {
                    Math_Vec3s_ToVec3f(&sp5C, &acCylinder->unk40.pos);
                }
                func_8005E81C(globalCtx, &atCylinder->base, &atCylinder->elem, &atCylinderPos, &acCylinder->base,
                              &acCylinder->elem, &acCylinderPos, &sp5C);
            }
        }
    }
}

void CollisionCheck_ATCylVsACTris(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                  Collider* acCollider) {
    ColliderCylinder* atCylinder = (ColliderCylinder*)atCollider;
    ColliderTris* acTris = (ColliderTris*)acCollider;
    ColliderTrisElement* acTrisElem;
    Vec3f sp68;
    Vec3f atCylinderPos;
    Vec3f acTrisElemPos;

    if ((atCylinder->unk40.radius > 0) && (atCylinder->unk40.height > 0) && (acTris->nElements > 0) &&
        ((acTris->elements != NULL)) && (func_8005DF2C_IsElementATOff(&atCylinder->elem) != 1)) {
        for (acTrisElem = acTris->elements; acTrisElem < &acTris->elements[acTris->nElements]; acTrisElem++) {
            if ((func_8005DF50_IsElementACOff(&acTrisElem->base) != 1) &&
                (func_8005DF74_AreDmgFlagsDisjoint(&atCylinder->elem, &acTrisElem->base) != 1) &&
                (Math3D_CylTriTouchingIntersect(&atCylinder->unk40, &acTrisElem->unk28, &sp68) == 1)) {
                Math_Vec3s_ToVec3f(&atCylinderPos, &atCylinder->unk40.pos);
                acTrisElemPos.x =
                    (acTrisElem->unk28.vtx[0].x + acTrisElem->unk28.vtx[1].x + acTrisElem->unk28.vtx[2].x) *
                    (1.0f / 3.0f);
                acTrisElemPos.y =
                    (acTrisElem->unk28.vtx[0].y + acTrisElem->unk28.vtx[1].y + acTrisElem->unk28.vtx[2].y) *
                    (1.0f / 3.0f);
                acTrisElemPos.z =
                    (acTrisElem->unk28.vtx[0].z + acTrisElem->unk28.vtx[1].z + acTrisElem->unk28.vtx[2].z) *
                    (1.0f / 3.0f);
                func_8005E81C(globalCtx, &atCylinder->base, &atCylinder->elem, &atCylinderPos, &acTris->base,
                              &acTrisElem->base, &acTrisElemPos, &sp68);
                return;
            }
            if (1) {}
            if (1) {}
        }
    }
}

Vec3f D_8015E310;

void CollisionCheck_ATTrisVsACCyl(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                  Collider* acCollider) {
    ColliderTris* atTris = (ColliderTris*)atCollider;
    ColliderCylinder* acCylinder = (ColliderCylinder*)acCollider;
    ColliderTrisElement* atTrisElem;
    Vec3f atTrisElemPos;
    Vec3f acCylinderPos;

    if ((acCylinder->unk40.radius > 0) && (acCylinder->unk40.height > 0) && (atTris->nElements > 0) &&
        ((atTris->elements != NULL)) && (func_8005DF50_IsElementACOff(&acCylinder->elem) != 1)) {

        for (atTrisElem = atTris->elements; atTrisElem < &atTris->elements[atTris->nElements]; atTrisElem++) {
            if ((func_8005DF2C_IsElementATOff(&atTrisElem->base) != 1) &&
                (func_8005DF74_AreDmgFlagsDisjoint(&atTrisElem->base, &acCylinder->elem) != 1) &&
                (Math3D_CylTriTouchingIntersect(&acCylinder->unk40, &atTrisElem->unk28, &D_8015E310) == 1)) {
                atTrisElemPos.x =
                    (atTrisElem->unk28.vtx[0].x + atTrisElem->unk28.vtx[1].x + atTrisElem->unk28.vtx[2].x) *
                    (1.0f / 3.0f);
                atTrisElemPos.y =
                    (atTrisElem->unk28.vtx[0].y + atTrisElem->unk28.vtx[1].y + atTrisElem->unk28.vtx[2].y) *
                    (1.0f / 3.0f);
                atTrisElemPos.z =
                    (atTrisElem->unk28.vtx[0].z + atTrisElem->unk28.vtx[1].z + atTrisElem->unk28.vtx[2].z) *
                    (1.0f / 3.0f);
                Math_Vec3s_ToVec3f(&acCylinderPos, &acCylinder->unk40.pos);
                func_8005E81C(globalCtx, &atTris->base, &atTrisElem->base, &atTrisElemPos, &acCylinder->base,
                              &acCylinder->elem, &acCylinderPos, &D_8015E310);
                return;
            }
            if (1) {}
            if (1) {}
        }
    }
}

TriNorm D_8015E320;
TriNorm D_8015E358;
Vec3f D_8015E390;

void CollisionCheck_ATCylVsACQuad(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                  Collider* acCollider) {
    ColliderCylinder* atCylinder = (ColliderCylinder*)atCollider;
    ColliderQuad* acQuad = (ColliderQuad*)acCollider;

    if ((atCylinder->unk40.height > 0) && ((atCylinder->unk40.radius > 0)) &&
        ((func_8005DF2C_IsElementATOff(&atCylinder->elem) != 1)) &&
        ((func_8005DF50_IsElementACOff(&acQuad->elem) != 1)) &&
        (func_8005DF74_AreDmgFlagsDisjoint(&atCylinder->elem, &acQuad->elem) != 1)) {
        Math3D_TriNorm(&D_8015E320, &acQuad->unk40.corners.cornerA, &acQuad->unk40.corners.cornerB,
                       &acQuad->unk40.corners.cornerC);
        Math3D_TriNorm(&D_8015E358, &acQuad->unk40.corners.cornerC, &acQuad->unk40.corners.cornerD,
                       &acQuad->unk40.corners.cornerA);
        if (Math3D_CylTriTouchingIntersect(&atCylinder->unk40, &D_8015E320, &D_8015E390) == 1) {
            Vec3f atCylinderPos;
            Vec3f acQuadPos;

            Math_Vec3s_ToVec3f(&atCylinderPos, &atCylinder->unk40.pos);
            acQuadPos.x = (acQuad->unk40.corners.cornerA.x + acQuad->unk40.corners.cornerB.x +
                           acQuad->unk40.corners.cornerC.x + acQuad->unk40.corners.cornerD.x) *
                          0.25f;
            acQuadPos.y = (acQuad->unk40.corners.cornerA.y + acQuad->unk40.corners.cornerB.y +
                           acQuad->unk40.corners.cornerC.y + acQuad->unk40.corners.cornerD.y) *
                          0.25f;
            acQuadPos.z = (acQuad->unk40.corners.cornerA.z + acQuad->unk40.corners.cornerB.z +
                           acQuad->unk40.corners.cornerC.z + acQuad->unk40.corners.cornerD.z) *
                          0.25f;
            func_8005E81C(globalCtx, &atCylinder->base, &atCylinder->elem, &atCylinderPos, &acQuad->base, &acQuad->elem,
                          &acQuadPos, &D_8015E390);
        } else if (Math3D_CylTriTouchingIntersect(&atCylinder->unk40, &D_8015E358, &D_8015E390) == 1) {
            Vec3f atCylinderPos;
            Vec3f acQuadPos;

            Math_Vec3s_ToVec3f(&atCylinderPos, &atCylinder->unk40.pos);
            acQuadPos.x = (acQuad->unk40.corners.cornerA.x + acQuad->unk40.corners.cornerB.x +
                           acQuad->unk40.corners.cornerC.x + acQuad->unk40.corners.cornerD.x) *
                          0.25f;
            acQuadPos.y = (acQuad->unk40.corners.cornerA.y + acQuad->unk40.corners.cornerB.y +
                           acQuad->unk40.corners.cornerC.y + acQuad->unk40.corners.cornerD.y) *
                          0.25f;
            acQuadPos.z = (acQuad->unk40.corners.cornerA.z + acQuad->unk40.corners.cornerB.z +
                           acQuad->unk40.corners.cornerC.z + acQuad->unk40.corners.cornerD.z) *
                          0.25f;
            func_8005E81C(globalCtx, &atCylinder->base, &atCylinder->elem, &atCylinderPos, &acQuad->base, &acQuad->elem,
                          &acQuadPos, &D_8015E390);
        }
    }
}

TriNorm D_8015E3A0;
TriNorm D_8015E3D8;
Vec3f D_8015E410;

void CollisionCheck_ATQuadVsACCyl(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                  Collider* acCollider) {
    ColliderQuad* atQuad = (ColliderQuad*)atCollider;
    ColliderCylinder* acCylinder = (ColliderCylinder*)acCollider;

    if ((acCylinder->unk40.height > 0) && ((acCylinder->unk40.radius > 0)) &&
        ((func_8005DF50_IsElementACOff(&acCylinder->elem) != 1)) &&
        ((func_8005DF2C_IsElementATOff(&atQuad->elem) != 1)) &&
        (func_8005DF74_AreDmgFlagsDisjoint(&atQuad->elem, &acCylinder->elem) != 1)) {
        Math3D_TriNorm(&D_8015E3A0, &atQuad->unk40.corners.cornerA, &atQuad->unk40.corners.cornerB,
                       &atQuad->unk40.corners.cornerC);
        Math3D_TriNorm(&D_8015E3D8, &atQuad->unk40.corners.cornerA, &atQuad->unk40.corners.cornerC,
                       &atQuad->unk40.corners.cornerD);
        if ((Math3D_CylTriTouchingIntersect(&acCylinder->unk40, &D_8015E3A0, &D_8015E410) == 1) &&
            func_8005D218(globalCtx, atQuad, &D_8015E410)) {
            Vec3f sp64;
            Vec3f sp58;

            sp64.x = (atQuad->unk40.corners.cornerA.x + atQuad->unk40.corners.cornerB.x +
                      atQuad->unk40.corners.cornerC.x + atQuad->unk40.corners.cornerD.x) *
                     0.25f;
            sp64.y = (atQuad->unk40.corners.cornerA.y + atQuad->unk40.corners.cornerB.y +
                      atQuad->unk40.corners.cornerC.y + atQuad->unk40.corners.cornerD.y) *
                     0.25f;
            sp64.z = (atQuad->unk40.corners.cornerA.z + atQuad->unk40.corners.cornerB.z +
                      atQuad->unk40.corners.cornerC.z + atQuad->unk40.corners.cornerD.z) *
                     0.25f;
            Math_Vec3s_ToVec3f(&sp58, &acCylinder->unk40.pos);
            func_8005E81C(globalCtx, &atQuad->base, &atQuad->elem, &sp64, &acCylinder->base, &acCylinder->elem, &sp58,
                          &D_8015E410);
        } else if ((Math3D_CylTriTouchingIntersect(&acCylinder->unk40, &D_8015E3D8, &D_8015E410) == 1) &&
                   func_8005D218(globalCtx, atQuad, &D_8015E410)) {
            Vec3f sp4C;
            Vec3f sp40;

            sp4C.x = (atQuad->unk40.corners.cornerA.x + atQuad->unk40.corners.cornerB.x +
                      atQuad->unk40.corners.cornerC.x + atQuad->unk40.corners.cornerD.x) *
                     0.25f;
            sp4C.y = (atQuad->unk40.corners.cornerA.y + atQuad->unk40.corners.cornerB.y +
                      atQuad->unk40.corners.cornerC.y + atQuad->unk40.corners.cornerD.y) *
                     0.25f;
            sp4C.z = (atQuad->unk40.corners.cornerA.z + atQuad->unk40.corners.cornerB.z +
                      atQuad->unk40.corners.cornerC.z + atQuad->unk40.corners.cornerD.z) *
                     0.25f;
            Math_Vec3s_ToVec3f(&sp40, &acCylinder->unk40.pos);
            func_8005E81C(globalCtx, &atQuad->base, &atQuad->elem, &sp4C, &acCylinder->base, &acCylinder->elem, &sp40,
                          &D_8015E410);
        }
    }
}

Vec3f D_8015E420;

void CollisionCheck_ATTrisVsACTris(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                   Collider* acCollider) {
    ColliderTris* atTris = (ColliderTris*)atCollider;
    ColliderTris* acTris = (ColliderTris*)acCollider;
    ColliderTrisElement* var_s0;
    ColliderTrisElement* var_s2;
    Vec3f sp5C;
    Vec3f sp50;

    if ((acTris->nElements > 0) && ((acTris->elements != NULL)) && (atTris->nElements > 0) &&
        (atTris->elements != NULL)) {

        for (var_s2 = acTris->elements; (((var_s2 < &acTris->elements[acTris->nElements]))); var_s2++) {
            if (func_8005DF50_IsElementACOff(&var_s2->base) != 1) {
                for (var_s0 = atTris->elements; var_s0 < &atTris->elements[atTris->nElements]; var_s0++) {
                    if (0) {}
                    if ((func_8005DF2C_IsElementATOff(&var_s0->base) != 1) &&
                        (func_8005DF74_AreDmgFlagsDisjoint(&var_s0->base, &var_s2->base) != 1) &&
                        (Math3D_TrisIntersect(&var_s0->unk28, &var_s2->unk28, &D_8015E420) == 1)) {
                        sp5C.x =
                            (var_s0->unk28.vtx[0].x + var_s0->unk28.vtx[1].x + var_s0->unk28.vtx[2].x) * (1.0f / 3.0f);
                        sp5C.y =
                            (var_s0->unk28.vtx[0].y + var_s0->unk28.vtx[1].y + var_s0->unk28.vtx[2].y) * (1.0f / 3.0f);
                        sp5C.z =
                            (var_s0->unk28.vtx[0].z + var_s0->unk28.vtx[1].z + var_s0->unk28.vtx[2].z) * (1.0f / 3.0f);
                        sp50.x =
                            (var_s2->unk28.vtx[0].x + var_s2->unk28.vtx[1].x + var_s2->unk28.vtx[2].x) * (1.0f / 3.0f);
                        sp50.y =
                            (var_s2->unk28.vtx[0].y + var_s2->unk28.vtx[1].y + var_s2->unk28.vtx[2].y) * (1.0f / 3.0f);
                        sp50.z =
                            (var_s2->unk28.vtx[0].z + var_s2->unk28.vtx[1].z + var_s2->unk28.vtx[2].z) * (1.0f / 3.0f);
                        func_8005E81C(globalCtx, &atTris->base, &var_s0->base, &sp5C, &acTris->base, &var_s2->base,
                                      &sp50, &D_8015E420);
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

void CollisionCheck_ATTrisVsACQuad(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                   Collider* acCollider) {
    ColliderTris* atTris = (ColliderTris*)atCollider;
    ColliderQuad* acQuad = (ColliderQuad*)acCollider;
    ColliderTrisElement* var_s1;
    Vec3f sp68;
    Vec3f sp5C;

    if ((atTris->nElements > 0) && ((atTris->elements != NULL)) && (func_8005DF50_IsElementACOff(&acQuad->elem) != 1)) {
        Math3D_TriNorm(&D_8015E440, &acQuad->unk40.corners.cornerA, &acQuad->unk40.corners.cornerB,
                       &acQuad->unk40.corners.cornerC);
        Math3D_TriNorm(&D_8015E478, &acQuad->unk40.corners.cornerC, &acQuad->unk40.corners.cornerD,
                       &acQuad->unk40.corners.cornerA);
        for (var_s1 = atTris->elements; var_s1 < &atTris->elements[atTris->nElements]; var_s1++) {
            if ((func_8005DF2C_IsElementATOff(&var_s1->base) != 1) &&
                (func_8005DF74_AreDmgFlagsDisjoint(&var_s1->base, &acQuad->elem) != 1) &&
                (((Math3D_TrisIntersect(&D_8015E440, &var_s1->unk28, &D_8015E430) == 1)) ||
                 (Math3D_TrisIntersect(&D_8015E478, &var_s1->unk28, &D_8015E430) == 1))) {
                sp68.x = (var_s1->unk28.vtx[0].x + var_s1->unk28.vtx[1].x + var_s1->unk28.vtx[2].x) * (1.0f / 3.0f);
                sp68.y = (var_s1->unk28.vtx[0].y + var_s1->unk28.vtx[1].y + var_s1->unk28.vtx[2].y) * (1.0f / 3.0f);
                sp68.z = (var_s1->unk28.vtx[0].z + var_s1->unk28.vtx[1].z + var_s1->unk28.vtx[2].z) * (1.0f / 3.0f);
                sp5C.x = (acQuad->unk40.corners.cornerA.x + acQuad->unk40.corners.cornerB.x +
                          acQuad->unk40.corners.cornerC.x + acQuad->unk40.corners.cornerD.x) *
                         0.25f;
                sp5C.y = (acQuad->unk40.corners.cornerA.y + acQuad->unk40.corners.cornerB.y +
                          acQuad->unk40.corners.cornerC.y + acQuad->unk40.corners.cornerD.y) *
                         0.25f;
                sp5C.z = (acQuad->unk40.corners.cornerA.z + acQuad->unk40.corners.cornerB.z +
                          acQuad->unk40.corners.cornerC.z + acQuad->unk40.corners.cornerD.z) *
                         0.25f;
                func_8005E81C(globalCtx, &atTris->base, &var_s1->base, &sp68, &acQuad->base, &acQuad->elem, &sp5C,
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

void CollisionCheck_ATQuadVsACTris(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                   Collider* acCollider) {
    ColliderQuad* atQuad = (ColliderQuad*)atCollider;
    ColliderTris* acTris = (ColliderTris*)acCollider;
    ColliderTrisElement* var_s1;
    Vec3f sp68;
    Vec3f sp5C;

    if ((acTris->nElements > 0) && ((acTris->elements != NULL)) && (func_8005DF2C_IsElementATOff(&atQuad->elem) != 1)) {
        Math3D_TriNorm(&D_8015E4C0, &atQuad->unk40.corners.cornerA, &atQuad->unk40.corners.cornerB,
                       &atQuad->unk40.corners.cornerC);
        Math3D_TriNorm(&D_8015E4F8, &atQuad->unk40.corners.cornerC, &atQuad->unk40.corners.cornerD,
                       &atQuad->unk40.corners.cornerA);
        if (var_s1 && var_s1) {}
        for (var_s1 = acTris->elements; var_s1 < &acTris->elements[acTris->nElements]; var_s1++) {
            if ((func_8005DF50_IsElementACOff(&var_s1->base) != 1) &&
                (func_8005DF74_AreDmgFlagsDisjoint(&atQuad->elem, &var_s1->base) != 1) &&
                (((Math3D_TrisIntersect(&D_8015E4C0, &var_s1->unk28, &D_8015E4B0) == 1)) ||
                 (Math3D_TrisIntersect(&D_8015E4F8, &var_s1->unk28, &D_8015E4B0) == 1)) &&
                func_8005D218(globalCtx, atQuad, &D_8015E4B0)) {
                sp5C.x = (var_s1->unk28.vtx[0].x + var_s1->unk28.vtx[1].x + var_s1->unk28.vtx[2].x) * (1.0f / 3.0f);
                sp5C.y = (var_s1->unk28.vtx[0].y + var_s1->unk28.vtx[1].y + var_s1->unk28.vtx[2].y) * (1.0f / 3.0f);
                sp5C.z = (var_s1->unk28.vtx[0].z + var_s1->unk28.vtx[1].z + var_s1->unk28.vtx[2].z) * (1.0f / 3.0f);
                sp68.x = (atQuad->unk40.corners.cornerA.x + atQuad->unk40.corners.cornerB.x +
                          atQuad->unk40.corners.cornerC.x + atQuad->unk40.corners.cornerD.x) *
                         0.25f;
                sp68.y = (atQuad->unk40.corners.cornerA.y + atQuad->unk40.corners.cornerB.y +
                          atQuad->unk40.corners.cornerC.y + atQuad->unk40.corners.cornerD.y) *
                         0.25f;
                sp68.z = (atQuad->unk40.corners.cornerA.z + atQuad->unk40.corners.cornerB.z +
                          atQuad->unk40.corners.cornerC.z + atQuad->unk40.corners.cornerD.z) *
                         0.25f;
                func_8005E81C(globalCtx, &atQuad->base, &atQuad->elem, &sp68, &acTris->base, &var_s1->base, &sp5C,
                              &D_8015E4B0);
                return;
            }
        }
    }
}

TriNorm D_8015E530[2];
Vec3f D_8015E598;
TriNorm D_8015E5A8[2];

void CollisionCheck_ATQuadVsACQuad(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider,
                                   Collider* acCollider) {
    ColliderQuad* atQuad = (ColliderQuad*)atCollider;
    ColliderQuad* acQuad = (ColliderQuad*)acCollider;
    s32 i;
    s32 j;
    Vec3f atQuadPos;
    Vec3f acQuadPos;

    if ((func_8005DF2C_IsElementATOff(&atQuad->elem) != 1) && ((func_8005DF50_IsElementACOff(&acQuad->elem) != 1)) &&
        (func_8005DF74_AreDmgFlagsDisjoint(&atQuad->elem, &acQuad->elem) != 1)) {
        Math3D_TriNorm(&D_8015E5A8[0], &atQuad->unk40.corners.cornerA, &atQuad->unk40.corners.cornerB,
                       &atQuad->unk40.corners.cornerC);
        Math3D_TriNorm(&D_8015E5A8[1], &atQuad->unk40.corners.cornerA, &atQuad->unk40.corners.cornerC,
                       &atQuad->unk40.corners.cornerD);
        Math3D_TriNorm(&D_8015E530[0], &acQuad->unk40.corners.cornerA, &acQuad->unk40.corners.cornerB,
                       &acQuad->unk40.corners.cornerC);
        Math3D_TriNorm(&D_8015E530[1], &acQuad->unk40.corners.cornerA, &acQuad->unk40.corners.cornerC,
                       &acQuad->unk40.corners.cornerD);

        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                if ((Math3D_TrisIntersect(&D_8015E5A8[j], &D_8015E530[i], &D_8015E598) == 1) &&
                    func_8005D218(globalCtx, atQuad, &D_8015E598)) {
                    atQuadPos.x = (atQuad->unk40.corners.cornerA.x + atQuad->unk40.corners.cornerB.x +
                                   atQuad->unk40.corners.cornerC.x + atQuad->unk40.corners.cornerD.x) *
                                  0.25f;
                    atQuadPos.y = (atQuad->unk40.corners.cornerA.y + atQuad->unk40.corners.cornerB.y +
                                   atQuad->unk40.corners.cornerC.y + atQuad->unk40.corners.cornerD.y) *
                                  0.25f;
                    atQuadPos.z = (atQuad->unk40.corners.cornerA.z + atQuad->unk40.corners.cornerB.z +
                                   atQuad->unk40.corners.cornerC.z + atQuad->unk40.corners.cornerD.z) *
                                  0.25f;
                    acQuadPos.x = (acQuad->unk40.corners.cornerA.x + acQuad->unk40.corners.cornerB.x +
                                   acQuad->unk40.corners.cornerC.x + acQuad->unk40.corners.cornerD.x) *
                                  0.25f;
                    acQuadPos.y = (acQuad->unk40.corners.cornerA.y + acQuad->unk40.corners.cornerB.y +
                                   acQuad->unk40.corners.cornerC.y + acQuad->unk40.corners.cornerD.y) *
                                  0.25f;
                    acQuadPos.z = (acQuad->unk40.corners.cornerA.z + acQuad->unk40.corners.cornerB.z +
                                   acQuad->unk40.corners.cornerC.z + acQuad->unk40.corners.cornerD.z) *
                                  0.25f;
                    func_8005E81C(globalCtx, &atQuad->base, &atQuad->elem, &atQuadPos, &acQuad->base, &acQuad->elem,
                                  &acQuadPos, &D_8015E598);
                    return;
                }
            }
        }
    }
}

void func_80060EBC_Type0_processAC_(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderSpheres* jntSph = (ColliderSpheres*)collider;
    ColliderSpheresElement* jntSphElem;
    Vec3f sp24;

    for (jntSphElem = jntSph->elements; jntSphElem < (jntSph->elements + jntSph->nElements); jntSphElem++) {
        if (jntSphElem->base.acElemFlags & ACELEM_DRAW_HITMARK) {
            if ((jntSphElem->base.acHitElem != NULL) && !(jntSphElem->base.acHitElem->atElemFlags & 0x40)) {
                Math_Vec3s_ToVec3f(&sp24, &jntSphElem->base.acDmgInfo.unk_06);
                func_8005E604(globalCtx, jntSphElem->base.acHit, jntSphElem->base.acHitElem, &jntSph->base,
                              &jntSphElem->base, &sp24);
                jntSphElem->base.acHitElem->atElemFlags |= 0x40;
                return;
            }
        }
    }
}

void func_80060F94_Type1_processAC_(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderCylinder* arg2 = (ColliderCylinder*)collider;
    Vec3f sp28;

    if (arg2->elem.acElemFlags & ACELEM_DRAW_HITMARK) {
        if ((arg2->elem.acHitElem != NULL) && !(arg2->elem.acHitElem->atElemFlags & 0x40)) {
            Math_Vec3s_ToVec3f(&sp28, &arg2->elem.acDmgInfo.unk_06);
            func_8005E604(globalCtx, arg2->elem.acHit, arg2->elem.acHitElem, &arg2->base, &arg2->elem, &sp28);
            arg2->elem.acHitElem->atElemFlags |= 0x40;
        }
    }
}

void func_80061028_Type2_processAC_(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderTris* arg2 = (ColliderTris*)collider;
    ColliderTrisElement* var_v0;
    Vec3f sp24;

    for (var_v0 = arg2->elements; var_v0 < &arg2->elements[arg2->nElements]; var_v0++) {
        if (var_v0->base.acElemFlags & ACELEM_DRAW_HITMARK) {
            if ((var_v0->base.acHitElem != NULL) && !(var_v0->base.acHitElem->atElemFlags & 0x40)) {
                Math_Vec3s_ToVec3f(&sp24, &var_v0->base.acDmgInfo.unk_06);
                func_8005E604(globalCtx, var_v0->base.acHit, var_v0->base.acHitElem, &arg2->base, &var_v0->base, &sp24);
                var_v0->base.acHitElem->atElemFlags |= 0x40;
                return;
            }
        }
    }
}

void func_8006110C_Type3_processAC_(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderQuad* arg2 = (ColliderQuad*)collider;
    Vec3f sp28;

    if (arg2->elem.acElemFlags & 0x80) {
        if ((arg2->elem.acHitElem != NULL) && !(arg2->elem.acHitElem->atElemFlags & 0x40)) {
            Math_Vec3s_ToVec3f(&sp28, &arg2->elem.acDmgInfo.unk_06);
            func_8005E604(globalCtx, arg2->elem.acHit, arg2->elem.acHitElem, &arg2->base, &arg2->elem, &sp28);
            arg2->elem.acHitElem->atElemFlags |= 0x40;
        }
    }
}

typedef void (*callback_800611A0)(GlobalContext*, CollisionCheckContext*, Collider*);

callback_800611A0 D_8011DF5C_processAC_[] = {
    func_80060EBC_Type0_processAC_, // COLTYPE_JNTSPH
    func_80060F94_Type1_processAC_, // COLTYPE_CYLINDER
    func_80061028_Type2_processAC_, // COLTYPE_TRIANGLES
    func_8006110C_Type3_processAC_, // COLTYPE_QUAD
};

void func_800611A0_processAC_(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    Collider** acColliderP;
    Collider* acCollider;

    for (acColliderP = colChkCtx->acColliders; acColliderP < &colChkCtx->acColliders[colChkCtx->nACColliders];
         acColliderP++) {
        acCollider = *acColliderP;
        if ((acCollider != NULL) && (acCollider->acFlags & 1) &&
            (((acCollider->actor == NULL)) || (acCollider->actor->update != NULL))) {
            D_8011DF5C_processAC_[acCollider->colType](globalCtx, colChkCtx, acCollider);
        }
    }
}

typedef void (*callback_8011DF6C)(GlobalContext*, CollisionCheckContext*, Collider*, Collider*);

callback_8011DF6C D_8011DF6C_ATvsAC[COLTYPE_MAX][COLTYPE_MAX] = {
    {
        CollisionCheck_ATJntSphVsACJntSph,
        CollisionCheck_ATJntSphVsACCyl,
        CollisionCheck_ATJntSphVsACTris,
        CollisionCheck_ATJntSphVsACQuad,
    },
    {
        CollisionCheck_ATCylVsACJntSph,
        CollisionCheck_ATCylVsACCyl,
        CollisionCheck_ATCylVsACTris,
        CollisionCheck_ATCylVsACQuad,
    },
    {
        CollisionCheck_ATTrisVsACJntSph,
        CollisionCheck_ATTrisVsACCyl,
        CollisionCheck_ATTrisVsACTris,
        CollisionCheck_ATTrisVsACQuad,
    },
    {
        CollisionCheck_ATQuadVsACJntSph,
        CollisionCheck_ATQuadVsACCyl,
        CollisionCheck_ATQuadVsACTris,
        CollisionCheck_ATQuadVsACQuad,
    },
};

void func_80061274_processATvsAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* atCollider) {
    Collider** acColliderP;
    Collider* acCollider;

    for (acColliderP = colChkCtx->acColliders; acColliderP < &colChkCtx->acColliders[colChkCtx->nACColliders];
         acColliderP++) {
        acCollider = *acColliderP;
        if (acCollider != NULL) {
            if ((acCollider->acFlags & 1) && ((acCollider->actor == NULL) || (acCollider->actor->update != NULL))) {
                if (((acCollider->acFlags & atCollider->atFlags & AT_TYPE_ALL) != 0) && (atCollider != acCollider) &&
                    ((atCollider->atFlags & AT_SELF) || (atCollider->actor == NULL) ||
                     (acCollider->actor != atCollider->actor))) {
                    D_8011DF6C_ATvsAC[atCollider->colType][acCollider->colType](globalCtx, colChkCtx, atCollider,
                                                                                acCollider);
                }
            }
        }
    }
}

void func_8006139C_ProcessAllATvsAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    Collider** atColliderP;
    Collider* atCollider;

    if ((colChkCtx->nATColliders != 0) && (colChkCtx->nACColliders != 0)) {
        for (atColliderP = colChkCtx->atColliders; atColliderP < &colChkCtx->atColliders[colChkCtx->nATColliders];
             atColliderP++) {
            atCollider = *atColliderP;
            if ((atCollider != NULL) && (atCollider->atFlags & 1) &&
                (((atCollider->actor == NULL)) || (atCollider->actor->update != NULL))) {
                func_80061274_processATvsAC(globalCtx, colChkCtx, atCollider);
            }
        }
        func_800611A0_processAC_(globalCtx, colChkCtx);
    }
}

typedef enum ColChkMassType {
    /* 0 */ MASSTYPE_IMMOVABLE,
    /* 1 */ MASSTYPE_HEAVY,
    /* 2 */ MASSTYPE_NORMAL
} ColChkMassType;

s32 CollisionCheck_GetMassType(u8 mass) {
    if (mass == MASS_IMMOVABLE) {
        return MASSTYPE_IMMOVABLE;
    }
    if (mass == MASS_HEAVY) {
        return MASSTYPE_HEAVY;
    }
    return MASSTYPE_NORMAL;
}

void CollisionCheck_SetOCvsOC(Collider* leftCollider, ColliderElement* leftElement, Vec3f* leftPos,
                              Collider* rightCollider, ColliderElement* rightElement, Vec3f* rightPos, f32 arg6) {
    s32 pad[3];
    f32 dxz;
    f32 leftMass;
    f32 rightMass;
    f32 totalMass;
    f32 invTotalMass;
    f32 leftMassRatio;
    f32 rightMassRatio;
    Actor* leftActor;
    Actor* rightActor;
    s32 rightMassType;
    s32 leftMassType;
    f32 dx;
    f32 dz;

    leftActor = leftCollider->actor;
    rightActor = rightCollider->actor;
    leftCollider->ocFlags1 |= OC1_HIT;
    leftCollider->oc = rightActor;
    leftElement->ocElemFlags |= OCELEM_HIT;
    if (rightCollider->ocFlags2 & OC2_TYPE_PLAYER) {
        leftCollider->ocFlags2 |= OC2_HIT_PLAYER;
    }
    rightCollider->oc = leftActor;
    rightCollider->ocFlags1 |= OC1_HIT;
    rightElement->ocElemFlags |= OCELEM_HIT;
    if (leftCollider->ocFlags2 & OC2_TYPE_PLAYER) {
        rightCollider->ocFlags2 |= OC2_HIT_PLAYER;
    }
    if ((leftActor != NULL) && (rightActor != NULL) && !(leftCollider->ocFlags1 & OC1_NO_PUSH) &&
        !(rightCollider->ocFlags1 & OC1_NO_PUSH)) {
        leftMassType = CollisionCheck_GetMassType(leftActor->sub_98.mass);
        rightMassType = CollisionCheck_GetMassType(rightActor->sub_98.mass);
        leftMass = leftActor->sub_98.mass;
        rightMass = rightActor->sub_98.mass;
        totalMass = leftMass + rightMass;
        if (fabsf(totalMass) < 0.008f) {
            leftMass = 1.0f;
            rightMass = 1.0f;
            totalMass = 2.0f;
        }
        dx = rightPos->x - leftPos->x;
        dz = rightPos->z - leftPos->z;
        dxz = sqrtf((dx * dx) + (dz * dz));
        if (leftMassType == MASSTYPE_IMMOVABLE) {
            if (rightMassType != MASSTYPE_IMMOVABLE) {
                rightMassRatio = 0;
                leftMassRatio = 1;
            } else {
                // Both MASSTYPE_IMMOVABLE
                return;
            }
        } else if (leftMassType == MASSTYPE_HEAVY) {
            if (rightMassType == MASSTYPE_IMMOVABLE) {
                rightMassRatio = 1;
                leftMassRatio = 0;
            } else if (rightMassType == MASSTYPE_HEAVY) {
                rightMassRatio = 0.5f;
                leftMassRatio = 0.5f;
            } else { // rightMassType == MASSTYPE_NORMAL
                rightMassRatio = 0;
                leftMassRatio = 1;
            }
        } else { // leftMassType == MASSTYPE_NORMAL
            if (rightMassType == MASSTYPE_NORMAL) {
                invTotalMass = 1 / totalMass;
                rightMassRatio = rightMass * invTotalMass;
                leftMassRatio = leftMass * invTotalMass;
            } else { // rightMassType == MASSTYPE_HEAVY or MASSTYPE_IMMOVABLE
                rightMassRatio = 1;
                leftMassRatio = 0;
            }
        }
        if (!(fabsf(dxz) < 0.008f)) {
            dx *= arg6 / dxz;
            dz *= arg6 / dxz;
            leftActor->sub_98.displacement.x += -dx * rightMassRatio;
            leftActor->sub_98.displacement.z += -dz * rightMassRatio;
            rightActor->sub_98.displacement.x += dx * leftMassRatio;
            rightActor->sub_98.displacement.z += dz * leftMassRatio;
        } else {
            if (arg6 != 0.0f) {
                leftActor->sub_98.displacement.x += -arg6 * rightMassRatio;
                rightActor->sub_98.displacement.x += arg6 * leftMassRatio;
            } else {
                leftActor->sub_98.displacement.x -= rightMassRatio;
                rightActor->sub_98.displacement.x += leftMassRatio;
            }
        }
    }
}

void func_800617D4_0OCvs0OC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* leftCollider,
                            Collider* rightCollider) {
    ColliderSpheres* leftJntSph = (ColliderSpheres*)leftCollider;
    ColliderSpheres* rightJntSph = (ColliderSpheres*)rightCollider;
    ColliderSpheresElement* rightJntSphElem;
    ColliderSpheresElement* leftJntSphElem;
    f32 sp74;
    Vec3f leftJntSphElemPos;
    Vec3f rightJntSphElemPos;

    if ((leftJntSph->nElements > 0) && (leftJntSph->elements != NULL) && (rightJntSph->nElements > 0) &&
        (rightJntSph->elements != NULL)) {
        for (leftJntSphElem = leftJntSph->elements; leftJntSphElem < &leftJntSph->elements[leftJntSph->nElements];
             leftJntSphElem++) {
            if (!(leftJntSphElem->base.ocElemFlags & OCELEM_ON)) {
                continue;
            }
            for (rightJntSphElem = rightJntSph->elements;
                 rightJntSphElem < &rightJntSph->elements[rightJntSph->nElements]; rightJntSphElem++) {
                if (!(rightJntSphElem->base.ocElemFlags & OCELEM_ON)) {
                    continue;
                }
                if (Math3D_SpheresTouchingSurface(&leftJntSphElem->unk28.unk8, &rightJntSphElem->unk28.unk8, &sp74) ==
                    1) {
                    Math_Vec3s_ToVec3f(&leftJntSphElemPos, &leftJntSphElem->unk28.unk8.center);
                    Math_Vec3s_ToVec3f(&rightJntSphElemPos, &rightJntSphElem->unk28.unk8.center);
                    CollisionCheck_SetOCvsOC(&leftJntSph->base, &leftJntSphElem->base, &leftJntSphElemPos,
                                             &rightJntSph->base, &rightJntSphElem->base, &rightJntSphElemPos, sp74);
                }
            }
        }
    }
}

void func_8006199C_0OCvs1OC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* leftCollider,
                            Collider* rightCollider) {
    ColliderSpheres* leftJntSph = (ColliderSpheres*)leftCollider;
    ColliderCylinder* rightCylinder = (ColliderCylinder*)rightCollider;
    ColliderSpheresElement* leftJntSphElem;
    f32 sp78;
    Vec3f leftJntSphElemPos;
    Vec3f rightCylinderPos;

    if (leftJntSph->nElements > 0) {
        if ((leftJntSph->elements != NULL) && (rightCylinder->base.ocFlags1 & 1) &&
            (rightCylinder->elem.ocElemFlags & 1)) {
            for (leftJntSphElem = leftJntSph->elements; leftJntSphElem < &leftJntSph->elements[leftJntSph->nElements];
                 leftJntSphElem++) {
                if (!(leftJntSphElem->base.ocElemFlags & 1)) {
                    continue;
                }
                if (func_800CFD84(&leftJntSphElem->unk28.unk8, &rightCylinder->unk40, &sp78) == 1) {
                    Math_Vec3s_ToVec3f(&leftJntSphElemPos, &leftJntSphElem->unk28.unk8.center);
                    Math_Vec3s_ToVec3f(&rightCylinderPos, &rightCylinder->unk40.pos);
                    CollisionCheck_SetOCvsOC(&leftJntSph->base, &leftJntSphElem->base, &leftJntSphElemPos,
                                             &rightCylinder->base, &rightCylinder->elem, &rightCylinderPos, sp78);
                }
            }
        }
    }
}

void func_80061AF8_1OCvs0OC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* leftCollider,
                            Collider* rightCollider) {
    func_8006199C_0OCvs1OC(globalCtx, colChkCtx, rightCollider, leftCollider);
}

void func_80061B24_OCCylinderVsOCCylinder(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx,
                                          Collider* leftCollider, Collider* rightCollider) {
    ColliderCylinder* arg2 = (ColliderCylinder*)leftCollider;
    ColliderCylinder* arg3 = (ColliderCylinder*)rightCollider;
    f32 sp4C;
    Vec3f sp40;
    Vec3f sp34;

    if ((arg2->base.ocFlags1 & 1) && (arg3->base.ocFlags1 & 1) && (arg2->elem.ocElemFlags & 1) &&
        (arg3->elem.ocElemFlags & 1) && (Math3D_CylinderOutCylinder(&arg2->unk40, &arg3->unk40, &sp4C) == 1)) {
        Math_Vec3s_ToVec3f(&sp40, &arg2->unk40.pos);
        Math_Vec3s_ToVec3f(&sp34, &arg3->unk40.pos);
        CollisionCheck_SetOCvsOC(&arg2->base, &arg2->elem, &sp40, &arg3->base, &arg3->elem, &sp34, sp4C);
    }
}

s32 func_80061BF4(Collider* collider) {
    if (!(collider->ocFlags1 & 1)) {
        return 1;
    }
    return 0;
}

s32 func_80061C18(Collider* arg0, Collider* arg1) {
    if (!(arg0->ocFlags1 & arg1->ocFlags2 & 0x38) || (((arg0->ocFlags2 & arg1->ocFlags1 & 0x38) == 0)) ||
        ((arg0->ocFlags2 & 2) && (arg1->ocFlags2 & 4)) || ((arg1->ocFlags2 & 2) && (arg0->ocFlags2 & 4))) {
        return 1;
    }
    if (arg0->actor == arg1->actor) {
        return 1;
    }
    return 0;
}

typedef void (*callback_8011DFAC)(GlobalContext*, CollisionCheckContext*, Collider*, Collider*);

callback_8011DFAC D_8011DFAC[COLTYPE_MAX][COLTYPE_MAX] = {
    { func_800617D4_0OCvs0OC, func_8006199C_0OCvs1OC, NULL, NULL },
    { func_80061AF8_1OCvs0OC, func_80061B24_OCCylinderVsOCCylinder, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
};

void func_80061C98_OC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    Collider** var_s0;
    Collider** var_s2;
    callback_8011DFAC temp_v0;

    for (var_s2 = colChkCtx->ocColliders; var_s2 < &colChkCtx->ocColliders[colChkCtx->nOCColliders]; var_s2++) {
        if ((*var_s2 == NULL) || (func_80061BF4(*var_s2) == 1)) {
            continue;
        }
        for (var_s0 = var_s2 + 1; var_s0 < &colChkCtx->ocColliders[colChkCtx->nOCColliders]; var_s0++) {
            if ((*var_s0 == NULL) || (func_80061BF4(*var_s0) == 1) || (func_80061C18(*var_s2, *var_s0) == 1)) {
                continue;
            }
            temp_v0 = D_8011DFAC[(*var_s2)->colType][(*var_s0)->colType];
            if (temp_v0 == NULL) {
                osSyncPrintf("CollisionCheck_OC():未対応 %d, %d\n", (*var_s2)->colType, (*var_s0)->colType);
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

void func_80061F64(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider,
                   ColliderElement* obj_elem) {
    f32 unkf;
    s32 i;
    u32 unk0;

    if (collider->actor != NULL && (collider->acFlags & 2)) {
        if ((obj_elem->acElemFlags & 2) && !(obj_elem->acElemFlags & 0x10)) {

            if (obj_elem->acHitElem == NULL) {
                __assert("pclobj_elem->ac_hit_elem != NULL", "../z_collision_check.c", 0x195D);
            }

            if (collider->actor->sub_98.damageChart == NULL) {
                unkf = (f32)obj_elem->acHitElem->atDmgInfo.damage - (f32)obj_elem->acDmgInfo.unk_05;
                if (unkf < 0.0f) {
                    unkf = 0.0f;
                }
            } else {
                unk0 = obj_elem->acHitElem->atDmgInfo.dmgFlags;

                for (i = 0; i < 32; i++) {
                    if (unk0 == 1) {
                        break;
                    }

                    unk0 >>= 1;
                }

                unkf = collider->actor->sub_98.damageChart->attack[i].raw & 0xF;
                collider->actor->sub_98.damageEffect = (collider->actor->sub_98.damageChart->attack[i].raw >> 4) & 0xF;
            }

            if (!(collider->acFlags & 4)) {
                collider->actor->sub_98.damage += unkf;
            }
            if (1) {}
            if (1) {}
        }
    }
}

void func_8006216C_Type0(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderSpheres* new_var2 = (ColliderSpheres*)collider;
    ColliderSpheres* new_var = (ColliderSpheres*)collider;
    s32 i;

    if (new_var->nElements <= 0 || new_var->elements == NULL) {
        return;
    }

    for (i = 0; i < new_var2->nElements; i++) {
        func_80061F64(globalCtx, colChkCtx, &new_var->base, &new_var->elements[i].base);
    }
}

void func_80062210_Type1(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderCylinder* new_var = (ColliderCylinder*)collider;

    func_80061F64(globalCtx, colChkCtx, collider, &new_var->elem);
}

void func_80062230_Type2(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    s32 i;
    ColliderTris* new_var = (ColliderTris*)collider;

    for (i = 0; i < new_var->nElements; i++) {
        func_80061F64(globalCtx, colChkCtx, &new_var->base, &new_var->elements[i].base);
    }
}

void func_800622C4_Type3(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderQuad* new_var = (ColliderQuad*)collider;

    func_80061F64(globalCtx, colChkCtx, collider, &new_var->elem);
}

typedef void (*func_ptr_800622E4)(GlobalContext*, CollisionCheckContext*, Collider*);

func_ptr_800622E4 D_8011E008[] = {
    func_8006216C_Type0,
    func_80062210_Type1,
    func_80062230_Type2,
    func_800622C4_Type3,
};

void func_800622E4(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    Collider* entry;
    s32 i;

    for (i = 0; i < colChkCtx->nACColliders; i++) {
        entry = colChkCtx->acColliders[i];

        if (entry == NULL) {
        } else if (entry->acFlags & 0x40) {
        } else {
            D_8011E008[entry->colType](globalCtx, colChkCtx, entry);
        }
    }
}

Linef D_8015E610;

s32 func_800623A4_Type0(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, Vec3f* arg3,
                        Vec3f* arg4) {
    ColliderSpheres* new_var;
    s32 i;
    ColliderSpheresElement* entry;

    new_var = (ColliderSpheres*)collider;
    for (i = 0; i < new_var->nElements; i++) {
        entry = new_var->elements + i;

        if (!(entry->base.ocElemFlags & 1)) {
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

s32 func_800624BC_Type1(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, Vec3f* arg3,
                        Vec3f* arg4) {
    ColliderCylinder* arg2 = (ColliderCylinder*)collider;

    if (!(arg2->elem.ocElemFlags & 1)) {
        return 0;
    }

    if (func_800CEE0C(&arg2->unk40, arg3, arg4, &D_8015E628, &D_8015E638) != 0) {
        return 1;
    }

    return 0;
}

typedef s32 (*func_ptr_80062530)(GlobalContext*, CollisionCheckContext*, Collider*, Vec3f*, Vec3f*);

func_ptr_80062530 D_8011E018[] = {
    func_800623A4_Type0,
    func_800624BC_Type1,
    NULL,
    NULL,
};

s32 func_80062530(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Vec3f* arg2, Vec3f* arg3, Actor** unkList,
                  s32 unkListCount) {
    func_ptr_80062530 func;
    s32 condition;
    s32 result = 0;
    s32 j;
    Collider** entryPtr = colChkCtx->ocColliders;
    Collider* entry;

    for (; entryPtr < colChkCtx->ocColliders + colChkCtx->nOCColliders; entryPtr++) {
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
        func = D_8011E018[entry->colType];

        if (func == NULL) {
            osSyncPrintf("CollisionCheck_generalLineOcCheck():未対応 %dタイプ\n", entry->colType);
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
void func_8006268C(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Vec3f* arg2, Vec3f* arg3) {
    func_80062530(globalCtx, colChkCtx, arg2, arg3, NULL, 0);
}

void func_800626B0(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Vec3f* arg2, Vec3f* arg3, Actor** arg4,
                   s32 arg5) {
    func_80062530(globalCtx, colChkCtx, arg2, arg3, arg4, arg5);
}

void ActorCollider_Type1_Update(Actor* actor, ColliderCylinder* collision) {
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
    ColliderQuadShape unk40;
} struct_80062734;

// uses not decompiled
void func_80062734(struct_80062734* arg0, Vec3f* cornerD, Vec3f* cornerC, Vec3f* cornerA, Vec3f* cornerB) {
    Math_Vec3f_Copy(&arg0->unk40.corners.cornerA, cornerA);
    Math_Vec3f_Copy(&arg0->unk40.corners.cornerB, cornerB);
    Math_Vec3f_Copy(&arg0->unk40.corners.cornerD, cornerD);
    Math_Vec3f_Copy(&arg0->unk40.corners.cornerC, cornerC);
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

void func_800628A4_Type0(s32 arg0, ColliderSpheres* jntSph) {
    static Vec3f D_8015CF00;
    // bss block number rollover!
    static Vec3f D_8015E648;

    s32 i;

    for (i = 0; i < jntSph->nElements; i++) {
        if (jntSph->elements[i].unk28.unk14 == arg0) {
            D_8015CF00.x = jntSph->elements[i].unk28.unk0.center.x;
            D_8015CF00.y = jntSph->elements[i].unk28.unk0.center.y;
            D_8015CF00.z = jntSph->elements[i].unk28.unk0.center.z;
            Matrix_MultVec3f(&D_8015CF00, &D_8015E648);
            jntSph->elements[i].unk28.unk8.center.x = D_8015E648.x;
            jntSph->elements[i].unk28.unk8.center.y = D_8015E648.y;
            jntSph->elements[i].unk28.unk8.center.z = D_8015E648.z;
            jntSph->elements[i].unk28.unk8.radius =
                (jntSph->elements[i].unk28.unk0.radius * jntSph->elements[i].unk28.unk10);
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
    D_8015CF10.unk49C[0].r = 128;
    D_8015CF10.unk49C[0].g = 0;
    D_8015CF10.unk49C[0].b = 0x40;
    D_8015CF10.unk49C[0].a = 0xFF;
    D_8015CF10.unk49C[1].r = 128;
    D_8015CF10.unk49C[1].g = 0;
    D_8015CF10.unk49C[1].b = 0x40;
    D_8015CF10.unk49C[1].a = 0xFF;
    D_8015CF10.unk49C[2].r = 0xFF;
    D_8015CF10.unk49C[2].g = 128;
    D_8015CF10.unk49C[2].b = 0;
    D_8015CF10.unk49C[2].a = 0xFF;
    D_8015CF10.unk49C[3].r = 0xFF;
    D_8015CF10.unk49C[3].g = 128;
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
    D_8015CF10.unk4AC[2].r = 128;
    D_8015CF10.unk4AC[2].g = 0;
    D_8015CF10.unk4AC[2].b = 0x40;
    D_8015CF10.unk4AC[2].a = 0;
    D_8015CF10.unk4AC[3].r = 128;
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
