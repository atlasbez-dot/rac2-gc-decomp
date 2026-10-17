/* 0 of 1 places match - last line: 01_oozla: instruction at +0x30 differs
   Size EXACT (180) and every instruction is right except one swap: retail puts
   `sw $zero,0x350($s0)` in the `beqz` delay slot and the call's argument setup
   (`addiu $a0,$zero,0x12C`) after it, this cc1 emits them the other way round.
   Everything else is byte-identical, branch layout included: the `beql $v0,$zero`
   guard on the 0x350 field with `lw $v1,0x244($s0)` annulled in its delay slot, the
   0x330 < 200 test, the 300/360 call, the `beql $v1,$v0` on the 0x244 == 1 test with
   `lhu $v1,0x96($s1)` annulled, the flags walk (`ori 0xFFFD` / `sltu` / `bnez` with
   `addiu $v0,$v1,1` in the delay slot), the two 0x00282948 calls on +0x32C/+0x334 and
   the tail func_002B0990(a0, p+0x250, 6, 1, 4.0f).
   Measured with five spellings (the order of the store and the call statement, the
   call's value in a local, the field read inline): all 180, all swapping the same pair. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern s32 func_002A7820(s32, s32);
extern void func_00282948(u8 *);
extern void func_002B0990(u8 *, u8 *, s32, s32, f32);

void func_L01_003B5310(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 flags;

    if (*(u32 *)(p + 0x350) != 0 && *(s32 *)(p + 0x330) < 200) {
        *(u32 *)(p + 0x350) = 0;
        *(u32 *)(p + 0x330) = func_002A7820(300, 360);
    }
    if (*(u32 *)(p + 0x244) != 1)
        func_00282948(p + 0x330);
    flags = *(u16 *)(a0 + 0x96);
    if (flags < 65534)
        *(u16 *)(a0 + 0x96) = flags + 1;
    func_00282948(p + 0x32C);
    func_00282948(p + 0x334);
    func_002B0990(a0, p + 0x250, 6, 1, 4.0f);
}
