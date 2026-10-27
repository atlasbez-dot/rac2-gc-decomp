/* func_0028AB70 - retained near miss, USA v1.01.
 *
 * Profile: -O2 -G8 -ffunction-sections (the body lives in 00288D88-g8.c because one
 * store, `sw $v0,0x28EC($gp)`, reaches D_001B18DC through $gp; every other access in
 * the body is absolute, which is what the -G8 unit's plain externs produce).
 * Last verdict: 312 bytes against 320, 0 of 28 places.
 *
 * What matches: the whole thirteen-record clear loop (including the delayed `jal`
 * argument setup and the `bnez` back edge), the lazy DebugMalloc pair with the
 * "hud.cpp" file string, the D_001B18E0/D_001B18DC/D_001B18D8 group, the byte 0xFF
 * store in the func_0028BCE8 delay slot, and the closing func_0028A278 call.
 *
 * Remaining difference (two instructions):
 *  1. Retail keeps the constant -1 in $s4 (saved and restored) although its only use
 *     is the `sw $s4,0x40($s0)` before the loop head; this draft materialises it in
 *     $v1. Retail's loop back edge targets the instruction *after* that store, so the
 *     store is outside the loop in the emitted code, yet its live range still spans
 *     the loop's call. A source form that keeps -1 live across the call (e.g. the
 *     store plain inside the loop with the loop rotated) was not found: putting the
 *     store back in the loop moves the back-edge target onto it instead.
 *  2. The `if (D_001B18D8 == 0)` join reloads D_001B18D8 in the `bnez` delay slot
 *     here; retail leaves `addiu $a1,$zero,0x2800` in that slot and reloads at the
 *     join. This is the load-hoisting tie of docs/MATCHING-BLOCKERS.md #42.
 *
 * Also measured: `extern char ref_L00_0028AB70_00[];` gives the absolute
 * `lui;addiu` string address retail uses (a `char *` declaration would load it).
 */
typedef struct {
    int unk00;
    int unk04;
    unsigned char pad08[0x18];
    int unk20;
    int unk24;
    unsigned char pad28[0x3C];
    int key;
    unsigned char pad68[4];
    int unk6C;
    unsigned char pad70[0xC];
    int unk7C;
    unsigned char pad80[0x10];
} HudSlot;

extern HudSlot D_00255330[13];
extern int D_001B1870;
extern int D_001B1874;
extern char *D_001B18D8;
extern char *D_001B18E0_1;
extern int D_001B18E4;
extern char ref_L00_0028AB70_00[];
extern char *D_001B18DC_1 __attribute__((sda));
extern char *func_0028B2B8(int, int, char *, int);
extern void func_0028B3D0(int, int, int, int, int, int, int);
extern char *func_00282A88(char *, int);
extern void func_0028BCE8(void);
extern void func_0028A278(void);

/* Clears the thirteen HUD element slots and lazily creates the HUD moby table. */
void func_0028AB70(void)
{
    int *q = (int *)((char *)D_00255330 + 0x24);
    int i = 0;

    D_001B1870 = 0;
    D_001B1874 = 0;
    q[16] = -1;
    do {
        q[-1] = 0x10000;
        func_0028B3D0(i, 0xffff, 0, 0, 0, 0, 1);
        i++;
        q[22] = 0;
        q[18] = -6;
        q[-8] = 0;
        q[0] = 0;
        q = (int *)((char *)q + 0x90);
    } while (i < 13);
    if (D_001B18D8 == 0) {
        char *file = ref_L00_0028AB70_00;
        D_001B18D8 = func_0028B2B8(0x2800, 0, file, 0x2AB);
        D_001B18E4 = (int)func_0028B2B8(0x1400, 0, file, 0x2AC);
    }
    D_001B18E0_1 = D_001B18D8 + 0x2800;
    D_001B18DC_1 = D_001B18D8;
    func_00282A88(D_001B18D8, 0x2800);
    *((unsigned char *)D_001B18D8 + 0x20) = 0xFF;
    func_0028BCE8();
    func_0028A278();
}
