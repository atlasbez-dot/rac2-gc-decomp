/* Nonmatching: 264 bytes versus 268; USA 0/27 placements.
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses -frac2-qcopy -frac2-qcopy-barrier.
 * +0x20: GP float access, division latency, loop base construction and zero-store scheduling differ. The G8 profile gave 248 bytes; G0/no-split is retained. Reopen with measured GP symbol declarations. */
typedef int Quad __attribute__((mode(TI)));

extern int D_L00_001B2C70 __attribute__((sda)), D_L00_001B2C84, D_L00_001B2D3C;
extern int D_L00_001B0E74 __attribute__((sda)), D_L00_001B0E7C __attribute__((sda)), D_L00_001B0E80 __attribute__((sda));
extern int D_L00_001B2D30[];
extern Quad D_L00_00254A50[], D_L00_001B2CC0[];
extern float D_L00_001B0E38 __attribute__((sda)), D_L00_001B2C80 __attribute__((sda));
extern float func_00283CE0(int);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
void func_L00_00406040(char *object)
{
    Quad step;
    char *state = *(char **)(object + 0x68);
    int i;
    Quad *src, *dst;
    int *count;
    if (D_L00_001B2C70) {
        D_L00_001B2C70 = 0;
        D_L00_001B2C80 = D_L00_001B0E38 / func_00283CE0(12);
        func_00282D30(&step, object + 0xC0, -D_L00_001B2C80);
        D_L00_00254A50[1] = *(Quad *)state;
        src = D_L00_00254A50 + 1;
        dst = src + 1;
        for (i=10; i>=0; i--) {
            func_00282CC0(dst, src, &step);
            src++; dst++;
        }
        D_L00_001B0E74 = 0; D_L00_001B0E7C = 0; D_L00_001B0E80 = 0;
        D_L00_001B2C84 = 0; D_L00_001B2D3C = 0;
        dst = D_L00_001B2CC0; count = D_L00_001B2D30;
        for (i=2; i>=0; i--) { *count = 0; *dst = step; dst++; count++; }
    }
}
