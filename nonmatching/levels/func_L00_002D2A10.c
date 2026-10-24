/* Nonmatching reconstruction, 2026-10-23. Default game -O2 -G0 profile.
 * US, US2 and PAL: 0/22 placements, exactly 1112 bytes; first instruction
 * mismatch +0x8 (callee-saved GPR allocation). Stack frame and scalar root slots
 * are correct; TI copies and case-local pointer lifetimes still schedule differently.
 * Nine bounded trials covered scalar versus array roots, resident pointer scopes,
 * default/-g and qcopy profiles. qcopy variants were 1104 or 1116 bytes.
 * Reopen with a measured vector-copy/pointer-lifetime remedy for this pattern.
 * The prior screening-only note is retained below as historical context.
 */

/* Not attempted - screened, no C written: 1112 bytes, 22 places.

   The screening: every branch of the body stays inside its own bytes (the `jal`
   calls excepted), so the row is a whole function and not a catalogue fragment.
   Ten of the words are MMI (0x78/0x7A/0x7C/0x7E), five `lq`/`sq` pairs, which
   plain C reaches through a `mode(TI)` copy; no COP2 (VU0) word and no multiply or
   divide.  Nothing in the row looks like handwritten assembly.

   The body is the game's "the object the caller's argument names" handler in its
   long form: it builds several matrices, transforms vectors through them, and
   writes the results into the resident state.  At 1112 bytes it is three times the
   size of the body this wave matched, and its register allocation (seven
   callee-saved registers) and the order of its stores have to be reproduced word
   for word; the budget of this wave went to the smaller rows of the same file. */


extern char D_00189E20_8[];
extern void func_00282D30(void *, const void *, float);
extern void func_00282CC0(void *, const void *, const void *);
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282F20(void *, const void *, float);
extern void func_L00_0031EC88(void *, void *);
extern int func_002761F8(void *, void *, int, void *, int);
extern float func_L00_002D3EA8(void *);
extern float func_L00_002D3B00(void *);
extern int func_002A88A0(float *, float *, float, float, float);
extern char D_L00_001BF240[];

extern char D_L00_001BF220[];
typedef int MotionQuad __attribute__((mode(TI)));

/* Solve the forward collision time for each of the resident movement modes. */
float func_L00_002D2A10(float time, float acceleration, float height)
{
    float end[4], direction[4], curve[4], start[4];
    float root0a, root0b, root1a, root1b, root2a, root2b;
    float half, speed, position;
    char *state = D_00189E20_8;
    switch (*(unsigned char *)(state + 0x22C3)) {
    case 0: {
        if (height < 0.0f) {
            char *pos = state + 0x80;
            func_00282D30(end, state + 0xF0, time);
            end[2] -= (time * time + time) * (acceleration * 0.5f);
            func_00282CC0(end, end, pos);
            *(MotionQuad *)direction = *(MotionQuad *)(state + 0x80);
            func_L00_0031EC88(direction, end);
            *(MotionQuad *)direction = *(MotionQuad *)pos;
            if (func_002761F8(direction, end, 0x22, 0, 0)) {
                if (func_L00_002D3EA8(D_L00_001BF240) <= 0.8726647f)
                    height = *(float *)(D_L00_001BF240 - 0x18);
            }
        }
        state = D_00189E20_8;
        if (height > 0.0f) {
            half = acceleration * -0.5f;
            if (func_002A88A0(&root0a, &root0b, half,
                    *(float *)(state + 0xF8) - half,
                    *(float *)(state + 0x88) - height) > 0
                    && root0a > 0.0f)
                return root0a;
        }
        break;
    } case 1: {
        char *velocity = state + 0xF0;
        char *pos = state + 0x80;
        *(MotionQuad *)direction = *(MotionQuad *)(state + 0x2A0);
        func_00282F20(direction, direction, acceleration);
        func_00282D30(direction, direction, -1.0f);
        func_00282D30(end, velocity, time);
        func_00282D30(curve, direction, (time * time + time) * (acceleration * 0.5f));
        func_00282CC0(end, curve, end);
        func_00282CC0(end, pos, end);
        *(MotionQuad *)start = *(MotionQuad *)(pos);
        func_L00_0031EC88(start, end);
        if (func_002761F8(pos, end, 0x22, 0, 0)) {
            half = acceleration * -0.5f;
            speed = func_L00_002D3B00(velocity) - half;
            position = func_L00_002D3B00(pos);
            position -= func_L00_002D3B00(D_L00_001BF220);
            if (func_002A88A0(&root1a, &root1b, half, speed, position) > 0
                    && root1a > 0.0f)
                return root1a;
        }
        break;
    } case 2: {
        char *velocity = state + 0xF0;
        char *pos = state + 0x80;
        curve[0] = 100.0f;
        curve[2] = 100.0f;
        curve[1] = 100.0f;
        func_00282CF0(direction, pos, curve);
        func_00282F20(direction, direction, acceleration);
        func_00282D30(direction, direction, -1.0f);
        func_00282D30(end, velocity, time);
        func_00282D30(curve, direction, (time * time + time) * (acceleration * 0.5f));
        func_00282CC0(end, curve, end);
        func_00282CC0(end, pos, end);
        *(MotionQuad *)start = *(MotionQuad *)(pos);
        func_L00_0031EC88(start, end);
        if (func_002761F8(pos, end, 0x22, 0, 0)) {
            half = acceleration * -0.5f;
            speed = func_L00_002D3B00(velocity) - half;
            position = func_L00_002D3B00(pos);
            position -= func_L00_002D3B00(D_L00_001BF220);
            if (func_002A88A0(&root2a, &root2b, half, speed, position) > 0
                    && root2a > 0.0f)
                return root2a;
        }
        break;
    } }
    return time;
}
