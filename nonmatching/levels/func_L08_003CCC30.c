typedef unsigned int ti_word __attribute__((mode(TI)));

extern void *func_0029EFD0(int id);
extern float func_00283CE0(int value);
extern void func_002A0F48(void *moby);

/* Near miss (worker 05, listener-small2): check.py (08_tabora) reports
   "240 bytes, expected 248".

   What is measured and right: the seven parameters (the source object, the
   id, the short flag, the value, the extra word, and the two bytes), the
   lookup of the target object, the copy of the 16-byte block at +0x10 and of
   the 16-byte block at +0xF0, the float at +0xF8, the two cleared words at
   +0xF0 and +0xF4, the byte at +0x30, the constant 1 at +0x31, the halfword
   at +0x32, the child pointer at +0x68, the child's stores (the flag at +0x4,
   the value at +0x1C, the second byte at +0x1D, the extra word at +0x0, the
   first byte at +0x1E, the cleared halfword at +0x6 and the float at +0x8),
   the release of the object and the cleared byte at +0x20. The order of the
   child's stores matches the retail when the value store precedes the
   func_00283CE0 call in the source: the retail puts the flag store before
   that call and the value store in the call's delay slot.

   What differs: the retail materialises both 16-byte copy addresses into
   registers and uses a zero displacement

     addiu $a2, $s1, 0x10
     addiu $a1, $s0, 0x10
     lq    $v0, 0x0($a1)
     sq    $v0, 0x0($a2)

   while this cc1 folds the offset into the instruction (`lq $v0,0x10($s2)`).
   Every spelling measured here folds it: mode(TI) casts, a mode(TI) union
   member, a 16-byte struct with and without aligned(16), a struct holding a
   mode(TI) array, memcpy of 16 bytes through mode(TI) and through char
   pointers, and a copy through separately computed mode(TI) pointers. The
   unaligned struct copy keeps the retail's seven saved registers but emits
   ldl/ldr instead of lq/sq, and the mode(TI) copy emits lq/sq but lets cc1
   hoist the child load (`lw $s0,0x68($s1)`) above the last use of the source
   pointer. That hoist costs an eighth saved register (frame 0x50 against the
   retail's 0x40), shifts the whole prologue, and moves the constant 1 from
   the retail's $a0 to $v0.

   Same wall as the sibling near misses func_L08_003D8290 and func_L08_003D0508
   in this area; a spelling that makes cc1 materialise the 128-bit copy's
   addresses would unblock this one too.  */
void *func_L08_003CCC30(void *src, int id, short flag, int value, int extra, unsigned char b1,
                        unsigned char b2) {
    unsigned char *s = (unsigned char *)src;
    unsigned char *d = (unsigned char *)func_0029EFD0(id);
    unsigned char *sub;

    if (d) {
        d[0x30] = s[0x30];
        d[0x31] = 1;
        *(unsigned short *)(d + 0x32) = *(unsigned short *)(s + 0x32);
        *(ti_word *)(d + 0x10) = *(ti_word *)(s + 0x10);
        *(ti_word *)(d + 0xF0) = *(ti_word *)(s + 0xF0);
        *(float *)(d + 0xF8) = *(float *)(s + 0xF8);
        *(int *)(d + 0xF0) = 0;
        *(int *)(d + 0xF4) = 0;
        sub = (unsigned char *)*(unsigned int *)(d + 0x68);
        *(unsigned short *)(sub + 0x4) = flag;
        sub[0x1C] = value;
        *(float *)(sub + 0x8) = func_00283CE0(value);
        sub[0x1D] = b2;
        *(int *)sub = extra;
        sub[0x1E] = b1;
        *(unsigned short *)(sub + 0x6) = 0;
        func_002A0F48(d);
        d[0x20] = 0;
    }
    return d;
}
