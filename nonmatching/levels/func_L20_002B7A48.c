/* Near miss from src/levels/20_yeedil/L20_002B7A48.c: the build refuses this body at its
   place — 180 bytes, expected 192. Kept as a starting point;
   not linked, not counted. */

/* The retail body is the "which screen does the front end hand back" lookup of
   D_00189E20: the state byte at 0x22B4 answers 0 (state 1) or 0xD (state 4),
   otherwise the resident table entry of the current selection is looked up and
   the 0x24CC/0x1492 fields of the selection decide between 0x51, 0x67 and 0.

   The C below is semantically the retail's.  It compiles to 180 bytes
   (45 instructions) against the retail's 192 (48).  The whole tail, from the
   "lw $v0,0x24CC($a0)" on, matches instruction for instruction; only the first
   14 instructions differ:

     1. the retail keeps the address of D_00189E20 in the lui register ("lui
        $v0,%hi" then "addiu $v0,$v0,%lo") and re-materialises the 64 bit form
        for the later loads ("addiu $v1,$a2,%lo", $a2 = "daddu $a2,$v0,$zero");
        this build copies the address into $a1 once and uses it for every load;
     2. the retail compares the state byte with 1 first ("beq $a1,$v1") and
        keeps the "return 0" as a separate two instruction block between the
        two tests ("b" + "daddu $v0,$zero,$zero", reached by the branch);
        this build inverts the first test ("bne") and merges that block into
        the fall-through;
     3. the retail's prologue starts with the lui of D_00189E20, this build
        starts with the stack adjustment.

   Tried (tools/check.py --diff on each):
     - "if (state == 1) ... else if (state == 4)" instead of two ifs: gives the
       retail's branch targets (+5) but then the compiler emits a branch-likely
       ("beql") for the state == 4 test and duplicates that test;
     - a switch on the state byte: 188 bytes, the byte lands in $v1 instead of
       $a1 and the constant 1 in $v0;
     - "a0 == 0 || ..." and two separate "a0 = D_00189E20" assignments: the
       branch-likely form appears and the body grows to 184/196 bytes;
     - the state byte in a local variable, the two tests in the other order,
       the common block written with "== 1" instead of "!= 1": no change, or
       worse.

   The sibling func_L18_002C2D48 (level 18) is the same function without the
   "state == 1" test and is matched; its C is the shape used here.  The
   function at 0x2C0C30 is the shared func_L00_002ADEA0, and 0x139568 is
   resident boot data, so it is D_00139568 (not D_L20_00139568). */

/* Standalone declarations recovered from src/levels/20_yeedil/L20_002B7A48.c. */
typedef unsigned char      u8;

typedef signed short       s16;

typedef signed int         s32;

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
    char *s0 = D_00189E20;

    if (*(u8 *)(s0 + 0x22B4) == 1)
        return 0;
    if (*(u8 *)(s0 + 0x22B4) == 4)
        return 0xD;
    if (a0 != 0 && *(u8 *)(s0 + 0x22BA) != 0 && *(s16 *)(s0 + 0x24EC) == 0) {
        s32 idx = func_L00_002ADEA0(0);
        return ((Entry *)(D_L20_0026D970 + D_00139568[idx] * 0xE0))->v;
    }
    a0 = D_00189E20;
    if (*(s32 *)(a0 + 0x24CC) != 1)
        return *(u8 *)(a0 + 0x1492) ? 0x67 : 0;
    return 0x51;
}

/* ---- second attempt (level-20 wave, 2026-10-20) ---------------------------------------
 * The state byte is read into a local and dispatched with a `switch` instead of two
 * `if`s, and the "return 0x51 / 0x67" tail is unchanged.  Measured: still 180 bytes
 * against the retail's 192, and the same 14 instructions differ at the top -- the
 * `switch` does not restore retail's forward `beq` for the state == 1 test, and the
 * branch-likely form appears for the state == 4 test.  Kept as the starting point;
 * not linked, not counted.
 */

typedef struct {
    u8 pad[0x28];
    s32 v;
} Entry;

s32 func_L20_002B7A48(char *a0)
{
    char *s0 = D_00189E20;
    u8 state = *(u8 *)(s0 + 0x22B4);

    switch (state) {
    case 1:
        return 0;
    case 4:
        return 0xD;
    }
    if (a0 != 0 && *(u8 *)(s0 + 0x22BA) != 0 && *(s16 *)(s0 + 0x24EC) == 0) {
        s32 idx = func_L00_002ADEA0(0);
        return ((Entry *)(D_L20_0026D970 + D_00139568[idx] * 0xE0))->v;
    }
    a0 = D_00189E20;
    if (*(s32 *)(a0 + 0x24CC) != 1)
        return *(u8 *)(a0 + 0x1492) ? 0x67 : 0;
    return 0x51;
}
