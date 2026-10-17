/* 0 of 1 places match - last line: 20_yeedil: 184 bytes, expected 176
   Shape recovered in full: one two-argument float helper scaled by 210000.0f, the frame's
   float kept in $f20 across the second helper (whose result rides in $t0, this ABI's fifth
   integer argument), then a `== 0xB5A` arm on the s16 at arg0+0xAA selecting between the
   $gp word D_L20_001B1FC0 and the absolute D_L20_001B1FC4, or the absolutes
   D_L20_001B1FC8 / D_L20_001B1FCC, and one six-argument call. Retail materialises each of
   the absolutes with its own `lui` + `lw`, so they are `nosda` scalars: a `s32[3]` spelling
   reaches all three through one shared base and costs two more words (204 bytes), and a
   plain scalar declaration puts them through $gp. Two words over: retail's bne delay slot
   carries the `$gp` load (`lw $v0,0x2FD0($gp)`) where this cc1 puts the first half of the
   absolute address, and the pair[2] stores retail keeps on the stack are what make the
   branch survive at all. */
#include "common.h"

extern f32 D_L20_001B1FD0 __attribute__((sda));

extern f32 D_L20_001B1FD4 __attribute__((nosda));

extern s32 D_L20_001B1FC0 __attribute__((sda));

extern s32 D_L20_001B1FC4 __attribute__((nosda));

extern s32 D_L20_001B1FC8 __attribute__((nosda));

extern s32 D_L20_001B1FCC __attribute__((nosda));

extern char D_L20_001A8F20[];

extern f32 func_002A7878(f32, f32);

extern s32 func_002A7820(s32, s32);

extern void func_002BDBC0(char *, char *, s32, s32, s32, f32);

/* Samples the two shared angles into one 210000.0f-scaled float, picks the object or the
   shared word pair by the record's 0xAA id, and passes the quad's 0x10 block, the level's
   0x001A8F20 table and both pairs to func_002BDBC0 with a 20/80 draw. */
void func_L20_0043F460(char *arg0)
{
    f32 f;
    s32 t;
    s32 pair[2];

    f = func_002A7878(D_L20_001B1FD0, D_L20_001B1FD4) * 210000.0f;
    t = func_002A7820(0x14, 0x50);
    if (*(s16 *)(arg0 + 0xAA) == 0xB5A) {
        pair[0] = D_L20_001B1FC0;
        pair[1] = D_L20_001B1FC4;
    } else {
        pair[0] = D_L20_001B1FC8;
        pair[1] = D_L20_001B1FCC;
    }
    func_002BDBC0(arg0 + 0x10, D_L20_001A8F20, D_L20_001B1FC0,
                  D_L20_001B1FC4, t, f);
}
