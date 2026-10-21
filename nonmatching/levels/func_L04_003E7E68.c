/* Near miss: the body, the control flow, the argument block and the dispatch all come
   out right; the registers of the argument block do not. Retail at 0x003E7E68, level 04
   (380 bytes, 1 place) reads a global record, picks one of four calls by the object's
   type byte and passes thirteen arguments in a block on the stack:

     void f(char *a0)
     {
         L04_003E7E68_ARGS args;
         L04_003E7E68_G *g = &D_0012EE20;
         char *s1 = a0;
         char *s0;
         char *p;
         int t6;
         int v1;
         int t5;
         int c;

         p = (char *)g->f1830;
         if (p == 0)
             goto have_s0;
         if (*(short *)(p + 0xAA) != 0x45) {
             s0 = *(char **)(s1 + 0x68);
             goto common;
         }
         c = *(unsigned char *)(p + 0x20);
         if (c == 0xFE)
             goto have_s0;
         if (c == 0xFD)
             goto have_s0;
         if (g->f2294 == 0x31)
             return;
     have_s0:
         s0 = *(char **)(s1 + 0x68);
     common:
         if (s0 == 0)
             return;
         v1 = *(int *)(s0 + 0x18);
         t6 = 1;
         if (v1 != -1)
             t6 = ((int *)&D_001AFFA0)[v1];

         args.f00 = 10;
         args.f04 = t6 + *(int *)(s0 + 0x10);
         args.f20 = (int)&D_001AFFD4;
         args.f24 = (int)&D_001AFFD8;
         args.f08 = (int)&D_0002A6C0;
         args.f0C = (int)&D_000245C0;
         args.f10 = (int)&D_001AFFC0;
         args.f14 = (int)&D_001AFFA0;
         args.f18 = (int)&D_00024660;
         args.f1C = (int)&D_00026660;
         args.f28 = (int)s1;
         args.f2C = (int)func_L04_003E7FE8;
         args.f30 = (int)func_L00_002E6EF8;

         t5 = *(unsigned char *)(s1 + 0x20);
         switch (t5) {
         case 0:
             func_L04_003A1A78(&args);
             func_L04_003A5C08(s1, *(float *)(s0 + 0x28));
             /* fall through */
         case 1:
             func_L04_003A1C98(&args);
             break;
         case 2:
             func_L04_003A1FA0(&args);
             break;
         }
         func_L04_003A1FE0(&args);
     }

   The function belongs in the -G8 sibling (the four small globals are addressed
   $gp-relative), so the attempt was made in src/levels/04_barlow/L04_003AB458-g8.c.

   probes "as measured": the four small globals are the boot's D_001AFFA0, D_001AFFC0,
   D_001AFFD4 and D_001AFFD8, each declared `extern int D_001AFFC0 __attribute__((sda))`
   as the sibling's own D_L04_001B07B0 does - that is what puts the `addiu $tX,$gp,0x..`
   in the code; without the attribute the addresses are lui+addiu. The global record at
   D_0012EE20 is a structure, not a pointer: retail computes its address (`lui $v0,0x19`
   + `addiu $a1,$v0,-0x61E0`) and reads the fields at +0x1830 and +0x2294 from it, so
   the source takes its address. The four object offsets are byte offsets (0x18, 0x10,
   0x28, 0xAA), not int offsets. The dispatch is a `switch` with the case 0 falling
   through into case 1: that is what gives retail's `beq $t5,$t4` / `slti` / `beqz` /
   `beqz` / `beq` chain and the shared `func_L04_003A1C98` call; an if/else-if chain
   or goto form does not. The two 0xFE/0xFD compares must be two separate `if`s with
   a goto, or the compiler folds them into the range check `(c + 3) & 0xFF < 2`.

   Remaining gap: the first difference is at +0x70, the constant 1 (candidate $a1,
   retail $t6); the table's address lands in $t6 (retail $t7), the table's value in $a1
   (retail $t6) and the thirteen argument values in other registers than retail's
   ($v0, $v1, $a0-$a3, $t0-$t3, $t6, $t7); the constant 10 is stored before the
   argument block here and inside it in retail. Tried and did not move it: the order
   of the assignments (the source order, the order of the materialisation and the
   order of the stores), an explicit pointer for the table, and the constant 10
   assigned last. Register allocation, the wall already paid. */
