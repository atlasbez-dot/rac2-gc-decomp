/* func_00132318 (384 bytes, boot) - NEAR MISS, 1 word (M22, 2026-10-26).
 *
 * Measured as src/core/00132318-g8.c with "-O2 -G8 -ffunction-sections".  Every
 * word matches except one padding nop: the last wait loop (jal, lui/lw of
 * D_001A7180, beq) gets two R5900 short-loop nops here and one in retail.
 * mips_r5900_pad_loops counts RTL insns, so retail's lui/lw were two insns
 * (a split %hi/%lo load) where the MACRO_ADDR declaration gives one macro insn.
 * But the same global is stored with the `lui $at` macro form and read through
 * $gp in two delay slots, which needs MACRO_ADDR; a plain incomplete array
 * splits every access and hoists the base.  Open: what spelling of the final
 * loop's read gives a split load next to the macro forms elsewhere.
 */
/* func_00132318, 384 bytes, boot. 989snd's snd_BankLoadByLoc: a synchronous bank load
   by CD location over RPC 3. The scalars are -G8 small data; the two RPC buffers are
   reached with the absolute macro form in ordinary flow and through $gp in delay slots. */
#include "common.h"

extern s32 D_001A74C8 __attribute__((sda));
extern s32 D_001A7488 __attribute__((sda));
extern s32 D_001A74F8 __attribute__((sda));
extern u32 D_001A7180[] MACRO_ADDR;
extern s32 D_001A71C0[] MACRO_ADDR;
extern char D_001A7140[] MACRO_ADDR;
extern char D_001A7578[];
extern char D_001A7600[];
extern char D_001A7630[];
extern char D_001A7650[];

extern void func_00115D48(char *, ...);
extern int func_00133580(int);
extern int func_00132028(void);
extern void func_0011AEA0(int);
extern int func_0011D810(void *);
extern int func_0011D620(void *, int, int, void *, int, void *, int, int, int);

s32 func_00132318(s32 loc, s32 offset)
{
    D_001A7488 = 0;
    if (D_001A74C8 != 0) {
        if (D_001A74F8 == 0)
            func_00115D48(D_001A7600);
        return 0;
    }
    if (func_00133580(1) == 1) {
        if (D_001A74F8 == 0)
            func_00115D48(D_001A7630);
        return 0;
    }
    D_001A71C0[0] = loc;
    D_001A71C0[1] = offset;
    D_001A7180[0] = 0xFFFFFFFFu;
    while (func_0011D810(D_001A7140) != 0) {
        if (D_001A74F8 == 0)
            func_00115D48(D_001A7578);
        func_00132028();
        func_0011AEA0(0);
    }
    if (func_0011D620(D_001A7140, 3, 1, D_001A71C0, 8, D_001A7180, 4, 0, 0) < 0) {
        if (D_001A74F8 == 0)
            func_00115D48(D_001A7650);
        D_001A7488 = 0x106;
        return 0;
    }
    while (D_001A7180[0] == 0xFFFFFFFFu)
        func_0011AEA0(0);
    return D_001A7180[0];
}
