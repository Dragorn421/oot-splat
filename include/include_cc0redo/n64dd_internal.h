#ifndef N64DD_INTERNAL_H
#define N64DD_INTERNAL_H

#include "ultra64.h"
#include "n64dd.h"

typedef struct struct_801DA5D0 {
    /* 0x00 */ s8 unk0;
    /* 0x01 */ char pad1[0x17];
    /* 0x18 */ void* unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
} struct_801DA5D0; // size >= 0x24

void func_801C77F0(void);
void func_801C7838(void);
void func_801C7898(void);
void func_801C78D8(void);
void func_801C7B28(void);
void func_801C8214(s32, void*, s32);
s32 func_801C843C(s32, s32*, s32*);
s32 func_801C84E0(s32);
void func_800F6BDC(void);
void func_800F6B3C(void);
s32 func_801C7924(void);
s32 func_801C7958(void);
s32 func_801C8860(struct_801DA5D0*);
void func_801C7E94(void);
s32 func_801C8A24(void);

extern void* D_801D36D0;
extern volatile u8 D_801DA638;
extern volatile OSTime D_801DA640;
typedef struct struct_801DA5C8 {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ void* unk8;
    /* 0x00C */ void* unkC;
    /* 0x010 */ n64ddStruct_80121220* unk10;
    /* 0x014 */ char pad14[0x104];
} struct_801DA5C8; // size = 0x118
extern struct_801DA5C8* D_801DA5C8;
extern struct_801DA5C8 D_801DA4B0;
extern s32 D_801DA648;
extern s32 D_801D3728;
extern s32 D_801E17E0;
extern s32 D_801E17E4;
extern struct_801DA5D0 D_801DA5D0;
extern s32 D_801DA64C;
extern s32 D_801DA650;
extern s32 D_801DA654;

#endif
