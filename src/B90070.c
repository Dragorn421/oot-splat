#include "common.h"

s32 LeoReadDiskID(LEOCmd* cmdBlock, LEODiskID* vaddr, OSMesgQueue* mq) {
    if (__leoActive == 0) {
        return -1;
    }
    cmdBlock->header.command = 0xC;
    cmdBlock->header.reserve1 = 0;
    cmdBlock->header.control = 0;
    cmdBlock->header.reserve3 = 0;
    cmdBlock->data.readwrite.lba = (u32)vaddr;
    if (mq != NULL) {
        cmdBlock->header.control |= 0x80;
        cmdBlock->header.post = mq;
    }
    leoCommand(cmdBlock);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/B90070/leoReadDiskId.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90070/D_801D9CF0.s")
