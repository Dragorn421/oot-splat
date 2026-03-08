#ifndef Z64COLLISION_CHECK_H
#define Z64COLLISION_CHECK_H

#include "ultra64.h"

struct Actor;

typedef enum {
    COLTYPE_CYLINDER = 1,
    COLTYPE_CYLINDER_GROUP = 0,
    COLTYPE_QUAD = 3,
    COLTYPE_TRIANGLE_GROUP = 2
} ColliderType;

typedef struct {
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
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} ColliderBump; // size = 0x0C

typedef struct ColliderBody {
    /* 0x00 */ ColliderTouch toucher;
    /* 0x08 */ ColliderBump bumper;
    /* 0x14 */ u8 flags;
    /* 0x15 */ u8 toucherFlags;
    /* 0x16 */ u8 bumperFlags;
    /* 0x17 */ u8 flags2;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ struct ColliderBodyEntry* colBuf;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ struct ColliderBody* colliding;
} ColliderBody; // size = 0x28

// typedef struct ColliderBodyEntry {
//     /* 0x00 */ ColliderBody c;
//     /* 0x28 */ char unk_28[0x18];
// } ColliderBodyEntry; // size = 0x40

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

typedef struct ColliderBodySrc {
    /* 0x00 */ u8 bodyFlags;
    /* 0x01 */ u8 unk_09[0x3]; /* 000000 */
    /* 0x04 */ ColliderTouchSrc unk4;
    /* 0x0C */ ColliderBumpSrc unkC;
    /* 0x14 */ u8 toucherFlags; /* Attack Toucher Flags */
    /* 0x15 */ u8 bumperFlags; /* Bumper Flags */
    /* 0x16 */ u8 bodyFlags2;
    /* 0x17 */ u8 unk_1F; /* 00 */
} ColliderBodySrc; // size = 0x18

typedef struct {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 colliderFlags; /* Collider Flags */
    /* 0x02 */ u8 collideFlags; /* Collide Flags */
    /* 0x03 */ u8 maskA; /* Bitwise-And with Mask B */
    /* 0x04 */ u8 maskB; /* Bitwise-And with Mask A */
    /* 0x05 */ u8 type; /* Collider Type */
    /* 0x06 */ u8 unk_06[0x2]; /* 0000 */
} ColliderSrc; // size = 0x08

// typedef struct {
//     /* 0x00 */ s16 radius; /* Cylinder Radius */
//     /* 0x02 */ s16 height; /* Cylinder Height */
//     /* 0x04 */ s16 yShift; /* Shift Cylinder on Y Axis */
//     /* 0x06 */ Vec3s position; /* {X, Y, Z} position of Cylinder */
// } ColliderDimensions; // size = 0xC

// typedef struct {
//     /* 0x00 */ Collider base;
//     /* 0x18 */ ColliderBody body;
//     /* 0x40 */ ColliderDimensions dim;
// } ColliderCylinderMain; // size = 0x4C

// typedef struct {
//     /* 0x00 */func_8005D160_SetAT_3 ColliderBodyInfo body;
//     /* 0x08 */ ColliderBodyInfoInner inner;
//     /* 0x22 */ ColliderDimensions dim;
// } ColliderCylinderInit; // size = 0x2E

typedef struct struct_8005C328 {
    s16 unk0[6];
} struct_8005C328;

// ?

typedef struct struct_8005BA84_arg1_sub {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} struct_8005BA84_arg1_sub; /* size = 0x8 */

typedef struct struct_8005BA84_arg1 {
    struct_8005BA84_arg1_sub unk0;
    char unk_8[8];
    f32 unk10;
    u8 unk14;
} struct_8005BA84_arg1; /* size = 0x18 */

typedef struct struct_8005BA84_arg2 {
    u8 unk0;
    struct_8005BA84_arg1_sub unk2;
    s16 unkA;
} struct_8005BA84_arg2; /* size >= 0xC */

// type0

typedef struct struct_8011DE54 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} struct_8011DE54; /* size = 0x18 */

typedef struct Collider_Type0_ptr1C {
    ColliderBody unk0;
    struct_8011DE54 unk28;
} Collider_Type0_ptr1C; /* size = 0x40 */

typedef struct Collider_Type0 {
    Collider unk0;
    s32 unk18;
    Collider_Type0_ptr1C* unk1C;
} Collider_Type0;

typedef struct struct_8005BB48_arg2_sub {
    /* 0x00 */ u8 bodyFlags;
    /* 0x01 */ u8 unk_09[0x3]; /* 000000 */
    /* 0x04 */ s32 toucherMask; /* Attack Toucher Exclusion Mask */
    /* 0x08 */ u8 bumperEffect; /* Damage Effect (Knockback, Fire, etc.) */
    /* 0x09 */ u8 toucherDamage; /* Damage Amount or Stun Timer */
    /* 0x0A */ u8 unk_12[0x2]; /* 0000 */
    /* 0x0C */ s32 bumperMask; /* Bumper Exclusion Mask */
    /* 0x10 */ u8 unk_18[0x4]; /* 00000000 */
    /* 0x14 */ u8 toucherFlags; /* Attack Toucher Flags */
    /* 0x15 */ u8 bumperFlags; /* Bumper Flags */
    /* 0x16 */ u8 bodyFlags2;
    /* 0x17 */ u8 unk_1F; /* 00 */
} struct_8005BB48_arg2_sub;

typedef struct struct_8005BB48_arg2 {
    struct_8005BB48_arg2_sub unk0;
    struct_8005BA84_arg2 unk18;
} struct_8005BB48_arg2; /* size = 0x24 */

typedef struct ColliderSrc_Type0 {
    ColliderSrc unk0;
    s32 unk8;
    struct_8005BB48_arg2* unkC;
} ColliderSrc_Type0;

// type1

typedef struct Collider_Type1 {
    Collider unk0;
    ColliderBody unk18;
    struct_8005C328 unk40;
} Collider_Type1;

typedef struct struct_8005C450_Type1_suba {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ char pad5[3];
} struct_8005C450_Type1_suba; /* size = 8 */

typedef struct struct_8005C450_Type1_subb {
    char unk_0[0x18];
} struct_8005C450_Type1_subb; /* size = 0x1A */

typedef struct struct_8005C450_Type1_ColliderSrc {
    struct_8005C450_Type1_suba unk0;
    struct_8005C450_Type1_subb unk8;
    struct_8005C328 unk20;
} struct_8005C450_Type1_ColliderSrc;

typedef struct Type1_ColliderSrc_alt {
    /* 0x000 */ ColliderSrc unk0;
    /* 0x008 */ ColliderBodySrc unk8;
    /* 0x020 */ struct_8005C328 unk20;
    /* 0x02C */ char pad2C[0x100]; /* unk size */
} Type1_ColliderSrc_alt;

// type2

typedef struct Collider_Type2_ptr1C {
    char unk_0[0x5C];
} Collider_Type2_ptr1C;

typedef struct Collider_Type2 {
    Collider unk0;
    s32 unk18;
    Collider_Type2_ptr1C* unk1C;
} Collider_Type2;

// type3

typedef struct ColliderSrc_Type3 {
    ColliderSrc unk0;
    ColliderBodySrc unk8;
    Vec3f unk20[4];
} ColliderSrc_Type3;

typedef struct struct_Collider_Type3_subb {
    char unk_0[0x28];
} struct_Collider_Type3_subb; /* size = 0x28 */

typedef struct struct_Collider_Type3_subc {
    char unk_0[0x100]; /* unk size */
} struct_Collider_Type3_subc;

typedef struct Collider_Type3 {
    Collider unk0;
    struct_Collider_Type3_subb unk18;
    struct_Collider_Type3_subc unk40;
} Collider_Type3;

#endif
