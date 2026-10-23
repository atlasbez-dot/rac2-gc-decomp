/* func_L09_003FE4D0 (332 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 324 bytes, 8 under retail's 332 with the file's measured profile
   (-O2 -G0 -ffunction-sections -frac2-qcopy); the loop body and the prologue's save
   order are retail's, the prologue's address materialisation is not.
   check.py (09_dobbo), with the source below:
     09_dobbo: 324 bytes, expected 332
   The body matches instruction for instruction from `lh $v0,0xB2($s0)` to the loop's
   `bnel`: retail's `addiu $v1,$s0,0x10; lq $v0,0($v1); sq $v0,0($sp)` is this cc1's
   `lq $v0,0($a0); sq $v0,0($sp)` with the same shape, and the `sw $v0,0($s3)` /
   `addiu $s3,$s3,0x4` pair is the table pointer advancing.
   What is left is the head: retail materialises the table's address as
   `lui $v0,0x25; addiu $v0,$v0,0x7110; addiu $v0,$v0,0x4C` (the base, then +0x4C for
   the last entry), this cc1 folds the +0x4C into the %lo addend
   (`lui $v0,0x0; addiu $v0,$v0,0x4C`) and hoists the %hi into $s6, which also changes
   the save order and swaps the $s3/$s6/$s7 roles of the base pointer, its copy and the
   -1 constant.

   What is measured and right:
   - the file needs -frac2-qcopy: retail's 128-bit copy is
     `lq $v0,0($v1); sq $v0,0($sp)` with both addresses in registers, which is exactly
     the grouped pattern that flag selects (tools/compiler/transformers/qcopy_pattern.py).
     Without it this cc1 folds the offset (`lq $v0,0x10($s0)`), and the flag is safe for
     the file's other nine functions (all nine still match with it).
   - the copy itself has to be a `mode(TI)` assignment through a union of the quadword
     and `float f[4]`, the same shape as the matched func_L02_0038DA60 in
     src/levels/shared/L02_002B5F50.c; a `long long` copy gives `ld`/`sd`.
   - the local is the 16-byte vector: `buf.f[3] = 4.0f` is retail's `swc1 $f20,0xC($sp)`
     and the call takes `&buf`.
   - the table is filled through a pointer that starts at the last entry and walks down
     (`q = &D_L09_00257110[19]`, `*q = -1; q--`), and the main loop advances its own
     pointer (`*p = ...; p++`); the twenty-entry fill and the walk then match retail's
     words exactly.
   - the loop counter is one variable used for the fill (19 down to 0) and for the walk
     (0 up), which is why retail keeps it in $s2 for both.
   - the call is `func_L09_003FE3B0(s5[0x21], D_L09_00257110)`: retail passes the table
     as a second argument that func_L09_003FE3B0 ignores, so that function's prototype
     needs the extra parameter.
   Tried and not enough: the fill as an indexed loop (`D_L09_00257110[i] = -1`) - the base
     is then live across the fill and this cc1 hoists its %hi into a saved register
     (324 bytes, different save order); the fill through a pointer variable
     (`int *q = D_L09_00257110; q[i] = -1`) - same; a named `base` variable used by the
     call - same; -mno-split-addresses on this file gives the retail size (332) and the
     body, but it breaks the file's other nine functions (func_L09_003FDC58 and
     func_L09_003FE620 stop matching), so the file must not use it.
   Next idea: a source whose fill pointer is the table's base plus 0x4C computed at run
   time, so that the base is materialised as a value and the %hi is not hoisted. */

extern int D_L09_00257110[];
extern unsigned char *D_L09_001B285C_1[3] __attribute__((sda));
extern short *D_L09_001FB560[];
extern char D_L09_001B9A00[];

extern float func_00282E80(void *, void *);
extern float func_00283CE0(int);
extern int func_00283DB8(void *buf, float value);
extern void func_L09_003FD460(void *);
extern void func_L09_003FD128(void *);
extern void *func_L09_003FE3B0(int index, int *table);

typedef int TI128 __attribute__((mode(TI)));

typedef union {
    TI128 q;
    float f[4];
} Vec4_L09;

/* Fills the level's twenty-entry screen table with the field 0xB2 of every entry of the
   object's track, then walks the entries and hands the ones the shared record starter
   accepts to the two level bodies. */
void func_L09_003FE4D0(unsigned char *a0)
{
    unsigned char *s5 = a0;
    unsigned char *s4;
    int i;
    int *p;
    int *q = &D_L09_00257110[19];
    Vec4_L09 buf;

    s4 = *(unsigned char **)(s5 + 0x68);
    i = 19;
    while (i >= 0) {
        *q = -1;
        q--;
        i--;
    }
    if (*(short *)(s4 + 0x424) <= 0)
        return;
    p = D_L09_00257110;
    i = 0;
    do {
        char *s0;
        unsigned char *s1;
        TI128 *src;
        float f;

        s0 = (char *)func_L09_003FE3B0(s5[0x21], D_L09_00257110);
        *p = *(short *)(s0 + 0xB2);
        p++;
        src = (TI128 *)(s0 + 0x10);
        buf.q = *src;
        buf.f[3] = 4.0f;
        f = func_00283CE0(*(short *)(s0 + 0x32));
        if (func_00283DB8(&buf, f) != -1) {
            s1 = *(unsigned char **)(s0 + 0x68);
            if (*(int *)(s1 + 0x42C) & 8)
                func_L09_003FD460(s0);
            if (*(int *)(s1 + 0x42C) & 2)
                func_L09_003FD128(s0);
        }
        i++;
    } while (i < *(short *)(s4 + 0x424));
}
