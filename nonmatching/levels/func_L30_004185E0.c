/* 0 of 1 places match - last line: 30_insomniac_museum: 144 bytes, expected 140
   Refreshes the owner's 0x50 object: run the two vector helpers on its 0x10 block
   (func_2F5130(local, 0x004005BC, D_L30_001B2100) - the float argument comes from
   $gp - then func_2F4E68(local, local, 0x004005BC - 0x230)), call the object's
   0x64 method with the object when it is set, then func_3194F0 on the object.
   Retail keeps the 0x004005BC base in $s0 across both calls and derives the second
   constant as `addiu $a2,$s0,-0x230`, i.e. one symbol with a negative index, and
   saves s0-s3 + $ra in a 0x30 frame. Measured: the one-base form (below) and the
   two-explicit-locals form both give 144 bytes with a 0x30 frame; the plain form
   with the second constant written as its own address gives 136 bytes and a 0x20
   frame. Blocker: the last four bytes of the frame/schedule. */
typedef char *ptr;
typedef int s32;
typedef float f32;

extern void func_00282F20(char *, char *, f32);
extern void func_00282CC0(char *, char *, char *);
extern void func_002A0F48(void *);
extern char D_L30_004005BC[];
extern f32 D_L30_001B2100 __attribute__((sda));

void func_L30_004185E0(char *a0)
{
    char *s3 = *(char **)(a0 + 0x68);
    char *s2 = *(char **)(s3 + 0x50);
    char *s1 = s2 + 0x10;

    func_00282F20(s1, D_L30_004005BC, D_L30_001B2100);
    func_00282CC0(s1, s1, D_L30_004005BC - 0x230);
    if (*(s32 *)(s2 + 0x64) != 0)
        (*(void (**)(char *))(*(char **)(s3 + 0x50) + 0x64))(s2);
    func_002A0F48(*(void **)(s3 + 0x50));
}

/* Wave 24 (worker 09) -- NEAR MISS, 148 bytes against 140: everything is
   instruction-exact except the last two instructions, and the body needs a -G8
   unit.

   The body needs a -G8 unit: retail reads a float global $gp-relative
   (lwc1 $f12, 0x3110($gp), the global at 0x1B2100) and this cc1 only emits
   the $gp-relative form for a small-data global in a -G8 unit; in a -G0 unit
   the `sda' attribute is ignored and the address is materialised
   (lui $at ; lwc1 $f0, 0($at)).  In a -g8.c unit the load lands in $f12 as
   retail has it, provided the float is passed to a call (it is the first float
   argument of func_00282F20) - as a dead local it lands in $f0 instead.

   The draft below is the wave-24 one: it reproduces the frame (0x30), the four
   saved registers, the %hi/%lo pair of D_L30_001B9FF0 in $s0, the $gp-relative
   float load in $f12 and both calls.  What is left is the layout of the last
   if: retail puts the else block (the call to func_002A0F48) right behind the
   then block (the indirect call), so the then block needs no jump over it,
   while this cc1 pushes the else block behind the epilogue and emits a dead
   `b' plus a dead `ld $s0' in its place (the 8 bytes).  Writing the test the
   other way round (if (... == 0) call else indirect) gives the retail's block
   order but a bnel instead of the retail's beqz, and is also 144 bytes.

   -mno-split-addresses was measured on the -G8 unit too: it moves the %hi/%lo
   pair of D_L30_001B9FF0 into $s1 instead of $s0, so the default (split) is
   the right profile here.

   Checked with: python3 tools/check.py func_L30_004185E0 --diff
   Last line: func_L30_004185E0: 0 of 1 places match (src/levels/30_insomniac_museum/L30_004185E0-g8.c) */
typedef int s32;
typedef float f32;

extern void func_00282F20(char *, char *, f32);

extern void func_00282CC0(char *, char *, char *);

extern void func_002A0F48(void *);

extern char D_L30_001B9FF0[];

extern f32 D_L30_001B2100 __attribute__((sda));

void func_L30_004185E0_w24(char *a0)
{
    char *s3 = *(char **)(a0 + 0x68);
    char *s2 = *(char **)(s3 + 0x50);
    char *s1 = s2 + 0x10;

    func_00282F20(s1, D_L30_001B9FF0, D_L30_001B2100);
    func_00282CC0(s1, s1, D_L30_001B9FF0 - 0x230);
    if (*(s32 *)(s2 + 0x64) != 0) {
        (*(void (**)(char *))(*(char **)(s3 + 0x50) + 0x64))(s2);
    } else {
        func_002A0F48(*(void **)(s3 + 0x50));
    }
}
