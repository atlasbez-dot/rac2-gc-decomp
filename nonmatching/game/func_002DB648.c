/* Near miss: 408 bytes, expected 420, 0 of 28 places (USA v1.01 boot).
 *
 * Profile: default (-O2 -G0 -ffunction-sections); no $gp access.
 * Last verdict: `python scratch/wslcmp.py src/game/002D5E98.c func_002DB648`
 *   func_002DB648: 0 of 28 places match   [boot: 408 bytes, expected 420]
 *
 * Remaining difference: the shared state base 0x1B8840 (accessed as a char
 * array here) and the flags word.  Retail keeps the %hi of the state address
 * in a register and re-derives `addiu v0,s1,-0x7E80` for every read of
 * D_00138180's flag word (four reads), while this cc1 materialises the full
 * address once.  Retail also turns the `flags & 0x10` early return into a
 * branch pair (`beql`, `daddu v1,zero,zero`) where this C gives `movn`.  The
 * sequence-record walk, the call sequence and the wrap byte are identical.
 */
typedef struct {
    char pad00[0x34];
    char *records;
    int index;
} Sequence_2DB648;

extern char D_001F2840[];

extern int D_00138180[];

extern void func_002DF190(int, int);

#define CTX_2DB648 ((char *)&D_001F2840)
#define STATE_2DB648 ((char *)D_00138180)

int func_002DB648(Sequence_2DB648 *o)
{
    char *p = (char *)o;
    int result = 0;
    int flags;
    int old;

    if (*(int *)(*(int *)(CTX_2DB648 + 0x14) + 0xE8) != (int)o)
        return 0;
    flags = *(int *)(STATE_2DB648 + 0x1C4);
    if ((flags & 0x900) != 0 && *(int *)(CTX_2DB648 + 0x134) == 0)
        return 1;
    flags = *(int *)(STATE_2DB648 + 0x1C4);
    if ((flags & 0x10) != 0) {
        int value = *(int *)(*(int *)(CTX_2DB648 + 0x14) + 0xE0);

        if (value != 0) {
            *(int *)(CTX_2DB648 + 0x18) = value;
        } else {
            result = -1;
            if (*(int *)(CTX_2DB648 + 0x134) != 0)
                result = 0;
        }
        return result;
    }
    old = *(int *)(p + 0x38);
    if ((flags & 0x1000) != 0) {
        if (old != 0)
            *(int *)(p + 0x38) = old - 1;
    }
    flags = *(int *)(STATE_2DB648 + 0x1C4);
    if ((flags & 0x4000) != 0) {
        char *record = *(char **)(p + 0x34) + *(int *)(p + 0x38) * 0x18;

        if (*(int *)(record + 0x18) != 0)
            *(int *)(p + 0x38) = *(int *)(p + 0x38) + 1;
    }
    if (*(int *)(p + 0x38) != old)
        func_002DF190(1, 0x11);
    {
        char *record = *(char **)(p + 0x34) + *(int *)(p + 0x38) * 0x18;
        int count = 0;
        char *slot;

        if (*(int *)(record + 0x8) != 0) {
            slot = record + 0xC;
            while (*(int *)slot != 0) {
                count++;
                if (count >= 4)
                    break;
                slot += 4;
            }
        }
        if ((flags & 0x40) != 0) {
            char *byte = *(char **)(record + 0x4);

            if (byte != 0) {
                unsigned char value = *(unsigned char *)byte;

                *byte = (value + 1) % count;
                func_002DF190(0, 0x11);
            }
        }
    }
    return 0;
}
