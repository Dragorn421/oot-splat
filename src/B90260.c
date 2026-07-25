#include "common.h"

s32 leoAnalize_asic_status(void) {
    u32 temp_v0;

    osEPiReadIo(LEOPiInfo, 0x05000508U, &D_801E67F0);
    temp_v0 = D_801E67F0 ^ 0x01000000;
    if (temp_v0 & 0x01C3FFFF) {
        if (temp_v0 & 0x01C1FFFF) {
            LEOdrive_flag = 0;
        }
        if (temp_v0 & 0xFFFF) {
            return 0x29;
        }
        if ((temp_v0 & 0xC00000) == 0x800000) {
            return 3;
        }
        if (temp_v0 & 0x400000) {
            D_801E67F4 |= 2;
            return 0x2B;
        }
        if (temp_v0 & 0x01000000) {
            return 0x31;
        }
        if (temp_v0 & 0x10000) {
            D_801E67F4 |= 1;
            return 0x2F;
        }
        if (temp_v0 & 0x20000) {
            return 0x15;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoChk_asic_ready.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoChk_done_status.s")

u8 leoSend_asic_cmd_i(u32 arg0, u32 arg1) {
    u8 temp_v0;

    temp_v0 = leoChk_asic_ready(arg0);
    if (temp_v0 != 0) {
        LEOcur_command->header.sense = temp_v0;
        return LEOcur_command->header.sense;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000500U, (u32)arg1);
    if (leoRecv_event_mesg(0) != 0) {
        LEOcur_command->header.sense = 0x25;
        return LEOcur_command->header.sense;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000508U, arg0);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoWait_mecha_cmd_done.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoSend_asic_cmd_w.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoSend_asic_cmd_w_nochkDiskChange.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoDetect_index_w.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/func_801CD1EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoRecal_w.s")

u8 leoSeek_i(u16 arg0) {
    s32 temp_t0;

    temp_t0 = ((LEOtgt_param.head << 0xC) + LEOtgt_param.cylinder) << 0x10;
    if (!arg0) {
        return leoSend_asic_cmd_i(0x10001, temp_t0);
    }
    return leoSend_asic_cmd_i(0x20001, temp_t0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoSeek_w.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoRecv_event_mesg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoChk_err_retry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoChk_cur_drvmode.s")

void leoDrive_reset(void) {
    osEPiWriteIo(LEOPiInfo, 0x05000520U, 0xAAAA0000U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoChkUnit_atten.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoRetUnit_atten.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoClrUA_RESET.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoClrUA_MEDIUM_CHANGED.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoSetUA_MEDIUM_CHANGED.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoInitUnit_atten.s")

s32 LeoSpdlMotor(LEOCmd* cmdBlock, u8 mode, OSMesgQueue* mq) {
    if (__leoActive == 0) {
        return -1;
    }
    cmdBlock->header.command = 8;
    cmdBlock->header.reserve1 = 0;
    switch (mode) {
        case 0:
            cmdBlock->header.control = 1;
            break;
        case 1:
            cmdBlock->header.control = 2;
            break;
        case 2:
            cmdBlock->header.control = 0;
            break;
        case 4:
            cmdBlock->header.control = 4;
            break;
    }
    cmdBlock->header.reserve3 = 0;
    if (mq != NULL) {
        cmdBlock->header.post = mq;
        cmdBlock->header.control |= 0x80;
    }
    leoCommand(cmdBlock);
    return 0;
}
