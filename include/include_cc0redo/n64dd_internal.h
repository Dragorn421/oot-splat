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

typedef struct struct_801E1598 {
    /* 0x00 */ char pad0[0x1C];
    /* 0x1C */ OSMesgQueue unk1C;
    /* 0x34 */ char pad34[4];
    /* 0x38 */ LEODiskID unk38;
    /* 0x58 */ void* unk58;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s8 unk64;
    /* 0x65 */ s8 unk65;
    /* 0x66 */ u8 unk66;
    /* 0x67 */ char pad67[1];
    /* 0x68 */ s32 unk68; // OSMesg
} struct_801E1598;        // size >= 0x6C

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
UNK_RET func_801C8EEC(void*, s32, s32, u8);
s8 func_801C8FD0(void);
s32 func_801C9020(void);
s32 func_801C905C(void);
s32 func_801C90A4(void);
s32 func_801C90BC(void);
s32 func_801C9114(void);
s32 func_801C916C(void);
void func_801C8D34(void*);
UNK_RET func_801C8E50(UNK_PTR, UNK_TYPE);
UNK_RET func_801CA3C0(s32, void (*)(void*, uintptr_t, size_t));
s32 func_801C8F9C(struct_801E1598*);

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
extern void (*D_801D3734)(UNK_PTR, UNK_PTR, UNK_PTR);
extern struct_801E1598 D_801E1598;
typedef struct struct_801E15FC {
    s8 unk0;
    s8 unk1;
} struct_801E15FC;
extern s32 D_801D3710;
extern s32 D_801E1604;
extern s32 D_801D36E4;
UNK_RET func_801C9400(void);
s32 func_801C9430(struct_801E1598*);
s32 func_801C948C(struct_801E1598*);
s32 func_801C97C8(struct_801E1598*);
s32 func_801C9870(struct_801E1598*);
s32 func_801C9934(struct_801E1598*);
s32 func_801C996C(struct_801E1598*);
extern UNK_PTR D_801D3724;
extern UNK_PTR D_801D372C;
extern UNK_PTR D_801D3730;
extern OSMesgQueue* D_801E1594;
UNK_RET func_801C8B40(struct_801E1598*);
UNK_RET func_801C92A0(UNK_TYPE);
UNK_RET func_801C92D4(void);
UNK_RET func_801C9228(UNK_TYPE);
UNK_RET func_801C925C(void);
s32 func_801C96E0(struct_801E1598*);
s32 func_801C978C(struct_801E1598*);
UNK_RET func_801C8AF8(struct_801E1598*);
UNK_RET func_801C91B0(s32);
s32 func_801C955C(struct_801E1598*);
UNK_PTR func_801CA800(s32);
UNK_PTR func_801CA698(s32);
UNK_PTR func_801CA86C(void);
UNK_PTR func_801CA8A0(s32);
UNK_PTR func_801CA8E0(void);
UNK_RET func_801C91E4(void);
UNK_PTR func_801CA730(void);
extern s32 (*D_801D36D4)(struct_801E1598*);
s32 func_801C9BA4(struct_801E1598*);
s32 func_801C9630(struct_801E1598*);
UNK_RET func_801C93C8(UNK_TYPE, UNK_TYPE, UNK_TYPE);
s32 func_801C999C(struct_801E1598*);
s32 func_801CA4B8(void);
UNK_RET func_801CA764(UNK_PTR, s32, UNK_TYPE);
extern UNK_TYPE D_801D4460;
extern UNK_TYPE D_801E1E00;
UNK_RET func_801CA628(UNK_PTR, s32);
extern UNK_TYPE D_801D3860;
extern UNK_TYPE D_801E1800;
UNK_RET func_801CA280(UNK_PTR, UNK_TYPE, const char*);
extern const char* D_801D3760[2][8][4];
extern UNK_TYPE D_801E4600;
void func_801CA4E4(u8*, u8, s32);
const char* func_801CA514(void);
UNK_RET func_801CA544(const char*, s32);
UNK_RET func_801CA5C4(char*, s32);
extern const char* D_801D3750[];
UNK_RET func_801C9D68(char*, u16);
s32 func_801CA3E0(s32);
int func_801C9CB0(const char*);
s32 func_801C9F0C(void*, int*, int*, int*, const char*);
s32 func_801CA034(void**, s32, s32, s32, s32, UNK_PTR, s32, s32, s32);
void func_801CA1C4(const char*, s32*, s32*);
extern void (*D_801D3740)(void*, uintptr_t, size_t);
extern s32 D_801E17F0;
void func_801C9E30(void*, uintptr_t, size_t);
s32 func_801C9E60(const char*);
s32 func_801C9EAC(s32*, int*, int*, int*, char);
u16 func_801C9D84(u16);
u16 func_801C9DA4(u16);

#endif
