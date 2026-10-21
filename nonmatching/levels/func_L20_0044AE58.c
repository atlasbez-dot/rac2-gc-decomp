/* Not attempted (wave 4, worker 10 of the level 20 wave): only the structure
   was mapped, for the next worker.

   func_L20_0044AE58 (676 bytes) reaches a global through $gp - `lwc1 $f12,
   0x3478($gp)` at 0x0044AF50 - so the body belongs in a -G8 unit of its own
   (a file named *-g8.c gets -G8 from its name).

   The shape: the frame is 0xA0 with $s0-$s5 saved, the first thing is the
   usual `D_001A8F00 != 2` test (the same guard as func_L20_00449CE0), then
   a dispatch on the byte at +0x20 of the object (0 means the long path,
   1 goes to .L0044B040, 2 to .L0044B0C8).  The long path calls
   f_00303270 three times (the float at +0x28 of the state times 0.7f,
   0.5f and 0.55f), then f_003022A8, f_003329E8, f_00302260 and f_002F3518,
   and ends with the usual f_0032F5B0 and the `D_1C0418` test.  The only
   16-byte copy is `lq $v0,0x0($v1) ; sq $v0,0x0($s4)` - the destination is
   a plain register, so the 128-bit copy wall does NOT stand here (the
   address is already a register).

   The float constants are in the listing: 0x3F333333 (0.7f), 0x3F000000
   (0.5f), 0xBF000000 (-0.5f), 0x484D1400 (210000.0f), 0x40200000 (2.5f),
   0x40400000 (3.0f), 0x3E4CCCCD (0.2f), 0x3ECCCCCD (0.4f), 0x3C8EFA36
   (0.017453292f).

   ------------------------------------------------------------------
   Wave 5 (worker 10), 2026-10-21: the body is now written out and nearly
   matches; the attempt is below (in a -G8 unit of its own, so the C is
   complete).  What the attempt reaches and what is left:

   last check.py line: "20_yeedil: instruction at +0xc differs" (the frame,
   the block structure, the branch shapes, the float constants and every
   call's argument list match; the difference is the register allocation).

   Measured facts (the retail body, from 0x0044AE58):

   * the frame is 0xA0; $s0-$s4 and $f20-$f21 are saved, and the four
     16-byte buffers are at sp+0x20, sp+0x30, sp+0x40 and sp+0x50;
   * the globals: D_L20_001A8F00 (the `!= 2` guard) and D_L20_001C0418 are
     read ABSOLUTE (`lui`+`lw`), D_L20_001B2468 is a float through $gp
     (`lwc1 $f12,0x3478($gp)`) and D_L20_001B2460 an int through $gp
     (`lw $a3,0x3470($gp)`).  In a -G8 unit the PLAIN declaration of an int
     gives the retail's `lui`+`lw` with the base and the destination in
     the SAME register (`lw $v1,%lo($v1)($v1)`) - that is what
     D_L20_001A8F00 needs; D_L20_001C0418 needs `__attribute__((nosda))`,
     which gives the retail's `lui $v0` + `lw $v1,%lo($v0)` with two
     different registers; the plain declaration puts it through $gp;
   * the dispatch on the byte at +0x20 is a SWITCH in the source: the
     `if (mode == 0) ... else if (mode == 1) ... else ...` spelling gives
     `bnez` where the retail has `beqz`, and the switch gives the
     retail's `beqz $s1` / `beql $s1,$v0` chain;
   * the D_L20_001C0418 test is the wave-2 branch-likely recipe: the
     source is `if (id != 0) { src = &buf20; if (id != *(int *)(arg0+0xB8))
     {...} } else { src = (TI128 *)id; }` and the retail's `beql $v1,$zero`
     skips the `addiu $v1,$sp,0x20` (the annulled delay slot) - the id
     itself is the pointer in the id == 0 case, so the copy reads from
     address 0 there, exactly as the retail does;
   * the two `func_002A7878` calls: the first (2.5f, 3.0f) is multiplied
     by 210000.0f in the delay slot of the second call (0.2f, 0.4f) and
     kept in the callee-saved $f21 (the source keeps `a * 210000.0f` alive
     across the second call), the second result is multiplied into $f13,
     the second float argument of func_002C65A0 - so func_002C65A0 takes
     EIGHT ints and TWO floats: (void*, void*, float, float, int x6);
   * 210000.0f lives in the callee-saved $f20 and the product in $f21;
   * func_002A8C28's second float argument is `*(float *)(state + 0x20)`
     (the `lwc1 $f13,0x20($s3)` in the delay slot of the branch-likely),
     and func_0032C700's first argument is `arg0 + 0x10`, not `arg0`;
   * the tail calls func_L00_002E6EF8 with the address of the level-11
     function func_L11_0045FEF8 (0x0044B288 in level 20) and `arg0`; the
     address is materialised as `lui $a0,%hi` in the delay slot of the
     branch that reaches the tail, and the `%lo` is added in the delay
     slot of the call.

   What is still different: the register allocation.  The retail has
   $s0 = the buffer pointer, $s1 = the mode byte (reused for `arg0+0x10`
   in the long path), $s2 = arg0, $s3 = the state, $s4 = `arg0+0x10`
   (a COPY of $s1: `daddu $s4,$s1,$zero`); the attempt has $s0 = the mode
   byte, $s1 = arg0, $s2 = the buffer pointer, $s3 = the state, $s4 =
   `arg0+0x10` (computed directly).  The mode byte is the value with the
   most references (5) and the buffer pointer has 3, yet the retail gives
   the buffer the lower register - so the order is not the reference
   count, and moving the declaration of the mode (before or after the
   buffers) does not change it.  That is the same wall the wave-4 note
   recorded for the -G8 profile.

*/
*/

#include "include_asm.h"

/* This unit is built with -G8: the body reaches level data through $gp. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));

extern int D_L20_001A8F00;

extern int D_L20_001C0418 __attribute__((nosda));

extern float D_L20_001B2468 __attribute__((sda));

extern int D_L20_001B2460 __attribute__((sda));

extern void func_0029F338(void *object);

extern float func_00283B98(float, float);

extern void func_00282D08(float *out, char *a, char *b, float k);

extern void func_002AA2E8(float *p, float v, float w);

extern void func_00282CC0(void *, void *, void *);

extern int func_00277258(void *, int, void *, float);

extern void func_002A7750(char *object, int a1, int a2);

extern void func_00282D30(void *dst, void *src, float value);

extern void func_00282C88(void *target);

extern float func_002A7878(float lo, float hi);

extern void func_002C65A0(void *, void *, float, float, int, int, int, int, int,
                           int);

extern void func_002A8C28(char *, char *, int, int, float, float, float, int, int);

extern void func_0032C700(void *a0, int a1, int a2, int a3, int a4, int a5, int a6,
                          int a7, float f12, float f13, int s1, int s2, int s3,
                          int s4);

extern void func_L00_002E6EF8(void *, void *);

extern void func_L11_0045FEF8(void);

void func_L20_0044AE58(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    char *base = arg0 + 0x10;
    TI128 buf20;
    TI128 buf30;
    TI128 buf40;
    TI128 buf50;
    TI128 *src;
    u8 mode;

    if (D_L20_001A8F00 == 2) {
        func_0029F338(arg0);
        return;
    }
    mode = *(u8 *)(arg0 + 0x20);
    switch (mode) {
    case 0: {
        float v = *(float *)(state + 0x28);
        float a;
        float b;

        *(float *)(arg0 + 0xF0) =
            func_00283B98(*(float *)(arg0 + 0xF0), v * 0.7f);
        *(float *)(arg0 + 0xF4) = func_00283B98(
            *(float *)(arg0 + 0xF4), *(float *)(state + 0x28) * 0.5f);
        *(float *)(arg0 + 0xF8) = func_00283B98(
            *(float *)(arg0 + 0xF8), *(float *)(state + 0x28));
        func_00282D08((float *)&buf30, state, state + 0x10,
                      *(float *)(state + 0x30));
        func_002AA2E8((float *)(state + 0x30), 1.0f, *(float *)(state + 0x34));
        func_00282CC0(&buf20, base, &buf30);
        if (func_00277258(&buf20, 0, arg0, D_L20_001B2468) != 0) {
            int id = D_L20_001C0418;

            if (id != 0) {
                src = &buf20;
                if (id != *(int *)(arg0 + 0xB8)) {
                    func_002A7750(arg0, 1, -1);
                    goto tail;
                }
            } else {
                src = (TI128 *)id;
            }
            goto copy;
        }
        src = &buf20;
    copy:
        *(TI128 *)base = *src;
        func_00282D30(&buf40, state, -0.5f);
        func_00282C88(&buf50);
        a = func_002A7878(2.5f, 3.0f);
        b = func_002A7878(0.2f, 0.4f);
        func_002C65A0(base, &buf40, a * 210000.0f, b * 210000.0f, 0xF,
                      D_L20_001B2460, 3, 0x50, 0, 0);
        func_L00_002E6EF8(&func_L11_0045FEF8, arg0);
    } break;
    case 1: {
        func_002A8C28(arg0, base, 0x10001, 0, 3.0f, *(float *)(state + 0x20),
                      1.0f, 1, 0);
        func_0032C700(base, 1, 0xA, 0xA, 0xA, 0xA, 0xA, 0, 2.0f, 20.0f, mode,
                      mode, 0, 0);
        func_0029F338(arg0);
    } break;
    default:
        func_L00_002E6EF8(&func_L11_0045FEF8, arg0);
    }
    return;
tail:
    func_L00_002E6EF8(&func_L11_0045FEF8, arg0);
}
