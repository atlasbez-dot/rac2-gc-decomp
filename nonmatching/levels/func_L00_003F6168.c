/* 2026-10-23 bounded reconstruction, not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0 of 27 places match (src/levels/shared/L00_003F6168-g8-qcopy.c); us2: 0 of 27 places match (src/levels/shared/L00_003F6168-g8-qcopy.c); pal: func_L00_003F6168 is in neither catalogue of pal.
 * 408/416 bytes; state/base allocation and repeated index/address calculations differ. Tried direct record accesses and a cached index around the object-position copy. Reopen with independently measured record/state aliasing and lowering.
 * Historical note below is retained; its no-C-attempt statement predates this draft.
 */
/* from src/levels/shared/L00_003EE100.c: not written this wave. Retail 416 bytes, 27 place(s), first word at L00:003f6168.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x003f6168  addiu       $sp, $sp, -0x40
 *   0x003f616c  sd          $s0, 0x10($sp)
 *   0x003f6170  sd          $s2, 0x20($sp)
 *   0x003f6174  sd          $s3, 0x28($sp)
 *   0x003f6178  addiu       $s2, $zero, 0x60
 *   0x003f617c  sd          $ra, 0x30($sp)
 * Kept as data for the maintainers. */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
extern char *func_L00_0032A088(int,int);
extern char *func_L00_0032A0B8(int,int);
extern int func_00282978(char *);
extern void func_00282F20(char *,char *,float);
extern void func_00282CC0(char *,char *,char *);
extern float D_L00_001B0988 __attribute__((sda));
extern float D_L00_001B09C0 __attribute__((sda));
extern float D_L00_001B099C __attribute__((sda));
#define RECORD (base + *(short *)(state + 0x18) * 0x60)
int func_L00_003F6168(char *object)
{
    TI128 step;
    int index;
    char *state = *(char **)(object + 0x68);
    char *base = func_L00_0032A088(0xc04,*(short *)(state + 0x1a));
    base += *(int *)func_L00_0032A0B8(0xc04,*(short *)(state + 0x1a));
    if (*(short *)(RECORD + 0x50) == 0) return 0;
    if (func_00282978(RECORD + 0x52) != 0) {
        *(short *)(RECORD + 0x50) = 0;
        return 0;
    }
    index = *(short *)(state + 0x18);
    *(TI128 *)(base + index*0x60 + 0x20) = *(TI128 *)(object + 0x10);
    *(float *)(base + index*0x60 + 0x54) += D_L00_001B0988;
    if (*(float *)(RECORD + 0x54) >= 4.0f) *(float *)(RECORD + 0x54) -= 4.0f;
    *(float *)(RECORD + 0x58) += D_L00_001B09C0;
    if (*(float *)(RECORD + 0x58) >= 4.0f) *(float *)(RECORD + 0x58) -= 4.0f;
    func_00282F20((char *)&step,state,D_L00_001B099C * 0.016666668f);
    func_00282CC0(RECORD,RECORD,(char *)&step);
    func_00282CC0(RECORD+0x10,RECORD+0x10,(char *)&step);
    return 1;
}
#undef RECORD
