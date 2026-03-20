#ifndef _Z_MIR_RAY_H_
#define _Z_MIR_RAY_H_

#include "ultra64.h"
#include "global.h"

struct MirRay;

typedef struct MirRay {
    /* 0x000 */ Actor actor;
    /* 0x14C */ ColliderSpheres unk14C;
    /* 0x16C */ ColliderSpheresElement unk16C;
    /* 0x1AC */ ColliderQuad unk1AC;
    /* 0x22C */ f32 unk22C;
    /* 0x230 */ Vec3f unk230[6];
    /* 0x278 */ f32 unk278;
    /* 0x27C */ Vec3f unk27C;
    /* 0x288 */ Vec3f unk288;
    /* 0x294 */ s16 unk294;
    /* 0x296 */ s16 unk296;
    /* 0x298 */ s16 unk298;
    /* 0x29A */ char pad29A[2];
    /* 0x29C */ LightNode* unk29C;
    /* 0x2A0 */ LightInfo unk2A0;
    /* 0x2AE */ u8 unk2AE;
    /* 0x2AF */ char pad2AF[1];
} MirRay; // size = 0x02B0

extern const ActorInit Mir_Ray_InitVars;

#endif
