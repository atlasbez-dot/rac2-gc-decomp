/* Readable C reconstruction, measured2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/1, us2: 0/1, pal: not carried.
 * 828 versus836 bytes; float/register allocation and particle call scheduling differ.
 * Tried: Full readable emitter sequence with verified BDCE8 four FP and C16C0 five FP inputs.
 * Reopen: A source lifetime or expression-order remedy with the complete helper ABI retained.
 * Historical notes below are preserved; their copy-wall claims are superseded
 * by the current qualified copy profiles. No handwritten-assembly inference.
 */

/* Not matched (worker 06, level-20 wave of 2026-10-20): not attempted
   in depth.

   The body has no 128-bit copy and no `$gp` access, so neither of the
   two walls of this level is in the way; it is 836 bytes with a frame
   of 0xD0, ten callee-saved registers and eight saved float registers
   (f21..f29), and it calls func_00282CF0, func_00282920, func_00282CC0
   and others.

   This body belongs in the `-G8` unit?  No: it reaches no global
   through `$gp`. */

/* ------------------------------------------------------------------
   level-20 wave of 2026-10-21, worker 07: the structure, and what it
   would take to match it.

   The body has NO 128-bit copy and reaches no global through $gp, so
   neither of the two walls of this level is in the way; it is 836 bytes
   with a frame of 0xD0, ten callee-saved registers ($s0..$s7 and $fp) and
   ten saved float registers (f20..f29).

   THE STRUCTURE.

     - $s2 = the argument; the first call is
       func_00282CF0(sp, D_L20_001B9FC0, arg0), i.e. it fills a 16-byte
       stack buffer at sp+0 from the global and the argument;
     - the two floats of that buffer go through func_00283248 and the
       result is kept in $f29; the constants are 0.2f ($f25), 1/60f
       ($f28), 1.0f ($f24), 210000.0f ($f27), 0.0f ($f22), 0x3FB2B8C4
       ($f26) and 0.1f ($f23);
     - the loop at .L0039C9A0 runs while $s6 >= 0, with $s6 starting at
       0x13 and the decrement in the delay slot of the call to
       func_002A7878 - a COUNT-DOWN loop (this is one of the bodies where
       the retail keeps the count-down form);
     - the body of the loop calls func_002A7878, func_00282D30,
       func_002A78D8, func_00283CF0, func_002A7878, func_002A78D8,
       func_002BDCE8 (f_00349DD8), func_00283CF0, func_00283CE0,
       func_002A7878, func_002A7878, func_002A78D8, func_00283B98,
       func_002AF000 (f_003385C8), func_002A78D8 and func_002C16C0
       (f_0034DA68);
     - three more stack buffers are used at sp+0x10 ($s4), sp+0x20 ($s5)
       and the float fields at +0x20, +0x24 and +0x28.

   WHY IT WAS NOT MATCHED HERE.  The float register allocation is the
   hard part: the retail keeps four constants in $f20..$f23 for the whole
   body and passes them as the second and third float arguments of
   func_002A78D8 and func_002B3BA8, and it re-uses $f0 for four
   different values in a row.  The frame is 0xD0 and every one of the
   eight calls has to set its arguments in the retail's order.

   This body belongs in the `-G8` unit?  No: it reaches no global through
   `$gp`.
   ------------------------------------------------------------------ */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
extern Vector D_L20_001B9FC0;
extern Vector D_0018A0E0;
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282D30(void *, const void *, float);
extern float func_00283248(float, float);
extern float func_002A7878(float, float);
extern float func_002A78D8(float, float);
extern int func_00283CF0(float);
extern float func_00283CE0(int);
extern float func_00283B98(float, float);
extern void func_002AF000(float *, float, float, float);
extern unsigned char *func_002BDCE8(void *, int, void *, unsigned int, int, float, float, float, float);
extern unsigned char *func_002C16C0(void *, void *, int, int, int, int, float, float, float, float, float);

void func_L20_0039C8C8(Vector *point) {
    Vector delta, velocity, position;
    unsigned char *particle;
    int count = 19;
    int lifetime;
    float heading, size, speed, pitch, yaw;
    func_00282CF0(&delta, &D_L20_001B9FC0, point);
    heading = func_00283248(delta.f[0], delta.f[1]);
    do {
        speed = func_002A7878(0.2f, 3.0f);
        func_00282D30(&velocity, &D_0018A0E0, -(speed * 0.016666668f));
        lifetime = func_00283CF0(func_002A78D8(1.0f, 2.0f));
        size = func_002A7878(0.3f, 0.75f) * 210000.0f;
        position.f[0] = point->f[0] + func_002A78D8(0.0f, 0.2f);
        position.f[1] = point->f[1] + func_002A78D8(0.0f, 0.2f);
        position.f[2] = point->f[2] + func_002A78D8(0.0f, 0.2f);
        particle = func_002BDCE8(&position, lifetime, &velocity, 0x7F202020, 0, 0.0f, 1.0f, 1.01f, size);
        if (particle) {
            *(short *)(particle + 10) = 90;
            particle[3] = 0x44;
            particle[9] = func_00283CF0(4.0f) + 0x40;
            *(float *)(particle + 0x3C) = func_00283CE0(5);
            *(int *)(particle + 0x24) = 3;
            particle[0x2A] = 0x30;
            particle[0x2B] = particle[10];
        }
        --count;
        speed = func_002A7878(1.0f, 2.0f);
        pitch = func_002A7878(0.0f, 1.3962636f);
        yaw = func_00283B98(heading, func_002A78D8(0.0f, 1.3962636f));
        func_002AF000(velocity.f, speed * 0.016666668f, yaw, pitch);
        position.f[0] = point->f[0] + func_002A78D8(0.0f, 0.1f);
        position.f[1] = point->f[1] + func_002A78D8(0.0f, 0.1f);
        position.f[2] = point->f[2] + func_002A78D8(0.0f, 0.1f);
        size = func_002A7878(0.1f, 0.5f);
        func_002C16C0(&position, &velocity, 30, 127, 0x7F7F7F, lifetime,
                      size * 210000.0f, 500.0f, 1.0f, 0.0f, 0.0f);
    } while (count >= 0);
}
