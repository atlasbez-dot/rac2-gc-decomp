/* Near miss: the candidate is 436 bytes against the retail's 444 (two words short).
 *
 * What matches: the frame's shape, the two first calls, the whole run of stores into
 * the map object, the branch on the map's word at 0x238, the map lookup through the
 * level table, the two calls of the main path and the call of the end.
 *
 * What differs:
 *  - one callee-saved register too many (the frame is 0x30, the retail's is 0x20);
 *  - the store of the map's word at 0x290 comes before the store of the word at 0x288,
 *    the retail's stores are in ascending order;
 *  - the prologue materialises the map's address (`addiu $s2,$s0,%lo`), the retail
 *    leaves it to the delay slot of the first call;
 *  - the test of the map's word at 0x238 is `bne $a3,$v1` where the retail has
 *    `beq $t0,$v1` (the test is read into another register).
 *
 * Tried: the map and the second object reached through pointer variables (the retail
 * reaches them through the symbol, the frame grows by one register), the store order
 * permuted in the source (the compiler keeps its own order), the three arms of the
 * if/else chain written out separately (the retail shares the tail of the second and
 * the third arm, so the source has one if/else-if/else).
 */
extern int D_001C4FA0[];
extern int D_001F2840[];
extern char D_0014B540_1[];
extern unsigned char D_001A7AFD;
extern int D_001A79F0_3 __attribute__((sda));

extern void func_0029DEA8(int, int);
extern void func_002B7C80(unsigned long, int, unsigned long);
extern void func_002B7CE0(int);
extern void func_002EEE50(int, int, int, int);
extern void func_002EEED0(int, int, int, int);
extern void func_002E5E58(int, int, int);

/* resets the map's cache slots and reloads the current level's entry */
void func_002954C0(void)
{
    int a;
    int b;
    int c;
    int e;
    int *entry;

    func_00298170();
    func_0029DEA8(D_001C4FA0[0x230 / 4], 1);
    a = D_001F2840[0x10C / 4];
    b = D_001F2840[0x110 / 4];
    c = a + 0x9A800;
    D_001F2840[0x110 / 4] = b + 0x48000;
    D_001F2840[0x10C / 4] = c + 0x48000;
    D_001C4FA0[0x248 / 4] = a;
    D_001C4FA0[0x288 / 4] = 0;
    D_001C4FA0[0x28C / 4] = c;
    D_001C4FA0[0x290 / 4] = b;
    D_001C4FA0[0x294 / 4] = 0;
    D_001C4FA0[0x298 / 4] = 0;
    D_001C4FA0[0x29C / 4] = -1;
    D_001C4FA0[0x2A0 / 4] = -1;
    D_001C4FA0[0x2A4 / 4] = -1;
    D_001C4FA0[0x2A8 / 4] = -1;
    D_001C4FA0[0x2AC / 4] = -1;
    D_001C4FA0[0x2B0 / 4] = -1;
    if (D_001C4FA0[0x238 / 4] == -1) {
        D_001C4FA0[0x24 / 4] = 0;
    } else if (D_001C4FA0[0x23C / 4] == 0 && D_001A7AFD != 0) {
        entry = (int *)((char *)D_0014B540_1 + D_001C4FA0[0x230 / 4] * 8);
        a = *(int *)((char *)D_0014B540_1 + 0x36C);
        b = *(int *)((char *)entry + 0x15D0) + a;
        e = *(int *)((char *)entry + 0x15D4);
        func_002B7C80(c, b, e);
        e <<= 7;
        func_002B7CE0(1);
        D_001C4FA0[0x23C / 4] = 1;
        func_002EEE50(D_001C4FA0[0x28C / 4], D_001C4FA0[0x238 / 4], 0, e);
        D_001C4FA0[0x240 / 4] = e;
        D_001C4FA0[0x234 / 4] = -2;
        D_001C4FA0[0x2A0 / 4] = D_001A79F0_3 + 0x100;
        D_001C4FA0[0x24 / 4] = 1;
    } else {
        e = D_001C4FA0[0x240 / 4];
        func_002EEED0(D_001C4FA0[0x28C / 4], e, 0, e);
        D_001C4FA0[0x2B8 / 4] = e;
        D_001C4FA0[0x234 / 4] = -2;
        D_001C4FA0[0x2A0 / 4] = D_001A79F0_3 + (D_001A7AFD ? 0x100 : 0);
        D_001C4FA0[0x24 / 4] = 1;
    }
    func_002E5E58(0x11, 0, 0);
}
