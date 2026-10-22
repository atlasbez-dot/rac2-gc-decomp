/* Near miss: the body matches the retail bytes, the prologue does not.
 *
 * func_L01_002B3458 (272 bytes, level 01 at 0x002B3458; also 04:002D8E88,
 * 07:002B17C0, 08:002C4050, 09:002B53F0, 16:002B2F20).
 *
 * tools/check.py func_L01_002B3458 --diff:
 *   01_oozla: instruction at +0x4 differs
 *   The body from 0x002B3498 on is byte-identical to the retail; the fifteen
 *   prologue instructions are the same set in a different order.
 *
 * The retail prologue keeps the high half of D_L01_00189E20 in $s0 (a
 * callee-saved register), copies it to $s4 and re-forms the address from $s4
 * after the calls:
 *
 *     lui    $s0, 0x19
 *     ...
 *     jal    func_2B0288
 *     daddu  $s4, $s0, $zero
 *     addiu  $s0, $s0, -0x61E0
 *     ...
 *     addiu  $s0, $s4, -0x61E0
 *
 * This draft keeps the high half in a temporary ($v1) and the address in $s0,
 * so the re-form is missing and the saves and the call land elsewhere.  The
 * re-assignment of p below is what makes cc1 rematerialize the address at all
 * (without it there is no $s4 at all); what is still missing is the order that
 * lets cc1 keep the high half in the address's own register.
 */

#include "include_asm.h"

extern char D_L01_00189E20[];

extern void func_L00_002AF7D0(int a0);

extern void func_L00_002B1F90(void);

extern int func_L00_00322EC8(char *a0);

extern void func_L00_002D2E68(void);

extern void func_L00_002A6708(void);

extern void func_L00_002A53B8(void);

extern void func_L00_002D24B8(void);

extern void func_002A677C(int a0);

extern void func_L01_002BEB90(int a0, int a1);

void func_L01_002B3458(int a0, int a1, int a2) {
    char *p;
    int *v;
    float f1;
    float f0;

    p = D_L01_00189E20;
    func_L00_002AF7D0(a0);
    p[0x22B6] = 1;
    func_L00_002B1F90();
    *(int *)(p + 0x2290) = *(int *)(p + 0xC18);
    func_L00_00322EC8(p + 0x18E0);
    func_L00_00322EC8(p + 0x1A30);
    v = *(int *)(p + 0x2290);
    *(int *)((char *)v + 0x9C) = -1;
    if (a0 != 4 || *(unsigned char *)(p + 0x22B4) != a0)
        func_L00_002D2E68();
    func_L00_002A6708();
    func_L00_002A53B8();
    p = D_L01_00189E20;
    p[0x22B4] = a0;
    *(int *)(p + 0x2290) = a2;
    *(int *)(p + 0xC14) = a2;
    func_L01_002B3D28();
    f0 = *(float *)(p + 0x258);
    f1 = *(float *)(p + 0x25C);
    *(float *)(p + 0x250) = f0;
    *(float *)(p + 0x254) = f1;
    v = *(int *)(p + 0x2290);
    *(unsigned short *)((char *)v + 0x34) |= 6;
    *(float *)(p + 0xC24) = 1.0f;
    *(float *)(p + 0xC20) = 1.0f;
    func_L00_002D24B8();
    func_002A677C(*(int *)(p + 0x2290));
    *(unsigned short *)(p + 0x24F2) = a1;
    func_L01_002BEB90(a1, 2);
}
