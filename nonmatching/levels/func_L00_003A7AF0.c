/* Retained plain-C near miss; measured 23 October 2026, USA v1.01.
 * Profile: -O2 -G8 -ffunction-sections.
 * 336/320 bytes, 0/27 placements. Meaningful initialization and table fill replace a
 * comment-only screen. The conditional data load becomes movz, a grouped config base
 * occupies another saved register, and short-result/loop scheduling differ. Mixed
 * absolute/GP accesses need further real layout evidence.
 */
#include "include_asm.h"
typedef struct { float a, b, c; } Config;
extern Config D_L00_001B2868[];
extern float D_L00_001B286C __attribute__((sda));
extern int D_L00_001AF6C4 __attribute__((sda));
extern int D_L00_001AF6CC __attribute__((sda));
extern int func_L00_00329E90(char *, int, void *);
extern char *func_L00_0032A088(int, int);
extern int func_L00_00329FF0(int);

void func_L00_003A7AF0(char *object)
{
    char *state = *(char **)(object + 0x68);
    int local[4];
    int value, i;
    short index;
    int *table;
    *(short *)(state + 4) = -1;
    *(float *)(state + 12) = 0.1f;
    *(int *)(state + 60) = -1;
    *(int *)(state + 0) = 0;
    *(short *)(state + 6) = 0;
    *(short *)(state + 16) = 0;
    *(int *)(state + 8) = 0;
    *(int *)(state + 36) = -1;
    *(int *)(state + 40) = 0;
    *(int *)(state + 44) = 0;
    *(int *)(state + 48) = 0;
    value = D_L00_001AF6CC;
    if (*(short *)(object + 0xAA) == 1490)
        value = D_L00_001AF6C4;
    *(int *)(state + 52) = value;
    *(unsigned int *)(object + 0x78) = 0xFF0020FF;
    index = func_L00_00329E90(object, 0, local);
    *(short *)(state + 18) = index;
    if (local[0] == 0) {
        table = (int *)func_L00_0032A088(*(short *)(object + 0xAA), index);
        value = func_L00_00329FF0((int)(table + 16));
        for (i = 15; i >= 0; --i) {
            *table++ = value;
            value += 640;
        }
    }
    D_L00_001B2868[0].a = 0.104719766f;
    if (*(short *)(object + 0xAA) == 1490)
        D_L00_001B2868[0].b = 20.0f;
    else
        D_L00_001B286C = 30.0f;
    D_L00_001B2868[0].c = 0.104719766f;
}
