/* Near miss (mid-15): 472/472 bytes, flags -O2 -G0 -ffunction-sections -fno-strength-reduce. Equal except the slot address ((s1+0x10) first, then + i*4: retail `addiu v0,s1,0x10; sll s2,s6,2; addu s0,v0,s2`; here the constant folds into the shift) and the matching operand order of the two `addu` / increments that follow (about 8 words). Twin func_L04_0043BE40 covers the first block only. */
#include "include_asm.h"

extern void func_002833F0(char *a, char *b);
extern void func_00282D30(char *a, char *b, float f);
extern int func_00283D38(int from, int to, float fraction);
extern void func_002AEC18(void *a0, int a1);
extern void func_002AE838(char *dst, char *src);
extern void func_00283098(char *a, char *b, char *c);
extern void func_00282CC0(char *a, char *b, char *c);
extern void func_00283738(char *a, char *b, char *c);
extern void func_002A10E8(void *a);

void func_L02_003C9ED0(char *a0)
{
    char *s1 = *(char **)(a0 + 0x68);
    char vec_a[16] __attribute__((aligned(16)));
    char vec_b[16] __attribute__((aligned(16)));
    char **slot;
    char *src5 = s1 + 0x4C;
    char *src4 = s1 + 0x40;
    int i;

    *(unsigned short *)(*(char **)(s1 + 0x10) + 0x34) &= 0xFFFE;
    *(unsigned char *)(*(char **)(s1 + 0x10) + 0x31) = 1;
    *(int *)(*(char **)(s1 + 0x10) + 0x98) = *(int *)(*(int *)(*(char **)(s1 + 0x10) + 0x24) + 0x10);
    func_002833F0(*(char **)(s1 + 0x10) + 0xC0, *(char **)(s1 + 0x10) + 0xF0);
    func_00282D30(*(char **)(s1 + 0x10) + 0xC0, *(char **)(s1 + 0x10) + 0xC0, *(float *)(s1 + 0xC));
    func_00282D30(*(char **)(s1 + 0x10) + 0xD0, *(char **)(s1 + 0x10) + 0xD0, *(float *)(s1 + 0xC));
    func_002AEC18(*(char **)(s1 + 0x10), func_00283D38(0x80FF8000, *(int *)(s1 + 0x30), *(float *)(s1 + 0xC)));
    func_002A10E8(*(char **)(s1 + 0x10));
    for (i = 1; i < 4; i++, src5 += 4, src4 += 4) {
        slot = (char **)(s1 + 0x10 + i * 4);
        if (*slot != 0) {
            *(unsigned short *)(*slot + 0x34) &= 0xFFFE;
            *(unsigned char *)(*slot + 0x31) = 1;
            *(int *)(*slot + 0x98) = *(int *)(*(int *)(*slot + 0x24) + 0x10);
            func_002AE838(vec_a, src4);
            func_00283098(vec_a, vec_a, *(char **)(s1 + 0x10) + 0xC0);
            func_00282CC0(*slot + 0x10, *(char **)(s1 + 0x10) + 0x10, vec_a);
            func_002AE838(vec_b, src5);
            func_002833F0(*slot + 0xC0, vec_b);
            func_00283738(*slot + 0xC0, *(char **)(s1 + 0x10) + 0xC0, *slot + 0xC0);
            func_002AEC18(*slot, func_00283D38(0x80FF8000, *(int *)(s1 + i * 4 + 0x30), *(float *)(s1 + 0xC)));
            func_002A10E8(*slot);
        }
    }
}
