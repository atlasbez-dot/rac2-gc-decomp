/* func_002D08C8 (100 bytes, 28 places), closer M2: matches at all 28 places under
 *     src/game/002D08C8-g8.c	-O2 -G8 -ffunction-sections
 * but only with D_001A7A0A declared volatile (as src/game/002CD8C0-g8.c declares it):
 * retail leaves the delay slot of the third test a nop, and a plain byte load of the
 * flag is copied into that slot as a $gp load (plain, incomplete, MACRO_ADDR and sized
 * sda arrays all measured). Everything else is plain C: the 0x1F2848 store sits before
 * the inner tests (retail runs it in a non-likely delay slot), the four stores are one
 * sda int[4] (assembler macro form), and the two $gp words differ between the boot and
 * the levels, hence ref_ names. Land it if the lead accepts the volatile flag. */
#include "common.h"

extern int D_001A8CFC;
extern int ref_002D08C8_01 __attribute__((sda));
extern int D_001F2848[];
extern int D_001ABA0C[4] __attribute__((sda));
extern int ref_002D08C8_02 __attribute__((sda));
extern volatile unsigned char D_001A7A0A;

int func_002D08C8(void)
{
    if (D_001A8CFC != 0) {
        D_001F2848[0] = 1;
        if (ref_002D08C8_01 != 0)
            D_001ABA0C[1] = 1;
        if (ref_002D08C8_02 != 0)
            D_001ABA0C[2] = 1;
        if (D_001A7A0A != 0) {
            D_001ABA0C[0] = 1;
            D_001ABA0C[3] = 1;
        }
    }
    return 0;
}
