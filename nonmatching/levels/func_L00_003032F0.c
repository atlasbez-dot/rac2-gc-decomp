/* 0 of 27 places match - last line: 00_aranos_tutorial: instruction at +0x8 differs.
   SIZE IS EXACT (148 / 148, 37 instructions) and the whole body is instruction-identical
   apart from ONE register: this cc1 materialises the state base straight into the register
   the slow arm keeps live (`lui $v0,%hi` / `addiu $a3,$v0,%lo` / `lw $v1,0x1C($a3)`), where
   retail materialises into $v0 for the guard (`lui $v0,0x1D` / `addiu $v0,$v0,-0x6CC0` /
   `lw $v1,0x1C($v0)`) and only then copies for the loop (`daddu $a3,$v0,$zero`, in the slow
   arm just before `daddu $a2,$v1,$zero`). Everything else lines up: the shared `n` load
   hoisted into the `bnez` delay slot, both three-nop loop bodies, the fast arm's
   pre-offset `addiu $v0,$v0,0x3A` walker with `sh $a0,0x0($v0)` / `addiu $v0,$v0,0x40`,
   the slow arm's `lh 0x3A` / `lw 0x14` / `sll 1` / `addu` / `lhu` / `sh 0x3A`, and the
   two `sh` stores around the counter loop.
   Two shapes were measured: `Rec *p` in both arms (140 bytes, the fast arm loses the
   pre-offset walker) and `s16 *q = &base->f3A` in the fast arm + `TutorialState *st` with a
   second counter in the slow arm (148 bytes, the difference above). Unblocking needs the base
   address to stay live in $v0 across the `bnez`.
   Below: the whole -G8 sibling source that measures 148, declarations included. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

typedef struct {
    u8 pad0[0x14];
    u16 *f14;
    u8 pad1[4];
    s32 f1C;
} TutorialState;

typedef struct {
    u8 pad0[0x3A];
    s16 f3A;
    u8 pad1[4];
} Rec;

extern TutorialState D_L00_001C9340;
extern Rec *D_L00_001B24D0[1] __attribute__((sda));
extern s32 D_L00_001B24D4[1] __attribute__((sda));

void func_L00_003032F0(void)
{
    Rec *p;
    s16 *q;
    s32 n;
    s32 count;
    TutorialState *st;

    if (D_L00_001C9340.f1C == 0) {
        n = D_L00_001B24D4[0];
        if (n <= 0)
            return;
        q = &D_L00_001B24D0[0]->f3A;
        do {
            *q = 0x7F80;
            q = (s16 *)((u8 *)q + 0x40);
            n--;
        } while (n != 0);
    } else {
        n = D_L00_001B24D4[0];
        if (n <= 0)
            return;
        p = D_L00_001B24D0[0];
        st = &D_L00_001C9340;
        count = n;
        do {
            p->f3A = st->f14[p->f3A];
            p = (Rec *)((u8 *)p + 0x40);
            count--;
        } while (count != 0);
    }
}
