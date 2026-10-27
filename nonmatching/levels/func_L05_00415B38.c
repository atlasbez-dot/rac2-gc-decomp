/* Opus big44, 26 October 2026. Profile: -O2 -G8 -ffunction-sections.
 * 142/142 instructions; 139 identical. Only difference: after the r+0x11C store retail
 * loads the table pointer D_L05_001B251C (lui/lw macro in one register) before reloading
 * state+0x260; this cc1 reloads state+0x260 first (3 words, order only). Queued for the permuter.
 * Fixed against the older draft: callee names are catalogue names; the float copies to
 * the two new children sit inside the create branch; r+0x11C receives 1 (retail stores
 * the $a0 that holds r+0x110, known equal to 1), not state+0x274; func_00282948 returns int.
 */

#include "common.h"

extern char D_00188660[];
extern char D_L05_002659E0[];
extern char *D_L05_001B251C;

extern int func_L00_00367720(char *object);
extern char *func_002ED688(char *object);
extern void func_L05_00379E60(char *object, char *a1, int a2, int a3);
extern void func_L05_0037C160(char *object);
extern void func_L05_0037B538(char *object, int a1, int a2, int a3);
extern void func_L05_0037B948(char *object, int a1, float a2);
extern int func_L05_0037B888(char *object);
extern void func_L05_0037B6D0(char *object);
extern int func_002E5DA0(int a0, int a1, char *object, int a3);
extern void func_00282C88(char *block);
extern int func_00282948(char *block);
extern void func_L00_002E6EF8(void *fn, char *object);
extern void func_L05_00415DA8(char *object);
extern void func_L05_00415F18(char *object);
extern void func_L05_00415FD0(char *object);
extern void func_L05_004161B0(char *object);
extern char *func_L05_00416D68(char *a0, int a1);
extern void func_L05_00415D70(void);
extern void func_L00_003BAAD0(void);

void func_L05_00415B38(char *object)
{
    char *state = *(char **)(object + 0x68);
    char *r;
    char *rec;
    char *table;
    char buf[0x10];
    int st;

    if (*(unsigned char *)(object + 0x20) == 0) {
        *(unsigned char *)(object + 0x30) = 0xFF;
        if (func_L00_00367720(object) == 0)
            return;
        func_L05_00415DA8(object);
        func_00282C88(buf);
        if (*(int *)(state + 0x264) != 0) {
            char *base;
            int *p;
            int i;

            func_L05_00379E60(object, (char *)func_L05_00415D70, 0, 0);
            base = D_L05_002659E0;
            p = (int *)(base + 0x27F0);
            i = 0x7F;
            do {
                *p = 0;
                p -= 0x14;
                i--;
            } while (i >= 0);
        }
        return;
    }
    r = func_002ED688(object);
    if (*(int *)(r + 0x110) == 0)
        return;
    if (*(int *)(state + 0x26C) == 0 && *(int *)(state + 0x270) == 0) {
        *(int *)(state + 0x26C) = (int)func_L05_00416D68(object, 0);
        *(int *)(state + 0x270) = (int)func_L05_00416D68(object, 1);
        *(float *)(*(int *)(state + 0x26C) + 0x2C) = *(float *)(object + 0x2C);
        *(float *)(*(int *)(state + 0x270) + 0x2C) = *(float *)(object + 0x2C);
    }
    {
    int one = 1;
    func_L05_0037C160(object);
    func_L05_0037B538(object, 0, 0, 0);
    func_L05_0037B948(object, one, 32.0f);
    st = *(int *)(r + 0x110);
    if (st == one) {
        if (*(int *)(state + 0x260) != -1) {
            *(int *)(r + 0x11C) = 1;
            *(int *)(r + 0x120) = (int)(D_L05_001B251C + *(int *)(state + 0x260) * 256);
        }
        if (*(int *)(r + 0x108) != 0 && *(int *)(r + 0x104) != 0)
            func_L05_00415F18(object);
        if (func_L05_0037B888(object) != 0)
            func_L05_0037B6D0(object);
        func_00282948(state + 0x268);
        func_L05_00415FD0(object);
    }
    }
    rec = D_00188660 + *(int *)(state + 0x274) * 0x70;
    if (*(char **)(rec + 0x88) != object || *(unsigned char *)(rec + 0x74) == 0)
        *(int *)(state + 0x274) = func_002E5DA0(1, 6, object, 0xF76);
    func_L05_004161B0(object);
    func_L00_002E6EF8(func_L00_003BAAD0, object);
}
