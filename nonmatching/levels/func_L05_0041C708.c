/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G0 -ffunction-sections -fno-strength-reduce.
 * 216/216 bytes; us: 0/4 placements; us2: 0/4 placements; pal: 0/4 placements.
 * The owner position and three complete matrix rows are copied; the factory consumes the integer
 * class argument and returns an object pointer. The rate remains in the FP bank. The prefix through
 * +0x70 and the tail agree, but matrix-loop allocation and store scheduling differ. Using the
 * helper in that loop adds one padding word; grouped TI has the same issue, while ordinary TI with
 * the measured counter profile removes that word.
 * Reopen with evidence that resolves the loop live ranges and store scheduling while retaining its
 * true seven-word instruction stream; do not add fake dependencies or padding.
 * Prior complete variants and diagnostic dumps are preserved privately.
 * No candidate or linked-build credit is claimed.
 */
#include "common.h"


typedef int Rac2TI128 __attribute__((mode(TI)));

extern char *func_0029EFD0(int kind);

extern void func_002A0F48(char *a0);

/* Arms the rung the factory returns: stamps the five flag bytes, binds the owner and the handle,
 * copies the owner's position and three matrix rows into the rung, folds the rate, then starts it. */
char *func_L05_0041C708(char *a0, char *a1, int kind, f32 f12)
{
    char *s0 = func_0029EFD0(kind);
    char *sub;
    char *src;
    char *dst;
    int i;

    if (s0 != 0) {
        sub = *(char **)(s0 + 0x68);
        *(u8 *)(s0 + 0x30) = 0xFF;
        *(u16 *)(s0 + 0x32) = 0xFF;
        *(u8 *)(s0 + 0x31) = 1;
        *(u16 *)(s0 + 0x34) |= 0x100;
        *(u8 *)(s0 + 0x20) = 0;
        *(char **)sub = a0;
        qcopy(s0 + 0x10, a0 + 0x10);
        src = a0 + 0xC0;
        dst = s0 + 0xC0;
        i = 0;
        do {
            *(Rac2TI128 *)dst = *(Rac2TI128 *)src;
            ++i;
            src += 16;
            dst += 16;
        } while (i < 3);
        *(f32 *)(s0 + 0x2C) = *(f32 *)(*(char **)(s0 + 0x24) + 0x24) * f12;
        *(char **)(sub + 4) = a1;
        func_002A0F48(s0);
    }
    return s0;
}
