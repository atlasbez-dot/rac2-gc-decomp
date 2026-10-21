/* 0 of 27 places match - last line: 00_aranos_tutorial: 112 bytes, expected 112
   The body is recovered and the sizes agree, but the register allocation and
   the re-materialisation of the table differ.  Retail:

     daddu $a3,$a0,$zero ; daddu $v0,$a1,$zero ; beq $a0,$zero,out ;
     daddu $t0,$a2,$zero ; lui $a1,0x1B ; lw $a1,0x1AFC($a1) ;
     sll $a2,$v0,2 ; addu $a1,$a2,$a1 ; lw $v1,0($a1) ; lbu $a0,4($v1) ;
     sll $a0,$a0,3 ; addu $v1,$a0,$v1 ; sw $t0,0($v1) ; lw $v0,0($a1) ;
     addu $v0,$a0,$v0 ; sb $t0,5($v0) ; lui $v1,0x1B ; lw $v1,0x1AFC($v1) ;
     addu $a2,$a2,$v1 ; lw $v0,0($a2) ; addu $a0,$a0,$v0 ; sh $zero,6($a0) ;
     lw $v1,0($a2) ; lbu $v0,4($v1) ; addiu $v0,$v0,1 ; sb $v0,4($v1)

   i.e. the table's address is materialised TWICE (two `lui`/`lw` pairs), the
   table's entry is re-read FOUR times and the block's byte counter is read
   twice, while the candidate keeps one address register and one entry in a
   register.  Measured in this wave:

     - the declaration must not carry `__attribute__((sda))`: retail uses the
       absolute `lui`/`lw` form, not the `$gp`-relative one;
     - the table and the block have to be `volatile` for the re-reads to
       survive (with a plain pointer the compiler keeps the entry in a
       register);
     - giving the global a second name (`extern u8 * volatile * volatile
       D_L00_001B1AFC_b __asm__("D_L00_001B1AFC");`) does force the second
       `lui`/`lw` pair, but the argument copies (`daddu $a3,$a0,$zero`,
       `daddu $v0,$a1,$zero`, `daddu $t0,$a2,$zero`) still come out missing and
       the entry is still kept in a register;
     - the three argument copies are 64-bit moves of the three arguments into
       `$a3`, `$v0` and `$t0`; a source that copies the arguments into
       locals gives them, but the block then spills to the stack.

   What would unblock it: a source shape in which the three arguments are
   copied into `$a3`, `$v0` and `$t0` and the table's entry is read from
   memory on every use, without spilling the block. */

typedef int s32;
typedef unsigned char u8;

extern u8 * volatile * volatile D_L00_001B1AFC;

void func_L00_003296C0(s32 enabled, s32 index, s32 value) {
    u8 * volatile * table;
    u8 * volatile record;
    s32 offset;

    if (enabled == 0)
        return;
    table = D_L00_001B1AFC;
    record = table[index];
    offset = record[4] << 3;
    *(s32 *)(record + offset) = value;
    *(u8 *)(record + offset + 5) = (u8)value;
    table = D_L00_001B1AFC;
    *(unsigned short *)(table[index] + offset + 6) = 0;
    record[4] = record[4] + 1;
}
