#ifndef Z64COLLISION_CHECK_H
#define Z64COLLISION_CHECK_H

#include "ultra64.h"
#include "z64math.h"

struct Actor;

typedef enum {
    /* 0 */ COLTYPE_JNTSPH,
    /* 1 */ COLTYPE_CYLINDER,
    /* 2 */ COLTYPE_TRIANGLES,
    /* 3 */ COLTYPE_QUAD,
    /* 4 */ COLTYPE_MAX
} ColliderType;

typedef struct Collider {
    /* 0x00 */ struct Actor* actor;
    /* 0x04 */ struct Actor* at;
    /* 0x08 */ struct Actor* ac;
    /* 0x0C */ struct Actor* ot;
    /* 0x10 */ u8 colliderFlags; /* Compared to 0x11 */
    /* 0x11 */ u8 collideFlags; /* Compared to 0x10 */
    /* 0x12 */ u8 maskA; /* Bitwise-and compared to 0x13 */
    /* 0x13 */ u8 maskB; /* Bitwise-and compared to 0x12 */
    /* 0x14 */ u8 unk_14;
    /* 0x15 */ u8 type; /* Cylinder Collection, Cylinder, Triangle Collection, Quad */
} Collider; // size = 0x18

typedef struct {
    /* 0x00 */ s32 flags; /* Toucher Attack Identifier Flags */
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 damage; /* Damage or Stun Timer */
} ColliderTouch; // size = 0x08

typedef struct {
    /* 0x00 */ s32 flags; /* Collision Exclusion Mask */
    /* 0x04 */ u8 effect; /* Damage Effect (Knockback, Fire, etc.) */
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ Vec3s unk_06;
} ColliderBump; // size = 0x0C

typedef struct ColliderElement {
    /* 0x00 */ ColliderTouch toucher;
    /* 0x08 */ ColliderBump bumper;
    /* 0x14 */ u8 flags;
    /* 0x15 */ u8 toucherFlags;
    /* 0x16 */ u8 bumperFlags;
    /* 0x17 */ u8 flags2;
    /* 0x18 */ struct Collider* unk_18;
    /* 0x1C */ struct Collider* colBuf;
    /* 0x20 */ struct ColliderElement* unk_20;
    /* 0x24 */ struct ColliderElement* colliding;
} ColliderElement; // size = 0x28

typedef struct ColliderTouchSrc {
     s32 toucherMask; /* Attack Toucher Exclusion Mask */
     u8 bumperEffect; /* Damage Effect (Knockback, Fire, etc.) */
     u8 toucherDamage; /* Damage Amount or Stun Timer */
    /* 0x0A */ u8 unk_12[0x2]; /* 0000 */
} ColliderTouchSrc;

typedef struct ColliderBumpSrc {
    s32 bumperMask; /* Bumper Exclusion Mask */
    u8 unk4;
    u8 unk5;
} ColliderBumpSrc;

typedef struct ColliderElementSrc {
    /* 0x00 */ u8 bodyFlags;
    /* 0x01 */ u8 unk_09[0x3]; /* 000000 */
    /* 0x04 */ ColliderTouchSrc unk4;
    /* 0x0C */ ColliderBumpSrc unkC;
    /* 0x14 */ u8 toucherFlags; /* Attack Toucher Flags */
    /* 0x15 */ u8 bumperFlags; /* Bumper Flags */
    /* 0x16 */ u8 bodyFlags2;
    /* 0x17 */ u8 unk_1F; /* 00 */
} ColliderElementSrc; // size = 0x18

typedef struct {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 colliderFlags; /* Collider Flags */
    /* 0x02 */ u8 collideFlags; /* Collide Flags */
    /* 0x03 */ u8 maskA; /* Bitwise-And with Mask B */
    /* 0x04 */ u8 maskB; /* Bitwise-And with Mask A */
    /* 0x05 */ u8 type; /* Collider Type */
    /* 0x06 */ u8 unk_06[0x2]; /* 0000 */
} ColliderSrc; // size = 0x08

typedef struct ColliderSrc_8005B6EC {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    char unk_5[3];
} ColliderSrc_8005B6EC;

typedef struct ColliderSrc_8005B6B0 {
    struct Actor* unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
} ColliderSrc_8005B6B0;

// ?

typedef struct struct_8005BA84_arg1_sub {
    Vec3s unk0;
    s16 unk6;
} struct_8005BA84_arg1_sub; /* size = 0x8 */

typedef struct ColliderSrc_Type0_ptrC_sub18 {
    u8 unk0;
    struct_8005BA84_arg1_sub unk2;
    s16 unkA;
} ColliderSrc_Type0_ptrC_sub18; /* size >= 0xC */

// type0 - jntsph

typedef struct struct_8011DE54 {
    struct_8005BA84_arg1_sub unk0;
    Sphere16 unk8;
    f32 unk10;
    u8 unk14;
} struct_8011DE54; /* size = 0x18 */

typedef struct Collider_Type0_ptr1C {
    ColliderElement base;
    struct_8011DE54 unk28;
} Collider_Type0_ptr1C; /* size = 0x40 */

typedef struct ColliderJntSph {
    Collider base;
    s32 unk18;
    Collider_Type0_ptr1C* unk1C;
} ColliderJntSph;

typedef struct ColliderSrc_Type0_ptrC {
    ColliderElementSrc unk0;
    ColliderSrc_Type0_ptrC_sub18 unk18;
} ColliderSrc_Type0_ptrC; /* size = 0x24 */

typedef struct ColliderSrc_Type0 {
    ColliderSrc unk0;
    s32 unk8;
    ColliderSrc_Type0_ptrC* unkC;
} ColliderSrc_Type0;

typedef struct ColliderSrc_Type0_8005B6B0 {
    ColliderSrc_8005B6B0 unk0;
    s32 unk8;
    ColliderSrc_Type0_ptrC* unkC;
} ColliderSrc_Type0_8005B6B0;

typedef struct ColliderSrc_Type0_8005B6EC {
    ColliderSrc_8005B6EC unk0;
    s32 unk8;
    ColliderSrc_Type0_ptrC* unkC;
} ColliderSrc_Type0_8005B6EC;

// type1 - cylinder

typedef struct ColliderCylinder {
    Collider base;
    ColliderElement unk18;
    Cylinder16 unk40;
} ColliderCylinder;

typedef struct ColliderSrc_Type1 {
    /* 0x00 */ ColliderSrc unk0;
    /* 0x08 */ ColliderElementSrc unk8;
    /* 0x20 */ Cylinder16 unk20;
} ColliderSrc_Type1;

typedef struct ColliderSrc_Type1_8005B6EC {
    ColliderSrc_8005B6EC unk0;
    ColliderElementSrc unk8;
    Cylinder16 unk20;
} ColliderSrc_Type1_8005B6EC;

typedef struct ColliderSrc_Type1_8005B6B0 {
    /* 0x00 */ ColliderSrc_8005B6B0 unk0;
    /* 0x08 */ ColliderElementSrc unk8;
    /* 0x20 */ Cylinder16 unk20;
} ColliderSrc_Type1_8005B6B0;

// type2 - tris

typedef struct ColliderSrc_Type2_ptrC {
    ColliderElementSrc unk0;
    Vec3f unk18;
    char unk_24[0x18];
} ColliderSrc_Type2_ptrC; /* size = 0x48 */

typedef struct ColliderSrc_Type2 {
    ColliderSrc unk0;
    s32 unk8;
    ColliderSrc_Type2_ptrC* unkC;
} ColliderSrc_Type2;

typedef struct ColliderSrc_Type2_8005B6EC {
    ColliderSrc_8005B6EC unk0;
    s32 unk8;
    ColliderSrc_Type2_ptrC* unkC;
} ColliderSrc_Type2_8005B6EC;

typedef struct Collider_Type2_ptr1C {
    ColliderElement base;
    TriNorm unk28;
} Collider_Type2_ptr1C; /* size = 0x5C */

typedef struct ColliderTris {
    Collider base;
    s32 unk18;
    Collider_Type2_ptr1C* unk1C;
} ColliderTris;

// type3 - quad

typedef struct ColliderSrc_Type3 {
    ColliderSrc unk0;
    ColliderElementSrc unk8;
    Vec3f unk20[4];
} ColliderSrc_Type3;

typedef struct ColliderSrc_Type3_8005B6EC {
    /* 0x00 */ ColliderSrc_8005B6EC unk0;
    /* 0x08 */ ColliderElementSrc unk8;
    /* 0x20 */ Vec3f unk20[4];
} ColliderSrc_Type3_8005B6EC;

typedef struct struct_Collider_Type3_subc {
    /* 0x00 */ Vec3f unk0;
    /* 0x0C */ Vec3f unkC;
    /* 0x18 */ Vec3f unk18;
    /* 0x24 */ Vec3f unk24;
    /* 0x30 */ Vec3s unk30;
    /* 0x36 */ Vec3s unk36;
    /* 0x3C */ f32 unk3C;
} struct_Collider_Type3_subc; /* size = 0x40 */

typedef struct ColliderQuad {
    Collider base;
    ColliderElement unk18;
    struct_Collider_Type3_subc unk40;
} ColliderQuad;

// ?

typedef struct struct_ColChkCtx_290 {
    char unk_0[0x18];
    u16 unk18;
} struct_ColChkCtx_290;

#endif
