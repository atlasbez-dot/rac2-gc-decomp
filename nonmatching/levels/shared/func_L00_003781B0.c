/* Near miss, not linked. Shared level function func_L00_003781B0 (472 bytes, 27 places),
   profile -O2 -G0 -ffunction-sections.

   Last verdict: `python scratch\wslcmp.py src/levels/shared/L00_00358D98.c
   func_L00_003781B0 full` -> 468 bytes, expected 472; 0 of 27 places match.

   The body is an icon pair: with the level word at 0x84 set it draws either the single
   icon 0x1124 or the pair 0x28/0x118 depending on D_001A79F8 against the 12-byte cell
   word at +0x144; with 0x84 clear it draws the pair when that cell word is positive.
   `x` is (int)(D_L00_001B25E0 * 312.0f + 0.5f) and the colour is 0x80F0F0F0.

   Remaining difference: GCC puts the level base in a2 and the scaled cell index in a0,
   retail holds the base in a0 and the index in v0/a2, so the first ten instructions and
   the two mult destinations differ; retail also re-materialises the 12-byte stride with
   `addiu v1,zero,0xC` on the path reached through the first beqz while this form reuses
   the constant from the branch delay slot (the one-instruction size gap). The
   `unsigned long` colour parameter (the ori/dsll/ori 0x80F0F0F0 materialisation) is
   measured and belongs in the reconstruction. The data symbol D_L00_001B25E0 and the
   table base D_L00_0022F7C0 differ per level (0x1B25E0/0x22F7C0 in level 00,
   0x1B2CA0/0x22FEC0 in level 01), so they must become ref_L00_003781B0_kk before a
   build; wslcmp already derived the per-place values. */

extern int D_L00_0022F7C0[];
extern float D_L00_001B25E0 __attribute__((sda));
extern int D_001A79F8;
extern int func_00288FB8(int id);
extern void func_0027F5B8(int sprite, int x, unsigned long color, int id, int y);
extern void func_0027FA10(int sprite, int x, unsigned long color, int id, int y);

typedef struct {
    int first;
    int second;
    int third;
} L00_003781B0_Cell;

#define L00_003781B0_X ((int)(D_L00_001B25E0 * 312.0f + 0.5f))

void func_L00_003781B0(void)
{
    if (D_L00_0022F7C0[0x84 / 4] != 0) {
        L00_003781B0_Cell *cell = (L00_003781B0_Cell *)((char *)D_L00_0022F7C0 + 0x144);
        if (D_001A79F8 >= cell[D_L00_0022F7C0[0x80 / 4]].first) {
            func_0027F5B8(0x28, L00_003781B0_X, 0x80F0F0F0UL, func_00288FB8(0x113B), -1);
            func_0027FA10(0x118, L00_003781B0_X, 0x80F0F0F0UL, func_00288FB8(0x1138), -1);
        } else {
            func_0027FA10(0x118, L00_003781B0_X, 0x80F0F0F0UL, func_00288FB8(0x1124), -1);
        }
    } else {
        L00_003781B0_Cell *cell = (L00_003781B0_Cell *)((char *)D_L00_0022F7C0 + 0x144);
        if (cell[D_L00_0022F7C0[0x80 / 4]].first > 0)
            func_0027F5B8(0x28, L00_003781B0_X, 0x80F0F0F0UL, func_00288FB8(0x1125), -1);
        func_0027FA10(0x118, L00_003781B0_X, 0x80F0F0F0UL, func_00288FB8(0x2D4F), -1);
    }
}
