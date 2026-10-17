/* 0 of 2 places match - last line: 22_dobbo_orbit: 24 bytes, expected 20
   Bit extract from a float's raw pattern. Every spelling tried (union local, union
   pointer, direct `*(unsigned int *)&value`, `mask` variable, compound shift, union
   parameter) compiles to retail's five instructions plus one instruction: this cc1
   inserts the FPR hazard `nop` after `mfc1 $v1,$f12`, retail has none. The rest -
   `mfc1`, the `daddu $v0,$v1,$zero` copy, `srlv $v0,$v0,$a0`, `andi $v0,$v0,1` - is
   exact. Worth noting for the whole L22 family: the unit has several `F32Bits`
   readers, so this hazard pad may be what stops them too. */

typedef union F32Bits {
    float f;
    unsigned int u;
} F32Bits;

int func_L22_003A2DF8(int bit, float value) {
    F32Bits bits;
    bits.f = value;
    return (bits.u >> bit) & 1;
}
