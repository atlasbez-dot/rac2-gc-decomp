/*
 * Near miss, wave 10 worker 06 (2026-10-25).
 * Profile: -O2 -G0 -ffunction-sections (boot default).
 * Retail: 504 bytes, 2 places (boot and 00_aranos_tutorial).
 * Best measured C: 500 bytes, 0 of 2 places.
 *   wslcmp: func_0031D070: 0 of 2 places match [boot: 500 bytes, expected 504]
 * Body reproduced: the frame (0x90), the seven saved FPRs, all six calls, the
 * 128-bit position save (volatile TImode store to a loop-invariant pointer),
 * both particle calls with 0x7F207F7F/0x7F7F7F7F, 0.1f/0.25f size, the
 * 0.3490659f/1.5358899f elevation and the 0.006f tail constant.
 * Remaining difference: retail's sign select is
 *   addiu v1,s0,-1 ; movn v1,v0,s0 ; daddu s0,v1   (three instructions)
 * and this cc1 emits sltiu/subu or a two-instruction movn.  The save order
 * (s1,s0,s2,s3) and the loop decrement placement also differ.
 * Reopen only with a source form that makes this cc1 emit the three-instruction
 * select, which would also account for the missing four bytes.
 */
typedef int V4_31D070 __attribute__((mode(TI)));
extern float func_002A7878(float, float);
extern float func_002A78D8(float, float);
extern float func_002A7940(void);
extern int func_002A77E0(int);
extern void func_002AF000(float *, float, float, float);
extern void *func_002C2210(void *, int, unsigned int, int, int, void *, int,
                           float, float, float);

void func_0031D070(float *position, int count)
{
    float velocity[4];
    V4_31D070 saved;
    V4_31D070 *savedp = &saved;
    float size, heading, elevation, magnitude;
    unsigned int sign;

    if (count > 0) do {
        size = func_002A7878(0.1f, 0.25f);
        sign = func_002A77E0(2);
        sign = sign ?: sign - 1;
        heading = func_002A7940();
        elevation = func_002A7878(0.3490659f, 1.5358899f);
        magnitude = func_002A7878(0.05f, 0.1f);
        func_002AF000(velocity, magnitude, heading, elevation);
        *(volatile V4_31D070 *)savedp = *(V4_31D070 *)position;
        position[0] += func_002A78D8(0.0f, 0.15f);
        position[1] += func_002A78D8(0.0f, 0.15f);
        position[2] += func_002A78D8(0.0f, 0.15f);
        func_002C2210(position, 30, 0x7F207F7F, 0, sign, velocity, 0,
                      size * 0.1f, size, 0.006f);
        func_002C2210(position, 30, 0x7F7F7F7F, 1, -sign, velocity, 0,
                      size * 0.07f, size * 0.7f, 0.006f);
    } while (--count);
}
