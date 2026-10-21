/* Near miss: func_L12_00413CE0 (src/levels/12_todano/L12_00398E50.c), 444 bytes against retail's
   452. Compile it as a -g8 file (it reads D_L12_001B1840 through $gp outside a delay slot, and
   D_L12_001B2EB8, the group count, through $gp in a delay slot).

   Everything matches word for word at its place except the 16-byte copy of the first point of the
   path list (table[state+0x2C0] + 0x10) into the stack vector, which is the 128-bit copy wall of
   docs/COMPILER-NOTES.md ("The 128-bit copy wall is a cost tie in the CSE"):

     retail:  lw v1,0(a0) ; addiu v1,v1,0x10 ; lq v0,0(v1) ; sq v0,0(sp) ; lbu a0,0x21(s4) ...
     this:    lw a2,0(v1) ; ... lbu a0,0x21(s4) ... lq v0,0x10(a2) ... sq v0,0(sp)

   The folded displacement removes the `addiu` (one word, and the loop-head alignment `nop` that
   goes with it: the 8 bytes), and the schedule of the front moves with it: this build hoists the
   `lbu` of the group byte and the second table address above the sq, retail keeps them after it,
   which also changes a few registers of the front (a2/v1 for a0/v1, a1 for v0 as the high half
   kept in s6). Measured in scratch copies (not allowed in src/): with the pair written as one
   volatile asm with a memory clobber (`lq $2,0(src)` / `sq $2,0(dst)`) the same C is exact, 113
   of 113 words, check.py OK; with the lq as an asm on a register address and the sq as a plain
   "=m" store the size is exact (452) but the `lbu` is hoisted again (100 of 113). So the pair in
   retail behaves as a barrier with materialised addresses, which is what an inline-asm copy
   macro does and a C access never does. The id-list walk, the best/bestd initialisation after the
   copy (that is what gives s5 = best, s6 = high half of the second table), the PathState member
   stores (which let the scheduler lift the $gp halfword load D_L12_001B1840 above the stores, as
   retail has it) and the second names are all right.

   Tried for the copy, all folded: the one-line cast copy below; a pointer local `u8 *pos =
   list + 0x10`; a struct with the TI128 as a member (`list->first`); a TI128 local; a pointer that
   takes two values at a join (materialises the address, but changes the allocation and adds the
   join). None of the escapes in the notes is a plain spelling here: the copy sits right after the
   `-1` test, with no join, loop or volatile between the pointer and the load.

   Would unblock it: nothing in plain C. A compiler-side tie-break in find_best_addr (gcc/cse.c)
   would give the unfolded addresses but not the ordering; retail's copy was most likely an asm
   macro. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));

extern u16 *D_L12_001FB960[];

/* The path-follower state of an entity: the record fields the nearest-entity hand-over touches. */
typedef struct {
    u8 pad00[0x2B0];
    s32 f2B0;
    s32 f2B4;
    s32 f2B8;
    s32 f2BC;
    s32 f2C0;
    u8 pad2C4[0x2D0 - 0x2C4];
    s32 f2D0;
    s32 f2D4;
    u8 pad2D8[0x2DC - 0x2D8];
    s32 f2DC;
    u16 f2E0;
    u8 pad2E2[0x2EA - 0x2E2];
    u8 f2EA;
    u8 pad2EB[0x302 - 0x2EB];
    u8 f302;
    u8 f303;
} PathState;

extern u8 *D_L12_001B2E9C_base[3] __asm__("D_L12_001B2E9C") __attribute__((sda));

extern s32 D_L12_001B2EB8;

extern u16 D_L12_001B1840_h __asm__("D_L12_001B1840") __attribute__((sda));

extern u8 *D_L12_001FEAC0[];

extern f32 func_2F1B20(void *a, void *b);

/* Hands the object's path state to the nearest eligible entity of its group. */
void func_L12_00413CE0(u8 *a0)
{
    PathState *state = *(PathState **)(a0 + 0x68);
    u8 *best;
    f32 bestd;
    f32 vec[4];
    u16 *p;
    u8 *e;
    PathState *sub;
    f32 d;

    if (state->f2C0 != -1) {
        *(TI128 *)vec = *(TI128 *)(D_L12_001FEAC0[state->f2C0] + 0x10);
        best = 0;
        bestd = 100000.0f;
        for (p = D_L12_001FB960[a0[0x21]];
             a0[0x21] != 0xFF && a0[0x21] <= D_L12_001B2EB8 && p != 0 &&
             ((p != 0 && (s16)p[-1] >= 0) || p == D_L12_001FB960[a0[0x21]]);
             p++) {
            e = D_L12_001B2E9C_base[0] + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            sub = *(PathState **)(e + 0x68);
            d = func_2F1B20(e + 0x10, vec);
            if (sub != 0 && (sub->f302 & 1)) {
                if (d < bestd) {
                    bestd = d;
                    best = e;
                }
            }
        }
        if (best != 0) {
            PathState *dst = *(PathState **)(best + 0x68);

            dst->f2B0 = state->f2B0;
            dst->f2B4 = state->f2B4;
            dst->f2B8 = state->f2B8;
            dst->f2BC = state->f2BC;
            dst->f2C0 = state->f2C0;
            dst->f2D0 = state->f2D0;
            dst->f2D4 = state->f2D4;
            dst->f2E0 = D_L12_001B1840_h;
            dst->f2DC = state->f2C0;
            dst->f2EA = 1;
            dst->f302 = 2;
            dst->f303 = state->f303;
        }
    }
}
