#include "common.h"

s32 LeoTestUnitReady(LEOStatus* status) {
    volatile LEOCmdTestUnitReady cmdBlock;

    if (__leoActive == 0) {
        return -1;
    }
    if (IO_READ(0xA4600010) & 1) {
        return 8;
    }
    cmdBlock.header.command = 3;
    cmdBlock.header.reserve1 = 0;
    cmdBlock.header.control = 0;
    cmdBlock.header.reserve3 = 0;
    leoCommand(&cmdBlock);
    while (cmdBlock.header.status == 8) {}
    *status = cmdBlock.test;
    return (s32)cmdBlock.header.sense;
}
