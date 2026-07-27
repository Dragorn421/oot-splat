#include "common.h"

void leoSeek(void) {
    u32 tgt_tk;
    u8 sense_code;
    u8 retry_cntr = 20;

    if (LEOcur_command->data.readwrite.lba >= 0x10C4) {
        LEOcur_command->header.sense = 0x20;
        LEOcur_command->header.status = 2;
        return;
    }
    leoLba_to_phys(LEOcur_command->data.readwrite.lba + 0x18);
    do {
        sense_code = leoSeek_w();
        if (sense_code == 0) {
            LEOcur_command->header.status = 0;
            return;
        }
        if (leoChk_err_retry(sense_code) != 0) {
            break;
        }
    } while (retry_cntr--);
    LEOcur_command->header.sense = sense_code;
    LEOcur_command->header.status = 2;
}
