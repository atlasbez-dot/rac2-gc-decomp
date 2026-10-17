/* 0 of 1 places match - last line: 12_todano: 64 bytes, expected 68
   "Is the tracked object still open?": 1 unless the 0x88-based block's stage byte
   at 0x20 is 6, 5 or 8 or has its sign bit set. Retail keeps four separate
   compares (`beq` 6, `beq` 5, `beq` 8, then `sll`/`bgez`) and the result in $a1.
   This cc1 merges the adjacent 5/6 into one range test
   (`addiu $v0,$v1,-0x5; sltiu $v0,$v0,2`), which costs the missing word and
   changes the result register. The `||` chain below is what comes closest (right
   size, wrong 5/6 pair); splitting the four tests into separate ifs or a switch
   gives 84 bytes. The -G8 unit spelling uses `extern u8 *D_L12_001B1360
   __attribute__((sda));` (gp+0x2370). Blocker: that range merge.
   Its sibling func_L12_003DE4B0 (same file, 6 / <0 / 8 order) matches. */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern u8 *D_L12_001B1360;

s32 func_L12_00404778(void) {
    u8 *object = D_L12_001B1360;
    s32 result = 1;

    if (object == 0) {
        result = 0;
    } else {
        u8 c = *(u8 *)(object + 0x20);
        if (c == 6 || c == 5 || c == 8 || (s8)c < 0)
            result = 0;
    }
    return result;
}
