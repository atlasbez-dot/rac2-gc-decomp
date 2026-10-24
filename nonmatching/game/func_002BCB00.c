/* func_002BCB00 - near miss.
 *
 * Retail size: 340 bytes. This candidate is 336 bytes and matches 0 of 28
 * placements in both USA v1.01 and USA v2.00. The boot diff shows different
 * saved-register allocation (position in $s0 and allocation result in $s1,
 * versus retail position in $s3 and result in $s0), plus a different pointer
 * setup and scheduling around the vector copies and float constant.
 *
 * Eight generated variants measured 328, 324, 328, 332, 332, 332, 332 and
 * 336 bytes; the first source compile failed on a hex-float literal.
 */

typedef unsigned char u8;

extern char *func_002B9030(int);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern int func_001163B0(void);
extern u8 *D_001F257C;

typedef int V4_002BCB00 __attribute__((mode(TI)));

typedef union {
    V4_002BCB00 whole;
    float lane[4];
} V4F_002BCB00;

char *func_002BCB00(char *position, char *motion, int color, int motion_arg,
                    int lifetime, int motion_arg2, int type, int color_byte,
                    int scale, float size)
{
    char *p;
    V4F_002BCB00 *v;
    V4F_002BCB00 *q;
    int alpha;

    if (lifetime == 0) {
        return 0;
    } else {
        p = func_002B9030(15);
    }
    if (p != 0) {
        v = (V4F_002BCB00 *)(p + 0x10);
        v->whole = *(V4_002BCB00 *)position;
        v->lane[3] = func_00283CE0(scale);
        *(int *)(p + 4) = color;
        alpha = func_00283CF0(4.0f);
        *(unsigned char *)(p + 9) = alpha - 0x60;
        if (color_byte != -1)
            *(unsigned char *)(p + 3) = color_byte;
        else
            *(unsigned char *)(p + 3) = 0x48;
        *(unsigned char *)(p + 1) = 0;
        *(float *)(p + 0x0C) = size;
        *(unsigned char *)(p + 8) = func_001163B0();
        if (type == -1)
            *(unsigned char *)(p + 2) = *D_001F257C;
        else
            *(unsigned char *)(p + 2) = type;

        q = (V4F_002BCB00 *)(p + 0x20);
        *(short *)(p + 0x0A) = lifetime;
        *(short *)((char *)q + 0x18) = lifetime;
        *(float *)((char *)q + 0x1C) = size;
        *(int *)((char *)q + 0x10) = color;
        *(int *)((char *)q + 0x14) = motion_arg;
        *(short *)((char *)q + 0x1A) = motion_arg2;
        q->whole = *(V4_002BCB00 *)motion;
        q->lane[3] = 0.004055555909872055f;
    }
    return p;
}
