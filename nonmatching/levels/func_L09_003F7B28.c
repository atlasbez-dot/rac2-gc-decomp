/* func_L09_003F7B28, 292 bytes, 3 places (09_dobbo, 12_todano, 20_yeedil).
 * NEAR MISS - the candidate is 280 bytes against retail's 292: the whole body is right
 * (the call to func_L09_0033E8B0 with the run's index, the level's table lookup, the two
 * distance calls and the stage call), but three words are missing: retail keeps a
 * direction word that starts at -1 and is set to 1 when the run's index is below the
 * frame's end, and it spends it in `addiu $t0,$zero,-1` and `movn $t0,$s4,$v0` in the
 * first call's delay slot.  This cc1 drops the word as dead: nothing reads it, and this
 * compiler removes the assignment before the conditional move is formed.
 *
 * What is needed: a source shape that keeps the direction word alive in the tree while
 * its value stays dead in the code - the retail's own source must have read it somewhere
 * this shape does not.  Twelve spellings were measured (a plain `if`, a ternary, a
 * `register` word, a self-comparison to keep the read, a word initialised in each arm,
 * and a word compared against the -1 sentinel): all of them drop the word, so the
 * remaining difference is the -1 sentinel the retail keeps in $s0 as well.
 *
 * The rest of the function is exact, including the table's 32-bit addresses
 * (D_L09_001FE6C0 holds 32-bit record pointers, indexed with the run's index) and the
 * four floats the stage call takes.
 */

#include "include_asm.h"

typedef unsigned int u32;

extern u32 D_L09_001FE6C0[];

extern int func_L09_0033E8B0_2(char *object, int index, void *out, int a, float f);

extern int func_L09_0033E658(int index);

extern float func_00283248(float x, float y);

extern void func_002AAA00(char *a, char *b, int c, float d, float e, float f, float g);

/* Steps the run's frame to the next entry of the level's table and hands the
   distance from the object to that entry's point to the stage. */
int func_L09_003F7B28(char *object, int index)
{
    char *frame = *(char **)(object + 0x68);
    short cur = *(short *)(frame + 0x1C8);
    short end = *(short *)(frame + 0x1CA);
    int ret = 1;
    int dir = -1;
    int step = -1;
    int next;
    short idx;
    int r;
    float dist;

    next = func_L09_0033E8B0_2(object, index, object + 0x10, cur,
                               *(float *)(frame + 0x128));
    idx = (short)next;
    dir = (cur < end) ? ret : dir;
    *(short *)(frame + 0x1C8) = next;
    if (idx != step) {
        if (idx != end)
            ret = 0;
    }
    step = idx + 1;
    r = func_L09_0033E658(index);
    if (r < step) {
        float *rec = (float *)(D_L09_001FE6C0[index] + step * 16);

        dist = func_00283248(rec[4] - *(float *)(object + 0x10),
                             rec[5] - *(float *)(object + 0x14));
    } else {
        dist = func_00283248(*(float *)(frame + 0x1F0) - *(float *)(object + 0x10),
                             *(float *)(frame + 0x1F4) - *(float *)(object + 0x14));
    }
    func_002AAA00(object + 0xF8, frame + 0x1B4, 0, dist,
                  *(float *)(frame + 0x114), *(float *)(frame + 0x118),
                  *(float *)(frame + 0x11C));
    return ret;
}
