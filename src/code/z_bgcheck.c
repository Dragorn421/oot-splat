#include "global.h"

typedef struct struct_80039448_arg1 {
    u16 unk0;
} struct_80039448_arg1;

typedef struct struct_80039448 {
    s16 unk0;
    u16 unk2;
} struct_80039448;

u16 func_8003E4DC(struct_8003E398*);
void func_80038708(struct_80039448*, s16*, u16);

typedef struct struct_8003BB18_arg2 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} struct_8003BB18_arg2;

s32 func_80038600(Vec3f* arg0, const char* arg1, s32 arg2) {
    if ((arg0->x >= 32760.0f) || (arg0->x <= -32760.0f) || ((arg0->y >= 32760.0f)) || (arg0->y <= -32760.0f) ||
        ((arg0->z >= 32760.0f)) || ((arg0->z <= -32760.0f))) {
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("T_BGCheck_PosErrorCheck():位置が妥当ではありません。pos (%f,%f,%f) file:%s line:%d\n", arg0->x,
                     (f64)arg0->y, (f64)arg0->z, arg1, arg2);
        osSyncPrintf("\x1b[m");
        return 1;
    }
    return 0;
}

void func_80038708(struct_80039448* arg0, s16* arg1, u16 arg2) {
    arg0->unk0 = *arg1;
    arg0->unk2 = arg2;
}

void func_8003871C(u16* arg0) {
    *arg0 = 0xFFFF;
}

void func_80038728(struct_8003E398* arg0, u16* arg1, s16* arg2) {
    u16 sp1E;

    sp1E = func_8003E4DC(arg0);
    func_80038708((struct_80039448*)arg0->unk4 + sp1E, arg2, *arg1);
    *arg1 = sp1E;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80038780.s")

void func_800387FC(GlobalContext* arg0, struct_800387FC* arg1) {
    arg1->unk0 = 0;
    arg1->unk4 = 0;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003880C.s")

void func_80038870(struct_800387FC* arg0) {
    arg0->unk4 = 0;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80038878.s")

void func_800388A8(Vec3s* arg0, Vec3f* arg1) {
    arg1->x = (f32)arg0->x;
    arg1->y = (f32)arg0->y;
    arg1->z = (f32)arg0->z;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_800388E8.s")

s16 func_80038924(CollisionPoly* arg0, Vec3s* arg1) {
    s32 i;
    s32 new_var2;
    int new_var;
    s16 var_a3;

    if ((arg0->norm.y == 0x7FFF) || (arg0->norm.y == (-0x7FFF))) {
        return arg1[arg0->unk2_arr[0] & 0x1FFF].y;
    }
    i = arg0->unk2_arr[0] & 0x1FFF;
    new_var2 = arg0->unk2_arr[1] & 0x1FFF;
    new_var = arg0->unk2_arr[2];
    var_a3 = arg1[i].y;
    if (arg1[new_var2].y < var_a3) {
        var_a3 = arg1[new_var2].y;
    }
    if (var_a3 < arg1[new_var].y) {
        return var_a3;
    }
    return arg1[new_var].y;
}

void func_800389D4(CollisionPoly* arg0, f32* arg1, f32* arg2, f32* arg3) {
    *arg1 = (f32)arg0->norm.x * 0.00003051851f;
    *arg2 = (f32)arg0->norm.y * 0.00003051851f;
    *arg3 = (f32)arg0->norm.z * 0.00003051851f;
}

void func_800389D4(CollisionPoly* arg0, f32* arg1, f32* arg2, f32* arg3);
void func_80038A28(CollisionPoly* poly, f32 x, f32 y, f32 z, MtxF* mtxF) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fv1;
    s32 pad[2];

    if (poly != NULL) {
        func_800389D4(poly, &sp3C, &sp38, &sp34);
        var_fv1 = sqrtf(1.0f - (sp3C * sp3C));
        if (!(fabsf(var_fv1) < 0.008f)) {
            temp_fv0 = 1.0f / var_fv1;
            var_fa1 = sp38 * temp_fv0;
            var_fa0 = -(sp34 * temp_fv0);
        } else {
            var_fa1 = sqrtf(1.0f - (sp38 * sp38));
            if (!(fabsf(var_fa1) < 0.008f)) {
                temp_fv0_2 = 1.0f / var_fa1;
                var_fa0 = sp3C * temp_fv0_2;
                var_fv1 = -(sp34 * temp_fv0_2);
            } else {
                var_fa0 = 0.0f;
                var_fv1 = 0.0f;
            }
        }
        mtxF->mf[0][0] = var_fv1;
        mtxF->mf[0][1] = -sp3C * var_fa1;
        mtxF->mf[0][2] = sp3C * var_fa0;
        mtxF->mf[1][0] = sp3C;
        mtxF->mf[1][1] = sp38;
        mtxF->mf[1][2] = sp34;
        mtxF->mf[2][1] = var_fa0;
        if (0) {}
        mtxF->mf[2][2] = var_fa1;
        mtxF->mf[0][3] = 0.0f;
        mtxF->mf[1][3] = 0.0f;
        mtxF->mf[2][0] = 0.0f;
        mtxF->mf[2][3] = 0.0f;
        mtxF->mf[3][0] = x;
        mtxF->mf[3][1] = y;
        mtxF->mf[3][2] = z;
        mtxF->mf[3][3] = 1.0f;
    }
}

f32 func_80038B7C(CollisionPoly* arg0, Vec3f* arg1) {
    return ((((f32)arg0->norm.x * arg1->x) + ((f32)arg0->norm.y * arg1->y) + ((f32)arg0->norm.z * arg1->z)) *
            0.00003051851f) +
           (f32)arg0->dist;
}

void func_80038BE0(CollisionPoly* arg0, Vec3s* arg1, Vec3f* arg2) {
    func_800388A8(((arg0->unk2 & 0x1FFF)) + arg1, arg2);
    func_800388A8(((arg0->unk4 & 0x1FFF)) + arg1, &arg2[1]);
    func_800388A8((arg0->unk6) + arg1, &arg2[2]);
}

void func_80038C78(CollisionPoly* arg0, s32 arg1, CollisionContext* arg2, Vec3f* arg3) {
    Vec3s* var_a1;

    if ((arg0 == NULL) || ((s32)arg1 >= 0x33) || (arg3 == NULL)) {
        osSyncPrintf("\x1b[41;37m");
        osSyncPrintf("T_Polygon_GetVertex_bg_ai(): Error %d %d %d 引数が適切ではありません。処理を終了します。\n",
                     arg0 == NULL, ((s32)arg1 < 0x33) ^ 1, arg3 == NULL);
        osSyncPrintf("\x1b[m");
        if (arg3 != NULL) {
            arg3[2].z = 0.0f;
            arg3[1].z = 0.0f;
            arg3[1].y = 0.0f;
            arg3[1].x = 0.0f;
            arg3[0].z = 0.0f;
            arg3[0].y = 0.0f;
            arg3[0].x = 0.0f;
        }
    } else {
        if (arg1 == 0x32) {
            var_a1 = arg2->stat.colHeader->vertexArray;
        } else {
            var_a1 = arg2->dyna.unk13F4;
        }
        func_80038BE0(arg0, var_a1, arg3);
    }
}

extern Vec3f D_8015BC30;
extern Vec3f D_8015BC3C;
extern Vec3f D_8015BC48;
s32 func_80038D48(CollisionPoly* arg0, Vec3s* arg1, f32 arg2, f32 arg3, f32* arg4, f32 arg5) {
    Vec3s* vtx0;
    Vec3s* vtx1;
    Vec3s* vtx2;
    f32 nx;
    f32 ny;
    f32 nz;

    vtx0 = &arg1[arg0->unk2_arr[0] & 0x1FFF];
    Math_Vec3s_ToVec3f(&D_8015BC30, vtx0);
    vtx1 = &arg1[arg0->unk2_arr[1] & 0x1FFF];
    Math_Vec3s_ToVec3f(&D_8015BC3C, vtx1);
    vtx2 = &arg1[arg0->unk2_arr[2]];
    Math_Vec3s_ToVec3f(&D_8015BC48, vtx2);
    nx = (f32)arg0->norm.x * 0.00003051851f;
    ny = (f32)arg0->norm.y * 0.00003051851f;
    nz = (f32)arg0->norm.z * 0.00003051851f;
    return Math3D_TriChkPointParaYIntersectDist(&D_8015BC30, &D_8015BC3C, &D_8015BC48, nx, ny, nz, (f32)arg0->dist,
                                                arg3, arg2, arg4, arg5);
}

extern Vec3f D_8015BC58;
extern Vec3f D_8015BC64;
extern Vec3f D_8015BC70;
s32 func_80038E78(CollisionPoly* arg0, Vec3s* arg1, f32 arg2, f32 arg3, f32* arg4, f32 arg5) {
    f32 sp44;
    f32 sp40;
    f32 sp3C;

    func_80038BE0((CollisionPoly*)arg0, arg1, &D_8015BC58);
    func_800389D4((CollisionPoly*)arg0, &sp44, &sp40, &sp3C);
    return Math3D_TriChkPointParaYIntersectInsideTri(&D_8015BC58, &D_8015BC64, &D_8015BC70, sp44, sp40, sp3C,
                                                     (f32)arg0->dist, arg3, arg2, arg4, arg5);
}

s32 func_80038D48(CollisionPoly*, Vec3s*, f32, f32, f32*, f32);
s32 func_80038F20(CollisionPoly* arg0, Vec3s* arg1, f32 arg2, f32 arg3, f32* arg4) {
    return func_80038D48(arg0, arg1, arg2, arg3, arg4, 1.0f);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80038F60.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80039000.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_800390A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003937C.s")

void func_80038728(struct_8003E398*, u16*, s16*);
s16 func_80038924(CollisionPoly*, Vec3s*);
void func_80039448(CollisionContext* arg0, u16* arg1, CollisionPoly* arg2, Vec3s* arg3, s16 arg4) {
    struct_80039448* var_t1;
    struct_80039448* temp_a0;
    s16 var_a2;
    s32 temp_v0;
    u16 temp_v0_2;

    if (*arg1 == 0xFFFF) {
        func_80038728(&arg0->stat.unk44, arg1, &arg4);
        return;
    }
    temp_v0 = func_80038924(&arg2[arg4], arg3);
    var_t1 = (struct_80039448*)arg0->stat.unk44.unk4 + ((struct_80039448_arg1*)arg1)->unk0;
    var_a2 = var_t1->unk0;
    if ((temp_v0 < arg3[arg2[var_a2].unk2_arr[0] & 0x1FFF].y) &&
        (temp_v0 < arg3[arg2[var_a2].unk2_arr[1] & 0x1FFF].y)) {
        if (temp_v0 < arg3[arg2[var_a2].unk2_arr[2]].y) {
            func_80038728(&arg0->stat.unk44, arg1, &arg4);
            return;
        }
    }
loop_7:
    if (var_t1->unk2 == 0xFFFF) {
        temp_v0_2 = func_8003E4DC(&arg0->stat.unk44);
        func_80038708((struct_80039448*)arg0->stat.unk44.unk4 + temp_v0_2, &arg4, 0xFFFFU);
        var_t1->unk2 = temp_v0_2;
        return;
    }
    temp_a0 = (struct_80039448*)arg0->stat.unk44.unk4 + var_t1->unk2;
    var_a2 = temp_a0->unk0;
    if ((temp_v0 < arg3[arg2[var_a2].unk2_arr[0] & 0x1FFF].y) &&
        (temp_v0 < arg3[arg2[var_a2].unk2_arr[1] & 0x1FFF].y) && (temp_v0 < arg3[arg2[var_a2].unk2_arr[2]].y)) {
        temp_v0_2 = func_8003E4DC(&arg0->stat.unk44);
        func_80038708((struct_80039448*)arg0->stat.unk44.unk4 + temp_v0_2, &arg4, var_t1->unk2);
        var_t1->unk2 = temp_v0_2;
        return;
    }
    var_t1 = temp_a0;
    goto loop_7;
}

void func_8003965C(struct_8003BB18_arg2* arg0, CollisionContext* arg1, CollisionPoly* arg2, Vec3s* arg3, s16 arg4) {
    s16 temp_v0;

    temp_v0 = arg2[arg4].norm.y;
    if (temp_v0 >= 0x4000) {
        func_80039448(arg1, &arg0->unk0, arg2, arg3, arg4);
        return;
    }
    if (temp_v0 < -0x6665) {
        func_80039448(arg1, &arg0->unk4, arg2, arg3, arg4);
        return;
    }
    func_80039448(arg1, &arg0->unk2, arg2, arg3, arg4);
}

typedef struct struct_800396F0 {
    u16 unk0;
} struct_800396F0;
f32 func_800396F0(CollisionContext* arg0, u16 arg1, struct_800396F0* arg2, CollisionPoly** arg3, Vec3f* arg4, f32 arg5,
                  f32 arg6, s32 arg7) {
    f32 var_fs0;
    s32 temp_s0;
    struct_80039448* var_s1;
    f32 sp78;

    var_fs0 = arg5;
    if (arg2->unk0 == 0xFFFF) {
        return arg5;
    }
    var_s1 = &((struct_80039448*)arg0->stat.unk44.unk4)[(arg2->unk0)];
    while (true) {
        temp_s0 = var_s1->unk0;
        if (((((CollisionPoly*)arg0->stat.colHeader->polygonArray)[temp_s0]).unk2 & ((arg1 & 7) << 0xD)) ||
            ((arg7 & 1) && ((((CollisionPoly*)arg0->stat.colHeader->polygonArray)[temp_s0]).norm.y < 0))) {
            if (var_s1->unk2 != 0xFFFF) {
                var_s1 = &((struct_80039448*)arg0->stat.unk44.unk4)[(var_s1->unk2)];
                continue;
            }
            break;
        }
        if (!(!(arg4->y < (f32)(arg0->stat.colHeader->vertexArray[(
                                    ((((CollisionPoly*)arg0->stat.colHeader->polygonArray)[temp_s0]).unk2 & 0x1FFF))])
                              .y) ||
              !(arg4->y < (f32)(arg0->stat.colHeader->vertexArray[(
                                    ((((CollisionPoly*)arg0->stat.colHeader->polygonArray)[temp_s0]).unk4 & 0x1FFF))])
                              .y) ||
              !(arg4->y < (f32)(arg0->stat.colHeader->vertexArray[(
                                    (((CollisionPoly*)arg0->stat.colHeader->polygonArray)[temp_s0]).unk6)])
                              .y))) {
            break;
        }
        if ((func_80038E78(&((CollisionPoly*)arg0->stat.colHeader->polygonArray)[temp_s0],
                           arg0->stat.colHeader->vertexArray, arg4->x, arg4->z, &sp78, arg6) == 1) &&
            (sp78 < arg4->y) && (var_fs0 < sp78)) {
            var_fs0 = sp78;
            *arg3 = &((CollisionPoly*)arg0->stat.colHeader->polygonArray)[temp_s0];
        }
        if (var_s1->unk2 == 0xFFFF) {
            break;
        }
        var_s1 = (struct_80039448*)arg0->stat.unk44.unk4 + (var_s1->unk2);
    }
    return var_fs0;
}

f32 func_8003992C(UNK_PTR arg0, CollisionContext* arg1, u16 arg2, CollisionPoly** arg3, Vec3f* arg4, s32 arg5, f32 arg6,
                  f32 arg7) {
    f32 var_fv1;
    s32 var_v0;

    var_fv1 = arg7;
    if (arg5 & 4) {
        var_fv1 = func_800396F0(arg1, arg2, (struct_800396F0*)arg0, arg3, arg4, arg7, arg6, 0);
    }
    if ((arg5 & 2) || (arg5 & 8)) {
        var_v0 = 0;
        if (arg5 & 0x10) {
            var_v0 = 1;
        }
        var_fv1 = func_800396F0(arg1, arg2, (struct_800396F0*)((char*)arg0 + 2), arg3, arg4, var_fv1, arg6, var_v0);
    }
    if (arg5 & 1) {
        var_v0 = 0;
        if (arg5 & 0x10) {
            var_v0 = 1;
        }
        var_fv1 = func_800396F0(arg1, arg2, (struct_800396F0*)((char*)arg0 + 4), arg3, arg4, var_fv1, arg6, var_v0);
    }
    return var_fv1;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80039A3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80039AEC.s")

s32 func_80038F20(CollisionPoly*, Vec3s*, f32, f32, f32*);
typedef struct struct_8003A3E0 {
    char pad0[4];
    u16 unk4;
} struct_8003A3E0;
s32 func_8003A3E0(struct_8003A3E0* arg0, u16 arg1, CollisionContext* arg2, f32* arg3, Vec3f* arg4, f32 arg5,
                  CollisionPoly** arg6) {
    s32 var_t0;
    CollisionPoly* temp_s0;
    CollisionPoly* temp_s6;
    struct_80039448* var_s1;
    f32 sp8C;
    Vec3s* temp_s7;
    f32 temp_fv0;
    f32 new_var;
    u16 new_var2;
    s16 i;

    var_t0 = 0;
    if (arg0->unk4 == 0xFFFF) {
        return 0;
    }
    temp_s6 = arg2->stat.colHeader->polygonArray;
    var_s1 = &((struct_80039448*)arg2->stat.unk44.unk4)[(arg0->unk4)];
    temp_s7 = arg2->stat.colHeader->vertexArray;
    *arg3 = arg4->y;
    while (true) {
        i = var_s1->unk0;
        temp_s0 = &temp_s6[i];
        if ((((CollisionPoly*)arg2->stat.colHeader->polygonArray)[i]).unk2 & ((arg1 & 7) << 0xD)) {
            if (var_s1->unk2 == 0xFFFF) {
                break;
            }
            var_s1 = &((struct_80039448*)arg2->stat.unk44.unk4)[(var_s1->unk2)];
            continue;
        }
        if (func_80038F20(temp_s0, temp_s7, arg4->x, arg4->z, &sp8C) != 0) {
            temp_fv0 = sp8C - *arg3;
            new_var = ((f32)temp_s0->norm.y * 0.00003051851f);
            if ((temp_fv0 > 0) && (temp_fv0 < arg5) && ((temp_fv0 * new_var) <= 0.0f)) {
                var_t0 = 1;
                *arg3 = sp8C - arg5;
                *arg6 = temp_s0;
            }
        }
        if (var_s1->unk2 == 0xFFFF) {
            break;
        }
        var_s1 = &((struct_80039448*)arg2->stat.unk44.unk4)[(var_s1->unk2)];
        continue;
    }
    return var_t0;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003A5B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003A7D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003A95C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003AB28.s")

void func_8003ADC8(CollisionContext*, PosRot*, s32*);
UNK_PTR func_8003AC54(CollisionContext* arg0, UNK_PTR arg1, PosRot* arg2) {
    s32 sp1C[3];

    func_8003ADC8(arg0, arg2, sp1C);
    return ((char*)arg1 + (sp1C[0] * 6) + (sp1C[1] * arg0->stat.unk1C * 6) +
            (sp1C[2] * arg0->stat.unk1C * arg0->stat.unk20 * 6));
}

s32 func_8003C55C(CollisionContext*, Vec3f*);
void* func_8003AD00(CollisionContext* arg0, void* arg1, Vec3f* arg2) {
    s32 sp1C[3];

    if (func_8003C55C(arg0, arg2) == 0) {
        return NULL;
    }
    func_8003ADC8(arg0, (PosRot*)arg2, sp1C);
    return (char*)arg1 + (sp1C[0] * 6) + (sp1C[1] * arg0->stat.unk1C * 6) +
           (sp1C[2] * arg0->stat.unk1C * arg0->stat.unk20 * 6);
}

void func_8003ADC8(CollisionContext* arg0, PosRot* arg1, s32* arg2) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;

    arg2[0] = (s32)((arg1->pos.x - arg0->stat.unk4) * arg0->stat.unk34);
    arg2[1] = (s32)((arg1->pos.y - arg0->stat.unk8) * arg0->stat.unk38);
    arg2[2] = (s32)((arg1->pos.z - arg0->stat.unkC) * arg0->stat.unk3C);
    if (arg2[0] < 0) {
        arg2[0] = 0;
    } else {
        temp_v1 = arg0->stat.unk1C;
        if (arg2[0] >= temp_v1) {
            arg2[0] = temp_v1 - 1;
        }
    }
    temp_v0 = arg2[1];
    if (temp_v0 < 0) {
        arg2[1] = 0;
    } else {
        temp_v1_2 = arg0->stat.unk20;
        if (temp_v0 >= temp_v1_2) {
            arg2[1] = (s32)(temp_v1_2 - 1);
        }
    }
    temp_v0_2 = arg2[2];
    if (temp_v0_2 < 0) {
        arg2[2] = 0;
        return;
    }
    temp_v1_3 = arg0->stat.unk24;
    if (temp_v0_2 >= temp_v1_3) {
        arg2[2] = (s32)(temp_v1_3 - 1);
    }
}

void func_8003AEA8(CollisionContext* arg0, Vec3f* arg1, s32* arg2, s32* arg3, s32* arg4) {
    f32 temp_fa0;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    temp_fv0 = arg1->x - arg0->stat.unk4;
    temp_fv1 = arg1->y - arg0->stat.unk8;
    temp_fa0 = arg1->z - arg0->stat.unkC;
    *arg2 = (s32)(arg0->stat.unk34 * temp_fv0);
    *arg3 = (s32)(arg0->stat.unk38 * temp_fv1);
    *arg4 = (s32)(arg0->stat.unk3C * temp_fa0);
    if (((s32)temp_fv0 % (s32)arg0->stat.unk28) < 0x32) {
        temp_v0 = *arg2;
        if (temp_v0 > 0) {
            *arg2 = temp_v0 - 1;
        }
    }
    if (((s32)temp_fv1 % (s32)arg0->stat.unk2C) < 0x32) {
        temp_v0_2 = *arg3;
        if (temp_v0_2 > 0) {
            *arg3 = temp_v0_2 - 1;
        }
    }
    if (((s32)temp_fa0 % (s32)arg0->stat.unk30) < 0x32) {
        temp_v0_3 = *arg4;
        if (temp_v0_3 > 0) {
            *arg4 = temp_v0_3 - 1;
        }
    }
}

void func_8003B04C(CollisionContext* arg0, Vec3f* arg1, s32* arg2, s32* arg3, s32* arg4) {
    f32 temp_fa0;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 temp_ft1;
    s32 temp_ft4;
    s32 temp_ft4_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    temp_fv0 = arg1->x - arg0->stat.unk4;
    temp_fv1 = arg1->y - arg0->stat.unk8;
    temp_fa0 = arg1->z - arg0->stat.unkC;
    *arg2 = (s32)(arg0->stat.unk34 * temp_fv0);
    *arg3 = (s32)(arg0->stat.unk38 * temp_fv1);
    *arg4 = (s32)(arg0->stat.unk3C * temp_fa0);
    temp_ft4 = (s32)arg0->stat.unk28;
    if ((temp_ft4 - 0x32) < ((s32)temp_fv0 % temp_ft4)) {
        temp_v0 = *arg2;
        if (temp_v0 < (arg0->stat.unk1C - 1)) {
            *arg2 = temp_v0 + 1;
        }
    }
    temp_ft1 = (s32)arg0->stat.unk2C;
    if ((temp_ft1 - 0x32) < ((s32)temp_fv1 % temp_ft1)) {
        temp_v0_2 = *arg3;
        if (temp_v0_2 < (arg0->stat.unk20 - 1)) {
            *arg3 = temp_v0_2 + 1;
        }
    }
    temp_ft4_2 = (s32)arg0->stat.unk30;
    if ((temp_ft4_2 - 0x32) < ((s32)temp_fa0 % temp_ft4_2)) {
        temp_v0_3 = *arg4;
        if (temp_v0_3 < (arg0->stat.unk24 - 1)) {
            *arg4 = temp_v0_3 + 1;
        }
    }
}

void func_8003B218(CollisionContext* arg0, Vec3s* arg1, CollisionPoly* arg2, s32* arg3, s32* arg4, s32* arg5, s32* arg6,
                   s32* arg7, s32* arg8, s16 arg9) {
    Vec3s* temp_v0;
    Vec3f sp58;
    Vec3f sp4C;
    f32 temp_fa0;
    f32 temp_fv0;
    f32 temp_fv1;
    u16* var_a0;
    s16 new_var;

    new_var = arg2[arg9].unk2 & 0x1FFF;
    Math_Vec3s_ToVec3f(&sp4C, &arg1[new_var]);
    Math_Vec3f_Copy(&sp58, &sp4C);
    for (var_a0 = arg2[arg9].unk2_arr + 1; var_a0 < arg2[arg9].unk2_arr + 3; var_a0++) {
        new_var = *var_a0 & 0x1FFF;
        temp_v0 = &arg1[new_var];
        temp_fv0 = (f32)temp_v0->x;
        temp_fv1 = (f32)temp_v0->y;
        temp_fa0 = (f32)temp_v0->z;
        if (temp_fv0 < sp58.x) {
            sp58.x = temp_fv0;
        } else if (sp4C.x < temp_fv0) {
            sp4C.x = temp_fv0;
        }
        if (temp_fv1 < sp58.y) {
            sp58.y = temp_fv1;
        } else if (sp4C.y < temp_fv1) {
            sp4C.y = temp_fv1;
        }
        if (temp_fa0 < sp58.z) {
            sp58.z = temp_fa0;
        } else if (sp4C.z < temp_fa0) {
            sp4C.z = temp_fa0;
        }
    }
    func_8003AEA8(arg0, &sp58, arg3, arg4, arg5);
    func_8003B04C(arg0, &sp4C, arg6, arg7, arg8);
}

s32 func_8003B3C8(Vec3f* arg0, Vec3f* arg1, CollisionPoly* arg2, Vec3s* arg3, s16 arg4) {
    f32 spB4;
    Vec3f spA8;
    Vec3f sp9C;
    Vec3f sp90;
    CollisionPoly* sp44;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    Vec3f sp70;
    Vec3f sp64;
    Vec3f sp58;
    s32 sp4C[3];

    sp4C[1] = 0;
    sp4C[0] = 0;
    sp44 = &arg2[arg4];
    func_800388A8(&arg3[sp44->unk2_arr[0] & 0x1FFF], &sp70);
    sp4C[0] = Math3D_PointRelativeToCubeFaces(&sp70, arg0, arg1);
    if (sp4C[0] == 0) {
        return 1;
    }
    func_800388A8(&arg3[sp44->unk2_arr[1] & 0x1FFF], &sp64);
    sp4C[1] = Math3D_PointRelativeToCubeFaces(&sp64, arg0, arg1);
    if (sp4C[1] == 0) {
        return 1;
    }
    func_800388A8(&arg3[sp44->unk2_arr[2]], &sp58);
    sp4C[2] = Math3D_PointRelativeToCubeFaces(&sp58, arg0, arg1);
    if (sp4C[2] == 0) {
        return 1;
    }
    if (sp4C[0] & sp4C[1] & sp4C[2]) {
        return 0;
    }
    sp4C[0] |= Math3D_PointRelativeToCubeEdges(&sp70, arg0, arg1) << 8;
    sp4C[1] |= Math3D_PointRelativeToCubeEdges(&sp64, arg0, arg1) << 8;
    sp4C[2] |= (Math3D_PointRelativeToCubeEdges(&sp58, arg0, arg1) << 8);
    if (sp4C[0] & sp4C[1] & sp4C[2]) {
        return 0;
    }
    sp4C[0] |= Math3D_PointRelativeToCubeVertices(&sp70, arg0, arg1) << 0x18;
    sp4C[1] |= Math3D_PointRelativeToCubeVertices(&sp64, arg0, arg1) << 0x18;
    sp4C[2] |= (Math3D_PointRelativeToCubeVertices(&sp58, arg0, arg1) << 0x18);
    if (sp4C[0] & sp4C[1] & sp4C[2]) {
        return 0;
    }
    func_800389D4(sp44, &sp88, &sp84, &sp80);
    sp7C = (f32)sp44->dist;
    if ((Math3D_TriChkLineSegParaYIntersect(&sp70, &sp64, &sp58, sp88, sp84, sp80, sp7C, arg0->z, arg0->x, &spB4,
                                            arg0->y, arg1->y) != 0) ||
        (Math3D_TriChkLineSegParaYIntersect(&sp70, &sp64, &sp58, sp88, sp84, sp80, sp7C, arg1->z, arg0->x, &spB4,
                                            arg0->y, arg1->y) != 0) ||
        (Math3D_TriChkLineSegParaYIntersect(&sp70, &sp64, &sp58, sp88, sp84, sp80, sp7C, arg0->z, arg1->x, &spB4,
                                            arg0->y, arg1->y) != 0) ||
        (Math3D_TriChkLineSegParaYIntersect(&sp70, &sp64, &sp58, sp88, sp84, sp80, sp7C, arg1->z, arg1->x, &spB4,
                                            arg0->y, arg1->y) != 0)) {
        return 1;
    }
    if ((Math3D_TriChkLineSegParaZIntersect(&sp70, &sp64, &sp58, sp88, sp84, sp80, sp7C, arg0->x, arg0->y, &spB4,
                                            arg0->z, arg1->z) != 0) ||
        (Math3D_TriChkLineSegParaZIntersect(&sp70, &sp64, &sp58, sp88, sp84, sp80, sp7C, arg0->x, arg1->y, &spB4,
                                            arg0->z, arg1->z) != 0) ||
        (Math3D_TriChkLineSegParaZIntersect(&sp70, &sp64, &sp58, sp88, sp84, sp80, sp7C, arg1->x, arg0->y, &spB4,
                                            arg0->z, arg1->z) != 0) ||
        (Math3D_TriChkLineSegParaZIntersect(&sp70, &sp64, &sp58, sp88, sp84, sp80, sp7C, arg1->x, arg1->y, &spB4,
                                            arg0->z, arg1->z) != 0)) {
        return 1;
    }
    if ((Math3D_TriChkLineSegParaXIntersect(&sp70, &sp64, &sp58, sp88, sp84, sp80, sp7C, arg0->y, arg0->z, &spB4,
                                            arg0->x, arg1->x) != 0) ||
        (Math3D_TriChkLineSegParaXIntersect(&sp70, &sp64, &sp58, sp88, sp84, sp80, sp7C, arg0->y, arg1->z, &spB4,
                                            arg0->x, arg1->x) != 0) ||
        (Math3D_TriChkLineSegParaXIntersect(&sp70, &sp64, &sp58, sp88, sp84, sp80, sp7C, arg1->y, arg0->z, &spB4,
                                            arg0->x, arg1->x) != 0) ||
        (Math3D_TriChkLineSegParaXIntersect(&sp70, &sp64, &sp58, sp88, sp84, sp80, sp7C, arg1->y, arg1->z, &spB4,
                                            arg0->x, arg1->x) != 0)) {
        return 1;
    }
    func_800388A8(&arg3[sp44->unk2_arr[0] & 0x1FFF], &spA8);
    func_800388A8(&arg3[sp44->unk2_arr[1] & 0x1FFF], &sp9C);
    func_800388A8(&arg3[sp44->unk2_arr[2]], &sp90);
    if ((Math3D_LineVsCube(arg0, arg1, &spA8, &sp9C) != 0) || (Math3D_LineVsCube(arg0, arg1, &sp9C, &sp90) != 0) ||
        (Math3D_LineVsCube(arg0, arg1, &sp90, &spA8) != 0)) {
        return 1;
    }
    return 0;
}

s32 func_8003BB18(CollisionContext* arg0, GlobalContext* arg1, UNK_PTR /* struct_8003BB18_arg2* */ arg2) {
    void* temp_s5_polygonArray;
    struct_8003BB18_arg2* var_fp;
    s32 temp_v1_nbPolygons;
    s32 spE8_iPoly;
    Vec3s* temp_s4_vertexArray;
    s32 spE0_iy;
    s32 var_a0_iz;
    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    s32 spC8;
    s32 spC4;
    Vec3f spB8;
    Vec3f spAC;
    f32 temp_fs1;
    struct_8003BB18_arg2* var_a1_2;
    f32 temp_fs2;
    f32 temp_fs3;
    s32 sp98;
    CollisionHeader* temp_a3;
    s32 var_s1_ix;
    struct_8003BB18_arg2* var_s0;

    temp_a3 = arg0->stat.colHeader;
    var_a1_2 = arg2;
    while (var_a1_2 < ((arg0->stat.unk1C * arg0->stat.unk20 * arg0->stat.unk24) + (struct_8003BB18_arg2*)arg2)) {
        var_a1_2->unk0 = 0xFFFF;
        var_a1_2->unk2 = 0xFFFF;
        var_a1_2->unk4 = 0xFFFF;
        var_a1_2++;
    }
    temp_v1_nbPolygons = (u16)temp_a3->nbPolygons;
    temp_s4_vertexArray = temp_a3->vertexArray;
    temp_s5_polygonArray = temp_a3->polygonArray;
    sp98 = arg0->stat.unk1C * arg0->stat.unk20;
    temp_fs1 = arg0->stat.unk28 + 100.0f;
    temp_fs2 = arg0->stat.unk2C + 100.0f;
    temp_fs3 = arg0->stat.unk30 + 100.0f;
    for (spE8_iPoly = 0; spE8_iPoly < temp_v1_nbPolygons; spE8_iPoly++) {
        func_8003B218(arg0, temp_s4_vertexArray, temp_s5_polygonArray, &spD8, &spD4, &spD0, &spCC, &spC8, &spC4,
                      (s32)(s16)spE8_iPoly);
        //! FAKE
        do {
            var_a1_2 = (spD0 * sp98) + (struct_8003BB18_arg2*)arg2;
        } while (0);
        spB8.z = ((arg0->stat.unk30 * (f32)spD0) + arg0->stat.unkC) - 50.0f;
        spAC.z = spB8.z + temp_fs3;
        for (var_a0_iz = spD0; var_a0_iz < spC4 + 1; var_a0_iz++) {
            var_fp = (arg0->stat.unk1C * spD4) + var_a1_2;
            spB8.y = ((arg0->stat.unk2C * (f32)spD4) + arg0->stat.unk8) - 50.0f;
            spAC.y = spB8.y + temp_fs2;
            for (spE0_iy = spD4; spE0_iy < spC8 + 1; spE0_iy++) {
                var_s0 = (spD8) + var_fp;
                spB8.x = ((arg0->stat.unk28 * (f32)spD8) + arg0->stat.unk4) - 50.0f;
                spAC.x = spB8.x + temp_fs1;
                for (var_s1_ix = spD8; var_s1_ix < spCC + 1; var_s1_ix++) {
                    if (func_8003B3C8(&spB8, &spAC, temp_s5_polygonArray, temp_s4_vertexArray, spE8_iPoly) != 0) {
                        func_8003965C(var_s0, arg0, temp_s5_polygonArray, temp_s4_vertexArray, spE8_iPoly);
                    }
                    spB8.x += arg0->stat.unk28;
                    spAC.x += arg0->stat.unk28;
                    var_s0 += 1;
                }
                spB8.y += arg0->stat.unk2C;
                spAC.y += arg0->stat.unk2C;
                var_fp += arg0->stat.unk1C;
            }
            spB8.z += arg0->stat.unk30;
            spAC.z += arg0->stat.unk30;
            var_a1_2 += sp98;
        }
    }
    return (u16)arg0->stat.unk44.unk2 * 4;
}

extern s16 D_80119E2C[];
s32 func_8003BF18(GlobalContext* arg0) {
    s16* var_v0;

    for (var_v0 = D_80119E2C; var_v0 < &D_80119E2C[19]; var_v0++) {
        if (arg0->sceneNum == *var_v0) {
            return 1;
        }
    }
    return 0;
}

typedef struct struct_80119E54 {
    s16 unk0;
    s32 unk4;
} struct_80119E54;
extern struct_80119E54 D_80119E54[];
s32 func_8003BF5C(s32 arg0, u32* arg1) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (arg0 == D_80119E54[i].unk0) {
            *arg1 = D_80119E54[i].unk4;
            return 1;
        }
    }
    return 0;
}

void func_8003BFF4(f32 arg0, s32 arg1, f32* arg2, f32* arg3, f32* arg4) {
    float new_var;

    new_var = (*arg2) - arg0;
    *arg3 = (f32)((s32)(new_var / arg1) + 1);
    if (*arg3 < 150.0f) {
        *arg3 = 150.0f;
    } else {
        *arg3 = *arg3;
    }
    *arg4 = 1.0f / *arg3;
    *arg2 = (*arg3 * arg1) + arg0;
}

typedef struct struct_80119E94 {
    /* 0x0 */ s16 unk0; /* inferred */
    /* 0x2 */ s16 unk2; /* inferred */
    /* 0x4 */ s16 unk4; /* inferred */
    /* 0x6 */ s16 unk6; /* inferred */
    /* 0x8 */ s32 unk8; /* inferred */
} struct_80119E94;      /* size = 0xC */
extern struct_80119E94 D_80119E94[];
s32 func_8003BB18(CollisionContext* arg0, GlobalContext* arg1, UNK_PTR arg2);
s32 func_8003BF18(GlobalContext* arg0);
void func_8003BFF4(f32 arg0, s32 arg1, f32* arg2, f32* arg3, f32* arg4);
void func_8003E398(struct_8003E398*);
void func_8003E3AC(GlobalContext* arg0, struct_8003E398* arg1, u32 arg2, s32 arg3);
void func_8003E954(GlobalContext* arg0, DynaCollisionContext* arg1);
void func_8003E9A0(GlobalContext* arg0, DynaCollisionContext* arg1);
void func_8003C078(CollisionContext* arg0, GlobalContext* arg1, CollisionHeader* arg2) {
    s32 var_a2;
    u32 sp50;
    s32 var_a0;
    u32 temp_s2;
    s32 var_s2;
    u32 sp40;
    s32 i;
    s32 pad;

    arg0->stat.colHeader = arg2;
    var_s2 = -1;
    osSyncPrintf("/*---------------- BGCheck バッファーメモリサイズ -------------*/\n");
    if ((gGameInfo->data[0x24F] == 0x10) || (gGameInfo->data[0x24F] == 0x20) || (gGameInfo->data[0x24F] == 0x30) ||
        (gGameInfo->data[0x24F] == 0x40)) {
        if (arg1->sceneNum == 0x36) {
            osSyncPrintf("/* BGCheck LonLonサイズ %dbyte */\n", 0x3520);
            arg0->dyna.unk1410 = 0x3520;
        } else {
            osSyncPrintf("/* BGCheck ミニサイズ %dbyte */\n", 0x4E20);
            arg0->dyna.unk1410 = 0x4E20;
        }
        arg0->dyna.unk1404 = 0x1F4;
        arg0->dyna.unk1408 = 0x100;
        arg0->dyna.unk140C = 0x100;
        arg0->stat.unk1C = 2;
        arg0->stat.unk20 = 2;
        arg0->stat.unk24 = 2;
    } else {
        if (func_8003BF18(arg1) == 1) {
            arg0->dyna.unk1410 = 0xF000;
            osSyncPrintf("/* BGCheck Spot用サイズ %dbyte */\n", 0xF000);
            arg0->dyna.unk1404 = 0x3E8;
            arg0->dyna.unk1408 = 0x200;
            arg0->dyna.unk140C = 0x200;
            arg0->stat.unk1C = 0x10;
            arg0->stat.unk20 = 4;
            arg0->stat.unk24 = 0x10;
        } else {
            if (func_8003BF5C(arg1->sceneNum, &sp40) != 0) {
                arg0->dyna.unk1410 = sp40;
            } else {
                arg0->dyna.unk1410 = 0x1CC00;
            }
            osSyncPrintf("/* BGCheck ノーマルサイズ %dbyte  */\n", arg0->dyna.unk1410);
            arg0->dyna.unk1404 = 0x3E8;
            arg0->dyna.unk1408 = 0x200;
            arg0->dyna.unk140C = 0x200;
            var_a0 = 0;
            for (i = 0; i < 2; i++) {
                if (arg1->sceneNum == D_80119E94[i].unk0) {
                    var_a0 = 1;
                    arg0->stat.unk1C = (s32)D_80119E94[i].unk2;
                    arg0->stat.unk20 = (s32)D_80119E94[i].unk4;
                    arg0->stat.unk24 = (s32)D_80119E94[i].unk6;
                    var_s2 = D_80119E94[i].unk8;
                }
            }
            if (var_a0 == 0) {
                arg0->stat.unk1C = 0x10;
                arg0->stat.unk20 = 4;
                arg0->stat.unk24 = 0x10;
            }
        }
    }
    arg0->stat.unk40 =
        THA_AllocEndAlign(&arg1->state.tha, arg0->stat.unk1C * 6 * arg0->stat.unk20 * arg0->stat.unk24, -2U);
    if (arg0->stat.unk40 == 0) {
        LogUtils_HungupThread("../z_bgcheck.c", 0x1050);
    }
    arg0->stat.unk4 = (f32)arg0->stat.colHeader->colAbsMin.x;
    arg0->stat.unk8 = (f32)arg0->stat.colHeader->colAbsMin.y;
    arg0->stat.unkC = (f32)arg0->stat.colHeader->colAbsMin.z;
    arg0->stat.unk10 = (f32)arg0->stat.colHeader->colAbsMax.x;
    arg0->stat.unk14 = (f32)arg0->stat.colHeader->colAbsMax.y;
    arg0->stat.unk18 = (f32)arg0->stat.colHeader->colAbsMax.z;
    func_8003BFF4(arg0->stat.unk4, arg0->stat.unk1C, &arg0->stat.unk10, &arg0->stat.unk28, &arg0->stat.unk34);
    func_8003BFF4(arg0->stat.unk8, arg0->stat.unk20, &arg0->stat.unk14, &arg0->stat.unk2C, &arg0->stat.unk38);
    func_8003BFF4(arg0->stat.unkC, arg0->stat.unk24, &arg0->stat.unk18, &arg0->stat.unk30, &arg0->stat.unk3C);
    sp50 = (arg0->stat.unk1C * 6 * arg0->stat.unk20 * arg0->stat.unk24) + (u16)arg0->stat.colHeader->nbPolygons +
           (arg0->dyna.unk1404 * 4) + (arg0->dyna.unk1408 * 0x10) + (arg0->dyna.unk140C * 6) + 0x1464;
    if (var_s2 > 0) {
        var_a2 = var_s2;
    } else {
        if ((u32)arg0->dyna.unk1410 < sp50) {
            LogUtils_HungupThread("../z_bgcheck.c", 0x1086);
        }
        var_a2 = (s32)((u32)(arg0->dyna.unk1410 - sp50) >> 2);
    }
    func_8003E398(&arg0->stat.unk44);
    func_8003E3AC(arg1, &arg0->stat.unk44, (u32)var_a2, (u16)arg0->stat.colHeader->nbPolygons);
    temp_s2 = func_8003BB18(arg0, arg1, arg0->stat.unk40);
    osSyncPrintf("\x1b[32m");
    osSyncPrintf("/*---結局 BG使用サイズ %dbyte---*/\n", sp50 + temp_s2);
    osSyncPrintf("\x1b[m");
    func_8003E954(arg1, &arg0->dyna);
    func_8003E9A0(arg1, &arg0->dyna);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/T_BGCheck_getBGDataInfo.s")

s32 func_8003C55C(CollisionContext* arg0, Vec3f* arg1) {
    if ((arg1->x < (arg0->stat.unk4 - 50.0f)) || ((arg0->stat.unk10 + 50.0f) < arg1->x) ||
        ((arg1->y < (arg0->stat.unk8 - 50.0f))) || ((arg0->stat.unk14 + 50.0f) < arg1->y) ||
        ((arg1->z < (arg0->stat.unkC - 50.0f))) || ((arg0->stat.unk18 + 50.0f) < arg1->z)) {
        return 0;
    }
    return 1;
}

UNK_PTR func_8003AD00(CollisionContext*, UNK_PTR, Vec3f*);
typedef struct struct_8003FDDC {
    /* 0x00 */ GlobalContext* unk0;
    /* 0x04 */ CollisionContext* unk4; /* inferred */
    /* 0x08 */ s16 unk8;               /* inferred */
    /* 0x0A */ char padA[2];
    /* 0x0C */ CollisionPoly** unkC; /* inferred */
    /* 0x10 */ f32 unk10;            /* inferred */
    /* 0x14 */ Vec3f* unk14;         /* inferred */
    /* 0x18 */ void* unk18;          /* inferred */
    /* 0x1C */ Actor* unk1C;         /* inferred */
    /* 0x20 */ s32 unk20;            /* inferred */
    /* 0x24 */ f32 unk24;            /* inferred */
    /* 0x28 */ char pad28[0xC];      /* maybe part of unk24[4]? */
} struct_8003FDDC;                   /* size = 0x34 ? */
f32 func_8003FDDC(struct_8003FDDC*);
s32 func_80041EC8(CollisionContext*, CollisionPoly*, UNK_TYPE);
f32 func_8003C614(GlobalContext* arg0, CollisionContext* arg1, u16 arg2, CollisionPoly** arg3, UNK_TYPE* arg4,
                  Vec3f* arg5, Actor* arg6, s32 arg7, f32 arg8) {
    f32 temp_fv0_2;
    f32 var_fs1;
    UNK_PTR temp_v0;
    Vec3f spA0;
    struct_8003FDDC sp6C;
    UNK_PTR temp_s5;

    *arg4 = 0x32;
    *arg3 = NULL;
    temp_s5 = arg1->stat.unk40;
    spA0 = *arg5;
    var_fs1 = -32000.0f;
    while (true) {
        if (!(spA0.y < arg1->stat.unk8)) {
            if ((func_80038600(&spA0, "../z_bgcheck.c", 0x113A) != 0) && (arg6 != NULL)) {
                osSyncPrintf("こいつ,pself_actor->name %d\n", arg6->id);
            }
            temp_v0 = func_8003AD00(arg1, temp_s5, &spA0);
            if (temp_v0 == 0) {
                spA0.y -= arg1->stat.unk2C;
                continue;
            }
            var_fs1 = func_8003992C(temp_v0, arg1, arg2, arg3, arg5, arg7, arg8, -32000.0f);
            if (!(var_fs1 > -32000.0f)) {
                spA0.y -= arg1->stat.unk2C;
                continue;
            }
        }
        break;
    }
    sp6C.unk4 = arg1;
    sp6C.unk8 = arg2;
    sp6C.unk10 = var_fs1;
    sp6C.unk14 = arg5;
    sp6C.unk1C = arg6;
    sp6C.unk20 = arg7;
    sp6C.unk24 = arg8;
    sp6C.unk0 = arg0;
    sp6C.unkC = arg3;
    sp6C.unk18 = arg4;
    temp_fv0_2 = func_8003FDDC(&sp6C);
    if (var_fs1 < temp_fv0_2) {
        var_fs1 = temp_fv0_2;
    }
    if ((var_fs1 != -32000.0f) && (func_80041EC8(arg1, *arg3, *arg4) != 0)) {
        var_fs1 -= 1.0f;
    }
    return var_fs1;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003C834.s")

f32 func_8003C890(CollisionContext* arg0, CollisionPoly** arg1, Vec3f* arg2) {
    UNK_TYPE sp34;

    return func_8003C614(0, arg0, 2, arg1, &sp34, arg2, 0, 0x1C, 1.0f);
}

f32 func_8003C8EC(GlobalContext* arg0, CollisionContext* arg1, CollisionPoly** arg2, Vec3f* arg3) {
    UNK_TYPE sp34;

    return func_8003C614(arg0, arg1, 2, arg2, &sp34, arg3, 0, 0x1C, 1.0f);
}

f32 func_8003C940(CollisionContext* arg0, CollisionPoly** arg1, s32* arg2, Vec3f* arg3) {
    return func_8003C614(NULL, arg0, 2, arg1, arg2, arg3, 0, 0x1C, 1.0f);
}

f32 func_8003C9A4(CollisionContext* arg0, CollisionPoly** arg1, void* arg2, Actor* arg3, Vec3f* arg4) {
    return func_8003C614(NULL, arg0, 2, arg1, arg2, arg4, arg3, 0x1C, 1.0f);
}

f32 func_8003CA0C(GlobalContext* globalCtx, CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, Actor* actor,
                  Vec3f* pos) {
    return func_8003C614(globalCtx, colCtx, 2, outPoly, bgId, pos, actor, 0x1C, 1.0f);
}

f32 func_8003CA64(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, Actor* actor, Vec3f* pos, f32 chkDist) {
    return func_8003C614(NULL, colCtx, 2, outPoly, bgId, pos, actor, 0x1C, chkDist);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003CAC8.s")

f32 func_8003CB30(CollisionContext* arg0, CollisionPoly* arg1, Vec3f* arg2) {
    CollisionPoly* sp3C;
    f32 temp_fv1;
    UNK_TYPE sp34;

    temp_fv1 = func_8003C614(NULL, arg0, 0, &sp3C, &sp34, arg2, NULL, 0x1C, 1.0f);
    if (sp3C != NULL) {
        *arg1 = *sp3C;
    }
    return temp_fv1;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003CBE8.s")

f32 func_8003CCA4(CollisionContext* arg0, CollisionPoly** arg1, s32* arg2, Vec3f* arg3) {
    return func_8003C614(NULL, arg0, 1, arg1, arg2, arg3, NULL, 6, 1.0f);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003CD08.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003CD70.s")

s32 func_8003D7F0(CollisionContext*, u16, UNK_PTR, Vec3f*, Vec3f*, Vec3f*, CollisionPoly**, s32*, Actor*, f32, s32);
s32 func_80039AEC(UNK_PTR, CollisionContext*, u16, Vec3f*, f32*, UNK_PTR, f32, CollisionPoly**);
s32 func_8003C55C(CollisionContext*, Vec3f*);
s32 func_800409A8(CollisionContext*, u16, Vec3f*, f32*, UNK_PTR, f32, CollisionPoly**, s32*, Actor*);
s32 func_8003CDD4(CollisionContext* arg0, u16 arg1, Vec3f* arg2, Vec3f* arg3, Vec3f* arg4, f32 arg5,
                  CollisionPoly** arg6, s32* arg7, Actor* arg8, f32 arg9, s32 arg10);
s32 func_8003CDD4(CollisionContext* arg0, u16 arg1, Vec3f* arg2, Vec3f* arg3, Vec3f* arg4, f32 arg5,
                  CollisionPoly** arg6, s32* arg7, Actor* arg8, f32 arg9, s32 arg10) {
    void* spDC;
    s32 padD8;
    s32 spD4;
    CollisionPoly* spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    Vec3f spB8;
    s32 spB4;
    Vec3f spA8;
    s32 spA4;
    f32 temp_fv0;

    spD4 = 0;
    *arg7 = 0x32;
    *arg6 = NULL;
    spDC = arg0->stat.unk40;
    *arg2 = *arg3;
    spCC = arg3->x - arg4->x;
    spC8 = arg3->y - arg4->y;
    spC4 = arg3->z - arg4->z;
    if (((func_80038600(arg3, "../z_bgcheck.c", 0x12DF) == 1) ||
         (func_80038600(arg4, "../z_bgcheck.c", 0x12E0) == 1)) &&
        (arg8 != NULL)) {
        osSyncPrintf("こいつ,pself_actor->name %d\n", arg8->id);
    }
    if (((spCC != 0.0f) || (spC4 != 0.0f)) && !((u8)arg10 & 1)) {
        if ((arg9 + spC8) < 5.0f) {
            spD4 = func_8003D7F0(arg0, (u16)arg1, NULL, arg4, arg3, &spA8, &spD0, &spA4, arg8, 1.0f, 0x1B);
            if (spD4 != 0) {
                f32 temp_fa0_ny = (f32)spD0->norm.y * 0.00003051851f;

                if (temp_fa0_ny > 0.5f) {
                    arg2->x = spA8.x;
                    if (arg9 > 1.0f) {
                        arg2->y = spA8.y - 1.0f;
                    } else {
                        arg2->y = spA8.y - arg9;
                    }
                    arg2->z = spA8.z;
                } else {
                    f32 nx;
                    f32 nz;

                    nx = ((f32)spD0->norm.x * 0.00003051851f);
                    nz = ((f32)spD0->norm.z * 0.00003051851f);
                    arg2->x = (arg5 * nx) + spA8.x;
                    arg2->y = (arg5 * temp_fa0_ny) + spA8.y;
                    arg2->z = (arg5 * nz) + spA8.z;
                }
                *arg6 = spD0;
                *arg7 = spA4;
            }
        } else {
            Vec3f sp88;
            Vec3f sp7C;
            s32 var_v0;
            s32 pad;

            if ((arg5 * arg5) < ((spCC * spCC) + (spC4 * spC4))) {
                var_v0 = 0x1B;
            } else {
                var_v0 = 0x19;
            }
            sp88 = *arg3;
            sp88.y += arg9;
            sp7C = *arg4;
            sp7C.y = sp88.y;
            spD4 = func_8003D7F0(arg0, (u16)arg1, NULL, &sp7C, &sp88, &spA8, &spD0, &spA4, arg8, 1.0f, var_v0);
            if (spD4 != 0) {
                f32 nx = (f32)spD0->norm.x * 0.00003051851f;
                f32 nz = (f32)spD0->norm.z * 0.00003051851f;
                f32 nxz = sqrtf((nx * nx) + (nz * nz));

                if (!(fabsf(nxz) < 0.008f)) {
                    //! FAKE
                    temp_fv0 = (0, arg5) * (1.0f / nxz);
                    arg2->x = (temp_fv0 * nx) + spA8.x;
                    arg2->z = (temp_fv0 * nz) + spA8.z;
                    *arg6 = spD0;
                    *arg7 = spA4;
                    spD4 = 1;
                }
            }
        }
    }
    spB8 = *arg2;
    spB8.y += arg9;
    spB4 = 0;
    if (func_800409A8(arg0, (u16)arg1, arg2, &arg2->z, &spB8, arg5, arg6, arg7, arg8) != 0) {
        spD4 = 1;
        spB4 = 1;
        spB8 = *arg2;
        spB8.y += arg9;
    }
    if ((func_8003C55C(arg0, arg3) == 1) && (func_80039AEC(func_8003AC54(arg0, spDC, (PosRot*)arg2), arg0, (u16)arg1,
                                                           arg2, &arg2->z, &spB8, arg5, arg6) != 0)) {
        *arg7 = 0x32;
        spD4 = 1;
    }
    if (((spB4 == 1) || (*arg7 != 0x32))) {
        Vec3f sp5C;
        s32 sp58;

        if ((func_8003D7F0(arg0, (u16)arg1, NULL, arg4, arg2, &sp5C, &spD0, &sp58, arg8, 1.0f, 9) != 0)) {
            f32 nx = (f32)spD0->norm.x * 0.00003051851f;
            f32 nz = (f32)spD0->norm.z * 0.00003051851f;
            f32 nxz;

            nxz = sqrtf((nx * nx) + (nz * nz));
            if (!(fabsf(nxz) < 0.008f)) {
                //! FAKE
                temp_fv0 = (0, arg5) * (1.0f / nxz);
                arg2->x = (temp_fv0 * nx) + sp5C.x;
                arg2->z = (temp_fv0 * nz) + sp5C.z;
                *arg6 = spD0;
                *arg7 = sp58;
                spD4 = 1;
            }
        }
    }
    return spD4;
}

s32 func_8003D464(CollisionContext* colCtx, Vec3f* posResult, Vec3f* posNext, Vec3f* posPrev, f32 arg4,
                  CollisionPoly** outPoly, f32 checkHeight) {
    UNK_TYPE sp3C;

    return func_8003CDD4(colCtx, 2, posResult, posNext, posPrev, arg4, outPoly, &sp3C, 0, checkHeight, 0);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003D4C8.s")

s32 func_8003D52C(CollisionContext* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32 arg4, CollisionPoly** arg5,
                  u32* arg6, Actor* arg7, f32 arg8) {
    return func_8003CDD4(arg0, 2U, arg1, arg2, arg3, arg4, arg5, (s32*)arg6, arg7, arg8, 0);
}

s32 func_8003D594(CollisionContext* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32 arg4, CollisionPoly** arg5,
                  u32* arg6, Actor* arg7, f32 arg8) {
    return func_8003CDD4(arg0, 2U, arg1, arg2, arg3, arg4, arg5, (s32*)arg6, arg7, arg8, 1);
}

s32 func_80040E40(CollisionContext*, u16, f32*, Vec3f*, f32, void*, u32*, Actor*);
s32 func_8003D600(CollisionContext* arg0, u16 arg1, f32* arg2, Vec3f* arg3, f32 arg4, void* arg5, u32* arg6,
                  Actor* arg7) {
    void* sp54;
    s32 pad;
    s32 var_v1;
    Vec3f sp40;
    f32 sp3C;

    *arg6 = 0x32;
    *arg2 = arg3->y;
    if ((func_80038600(arg3, "../z_bgcheck.c", 0x1456) == 1) && (arg7 != NULL)) {
        osSyncPrintf("こいつ,pself_actor->name %d\n", arg7->id);
    }
    sp54 = arg0->stat.unk40;
    if (func_8003C55C(arg0, arg3) == 0) {
        return 0;
    }
    var_v1 = func_8003A3E0(func_8003AC54(arg0, sp54, (PosRot*)arg3), (u16)arg1, arg0, arg2, arg3, arg4, arg5);
    sp40 = *arg3;
    sp40.y = *arg2;
    sp3C = *arg2;
    if (func_80040E40(arg0, (u16)arg1, &sp3C, &sp40, arg4, arg5, arg6, arg7) != 0) {
        var_v1 = 1;
        *arg2 = sp3C;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003D754.s")

s32 func_8003D7A0(CollisionContext* arg0, f32* arg1, Vec3f* arg2, f32 arg3, void* arg4, u32* arg5, Actor* arg6) {
    return func_8003D600(arg0, 2, arg1, arg2, arg3, arg4, arg5, arg6);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003D7F0.s")

s32 func_8003DD28(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0 != 0) {
        var_v1 = 1;
    }
    if (arg1 != 0) {
        var_v1 |= 2;
    }
    if (arg2 != 0) {
        var_v1 |= 4;
    }
    if (arg3 != 0) {
        var_v1 |= 8;
    }
    if (arg4 != 0) {
        var_v1 |= 0x10;
    }
    return var_v1;
}

s32 func_8003DD6C(CollisionContext* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, CollisionPoly** arg4, s32 arg5,
                  s32 arg6, s32 arg7, s32 arg8, void* arg9) {
    return func_8003D7F0(arg0, 1U, NULL, arg1, arg2, arg3, arg4, (s32*)arg9, NULL, 1.0f,
                         func_8003DD28(arg5, arg6, arg7, arg8, 1));
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003DDF8.s")

s32 func_8003DE84(CollisionContext* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, CollisionPoly** arg4, u32 arg5,
                  u32 arg6, u32 arg7, u32 arg8, u32* arg9) {
    return func_8003D7F0(arg0, 2U, NULL, arg1, arg2, arg3, arg4, (s32*)arg9, NULL, 1.0f,
                         func_8003DD28((s32)arg5, (s32)arg6, (s32)arg7, (s32)arg8, 1));
}

s32 func_8003DF10(CollisionContext* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, CollisionPoly** arg4, u32 arg5,
                  u32 arg6, u32 arg7, u32 arg8, u32* arg9, Actor* arg10) {
    return func_8003D7F0(arg0, 2U, NULL, arg1, arg2, arg3, arg4, (s32*)arg9, arg10, 1.0f,
                         func_8003DD28((s32)arg5, (s32)arg6, (s32)arg7, (s32)arg8, 1));
}

s32 func_8003DFA0(CollisionContext* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, CollisionPoly** arg4, u32 arg5,
                  u32 arg6, u32 arg7, u32 arg8, u32* arg9, Actor* arg10, f32 arg11) {
    return func_8003D7F0(arg0, 2U, NULL, arg1, arg2, arg3, arg4, (s32*)arg9, arg10, arg11,
                         func_8003DD28((s32)arg5, (s32)arg6, (s32)arg7, (s32)arg8, 1));
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003E02C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003E0B8.s")

s32 func_8003E0FC(CollisionContext* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, CollisionPoly** arg4, u32 arg5,
                  u32 arg6, u32 arg7, u32 arg8) {
    s32 sp3C;

    return func_8003D7F0(arg0, 0U, NULL, arg1, arg2, arg3, arg4, &sp3C, NULL, 1.0f,
                         func_8003DD28((s32)arg5, (s32)arg6, (s32)arg7, (s32)arg8, 1));
}

s32 func_8003E188(CollisionContext* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, CollisionPoly** arg4, u32 arg5,
                  u32 arg6, u32 arg7, u32 arg8, f32* arg9) {
    return func_8003D7F0(arg0, 0U, NULL, arg1, arg2, arg3, arg4, (s32*)arg9, NULL, 1.0f,
                         func_8003DD28((s32)arg5, (s32)arg6, (s32)arg7, (s32)arg8, 1));
}

s32 func_8003AB28(void*, u16, CollisionContext*, Vec3f*, f32, s32*, u16);
s32 func_80041648(CollisionContext*, u16, s32*, s32*, Vec3f*, f32, Actor*, u16);
s32 func_8003E214(CollisionContext* arg0, u16 arg1, s32* arg2, s32* arg3, Vec3f* arg4, f32 arg5, Actor* arg6,
                  u16 arg7) {
    void* temp_v0;

    *arg3 = 0x32;
    if ((func_80038600(arg4, "../z_bgcheck.c", 0x16DC) == 1) && (arg6 != 0)) {
        osSyncPrintf("こいつ,pself_actor->name %d\n", arg6->id);
    }
    temp_v0 = func_8003AD00(arg0, arg0->stat.unk40, arg4);
    if (temp_v0 == NULL) {
        return 0;
    }
    if ((func_8003AB28(temp_v0, arg1, arg0, arg4, arg5, arg2, arg7) != 0) ||
        (func_80041648(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) != 0)) {
        return 1;
    }
    return 0;
}

s32 func_8003E30C(CollisionContext* colCtx, Vec3f* center, f32 radius) {
    UNK_TYPE sp2C;
    UNK_TYPE sp28;

    return func_8003E214(colCtx, 0, &sp2C, &sp28, center, radius, 0, 0);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003E350.s")

void func_8003E398(struct_8003E398* arg0) {
    arg0->unk0 = 0;
    arg0->unk2 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
}

void func_8003E3AC(GlobalContext* arg0, struct_8003E398* arg1, u32 arg2, s32 arg3) {
    UNK_PTR temp_v0;
    UNK_PTR temp_v0_2;

    arg1->unk0 = (s16)arg2;
    arg1->unk2 = 0;
    temp_v0 = THA_AllocEndAlign(&arg0->state.tha, arg2 * 4, -2U);
    arg1->unk4 = temp_v0;
    if (temp_v0 == 0) {
        __assert("this->short_slist_node_tbl != NULL", "../z_bgcheck.c", 0x1757);
    }
    temp_v0_2 = GameState_Alloc(&arg0->state, (u32)arg3, "../z_bgcheck.c", 0x175B);
    arg1->unk8 = temp_v0_2;
    if (temp_v0_2 == 0) {
        __assert("this->polygon_check != NULL", "../z_bgcheck.c", 0x175D);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003E458.s")

u16 func_8003E4DC(struct_8003E398* arg0) {
    u16 temp_v1;

    temp_v1 = (u16)arg0->unk2;
    arg0->unk2 = temp_v1 + 1;
    if ((s32)temp_v1 >= (s32)(u16)arg0->unk0) {
        __assert("new_index < this->short_slist_node_size", "../z_bgcheck.c", 0x1785);
    }
    return temp_v1;
}

void func_8003E530(ActorMeshTransform* arg0) {
    s16 temp_v0;

    arg0->rot.z = 0;
    temp_v0 = arg0->rot.z;
    arg0->scale.z = 1.0f;
    arg0->scale.y = 1.0f;
    arg0->scale.x = 1.0f;
    arg0->pos.z = 0.0f;
    arg0->pos.y = 0.0f;
    arg0->pos.x = 0.0f;
    arg0->rot.y = temp_v0;
    arg0->rot.x = temp_v0;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003E568.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003E5B4.s")

void func_8003E688(ActorMesh_sub8* arg0) {
    func_8003871C(&arg0->unk2);
    func_8003871C(&arg0->unk4);
    func_8003871C(&arg0->unk6);
}

void func_8003E6C4(ActorMesh_sub8* arg0) {
    arg0->unk0 = 0;
    func_8003E688(arg0);
}

void func_8003E6E4(UNK_TYPE2* arg0) {
    *arg0 = 0;
}

void func_8003E530(ActorMeshTransform*);
void func_8003E6EC(GlobalContext* arg0, ActorMesh* arg1) {
    s16 temp_v0;

    arg1->actor = NULL;
    arg1->unk_04 = NULL;
    func_8003E530(&arg1->transform1);
    func_8003E530(&arg1->transform2);
    func_8003E6C4(&arg1->unk8);
    func_8003E6E4(&arg1->unk10);
    arg1->unk58 = 0;
    temp_v0 = arg1->unk58;
    arg1->unk5A = 0;
    arg1->unk56 = temp_v0;
    arg1->unk54 = temp_v0;
}

void func_8003E750(ActorMesh* arg0, Actor* arg1, CollisionHeader* arg2) {
    arg0->actor = arg1;
    arg0->unk_04 = arg2;
    arg0->transform1.scale = arg1->scale;
    arg0->transform1.rot = arg1->shape.rot;
    arg0->transform1.rot.x -= 1;
    arg0->transform1.pos = arg1->posRot.pos;
    arg0->transform2.scale = arg1->scale;
    arg0->transform2.rot = arg1->shape.rot;
    arg0->transform2.pos = arg1->posRot.pos;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003E804.s")

void func_8003E82C(void* arg0) {
    *(s32*)arg0 = 0;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003E834.s")

void func_8003E888(void* arg0) {
    *(s32*)arg0 = 0;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003E890.s")

void func_8003E8EC(GlobalContext* arg0, ActorMesh* arg1) {
    arg1->transform1 = arg1->transform2;
}

s32 func_8003E934(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= 0x32)) {
        return 0;
    }
    return 1;
}

void func_8003E82C(UNK_PTR);
void func_8003E888(UNK_PTR);
void func_8003E954(GlobalContext* arg0, DynaCollisionContext* arg1) {
    arg1->unk0 = 1;
    func_8003E82C(&arg1->unk13F0);
    func_8003E888(&arg1->unk13F4);
    func_800387FC(arg0, &arg1->unk13F8);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003E9A0.s")

u32 DynaPolyInfo_RegisterActor(GlobalContext* globalCtx, DynaCollisionContext* dynaColCtx, Actor* actor,
                               CollisionHeader* arg3) {
    s32 var_t0;
    u32 var_s0;

    var_t0 = 0;
    for (var_s0 = 0; var_s0 < 50; var_s0++) {
        if (!(dynaColCtx->flags[var_s0] & 1)) {
            dynaColCtx->flags[var_s0] |= 1;
            var_t0 = 1;
            break;
        }
    }
    if (var_t0 == 0) {
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("DynaPolyInfo_setActor():ダイナミックポリゴン 空きインデックスはありません\n");
        osSyncPrintf("\x1b[m");
        return 0x32U;
    }
    func_8003E750(&dynaColCtx->actorMeshArr[var_s0], actor, arg3);
    dynaColCtx->unk0 |= 1;
    dynaColCtx->flags[var_s0] &= 0xFFFD;
    osSyncPrintf("\x1b[32m");
    osSyncPrintf("DynaPolyInfo_setActor():index %d\n", var_s0);
    osSyncPrintf("\x1b[m");
    return var_s0;
}

DynaPolyActor* DynaPolyInfo_GetActor(CollisionContext* colCtx, s32 dynaPolyId) {
    if ((func_8003E934(dynaPolyId) == 0) || (((colCtx->dyna.flags[dynaPolyId] & 1) == 0)) ||
        (colCtx->dyna.flags[dynaPolyId] & 2)) {
        return NULL;
    }
    return (DynaPolyActor*)colCtx->dyna.actorMeshArr[dynaPolyId].actor;
}

void func_8003EBF8(GlobalContext* globalCtx, DynaCollisionContext* dynaColCtx, s32 dynaPolyId) {
    if (func_8003E934(dynaPolyId) != 0) {
        dynaColCtx->flags[dynaPolyId] |= 4;
        dynaColCtx->unk0 |= 1;
    }
}

void func_8003EC50(GlobalContext* globalCtx, DynaCollisionContext* dynaColCtx, s32 dynaPolyId) {
    if (func_8003E934(dynaPolyId) != 0) {
        dynaColCtx->flags[dynaPolyId] &= 0xFFFB;
        dynaColCtx->unk0 |= 1;
    }
}

void func_8003ECA8(GlobalContext* globalCtx, DynaCollisionContext* dynaColCtx, s32 dynaPolyId) {
    if (func_8003E934(dynaPolyId) != 0) {
        dynaColCtx->flags[dynaPolyId] |= 8;
        dynaColCtx->unk0 |= 1;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003ED00.s")

s32 func_8003E934(s32 arg0);
void DynaPolyInfo_Free(GlobalContext* globalCtx, DynaCollisionContext* dynaColCtx, s32 dynaPolyId) {
    DynaPolyActor* temp_v0;

    osSyncPrintf("\x1b[32m");
    osSyncPrintf("DynaPolyInfo_delReserve():index %d\n", dynaPolyId);
    osSyncPrintf("\x1b[m");
    if (func_8003E934(dynaPolyId) == 0) {
        if (dynaPolyId == -1) {
            osSyncPrintf("\x1b[32m");
            osSyncPrintf(
                "DynaPolyInfo_delReserve():削除されているはずの(?)\nインデックス(== -1)のため,処理を中止します。\n");
            osSyncPrintf("\x1b[m");
            return;
        }
        osSyncPrintf("\x1b[31m");
        osSyncPrintf("DynaPolyInfo_delReserve():"
                     "確保していない／出来なかったインデックスの解放のため、処理を中止します。index == %d\n",
                     dynaPolyId);
        osSyncPrintf("\x1b[m");
        return;
    }
    temp_v0 = DynaPolyInfo_GetActor(&globalCtx->colCtx, dynaPolyId);
    if (temp_v0 != NULL) {
        temp_v0->dynaPolyId = -1U;
        dynaColCtx->actorMeshArr[dynaPolyId].actor = NULL;
        dynaColCtx->flags[dynaPolyId] |= 2;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003EE6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003EE80.s")

void func_8003F8EC(GlobalContext* globalCtx, DynaCollisionContext* dynaColCtx, Actor* actor) {
    DynaPolyActor* temp_v0;
    s32 var_s0;

    for (var_s0 = 0; var_s0 < 50; var_s0++) {
        if (dynaColCtx->flags[var_s0] & 1) {
            temp_v0 = DynaPolyInfo_GetActor(&globalCtx->colCtx, var_s0);
            if ((temp_v0 != NULL) && (&temp_v0->actor == actor)) {
                func_800434A0((DynaPolyActor*)actor);
                return;
            }
        }
    }
}

void func_80038870(struct_800387FC*);
void func_8003E688(ActorMesh_sub8*);
void func_8003E6EC(GlobalContext*, ActorMesh*);
void func_8003EE80(GlobalContext*, DynaCollisionContext*, s32, UNK_PTR, UNK_PTR);
void func_8003F984(GlobalContext* globalCtx, DynaCollisionContext* dynaColCtx) {
    DynaPolyActor* temp_v0_2;
    s32 sp60;
    s32 sp5C;
    s32 i;

    func_80038870(&dynaColCtx->unk13F8);
    i = 0;
    do {
        func_8003E688(&dynaColCtx->actorMeshArr[i].unk8);
        i++;
    } while (i < 50);
    for (i = 0; i < 50; i++) {
        if (dynaColCtx->flags[i] & 2) {
            osSyncPrintf("\x1b[32m");
            osSyncPrintf("DynaPolyInfo_setup():削除 index=%d\n", i);
            osSyncPrintf("\x1b[m");
            dynaColCtx->flags[i] = 0;
            func_8003E6EC(globalCtx, &dynaColCtx->actorMeshArr[i]);
            dynaColCtx->unk0 |= 1;
        }
        if ((dynaColCtx->actorMeshArr[i].actor != NULL) && (dynaColCtx->actorMeshArr[i].actor->update == NULL)) {
            osSyncPrintf("\x1b[32m");
            osSyncPrintf("DynaPolyInfo_setup():削除 index=%d\n", i);
            osSyncPrintf("\x1b[m");
            temp_v0_2 = DynaPolyInfo_GetActor(&globalCtx->colCtx, i);
            if (temp_v0_2 != NULL) {
                temp_v0_2->dynaPolyId = -1U;
                dynaColCtx->flags[i] = 0;
                func_8003E6EC(globalCtx, &dynaColCtx->actorMeshArr[i]);
                dynaColCtx->unk0 |= 1;
            } else {
                return;
            }
        }
    }

    sp60 = 0;
    sp5C = 0;
    i = 0;
    do {
        if (dynaColCtx->flags[i] & 1) {
            func_8003EE80(globalCtx, dynaColCtx, i, &sp60, &sp5C);
        }
        i += 1;
    } while (i != 0x32);
    dynaColCtx->unk0 &= 0xFFFE;
}

void func_8003FB64(GlobalContext* globalCtx, DynaCollisionContext* dynaColCtx) {
    s32 var_s0;

    var_s0 = 0;
    do {
        if (dynaColCtx->flags[var_s0] & 1) {
            func_8003E8EC(globalCtx, &dynaColCtx->actorMeshArr[var_s0]);
        }
        var_s0 += 1;
    } while (var_s0 != 0x32);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003FBF4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8003FDDC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80040284.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_800409A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80040BE4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80040E40.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80040FA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041128.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041240.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_800413F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041510.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041648.s")

void func_800417A0(CollisionHeader* arg0) {
    arg0->vertexArray = SEGMENTED_TO_VIRTUAL(arg0->vertexArray);
    arg0->polygonArray = SEGMENTED_TO_VIRTUAL(arg0->polygonArray);
    arg0->polygonTypes = SEGMENTED_TO_VIRTUAL(arg0->polygonTypes);
    arg0->cameraData = SEGMENTED_TO_VIRTUAL(arg0->cameraData);
    arg0->waterBoxes = SEGMENTED_TO_VIRTUAL(arg0->waterBoxes);
}

void DynaPolyInfo_Alloc(CollisionHeader* arg0, CollisionHeader** arg1) {
    *arg1 = SEGMENTED_TO_VIRTUAL(arg0);
    func_800417A0(*arg1);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_800418D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041978.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_800419B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041A28.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041A4C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041A94.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041B24.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041B80.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041C10.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041C98.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041D28.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041D4C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041D70.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041D94.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041DB8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041DE4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041E18.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041E4C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041E80.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041EA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041EC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041EEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041F10.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041F34.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041F7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041FA0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041FC4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80041FE8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8004200C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80042048.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80042084.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_800420C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_800420E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80042108.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8004213C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80042244.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_8004239C.s")

u32 func_80042538(CollisionContext* colCtx, WaterBox* waterBox) {
    u32 v = waterBox->properties & 0xFF;

    return v;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80042548.s")

u32 func_8004259C(CollisionContext* colCtx, WaterBox* waterBox) {
    u32 v = (waterBox->properties >> 8) & 0x1F;

    return v;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_800425B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80042708.s")

s32 func_800427B4(CollisionPoly* arg0, CollisionPoly* arg1, Vec3f* arg2, Vec3f* arg3, Vec3f* arg4) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    s32 pad;

    func_800389D4(arg0, &sp54, &sp50, &sp4C);
    func_800389D4(arg1, &sp48, &sp44, &sp40);
    return Math3D_PlaneVsLineSegClosestPoint(sp54, sp50, sp4C, (f32)arg0->dist, sp48, sp44, sp40, (f32)arg1->dist, arg2,
                                             arg3, arg4);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80042868.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80042B2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80042C3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_bgcheck/func_80042CB8.s")

void func_80042CB8(GlobalContext*, CollisionContext*, void*, u8, u8, u8);
void func_80042EF8(GlobalContext* arg0, CollisionContext* arg1, u16* arg2, u8 arg3, u8 arg4, u8 arg5) {
    u16 temp_v0;
    s16 new_var;
    CollisionPoly* temp_s2;
    struct_80039448* var_s0;

    temp_v0 = *arg2;
    temp_s2 = arg1->stat.colHeader->polygonArray;
    if (temp_v0 != 0xFFFF) {
        var_s0 = &((struct_80039448*)arg1->stat.unk44.unk4)[(temp_v0)];
        while (true) {
            new_var = var_s0->unk0;
            func_80042CB8(arg0, arg1, &temp_s2[(new_var)], arg3, arg4, arg5);
            if (var_s0->unk2 != 0xFFFF) {
                var_s0 = &((struct_80039448*)arg1->stat.unk44.unk4)[(var_s0->unk2)];
                continue;
            }
            break;
        }
    }
}

void func_80042FC4(GlobalContext* globalCtx, CollisionContext* colCtx) {
    Player* player = PLAYER;
    UNK_PTR sp28;

    sp28 = func_8003AC54(colCtx, colCtx->stat.unk40, &player->actor.posRot);
    if (gGameInfo->data[0x737] != 0) {
        func_80042EF8(globalCtx, colCtx, sp28, 0, 0, 0xFF);
    }
    if (gGameInfo->data[0x736] != 0) {
        func_80042EF8(globalCtx, colCtx, (u16*)((char*)sp28 + 2), 0, 0xFF, 0);
    }
    if (gGameInfo->data[0x735] != 0) {
        func_80042EF8(globalCtx, colCtx, (u16*)((char*)sp28 + 4), 0xFF, 0, 0);
    }
}
