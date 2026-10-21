/* func_L20_004435A0 (492 bytes, level 20 only) -- NEAR MISS, not integrated.
   state: 488 bytes against retail's 492; the body matches instruction for instruction
   from the prologue to the copy, and the differences are the register allocation, one
   branch-likely and the two 128-bit addresses.
   check.py (20_yeedil), with the source below:
     0044364C  addiu $v0, $zero, -0x1  |  addiu $v1, $zero, -0x1
     0044367C  bnel  $v1, $v0, ...    |  bne   $v1, $v0, ...
     00443680  lq    $v0, 0x10($s2)  |  addiu $v1, $s1, 0x17E0
     0044368C  lq    $v0, 0x10($s2)  |  addiu $s3, $s2, 0x10
     00443694  sq    $v0, 0x0($s0)   |  sq    $v0, 0x0($v1)
   So: the retail keeps the source address of the 16-byte copy in a callee-saved register
   ($s3 = arg0+0x10) and the destination address in a caller-saved one ($v1), while this
   compiler folds the source address into the lq's displacement (0x10($s2)) and keeps the
   destination in $s0; the retail's branch at +0x7C is a plain bne with the destination
   address in the delay slot, ours is a branch-likely with a duplicated lq in the delay
   slot; and the -1 constant goes to $v1 in the retail and to $v0 here.

   What is measured and right:
   - the unit must be built with -G8: the function reaches D_L20_001B20B0 (the point,
     `addiu $a1, $gp, 0x30C0`) and D_L20_001B2164 (the rate, `lwc1 $f12, 0x3174($gp)`)
     through $gp.  In a -G0 unit the `sda` attribute does NOT give the gp-relative form
     (measured: the relocation comes out HI16/LO16), so the function needs its own
     -G8 file; the two globals are at 0x1B20B0 and 0x1B2164 (1.3f).
   - the float constants: 0.015f (0x3C75C28F) and 0.3f (0x3E99999A) for func_002AEC48.
   - the byte at p+0x20 must be read unsigned and the two compares against 0xFE and 0xFD
     must be two nested `if`s (a single `!=` pair is folded into a range check).
   - the 16-byte copy's destination must be a pointer variable (a plain `*(TI128 *)(s1 +
     0x17E0)` folds into the sq's displacement).
   Tried and not enough: the destination as char * / TI128 * / computed at the join /
     computed before the test; the source address through a char * / a TI128 * / assigned
     at the top of the function (that one materialises it in the prologue instead, one
     instruction over) / assigned at the copy site (that one folds it into the lq). */

#include "include_asm.h"

/* This unit is built with -G8: func_L20_004435A0 reaches two globals through $gp
   (a point and a constant). */

typedef int TI128 __attribute__((mode(TI)));

extern float func_00283CE0(int);

extern void func_L01_002F14E8(int, int, float);

extern void func_L20_00442890(char *);

extern void func_L20_004429F0(char *);

extern void func_002AEC48(void *, void *, int, float, float);

extern int func_00282948(void *);

extern void func_L20_00442F80(char *);

extern void func_00283098(void *, const void *, const void *);

extern void func_002833F0(char *, char *);

extern void func_00282CF0(void *, void *, void *);

extern void func_002A93B0(void *);

extern void func_002B0990(void *, void *, int, int, float);

/* The point the object's transform is measured from. */
extern float D_L20_001B20B0 __attribute__((sda));

/* The rate of the object's turn. */
extern float D_L20_001B2164 __attribute__((sda));

void func_L20_004435A0(char *arg0) {
    char *s2 = arg0;
    char *s1 = *(char **)(arg0 + 0x68);
    char *p;
    char *dst;
    char *src;
    TI128 v0, v1, v2;
    float f;
    unsigned short n;

    if (*(unsigned char *)(arg0 + 0x95) != 6) {
        func_L01_002F14E8(0xA, 0,
                         *(float *)(s1 + 0x20)
                         / func_00283CE0(*(short *)(s1 + 0x24)));
        func_L20_00442890(arg0);
        func_L20_004429F0(arg0);
    }
    func_002AEC48(arg0, s1 + 0x250, 0, 0.015f, 0.3f);
    if (*(int *)(s1 + 0x1810) > 0) {
        if (func_00282948(s1 + 0x1810) != 0) {
            func_L20_00442F80(arg0);
            *(int *)(s1 + 0x1810) = -1;
        }
    }
    p = *(char **)(s1 + 0x1850);
    if (p != 0) {
        if (*(short *)(p + 0xAA) != 0x1316) {
            *(int *)(s1 + 0x1850) = 0;
        } else {
            if (*(unsigned char *)(p + 0x20) != 0xFE) {
                if (*(unsigned char *)(p + 0x20) != 0xFD) {
                    goto copy;
                }
            }
            *(int *)(s1 + 0x1850) = 0;
        }
    }
    dst = s1 + 0x17E0;
copy:
    src = arg0 + 0x10;
    *(TI128 *)dst = *(TI128 *)src;
    f = *(float *)(s1 + 0x1800);
    if (f == 0.0f) {
        *(float *)(arg0 + 0xF0) = f;
        if (*(float *)(s1 + 0x1804) == 0.0f) {
            goto done;
        }
        *(float *)(arg0 + 0xF0) = f;
    }
    func_00283098(&v0, &D_L20_001B20B0, arg0 + 0xC0);
    *(float *)(arg0 + 0xF4) = *(float *)(s1 + 0x1804);
    func_002833F0(arg0 + 0xC0, arg0 + 0xF0);
    func_00283098(&v1, &D_L20_001B20B0, arg0 + 0xC0);
    func_00282CF0(&v2, &v1, &v0);
    func_00282CF0(src, src, &v2);
done:
    func_002A93B0(arg0);
    n = *(unsigned short *)(arg0 + 0x96);
    if (n <= 0xFFFE) {
        arg0[0xBD] = 2;
        *(unsigned short *)(arg0 + 0x96) = n + 1;
    }
    func_002B0990(arg0, s1 + 0x250, 0, 1, D_L20_001B2164);
}
