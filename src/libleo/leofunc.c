#include "common.h"

s32 __leoResetCalled = 0;
s32 __leoQueuesCreated = 0;

OSMesgQueue LEOpost_que;
OSMesg LEOpost_que_buf;

void leoInitialize(OSPri compri, OSPri intpri, void** command_que_buf, u32 cmd_buff_size) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;
    OSPri pri;

    if (intpri < compri) {
        pri = compri;
    } else {
        pri = intpri;
    }
    oldPri = -1;
    myPri = osGetThreadPri(NULL);
    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri(NULL, pri);
    }
    savedMask = __osDisableInt();
    __leoQueuesCreated = 1;
    osCreateMesgQueue(&LEOcommand_que, command_que_buf, (s32)cmd_buff_size);
    osCreateMesgQueue(&LEOcontrol_que, &LEOcontrol_que_buf, 1);
    osCreateMesgQueue(&LEOevent_que, &LEOevent_que_buf, 1);
    osCreateMesgQueue(&LEOdma_que, LEOdma_que_buf, ARRAY_COUNT(LEOdma_que_buf));
    osCreateMesgQueue(&LEOblock_que, &LEOblock_que_buf, 1);
    osCreateMesgQueue(&LEOpost_que, &LEOpost_que_buf, 1);
    osCreateThread(&LEOcommandThread, 1, leomain, NULL, STACK_TOP(LEOcommandThreadStack), compri);
    osStartThread(&LEOcommandThread);
    osCreateThread(&LEOinterruptThread, 1, leointerrupt, NULL, STACK_TOP(LEOinterruptThreadStack), intpri);
    osStartThread(&LEOinterruptThread);
    osSetEventMesg(2, &LEOevent_que, (void*)0x30000);
    osSendMesg(&LEOblock_que, NULL, OS_MESG_NOBLOCK);
    __osRestoreInt(savedMask);
    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}

void leoCommand(void* cmd_blk_addr) {
    LEOCmdHeader* header = cmd_blk_addr;

    if (__leoResetCalled != 0) {
        header->status = 2;
        header->sense = 0x25;
        if (header->control & 0x80) {
            osSendMesg(header->post, (OSMesg)0x25, OS_MESG_BLOCK);
        }
    } else {
        osRecvMesg(&LEOblock_que, NULL, OS_MESG_BLOCK);
        header->status = 8;
        header->sense = 0;
        switch (header->command) {
            case 1:
                LEOclr_que_flag = 0xFF;
                leoClr_queue();
                LEOclr_que_flag = 0;
                header->status = 0;
                if (header->control & 0x80) {
                    osSendMesg(header->post, NULL, OS_MESG_BLOCK);
                }
                break;
            case 5:
            case 6:
                ((LEOCmdRead*)cmd_blk_addr)->rw_bytes = 0;
                goto cmd_queing;
            default:
                if ((u32)(header->command - 1) >= 0xE) {
                    header->sense = 0x1F;
                    header->status = 2;
                } else {
                cmd_queing:
                    if (osSendMesg(&LEOcommand_que, cmd_blk_addr, OS_MESG_NOBLOCK) != 0) {
                        header->sense = 0x23;
                        header->status = 2;
                    }
                }
                break;
        }
        osSendMesg(&LEOblock_que, NULL, OS_MESG_BLOCK);
    }
}

const u8 zero[] = { 0 };

void LeoReset(void) {
    __leoResetCalled = 1;
    if (__leoQueuesCreated != 0) {
        LEOclr_que_flag = 0xFF;
        leoClr_queue();
        LEOclr_que_flag = 0;
        osRecvMesg(&LEOevent_que, NULL, OS_MESG_NOBLOCK);
        osSendMesg(&LEOevent_que, (OSMesg)0xA0000, OS_MESG_BLOCK);
        osSendMesg(&LEOcommand_que, zero, OS_MESG_BLOCK);
    }
}

s32 __leoSetReset(void) {
    leoDrive_reset();
    return 0;
}

s32 LeoResetClear(void) {
    LEOCmdHeader resetclear;

    resetclear.command = 0xF;
    resetclear.control = 0x80;
    resetclear.status = 0;
    resetclear.post = &LEOpost_que;
    if (osSendMesg(&LEOcommand_que, &resetclear, OS_MESG_NOBLOCK) != 0) {
        return 0x23;
    }
    osRecvMesg(&LEOpost_que, NULL, OS_MESG_BLOCK);
    if (resetclear.status == 0) {
        return 0;
    } else {
        return resetclear.sense;
    }
}
