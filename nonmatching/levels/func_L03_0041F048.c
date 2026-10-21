/* 0 of 1 places match - 128-bit LQ/SQ copy; MEASURED not reachable from C.
   Level 3 (03_endako), 0x0041F048, 72 bytes:
     0031B920(a0, 7, 2) after the full frame save; then
       lw    $s0,0x68($v0)
       addiu $s0,$s0,0x1B0
       lq    $v0,0x0($s1)      (0x7A220000, opcode 0x1E = LQ)
       sq    $v0,0x0($s0)      (0x7E020000, opcode 0x1F = SQ)
       ... epilogue
   i.e. a 16-byte vector copy: *(V4 *)(ctx->field_68 + 0x1B0) = *src.
   Four spellings were compiled this session (Vector4 aggregate assignment, four
   scalar f32 stores, the copy before/after the call, char* + cast): all give 92-96
   bytes of ld/sd word moves and this cc1 never emits lq/sq, so the retail's two
   128-bit instructions cannot come out of C here. Needs ASM_FUNC (lead decision
   for the EE 128-bit moves). Same result as func_L02_003A8770 / func_L07_002E2090. */

#include "include_asm.h"

typedef float Vector4[4];

extern void func_0031B920(void *, int, int);

void func_L03_0041F048(char *self, Vector4 *src)
{
    Vector4 *dst = (Vector4 *)(*(char **)(self + 0x68) + 0x1B0);

    func_0031B920(self, 7, 2);
    *dst = *src;
}

/* ---------------------------------------------------------------------------
 * wave 24, worker 14: same wall, measured again with the `mode(TI)` cast, which
 * does reach lq/sq (so the retail's pair is not the problem) - only the
 * materialised address is.  The candidate below is 68 bytes against retail's 72:
 *
 *   0041F070  addiu $s0,$s0,0x1B0   |  sq $v0,0x1B0($s0)
 *   0041F074  lq   $v0,0x0($s1)    |  lq $v0,0x0($s1)
 *   0041F078  sq   $v0,0x0($s0)    |  sq $v0,0x0($s0)
 *
 * Every other instruction matches (the frame, the three saves, the call to
 * func_31B920 with its delay slot, the epilogue).  Retail materialises the
 * destination address into $s0 and stores with a zero displacement; this cc1
 * folds the +0x1B0 into the store's displacement.  The fold is the reload
 * (GO_IF_LEGITIMATE_ADDRESS accepts plus(reg, const_int) for TImode) plus the
 * cse's find_best_addr, which rewrites the address of a pointer *variable*
 * into a plus.  Measured: the offset as a plain expression, the pointer
 * incremented in a statement (`state += 0x1B0`), the pointer held in a
 * `volatile` local, the store written through `volatile TI128 *`, the address
 * written inline (`*(u8 **)(entity+0x68) + 0x1B0`) - all fold the same way.
 * 1,722 places in the retail materialise a 128-bit address this way and none of
 * them is matched, so the shape is a wall and not a spelling.
 */

typedef int TI128 __attribute__((mode(TI)));

extern void func_31B920(void *entity, int a, int b);

void func_L03_0041F048_w24(u8 *entity, void *src)
{
    u8 *state = *(u8 **)(entity + 0x68);

    func_31B920(entity, 7, 2);
    *(volatile TI128 *)(state + 0x1B0) = *(TI128 *)src;
}
