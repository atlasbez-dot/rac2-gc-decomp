/* func_L23_0041D9B0 (152 bytes, 1 place, -g8 unit) -- measured 0 of 1, candidate 160 bytes
   (8 too many). Measurement from wave 9 worker 16; kept for the next worker.

   Releases the five pointers at state+0x358 (walked with a pointer, the counter
   compared with `bgez` at the bottom), then the level object, then sets three flags:

     lw  $v1,0x2494($gp) ; lw $v0,0x68($v1) ; addiu $s0,$v0,0x358 ; addiu $s1,$zero,4
     loop: lw $a0,0($s0) ; beqz -> skip ; (delay: s1--)
           jal func_0029F338 ; sw $zero,0($s0)
     skip: bgez $s1,loop ; (delay: s0 += 4)
     lw $v0,0x2494($gp) ; beqz -> tail
           jal func_0029B758 (0,0) ; jal func_0029CE80
           jal func_0029F338 (delay: lw $a0,0x2494($gp)) ; sw $zero,0x2494($gp)
     tail: li $v0,1 ; lui $v1,0x14 / addiu $v1,$v1,-0x6A48 (= D_001395B8)
           sb $v0,0x88($v1) ; sw $v0,0x2434($gp) ; sb $v0,0xA1($v1)

   The emission order of the last three stores is [0x88], [0x2434($gp)], [0xA1] while
   the source order was derived as [0x2434, 0xA1, 0x88] (last source store emitted
   first). That permutation is the one thing this file still has to confirm: the
   candidate below is 160 bytes, i.e. two words too long.
*/

extern char *D_L23_001B1484 __attribute__((sda));
extern int D_L23_001B1424 __attribute__((sda));
extern unsigned char D_001395B8[];
extern void func_0029F338(char *);
extern void func_0029B758(int, int);
extern void func_0029CE80(void);

void func_L23_0041D9B0(void) {
    char **p = (char **)(*(char **)(D_L23_001B1484 + 0x68) + 0x358);
    int i;

    for (i = 4; i >= 0; i--) {
        if (*p != 0) {
            func_0029F338(*p);
            *p = 0;
        }
        p++;
    }
    if (D_L23_001B1484 != 0) {
        func_0029B758(0, 0);
        func_0029CE80();
        func_0029F338(D_L23_001B1484);
        D_L23_001B1484 = 0;
    }
    D_L23_001B1424 = 1;
    *(D_001395B8 + 0xA1) = 1;
    *(D_001395B8 + 0x88) = 1;
}
