/* func_L04_003A1868, 384 bytes, 5 placements (levels 04, 06, 08, 18, 20).
   G8 candidate is 376 bytes: the body is recovered - the seven lighting floats
   the level's globals take (16.0f, -8.0f, 1.0f, 0.9f, 16.0f, -8.0f, 1.0f, 0.1f),
   the engine's func_00283248 with the level's table of two floats, the two
   func_00283180/func_00283198 calls scaled by 1/sqrt(3) (0.57735f), the three
   words the level keeps (63, 64 and the 127 flag byte), the three pointers and
   the four small-data globals.  The frame, the register roles ($f20 and $f21
   across the calls, $s0/$s1/$s2 for the three arguments) and the order of the
   stores match retail.

   Two residues: the globals at 0x1AD860 and 0x1AD870 come out reached through
   $gp here (one instruction each) where retail reaches them by their %hi/%lo
   address (two instructions each), which is the eight bytes the candidate is
   short; and the small-data store of 16.0f (0x1AD840) is scheduled first here
   where retail keeps it fifth.  Needs the -G8 unit: the five globals at
   0x1AD808, 0x1AD80C, 0x1AD810, 0x1AD814 and 0x1AD840 are reached through
   $gp in retail, and the rest by their absolute address.
*/
#include "include_asm.h"

typedef int s32;

typedef unsigned int u32;

typedef unsigned char u8;

typedef float f32;

/* the level's table of two floats */
typedef struct {
    u8  pad00[0x10];
    f32 field10;
    f32 field14;
} L04Table;

/* the globals the level's lighting reads; the small-data ones are reached
   through $gp, the others by their absolute address */
extern L04Table ref_L04_003A1868_00;

extern f32 ref_L04_003A1868_01;
extern f32 ref_L04_003A1868_02;
extern f32 ref_L04_003A1868_03;
extern f32 ref_L04_003A1868_04;
extern f32 ref_L04_003A1868_05 __attribute__((sda));
extern f32 ref_L04_003A1868_06;
extern f32 ref_L04_003A1868_07;
extern f32 ref_L04_003A1868_08;
extern f32 ref_L04_003A1868_09;
extern f32 ref_L04_003A1868_10;
extern f32 ref_L04_003A1868_11;
extern u32 ref_L04_003A1868_12;
extern u32 ref_L04_003A1868_13;
extern u8  ref_L04_003A1868_14;
extern f32 ref_L04_003A1868_15 __attribute__((sda));
extern f32 ref_L04_003A1868_16 __attribute__((sda));
extern f32 ref_L04_003A1868_17 __attribute__((sda));
extern u8  ref_L04_003A1868_18;
extern u32 ref_L04_003A1868_19 __attribute__((sda));
extern u32 ref_L04_003A1868_20;
extern u32 ref_L04_003A1868_21;
extern u32 ref_L04_003A1868_22;

extern f32 func_00283248(f32 a, f32 b);
extern f32 func_00283180(f32 a);
extern f32 func_00283198(f32 a);

/* Fills the level's lighting globals: the engine's helpers give the light's
   direction, the two of them are scaled by 1/sqrt(3). */
void func_L04_003A1868(void *a0, void *a1, void *a2) {
    f32 base;
    f32 scale;

    ref_L04_003A1868_01 = 16.0f;
    ref_L04_003A1868_02 = -8.0f;
    ref_L04_003A1868_03 = 1.0f;
    ref_L04_003A1868_04 = 0.9f;
    ref_L04_003A1868_05 = 16.0f;
    ref_L04_003A1868_06 = -8.0f;
    ref_L04_003A1868_07 = 1.0f;
    ref_L04_003A1868_08 = 0.1f;
    base = func_00283248(ref_L04_003A1868_00.field10, ref_L04_003A1868_00.field14);
    scale = 0.57735f;
    ref_L04_003A1868_09 = func_00283180(base) * scale;
    ref_L04_003A1868_10 = func_00283198(base) * scale;
    ref_L04_003A1868_11 = -0.57735f;
    ref_L04_003A1868_12 = 63;
    ref_L04_003A1868_13 = 64;
    ref_L04_003A1868_14 = 127;
    ref_L04_003A1868_15 = 32768.0f;
    ref_L04_003A1868_16 = 255.0f;
    ref_L04_003A1868_17 = 48.0f;
    ref_L04_003A1868_18 = 127;
    ref_L04_003A1868_19 = 0;
    ref_L04_003A1868_20 = (u32)a0;
    ref_L04_003A1868_21 = (u32)a1;
    ref_L04_003A1868_22 = (u32)a2;
}
