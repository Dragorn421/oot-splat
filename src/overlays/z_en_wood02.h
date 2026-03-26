#ifndef _Z_EN_WOOD02_H_
#define _Z_EN_WOOD02_H_

#include "ultra64.h"
#include "global.h"

struct EnWood02;

typedef struct EnWood02 {
    /* 0x000 */ Actor actor;
    /* 0x14C */ s16 unk14C;
    /* 0x14E */ u8 unk14E[5];
    /* 0x153 */ u8 unk153;
    /* 0x154 */ u8 unk154;
    /* 0x155 */ char pad155[3];
    /* 0x158 */ ColliderCylinder unk158;
} EnWood02; // size = 0x1A4

extern const ActorInit En_Wood02_InitVars;

#endif
