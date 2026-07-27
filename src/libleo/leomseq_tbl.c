#include "common.h"

extern vu16 LEOrw_flags;

s32 D_801E7040[0x10];

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
    temp_t2 = sp2C = LEOtgt_param.sec_bytes - 1;
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

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leomseq_tbl/D_801DA370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leomseq_tbl/D_801DA3B0.s")
