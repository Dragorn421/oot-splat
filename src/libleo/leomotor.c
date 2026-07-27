#include "common.h"

void leoStart_stop(void) {
    u8 var_s0;
    u32 var_a0;
    u32 var_a1;
    u8 temp_v0_2;

    var_s0 = 8;
    do {
        var_a1 = 0;
        if (LEOcur_command->header.control & 1) {
            var_a0 = 0x50001;
        } else if (LEOcur_command->header.control & 2) {
            var_a0 = 0xD0000;
        } else {
            if (LEOcur_command->header.control & 4) {
                var_a1 = 0x10000;
            }
            var_a0 = 0x40000;
        }
        temp_v0_2 = leoSend_asic_cmd_w_nochkDiskChange(var_a0, var_a1);
        if (temp_v0_2 == 0) {
            LEOcur_command->header.status = 0;
            return;
        }
        if (leoChk_err_retry(temp_v0_2) != 0) {
            break;
        }
    } while (var_s0--);
    LEOcur_command->header.sense = temp_v0_2;
    LEOcur_command->header.status = 2;
}
