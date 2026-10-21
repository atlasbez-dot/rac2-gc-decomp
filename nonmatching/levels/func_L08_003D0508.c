typedef unsigned int ti_word __attribute__((mode(TI)));
extern void func_00282CF0(void *, void *, void *);
extern void func_002AD6F0(void *, void *, void *, void *);

void func_L08_003D0508(void *raw) {
    char *object = raw;
    char *state = *(char **)(object + 0x68);
    ti_word copy;
    char scratch[0x10];
    if (*(unsigned char *)(object + 0x20)) return;
    copy = *(ti_word *)(object + 0x10);
    *(ti_word *)(state + 0x90) = copy;
    *(unsigned short *)(state + 0x3E) = 15;
    *(unsigned int *)(state + 0x8C) |= 1;
    *(void **)(state + 8) = state + 0x50;
    *(void **)(state + 0) = state + 0x20;
    object[0x20] = 1;
    *(unsigned short *)(object + 0x34) |= 0x20;
    func_00282CF0(scratch, object + 0x10, state + 0x90);
    func_002AD6F0(state + 0x50, scratch, object + 0xF0, object + 0xF0);
}

/* Wave 24 (worker 05): the same wall, measured again from the retail body.
   The retail keeps the address of the 16-byte transfer in a register and
   uses a zero displacement:

     addiu $a1, $s2, 0x90
     addiu $v1, $s3, 0x10
     lq    $v0, 0x0($v1)      <- the source is base + 0x10
     sq    $v0, 0x0($a1)      <- the destination is base + 0x90
     ...
     addiu $s1, $s3, 0x10
     addiu $s0, $s2, 0x90
     ...
     lq    $v0, 0x0($s1)
     sq    $v0, 0x0($s0)

   this cc1 folds the constant offset into the lq/sq instead
   (GO_IF_LEGITIMATE_ADDRESS accepts plus(reg, const) as a TImode address while
   the offset is inside [-32768, 32752]), so the body comes out 160 bytes
   against retail's 192 and with the frame 0x30 against retail's 0x40 (the
   materialised addresses need registers of their own).  check.py (08_tabora):
   "160 bytes, expected 192"; the first difference is the lq's displacement.
   The same wall as func_L00_002A6008 / func_L00_002A5CB0: a retail address
   that is base + const is not reachable from plain C.

   What is measured and right: the copy is a mode(TI) object; the field at
   0x20 is read as an unsigned byte (retail `lbu`); the frame's local is 16
   bytes at 0x00 (retail passes sp+0 to func_00282CF0).

   The attempt below uses the level-8 names of the two calls
   (func_00282CF0 at 0x2F9E20, func_002AD6F0 at 0x3301C0).  */
extern void func_00282CF0(void *, void *, void *);
extern void func_002AD6F0(void *, void *, void *, void *);

void func_L08_003D0508_w24(char *a0) {
    char *s3 = a0;
    char *s2 = *(char **)(s3 + 0x68);
    ti_word buf[1];

    if (s3[0x20] == 0) {
        *(ti_word *)(s2 + 0x90) = *(ti_word *)(s3 + 0x10);
        *(int *)(s2 + 0x8C) |= 1;
        *(unsigned short *)(s2 + 0x3E) = 0xF;
        *(int *)(s2 + 0x8) = (int)(s2 + 0x50);
        *(int *)(s2 + 0x0) = (int)(s2 + 0x20);
        s3[0x20] = 1;
        *(unsigned short *)(s3 + 0x34) |= 0x20;
    }
    func_00282CF0(buf, s3 + 0x10, s2 + 0x90);
    func_002AD6F0(s2 + 0x50, buf, s3 + 0xF0, s3 + 0xF0);
    *(ti_word *)(s2 + 0x90) = *(ti_word *)(s3 + 0x10);
}
