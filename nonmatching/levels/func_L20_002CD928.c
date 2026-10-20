/* func_L20_002CD928 (34964 bytes, 8741 instructions, level 20 only) -- NEAR MISS, not
   integrated.

   What this is: the level's big state machine.  A `switch` on a value read from the
   boot global D_00189E20 (+0x2294) with 149 possible values, 62 distinct bodies, and a
   common tail.  746 calls to 136 distinct functions, 873 float constants.

   State of the attempt: the C below has the right shape (the 149-way dispatch, the
   global reads, the epilogue) and the first body transcribed; the other 61 bodies are
   stubs.  tools/check.py func_L20_002CD928 --diff says

     20_yeedil: 576 bytes, expected 34964
     func_L20_002CD928: 0 of 1 places match (src/levels/20_yeedil/L20_002CD928.c)

   The first difference is the very first instruction: our frame is 0x60, retail's is
   0x1A0, because retail keeps ten GPRs (s0-s7, fp) and five FPRs (f20-f24) live
   across the calls and spills about forty floats to the stack.  The register
   allocation of a 8741-instruction function cannot be reproduced without the whole
   function, so this is not a matter of fixing a line or two.

   Measured, byte for byte, on the parts that are transcribed:
   - the dispatch: our ten instructions have the same opcode sequence as retail's
     (sltiu, beqz, lui, sll, addiu, addu, lw, jr, nop); the registers differ ($v0/$v1
     against $v1/$a0) and retail's branch delay slot holds `sw $v0,0x114($sp)` where
     ours holds `lbu $s5,0x43($s2)`, because retail spills the two saved values to the
     stack in the prologue and we keep them in registers.
   - the first body (cases 0,1,3,4,28,29,30,57,109,111,125, retail 0x002CD9B0): 25 of
     the first 60 instructions are identical (counting a jal to any symbol as equal),
     28 have the same opcode.  The first divergence is retail's `addiu $s2,$zero,0x1`
     (the int variable 1, materialised before the call) against our rematerialisation
     of the constant after the call.

   What the next worker should know (measured with the reconstructed compiler):

   1. THE JUMP TABLE.  The dispatch is GCC's own `casesi` expansion: `sltiu $v1,$a0,
      0x95; beqz $v1,default; lui $v0,%hi(T); sll $v1,$a0,2; addiu $v0,$v0,%lo(T);
      addu $v1,$v1,$v0; lw $a0,0($v1); jr $a0`.  The table T is D_L20_002B27E0, 149
      words of absolute case addresses, in the level's data section.
      A C `switch` cannot be used here: the compiler puts its jump table in the C
      object's .rdata, and tools/build.py loads only `obj(.text.func_X)` of every C
      object and discards the rest, so the table would not be in the image and the
      `lui` would point at a discarded section.  (Worse: check.py would still pass,
      because it reads the symbol's value out of the retail bytes and a compiler-local
      table symbol carries no address constraint.)
      A computed goto through the level's own table gives retail's instructions, but
      GCC then deletes every case body as unreachable: only labels whose address is
      taken (a `&&label` array) survive.  The C below uses both - `goto
      *D_L20_002B27E0[sel]` for the dispatch and a `static void * volatile jt[]` of
      `&&label`s that is never read, so the bodies stay and cost no code.  The volatile
      array lands in the C object's .data, which the build discards, so it is harmless.
      tools/build.py would need a change to place a compiler's .rdata at a fixed
      address before a plain `switch` can be used at all.

   2. THE LAYOUT IS THE SOURCE ORDER OF THE CASES.  With this compiler the bodies of a
      switch are laid out in the order the `case` labels appear in the source, not in
      the order of the case values, and not in a probability order (measured: a switch
      whose cases are written 148,147,...,0 comes out laid out 148,147,...,0, and the
      jump table still lists the cases by value).  Retail's layout therefore gives the
      original source order of the 62 bodies, which is what the table below records.
      A body is shared by several case values where the source wrote them one after
      the other.

   3. THE FILE NEEDS -G8.  Six small-data globals are reached through $gp
      (-0x7C60($gp) = 0x1A7390, -0x7600($gp) = 0x1A79F0, -0x6000($gp) = 0x1A8FF0,
      0xF10($gp) = 0x1AF000, 0x3AD8($gp) = 0x1B2AC8, 0x4748($gp) = 0x1B3738), so the
      body belongs in a `-g8.c` unit (L20_002CD928-g8.c) and not in
      L20_002CD928.c, which builds with -G0.

   4. THE 64-BIT GLOBAL.  Retail keeps the address of D_00189E20 as a 64-bit value:
      `lui $v0,%hi(D); daddu $s6,$v0,$zero` in the prologue and
      `addiu $s0,$s6,%lo(D)` (=-0x61E0) wherever the 32-bit address is wanted.  That
      is GCC's 64-bit `la`: it appears when the pointer's value is needed in 64 bits
      (measured: a pointer cast to unsigned long long gives `lui; daddu; addiu`, a
      pointer only used through 32-bit offsets gives `lui; addiu`).  The source passes
      64-bit arguments (the retail's `daddu $a1,$sp,$zero`, `daddu $a2,$s0,$zero`), so
      the prototypes of the callees matter to the register allocation.

   5. FRAME.  0x1A0, the saved GPRs at 0x120-0x168 (s0, s1, ..., s7, fp, ra) and the
      saved FPRs at 0x170-0x190 (f20, f21, f22, f23, f24, as 4-byte swc1 in descending
      order), the locals at 0x00-0x11F (about forty float spills, the two ints the
      epilogue compares at 0x114 and 0x118).

   6. THE EPILOGUE.  Both tests are "if the value changed, clear a flag":
        if (saved != D_00189E20[0x2298]) D_00189E20[0x1C0] = 0;
        if (state != obj[0x43])         D_00189E20[0x1C4] = 0;
      with `bnel` + the store in the delay slot, as the compiler emits it.

   The structure, from the retail (the jump table at 0x002B27E0 and the body map):

     0x002CD928  prologue: frame 0x1A0, the 64-bit address of D_00189E20 in s6,
                 obj = D_00189E20[0x2290] in fp, sel = D_00189E20[0x2294],
                 saved = D_00189E20[0x2298] and state = obj[0x43] spilled to
                 0x114($sp) and 0x118($sp)
     0x002CD980  the dispatch (see 1.)
     0x002CD9B0  the 62 bodies, in the source order (see the table)
     0x002D6154  the default body: one instruction, `addiu $v1,$s6,%lo(D)`
     0x002D6158  the epilogue (see 6.)
     0x002D6178  the restores and `jr $ra`

   The 62 bodies, the cases each one answers and its size in the retail:


    0x002CD9B0   1392 bytes  cases 0, 1, 3, 4, 28, 29, 30, 57, 109, 111, 125
    0x002CDF20    328 bytes  cases 124
    0x002CE068   3412 bytes  cases 50, 51, 52
    0x002CEDBC    120 bytes  cases 115
    0x002CEE34     68 bytes  cases 114
    0x002CEE78    444 bytes  cases 103, 127
    0x002CF034    712 bytes  cases 53, 54
    0x002CF2FC     48 bytes  cases 133
    0x002CF32C    380 bytes  cases 134
    0x002CF4A8    368 bytes  cases 47
    0x002CF618    168 bytes  cases 138, 139
    0x002CF6C0    256 bytes  cases 35
    0x002CF7C0    804 bytes  cases 36
    0x002CFAE4    236 bytes  cases 37
    0x002CFBD0   2032 bytes  cases 43
    0x002D03C0   1556 bytes  cases 20
    0x002D09D4   1100 bytes  cases 21, 131
    0x002D0E20   1408 bytes  cases 19
    0x002D13A0    336 bytes  cases 119
    0x002D14F0   1244 bytes  cases 31
    0x002D19CC    236 bytes  cases 34
    0x002D1AB8   1816 bytes  cases 2, 112
    0x002D21D0    840 bytes  cases 123
    0x002D2518    536 bytes  cases 46
    0x002D2730    868 bytes  cases 48
    0x002D2A94   3904 bytes  cases 39, 40, 41, 42, 62
    0x002D39D4    180 bytes  cases 23, 24
    0x002D3A88    172 bytes  cases 70, 71
    0x002D3B34    320 bytes  cases 25, 26
    0x002D3C74     24 bytes  cases 118
    0x002D3C8C    292 bytes  cases 6, 44
    0x002D3DB0    184 bytes  cases 116
    0x002D3E68    924 bytes  cases 130
    0x002D4204    596 bytes  cases 8
    0x002D4458   2028 bytes  cases 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 27, 56, 69, 72, 91, 102, 110, 129, 137, 146
    0x002D4C44    180 bytes  cases 22
    0x002D4CF8     36 bytes  cases 140
    0x002D4D1C    592 bytes  cases 98
    0x002D4F6C    164 bytes  cases 99
    0x002D5010     20 bytes  cases 60, 100
    0x002D5024    108 bytes  cases 101
    0x002D5090      8 bytes  cases 121
    0x002D5098     36 bytes  cases 120
    0x002D50BC     36 bytes  cases 122
    0x002D50E0    152 bytes  cases 63, 67
    0x002D5178    688 bytes  cases 77
    0x002D5428    148 bytes  cases 75
    0x002D54BC     84 bytes  cases 78
    0x002D5510     24 bytes  cases 65
    0x002D5528     68 bytes  cases 68
    0x002D556C    688 bytes  cases 64, 76
    0x002D581C    108 bytes  cases 66
    0x002D5888    364 bytes  cases 73, 74
    0x002D59F4    188 bytes  cases 141
    0x002D5AB0     84 bytes  cases 145
    0x002D5B04    232 bytes  cases 147
    0x002D5BEC    108 bytes  cases 148
    0x002D5C58    152 bytes  cases 143
    0x002D5CF0    800 bytes  cases 142
    0x002D6010    192 bytes  cases 144
    0x002D60D0    120 bytes  cases 55
    0x002D6148     12 bytes  cases 96, 97
    0x002D6154      0 bytes  cases 5, 32, 33, 38, 45, 49, 58, 59, 61, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 92, 93, 94, 95, 104, 105, 106, 107, 108, 113, 117, 126, 128, 132, 135, 136

     The 36 case values that are not in the table above (5, 32, 33, 38, 45, 49, 58,
     59, 61, 79-90, 92-95, 104-108, 113, 117, 126, 128, 132, 135, 136) have an empty
     body: they fall into the default body at 0x002D6154.

   The C below.  It compiles, it is the right shape, and it is the start of the
   transcription; the 61 stub bodies are where the work is.  The prototypes of the
   callees are guesses where the repo has none (26 of the 136 callees are already
   matched and their prototypes are in src/, the rest are guessed from the call sites).

*/


#include "common.h"

/* func_L20_002CD928 - the level's big state machine (34964 bytes, 8741 instructions).
 *
 * A near miss: the shape is right (the 149-way dispatch, the frame, the epilogue), the
 * bodies are not transcribed.  See nonmatching/levels/func_L20_002CD928.c for what was
 * measured and what blocks the match.
 *
 * The dispatch is the retail's own jump table, D_L20_002B27E0 (level 20 data, 149
 * entries of absolute case addresses).  A C `switch` cannot be used: the compiler puts
 * its jump table in the C object's .rdata, which tools/build.py discards, and the case
 * bodies would then not be the ones the table points at.  A computed goto through the
 * level's table gives the retail's instructions, but GCC then deletes every case body
 * as unreachable; the `jt` array below only exists to keep the labels alive (its
 * address is never taken, so it costs no code).
 */

extern char D_00189E20[];

extern void *D_L20_002B27E0[149];

extern u16 D_0018C750[];
extern int D_001A7390;
extern int D_001A79F0;
extern char D_L20_001BA1F0[];

extern void func_L00_002AA478(int, int);
extern void func_L00_002B54F8(float, float);
extern void func_L00_002B9F00(float, float, float);
extern void func_L00_002B39F0(long long, float);
extern void func_00283098(char *, void *, void *);
extern void func_L00_002B3EF8(int, float, float, float);
extern int func_L00_002CAF20(char *, int, int);

void func_L20_002CD928(void) {
    static void * volatile jt[62] = {
        &&b0, &&b1, &&b2, &&b3, &&b4, &&b5, &&b6, &&b7, &&b8, &&b9, &&b10, &&b11, &&b12, &&b13, &&b14, &&b15, &&b16, &&b17, &&b18, &&b19, &&b20, &&b21, &&b22, &&b23, &&b24, &&b25, &&b26, &&b27, &&b28, &&b29, &&b30, &&b31, &&b32, &&b33, &&b34, &&b35, &&b36, &&b37, &&b38, &&b39, &&b40, &&b41, &&b42, &&b43, &&b44, &&b45, &&b46, &&b47, &&b48, &&b49, &&b50, &&b51, &&b52, &&b53, &&b54, &&b55, &&b56, &&b57, &&b58, &&b59, &&b60, &&b61
    };
    unsigned char *g = D_00189E20;
    unsigned char *obj = *(unsigned char **)(g + 0x2290);
    int sel = *(int *)(g + 0x2294);
    int saved = *(int *)(g + 0x2298);
    unsigned char state = obj[0x43];
    unsigned char *base;
    float f20, f21, f0;
    int one;

    if ((unsigned)sel < 149) {
        goto *D_L20_002B27E0[sel];
    }
    base = g;
    goto done;

b0: /* cases 0, 1, 3, 4, 28, 29, 30, 57, 109, 111, 125 - retail 0x002CD9B0 */
    if (g[0x22B9] != 0) {
        func_L00_002AA478(15, 30);
    }
    if (g[0x1492] != 0) {
        func_L00_002B54F8(0.7f, 0.0f);
    } else {
        func_L00_002B54F8(0.5f, 1.0f / 30.0f);
    }
    f21 = 0.0f;
    f20 = 1.0f;
    one = 1;
    func_L00_002B9F00(3.7f, f21, 0.35f);
    func_L00_002B39F0(0, f20);
    if (*(int *)(g + 0x2294) == one) {
        goto b0_a64;
    }
    if (*(int *)(g + 0x2294) != 29) {
        goto b0_b2c;
    }
b0_a64:
    if (g[0x22B5] != 0) {
        union {
            long long l;
            float f;
        } tmp;
        float a, b, c;
        tmp.l = 0;
        tmp.f = f20;
        func_00283098((char *)(g + 0x190), &tmp, D_L20_001BA1F0);
        f0 = *(float *)(D_L20_001BA1F0 - 0x218);
        a = f20;
        b = f21;
        c = 2.97f;
        *(float *)(g + 0x1A0) = f0;
        func_L00_002B3EF8(0, a, b, c);
        if (g[0x22BB] != 0) {
            if (*(int *)(g + 0x1B8) == 120) {
                if (0xFFFEu < *(u16 *)(D_0018C750 + 0xD8)) {
                    *(u16 *)(D_0018C750 + 0xD8) = (u16)(D_001A7390 + 1);
                }
                if (*(int *)(D_0018C750 + 0xDC) < D_001A7390) {
                    *(int *)(D_0018C750 + 0xDC) = D_001A7390;
                }
                *(int *)(D_0018C750 + 0xE0) |= (1 << (int)D_001A79F0) | 0x80000000;
            }
        }
    }
b0_b2c:
    if (*(int *)(g + 0x2294) == 3) {
        if (func_L00_002CAF20((char *)obj, *(int *)(g + 0x2294), 0) != 0) {
            base = g;
            goto done;
        }
    }
    /* the retail carries on with the g[0x2294] == 4 sub-block at 0x002CDB5C */
    base = g;

b1: /* cases 124 - retail 0x002CDF20 */
    base = g;
    goto done;

b2: /* cases 50, 51, 52 - retail 0x002CE068 */
    base = g;
    goto done;

b3: /* cases 115 - retail 0x002CEDBC */
    base = g;
    goto done;

b4: /* cases 114 - retail 0x002CEE34 */
    base = g;
    goto done;

b5: /* cases 103, 127 - retail 0x002CEE78 */
    base = g;
    goto done;

b6: /* cases 53, 54 - retail 0x002CF034 */
    base = g;
    goto done;

b7: /* cases 133 - retail 0x002CF2FC */
    base = g;
    goto done;

b8: /* cases 134 - retail 0x002CF32C */
    base = g;
    goto done;

b9: /* cases 47 - retail 0x002CF4A8 */
    base = g;
    goto done;

b10: /* cases 138, 139 - retail 0x002CF618 */
    base = g;
    goto done;

b11: /* cases 35 - retail 0x002CF6C0 */
    base = g;
    goto done;

b12: /* cases 36 - retail 0x002CF7C0 */
    base = g;
    goto done;

b13: /* cases 37 - retail 0x002CFAE4 */
    base = g;
    goto done;

b14: /* cases 43 - retail 0x002CFBD0 */
    base = g;
    goto done;

b15: /* cases 20 - retail 0x002D03C0 */
    base = g;
    goto done;

b16: /* cases 21, 131 - retail 0x002D09D4 */
    base = g;
    goto done;

b17: /* cases 19 - retail 0x002D0E20 */
    base = g;
    goto done;

b18: /* cases 119 - retail 0x002D13A0 */
    base = g;
    goto done;

b19: /* cases 31 - retail 0x002D14F0 */
    base = g;
    goto done;

b20: /* cases 34 - retail 0x002D19CC */
    base = g;
    goto done;

b21: /* cases 2, 112 - retail 0x002D1AB8 */
    base = g;
    goto done;

b22: /* cases 123 - retail 0x002D21D0 */
    base = g;
    goto done;

b23: /* cases 46 - retail 0x002D2518 */
    base = g;
    goto done;

b24: /* cases 48 - retail 0x002D2730 */
    base = g;
    goto done;

b25: /* cases 39, 40, 41, 42, 62 - retail 0x002D2A94 */
    base = g;
    goto done;

b26: /* cases 23, 24 - retail 0x002D39D4 */
    base = g;
    goto done;

b27: /* cases 70, 71 - retail 0x002D3A88 */
    base = g;
    goto done;

b28: /* cases 25, 26 - retail 0x002D3B34 */
    base = g;
    goto done;

b29: /* cases 118 - retail 0x002D3C74 */
    base = g;
    goto done;

b30: /* cases 6, 44 - retail 0x002D3C8C */
    base = g;
    goto done;

b31: /* cases 116 - retail 0x002D3DB0 */
    base = g;
    goto done;

b32: /* cases 130 - retail 0x002D3E68 */
    base = g;
    goto done;

b33: /* cases 8 - retail 0x002D4204 */
    base = g;
    goto done;

b34: /* cases 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 27, 56, 69, 72, 91, 102, 110, 129, 137, 146 - retail 0x002D4458 */
    base = g;
    goto done;

b35: /* cases 22 - retail 0x002D4C44 */
    base = g;
    goto done;

b36: /* cases 140 - retail 0x002D4CF8 */
    base = g;
    goto done;

b37: /* cases 98 - retail 0x002D4D1C */
    base = g;
    goto done;

b38: /* cases 99 - retail 0x002D4F6C */
    base = g;
    goto done;

b39: /* cases 60, 100 - retail 0x002D5010 */
    base = g;
    goto done;

b40: /* cases 101 - retail 0x002D5024 */
    base = g;
    goto done;

b41: /* cases 121 - retail 0x002D5090 */
    base = g;
    goto done;

b42: /* cases 120 - retail 0x002D5098 */
    base = g;
    goto done;

b43: /* cases 122 - retail 0x002D50BC */
    base = g;
    goto done;

b44: /* cases 63, 67 - retail 0x002D50E0 */
    base = g;
    goto done;

b45: /* cases 77 - retail 0x002D5178 */
    base = g;
    goto done;

b46: /* cases 75 - retail 0x002D5428 */
    base = g;
    goto done;

b47: /* cases 78 - retail 0x002D54BC */
    base = g;
    goto done;

b48: /* cases 65 - retail 0x002D5510 */
    base = g;
    goto done;

b49: /* cases 68 - retail 0x002D5528 */
    base = g;
    goto done;

b50: /* cases 64, 76 - retail 0x002D556C */
    base = g;
    goto done;

b51: /* cases 66 - retail 0x002D581C */
    base = g;
    goto done;

b52: /* cases 73, 74 - retail 0x002D5888 */
    base = g;
    goto done;

b53: /* cases 141 - retail 0x002D59F4 */
    base = g;
    goto done;

b54: /* cases 145 - retail 0x002D5AB0 */
    base = g;
    goto done;

b55: /* cases 147 - retail 0x002D5B04 */
    base = g;
    goto done;

b56: /* cases 148 - retail 0x002D5BEC */
    base = g;
    goto done;

b57: /* cases 143 - retail 0x002D5C58 */
    base = g;
    goto done;

b58: /* cases 142 - retail 0x002D5CF0 */
    base = g;
    goto done;

b59: /* cases 144 - retail 0x002D6010 */
    base = g;
    goto done;

b60: /* cases 55 - retail 0x002D60D0 */
    base = g;
    goto done;

b61: /* cases 96, 97 - retail 0x002D6148 */
    base = g;
    goto done;

    /* the retail cases 5, 32, 33, 38, 45, 49, 58, 59, 61, 79, 80, 81, 82, 83, 84,
       85, 86, 87, 88, 89, 90, 92, 93, 94, 95, 104, 105, 106, 107, 108, 113, 117,
       126, 128, 132, 135, 136 have an empty body and fall into the default body
       at 0x002D6154 */
done:
    if (saved != *(int *)(base + 0x2298)) {
        *(int *)(base + 0x1C0) = 0;
    }
    if (state != *(unsigned char *)(obj + 0x43)) {
        *(int *)(base + 0x1C4) = 0;
    }
}

