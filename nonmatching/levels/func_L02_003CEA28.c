/* func_L02_003CEA28 (396 bytes, 4 places) -- NEAR MISS, not integrated.
   state: the call sequence, the argument lists and the float constants are the retail's;
   the frame and the stack slots are not. Ours is 392 bytes against retail's 396, the frame
   is 0x70 against retail's 0x80 (retail saves $s3 as well), and our locals sit 0x10 lower:
   retail lays the outgoing arguments out at 0x00, 0x08, 0x10, 0x18 (eight bytes apart, four
   64-bit slots) and the three 16-byte locals at 0x20, 0x30 and 0x40, where ours lays the
   four stack arguments out four bytes apart and the locals at 0x10, 0x20 and 0x30.

   What is measured and right:
   - the first float of the func_0032C700 call is `0.333f`: this cc1 parses 0.333f as
     0x3EAA7EFA, the bits retail holds (1.0f/3.0f would be 0x3EAAABAB).
   - the float of the func_00282F20 call is `0.1f`: this cc1 parses 0.1f as 0x3DCCCCCE,
     the bits retail holds (0.45f comes out 0x3EE66666).
   - the three locals are 16 bytes each and the one that is zeroed is a mode(TI) local
     (retail's `por`/`sq`), with the 1.0f written at its offset 8.
   - the calls, in order: func_002AB6D8(a0+0xC0, a0+0xF0) when the halfword at
     a0->f68+0x338 is not zero, func_002A6C58(a0, 0, 3), func_002E5CF8(1, 0, a0),
     func_00283098(vec, dir, a0+0xC0), func_00282CC0(vec, vec, a0+0x10),
     func_0032C700(a0+0x10, 0, 0, 0, 0, 10, 20, 0, 0.333f, 20.0f, 1, 0, 0, 0),
     func_00282CF0(buf, a0+0x10, D_00189EA0), func_002AFEB8(a0, buf, buf, 0, 0.0f),
     func_00282F20(buf, buf, 0.1f), func_002B0A68(a0, v & 0x1F, buf, 255, 3.0f, 6.0f,
     3.0f, 6.0f) and func_L00_002E6CF0(func_0029F338(a0) - 0x5D80, a0).
   - the last call's first argument is the *result* of func_0029F338 minus 0x5D80 (retail
     computes it in the delay slot), so the unit declares func_0029F338 as returning a
     pointer.
   - the byte at 0x1AF8F0 (a level symbol, D_L02_001AF8F0) is read into the register that
     the func_002A77E0(255) result then replaces; the "if it is zero, 255" branch is dead
     in retail and this cc1 keeps it.

   Tried and not enough: the stack arguments of the func_0032C700 call as int (four bytes
   apart) and as s64 (still four bytes apart here); the three locals as mode(TI) and as
   float[4]. What is left is the outgoing-argument area of the func_0032C700 call: retail
   reserves eight bytes per stack argument, and the declaration that produces that is not
   found yet. */

#include "include_asm.h"
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_002AB6D8(float *, float *);
extern void func_002A6C58(void *, int, int);
extern int func_002E5CF8(int, int, char *);
extern void func_00283098(float *, const float *, const float *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(float *, const float *, const float *);
extern void func_0032C700(void *, int, int, int, int, int, int, int, float, float, s64, s64, s64, s64);
extern void func_002AFEB8(char *, char *, char *, char *, float);
extern void func_00282F20(char *, char *, float);
extern int func_002A77E0(int);
extern void func_002B0A68(char *, int, int, unsigned char, float, float, float, float);
extern void *func_0029F338(void *);
extern void func_L00_002E6CF0(void *, void *);
extern char D_00189EA0[];
extern int D_L02_001AF8F0[];

void func_L02_003CEA28(char *a0)
{
    TI128 vec;
    TI128 dir;
    TI128 buf;
    int v;

    if (*(short *)((char *)*(void **)(a0 + 0x68) + 0x338) != 0)
        func_002AB6D8((float *)(a0 + 0xC0), (float *)(a0 + 0xF0));
    func_002A6C58(a0, 0, 3);
    func_002E5CF8(1, 0, a0);
    dir = 0;
    ((float *)&dir)[2] = 1.0f;
    func_00283098((float *)&vec, (float *)&dir, (float *)(a0 + 0xC0));
    func_00282CC0((float *)&vec, (float *)&vec, (void *)(a0 + 0x10));
    func_0032C700(a0 + 0x10, 0, 0, 0, 0, 10, 20, 0, 0.333f, 20.0f, 1, 0, 0, 0);
    func_00282CF0((float *)&buf, (float *)(a0 + 0x10), (float *)D_00189EA0);
    func_002AFEB8(a0, (char *)&buf, (char *)&buf, 0, 0.0f);
    func_00282F20((char *)&buf, (char *)&buf, 0.1f);
    v = *(int *)D_L02_001AF8F0;
    if (v == 0)
        v = 255;
    v = func_002A77E0(255);
    func_002B0A68(a0, v & 0x1F, (char *)&buf, 255, 3.0f, 6.0f, 3.0f, 6.0f);
    func_L00_002E6CF0((char *)func_0029F338(a0) - 0x5D80, a0);
}
