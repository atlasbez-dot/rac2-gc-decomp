#include "include_asm.h"

#include "common.h"

/* Near miss: the body is decoded, the frame and the loop's shape are not.
   Needs a grouped quadword copy for the four 16-byte copies
   (-frac2-qcopy in a -G0 unit).

   What is recovered from the retail bytes:
     - the two saved quads (the object's 0x10 and 0xF0 vectors) are kept on the
       stack at 0x00 and 0x10 and written back before the last call;
     - the state's record is picked with the word at 0xC8 of the state, scaled by
       128 (the retail's `sll $a0,$a0,7`), so it indexes the record array
       D_L07_001B23CC; the record's 0x30 and 0x70 quads are written to the
       object's 0x10 and 0xF0;
     - func_2E4B70 is called with the object's 0xC0 and 0xF0, and func_3196B8
       with the object, the state's 0x1B0, 0x40, -1, the word at 0xCC of the
       state, -1, 7 and 0;
     - the walk: the state's records are 0x50 apart, the id is the halfword at
       0x1F8, the table D_L07_001B2954 is indexed with the id shifted left by
       five, the byte compared is the one at 0x1D of the entry and the value it
       is compared against is the byte at 0x227E7F; a match writes the current
       slot (state + 0x15B0, stepping by 0x20) into the record's 0x1F0 word,
       clears the byte at 0x1FE and counts the match; eight matches stop the
       walk and the walk ends at state + 0x1400.

   What is not recovered: the frame (the retail's is 0x40 with $s0-$s2 and $ra
   saved from 0x20) and the loop's shape - the retail increments the state
   pointer itself, tests it against state + 0x1400 with a `slt`/`bnel` and counts
   the matches with an `slti`/`beqz` pair.

   Measured (tools/check.py func_L07_00410588 --diff): not matched; the frame is
   0x30 here against the retail's 0x40 and the saved registers differ.
*/

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    u8 pad00[0x38];
    f32 f38;
    u8 rest38[128 - 0x3C];
} SibRec128;

extern SibRec128 *D_L07_001B23CC;

extern u8 *D_L07_001B2954;

extern u8 D_L07_00227E7F;

extern void func_2E4B70(u8 *a0, void *a1);

extern void func_3196B8(u8 *a, u8 *b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);

void func_L07_00410588(u8 *a0)
{
    u8 *s0;
    u8 *s1;
    u8 *s2;
    TI128 save0;
    TI128 save1;
    SibRec128 *rec;
    u8 *out;
    u8 *p;
    u8 *end;
    s32 n;

    s2 = a0;
    s0 = *(u8 **)(s2 + 0x68);
    save0 = *(TI128 *)(s2 + 0x10);
    save1 = *(TI128 *)(s2 + 0xF0);
    rec = &D_L07_001B23CC[*(s32 *)(s0 + 0xC8)];
    *(TI128 *)(s2 + 0x10) = *(TI128 *)((u8 *)rec + 0x30);
    *(TI128 *)(s2 + 0xF0) = *(TI128 *)((u8 *)rec + 0x70);
    func_2E4B70(s2 + 0xC0, s2 + 0xF0);
    func_3196B8(s2, s0 + 0x1B0, 0x40, -1, *(s32 *)(s0 + 0xCC), -1, 7, 0);
    n = 0;
    out = s0 + 0x15B0;
    end = s0 + 0x1400;
    for (p = s0; p < end; p += 0x50) {
        if (*(u8 *)(D_L07_001B2954 + ((*(s16 *)(p + 0x1F8)) << 5) + 0x1D) == D_L07_00227E7F) {
            *(u32 *)(p + 0x1F0) = out;
            out += 0x20;
            *(u8 *)(p + 0x1FE) = 0;
            n++;
            if (n == 8) {
                break;
            }
        }
    }
    *(TI128 *)(s2 + 0x10) = save0;
    *(TI128 *)(s2 + 0xF0) = save1;
    func_2E4B70(s2 + 0xC0, s2 + 0xF0);
}
