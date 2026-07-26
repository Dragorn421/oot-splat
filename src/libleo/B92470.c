#include "common.h"

void leoRezero(void) {
    u8 var_s0;
    u8 temp_v0;

    var_s0 = 8;
    do {
        temp_v0 = leoRecal_w();
        if (temp_v0 == 0) {
            LEOtgt_param.cylinder = 0;
            LEOtgt_param.head = 0;
            LEOtgt_param.zone = 0;
            LEOcur_command->header.status = 0;
            return;
        }
        if (leoChk_err_retry(temp_v0) != 0) {
            break;
        }
    } while (var_s0--);
    LEOcur_command->header.sense = temp_v0;
    LEOcur_command->header.status = 2;
}
