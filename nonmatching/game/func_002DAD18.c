/* Near miss: 364 bytes, expected 372, 0 of 28 places (USA v1.01 boot).
 *
 * Profile: default (-O2 -G0 -ffunction-sections); the body has no $gp access.
 * Last verdict: `python scratch/wslcmp.py src/game/002D5E98.c func_002DAD18`
 *   func_002DAD18: 0 of 28 places match   [boot: 364 bytes, expected 372]
 *
 * Remaining difference (eight bytes, both cases): the frame counter modulo is
 * expanded as `lbu a0,D_001A7BB4` / `addiu v0,zero,5` / `divu $zero,$a0,$v0`,
 * and the bank address is `addu v0,v1,a1` with a `daddu v1,v0,zero` copy for
 * the second `lw 0xDD4($v1)`.  This unit's cc1 puts the divisor in $v1, the
 * base in $a1 and reuses one address register for both loads, so the shared
 * `lw` of the bank pair loses the copy.  Tried: named divisor local, unsigned
 * local, `% 5`, direct global expression, locals for the pair; all give the
 * same 364-byte shape.  The switch, the calls and every other instruction are
 * identical.
 */
typedef struct {
    char pad[0x44];
    int state;
    int first;
    int second;
} State2DAD18;

extern short D_001A63AC;

extern unsigned char D_001A7BB4;

extern char D_0014B540[];

extern int func_002B7B18(int, int, int);

int func_002DAD18(State2DAD18 *o)
{
    switch (o->state) {
    case 0:
        if (o->first != 0) {
            if (D_001A63AC != 0)
                break;
            {
                char *base = D_0014B540;
                unsigned int frame = D_001A7BB4;
                int slot = frame % 5;

                if (func_002B7B18(o->first,
                                  *(int *)(base + 0x36C) + *(int *)(base + 0xDD0 + slot * 8),
                                  *(int *)(base + 0xDD4 + slot * 8)) != 0)
                    o->state++;
                else
                    o->state = -1;
            }
        }
        break;
    case 1:
        if (D_001A63AC != 0)
            break;
        o->state = 2;
        break;
    case 2:
        if (o->second != 0) {
            if (D_001A63AC != 0)
                break;
            {
                char *base = D_0014B540;
                unsigned int frame = D_001A7BB4;
                int slot = frame % 5;

                if (func_002B7B18(o->second,
                                  *(int *)(base + 0x36C) + *(int *)(base + 0xDF8 + slot * 8),
                                  *(int *)(base + 0xDFC + slot * 8)) != 0)
                    o->state++;
                else
                    o->state = -1;
            }
        }
        break;
    case 3:
        if (D_001A63AC != 0)
            break;
        o->state = 4;
        break;
    }
    return 0;
}
