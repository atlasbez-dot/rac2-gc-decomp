/* func_L00_003C37C8 (344 bytes, 27 places) - best attempt, NOT MATCHED.
 *
 * G8: this unit needs -G8 (the sda attribute on D_001AFF08 only gives the $gp-relative
 * access retail has in a -G8 unit); check it again in a "-g8.c" source unit.
 *
 * Measured: 336 bytes against 344. The calls are the retail's: the two-argument helper
 * with the angle or with its negation, the level's own twenty-round emitter, the
 * record's setter and the four-argument helper, and the final one that writes the new
 * record back. The state's own words are the retail's: the mode at 0x189E20+0x24EC,
 * the flag at +0xBF8, the table at +0x760, the byte that indexes the level's table at
 * 0x0D568+0x19 and the level's table at 0x262570 with a stride of 0xE0.
 *
 * The measured differences are in the addresses and the register allocation: retail
 * materialises the byte's address as "lui $v0,0x14; addiu $v0,$v0,-0x6A98" and keeps
 * the base 0x14000 in $s4 for the second use of the same address, while this cc1
 * materialises the symbol itself and keeps one copy of it; retail's $v0 and $s4 hold
 * the two halves of the 0x14000 base, this cc1's $v0 and $v1 hold two symbols.
 *
 * To retake: a form whose two uses of the byte's address come out of one base
 * register the way retail has it, and whose table address is one symbol.
 */

#include "include_asm.h"
#include "common.h"

extern char D_0010D568[];

extern char D_00189E20_13[];

extern char D_L00_262570[];

/* A float in the boot's small data: the sda attribute and this unit's -G8 make the
   reference to it $gp-relative, the way retail has it. */
extern float D_001AFF08 __attribute__((sda));

extern void func_00282F20(void *a0, void *a1, float f);

extern void func_L00_003C3920(char *a0, char *a1, void *a2);

extern void func_L00_0032A1A8(int a0, char *a1, void *a2, float f);

extern float func_00282DF0(void *a0);

extern void *func_L00_003A98E8(char *a0, void *a1, char *a2, int a3, float f12, float f13, float f14);

void func_L00_003C37C8(char *a0, char *a1)
{
    char scratch[16];
    char *ctx = *(char **)(a0 + 0x68);
    char *rec;
    unsigned char *base = D_0010D568;
    float f20;
    float f21;
    float f0;
    float f14;
    int mode;
    void *v;

    rec = D_L00_262570 + base[0x19] * 0xE0;
    f0 = *(float *)(rec + 0x50);
    f20 = f0 * 0.016666667f;
    mode = *(short *)(D_00189E20_13 + 0x24EC);
    if (mode != 1)
        func_00282F20(scratch, D_00189E20_13 + 0x760, f20);
    else
        func_00282F20(scratch, a0 + 0xD0, -f20);

    rec = D_L00_262570 + base[0x19] * 0xE0;
    func_L00_003C3920(a0, a1, scratch);
    f21 = *(float *)(rec + 0x70);

    mode = *(int *)(D_00189E20_13 + 0xBF8);
    if (mode != 0)
        func_L00_0032A1A8(mode, a1, scratch, f20);

    f0 = func_00282DF0(scratch);
    f14 = D_001AFF08;
    v = func_L00_003A98E8(a1, scratch, a0, 0, f0, f21, f14);
    if (v != 0) {
        *(int *)ctx = (int)v;
        *(int *)((char *)v + 0xB8) = (int)a0;
    }
}
