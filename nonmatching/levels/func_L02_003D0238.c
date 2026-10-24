/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-barrier -mno-split-addresses.
 * Prior worker coverage: US 0/1; US2 0/1; PAL 0/1.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Nonmatching: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-barrier -mno-split-addresses. us: func_L02_003D0238: 0 of 1 places match (src/levels/02_maktar_nebula/L02_003D0238.c); us2: func_L02_003D0238: 0 of 1 places match (src/levels/02_maktar_nebula/L02_003D0238.c); pal: func_L02_003D0238: 0 of 1 places match (src/levels/02_maktar_nebula/L02_003D0238.c). Six bounded manual/profile trials; final192/184 frame0x20. Two quad copies and zero clear are ordinaryC; remaining position-pointer CSE adds a saved register, zero displacement and absolute/GP scalar-load scheduling differ. Canonical helper registration returnsint with allfiveGPRinputs. Reopen on source address-lifetime/clear shape. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern int D_L02_001B0138 __attribute__((sda));
extern int D_L02_001B013C NOT_SDA;
extern int func_L01_0031BC68(int, int, float);
extern void func_002A7750(u8 *, u8, int), func_L00_003294F0(u8 *, int);
extern int func_L02_002EF388(void *, void *, void *, void *, int);
/* Restores the actor's saved spawn point and registers its hidden proxy. */
void func_L02_003D0238(char *self) {
    char *state = *(char **)(self + 0x68);
    *(int *)(state + 0xD8) = 0;
    *(int *)(self + 0x78) = func_L01_0031BC68(D_L02_001B0138, D_L02_001B013C, *(float *)(state + 0xD8));
    func_002A7750((u8 *)self, 1, -1);
    *(Quad *)(self + 0x10) = *(Quad *)(state + 0xA0);
    *(Quad *)(state + 0x60) = *(Quad *)(state + 0xA0);
    *(Quad *)(state + 0x50) = 0;
    self[0x31] = 1;
    *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) & 0xFFFE) | 0x1000;
    func_L00_003294F0((u8 *)self, 0);
    func_L02_002EF388(self, self + 0x10, self + 0xF0, 0, 0);
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* Historical analysis (summary).
 * Historical screening identified three vector transfers and investigated source/destination
 * address lifetimes and mixed small-data loads. Its earlier claim that no ordinary C
 * reconstruction was possible is superseded by the manual body and recorded measurements above.
 * The old decoded instruction excerpt remains private.
 */

#include "include_asm.h"

INCLUDE_ASM("asm/levels", func_L02_003D0238);
