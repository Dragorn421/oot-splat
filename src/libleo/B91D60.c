#include "common.h"

extern vu16 LEOrw_flags;

void leoSet_mseq(u16 rwmode) {
    s32 pad[2];
    u32 sp2C;
    u32* var_v1;
    u32 temp_t2;
    u8 var_v0;

    LEOasic_seq_ctl_shadow &= 0xBFFFFFFF;
    osEPiWriteIo(LEOPiInfo, 0x05000518U, LEOasic_seq_ctl_shadow);
    if (rwmode == 1) {
        var_v1 = &D_801DA3B0;
    } else {
        var_v1 = &D_801DA370;
    }
    for (var_v0 = 0; var_v0 < 0x10; var_v0++, var_v1++) {
        D_801E7040[var_v0] = *var_v1;
    }
    temp_t2 = sp2C = D_801E6716 - 1;
    sp2C += 7;
    temp_t2 <<= 8;
    D_801E7040[4] |= temp_t2;
    osWritebackDCache(D_801E7040, 0x40);
    LEOPiDmaParam.dramAddr = D_801E7040;
    LEOPiDmaParam.devAddr = 0x05000580;
    LEOPiDmaParam.size = 0x40;
    LEOPiInfo->transferInfo.cmdType = 2;
    osEPiStartDma(LEOPiInfo, &LEOPiDmaParam, 1);
    osRecvMesg(&LEOdma_que, NULL, 1);
    osEPiWriteIo(LEOPiInfo, 0x05000530U, (sp2C | 0x5900) << 0x10);
    if (LEOrw_flags & 0x800) {
        temp_t2 += 0x100;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000528U, temp_t2 << 8);
    LEOasic_seq_ctl_shadow |= 0x40000000;
    osEPiWriteIo(LEOPiInfo, 0x05000518U, LEOasic_seq_ctl_shadow);
}

void leoStart_stop(void) {
    u8 var_s0;
    u32 var_a0;
    u32 var_a1;
    u8 temp_v0_2;

    var_s0 = 8;
    do {
        var_a1 = 0;
        if (LEOcur_command->header.control & 1) {
            var_a0 = 0x50001;
        } else if (LEOcur_command->header.control & 2) {
            var_a0 = 0xD0000;
        } else {
            if (LEOcur_command->header.control & 4) {
                var_a1 = 0x10000;
            }
            var_a0 = 0x40000;
        }
        temp_v0_2 = leoSend_asic_cmd_w_nochkDiskChange(var_a0, var_a1);
        if (temp_v0_2 == 0) {
            LEOcur_command->header.status = 0;
            return;
        }
        if (leoChk_err_retry(temp_v0_2) != 0) {
            break;
        }
    } while (var_s0--);
    LEOcur_command->header.sense = temp_v0_2;
    LEOcur_command->header.status = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/B91D60/D_801DA370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/B91D60/D_801DA3B0.s")
