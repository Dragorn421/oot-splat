#include "common.h"

void leoInquiry(void) {
    u32 sp1C;
    u32 sp18;

    osEPiReadIo(LEOPiInfo, 0x05000540U, &sp1C);
    if (leoSend_asic_cmd_w(0x1B0000U, 0U) == 0) {
        osEPiReadIo(LEOPiInfo, 0x05000500U, &sp18);
        if (sp18 & 0x10000) {
            sp1C |= 0x100000;
        }
    }
    LEOcur_command->data.time.pad = 0;
    LEOcur_command->data.time.yearhi = (u8)(sp1C >> 0x10);
    LEOcur_command->data.time.yearlo = 1;
    LEOcur_command->data.time.month = 0;
    LEOcur_command->header.status = 0;
}
