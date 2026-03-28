#ifndef _Z_EN_TR_H_
#define _Z_EN_TR_H_

#include "ultra64.h"
#include "global.h"

struct EnTr;

typedef struct EnTr {
    /* 0x000 */ Actor actor;
    /* 0x14C */ SkelAnime unk14C;
    /* 0x190 */ Vec3s unk190;
    /* 0x196 */ char pad196[0x9C]; /* maybe part of unk190[0x1B]? */
    /* 0x232 */ Vec3s unk232;
    /* 0x238 */ char pad238[0x9C]; /* maybe part of unk232[0x1B]? */
    /* 0x2D4 */ s16 unk2D4;
    /* 0x2D6 */ u16 unk2D6;
    /* 0x2D8 */ s16 unk2D8;
    /* 0x2DA */ char pad2DA[2];
    /* 0x2DC */ void (*unk2DC)(Actor*, GlobalContext*);
    /* 0x2E0 */ s16 unk2E0;
    /* 0x2E2 */ s16 unk2E2;
    /* 0x2E4 */ AnimationHeader* unk2E4;
} EnTr; // size = 0x2E8

extern const ActorInit En_Tr_InitVars;

#endif
