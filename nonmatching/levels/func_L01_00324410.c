/* func_L01_00324410 - near miss (wave 1, worker 06, 22 October 2026)
 *
 * Retail: 316 bytes, 11 places (levels 01, 04, 06, 08, 09, 11, 12, 14, 17, 18, 19).
 * This candidate: 320 bytes, the instruction sequence is the retail's word for word -
 * only the register allocation of the saved registers differs, and the frame with it
 * (0x90 against the retail's 0x80, one callee-saved register more).
 *
 * What the function does (decoded):
 *   - func_00115AC0(0x70000000, src, 0xFF) fills the buffer at 0x70000000;
 *   - a loop reads up to ten ints out of the array at the third argument, every second
 *     int (the retail's `addiu $s0,$s0,0x8 ; lw $v0,-0x8($s0)`), stopping at -1, and
 *     keeps them in a ten-int table at sp+0x00;
 *   - the buffer is walked: a plain character is copied, "%d" prints the next number of
 *     the table and "%<n>d" the n-th one (the retail reads the character after the '%'
 *     with `lbu $v0,0x1($s1)`, and takes three characters for the indexed form);
 *   - the number is formatted by func_L01_003242C8 into the buffer at sp+0x30 and
 *     copied out, at most 0x20 characters.
 *
 * The one difference left is the allocation of the callee-saved registers.  The retail
 * uses five ($s0-$s4) and shares them: the array pointer, the loop counter and the
 * first argument die before the format loop and their registers are taken over by the
 * output cursor, the buffer pointer and the number counter.  This candidate uses six:
 * the buffer pointer ($s2) and the first argument ($s3) each keep a register of their
 * own, so the two sharing pairs are lost.
 *
 * Measured with tools/check.py func_L01_00324410 --diff: 320 bytes against the retail's
 * 316, every instruction equal, the registers of the frame and of the two derived
 * pointers differing.
 *
 * What was tried (each a compile):
 *   - the first loop as `while (i < 10)`, as a `for` and as a `for(;;)` with the
 *     counter test at the bottom: only the last gives the retail's shape (the pointer
 *     advanced first and the load at -8, `lw $v0,-0x8($s0)`);
 *   - the format string walked with `s[1]` (the retail reads it with an offset of 1)
 *     and with the pointer advanced first: the first matches;
 *   - the first argument kept in a parameter, copied into a local at the top of the
 *     function and copied again before the format loop (the retail's
 *     `daddu $s0,$s2,$zero`): the copy matches, the allocation does not;
 *   - the '%' and 'd' as local variables instead of literals: the retail keeps them in
 *     registers too, but the assignment order does not follow.
 */

extern int func_00115AC0(char *dst, char *src, int len);

void func_L01_00324410(char *out, char *src, int *nums)
{
    unsigned char *dst = (unsigned char *)out;
    int tab[10];
    unsigned char buf[32];
    int i;
    int *p;
    int *q;
    unsigned char *s;
    unsigned char *d;
    char *w;
    int n;
    int cnt;
    int v;

    p = nums;
    i = 0;
    func_00115AC0((char *)0x70000000, src, 0xFF);

    q = tab;
    for (;;) {
        p += 2;
        v = p[-2];
        if (v == -1)
            break;
        *q++ = v;
        i++;
        if (i >= 10)
            break;
    }

    s = (unsigned char *)0x70000000;
    w = (char *)dst;
    cnt = 0;
    while (*s != 0) {
        if (*s == '%') {
            if (s[1] == 'd') {
                v = cnt++;
                s += 2;
            } else {
                v = s[1] - '0';
                s += 3;
            }
            func_L01_003242C8((char *)buf, tab[v], 0);
            if (*buf != 0) {
                d = buf;
                n = 0;
                while (*d != 0 && n < 32) {
                    *w = *d;
                    n++;
                    d++;
                    w++;
                }
                *w = 0;
            }
        } else {
            *w = *s;
            s++;
            w++;
        }
    }
    *w = 0;
}
