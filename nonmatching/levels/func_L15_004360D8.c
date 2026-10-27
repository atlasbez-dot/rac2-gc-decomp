/* Mid worker 19 near miss (func_L15_004360D8).
   Profile: -O2 -G0 -ffunction-sections -frac2-qcopy.
   Status: 440 vs 444 bytes: retail keeps the table pointer, link byte and source pointer in $s0 and the first temporaries in $v0/$v1/$a1; here the temporaries are allocated differently. */
typedef int TI128 __attribute__((mode(TI)));
typedef unsigned char u8;
typedef unsigned short u16;

extern char *func_0029EFD0(int);
extern void func_00282D60(void *, void *, float);
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_002AB6D8(char *, char *);

void func_L15_004360D8(char *self, int idx)
{
    char *p = *(char **)(self + 0x24);
    int count = *(short *)(p + 0x2E);

    if (count != 0) {
        char *entry = p + (count << 4);
        int link = *(u8 *)(entry + idx + 1);

        if (link != 0xFF) {
            char *basis = self + 0xC0;
            char *pos = self + 0x10;
            char *obj;
            char *st;
            char *a;
            char *b;
            char m[0x30] __attribute__((aligned(16)));

            p = entry + (link << 4);
            obj = func_0029EFD0(0x1211);
            st = *(char **)(obj + 0x68);
            a = st + 0x420;
            b = st + 0x410;
            func_00282D60(a, p, *(float *)(self + 0x2C) * 0.0009765595197677612f);
            func_00283098(a, a, basis);
            func_00282CC0(a, a, pos);
            *(u8 *)(obj + 0x30) = 0xFF;
            *(u16 *)(obj + 0x32) = 0x1FF;
            *(u16 *)(obj + 0x34) |= 0x100;
            *(float *)(obj + 0x2C) = *(float *)(self + 0x2C);
            func_00282CF0(b, a, pos);
            func_00282F20(b, b, 0.26666668f);
            *(TI128 *)(obj + 0xC0) = *(TI128 *)basis;
            *(TI128 *)(obj + 0xD0) = *(TI128 *)(self + 0xD0);
            *(TI128 *)(obj + 0xE0) = *(TI128 *)(self + 0xE0);
            *(TI128 *)m = *(TI128 *)basis;
            *(TI128 *)(m + 0x10) = *(TI128 *)(self + 0xD0);
            *(TI128 *)(m + 0x20) = *(TI128 *)(self + 0xE0);
            func_002AB6D8(m, st + 0x400);
            *(u8 *)(obj + 0x20) = 7;
            *(u16 *)(obj + 0x7C) = (1 << idx) | 0x8000;
            *(TI128 *)(obj + 0x10) = *(TI128 *)pos;
            *(int *)(obj + 0x98) = 0;
        }
    }
}
