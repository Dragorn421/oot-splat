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

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoSend_asic_cmd_i.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoWait_mecha_cmd_done.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoSend_asic_cmd_w.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoSend_asic_cmd_w_nochkDiskChange.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoDetect_index_w.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/func_801CD1EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoRecal_w.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/leoSeek_i.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/B90260/LeoSpdlMotor.s")
