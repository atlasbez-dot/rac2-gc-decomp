#include "include_asm.h"

/* func_00308408 - 448 bytes, 28 places (the boot and every level).
   SpawnShockwaveRingMoby (symbol_addrs/usa/symbol_addrs.txt: SpawnShockwaveRingMoby =
   0x00308408).  Compiled with -frac2-qcopy this source is retail's exact 448 bytes and
   every instruction of the body matches except three; the prologue differs in four
   instructions (the allocator's choice between $s7 and $fp for the first two
   arguments).

   What the retail bytes say about the source:

     * the function creates a moby of type 0x70 (func_0029EFD0(0x70)) and returns it
       (the early exit branches to the same `daddu $v0,$s1,$zero` as the normal end,
       so the source returns the moby and the null case falls into the same return);
     * the frame is 0xA0: 0x00 a 16-byte staging area, 0x10 the four random floats,
       0x20 the spill of the third argument, 0x30..0x7F the register saves and
       0x80/0x88/0x90 the three float saves;
     * `por $v0,$zero,$zero` + `sq $v0,0x10($sp)` is the 16-byte clear of the float
       block (a TImode store of zero at a non-zero displacement keeps its por), and
       the three `swc1 $f0` are the three draws of func_002A7878(-pi, pi);
     * the staging area is filled with `lq $v0,0x10($sp); sq $v0,0x0($sp)` (the float
       block copied to the staging area) and later read with `lq $v0,0x0($sp)` for the
       copy to moby+0xF0; a `char tmp[16]` local plus a `float dir[4]` local gives
       exactly that pair of copies, in that order;
     * the two copies into the moby are the materialised form (`addiu $v1,$s1,0x10`
       then `sq $v0,0x0($v1)`, and the same for +0xF0), which is what
       -frac2-qcopy produces; without the flag the offsets fold into the sq and the
       function is twelve bytes short;
     * the arguments are (float scale, void *parent, void *pos, void *childpos,
       int index, u8 r, u8 g, u8 b, u8 a): the float arrives in $f12 (copied to
       $f22), the four byte arguments are masked with 0xFF, the third argument is
       the one that is spilled to 0x20($sp) and reloaded for the copy into the child,
       and the first argument is the 32-bit pointer stored at child+0x10;
     * the child's own float at +0x18 is moby+0x2C times the scale, and moby+0x2C is
       then set to the distance formula
       func_00283CE0(index - (short)(child->[0x14] - 4)) * child->[0x18]
       / func_00283CE0(child->[0x14]).

   What is still open (measured, not guessed):

     1. The prologue: retail puts the first argument in $s7 and the second in $fp
        (both assigned before the four byte arguments), this cc1 puts the first in
        $fp and the second in $s7.  The order of assignment is the same, only the
        register choice differs, and it is very sensitive: declaring the first
        argument as a 64-bit value gives retail's exact prologue (the same $s7/$fp
        choice) but then the 32-bit store of it costs two extra instructions
        (`dsll32`/`dsra32`, the sign extension this target's 32-bit convention
        needs), so the function comes out eight bytes too long.  A 32-bit first
        argument and a 64-bit one are the two ends of the lever, and the retail
        bytes are between them.
     2. The first staging copy: retail reads the float block with
        `lq $v0,0x10($sp)` (the displacement folded in), while -frac2-qcopy
        materialises the address (`addiu $v1,$sp,0x10; lq $v0,0x0($v1)`) because the
        pattern selects every aligned TImode memory assignment.  The retail shape is
        what the pattern gives when the source address has no displacement, so the
        float block would have to sit at offset 0 of its own object - which the
        zero store at 0x10($sp) forbids.
     3. The `div.s` at the end: retail has one `nop` in front of it, this cc1 none.
        The nop is the SDK 3.01 assembler's padding of a division fewer than two
        instructions after the last label, so it needs the division to start a basic
        block; -g instead gives two nops (one too many).

   Measured with: python3 work/w4check.py func_00308408 -frac2-qcopy --diff
   ("boot: instruction at +0x4 differs", 448 bytes, expected 448).
*/

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;
typedef int TI __attribute__((mode(TI)));

extern char *func_0029EFD0(s32);
extern float func_002A7878(float low, float high);
extern void func_002A0488(void *moby, u8 r, u8 g, u8 b);
extern float func_00283CE0(s32 value);
extern void func_002A0F48(void *moby);

char *func_00308408(f32 scale, char *parent, char *pos, char *childpos, s32 index, u8 r, u8 g, u8 b, u8 a)
{
    char *moby;
    char *child;
    char tmp[16];
    float dir[4];

    moby = func_0029EFD0(0x70);
    if (moby != 0) {
        child = *(char **)(moby + 0x68);
        *(TI *)dir = 0;
        dir[0] = func_002A7878(-3.1415927f, 3.1415927f);
        dir[1] = func_002A7878(-3.1415927f, 3.1415927f);
        dir[2] = func_002A7878(-3.1415927f, 3.1415927f);
        *(TI *)tmp = *(TI *)dir;
        *(u8 *)(moby + 0x20) = 0;
        *(u8 *)(moby + 0x23) = a;
        *(u8 *)(moby + 0x31) = 1;
        *(u8 *)(moby + 0x30) = 0xFF;
        *(u16 *)(moby + 0x32) = 0xFF;
        func_002A0488(moby, r, g, b);
        *(f32 *)(child + 0x18) = *(f32 *)(moby + 0x2C) * scale;
        *(s32 *)(moby + 0x2C) = 0;
        *(TI *)(moby + 0x10) = *(TI *)pos;
        *(TI *)child = *(TI *)childpos;
        *(TI *)(moby + 0xF0) = *(TI *)tmp;
        *(char **)(child + 0x10) = parent;
        *(s32 *)(child + 0x14) = index;
        *(u16 *)(child + 0x1C) = *(u16 *)(child + 0x14) - 4;
        *(f32 *)(moby + 0x2C) = func_00283CE0(index - (short)(*(u16 *)(child + 0x14) - 4))
                * *(f32 *)(child + 0x18) / func_00283CE0(*(s32 *)(child + 0x14));
        *(u16 *)(child + 0x1E) = a;
        func_002A0F48(moby);
    }
    return moby;
}
