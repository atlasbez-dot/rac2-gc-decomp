typedef unsigned int ti_word __attribute__((mode(TI)));
extern void *func_0029EFD0(int);
extern void func_002A0F48(void *);

void *func_L08_003D3D80(void *source) {
    char *dest = (char *)func_0029EFD0(0x987);
    char *src = (char *)source;
    ti_word copy;
    if (dest != 0) {
        dest[0x30] = src[0x30];
        dest[0x31] = 1;
        *(unsigned short *)(dest + 0x32) = *(unsigned short *)(src + 0x32);
        *(unsigned short *)(dest + 0x7C) = 0x7F;
        dest[0x20] = 0;
        *(void **)(*(char **)(dest + 0x68)) = source;
        copy = *(ti_word *)(src + 0x10);
        *(ti_word *)(dest + 0x10) = copy;
        func_002A0F48(dest);
    }
    return dest;
}

/* Wave 24 (worker 05): the same wall, measured again from the retail body.
   The retail keeps the address of the transfer in a register and uses a zero
   displacement:

     addiu $a2, $s1, 0x10
     addiu $a1, $s0, 0x10
     lq    $v0, 0x0($a2)
     sq    $v0, 0x0($a1)

   while this cc1 folds the offsets into the instructions
   (`lq $v0,0x10($v1)` / `sq $v0,0x10($v0)`), which also moves the moby
   pointer out of $a3 and reorders the stores.  check.py (08_tabora):
   "instruction at +0x24 differs" - the first difference is the register the
   constant 1 is built in ($v0 against retail's $v1).

   The attempt below uses the level-8 names of the two calls
   (func_0029EFD0 at 0x31D1D8, func_002A0F48 at 0x31FC78).  */
extern void *func_0029EFD0(int);
extern void func_002A0F48(void *);

void *func_L08_003D3D80_w24(char *a0) {
    char *s1 = a0;
    char *s0 = func_0029EFD0(0x987);
    int *a3;

    if (s0 == 0) {
        return s0;
    }
    a3 = *(int **)(s0 + 0x68);
    *(unsigned char *)(s0 + 0x30) = *(unsigned char *)(s1 + 0x30);
    *(unsigned char *)(s0 + 0x31) = 1;
    *(unsigned short *)(s0 + 0x32) = *(unsigned short *)(s1 + 0x32);
    *(unsigned short *)(s0 + 0x7C) = 0x7F;
    *(unsigned char *)(s0 + 0x20) = 0;
    *a3 = (int)s1;
    *(ti_word *)(s0 + 0x10) = *(ti_word *)(s1 + 0x10);
    func_002A0F48(s0);
    return s0;
}
