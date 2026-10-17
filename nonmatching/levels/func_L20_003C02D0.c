/* 0 of 1 places match - last line: 20_yeedil: 132 bytes, expected 128
   Walks the table D_L20_001FBB20[state->first word]: for each record
   (D_L20_001B2F9C + (word & 0x7FFF) << 8) copy its 0x18 float into
   D_L20_0023E670 (advancing the destination), subtract 20.0f from the record's
   own float, raise 0x41 on its 0x34 half-word, and continue while the record's
   packed half is not negative. Retail hoists the 20.0f constant into $f1
   (`lui $at,0x41A0; mtc1`), the destination base into $a1 and the record base
   into $a2 before the loop, and reloads the record's float after the destination
   store. This form is 132 bytes (one word over): the same body with the flag
   update written before the float store, or a per-iteration record base, changes
   other words. Blocker: one extra scheduling word after the destination store. */
typedef char *ptr;
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern char *D_L20_001FBB20[];
extern char *D_L20_001B2F9C;
extern f32 D_L20_0023E670[];

void func_L20_003C02D0(char *a0) {
    char *s = *(char **)(a0 + 0x68);
    char *r = D_L20_001FBB20[*(int *)s];
    f32 *dst;

    if (r == 0)
        return;
    dst = D_L20_0023E670;
    do {
        u32 v = (*(u16 *)r & 0x7FFF) << 8;
        char *o = D_L20_001B2F9C + v;

        *dst++ = *(f32 *)(o + 0x18);
        *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) - 20.0f;
        *(u16 *)(o + 0x34) = *(u16 *)(o + 0x34) | 0x41;
    } while (*(s16 *)r++ >= 0);
}
