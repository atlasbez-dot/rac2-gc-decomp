#include "include_asm.h"

#include "common.h"
typedef unsigned char BatchA_A18_u8;
typedef int BatchA_A18_s32;
extern BatchA_A18_u8 D_0018C0D4;
extern BatchA_A18_s32 ref_L18_002E4090_00(BatchA_A18_s32 a0, BatchA_A18_s32 a1);
extern BatchA_A18_s32 func_002A8AF0(BatchA_A18_s32 a0, BatchA_A18_s32 a1, BatchA_A18_s32 a2);
extern BatchA_A18_s32 D_001FE480[];
extern BatchA_A18_s32 D_001FE480[];
extern BatchA_A18_s32 func_L18_003F8E40(BatchA_A18_u8 *s);
extern BatchA_A18_s32 func_002A77E0(BatchA_A18_s32 a0);
extern BatchA_A18_s32 func_L18_003F75E8(BatchA_A18_s32 a0, BatchA_A18_u8 *a1);
extern void func_00335388(BatchA_A18_u8 *a0, BatchA_A18_s32 a1, BatchA_A18_s32 a2,
                          BatchA_A18_s32 a3);
extern void func_002EC9C8(BatchA_A18_u8 *a0, BatchA_A18_s32 a1);
extern BatchA_A18_s32 func_L09_0033E690(BatchA_A18_u8 *a0, BatchA_A18_s32 a1, float f12);
extern BatchA_A18_s32 func_L09_00329178(BatchA_A18_u8 *a0, BatchA_A18_s32 a1,
                                        BatchA_A18_s32 a2, BatchA_A18_s32 a3);
extern BatchA_A18_s32 func_L09_0033E658(void *a0);

void func_PAL_L18_0042BA90(BatchA_A18_u8 *a0, BatchA_A18_s32 a1, BatchA_A18_s32 a2, float f12) {
    if (a0[0xBC] == 0) {
        if (a0[0x43] != a1) {
            func_00335388(a0, a1, a2, (BatchA_A18_s32)f12);
        }
    } else {
        func_002EC9C8((BatchA_A18_u8 *)a1, a2);
    }
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L18_0042BAE0);
