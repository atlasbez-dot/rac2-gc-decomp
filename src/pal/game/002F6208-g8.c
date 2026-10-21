#include "include_asm.h"
typedef float f32_F2144bf3d;
typedef int s32_F2144bf3d;
typedef struct {
    char  pad0[0x100];
    f32_F2144bf3d   f100;                  
    f32_F2144bf3d   f104;                  
    f32_F2144bf3d   f108;                  
    f32_F2144bf3d   f10C;                  
    char  pad1[0x1A0 - 0x110];
    s32_F2144bf3d   i1A0;                  
} Resident138180_F2144bf3d;
extern char D_00138180[];
extern s32_F2144bf3d D_0018D198[];
extern s32_F2144bf3d D_L06_001AD3A0 __attribute__((sda));
extern s32_F2144bf3d D_001A7390;
extern s32_F2144bf3d D_001A79F0;
extern s32_F2144bf3d D_L06_001B2348;
extern s32_F2144bf3d D_L06_001A8FC0;
extern s32_F2144bf3d D_L06_001B2900;
extern s32_F2144bf3d D_L06_001AA0F0;

void func_PAL_002F6208(void)
{
    Resident138180_F2144bf3d *p = (Resident138180_F2144bf3d *)D_00138180;

    if (p->i1A0 != 0) goto mismatch;
    if (p->f108 != 0.0f) goto mismatch;
    if (p->f10C != 0.0f) goto mismatch;
    if (p->f100 != 0.0f) goto mismatch;
    if (p->f104 == 0.0f) goto match;
mismatch:
    D_L06_001AD3A0 = 0;
    goto gated;
match:
    D_L06_001AD3A0 = D_L06_001AD3A0 + 1;
gated:
    D_L06_001B2348 = D_L06_001B2348 + 1;
    D_001A7390 = D_001A7390 + 1;

    if (D_L06_001A8FC0 != 0) {
        if (D_L06_001AD3A0 < 750) {
            D_0018D198[D_001A79F0] = D_0018D198[D_001A79F0] + 1;
        }
    }

    if (D_L06_001B2900 != D_001A7390 - 1) {
        D_L06_001AA0F0 = -1;
    }
}
