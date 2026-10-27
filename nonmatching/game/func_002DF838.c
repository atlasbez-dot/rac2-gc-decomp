#include "include_asm.h"

extern short D_001A6480[];

extern unsigned char *D_001B22A8;

extern void func_002FC560(unsigned int reg, unsigned long value);

/* Near miss for func_002DF838 (boot 0x002DF838, 424 bytes, 28 places: boot and 27
 * levels).  File profile is the sdk one: -O2 -G2 -ffunction-sections.
 * Best local check: 396 bytes, `func_002DF838: 0 of 28 places match`.
 *
 * Retail body: one GS packet.  w = D_001A6480[0xA8], h = D_001A6480[0xA9] (lh),
 * n = w / 32 (signed division), then func_002FC560(0x42, 0x64).  The 16-byte DMA
 * tag is written through D_001B22A8 (each word reloads the global):
 *   +0 (n+5)|0x10000000, +4 0, +8 0, +0xC (n+5)|0x50000000.
 * The cursor advances by 0x10 and a ten-qword descriptor is written at it:
 *   +0x00 0x1000000000000001  +0x08 0xE       +0x10 0x31001
 *   +0x18 0x47                +0x20 0x2400000000008001
 *   +0x28 0x10                +0x30 0x146     +0x38 0x7F808080
 *   +0x40 0x2400000000008000|n                +0x48 0x44
 * A loop then writes n pairs of qwords at cursor+0x60:
 *   line0 = 0x8000 - w*8 (incremented by 0x200), top = (0x8000 - h*8)<<16,
 *   line1 = 0x8200 - w*8 (incremented by 0x200), bot = (h*8 + 0x7FF0)<<16,
 *   qword0 = line0 | top, qword1 = line1 | bot,
 * and the cursor finally becomes cursor + n*16 + 0x50.
 *
 * This draft reproduces the whole body and every constant, but GCC allocates
 * w/h/n to $s0/$s1/$s3 and the first packed tag constant to $s2, where retail has
 * w/h/n in $s1/$s2/$s0 and the constant in $t5; the 0x20 vs 0x30 frame and the
 * loop shape follow from that.
 *
 * Loop difference: retail keeps an up-counter (`slt t6,s0` / `bnez`) and advances
 * the destination pointer by 8 twice per iteration; this cc1 strength-reduces the
 * same source to a countdown loop (`addiu a1,-1` / `bnez`) with one +0x10 step.
 * The loop was tried both as a walking `unsigned char *` (two += 8) and as
 * `q + 0x60 + i * 16`; both count down here.
 *
 * Next experiment: a spelling that keeps the loop counter live in the body (so
 * loop.c cannot count down) while still producing the two +8 pointer steps, and
 * a store order that materialises the qword constants immediately before their
 * stores so the tag stays in a caller-saved register.
 */
void func_002DF838(void)
{
    short w = D_001A6480[0xA8];
    short h = D_001A6480[0xA9];
    int n = w / 32;
    unsigned char *q;
    long long top;
    long long bot;
    int line0;
    int line1;
    int i;

    func_002FC560(0x42, 0x64);
    *(unsigned int *)(D_001B22A8 + 0) = (n + 5) | 0x10000000;
    *(unsigned int *)(D_001B22A8 + 4) = 0;
    *(unsigned int *)(D_001B22A8 + 8) = 0;
    *(unsigned int *)(D_001B22A8 + 0xC) = (n + 5) | 0x50000000;
    q = D_001B22A8 + 0x10;
    D_001B22A8 = q;
    *(unsigned long long *)(q + 0) = 0x1000000000000001ULL;
    *(unsigned long long *)(q + 0x48) = 0x44;
    *(unsigned long long *)(q + 8) = 0xE;
    *(unsigned long long *)(q + 0x10) = 0x31001;
    *(unsigned long long *)(q + 0x18) = 0x47;
    *(unsigned long long *)(q + 0x20) = 0x2400000000008001ULL;
    *(unsigned long long *)(q + 0x28) = 0x10;
    *(unsigned long long *)(q + 0x30) = 0x146;
    *(unsigned long long *)(q + 0x38) = 0x7F808080;
    *(unsigned long long *)(q + 0x40) = 0x2400000000008000ULL | n;
    top = (long long)(0x8000 - h * 8) << 16;
    bot = (long long)(h * 8 + 0x7FF0) << 16;
    line0 = 0x8000 - w * 8;
    line1 = 0x8200 - w * 8;
    for (i = 0; i < n; i++) {
        *(unsigned long long *)(q + 0x60 + i * 16) = (long long)line0 | top;
        *(unsigned long long *)(q + 0x68 + i * 16) = (long long)line1 | bot;
        line0 += 0x200;
        line1 += 0x200;
    }
    D_001B22A8 = D_001B22A8 + n * 16 + 0x50;
}
