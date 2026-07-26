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

void leoCommand(void* CDB) {
    LEOCmdHeader* header = CDB;

    if (__leoResetCalled != 0) {
        header->status = 2;
        header->sense = 0x25;
        if (header->control & 0x80) {
            osSendMesg(header->post, (void*)0x25, 1);
        }
    } else {
        osRecvMesg(&LEOblock_que, NULL, 1);
        header->status = 8;
        header->sense = 0;
        switch (header->command) {
            case 1:
                LEOclr_que_flag = 0xFF;
                leoClr_queue();
                LEOclr_que_flag = 0;
                header->status = 0;
                if (header->control & 0x80) {
                    osSendMesg(header->post, NULL, 1);
                }
                break;
            case 5:
            case 6:
                ((LEOCmdRead*)CDB)->rw_bytes = 0;
                goto label;
            default:
                if ((u32)(header->command - 1) >= 0xEU) {
                    header->sense = 0x1F;
                    header->status = 2;
                } else {
                label:
                    if (osSendMesg(&LEOcommand_que, CDB, 0) != 0) {
                        header->sense = 0x23;
                        header->status = 2;
                    }
                }
                break;
        }
        osSendMesg(&LEOblock_que, NULL, 1);
    }
}

extern LEOCmdHeader D_801D9C30;
void LeoReset(void) {
    __leoResetCalled = 1;
    if (__leoQueuesCreated != 0) {
        LEOclr_que_flag = 0xFF;
        leoClr_queue();
        LEOclr_que_flag = 0;
        osRecvMesg(&LEOevent_que, NULL, 0);
        osSendMesg(&LEOevent_que, (void*)0xA0000, 1);
        osSendMesg(&LEOcommand_que, &D_801D9C30, 1);
    }
}

s32 __leoSetReset(void) {
    leoDrive_reset();
    return 0;
}

s32 LeoResetClear(void) {
    LEOCmdHeader cmd;

    cmd.command = 0xF;
    cmd.control = 0x80;
    cmd.status = 0;
    cmd.post = &D_801E5A00;
    if (osSendMesg(&LEOcommand_que, &cmd, 0) != 0) {
        return 0x23;
    }
    osRecvMesg(&D_801E5A00, NULL, 1);
    if (cmd.status == 0) {
        return 0;
    } else {
        return cmd.sense;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/B8E6A0/D_801D9C30.s")
