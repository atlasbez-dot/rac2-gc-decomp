/* Retained complete C repair, 2026-10-25; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy.
 * Private placement checks: us: 0/1, us2: 0/1, pal: 0/1.
 * The submission object is 144 bytes: four vectors, four color words, eight UV
 * floats and four genuine 64-bit register words. The initializer writes the
 * four tail fields at +0x70/+0x78/+0x80/+0x88, and the submit consumer reads
 * them. Its optional second input is a matrix pointer, null here. Historical
 * screening used an incomplete 112-byte object.
 * Current code is 520/552 bytes. The object extent and frame 0xE0 now agree
 * with retail; address/index allocation and the two inner loops still differ.
 * No dummy frame bytes were added.
 */

#include "common.h"

typedef int L12_TI128 __attribute__((mode(TI)));

extern int D_L12_001B1F40 __attribute__((sda));
extern int D_L12_001B1F34 __attribute__((sda));
extern int D_L12_001B1F38 __attribute__((sda));

extern float D_L12_002A38F8[][2];
extern char D_L12_002A11B0[][16];
extern short D_L12_002A2410[][12];

extern void func_00281DE8(void *, int, int, int);
extern void func_00280B90(void *, void *, int);

typedef struct {
    L12_TI128 v[4];
    int i[4];
    float f[8];
    u64 registers[4];
} L12Buf_420950;

void func_L12_00420950(char *a0)
{
    char *state = *(char **)(a0 + 0x68);
    L12Buf_420950 buf;
    short *p;
    int i;
    int j;

    func_00281DE8(&buf, D_L12_001B1F40, 2, 0x80);
    buf.i[0] = D_L12_001B1F34;
    buf.i[3] = D_L12_001B1F34;
    buf.i[2] = D_L12_001B1F34;
    buf.i[1] = D_L12_001B1F34;
    p = D_L12_002A2410[0];
    for (i = 0; i < 0xDF; i++) {
        char *dst = (char *)&buf.v[0];
        float *f0p = &buf.f[0];
        float *f1p = &buf.f[1];
        short *e = p;

        for (j = 0; j < 4; j++, e += 3) {
            short i0 = e[0];
            short i1 = e[1];

            *(L12_TI128 *)dst = *(L12_TI128 *)D_L12_002A11B0[i0];
            *f0p = D_L12_002A38F8[i1][0] + *(float *)(state + 0x10);
            *f1p = D_L12_002A38F8[i1][1];
            dst += 16;
            f0p += 2;
            f1p += 2;
        }
        func_00280B90(&buf, 0, 0);
        p += 12;
    }
    func_00281DE8(&buf, D_L12_001B1F40 + 1, 2, 0x80);
    for (i = 0; i < 0xDF; i++) {
        char *dst;
        float *f0p;
        float *f1p;
        short *e;

        p = (short *)((char *)D_L12_002A2410 + i * 0x18);
        dst = (char *)&buf.v[0];
        f0p = &buf.f[0];
        f1p = &buf.f[1];
        e = p;
        for (j = 0; j < 4; j++, e += 3) {
            short i0 = e[0];
            short i1 = e[1];

            *(L12_TI128 *)dst = *(L12_TI128 *)D_L12_002A11B0[i0];
            *f0p = D_L12_002A38F8[i1][0] + *(float *)(state + 0x10);
            *f1p = D_L12_002A38F8[i1][1];
            dst += 16;
            f0p += 2;
            f1p += 2;
        }
        func_00280B90(&buf, 0, 0);
    }
}
