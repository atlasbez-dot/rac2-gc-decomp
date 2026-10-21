/* Near miss from src/levels/01_oozla/L01_002BEB90-g8.c: the build refuses this body at its
   place — 144 bytes, expected 156. Kept as a starting point;
   not linked, not counted. */

/* Standalone declarations recovered from src/levels/01_oozla/L01_002BEB90-g8.c. */
extern int D_L01_001B2088 __attribute__((sda));

extern int D_L01_001AEC38 __attribute__((sda));

extern unsigned char D_L01_001A7A6F;

extern int D_L01_001A907C;

extern void func_3558E0(int, int, int);

extern void func_31BEC0(int, int);

void func_L01_00378A80(char *arg0) {
    if (*(unsigned char *)(arg0 + 0x20) == 0)
        *(unsigned char *)(arg0 + 0x30) = 0xFF;
    if (D_L01_001B2088 == 2)
        D_L01_001AEC38 = 0x42;
    if (D_L01_001B2088 < 6)
        return;
    if (D_L01_001AEC38 > 0)
        return;
    if (D_L01_001A7A6F != 0)
        return;
    D_L01_001A7A6F = 1;
    func_3558E0(1, 0, 0);
    func_31BEC0(0x1233, -1);
    D_L01_001A907C = 1;
}

/* Wave 24 (worker 09) -- NEAR MISS, 148 bytes against 156.
   The retail reads the level's mode word (D_L01_001B2088, 0x1B2088) twice: once
   $gp-relative (lw $v1, 0x3098($gp), in the delay slot of the first branch) and
   once as a lui/%lo pair (lui $v1, %hi(D_1B2088) ; lw $v1, %lo(D_1B2088)($v1)).
   One C name cannot give both forms: the `sda' attribute gives the $gp form for
   every access and a `nosda' declaration gives the lui/%lo form for every
   access.  With the second access named D_001B2088 (the same address, nosda) the
   two forms appear, and the first 9 instructions are instruction-exact
   (including the $gp-relative load in the delay slot of the first branch).
   What is left: retail materialises the %hi into the destination register of
   the load (lui $v0, 0x1A ; lbu $v0, 0x7A6F($v0)) and leaves it after the
   store, while this cc1 rematerialises it into a scratch register ($v1) and
   hoists the lui above the store; the same for the D_001A907C store, where
   retail uses $at for the %hi.  D_001A7A6F and D_001A907C need the `nosda'
   attribute to get the lui/%lo form at all.

   Checked with: python3 tools/check.py func_L01_00378A80 --diff
   Last line: func_L01_00378A80: 0 of 1 places match (src/levels/01_oozla/L01_002BEB90-g8.c) */
extern int D_001B2088 __attribute__((nosda));

extern unsigned char D_001A7A6F __attribute__((nosda));

extern int D_001A907C __attribute__((nosda));

void func_L01_00378A80_w24(char *arg0)
{
    int v1;

    if (*(unsigned char *)(arg0 + 0x20) != 0) {
        v1 = D_L01_001B2088;
    } else {
        v1 = D_001B2088;
        *(unsigned char *)(arg0 + 0x30) = 0xFF;
    }
    if (v1 == 2) {
        D_L01_001AEC38 = 0x42;
    }
    if (v1 < 6) {
        return;
    }
    if (D_L01_001AEC38 > 0) {
        return;
    }
    if (D_001A7A6F != 0) {
        return;
    }
    D_001A7A6F = 1;
    func_3558E0(1, 0, 0);
    func_31BEC0(0x1233, -1);
    D_001A907C = 1;
}
