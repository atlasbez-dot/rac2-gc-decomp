/* 2026-10-23 bounded reconstruction, not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0 of 27 places match (src/levels/shared/L00_003F5750-g8-qcopy.c); us2: 0 of 27 places match (src/levels/shared/L00_003F5750-g8-qcopy.c); pal: func_L00_003F5750 is in neither catalogue of pal.
 * 288/288 bytes; table/offset register allocation and address operand order differ. Tried direct and incremented table pointers, operand order and explicit next-call arguments. Reopen with an independently justified table/record layout.
 * Historical note below is retained; its no-C-attempt statement predates this draft.
 */
/* from src/levels/shared/L00_003EE100.c: not written this wave. Retail 288 bytes, 27 place(s), first word at L00:003f5750.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x003f5750  addiu       $sp, $sp, -0x40
 *   0x003f5754  sd          $s0, 0x0($sp)
 *   0x003f5758  sd          $s1, 0x8($sp)
 *   0x003f575c  sd          $s3, 0x18($sp)
 *   0x003f5760  sd          $s4, 0x20($sp)
 *   0x003f5764  sd          $ra, 0x28($sp)
 * Kept as data for the maintainers. */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
extern char *func_L00_0032A088(int,int);
extern float func_00283CE0(int);
extern float func_002ABB18(float);
extern float func_002A7878(float,float);
extern float func_002A78D8(float,float);
extern void func_L00_003F5870(char *,int);
extern float D_L00_001B0940 __attribute__((sda));
extern float D_L00_001B0944 __attribute__((sda));
extern float D_L00_001B0948 __attribute__((sda));
extern float D_L00_001B094C __attribute__((sda));
extern float D_L00_001B0950 __attribute__((sda));
extern float D_L00_001B0954 __attribute__((sda));

void func_L00_003F5750(char *object, char *position)
{
    char *state = *(char **)(object + 0x68);
    char **table = (char **)func_L00_0032A088(0xc04, *(short *)(state + 0x1a));
    int index = *(short *)(state + 0x20);
    int slot = *(short *)(state + 0x18);
    char **entry;
    int offset = index * 0x30;
    float degrees, result, next, low, high;
    entry = table;
    entry += slot;
    *(TI128 *)(offset + *entry + 0x10) = *(TI128 *)position;
    degrees = func_00283CE0(index) * 0.017453294f;
    result = func_002ABB18(degrees * D_L00_001B0948);
    low = D_L00_001B0940; high = D_L00_001B0944;
    *(float *)(offset + *entry + 0x20) = result;
    result = func_002A7878(low,high);
    low = D_L00_001B0950; next = D_L00_001B094C;
    *(float *)(offset + *entry + 0x28) = result * 0.017453294f;
    high = D_L00_001B0954;
    *(float *)(offset + *entry + 0x24) = next;
    result = func_002A78D8(low,high);
    offset += (int)*entry;
    *(float *)(offset + 0x2c) = result * 0.016666668f;
    func_L00_003F5870(*entry,index);
    (*(unsigned short *)(state + 0x20))++;
}
