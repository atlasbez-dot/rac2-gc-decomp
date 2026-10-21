/* Near miss from src/levels/07_siberius/L07_003F4578-g8.c: the build refuses this body at its
   place — instruction at +0x30 differs. Kept as a starting point;
   not linked, not counted. */

/* Standalone declarations recovered from src/levels/07_siberius/L07_003F4578-g8.c. */
typedef unsigned char      u8;

typedef signed int         s32;

extern u8 *D_L07_001B22DC __attribute__((sda));

extern void func_317520(u8 *a, u8 *b, u8 *c, u8 *d, u8 *e, u8 *f);

void func_L07_0040F6B8(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 *ids = (s32 *)(p + 0xA8);
    u8 *b = p + 0x160;
    u8 *c = p + 0x120;
    s32 i = 3;

    while (i >= 0) {
        if (*ids != -1) {
            u8 *e = D_L07_001B22DC + (*ids << 8);
            func_317520(e, a0, e + 0x10, e + 0xF0, c, b);
        }
        b += 0x10;
        c += 0x10;
        i--;
        ids++;
    }
}

/* --- wave 24, worker 04 (2026-10-21) --------------------------------------------
   Re-measured: 164 bytes, 34 of 41 words identical; the fault is that this cc1
   rotates the loop.  Retail keeps the id load at the top of the body and the
   three pointer increments at the bottom, with a plain `bgez` branching back
   over them; ours rotates the loop: the id load moves into the delay slot of
   the back branch (`bgezl`), the increments move to the top of the body and the
   three pointers change registers.
   What I added to the measurements:
   - the ids are the words at state+0xA8, the third and fourth arguments of
     func_317520 are state+0x120 and state+0x160, and the first argument is
     D_L07_001B22DC + (id << 8) (the $gp global at 0x32EC).
   - the for, do-while, while and goto spellings of the loop all canonicalise
     into the same rotated form here; the increments' order (0x160, 0x120, then
     the id pointer) matches retail.
   Last check.py line: "07_siberius: instruction at +0x30 differs". */
