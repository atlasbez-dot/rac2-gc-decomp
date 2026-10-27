/* Near miss: option row input handler (two rotations, then a four-way switch).
 *
 * wslcmp (boot): 0 of 28 places; 424 bytes against 420, one instruction long.
 * Everything matches except one redundant `addiu $v0,$zero,3` at the start of
 * the mode==2 case. Retail reuses the 3 that the mode==2 comparison's delay slot
 * already put in $v0 (it is the next case's comparison value) as the divisor of
 * `(mode + 1) % 3`; this cc1 materialises that 3 a second time. Measured:
 * `% 3` and a named `int n = 3` both give the extra addiu; unsigned mode gives
 * `divu` where retail has `div`, so mode must stay signed. The toggles are
 * `volatile unsigned int *` at 0x1A7BA4/0x1A7BA8 (`sltiu`) and
 * `volatile unsigned char *` at 0x1A7BB1; the sibling func_0033CB18 shows the
 * same rotation spelling. Reopen with a source form whose constant 3 is shared
 * between the case-3 comparison and the modulo divisor.
 */
typedef unsigned char u8;
typedef int s32;

extern void func_0033AE28(char *);
extern void func_0033B018(char *, float, float);
extern void func_002E5E58(int, int, int);
extern void func_0027AB40(void);

int func_0033C590(u8 *a0, s32 a1)
{
    u8 *p = a0 + 8;
    volatile unsigned int *sfx = (volatile unsigned int *)0x1A7BA4;
    volatile unsigned int *music = (volatile unsigned int *)0x1A7BA8;
    volatile int *mode = (volatile int *)0x1A7BAC;
    volatile unsigned char *paused = (volatile unsigned char *)0x1A7BB1;
    float *q;
    int v;

    func_0033AE28(p);
    q = *(float **)(a0 + 0x2AC);
    func_0033B018(p, q[0], q[1]);
    if (a1 & 0x1000) {
        func_002E5E58(3, 0, 0);
        v = *(int *)(a0 + 0x2A8);
        *(int *)(a0 + 0x2A8) = (v + 3) % 4;
    } else if (a1 & 0x4000) {
        func_002E5E58(3, 0, 0);
        v = *(int *)(a0 + 0x2A8);
        *(int *)(a0 + 0x2A8) = (v + 1) % 4;
    } else if (a1 & 0x40) {
        func_002E5E58(4, 0, 0);
        switch (*(int *)(a0 + 0x2A8)) {
        case 0:
            *sfx = *sfx < 1;
            break;
        case 1:
            *music = *music < 1;
            break;
        case 2:
            *mode = (*mode + 1) % 3;
            break;
        case 3:
            *paused = *paused < 1;
            func_0027AB40();
            break;
        }
    }
    return (a1 >> 6) & 1;
}
