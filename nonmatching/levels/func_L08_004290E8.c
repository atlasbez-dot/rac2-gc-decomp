/* func_L08_004290E8 (336 bytes, 1 place) - best attempt, NOT MATCHED.
 *
 * `python3 tools/check.py func_L08_004290E8 --diff`: the candidate is 332 bytes and the
 * whole three-slot body is retail's - the clear loop with its countdown, the
 * `bgezl` delay-slot index bump, the `beqz`/`beql` guards, the two calls with the
 * index in $a0/$a1 and the `s5` counter bumped in the call's delay slot.  What is
 * left is the first test and the register allocation:
 *
 *  - retail branches `beqz $v1,0x42912C` (a plain, not-likely branch to the clear
 *    arm) and keeps the second test as the fall-through; an if/else chain gives
 *    `bnel $v1,$zero` with the clear arm inline, and a `switch` gives the retail
 *    layout but a `beql`.  The clear arm's position and the likely bit move
 *    together: this cc1 lays the arms out by predicted probability, and the two
 *    spellings disagree on which arm it thinks is likely.
 *
 *  - retail's callee-saved order is $s0 = the constant 4, $s1 = &0x1B39A0,
 *    $s2 = &0x1B3A30, $s3 = the index, $s4 = a0, $s5 = the counter; this cc1 gives
 *    $s0 = the index, $s1 = the constant 4, $s2 = &0x1B39A0, $s3 = &0x1B3A30,
 *    $s4 = the counter, $s5 = a0.  The order is the allocator's
 *    (references / live length) ranking, so the same two groups of values are
 *    ranked the other way round here.
 *
 * Measured, no effect: the clear loop's two stores in either order, an explicit
 * `s32 *pa`/`s32 *pd` pair, and reading the state byte twice instead of through a
 * local.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef float f32;

extern s32 D_L08_001B39A0[];
extern s32 D_L08_001B3A30[];
extern void func_L08_00429408(s32 a0);
extern void func_L08_00429560(s32 a0, s32 a1);
extern void func_L08_002F2D10(void (*fn)(void *), void *arg);
extern void func_L08_00429EE8(void *);

/* The spawner's three slots: the first byte of the record says whether the slot is
   empty (0), in use (1) or a finished one (4); a slot whose record is gone is freed. */
void func_L08_004290E8(char *a0) {
    s32 i;
    s32 k;
    s32 count;
    s32 v;

    if (*(u8 *)(a0 + 0x20) != 0) {
        if (*(u8 *)(a0 + 0x20) == 1) {
            count = 0;
            for (i = 0; i < 3; i++) {
                v = D_L08_001B39A0[i];
                if (v == 1) {
                    if (*(signed char *)(D_L08_001B3A30[i] + 0x20) < 0) {
                        D_L08_001B39A0[i] = 0;
                        D_L08_001B3A30[i] = 0;
                    }
                } else if (v == 4) {
                    func_L08_00429408(i);
                } else if (v != 0) {
                    func_L08_00429560(D_L08_001B3A30[i], i);
                    count++;
                    D_L08_001B39A0[i] = 4;
                }
            }
            if (count != 0) {
                func_L08_002F2D10(func_L08_00429EE8, a0);
            }
        }
        return;
    }
    for (k = 0; k < 3; k++) {
        D_L08_001B39A0[k] = 0;
        D_L08_001B3A30[k] = 0;
    }
    *(u8 *)(a0 + 0x30) = 0xFF;
    *(u8 *)(a0 + 0x20) = 1;
}
