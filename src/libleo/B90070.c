#include "common.h"

extern vu16 LEOrw_flags;

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

void leoReadDiskId(void) {
    LEOCmdRead dummy_cmd;
    u8* temp_pointer;
    u32 cntr;

    // Keep Disk ID Command and replace
    temp_pointer = (u8*)LEOcur_command;

    // Read Disk ID to Temp Buffer
    LEOcur_command = (LEOCmd*)&dummy_cmd;
    for (cntr = 0; cntr < 2; cntr++) {
        LEOrw_flags = 0x2000;
        dummy_cmd = D_801D9650;
        dummy_cmd.lba = D_801D9CF0[cntr];
        leoRead_common(0);
        if (dummy_cmd.header.sense != LEO_SENSE_UNRECOVERED_READ_ERROR) {
            break;
        }
    }

    // Put back the old ReadDiskID command
    LEOcur_command = (LEOCmd*)temp_pointer;

    // Copy Disk ID to buffer pointed by ReadDiskID command
    temp_pointer = (u8*)LEOcur_command->data.readdiskid.buffer_pointer;
    for (cntr = 0; cntr < (sizeof(LEODiskID)); cntr += sizeof(u32)) {
        *(u32*)temp_pointer = *((u32*)&LEO_TempBuffer[cntr]);
        temp_pointer += sizeof(u32);
    }

    // Copy status and sense
    LEOcur_command->header.sense = dummy_cmd.header.sense;
    LEOcur_command->header.status = dummy_cmd.header.status;

    if (LEOcur_command->header.status == LEO_STATUS_GOOD) {
        leoClrUA_MEDIUM_CHANGED();
    } else {
        leoSetUA_MEDIUM_CHANGED();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/B90070/D_801D9CF0.s")
