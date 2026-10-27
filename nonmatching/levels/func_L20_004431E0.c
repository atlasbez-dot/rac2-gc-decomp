/* Nonmatching: 320/324 bytes.
 * Profile: -O2 -G8 -ffunction-sections.
 * Placement checks: US: 0/1; US2: 0/1; PAL absent from catalogue.
 * 320/324 bytes. The initial table/index allocation and guard block layout differ; CSE shares the unchanged index read and cross-jumps the guard. The source retains real pointer returns, canonical callee names and complete typed vector copies, without the old artificial volatile read.
 * Reopen with independent source-level index or table lifetime evidence and actual allocator/control-flow diagnostics; do not force a second read with invented volatility.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 quad; float component[4]; } Vector431E0;

extern u16 *D_L20_001FBB20[];
extern char *D_L20_001B2F9C;
extern int D_L20_001B2FB8 __attribute__((sda));
extern int func_00312B58(char *);
extern void func_L02_003A6FE8(char *);
extern int func_L02_002EF388(char *, char *, char *, char **, int);
extern char *func_L20_0039BDF0(char *, char *, int, int);

char *func_L20_004431E0(char *arg0, TI128 *arg1) {
    char *state = *(char **)(arg0 + 0x68);
    u16 **tbl = D_L20_001FBB20;
    u16 *rec = (u16 *)tbl[*(int *)(state + 0x218)];
    char *found = 0;
    Vector431E0 buf;
    int idx;

    goto check;
body:
    {
        char *e = D_L20_001B2F9C + ((*rec & 0x7FFF) << 8);

        if (e != 0) {
            if (func_00312B58(e) != 0) {
                found = e;
            }
        }
    }
    goto end;
check:
    idx = *(int *)(state + 0x218);
    if ((idx & 0xFF) == 0xFF) {
        goto end;
    }
    if (D_L20_001B2FB8 < idx) {
        goto end;
    }
    if (rec == 0) {
        goto end;
    }
    if (*(s16 *)(rec - 1) >= 0) {
        goto body;
    }
    tbl = D_L20_001FBB20;
    if (rec == (u16 *)tbl[idx]) {
        goto body;
    }
    goto end;
end:
    if (found != 0) {
        char *p = found + 0x10;
        char *s2;

        qcopy(p, arg1);
        func_L02_003A6FE8(found);
        func_L02_002EF388(found, p, found + 0xF0, 0, 0);
        s2 = *(char **)(found + 0x68);
        *(int *)(s2 + 0xAC) |= 8;
        qcopy(&buf, p);
        buf.component[2] -= 0.5f;
        func_L20_0039BDF0(found, (char *)&buf, 0x168, 0);
    }
    return found;
}
