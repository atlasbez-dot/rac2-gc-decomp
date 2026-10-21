/* Matched byte for byte, but not landable: this body needs `qcopy`/`qzero` from
   include/common.h, which are inline assembly, and AGENTS.md's "Plain C" rule (no inline
   assembly in a function) forbids that as a matching route - docs/COMPILER-NOTES.md says it
   in as many words. Kept here as a starting point: the shape is right, and only the 128-bit
   copies would need a plain-C spelling that neither `mode(TI)` nor an aggregate gives yet.
   Removed from src/ on 2026-10-13. */

void func_L16_00411ED0(u8 *arg)
{
    u8 *s0 = arg;
    u8 *s1 = *(u8 **)(arg + 0x68);
    s32 buf[4];
    s32 rec[4];
    float t;

    func_30AD48(s0, func_313EA0(2), buf);
    qzero(rec);
    t = func_313F38(5.0f, 10.0f);
    *(float *)((u8 *)rec + 8) = -(t * (1.0f / 60.0f));
    func_41F1F0(s0, buf, rec, 1, 1.0f / 180.0f, (float)*(u8 *)(s1 + 0x36));
}

/* ---------------------------------------------------------------------------
 * wave 24, worker 14: the plain-C spelling reaches the retail's size (172 bytes,
 * the frame 0x40, the two calls with their arguments, the 5.0f/10.0f call, the
 * `mul.s`/`neg.s` pair, the 1/180 constant, the byte field converted with
 * `cvt.s.w` and the epilogue) but the 16-byte zero store is not the retail's
 * pair:
 *
 *   00411F00  addiu $v0,$sp,0x10   |  lui $at,0x40A0
 *   00411F04  sq   $zero,0x0($v0)  |  mtc1 $at,$f12
 *   ...                           |  sq $zero,0x10($sp)   (in the delay slot)
 *
 * Retail materialises the frame address into $v0 and stores with a zero
 * displacement; this cc1 folds the +0x10 into the store's displacement (the
 * reload accepts plus(reg, const) for TImode, and the cse rewrites the address
 * of a local into that plus).  The same fold then decides the other two
 * uses: retail stores the float at 0x18($sp) and passes sp+0x10 in $a2, this
 * cc1 keeps the materialised base in $v1 and adds 0x8 to it.
 * Tried: `rec = 0;` (168 bytes, the store folded in place), `*(TI128 *)&rec = 0;`
 * (168), `*(volatile TI128 *)&rec = 0;` (172, the size is right but the store
 * lands in the second call's delay slot), and the record's address taken into a
 * pointer (`TI128 *p = &rec;` - 176 bytes, the address is kept in $s1 across
 * the calls, so the frame grows).
 * The earlier note in this file (the inline-asm `qcopy`/`qzero` route) is
 * forbidden by AGENTS.md's "Plain C" rule; the C above is the plain-C
 * equivalent and it is one instruction away.
 */

typedef int TI128 __attribute__((mode(TI)));

extern void func_30AD48(void *, s32, void *);
extern s32 func_313EA0(s32);
extern float func_313F38(float, float);
extern void func_41F1F0(void *, void *, void *, s32, float, float);

void func_L16_00411ED0_w24(u8 *arg)
{
    u8 *s0 = arg;
    u8 *s1 = *(u8 **)(arg + 0x68);
    s32 buf[4];
    TI128 rec;
    float t;

    func_30AD48(s0, func_313EA0(2), buf);
    *(volatile TI128 *)&rec = 0;
    t = func_313F38(5.0f, 10.0f);
    *(float *)((u8 *)&rec + 8) = -(t * (1.0f / 60.0f));
    func_41F1F0(s0, buf, &rec, 1, 1.0f / 180.0f, (float)*(u8 *)(s1 + 0x36));
}
