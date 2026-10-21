/* func_L17_003C5B68 (188 bytes) -- NEAR MISS, not integrated.
   state: 196 bytes against retail's 188; the two table lookups, the float
   test and the three returns are all there, but the shape of the early
   returns and the branch forms differ.
   check.py (17_smolg), with the source below:
     17_smolg: 196 bytes, expected 188
   Retail returns 0 from three places and 1 from three, and the body is a
   chain of tests whose branches are `bnel`/`bnez` where this cc1 gives plain
   branches; the last check (the byte 0xFD) becomes `xori`+`sltiu` here and
   `beq` there.

   The table base is reached through $gp (0x001B2C1C), so the body needs the
   -G8 profile and belongs in L17_0032C070-g8.c.

   Tried: the returns as one tail return, the tests as one && chain, the
   table entry compared against 0xFE and 0xFD in the other order, the
   remainder of the state word read as a signed and as an unsigned halfword.
   */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef int s32;
typedef float f32;

extern s32 D_0018A160;
extern s32 D_L17_001B2C1C __attribute__((sda));

int func_L17_003C5B68(s32 a0) {
    s32 a1 = *(s16 *)(a0 + 0xAA);
    s32 s0;
    s32 v0;
    u16 v1;
    s32 a2;
    u8 *p;

    if (D_0018A160 == 0)
        return 0;
    if (a1 == 0x920)
        return 1;
    if (a1 != 0x929)
        return 0;
    s0 = *(s32 *)(a0 + 0x68);
    v0 = *(s32 *)(s0 + 0x9C);
    if (v0 != 0) {
        v1 = *(u16 *)(v0 + 0xAA);
        if ((u16)(v1 - 0x920) < 2)
            return 0;
        if ((s16)v1 == a1)
            return 0;
    }
    if (*(f32 *)(s0 + 0x98) != 0.0f)
        return 0;
    a2 = *(s32 *)(s0 + 0xA0);
    if (a2 == -1)
        return 1;
    p = (u8 *)(D_L17_001B2C1C + (a2 << 8));
    if (p == 0)
        return 1;
    if (p[0x20] == 0xFE)
        return 1;
    if (p[0x20] == 0xFD)
        return 1;
    return 0;
}
