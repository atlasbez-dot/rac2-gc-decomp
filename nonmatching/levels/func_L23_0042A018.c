/* func_L23_0042A018 (1052 bytes, level 23 only) -- NEAR MISS, not integrated.
   Measured on 22 October 2026 with the compiler built from master (qcopy barrier and the
   annulled-wide-store switch included). This C compiles to 1052 bytes, retail's size; check.py:
   "instruction at +0x78 differs". It belongs in a unit of its own,
   src/levels/23_damosel_orbit/L23_0042A018-g8.c, built with `-O2 -G8 -ffunction-sections
   -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-barrier` ($gp data, hence -G8): 68 rows differ,
   19 when the registers are ignored.
   What this attempt fixed (each is retail's code now):
   - the 64-bit ALPHA word re-reads the stored field, `(s64)vars->alpha << 32`: CSE replaces the
     load with the stored value but combine then keeps retail's separate `daddu v0,a2,zero`
     before `dsll32` (with `(s64)x << 32` combine folds the extension into the shift: 4 bytes
     short); the sum is written `D_147C + (s32)(...)`, which gives retail's a2/a3;
   - the colour select computes `(vars->alpha << 24) + (rgb & 0xFFFFFF)` in each arm: the alpha
     load is shared before the branch (retail's `bnez ; lw v0,4(s1)`), each arm keeps its `lui`
     and cross-jumping merges the identical `ori; sll; and; addu` tails, as in retail;
   - the uv table is one `float [][2]` table: `[b][1]` is addressed from the constant
     D_L23_002A6D50+4 (retail's `lui; addiu 0x6D54`) and loop.c hoists the whole address of
     D_L23_002A6D50 into fp, which fixes the inner loop and its registers (two separate symbols
     leave fp with the %hi of the second table);
   - the inner pointers are declared e, uvy, uvx, pos (retail's s0, s4, s3, s2).
   What differs, and why it is not a source question:
   - the clear `axis[0] = 0` (retail +0x1CC `addiu v0,sp,0xD0; sq $zero,0(v0)`): the zero store is
     not a qcopy pattern, CSE folds the stack offset into the `sq` (the address-cost tie), and
     rac2_fold_zero_ti_store only folds a register address, so this cc1 gives `por v0; sq
     v0,0xD0(sp)`. Retail has 57 such `addiu rX,sp,N ; sq $zero,0(rX)` pairs and no C in src/
     reproduces one;
   - retail's copies and clear have the shape of volatile-asm macros (docs/COMPILER-NOTES.md), and
     CSE flushes its table at a volatile asm: retail re-forms `addiu a1,sp,0x90` for func_00283738's arguments, while here
     CSE reuses the first qcopy's address register across the call, which takes s1 and shifts vars
     to s2 (the +0x78 difference) and every later callee-saved register. -frac2-qcopy-barrier
     models the scheduling side of the macro only;
   - in a SCRATCH copy only, with the clear written as `__asm__ __volatile__("sq $0,0(%0)" ::
     "r"(axis))`, the copies, the clear, the call arguments and the callee-saved registers are
     retail's (35 rows, 20 without registers). Those rows are the ALPHA word's schedule
     (retail loads D_1BB0, D_1BAC, D_1BB4 then D_1BB8; here D_1BB4 comes second, and the sum
     prints `addu a2,a2,a3` where retail has `addu a2,a3,a2`) and the outer
     loop set-up: the colour lands in v1 instead of v0, so sched2 interleaves the four colour
     stores with the set-up; the hoisted uv start pointers spill to 0x110/0x114 in the other order
     (gcse's PRE creates uvx's start register, sp+0x50, first in every source order measured);
     `i` is in a0 instead of v1.
   What would unblock it: a qcopy-like opt-in pattern for 16-byte zero stores (register address,
   zero displacement), and a CSE flush at the grouped copy and the clear.
   Measured without effect today: the 24 orders of the four inner-loop declarations (only the
   register rotation moves), do/while and while outer loops, `!=`/`<=` tests, the ALPHA word as one
   expression or with `unsigned long` casts, `x` kept as a variable or as an s64, the colour
   select as a ternary, with the mask outside the arms or with `0xFFFFFF & rgb`. */

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef int s32;

typedef long long s64;

typedef int TI16 __attribute__((mode(TI)));

/* the state object word, read through an absolute access */
extern u8 *D_L23_001B1484_2;

extern float D_L23_001B1470;

extern float D_L23_001B1478;

extern s32 D_L23_001B1474;

extern s32 D_L23_001B1480;

extern s32 D_L23_001B147C;

extern float D_L23_001B39D0;

extern s32 D_L23_001B3714;

extern s32 D_L23_001B1BAC __attribute__((sda));

extern s32 D_L23_001B1BB0 __attribute__((sda));

extern s32 D_L23_001B1BB4 __attribute__((sda));

extern s32 D_L23_001B1BB8 __attribute__((sda));

extern s32 D_L23_001B1BC0 __attribute__((sda));

extern s32 D_L23_001B1BC4 __attribute__((sda));

extern s32 D_L23_001B1BC8 __attribute__((sda));

extern float D_L23_001B1BCC __attribute__((sda));

extern float D_L23_001B1BD0 __attribute__((sda));

extern float D_L23_001B1BD4 __attribute__((sda));

extern float D_L23_001B1BD8 __attribute__((sda));

extern float D_L23_001B1BDC __attribute__((sda));

extern float D_L23_001B1BE0 __attribute__((sda));

extern float D_L23_001B1BE4 __attribute__((sda));

extern float D_L23_001B1BF0 __attribute__((sda));

extern float D_L23_001B1BF4 __attribute__((sda));

extern float D_L23_001B1BF8 __attribute__((sda));

extern float D_L23_001B1BFC __attribute__((sda));

/* the quad record handed to the draw helper */
typedef struct {
    TI16 pos[4];
    u32 col[4];
    float uv[4][2];
    s64 tail[4];
} L23Quad;

/* the spin state at object + 0x68 */
typedef struct {
    float turn;
    s32 alpha;
    float spin;
} L23Spin;

typedef struct {
    s16 a;
    s16 b;
} L23Corner;

extern L23Corner D_L23_002A68D0[][4];

extern TI16 D_L23_002A6390[];

extern float D_L23_002A6D50[][2];

extern float func_00283B98(float, float);

extern float func_00283198(float);

extern float func_00283180(float);

extern float func_00283C28(float);

extern float func_002A7878(float, float);

extern long long func_0027C878(s32);

extern void func_002FC560(u32, unsigned long);

extern void func_00282D30(void *, void *, float);

extern void func_002833F0(void *, void *);

extern void func_00283738(void *, void *, void *);

extern void func_00280B90(void *, void *, s32);

/* updates the spin state at +0x68 and draws 72 quads of four corners each (corner positions from
   one table, uv from another; the colour and two GS words sit in the packet), the packet's matrix
   being the object's rotation rows turned about the spin angle */
void func_L23_0042A018(u8 *moby) {
    L23Spin *vars;
    L23Quad pkt;
    TI16 m[4];
    TI16 axis[1];
    TI16 rot[3];
    float f;
    float fa;
    float fb;
    float fc;
    float fd;
    s32 i;
    s32 k;
    u32 col;
    s64 reg;
    s64 tex;

    if (D_L23_001B1484_2 != 0) {
        vars = *(L23Spin **)(moby + 0x68);
        D_L23_001B39D0 = D_L23_001B1470 * 1.1f;
        vars->turn = func_00283B98(vars->turn, (float)D_L23_001B1480 * 0.00029088825f);
        f = func_00283198((float)(*(u16 *)(moby + 0x96) % D_L23_001B1474) * (1.0f / (float)D_L23_001B1474) * 3.1415927f);
        vars->alpha = D_L23_001B147C + (s32)(f * D_L23_001B1478);
        reg = D_L23_001B1BAC;
        reg |= (s64)D_L23_001B1BB0 << 2;
        reg |= (s64)D_L23_001B1BB4 << 4;
        reg |= (s64)D_L23_001B1BB8 << 6;
        reg |= (s64)vars->alpha << 32;
        pkt.tail[3] = reg;
        tex = func_0027C878(D_L23_001B1BC0);
        pkt.tail[2] = 0xFF9000000260LL;
        pkt.tail[1] = tex;
        pkt.tail[0] = 0;
        func_002FC560(0x47, 0x53001);
        m[0] = *(TI16 *)(D_L23_001B1484_2 + 0xC0);
        m[1] = *(TI16 *)(D_L23_001B1484_2 + 0xD0);
        m[2] = *(TI16 *)(D_L23_001B1484_2 + 0xE0);
        m[3] = *(TI16 *)(D_L23_001B1484_2 + 0x10);
        ((float *)&m[3])[3] = 1.0f;
        axis[0] = 0;
        ((float *)axis)[2] = vars->turn;
        func_002833F0(rot, axis);
        func_00283738(m, m, rot);
        if (D_L23_001B3714 == 0) {
            col = (vars->alpha << 24) + (D_L23_001B1BC4 & 0xFFFFFF);
        } else {
            col = (vars->alpha << 24) + (D_L23_001B1BC8 & 0xFFFFFF);
        }
        pkt.col[3] = col;
        pkt.col[2] = col;
        pkt.col[1] = col;
        pkt.col[0] = col;
        for (i = 0; i < 0x48; i++) {
            L23Corner *e = D_L23_002A68D0[i];
            float *uvy = &pkt.uv[0][1];
            float *uvx = &pkt.uv[0][0];
            TI16 *pos = pkt.pos;

            for (k = 3; k >= 0; k--) {
                s32 b = e->b;

                func_00282D30(pos, &D_L23_002A6390[e->a], D_L23_001B39D0);
                vars->spin = func_00283B98(vars->spin, D_L23_001B1BCC * 0.00029088825f);
                func_00283C28(vars->spin);
                if (D_L23_001B3714 == 0) {
                    fa = func_00283180(vars->spin) * D_L23_001B1BD8;
                    fb = func_00283198(vars->spin) * D_L23_001B1BDC;
                    fc = func_00283180(vars->spin) * D_L23_001B1BE0;
                    fd = func_00283198(vars->spin) * D_L23_001B1BE4;
                } else {
                    fa = func_00283180(vars->spin) * D_L23_001B1BF0;
                    fb = func_00283198(vars->spin) * D_L23_001B1BF4;
                    fc = func_00283180(vars->spin) * D_L23_001B1BF8;
                    fd = func_00283198(vars->spin) * D_L23_001B1BFC;
                }
                f = func_002A7878(D_L23_001B1BD0, D_L23_001B1BD4);
                *uvx = (D_L23_002A6D50[b][0] * fa + fb) * f;
                *uvy = D_L23_002A6D50[b][1] * fc + fd;
                pos++;
                e++;
                uvx += 2;
                uvy += 2;
            }
            func_00280B90(&pkt, m, 0);
        }
    }
}
