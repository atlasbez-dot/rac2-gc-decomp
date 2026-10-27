/* func_L11_003CF250: near miss, 444 B vs 448. Everything matches (hero pointer re-read for the else-if, call sequence, clamp) except that retail fills the beql delay slot after the 0x340 test with the else-if address (annulled) and loads the D_001A7B00 flag into $v0, where this build puts the flag in $v1 and fills the slot with the lui. The helpers func_002B0CE0 and func_L11_002D8EF8 return int (status). -mno-split-addresses gives retail's annulled beql delay slot and one-register flag load but loses the shared high half of the hero address. Needs func_00283CF0 declared int (the unit declares it void: here an alias). */
#include "common.h"

extern char D_00189E20[];
extern unsigned char D_001A7B00[];
extern int func_00283CF0_1(float);
extern float func_00283198(float);
extern void func_002A7750(char *, int, int);
extern int func_002B3868(char *);
extern void func_L00_00429020(int);
extern int func_002B0CE0(int, int, int);
extern int func_L11_002D8EF8(int, int);
extern float func_00283B98(float, float);
extern float func_00283198(float);

/* Opens its trigger and waits: while the hero stands in it, shows the hint, then pulses the glow colour. */
void func_L11_003CF250(char *obj)
{
    char *rig = *(char **)(obj + 0x68);
    char *hero, *other;
    int word, level, color;
    float turn, pulse;

    switch (*(unsigned char *)(obj + 0x20)) {
    case 0:
        *(unsigned short *)(obj + 0x34) |= 0x10;
        func_002A7750(obj, 1, -1);
        break;
    case 1:
        if (func_002B3868(obj) != 0) {
            word = *(int *)rig;
            if (word != -1) {
                func_L00_00429020(word);
                *(int *)rig = -1;
            }
        }
        hero = D_00189E20;
        if (*(char **)(hero + 0x33C) == obj && *(int *)(hero + 0x340) != 0) {
            if (D_001A7B00[0] != 0) {
                func_002B0CE0(0xC, 0x27F7, 1);
                *(short *)(hero + 0x1F2) = 0xA;
                turn = *(float *)(rig + 0xC);
                if (turn != 0.0f)
                    *(float *)(hero + 0x5B8) = turn;
            }
        } else if (*(int *)((other = D_00189E20) + 0x2294) == 0x82) {
            level = *(int *)(rig + 8);
            if (level >= 0 && func_002ACBC8(other + 0x80, level) != 0)
                func_L11_002D8EF8(6, 1);
        }
        break;
    }
    if (*(unsigned char *)(obj + 0x31) != 0) {
        pulse = func_00283B98(*(float *)(rig + 4), 0.10471977f);
        *(float *)(rig + 4) = pulse;
        level = func_00283CF0_1(func_00283198(pulse) * 128.0f);
        if (level > 0x80)
            level = 0x80;
        else if (level < 0x20)
            level = 0x20;
        if (D_001A7B00[0] != 0)
            color = (level << 8) | 0x80000000;
        else
            color = level | 0x80000000;
        *(int *)(obj + 0x78) = color;
    }
}
