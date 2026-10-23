/* func_L04_00456628 (288 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 292 bytes, 71 of 72 words identical; the fault is the mask on the flag.
   check.py (04_barlow), with the source below:
     00456654  beqz  $v0,0x21        |  beqz  $v0,0x21
     00456658  daddu $a0,$v0,$zero   |  daddu $a0,$v0,$zero
     00456670  andi  $v0,$a0,0xFF   |  andi  $v0,$a0,0xFF   <- retail only
   Everything through the "state == 0" test matches; retail then keeps the
   flag's low byte in a separate AND (twice: in the bnez delay slot and again at
   +0xB4) where this compiler folds `flag & 0xFF` to the flag itself and spends
   the word elsewhere, so the function is one word longer.
   The flag byte is D_001A7B1F; the second byte tested is D_001495CA (the base
   symbol is D_001395B8, the byte is at +0x12) and the byte written back is
   D_001395CA. The address of the second one is what makes the %hi live in a
   callee-saved register (daddu $a1,$v0,$zero then addiu $v0,$a1,-0x6A48): the
   same global has to be reached through a second C name for that form to appear.

   What is measured and right:
   - the unit is a -G0 one (src/levels/04_barlow/L04_00422A00.c): at -G8 the
     function grows to 296 bytes and the addresses change form.
   - the flag is read into $a0 (the argument register is dead after the copy to
     $s0) and the tests are on it; the "state == 1" tail reuses $s1 for the byte.
   - the branch to the epilogue after func_342228 is a likely beql in retail and
     a plain beqz here.
   - the loop over the four moby words and the func_2DFC18 call with its 0 and 1
     arguments come out exactly.
   Tried and not enough: the flag as u8, s32, u32 and a pointer; the mask
     written as (u32)flag & 0xFF; the flag read through a pointer variable; the
     two D_001395CA accesses written as one symbol or as two. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_001A7B1F[];
extern u8 D_001395B8[];
extern u8 D_001395CA;
extern s32 D_L04_001B2008[];
extern u8 *D_L04_001B25CC;
extern u8 D_0019E9A0[];

extern void func_2DFC18(void *a0, void *a1, s32 a2, s32 a3);
extern void func_3317E8(void *a0);
extern s32 func_342228(void *a0, void *a1);

/* Starts the object's state, then hands it to the level's helper when the
   object is the one the level is waiting for. */
void func_L04_00456628(u8 *a0) {
    u8 *s2 = *(u8 **)(a0 + 0x68);
    u8 *s1;
    s32 flag;
    u8 *p;

    if (a0[0x20] == 0) {
        flag = D_001A7B1F[0];
        if (flag == 0) {
            a0[0x20] = 1;
            a0[0x30] = 0xFF;
        } else if (D_001395B8[0x12] == 0 && D_L04_001B2008[0] < 5) {
            p = D_L04_001B25CC + (*(s32 *)(s2 + 4) << 7);
            func_2DFC18(p + 0x30, p + 0x70, 0, 1);
            a0[0x30] = 0xFF;
        } else if ((flag & 0xFF) == 0) {
            a0[0x20] = 1;
            a0[0x30] = 0xFF;
        } else if (D_001395B8[0x12] == 0) {
            a0[0x20] = flag & 0xFF;
            a0[0x30] = 0xFF;
        } else {
            func_3317E8(a0);
            return;
        }
    }
    s1 = a0[0x20];
    if (s1 == 1) {
        if (func_342228(D_0019E9A0, *(void **)s2) != 0) {
            if (D_001A7B1F[0] != 0) {
                D_001395CA = s1;
                func_3317E8(a0);
            }
        }
    }
}
