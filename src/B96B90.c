#include "common.h"

s32 LeoTestUnitReady(u8* status) {
    volatile LEOCmdTestUnitReady sp18;

    if (__leoActive == 0) {
        return -1;
    }
    if (IO_READ(0xA4600010) & 1) {
        return 8;
    }
    sp18.header.command = 3;
    sp18.header.reserve1 = 0;
    sp18.header.control = 0;
    sp18.header.reserve3 = 0;
    leoCommand(&sp18);
    while (sp18.header.status == 8) {}
    *status = sp18.test;
    return (s32)sp18.header.sense;
}
