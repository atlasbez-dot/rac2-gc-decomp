/* func_00329CB8 (USA v1.01 boot, 260 bytes, 28 places): builds the 0xBD8 object's state from a
   caller id and two 16-byte vectors.

   Near miss: the size is exact and 0 of 28 places match. tools/check.py --version us reports the
   first difference at +0x4C and only in how the two float literals are materialised: retail loads
   180.0f into $f21 and 360.0f into $f22 (then $f12/$f13 from them and 0.00029088825f into $f20),
   this C loads 180.0f into $f22 and 360.0f into $f21. That swap moves the two `lui $at/mtc1` pairs
   before `sw $s2,0x30($s0)` and also reorders the `sb $v0,0x30($s1)` / `sh $v0,0x32($s1)` pair.
   Six wordings were measured (early `return 0`, one 0xFF local, two 0xFF literals, `float low/high`
   variables, and mixes of literals and variables): the variable forms are rematerialised into
   $f12/$f13 and shrink the frame to 0x40, the literal forms keep the frame at 0x50 and the size at
   260 but always produce the swapped constant registers.
   The 16-byte copies need `-frac2-qcopy` for `src/game/00327038.c`. Unblocking this needs a
   compiler mode or an approved flag profile that assigns the two literal-argument pseudos the
   other way round, or another source wording for the two calls; the C below is otherwise final. */
typedef int V4_Fc936841d __attribute__((mode(TI)));

extern char *func_0029EFD0(int);
extern float func_002A7878(float, float);
extern void func_002A0F48(void *);

char *func_00329CB8(int id, void *data, void *source)
{
    char *self = func_0029EFD0(0xBD8);
    char *state;
    int flags;

    if (self != 0) {
        state = *(char **)(self + 0x68);
        *(int *)(state + 0x30) = id;
        *(V4_Fc936841d *)(self + 0x10) = *(V4_Fc936841d *)data;
        *(V4_Fc936841d *)state = *(V4_Fc936841d *)source;
        *(int *)(state + 0x10) = 0;
        *(float *)(state + 0x14) = func_002A7878(180.0f, 360.0f) * 0.00029088825f;
        *(float *)(state + 0x18) = func_002A7878(180.0f, 360.0f) * 0.00029088825f;
        *(unsigned char *)(self + 0x20) = 0;
        flags = 0xFF;
        *(unsigned char *)(self + 0x30) = flags;
        *(unsigned short *)(self + 0x32) = flags;
        *(float *)(self + 0x2C) *= 0.5f;
        func_002A0F48(self);
    }
    return self;
}
