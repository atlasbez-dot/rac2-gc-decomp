/* near-miss: func_L20_004448A8 (20_yeedil, 508 bytes).
 *
 * This is the wave-5 structure recovery, not a close candidate: the candidate is 484
 * bytes against retail's 508 and the inner loop's shape is not the retail's.
 *
 * WHAT IS RECOVERED (retail's):
 *   - the dispatch on the type word at arg1+0xAA:
 *       type == 0x119E          -> n = 1, loc[0] = state->0x23C
 *       type <  0x119F and == 0xD0F -> n = 2, loc[0] = state->0x21C, loc[1] = state->0x240
 *       type == 0x12EF          -> n = 1, loc[0] = state->0x23C   (checked TWICE in the
 *                                  retail: once under `type < 0x119F` and once above it)
 *       otherwise               -> n = 0 and the function returns 0
 *     The two ints live in a local array at sp+0x00 and sp+0x04 and are read through
 *     the index (sp + i*4).
 *   - the float constant is 1028.0f (0x44802000), compared with the result of
 *     func_00282E80(object+0x10, arg0+0x10): `c.lt.s $f0,$f20 ; bc1tl` - the object is
 *     the result when the compare is true.
 *   - the outer loop walks the local array (i < n) and the inner loop walks a list:
 *     p = D_L20_001FBB20[loc[i]]; the object is
 *     D_L20_001B2F9C + ((count & 0x7FFF) << 8) where count is the short at p-2 (or the
 *     unsigned short at p when that short is negative); the object is skipped when
 *     *(short *)(o+0xAA) != 0xB69, and the two calls func_0032EAB8(o,0,1) and
 *     func_003FBEA8(o,0) run when the byte at o+0x20 is neither 0xFE nor 0xFD.
 *   - the globals are absolute here (no $gp): D_L20_001FBB20, D_L20_001B2FB8,
 *     D_L20_001B2F9C.
 *
 * WHAT IS LEFT:
 *   - the inner loop's shape.  The retail's inner loop has its body at the top with the
 *     count test `bgezl` (branch likely, the delay slot carries `lhu $v0,0($s1)`) and
 *     its condition at the bottom, where the same three tests (the byte 0xFF, the
 *     D_L20_001B2FB8 bound and p != 0) are repeated; this candidate's loop is a plain
 *     `for(;;)` with the tests at the bottom and the compiler's own shape.
 *   - the dispatch's branch-likely forms: the retail's `beql $v1,$v0` with the case's
 *     first instruction in the delay slot (the three case bodies are laid out after
 *     the dispatch), this candidate a plain `bne`.
 *   - the frame: the retail's is 0x80 with eight saved registers plus $fp and $f20,
 *     this candidate's 0x50 with six.
 */

extern char *D_L20_001FBB20[];
extern int D_L20_001B2FB8;
extern void func_0032EAB8(char *, int, int);
extern void func_003FBEA8(char *, int);

char *func_L20_004448A8(char *arg0, char *arg1) {
    char *state = *(char **)(arg0 + 0x68);
    int loc[2];
    int n = 0;
    char *res = 0;
    short type = *(short *)(arg1 + 0xAA);
    int i;
    int a;
    char *p;
    char *o;
    unsigned int c;

    o = (char *)D_L20_001B2F9C;

    if (type == 0x119E) {
        n = 1;
        loc[0] = *(int *)(state + 0x23C);
    } else if (type < 0x119F) {
        if (type == 0xD0F) {
            n = 2;
            loc[0] = *(int *)(state + 0x21C);
            loc[1] = *(int *)(state + 0x240);
        } else if (type == 0x12EF) {
            n = 1;
            loc[0] = *(int *)(state + 0x23C);
        }
    } else if (type == 0x12EF) {
        n = 1;
        loc[0] = *(int *)(state + 0x23C);
    }

    for (i = 0; i < n; i++) {
        a = loc[i];
        if ((a & 0xFF) == 0xFF) {
            continue;
        }
        if (D_L20_001B2FB8 < a) {
            break;
        }
        p = D_L20_001FBB20[a];
        if (p == 0) {
            continue;
        }
        for (;;) {
            c = *(unsigned short *)(p - 2);
            if ((c & 0x8000) != 0) {
                c = *(unsigned short *)p;
                if (p != D_L20_001FBB20[loc[i]]) {
                    goto check;
                }
            }
            o = D_L20_001B2F9C + ((c & 0x7FFF) << 8);
            if (o == 0) {
                goto check;
            }
            if (*(short *)(o + 0xAA) != 0xB69) {
                p += 2;
                goto check;
            }
            if (*(unsigned char *)(o + 0x20) != 0xFE &&
                *(unsigned char *)(o + 0x20) != 0xFD) {
                func_0032EAB8(o, 0, 1);
                func_003FBEA8(o, 0);
            }
            p += 2;
check:
            a = loc[i];
            if ((a & 0xFF) == 0xFF) {
                break;
            }
            if (D_L20_001B2FB8 < a) {
                break;
            }
            if (p == 0) {
                break;
            }
        }
    }
    return res;
}
