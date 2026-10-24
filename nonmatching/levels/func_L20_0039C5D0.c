/* Readable C reconstruction, measured2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/1, us2: 0/1, pal: not carried.
 * 760 versus756 bytes; frame A0 versus90 and common constant-vector address hoisting differ.
 * Tried: Typed vector reconstruction and qualified copy/barrier; -mno-split-addresses did not improve the trial.
 * Reopen: A truthful global-vector binding/address model and local lifetime remedy.
 * Historical notes below are preserved; their copy-wall claims are superseded
 * by the current qualified copy profiles. No handwritten-assembly inference.
 */

/* Not matched (worker 05, level-20 wave 5, 2026-10-21).

   The body is 756 bytes with a frame of 0x90 and eight calls.  The one thing
   that stops it is its single 128-bit copy:

       addiu      $v1, $sp, 0x10      ; the address of a local buffer
       lq         $v0, 0x0($s2)       ; $s2 = *(arg0 + 0x68), a plain register
       sq         $v0, 0x0($v1)       ; the destination: the local buffer

   The source is a plain register and this compiler reproduces it; the
   DESTINATION is the wall: the retail keeps the address of the stack local in
   a register, this compiler folds the offset into the store
   (`sq $v0,0x10($sp)`).

   The mechanism and every escape measured are in the note on
   func_L20_0039E770 in this directory: the CSE's find_best_addr() replaces
   the address pseudo of a 128-bit access by the `plus` of a register and a
   constant (the class member with the highest rtx cost wins, and the plus
   costs 8 against the pseudo's 1), and the reload then prints the constant as
   the displacement.  The address stays in a register only when the pointer's
   value is not a plus of a register: a symbol, a load, a call result, or a
   pointer carried by a loop.  A stack local is a plus of $sp, so it folds
   like any other base.

   What the rest of the body needs (for the next worker):

     * the calls are f_0032F680, f_00353190 (three times), f_00302290,
       f_003022D0, f_0032F718, f_0032F778 (three times) and f_00302260;
     * the globals are the boot's D_001A8F20 (its address is taken with
       lui/addiu, so it is `extern char D_001A8F20[]` without sda), D_1FFC14
       and D_1B2AC8 (both read with lui + lw, so they need __attribute__((nosda)));
     * the float constants are 0x48CD1400 (210000.0f), 0x3DCCCCCD (0.1f),
       0x3D4CCCCD (0.05f), 0x484D1400, 0x47241000 and 0x3E99999A (0.3f);
     * the `div $zero,$v1,$v0` is guarded by `beql $v0,$zero` plus `break 0,7`
       (the divide-by-zero trap the compiler emits for an integer division),
       and the same guard appears on the `mfhi` of D_1B2AC8 / 10.

   This body belongs in the -G8 unit?  No: it reaches no global through $gp. */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
extern int func_002A77E0(int);
extern unsigned char *func_002C65A0(void *, void *, int, int, int, int, int, int, float, float, float);
extern float func_002A7878(float, float);
extern float func_002A78D8(float, float);
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282D30(void *, const void *, float);
extern void func_00282CC0(void *, const void *, const void *);
extern Vector D_L20_001A8F20;
extern unsigned char *D_L20_001FFC14;
extern unsigned char *D_L20_001FFBF4;
extern int D_L20_001B2AC8;

void func_L20_0039C5D0(unsigned char *object) {
    Vector delta, position, jitter;
    unsigned char *state = *(unsigned char **)(object + 0x68);
    unsigned char *particle;
    int shade = func_002A77E0(255);
    int count;
    float size;
    particle = func_002C65A0(object + 0x10, &D_L20_001A8F20, 2, 0x202080, shade, 64, 16, 0,
                            420000.0f, 420000.0f, 0.0f);
    if (particle) particle[2] = *D_L20_001FFC14;
    particle = func_002C65A0(object + 0x10, &D_L20_001A8F20, 2, 0x202080, (shade + 128) % 255, 64, 16, 0,
                            420000.0f, 420000.0f, 0.0f);
    if (particle) particle[2] = *D_L20_001FFC14;
    func_00282CF0(&delta, object + 0x10, state);
    func_00282D30(&delta, &delta, 0.1f);
    position.q = *(Quadword *)state;
    count = 4;
    do {
        --count;
        shade = func_002A77E0(255);
        size = func_002A7878(0.1f, 0.3f);
        jitter.f[0] = position.f[0] + func_002A78D8(0.0f, 0.05f);
        jitter.f[1] = position.f[1] + func_002A78D8(0.0f, 0.05f);
        jitter.f[2] = position.f[2] + func_002A78D8(0.0f, 0.05f);
        func_002C65A0(&jitter, &D_L20_001A8F20, 15, 0x808080, shade, 32, 0, 0,
                      size * 210000.0f, size * 42000.0f, 0.0f);
        func_00282CC0(&position, &position, &delta);
    } while (count >= 0);
    if (D_L20_001B2AC8 % 10 == 0) {
        particle = func_002C65A0(object + 0x10, &D_L20_001A8F20, 30, 0x202080, 0, 32, 0, 0,
                                2100.0f, 420000.0f, 0.0f);
        if (particle) particle[2] = *D_L20_001FFBF4;
    }
}
