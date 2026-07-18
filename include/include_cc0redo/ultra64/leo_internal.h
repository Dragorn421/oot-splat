#ifndef LEO_INTERNAL_H
#define LEO_INTERNAL_H

#include "unk.h"

extern OSPiHandle* LEOPiInfo;
extern u32 D_801E67F0;
extern s32 D_801E67F4;
extern s8 LEOdrive_flag;
void leointerrupt(void*);
void leomain(void*);
extern OSMesgQueue D_801E5A00;
extern void* D_801E5A18;
extern OSMesgQueue LEOblock_que;
extern void* LEOblock_que_buf;
extern OSThread LEOcommandThread;
extern OSMesgQueue LEOcommand_que;
extern OSMesgQueue LEOcontrol_que;
extern void* LEOcontrol_que_buf;
extern OSMesgQueue LEOdma_que;
extern void* LEOdma_que_buf;
extern OSMesgQueue LEOevent_que;
extern void* LEOevent_que_buf;
extern OSThread LEOinterruptThread;
extern STACK(LEOcommandThreadStack, 0x400);
extern STACK(LEOinterruptThreadStack, 0x400);
extern s32 __leoQueuesCreated;
UNK_RET leoClr_queue(void);
extern vu8 LEOclr_que_flag;
extern s32 __leoResetCalled;

#endif
