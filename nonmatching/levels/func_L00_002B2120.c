/* func_L00_002B2120 (220 bytes, 27 places) -- NEAR MISS, not integrated.
   Wave 8 w8-10: 208 bytes against 220. The frame is the retail's 0x10 with only $s0
   and $ra saved, and the callee sequence, the two calls to the first helper and the
   five tail calls all match. What still differs:

   - The retail keeps the HIGH half of the resident block in $s0 (`daddu $s0,$v1,$zero`
     with $v1 = 0x190000) and rebuilds the base with `addiu $v1,$s0,-0x61E0` at every
     access; this draft materialises the full address 0x189E20 once and keeps it in
     $s0. The same split shows up in func_L00_002B5A88's retail body.
   - The retail's first test is a branch-likely `bnel $v0,$zero` whose delay slot
     re-materialises the base (and is annulled on the fall-through path, so $v1 still
     holds the state word); this draft emits a plain `bnez` and keeps the state word
     in a register.
   - The state word must NOT be live across the first call: reading it twice from
     memory (`*(int *)(p + 0x229C) == 3` in the second half) is what keeps this cc1
     from parking it in a callee-saved register - with a cached `state` variable the
     draft needs $s0 and $s1 for it and a 0x20 frame (216 bytes).
   - The first half is an if/else, not an early return: the retail's "else" path stores
     the zero the first helper returned into 0x22B7 and skips the 0x22BC store, so the
     flag has to be a value, not a constant. The previous draft's early return had the
     wrong semantics (it also skipped the second half).

   What was measured: the state test as `state == 21 || state == 22 || state == 31`
   folds to the retail's `(state - 21) < 2` (sltiu) plus `state == 31`; the four-way
   `kind == 49 || state == 3 || kind == 18 || kind == 130` matches the retail's three
   compares and its branch-likely `bnel` with the zero store in the slot. */

extern unsigned char D_00189E20_1[];
extern int ref_L00_002B2120_00(void);
extern void ref_L00_002B2120_01(void);
extern void ref_L00_002B2120_02(int);
extern void ref_L00_002B2120_03(void);
extern void ref_L00_002B2120_04(void);
extern void ref_L00_002B2120_05(void);

void func_L00_002B2120(void)
{
    char *p = (char *)D_00189E20_1;
    int state = *(int *)(p + 0x229C);
    int kind;

    if (state == 21 || state == 22 || state == 31 || ref_L00_002B2120_00() != 0) {
        p[0x22BC] = 1;
        p[0x22B7] = 1;
    } else {
        p[0x22B7] = 0;
    }
    if (ref_L00_002B2120_00() != 0) {
        p[0x22BE] = 1;
    } else {
        kind = *(int *)(p + 0x2294);
        if (kind == 49 || *(int *)(p + 0x229C) == 3 || kind == 18 || kind == 130)
            p[0x22BE] = 1;
        else
            p[0x22BE] = 0;
    }
    ref_L00_002B2120_01();
    ref_L00_002B2120_02(*(int *)(p + 0x2290));
    ref_L00_002B2120_03();
    ref_L00_002B2120_04();
    ref_L00_002B2120_05();
}
