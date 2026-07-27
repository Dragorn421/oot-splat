#include "common.h"

OSPiHandle __LeoDiskHandle;
OSPiHandle* __osDiskHandle;

OSPiHandle* osLeoDiskInit(void) {
    u32 temp_v0;

    __LeoDiskHandle.type = 2;
    __LeoDiskHandle.baseAddress = 0xA5000000;
    __LeoDiskHandle.latency = 3;
    __LeoDiskHandle.pulse = 6;
    __LeoDiskHandle.pageSize = 6;
    __LeoDiskHandle.relDuration = 2;
    __LeoDiskHandle.domain = 1;
    __LeoDiskHandle.speed = 0;
    bzero(&__LeoDiskHandle.transferInfo, sizeof(__LeoDiskHandle.transferInfo));
    temp_v0 = __osDisableInt();
    __LeoDiskHandle.next = __osPiTable;
    __osPiTable = &__LeoDiskHandle;
    __osDiskHandle = &__LeoDiskHandle;
    __osRestoreInt(temp_v0);
    return &__LeoDiskHandle;
}
