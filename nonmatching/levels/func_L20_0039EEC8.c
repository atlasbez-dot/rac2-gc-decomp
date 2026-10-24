/* Readable C reconstruction, measured2026-10-23.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/1, us2: 0/1, pal: not carried.
 * 876 versus836 bytes; common vector/history addresses and initialization-loop scheduling differ.
 * Tried: Measured8-by25 history vectors and8 normals; copy/barrier and explicit assembler G8 trials.
 * Reopen: A truthful vector/global addressing and loop scheduling remedy.
 * Historical notes below are preserved; their copy-wall claims are superseded
 * by the current qualified copy profiles. No handwritten-assembly inference.
 */

/* Not matched (worker 05, level-20 wave 5, 2026-10-21).

   The body is 836 bytes with a frame of 0x60 and four 128-bit copies:

       addiu $v1, $s6, 0x10 ; lq $v0,0x0($s0) ; sq $v0,0x0($v1)   ; dest materialised
       lq $v0,0x0($s5)      ; sq $v0,0x0($s3)                    ; BOTH plain registers
       addiu $v1, $s3, 0x10 ; lq $v0,0x0($fp) ; sq $v0,0x0($v1)   ; dest materialised
       addiu $v1, $s3, 0x20 ; lq $v0,0x0($s7) ; sq $v0,0x0($v1)   ; dest materialised

   The second copy is the plain-pointer form and this compiler reproduces it;
   the other three materialise the destination, which this compiler folds
   (`sq $v0,0x10($s6)` and so on).  The mechanism and every escape measured
   are in the note on func_L20_0039E770 in this directory.

   What the rest of the body needs (for the next worker):

     * the frame is 0x60 and the saved registers are $s0, $s1, $s2, $s3, $s4,
       $s5, $s6, $s7, $fp and $ra, with $f20 in the frame - eleven saved
       registers, so the body is long;
     * the calls are f_00325040, f_00302A38, f_00302548 (many times),
       f_00302260 (twice), f_00302378 (four times) and f_00302290 (twice);
     * the globals are D_234880, D_235500, D_235540, D_235550 and D_235560
       (level data, taken with lui/addiu), D_1B388C, D_1B38AC and D_1B38C2
       (the same) and D_001AEDA0 (read with lui + lw, so it needs
       __attribute__((nosda)));
     * the float constants are 0x3F800000 (1.0f) and the pi/180 constant
       0x3C8EFA36, which needs the literal 0.017453294f in this compiler;
     * the two loops (the `sw $zero,0x0($v0)` loop over D_1B38AC with a count
       of 7 and the `sh $zero,0x0($v0)` loop over D_1B38C2 with a count of 9)
       are counted loops, and this compiler's loop optimiser turns a counted
       loop into a count-down (`addiu $v1,$v1,-1` ; `bgez`) where the retail
       keeps the count-up - that is a separate obstacle from the copy.

   This body belongs in the -G8 unit?  YES: it reads a float through $gp
   (`lwc1 $f12,-0x2B0($gp)`, eight times), which only comes out of a file
   built with -G8, so it cannot live in the -G0 unit
   (src/levels/20_yeedil/L20_0039C448.c).  The gp offset is -0x2B0, that is
   the level-20 address 0x001AED40, the float 6.0f (0x40C00000); the C name
   is D_L20_001AED40 and it needs __attribute__((sda)). */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
extern unsigned char *func_0029EFD0(int);
extern void func_00283360(float *);
extern void func_00282F20(void *, const void *, float);
extern void func_00282CC0(void *, const void *, const void *);
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282DD8(void *, const void *, const void *);
extern unsigned int D_L20_001AEDA0 __attribute__((nosda));
extern float D_L20_001AED40;
extern int D_L20_001B3870[8];
extern int D_L20_001B3890[8];
extern short D_L20_001B38B0[10];
extern float D_L20_001B3904 __attribute__((nosda));
extern Vector D_L20_00234880[8][25];
extern Vector D_L20_00235500[8];

unsigned char *func_L20_0039EEC8(int owner, const Vector *position) {
    unsigned char *object = func_0029EFD0(0x1316);
    unsigned char *state;
    Vector *x, *y, *z;
    int i;
    if (object) {
        *(Quadword *)(object + 0x10) = position->q;
        x = (Vector *)(object + 0xC0);
        y = (Vector *)(object + 0xD0);
        z = (Vector *)(object + 0xE0);
        func_00283360((float *)x);
        state = *(unsigned char **)(object + 0x68);
        object[0x30] = 255;
        *(int *)(object + 0xB8) = owner;
        *(int *)state = 5;
        *(int *)(state + 0x14) = 0;
        *(int *)(state + 0x10) = 0;
        *(unsigned int *)(state + 4) = D_L20_001AEDA0 & 0xFFFFFF;
        for (i = 7; i >= 0; --i) D_L20_001B3870[i] = 0;
        func_00282F20(&D_L20_00234880[0][0], x, D_L20_001AED40);
        D_L20_00235500[0].q = z->q;
        func_00282F20(&D_L20_00234880[1][0], y, D_L20_001AED40);
        D_L20_00235500[1].q = x->q;
        func_00282F20(&D_L20_00234880[2][0], z, D_L20_001AED40);
        D_L20_00235500[2].q = y->q;
        func_00282CC0(&D_L20_00234880[3][0], x, z);
        func_00282F20(&D_L20_00234880[3][0], &D_L20_00234880[3][0], D_L20_001AED40);
        func_00282DD8(&D_L20_00235500[3], &D_L20_00234880[3][0], y);
        func_00282F20(&D_L20_00235500[3], &D_L20_00235500[3], 1.0f);
        func_00282CC0(&D_L20_00234880[4][0], x, y);
        func_00282F20(&D_L20_00234880[4][0], &D_L20_00234880[4][0], D_L20_001AED40);
        func_00282DD8(&D_L20_00235500[4], &D_L20_00234880[4][0], z);
        func_00282F20(&D_L20_00235500[4], &D_L20_00235500[4], 1.0f);
        func_00282CF0(&D_L20_00234880[5][0], y, z);
        func_00282F20(&D_L20_00234880[5][0], &D_L20_00234880[5][0], D_L20_001AED40);
        func_00282DD8(&D_L20_00235500[5], &D_L20_00234880[5][0], x);
        func_00282F20(&D_L20_00235500[5], &D_L20_00235500[5], 1.0f);
        func_00282CF0(&D_L20_00234880[6][0], x, z);
        func_00282F20(&D_L20_00234880[6][0], &D_L20_00234880[6][0], D_L20_001AED40);
        func_00282DD8(&D_L20_00235500[6], &D_L20_00234880[6][0], y);
        func_00282F20(&D_L20_00235500[6], &D_L20_00235500[6], 1.0f);
        func_00282CF0(&D_L20_00234880[7][0], x, y);
        func_00282F20(&D_L20_00234880[7][0], &D_L20_00234880[7][0], D_L20_001AED40);
        func_00282DD8(&D_L20_00235500[7], &D_L20_00234880[7][0], z);
        func_00282F20(&D_L20_00235500[7], &D_L20_00235500[7], 1.0f);
        for (i = 7; i >= 0; --i) D_L20_001B3890[i] = 0;
        for (i = 9; i >= 0; --i) D_L20_001B38B0[i] = 0;
        D_L20_001B3904 = 1.0f;
    }
    return object;
}
