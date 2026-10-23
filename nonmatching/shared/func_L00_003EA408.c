/* func_L00_003EA408 (near miss, level 00 aranos_tutorial and 14 aranos_prison,
 * 312 bytes at 2 places).
 *
 * The body is read from the retail bytes: it takes one pointer, and when the
 * state byte at +0x20 is zero it stores 0xAF0 at +0x32, 0xFF at +0x30, 1 at
 * +0x20 and calls the level helper with (1, 3000.0f).  It then gives up when
 * the state byte is not 1 or when the resident word D_L00_001A8F00 is 2, and
 * otherwise takes the float at +0x14, subtracts 1.6666667f from it, takes its
 * absolute value, scales it with (3000.0f - x) / 750.0f, clamps that to
 * 0.0f..3.0f, writes the scaled value times the float at +0x24 of the object
 * at +0x24 into +0x2C, and puts 3000.0f back into +0x14 when the value has
 * reached -3000.0f.
 *
 * Measured: 316 bytes against the retail's 312.  Every instruction matches
 * except one: retail materialises the constant 1 once, in $a0, and uses that
 * register both for the call's first argument and for the byte stored at
 * +0x20; this compiler materialises the store's 1 in $a1 and the argument's 1
 * in $a0, so the body is one instruction longer and everything after the
 * first block is shifted by four bytes.  Tried: the literal 1 in both places;
 * the argument read back from the field after the store (both as unsigned
 * char and as char); a local variable holding the 1 for both uses (at
 * function scope and inside the block, int and unsigned char); the call
 * before the store and the store before the call; the store written through
 * a pointer variable.  None merges the two constants: the store's value and
 * the call argument stay separate pseudos.
 *
 * The D_L00_001A8F00 read needs the `sda` attribute: without it this
 * compiler materialises the address in a separate register
 * (lui $v0 ; lw $v1,0x0($v0)), with it the bare symbol is loaded as retail
 * has it (lui $v1 ; lw $v1,0x8F00($v1)).
 */

extern int D_L00_001A8F00 __attribute__((sda));

extern void func_L00_002E54E0(int mode, float value);

extern float func_00282C48(float value);

void func_L00_003EA408(char *p)
{
    float v;
    float x;
    float a;
    float b;
    float c;
    int *q;

    if (*(unsigned char *)(p + 0x20) == 0) {
        *(unsigned short *)(p + 0x32) = 0xAF0;
        *(unsigned char *)(p + 0x30) = 0xFF;
        *(unsigned char *)(p + 0x20) = 1;
        func_L00_002E54E0(1, 3000.0f);
    }
    if (*(unsigned char *)(p + 0x20) != 1)
        return;
    if (D_L00_001A8F00 == 2)
        return;

    v = *(float *)(p + 0x14);
    v = v - 1.6666667f;
    *(float *)(p + 0x14) = v;
    x = func_00282C48(v);

    a = 3000.0f - x;
    b = 750.0f - a;
    c = 1.0f - b * (1.0f / 750.0f);
    if (c > 3.0f)
        c = 3.0f;
    if (c < 0.0f)
        c = 0.0f;

    q = *(int **)(p + 0x24);
    *(float *)(p + 0x2C) = *(float *)((char *)q + 0x24) * c;
    if (*(float *)(p + 0x14) <= -3000.0f)
        *(float *)(p + 0x14) = 3000.0f;
}
