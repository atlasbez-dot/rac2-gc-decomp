/* M33 2026-10-26: re-measured 656/656 B, 8 lines, float registers only: in the c1/c3 accel computation retail keeps speed*4 in $f1 (div.s $f13,$f1,$f0), here it is tied to $f13. Tried float return, 4*speed, inline args, split statements, a temp. In the permuter. */
/* Nonmatching: 656/656 bytes.
 * Profile: -O2 -G0 -ffunction-sections.
 * Placement checks: US: 0/1; US2: 0/1; PAL absent from catalogue.
 * 656/656 bytes. Approved copies and an ordinary C switch recover the frame, dispatch and complete integer paths. The first remaining instruction difference is +0xdc in the speed/numerator FP allocation of cases1/3. The five retail table entries were independently read and agree with the five source cases.
 * Reopen with real speed/acceleration lifetimes or floating allocator evidence. Scoped case variables improve the integer allocation; an explicitly shared acceleration path gives648 bytes and is archived privately.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_L00_003294F0(unsigned char *, int);
extern void func_002A7750(unsigned char *, int, int);
extern int func_002B3868(char *);
extern int func_00282948(char *);
extern void func_002AA548(char *, char *, float, float, float, float);
extern int func_002B38B8(char *);
extern void func_L20_00447640(char *);
extern void func_00282CF0(char *, char *, char *);
extern void func_002AD6F0(char *, char *, char *, char *);

void func_L20_004473B0(char *arg0) {
    char *state;
    TI128 a, b, c;
    unsigned char sel;
    int n;

    state = *(char **)(arg0 + 0x68);
    qcopy(&a, arg0 + 0x10);
    qcopy(&b, arg0 + 0xF0);
    sel = *(unsigned char *)(arg0 + 0x20);
    switch (sel) {
    case 0: goto c0;
    case 1: goto c1;
    case 2: goto c2;
    case 3: goto c3;
    case 4: goto c4;
    default: goto end;
    }
c0:
    qcopy(state + 0x60, arg0 + 0x10);
    n = *(int *)(state + 0x5C) | 1;
    *(int *)(state + 0x5C) = n;
    func_L00_003294F0((unsigned char *)arg0, 1);
    func_002A7750((unsigned char *)arg0, 4, -1);
    goto end;
c1:
    if (func_002B3868(arg0) != 0) {
        *(int *)(state + 0x88) = 0;
        *(int *)(state + 0x84) = *(int *)(state + 0x74);
    }
    if (func_00282948(state + 0x84) != 0) {
        func_002A7750((unsigned char *)arg0, 2, -1);
    }
    {
        int duration = *(int *)(state + 0x74);
        float speed = *(float *)(state + 0x70);
        float start = *(float *)(state + 0x68) + speed;
        float acceleration = (speed * 4.0f) / (float)(duration * duration);
        func_002AA548(arg0 + 0x18, state + 0x88, start, acceleration,
                     acceleration, acceleration * (float)duration);
    }
    goto end;
c2:
    if (func_002B3868(arg0) != 0) {
        *(int *)(state + 0x84) = *(int *)(state + 0x78);
    }
    if (func_00282948(state + 0x84) != 0) {
        func_002A7750((unsigned char *)arg0, 3, -1);
    }
    goto end;
c3:
    if (func_002B3868(arg0) != 0) {
        *(int *)(state + 0x88) = 0;
        *(int *)(state + 0x84) = *(int *)(state + 0x7C);
    }
    if (func_00282948(state + 0x84) != 0) {
        func_002A7750((unsigned char *)arg0, 4, -1);
    }
    {
        int duration = *(int *)(state + 0x74);
        float speed = *(float *)(state + 0x70);
        float start = *(float *)(state + 0x68);
        float acceleration = (speed * 4.0f) / (float)(duration * duration);
        func_002AA548(arg0 + 0x18, state + 0x88, start, acceleration,
                     acceleration, acceleration * (float)duration);
    }
    goto end;
c4:
    if (func_002B3868(arg0) != 0) {
        *(int *)(state + 0x84) = *(int *)(state + 0x80);
    }
    if (func_00282948(state + 0x84) != 0) {
        func_002A7750((unsigned char *)arg0, 1, -1);
    }
    goto end;
end:
    if (func_002B38B8(arg0) == 0) {
        if (0.0f < *(float *)(state + 0x8C)) {
            func_L20_00447640(arg0);
            *(float *)(state + 0x8C) = -1000.0f;
        }
    }
    func_00282CF0((char *)&c, arg0 + 0x10, (char *)&a);
    func_002AD6F0(state + 0x20, (char *)&c, (char *)&b, arg0 + 0xF0);
}
