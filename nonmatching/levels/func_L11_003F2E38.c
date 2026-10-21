/* func_L11_003F2E38 (200 bytes, 1 place) - best attempt, NOT MATCHED.
 *
 * `tools/check.py func_L11_003F2E38 --diff`: "11_joba: instruction at +0x10 differs",
 * 18 differing lines.  The body itself is retail's: the frame, the seven `sd`/`ld` of the
 * save block, the `addiu $v0,$zero,1`, the context lookup (`lw $a0,0x68($s2)` then
 * `lw $v1,0x258($a0)`), the branch-likely shape around the aim-vector source, the
 * `lq`/`sq` 16-byte copy, the four calls and the three float results.
 *
 * What is left is register allocation, in two places only:
 *
 *   (a) The two pointer parameters trade $s1 and $s2.  Retail copies the SECOND
 *       parameter (the 16-byte destination) into $s1 and the first (the record) into $s2;
 *       this cc1 does the opposite.  Everything else follows from that swap, which is
 *       why the diff is 18 lines and not 2.
 *   (b) The merged pointer (the aim-vector source, either the context's 0x80 slot or the
 *       boot constant D_00189EA0) lands in $v0, so the copy reads `lq $v0,0($v0)`; retail
 *       keeps it in $v1 and reads `lq $v0,0($v1)`.
 *
 * Measured, no effect on either: the pointer selection as an if/else, as a ternary and
 * inlined into both arms of the condition; the copy direct and through a TI128 temporary;
 * the second argument's type as u8 *, f32 * and void *; the local buffer as f32[4] and as
 * char[16]; `arg0 + 0x10` computed once into a variable and written out at each call;
 * a local copy of the destination pointer; and the -G8 profile (a unit of its own with
 * D_00189EA0 declared `nosda`), which allocates exactly the same way.
 *
 * Isolated in a standalone unit with the same shape, the two pointer parameters swap
 * only when the destination buffer's live range is stretched past the last call (adding
 * one more call to the buffer does it, which is not in the retail) - so retail's source
 * must keep the destination buffer live past the fourth call, or shape the parameters
 * some other way this cc1 does not reproduce.
 */
#include "include_asm.h"

typedef unsigned char u8;
typedef signed int s32;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));

extern char D_00189EA0[];
extern void func_00282CF0(f32 *a0, const f32 *a1, const f32 *a2);
extern f32 func_002B04E0(u8 *a0, f32 *a1, s32 a2);
extern f32 func_00282E48(u8 *a0, u8 *a1);
extern f32 func_00282E80(u8 *a0, u8 *a1);

void func_L11_003F2E38(u8 *arg0, u8 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    f32 buf[4];
    u8 *p;
    u8 *q;
    u8 *r;

    q = *(u8 **)(arg0 + 0x68);
    if (*(s32 *)(q + 0x258) == 1) {
        p = q + 0x80;
    } else {
        p = D_00189EA0;
    }
    *(TI128 *)arg1 = *(TI128 *)p;
    r = arg0 + 0x10;
    func_00282CF0(buf, (const f32 *)arg1, r);
    *arg4 = func_002B04E0(arg0, buf, 0);
    *arg2 = func_00282E48(r, arg1);
    *arg3 = func_00282E80(r, arg1);
}
