/* closer8 2026-10-26 (third pass, base rac2-large-functions ab77006e with the dli fix 25c1ac77):
   still a near miss.  Opcode-aligned 1360/1467 (this scorer; 1358 for the previous draft),
   1459 instructions (5836 of 5868 B).  Changes kept here: `(float)i` written inline (gcse's
   reaching-register copy gives retail's cvt into $f20 + mov.s $f23 after func_00283CE0), and
   `base = func_00283CE0(i) * 0.05f; base = D04 + (D08 - D04) * base;` (D_001AEE04 in a temp
   $f4, as retail).  Neither the qzero_nc helper (no qzero here) nor the combined loop-padding
   fixes (d53f2197 + efabf1d2) change a byte of this function.
   Mechanisms measured (variants in claims/func_0030A348/closer8/, ga2.py/an.sh there):
   - Scan loop: `Tgt **list = D_001EE960; for (n = 0; (t = list[n]) != 0; n++)` makes loop.c
     reduce a giv for the walking pointer; loops are scanned last-to-first, so it gets the
     highest pseudo number and retail's LAST spill slot (0x3AC), with the lw in the continue
     delay slots as retail.  With `D_001EE960[n]` the lo_sum stays in the loop ("not
     desirable", 61*1*2 < 173 insns) and no giv forms; with a user pointer p the slot is early.
     It scores lower overall only because the allocation cascade shifts.
   - best/second spill: update_equiv_regs doubles REG_LIVE_LENGTH once per constant set seen
     before the first non-constant set.  A second `best = 0; second = 0;` before the scan
     doubles best again (priority 527 -> 293), so it spills as in retail.
   - The z giv &D_00229170[i][2] ($s7 here) is not combined with &D_00229170[i] because cse
     puts the address in a register shared by the load and the store (not DEST_ADDR).  A
     `float *cp = D_00229170[i]` for the two z statements combines it (0x8($s1), as retail) and
     &v80 then gets $s7 as retail; but the i*16 giv (pri 615) then takes $fp ahead of &hit1
     (pri 480), and best/second/got (508/485) are also above &hit1.  Retail's order needs
     &hit1 above all of them; no spelling found yet.
   - &D_00229170[i - 1] is a giv in retail (0x3A8); here "not worth while, 378 vs 440 insns"
     (lifetime 2 * 63 * benefit 3).  A `float *prev = D_00229170[i - 1]` local gets it reduced
     but into a saved register.
   - Retail keeps two separate &D_00229440[i] givs (0x3A0 for the far arm, 0x3A4 for the near
     arm) and cp2[2] as 0x148($s1); the k loop's i-loop giv is 0x398.
*/
/* WIP 2026-10-26 (second agent): 1346/1467 opcodes equal (was 1267), 5828 B.
   Closed since the header below: qcopy() helper from common.h for every quadword copy
   (asm volatile flushes CSE, so k*0x50 is recomputed and becomes madd as in retail);
   indexed for-loops in the k-loop arms (check_dbra_loop count-down, one tmp pointer);
   abs-diff as a call in each arm, `if (D_001B23E8[k] > D_001B2400[k])` (cross-jumped call,
   beql, no movn); `a2 = 0.0f` before the CA0 test plus a separate `cs` variable (the 0.0
   lives in $f21 as retail); block-local f/w/m; amp's base as its own statement;
   D_001BAF98 as a struct {hit; pad; pos[4]} (retail reads hit as -8 off &pos).
   dli 0xFFFF0000FFFF0000 closed by compiler/dli-leading-ones.
   Still open: allocation (best/second spilled and &hit1 in $fp in retail), scan pointer
   in the last spill slot, chain-loop giv set (retail: separate i-1 and two D_00229440 givs),
   D5E0 madd needs the symbol hoisted (loop.c "not desirable", k loop 223 insns).
   The GCC 2.95 gcse model (compiler/gcse-default 7d7df088) gives identical bytes here.
   Variant with `float *cp = D_00229170[i]` for the z accesses and no cp2 local: 1344, with
   retail's [i][2] giv combination and cp2 giv, but a separate [20+i][2] giv where retail
   uses 0x148($s1). See claims/func_0030A348/NOTE. */
/* func_0030A348 (5868 bytes, 1467 instructions, boot; also 26 per-level copies: family F4, 27
   members, 158 KB), the lock-on tether effect.  NEAR MISS: 5808 of 5868 bytes, 1267 of 1467
   opcodes equal (difflib, registers ignored, 86.4%; the first draft had 1218).  The stack frame
   is equal (-0x440), and so is the local layout up to 0x350; the spill slots 0x350-0x3AC differ
   in assignment.  The INCLUDE_ASM in src/game/00308600.c stays.

   Profile: put this C in src/game/0030A348-g8-qcopy.c with
       -O2 -G8 -ffunction-sections -g -frac2-qcopy -frac2-qcopy-barrier
   (-g: the $LM line labels matter, see "line structure" below; -G8: the D_001AED../EE.. tuning
   floats are gp-relative, declared `__attribute__((sda))` with D_<addr> names; qcopy: lq/sq
   through address registers.)  The compiler is the one with the TImode one-GPR fix (branch
   compiler/ti-zero-reload).

   Step 0: one function, one prologue, one jr $ra, no dead code, no jump tables.

   Source: m2c (mipsee-gcc-c, prototypes from the matched callees) rewritten by hand.  What it is:
   the rope that the player's hand throws at up to two locked targets (Rope = the moby's +0x68
   record: a[4] anchor, b[4] tip, lockA +0x20, lockB +0x38, count +0x3E, four u16 at +0x40 read
   as one u64 for the "nothing pending" tests).  It (1) scores the targets in D_001EE960 by
   distance/angle, keeps the best two, (2) walks 19 chain points in D_00229170 (twenty, plus the
   mirrored second chain at +0x140), wobbling them with the tuning floats and breaking at the
   first point whose segment hits something (func_002761F8), (3) spawns hit records for the
   locked targets, (4) animates four glow nodes (Node5 = five quads, stride 0x50, in the three
   symbols D_002295C0/D0/E0), (5) spawns three sparks with func_002C2210.

   What closed differences since the first draft (all apply to the 26 other members):
   - Line structure.  With -g the assembler pads every div.s that is fewer than two slots after
     a $LM label with nops, so the statement boundaries around each division are visible in the
     bytes.  Retail has separate statements for the two score divisions (fa, fb), for
     `f = DF0(v80); if (f == 0) ... reach / f` (one call, not two), and for `cd = CE0(..);
     reach = f / cd`.  Now all div.s contexts equal retail's except one.
   - De-nested calls.  `D30(dst, ent + 0xE0, DB0(src, ent + 0xE0))` is two statements
     (proj = DB0(..); D30(.., proj)): retail re-reads D_00189E20.ent after the first call
     instead of keeping ent + 0xE0 in a saved register.
   - lockA/lockB length block: `ia = AB1F0(st->lockA)` first, then the copy of the position,
     then D30(.., ia[4]) (retail calls before it copies).
   - `if (locked) D_001AEE58 = 0x207F20; else D_001AEE58 = 0x7F2020;` as two statements (the
     ternary makes a movn here, retail branches).
   - kind test as two nested ifs (0xFE then 0xFD): `&&` is folded into a range test.
   - Arrays indexed by i as float[][4] (D_00229150/60/70, D_00229440) and `cp2` as the only
     pointer local: the loop optimiser then builds the same pointer inductions as retail
     (0x148($cp) for cp2[2], one lui/addiu per symbol).
   - The two hit records are members of one union local `hb` (hb.a.r at +0x10, hb.b.r at +0,
     scratch quad hb.q at +0): retail addresses them $sp-direct (sb 0x2D9($sp)); pointers into a
     char buffer give sb 0x19($a0).
   - D_001B23E0 is an int (sw), the second spark passes -s, the two stores of the k loop come
     before the first func_002A78D8 call (the sh zero fills its delay slot), info->short test
     is `if (x == 1) n = 1` (lh + movz, not lhu + movn).
   - best/second declared after locked: the spill slots then come out locked 0x354, best 0x358.

   What still differs (all of it register allocation, spill, or compiler-model):
   1. Allocation.  Retail keeps &hit1 in $fp and &v80 in $s7 across the candidate scan and the
      chain loop, and spills best/second (0x358/0x35C), got/nheld (0x360/0x364), &s2B0 (0x37C),
      &buf (0x380), &v60 (0x384), &v70 (0x388), st+0x10 (0x38C), &v90 (0x390), &vA0 (0x394)
      and the scan's walking pointer (0x3AC, the last slot).  Here best is spilled too now but
      second stays in $s7 and &s2B0 takes $fp, hit1/v80 are spilled.  tools/regalloc.py cannot
      run on this function (the -dS/-dR dumps abort cc1, "buffer overflow detected"); run cc1
      with -dl -dg only.  The inferred priority floor_log2(refs)*refs/live_length puts
      &hit1 (11 refs, live 690) at 0.048, second (9, 528) at 0.051, the D_001B5200 base (7, 278)
      at 0.050 and &s2B0 (36, 1058) at 0.17, so retail's choice is not a plain priority order
      (retail spills &s2B0 although its priority is highest): another pseudo must hold $fp inside
      its range (the lui $fp,0x1B of D_001B5340 after the chain loop is one).  Nothing tried
      moves them honestly: declaration order, scopes, pointer locals for every array
      combination (32 variants), index vs pointer scan loops, ref-count changes.  The
      decomp-permuter (aligned-diff scorer) reached 505 differing lines from 578 but only by
      duplicating loop bodies under `if (best)`: artifacts, rejected.
   2. k loop, `sym + k * 0x50`.  Retail has mtlo/madd for D_002295D0[k].v[0] and
      &D_002295E0[k] (3 madd + 3 mult in all), this compiler has one mult per arm and shares it
      with the pointer inits (mult count 3).  r5900_madd_profitable_p refuses when the addend's
      def is linked to the madd insn, and gcse/cse share the multiply across the call and the
      do-while loop.  No spelling found that unshares them (statement order, pointer locals,
      D + k * 80 forms).  Needs a compiler look.
   3. dli 0xFFFF0000FFFF0000 (the lockB mask).  Retail: lui $v1,0x8000; dsll $v1,$v1,1;
      ori $v1,$v1,0xFFFF; dsll $v1,$v1,16.  Patch 0052's field expansion gives ori 0xFFFF;
      dsll32 0; ori 0xFFFF; dsll 16 (same length, different bytes) for every spelling of the
      constant, and --r5900-sign-bit does not touch it.  The lockA mask 0x0000FFFF0000FFFF
      matches.  A narrow gas rule (sign bit set, low 16 bits zero, shifted value
      0xFFFFFFFF0000FFFF built as lui 0x8000/dsll 1/ori) would close it; needs
      `tools/build.py all` and tests/test_dli_masks.py.
   4. `d = x >= y ? x - y : y - x` (and the if/else spelling) becomes movn here; retail has
      slt + beql with the subu in the delay slot.
   5. Retail hoists a float 0.0 (mtc1 $zero,$f21) before the scan's `f != 0.0f` compare and
      keeps zero in $f25 for the chain loop's compares; here it is reloaded at each use.
*/
#include "include_asm.h"
#include "common.h"

typedef int V4 __attribute__((mode(TI)));

/* The lock-on tether: a chain of twenty points that hangs from the player's hand to up to two
   locked targets, its glow spots and sparks. Only the fields this function touches are named. */
typedef struct Tgt {
    char pad0[0x10];
    float pos[4];                       /* 0x10 */
    unsigned char kind;                 /* 0x20 */
    char pad1[3];
    struct TgtClass *cls;               /* 0x24 */
    char pad2[0x98 - 0x28];
    int f98;                            /* 0x98 */
} Tgt;

typedef struct TgtClass {
    char pad0[0x10];
    int f10;                            /* 0x10 */
    char pad1[0x46 - 0x14];
    short id;                           /* 0x46 */
} TgtClass;

typedef struct Rope {
    float a[4];                         /* 0x00 */
    float b[4];                         /* 0x10 */
    Tgt *lockA;                         /* 0x20 */
    char pad1[0x38 - 0x24];
    Tgt *lockB;                         /* 0x38 */
    short pad2;
    short count;                        /* 0x3E */
    union {
        struct {
            unsigned short h40, h42, h44, h46;
        } s;
        unsigned long q;                /* 0x40 */
    } u;
} Rope;

typedef struct Moby {
    char pad0[0x68];
    Rope *rope;                         /* 0x68 */
    char pad1[0xAA - 0x6C];
    unsigned short tag;                 /* 0xAA */
} Moby;

typedef struct Hit {
    float dir[4];                       /* 0x00 */
    char pad0[0x18 - 0x10];
    unsigned char kind;                 /* 0x18 */
    unsigned char flag;                 /* 0x19 */
    unsigned short tag;                 /* 0x1A */
    char pad1[0x30 - 0x1C];
} Hit;

typedef struct Cam {
    char pad0[0x80];
    float x, y;
    char pad1[0x98 - 0x88];
    float f98;
    char pad2[0x2290 - 0x9C];
    char *ent;
} Cam;

typedef struct Level { char pad0[0x12]; unsigned char cur; } Level;
typedef struct Slot { char pad0[4]; unsigned char on; char pad1[0x70 - 5]; float f70; char pad2[0xE0 - 0x74]; } Slot;

extern Level D_00139568;
extern Slot D_00239BA0[];
extern Cam D_00189E20;
extern char D_00189EA0[];
extern char D_0018A560[];
extern int D_001A8CA0;
extern char D_001A8BD0[];
extern int D_001B23E0;
extern short D_001B23E8[], D_001B23F0[], D_001B23F8[], D_001B2400[];
extern float D_001B5200[];
extern char D_001B5340[];
/* The collision query's result: what the segment hit, and where. */
typedef struct HitResult {
    Tgt *hit;                           /* 0x0 */
    int pad;
    float pos[4];                       /* 0x8 */
} HitResult;
extern HitResult D_001BAF98;
extern Tgt *D_001EE960[];
extern float D_00229150[][4], D_00229160[][4], D_00229170[][4];
extern V4 D_002292A0;
extern float D_002293F0[];
extern float D_00229440[][4];
extern float D_00229580[];
typedef struct { V4 v[5]; } Node5;
extern Node5 D_002295C0[], D_002295D0[], D_002295E0[];

extern float D_001AEDF4 __attribute__((sda));
extern float D_001AEDF8 __attribute__((sda));
extern float D_001AEDFC __attribute__((sda));
extern float D_001AEE00 __attribute__((sda));
extern float D_001AEE04 __attribute__((sda));
extern float D_001AEE08 __attribute__((sda));
extern float D_001AEE0C __attribute__((sda));
extern float D_001AEE10 __attribute__((sda));
extern float D_001AEE14 __attribute__((sda));
extern float D_001AEE18 __attribute__((sda));
extern float D_001AEE1C __attribute__((sda));
extern float D_001AEE20 __attribute__((sda));
extern float D_001AEE24 __attribute__((sda));
extern float D_001AEE28 __attribute__((sda));
extern float D_001AEE2C __attribute__((sda));
extern float D_001AEE30 __attribute__((sda));
extern float D_001AEE44 __attribute__((sda));
extern float D_001AEE48 __attribute__((sda));
extern float D_001AEE88 __attribute__((sda));
extern float D_001AEE8C __attribute__((sda));
extern int D_001AEE58 __attribute__((sda));

extern int func_002761F8(void *, void *, int, void *, void *);
extern int func_00277F48(void *, int, char *, void *, float);
extern int func_00282948(void *);
extern int func_00282978(void *);
extern void func_00282C88(void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D08(void *, void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern float func_00282DF0(void *);
extern float func_00282E20(void *);
extern float func_00282E48(void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_002831B0(float);
extern float func_00283248(float, float);
extern float func_00283B98(float, float);
extern float func_00283BE0(float, float);
extern float func_00283C80(float, float);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern int func_002A77E0(int);
extern int func_002A7820(int, int);
extern float func_002A7878(float, float);
extern float func_002A78D8(float, float);
extern void func_002A8C00(void *, void *, int, void *, float);
extern void func_002A8E20(void *, void *);
extern float *func_002AB1F0(void *);
extern float func_002ABB18(float);
extern void func_002ACEC0(void *, void *, void *, float);
extern void func_002C2210(void *, int, int, int, int, void *, int, float, float, float);
extern void func_00300190(void *, void *);

void func_0030A348(Moby *self)
{
    Rope *st = self->rope;
    float v0[4] __attribute__((aligned(16)));
    float va[4] __attribute__((aligned(16)));
    float vb[4] __attribute__((aligned(16)));
    Hit hit1 __attribute__((aligned(16)));
    float v60[4] __attribute__((aligned(16)));
    float v70[4] __attribute__((aligned(16)));
    float v80[4] __attribute__((aligned(16)));
    float v90[4] __attribute__((aligned(16)));
    float vA0[4] __attribute__((aligned(16)));
    Tgt *held[128];
    float s2B0[4] __attribute__((aligned(16)));
    union {
        float q[16];
        struct { Hit r; } b;
        struct { float pad[4]; Hit r; } a;
    } hb __attribute__((aligned(16)));
    float tmp[5][4] __attribute__((aligned(16)));
    int locked;
    Tgt *best = 0, *second = 0;
    int got, nheld;
    float bestScore = 0.0f, secondScore = 0.0f;
    float reach, len;
    int i, k;

    locked = D_00239BA0[D_00139568.cur].on != 0;
    reach = D_001AEDF4 * 0.05f;
    D_001AEE0C = func_00283B98(D_001AEE0C, D_001AEE10);
    D_001AEE14 = func_00283BE0(D_001AEE14, D_001AEE18);
    D_001AEE28 = func_00283B98(D_001AEE28, D_001AEE2C);

    if (st->lockA == 0 || (locked && st->lockB == 0)) {
        if (st->lockB != 0) {
            st->lockA = st->lockB;
            st->u.s.h40 = st->u.s.h42;
            st->lockB = 0;
            st->u.s.h42 = 0;
        } else {
            Tgt **p;
            Tgt *t;
            for (p = D_001EE960; (t = *p) != 0; p++) {
                if (t != st->lockA && t != st->lockB) {
                    if (t != 0 && t->cls != 0 && t->cls->id == 5) {
                        if (t->kind != 0xFE) {
 if (t->kind != 0xFD) {
                            if (func_002AB1F0(t) != 0) {
                                float dist, ang, a2, cs, m, score, proj, fa, fb;
                                func_00282CF0(v0, t->pos, st);
                                if (D_001A8CA0 != 0) {
                                    proj = func_00282DB0(v0, D_00189E20.ent + 0xE0);
                                    func_00282D30(va, D_00189E20.ent + 0xE0, proj);
                                    func_00282CF0(vb, v0, va);
                                    dist = func_00282DF0(vb);
                                } else {
                                    dist = func_00282E20(v0);
                                }
                                if (!(D_001AEDF4 < dist)) {
                                    ang = func_00283C80(D_001B5200[0x158 / 4], func_00283248(t->pos[0] - D_001B5200[0x140 / 4], t->pos[1] - D_001B5200[0x144 / 4]));
                                    if (!(D_001AEDFC < ang)) {
                                        a2 = 0.0f;
                                        if (D_001A8CA0 != 0) {
                                            func_00282CF0(va, t->pos, D_00189EA0);
                                            proj = func_00282DB0(va, D_00189E20.ent + 0xE0);
                                            func_00282D30(vb, D_00189E20.ent + 0xE0, proj);
                                            func_00282CF0(va, va, vb);
                                            cs = func_00282DB0(va, D_00189E20.ent + 0xC0);
                                            m = func_00282DF0(va);
                                            if (m != 0.0f) {
                                                a2 = 1.5707964f - func_002831B0(cs / m);
                                                goto tail;
                                            }
                                        } else {
                                            a2 = func_00283C80(func_00283248(t->pos[0] - D_00189E20.x, t->pos[1] - D_00189E20.y), D_00189E20.f98);
                                        tail:
                                            if (!(D_001AEDF8 < a2)) {
                                                fa = (D_001AEDFC - ang) / D_001AEDFC;
                                                fb = (D_001AEDF4 - dist) / D_001AEDF4;
                                                score = fa * D_001AEE8C + fb;
                                                if (bestScore < score) {
                                                    secondScore = bestScore;
                                                    bestScore = score;
                                                    second = best;
                                                    best = t;
                                                } else if (secondScore < score) {
                                                    second = t;
                                                    secondScore = score;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
}
                    }
                }
            }
        }
    }

    if (best != 0) {
        if (st->lockA != 0) {
            second = best;
        } else {
            st->u.s.h40 = 0;
            st->lockA = best;
            if (func_00282948(&D_001B23E0) != 0)
                D_001B23E0 = 0xA;
        }
    }
    if (second != 0 && locked) {
        float d = func_00282E48(st, best->pos);
        if (d < D_001AEDF4 && d + func_00282E48(best->pos, second->pos) < D_001AEDF4) {
            st->u.s.h42 = 0;
            st->lockB = second;
        }
    }
    len = 0.0f;
    if (st->lockA != 0) {
        float *ia = func_002AB1F0(st->lockA);
        qcopy(v0, st->lockA->pos);
        func_00282D30(va, (char *)st->lockA + 0xE0, ia[4]);
        func_00282CC0(v0, v0, va);
        len = func_00282E48(st, v0);
        reach = len * 0.05f;
    }
    if (st->lockB != 0) {
        float *ib = func_002AB1F0(st->lockB);
        qcopy(va, st->lockB->pos);
        func_00282D30(vb, (char *)st->lockB + 0xE0, ib[4]);
        func_00282CC0(va, va, vb);
        reach = (func_00282E48(v0, va) + len) * 0.05f;
    }
    if (locked)
        D_001AEE58 = 0x207F20;
    else
        D_001AEE58 = 0x7F2020;
    func_00282C88(vb);
    func_002A8C00(&hit1, self, 0x210000, vb, D_00239BA0[D_00139568.cur].f70);
    hit1.flag = 1;
    hit1.kind = 5;
    hit1.tag = self->tag;
    st->count = 0x14;
    func_00277F48(st, 0x10, D_00189E20.ent, &hit1, 0.3f);
    func_00282CF0(v60, st->b, st);
    func_00282F20(v60, v60, 1.0f);
    if (st->lockA != 0 || st->lockB != 0) {
        func_00282DD8(v70, v60, (char *)&D_00189E20 + 0x2C0);
        func_002ACEC0(v60, v60, v70, 0.17453295f);
    }
    got = 0;
    func_00282D30(v90, v60, reach);
    nheld = 0;
    qcopy(D_00229170[0], st);
    qcopy(D_00229170[20], st);
    for (i = 1; i < 20; i++) {
        float f, w;
        float base, amp, amp2, ph2, m, old, ang, pj, cd;
        int near;
        float *cp2 = D_00229170[20 + i];

        base = func_00283CE0(i) * 0.05f;
        base = D_001AEE04 + (D_001AEE08 - D_001AEE04) * base;
        amp = base * func_00283198(func_002ABB18(D_001AEE0C + (float)i * D_001AEE00));
        amp += func_002A78D8(D_001AEE44, D_001AEE48);
        old = D_002293F0[i];
        D_002293F0[i] = amp;
        D_00229170[i][2] = D_00229170[i][2] - old;
        func_00300190(D_00229170[i], D_00229170[i]);
        func_00282CF0(v70, D_00229170[i], D_00229160[i]);
        func_00282D08(v80, v70, v90, 0.85f);
        m = func_00282DF0(v80);
        if (m == 0.0f) {
            qcopy(D_00229170[i], D_00229170[i - 1]);
        } else {
            func_00282D30(v80, v80, reach / m);
            func_00282CC0(D_00229170[i], D_00229160[i], v80);
            qcopy(v90, v80);
        }
        near = i < 10;
        D_00229170[i][2] = D_00229170[i][2] + amp;
        func_00282CF0(v70, D_00229170[i], D_00229160[i]);
        if (st->lockA != 0) {
            if (!locked || st->lockB == 0) {
                func_00282CF0(s2B0, v0, D_00229170[i]);
                f = func_00282DF0(s2B0);
                if (f != 0.0f) {
                    if (i == 0x13) {
                        w = 0.5f;
                        reach = f;
                    } else if (i >= 0x10) {
                        w = 0.5f;
                        cd = func_00283CE0(0x13 - i);
                        reach = f / cd;
                    } else {
                        w = 0.1f;
                    }
                    func_00282D30(s2B0, s2B0, reach / f);
                    func_00282D08(v90, v90, s2B0, w);
                }
            } else {
                if (!near)
                    func_00282CF0(s2B0, va, D_00229170[i]);
                else
                    func_00282CF0(s2B0, v0, D_00229170[i]);
                f = func_00282DF0(s2B0);
                if (f != 0.0f) {
                    if (i == 9 || i == 0x13) {
                        w = 0.7f;
                        reach = f;
                    } else if ((unsigned)(i - 5) < 5) {
                        w = 0.7f;
                        cd = func_00283CE0(9 - i);
                        reach = f / cd;
                    } else if (i >= 0xF) {
                        w = 0.7f;
                        cd = func_00283CE0(0x13 - i);
                        reach = f / cd;
                    } else {
                        w = 0.2f;
                    }
                    func_00282D30(s2B0, s2B0, reach / f);
                    func_00282D08(v90, v90, s2B0, w);
                }
            }
        }
        if (near) {
            ph2 = func_002ABB18(D_001AEE14 + (float)i * D_001AEE1C);
            amp2 = D_001AEE20 * func_00283198(func_002ABB18(D_001AEE28 + (float)i * D_001AEE30));
            qcopy(cp2, D_00229170[i]);
            amp2 = amp2 * func_00283198(ph2) + func_002A78D8(0.0f, 0.1f);
            D_00229580[i] = amp2;
            cp2[2] = cp2[2] + amp2;
            ang = func_00283B98(func_00283248(v70[0], v70[1]), 1.5707965f);
            f = D_001AEE24 * func_00283180(ph2);
            vA0[0] = func_00283180(ang) * f;
            vA0[1] = func_00283198(ang) * f;
            vA0[2] = 0.0f;
            qcopy(D_00229440[i], vA0);
            func_00282CC0(cp2, cp2, vA0);
        } else {
            int a2 = 0x15 - i;
            qcopy(cp2, D_00229170[i]);
            cp2[2] = cp2[2] + D_00229580[a2];
            func_00282CC0(cp2, cp2, D_00229440[a2]);
            qcopy(vA0, D_00229440[i]);
        }
        if (i >= 2 && (i == 0x13 || !(i & 1))) {
            func_00282CF0(vb, D_00229170[i], D_001B5340);
            if (D_001A8CA0 != 0) {
                pj = func_00282DB0(vb, D_00189E20.ent + 0xE0);
                func_00282D30(s2B0, D_00189E20.ent + 0xE0, pj);
                func_00282CF0(vb, vb, s2B0);
            } else {
                *(int *)&vb[2] = 0;
            }
            f = func_00282DF0(vb);
            if (f == 0.0f)
                vb[2] = 1.0f;
            else
                func_00282D30(vb, vb, 1.0f / f);
            vb[3] = 5627.925f;
            qcopy(&hit1, vb);
            got = func_002761F8(D_00229150[i], D_00229170[i], 0x10, self, 0);
            if (got != 0) {
                Tgt *t = D_001BAF98.hit;
                if (t != 0) {
                    float *info = func_002AB1F0(t);
                    if (info == 0 || t->cls == 0 || t->cls->id != 5) {
                        func_002A8E20(t, &hit1);
                    } else {
                        got = 0;
                        held[nheld++] = t;
                        t->f98 = 0;
                    }
                }
                if (got != 0) {
                    qcopy(D_00229170[i], D_001BAF98.pos);
                    st->count = i;
                    qcopy(st->b, D_001BAF98.pos);
                    if (D_001BAF98.hit == 0) {
                        st->lockA = 0;
                        st->u.s.h40 = 0;
                    }
                    break;
                }
            }
        }
    }
    for (i = 0; i < nheld; i++)
        held[i]->f98 = held[i]->cls->f10;
    if (got == 0)
        qcopy(st->b, &D_002292A0);
    if (st->lockA != 0 && (st->u.q & 0x0000FFFF0000FFFFUL) == 0) {
        float *tv = hb.q;
        float pj;
        float *info;
        short n = 5;
        func_00282CF0(s2B0, st->lockA->pos, D_001B5340);
        if (D_001A8CA0 != 0) {
            pj = func_00282DB0(s2B0, D_00189E20.ent + 0xE0);
            func_00282D30(tv, D_00189E20.ent + 0xE0, pj);
            func_00282CF0(s2B0, s2B0, tv);
        } else {
            *(int *)&s2B0[2] = 0;
        }
        func_00282F20(s2B0, s2B0, 1.0f);
        s2B0[3] = 5627.925f;
        func_002A8C00(&hb.a.r, self, 0x210000, s2B0, D_00239BA0[D_00139568.cur].f70);
        hb.a.r.flag = 3;
        hb.a.r.kind = 5;
        hb.a.r.tag = self->tag;
        func_002A8E20(st->lockA, &hb.a.r);
        info = func_002AB1F0(st->lockA);
        if (info != 0) {
            if (((short *)info)[2] == 1)
                n = 1;
        }
        st->u.s.h44 = n;
    }
    if (st->lockB != 0 && (st->u.q & 0xFFFF0000FFFF0000UL) == 0) {
        float pj;
        float *info;
        short n = 5;
        func_00282CF0(s2B0, st->lockB->pos, D_001B5340);
        if (D_001A8CA0 != 0) {
            pj = func_00282DB0(s2B0, D_00189E20.ent + 0xE0);
            func_00282D30(hb.q, D_00189E20.ent + 0xE0, pj);
            func_00282CF0(s2B0, s2B0, hb.q);
        } else {
            *(int *)&s2B0[2] = 0;
        }
        func_00282F20(s2B0, s2B0, 1.0f);
        s2B0[3] = 5627.925f;
        func_002A8C00(&hb.b.r, self, 0x210000, s2B0, D_00239BA0[D_00139568.cur].f70);
        hb.b.r.flag = 3;
        hb.b.r.kind = 5;
        hb.b.r.tag = self->tag;
        func_002A8E20(st->lockB, &hb.b.r);
        info = func_002AB1F0(st->lockB);
        if (info != 0) {
            if (((short *)info)[2] == 1)
                n = 1;
        }
        st->u.s.h46 = n;
    }
    for (k = 0; k < 4; k++) {
        float *s2C0 = hb.q;
        float w;
        if (k < 2) {
            qcopy(s2C0, st);
            w = 0.4f;
        } else {
            qcopy(s2C0, st->b);
            w = 0.5f;
        }
        if (func_00282978(&D_001B23E8[k]) != 0) {
            float s, f;
            int j;
            float a, b;
            D_001B23E8[k] = D_001B23F8[k];
            D_001B23F0[k] = 0;
            a = func_002A78D8(0.52359885f, 1.0471977f);
            b = func_002A7878(-1.0471977f, 0.17453295f);
            func_00282D30(s2B0, v60, w);
            func_002ACEC0(s2B0, s2B0, D_0018A560, b);
            func_002ACEC0(s2B0, s2B0, D_0018A560 + 0x10, a);
            qcopy(&D_002295D0[k].v[0], s2C0);
            s = 1.0f;
            func_00282CC0(D_002295E0[k].v, s2C0, s2B0);
            for (j = 2; j < 5; j++) {
                func_00282CF0(hb.q + 4, &D_002295C0[k].v[j], D_001B5340);
                f = func_002A7878(0.17453295f, 0.9599312f) * s;
                s = -s;
                func_002ACEC0(s2B0, s2B0, hb.q + 4, f);
                func_00282CC0(&D_002295D0[k].v[j], &D_002295C0[k].v[j], s2B0);
            }
        } else {
            int d, j;
            float f;
            for (j = 1; j < 5; j++) {
                float *q = tmp[j];
                func_00282CF0(q, &D_002295D0[k].v[j], &D_002295C0[k].v[j]);
                q[0] = q[0] + func_002A78D8(0.0f, 0.1f);
                q[1] = q[1] + func_002A78D8(0.0f, 0.1f);
                q[2] = q[2] + func_002A78D8(0.0f, 0.1f);
            }
            qcopy(&D_002295D0[k].v[0], s2C0);
            for (j = 1; j < 5; j++)
                func_00282CC0(&D_002295D0[k].v[j], &D_002295C0[k].v[j], tmp[j]);
            if (D_001B23E8[k] > D_001B2400[k])
                f = func_00283CE0(D_001B23E8[k] - D_001B2400[k]);
            else
                f = func_00283CE0(D_001B2400[k] - D_001B23E8[k]);
            D_001B23F0[k] = func_00283CF0((1.0f - f / func_00283CE0(0xF)) * 32.0f);
        }
    }
    {
        float a = func_002A78D8(0.52359885f, 1.0471977f);
        float b = func_002A7878(-0.52359885f, 1.0471977f);
        int s;
        float g;
        func_00282D30(s2B0, v60, D_001AEE88);
        func_002ACEC0(s2B0, s2B0, D_0018A560, b);
        func_002ACEC0(s2B0, s2B0, D_0018A560 + 0x10, a);
        s = func_002A7820(1, 8);
        s = func_002A77E0(2) != 0 ? -s : s;
        g = func_002A7878(0.2f, 0.6f);
        func_002C2210(st, 0xF, D_001AEE58 | 0x7F000000, 0, s, s2B0, 1, g * 0.3f, g, 0.0f);
        func_002C2210(st, 0xF, 0x307F7F7F, 0, -s, s2B0, 1, g * 0.15f, g * 0.5f, 0.0f);
        s = func_002A7820(1, 8);
        s = func_002A77E0(2) != 0 ? -s : s;
        g = func_002A7878(0.15f, 3.0f);
        func_002C2210(st->b, 0xC, D_001AEE58 | 0x7F000000, 0, s, D_001A8BD0, 1, g * 0.1f, g, 0.0f);
    }
}
