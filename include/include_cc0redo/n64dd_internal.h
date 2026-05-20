#ifndef N64DD_INTERNAL_H
#define N64DD_INTERNAL_H

#include "ultra64.h"
#include "n64dd.h"
#include "stack.h"
#include "irqmgr.h"

extern IrqMgr gIrqMgr; // from main.c

typedef struct struct_801DA5D0 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ char pad1[3];
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s8 unk8;
    /* 0x09 */ char pad9[3];
    /* 0x0C */ void (*unkC)(s32, s32, s32);
    /* 0x10 */ s32 unk10;
    /* 0x14 */ void (*unk14)(void*, uintptr_t, size_t);
    /* 0x18 */ void* unk18;
    union { // different substruct based on struct_801DA5D0.unk0 ? see func_801C8860
        struct {
            /* 0x1C */ OSMesgQueue* unk1C;
            /* 0x20 */ OSMesgQueue* unk20;
            /* 0x24 */ s32 unk24;
            /* 0x28 */ void* unk28;
            /* 0x2C */ s32 unk2C;
        } unk1C_1;
        struct {
            /* 0x1C */ s32 unk1C;
            /* 0x20 */ s32 unk20;
        } unk1C_3_4;
    };
} struct_801DA5D0; // size >= 0x30

void func_801C77F0(void);
void func_801C7838(void);
void func_801C7898(void);
void func_801C78D8(void);
void func_801C7B28(void);
s32 func_801C843C(s32, s32*, s32*);
s32 func_801C84E0(s32);
void func_800F6BDC(void);
void func_800F6B3C(void);
s32 func_801C7924(void);
s32 func_801C7958(void);
s32 func_801C8860(struct_801DA5D0*);
void func_801C7E94(void);
s32 func_801C8A24(void);
UNK_RET func_801CAA60(s32, UNK_TYPE, UNK_TYPE, UNK_TYPE, s32, s32, s32, s32);
UNK_RET func_801C9318(void);
UNK_RET func_801C8DB4(void);
void func_801C8DD8(OSMesgQueue*, OSMesgQueue*, s32, void*, s32);
UNK_RET func_801C8E98(void (*)(s32, s32, s32), s32, void (*)(void*, uintptr_t, size_t));
UNK_RET func_801C8EEC(void*, s32, s32, UNK_TYPE);
s8 func_801C8FD0(void);
s32 func_801C9020(void);
s32 func_801C905C(void);
s32 func_801C90A4(void);
s32 func_801C90BC(void);
s32 func_801C9114(void);
s32 func_801C916C(void);
void func_801C8D34(void*);

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
typedef struct struct_801C79DC {
    /* 0x00 */ OSMesg unk0[30];
    /* 0x78 */ OSMesgQueue unk78;
    /* 0x90 */ IrqMgrClient unk90;
    /* 0x98 */ IrqMgr* unk98;
} struct_801C79DC; // size >= 0x9C
extern struct_801C79DC D_801DA410;
extern OSMesgQueue D_801DA600;
extern OSMesgQueue D_801DA618;
extern OSMesg D_801DA630;
extern OSMesg D_801DA634;
extern OSThread D_801DA658;
extern STACK(D_801DA808, 0x1000);
extern StackEntry D_801DB808;
extern STACK(D_801DB828, 0x1000);
extern StackEntry D_801DC828;
extern void* D_801DC848;
extern s32 D_801D3720;
extern s32 D_801D36E0;
extern OSThread D_801E1630;
typedef struct struct_801E1590 {
    /* 0x0 */ OSMesgQueue* unk0;
    /* 0x4 */ OSMesgQueue* unk4;
} struct_801E1590; // size >= 8
extern struct_801E1590 D_801E1590;

#endif
