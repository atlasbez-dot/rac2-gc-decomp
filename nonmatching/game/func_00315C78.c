/* Retained near miss, 24 October 2026.
 * Game unit `-O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier`.
 * USA v1.01, PAL and USA v2.00: 424/424 bytes, 0/28 places each.
 * Nine checker invocations, no scratch compiles.
 *
 * The body from 0x315CD8 to the epilogue is retail's, instruction for
 * instruction, including the grouped `lq`/`sq` of the 16-byte object block,
 * the 0.5f fourth word, the four helper calls, the accept chain and the
 * nearest-distance update. The remaining difference is the entry block only:
 * retail materialises D_001AF54C's high half in `$v0` and loads the list head
 * with `lui $s0; lw $s0,0x1B68($s0)`, then loads the player base into `$v1`
 * after the null test; this source materialises the list head in `$v0` and
 * the float in `$v1`, and the player base in `$v0`.
 *
 * Measured variants, all identical at the entry block: declaration-order
 * permutations, separate assignments instead of initialisers, while/do-while/
 * for loop forms, the player-base local moved inside the loop (which is what
 * produces retail's late player materialisation), qcopy without the barrier,
 * and -mno-split-addresses (420 bytes, worse). Removing the player-base local
 * gives 412 bytes. No tested source form moves the float to `$v0` and the
 * cursor's high half to `$s0` without changing the matched body.
 *
 * The full body is kept because it is the measured closest reconstruction.
 * Reopen with independent evidence for a source lifetime that fixes the two
 * entry-block register assignments, not another permutation of these forms.
 * Do not add register pins, barriers or volatile to steer the allocator.
 */
typedef int TI128 __attribute__((mode(TI)));

extern char *D_001B1B68;
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
            int accept = 1;

            *(TI128 *)local = *(TI128 *)(cursor + 0x10);
            *(float *)(local + 0xC) = 0.5f;
            if (func_00283DB8(local, *(float *)(*(char **)(cursor + 0x68) + 8)) != -1) {
                if (func_002761F8(D_001B5340, cursor + 0x10, 6, cursor, 0)) {
                    char *base = D_001BAF80;
                    char *state = *(char **)(base + 0x18);
                    if (state == 0 ||
                        (*(short *)(state + 0xAA) != 0xCB5 &&
                         *(char **)(resident + 0x2290) != state))
                        accept = 0;
                }
                if (*(short *)(cursor + 0xAA) == 0x12EA &&
                    func_00282E80(D_001BAFA0, cursor + 0x10) < 1.0f)
                    accept = 1;
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
