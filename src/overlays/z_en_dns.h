#ifndef _Z_EN_DNS_H_
#define _Z_EN_DNS_H_

#include "ultra64.h"
#include "global.h"

struct EnDns;

typedef struct struct_EnDns_2C0ptr {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ UNK_TYPE unk4;
    /* 0x08 */ u32 (*unk8)(struct EnDns*);
    /* 0x0C */ void (*unkC)(struct EnDns*);
} struct_EnDns_2C0ptr;

typedef struct EnDns {
    /* 0x0000 */ Actor actor;
    /* 0x14C */ SkelAnime unk14C;
    /* 0x190 */ Vec3s unk190;
    /* 0x196 */ char pad196[0x66]; /* maybe part of unk190[0x12]? */
    /* 0x1FC */ Vec3s unk1FC;
    /* 0x202 */ char pad202[0x66]; /* maybe part of unk1FC[0x12]? */
    /* 0x268 */ void (*unk268)(struct EnDns*, GlobalContext*);
    /* 0x26C */ ColliderCylinder unk26C;
    /* 0x2B8 */ s16 unk2B8;
    /* 0x2BA */ u8 unk2BA;
    /* 0x2BB */ u8 unk2BB;
    /* 0x2BC */ u8 unk2BC;
    /* 0x2BD */ s8 unk2BD;
    /* 0x2BE */ char pad2BE[2]; /* maybe part of unk2BD[3]? */
    /* 0x2C0 */ struct_EnDns_2C0ptr* unk2C0;
    /* 0x2C4 */ f32 unk2C4;
} EnDns; // size = 0x02C8

extern const ActorInit En_Dns_InitVars;

#endif
