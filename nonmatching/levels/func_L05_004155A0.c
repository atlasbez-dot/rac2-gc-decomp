/* 0 of 1 places match - last line: 05_feltzin_system: instruction at +0xe4 differs
   Same size (524 bytes) and the same structure; the whole main body differs only in the
   block that builds the entry pointer at +0x120: retail loads the absolute table pointer
   with its destination as the address temporary (`lui $v0,%hi ; lw $v0,%lo($v0)`, index in
   $v1, `addu $v0,$v0,$v1`), where this cc1 gives the address its own register
   (`lui $a0,%hi ; lw $v1,%lo($a0)`, index in $v0, result in $a2). Everything downstream of
   that block then follows the different registers.
   Tried: `extern char *D` and `extern char D[]` with a cast, the load assigned to a local
   first, the addition operands commuted, *256 vs <<8, an int-typed pointer.
   Not tried here: -mno-split-addresses in a dedicated unit (it costs one instruction on the
   D_00188660 base of this same function: retail keeps `lui $s4,%hi` live and adds the low
   half at each site), and the sibling `-g8.c` with a nosda declaration.
   Notes: `int one = 1;` used for both the func_37B948 argument and the `== 1` test is what
   makes cc1 keep 1 in $s0 across the two calls, which is what retail's $s0 is; without it
   the whole save set shifts by one register. func_3067D8 is the two-pointer COP2 helper
   func_00282E48 (its second argument is object + 0x10). */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern char D_00188660[];

extern char D_L05_001B251C[];

extern int func_379860(char *object);
extern char *func_379CA0(char *object);
extern void func_379E60(char *object, int a1, int a2, int a3);
extern void func_37C160(char *object);
extern void func_37B538(char *object, int a1, int a2, int a3);
extern void func_37B948(char *object, int a1, float a2);
extern int func_37B888(char *object);
extern void func_37B6D0(char *object);
extern int func_3719A8(int a0, int a1, char *object, int a3);
extern int func_332AB8(int kind);
extern void func_3065F8(char *block);
extern float func_3067D8(char *a, char *b);
extern void func_3062A0(char *block);
extern void func_L05_004157B0(char *obj);
extern void func_L05_004158B0(char *object);
extern void func_L05_00415958(char *object);

void func_L05_004155A0(char *object)
{
    char *state = *(char **)(object + 0x68);
    char *r;
    char *rec;
    char buf[0x10];
    int st;

    if (*(unsigned char *)(object + 0x20) == 0) {
        *(unsigned char *)(object + 0x30) = 0xFF;
        if (func_379860(object) == 0)
            return;
        func_L05_004157B0(object);
        func_3065F8(buf);
        if (*(int *)(state + 0x264) != 0)
            func_379E60(object, 0, 0, 0);
        return;
    }
    r = func_379CA0(object);
    if (*(int *)(r + 0x110) == 0)
        return;
    {
    int one = 1;
    func_37C160(object);
    func_37B538(object, 0, 0, 0);
    func_37B948(object, one, 32.0f);
    st = *(int *)(r + 0x110);
    if (st == one) {
        if (*(int *)(state + 0x260) != -1) {
            *(int *)(r + 0x11C) = st;
            rec = *(char **)D_L05_001B251C + *(int *)(state + 0x260) * 256;
            *(int *)(r + 0x120) = (int)rec;
            if (func_3067D8(rec + 0x10, object + 0x10) < 10.0f) {
                rec = D_00188660 + *(int *)(state + 0x270) * 0x70;
                if (*(char **)(rec + 0x88) != object ||
                    *(unsigned char *)(rec + 0x74) == 0) {
                    if (func_332AB8(0x190) == 0)
                        *(int *)(state + 0x270) =
                            func_3719A8(0xE, 0, object, 0xFBF);
                }
            }
        }
        if (*(int *)(r + 0x104) != 0)
            func_L05_004158B0(object);
        if (func_37B888(object) != 0)
            func_37B6D0(object);
        func_3062A0(state + 0x268);
        func_L05_00415958(object);
    }
    }
    rec = D_00188660 + *(int *)(state + 0x26C) * 0x70;
    if (*(char **)(rec + 0x88) != object || *(unsigned char *)(rec + 0x74) == 0)
        *(int *)(state + 0x26C) = func_3719A8(0, 6, object, 0xF73);
}
