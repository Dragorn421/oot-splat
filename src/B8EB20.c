#include "common.h"

extern vu16 LEOrw_flags;

// https://decomp.me/scratch/n5d7V
#pragma GLOBAL_ASM("asm/nonmatchings/B8EB20/leointerrupt.s")

u32 func_801CB650(void) {
    u32 message;
    u32 block;
    u32 retry_cntr;
    block_param_form block_param;

    block_param.bytes = LEOtgt_param.sec_bytes;
    block_param.blkbytes = LEOtgt_param.blk_bytes;
    if (LEOrw_flags & 0x2000) {
        // Sector Mode
        block_param.blkbytes = block_param.bytes;
    }
    block_param.pntr = LEOwrite_pointer;
    LEOwrite_pointer += block_param.blkbytes;
    if (LEOtgt_param.rdwr_blocks == 2) {
        LEOwrite_pointer += block_param.blkbytes;
    }
    retry_cntr = 0;
    for (;;) {
        LEOPiInfo->transferInfo.transferMode = 1;
        LEOPiInfo->transferInfo.blockNum = 0;
        LEOPiInfo->transferInfo.block[0].C1ErrNum = 0;
        LEOPiInfo->transferInfo.block[0].sectorSize = block_param.bytes;
        LEOPiInfo->transferInfo.block[0].dramAddr = block_param.pntr;
        LEOPiInfo->transferInfo.block[0].C2Addr = &D_801E68F0[0];
        if (LEOrw_flags & 0x2000) {
            // Sector Mode
            LEOtgt_param.rdwr_blocks = 1;
            LEOPiInfo->transferInfo.transferMode = 3;
        } else if (LEOtgt_param.rdwr_blocks == 2) {
            LEOPiInfo->transferInfo.transferMode = 2;
            LEOPiInfo->transferInfo.block[1] = LEOPiInfo->transferInfo.block[0];
            LEOPiInfo->transferInfo.block[1].C2Addr = &D_801E68F0[1];
            LEOPiInfo->transferInfo.block[1].dramAddr =
                ((u8*)LEOPiInfo->transferInfo.block[1].dramAddr + block_param.blkbytes);
        }
        message = func_801CBC4C();
        if (message == 0) {
            if (LEOrw_flags & 0x8000) {
                // Write Mode
                leoSet_mseq(1);
            } else {
                // Read Mode
                leoSet_mseq(0);
            }
            func_801CBCB4();
            LEOPiInfo->transferInfo.bmCtlShadow = LEOasic_bm_ctl_shadow;
            LEOPiInfo->transferInfo.seqCtlShadow = LEOasic_seq_ctl_shadow;
            if (LEOrw_flags & 0x8000) {
                u16 bnum;

                LEOPiInfo->transferInfo.cmdType = 1;
                osWritebackDCache(block_param.pntr, block_param.blkbytes * LEOtgt_param.rdwr_blocks);
                osEPiStartDma(LEOPiInfo, &LEOPiDmaParam, 1);
                osRecvMesg(&LEOdma_que, NULL, OS_MESG_BLOCK);
                LEOasic_bm_ctl_shadow = LEOPiInfo->transferInfo.bmCtlShadow;
                LEOasic_seq_ctl_shadow = LEOPiInfo->transferInfo.seqCtlShadow;
                bnum = LEOPiInfo->transferInfo.blockNum;
                message = LEOPiInfo->transferInfo.block[bnum].errStatus;
                if (message == 0) {
                    return message;
                }
                goto track_end;
            } else {
                if (LEOrw_flags & 0x4000) {
                    osRecvMesg(&LEOc2ctrl_que, NULL, OS_MESG_BLOCK);
                    osSendMesg(&LEOc2ctrl_que, NULL, OS_MESG_NOBLOCK);
                }
                LEOPiInfo->transferInfo.cmdType = 0;
                osInvalDCache(block_param.pntr, block_param.blkbytes * LEOtgt_param.rdwr_blocks);
                osEPiStartDma(LEOPiInfo, &LEOPiDmaParam, 0);
                block = 0;
                while (LEOtgt_param.rdwr_blocks != 0) {
                    osRecvMesg(&LEOdma_que, NULL, OS_MESG_BLOCK);
                    LEOasic_bm_ctl_shadow = LEOPiInfo->transferInfo.bmCtlShadow;
                    LEOasic_seq_ctl_shadow = LEOPiInfo->transferInfo.seqCtlShadow;
                    message = LEOPiInfo->transferInfo.block[block].errStatus;
                    if (message != 0) {
                        goto track_end;
                    }
                    if (LEOrw_flags & 0x2000) {
                        return 0;
                    }
                    if (LEOPiInfo->transferInfo.block[block].C1ErrNum) {
                        if (LEOPiInfo->transferInfo.block[block].C1ErrSector[0] < 0x55) {
                            u8* temp;
                            u32 c2datasize;

                            if (LEOtgt_param.rdwr_blocks == 1) {
                                osEPiReadIo(LEOPiInfo, 0x05000514, &message);
                                if (message & 0x10000000) {
                                    message = 4;
                                    goto track_end;
                                }
                            }

                            if (block == 0) {
                                temp = D_801E68F0[0];
                            } else {
                                temp = D_801E68F0[1];
                            }
                            c2datasize = block_param.bytes * 4;
                            block_param.c2buff_e = temp + c2datasize;
                            osInvalDCache(temp, c2datasize);
                            block_param.err_num = LEOPiInfo->transferInfo.block[block].C1ErrNum;
                            block_param.err_pos[0] = LEOPiInfo->transferInfo.block[block].C1ErrSector[0];
                            block_param.err_pos[1] = LEOPiInfo->transferInfo.block[block].C1ErrSector[1];
                            block_param.err_pos[2] = LEOPiInfo->transferInfo.block[block].C1ErrSector[2];
                            block_param.err_pos[3] = LEOPiInfo->transferInfo.block[block].C1ErrSector[3];
                            osRecvMesg(&LEOc2ctrl_que, NULL, OS_MESG_BLOCK);
                            LEOrw_flags |= 0x4000;
                            LEOc2_param = block_param;
                            osSendMesg(&LEOcontrol_que, (void*)0x80000, OS_MESG_BLOCK);
                        }
                    } else {
                        if (LEOtgt_param.rdwr_blocks == 1) {
                            if ((*(u32*)&D_801E68F0[block][0x00] | *(u32*)&D_801E68F0[block][0x04] |
                                 *(u32*)&D_801E68F0[block][0x08] | *(u32*)&D_801E68F0[block][0x0C]) != 0) {
                                message = 0x17;
                                goto track_end;
                            }
                        }
                    }
                    block++;
                    block_param.pntr += block_param.blkbytes;
                    LEOtgt_param.start_block ^= 1;
                    LEOtgt_param.rdwr_blocks--;
                }
            }
            return 0;
        }
    track_end:
        if (message == 0x16) {
            message = func_801CBD9C();
        }
    do_retry:
        if (leoChk_err_retry(message) || (LEOrw_flags & 0x1000) || retry_cntr++ == 0x40) {
            break;
        }
        if ((retry_cntr & 7) == 0) {
            message = leoSend_asic_cmd_w(0x30001, 0);
            if (message != 0) {
                goto do_retry;
            }
        }
        if (message == 0x18 || (message == 0x17 && retry_cntr == 0x20)) {
            message = leoDetect_index_w();
            if (message != 0) {
                goto do_retry;
            }
        }
        if (LEOrw_flags & 0x8000) {
            message = leoSeek_i(1);
        } else {
            message = leoSeek_i(0);
        }
        if (message != 0) {
            goto do_retry;
        }
    }
    return message;
}

u32 func_801CBC4C(void) {
    u32 var_v1;
    u32 sp18;

    var_v1 = leoWait_mecha_cmd_done(0x10001U);
    if (var_v1 == 0) {
        osEPiReadIo(LEOPiInfo, 0x0500050CU, &sp18);
        if ((sp18 & 0x60000000) != 0x60000000) {
            var_v1 = 0x18;
        }
    }
    return var_v1;
}

void func_801CBCB4(void) {
    osEPiWriteIo(LEOPiInfo, 0x05000510U, LEOasic_bm_ctl_shadow | 0x10000000);
    osEPiWriteIo(LEOPiInfo, 0x05000510U, (u32)LEOasic_bm_ctl_shadow);
    if (LEOtgt_param.start_block != 0) {
        LEOasic_bm_ctl_shadow = 0x5A0000;
    } else {
        LEOasic_bm_ctl_shadow = 0;
    }
    if (!(LEOrw_flags & 0x8000)) {
        LEOasic_bm_ctl_shadow |= 0x40000000;
    }
    if (LEOtgt_param.rdwr_blocks == 2) {
        LEOasic_bm_ctl_shadow |= 0x02000000;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000510U, (u32)LEOasic_bm_ctl_shadow);
}

#ifdef NON_MATCHING
u32 func_801CBD9C(void) {
    u32 sp1C;
    u32 sp18;

    osEPiReadIo(LEOPiInfo, 0x05000514U, &sp1C);
    osEPiWriteIo(LEOPiInfo, 0x05000510U, LEOasic_bm_ctl_shadow | 0x10000000);
    osEPiWriteIo(LEOPiInfo, 0x05000510U, (u32)LEOasic_bm_ctl_shadow);
    if (sp1C & 0x04000000) {
        return 0x31U;
    }
    if (sp1C & 0x10000000) {
        return 4U;
    }
    if (sp1C & 0x42000000) {
        if (LEOrw_flags & 0x8000) {
            return 0x16U;
        }
        return 0x17U;
    }
    if (sp1C & 0x80000000) {
        return 0x18U;
    }
    osEPiReadIo(LEOPiInfo, 0x0500050CU, &sp18);
    if ((sp18 & 0x60000000) == 0x60000000) {
        return 0x19U;
    }
    return 0x18U;
}
#else
// zero padding
#pragma GLOBAL_ASM("asm/nonmatchings/B8EB20/func_801CBD9C.s")
#endif
