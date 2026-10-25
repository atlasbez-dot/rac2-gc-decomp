/* 0 of 1 places match - last line: 05_feltzin_system: instruction at +0x120 differs
   Same size (524 bytes) and the same structure, including the grouped quadword copy.
   Remaining differences, all in one block: retail materialises the stored constant with
   `lui $a0,0x42` in the delay slot of the `bnel` and stores $a0, and it uses branch-likely
   for the two guards (`bnel $a0,$s0` / `beql $v1,-1`); here they are plain `bne`/`beq`, the
   delay slot holds the absolute table address instead of the constant, and the store gets a
   fresh `lui $v1,0x42`. The same address-temporary difference as func_L05_004155A0: retail
   loads the table pointer as `lui $v1,%hi ; lw $v1,%lo($v1)`.
   Profile: the 16-byte copy reaches `addiu $v1,$s1,0x10 ; lq $v0,0($v1) ; sq $v0,0($sp)` only
   with a dedicated unit built with -frac2-qcopy, and only when the local is a 16-byte-aligned
   TI128 (`TI128 qbuf;`); a `char buf[16]` keeps the displacement form and stays 4 bytes short.
   The constant stored at +0x11C is the literal 0x420000 (no symbol in the level's data).
   Notes: `int one = 1;` gives retail's $s0 (see func_L05_004155A0); the 128-record clear is
   the body of func_L05_00415D70 with its initialisers assigned after the call; the callback
   of the last func_2FF698 is func_L00_003E4948 (0x41D190). */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern char D_L05_002681E0[];
extern char *D_L05_001B251C;

extern int func_379860(char *object);
extern char *func_379CA0(char *object);
extern void func_379E60(char *object, char *a1, int a2, int a3);
extern void func_37C160(char *object);
extern void func_37B538(char *object, int a1, int a2, int a3);
extern void func_37B948(char *object, int a1, float a2);
extern int func_37B888(char *object);
extern void func_37B6D0(char *object);
extern void func_3065F8(char *block);
extern void func_3062A0(char *block);
extern void func_2FF698(void *fn, char *object);
extern void func_332708(char *object, int a1, int a2, int a3);
extern float func_332B50(float a, float b);
extern int func_307840(char *buf, float value);
extern void func_L05_0041CA70(char *obj);
extern void func_L05_0041CB68(char *object);
extern void func_L05_0041CE00(char *object);
extern void func_L00_003E4948(void);

void func_L05_0041C860(char *object)
{
    char *state = *(char **)(object + 0x68);
    char *r;
    TI128 qbuf;
    int st;

    if (*(unsigned char *)(object + 0x20) == 0) {
        *(unsigned char *)(object + 0x30) = 0xFF;
        if (func_379860(object) == 0)
            return;
        func_L05_0041CA70(object);
        func_332708(object, 1, 0, 0);
        func_3065F8((char *)&qbuf);
        *(float *)(object + 0x48) = func_332B50(0.9f, 1.1f);
        if (*(int *)(state + 0x264) != 0) {
            char *base;
            int *p;
            int i;

            func_379E60(object, 0, 0, 0);
            base = D_L05_002681E0;
            p = (int *)(base + 0x27F0);
            i = 0x7F;
            do {
                *p = 0;
                p -= 0x14;
                i--;
            } while (i >= 0);
        }
        return;
    }
    r = func_379CA0(object);
    if (*(int *)(r + 0x110) == 0)
        return;
    {
    int one = 1;
    func_37C160(object);
    func_37B538(object, 0, 0, 0);
    func_37B948(object, one, 64.0f);
    st = *(int *)(r + 0x110);
    if (st == one) {
        if (*(int *)(state + 0x260) != -1) {
            *(int *)(r + 0x11C) = 0x420000;
            *(int *)(r + 0x120) = (int)(D_L05_001B251C + *(int *)(state + 0x260) * 256);
        }
        if (*(int *)(r + 0x108) != 0 && *(int *)(r + 0x104) != 0)
            func_L05_0041CB68(object);
        if (func_37B888(object) != 0)
            func_37B6D0(object);
        func_3062A0(state + 0x268);
        qbuf = *(TI128 *)(object + 0x10);
        *(float *)((char *)&qbuf + 0xC) = *(float *)(object + 0xC) * 0.00097656f;
        if (func_307840((char *)&qbuf, 100.0f) != -1)
            func_L05_0041CE00(object);
    }
    }
    func_2FF698(func_L00_003E4948, object);
}
