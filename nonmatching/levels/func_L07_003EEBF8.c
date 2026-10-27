/* Nonmatching: 216/232 bytes.
 * Profile: -O2 -G0 -ffunction-sections.
 * Final placement checks: US: 0/1; US2: 0/1; PAL: 0/1.
 * 216/232 bytes. Frame remains 0x50, but retail keeps the second local-vector address in an additional saved register across calls; current allocation materializes it at its final use. The initial load/save schedule and byte/halfword constant setup also differ.
 * Reopen with evidence for the second local vector address lifetime and actual allocator conflicts; the incoming quadword reads remain ordinary loads and outgoing copies use qcopy.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750(unsigned char *, int, int);

extern void func_00283098(TI128 *, TI128 *, TI128 *);

extern void func_00282CC0(TI128 *, TI128 *, TI128 *);

void func_L07_003EEBF8(char *arg, char *a1, TI128 *a2, TI128 *a3)
{
    TI128 v[2];
    char *s1;
    unsigned short w;

    v[0] = *a2;
    v[1] = *a3;

    w = *(unsigned short *)(arg + 0x34);
    *(unsigned short *)(arg + 0x34) = (w & 0xFFBE) | 0x1000;

    s1 = *(char **)(arg + 0x68);
    *(int *)(arg + 0x98) = *(int *)(*(int *)(arg + 0x24) + 0x10);
    func_002A7750((unsigned char *)arg, 2, -1);

    *(unsigned short *)(arg + 0x32) = 0xFF;
    *(unsigned char *)(arg + 0x30) = 0xFF;

    *(int *)(s1 + 0x110) = (int)a1;

    func_00283098((TI128 *)(arg + 0x10), &v[0], (TI128 *)(a1 + 0xC0));
    func_00282CC0((TI128 *)(arg + 0x10), (TI128 *)(arg + 0x10),
                  (TI128 *)(*(int *)(s1 + 0x110) + 0x10));

    w = *(unsigned short *)(arg + 0x34);
    *(unsigned short *)(arg + 0x34) = w & 0xEFFF;

    qcopy(s1 + 0xF0, arg + 0x10);
    qcopy(s1 + 0xD0, &v[1]);
}
