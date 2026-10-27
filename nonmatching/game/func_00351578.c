#include "include_asm.h"
typedef struct { unsigned long long first, second; int offset, count; } Transfer_3518F0;
extern int func_0011AC60(int);
extern int func_0011AC40(int);
static inline int ring_mod(int a, int b) { return a % b; }

int func_00351578(void *owner, Transfer_3518F0 *out)
{
    char *self = (char *)owner;
    unsigned int address = *(volatile unsigned int *)0x1000B410;
    unsigned int status = *(volatile unsigned int *)0x10002020;
    int fill = *(int *)(self + 0x38) & 0x7F;
    int unit = *(int *)(self + 0x8) << 11;
    int found = 0;
    int count;
    int head;
    int i;

    address -= (((status >> 16) & 3) + ((status >> 8) & 0xF)) << 4;
    func_0011AC60(*(int *)(self + 0x40));
    out->first = -1;
    out->second = -1;
    address = (address + (fill >> 3) + unit - *(int *)self) % (unsigned int)unit + unit;
    count = *(int *)(self + 0x58);
    head = *(int *)(self + 0x5C) - count;
    for (i = 0; i < count; i++) {
        int index = (head + *(int *)(self + 0x54) + i) % *(int *)(self + 0x54);
        Transfer_3518F0 *slot = *(Transfer_3518F0 **)(self + 0x50) + index;

        if (ring_mod(address - slot->offset, unit) < slot->count) {
            out->first = slot->first;
            found = 1;
            out->second = (*(Transfer_3518F0 **)(self + 0x50) + index)->second;
            (*(Transfer_3518F0 **)(self + 0x50) + index)->first = -1;
            (*(Transfer_3518F0 **)(self + 0x50) + index)->second = -1;
            *(int *)(self + 0x58) = *(int *)(self + 0x58) - ((*(int *)(self + 0x58) < 2) ? *(int *)(self + 0x58) : 1);
        }
        if (found) {
            break;
        }
    }
    func_0011AC40(*(int *)(self + 0x40));
    return 1;
}
