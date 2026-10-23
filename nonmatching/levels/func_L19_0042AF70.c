/* func_L19_0042AF70 (232 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 232 bytes, the retail's size; 51 of the 58 words differ, the two
   guards, the list walk and the call are the retail's, the addresses are not.
   check.py (19_grelbin), with the source below:
     19_grelbin: instruction at +0x0 differs
     func_L19_0042AF70: 0 of 1 places match (src/levels/19_grelbin/L19_0042A860.c)

   What is measured and right:
   - the body is guarded by D_L19_001A8F00 == 2 and then by the resident byte at
     D_001A7A40 (0x001A7A40 is below the level base, so it is the boot's own
     byte, not a level symbol).
   - the list lives at D_L19_001BD740: the count is the short at +0x44 and the
     entries are the words at +0x18C; the loop reloads the count each round, so
     the source reads it in the loop condition.
   - the entry that carries the object's own id (the short at +0xAA) is handed to
     func_0029F978 with the table at D_L19_001B22E0, and the three headings at
     D_L19_001B22E0 + 0x20, +0x24 and +0x28 are set to 1.9f (0x3FF33333).
   - the third heading is published only when the byte at D_L19_001B22E0 + 1 is
     zero.

   What is left (the compiler-side wall, not a source shape):
   - the retail re-materialises every address inside the loop (`lui $v0, 0x1B;
     lbu $v0, 0x22E1($v0)` for the byte, `lui $at, 0x1B; swc1 $f20, 0x2300($at)`
     for the first heading), while this cc1 CSEs the symbol addresses into
     callee-saved registers and keeps them across the call in the loop. That is
     the wall recorded in docs/COMPILER-NOTES.md, "Two walls the source cannot
     move": the source shapes below were measured and none of them changes it.
   - with three separate symbols (D_L19_001B2300, D_L19_001B2304, D_L19_001B2308)
     the addresses come out in $s4, $s5, $s6, $s7 and $fp and the body grows to
     264 bytes; with one base symbol and offsets (what this draft uses) the
     three headings come out as one base plus offsets and the body is the
     retail's 232 bytes, but the stores are `swc1 $f20, 0x28($s0)` where the
     retail has three lui pairs.
   - declaring the three headings as separate *volatile* floats does give the
     retail's three `lui $at, 0x1B; swc1 $f20, 0x2300($at)` pairs, and the
     volatile byte gives the retail's `lui $v0, 0x1B; lbu $v0, 0x22E1($v0)`;
     but this cc1 then hoists the four address materialisations out of the
     loop into $s4..$s7 and the body grows to 252 bytes (264 bytes with the
     byte as a fifth symbol).  The volatility keeps the accesses in the loop
     but not the addresses.

   Tried and not enough: the three headings as separate symbols, as one symbol
   with offsets, the same with the byte volatile, the base symbol written as
   a local pointer, and the three headings as separate volatile floats with
   the byte as a fifth volatile symbol. */

extern int D_L19_001A8F00 __attribute__((sda));
extern unsigned char D_001A7A40;
extern char D_L19_001BD740[];
extern unsigned char D_L19_001B22E0[];
extern void func_0029F978(unsigned char *, unsigned int, unsigned char *);

void func_L19_0042AF70(char *obj)
{
    char *base;
    unsigned char *entry;
    int i;

    if (D_L19_001A8F00 == 2) {
        if (D_001A7A40 != 0) {
            base = D_L19_001BD740;
            for (i = 0; i < *(short *)(base + 0x44); i++) {
                entry = *(unsigned char **)(base + 0x18C + 4 * i);
                if (*(short *)(entry + 0xAA) == *(short *)(obj + 0xAA)) {
                    if (D_L19_001B22E0[1] == 0) {
                        func_0029F978(entry, 0, D_L19_001B22E0);
                        *(float *)(D_L19_001B22E0 + 0x20) = 1.9f;
                        *(float *)(D_L19_001B22E0 + 0x24) = 1.9f;
                        *(float *)(D_L19_001B22E0 + 0x28) = 1.9f;
                    }
                }
            }
        }
    }
}
