/* func_L09_00403700, 152 bytes, 1 placement (level 9).  Closest candidate: 152 bytes,
   every instruction retail's except one register.

   Two things the earlier attempt had wrong, both now fixed:
   (1) the guard's argument is 0x4000001, not 0x40000001 - one zero too many made
       the constant 0x40000000|1 instead of 0x04000000|1, so the `lui` differed;
   (2) the guard is `if (*(u8 *)(a0 + 0x20) == 7) { ... }` with the state pointer
       loaded BEFORE the test, not `if (... != 7) return;` with it loaded after.
       That is what puts retail's `bne $v0,$v1` with the `lw $s2,0x68($s1)` in its
       delay slot; the early-return spelling gave a branch-likely `bnel` with the
       epilogue's `ld $s0,0x0($sp)` in the annulled slot and one instruction more.

   The one difference left: the loop's trip test.  Retail compares into $v1
   (`slti $v1,$s0,0x4` / `bnel $v1,$zero`), this candidate into $v0.  $v0 holds
   the sub-object's byte +0x34 in retail, and it is dead after the `mtc1 $v0,$f13`
   in both, so the allocator may use it; retail's copy of the compare result
   into $v1 means $v0 was still reserved there (the reload of the byte across
   the loop's back edge).  Measured: 25 spellings of the body (do-while and for,
   the byte in a u8/f32 local, the byte through a pointer, a volatile read, the
   counter as long/unsigned, `i <= 3`, `4 > i`, `!(i >= 4)`, the guard's polarity,
   the state pointer before/after the test) and 12 flag combinations (-G2/-G4/-G8,
   -fno-gcse, -fno-strength-reduce, -fno-thread-jumps, -O1/-O3, -fno-schedule-insns2)
   all give $v0 for the compare.  The body: */

typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern void func_318450(char *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5,
                        f32 f12, f32 f13, f32 f14);

void func_L09_00403700(char *a0) {
    char *s2 = *(char **)(a0 + 0x68);
    s32 i;

    if (*(u8 *)(a0 + 0x20) == 7) {
        i = 0;
        do {
            func_318450(a0, i, 0x4000001, 0, 1, 0, 0.17f,
                        (f32)*(u8 *)(s2 + 0x34), 1.0f);
            i++;
        } while (i < 4);
    }
}
