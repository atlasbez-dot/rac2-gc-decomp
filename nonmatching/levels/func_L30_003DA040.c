/* Near miss: 308 bytes against retail's 324. The switch, the three arms, the calls, the
   loads and the stores are all in the retail order; what is missing is the two
   address computations around each 16-byte copy.

   The retail body at 0x003DA040 (level 30) switches on the state byte at +0x20 of the
   object. Arm 0 copies the object's own 16 bytes at +0x10 into the state block's slot at
   +0x100, arm 2 copies them back, arm 1 asks func_3232D0 for 0x10000 and then hands the
   two results to func_320FD0/func_320CF0; the byte at +0xA8 ends as 0xFF in every arm.
   The two copies are 128-bit, and retail emits them as

       addiu $v1,$v1,0x100   /  addiu $a0,$s0,0x10  /  lq $v0,0x0($a0)  /  sq $v0,0x0($v1)

   - the addresses are materialised in registers, and the lq/sq carry no offset. This
   cc1 folds the offsets into the lq/sq instead

       lq $v0,0x10($s0)  /  sq $v0,0x100($v1)

   and so is 16 bytes short. Twelve spellings of the copy were tried (the mode(TI) type
   direct, through a char* pair, through two reassigned pointer variables, through a
   void* pair, through a local, through a local array, with the operands exchanged, with
   a volatile object, through a 64-bit cast) and this cc1 always folds the offset: the
   128-bit copy has to go through a mode(TI) type to reach lq/sq at all, and that path
   folds. The retail shape wants the two addresses as separate values before the copy.

   The rest of the body matches: the switch dispatch (beq 1, slti 2, beqz 0, beq 2), the
   0xFF constant, the 1.0f/0.0f at +0x48 and the 0x10000 argument. */

typedef int L30TI128 __attribute__((mode(TI)));

extern void func_320FD0(char *, int, int);
extern void func_320CF0(char *, int, int, int);
extern int func_3232D0(char *, int, int);

void func_L30_003DA040(char *a0) {
    char *st = *(char **)(a0 + 0x68);

    switch (*(unsigned char *)(a0 + 0x20)) {
    case 0:
        *(L30TI128 *)(st + 0x100) = *(L30TI128 *)(a0 + 0x10);
        func_320FD0(a0, 1, -1);
        if (*(unsigned char *)(a0 + 0x43) != 1) {
            func_320CF0(a0, 0, 0, 1);
        }
        *(float *)(a0 + 0x48) = 0.0f;
        break;
    case 1:
        if (func_3232D0(a0, 0x10000, 0) != 0) {
            func_320FD0(a0, 2, -1);
            if (*(unsigned char *)(a0 + 0x43) != 1) {
                func_320CF0(a0, 1, 0, 1);
            }
            *(float *)(a0 + 0x48) = 1.0f;
        }
        break;
    case 2:
        if ((*(unsigned char *)(a0 + 0x60) & 2) != 0) {
            *(L30TI128 *)(a0 + 0x10) = *(L30TI128 *)(st + 0x100);
            func_320FD0(a0, 1, -1);
            if (*(unsigned char *)(a0 + 0x43) != 0) {
                func_320CF0(a0, 0, 0, 1);
            }
            *(float *)(a0 + 0x48) = 0.0f;
        }
        break;
    }
    *(unsigned char *)(a0 + 0xA8) = 0xFF;
}
