/* 0 of 1 places match - last line: 11_joba: 332 bytes, expected 336
   G8: the body reads the level's list through $gp, so it needs the
   src/levels/11_joba/L11_002DE9E0-g8.c unit (-G8).
   The body is recovered: the level's list at D_001A79F0 + 0x18C is walked once
   per object, the objects of type 0xE29 get their flag word at +0x34 set,
   the ones of type 0xD54 are handed to func_002E64A0, and the ones of type
   0xFA0 are drawn through func_L00_00326048 with the level's two packed
   words; afterwards, when D_001A79F0 is not 11 and the level's mode word at
   D_L11_001BE5C0 + 0x30 is 2, the level's own effect is started.  The whole
   loop body (from the object load to the call's argument setup) matches word
   for word.  Four differences are left: retail keeps the counter in $s1, the
   array pointer in $s2 and the list base in $s3 while this cc1 uses $s3, $s1
   and $s2 for the same three values in the same order, retail's test of the
   object count is the branch-likely `blezl` while this cc1 emits a plain
   `blez`, retail loads D_001A79F0 once (in the branch's delay slot, the
   one-instruction $gp form) and reuses it while this cc1 loads it twice (the
   $gp form in the delay slot and the absolute form for the list base), and
   retail's D_001A79F0 at the end is read again in the absolute form while
   this cc1 reads it the same way.  The count is read again for each call: the
   global can change under the calls. */

#include "common.h"

extern void func_L00_002FC980(void);

extern void func_002E64A0(u8 *a0);

extern void func_L00_00326048(u8 *a0, u8 *a1, u32 a2, u32 a3, f32 f12);

extern void func_L00_002E6CF0(void *a0, void *a1);

extern u32 D_001A79F0;

extern u32 D_L11_0030FD58;

/* The level's own state block: the count at +0x44 and the mode word at +0x30. */
typedef struct {
    char pad0[0x30];
    s32 mode30;
    char pad34[0x10];
    s16 count44;
} L11State;

extern L11State D_L11_001BE5C0;

void func_L11_0030F060(void) {
    s32 s1;
    u8 *s0;
    u32 *s2;
    u8 *s3;
    s32 s6;
    s32 s5;
    s32 s4;
    u32 a1;

    s1 = 0;
    func_L00_002FC980();
    if (D_L11_001BE5C0.count44 > 0) {
        s3 = (u8 *)D_001A79F0;
        s6 = 0xE29;
        s5 = 0xD54;
        s4 = 0xFA0;
        s2 = (u32 *)((u8 *)s3 + 0x18C);
        do {
            s0 = (u8 *)*s2;
            if (s0 != 0) {
                if (*(s16 *)(s0 + 0xAA) == 0xE29) {
                    *(u16 *)(s0 + 0x34) |= 0x800;
                }
            }
            if (*(s16 *)(s0 + 0xAA) == 0xD54) {
                func_002E64A0(s0);
            }
            if (s0 != 0) {
                if (*(s16 *)(s0 + 0xAA) == 0xFA0) {
                    a1 = *(u32 *)(s0 + 0x68);
                    if (a1 != 0) {
                        func_L00_00326048(s0, (u8 *)a1 + 0xC, 0x80AAAAD2, 0x80396464,
                                          0.061086535f);
                    }
                }
            }
            s1++;
            s2++;
        } while (s1 < *(s16 *)((u8 *)s3 + 0x44));
    }
    if (D_001A79F0 == 0xB) {
        return;
    }
    if (D_L11_001BE5C0.mode30 == 2) {
        func_L00_002E6CF0((void *)D_L11_0030FD58, 0);
    }
}
