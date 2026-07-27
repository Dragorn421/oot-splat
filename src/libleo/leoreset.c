#include "common.h"

void leoClr_queue(void) {
    OSMesg clr_cmd;

    while (osRecvMesg(&LEOcommand_que, &clr_cmd, OS_MESG_NOBLOCK) == 0) {
        ((LEOCmdHeader*)clr_cmd)->sense = 0x22;
        ((LEOCmdHeader*)clr_cmd)->status = 2;
        if (((LEOCmdHeader*)clr_cmd)->control & 0x80) {
            osSendMesg(((LEOCmdHeader*)clr_cmd)->post, (OSMesg)0x22, OS_MESG_BLOCK);
        }
    }
}

void leoClr_reset(void) {
    u32 code;

    code = leoAnalize_asic_status();
    if (code == 3 || code == 0x29 || code == 0x2B) {
        LEOcur_command->header.sense = code;
        LEOcur_command->header.status = 2;
    } else {
        LEOcur_command->header.sense = 0;
        LEOcur_command->header.status = 0;
    }
}
