/* 0 of 2 places match - last line: 09_dobbo: instruction at +0x38 differs (572 bytes, retail 572)
   Picks, among the class-0xD0F entities of the object's group, the one nearest to a vector
   read from the 0x2C0 record, and copies the caller's 0x2B0..0x31D parameter block into it.
   Needs $gp (group count, a halfword at gp+0x1F68), so it belongs in L09_002B7238-g8.c between
   func_L09_003F72A8 and func_L09_003F8898; it calls func_L09_003F72A8 and func_L09_003F71C8,
   both matched there.

   Measured: 19 of the 143 words differ, all of them in the preheader at +0x38..+0x8C; the
   prologue, the whole walk and the 0x2B0..0x31D copy block are word for word retail's (the
   0x31C/0x31D stores need the reversed order, the halfword from $gp must be read into a
   local first).
   What differs: retail copies the 16-byte vector with the pointer materialised,
     lw $v1,0($a0) ; addiu $v1,$v1,0x10 ; lq $v0,0($v1) ; sq $v0,0($sp)
   and keeps the preheader in source order (lq/sq, then lbu 0x21($s4), the 100000.0f
   constant, best = 0, the first list pointer), the table index in $a0. This cc1 folds the
   offset: lq $v0,0x10($a2), schedules the lbu and the constant ahead of the copy, and puts
   the index in $v1. That is the known constant-offset wall (cse's find_best_addr tie
   between a register and register + 16, docs/COMPILER-NOTES.md "The constant-offset wall"),
   plus retail's lq/sq pair acting as a scheduling barrier (the pointer computed by its own
   addiu, $v0 as the temporary, nothing moved across it): the shape of a volatile asm quad
   copy taking `entry + 0x10` as an operand, which plain C cannot give.
   Tried (about twelve compiles): the direct TI128 copy, through a TI128 * variable, through
   unsigned arithmetic, through an in-place `src += 0x10`, memcpy of typed TI128 pointers
   (ld/sd pairs or ldl/ldr, never lq), three statement orders for the preheader, a local for
   the index; a screen of 25 single extra flags (-fno-gcse, -fno-schedule-insns{,2},
   -fno-cse-follow-jumps, -mno-split-addresses ...) never materialises the address either.
   Would unblock: a cc1 lever that keeps `reg + 16` out of a TImode address, or a volatile
   barrier (not plain C). */
typedef int TI128 __attribute__((mode(TI)));

extern int D_L09_001B2878 __attribute__((sda));

extern unsigned char *D_L09_001B285C_1[3] __attribute__((sda));

extern unsigned short *D_L09_001FB560[];

extern unsigned char *D_L09_001FE6C0[];

extern unsigned short D_L09_001B0F58_1 __attribute__((sda));

extern float func_00282E80(void *, void *);

extern int func_L09_003F72A8(unsigned char *);

extern int func_L09_003F71C8(unsigned char *, int);

void func_L09_003F8598(unsigned char *a0) {
    unsigned char *s3 = *(unsigned char **)(a0 + 0x68);
    TI128 v;
    unsigned short *p;
    unsigned char *e;
    unsigned char *s0;
    unsigned char *best;
    unsigned char *t;
    unsigned short w;
    int idx;
    float bestd;
    float d;
    int n;

    idx = *(int *)(s3 + 0x2C0);
    if (idx == -1)
        return;
    v = *(TI128 *)(D_L09_001FE6C0[idx] + 0x10);
    p = D_L09_001FB560[a0[0x21]];
    best = 0;
    bestd = 100000.0f;
    for (;
         a0[0x21] != 0xFF && a0[0x21] <= D_L09_001B2878 && p != 0 &&
         ((p != 0 && (short)p[-1] >= 0) || p == D_L09_001FB560[a0[0x21]]);
         p++) {
        e = D_L09_001B285C_1[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        s0 = *(unsigned char **)(e + 0x68);
        d = func_00282E80(e + 0x10, &v);
        if (s0 == 0)
            continue;
        if ((s0[0x302] & 1) == 0)
            continue;
        if (*(int *)(s3 + 0x420) != -1) {
            n = func_L09_003F72A8(a0) + 1;
            if (n != *(int *)(s0 + 0x420))
                continue;
            if (func_L09_003F71C8(e, n) >= *(int *)(s0 + 0x42C))
                continue;
        }
        if (*(int *)(s3 + 0x424) != 0 && *(int *)(s3 + 0x424) != *(int *)(s0 + 0x424))
            continue;
        if (d < bestd) {
            bestd = d;
            best = e;
        }
    }
    if (best != 0) {
        t = *(unsigned char **)(best + 0x68);
        w = D_L09_001B0F58_1;
        *(int *)(t + 0x2B0) = *(int *)(s3 + 0x2B0);
        *(int *)(t + 0x2B4) = *(int *)(s3 + 0x2B4);
        *(int *)(t + 0x2B8) = *(int *)(s3 + 0x2B8);
        *(int *)(t + 0x2BC) = *(int *)(s3 + 0x2BC);
        *(int *)(t + 0x2C0) = *(int *)(s3 + 0x2C0);
        *(int *)(t + 0x2D0) = *(int *)(s3 + 0x2D0);
        *(int *)(t + 0x2D4) = *(int *)(s3 + 0x2D4);
        *(unsigned short *)(t + 0x2E0) = w;
        *(int *)(t + 0x2DC) = *(int *)(s3 + 0x2C0);
        t[0x2EA] = 1;
        t[0x302] = (t[0x302] | 2) & 0xFE;
        t[0x303] = s3[0x303];
        *(unsigned short *)(best + 0x34) = *(unsigned short *)(best + 0x34) & 0xFFFD;
        t[0x31D] = 1;
        t[0x31C] = 1;
    }
}
