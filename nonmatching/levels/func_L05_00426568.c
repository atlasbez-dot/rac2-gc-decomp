/* Near miss from src/levels/shared/L05_00426568-g8.c: 228 bytes, expected 236; 0 of 4 places.
   Kept as a starting point; not linked, not counted.

   The source unit needs -G8 (the level's cached pointer is reached through $gp) and
   -frac2-qcopy (the 16-byte copy keeps both addresses in registers). The flags of
   L05_003D33E8-g8.c do not give the copy that shape, so the candidate needs a
   -g8.c source unit of its own, as the draft below assumes.

   What still differs against retail (level 05 at 0x00426568):
   - the three flag stores come out in retail's order (sh 0x32, sb 0x30, sb 0x31) but the
     constants are hoisted above them here, where retail materialises the second 0xFF and
     the 1 between the stores;
   - retail keeps the 0xFBF of the list walk in a register (addiu $a1,$zero,0xFBF in the
     delay slot of the list test, then xor $v0,$v0,$a1), here the comparison is an
     xori with the immediate; a local, a parameter and a loop-local copy of the tag all
     fold back to the immediate;
   - retail's loop has one more nop (the load delay of the lh) and one more instruction
     (the addiu of the 0xFBF), so this body is 8 bytes short.

   The level's cached pointer has to be named D_L05_001B1500 (with __attribute__((sda)))
   and the level's list D_L05_001B2528 (with __attribute__((nosda))): with ref_ names for
   them the $gp-relative access comes out with a zero offset (lw $v0,0x0($gp)) instead of
   the retail's 0x2510, and without nosda the list lands in the small data section of the
   -G8 unit and is reached through $gp as well. The calls go to the boot's functions by
   their catalogue names; the level's own function_L05_00426810 has one place in every
   level that has this one, so it keeps its name.

   The same family is recorded for func_L05_00425FE0, whose candidate has the same
   0xFBF comparison and the same flag stores. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef int TI128 __attribute__((mode(TI)));

extern int func_0029EFD0(int);

extern void func_00282C88(TI128 *);

extern float func_002A7940(void);

extern void func_L05_00426810(char *);

extern int D_L05_001B1500 __attribute__((sda));

extern int D_L05_001B2528 __attribute__((nosda));

char *func_L05_00426568(char *object)
{
    char *obj = (char *)func_0029EFD0(0x117D);
    char *node;
    char *found;
    float half;
    float f;
    int cached;

    if (obj != 0) {
        *(u8 *)(obj + 0x30) = 0xFF;
        *(u16 *)(obj + 0x32) = 0xFF;
        *(u8 *)(obj + 0x31) = 1;
        *(TI128 *)(obj + 0x10) = *(TI128 *)(object + 0x10);
        func_00282C88((TI128 *)(obj + 0xF0));
        f = func_002A7940();
        half = *(float *)(obj + 0x2C) * 0.5f;
        cached = D_L05_001B1500;
        *(float *)(obj + 0xF8) = f;
        if (cached == 0) {
            *(float *)(obj + 0x2C) = half;
            node = (char *)D_L05_001B2528;
            if (node != 0) {
                found = 0;
                do {
                    if (*(s16 *)(node + 0xAA) == 0xFBF)
                        found = node;
                    node = *(s32 *)(node + 0x28);
                } while (node != 0);
                D_L05_001B1500 = (int)found;
            }
        }
        func_L05_00426810(obj);
        *(float *)(obj + 0x2C) = *(float *)(*(s32 *)(obj + 0x24) + 0x24);
        return obj;
    }
    return 0;
}
