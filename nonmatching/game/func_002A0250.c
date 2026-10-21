/* func_002A0250 - 172 bytes, 28 places (the boot and every level).
   Screened in wave 13 (worker g4): 3 call(s), 0 $gp-relative small-data access(es), 0 MMI lq/sq word(s), 0 64-bit daddu copy(ies), 0 float constant(s).
   Near miss: the body has the retail size (172 bytes), the same three calls, the same
   statement order and the same stores; two differences are left.
   1. the u16 at 0x10FFB0: retail materialises its address into $v0 before the prologue and
      loads through it ("lui $v0,0x11 ; lhu $a1,-0x50($v0)"), this cc1 materialises it into
      the destination register $a1 and only after the prologue ("addiu $sp,$sp,-0x10 ;
      lui $a1,0x11 ; lhu $a1,-0x50($a1)");
   2. the second half: this cc1 hoists the "p + 0x10" of the packet pointer to the top of
      the block, retail computes it after the last load.
   The unit needs -G8 (with -G0 this cc1 common-subexpression-eliminated the lui of the
   0x1Bxxxx data into one register, 168 bytes against the retail 172).  Every 0x1Bxxxx word
   of this body is 0x1B19DC in the levels and 0x1B169C in the boot, so it needs a ref_ name.
   Not matched in wave 13 (worker g4): the register allocation and the scheduling of those two
   instructions were not reproduced. */

extern char D_0010FFC0[];
extern char D_00100080[];
extern int ref_002A0250_00;
extern char *ref_002A0250_01;
extern int ref_002A0250_02;
extern int ref_002A0250_03;
extern char *ref_002A0250_04;
extern int ref_002A0250_05;
extern int ref_002A0250_06;
extern int ref_002A0250_07;
extern int D_001A72D0;
extern int D_001A72D4;
extern void func_002FC410(unsigned int, unsigned int);
extern void func_002FC070(int);
extern void func_002FC560(unsigned int, unsigned long long);

void func_002A0250(void)
{
    char *p;

    func_002FC410((unsigned int)D_0010FFC0, *(unsigned short *)0x10FFB0);
    ref_002A0250_00 = 6;
    func_002FC070((int)D_00100080);
    func_002FC560(0x47, 0x5360B);
    p = ref_002A0250_01;
    ref_002A0250_04 = p;
    ref_002A0250_06 = ref_002A0250_02 + 0xFFFF0000;
    ref_002A0250_05 = ref_002A0250_03;
    D_001A72D0 = D_001A72D4;
    ref_002A0250_01 = p + 0x10;
    ref_002A0250_07 = 0;
}
