#include "include_asm.h"

/* The retail body normalises a quaternion: it turns the float the second argument
   points at into a vector, subtracts the vector (127, 127, 127, 0) from it, scales
   the difference and writes the result into the first argument.

   The frame, the calls and the constants match; what differs is the register
   allocation of the two locals: the retail keeps the first argument in $s0 and
   addresses the second local from $sp (`swc1 $f0,0x10($sp)`, `swc1 $f0,0x14($sp)`,
   `swc1 $f0,0x18($sp)`), while this cc1 keeps the local's address in $s0 and needs
   a second callee-saved register for the argument (`$s1`), which makes the body
   four bytes longer.  The zero store has the retail's shape (`por`+`sq` with the
   displacement of the local, which the compiler's zero-store fold does not
   rewrite) as soon as the local sits at +0x10. */
typedef unsigned char u8;
typedef __attribute__((mode(TI))) int TI;

extern void func_002830F0(char *dst, float *src);
extern void func_00282CF0(char *dst, char *a, char *b);
extern void func_00282D30(char *dst, char *a, char *b, float scale);

void func_002AE838(void *a0, void *a1)
{
    struct { float x, y, z, w; } v;
    TI w;

    w = 0;
    *(float *)((char *)&w + 8) = 127.0f;
    *(float *)((char *)&w + 0) = 127.0f;
    *(float *)((char *)&w + 4) = 127.0f;
    func_002830F0((char *)&v, *(float **)a1);
    func_00282CF0((char *)&v, (char *)&v, (char *)&w);
    func_00282D30((char *)a0, (char *)&v, (char *)&w,
                   *(float *)((char *)&v + 0xC) * 0.0001f);
}
