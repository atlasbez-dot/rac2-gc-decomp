#include "common.h"

/* Near miss: the candidate is 96 bytes against retail's 100 and the whole
 * shape is right (four nested tests, the stores of 1 and the return of 0),
 * but the register allocation and the schedule of the delay slots differ.
 *
 * Retail keeps the value 1 in `$a0` across the three blocks and computes the
 * address of the first store early, in the delay slot of the first branch
 * (`lui $v1,0x1F`), so that the store itself is a single instruction
 * (`sw $a0,0x2848($v1)`) that fits in the delay slot of the second branch.
 * This cc1 keeps the value in `$v1` (the register its own allocator picks),
 * materialises it again after each load that clobbers it, and leaves the
 * stores as `lui`+`sw` pairs, so one of them cannot be scheduled into a
 * delay slot - and the one that does goes `$gp`-relative, which retail does
 * not do.
 *
 * The addresses are per-program values (0x001A8CFC and 0x001A904C for the
 * first test in the boot and in level 00), so they are `ref_` symbols and
 * the small-data ones carry the `sda` attribute; the unit needs `-G8`.
 */

extern int ref_L00_002D08C8_01;

extern int ref_L00_002D08C8_02 __attribute__((sda));

extern int ref_L00_002D08C8_03;

extern int ref_L00_002D08C8_04;

extern int ref_L00_002D08C8_05 __attribute__((sda));

extern int ref_L00_002D08C8_06;

extern int ref_L00_002D08C8_07;

extern int ref_L00_002D08C8_08;

extern volatile unsigned char D_001A7A0A;

int func_002D08C8(void)
{
    int one = 1;

    if (ref_L00_002D08C8_01 != 0) {
        if (ref_L00_002D08C8_02 != 0) {
            ref_L00_002D08C8_03 = one;
            ref_L00_002D08C8_04 = one;
        }
        if (ref_L00_002D08C8_05 != 0)
            ref_L00_002D08C8_06 = one;
        if (D_001A7A0A != 0) {
            ref_L00_002D08C8_07 = one;
            ref_L00_002D08C8_08 = one;
        }
    }
    return 0;
}
