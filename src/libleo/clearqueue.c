#include "common.h"

s32 LeoClearQueue(void) {
    LEOCmdClearQue cmdBlock;

    if (__leoActive == 0) {
        return -1;
    }
    cmdBlock.header.command = 1;
    cmdBlock.header.reserve1 = 0;
    cmdBlock.header.control = 0;
    cmdBlock.header.reserve3 = 0;
    leoCommand(&cmdBlock);
    return 0;
}
