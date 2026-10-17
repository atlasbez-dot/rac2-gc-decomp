/* func_L23_00418650 (124 bytes, 1 place) -- measured 0 of 1: SIZE IS RIGHT (124), three
   instruction-ordering differences left. (Wave 6, Docker-free ruler; provisional.)

   Retail builds a sixteen-byte vector in a stack local through three shared helpers
   and copies it back over the argument:
     func_00282CF0(local, arg0, D_00189ED0)
     func_00282F20(local, local, arg1 + D_001B36A4)
     func_00282CC0(local, local, D_00189ED0)
     *(V4 *)arg0 = *(V4 *)local                       /* lq/sq */

   With the source below every instruction is present and the size matches; what
   differs is the interleaving of three independent pairs:
     1) +0x14: this cc1 emits `daddu $s1,$a0,$zero` BEFORE the second half of the
        basis address (`addiu $s0,$s0,-0x6130`); retail has the address pair first.
        (-mno-split-addresses was tried on the whole file: the other eight functions
        in L23_00416388.c stay matched, this one keeps the same swap.)
     2) +0x34: the float constant D_001B36A4 loads through `lui $2` here, `lui $at`
        in retail.
     3) +0x60: `lq $2,0($sp); ld $s0,0x10($sp); sq $2,0($s1)` here against retail's
        `lq $v0,0($sp); sq $v0,0($s1); ld $s0,0x10($sp)` (the copy before the restores).
   A `char *base = D_00189ED0;` local changes nothing; a `float k = D_001B36A4 + arg1;`
   local moves the first difference to +0x8 (worse).
*/

typedef int V4_L23_418650 __attribute__((mode(TI)));

extern char D_00189ED0[];
extern float D_001B36A4;
extern void func_00282CF0_L23(char *dst, char *src, char *arg);
extern void func_00282F20_L23(char *dst, char *src, float arg);
extern void func_00282CC0_L23(char *dst, char *src, char *arg);

void func_L23_00418650(char *arg0, float arg1) {
    char local[16];

    func_00282CF0_L23(local, arg0, D_00189ED0);
    func_00282F20_L23(local, local, arg1 + D_001B36A4);
    func_00282CC0_L23(local, local, D_00189ED0);
    *(V4_L23_418650 *)arg0 = *(V4_L23_418650 *)local;
}
