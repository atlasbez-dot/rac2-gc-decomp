/* Near miss from src/levels/20_yeedil/L20_00449178-g8.c: 296 bytes, retail 308.
   The attempt belongs in the -G8 unit (the body reaches D_L20_001B23F8
   through $gp).

   Two differences:
   * the 128-bit copy into the object: retail materialises the destination
         addiu $v1, $s1, 0x10 ; lq $v0, 0x0($s2) ; sq $v0, 0x0($v1)
     while this cc1 folds the offset into the store
         sq $v0, 0x10($s1)
     (the second copy, into state, has plain-register addresses on both sides
     and matches exactly);
   * the two float arguments land in the callee-saved FPRs the other way
     round: the retail has $f21 = the first float and $f20 = the second, this
     cc1 has $f21 = the second and $f20 = the first.  The frame, the FPR
     saves and the restores are the retail's.

   Measured this wave (2026-10-20): the func_0029EFD0(0x12EE) call, the
   null test, the func_002B37E8 call, the two func_002A7940 calls (each
   result stored, at obj+0xF0 and obj+0xF4), the func_002833F0 call, the
   0x100 flag, the D_L20_001B23F8 multiply, the state stores, the
   func_002A7878(10.0f, 20.0f) call and the 1/3600 multiply are all the
   retail instructions.  The    float constants: 0.016666668f (1/60,
   0x3C888889) and 0.00027777778f (1/3600, 0x3991A2B4); the last product
   multiplies the RESULT of func_002A7878, not the earlier f12/60.

   History: an earlier attempt in this file was 300 bytes; it had the fourth
   argument as an int, the second and third as void *, and called
   func_002A7878 with (20.0f, 20.0f) - the retail passes 10.0f in f12 and
   20.0f in f13. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));

extern float D_L20_001B23F8 __attribute__((sda));

extern void *func_0029EFD0(int);
extern void func_002B37E8(u8 *, u8 *);
extern float func_002A7940(void);
extern void func_002833F0(void *, void *);
extern float func_002A7878(float a, float b);

void func_L20_00449FD0(char *arg0, char *arg1, char *arg2, char *arg3, float f12,
                        float f13) {
    char *obj;
    char *state;

    obj = func_0029EFD0(0x12EE);
    if (obj != 0) {
        func_002B37E8((u8 *)obj, (u8 *)arg0);
        *(TI128 *)(obj + 0x10) = *(TI128 *)arg1;
        *(float *)(obj + 0xF0) = func_002A7940();
        *(float *)(obj + 0xF4) = func_002A7940();
        func_002833F0(obj + 0xC0, obj + 0xF0);
        *(u8 *)(obj + 0x20) = 1;
        *(u16 *)(obj + 0x34) |= 0x100;
        *(float *)(obj + 0x2C) =
            *(float *)(*(u32 *)(obj + 0x24) + 0x24) * D_L20_001B23F8;
        state = *(char **)(obj + 0x68);
        *(TI128 *)state = *(TI128 *)arg2;
        *(int *)(state + 0x18) = (int)arg3;
        *(float *)(state + 0x1C) = f13;
        *(float *)(state + 0x14) = f12 * 0.016666668f;
        *(int *)(state + 0x20) = 0x3C;
        *(float *)(state + 0x10) =
            func_002A7878(10.0f, 20.0f) * 0.00027777778f;
    }
}
