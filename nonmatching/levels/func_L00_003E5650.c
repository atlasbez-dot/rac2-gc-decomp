/* func_L00_003E5650 - NOT MATCHED, best attempt - 188 bytes expected, 27 places.
 * last check.py line: "func_L00_003E5650: 0 of 27 places match (src/levels/shared/L00_003E3258.c)"
 * with "00_aranos_tutorial: 184 bytes, expected 188".
 *
 * The body is 184 of 188 bytes: the guard, the call sequence, the local vector, the
 * store of 2.0f into its w and the whole update chain match. What is left is the
 * 128-bit copy and the branch that carries it:
 *
 *   retail: bnez $v0 ; addiu $v1, $s0, 0x10 ; lq $v0, 0($v1) ; sq $v0, 0($sp)
 *   ours:   bnel $v0, $zero ; lq $v0, 0x10($s0) ; sq $v0, 0($sp)
 *
 * this cc1 folds the constant offset of a 128-bit load into the lq
 * (lq $v0, 0x10($s0)); retail materialises the pointer first (addiu $v1, $s0, 0x10)
 * and loads through it (lq $v0, 0($v1)). Measured: the same folding for every
 * spelling of the copy - a direct cast, a char* variable, a TI128* variable, a
 * second variable holding the pointer, a local of type TI128, the offset as a
 * variable - so the folded lq is a property of the compiler, not of the source.
 * The branch is branch-likely here (bnel) because the lq can fill the delay slot
 * from the taken path; retail's delay slot holds the address computation instead.
 *
 * The earlier deposit of this body used the inline-assembly qcopy of include/common.h
 * and matched byte for byte; that is not a route under AGENTS.md's "Plain C" rule.
 */

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    float x;
    float y;
    float z;
    float w;
} Vec16_Fc936841d;

extern int func_002B4038(short id, int mode);
extern int func_00283DB8(Vec16_Fc936841d *v, float scale);
extern void func_L00_003E5330(void);
extern void func_0029F338(char *object);
extern void func_L00_003E5710(char *object);
extern void func_L00_003E5978(char *object);
extern void func_L00_003E55B0(char *object);
extern void func_L00_003E5BD8(char *object);
extern void func_L00_003E6030(char *object);
extern void func_L00_003E6710(char *object);

void func_L00_003E5650(char *object)
{
    char *data;
    Vec16_Fc936841d local;
    int result;

    data = *(char **)(object + 0x68);
    if (func_002B4038(*(short *)(object + 0xAA), *(int *)(data + 0x28)) == 0) {
        func_L00_003E5330();
        func_0029F338(object);
        return;
    }
    *(TI128 *)&local = *(TI128 *)(object + 0x10);
    local.w = 2.0f;
    result = func_00283DB8(&local, 100.0f);
    if (result != -1) {
        if (*(unsigned char *)(object + 0x20) != 6) {
            func_L00_003E5710(object);
            func_L00_003E5978(object);
            func_L00_003E55B0(object);
        }
        func_L00_003E5BD8(object);
        func_L00_003E6030(object);
        func_L00_003E6710(object);
    }
}
