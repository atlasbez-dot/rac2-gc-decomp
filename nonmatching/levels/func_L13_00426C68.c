/* func_L13_00426C68 - 368 bytes, 5 place(s), level 13_boldan, retail at
   0x00426c68. Screened with tools/w10_screen.py: 4 call(s)
   [func_002FC560@00426CB0, func_0027DE50@00426CD4,
   func_L00_00416A38@00426D4C, func_L00_00416A38@00426DBC]; data addresses
   materialised [0x1a0000, 0x80800000, 0x3dcc0000, 0x3dcc0000]; float
   constants [0x3f000000, 0x3f000000]; $gp-relative small data: no   saves:
   -; callee-saved registers saved [-]; words plain C cannot emit [COP1
   46800020@0x00a0, COP1 46800020@0x0114]. Head: addiu $sp, $sp, -0x20 ; sd
   $s1, 0x8($sp) ; sd $ra, 0x10($sp) ; daddu $s1, $a0, $zero ; sd $s0,
   0x0($sp) ; lw $s0, 0x68($s1). Not matched in this wave: the float code
   has to come out of the same expression tree to keep the FPU registers.
   What would unblock it: the exact source expression tree, so this cc1
   picks the same registers in the same order. */

/* Manual C reconstruction, retained after bounded retail comparison.
 * This body supersedes the historical screening conclusions above.
 * Profile: -O2 -G0 -ffunction-sections
 * Measured text: 368 bytes; retail: 368 bytes. US/US2/PAL: 0/5 placements in each carrying
 * release.
 * 3 distinct measured forms. Equal size; first real difference +0xA8: floating-point
 * constant/load/multiply scheduling. An explicit weight temporary and -fno-schedule-insns
 * both worsened the first difference. Reopen with a new expression/scheduling hypothesis.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

extern short D_001A6480[];
extern void func_002FC560(unsigned int, unsigned long long);
extern void func_0027DE50(int, int, int, int, unsigned long);
extern void func_L00_00416A38(void *, int, int, float, float, float, float, float);

void func_L13_00426C68(char *object) {
    char *state = *(char **)(object + 0x68);
    int elapsed;
    float start;
    if (*(short *)(state + 2) - *(short *)state < 2) {
        if (*(short *)(state + 4) != 0) {
            if (*(int *)(state + 0x1C) != 0) {
                func_002FC560(0x42, 0x48);
                func_0027DE50(0, D_001A6480[0xA9], 0, D_001A6480[0xA8], (unsigned long)(int)0x80808080);
            }
        }
    }
    if (*(int *)(state + 0x18) != 0) {
        elapsed = *(short *)(state + 2) - *(short *)state;
        if (elapsed < 10) {
            start = *(float *)(state + 8);
            func_L00_00416A38(object + 0x10, 60, 0,
                start + (*(float *)(state + 0xC) - start) * ((float)elapsed * 0.1f),
                0.5f, 0.0f, 0.0f, 0.0f);
        } else if ((unsigned short)(*(unsigned short *)state - 46) < 4) {
            start = *(float *)(state + 8);
            func_L00_00416A38(object + 0x10, 60, 0,
                start + (*(float *)(state + 0xC) - start) * ((float)(*(short *)state - 45) * 0.1f),
                0.5f, 0.0f, 0.0f, 0.0f);
        }
    }
}
