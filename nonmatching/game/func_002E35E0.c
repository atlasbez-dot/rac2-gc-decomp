/* func_002E35E0 (464 bytes, boot 0x2E35E0, 28 places)
 *
 * Draft, not compiled: the body is decoded, the switch on the counter and the
 * float work are not reproduced yet.
 *
 * The body: it calls func_002E37B0, then func_283388 with the block at
 * 0x1B20F0 and clears the halfword at +4 of the block at 0x1B20C0, then calls
 * func_282C88 with the frame.  It reads the halfword at +6 of that block; when
 * it is not positive it skips the loop.  Otherwise it sets four float
 * constants (-0.1, -0.05, 0.1 and 0.0) and runs a loop over the counter $s0:
 * the counter selects one of four cases (0, 1, 2, 3) with a branch chain, and
 * each case writes a float parameter into the frame (at +0, +4 and +8) and a
 * second float into $f13; the case bodies use a float constant read through
 * `$gp` (-0x321C).  After the case the body calls func_283B98, calls
 * func_283430 with the block at 0x1B20F0 and the frame, copies the 16 bytes at
 * 0x1B20D0 to 0x1B2120 (`lq`/`sq`), calls func_002E3940 with the counter,
 * counts the counter up and loops while it is below the halfword at +6.  When
 * the loop ends it calls func_002E3820 and then func_002FC560 twice, with the
 * strings built from the halfword at 0x1A72E0.
 *
 * The unit has to be built with -G8: the case bodies read a float constant
 * through `$gp` (-0x321C).
 *
 * What has to be reproduced: the switch (the retail uses a branch chain with
 * `b`/`beql`, not a jump table), the order of the four float constants and the
 * FPU registers they are built in, the `lq`/`sq` copy and the nine calls.
 *
 * What would unblock it: a switch spelling that this cc1 lays out as the
 * retail's branch chain (the level 20 wave: a `switch` often keeps the retail
 * shape where an if/else does not), and the float constants' register
 * allocation.
 */
typedef float f32;

extern void func_002E37B0(void);
extern void func_283388(void *);
extern void func_282C88(void *);
extern f32 func_283B98(void);
extern void func_283430(void *, void *);
extern void func_002E3940(int);
extern void func_002E3820(void);
extern void func_002FC560(int, unsigned long long);

void func_002E35E0(void)
{
    short count;

    func_002E37B0();
    func_283388((void *)0x1B20F0);
    func_282C88((void *)0);
    count = *(short *)(0x1B20C0 + 6);
    while (count-- > 0) {
        f32 a = 0.0f;
        f32 b = 0.1f;

        func_283B98();
        func_283430((void *)0x1B20F0, (void *)0);
        func_002E3940(0);
    }
    func_002E3820();
    func_002FC560(0x47, 0x5360BULL);
    func_002FC560(0x4E, 0);
}
