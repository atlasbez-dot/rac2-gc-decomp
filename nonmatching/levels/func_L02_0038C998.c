/* func_L02_0038C998 (shared, 9 places) - NEAR MISS, one instruction short.
   state: 1100 bytes against retail's 1104; tools/check.py: 0 of 9 places match ("1100 bytes,
   expected 1104" at every place). An aligned diff (immediates ignored) leaves three hunks, all
   the same spot: retail has `por $v0,$zero,$zero` (0x700014A9) ahead of the `lui $at,0x3D4C ;
   ori ; mtc1 $at,$f0` that builds 0.05f, then `sq $v0,0x20($sp)` (0x7FA20020) before
   `addiu $s2,$sp,0x30`; this cc1 prints one `sq $zero,0x20($sp)` (0x7FA00020) after the 0.05f.
   Everything else is retail's: with that one spot written by hand in the compiler's assembly
   (`por $2,$0,$0` first, `sq $2,32($sp)` before the `addu $18,$sp,48`) and assembled with the
   game `as`, the same C passes all 9 of 9 places (every symbol resolves; no ref_ name is needed).
   needs -G8: the function reads $gp data (-0xA0, -0x180, -0x1A0, -0x1A8, -0x1B0 of $gp), so it
   would live in L02_002B5F50-g8.c, after func_L02_002F1658. The names below are the level-2
   ones (D_L02_...); the plain externs (D_L02_001FC060, D_L02_001B359C, D_L02_001A9048) are
   absolute as in retail, the ones marked sda are $gp-relative.

   wall: the zero-TI fold. `rac2_fold_zero_ti_store` (tools/compiler/transformers/
   fold_zero_ti_store.py) runs right after reload. The `movti_internal` store takes a register, so
   reload puts the constant in `$v0` with a `por` directly in front of the `sq` (insn 664 in the
   .greg dump, a reload insn, next to the store); the pass then folds the pair into `sq $0` when
   `$v0` is dead after the store, which it is here (the next write of `$v0` is the `li $v0,0x1290`
   of the kind test). Retail keeps the `por`. Nothing in the source reaches it: the pair is always
   adjacent (inside the pass's 12-insn window) and the register is always dead after a single
   store; the pass keeps a por only when the zero feeds a second store (func_L00_002B91C0: three
   `sq $v0`), and there is no second store here.
   Retail has both forms for a store to `$sp`: a bare `sq $zero,N($sp)` (func_00302848,
   func_0031AB18) and `por vN ; ... ; sq vN,N($sp)` followed by scalar stores into the same vector
   (this function, func_002AE838, func_00325C50, func_L23_00422798): the por form is the clear of a
   partly initialised 16-byte local `{0, 0, x, 0}`, the bare form a whole-zero store. A rule that
   skips `$sp` destinations would therefore not separate them; one that leaves a clear-then-field-
   store local alone might (untested). This cc1 also does not reach the retail path for such a
   local: a four-float aggregate (with or without aligned(16), also a struct typed aligned(16)) is
   cleared by a call to memset, and only a TI128 union gives a `sq`, which the pass then folds.
   A cc1 that cleared such locals with one TImode move and left that pair alone would unblock the
   family (the level 23 vector bodies carry the same pair).
   what would unblock it: the fold must leave this pair; no source spelling reaches it.
   tried for the zero: `float dir[4] = {0, 0, 0.05f, 0}` with and without aligned(16), and a
   16-byte aligned struct of four floats (all call memset), a union of TI128 and float[4] with
   `dir.q = 0` (this file: `sq $zero`), `Vec4 dir = {{0}}`, the clear before or after the call.

   what was measured on the way (each one moved the body closer, kept below):
   - the hit block's stores must be struct member stores (`((Ent *)e)->f31 = 0`, `->f34 |= 1`,
     `->f98 = 0`): through a plain `*(T *)(e + n)` cast they alias the global counter, the
     scheduler cannot move its load between them, and the stack-argument constants land in
     $v1/$t0 where retail has $a2/$a3 (retail loads the counter after the `sb`, before the other two
     stores, and stores it last);
   - func_002ABBB8 takes twelve integer and seven float arguments; they go to $a0-$t3 + stack and
     $f12-$f18 independently, but the order of the call's arguments sets the order of the
     set-up code. Retail's order (the `mov.s $f13,$f12` ahead of the `sw`s, `addiu $t1`
     before `mov.s $f16`) comes out only with the floats interleaved as below (hill-climbed over
     the positions of the seven floats: ints first 28 words off, floats after every int 18, this
     one 16, before the struct stores below took the first call's set-up from 12 words to 0);
   - `(flags ^ 1) & 1` gives retail's `xori ; andi ; beqz`; `!(flags & 1)` gives `andi ; bnez`;
   - `dir` and `pos` declared inside the hit block; `pos` and `dir` 16-byte aligned (retail's
     vectors sit at $sp+0x20 and $sp+0x30);
   - the initialisers are ordered range, step, seg (`lh $fp` after `lwc1 $f24` in the source
     gives retail's `lh` first), rate last;
   - the counter must be a plain extern (absolute `lui`/`lw`, `lui $at`/`sw` as retail), not sda. */

typedef int TI128 __attribute__((mode(TI)));

typedef union {
    TI128 q;
    float f[4];
} Vec4;

typedef struct Ent {
    unsigned char pad00[0x31];
    unsigned char f31;
    unsigned char pad32[2];
    unsigned short f34;
    unsigned char pad36[0x98 - 0x36];
    int f98;
} Ent;

extern unsigned int D_L02_001FC060[];
extern char *D_L02_001B359C;
extern int D_L02_001B35B8 __attribute__((sda));
extern int D_L02_001A9048;
extern float D_L02_001AEF50 __attribute__((sda));
extern float D_L02_001AEE50[2] __attribute__((sda));
extern float D_L02_001AEE48[2] __attribute__((sda));
extern float D_L02_001AEE40[2] __attribute__((sda));
extern int D_L02_001AEE70 __attribute__((sda));
extern float func_00283198(float x);
extern float func_00283B98(float a, float b);
extern float func_00283BE0(float a, float b);
extern void func_002C9828(int *path, int seg, void *pos, void *rot, int flags, float t);
extern int func_002A9640(void *e, int a1, int a2);
extern void func_L00_0032A258(void *a0, void *a1, void *a2, void *a3, int t0, int t1, int t2, int t3,
                              int s0, int s1, int s2);
extern void func_L01_0031A278(char *a0, float *a1, float f12, float f13, float f14);
extern void func_002E5CF8(int a0, int a1, void *a2);
extern void func_002ABBB8(void *a0, float f12, void *a1, float f13, void *a2, float f14, int a3,
                          float f15, int t0, int t1, float f16, float f17, int t2, float f18,
                          int t3, int s0, int s1, int s2, int s3);
extern void func_002AA2E8(float *p, float a, float b);
extern void func_L02_0038CDE8(void *e);
extern void func_L02_0038D978(void *e);
extern void func_002A0F48(void *e);

/* Walks the group's entity list: each one moves along the path object (func_002C9828), turns its
   angle and advances its phase; a hit by the player while it is active switches it off and spawns
   the debris (func_L00_0032A258, func_002ABBB8); a live one tilts toward its turning speed
   (func_002AA2E8) and runs the level's two update calls. */
void func_L02_0038C998(unsigned char *arg0) {
    unsigned char *o = *(unsigned char **)(arg0 + 0x68);
    int *path = *(int **)(o + 0x60);
    float range = (float)*path;
    float step = *(float *)(o + 0x14);
    int seg = *(short *)(o + 0x70);
    float rate = D_L02_001AEF50 * 0.00029088825f;
    unsigned short *q;
    unsigned char *e;
    unsigned char *s1;
    float prev;
    float h;

    q = (unsigned short *)D_L02_001FC060[arg0[0x21]];
    while (arg0[0x21] != 0xFF && arg0[0x21] <= D_L02_001B35B8 && q != 0 &&
           ((q != 0 && (short)q[-1] >= 0) || q == (unsigned short *)D_L02_001FC060[arg0[0x21]])) {
        e = (unsigned char *)(D_L02_001B359C + ((*q & 0x7FFF) << 8));
        if (e == 0)
            break;
        s1 = *(unsigned char **)(e + 0x68);
        prev = *(float *)(e + 0xF8);
        h = *(float *)(s1 + 0x10) + *(float *)(s1 + 0x7C) * func_00283198(*(float *)(s1 + 0x80));
        if (range <= h)
            h -= range;
        else if (h < 0.0f)
            h += range;
        func_002C9828(path, seg, e + 0x10, e + 0xF0, 0, h);
        *(float *)(s1 + 0x68) = func_00283B98(*(float *)(s1 + 0x68), *(float *)(s1 + 0x6C));
        *(float *)(e + 0x18) += func_00283198(*(float *)(s1 + 0x68));
        *(float *)(s1 + 0x10) += step;
        if (range <= *(float *)(s1 + 0x10))
            *(float *)(s1 + 0x10) -= range;
        *(float *)(s1 + 0x80) = func_00283B98(*(float *)(s1 + 0x80), *(float *)(s1 + 0x84));
        if (func_002A9640(e, 0x4010000, 0) != 0) {
            if (e[0x31] != 0) {
                Vec4 dir;
                float pos[4] __attribute__((aligned(16)));

                ((Ent *)e)->f31 = 0;
                ((Ent *)e)->f34 |= 1;
                ((Ent *)e)->f98 = 0;
                D_L02_001A9048++;
                func_L00_0032A258(e, D_L02_001AEE50, D_L02_001AEE48, D_L02_001AEE40, 0x3F, 2,
                                  D_L02_001AEE70, 0, 0xFFFF, 0xFF, 0);
                dir.q = 0;
                dir.f[2] = 0.05000000447f;
                func_L01_0031A278((char *)e, pos, 0.0f, 0.0f, 0.0f);
                if (*(short *)(e + 0xAA) == 0x1290)
                    func_002E5CF8(0, 0, e);
                if (*(short *)(e + 0xAA) == 0x134B)
                    func_002E5CF8(0, 0, e);
                if (*(short *)(e + 0xAA) == 0xB15)
                    func_002E5CF8(1, 0, e);
                if (*(short *)(e + 0xAA) == 0xB13)
                    func_002E5CF8(1, 0, e);
                func_002ABBB8(e, 0.0f, &dir, 0.0f, pos, 5.0f, 0x23, 2.5f, 8, 0x10, 0.0f, 3.0f, -1,
                              15.0f, 1, 10, -1, 0, 0x810001);
            }
        }
        e[0xA8] = 0xFF;
        if (e[0x31] != 0) {
            if ((*(unsigned short *)(e + 0x34) ^ 1) & 1) {
                h = -func_00283BE0(*(float *)(e + 0xF8), prev) * 50.0f;
                if (0.78539824f < h)
                    h = 0.78539824f;
                if (h < -0.78539824f)
                    h = -0.78539824f;
                func_002AA2E8((float *)(e + 0xF0), h, rate);
                if (*(short *)(s1 + 0x72) != 0)
                    func_L02_0038CDE8(e);
                func_L02_0038D978(e);
            }
        }
        func_002A0F48(e);
        q++;
    }
}
