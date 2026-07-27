#include "common.h"
#include "ultra64/internal.h"

STACK(leoDiskStack, 0xFF0);

s32 __osLeoInterrupt(void) {
    u32 temp_a1;
    volatile u32 sp30;
    u32 v;
    __OSTranxInfo* temp_t0;
    __OSBlockInfo* temp_t1;
    int errNum;
    __OSBlockInfo* temp_v1;

    temp_t0 = &__osDiskHandle->transferInfo;
    temp_t1 = &temp_t0->block[temp_t0->blockNum];
    sp30 = IO_READ(0xA4600010);
    if (sp30 & 1) {
        D_800068E0 &= ~0x800;
        temp_t1->errStatus = 0x1D;
        func_801D3244();
        return 1;
    }
    sp30 = IO_READ(0xA4600010);
    while (sp30 & 3) {
        sp30 = IO_READ(0xA4600010);
    }
    temp_a1 = IO_READ(0xA5000508);
    if (temp_a1 & 0x02000000) {
        sp30 = IO_READ(0xA4600010);
        while (sp30 & 3) {
            sp30 = IO_READ(0xA4600010);
        }
        IO_WRITE(0xA5000510, temp_t0->bmCtlShadow | 0x01000000);
        temp_t1->errStatus = 0;
        return 0;
    }
    if (temp_t0->cmdType == 2) {
        return 1;
    }
    if (temp_a1 & 0x08000000) {
        sp30 = IO_READ(0xA4600010);
        while (sp30 & 3) {
            sp30 = IO_READ(0xA4600010);
        }
        IO_READ(0xA5000508);
        temp_t1->errStatus = 0x16;
        func_801D3244();
        IO_WRITE(0xA4600010, 2);
        D_800068E0 |= 0x100401;
        return 1;
    }
    if (temp_t0->cmdType == 1) {
        if (!(temp_a1 & 0x40000000)) {
            if ((temp_t0->sectorNum + 1) != (temp_t0->transferMode * 0x55)) {
                temp_t1->errStatus = 0x18;
                func_801D3190();
            } else {
                IO_WRITE(0xA4600010, 2);
                D_800068E0 |= 0x100401;
                temp_t1->errStatus = 0;
                func_801D3244();
            }
        } else {
            temp_t1->dramAddr = (u32)temp_t1->dramAddr + temp_t1->sectorSize;
            temp_t0->sectorNum += 1;
            __osEPiRawStartDma(__osDiskHandle, 1, 0x05000400U, temp_t1->dramAddr, temp_t1->sectorSize);
        }
        return 1;
    }
    if (temp_t0->cmdType == 0) {
        if (temp_t0->transferMode == 3) {
            if ((s32)(temp_t1->C1ErrNum + 0x11) < temp_t0->sectorNum) {
                temp_t1->errStatus = 0;
                func_801D3190();
                return 1;
            }
            if (!(temp_a1 & 0x40000000)) {
                temp_t1->errStatus = 0x17;
                func_801D3190();
                return 1;
            }
        } else {
            temp_t1->dramAddr = (u32)temp_t1->dramAddr + temp_t1->sectorSize;
        }
        v = IO_READ(0xA5000510);
        if (((v & 0x200000) && (v & 0x400000)) || (v & 0x02000000)) {
            if (temp_t1->C1ErrNum >= 4U) {
                if ((temp_t0->transferMode != 3) || (temp_t0->sectorNum >= 0x53)) {
                    temp_t1->errStatus = 0x17;
                    func_801D3190();
                    return 1;
                }
            } else {
                errNum = temp_t1->C1ErrNum;
                temp_t1->C1ErrSector[errNum] = temp_t0->sectorNum + 1;
            }
            temp_t1->C1ErrNum += 1;
        }
        if (temp_a1 & 0x10000000) {
            if (temp_t0->sectorNum != 0x57) {
                temp_t1->errStatus = 0x18;
                func_801D3190();
            } else {
                if ((temp_t0->transferMode == 2) && (temp_t0->blockNum == 0)) {
                    temp_t0->blockNum = 1;
                    temp_t0->sectorNum = -1;
                    temp_t0->block[1].dramAddr = (u32)temp_t0->block[1].dramAddr - temp_t0->block[1].sectorSize;
                    temp_t1->errStatus = 0x16;
                } else {
                    IO_WRITE(0xA4600010, 2);
                    D_800068E0 |= 0x100401;
                    temp_t0->cmdType = 2;
                    temp_t1->errStatus = 0;
                }
                __osEPiRawStartDma(__osDiskHandle, 0, 0x05000000U, temp_t1->C2Addr, temp_t1->sectorSize * 4);
            }
            return 1;
        }
        if ((temp_t0->sectorNum == -1) && (temp_t0->transferMode == 2) && (temp_t0->blockNum == 1)) {
            temp_v1 = temp_t0->block;
            if (temp_t0->block[0].C1ErrNum == 0) {
                if ((((u32*)temp_v1->C2Addr)[0] | ((u32*)temp_v1->C2Addr)[1] | ((u32*)temp_v1->C2Addr)[2] |
                     ((u32*)temp_v1->C2Addr)[3]) != 0) {
                    temp_v1->errStatus = 0x17;
                    func_801D3190();
                    return 1;
                }
            }
            temp_t0->block[0].errStatus = 0;
            func_801D3244();
        }
        temp_t0->sectorNum += 1;
        if (temp_a1 & 0x40000000) {
            if (temp_t0->sectorNum >= 0x55) {
                temp_t1->errStatus = 0x18;
                func_801D3190();
                return 1;
            }
            __osEPiRawStartDma(__osDiskHandle, 0, 0x05000400U, temp_t1->dramAddr, temp_t1->sectorSize);
            temp_t1->errStatus = 0;
            return 1;
        }
        if (temp_t0->sectorNum < 0x55) {
            temp_t1->errStatus = 0x18;
            func_801D3190();
            return 1;
        }
        return 1;
    }
    temp_t1->errStatus = 4;
    func_801D3190();
    return 1;
}

void func_801D3190(void) {
    __OSTranxInfo* temp_a0;
    u32 pi_stat;

    temp_a0 = &__osDiskHandle->transferInfo;
    while ((pi_stat = IO_READ(0xA4600010)) & 3) {}
    IO_WRITE(0xA5000510, temp_a0->bmCtlShadow | 0x10000000);
    while ((pi_stat = IO_READ(0xA4600010)) & 3) {}
    IO_WRITE(0xA5000510, temp_a0->bmCtlShadow);
    func_801D3244();
    IO_WRITE(0xA4600010, 2);
    D_800068E0 |= 0x100401;
}

void func_801D3244(void) {
    __OSEventState* es;
    OSMesgQueue* mq;
    s32 last;

    es = &__osEventStateTab[OS_EVENT_PI];
    mq = es->queue;
    if (mq != NULL) {
        if (mq->validCount < mq->msgCount) {
            last = (mq->first + mq->validCount) % mq->msgCount;
            mq->msg[last] = es->msg;
            mq->validCount++;
            if (mq->mtqueue->next != NULL) {
                __osEnqueueThread(&__osRunQueue, __osPopThread(&mq->mtqueue));
            }
        }
    }
}
