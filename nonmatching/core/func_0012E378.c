/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: SDK EE-GCC 2.9-ee-991111-01.
 * Profile: sdk -O2 -G2 -ffunction-sections.
 * Reported final C / retail: 448 / 448 bytes; size equality is not a match.
 * us: 0/1 placements.
 * us2: not run: US candidate failed.
 * pal: not run: US candidate failed.
 * Residual: Retained readable CSC DMA chain with five-word callback context. Two forms 456 then448/448, prologue/trap and call delay scheduling differ. Kernel syscall18 contract still needs source-width qualification.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not attempted in this run.
 *
 * src/core/0012E110.c line 46. 448 bytes, and per symbol_addrs a "chained
 * IPU colour conversion in cod/022FA8" whose error string D_0013BCC0 reads
 * "CSC handler error"; func_0012E608 (compiled C since task 2055) calls it.
 * The body is ordinary C - no VU0, no MMI, no `sync` - so it is a C target;
 * it just had no upstream source to transcribe from, unlike the two
 * functions this run did finish.
 *
 * What is known from the head: `addiu $a3,$zero,0x3FF` before the frame is
 * even built, then `div $zero,$a2,$a3` - the row argument is divided by 1023
 * into a quotient/remainder pair, and the 0xF constants that follow are the
 * IPU colour-conversion selection words. rac1's libmpeg neighbour
 * src/core/0012A2F0.c holds _doCSC and its callers (func_0012A720 is the
 * same address as this one minus the usual +0x3C58), but that file is
 * INCLUDE_ASM over this range in rac1 too, so it gives the idioms and not
 * the body.
 */

/* Expanded screening: sdk -O2 -G2 -ffunction-sections.
 * Two forms: 456 then 448/448 bytes. Completion-only volatile read removes excess bytes; remaining differences are division-trap/prologue scheduling and call result/delay-slot treatment. Interrupt callback context is five 32-bit fields, handler consumes a1 and returns zero; syscall18 itself provides no source return-width proof. Do not change helper declarations to void merely to alter scheduling. Reopen with qualified kernel wrapper contracts and grounded scheduling hypothesis.
 * tools/check.py func_0012E378 --diff --version us: 0 of 1 places; exit 1.
 */
typedef struct {
    int completed;
    int error;
    int remaining;
    unsigned int next_address;
    int transfers;
} CscTransfer;

extern int func_0011A940(int channel, int (*handler)(int, CscTransfer *), int next, CscTransfer *data);
extern int func_0011A950(int channel, int handler);
extern int func_0011B6C0(int channel);
extern int func_0011B658(int channel);
extern int func_0011F5E0(void);
extern int func_0011F628(void);
extern int func_0012E238(int channel, CscTransfer *data);
extern void *func_0012FA98(void *, int *);
extern void func_00130288(void *, void *);
extern char D_0013BCC0[];

/* Split an IPU colour conversion across 1023-macroblock DMA transfers. */
void func_0012E378(void *arg0, unsigned int destination, int count) {
    int event[8];
    CscTransfer transfer;
    int handler;
    int interrupts;

    transfer.remaining = count;
    transfer.next_address = (destination + 0xFFC00) & 0x0FFFFFFF;
    transfer.error = 0;
    transfer.completed = 0;
    transfer.transfers = count / 1023 + 1;
    while (*(volatile int *)0x10002010 < 0) {}
    handler = func_0011A940(3, func_0012E238, 0, &transfer);
    *(volatile unsigned int *)0x1000E010 = 8;
    func_0011B6C0(3);
    interrupts = func_0011F5E0();
    *(volatile unsigned int *)0x1000B010 = destination & 0x0FFFFFFF;
    *(volatile unsigned int *)0x1000B020 = 0xFFC0;
    *(volatile unsigned int *)0x1000B000 = 0x100;
    if (interrupts != 0) func_0011F628();
    *(volatile unsigned int *)0x10002000 = 0x700003FF;
    event[0] = 4;
    func_0012FA98(*(void **)((char *)arg0 + 0x858), event);
    while (*(volatile int *)&transfer.completed < transfer.transfers) {}
    if (transfer.error != 0) func_00130288(arg0, D_0013BCC0);
    while (*(volatile int *)0x10002010 < 0) {}
    func_0011B658(3);
    func_0011A950(3, handler);
}
