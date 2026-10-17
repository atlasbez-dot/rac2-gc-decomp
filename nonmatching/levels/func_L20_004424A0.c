/* 0 of 1 places match - last line: 20_yeedil: 168 bytes, expected 176
   Every call and both constant blocks are in retail's order: the angle helper takes 0.0f,
   0.0f and the arcsecond/arcminute words (0.000244140625-scale 4.84813745e-06f and
   0.000290888245f), the second helper takes the quad's 0x10 block with 0.5f, the shared
   0.000277777785f-scaled word goes into the state's 0x7C and 0xE0 floats, and 0xF8 is the
   helper of (0x7C + 0x7C) * D_L20_001B2128. Three residues, each measured: (1) `$s0`/`$s1`
   hold the object and the state the other way round; (2) the `*(f32*)(state + 0x7C)` term
   is CSE'd with the store this cc1 has just made (it uses the live value, retail reloads
   with `lwc1 $f12,0x7C($s0)` and pays `add.s $f12,$f12,$f12`); (3) the
   `*(TI128 *)(state + 0xF0) = 0` folds into `sq $zero,0xF0($s1)` where retail materialises
   `addiu $v0,$s0,0xF0` first - the func_L11_003973F8 wall. Computing the 0.000277777785f
   product before the second call instead of after it moves the product into $f20 and costs
   a slot in the frame. */
#include "common.h"

extern f32 D_L20_001B2128 __attribute__((sda));

extern f32 D_L20_001B212C __attribute__((sda));

extern f32 D_L20_001B2130 __attribute__((sda));

extern f32 D_L20_001B2138 __attribute__((sda));

extern void func_002B60B0(char *, f32, f32, f32, f32);

extern void func_002A89A8(void *, int, f32);

extern f32 func_00282C10(f32);

/* Re-aims the quad from the two shared angle words and seeds the state's 0x7C/0xE0/0xF0/
   0xF8 cluster. */
void func_L20_004424A0(char *arg0)
{
    char *state = *(char **)(arg0 + 0x68);
    f32 v;

    func_002B60B0(arg0, 0.0f, 0.0f, D_L20_001B212C * 4.84813745e-06f,
                  D_L20_001B2130 * 0.000290888245f);
    func_002A89A8(arg0 + 0x10, 0, 0.5f);
    v = D_L20_001B2138 * 0.000277777785f;
    *(f32 *)(state + 0x7C) = v;
    *(f32 *)(state + 0xE0) = v;
    *(TI128 *)(state + 0xF0) = 0;
    *(f32 *)(state + 0xF8) =
        func_00282C10((*(f32 *)(state + 0x7C) + *(f32 *)(state + 0x7C)) *
                      D_L20_001B2128);
}
