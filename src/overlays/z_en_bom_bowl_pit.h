#ifndef _Z_EN_BOM_BOWL_PIT_H_
#define _Z_EN_BOM_BOWL_PIT_H_

#include "ultra64.h"
#include "global.h"

struct EnBomBowlPit;

typedef void (*EnBomBowlPitActionFunc)(struct EnBomBowlPit*, GlobalContext*);

typedef struct EnBomBowlPit {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ EnBomBowlPitActionFunc unk14C;
    /* 0x0150 */ char pad150[2];
    /* 0x0152 */ s16 unk152;
    /* 0x0154 */ s16 unk154;
    /* 0x0156 */ s16 unk156;
    /* 0x0158 */ s16 unk158;
    /* 0x015A */ s16 unk15A;
    /* 0x015C */ s16 unk15C;
    /* 0x015E */ char pad15E[2];
    /* 0x0160 */ s32 unk160;
    /* 0x0164 */ u8 unk164;
    /* 0x0165 */ char pad165[3]; /* maybe part of unk164[4]? */
    /* 0x0168 */ Vec3f unk168;
    /* 0x0174 */ Vec3f unk174;
    /* 0x0180 */ Vec3f unk180;
    /* 0x018C */ Vec3f unk18C;
    /* 0x0198 */ f32 unk198;
    /* 0x019C */ f32 unk19C;
    /* 0x01A0 */ f32 unk1A0;
    /* 0x01A4 */ f32 unk1A4;
    /* 0x01A8 */ f32 unk1A8;
    /* 0x01AC */ f32 unk1AC;
    /* 0x01B0 */ f32 unk1B0;
    /* 0x01B4 */ f32 unk1B4;
    /* 0x01B8 */ f32 unk1B8;
    /* 0x01BC */ f32 unk1BC;
    /* 0x01C0 */ f32 unk1C0;
    /* 0x01C4 */ f32 unk1C4;
    /* 0x01C8 */ f32 unk1C8;
    /* 0x01CC */ f32 unk1CC;
    /* 0x01D0 */ f32 unk1D0;
    /* 0x01D4 */ f32 unk1D4;
    /* 0x01D8 */ f32 unk1D8;
    /* 0x01DC */ f32 unk1DC;
    /* 0x01E0 */ Actor* unk1E0;
    /* 0x01E4 */ char pad1E4[0x3520];
} EnBomBowlPit; // size = 0x3704

extern const ActorInit En_Bom_Bowl_Pit_InitVars;

#endif
