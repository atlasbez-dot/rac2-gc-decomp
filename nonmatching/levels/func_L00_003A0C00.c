/* Nonmatching: -O2 -G8 -ffunction-sections. us: func_L00_003A0C00: 0 of 18 places match (src/levels/shared/L00_003A0C00-g8.c); us2: func_L00_003A0C00: 0 of 18 places match (src/levels/shared/L00_003A0C00-g8.c); pal: absent. Two source trials: pointer for-loop 456/412 bytes, signed-address do-loop 452/412. Original 0x50 frame; object-search loop is peeled with extra field reads and register roles differ. Truthful helpers checked against current definitions. Reopen with actor search helper/source-shape hypothesis; no linked builds. */
#include "common.h"
typedef struct { int polygon; float lower, upper; int region; } TriggerRegion;
typedef struct { TriggerRegion region[20]; int timer; } TriggerState;
extern int D_0018C0B4;
extern char *D_L00_001B1EA8;
extern char *D_L00_001FDA80[];
extern int D_L00_001A8A44 __attribute__((sda));
extern int func_002A8AF0(float *, float *, int);
extern int func_002ACBC8(void *, int);
extern void func_L00_002E6EF8(void (*)(void *), void *);
extern void func_L00_003A09F8(void *);
extern void func_L00_00391310(char *, char *);
/* Advances the release timer only while the class-AC actor is outside all trigger regions. */
void func_L00_003A0C00(char *actor) {
    TriggerState *state = *(TriggerState **)(actor + 0x68);
    char *target = 0;
    TriggerRegion *region;
    char *cursor;
    *(unsigned char *)(actor + 0x30) = 0xFF;
    if (D_0018C0B4 == 28) {
        for (cursor = D_L00_001B1EA8; cursor; cursor = *(char **)(cursor + 0x28))
            if (*(short *)(cursor + 0xAA) == 0xAC) break;
        target = cursor;
        if (!target || *(short *)(target + 0xAA) != 0xAC) {
            state->timer = 0;
            return;
        }
        state->timer++;
        region = state->region;
        do {
            if (region->polygon != -1 && region->lower < *(float *)(target + 0x18) && *(float *)(target + 0x18) < region->upper) {
                char *polygon = D_L00_001FDA80[region->polygon];
                if (func_002A8AF0((float *)(target + 0x10), (float *)(polygon + 0x10), *(int *)polygon)) { state->timer = 0; break; }
            }
            if (func_002ACBC8(target + 0x10, region->region)) { state->timer = 0; break; }
            region++;
        } while ((int)region < (int)(state->region + 20));
    } else state->timer = 0;
    if (state->timer > 0) {
        if (D_L00_001A8A44) func_L00_002E6EF8(func_L00_003A09F8, actor);
        if (state->timer > 90) func_L00_00391310(target, *(char **)(target + 0x68));
    }
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_003A0C00 - 412 bytes, 18 place(s), level 00_aranos_tutorial,
   retail at 0x003a0c00. Screened with tools/w10_screen.py: 4 call(s)
   [func_002A8AF0@003A0D04, func_002ACBC8@003A0D18,
   func_L00_002E6EF8@003A0D4C, func_L00_00391310@003A0D68]; data addresses
   materialised [0x190000, 0x200000, 0x3a0000]; float constants [0x1b0000];
   $gp-relative small data: no   saves: -; callee-saved registers saved [-];
   words plain C cannot emit [-]. Head: addiu $sp, $sp, -0x50 ; addiu $v0,
   $zero, 0xFF ; sd $s5, 0x28($sp) ; addiu $v1, $zero, 0x1C ; sd $s3,
   0x18($sp) ; daddu $s5, $a0, $zero. Not matched in this wave: the body is
   straight-line code whose register allocation and the materialisation of
   its constant addresses have to be reproduced word for word. What would
   unblock it: the exact source expression tree, so this cc1 picks the same
   registers in the same order. */
