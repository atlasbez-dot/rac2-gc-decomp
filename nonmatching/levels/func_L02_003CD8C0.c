/* from src/levels/shared/L02_003C43F0.c: not written this wave - decoded, no C attempt.
 * 176 bytes, 2 places. Same family as func_L02_003CEBB8 (the 0x7FFF list walk) but void:
 *     if (*(u8 *)(a0 + 0x21) == 0xFF) return;
 *     q = (u16 *)D_L02_001FC060[*(u8 *)(a0 + 0x21)];
 *     for (;;) {
 *         base = *(u8 **)D_L02_001B359C;                (reloaded inside the body: nosda)
 *         e = (char *)(base + ((*q & 0x7FFF) << 8));
 *         if (e == 0) return;
 *         o = *(u32 *)(e + 0x68);
 *         *(u16 *)(o + 0x386) = 0xB4;                   (the 0x41/0xFFFF mask pair)
 *         *(u16 *)(o + 0x382) = 1;
 *         ... continuation ...
 *     }
 * The index byte 0x21 is re-read at every iteration (the stores in the body alias it, so no
 * CSE) and it is re-indexed into D_L02_001FC060 for the loop test - see the twin above for
 * the duplicated continuation chain, which is the wall here too.
 * One dead word: the byte at 0x003CD8EC is a bare nop between the entry jump and the loop
 * body; the body is only ever entered through the continuation tests.
 */
