/* Retained C reconstruction, 2026-10-23. Not linked or counted.
   Profile: -O2 -G0 -ffunction-sections
   USA: 196/204 bytes, 0/4 placements; size differs from retail.
   us: 0/4, pal: absent, us2: 0/4.
   Revisit the two-step shared-exit test and saved-pointer allocation.
*/
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
