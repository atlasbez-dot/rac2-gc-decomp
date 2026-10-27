/* Retained nonmatching C (integrate/holds, 26 October 2026). Profile: -O2 -G0
 * -ffunction-sections -g. us 0/27 at 536/552 bytes; pal catalogue absent. Written from the asm.
 * The two-nop floor before the step's div.s (jal func_00283CE0, delay, nop, nop, div.s) comes
 * out right with the division in its own statement under the label floor after a call. Left:
 * retail keeps more loop invariants in callee-saved registers (s0-s7 and fp: the start vector's
 * address, the step pointer copied to fp, D_0018A0E0's high half, the velocity vector), and the
 * alpha compare at the end reads a register set to 0x50 in both arms while the call takes a
 * literal 0x50. Callees mapped through config/levels/functions.tsv.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
extern char D_L00_001FE940[];
extern char D_0018A0E0[];
extern s32 func_00283CF0(float);
extern f32 func_00283CE0(s32);
extern void func_00282F20(float *, float *, float);
extern void func_00282D30(float *, void *, float);
extern void func_00282CF0(float *, void *, float *);
extern void func_00282CC0(float *, float *, float *);
extern float func_002A78D8(float, float);
extern float func_002A7878(float, float);
extern s32 func_002A7820(s32, s32);
extern u8 *func_002C16C0(f32 *pos, f32 *sym, s32 a2, s32 a3, u32 color, s32 alpha, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16);
extern s32 func_001163B0(void);

void func_L00_0040B098(u8 *self, Vector *origin)
{
    Vector start;
    Vector velocity;
    Vector position;
    Vector step;
    Vector *from = &start;
    float length;
    float size;
    int count;
    int life;
    int spin;
    int alpha;
    u32 color;
    u8 *part;

    start.q = origin->q;
    length = *(float *)(*(u8 **)(self + 0x68) + 0x18);
    count = func_00283CF0(length * 10.0f) / 4;
    position.q = from->q;
    func_00282CF0(step.f, self + 0x10, start.f);
    size = func_00283CE0(count);
    func_00282F20(step.f, step.f, length / size);
    while (count-- > 0) {
        spin = func_00283CF0(func_002A78D8(1.0f, 3.0f));
        func_00282D30(velocity.f, D_0018A0E0, -(func_002A7878(0.2f, 1.0f) * 0.016666668f));
        life = func_002A7820(30, 50);
        size = func_002A7878(200.0f, 1000.0f);
        if (func_001163B0() & 2) {
            color = 0x404040;
            alpha = 0x50;
        } else {
            color = 0x7F7F7F;
            alpha = 0x50;
        }
        part = func_002C16C0(position.f, velocity.f, life, 0x50, color, spin, 21000.0f, size, 1.0f, 0.0f, 1.0f);
        func_00282CC0(position.f, position.f, step.f);
        if (part != 0) {
            part[2] = **(u8 **)(D_L00_001FE940 + 0x5C);
            part[3] = alpha == 0x40 ? 0x48 : 0x44;
        }
    }
}
