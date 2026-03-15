#ifndef BG_HAKA_TRAP_H
#define BG_HAKA_TRAP_H

#include "global.h"

typedef struct BgHakaTrap {
    /* 0x000 */ Actor actor;
    /* 0x14C */ char unk_14C[0x29C - 0x14C];
} BgHakaTrap;

#endif
