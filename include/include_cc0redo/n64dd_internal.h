#ifndef N64DD_INTERNAL_H
#define N64DD_INTERNAL_H

#include "ultra64.h"

void func_801C77F0(void);
void func_801C7838(void);
void func_801C7898(void);
void func_801C78D8(void);
void func_801C7B28(void);
void func_801C8214(s32, void*, s32);
void func_801C843C(s32, s32*, s32*);
s32 func_801C84E0(s32);

extern void *D_801D36D0;
extern s8 D_801DA638;
typedef struct struct_801DA640 {
    s32 unk0;
    s32 unk4;
} struct_801DA640; // size >= 8
extern struct_801DA640 D_801DA640;

#endif
