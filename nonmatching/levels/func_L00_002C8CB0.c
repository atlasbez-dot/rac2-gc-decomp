/* Retained plain-C attempt: 332/348 bytes; first difference +0x1c.
 * us: 0/22, pal: 0/22, us2: 0/22.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * The compiler merges the early transition call into the final call, shortening control flow. The vector copies are compiler-reachable. -fno-crossjumping is unavailable in this compiler. Next: a natural transition/control-flow arrangement.
 */
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float v[4]; } Vector;
extern char D_00189E20[];
extern int D_00138320;
extern int D_L00_001B9080;
extern void func_L00_002C42E0(int mode, int flag);
extern int func_002761F8(void *start, void *end, int flags, void *object, int mode);
int func_L00_002C8CB0(void)
{
    char *pre = D_00189E20;
    char *base;
    Vector start, end;
    int mode;
    if (*(int *)(pre + 0x229c) == 0x11) {
        if (*(float *)(pre + 0x330) + 0.4f < *(float *)(pre + 0x88)) {
            D_L00_001B9080 = 0;
            mode = 6;
early_change:
            func_L00_002C42E0(mode, 1);
            return 1;
        }
    } else if (*(int *)(pre + 0x2294) != 0x67 && *(int *)(pre + 0x2294) != 0x73) {
        *(int *)(pre + 0x24c0) = 10000;
    }
    base = D_00189E20;
    if (*(short *)(base + 0x1fe) != 0)
        return 0;
    if (*(int *)(*(char **)(*(char **)(base + 0x2290) + 0x24) + 0x134) == 0)
        return 0;
    if (*(int *)(base + 0x229c) != 0x12)
        return 0;
    start.q = *(Quad *)(base + 0x80);
    start.v[2] = *(float *)(base + 0x330) + 0.01f;
    end.q = start.q;
    end.v[2] += 0.3f;
    if (func_002761F8(&start, &end, 2, *(char **)(base + 0x2290), 0) == 0)
        return 0;
    mode = 0x32;
    if (*(short *)(base + 0x24fc) == 0 && (D_00138320 & 10) != 0) {
        mode = 0x34;
        goto early_change;
    }
    func_L00_002C42E0(mode, 1);
    return 1;
}
