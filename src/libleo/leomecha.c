#include "common.h"

u8 leoRecv_event_mesg(s32 control);

u32 D_801E67F0;
s32 D_801E67F4;

u8 leoAnalize_asic_status(void) {
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

u8 leoChk_asic_ready(u32 arg0) {
    s32 sp1C;

    sp1C = leoAnalize_asic_status();
    switch (sp1C) {
        case 47:
            if (arg0 == 0x80000) {
                return 0U;
            }
            FALLTHROUGH;
        case 43:
            if (!(D_801E67F0 & 0x800000)) {
                if (arg0 == 0x90000) {
                    return 0U;
                }
                if (leoRecv_event_mesg(OS_MESG_NOBLOCK) != 0) {
                    return 0x25U;
                }
                osEPiWriteIo(LEOPiInfo, 0x05000508U, 0x90000U);
                if (leoRecv_event_mesg(OS_MESG_BLOCK) != 0) {
                    return 0x25U;
                }
            }
            break;
        case 49:
            if (arg0 & 1) {
                break;
            }
            FALLTHROUGH;
        case 21:
            return 0U;
        default:
            break;
    }
    return sp1C;
}

u8 leoChk_done_status(u32 asic_cmd) {
    u32 sp24;
    u32 sp20;

    sp20 = leoAnalize_asic_status();
    switch (sp20) {
        case 43:
        case 47:
            if (!(D_801E67F0 & 0x800000)) {
                if (leoRecv_event_mesg(OS_MESG_NOBLOCK) != 0) {
                    return 0x25U;
                }
                osEPiWriteIo(LEOPiInfo, 0x05000508U, 0x90000U);
                if (leoRecv_event_mesg(OS_MESG_BLOCK) != 0) {
                    return 0x25U;
                }
            }
            break;
        default:
            break;
        case 49:
            if (!(asic_cmd & 1)) {
                return 0U;
            }
            break;
        case 21:
            osEPiWriteIo(LEOPiInfo, 0x05000500U, 0U);
            if (leoRecv_event_mesg(OS_MESG_NOBLOCK) != 0) {
                return 0x25U;
            }
            osEPiWriteIo(LEOPiInfo, 0x05000508U, 0xC0000U);
            if (leoRecv_event_mesg(OS_MESG_BLOCK) != 0) {
                return 0x25U;
            }
            osEPiReadIo(LEOPiInfo, 0x05000500U, &sp24);
            sp20 = leoChk_asic_ready(0xC0000U);
            if (sp20 != 0) {
                return sp20;
            }
            if (sp24 & 0x10000) {
                return 2U;
            }
            if (sp24 & 0x20000) {
                return 0x18U;
            }
            if (sp24 & 0x40000) {
                return 1U;
            }
            if (sp24 & 0x80000) {
                return 0x15U;
            }
            if (sp24 & 0x200000) {
                return 0xBU;
            }
            return 0x29U;
    }
    return sp20;
}

u8 leoSend_asic_cmd_i(u32 arg0, u32 arg1) {
    u8 temp_v0;

    temp_v0 = leoChk_asic_ready(arg0);
    if (temp_v0 != 0) {
        LEOcur_command->header.sense = temp_v0;
        return LEOcur_command->header.sense;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000500U, (u32)arg1);
    if (leoRecv_event_mesg(OS_MESG_NOBLOCK) != 0) {
        LEOcur_command->header.sense = 0x25;
        return LEOcur_command->header.sense;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000508U, arg0);
    return 0;
}

u8 leoWait_mecha_cmd_done(u32 asic_cmd) {
    u32 temp_v0;

    if (leoRecv_event_mesg(OS_MESG_BLOCK) != 0) {
        return 0x25U;
    }
    temp_v0 = leoChk_done_status(asic_cmd);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    return 0U;
}

u8 leoSend_asic_cmd_w(u32 asic_cmd, u32 asic_data) {
    u32 temp_v0;

    temp_v0 = leoSend_asic_cmd_i(asic_cmd, asic_data);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    return leoWait_mecha_cmd_done(asic_cmd);
}

u8 leoSend_asic_cmd_w_nochkDiskChange(u32 asic_cmd, u32 asic_data) {
    u8 temp_v0_2;
    u32 temp_v0;

    temp_v0_2 = leoChk_asic_ready(asic_cmd);
    if ((temp_v0_2 != 0x2F) && (temp_v0_2 != 0)) {
        LEOcur_command->header.sense = temp_v0_2;
        return LEOcur_command->header.sense;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000500U, asic_data);
    if (leoRecv_event_mesg(OS_MESG_NOBLOCK) != 0) {
        LEOcur_command->header.sense = 0x25;
        return LEOcur_command->header.sense;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000508U, asic_cmd);
    if (leoRecv_event_mesg(OS_MESG_BLOCK) != 0) {
        return 0x25U;
    }
    temp_v0 = leoChk_done_status(asic_cmd);
    if ((temp_v0 != 0x2F) && (temp_v0 != 0)) {
        return temp_v0;
    }
    return 0U;
}

u8 leoDetect_index_w(void) {
    return leoSend_asic_cmd_w(0xE0001U, 0U);
}

// "leoRecal_i"
u8 func_801CD1EC(void) {
    return leoSend_asic_cmd_i(0x30001U, 0U);
}

u8 leoRecal_w(void) {
    return leoSend_asic_cmd_w(0x30001U, 0U);
}

u8 leoSeek_i(u16 arg0) {
    s32 temp_t0;

    temp_t0 = ((LEOtgt_param.head << 0xC) + LEOtgt_param.cylinder) << 0x10;
    if (!arg0) {
        return leoSend_asic_cmd_i(0x10001, temp_t0);
    }
    return leoSend_asic_cmd_i(0x20001, temp_t0);
}

u8 leoSeek_w(void) {
    u8 temp_v0;

    temp_v0 = leoSeek_i(0U);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    return leoWait_mecha_cmd_done(0x10001U);
}

u8 leoRecv_event_mesg(s32 control) {
    OSMesg sp1C;

    if ((osRecvMesg(&LEOevent_que, &sp1C, control) == 0) && (sp1C == (OSMesg)0xA0000)) {
        leoDrive_reset();
        return 0xFFU;
    }
    return 0U;
}

u32 leoChk_err_retry(u32 sense) {
    if ((currentCommand == 0xC) || (currentCommand == 8)) {
        switch (sense) {
            case 43:
                D_801E67F4 |= 2;
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
                D_801E67F4 |= 2;
                FALLTHROUGH;
            case 47:
                D_801E67F4 |= 1;
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
    return 0U;
}

u8 leoChk_cur_drvmode(void) {
    u8 var_v1;

    var_v1 = 0;
    if (!(D_801E67F0 & 0x01000000)) {
        var_v1 |= 1;
    }
    if (D_801E67F0 & 0x80000) {
        var_v1 |= 2;
    }
    if (D_801E67F0 & 0x100000) {
        var_v1 |= 4;
    }
    return var_v1;
}

void leoDrive_reset(void) {
    osEPiWriteIo(LEOPiInfo, 0x05000520U, 0xAAAA0000U);
}

u32 leoChkUnit_atten(void) {
    return (u32)D_801E67F4;
}

u32 leoRetUnit_atten(void) {
    if (D_801E67F4 & 2) {
        return 0x2BU;
    }
    if (D_801E67F4 & 1) {
        return 0x2FU;
    }
    return 0U;
}

void leoClrUA_RESET(void) {
    D_801E67F4 &= ~2;
}

void leoClrUA_MEDIUM_CHANGED(void) {
    D_801E67F4 &= ~1;
}

void leoSetUA_MEDIUM_CHANGED(void) {
    D_801E67F4 |= 1;
}

void leoInitUnit_atten(void) {
    D_801E67F4 = 1;
}
