#ifndef BG_HAKA_TRAP_H
#define BG_HAKA_TRAP_H

#include "global.h"

struct BgHakaTrap;

typedef void (*BgHakaTrapActionFunc)(struct BgHakaTrap*, GlobalContext*);

typedef struct BgHakaTrap {
    /* 0x000 */ Actor actor;
    /* 0x14C */ u32 unk14C;
    /* 0x150 */ char pad150[0x14];
    /* 0x164 */ BgHakaTrapActionFunc unk164;
    /* 0x168 */ s8 unk168;
    /* 0x169 */ char pad169[1];
    /* 0x16A */ s16 unk16A;
    /* 0x16C */ char pad16C[0xC];
    /* 0x178 */ ColliderCylinder unk178;
    /* 0x1C4 */ struct_8005C7E0 unk1C4;
    /* 0x1E4 */ ColliderTrisElement unk1E4;
    /* 0x240 */ char pad240[0x5C];
} BgHakaTrap; // size = 0x29C

#endif
