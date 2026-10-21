/* func_L00_003E9490 - NOT MATCHED, best attempt - 172 bytes expected, 27 places.
 * last check.py line: "func_L00_003E9490: 0 of 27 places match (src/levels/shared/L00_003E3258.c)"
 * with "00_aranos_tutorial: 164 bytes, expected 172".
 *
 * The two 128-bit copies and the three calls of the blended path match; what is
 * left is one instruction in each of the two copy paths:
 *
 *   retail: lq $v0, 0($s0) ; sq $v0, 0($s1) ; b +0x17 ; ld $s0, 0x10($sp)
 *   ours:   lq $v0, 0($s0) ; b +0x16          ; sq $v0, 0($s1)
 *
 * retail keeps the store out of the branch's delay slot and copies the epilogue's
 * first instruction (ld $s0) into it instead; this compiler moves the last
 * instruction of the copy block (the sq) into the delay slot, so the path is one
 * instruction shorter. Measured: the same for every spelling of the two copies
 * (TI128* parameters, a local of type TI128, the else-if and the nested else, a
 * copy through one variable stored once at the end) - a delay-slot choice, not a
 * source shape.
 */

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    float x;
    float y;
    float z;
    float w;
} Vec16_Fc936841d;

extern void func_00282CF0_9(char *local, char *first, char *second);
extern void func_00282D30_3(char *a, char *b, float value);
extern void func_00282CC0_15(char *target, char *first, char *local);

void func_L00_003E9490(float t, Vec16_Fc936841d *dst, Vec16_Fc936841d *src, Vec16_Fc936841d *other)
{
    Vec16_Fc936841d local;

    if (t == 0.0f) {
        *(TI128 *)dst = *(TI128 *)src;
    } else if (t == 1.0f) {
        *(TI128 *)dst = *(TI128 *)other;
    } else {
        func_00282CF0_9((char *)&local, (char *)&local, (char *)src);
        func_00282D30_3((char *)&local, (char *)&local, t);
        func_00282CC0_15((char *)dst, (char *)src, (char *)&local);
    }
}
