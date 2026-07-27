#include "common.h"

extern vu16 LEOrw_flags;

void leoRead(void) {
    LEOrw_flags = 0;
    leoRead_common(0x18U);
}

void leoRead_common(unsigned int offset) {
    u32 tg_lba;
    u32 tg_blocks;
    u32 message;
    u16 retry_cnt;

    tg_lba = LEOcur_command->data.readwrite.lba;
    tg_blocks = LEOcur_command->data.readwrite.xfer_blks;
    if ((tg_lba | tg_blocks) & 0xFFFF0000) {
        goto invalid_lba;
    }
    tg_lba += offset;
    if ((tg_lba + tg_blocks) >= 0x10DD) {
    invalid_lba:
        LEOcur_command->header.sense = 0x20;
        LEOcur_command->header.status = 2;
        return;
    }
    if (tg_blocks == 0) {
        if (tg_lba >= 0x10DC) {
            goto invalid_lba;
        }
        LEOcur_command->header.sense = 0;
        LEOcur_command->header.status = 0;
        return;
    }
    LEOtgt_param.lba = tg_lba;
    LEOrw_flags &= ~0xC000;
    osSendMesg(&LEOc2ctrl_que, NULL, OS_MESG_NOBLOCK);
    osStartThread(&LEOinterruptThread);

    while (1) {
        osRecvMesg(&LEOcontrol_que, &message, OS_MESG_BLOCK);
        switch (message) {
            case 0x90000:
                goto read_complete;
            case 0x80000:
                leoC2_Correction();
                LEOrw_flags &= ~0x4000;
                if (LEOcur_command) {}
                osSendMesg(&LEOc2ctrl_que, NULL, OS_MESG_NOBLOCK);
                break;
            default:
                LEOcur_command->header.sense = (u8)message;
                LEOcur_command->header.status = 2;
                return;
        }
    }
read_complete:
    LEOcur_command->header.sense = 0;
    LEOcur_command->header.status = 0;
}
