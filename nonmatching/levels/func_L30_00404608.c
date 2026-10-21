/* Near miss: 228 bytes against retail's 236, and the retail row itself starts eight
   bytes early. The 236-byte extent at 0x00404608 opens with

       addiu $sp,$sp,0x50   /  nop

   which is linker fill, not code: the real body is the 228 bytes at 0x00404610, from
   `addiu $sp,$sp,-0x30` to the `jr $ra` at 0x004046F0, and the previous row
   (func_L16_004051A8) ends cleanly at 0x00404608 with its own `jr $ra` at 0x00404600
   and its delay slot `addiu $sp,$sp,0xD0` at 0x00404604. A tools/levels.py entry
   (the LEVEL_ENTRY_OFFSETS list that already carries three level-00 rows) would move the
   start to 0x00404610; that is not a worker's to make.

   The body below is that reconstruction: 228 bytes, and it differs from the retail body
   in the register choice only - retail keeps the scale in $f20 and the 1.0f in $f21 where
   this cc1 keeps the 1.0f in $f20 and the scale in $f21, and retail gives $s0 to the
   random length where this cc1 gives it $s2. The rest (the two calls to
   func_L16_00405818, the two random lengths 0x5F/0x6F and 0x6F/0x7F, the two random
   angles and the two $gp-relative scales) is in the retail order.

   It needs the -g8 sibling of the level unit: the scales and the four $gp-relative
   words are small data (D_L30_001B15A4, D_L30_001B15A8, D_L30_001B15AC, D_L30_001B15B0,
   D_L30_001B156C, D_L30_001B1570 - $gp = 0x1AEFF0), so the unit is built with -G8
   and the globals carry the sda attribute. */

extern float D_L30_001B15AC __attribute__((sda));
extern float D_L30_001B15B0 __attribute__((sda));
extern int D_L30_001B156C __attribute__((sda));
extern int D_L30_001B1570 __attribute__((sda));
extern int D_L30_001B15A4 __attribute__((sda));
extern int D_L30_001B15A8 __attribute__((sda));

extern int func_002A7820(int, int);
extern float func_002A7940(void);
extern void func_L16_00405818(char *, int, int, int, float, float, float, int, char *);

void func_L30_00404608(char *a0) {
    float scale = D_L30_001B15AC * *(float *)(a0 + 0x2C);
    int len = func_002A7820(0x5F, 0x6F);
    float angle = func_002A7940();

    func_L16_00405818(a0 + 0x10, D_L30_001B156C, len, D_L30_001B15A4, scale, angle, 1.0f, 2, a0);

    scale = D_L30_001B15AC * *(float *)(a0 + 0x2C) * D_L30_001B15B0;
    len = func_002A7820(0x6F, 0x7F);
    angle = func_002A7940();
    func_L16_00405818(a0 + 0x10, D_L30_001B1570, len, D_L30_001B15A8, scale, angle, 1.0f, 2, a0);
}
