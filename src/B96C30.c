#include "common.h"

void leoTest_unit_rdy(void) {
    LEOcur_command->data.time.pad = leoChk_cur_drvmode();
    LEOcur_command->header.sense = 0;
    LEOcur_command->header.status = 0;
}

void leoSeek(void) {
    u8 var_s0;
    u8 temp_s1;

    var_s0 = 0x14;
    if (LEOcur_command->data.readwrite.lba >= 0x10C4U) {
        LEOcur_command->header.sense = 0x20;
        LEOcur_command->header.status = 2;
        return;
    }
    leoLba_to_phys(LEOcur_command->data.readwrite.lba + 0x18);
    do {
        temp_s1 = leoSeek_w();
        if (temp_s1 == 0) {
            LEOcur_command->header.status = 0;
            return;
        }
        if (leoChk_err_retry(temp_s1) != 0) {
            break;
        }
    } while (var_s0--);
    LEOcur_command->header.sense = temp_s1;
    LEOcur_command->header.status = 2;
}
