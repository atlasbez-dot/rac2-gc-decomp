/* func_003285C0 (USA v1.01 boot, 268 bytes, 28 places): the same construction as func_00329CB8 for
   the 0xBD7 object.

   Near miss: the size is exact and 0 of 28 places match. tools/check.py --version us reports the
   first difference at +0x4C, again only in which callee-saved register holds each float literal:
   retail loads 180.0f into $f21 and 360.0f into $f22, this C loads 180.0f into $f22 and 360.0f
   into $f21; the two `lui $at/mtc1` pairs consequently move before `sw $s2,0x40($s0)` and the
   `sb $v0,0x30($s1)` / `sh $v0,0x32($s1)` pair comes out in the other order. Same measured wordings
   as func_00329CB8: variable forms are rematerialised into $f12/$f13 and shrink the frame to 0x40,
   literal forms keep the frame at 0x50 and the exact size but always swap the two registers.
   The 16-byte copies need `-frac2-qcopy` for `src/game/00327038.c`. Unblocking needs a compiler
   mode or approved flag profile that allocates the two literal-argument pseudos the other way
   round, or another source wording; the C below is otherwise final. */
typedef int V4_Fc936841d __attribute__((mode(TI)));

extern char *func_0029EFD0(int);
extern float func_002A78D8(float, float);
extern void func_002A0F48(void *);

char *func_003285C0(int id, void *data, void *source)
{
    char *self = func_0029EFD0(0xBD7);
    char *state;
    int flags;

    if (self != 0) {
        state = *(char **)(self + 0x68);
        *(int *)(state + 0x40) = id;
        *(V4_Fc936841d *)(self + 0x10) = *(V4_Fc936841d *)data;
        *(V4_Fc936841d *)state = *(V4_Fc936841d *)source;
        *(int *)(state + 0x10) = 0;
        *(float *)(state + 0x14) = func_002A78D8(180.0f, 360.0f) * 0.00029088825f;
        *(float *)(state + 0x18) = func_002A78D8(180.0f, 360.0f) * 0.00029088825f;
        flags = 0xFF;
        *(unsigned char *)(self + 0x30) = flags;
        *(unsigned short *)(self + 0x32) = flags;
        *(float *)(self + 0x2C) *= 0.5f;
        *(unsigned char *)(self + 0x20) = 0;
        *(int *)(state + 0x5C) = 0x1E;
        func_002A0F48(self);
    }
    return self;
}
