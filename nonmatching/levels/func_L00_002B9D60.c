/* Near miss for func_L00_002B9D60 (412 bytes, 27 places).

   The body is right: the three 16-byte copies (lq/sq), the resident block at
   D_00189EA0-0x80, the call sequence, the flag clearing, the branch on the
   resident mode and the float test all come out as retail does.

   What differs (400 of 412 bytes, the rest in the same order):

   - the register allocation of the two pointers: retail keeps the hero block in
     $s1 and the resident block in $s2, this C keeps them in $s0 and $s1, and the
     128-bit temporary follows ($v0 in retail, $v1 here);
   - retail materialises the address of D_00189EA0+0x250 in a register ($s1) and
     reads the quadword from it (lq $v0,0($s1)), this C folds the 0x250 into the
     lq and computes the argument with an addiu;
   - retail re-materialises the address of D_00189EA0 from the high part it kept
     in $s5 (addiu $s0,$s5,-0x6160), this C keeps the pointer in $s0.

   The addresses of D_00189EA0 and D_00189E20 differ by 0x80 in retail, which the
   compiler only knows when both symbols are in one unit; here the resident
   block is written as D_00189EA0-0x80 to get the same addiu.

   tools/check.py func_L00_002B9D60: 0 of 27 places match (400 bytes, expected 412)
*/

extern char D_00189EA0[];

extern int D_L00_001B9080;

extern void func_00283410_1(void *a, void *b);

extern void func_002833F0_1(void *a, void *b);

extern void func_L00_002B2BD0(void);

extern void func_L00_00322EC8(void *p);

extern void func_L00_002AF7D0(void);

extern void func_L00_002A53B8(void);

extern void func_L00_002C42E0(int a0, int a1);

extern void func_L00_002D23C0(int a0, int a1);

extern void func_L00_002B4900(void);

extern float func_00282E48_1(void *a, void *b);

extern void func_L00_003DF6B0(int a0, int a1);

extern void func_L00_004028C0(void *a, int b);

extern void func_L00_002D9D98(void);

extern void func_L00_00311DC0(void *p);

/* Copies the two incoming vectors into the hero block and into the moby it points at, runs the
   matrix and level helpers on them, clears the flags of the resident block, updates the moby's
   two bytes and the resident mode, then refreshes the hero position when the distance to the
   target is below one. */
void func_L00_002B9D60(void *a0, void *a1, int a2, int a3)
{
    char *res;
    char *hero = D_00189EA0;
    char *target;

    res = hero - 0x80;
    *(TI_F41eb487e *)hero = *(TI_F41eb487e *)a0;
    *(TI_F41eb487e *)((char *)*(void **)(res + 0x2290) + 0x10) = *(TI_F41eb487e *)a0;
    *(TI_F41eb487e *)(hero + 0x10) = *(TI_F41eb487e *)a1;

    func_00283410_1(res, hero + 0x10);
    func_002833F0_1((char *)*(void **)(res + 0x2290) + 0xC0, hero + 0x10);
    func_L00_002B2BD0();
    func_L00_00322EC8(hero + 0x1860);
    func_L00_00322EC8(hero + 0x19B0);

    *(int *)(res + 0x3A4) &= ~1;
    *(int *)(res + 0x3A4) &= ~2;
    *(short *)(res + 0x34E) = 1;
    *(int *)(res + 0x3A0) = 0;
    *(u8 *)(res + 0x24EF) = 0;

    func_L00_002AF7D0();
    func_L00_002A53B8();

    if (a2 != -1)
        func_L00_002C42E0(a2, 2);

    func_L00_002D23C0(*(u8 *)((char *)*(void **)(res + 0x2290) + 0x43),
                      *(u8 *)((char *)*(void **)(res + 0x2290) + 0x41));

    if (*(int *)(res + 0x229C) == 0x11)
        D_L00_001B9080 = 1;
    else
        D_L00_001B9080 = 0;

    func_L00_002B4900();

    if (func_00282E48_1(D_00189EA0, D_00189EA0 + 0x250) < 1.0f)
        *(TI_F41eb487e *)D_00189EA0 = *(TI_F41eb487e *)(D_00189EA0 + 0x250);

    func_L00_003DF6B0(0, 0);
    func_L00_004028C0(0, 0);

    if (a3 != 0)
        func_L00_002D9D98();

    func_L00_00311DC0(*(void **)(D_00189EA0 + 0x2210));
}
