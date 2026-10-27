/* func_0034E070: Opus closer M1 near miss, 26 October 2026.
   Profile: -O2 -G0 -ffunction-sections, own unit.
   D_001AE710 and D_001AE720 are passed by address (char arrays), the 7th call takes 0x80000000, the second colour is 60008.0f and the loop has no entry guard (do-while). Left: the record pointer and the 0x8710 constant should share $s0 (one saved register too many). */
#include "common.h"
extern int D_001A8CFC[] __attribute__((sda));
extern char D_001AE710[];
extern char D_001AE720[];

extern int func_00336D50(int, int);
extern void func_00336408(void *, int, int, void *, void *);
extern void func_00336CC8(void *, int);
extern void func_00336B90(void *, int);
extern void func_00336B98(void *, int);
extern void func_00336498(void *, int, int);
extern void func_003364B0(void *, int, int);
extern void func_00336CE0(void *, int);
extern void func_00336CC0(void *, int);
extern void func_0034B2C8(void *, int, int);
extern void func_00336710(void *, void *, void *);
extern int *func_00335E20(void *);
extern void *func_003367B8(void *);
extern void func_00337C10(void *, void *);

void func_0034E070(void *object, int a1, void *a2)
{
    char *base = (char *)object;
    char *record = base;
    void *colour;

    *(int *)(base + 0x220C) = func_00336D50(D_001A8CFC[0] + 0x8710, 0x57);
    *(int *)(base + 0x2210) = func_00336D50(D_001A8CFC[0] + 0x8710, 0x58);
    {
    char *end = base + 0x750;
    do {
        func_00336408(record, 0x20, 1, D_001AE710, a2);
        func_00336CC8(record, 5);
        func_00336B90(record, 0x64);
        func_00336B98(record, 0);
        func_00336498(record, 0x8049C1FF, 0x80001EFF);
        func_003364B0(record, 0x50F0C070, 0x50F0C070);
        func_00336CE0(record, 0x80000000);
        func_00336CC0(record, 1);
        record += 0x48;
    } while (record < end);
    }
    func_0034B2C8(base + 0x7A0, a1, a2);
    func_00336710(base + 0x1D30, D_001AE720, a2);
    func_00335E20(base + 0x1D30);
    colour = func_003367B8(base + 0x1D30);
    *(float *)colour = 2155905152.0f;
    colour = func_003367B8(base + 0x1D30);
    *(float *)colour = 60008.0f;
    *(int *)((char *)colour + 4) = 0;
    *(int *)(base + 0x798) = (int)a2;
    func_00337C10(base + 0x1D6C, a2);
    func_00337C10(base + 0x1FBC, a2);
}
