/* Near miss for func_L09_003F9568 (shared, 2 places: 09_dobbo, 20_yeedil), 412 bytes.
 *
 * Measured with tools/check.py func_L09_003F9568 --diff; the body below is 412 bytes in
 * size and every branch, call and float constant is retail's, but the three 128-bit
 * copies come out with their offsets folded into the lq/sq where retail materialises the
 * pointer first:
 *
 *   retail  addiu $v1, $s1, 0x10 ; lq $v0, 0($v1) ; sq $v0, 0($sp)
 *   this    lq $v0, 0x10($s1)                        ; sq $v0, 0($sp)
 *   retail  addiu $a1, $sp, 0x10 ; addiu $v1, $v1, 0x10 ; lq $v0, 0($v1) ; sq $v0, 0($a1)
 *   this    lq $v0, 0x10($v1)                        ; sq $v0, 0x10($sp)
 *   retail  addiu $a0, $sp, 0x20 ; addiu $s0, $v1, -0x1A0 ; lq $v0, 0($s0) ; sq $v0, 0($a0)
 *   this    lq $v0, 0($s0)                           ; sq $v0, 0x20($sp)
 *
 * Ten spellings were measured on the source of the offsets (a plain member access, an
 * explicit (char *) cast, a pointer variable, a TI128* variable, a pointer arithmetic in
 * TI units, a variable offset, the pointer used twice, a global destination) with both
 * compilers (build/compiler/tools and build/compiler/sdk): every one folds the constant
 * into the lq/sq.  Only a *global* destination keeps the materialised form
 * (lui/addiu then lq 0(reg)); the stack locals do not.
 *
 * Two other measured points, kept here because they cost the most to find:
 *   - the float constants are 1.76f (0x3FE147AE) and 1.18f (0x3F970A3D); the third
 *     component of the first quad is the one the function changes, not the second;
 *   - the block that adds them is retail's
 *         beqz $a3, L_else ; lwc1 $f0, 8($sp) ; lui $at, 0x3F80 ; mtc1 $at, $f1
 *         b L_tail ; add.s $f0, $f0, $f1
 *     L_else: lui $at, 0x3FE1 ; ori $at, $at, 0x47AE ; mtc1 $at, $f1 ; nop
 *     L_tail: add.s $f0, $f0, $f1 ; swc1 $f0, 8($sp)
 *     which is the C
 *         if (a3 != 0) { v1.z += 1.0f; v1.z += 1.0f; } else { v1.z += 1.76f; }
 *     - one add of 1.0f in the "then" branch and one at the shared tail, so the "then"
 *     path adds 1.0f twice.  A single add per branch compiles to a different shape (the
 *     branch then targets the store, not the tail).
 */

typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef int TI128 __attribute__((mode(TI)));

typedef struct __attribute__((aligned(16))) {
    f32 x, y, z, w;
} DobboVec4;

typedef struct {
    u8 field00[0x1f0];
    f32 field1F0[4];
    void *field200;
    u8 field204[0xb0];
    u8 field2B4[0x28];
    s32 field2DC;
    f32 field2E0;
    u8 field2E4[4];
    f32 field2E8;
    u8 field2EC[0x20];
    u8 field30C;
    u8 field30D;
    u8 field30E;
    u8 field30F;
} NativeAngleState __attribute__((aligned(16)));

typedef struct {
    u8 field00[0x10];
    f32 field10[4];
    u8 field20[0x48];
    NativeAngleState *field68;
} NativeAngleOwner __attribute__((aligned(16)));

extern int func_002761F8(void *a, void *b, int c, void *d, int e, float f);

extern int func_00277258(void *a, int b, void *c, float d);

/* the table of 4-byte entries at 0x1FE6C0 (level 09) / another address (level 20) */
extern void *ref_L09_003F9568_00[64];

/* the 16-byte global at 0x1BFE60 (level 09) / another address (level 20) */
extern TI128 ref_L09_003F9568_01;

int func_L09_003F9568(NativeAngleOwner *owner, void *a1, int a2, int a3)
{
    NativeAngleState *state = owner->field68;
    DobboVec4 v1, v2, v3;
    int result;

    if (state->field30F != 0)
        return 1;

    *(TI128 *)&v1 = *(TI128 *)&owner->field10;

    if (a2 != 0) {
        s32 idx = state->field2DC;
        if (idx != -1) {
            short sub = *(short *)((u8 *)state + 0x1CA);
            if (sub != -1) {
                u8 *p = (u8 *)ref_L09_003F9568_00[idx] + sub * 16 + 0x10;
                *(TI128 *)&v1 = *(TI128 *)p;
            }
        }
    }

    if (a3 != 0) {
        v1.z += 1.0f;
        v1.z += 1.0f;
    } else {
        v1.z += 1.76f;
    }

    *(TI128 *)&v2 = *(TI128 *)((u8 *)state->field200 + 0x10);
    v2.z += 1.18f;

    result = 0;
    if (func_002761F8(&v1, &v2, 0, owner, 0, v2.z) == 0 ||
        state->field200 == *(void **)((u8 *)&ref_L09_003F9568_01 - 8))
        result = 1;

    if (a1 == 0 || result != 0)
        return result;

    *(TI128 *)&v3 = *(TI128 *)&ref_L09_003F9568_01;

    if (func_00277258(&v3, 1, owner, 0.5f)) {
        void *q = *(void **)((u8 *)&ref_L09_003F9568_01 - 8);
        if (q != 0) {
            q = *(void **)((u8 *)q + 0x24);
            if (q != 0 && *(short *)((u8 *)q + 0x46) == 5)
                return result;
        }
        result = 1;
    }
    return result;
}
