#include "common.h"

void leoInitialize(s32 PRI_WRK, s32 PRI_INT, void** command_que_buf, u32 cmd_buff_size) {
    s32 sp2C;
    s32 sp28;
    s32 temp_v0;
    s32 sp20;

    if (PRI_INT < PRI_WRK) {
        sp20 = PRI_WRK;
    } else {
        sp20 = PRI_INT;
    }
    sp28 = -1;
    temp_v0 = osGetThreadPri(NULL);
    if (temp_v0 < sp20) {
        sp28 = temp_v0;
        osSetThreadPri(NULL, sp20);
    }
    sp2C = __osDisableInt();
    __leoQueuesCreated = 1;
    osCreateMesgQueue(&LEOcommand_que, command_que_buf, (s32)cmd_buff_size);
    osCreateMesgQueue(&LEOcontrol_que, &LEOcontrol_que_buf, 1);
    osCreateMesgQueue(&LEOevent_que, &LEOevent_que_buf, 1);
    osCreateMesgQueue(&LEOdma_que, &LEOdma_que_buf, 2);
    osCreateMesgQueue(&LEOblock_que, &LEOblock_que_buf, 1);
    osCreateMesgQueue(&D_801E5A00, &D_801E5A18, 1);
    osCreateThread(&LEOcommandThread, 1, leomain, NULL, STACK_TOP(LEOcommandThreadStack), PRI_WRK);
    osStartThread(&LEOcommandThread);
    osCreateThread(&LEOinterruptThread, 1, leointerrupt, NULL, STACK_TOP(LEOinterruptThreadStack), PRI_INT);
    osStartThread(&LEOinterruptThread);
    osSetEventMesg(2U, &LEOevent_que, (void*)0x30000);
    osSendMesg(&LEOblock_que, NULL, 0);
    __osRestoreInt(sp2C);
    if (sp28 != -1) {
        osSetThreadPri(NULL, sp28);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/B8E6A0/leoCommand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8E6A0/LeoReset.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8E6A0/__leoSetReset.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8E6A0/LeoResetClear.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B8E6A0/D_801D9C30.s")
