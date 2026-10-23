/* func_L06_003F3EF0 (304 bytes, 1 place) -- NEAR MISS, not integrated.
   state: the candidate has retail's 304 bytes and 59 of the 76 words are the retail's
   word for word; the rest is the schedule of the two float constants and the two
   register moves that set the call's arguments.
   check.py (06_notak), with the source below and the file's measured profile
   (-O2 -G0 -ffunction-sections -frac2-qcopy):
     003F3F48  lui  $at,0xC049   |  sw   $s2,0x10($s0)
     003F3F4C  ori  $at,$at,0xFDB|  lq   $v0,0x0($s3)
     003F3F50  mtc1 $at,$f21    |  sq   $v0,0x0($v1)
     003F3F54  sw   $s2,0x10($s0)| lq   $v0,0x0($s4)
     003F3F58  lui  $at,0x4049   |  sq   $v0,0x0($s0)
     003F3F5C  ori  $at,$at,0xFDB|  lui  $at,0xC049
     003F3F60  mtc1 $at,$f20     |  ori  $at,$at,0xFDB
     003F3F64  lq   $v0,0x0($s3) |  mtc1 $at,$f20
     003F3F68  sq   $v0,0x0($v1) |  lui  $at,0x4049
     003F3F6C  lq   $v0,0x0($s4) |  ori  $at,$at,0xFDB
     003F3F70  sq   $v0,0x0($s0) |  mtc1 $at,$f21
     003F3F74  mov.s $f13,$f21   |  mov.s $f12,$f20
     003F3F78  jal  func_35A6B8  |  jal   func_35A6B8
     003F3F7C  mov.s $f12,$f20   |  mov.s $f13,$f21

   What is measured and right:
   - the two float constants are pi: retail materialises 0xC0490FDB (-pi) and
     0x40490FDB (+pi), which is float(3.1415927);
   - the constants live in $f20 and $f21 (callee-saved, saved before the call to
     func_350020 and restored after it) and are moved into $f12/$f13 for the two calls
     to func_35A6B8.  Passing them as literals and letting the compiler keep them in
     $f20/$f21 needs the results to go through a local float, not straight into the
     store, otherwise cc1 rematerialises them into $f12/$f13 and the frame stays 0x40
     instead of retail's 0x50;
   - the declaration order decides which constant gets which callee-saved register:
     declaring the positive one first puts -pi in $f20 and +pi in $f21, which is
     retail's order (the other order swaps them);
   - the file needs -frac2-qcopy: retail's 128 bit copies are
     `lq $v0,0($s3); sq $v0,0($v1)` with both addresses in registers, which is the
     grouped pattern that flag selects.  Without it this cc1 folds the offset
     (`sq $v0,0x10($s1)`).  The flag is safe for the file's other five functions
     (all five still match with it);
   - the two byte arguments are masked where they enter (retail's
     `andi $s5,$t0,0xFF` and `andi $s6,$a3,0xFF`), the fifth argument going to the
     record's +0x1C and the fourth to its +0x1A;
   - the frame is 0x50, $s0 to $s6 hold the record, the moby and the five arguments
     the way retail holds them, and the two calls to func_35A6B8 and the call to
     func_352A70 are retail's.

   What is left: this source materialises the two constants before the two 128 bit
   copies and sets $f13 before $f12, retail does the copies first and sets $f12 first.
   Both are one scheduling decision in cc1's late scheduler, and the two spellings
   tried for the constants (as locals, and as literals) move the decision but do not
   settle it: with the constants as locals the compiler rematerialises them into
   $f12/$f13 and the frame shrinks to 0x40.  Next idea: the order of the two
   arguments of the call and the declaration order of the two constants are the same
   decision, so a source that puts the two constants in the opposite order and the
   call's arguments in the retail's order may move both. */

#include "common.h"

extern char *func_350020(int);
extern float func_35A6B8(float, float);
extern void func_352A70(char *);

typedef int TI128 __attribute__((mode(TI)));

char *func_L06_003F3EF0(char *a0, TI128 *a1, TI128 *a2, int a3, int a4)
{
    char *s0;
    char *s1;
    float f;
    u8 b4 = (u8)a4;
    u8 b3 = (u8)a3;

    s1 = (char *)func_350020(0x75E);
    if (s1 != 0) {
        float pos = 3.1415927f;
        float neg = -3.1415927f;

        s0 = *(char **)(s1 + 0x68);
        *(char **)(s0 + 0x10) = a0;
        *(TI128 *)(s1 + 0x10) = *a1;
        *(TI128 *)s0 = *a2;
        f = func_35A6B8(neg, pos);
        *(float *)(s1 + 0xF0) = f;
        f = func_35A6B8(neg, pos);
        *(float *)(s1 + 0xF4) = f;
        *(unsigned short *)(s0 + 0x18) = 0x1F4;
        *(int *)(s0 + 0x14) = 0;
        *(unsigned char *)(s1 + 0x30) = 0xFF;
        *(unsigned short *)(s1 + 0x32) = 0x40;
        *(unsigned char *)(s1 + 0x31) = 1;
        *(unsigned char *)(s1 + 0x20) = 0;
        f = *(float *)(*(int *)(s1 + 0x24) + 0x24) * 0.3f;
        *(float *)(s1 + 0x2C) = f;
        *(unsigned char *)(s0 + 0x1C) = b4;
        *(unsigned char *)(s0 + 0x1A) = b3;
        *(unsigned char *)(s0 + 0x1B) = 0;
        func_352A70(s1);
    }
    return s1;
}
