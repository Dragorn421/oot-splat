#include "common.h"

void leoClr_queue(void) {
    LEOCmdHeader* sp2C;

    while (osRecvMesg(&LEOcommand_que, (OSMesg*)&sp2C, 0) == 0) {
        sp2C->sense = 0x22;
        sp2C->status = 2;
        if (sp2C->control & 0x80) {
            osSendMesg(sp2C->post, (void*)0x22, 1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/B926C0/leoClr_reset.s")
