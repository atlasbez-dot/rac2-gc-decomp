/* Retained near miss, 24 October 2026.
 * Game `-O2 -G0 -ffunction-sections` (the default unit of 002EEB00.c), with
 * D_001B22A8 declared `sda` so the assembler relaxes its store to $gp while
 * its load stays absolute.
 * USA v1.01, PAL and USA v2.00: 208/208 bytes, 0/28 places each.
 * One checker invocation after correcting the earlier n4 draft.
 *
 * The body from the first call to the epilogue is retail's, including the
 * two func_002FC468 packets, the 4x4 build and the two render restarts. The
 * residual is the entry block: retail adjusts the frame, saves $s0/$ra and
 * only then stores D_001B219C and D_001A72D0; this source schedules the
 * D_001B22A8/D_001A72D4 loads and both stores before the frame adjustment.
 *
 * The earlier n4 worktree draft stored *p into D_001B219C; retail stores the
 * pointer p itself. That correction recovers the size and the whole call
 * body. Reopen with evidence for the entry-block schedule (`-mastra-keep-
 * frame-order` and a different declaration order are the first experiments),
 * not a register pin.
 */
extern void func_0011AEA0(int);
extern void func_002FC468(unsigned int, void *, unsigned int);
extern int D_001A72D4;
extern int D_001A72D0;
extern unsigned char *D_001B22A8 __attribute__((sda));
extern unsigned char *D_001B219C;
extern char D_001B5340[];
extern int D_00215E80[];
extern void func_00283388(float *);
extern void func_00282D30(void *, void *, float);
extern void func_00283788(char *, char *, char *);
extern void func_002EF480(void);
extern void func_002EF1E8(void);
extern unsigned int func_00282BA8(void *, unsigned int, unsigned int);

void func_002EF3B0(void)
{
    float m[16];
    unsigned char *p = D_001B22A8;

    D_001B219C = p;
    p += 0x10;
    D_001B22A8 = p;
    D_001A72D0 = D_001A72D4;
    func_00283388(m);
    func_00282D30(m + 12, D_001B5340, -1024.0f);
    m[15] = 1.0f;
    func_00283788((char *)m, D_001B5340 - 0x100, (char *)m);
    func_002FC468(5, m, 4);
    func_002FC468(0x14D, m, 4);
    func_0011AEA0(0);
    func_002EF480();
    func_002EF1E8();
    func_00282BA8(D_00215E80, 0x3000, 0x40);
}
