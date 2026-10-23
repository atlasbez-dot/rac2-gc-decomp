/* func_L16_00410E40 (356 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 364 bytes against retail's 356; the second loop's modulo and the register
   allocation differ.
   check.py (16_snivelak), with the source below:
     16_snivelak: 364 bytes, expected 356
   What is measured and right:
   - the table of the handle's index is at 0x447FE7C0 in level 16 (`lui $v1,0x4480;
     addiu $v1,$v1,-0x1840`), so `extern u32 D_L16_447FE7C0[];` reproduces it.
   - the second argument of func_L16_00417788 is the handle's word at +0x24C and the
     first argument of func_002ACBC8 is that call's RESULT, not the table entry: the
     retail loads the table entry in the delay slot of the call and reads the return
     value in $v0 afterwards (`daddu $fp,$v0,$zero`).
   - the first loop is a do-while whose index is incremented in the delay slot of the
     `bc1fl` on the "not smaller" path and in the body on the other one.
   Not matched: retail keeps the result of func_L16_00417788 in $fp across both
   loops, this source spills it; retail computes the remainder's `(a0 + 7)` inside
   the loop, this source hoists it as an induction variable; and retail's second loop
   increments its index only on the "no result" path, which this source reproduces
   but with the branches the other way round.
   Next idea: keep the second loop's index in a variable that the compiler cannot
   strength-reduce (the retail body reloads it from the stack), so the modulo is
   computed from the reloaded value. */

typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int s32;

typedef float f32;

typedef int TI128 __attribute__((mode(TI)));

extern u32 D_L16_447FE7C0[];

extern s32 func_L16_00417788(void *);

extern s32 func_002ACBC8(void *, s32);

extern s32 func_002A77E0(s32);

extern float func_00282E80(void *, void *);

extern void func_L16_00410CC0(u8 *, u8 *);

/* Picks the row of the level's table that is closest to the handle and copies it
   into the handle's second half. */
void func_L16_00410E40(u8 *arg0)
{
    u32 *base;
    u32 *s2;
    u8 *s3;
    s32 fpi;
    u8 *p;
    s32 i;
    s32 best;
    s32 found;
    s32 b2;
    s32 rem;
    f32 bestf;
    f32 f;

    base = D_L16_447FE7C0;
    i = 0;
    best = -1;
    s2 = *(u32 **)(arg0 + 0x68);
    bestf = 1024.0f;
    s3 = *(u8 **)(base + s2[92]);
    fpi = func_L16_00417788((void *)s2[147]);
    p = s3 + 0x10;
    do {
        f = func_00282E80(arg0 + 0x10, p);
        if (f < bestf) {
            bestf = f;
            best = i;
        }
        i++;
        p += 0x10;
    } while (i < 8);
    found = -1;
    b2 = func_002A77E0(8);
    i = 0;
    s2 = (u32 *)((u8 *)s2 + 0x200);
    while (i < 8) {
        rem = (i + b2) % 8;
        if (func_002ACBC8(s3 + (rem * 16 + 0x10), fpi) == 0) {
            i++;
            continue;
        }
        if (rem == best)
            continue;
        found = rem;
        break;
    }
    *(TI128 *)s2 = *(TI128 *)(s3 + found * 16 + 0x10);
    func_L16_00410CC0(arg0, (u8 *)s2);
}
