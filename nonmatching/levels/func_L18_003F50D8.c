/* func_L18_003F50D8 (188 bytes, 3 places) -- NEAR MISS, not integrated.
   Two resident-state edits (0x001A79F0 == 0x13 and 0x001A8F00 == 2) then a
   three-way dispatch on the byte at +0x20: 0 calls func_L18_003F5198, 1 and 0x13
   do nothing, anything else runs the four-function update chain.
   The candidate is 192 bytes: every instruction of both blocks and the epilogue
   is the source's, but where retail branches (beq/beql to the epilogue) this cc1
   speculates the +0x20 load into the delay slot of a `bnel` and reloads it at the
   join - the annulled-slot wall of COMPILER-NOTES, here on the branch that leaves
   the first block.  Four spellings measured (local byte, three inline re-reads,
   nested else-if, flipped constant order): all 192. */
extern int D_L18_001A79F0;
extern int D_L18_001A8F00;
extern void func_L18_003F5198(void *);
extern void func_L18_003F53D8(void *);
extern void func_L18_003F5650(void *);
extern void func_L18_003F6CA8(void *);
extern void func_L18_003F7198(void *);

void func_L18_003F50D8(char *a0)
{
    char *s0 = a0;
    unsigned char v;

    if (D_L18_001A79F0 == 0x13) {
        if (D_L18_001A8F00 == 2) {
            *(int *)(s0 + 0x98) = 0;
            *(unsigned short *)(s0 + 0x34) = (*(unsigned short *)(s0 + 0x34) | 0x41) & 0xEFFF;
        } else {
            char *p = *(char **)(s0 + 0x24);

            *(unsigned short *)(s0 + 0x34) = (*(unsigned short *)(s0 + 0x34) & 0xFFBE) | 0x1000;
            *(int *)(s0 + 0x98) = *(int *)(p + 0x10);
        }
    }
    v = *(unsigned char *)(s0 + 0x20);
    if (v == 0) {
        func_L18_003F5198(s0);
    } else if (v != 1 && v != 0x13) {
        func_L18_003F53D8(s0);
        func_L18_003F5650(s0);
        func_L18_003F6CA8(s0);
        func_L18_003F7198(s0);
    }
}
