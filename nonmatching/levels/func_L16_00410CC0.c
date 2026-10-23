/* func_L16_00410CC0 (380 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 368 bytes against retail's 380; the frame is smaller than retail's 0x90 and
   the register allocation differs, so the bytes do not match.
   check.py (16_snivelak), with the source below:
     16_snivelak: 368 bytes, expected 380
   The table of short rows is reached through $gp (retail: `addiu $a0, $gp, 0x2720`),
   so the body needs a -G8 unit: `extern s16 D_L16_001B1710[4] __attribute__((sda));`
   gives the one-instruction form.
   What is measured and right:
   - the pointer table of the handle's index is at 0x1FE7C0 in level 16 (`lui $v0,0x20;
     addiu $v0,$v0,-0x1840`), so `extern u32 D_L16_001FE7C0[];` reproduces it.
   - the 16-byte copies are `lq`/`sq`, which this cc1 emits for a `mode(TI)` local;
     the state at the frame's base and the working buffer at +0x10 are two distinct
     locals, and the winning row is copied from the buffer into the state.
   - the row loop walks the eight rows of the short table and stops at the first
     row whose first word is -1; the inner loop counts the entries it looked at and
     stops after four, and the value that wins is written to the handle's +0x1F4,
     +0x1F8 and +0x1FC.
   Not matched: retail spills the row index and the destination pointer to the frame
   and recomputes the row address from the reloaded index every row, this source
   keeps both in registers and strength-reduces the address; retail's frame is 0x90
   against this source's smaller one.
   Next idea: the register pressure that makes retail spill the row index has to
   come from one more live value in the source; the two 16-byte locals and the
   handle, the table entry, the argument and the two floats are all live across the
   two calls. */

typedef unsigned char u8;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int s32;

typedef float f32;

typedef int TI128 __attribute__((mode(TI)));

extern s16 D_L16_001B1710[4] __attribute__((sda));

extern u32 D_L16_001FE7C0[];

extern float func_L01_00311C18(void *, void *, void *, void *);

extern float func_00282E80(void *, void *);

/* Walks the level's table of short rows, keeping the closest match of the handle's
   measured pair in the handle and the winning row in the handle's second half. */
void func_L16_00410CC0(u8 *arg0, u8 *arg1)
{
    TI128 state;
    TI128 work;
    u32 *s4;
    u8 *fp;
    u8 *dest;
    f32 best;
    f32 f;
    f32 g;
    s32 row;
    s32 count;
    s16 v;
    s16 *r;

    s4 = *(u32 **)(arg0 + 0x68);
    best = 2000.0f;
    fp = *(u8 **)(D_L16_001FE7C0 + s4[92]);
    state = *(TI128 *)arg1;
    dest = (u8 *)s4 + 0x200;
    for (row = 0; row < 8; row++) {
        r = D_L16_001B1710 + row * 4;
        v = r[0];
        if (v == -1)
            break;
        count = 0;
        for (;;) {
            if (v < row) {
                count++;
            } else {
                f = func_L01_00311C18(&work, fp + row * 16 + 0x10, fp + v * 16 + 0x10, arg1);
                g = func_00282E80(arg1, &work);
                if (g < best) {
                    best = g;
                    s4[0x7E] = v;
                    *(f32 *)((u8 *)s4 + 0x1FC) = f;
                    s4[0x7D] = row;
                    state = work;
                }
                count++;
            }
            if (count >= 4)
                break;
            v = *++r;
            if (v == -1)
                break;
        }
    }
    *(TI128 *)dest = state;
}
