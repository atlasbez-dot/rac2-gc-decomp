/* func_L20_0043F460 (176 bytes, level 20): near miss, 44 of 44 words, six words differ.
 *
 * What matches: the frame (0x30), the two calls (func_002A7878 with the $gp float and the
 * absolute float, func_002A7820), the 210000.0f materialisation into $f1 and the mul.s in the
 * second call's delay slot, the branch on *(short *)(arg0 + 0xAA) == 0xB5A, the two arm loads
 * and the two stack stores.
 *
 * What differs: the register allocation of the two arms and the branch delay slot.
 *   retail 0043F4B0  lw    $v0, 0x2FD0($gp)      (the C0 value, in the bne delay slot)
 *          0043F4B4  lui   $v1, %hi(D_001B1FC4)
 *          0043F4B8  lw    $v1, %lo(D_001B1FC4)($v1)
 *   ours   0043F4B0  lui   $v0, %hi(D_L20_001B1FC8)   (the else arm's address, in the slot)
 *          0043F4B4  lw    $v1, D_L20_001B1FC0
 *          0043F4B8  lui   $v0, %hi(D_001B1FC4)
 *          0043F4BC  lw    $t1, %lo(D_001B1FC4)($v0)
 * The retail puts the address pseudo in the same register as its value (base == dest) and the
 * phi of the second element in $v1; this cc1 puts the address in $v0 and the phi in $t1, and
 * fills the bne delay slot with the else arm's address instead of the arm's load.  Twenty-one
 * spellings were measured: array vs struct vs two scalars, both arm orders, the condition in a
 * variable, goto instead of if/else, plain vs nosda vs sda on every global, and the two
 * constants under two names (no CSE).  The frame, the size and the block structure are right;
 * the register allocation and the delay-slot choice are the wall.
 */
extern float D_L20_001B1FD0 __attribute__((sda));
extern float D_L20_001B1FD4;
extern int D_L20_001B1FC0 __attribute__((sda));
extern int D_L20_001B1FC4 __attribute__((nosda));
extern int D_001B1FC4 __attribute__((nosda));
extern int D_L20_001B1FC8 __attribute__((nosda));
extern int D_L20_001B1FCC __attribute__((nosda));
extern char D_L20_001A8F20[];
extern float func_002A7878(float, float);
extern int func_002A7820(int, int);
extern void func_002BDBC0(char *, char *, int, int, int, float);

void func_L20_0043F460(char *arg0) {
    char *s0 = arg0;
    float f20;
    int r;
    int a[2];
    int b;

    f20 = func_002A7878(D_L20_001B1FD0, D_L20_001B1FD4) * 210000.0f;
    r = func_002A7820(0x14, 0x50);
    if (*(short *)(s0 + 0xAA) == 0xB5A) {
        a[0] = D_L20_001B1FC0;
        b = D_001B1FC4;
    } else {
        a[0] = D_L20_001B1FC8;
        b = D_L20_001B1FCC;
    }
    a[1] = b;
    func_002BDBC0(s0 + 0x10, D_L20_001A8F20, D_L20_001B1FC0, D_L20_001B1FC4, r, f20);
}
