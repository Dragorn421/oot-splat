#include "common.h"

void leoClr_queue(void) {
    LEOCmdHeader* sp2C;

    while (osRecvMesg(&LEOcommand_que, (OSMesg*)&sp2C, OS_MESG_NOBLOCK) == 0) {
        sp2C->sense = 0x22;
        sp2C->status = 2;
        if (sp2C->control & 0x80) {
            osSendMesg(sp2C->post, (void*)0x22, OS_MESG_BLOCK);
        }
    }
}

void leoClr_reset(void) {
    u32 temp_v0;

    temp_v0 = leoAnalize_asic_status();
    if (temp_v0 == 3 || temp_v0 == 0x29 || temp_v0 == 0x2B) {
        LEOcur_command->header.sense = temp_v0;
        LEOcur_command->header.status = 2;
    } else {
        LEOcur_command->header.sense = 0;
        LEOcur_command->header.status = 0;
    }
}
