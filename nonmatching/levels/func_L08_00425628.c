/* func_L08_00425628 (376 bytes, 1 place) - best attempt, NOT MATCHED.
 *
 * `python3 tools/check.py func_L08_00425628 --diff`: the candidate is 368 bytes and the
 * prologue, the frame, the call sequence, the three float constants in $f20/$f21/$f22
 * and the whole swing-angle body are retail's.  Two things differ:
 *
 *  - the two 16-byte copies keep their addresses in registers in retail
 *    (`addiu $v1,$s0,0x170 ; lq $v0,0($v1) ; addiu $a0,$s0,0x180 ; sq $v0,0($a0)`)
 *    while this cc1 folds the 0x170 source into the `lq` displacement
 *    (`lq $v0,0x170($s0)`).  That is the CSE tie docs/COMPILER-NOTES.md records for
 *    the 128-bit copy: the address has to stay a pseudo at reload time, and only a
 *    symbol base, a loop-carried pointer, a pointer with different values in two
 *    branches, a volatile pointer object or an offset outside [-32768,32752] survives
 *    the substitution.  Measured here: the destination through the `s1` local keeps a
 *    register (`sq $v0,0($s1)`), the source does not; a 16-byte-aligned struct
 *    (`mode(TI)` with `aligned(16)`) gives `ld`/`sd` pairs instead of `lq`/`sq`, and
 *    a pointer local assigned in both arms is folded as well.
 *
 *  - the `f1E8 == -1` test is a plain `beq` in retail and a `beql` here, and the
 *    D_00189EA0 address is split `lui`/`addiu` in retail and materialised whole here.
 *
 * The float constants must be declared inside the arm that uses them: with them in
 * the function's outer scope this cc1 rematerialises the two pi constants into $f12/
 * $f13 and keeps only 3.0f in a callee-saved register (a 0x30 frame against
 * retail's 0x40).
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef float f32;
typedef unsigned long long u64;
typedef u64 TI128 __attribute__((mode(TI)));

extern s32 func_32E920(void *, s32, s32, s32, s32);
extern s32 func_1163B0();
extern s32 D_L08_001B29DC;
extern f32 func_3278F0(f32, f32);
extern f32 func_2FA3C8(f32);
extern f32 func_2FA3E0(f32);
extern void func_2F9DF0(void *, void *, void *);
extern char D_00189EA0[];

void func_L08_00425628(char *a0) {
    char *s0 = *(char **)(a0 + 0x68);
    char *s1 = s0 + 0x180;
    f32 t;

    if (func_32E920(s1, *(s32 *)(s0 + 0x1D8), *(s32 *)(s0 + 0x1E0),
                    *(s32 *)(s0 + 0x1DC), -1) != 0) {
        return;
    }
    if ((func_1163B0() & 1) || *(s32 *)(s0 + 0x164) == 2 ||
        *(s16 *)(s0 + 0x1B6) != 0) {
        if (*(s32 *)(s0 + 0x1E8) == -1 || (func_1163B0(s0 + 0x180) & 1)) {
            *(TI128 *)s1 = *(TI128 *)(s0 + 0x170);
        } else {
            f32 f20 = -3.1415927f;
            f32 f21 = 3.1415927f;
            f32 f22 = 3.0f;
            t = func_3278F0(f20, f21);
            *(f32 *)(s0 + 0x180) = func_2FA3C8(t) * f22;
            t = func_3278F0(f20, f21);
            *(f32 *)(s0 + 0x184) = func_2FA3E0(t) * f22;
            *(f32 *)(s0 + 0x188) = 0.0f;
            func_2F9DF0(s1, s1,
                        (char *)(D_L08_001B29DC + (*(s32 *)(s0 + 0x1E8) << 8)) + 0x10);
        }
    } else {
        *(TI128 *)s1 = *(TI128 *)D_00189EA0;
    }
    *(f32 *)(s0 + 0x188) = *(f32 *)(s0 + 0x188) + 6.5f;
}
