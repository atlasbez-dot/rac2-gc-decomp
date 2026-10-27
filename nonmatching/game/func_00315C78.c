/* func_00315C78 (424 bytes, 28 places), closer M2: 424/424 under
 *     -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * with the list head an sda word (retail's lui $s0 / lw $s0 macro read) and accept = 1
 * set after the func_00283DB8 test (retail puts it in that beq's delay slot). One register
 * is left: retail builds the player base's high half in $v1 (lui $v1 / addiu $s5,$v1),
 * this cc1 in $v0. Measured without effect: the base local outside the loop, before or
 * after the float, assigned separately, read inline (worse), sda, and the declaration
 * order of best/cursor.
 * M16: the 0x12EA override sits inside the func_002761F8 block (retail's beqz skips it;
 * the old draft fell through to it). Statement/declaration orders of best, cursor, nearest
 * and the resident pointer, a do/while loop and a HERO view leave the one register. In the
 * permuter queue. */
typedef int TI128 __attribute__((mode(TI)));

extern char *D_001B1B68 __attribute__((sda));
extern float D_001AF54C;
extern char D_001B5340[];
extern char D_001BAF80[];
extern char D_001BAFA0[];
extern char D_00189E20[];

extern int func_00283DB8(void *, float);
extern int func_002761F8(void *, void *, int, void *, int);
extern float func_00282E80(void *, void *);
extern float func_00282E48(void *, void *);

/* Returns the nearest live object of kind 0xCB5 or 0x12EA. */
char *func_00315C78(char *object)
{
    char *best = 0;
    char *cursor = D_001B1B68;
    float nearest;
    char local[16];

    nearest = D_001AF54C;
    while (cursor != 0) {
        char *resident = D_00189E20;

        if ((*(short *)(cursor + 0xAA) == 0xCB5 ||
             *(short *)(cursor + 0xAA) == 0x12EA) &&
            *(unsigned char *)(cursor + 0x20) != 2) {
            int accept;

            *(TI128 *)local = *(TI128 *)(cursor + 0x10);
            *(float *)(local + 0xC) = 0.5f;
            if (func_00283DB8(local, *(float *)(*(char **)(cursor + 0x68) + 8)) != -1) {
                accept = 1;
                if (func_002761F8(D_001B5340, cursor + 0x10, 6, cursor, 0)) {
                    char *base = D_001BAF80;
                    char *state = *(char **)(base + 0x18);
                    if (state == 0 ||
                        (*(short *)(state + 0xAA) != 0xCB5 &&
                         *(char **)(resident + 0x2290) != state))
                        accept = 0;
                    if (*(short *)(cursor + 0xAA) == 0x12EA &&
                        func_00282E80(D_001BAFA0, cursor + 0x10) < 1.0f)
                        accept = 1;
                }
                if (accept) {
                    float dist = func_00282E48(cursor + 0x10,
                                               *(char **)(resident + 0x2290) + 0x10);
                    if (dist < nearest) {
                        nearest = dist;
                        best = cursor;
                    }
                }
            }
        }
        cursor = *(char **)(cursor + 0x28);
    }
    return best;
}
