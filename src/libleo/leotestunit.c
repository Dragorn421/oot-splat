#include "common.h"

void leoTest_unit_rdy(void) {
    LEOcur_command->data.time.pad = leoChk_cur_drvmode();
    LEOcur_command->header.sense = 0;
    LEOcur_command->header.status = LEO_STATUS_GOOD;
}
