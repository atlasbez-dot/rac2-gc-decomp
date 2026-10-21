#include "include_asm.h"

/* Near miss: nonmatching/levels/func_L20_002D6488.c - the body needs -G8 (it
   reaches three globals through $gp), so it belongs in a sibling unit of its
   own, src/levels/20_yeedil/L20_002D6488-g8.c; the attempt and the note are
   in nonmatching/. The note there explains the retail's split address (the
   %hi half in a callee-saved register, the address re-made at every use),
   the C spelling that produces it (a SECOND ASSIGNMENT of the same symbol
   after a nested block, with the global used more than once), the frame
   (0x80 only when 15.37f is assigned inside the object-loop block) and what
   is still missing: the retail's register order. */
INCLUDE_ASM("asm/levels", func_L20_002D6488);

/* Not attempted: nonmatching/levels/func_L20_002D7730.c holds a map of this
   body (19548 bytes, 4887 instructions, 278 blocks, 238 calls, no loop; the
   dispatch through the level's own jump table jtbl_002B2A40, the join points
   with their predecessor counts, the exits, the callees, the $gp accesses,
   and the -G8 unit it needs). */
INCLUDE_ASM("asm/levels", func_L20_002D7730);

extern unsigned char D_L20_0018C0D4;

extern void func_L20_002D7730(int a0, int a1);

/* Picks the variant of the shared loader the current game state selects. */
void func_L20_002DC390(int a0)
{
    int a1 = (a0 != 0) ? 2 : 1;

    switch (D_L20_0018C0D4) {
    case 0:
        func_L20_002D7730(0, a1);
        break;
    case 1:
        func_L20_002D7730(0x3F, a1);
        break;
    case 4:
        func_L20_002D7730(0x8D, a1);
        break;
    }
}
