/* Draft: the switch is recovered, the body does not match yet.
 *
 * func_L06_00457100 (level 06, 368 bytes).  The draft is 364 bytes and the shape of retail's
 * three-way switch (the branch-likely chain on `a0[0x20]`, the shared block of the
 * `a0[0x20] == 1` case, the `func_363718`/`func_35CBA0` body of the state 1 and the vector
 * tail of the state 2) is in place.  What is left:
 *
 *   - retail materialises the quadword zero in a register (`por $v0,$zero,$zero` then
 *     `sq $v0,0($sp)`) where this cc1 folds it into the store (`sq $zero,0($sp)`); that
 *     is what the `-frac2-zero-ti-barrier` profile keeps, so a matching unit would need it;
 *   - retail reads a word through a constant base (`addiu $v0,$zero,0xFF` then
 *     `lw $v0,0x20($v0)`, the address 0x11F) where this cc1 folds the constant address
 *     into the displacement (`lw $v0,0x11F($zero)`); the base has to stay in a register,
 *     and no C spelling of a constant base was found that does it;
 *   - the default case's store is duplicated by this cc1 instead of sitting in the
 *     delay slot of the branch-likely state-0 test, and the frame keeps one register
 *     less than retail's.
 *
 * The float constants are retail's bits: 0x3998825C (0.0002908882452175021f), 0x3E2AAAAB
 * (0.16666667f, the annulled store) and 0xBE2AAAAB (-0.16666667f).
 */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_35A550(char *, int, int);
extern int func_35CBA0(char *, int, int);
extern void func_363718(char *, float, float, float);
extern void func_002B0A68(char *, int, char *, float, float, float, float, int);
extern int func_3A0948(int, int, char *);
extern void func_350388(char *);

void func_L06_00457100(unsigned char *a0)
{
    char *o = *(char **)(a0 + 0x68);
    float vec[4];

    switch (a0[0x20]) {
    default:
        *(int *)(o + 4) = 0;
        break;
    case 0:
        func_35A550((char *)a0, 1, -1);
        break;
    case 1:
        func_363718((char *)a0, 0.0f, 0.0f, -(*(float *)o * 0.0002908882452175021f));
        if (func_35CBA0((char *)a0, 0x4010000, 0) != 0) {
            int *m = *(int *)((char *)0xFF + 0x20);

            if (m != 0) {
                if (*(short *)((char *)m + 0xAA) == 0x12C4) {
                    func_35A550((char *)a0, 2, -1);
                } else {
                    *(int *)(o + 4) = a0[0x20];
                }
            }
        }
        a0[0xA8] = 0xFF;
        func_350388((char *)a0);
        break;
    case 2:
        *(TI128 *)vec = 0;
        if (*(int *)(o + 4) != 0) {
            *(float *)vec = -0.16666667f;
        }
        func_002B0A68((char *)a0, 0x1FE, (char *)vec, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF);
        func_3A0948(0, 0, (char *)a0);
        func_350388((char *)a0);
        break;
    }
}
