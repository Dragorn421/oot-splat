#include "common.h"

s32 LeoReadWrite(LEOCmd* cmdBlock, s32 direction, u32 LBA, void* vAddr, u32 nLBAs, OSMesgQueue* mq) {
    if (__leoActive == 0) {
        return -1;
    }
    if (direction == 0) {
        cmdBlock->header.command = 5;
    } else {
        cmdBlock->header.command = 6;
    }
    cmdBlock->header.reserve1 = 0;
    if (mq != NULL) {
        cmdBlock->header.control = 0x80;
    } else {
        cmdBlock->header.control = 0;
    }
    cmdBlock->header.reserve3 = 0;
    cmdBlock->header.post = mq;
    cmdBlock->data.readwrite.lba = LBA;
    cmdBlock->data.readwrite.xfer_blks = nLBAs;
    cmdBlock->data.readwrite.buff_ptr = vAddr;
    leoCommand(cmdBlock);
    return 0;
}
