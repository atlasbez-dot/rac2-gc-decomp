/* func_L00_002B8CB8 (396 bytes, 27 places) - best attempt, NOT MATCHED.
 *
 * G8: this unit needs -G8 (the sda attribute on D_001A7BF8 only gives the $gp-relative
 * access retail has in a -G8 unit) and a -frac2-nothing else; check it again in a
 * "-g8.c" source unit.
 *
 * Measured: 364 bytes against 396, with the retail's structure otherwise in place:
 * the state block at 0x189E20 (the pointer at +0x1314, the mode at +0x2294, the angle
 * at +0x1A8), the record at 0x25BE10 (the four floats at +0xCC8, +0xCF8, +0xD04 and
 * +0xD08) and the level's float at 0x25CB1C. The clamp of the angle to +/-1.4 and of
 * the share to +/-75 degrees (0x3FA78D37) is the retail's, including the way this cc1
 * renders the "if (x < -1.4f) x = -1.4f;" as a likely branch with the assignment in
 * the delay slot.
 *
 * Four measured differences remain:
 *   (a) retail has two nops between the load of the mode and the div.s; this cc1
 *       never emits nops there;
 *   (b) retail reloads the pointer at +0x1314 after the store to 0x25CB1C; this cc1
 *       keeps it in a register, because a float store and a pointer load are in
 *       different alias sets, so the load is not invalidated;
 *   (c) retail computes the share as "neg.s" of the clamped angle; this cc1 folds the
 *       "x = -1.4f; y = -x;" pair into the constant 1.4f;
 *   (d) the register allocation differs: retail keeps the record's address in two
 *       registers (one per block) and the block's base in $a1, this cc1 keeps one copy
 *       of each and puts the state base in $a1 with the offsets folded into the loads.
 *
 * To retake: a form whose float store invalidates the pointer load, whose negated
 * angle is not folded, and whose record address is rematerialised per block.
 */

#include "include_asm.h"
#include "common.h"

/* The record the level writes: four floats near its end. */
typedef struct Rac2Native_002B8CB8_Record {
    unsigned char prefix_00[0xCC8];
    float f_CC8;
    unsigned char prefix_CCC[0xCF8 - 0xCC8 - 4];
    float f_CF8;
    unsigned char prefix_CFC[0xD04 - 0xCF8 - 4];
    float f_D04;
    float f_D08;
} Rac2Native_002B8CB8_Record;

extern char D_00189E20_13[];

extern unsigned char D_001A7A43 NOT_SDA;

/* A float in the boot's small data: the sda attribute and this unit's -G8 make the
   reference to it $gp-relative, the way retail has it. */
extern float D_001A7BF8 __attribute__((sda));

extern Rac2Native_002B8CB8_Record D_L00_25BE10;

extern float D_L00_25CB1C NOT_SDA;

extern float func_00282C48(float f);

/* Scales the level's record by the state block's mode: the block's own angle is clamped
   to a range, turned into a small signed share and written back, and the record's two
   lengths follow it. */
void func_L00_002B8CB8(void)
{
    Rac2Native_002B8CB8_Record *rec = &D_L00_25BE10;
    float *live;
    char *st = D_00189E20_13;
    float x;
    float y;
    float share;
    float len;
    float scale;

    if (*(void **)(st + 0x1314) == 0)
        return;
    if (D_001A7A43 != 0)
        D_L00_25CB1C = D_001A7BF8;
    live = *(void **)(st + 0x1314);
    scale = 1024.0f / *(float *)((char *)live + 0x2C);
    if (*(int *)(st + 0x2294) != 2)
        return;

    x = *(float *)(st + 0x1A8);
    y = 0.02f;
    rec->f_D04 = y;
    rec->f_D08 = 0.35f;
    if (1.4f < x)
        x = 1.4f;
    if (x < -1.4f) {
        x = -1.4f;
        y = -x;
    }
    y = y * 1.2f;
    if (75.0f * 3.14159274f / 180.0f < y)
        y = 75.0f * 3.14159274f / 180.0f;
    if (y < -(75.0f * 3.14159274f / 180.0f))
        y = -(75.0f * 3.14159274f / 180.0f);
    rec->f_CC8 = y;

    share = 0.1f;
    len = func_00282C48(x) * share;
    share = len + share;
    if (0.055f < share)
        share = 0.055f;
    rec->f_CF8 = share * scale;
}
