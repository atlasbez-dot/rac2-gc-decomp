/* Not matched (worker 07, level-20 wave of 2026-10-21): the 128-bit copy wall.
 *
 * THE WALL.  The retail's only 128-bit access is
 *
 *     0039DAB0  addiu      $v1, $s4, 0x10      ; the source, arg0 + 0x10
 *     0039DAB4  addiu      $a0, $sp, 0x20     ; the destination, a stack buffer
 *     0039DAB8  lq         $v0, 0x0($v1)
 *     0039DABC  sq         $v0, 0x0($a0)
 *
 * i.e. the address is MATERIALISED into a register and the lq/sq use a ZERO
 * displacement - the shape the corrected rule of wave 5 describes (43,255
 * places game-wide).  Plain C cannot produce it here: the address is
 * `base + 0x10` with a runtime base, so the TImode reload keeps the offset as
 * the displacement and the copy comes out as
 *
 *     lq $v0,0x10($s4) ; sq $v0,0x20($sp)
 *
 * (measured in the candidate below).  The escapes do not apply: the base is a
 * runtime pointer (not a plain pointer, not a symbol, not a stack slot at
 * offset 0), the offset is inside the TImode displacement range
 * [-32768, 32751] and inside the addiu immediate range, and a `volatile`
 * pointer object costs a stack store and a reload per copy.
 *
 * THE CANDIDATE.  716 bytes against the retail's 720.  The frame, the walk,
 * the ten saved float registers, the two float loops and the eight calls are
 * all there; what differs is the register allocation (the retail keeps the
 * argument in $s4, the state pointer in $s2, the loop counter in $s0, the
 * object pointer in $s5 and the global's address in $s6; this cc1 gives the
 * argument $s6, the state $s1, the counter $s0, the object $s3 and the global
 * $fp) and the two `lq`/`sq` pairs above.
 *
 * MEASURED SPELLINGS for the copy (all folded, all in a scratch unit):
 *   *(TI128 *)(arg0 + 0x10) = *(TI128 *)p;      -> lq $v0,0x10($s4)
 *   TI128 *d = (TI128 *)(arg0 + 0x10); *d = v;   -> lq $v0,0x10($s4)
 *   the same with an offset of 0x2010 (> 0x2000, so mips_address_cost() gives
 *     it 2 instead of 1 and the CSE tie should go the other way)   -> lq
 *     $v0,0x2010($s4)   (still folded: the front end builds the address as
 *     plus(reg,const) and the RELOAD accepts it for TImode, so the CSE never
 *     gets a chance to substitute)
 *   TI128 * volatile d = (TI128 *)(arg0 + 0x10); -> sw ; lq ; lw ; sq $v0,0($2)
 *     (the zero displacement, but four instructions and a stack slot against
 *     the retail's three)
 *
 * This body belongs in the `-G8` unit?  No: it reaches no global through
 * `$gp`.
 */

/* The candidate below is the near miss: 716 bytes against the retail's 720. */

#include "common.h"

typedef int TI128_w07 __attribute__((mode(TI)));

extern float func_00283CF0(float);
extern float func_002A78D8(float, float);
extern float func_00283B98(float, float);
extern float func_002A7878(float, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_00273730(void *, int, void *, void *, void *, int, int);
extern void func_002E5E58(int, int, int, int);
extern void func_0029F338(void *);
extern void func_0032C700(void *, int, int, int, int, int, int, int, int, int, int, int);
extern void func_00310C88(void);
extern char D_L20_001B9E80[];

void func_L20_0039D880(char *arg0) {
    char *s4 = arg0;
    char *s2 = *(char **)(arg0 + 0x68);
    char *s5 = (char *)func_00310C88;
    char *s6 = D_L20_001B9E80;
    int s0 = 0;
    int s1;
    u32 s3;
    f32 f20;
    f32 f21;
    f32 f22 = 0.016666668f;
    f32 f23 = 90.0f;
    f32 f0;
    f32 f12;
    f32 f13;
    TI128_w07 buf;

    if (*(int *)(s2 + 0x254) != 0) {
        f12 = *(f32 *)(s2 + 0x20) / (f32)*(s16 *)(s2 + 0x24);
        s3 = (u32)func_00283CF0(f12 * 255.0f) & 0xFF;
        for (s0 = 0; s0 < 10; s0++) {
            if ((u32)(s0 - 4) >= 2) {
                continue;
            }
            if (s0 == 7) {
                continue;
            }
            if ((*(u16 *)(*(int *)(s2 + 0x254) + 0x7C) & (1 << s0)) == 0) {
                continue;
            }
            if (!(s3 < *(u8 *)(s2 + 0x270 + s0))) {
                continue;
            }
            f0 = func_002A78D8(f23, 120.0f);
            f0 = func_00283B98(f0 * 0.017453294f, *(f32 *)((char *)s6 + 0x158));
            f20 = func_002A7878(2.0f, 4.0f);
            f21 = f20 * f22;
            *(f32 *)((char *)&buf + 0) = func_00283180(f20) * f21;
            *(f32 *)((char *)&buf + 4) = func_00283198(f20) * f21;
            *(f32 *)((char *)&buf + 8) = func_002A7878(5.0f, 8.0f) * f22;
            func_00273730((void *)*(int *)(s2 + 0x254),
                          *(s16 *)(*(int *)(s2 + 0x254) + 0xAA),
                          (char *)*(int *)(s2 + 0x254) + 0x10,
                          (char *)*(int *)(s2 + 0x254) + 0xF0,
                          (char *)&buf, s0, 0xFF);
        }
        *(u16 *)(*(int *)(s2 + 0x254) + 0x7C) &= ~(1 << s1);
        func_002E5E58(7, 0, 0, *(u16 *)(*(int *)(s2 + 0x254) + 0x7C));
    }
    if (*(f32 *)(s2 + 0x20) <= 0.0f) {
        s0 = (int)((char *)s2 + 0x258);
        s1 = 1;
        do {
            if (*(int *)s0 != 0) {
                func_0029F338((void *)*(int *)s0);
                *(int *)s0 = 0;
            }
            s1--;
            s0 += 4;
        } while (s1 >= 0);
    }
    if (*(int *)(s2 + 0x254) != 0) {
        func_0029F338((void *)*(int *)(s2 + 0x254));
        *(int *)(s2 + 0x254) = 0;
    }
    buf = *(TI128_w07 *)(arg0 + 0x10);
    f0 = *(f32 *)((char *)&buf + 8);
    func_0032C700(&buf, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1, 0, 0, 0);
}
