#include "common.h"

s32 func_801CA3E0(s32 arg0) {
    s32 temp_t6;
    s32 var_a1;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_v0;
    s32 var_v1;

    var_v0 = 0;
    var_v1 = 0;
    if (arg0 < 0xA) {
        return arg0;
    }
    var_a1 = 1;
    if (arg0 >= 0xA) {
        var_a2_2 = 0xA;
        do {
            var_a1 = var_a2_2;
            var_v0 += 1;
            var_a2_2 *= 0xA;
        } while (arg0 >= var_a2_2);
    }
    var_a2 = arg0;
    while (var_v0--) {
        temp_t6 = var_a2 / var_a1;
        var_v1 = (var_v1 | temp_t6) * 0x10;
        var_a2 = var_a2 % var_a1;
        var_a1 = var_a1 / 10;
    }
    return var_v1 + var_a2;
}

s32 func_801CA4B8(void) {
    return gCurrentRegion == 1 ? 0 : 1;
}

void func_801CA4E4(u8* arg0, u8 arg1, s32 arg2) {
    while (arg2--) {
        *arg0++ = arg1;
    }
}

const char* func_801CA514(void) {
    return D_801D3750[func_801CA4B8()];
}

void func_801CA544(const char* arg0, s32 arg1) {
    s32 temp_v0;
    u16 var_a1;

    temp_v0 = func_801CA3E0(arg1);
    if (arg1 >= 0xA) {
        var_a1 = ((temp_v0 >> 4) + 0xA3B0);
    } else {
        var_a1 = 0xA1A1;
    }
    func_801C9D68((char*)arg0, var_a1);
    arg0 += 2;
    func_801C9D68((char*)arg0, ((temp_v0 & 0xF) + 0xA3B0));
}

void func_801CA5C4(char* arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_801CA3E0(arg1);
    if (arg1 >= 0xA) {
        *arg0 = (temp_v0 >> 4) + 0x30;
    } else {
        *arg0 = 0x20;
    }
    arg0++;
    *arg0 = (temp_v0 & 0xF) + 0x30;
}

void func_801CA628(void* arg0, s32 arg1) {
    const char* temp_v0;

    temp_v0 = func_801CA514();
    if (gCurrentRegion == 1) {
        func_801CA544((char*)(temp_v0 + 0xC), arg1);
    } else {
        func_801CA5C4((char*)(temp_v0 + 0xD), arg1);
    }
    func_801CA280(arg0, 0xC0, temp_v0);
}

void* func_801CA698(s32 arg0) {
    func_801CA730();
    if (arg0 == 0x29) {
        return (func_801CA4B8() * 0x600) + (char*)&D_801D3860;
    }
    if (((arg0 >= 0x25) && (arg0 < 0x29)) || (arg0 == 0x1F) || (arg0 == 0x20)) {
        return &D_801E1800;
    } else {
        func_801CA628(&D_801E1800, arg0);
        return &D_801E1800;
    }
}

void* func_801CA730(void) {
    func_801CA4E4((u8*)&D_801E1800, 0U, 0x600);
    return &D_801E1800;
}

void func_801CA764(void* arg0, s32 arg1, s32 arg2) {
    s32 var_s0;

    for (var_s0 = 0; var_s0 < arg2; var_s0++) {
        func_801CA280(arg0, 0x140, D_801D3760[func_801CA4B8()][arg1][var_s0]);
        arg0 = (char*)arg0 + 0xA00;
        if (1) {}
    }
}

void* func_801CA800(s32 arg0) {
    func_801CA86C();
    if (arg0 == 3) {
        return (func_801CA4B8() * 0x2800) + (char*)&D_801D4460;
    }
    func_801CA764(&D_801E1E00, arg0, 4);
    return &D_801E1E00;
}

void* func_801CA86C(void) {
    func_801CA4E4((u8*)&D_801E1E00, 0U, 0x2800);
    return &D_801E1E00;
}

UNK_PTR func_801CA8A0(s32 arg0) {
    func_801CA8E0();
    func_801CA764(&D_801E4600, arg0, 2);
    return &D_801E4600;
}

void* func_801CA8E0(void) {
    func_801CA4E4((u8*)&D_801E4600, 0, 0x1400);
    return &D_801E4600;
}
