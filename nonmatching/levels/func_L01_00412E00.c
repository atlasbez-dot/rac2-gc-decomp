/* func_L01_00412E00 (280 bytes, 1 place, level 01, profile -O2 -G8, needs a -g8.c unit)
   -- not matched: the retail body reads the same word two ways, which no single
   declaration produces (see below).  The structure below is what the retail
   bytes say; the attempt is a first pass and does not match.

   The body's shape, read off the retail instructions:

     v  = a0->f20;                     [ lbu $v1,0x20($s0)  ]
     st = *(u32 **)(a0 + 0x68);        [ lw  $s1,0x68($s0)  ]
     if (v == 1) {                     [ beq $v1,$v0(=1)     ]
         r = func_312B68(a0, 0x401000, 0);
         if (r == 0)            { a0->fA8 = 0xFF;  goto out; }
         if (*st != 0)          { a0->fA8 = *st;   goto out; }
         c = D_L01_001AEC38;            [ absolute load     ]
         c = c - 1;
         D_L01_001AEC38 = c;
         func_310418(a0, 2, -1);
         a0->fA8 = 0xFF;
         goto out;
     }
     if (v >= 2) {
         if (v == 2) goto d;
         a0->fA8 = 0xFFFF;             [ ori $v0,$zero,0xFFFF ]
         goto out;
     }
     if (v == 0) {
         c = D_L01_001AEC38;
         c = c + 1;
         D_L01_001AEC38 = c;
         func_310418(a0, 1, -1);
         goto out;
     }
     c = D_L01_001AEC38;                [ dead              ]
   out:
     ...
   d:
     func_31FDF0(a0, &D_L01_001B1960, &D_L01_001B1958, &D_L01_001B1950,
                 2, 0xFF, 0, 0xFFFF, 0, -1, 0);
     func_306250(a0);

   Why this one is hard: the word at D_L01_001AEC38 is read twice and written
   twice, and retail uses two different addressings for it - `lw $v0,-0x3B8($gp)`
   and `sw $v0,-0x3B8($gp)` in three places, and `lui $v0,0x1B; lw $v0,-0x13C8($v0)`
   in the fourth.  Under -G0 a small-data variable is only addressed $gp-relative
   when its value is used directly; a value that goes into an expression comes
   out as lui+lw.  Under -G8 every access to it is $gp-relative.  So no single
   declaration gives both forms, and the two accesses cannot be two variables:
   0x1AEFF0 - 0x3B8 and 0x1B0000 - 0x13C8 are the same address, 0x1AEC38.
   The three addresses handed to func_31FDF0 ($gp+0x2970, +0x2968, +0x2960)
   are $gp-relative too, which also wants -G8.

   The retail prologue is odd as well: `addiu $sp,$sp,0x10; nop` before
   `addiu $sp,$sp,-0x40`, and the epilogue gives back only 0x40, so the
   function leaves the stack 0x10 bytes higher than it found it.  The first
   eight bytes of the catalogue extent may belong to the previous function
   (the words before it are `jr $ra; nop`), which would make this extent a
   fragment; that is worth checking in tools/levels.py before more attempts.

   Nothing here is a match: the attempt below is a first pass at the shape
   above.  */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern u32 D_L01_001AEC38 __attribute__((sda));
extern u32 D_L01_001B1960 __attribute__((sda));
extern u32 D_L01_001B1958 __attribute__((sda));
extern u32 D_L01_001B1950 __attribute__((sda));
extern s32 func_312B68(void *a0, u32 a1, s32 a2);
extern void func_310418(void *a0, s32 a1, s32 a2);
extern void func_31FDF0(void *a0, void *a1, void *a2, void *a3, s32 a4, s32 a5,
                        s32 a6, s32 a7, s32 a8, s32 a9, s32 a10);
extern void func_306250(void *a0);

void func_L01_00412E00(u8 *a0)
{
    u32 *st;
    u32 v;
    u32 c;

    v = a0[0x20];
    st = *(u32 **)(a0 + 0x68);
    if (v == 1) {
        s32 r = func_312B68(a0, 0x401000, 0);

        if (r == 0) {
            a0[0xA8] = 0xFF;
            return;
        }
        v = *st;
        if (v != 0) {
            a0[0xA8] = (u8)v;
            return;
        }
        c = D_L01_001AEC38 - 1;
        D_L01_001AEC38 = c;
        func_310418(a0, 2, -1);
        a0[0xA8] = 0xFF;
        return;
    }
    if (v >= 2) {
        if (v == 2) {
            func_31FDF0(a0, &D_L01_001B1960, &D_L01_001B1958, &D_L01_001B1950,
                        2, 0xFF, 0, 0xFFFF, 0, -1, 0);
            func_306250(a0);
            return;
        }
        a0[0xA8] = 0xFF;
        return;
    }
    if (v == 0) {
        c = D_L01_001AEC38 + 1;
        D_L01_001AEC38 = c;
        func_310418(a0, 1, -1);
        return;
    }
    c = D_L01_001AEC38;
    a0[0xA8] = (u8)c;
}
