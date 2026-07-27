#include "common.h"

void leoMode_sel(void) {
    u8 sense;

    sense = leoSend_asic_cmd_w_nochkDiskChange(0x60000U, LEOcur_command->data.time.yearlo << 16);
    if ((sense != 0) ||
        (sense = leoSend_asic_cmd_w_nochkDiskChange(0x70000U, LEOcur_command->data.time.month << 16),
         (sense != 0)) ||
        (sense = leoSend_asic_cmd_w_nochkDiskChange(0x150000U, LEOcur_command->data.readwrite.xfer_blks),
         (sense != 0))) {
        LEOcur_command->header.sense = sense;
        LEOcur_command->header.status = 2;
        return;
    }
    LEOcur_command->header.sense = sense;
    LEOcur_command->header.status = 0;
}
