/*
 * func_L00_003C8608 - near miss, 540 bytes, 27 places.  Needs a -G8 unit: the level tables are
 * read through $gp (gp+0x10B0, +0x10F0, +0x10F4, +0x10F8, +0x10FC), so the body belongs in
 * L00_003C6298-g8.c and its marker is removed from L00_003C6298.c.
 *
 * What the body is: draws the object twice.  It builds one render packet from the frame at +0xD0
 * (scale from gp+0x10F8, two matrix products with the constants at 0x2403C0 and 0x18A0E0, one
 * negated product), then walks the four 16-byte vectors of the table at gp+0x10B0 through the
 * packet (func_2EE178 + func_2EE5D8) with the weight at gp+0x10F0, draws it, sets the packet
 * colour to 0xFFFFFFFF and walks the same four vectors again with the weight at gp+0x10F4.
 *
 * Measured result: 548 bytes against 540.  The frame (0x140), the saved set, the whole packet
 * block, both walk loops and the epilogue line up one for one; the two extra instructions are
 * scheduling: this source puts the loop preheader's `nop` in the first walk where retail puts it
 * in the second, and the second walk keeps one copied pointer register that retail reuses.
 *
 * Note measured: an array declared `__attribute__((sda))` only takes the $gp form when its
 * declared size fits -G8; `float D[16]` (64 bytes) falls back to lui/addiu, while
 * `int D[2]` takes `addiu $r,$gp,off`.  That alone was the difference between 556 and 548 bytes.
 *
 * Reopen: a formulation that makes the compiler place the preheader nop in the second walk, or
 * that lets the second walk reuse the packet pointer instead of copying it.
 */
#include "include_asm.h"

extern int func_2E67A0(int);
extern void func_2EE3D0(char *, char *, float);
extern void func_2EE108(char *, char *, char *);
extern void func_2EE138(char *, char *, char *);
extern void func_2EE220(char *, char *, char *);
extern void func_2EE178(char *, char *, float);
extern void func_2EE5D8(char *, char *, char *);
extern void func_2EAC30(char *, char *, char *);

extern int D_L00_1B00A0[2] __attribute__((sda));
extern float D_L00_1B00E0 __attribute__((sda));
extern float D_L00_1B00E4 __attribute__((sda));
extern float D_L00_1B00E8 __attribute__((sda));
extern int D_L00_1B00EC __attribute__((sda));

extern int func_2E67A0(int);
extern void func_2EE3D0(char *, char *, float);
extern void func_2EE108(char *, char *, char *);
extern void func_2EE138(char *, char *, char *);
extern void func_2EE220(char *, char *, char *);
extern void func_2EE178(char *, char *, float);
extern void func_2EE5D8(char *, char *, char *);
extern void func_2EAC30(char *, char *, char *);

extern int D_L00_1B00A0[2] __attribute__((sda));
extern float D_L00_1B00E0 __attribute__((sda));
extern float D_L00_1B00E4 __attribute__((sda));
extern float D_L00_1B00E8 __attribute__((sda));
extern int D_L00_1B00EC __attribute__((sda));

/* Draws the object twice: builds one render packet from its frame at +0xD0, then feeds the four
   16-byte vectors of the level's small-data table through the packet, once in the level's colour
   and once in the inverted one. */
void func_L00_003C8608(char *self)
{
    unsigned char work[0xE0];
    float vector[4];
    int *source;
    float *target;
    int i;

    func_2E67A0(0xB);
    *(long long *)(work + 0x80) = 0x0000FF9000000260LL;
    *(long long *)(work + 0x88) = 0x0000008000000048LL;
    *(int *)(work + 0x4C) = D_L00_1B00EC;
    *(int *)(work + 0x48) = D_L00_1B00EC;
    *(int *)(work + 0x44) = D_L00_1B00EC;
    *(int *)(work + 0x40) = D_L00_1B00EC;
    *(long long *)(work + 0x78) = func_2E67A0(0xB);
    *(long long *)(work + 0x70) = 0;
    *(int *)(work + 0x50) = 0;
    *(int *)(work + 0x54) = 0;
    *(int *)(work + 0x58) = 0;
    *(float *)(work + 0x5C) = 1.0f;
    *(float *)(work + 0x60) = 1.0f;
    *(int *)(work + 0x64) = 0;
    *(float *)(work + 0x68) = 1.0f;
    *(float *)(work + 0x6C) = 1.0f;

    func_2EE3D0((char *)vector, self + 0xD0, D_L00_1B00E8);
    func_2EE108((char *)work + 0xC0, (char *)0x2403C0, (char *)vector);
    func_2EE138((char *)vector, (char *)0x1B8DC0, (char *)work + 0xC0);
    func_2EE3D0((char *)work + 0x90, (char *)vector, 1.0f);
    func_2EE220((char *)work + 0xA0, (char *)work + 0x90, (char *)0x18A0E0);
    func_2EE3D0((char *)work + 0xA0, (char *)work + 0xA0, -1.0f);
    func_2EE220((char *)work + 0xB0, (char *)work + 0xA0, (char *)work + 0x90);

    target = (float *)work;
    for (i = 3, source = D_L00_1B00A0; i >= 0; i--) {
        func_2EE178((char *)work + 0xD0, (char *)source, D_L00_1B00E0);
        func_2EE5D8((char *)target, (char *)work + 0xD0, (char *)work + 0x90);
        source += 4;
        target += 4;
    }
    func_2EAC30((char *)work, (char *)0, (char *)0);

    *(int *)(work + 0x40) = -1;
    *(int *)(work + 0x44) = -1;
    *(int *)(work + 0x48) = -1;
    *(int *)(work + 0x4C) = -1;

    target = (float *)work;
    for (i = 3, source = D_L00_1B00A0; i >= 0; i--) {
        func_2EE178((char *)work + 0xD0, (char *)source, D_L00_1B00E4);
        func_2EE5D8((char *)target, (char *)work + 0xD0, (char *)work + 0x90);
        source += 4;
        target += 4;
    }
    func_2EAC30((char *)work, (char *)0, (char *)0);
}
