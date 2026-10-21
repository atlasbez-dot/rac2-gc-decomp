/* func_L11_004566C0 (632 bytes, 1 place: 11:004566C0) -- NEAR MISS, not integrated.
   This C compiles to 620 bytes against retail's 632 in a -G8 unit (it reads the group count and
   three floats through $gp, so it belongs in L11_00453358-g8.c). At the mnemonic level it is 155
   instructions against retail's 158 and five edits apart; the vector set-up, the walk (unrotated:
   `b` to the bottom test, the hi half of the table address kept in a saved register, 0xFF and the
   lo half rebuilt in the test, the group word re-read at each test), the eleven calls and their
   argument order, the float constants and the FPR split (0.017453294f in $f21, the range times it
   in $f20, `mov.s $f12,$f20 ; bc1f ; neg.s $f12,$f12` for the signed argument) are retail's.
   What it is: it asks the visibility probe func_00283DB8 about a 16-byte copy of {x, y, z, 2.0}
   (the object's +0x10 position) with radius 128.0; when that is positive and the state's group
   word (+0x244) is not -1 it walks the group's id list (D_L11_001FC420) for the first entity that
   func_L02_003D7300 accepts, that lies closer than D_L11_001B1D94 and inside D_L11_001B1D98 degrees of the
   object's heading (+0xF8). It then builds the direction vector at sp+0x10 (func_00282CF0), turns
   it by +-D_L11_001B1D9C degrees about obj+0xE0 (func_002ACEC0, sign from func_00283BE0, func_00282CC0),
   hands it to func_L11_00456070 with the state float at +0x134 parked on 0.0001, and returns 1;
   0 when the probe fails, the group is -1, the list ends or an entity pointer is 0.
   What differs (12 bytes, three instructions):
   1. The 128-bit zero of the local vector. Retail: `por $v0,$zero,$zero` (the MMI word 0x700014A9)
      at +0x4, hoisted by sched2 above the whole prologue, and `sq $v0,0x10($sp)` at +0x40. Here
      rac2_fold_zero_ti_store turns the pair into `sq $zero,0x10($sp)` (the zero register is dead
      after its only store and reload puts the por directly in front of the sq), and the
      `lui $at,0x4000 ; mtc1 $at,$f3` pair for 2.0f moves up to +0x4. This is the known zero-TI wall
      (func_L20_0039BB18, func_L23_00422798: the por only survives a zero that feeds two stores,
      and a store of a pseudo that cse proves zero is folded back to the constant), so no spelling of
      this body can reach the por. The clear itself is `*(TI128 *)vec = 0` followed by the four float
      stores, which gives retail's order `sq`, `swc1` x4, `lq`, `sq` into the copy at sp+0.
   2. Retail copies `e + 0x10` into a second saved register (`daddu $s5,$s4,$zero` in the delay slot
      of the first `bc1f`) and passes the copy to func_00282CF0 as its third argument, the original
      ($s4) to func_00282E80 and func_00282CC0. Here the three uses share one pseudo, so the state
      sits in $s5 and the hi half of the table address in $s6 where retail has $s6 and $s7 (no $s7
      save and restore, a 0x70 frame instead of 0x80), `e + 0x10` and `obj + 0x10` are in $s3/$s4
      where retail has $s4/$s3, and the first `bc1f` is a `bc1fl` whose slot holds a copy of the
      loop test's `lw` of the group word. Everything else follows from these two.
   Tried (about twenty compiles, none moves item 2): the three `e + 0x10` written out, as one local
   pointer, as a pointer per call, as a second name (`epos2 = epos`), assigned at the top of the
   loop body or just before each call; nested ifs, `continue` style and one flat `&&` chain;
   inline helpers with early returns for the range and cone tests (644 bytes, materialised flags);
   labels between the uses. cse leaves one pseudo for the three uses (-ds dump: its extended block
   runs through the fall-through of every `bc1f` and around the short negation block), so a second
   register needs a use that cse cannot reach (retail's looks like a gcse reaching-register copy
   used in a block cse treats separately); no plain spelling here produces one.
   Settled by measurement: an `if (c) b = -b;` statement shares one register between the constant
   and the range (K and b both in $f20); the ternary in the argument gives retail's $f21/$f20 split.
   `p = table[g]` read once for the init (no `q`) and the second `p != 0` guard are what keep the
   walk unrotated. `-g` changes nothing. Compiled here with the -g8 unit's flags, -O2 -G8 -ffunction-sections. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef int TI128 __attribute__((mode(TI)));

/* the id-list table, and the two words the walk reads (the count through $gp; the entity base as a
   bare symbol: a three-word `sda` array keeps the `lui`/`lw` pair, a scalar would use $gp) */
extern u16 *D_L11_001FC420[];
extern u8 *D_L11_001B359C_abs[3] __attribute__((sda));
extern s32 D_L11_001B35B8 __attribute__((sda));

/* the three float tuning words of this variant (angle limits in degrees, range) */
extern float D_L11_001B1D94 __attribute__((sda));
extern float D_L11_001B1D98 __attribute__((sda));
extern float D_L11_001B1D9C __attribute__((sda));

extern int func_00283DB8(void *v, float r);
extern float func_00282E80(void *, void *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_00283BE0(float, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_002ACEC0(void *, void *, void *, float);
extern void func_L11_00456070(void *, void *);
extern s32 func_L02_003D7300(u8 *);

#define GROUP(off) (*(s32 *)(state + (off)))

s32 func_L11_004566C0(u8 *obj) {
    u8 *state = *(u8 **)(obj + 0x68);
    float copy[4];
    float vec[4];
    u16 *p;
    u8 *e;
    float saved;
    float a;
    float b;

    *(TI128 *)vec = 0;
    vec[0] = *(float *)(obj + 0x10);
    vec[1] = *(float *)(obj + 0x14);
    vec[2] = *(float *)(obj + 0x18);
    vec[3] = 2.0f;
    *(TI128 *)copy = *(TI128 *)vec;
    if (func_00283DB8(copy, 128.0f) > 0) {
        if (GROUP(0x244) != -1) {
            for (p = D_L11_001FC420[GROUP(0x244)];
                 (GROUP(0x244) & 0xFF) != 0xFF && GROUP(0x244) <= D_L11_001B35B8 && p != 0 &&
                 ((p != 0 && (s16)p[-1] >= 0) || p == D_L11_001FC420[GROUP(0x244)]);
                 p++) {
                e = D_L11_001B359C_abs[0] + ((*p & 0x7FFF) << 8);
                if (e == 0)
                    break;
                if (func_L02_003D7300(e)) {
                    if (func_00282E80(obj + 0x10, e + 0x10) < D_L11_001B1D94) {
                        a = func_00283248(*(float *)(e + 0x10) - *(float *)(obj + 0x10),
                                          *(float *)(e + 0x14) - *(float *)(obj + 0x14));
                        if (func_00283C80(*(float *)(obj + 0xF8), a) < D_L11_001B1D98 * 0.017453294f) {
                            func_00282CF0(vec, obj + 0x10, e + 0x10);
                            b = D_L11_001B1D9C * 0.017453294f;
                            a = func_00283248(*(float *)(e + 0x10) - *(float *)(obj + 0x10),
                                              *(float *)(e + 0x14) - *(float *)(obj + 0x14));
                            func_002ACEC0(vec, vec, obj + 0xE0,
                                          func_00283BE0(*(float *)(obj + 0xF8), a) >= 0.0f ? -b : b);
                            func_00282CC0(vec, vec, e + 0x10);
                            saved = *(float *)(state + 0x134);
                            *(float *)(state + 0x134) = 0.0001f;
                            func_L11_00456070(obj, vec);
                            *(float *)(state + 0x134) = saved;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
