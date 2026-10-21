/* 0 of 1 places match - last line: 22_dobbo_orbit: 176 bytes, expected 160
   Candidate is four instructions over.  Arms the object's private block the first time, then
   asks the shared helper for the resident record and only fires the engine call when the
   record's two gate words are both clear, parking the block's mode word at 0x708 either way.
   Retail reaches the record pointer with a plain absolute `lui $v0,0x19 / lw $s0,-0x4958($v0)`
   (0x0018B6A8) where this unit's own declaration of that address is `sda`, so the body below
   reaches it under a second name marked `nosda` - that part is right.  The extra four
   instructions are in the two guards and the early returns, which retail folds into the
   epilogue with `ld $s0,0x0($sp)` in each `beql`/`bnel` delay slot (the annulled-slot idiom
   again, three times here).  Unblocking needs the guard chain written so this cc1 annuls the
   branches, or accepts the per-guard frame restore. */

typedef int s32;
typedef unsigned char u8;

extern s32 func_2F36F0(s32);
extern void func_2F9E20(s32, s32);
extern s32 D_L22_0018B6A8_nosda __asm__("D_L22_0018B6A8") __attribute__((nosda));

void func_L22_00415A48(s32 a0) {
    s32 s1 = *(s32 *)(a0 + 0x68);
    s32 s0;

    if (*(u8 *)(a0 + 0x20) == 0) {
        *(u8 *)(a0 + 0x20) = 1;
        *(u8 *)(a0 + 0x30) = 0xFF;
        *(s32 *)s1 = 0x708;
    }
    if (*(u8 *)(a0 + 0x20) != 1)
        return;
    s0 = D_L22_0018B6A8_nosda;
    if (func_2F36F0(s1) == 0)
        return;
    if (*(s32 *)(s0 + 8) != 0)
        return;
    if (*(s32 *)(s0 + 0xC) != 0)
        return;
    func_2F9E20(0x9FD, 0x54);
    *(s32 *)s1 = 0x708;
}

/* Second attempt (wave 24, worker 15): 160 bytes, ONE word off.
   check.py (22_dobbo_orbit): "22_dobbo_orbit: instruction at +0x84 differs";
   every other word matches, including the annulled-slot idiom the earlier
   draft could not get:
     00415ACC  addiu $v0, $zero, 0x708   |  addiu $v1, $zero, 0x708
     00415AD0  sw     $v0, 0x0($s1)     |  sw     $v1, 0x0($s1)
   What unblocked it: the two guards are written as two separate `if` blocks
   (not one && chain), the record is read through an `__asm__` alias without
   `sda` so that the address keeps retail's `lui $v0,%hi(D); lw $s0,%lo(D)($v0)`
   split form, and the unit stays at -G0 (at -G8 that same load comes out
   `lui $s0; lw $s0,%lo(D)($s0)` and no longer matches).
   Still open: the second 0x708 lands in $v0 where retail has $v1.  Tried
   and all identical: the 0x708 constant in a named local (it is then kept
   in $s2 across the call, which the retail does not do), the constant named
   only in the first block, the constant named only in the second block, the
   two inner tests as one && chain, the two tests in the other order.

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

/* The same object as D_L22_0018B6A8, read with an absolute address. */
extern s32 D_L22_0018B6A8_abs __asm__("D_L22_0018B6A8");

void func_L22_00415A48(s32 a0) {
    s32 s1 = *(u32 *)(a0 + 0x68);
    s32 s0;

    if (*(u8 *)(a0 + 0x20) == 0) {
        *(u8 *)(a0 + 0x20) = 1;
        *(u8 *)(a0 + 0x30) = 0xFF;
        *(u32 *)s1 = 0x708;
    }
    if (*(u8 *)(a0 + 0x20) == 1) {
        s0 = D_L22_0018B6A8_abs;
        if (func_2F36F0(s1) != 0) {
            if (*(u32 *)(s0 + 8) == 0) {
                if (*(u32 *)(s0 + 0xC) == 0) {
                    func_2F9E20(0x9FD, 0x54);
                    *(u32 *)s1 = 0x708;
                }
            }
        }
    }
}
