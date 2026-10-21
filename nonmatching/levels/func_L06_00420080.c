/* func_L06_00420080 (428 bytes, 1 place: 06:00420080) -- ABANDON (best 412 bytes,
 * four instructions short; ten compiles).
 * The body is recovered from the retail bytes:
 *  - the actor's state is at *(a0 + 0x68); the byte at a0 + 0x20 selects between
 *    the two tables D_L06_001FE500 (indexed by *(int *)(state + 0x260)) and
 *    D_0018E500 (indexed by *(int *)(state + 0x264)); the table entry is a
 *    pointer whose first word is passed as the sixth argument of func_361930 and
 *    whose address + 0x10 is its fifth;
 *  - func_361930 takes six integer arguments (a0, a1, a2, a3 in a0-a3, the fifth
 *    in t0, the sixth in t1) and one float in f12; func_361728 takes two integers
 *    and one float; func_36A798 takes four integers and two floats;
 *  - the two float tests against 8.0f write 2 or 1 to *(int *)(state + 0x258) and
 *    the copy of D_L06_00189EA0 writes 0 there; the function returns that word;
 *  - the tail reads *(float *)(state + 0x338), scales it by 20.0f and calls
 *    func_36A798(a0, -1, 0, 0, scale, 10.0f).
 * The candidate needs the -frac2-qcopy profile in a unit of its own: with it the
 * two 16-byte copies come out as retail's lq/sq pair over two registers (the
 * default profile folds the destination offset into the sq).
 * What still differs (four instructions and the register allocation):
 *  - retail keeps the base pointer of the last block in a register
 *    (addiu $v0,$v0,-0x61E0) and offsets from it twice (lw $v1,0x2290($v0) and
 *    addiu $a0,$v0,0x80); this cc1's combine folds that base into both users
 *    (lw $v0,-0x3F50($a0) and addiu $a0,$a0,-0x6160), so one instruction is
 *    missing and the two offsets differ. A volatile read of the pointer does not
 *    stop it;
 *  - the object pointer and the vector pointer take $s1/$s2 in the candidate and
 *    $s2/$s1 in retail (the save order follows: s1,s0,s2,s3,ra against
 *    s2,s0,s1,s3,ra);
 *  - the test on func_35A620(7) is a plain bnez in retail and a bnel here, and
 *    retail's delay slot holds the else path's table base (lui $v0,0x19) where
 *    this cc1 hoists the last block's load into it;
 *  - retail puts the copy block between the func_361728 block and the second
 *    float test, this cc1 puts it after the second float test.
 * What would unblock it: the exact source expression tree, so this cc1 picks the
 * same registers in the same order and keeps the base pointer in a register.
 */
extern char D_L06_00189EA0[];
extern int *D_L06_001FE500[];
extern int *D_0018E500[];

extern int func_35A620(int);
extern float func_32D7C0(char *);
extern int func_361930(char *, char *, int, int, char *, int, float);
extern int func_361728(char *, char *, float);
extern void func_36A798(char *, int, int, int, float, float);

typedef int TI128 __attribute__((mode(TI)));

int func_L06_00420080(char *a0)
{
    char *s0 = *(char **)(a0 + 0x68);
    char *vec;
    int *p;
    int v;

    if (*(unsigned char *)(a0 + 0x20) != 0) {
        if (func_35A620(7) != 0)
            goto final;
    }
    v = *(int *)(s0 + 0x260);
    vec = s0 + 0x1C0;
    if (v != -1) {
        if (*(unsigned char *)(a0 + 0x20) < 3) {
            p = D_L06_001FE500[v];
        } else {
            p = D_0018E500[*(int *)(s0 + 0x264)];
        }
        if (func_361930(a0, s0 + 0x1C0, 0, 0, (char *)p + 0x10, p[0],
                        *(float *)(s0 + 0x290)) == 2)
            goto copy;
        if (func_32D7C0(a0 + 0x10) < 8.0f)
            *(int *)(s0 + 0x258) = 2;
        else
            *(int *)(s0 + 0x258) = 1;
        goto tail;
    }
    if (func_361728(a0, vec, *(float *)(s0 + 0x290)) == 2)
        goto copy;
    if (func_32D7C0(a0 + 0x10) < 8.0f)
        *(int *)(s0 + 0x258) = 2;
    else
        *(int *)(s0 + 0x258) = 1;
    goto tail;

copy:
    *(TI128 *)vec = *(TI128 *)D_L06_00189EA0;
    *(int *)(s0 + 0x258) = 0;
    goto tail;

final:
    {
        int *p = *(volatile int **)(s0 + 0x200);
        int *base = (int *)((char *)p - 0x61E0);

        if (p == base[0x8A4]) {
            TI128 *dst = (TI128 *)(s0 + 0x1C0);
            TI128 *src = (TI128 *)((char *)base + 0x80);

            *dst = *src;
        }
    }
tail:
    func_36A798(a0, -1, 0, 0, *(float *)(s0 + 0x338) * 20.0f, 10.0f);
    return *(int *)(s0 + 0x258);
}
