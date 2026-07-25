#include "common.h"

s32 LeoCJCreateLeoManager(s32 comPri, s32 intPri, void** cmdBuf, s32 cmdMsgCnt) {
    OSPiHandle* sp84;
    OSPiHandle* sp80;
    volatile LEOCmdInquiry sp60;
    volatile LEOCmd sp30;
    LEODiskID sp10;
    u32 stat;
    u32 data;
    volatile s32 dummy1;
    volatile u32 dummy2;

    if (__leoActive != 0) {
        return 0;
    }
    if (LeoDriveExist() == 0) {
        return 0x29;
    }
    osLeoDiskInit();
    sp84 = osDriveRomInit();
    __leoActive = 1;
    __osSetHWIntrRoutine(1U, __osLeoInterrupt, STACK_TOP(leoDiskStack));
    leoInitialize(comPri, intPri, cmdBuf, (u32)cmdMsgCnt);
    if (osResetType == 1) {
        __leoSetReset();
    }
    sp60.header.command = 2;
    sp60.header.reserve1 = 0;
    sp60.header.control = 0;
    sp60.header.reserve3 = 0;
    leoCommand((void*)&sp60);
    dummy1 = (u32)&sp60 & 0xFFFFFF;
    while (dummy1 > 0) {
        dummy1 -= ((s32)__leoSetReset & 0xFFFFFF) | 0x403DF4;
    }
    while (sp60.header.status == 8)
        ;
    if (sp60.header.status != 0) {
        return (s32)sp60.header.sense;
    }
    __leoVersion.drive = sp60.version;
    __leoVersion.driver = 6;
    __leoVersion.deviceType = sp60.dev_type;
    __leoVersion.ndevices = sp60.dev_num;
    if ((__leoVersion.drive & 0xF) == 4) {
        LEO_country_code = 0;
    } else if (((__leoVersion.drive & 0xF) == 3) || ((__leoVersion.drive & 0xF) == 1)) {
        osEPiReadIo(sp84, 0x9FF00U, &data);
        data = ((u32)(data & 0xFF000000) >> 0x18);
        dummy2 = 0x3ED98F23;
        if (data != 0xC3) {
            while (true) {}
        }
        dummy2 *= data;
        dummy2 -= (u32)&sp60;
        LEO_country_code = -0x17B72CEA;
    } else {
        while (true) {}
    }
    return 0;
}
