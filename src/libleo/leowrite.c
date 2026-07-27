#include "common.h"

extern u16 LEOrw_flags;

void leoWrite(void) {
    u32 sp2C;
    u32 start_lba;
    u32 xfer_blk;
    u32 temp_v1;

    start_lba = LEOcur_command->data.readwrite.lba;
    xfer_blk = LEOcur_command->data.readwrite.xfer_blks;
    if ((((u32)(LEOcur_command->data.readwrite.lba | xfer_blk) >> 0x10) != 0)) {
        goto invalid_lba;
    }
    temp_v1 = start_lba + 0x18;
    if ((temp_v1 >= 0x10DCU) || ((u32)(temp_v1 + xfer_blk) >= 0x10DDU)) {
    invalid_lba:
        LEOcur_command->header.sense = 0x20;
        LEOcur_command->header.status = 2;
        return;
    }
    if (temp_v1 < (u16)LEORAM_START_LBA[LEOdisk_type]) {
        LEOcur_command->header.sense = 0x21;
        LEOcur_command->header.status = 2;
        return;
    }
    if (xfer_blk == 0) {
        LEOcur_command->header.sense = 0;
        LEOcur_command->header.status = 0;
        return;
    }
    LEOrw_flags = 0x8000;
    LEOtgt_param.lba = temp_v1;
    osStartThread(&LEOinterruptThread);
    osRecvMesg(&LEOcontrol_que, &sp2C, 1);
    if (sp2C != 0x90000) {
        LEOcur_command->header.sense = (u8)sp2C;
        LEOcur_command->header.status = 2;
        return;
    }
    LEOcur_command->header.sense = 0;
    LEOcur_command->header.status = 0;
}
