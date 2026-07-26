#include "common.h"

void leoMode_sel(void) {
    u8 var_v0;

    var_v0 = leoSend_asic_cmd_w_nochkDiskChange(0x60000U, LEOcur_command->data.time.yearlo << 0x10);
    if ((var_v0 != 0) ||
        (var_v0 = leoSend_asic_cmd_w_nochkDiskChange(0x70000U, LEOcur_command->data.time.month << 0x10),
         (var_v0 != 0)) ||
        (var_v0 = leoSend_asic_cmd_w_nochkDiskChange(0x150000U, LEOcur_command->data.readwrite.xfer_blks),
         (var_v0 != 0))) {
        LEOcur_command->header.sense = var_v0;
        LEOcur_command->header.status = 2;
        return;
    }
    LEOcur_command->header.sense = var_v0;
    LEOcur_command->header.status = 0;
}
