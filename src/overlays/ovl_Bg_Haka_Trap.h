#ifndef BG_HAKA_TRAP_H
#define BG_HAKA_TRAP_H

#include "global.h"
#include "z64actor.h"

struct BgHakaTrap;

typedef void (*BgHakaTrapActionFunc)(struct BgHakaTrap*, GlobalContext*);

typedef struct BgHakaTrap {
    /* 0x000 */ DynaPolyActor dyna;
    /* 0x164 */ BgHakaTrapActionFunc unk164;
    /* 0x168 */ u8 unk168;
    /* 0x169 */ s8 unk169;
    /* 0x16A */ s16 unk16A;
    /* 0x16C */ Vec3f unk16C;
    /* 0x178 */ ColliderCylinder unk178;
    /* 0x1C4 */ struct_8005C7E0 unk1C4;
    /* 0x1E4 */ ColliderTrisElement unk1E4;
    /* 0x240 */ char pad240[0x5C];
} BgHakaTrap; // size = 0x29C

#endif
