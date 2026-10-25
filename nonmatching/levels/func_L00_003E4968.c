/* 0 of 27 places match - last line: 00_aranos_tutorial: 536 bytes, expected 532.
   The loop, the call order and the four argument buffers are right; the eight
   remaining instructions are allocation and rematerialisation:
   - the rebuilt cc1 hoists the loop-invariant symbol address
     (`D_L00_001A8F20`, the second argument of both spawn calls) into a saved
     register, where retail rematerialises `lui/addiu` per call;
   - it likewise hoists the two float literals the spawn calls pass twice
     (42000.0f, 273000.0f) into $f22/$f23 and grows the frame to 0xA0/0x90; an
     explicit per-iteration `float big;` local keeps them inside the loop but
     still leaves the frame one instruction over;
   - the loop counter and the `d` buffer land in different saved registers
     ($s3/$s5 here, $s2/$s1 in retail).
   Best measured form: -O2 -G0 -ffunction-sections -fno-gcse (536 bytes; the
   plain default gives 584). Reopen: a source shape that keeps the spawn
   arguments out of the preheader without -fno-gcse, so the whole file can keep
   the default profile. */

#include "include_asm.h"

extern void func_2EE178(float *a0, char *a1, float f12);
extern void func_2EE108(float *a0, float *a1, float *a2);
extern float func_31A820(float *a0, float f12, float f13);
extern int func_31A728(int a0);
extern char *func_33DC48(float *a0, char *a1, int a2, int a3, void *t0, int t1,
                         int t2, int t3, float f12, float f13, float f14);

extern char D_L00_001FE940[];
extern char D_L00_001A8F20[];

void func_L00_003E4968(char *a0) {
    float a[4];
    float b[4];
    float c[4];
    float d[4];
    char *tbl;
    char *n;
    char *r;
    char *v;
    float big;
    int i;

    v = *(char **)(a0 + 0x68);
    a[0] = *(float *)(v + 0x14);
    a[1] = *(float *)(v + 0x18);
    a[2] = *(float *)(v + 0x1C);
    a[3] = 0.0f;
    func_2EE178(b, a0 + 0xD0, -0.1f);
    func_2EE108(a, a, b);
    func_2EE178(c, a0 + 0xE0, 0.15f);
    func_2EE108(a, a, c);
    func_2EE178(c, a0 + 0xE0, -0.033333335f);
    tbl = D_L00_001FE940;
    for (i = 8; i >= 0; i--) {
        d[0] = a[0] + func_31A820(c, 0.0f, 0.1f);
        d[1] = a[1] + func_31A820(c, 0.0f, 0.1f);
        d[2] = a[2] + func_31A820(c, 0.0f, 0.1f);
        n = (char *)func_31A728(0xFF);
        big = 42000.0f;
        func_33DC48(d, D_L00_001A8F20, 4, 0x808080, n, 0x7F, 0x7F, 1, big, big, 0.0f);
        big = 273000.0f;
        r = func_33DC48(a, D_L00_001A8F20, 4, 0x406080, n, 0x10, 0x10, 1, big, big, 0.0f);
        if (r != 0)
            *(unsigned char *)(r + 2) = *(unsigned char *)(*(unsigned *)(tbl + 0xD4));
        func_2EE108(a, a, c);
    }
}
