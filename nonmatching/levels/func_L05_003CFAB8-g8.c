/* Draft (best attempt) for func_L05_003CFAB8 (212 bytes, 2 places) - NOT a match.
   The body is recovered: 48 of the 53 instructions are byte-identical to retail in
   both places (level 05 at 0x3CFAB8, level 25 at 0x3C8758), only the last five
   differ:

     retail   addiu $v0, $s1, -0x140 | addiu $v1,$zero,0x1E/0x3C |
              sw $zero,0x16C($v0) | swc1 $f0,0x160($v0) | sw $v1,0x168($v0)
     ours     addiu $a0, $s1, -0x140 | addiu $v0,$zero,0x1E/0x3C |
              sw $v0,0x168($a0) | swc1 $f0,0x160($a0) | sw $zero,0x16C($a0)

   So the two differences are the register the state pointer and the small counter
   get ($v0/$v1 in retail, $a0/$v0 here) and the order of the three stores: the
   scheduler puts the constant store last here, retail has it first.

   Measured with the game compiler (-O2 -G8 -ffunction-sections):
   - the $gp-relative reach table at $gp+0xB78 needs this -G8 unit (the same
     table the sibling func_L05_003CF9C8 reads, so D_L05_001AFB68 is reused);
   - with -fno-schedule-insns the three stores keep the source order (which then
     matches retail) but the earlier part of the body changes (the `la`/sll/lui
     order and the register allocation), so that flag is not the answer;
   - all six orders of the three stores, the struct-field and the cast spelling,
     the declaration order, the if/else and the ternary form of the two values,
     and putting the stores in both branches were tried: with the values in the
     branches the constant store always ends up last in the merged block.
   - the same wall is recorded for the sibling func_L05_003CFB90 (a rotation of
     three constant stores) and for func_L05_004157B0, which was solved there by
     changing the source order of the stores.

   The state block is at level 05's 0x1BF96C0 (0x1BF9200 in level 25) and the
   struct pointer is that block minus 0x140; the two values are the cone (0.05f
   for id 0x955, 0.15f otherwise) and a counter (0x1E or 0x3C). */

extern int func_L05_003CFC28(int);
extern void func_L05_003CFB90(char *, char *);
extern float func_00282E48(char *, char *);
extern void func_002E5DA0(int, int, char *, int);

extern float D_L05_001AFB68 __attribute__((sda));
extern char D_L05_001BF96C0[];

struct S_L05_003CFAB8 {
    char pad0[0x160];
    float f160;
    int f164;
    int f168;
    int f16C;
};

void func_L05_003CFAB8(char *a0)
{
    char *s0 = a0;
    char *s1;
    struct S_L05_003CFAB8 *t;
    float f20;
    float f0;
    int v1;
    int idx;

    idx = func_L05_003CFC28(*(short *)(s0 + 0xAA));
    f20 = *(float *)((char *)&D_L05_001AFB68 + 4 * idx);
    s1 = D_L05_001BF96C0;
    if (func_00282E48(s0 + 0x10, s1) <= f20) {
        if (*(short *)(s0 + 0xAA) != 0x956) {
            func_L05_003CFB90(s0, s1);
            func_002E5DA0(7, 0, s0, 0xFBF);
            t = (struct S_L05_003CFAB8 *)(s1 - 0x140);
            if (*(short *)(s0 + 0xAA) == 0x955) {
                f0 = 0.05f;
                v1 = 0x1E;
            } else {
                f0 = 0.15f;
                v1 = 0x3C;
            }
            t->f16C = 0;
            t->f160 = f0;
            t->f168 = v1;
        }
    }
}
