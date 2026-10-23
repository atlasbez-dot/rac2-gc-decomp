/* Retained plain-C near miss; measured 23 October 2026, USA v1.01.
 * Profile: -O2 -G0 -ffunction-sections -fno-strength-reduce -fno-gcse.
 * 360/360 bytes, 0/27 placements. First instruction mismatch +0x8: base/owner/count
 * register allocation and save order. Disabling strength reduction restores the
 * increasing counter, without fixing allocation. Corrects helper identity, two
 * constants and removes fictitious stores. Reopen with original table/record
 * lifetimes.
 */
#include "include_asm.h"
extern char D_L00_0025A920[];
extern void func_L00_00417868(char *, char *);
extern float func_002A7878(float, float);
extern void func_00281EB8(char *, int, int, int, float, float, float);

void func_L00_00417700(char *owner)
{
    char *base = D_L00_0025A920;
    char *entry;
    int i;
    float value;
    entry = base + 0x30;
    for (i = 0; i < 24; i++, entry += 0xB0, base += 0xB0) {
        if (*(char **)(entry + 0x6C) == owner) {
            func_L00_00417868(owner, base);
            if (*(int *)(entry + 0x70) == 0) {
                value = func_002A7878(0.125f, 0.25f) * 5.0f;
                func_00281EB8(entry, 0x31, 0x3F7F0000, 1, value, 1.25f, 0.0f);
                value = func_002A7878(0.0625f, 0.125f) * 5.0f;
                func_00281EB8(entry, 0x31, 0x5F7F7F7F, 1, value, 1.24f, 0.0f);
                value = func_002A7878(0.15f, 0.35f) * 5.0f;
                func_00281EB8(entry, 0x0B, 0x103F0000, 1, value, 1.23f, 0.0f);
            }
        }
    }
}
