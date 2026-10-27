/* func_L04_00451150, 732 bytes, 2 placements (levels 04, 11); family F44 (nine
   per-level copies of 680-772 bytes).  Default -O2 -G0 unit.
   M30: the body is recovered (the camera-to-point direction flattened, the
   rotation axis, the two func_002C2210 spawns per pass with retail's argument
   order, the 1/60 scale, the side = rand(2) or -1 written as side-- so the
   movn takes side - 1).  744 bytes against 732: the jitter low bound is read
   from dir[2] once (retail loads it in the loop preheader, here in the entry
   block), and here loop.c keeps &axis (sp+0x30) and a second copy of &dir in
   callee-saved registers ($s5, $s7) where retail rebuilds `addiu $a2,$sp,0x30`
   at the call; that adds $s7 to the frame (0xC0 against 0xB0).
*/
#include "include_asm.h"
#include "common.h"

extern char D_L04_001B9680[];

extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern float func_002A78D8(float, float);
extern void func_002ACEC0(void *, void *, void *, float);
extern char *func_002C2210(void *, int, unsigned int, int, int, void *, int, float, float, float);
extern int func_00283CF0(float);

/* Throws count pairs of sparks from pos, spread around the flattened direction to the
   camera and nudged at random. */
void func_L04_00451150(float *pos, int count)
{
    float vel[4];
    float at[4];
    float dir[4];
    float axis[4];
    float back[4];
    float size;
    float jitter;
    int side;
    int i;
    char *p;

    func_00282CF0(dir, D_L04_001B9680, pos);
    func_00282F20(back, dir, 0.3f);
    dir[2] = 0.0f;
    axis[0] = 0.0f;
    axis[1] = 0.0f;
    axis[2] = 1.0f;
    axis[3] = 1.0f;
    jitter = dir[2];
    for (i = 0; i < count; i++) {
        size = func_002A7878(0.5f, 2.0f);
        side = func_002A77E0(2);
        if (side == 0)
            side--;
        func_002ACEC0(vel, dir, axis, func_002A7878(-1.0471977f, 1.0471977f));
        func_00282F20(vel, vel, func_002A7878(0.05f, 3.0f) * 0.016666668f);
        vel[2] = func_002A7878(1.0f, 5.0f) * 0.016666668f;
        func_00282CC0(at, pos, back);
        pos[0] += func_002A78D8(jitter, 0.15f);
        pos[1] += func_002A78D8(jitter, 0.15f);
        pos[2] += func_002A78D8(jitter, 0.15f);
        p = func_002C2210(at, 0x3C, 0x7F207F7F, 0, side, vel, 0, size * 0.1f, size, 0.002f);
        if (p)
            p[9] = func_00283CF0(4.0f) + 0x70;
        p = func_002C2210(at, 0x3C, 0x7F7F7F7F, 1, -side, vel, 0, size * 0.07f, size * 0.7f, 0.002f);
        if (p)
            p[9] = func_00283CF0(4.0f) + 0x70;
    }
}
