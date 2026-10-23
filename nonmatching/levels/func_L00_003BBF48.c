/* func_L00_003BBF48 (312 bytes, 27 places) - best attempt, NOT MATCHED.
 *
 * Measured: 300 bytes against 312. The body is the retail's: the table at 0x23DDA0
 * (the record pointer at +0x30), the owner word at +0x5C, the "still free" word at
 * +0x64, the two sprites drawn with the colours 0x103080 and 0xFFFFFFFF and the
 * seven-argument helper. The loop's shape is the retail's too: the record pointer
 * walks the table in the three steps the retail walks it (one step after the owner
 * word matches, one more before the sprites, one more at the end of the body) and
 * the table pointer steps once per round.
 *
 * Two measured differences remain, and both are about the loop's shape:
 *   (a) this cc1 rotates the loop: it moves the round counter's decrement to the top
 *       of the body, where retail has it at the end, and with it the exit test's
 *       branch form changes;
 *   (b) retail uses the "likely" branches (bnel/bnel) whose delay slot is nullified
 *       when the branch is taken, so the two record steps in the delay slots only
 *       happen on the path that continues the body; this cc1 emits the ordinary
 *       bne/bnez, whose delay slot always runs.
 *
 * The register allocation follows from (a) and (b): retail keeps the two colour
 * constants in $s3 and $s4 and the table pointer in $s6, this cc1 keeps one colour
 * constant in $s3 and materialises the other inside the loop.
 *
 * To retake: a form whose loop this cc1 does not rotate (a do-while with the counter
 * decrement at the end of the body, or a form whose entry test it cannot fold), and
 * whose exit branches come out as the "likely" ones.
 */

#include "include_asm.h"

extern char D_L00_23DDA0[];

extern void func_L00_003BC228(char *a0, char *a1);

extern unsigned int func_002A7820(int a, int b);

extern float func_002A7940(void);

extern void func_00281EB8(char *a, int b, unsigned int c, int d, float e, float f, float g);

/* Walks the level's table of records and draws the two sprites of the record the owner
   holds, when that record is still free. The record's own field is the owner, the one
   after it says whether it is free. */
void func_L00_003BBF48(char *a0)
{
    char *base = D_L00_23DDA0;
    char *p = base + 0x30;
    char *q = base;
    int i;
    int c;
    unsigned int color;
    float f;

    i = 29;
    do {
        if (*(int *)(p + 0x5C) == (int)a0) {
            p += 0xA0;
            func_L00_003BC228(a0, q);
            if (*(int *)(p + 0x64) == 0) {
                p += 0xA0;
                c = (int)func_002A7820(0x50, 0x60);
                f = func_002A7940();
                color = ((unsigned int)c << 24) | 0x103080;
                func_00281EB8(p, 0x31, color, 1, 0.5f, 0.15f, f);
                c = (int)func_002A7820(0x50, 0x60);
                f = func_002A7940();
                color = ((unsigned int)c << 24) | 0xFFFFFFFF;
                func_00281EB8(p, 0x31, color, 1, 0.3f, 0.16f, f);
                p += 0xA0;
            }
        }
        i--;
        q += 0xA0;
    } while (i >= 0);
}
