/* Retained plain-C near miss; measured 23 October 2026, USA v1.01.
 * Profile: -O2 -G8 -ffunction-sections.
 * 192/192 bytes, 0/27 placements. First instruction mismatch +0x1c: load order and
 * subtraction reassociation; prologue and remaining body agree. Reopen with
 * independent source expression evidence.
 */
#include "include_asm.h"

extern char *D_L00_001B144C __attribute__((sda));
extern int func_001163B0(void);
extern void func_L00_0041ACA0(char *object, void *entry);
extern void func_002BE278(void *entry, void *next, int zero, float scale);

void func_L00_0041A500(char *object)
{
    char *state = *(char **)(object + 0x68);
    int first = *(int *)(state + 0x48);
    int last = *(int *)(state + 0x44);
    int index;
    int random;
    index = first + 2 - last;
    if (index <= -1)
        index += 0x23;

    random = func_001163B0();
    if (random % 7 == 0)
        func_L00_0041ACA0(object, D_L00_001B144C + (index << 6));

    random = func_001163B0();
    if (random % 0x16 == 0) {
        char *entry = D_L00_001B144C + (index << 6);
        func_002BE278(entry, entry + 0x10, 0, -1.0f);
    }
}
