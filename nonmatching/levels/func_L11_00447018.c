/* func_L11_00447018 (396 bytes, to be placed in a -g8.c source unit) -- FIRST ATTEMPT
 * check.py: 11_joba: 452 bytes against 396, not matched (the loop shape, the
 * branch-likely forms and the frame differ); kept as a starting point, not linked,
 * not counted.
 * Measured with "-O2 -G8 -ffunction-sections": every level constant of this body
 * reaches $gp, so the unit has to be a -G8 one with the small-data attribute
 * (D_L11_001B1950, D_L11_001B1954, D_L11_001B1958, D_L11_001B195C, D_L11_001B1960,
 * D_L11_001B1964, D_L11_001B1968).
 * The body runs the same block once per count and once more after the loop; the
 * retail jumps into the middle of the second block ("bnez $v0" at +0xD0 into
 * +0x114), so the first half of the block is shared with the loop's body and only
 * the second half is common to both.
 * The locals are one object at +0x0 of the frame: an int at +0x8 ("sw $zero,8($sp)")
 * and a quad at +0x10 ("lq"/"sq"), whose third float is the one the block adds to
 * ("lwc1 $f1,0x18($sp)").
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    float head[2];
    int flag;
    TI128 v;
} L11_00447018_Locals;

extern char *func_4417E8(char *a0);
extern void func_332B90(char *a0, float f12);
extern void func_3004A8(char *a0);
extern float func_32CB48(float f12, float f13);
extern s32 func_32CAB0(s32 a0);
extern s32 func_32CAF0(s32 a0, s32 a1);
extern void func_351F78(char *a0, char *a1, char *a2, s32 a3, s32 a4);

extern int D_L11_001B1950 __attribute__((sda));
extern int D_L11_001B1954 __attribute__((sda));
extern int D_L11_001B1958 __attribute__((sda));
extern float D_L11_001B195C __attribute__((sda));
extern float D_L11_001B1960 __attribute__((sda));
extern float D_L11_001B1964 __attribute__((sda));
extern float D_L11_001B1968 __attribute__((sda));
extern char D_L11_001B1990[];

void func_L11_00447018(char *a0, int a1)
{
    L11_00447018_Locals s;
    char *v1;
    int v0, s0, n;

    n = a1;
    if (a1 > 0) {
        do {
            v1 = func_4417E8(a0);
            s.v = *(TI128 *)v1;
            func_332B90((char *)&s.v, 10.0f);
            ((float *)&s.v)[2] += 20.0f;
            func_3004A8((char *)&s);
            func_32CB48(0.2f, 4.0f);
            func_332B90((char *)&s, 20.0f * (1.0f / 60.0f));
            s.flag = 0;
            v0 = func_32CAB0(2);
            s0 = v0;
            v0 = func_32CAF0(D_L11_001B1954, D_L11_001B1958);
            func_351F78((char *)&s.v, (char *)&s, D_L11_001B1990, s0, v0);
            n--;
        } while (n != 0);
    }
    if (func_32CAB0(D_L11_001B1950) == 0) {
        v1 = func_4417E8(a0);
        s.v = *(TI128 *)v1;
        func_332B90((char *)&s.v, 10.0f);
        ((float *)&s.v)[2] += 20.0f;
        func_3004A8((char *)&s);
    }
    func_32CB48(0.2f, 4.0f);
    func_332B90((char *)&s, 20.0f * (1.0f / 60.0f));
    s.flag = 0;
    v0 = func_32CAB0(2);
    s0 = v0;
    v0 = func_32CAF0(D_L11_001B1954, D_L11_001B1958);
    func_351F78((char *)&s.v, (char *)&s, D_L11_001B1990, s0, v0);
}
