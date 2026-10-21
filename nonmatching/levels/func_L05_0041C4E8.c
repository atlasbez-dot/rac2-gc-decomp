/* func_L05_0041C4E8 (540 bytes, 4 places) -- NEAR MISS, not integrated.
   The same body serves func_L05_0041D800, func_L05_004268E8, func_L05_00426E70
   and func_L05_00426348; they differ only in the two `ori` immediates of the
   colour call (0x5FFF here, 0xFF40 in func_L05_0041D800, 0x7FFF in
   func_L05_004268E8, 0x4FFF in func_L05_00426E70, 0x20FF in
   func_L05_00426348).  See nonmatching/levels/func_L05_004268E8.c for the
   full reading of the body and for what differs.

   Measured: 540 bytes against 540 (the size is right) but the bytes differ;
   the first difference is at +0x3c, the extra `sd $fp` of the ninth
   callee-saved register.
*/
extern int ref_L05_0041C4E8_00[];

extern void func_00282CF0(void *, void *, void *);

extern void func_00282F20(void *, void *, float);

extern void func_00282CC0(char *dst, char *src, char *src2);

extern int func_00282948(void *);

extern float func_00283CE0(int);

extern int func_00283CF0(float);

extern float func_00282C48(float);

extern void func_00283D38(int, int, float);

extern void *func_002C2FD8(void *, void *, int, int, int, int, int, float);

void func_L05_0041C4E8(char *a0)
{
    TI128 buf[3];
    char *base;
    char *r;
    float *fp;
    char *ip;
    int b20;
    int off;
    float f;
    int n;
    int m;
    void *ptr;

    buf[2] = *(TI128 *)(a0 + 0x10);
    base = *(char **)(a0 + 0x68);
    r = base + 0x10;
    b20 = (int)base + 0x20;
    ((float *)&buf[2])[2] += 0.25f;
    func_00282CF0(&buf[0], ref_L05_0041C4E8_00, &buf[2]);
    func_00282F20(&buf[0], &buf[0], -0.3f);
    func_00282F20(&buf[1], &buf[0], 0.1f);
    func_00282CC0((char *)&buf[0], (char *)&buf[0], (char *)&buf[2]);
    fp = (float *)base;
    ip = base + 0x20;
    off = 0;
    do {
        f = *fp + *(float *)(r + off);
        *fp = f;
        if (f >= 255.0f)
            *fp = f - 255.0f;
        else if (f <= 0.0f)
            *fp = f + 255.0f;
        if (func_00282948((void *)ip) != 0)
            *(int *)(b20 + off) = 255;
        f = func_00283CE0(255 - *(int *)(b20 + off));
        f = f * (1.0f / 255.0f);
        func_00283D38(0x40405FFF, 0x10405FFF, func_00282C48(0.5f - f));
        n = func_00283CF0(*fp);
        ptr = func_002C2FD8(&buf[0], (void *)n, n & 0xFF, 0x35, 1, 2, 0,
                            *(float *)((int)base + 0x30 + off));
        if (ptr != 0) {
            m = func_00283CF0(1.0f);
            *(char *)(ptr + 0x9) = (char)(m + 0x60);
        }
        func_00282CC0((char *)&buf[0], (char *)&buf[0], (char *)&buf[1]);
        off += 4;
        fp++;
        ip += 4;
    } while ((int)fp < (int)r);
}

