#include "common.h"

u8 leoRecv_event_mesg(s32 control);

u32 asic_cur_status;
u32 unit_atten;

u8 leoAnalize_asic_status(void) {
    u32 curr_stat;

    osEPiReadIo(LEOPiInfo, 0x05000508, &asic_cur_status);
    curr_stat = asic_cur_status ^ 0x01000000;
    if (curr_stat & 0x01C3FFFF) {
        if (curr_stat & 0x01C1FFFF) {
            LEOdrive_flag = 0;
        }
        if (curr_stat & 0xFFFF) {
            return 0x29;
        }
        if ((curr_stat & 0xC00000) == 0x800000) {
            return 3;
        }
        if (curr_stat & 0x400000) {
            unit_atten |= 2;
            return 0x2B;
        }
        if (curr_stat & 0x01000000) {
            return 0x31;
        }
        if (curr_stat & 0x10000) {
            unit_atten |= 1;
            return 0x2F;
        }
        if (curr_stat & 0x20000) {
            return 0x15;
        }
    }
    return 0;
}

u8 leoChk_asic_ready(u32 asic_cmd) {
    u32 sense_code;

    sense_code = leoAnalize_asic_status();
    switch (sense_code) {
        case 47:
            if (asic_cmd == 0x80000) {
                return 0;
            }
            FALLTHROUGH;
        case 43:
            if (!(asic_cur_status & 0x800000)) {
                if (asic_cmd == 0x90000) {
                    return 0;
                }
                if (leoRecv_event_mesg(OS_MESG_NOBLOCK) != 0) {
                    return 0x25;
                }
                osEPiWriteIo(LEOPiInfo, 0x05000508, 0x90000);
                if (leoRecv_event_mesg(OS_MESG_BLOCK) != 0) {
                    return 0x25;
                }
            }
            break;
        case 49:
            if (asic_cmd & 1) {
                break;
            }
            FALLTHROUGH;
        case 21:
            return 0;
        default:
            break;
    }
    return sense_code;
}

u8 leoChk_done_status(u32 asic_cmd) {
    u32 asic_data;
    u32 code;

    code = leoAnalize_asic_status();
    switch (code) {
        case 43:
        case 47:
            if (!(asic_cur_status & 0x800000)) {
                if (leoRecv_event_mesg(OS_MESG_NOBLOCK) != 0) {
                    return 0x25;
                }
                osEPiWriteIo(LEOPiInfo, 0x05000508, 0x90000);
                if (leoRecv_event_mesg(OS_MESG_BLOCK) != 0) {
                    return 0x25;
                }
            }
            break;
        default:
            break;
        case 49:
            if (!(asic_cmd & 1)) {
                return 0;
            }
            break;
        case 21:
            osEPiWriteIo(LEOPiInfo, 0x05000500, 0);
            if (leoRecv_event_mesg(OS_MESG_NOBLOCK) != 0) {
                return 0x25;
            }
            osEPiWriteIo(LEOPiInfo, 0x05000508, 0xC0000);
            if (leoRecv_event_mesg(OS_MESG_BLOCK) != 0) {
                return 0x25;
            }
            osEPiReadIo(LEOPiInfo, 0x05000500, &asic_data);
            code = leoChk_asic_ready(0xC0000);
            if (code != 0) {
                return code;
            }
            if (asic_data & 0x10000) {
                return 2;
            }
            if (asic_data & 0x20000) {
                return 0x18;
            }
            if (asic_data & 0x40000) {
                return 1;
            }
            if (asic_data & 0x80000) {
                return 0x15;
            }
            if (asic_data & 0x200000) {
                return 0xB;
            }
            return 0x29;
    }
    return code;
}

u8 leoSend_asic_cmd_i(u32 asic_cmd, u32 asic_data) {
    u8 status;

    status = leoChk_asic_ready(asic_cmd);
    if (status != 0) {
        LEOcur_command->header.sense = status;
        return LEOcur_command->header.sense;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000500, asic_data);
    if (leoRecv_event_mesg(OS_MESG_NOBLOCK) != 0) {
        LEOcur_command->header.sense = 0x25;
        return LEOcur_command->header.sense;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000508, asic_cmd);
    return 0;
}

u8 leoWait_mecha_cmd_done(u32 asic_cmd) {
    u32 done_stat;

    if (leoRecv_event_mesg(OS_MESG_BLOCK) != 0) {
        return 0x25;
    }
    done_stat = leoChk_done_status(asic_cmd);
    if (done_stat != 0) {
        return done_stat;
    }
    return 0;
}

u8 leoSend_asic_cmd_w(u32 asic_cmd, u32 asic_data) {
    u32 wstatus;

    wstatus = leoSend_asic_cmd_i(asic_cmd, asic_data);
    if (wstatus != 0) {
        return wstatus;
    }
    return leoWait_mecha_cmd_done(asic_cmd);
}

u8 leoSend_asic_cmd_w_nochkDiskChange(u32 asic_cmd, u32 asic_data) {
    u8 status;
    u32 done_stat;

    status = leoChk_asic_ready(asic_cmd);
    if ((status != 0x2F) && (status != 0)) {
        LEOcur_command->header.sense = status;
        return LEOcur_command->header.sense;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000500, asic_data);
    if (leoRecv_event_mesg(OS_MESG_NOBLOCK) != 0) {
        LEOcur_command->header.sense = 0x25;
        return LEOcur_command->header.sense;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000508, asic_cmd);
    if (leoRecv_event_mesg(OS_MESG_BLOCK) != 0) {
        return 0x25;
    }
    done_stat = leoChk_done_status(asic_cmd);
    if ((done_stat != 0x2F) && (done_stat != 0)) {
        return done_stat;
    }
    return 0;
}

u8 leoDetect_index_w(void) {
    return leoSend_asic_cmd_w(0xE0001, 0);
}

u8 leoRecal_i(void) {
    return leoSend_asic_cmd_i(0x30001, 0);
}

u8 leoRecal_w(void) {
    return leoSend_asic_cmd_w(0x30001, 0);
}

u8 leoSeek_i(u16 rwmode) {
    s32 tgt_tk;

    tgt_tk = ((LEOtgt_param.head << 12) + LEOtgt_param.cylinder) << 16;
    if (!rwmode) {
        return leoSend_asic_cmd_i(0x10001, tgt_tk);
    }
    return leoSend_asic_cmd_i(0x20001, tgt_tk);
}

u8 leoSeek_w(void) {
    u8 sksense;

    sksense = leoSeek_i(0);
    if (sksense != 0) {
        return sksense;
    }
    return leoWait_mecha_cmd_done(0x10001);
}

u8 leoRecv_event_mesg(s32 control) {
    OSMesg done_mesg;

    if ((osRecvMesg(&LEOevent_que, &done_mesg, control) == 0) && (done_mesg == (OSMesg)0xA0000)) {
        leoDrive_reset();
        return 0xFF;
    }
    return 0;
}

u32 leoChk_err_retry(u32 sense) {
    if ((currentCommand == 0xC) || (currentCommand == 8)) {
        switch (sense) {
            case 43:
                unit_atten |= 2;
                FALLTHROUGH;
            case 2:
            case 3:
            case 37:
            case 41:
            case 42:
            case 49:
                LEOdrive_flag = 0;
                return -1U;
            default:
                break;
        }
    } else {
        switch (sense) {
            case 43:
                unit_atten |= 2;
                FALLTHROUGH;
            case 47:
                unit_atten |= 1;
                FALLTHROUGH;
            case 2:
            case 3:
            case 37:
            case 41:
            case 42:
            case 49:
                LEOdrive_flag = 0;
                return -1U;
            default:
                break;
        }
    }
    return 0;
}

u8 leoChk_cur_drvmode(void) {
    u8 devstat;

    devstat = 0;
    if (!(asic_cur_status & 0x01000000)) {
        devstat |= 1;
    }
    if (asic_cur_status & 0x80000) {
        devstat |= 2;
    }
    if (asic_cur_status & 0x100000) {
        devstat |= 4;
    }
    return devstat;
}

void leoDrive_reset(void) {
    osEPiWriteIo(LEOPiInfo, 0x05000520, 0xAAAA0000);
}

u32 leoChkUnit_atten(void) {
    return (u32)unit_atten;
}

u32 leoRetUnit_atten(void) {
    if (unit_atten & 2) {
        return 0x2B;
    }
    if (unit_atten & 1) {
        return 0x2F;
    }
    return 0;
}

void leoClrUA_RESET(void) {
    unit_atten &= ~2;
}

void leoClrUA_MEDIUM_CHANGED(void) {
    unit_atten &= ~1;
}

void leoSetUA_MEDIUM_CHANGED(void) {
    unit_atten |= 1;
}

void leoInitUnit_atten(void) {
    unit_atten = 1;
}
