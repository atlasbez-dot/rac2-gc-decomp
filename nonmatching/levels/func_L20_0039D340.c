/* Readable C reconstruction, measured2026-10-23.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/1, us2: 0/1, pal: not carried.
 * 844 versus828 bytes; settings initialization scheduling and mixed GP/address allocation differ.
 * Tried: Honest four-float settings view with G16 and matching assembler threshold; evaluating parameters earlier was worse.
 * Reopen: A verified settings/data declaration and initialization-order remedy.
 * Historical notes below are preserved; their copy-wall claims are superseded
 * by the current qualified copy profiles. No handwritten-assembly inference.
 */

/* Not matched (worker 07, level-20 wave of 2026-10-21): the 128-bit copy wall,
 * and this body needs the -G8 profile.
 *
 * TWO FINDINGS.
 *
 * 1. THIS BODY REACHES FOUR FLOATS THROUGH $gp:
 *
 *      0039D3C8  lwc1 $f1, -0x300($gp)
 *      0039D3CC  lwc1 $f2, -0x2F4($gp)
 *      0039D3D0  lwc1 $f3, -0x2F8($gp)
 *      0039D3D4  lwc1 $f12, -0x2FC($gp)
 *
 *    so it belongs in a -G8 unit of its own (a sibling file named
 *    L20_0039D340-g8.c, which gets -G8 from its name).  It is the only
 *    function of this wave that needs it.  In a -G0 unit the four floats
 *    come out as absolute loads and the body cannot match.
 *
 * 2. THE 128-BIT COPY WALL.  The retail's only copy is
 *
 *      0039D610  addiu $a0, $v1, 0x10      ; the source, object + 0x10
 *      0039D618  addiu $v1, $s1, 0x1F0     ; the destination, state + 0x1F0
 *      0039D61C  lq    $v0, 0x0($a0)
 *      0039D620  sq    $v0, 0x0($v1)
 *
 *    - the address is MATERIALISED into a register and the lq/sq use a ZERO
 *    displacement (the shape the corrected rule of wave 5 describes).  Both
 *    addresses are `base + constant` with a runtime base, so plain C folds
 *    them into the displacement (`lq $v0,0x10($v1) ; sq $v0,0x1F0($s1)`) and
 *    the escape does not apply: the base is not a plain pointer, not a
 *    symbol and not a stack slot at offset 0, and the offsets are inside the
 *    TImode displacement range [-32768, 32751] and inside the addiu immediate
 *    range.
 *
 * THE STRUCTURE (for whoever picks it up after the wall is solved).
 *   - the frame is 0x30 with $s0..$s3 and $ra saved;
 *   - $s2 = the argument, $s1 = the object (arg0 + 0x68);
 *   - the first block reads the byte at object+0x20 and, if it is zero, writes
 *     a block of constants into the state (offsets 0x150..0x1B6), multiplies
 *     four $gp floats by four constants and stores thirteen floats into the
 *     state, then calls func_002B60B0 (f_00341B10) with four arguments;
 *   - then it calls func_L20_00330A68, func_002A7750, func_002A7470,
 *     func_002A9640, func_002B0ED8, func_0029F338 and func_002B3BA8;
 *   - the two-element loop at 0x0039D5C8 frees the two objects at state+0x258
 *     and state+0x25C and then frees state+0x254;
 *   - the copy at 0x0039D61C is the only 128-bit access.
 *
 * This body belongs in the `-G8` unit?  YES - see above.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
extern float D_L20_001AECF0[4];
extern void *func_002B60B0(unsigned char *, float, float, float, float);
extern void func_L20_00330A68(void *, int);
extern void func_002A7750(unsigned char *, unsigned char, int);
extern void func_002A7470(void *, int, int, int);
extern void *func_002A9640(void *, unsigned int, int);
extern int func_002B0ED8(void *, void *, int);
extern void func_0029F338(void *);
extern int func_002B3BA8(void *, int, void *, int, float, float);

void func_L20_0039D340(unsigned char *object) {
    unsigned char *state = *(unsigned char **)(object + 0x68);
    unsigned char *event;
    unsigned char *target;
    unsigned char **child;
    int count;
    if (object[0x20] == 0) {
        state[0x151] = 18;
        state[0x156] = 20;
        state[0x1AC] = 5;
        state[0x1AD] = 9;
        state[0x1AE] = 4;
        state[0x1AF] = 7;
        state[0x1B2] = 10;
        state[0x1B3] = 17;
        state[0x150] = 5;
        state[0x152] = 17;
        state[0x1B6] = 0;
        *(int *)(state + 0x188) = 1;
        *(float *)(state + 0x174) = 0.5f;
        *(float *)(state + 0x17C) = 0.15000000596046448f;
        *(float *)(state + 0x15C) = 0.3333333432674408f;
        *(float *)(state + 0x160) = 0.11666667461395264f;
        *(float *)(state + 0x164) = 0.0041666668839752674f;
        *(float *)(state + 0x16C) = 0.0083333337679505348f;
        *(float *)(state + 0x54) = 0.20000000298023224f;
        *(float *)(state + 0x50) = 0.82499998807907104f;
        *(float *)(state + 0x5C) = 0.40000000596046448f;
        *(float *)(state + 0x60) = 1.5707964897155762f;
        *(float *)(state + 0x80) = 0.52359884977340698f;
        *(float *)(state + 0x84) = 0.10000000149011612f;
        *(float *)(state + 0x170) = 0.5f;
        *(float *)(state + 0x168) = 0.0083333337679505348f;
        *(float *)(state + 0x58) = 0.40000000596046448f;
        *(short *)(object + 0x7C) = 15;
        func_002B60B0(object, D_L20_001AECF0[1] * 0.00027777778f,
                     D_L20_001AECF0[0] * 0.016666668f,
                     D_L20_001AECF0[3] * 4.8481375e-06f,
                     D_L20_001AECF0[2] * 0.00029088825f);
        if (*(short *)(state + 0x24) == 0) {
            *(short *)(state + 0x24) = 10;
            *(float *)(state + 0x20) = 10.0f;
        }
        func_L20_00330A68(object, 0xD0F);
        func_002A7750(object, 6, 2);
        if (object[0x43]) func_002A7470(object, 0, 0, 0);
        *(unsigned short *)(object + 0x34) = (*(unsigned short *)(object + 0x34) | 0x4000) & 0xFFFB;
    }
    event = func_002A9640(object, 0x10000, 0);
    if (event && *(unsigned char **)(event + 0x20) && *(short *)(*(unsigned char **)(event + 0x20) + 0xAA) == 0xD0F)
        object[0xA8] = 255;
    func_002B0ED8(object, state + 0x140, 0);
    if (state[0x2E] == 2) {
        func_002A7750(object, 6, 2);
        *(int *)(object + 0x98) = 0;
        *(unsigned short *)(object + 0x34) = (*(unsigned short *)(object + 0x34) & 0xEFFF) | 0x41;
        child = (unsigned char **)(state + 0x258);
        count = 1;
        do {
            --count;
            if (*child) {
                func_0029F338(*child);
                *child = 0;
            }
            ++child;
        } while (count >= 0);
        if (*(unsigned char **)(state + 0x254)) func_0029F338(*(unsigned char **)(state + 0x254));
        *(unsigned char **)(state + 0x254) = 0;
    }
    state[0x2E] = 1;
    target = *(unsigned char **)(state + 0x280);
    if (target) {
        *(unsigned char **)(state + 0x200) = target;
        *(Quadword *)(state + 0x1F0) = *(Quadword *)(target + 0x10);
        *(float *)(state + 0x1F8) += 0.5f;
    } else {
        func_002B3BA8(object, *(int *)(state + 0x230), 0, 0, 128.0f, 0.0f);
    }
}
