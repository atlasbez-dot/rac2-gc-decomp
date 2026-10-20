#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern char *D_L20_001FBB20[];

extern char *D_L20_001B2F9C __attribute__((sda));

extern int D_L20_001B2FB8;

extern void func_0029F338(int);

extern void func_L09_003F73E8(char *);

extern void func_L09_003F77D0(char *);

/* Near miss from src/levels/20_yeedil/L20_0039C448.c: 336 bytes; 328-byte candidate; 0/1.
    The walk, the three calls, the frame (0x50) and the globals are all right; two
    instructions are missing and the register allocation differs:
      - retail keeps `index & 0xFF` in a temporary for the first test and copies it to $s4
        only later (`andi $a1,$s2,0xFF; beq $a1,$a0; ...; daddu $s4,$a1,$zero`), this cc1
        copies it to $s4 at once (`andi $s4,$s2,0xFF; beq $s4,$a0`).  Two C names for the
        value do not change it.
      - retail's loop back-edges are the branch-likely forms with the reload of the record
        word in the delay slot (`bgezl $v0,.L00409508 / lhu $v0,0($s1)` and
        `beql $s1,$v0,.L00409508 / lhu $v0,0($s1)`), this cc1 keeps the word in $v1 across
        the loop and uses plain `bgez`/`beq`, so it is two instructions shorter.
    The `u16 **tbl` spelling of the table element is what puts the address of the element in
    a callee-saved register ($s3), as retail has it; a plain `D_L20_001FBB20[index]` leaves it
    in $a1, which the calls clobber. */
void func_L20_00409480(s32 index) {
    u16 **tbl = &D_L20_001FBB20[index];
    u16 *rec = (u16 *)*tbl;
    s32 x = index & 0xFF;
    char *p;
    u16 w;

    if (x == 0xFF) {
        return;
    }
    if (D_L20_001B2FB8 < index) {
        return;
    }
    if (rec == 0) {
        return;
    }
    w = *rec;
    do {
        p = D_L20_001B2F9C + ((w & 0x7FFF) << 8);
        if (p == 0) {
            break;
        }
        if (*(s16 *)(p + 0xAA) == 0xD0F && *(u8 *)(p + 0x20) != 0xFE && *(u8 *)(p + 0x20) != 0xFD) {
            *(u8 *)(*(int *)(p + 0x68) + 0x20) = 0;
            func_L09_003F73E8(p);
            func_L09_003F77D0(p);
            func_0029F338((int)p);
        }
        if (x == 0xFF) {
            break;
        }
        rec++;
        if (D_L20_001B2FB8 < index) {
            break;
        }
        if (rec == 0) {
            break;
        }
        w = *rec;
    } while (*(s16 *)(rec - 1) >= 0 || rec == (u16 *)*tbl);
}
