#include "common.h"

u32 LeoDriveExist(void) {
    u32 sp1C;
    u32 temp_a0;
    u32 temp_a1;
    u32 temp_v0;
    u32 temp_v1;
    u32 new_var;

    __osPiGetAccess();
    while ((new_var = IO_READ(0xA4600010)) & 3) {}
    temp_v0 = IO_READ(0xA4600014);
    temp_v1 = IO_READ(0xA460001C);
    temp_a0 = IO_READ(0xA4600020);
    temp_a1 = IO_READ(0xA4600018);
    IO_WRITE(0xA4600014, 0xFF);
    IO_WRITE(0xA460001C, 0);
    IO_WRITE(0xA4600020, 3);
    IO_WRITE(0xA4600018, 0xFF);
    sp1C = IO_READ(0xA6001010);
    IO_WRITE(0xA4600014, temp_v0);
    IO_WRITE(0xA460001C, temp_v1);
    IO_WRITE(0xA4600020, temp_a0);
    IO_WRITE(0xA4600018, temp_a1);
    __osPiRelAccess();
    if (sp1C == 0x2129FFF8) {
        return 1U;
    }
    return 0U;
}
