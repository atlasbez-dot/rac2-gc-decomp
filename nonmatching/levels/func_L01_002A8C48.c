/* 0 of 6 places match - last line: 01_oozla: 536 bytes, expected 540.
   The whole call sequence, both state checks and the tail condition agree; what
   differs is how the resident block at 0x189E20 and the 64K-aligned value
   0x190000 (passed to func_2A8E68) share one `lui $19`:
   retail keeps the block in $s0 (`lui $v0,0x19` + `addiu $s0,$v0,-0x61E0`) and a
   copy of the high fragment in $s1 (`daddu $s1,$v0`), then re-derives the block
   at each tail use (`addiu ...,$s1,-0x61E0`); here the block itself takes $s1 and
   the derived `+0x80` pointer $s0, so the `daddu` copy is missing and the frame
   and the `sh $zero,0x2160` delay-slot filling differ.
   Tried: the tail written through the pointer (536 bytes) and through the raw
   symbol (532, frame shrinks to 0x10 because the pointer is then eliminated).
   Passing `D_00190000` as func_2A8E68's argument (retail shows
   `lui $a0,0x19` with no `%lo`, i.e. a 64K-aligned symbol) moves the prologue
   the wrong way. Reopen: the declaration/binding pair that makes one `%hi`
   serve both the block and the 0x190000 value in retail's order. */

#include "include_asm.h"

extern char D_00189E20[];
extern int D_001A0F40;

extern void func_2A84D8(void);
extern void func_2C7CA8(void);
extern void func_2B4070(void);
extern void func_2ADDC8(void);
extern void func_2AE128(char *a0, char *a1, char *a2);
extern void func_2C37C8(void);
extern void func_2C8628(void);
extern void func_2C8828(void);
extern void func_2AEB80(void);
extern void func_2B9878(void);
extern void func_2AD560(void);
extern void func_2AC598(void);
extern void func_2AC7E0(void);
extern void func_2ACF60(void);
extern void func_2ACD08(void);
extern void func_2A78F0(void);
extern void func_2A7C18(void);
extern void func_2B7C10(void);
extern void func_2A7740(void);
extern void func_2AB028(void);
extern void func_2ABC90(int a0);
extern void func_2B2B38(void);
extern void func_2B2D30(void);
extern void func_2B2C18(void);
extern void func_2B05D8(void);
extern int func_2CBBE8(void);
extern void func_2A9520(void);
extern void func_2A9310(void);
extern void func_2A8670(void);
extern void func_2CB688(void);
extern void func_2A8320(void);
extern void func_2CA928(void);
extern int func_2A8E68(void);
extern void func_2FDB00(void *a0);
extern void func_30F444(int a0);
extern void func_2A9298(void);
extern void func_2AB328(void);

void func_L01_002A8C48(void) {
    char *p;

    p = D_00189E20;
    *(short *)(p + 0x2162) = 0;
    if (*(unsigned char *)(p + 0x22B4) != 0) {
        *(short *)(p + 0x2160) = 0;
        func_2A84D8();
        return;
    }
    func_2C7CA8();
    func_2B4070();
    func_2ADDC8();
    func_2AE128(p + 0x80, p + 0x90, p + 0x550);
    func_2C37C8();
    if (D_001A0F40 == 2 || D_001A0F40 == 6) {
        if (*(unsigned char *)(p + 0x22B5) != 0)
            func_2C8628();
        else
            func_2C8828();
        return;
    }
    func_2AEB80();
    if (*(unsigned char *)(p + 0x22B4) != 0)
        return;
    func_2B9878();
    func_2AD560();
    func_2AC598();
    func_2AC7E0();
    func_2ACF60();
    func_2ACD08();
    func_2A78F0();
    func_2A7C18();
    func_2B7C10();
    func_2A7740();
    func_2AB028();
    func_2ABC90(0);
    func_2B2B38();
    func_2B2D30();
    func_2B2C18();
    func_2B05D8();
    if (*(unsigned char *)(p + 0x22B5) == 0) {
        if (func_2CBBE8() != 0)
            func_2C8628();
        else
            func_2C8828();
    }
    func_2A9520();
    func_2A9310();
    func_2A8670();
    func_2CB688();
    func_2A8320();
    func_2CA928();
    if ((*(int *)(p + 0x229C) == 0x16 || *(int *)(p + 0x229C) == 0x1F
         || *(int *)(p + 0x2294) == 0x31) && func_2A8E68() != 0)
        func_2FDB00(p + 0x80);
    func_30F444(*(int *)(p + 0x2290));
    func_2A9298();
    func_2AB328();
}
