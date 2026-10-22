/* func_L05_003CD1A8 (212 bytes, 4 places) -- NEAR MISS, not integrated.
   state: 204 bytes, the body matches retail from the prologue to the three header stores
   and again from the list walk to the epilogue; the fault is the schedule of the header
   stores and of the two constants 0xFF.
   check.py (05_feltzin_system), with the source below:
     003CD1C8  beqz  $s0, . + 4 + (0x26 << 2)  |  beqz  $s0, . + 4 + (0x24 << 2)
     003CD1CC  addiu $v1, $zero, 0xFF          |  addiu $v0, $zero, 0xFF
     003CD1D0  addiu $v0, $zero, 0xFF          |  addiu $a0, $zero, 0x1
     003CD1D4  sh    $v1, 0x32($s0)            |  sh    $v0, 0x32($s0)
     003CD1D8  addiu $a1, $zero, 0x1           |  addiu $a1, $s1, 0x10
     003CD1DC  sb    $v0, 0x30($s0)            |  sb    $a0, 0x30($s0)
   What is measured and right:
   - the file must build at -O2 -G8 -ffunction-sections -frac2-qcopy
     (src/levels/shared/L05_0037BC08-g8.c): the 128-bit copy needs the grouped quadword
     copy to stay one instruction, and -G8 is what keeps the %hi of the two globals
     rematerialised at each use.
   - the float store at +0xF8 is unconditional; the branch at +0x8 only skips the list
     walk, so the source must store the float before the test, not inside it.
   - the test is on the flag at $gp+0xAB0 (0x1AFAA0), which needs
     __attribute__((sda)) to be reached $gp-relative; the list head at 0x1B2528 stays
     absolute.
   - the three header stores keep retail's order only when they are volatile; without
     volatile the compiler emits them in the reverse order (sb 0x31, sb 0x30, sh 0x32).
   Tried and not enough: the header stores volatile and not; the short store signed and
     unsigned; the 0xFF as a local variable; the mask 0xFBF as a local variable; the
     float store inside and outside the test; the list walk in an if and in a goto.
   Next idea: a lever that pins the second 0xFF copy (retail materialises 0xFF twice, in
     $v1 and $v0, and ours once) and the float store in the branch's delay slot. */

typedef int TI128 __attribute__((mode(TI)));

extern int D_L05_001AFAA0 __attribute__((sda));
extern char *D_L05_001B2528;

extern int func_0029EFD0(int);
extern void func_00282C88(int);
extern float func_002A7940(void);
extern void func_L05_003CD4C0(char *);

/* Sets the object's header, copies the caller's sixteen bytes into it, and looks the
   object up in the list the game keeps. */
char *func_L05_003CD1A8(char *object)
{
    char *s0;
    char *node;
    char *found;
    float f;

    s0 = (char *)func_0029EFD0(0x946);
    if (s0 != 0) {
        *(volatile short *)(s0 + 0x32) = 0xFF;
        *(volatile unsigned char *)(s0 + 0x30) = 0xFF;
        *(volatile unsigned char *)(s0 + 0x31) = 1;
        *(TI128 *)(s0 + 0x10) = *(TI128 *)(object + 0x10);
        func_00282C88((int)(s0 + 0xF0));
        f = func_002A7940();
        *(float *)(s0 + 0xF8) = f;
        if (D_L05_001AFAA0 == 0) {
            node = D_L05_001B2528;
            if (node != 0) {
                found = 0;
                do {
                    found = ((*(short *)(node + 0xAA) ^ 0xFBF) == 0) ? node : found;
                    node = (char *)(*(int *)(node + 0x28));
                } while (node != 0);
                D_L05_001AFAA0 = (int)found;
            }
        }
        func_L05_003CD4C0(s0);
        *(float *)(s0 + 0x2C) = *(float *)(*(int *)(s0 + 0x24) + 0x24);
        return s0;
    }
    return 0;
}
