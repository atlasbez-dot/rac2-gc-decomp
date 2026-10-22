/* Draft: the state machine's shape is mapped, the body does not match yet.
 *
 * func_L06_0041FAF8 (level 06, 348 bytes).  The draft is 372 bytes, six instructions over
 * retail, and lays the blocks out in a different order: retail keeps the object in $s0 and
 * its state pointer in $s1, and the draft needs one more live value.
 *
 * What retail does, and what a matching body has to reproduce:
 *   - the test `o->0x5A0 != 1` is a branch-likely (bnel) whose annulled delay slot holds
 *     the `lh $v0,0x492(o)` of the taken path;
 *   - `o->0x23C != -1` jumps to the `func_35A550(a0,8,2)` block;
 *   - the `o->0x5A0 == 0` path and the path where `func_32D238(o+0x25C)` returns 0 share
 *     one block; the latter first tests `o->0x492` and leaves the function with $s0
 *     unrestored when it is not 0;
 *   - `func_35A270` is called with 0x12 in the default case, 0x13 after the
 *     `o->0x23C == -1` path and 0x11 after `func_35A620(2) != 0`, and it is skipped for
 *     the states 0x11, 0x12 and 0x13;
 *   - the tail is `o->0x48 = func_32E728(20.0f); o->0x4A = func_32E728(24.0f);`
 *     (0x41A00000 and 0x41C00000).
 */

#include "include_asm.h"

extern int func_32D238(char *);
extern void func_35A550(char *, int, int);
extern int func_35A620(int);
extern void func_35A270(char *, int, int, int);
extern int func_32E728(float);

void func_L06_0041FAF8(char *a0)
{
    char *o = *(char **)(a0 + 0x68);
    int mode = 0x12;
    int state;

    if (*(int *)(o + 0x5A0) != 1) {
        if (*(int *)(o + 0x5A0) == 0) {
            goto shared;
        }
        if (func_32D238(o + 0x25C) == 0) {
            if (*(short *)(o + 0x492) != 0) {
                return;
            }
            goto shared;
        }
        *(short *)(o + 0x492) = 0;
        func_35A550(a0, 7, 2);
        if (func_35A620(2) != 0) {
            mode = 0x11;
            goto call;
        }
        state = a0[0x43];
        if (state == 0x11) {
            goto c1;
        }
        goto b7;
    }
    if (*(int *)(o + 0x23C) != -1) {
        goto b7;
    }
    if (func_32D238(o + 0x25C) == 0) {
        return;
    }
    func_35A550(a0, 7, 2);
    state = a0[0x43];
    if (state == 0x13) {
        goto c1;
    }
    mode = 0x13;
    goto call;
shared:
    if (func_32D238(o + 0x25C) == 0) {
        return;
    }
    func_35A550(a0, 9, 2);
b7:
    func_35A550(a0, 8, 2);
    state = a0[0x43];
    if (state == 0x12) {
        goto c1;
    }
call:
    func_35A270(a0, mode, 0, 0x14);
c1:
    o[0x48] = (char)func_32E728(20.0f);
    o[0x4A] = (char)func_32E728(24.0f);
}
