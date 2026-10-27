/* func_L00_00426248: Opus closer M1 near miss, 26 October 2026.
   Profile: -O2 -G0 -ffunction-sections, own unit.
   248/248 bytes with func_00282DF0 returning float and the record count re-read each iteration; 49 differing. Left: retail keeps the two globals out of delay slots (two-instruction absolute macro form) and has a nop at the top of the j loop. */
#include "common.h"
typedef struct Rac2Native_428d1e2cc4aa1f21_Entry {
    unsigned char unknown_00[16];
    int type_10;
    int index_14;
    unsigned char unknown_18[24];
} Rac2Native_428d1e2cc4aa1f21_Entry;

extern char *D_L00_001B1880[] __attribute__((sda));
extern char *D_L00_001B1F94[] __attribute__((sda));
extern float func_00282DF0(void *);

void func_L00_00426248(void)
{
    int i, j, k;

    for (i = 0; i < 64; i++) {
        for (j = 0; j < 64; j++) {
            char *base = D_L00_001B1880[0];
            int off = ((int *)base)[i * 64 + j];
            char *hdr;

            if (off == 0) {
                continue;
            }
            hdr = off + base;
            for (k = 0; k < *(int *)hdr; k++) {
                Rac2Native_428d1e2cc4aa1f21_Entry *entry =
                    (Rac2Native_428d1e2cc4aa1f21_Entry *)(hdr + 16) + k;

                if (entry->type_10 == 5) {
                    func_00282DF0(D_L00_001B1F94[0] + (entry->index_14 << 7));
                }
            }
        }
    }
}
