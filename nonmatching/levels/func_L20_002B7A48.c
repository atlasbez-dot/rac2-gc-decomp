/* Near miss from src/levels/20_yeedil/L20_002B7A48.c (level-20 wave 5, worker 12).
   Kept as a starting point; not linked, not counted.

   The retail keeps THREE materialisations of D_00189E20 out of ONE lui: the
   address in the lui register itself ("lui $v0,%hi(D)" + "addiu $v0,$v0,%lo(D)"),
   the %hi copied into $a2 ("daddu $a2,$v0,$zero") with the %lo added at every
   use ("addiu $x,$a2,%lo(D)"), and the "a0 = D" again on the a0 == 0 path.

   MEASURED (tools/check.py func_L20_002B7A48 --diff): 188 bytes against the
   retail's 192, and the tail from the "jal func_L00_002ADEA0" on matches the
   retail instruction for instruction.  What is left:

     1. the retail's state byte is read from the lui register itself (the F2
        form, "addiu $v0,$v0,%lo(D)" + "lbu $a1,0x22B4($v0)") while this build
        keeps one address in $a1 for the byte and for the two fields at
        0x22BA/0x24EC (the F1 form).  The CSE merges the two references to the
        symbol whatever their type and whatever block they are in; what the
        retail needs is a SECOND assignment of the symbol whose value is used
        after it, and the re-assignment has to be a different expression from
        the first one.  Measured and NOT enough: a second name, a second
        assignment in the same block, a second assignment after the nested
        block, and the byte read through a separate variable - all of them
        still fold into one materialisation;
     2. the retail's "state == 1" test is a FORWARD "beq" to an out-of-line
        two-instruction block ("b .L7AFC" + "daddu $v0,$zero,$zero") and the
        "state == 4" test a forward "beq" to the epilogue; the switch below
        gives the forward "beq" for the first test (it is the only spelling
        measured that does) but the block still lands at the end of the
        function instead of in front of the main body;
     3. the retail's "the 0x24CC word == 1" test is a forward "beq" to the
        "return 0x51" block; the level-18 twin's spelling ("!= 1" first, then
        the 0x67/0x1492 pair, then "return 0x51") gives exactly that and is
        what this attempt uses;
     4. the register of the state byte ($a1 in the retail, $v1 here) and of
        the constant 1 ($v1 in the retail, $v0 here) - the allocation follows
        the order in which the values are first set, and the retail sets the
        byte before the constant.

   The level-18 twin of this body (func_L18_002C2D48, MATCHED) is the same
   game code without the "state == 1" test; its C is the template. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef long long s64;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));

extern char D_00189E20[];
extern u8 D_00139568[];
extern char D_L20_0026D970[];
extern s32 func_L00_002ADEA0(s32 index);

typedef struct {
    u8 pad[0x28];
    s32 v;
} Entry;

s32 func_L20_002B7A48(char *a0)
{
    char *s1 = D_00189E20;
    u8 state = D_00189E20[0x22B4];

    switch (state) {
    case 1:
        return 0;
    case 4:
        return 0xD;
    }
    if (a0 != 0 && *(u8 *)(s1 + 0x22BA) != 0 && *(s16 *)(s1 + 0x24EC) == 0) {
        int idx = func_L00_002ADEA0(0);

        return ((Entry *)(D_L20_0026D970 + D_00139568[idx] * 224))->v;
    }
    a0 = D_00189E20;
    if (*(int *)(a0 + 0x24CC) != 1)
        return *(u8 *)(a0 + 0x1492) ? 0x67 : 0;
    return 0x51;
}

/* M18 (2026-10-26): a switch spelling reaches retail size, 192/192 B, ~40 lines off (the first 14 instructions and the case-1 block layout):
int func_L20_002B7A48(char *a0)
{
    switch (*(u8 *)(D_00189E20 + 0x22B4)) {
    case 1:
        return 0;
    case 4:
        return 0xD;
    }
    if (a0 != 0 && *(u8 *)(D_00189E20 + 0x22BA) != 0 && *(s16 *)(D_00189E20 + 0x24EC) == 0) {
        int idx = func_L00_002ADEA0(0);
        return ((WeaponEntry_2B7A48 *)(D_L20_0026D970 + D_00139568[idx] * 224))->v;
    }
    a0 = D_00189E20;
    if (*(int *)(a0 + 0x24CC) != 1)
        return *(u8 *)(a0 + 0x1492) ? 0x67 : 0;
    return 0x51;
}
*/
