/* func_L16_004117A8 (340 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 340 bytes, the same size as retail, and every instruction is the same
   instruction in the same place; only the registers differ: this source hoists the
   class constants 0xC86 and 0x113A into $fp and $s7 where retail keeps 1 and 2
   there and materialises 0xC86 and 0x113A in the delay slots of the chain.
   check.py (16_snivelak), with the source below:
     16_snivelak: instruction at +0x44 differs
       004117EC  addiu       $fp, $zero, 0xC86        |  addiu       $fp, $zero, 0x1162
       004117F0  addiu       $s7, $zero, 0x113A       |  addiu       $s7, $zero, 0x7FB
       004117F4  addiu       $s6, $zero, 0x1162       |  addiu       $s6, $zero, 0xF35
       004117F8  addiu       $s5, $zero, 0x7FB        |  addiu       $s5, $zero, 0xEA3
       004117FC  addiu       $s4, $zero, 0xF35        |  addiu       $s4, $zero, 0xEA4
       00411800  addiu       $s3, $zero, 0xEA3        |  addiu       $s3, $zero, 0xEBB
       00411804  addiu       $s2, $zero, 0xEA4        |  addiu       $s2, $zero, 0x1
       00411808  addiu       $s1, $zero, 0xEBB        |  addiu       $s1, $zero, 0x2
   What is measured and right:
   - the class word is read unsigned (`lhu`) and sign-extended for the equality
     tests (`sll $v0,$v1,16; sra $v0,$v0,16`), so the source keeps it in a u16 and
     casts at the comparison; a `s16` variable makes cc1 emit a narrowing `lh` load
     instead (152 bytes of body, tested).
   - the range test is the unsigned one (`addiu $v0,$v1,-0xE71; sltiu $v0,$v0,3`), so
     it has to be written on the unsigned value: `id - 0xE71 < 3` with a u32 id.
   - the byte at the result's +0xE is compared against 1 and set to 2; the call to
     func_0029F338 happens only in the "not 1" branch (retail's `bne $v0,$s2` jumps
     to the call, the "is 1" branch jumps over it), so the source has an else.
   - the two `$gp` reads of D_L16_001B2B20 (the limit) come out as `lw $v0,0x3B30($gp)`
     in the delay slots and as `lui $v0,0x1B; lw $v0,0x2B20($v0)` in the ordinary flow
     with the `sda` attribute, in a -G0 unit.
   Not matched: which of the eleven constants of the loop body get one of the eight
   callee-saved registers. This source's set is {0xC86, 0x113A, 0x1162, 0x7FB, 0xF35,
   0xEA3, 0xEA4, 0xEBB}, retail's is {0x1162, 0x7FB, 0xF35, 0xEA3, 0xEA4, 0xEBB, 1, 2}.
   Tried and not enough: one `||` chain against two `if`s (the two `if`s change the
   body to 344 bytes), the range test written as a comparison pair, the class chain
   split in three, and the chain order permuted (the order follows the source).
   Next idea: the constant hoisting of this cc1 sorts its candidates by the order of
   the RTL; a source that reads the class once and keeps the unsigned and the signed
   value in two variables may change the order the candidates are built in. */

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int s32;

extern u8 *D_L16_001B2B1C[] __attribute__((sda));

extern u8 *D_L16_001B2B20[] __attribute__((sda));

extern u8 *func_002AB1F0(u8 *);

extern void func_0029F338(void *);

/* Walks the level's entity list and reports the classes that need a second pass. */
void func_L16_004117A8(u8 *arg0)
{
    u8 *s0;
    u8 *r;
    u32 id;
    s16 cls;

    s0 = D_L16_001B2B1C[0];
    if (D_L16_001B2B20[0] < s0)
        return;
    do {
        id = *(u16 *)(s0 + 0xAA);
        if (id - 0xE71 < 3 || (s16)id == 0xC87 || (s16)id == 0xC86
            || (s16)id == 0x113A || (s16)id == 0x1162 || (s16)id == 0x7FB) {
            func_0029F338(s0);
        }
        cls = *(s16 *)(s0 + 0xAA);
        if (cls == 0xF35 || cls == 0xEA3 || cls == 0xEA4 || cls == 0xEBB) {
            r = func_002AB1F0(s0);
            if (r != 0) {
                if (*(u8 *)(r + 0xE) == 1) {
                    *(u16 *)(s0 + 0xB6) = 0;
                    *(u16 *)(s0 + 0xB4) = 0;
                    *(u8 *)(r + 0xE) = 2;
                } else {
                    func_0029F338(s0);
                }
            }
        }
        s0 += 0x100;
    } while (D_L16_001B2B20[0] >= s0);
}
