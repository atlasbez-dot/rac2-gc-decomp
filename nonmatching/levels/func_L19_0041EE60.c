/* func_L19_0041EE60 (1380 bytes, 1 place: level 19_grelbin) - best attempt, NOT MATCHED.
 *
 * This body is 1372 bytes against retail's 1380 (checked in src/levels/19_grelbin/L19_003E9400.c,
 * where it replaces the marker; it needs the declarations of func_L19_00422810 above it in that
 * file, repeated below). tools/check.py: "1372 bytes, expected 1380". Everything but the three
 * items below is retail's (about 25 of retail's 345 words; the calls and the branch offsets that
 * move with the size are not counted):
 *
 *  1. The 128-bit copy wall, 8 bytes. Case 3 copies the object's position (obj + 0x10) twice, into
 *     the entity (e + 0x10) and into the entity state (s + 0x210). Retail forms all three
 *     addresses first (`addiu $a1,$s2,0x10 ; lq $v0,0($a1) ; sq $v0,0($a0) ; addiu $v1,$s1,0x210 ;
 *     lq $v0,0($a1) ; sq $v0,0($v1)`, with `$a0 = e + 0x10` shared with the call that follows);
 *     this cc1 folds every offset into the lq/sq (`sq $v0,0x10($s0) ; lq $v1,0x10($s2) ;
 *     sq $v1,0x210($s1)`). Spelled `*(TI128 *)(e + 0x10) = *(TI128 *)(object + 0x10)`; pointer
 *     variables measure the same (the cost tie in cse's find_best_addr, see docs/COMPILER-NOTES.md).
 *
 *  2. The table address operands, one word: retail adds `addu $v0,$v0,$v1` (table first, index
 *     second) for `D_L19_0021EA30[(s16)h + 0x464]`, this cc1 `addu $v1,$v1,$v0`, and the `lbu`
 *     then reads `0x464($v0)` against `0x464($v1)`. Pointer locals for the table, the 0x464 moved
 *     into the pointer, `*(tab + i)` and a signed halfword load all give this form or are worse.
 *
 *  3. Case 1's call set-up, five words. Retail's block after `beqz $a1` starts
 *     `sq $zero,0($sp) ; lui $at,0x4040 ; mtc1 $at,$f12 ; daddu $a2,$sp,$zero ; lui $at,0x40C0 ;
 *     mtc1 $at,$f13 ; daddu $a0,$s2,$zero ...` and the branch's delay slot is the epilogue's
 *     `ld $s1,0x18($sp)`; here sched2 puts `daddu $a0,$s2,$zero` first and reorg moves it into the
 *     slot (`beqz $a1 ; daddu $a0,$s2,$zero`), with `$a2` right after the `sq`. Measured without
 *     effect: the 70 interleavings of func_002B0A68's integer and float parameters, constants in
 *     locals, `vec[2]` through a local, the `sh` before/after the call, nesting or reordering the
 *     `if (state->w64 == 1 && gone)` test.
 *
 * Everything else is retail's: the prologue, the check chain at the top (nibble of the table byte
 * `(c >> 4) & 7` needs an `int c`, a u8 gives `srl` where retail has `sra`), the four cases in the
 * order 0, 1, 3, 2 (retail's compare tree), the id-list walks (rotated, `e == 0` break), the
 * movn of case 2's counter (nested `!= 0xFE`, `!= 0xFD` ifs; one `&&` folds to a range test), the
 * f20 save, the stores of case 0 in the order f22C, 26C, 274 (brute-forced), func_002B3BA8's
 * parameters declared floats first (the other order puts the `mov.s $f13,$f12` in the delay slot).
 *
 * Callees (level 19 addresses -> names): 0x31E3A0 func_002ACD38, 0x30DFE8 func_0029F338,
 * 0x3198B8 func_002A89A8 (returns a float: args pointer, 0, 0.5f/1.0f), 0x3183D8 func_002A7878,
 * 0x326D70 func_002B3BA8, 0x3239B8 func_002B0A68, 0x35D3D8 func_002E5CF8, 0x318240 func_002A7750,
 * 0x2EB590 func_00282948. Globals: the words at 0x1B1D20 and 0x1B1D24 (compared in case 2, the
 * first through a bare lui/lw, the second through $gp) are two separate `sda` scalars here.
 */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

typedef int TI128 __attribute__((mode(TI)));

extern u16 *D_L19_001FB5A0[];
extern u8 *D_L19_001B2A1C[] __attribute__((sda));
extern s32 D_L19_001B2A38[] __attribute__((sda));
extern s32 D_001A79F0 __attribute__((sda));
extern char D_0019B4A8[];

extern void func_0029F338(u8 *);

extern u8 D_L19_0021EA30[];
extern s32 D_L19_001B1D20 __attribute__((sda));
extern s32 D_L19_001B1D24 __attribute__((sda));

extern s32 func_002ACD38(void *);
extern float func_002A89A8(void *, s32, f32);
extern float func_002A7878(f32, f32);
extern s32 func_002B3BA8(u8 *, s32, f32, f32, s32, s32);
extern void func_002B0A68(u8 *, s32, void *, s32, f32, f32, f32, f32);
extern s32 func_002E5CF8(s32, s32, u8 *);
extern void func_002A7750(u8 *, s32, s32);
extern s32 func_00282948(void *);

#define GROUP(off) (*(s32 *)(state + (off)))
#define FOR_EACH_ID(p, off) \
    for (p = D_L19_001FB5A0[GROUP(off)]; \
         (GROUP(off) & 0xFF) != 0xFF && GROUP(off) <= D_L19_001B2A38[0] && p != 0 && \
         ((p != 0 && (s16)p[-1] >= 0) || p == D_L19_001FB5A0[GROUP(off)]); \
         p++)

void func_L19_0041EE60(u8 *object)
{
    u8 *state;
    s32 c;

    if (func_002ACD38(object + 0x10) == 0)
        return;
    state = *(u8 **)(object + 0x68);
    if (GROUP(0x120) == -1 ||
        (object[0xB0] != 0xFF &&
         (D_L19_0021EA30[(s16) * (u16 *)(object + 0xB2) + 0x464] != 0 ||
          ((c = *(u8 *)(D_0019B4A8 + (((s16) * (u16 *)(object + 0xB2) >> 1) + (D_001A79F0 << 10)))),
           (*(u16 *)(object + 0xB2) & 1) ? ((c >> 4) & 7) != 0 : (c & 7) != 0)))) {
        func_0029F338(object);
        return;
    }
    switch (object[0x20]) {
    case 0: {
        u16 *p;
        u8 *e;
        u8 *s;
        f32 x;

        x = func_002A89A8(object + 0x10, 0, 0.5f);
        x -= func_002A7878(0.1f, 0.3f);
        *(s16 *)(object + 0x7C) = 0x1F;
        *(s32 *)(object + 0x48) = 0;
        *(f32 *)(object + 0x18) = x;
        FOR_EACH_ID(p, 0x120) {
            e = D_L19_001B2A1C[0] + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (*(s16 *)(e + 0xAA) == 0x10D0) {
                s = *(u8 **)(e + 0x68);
                *(f32 *)(s + 0x22C) = *(f32 *)(state + 0x128) + 10.0f;
                *(s32 *)(s + 0x26C) = 1;
                *(s32 *)(s + 0x274) = 1;
            }
        }
        func_002A7750(object, 1, -1);
        break;
    }
    case 1: {
        u8 *e;
        f32 vec[4];
        s32 gone;

        func_002B3BA8(object, -1, *(f32 *)(state + 0x128), *(f32 *)(state + 0x128), 0, 0);
        gone = 0;
        if (GROUP(0x138) == -1) {
            gone = 1;
        } else {
            e = D_L19_001B2A1C[0] + (GROUP(0x138) << 8);
            if (e == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD)
                gone = 1;
        }
        if (GROUP(0x64) == 1 && gone) {
            *(TI128 *)vec = 0;
            vec[2] = 0.15f;
            *(s16 *)(object + 0x7C) = 0;
            func_002B0A68(object, 0x1F, vec, 0xFF, 3.0f, 6.0f, 3.0f, 6.0f);
            func_002E5CF8(0, 0, object);
            func_002A7750(object, 3, -1);
        }
        break;
    }
    case 3: {
        u16 *p;
        u8 *e;
        u8 *s;
        s32 found = 0;

        FOR_EACH_ID(p, 0x120) {
            e = D_L19_001B2A1C[0] + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (*(s16 *)(e + 0xAA) == 0x10D0) {
                s = *(u8 **)(e + 0x68);
                if (*(s32 *)(s + 0x26C) == 1) {
                    *(TI128 *)(e + 0x10) = *(TI128 *)(object + 0x10);
                    *(TI128 *)(s + 0x210) = *(TI128 *)(object + 0x10);
                    *(f32 *)(e + 0x18) = func_002A89A8(e + 0x10, 0, 1.0f);
                    found = 1;
                    *(s32 *)(s + 0x26C) = 0;
                    *(u16 *)(e + 0x34) &= 0xFF7F;
                    break;
                }
            }
        }
        if (!found) {
            func_002A7750(object, 4, -1);
        } else {
            GROUP(0x13C) = 200;
            func_002A7750(object, 2, -1);
        }
        break;
    }
    case 2: {
        u16 *p;
        u8 *e;
        u8 *s;
        s32 n;

        func_002B3BA8(object, -1, *(f32 *)(state + 0x128) + 10.0f, *(f32 *)(state + 0x128), 0, 0);
        if (GROUP(0x64) == 1) {
            n = 0;
            FOR_EACH_ID(p, 0x120) {
                e = D_L19_001B2A1C[0] + ((*p & 0x7FFF) << 8);
                if (e == 0)
                    break;
                if (*(s16 *)(e + 0xAA) == 0x10D0) {
                    s = *(u8 **)(e + 0x68);
                    if (*(s32 *)(s + 0x26C) == 0) {
                        if (e[0x20] != 0xFE) {
                            if (e[0x20] != 0xFD)
                                n++;
                        }
                    }
                }
            }
            if (D_L19_001B1D20 < D_L19_001B1D24) {
                if (n < 3) {
                    if (func_00282948(state + 0x13C))
                        func_002A7750(object, 3, -1);
                }
            }
        }
        break;
    }
    }
}
