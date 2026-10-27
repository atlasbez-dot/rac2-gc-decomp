/* from src/levels/09_dobbo/L09_002F8BA0.c: samples the sub-object's 0x390 vector
 * block through the shared cross/angle bodies, stamps the record's 0x3DC/0x278 and
 * 0x3E0/0x274 angles, copies the block to 0x330, seeds the shared ray body with the
 * block and 0.9*0x434, registers func_L09_003FD7D0 when the 1.4*0x434 test hits, and
 * walks the shared hit table D_L09_001C3EC0 stamping the first object whose kind is
 * 0xCB/0x76C/0xEB0 into 0x3AC/0x44C.
 * Best of 5 compiles: 516 bytes against retail 532, 0/1 in level 09.
 * The whole body is retail's apart from four instructions: (a) the retail store block
 * reloads *p for its 0x3AC store (three delay-slot `lw $v1,0($a0)` copies) where this
 * cc1 reuses the null-check load, (b) retail has a second `blez` at the loop entry
 * (retail tests the count twice), (c) the 16-byte copies keep register addresses in
 * retail (`lq $v0,0($s0); sq $v0,0($v1)`) where this source folds the displacements,
 * and (d) the a0/subobject/block locals come out as $s1/$s0/$s2 instead of retail's
 * $s2/$s1/$s0. Next hypothesis: a source where the hit entry is not bound to a local
 * across the compare chain (so the store reloads), and a Vec4 struct-copy spelling
 * that keeps both copy addresses in registers. */
extern float func_00282E80(void *, void *);
extern void func_00282CF0(float *, const float *, const float *);
extern float func_00282E20(void *);
extern float func_00283248(float, float);
extern float func_00283BE0(float, float);
extern int func_00283DB8(char *, float);
extern int func_00277F48(void *, int, void *, void *, float);
extern void func_0029FC20(char *, int, void *);
extern void func_L00_002E6EF8(void (*)(void *), void *);
extern void func_L09_003FD7D0(unsigned char *);

extern unsigned char *D_L09_001C3EC0[];

typedef int qword __attribute__((mode(TI)));

int func_L09_003FE0C0(unsigned char *a0, int a1) {
    unsigned char *s1 = *(unsigned char **)(a0 + 0x68);
    float v[8];
    int done = 0;
    int n;
    int i;
    unsigned char **p;

    if (func_00282E80(a0 + 0x10, s1 + 0x140) <
        (float)*(short *)(a0 + 0x32) * 2.0f) {
        unsigned char *blk;
        unsigned char *dst;
        float x;
        float y;
        float r;

        func_0029FC20(a0, 1, s1 + 0x340);
        done = 1;
        blk = s1 + 0x390;
        func_00282CF0(v, blk, s1 + 0x370);
        x = func_00283248(v[0], v[1]);
        y = -func_00283248(func_00282E20(v), v[2]);
        r = func_00283BE0(x, *(float *)(a0 + 0xF8));
        *(float *)(s1 + 0x278) = r;
        *(float *)(s1 + 0x3DC) = r;
        r = func_00283BE0(y, *(float *)(a0 + 0xF4));
        *(float *)(s1 + 0x274) = r;
        *(float *)(s1 + 0x3E0) = r;
        dst = s1 + 0x330;
        *(qword *)dst = *(qword *)blk;
        if (a1 != 0) {
            *(qword *)(v + 4) = *(qword *)dst;
            v[7] = *(float *)(s1 + 0x434) * 1.4f;
            if (func_00283DB8((char *)(v + 4), (float)*(short *)(a0 + 0x32)) != -1) {
                func_L00_002E6EF8(func_L09_003FD7D0, a0);
            }
        }
        n = func_00277F48(blk, 0, 0, 0, *(float *)(s1 + 0x434) * 0.9f);
        if (n > 0) {
            for (i = n, p = D_L09_001C3EC0; i != 0; i--, p++) {
                if (*(int *)p == 0) {
                    continue;
                }
                if (*(short *)(*(unsigned char **)p + 0xAA) != 0xCB &&
                    *(short *)(*(unsigned char **)p + 0xAA) != 0x76C &&
                    *(short *)(*(unsigned char **)p + 0xAA) != 0xEB0) {
                    continue;
                }
                *(int *)(s1 + 0x3AC) = *(int *)p;
                *(int *)(s1 + 0x44C) = *(short *)(*(unsigned char **)p + 0xAA);
            }
        }
        if (a1 != 0) {
            *(int *)(s1 + 0x42C) |= 2;
        }
    }
    return done;
}
