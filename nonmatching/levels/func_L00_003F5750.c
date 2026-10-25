/*
 * Retained manual near miss; not linked or counted.
 * Final measured profile: -O2 -G8 -ffunction-sections.
 * Final C / retail: 288 / 288 bytes.
 * us:0/27 placements, exit1; us2:0/27 placements, exit1.
 * pal: absent from catalogue, exit1; absence is not a match.
 * 6 bounded source/profile trials; three natural source forms tie.
 * Equal288-byte size and0x40 frame; table/offset live ranges occupy different saved GPRs, with pointer-add operand/store scheduling differences. Actual regalloc diagnostics were consistent across baseline/diagnostic objects.
 * Reopen only with: Independently measured table/record cursor lifetimes that change the genuine allocator queue; not another equivalent pointer spelling.
 * Measured in the dedicated src unit before its marker/profile were restored; this body is retained unchanged modulo this comment.
 * Historical draft and trial variants remain private. Behavior and strict linked equality remain unverified.
 */

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
    short index = *(short *)(state + 0x20);
    char **entry;
    int offset = index * 0x30;
    float degrees, result, next, low, high;
    entry = table + *(short *)(state + 0x18);
    qcopy(*entry + 0x10 + offset,position);
    degrees = func_00283CE0(index) * 0.017453294f;
    result = func_002ABB18(degrees * D_L00_001B0948);
    low = D_L00_001B0940; high = D_L00_001B0944;
    *(float *)(*entry + offset + 0x20) = result;
    result = func_002A7878(low,high);
    low = D_L00_001B0950; next = D_L00_001B094C;
    *(float *)(*entry + offset + 0x28) = result * 0.017453294f;
    high = D_L00_001B0954;
    *(float *)(*entry + offset + 0x24) = next;
    result = func_002A78D8(low,high);
    *(float *)(*entry + offset + 0x2c) = result * 0.016666668f;
    func_L00_003F5870(*entry,index);
    (*(unsigned short *)(state + 0x20))++;
}
