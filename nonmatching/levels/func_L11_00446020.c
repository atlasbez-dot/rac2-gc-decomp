/* mid-9 draft: structure, instruction count and every constant match (416 B). Remaining: $s1/$s2 are swapped (retail keeps the D_00189E20 base in $s1 and the target+0x68 pointer in $s2) and the table address is 'addu v1,s0,v1' in retail vs 'addu v1,v1,s0'. Declaration order, a named base local and index spelling did not change either. Needs the -G8 profile. */
#include "common.h"

extern int D_L11_00189E20[];
extern float D_L11_001B2880 __attribute__((sda));
extern int func_32CAB0(int);
extern int func_L11_00445D28(char *, int);

void func_L11_00446020(char *self) {
    int idx;
    char *s2;
    char *s0 = *(char **)(self + 0x68);
    char *target = *(char **)(s0 + 0x180);

    if (target != 0) {
        idx = -1;
        if (*(short *)(target + 0xAA) != 0xB3A) {
            if (*(short *)(target + 0xAA) == 0xD4A) {
                s2 = *(char **)(target + 0x68);
                if ((float)D_L11_00189E20[0x933] <= 0.0f) {
                    idx = func_32CAB0(3) + 0xC;
                    if (*(short *)(0x2A0 + s0 + idx * 2) != 0) {
                        idx = -1;
                    }
                }
                if (*(short *)(s0 + 0x2BE) == 0) {
                    if ((float)D_L11_00189E20[0x933] < D_L11_001B2880) {
                        idx = 0xF;
                    }
                }
                if (*(short *)(s0 + 0x2C0) == 0) {
                    if (*(float *)(s2 + 0x20) <= 0.0f) {
                        if (*(int *)(s0 + 0x140) == 0) {
                            idx = 0x10;
                        }
                    }
                }
            }
        } else {
            s2 = *(char **)(target + 0x68);
            if ((float)D_L11_00189E20[0x933] <= 0.0f) {
                idx = func_32CAB0(2) + 6;
                if (*(short *)(0x2A0 + s0 + idx * 2) != 0) {
                    idx = -1;
                }
            }
            if (*(short *)(s0 + 0x2B0) == 0) {
                if ((float)D_L11_00189E20[0x933] < D_L11_001B2880) {
                    idx = 8;
                }
            }
            if (*(short *)(s0 + 0x2B2) == 0) {
                if (*(float *)(s2 + 0x20) <= 0.0f) {
                    idx = 9;
                }
            }
        }
        if (idx > 0) {
            func_L11_00445D28(self, idx);
        }
    }
}
