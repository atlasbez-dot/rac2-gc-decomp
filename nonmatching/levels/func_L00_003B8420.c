/* func_L00_003B8420 (204 bytes, 4 places) -- NEAR MISS, not integrated.

   New measurement (wave 12, worker s4): the two-step exit is the whole difference.
   Retail keeps a shared block that the two "v == 0" exits jump to, and that block
   tests the value again (`beql $v0,$zero` into the epilogue) before falling
   through into the "f28 != 0" path:

       beqz $v0, zero, L1        ; the first probe failed
       lw   $v0, 0x28($s0)
       bnel $v0, zero, L2        ; the flag is set
       ...
       beql $v0, zero, L1        ; the second probe failed
       ...
   L1: beql $v0, zero, END      ; the shared exit test
       ...

   Every spelling measured collapses the two steps into one branch and gives 196
   bytes: the nested single-return form, the same form with an explicit copy of
   the parameter (`char *s1 = a0`), and two `goto` forms (one with the shared
   label falling through into the "f28 != 0" path, one with it not).  What is
   missing is a source shape in which the two "v == 0" exits reach a *common*
   block that still tests the value - this cc1 folds the redundant test away.

   The callee-saved allocation is also wrong: retail gives $s1 to the parameter
   and $s2 to the 0x00190000 constant, this cc1 gives $s1 to the constant and
   $s2 to the parameter.

   Wave 12 (worker s4). */
extern char D_00189EA0[];

extern int func_002ACBC8(char *, int);

extern int func_002A8508(int, int);

extern void *func_L00_002D70A0(int);

extern void func_L00_002D7140(void *);

extern void func_L00_003B81D0(char *);

void func_L00_003B8420(char *a0)
{
    char *s0 = *(char **)(a0 + 0x68);

    if (func_002ACBC8(D_00189EA0, *(int *)s0) != 0) {
        if (*(int *)(s0 + 0x28) == 0) {
            if (func_002A8508(*(int *)(s0 + 0x40), -1) != 0) {
                *(int *)(s0 + 0x2C) = (int)func_L00_002D70A0(5);
                *(int *)(s0 + 0x28) = 1;
                func_L00_003B81D0(a0);
            }
        } else if (func_002ACBC8(D_00189EA0, *(int *)s0) != 0) {
            if (func_002A8508(*(int *)(s0 + 0x40), -1) == 0) {
                func_L00_002D7140(*(void **)(s0 + 0x2C));
                *(int *)(s0 + 0x28) = 0;
            }
        } else {
            func_L00_002D7140(*(void **)(s0 + 0x2C));
            *(int *)(s0 + 0x28) = 0;
        }
    }
}
