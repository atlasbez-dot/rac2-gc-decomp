/* Publication review uses the catalogue data name D_001B7F80; historical
 * measurements below precede that naming correction. This draft is not linked. */
/* Useful semantic draft; corrected current C is unmeasured.
 * Historical draft: USA v1.01, PAL and USA v2.00, 204/204 bytes,
 * 0/28 placements each, using inaccurate callee prototypes. Those measurements
 * do not apply to the corrected current C: func_001261F0 takes no arguments,
 * and func_002FC3C0 takes the existing unsigned-long 64-bit wrapper mask.
 * Default game compiler profile: -O2 -G0 -ffunction-sections.
 * Two independent additions at +0x70 and +0x74 are swapped: retail adds
 * 0x60000 to the second coordinate before adding 0xD0800 to the first.
 * Seven USA checker trials tested base declarations, coordinate load/store
 * order and local arithmetic. Complete int-array declaration preserves the
 * retail base materialization; localizing the updated first coordinate folds
 * the constants and produces 200 bytes. Reordering the coordinate stores
 * changes earlier scheduling. Three useful forms leave the same two-word tie.
 * That prior form was also checked in PAL and USA v2.00 (nine total
 * checker invocations, no scratch compiles or full builds).
 * Reopen with independent evidence for the original state/coordinate types
 * or a measured source structure that resolves this scheduling tie.
 */
extern void func_002FC3C0(unsigned long);
extern int func_001261F0(void);
extern void func_002FC1D8(void);
extern void func_002E5FE0(void);
extern int D_001BAEC0[8];
extern char D_001B7F80[];
extern int D_001B1598 __attribute__((sda));
extern int D_001B22B0 __attribute__((sda));
extern int D_001A8BC0 __attribute__((sda));
extern float D_001B15A0 __attribute__((sda));
extern int D_001A72D4 __attribute__((sda));

void func_00278EB0(void)
{
    char *state;
    int x, y, z;
    func_002FC3C0(1UL);
    func_001261F0();
    D_001B1598++;
    y = D_001BAEC0[4];
    x = D_001BAEC0[3];
    z = D_001B22B0;
    state = D_001B7F80;
    *(int *)(state + 20) = z - 0x60000;
    *(int *)state = x + 0x60000;
    *(int *)(state + 4) = y + 0x60000;
    *(int *)(state + 8) = *(int *)state + 0xD0800;
    D_001A8BC0 = 0x2000;
    D_001B22B0 = 0x60000;
    func_002FC1D8();
    func_002E5FE0();
    *(int *)(state + 0x18) = D_001A72D4;
    *(short *)(state + 0x26) = 0;
    D_001B15A0 = 1.0f;
}
