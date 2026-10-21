/* Near miss from src/levels/12_todano/L12_002CF7B0.c: the build refuses this body at its
   place — 100 bytes, expected 108. Kept as a starting point;
   not linked, not counted. */

/* Standalone declarations recovered from src/levels/12_todano/L12_002CF7B0.c. */
extern char *D_L12_001BDB00;

extern float D_L12_001AD230;

extern float D_L12_001AD234;

void func_L12_00300138(void)
{
    char *p = D_L12_001BDB00;

    if (*(int *)(p + 0x58) != 0) {
        D_L12_001AD230 = 0.1f;
        D_L12_001AD234 = 0.02f;
        return;
    }
    if ((unsigned int)(*(int *)(p + 0x30) - 3) < 2) {
        D_L12_001AD230 = 0.0f;
        D_L12_001AD234 = 0.0f;
    }
}

/* --- wave 24, worker 04 (2026-10-21) --------------------------------------------
   Re-measured: 100 bytes, 23 of 27 words identical; the two differences are that
   ours moves the second float store into the delay slot of the `jr $ra` (where
   it then takes the $gp-relative form and needs no register) while retail keeps
   it in the block, and that retail materialises D_1BDB00 with
   `lui %hi ; addiu %lo` where ours keeps the plus-form.
   What I added to the measurements:
   - D_1BDB00 has to be read as an ARRAY, not through the file's pointer
     declaration: retail's code is `lui %hi(D_1BDB00) ; addiu %lo(D_1BDB00) ;
     lw 0x58($v0)`, so the source reads the symbol's own address.
   - the two float globals are written through a bare symbol (retail's
     `lui $at,%hi ; swc1 %lo($at)`), which is what __attribute__((sda)) gives in
     a -G0 unit; without it the store takes a normal register.
   - 0x3DCCCCCD is 0.1f and 0x3CA3D70A is 0.02f.
   - the state test written as `x == 3 || x == 4` is what gives retail's sltiu
     pair; `(unsigned)(x-3) < 2` gives the same.
   Last check.py line: "12_todano: 100 bytes, expected 108". */
