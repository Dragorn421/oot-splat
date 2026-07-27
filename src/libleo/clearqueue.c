#include "common.h"

s32 LeoClearQueue(void) {
    LEOCmdClearQue sp1C;

    if (__leoActive == 0) {
        return -1;
    }
    sp1C.header.command = 1;
    sp1C.header.reserve1 = 0;
    sp1C.header.control = 0;
    sp1C.header.reserve3 = 0;
    leoCommand(&sp1C);
    return 0;
}
