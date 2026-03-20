#ifndef _Z_EN_FIREFLY_H_
#define _Z_EN_FIREFLY_H_

#include "ultra64.h"
#include "global.h"

struct EnFirefly;

typedef void (*EnFireflyActionFunc)(struct EnFirefly*, GlobalContext*);

typedef struct EnFirefly {
    /* 0x000 */ Actor actor;
    /* 0x14C */ Vec3f unk14C;
    /* 0x158 */ Vec3f unk158;
    /* 0x164 */ Vec3f unk164;
    /* 0x170 */ SkelAnime skelAnime;
    /* 0x1B4 */ EnFireflyActionFunc actionFunc;
    /* 0x1B8 */ u8 unk1B8;
    /* 0x1B9 */ u8 unk1B9;
    /* 0x1BA */ s16 unk1BA_timer;
    /* 0x1BC */ s16 unk1BC_targetRotX;
    /* 0x1BE */ Vec3s unk1BE[0x1C];
    /* 0x266 */ Vec3s unk266[0x1C];
    /* 0x310 */ f32 unk310_homeY;
    /* 0x314 */ ColliderSpheres unk314;
    /* 0x334 */ ColliderSpheresElement unk334[1];
} EnFirefly; // size = 0x0374

extern const ActorInit En_Firefly_InitVars;

#endif
