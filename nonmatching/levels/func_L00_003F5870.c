/* 2026-10-23 bounded reconstruction, not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * us: 0 of 27 places match (src/levels/shared/L00_003F5870-g8-qcopy.c); us2: 0 of 27 places match (src/levels/shared/L00_003F5870-g8-qcopy.c); pal: 0 of 27 places match (src/levels/shared/L00_003F5870-g8-qcopy.c).
 * 364/384 bytes; fallback/rotation merge and local vector allocation differ. Tried duplicated scales, shared source pointer and explicit fallback labels. Reopen with the original control-flow/source-pointer lifetime shape; no handwritten-assembly claim.
 * Historical note below is retained; its no-C-attempt statement predates this draft.
 */
/* from src/levels/shared/L00_003EE100.c: not written this wave. Retail 384 bytes, 27 place(s), first word at L00:003f5870.
 * Rule: MMI/LQ/SQ (op 0x1c).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x003f5870  addiu       $sp, $sp, -0x80
 *   0x003f5874  .word       0x700014A9                   # INVALID     $zero, $zero, 0x14A9 # 00000000 <InstrIdType: CPU_NORMAL>
 *   0x003f5878  swc1        $f20, 0x70($sp)
 *   0x003f587c  .word       0x7FA20000                   # INVALID     $sp, $v0, 0x0 # 00000000 <InstrIdType: CPU_NORMAL>
 *   0x003f5880  lui         $at, 0x3F80
 *   0x003f5884  mtc1        $at, $f20
 * Kept as data for the maintainers. */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
extern int D_L00_001A8FF0;
extern float D_L00_001B093C __attribute__((sda));
extern int func_002AFFD8(void *,void *,int);
extern float func_00282C48(float);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_002AB668(void *,void *,float);
extern void func_002ACDE8(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
void func_L00_003F5870(char *base,int index)
{
    TI128 up, direction, difference, normal;
    char *record;
    TI128 *source;
    up = 0;
    ((float *)&up)[2] = 1.0f;
    if (D_L00_001A8FF0 != 0) func_002AFFD8(&up,base + index*0x30 + 0x10,1);
    if ((float)index == 0.0f) goto from_up;
    {
        record = base + index*0x30;
        if (func_00282C48(*(float *)(record+0x20)) < 0.00001f) goto from_up;
        {
            func_00282CF0(&difference,record+0x10,base+index*0x30-0x20);
            func_00282F20(&normal,&difference,1.0f);
            func_002AB668(&normal,&normal,*(float *)(record+0x20));
            func_002ACDE8(&direction,&up,&normal);
            source = &direction;
            goto scale;
        }
    }
from_up:
    source = &up;
scale:
    func_00282D30(&direction,source,*(float *)(base+index*0x30+0x24));
    record = base+index*0x30;
    func_00282CC0(record,record+0x10,&direction);
    *(float *)(record+0xc) = D_L00_001B093C;
}
