#include "include_asm.h"

/* func_002BABE8 is in 002B7E28-g8.c.

   It reads the game-time word D_001B1688, whose retail access is the pair
   `lui $v0,%hi(D_001B1688)` / `lw $v0,%lo(D_001B1688)($v0)`: one register for the
   address and the loaded word.  A file built with -G8 (config/cflags.txt) makes the
   compiler emit a bare symbol reference, which the assembler expands into that
   pair; a -G0 unit emits `lui`/`lw` with two different registers instead.  The
   same file holds the clear of the fixed-address word at 0x10000000, which the
   retail reaches through its own `lui`/`sw` pair. */

extern int D_001B1688;

/* The fixed-address word the particle update clears.  Its address is the same in
   every program, so it is named after the address; the incomplete array keeps it
   out of the small-data pool, which is what makes the compiler split the address
   into the retail's `lui`/`sw` pair. */
extern int D_10000000[];

extern void func_002AE838(char *dst, char *src);

extern void func_00282CC0(char *dst, char *a, char *b);

extern float func_00283CE0(int a);

extern int func_00283D38(int a, int b, float f);

extern int func_00282978(short *p);

extern void func_00282D08(float *out, char *a, char *b, float f);

extern void func_002B9180(void *p);

typedef struct {
    float v[4];
} Vec4_002BABE8;

void func_002BABE8(char *self)
{
    char *s2 = self;
    char *s3 = self + 0x20;
    Vec4_002BABE8 t0, t1, t2;
    float f;

    if (D_001B1688 & 1) {
        *(unsigned char *)(s2 + 8) = *(unsigned char *)(s2 + 8) + 1;
    }
    if (*(short *)(s3 + 0x10) != 0) {
        D_10000000[0] = 0;
        func_002AE838((char *)&t0, s3);
        func_00282CC0(s2 + 0x10, s2 + 0x10, (char *)&t0);
        f = func_00283CE0(*(short *)(s2 + 0xA)) / func_00283CE0(*(short *)(s3 + 0x10));
        *(int *)(s2 + 4) = func_00283D38(*(int *)(s3 + 8) & 0xFFFFFF, *(int *)(s3 + 8), 1.0f - f);
        *(float *)(s2 + 0xC) = (float)(*(short *)(s3 + 0x16) * 1000);
        if (func_00282978((short *)(s2 + 0xA)) != 0) {
            *(short *)(s3 + 0x10) = 0;
            *(short *)(s2 + 0xA) = *(unsigned short *)(s3 + 0x12);
        }
    } else if (*(short *)(s3 + 0x12) != 0) {
        func_002AE838((char *)&t1, s3);
        func_002AE838((char *)&t2, s2 + 0x24);
        f = func_00283CE0(*(short *)(s2 + 0xA)) / func_00283CE0(*(short *)(s3 + 0x12));
        func_00282D08((float *)&t0, (char *)&t2, (char *)&t1, f);
        func_00282CC0(s2 + 0x10, s2 + 0x10, (char *)&t0);
        *(float *)(s2 + 0xC) = ((float)(*(short *)(s3 + 0x16) - *(short *)(s3 + 0x18)) * f
                               + (float)*(short *)(s3 + 0x18)) * 1000.0f;
        *(int *)(s2 + 4) = func_00283D38(*(int *)(s3 + 0xC), *(int *)(s3 + 8), f);
        if (func_00282978((short *)(s2 + 0xA)) != 0) {
            *(short *)(s3 + 0x12) = 0;
            *(short *)(s2 + 0xA) = *(unsigned short *)(s3 + 0x14);
        }
    } else {
        func_002AE838((char *)&t0, s2 + 0x24);
        func_00282CC0(s2 + 0x10, s2 + 0x10, (char *)&t0);
        *(int *)(s2 + 4) = func_00283D38(*(int *)(s3 + 0xC) & 0xFFFFFF, *(int *)(s3 + 0xC),
                                         func_00283CE0(*(short *)(s2 + 0xA))
                                             / func_00283CE0(*(short *)(s3 + 0x14)));
        *(float *)(s2 + 0xC) = (float)(*(short *)(s3 + 0x18) * 1000);
        if (func_00282978((short *)(s2 + 0xA)) != 0) {
            func_002B9180(s2);
        }
    }
}
