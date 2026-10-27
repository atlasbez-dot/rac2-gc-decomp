/* Mid worker 7: partial draft of func_L09_003EA108 (452 B), own unit, flags -O2 -G0 -ffunction-sections -frac2-qcopy
   -frac2-qcopy-barrier. Flow, calls (func_L09_0033E8B0 takes a direction int 1/-1 as fifth argument; func_L00_00341FA8
   takes &int and &float out-params) and constants match. 456 B vs 452: the stack slots come out in another order
   (retail: v0 0, v1 0x10, v2 0x20, v3 0x30, int 0x40, float 0x44; ours puts the out-params first) and an eighth saved
   register keeps the destination pointer. Declaration-order permutations do not move the slots. */
typedef int TI128 __attribute__((mode(TI)));

extern float func_00282E48(TI128 *, TI128 *);
extern void func_L00_00341FA8(int, TI128 *, TI128 *, int *, float *, int, float, float, float);
extern short func_L09_0033E8B0(char *, int, TI128 *, int, int, float);
extern void func_L09_003E9E60(char *, TI128 *, float);
extern int D_L09_001FE6C0[];

void func_L09_003EA108(char *arg0, int arg1)
{
    char *st = *(char **)(arg0 + 0x68);
    TI128 v0;
    TI128 v1;
    TI128 v2;
    TI128 v3;
    int e;
    float f;
    TI128 *pos = (TI128 *)(st + 0x140);
    TI128 *q2 = &v2;
    TI128 *q3 = &v3;

    e = -1;
    f = 0.0f;
    func_L00_00341FA8(D_L09_001FE6C0[arg1], pos, &v0, &e, &f, 0, 100000.0f, 1.0f, 0.0f);
    if (func_00282E48(&v0, (TI128 *)(arg0 + 0x10)) > 2.0f) {
        short a = func_L09_0033E8B0(arg0, arg1, q2, *(short *)(st + 0x118), 1, *(float *)(st + 0x78) * 10.0f);
        short b = func_L09_0033E8B0(arg0, arg1, q3, *(short *)(st + 0x118), -1, *(float *)(st + 0x78) * 10.0f);
        float d;

        func_00282E48(pos, q2);
        func_00282E48(pos, q3);
        d = func_00282E48(&v0, q2);
        if (d < func_00282E48(&v0, q3)) {
            v1 = *q2;
            *(short *)(st + 0x118) = a;
        } else {
            v1 = *q3;
            *(short *)(st + 0x118) = b;
        }
    } else {
        v1 = v0;
    }
    func_L09_003E9E60(arg0, &v1, func_00282E48((TI128 *)(arg0 + 0x10), &v0));
}
