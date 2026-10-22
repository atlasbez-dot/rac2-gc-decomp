/* Near miss: the prologue and the frame are the retail's, the body is 316 bytes
 * against the retail's 308.
 *
 * func_L01_003120A8 (308 bytes, level 01 at 0x003120A8; also 07:00312500,
 * 08:00329690, 09:003184F8, 18:003370F0, 19:00319E08, 20:00331110).
 *
 * tools/check.py func_L01_003120A8 --diff (with -frac2-qcopy on the unit):
 *   01_oozla: 316 bytes, expected 308
 *
 * The frame (0xA0), the nine saved registers, the two float registers and every
 * call's argument list are the retail's.  Three things are still open:
 *
 * 1. The retail's record of three bytes (the two argument bytes and the half
 *    word at 0xAA of the object) sits at 0x28 of the frame, this draft puts it
 *    at 0x20: the retail has eight more bytes of locals before it, and this
 *    draft has to make the frame up with padding in the record itself.
 *
 * 2. The retail sets $a0 once, before the branch, and uses it for both calls
 *    in the "no flag" arm; this cc1 re-sets it for the second call, because a
 *    call clobbers $a0.
 *
 * 3. The retail calls func_002E3A60 with (a0 = sp, f12 = a float) here, and
 *    with (a0, a1) in the integers in func_L01_0031BC68, which this unit
 *    already declares as "extern float func_002E3A60(int a0, int a1);".  The
 *    two call sites cannot share one declaration, so this draft reaches the
 *    same symbol through a second name (the same trick the file already uses
 *    for r1_D_L01_00160058).  A unit of its own would avoid that.
 *
 * The retail's lq/sq needs the grouped R5900 quadword copy, so the unit wants
 * -frac2-qcopy.
 */

#include "include_asm.h"

/* The game's 16-byte copy type: a whole vector or matrix moved in one quadword. */
typedef int TI128 __attribute__((mode(TI)));

extern float func_002E3A48(float *a0, float f12);

/* The same symbol as func_002E3A60, called the way this unit calls it. */
extern float func_002E3A60_f(float *a0, float f12) __asm__("func_002E3A60");

extern void func_002E34E0(float *a0, float *a1, float f12);

extern void func_311E90(float *a0, void *a1, void *a2, void *a3, float f12);

extern int func_002D3C80(char *a0, char *a1, int a2, char *a3, char *a4);

void func_L01_003120A8(void *a0, char *a1, char *a2, void *a3, int a4, int a5, int a6, float f12, float f13) {
    float v[4];
    float w[4];
    struct { unsigned char a; unsigned char b; unsigned short c; char pad[16]; } s;

    if (*(unsigned short *)((char *)a0 + 0x34) & 0x100) {
        *(TI128 *)v = *(TI128 *)((char *)a0 + 0xC0);
    } else {
        v[0] = func_002E3A48(v, *(float *)((char *)a0 + 0xF8));
        v[1] = func_002E3A60_f(v, *(float *)((char *)a0 + 0xF8));
        v[2] = 0.0f;
    }
    func_002E34E0(v, v, f13);
    v[2] = 1.0f;
    v[3] = 5627.9248046875f;
    func_311E90(w, a0, a3, v, f12);
    s.a = a4;
    s.b = a5;
    s.c = *(unsigned short *)((char *)a0 + 0xAA);
    func_002D3C80(a1, a2, a6 | 9, (char *)a0, (char *)w);
}
