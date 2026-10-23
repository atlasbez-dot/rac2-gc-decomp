/* Near miss, remeasured 2026-10-23: 300 bytes, 0/27 in US, PAL and US2.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * The first differing instruction is +0x08: the initial pointer load targets s0
 * instead of v0. The outer loop remains rotated, with bgtz instead of retail's
 * top test and out-of-line busy path. -g, -O1, -fno-gcse and the qualified
 * unsplit-edge/block-order flags did not close it; bounded trials stopped.
 * Corrected the old draft's normalization source, canonical vector-add identity,
 * and helper ABI: integer arguments rec/2/0; float arguments phase/0.
 * Next useful work: explain the loop-rotation pass before more source variants.
 */
typedef int TI128 __attribute__((mode(TI)));

extern char D_L00_001B2B50[];

extern void func_00282F20(char *a, char *b, float c);

extern void func_00282CC0(char *a, char *b, char *c);

extern void func_00282DD8(char *a, char *b, char *c);

extern float func_002A7940(void);

extern void func_L00_003E6778(char *rec, int a, int b, float c, float d);

extern float func_00283B98(float a, float b);

void func_L00_003E64F8(char *owner, int a1, void *a2, void *a3, float f12)
{
    char *base = *(char **)D_L00_001B2B50;
    char *rec = base;
    char *p1 = base + 0x10;
    char *p2 = base + 0x20;
    TI128 local;
    float v;
    int i = 0;
    int j;

    for (;;) {
        if (*(int *)(rec + 0x30) != 0) {
            p2 += 0x50;
            if (++i <= 0) {
                rec += 0x50;
                p1 += 0x50;
                continue;
            }
            rec += 0x50;
            break;
        }
        *(int *)(rec + 0x34) = a1;
        *(float *)(rec + 0x3C) = f12;
        *(int *)(rec + 0x30) = (int)owner;
        *(int *)(rec + 0x38) = 0;
        *(TI128 *)rec = *(TI128 *)a3;
        *(TI128 *)p2 = *(TI128 *)a2;
        *(float *)(rec + 0x28) = *(float *)((char *)owner + 0x18);
        func_00282F20((char *)&local, (char *)a3, 2.0f);
        func_00282CC0((char *)&local, (char *)&local, p2);
        func_00282DD8(p1, p2, (char *)&local);
        v = func_002A7940();
        for (j = 47; j >= 0; j--) {
            func_L00_003E6778(rec, 2, 0, v, 0.0f);
            v = func_00283B98(v, 0.1336848f);
        }
        *(int *)(rec + 0x44) = 0;
        *(int *)(rec + 0x40) = 0;
        break;
    }
}
