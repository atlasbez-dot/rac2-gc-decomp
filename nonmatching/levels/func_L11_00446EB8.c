/* func_L11_00446EB8 (348 bytes, to be placed in a -g8.c source unit) -- BEST ATTEMPT
 * check.py: 11_joba: 352 bytes against 348, and the frame and the loop shape differ.
 * Measured with "-O2 -G8 -ffunction-sections": the level's float constants only reach
 * $gp through the small-data attribute in a -G8 unit, so D_L11_001B1940,
 * D_L11_001B1948 and D_L11_001B194C carry __attribute__((sda)) and D_L11_001B1944
 * and D_L11_001B359C carry __attribute__((nosda)) (the retail loads the latter two
 * with lui/lwc1 and lui/lw, not through $gp).
 * What still differs:
 *   - the loop: the retail counts up ("addiu $s2,$s2,1" in the body, "slti $v0,$s2,4"
 *     and "bnel" at the end, and the index recomputed with "sll $v0,$s2,2" every
 *     iteration); this cc1 strength-reduces the counter into a pointer and counts
 *     down ("addiu $s0,$s0,4" / "bgez $s2");
 *   - the address of D_L11_001B359C is CSEd into a callee-saved register ($s3) and
 *     kept across the calls, where the retail re-materialises "lui $a2,0x1B" twice
 *     (the known "this cc1 CSEs symbol addresses into callee-saved registers" wall);
 *   - the comparison is a plain "bc1f" where the retail has the likely "bc1fl";
 *   - the frame is 0x60 bytes instead of 0x50 (the two extra callee-saved registers
 *     of the point above).
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_2FF800(char *a0);
extern void func_3009D8(char *a0, char *a1, char *a2);
extern void func_3004E0(char *a0, char *a1, char *a2);
extern float func_32FBF0(float f12, float f13, float f14);
extern s32 func_301700(float f12);
extern void func_2FF830(char *a0, s32 a1, s32 a2, float f12, float f13, float f14);

extern float D_L11_001B1940 __attribute__((sda));
extern float D_L11_001B1944 __attribute__((nosda));
extern int D_L11_001B1948 __attribute__((sda));
extern float D_L11_001B194C __attribute__((sda));
extern char *D_L11_001B359C __attribute__((nosda));

void func_L11_00446EB8(char *a0)
{
    char *s1;
    TI128 t[2];
    float *p, *q;
    float f1, f12, f13, f14, f20;
    int i, v;

    func_2FF800(a0);
    s1 = *(char **)(a0 + 0x68);
    for (i = 0; i < 4; i++) {
        p = (float *)(s1 + 0xA0 + i * 4);
        q = (float *)(s1 + 0x90 + i * 4);
        t[1] = 0;
        *(float *)((char *)&t[1] + 8) = *p * *q;
        t[0] = t[1];
        func_3009D8((char *)&t[0], (char *)&t[0],
                    D_L11_001B359C + (*(int *)(s1 + 0x1D0) << 8) + 0xC0);
        func_3004E0((char *)&t[0], (char *)&t[0],
                    D_L11_001B359C + (*(int *)(s1 + 0x1D0) << 8) + 0x10);
        f12 = D_L11_001B1940;
        f13 = D_L11_001B1944;
        f14 = *p;
        f20 = func_32FBF0(f12, f13, f14);
        f1 = *p;
        if (f1 < 0.1f) {
            f12 = (float)D_L11_001B1948;
            f12 = f12 * (1.0f - f1);
        } else {
            f12 = (float)D_L11_001B1948;
            f12 = f12 * f1;
            f12 = f12 * 10.0f;
        }
        v = func_301700(f12);
        func_2FF830((char *)&t[0], v, 0, f20, D_L11_001B194C, 0.08f);
    }
}
