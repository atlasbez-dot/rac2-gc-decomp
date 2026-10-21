/* Near miss: 8 bytes short, the tag and the iterator land in different argument registers.
   Retail at 0x003E5298, level 04 (124 bytes, 1 place) runs the tag's list of sub-objects and
   marks each live one that carries handle 0x8BA:

     void f(char *a0)
     {
         unsigned char tag = *(unsigned char *)(a0 + 0x21);
         char *base = (char *)D_L04_001B24DC;      /* the $gp word, -G8 + sda */
         short *it;

         if (tag == 0xFF) return;
         it = ((short **)D_L04_001FB1E0)[tag];     /* the level's sub-object table */
         if (it == 0) return;
         do {
             char *object = base + ((*it & 0x7FFF) << 8);
             if (*(signed char *)(object + 0x20) >= 0 && *(short *)(object + 0xAA) == 0x8BA)
                 *(unsigned short *)(*(char **)(object + 0x68) + 0x2A6) = 1;
         } while (*it++ >= 0);
     }

   probes "as measured": the short pointer iterator with the increment inside the do/while
   condition is what reproduces the terminator test (`lh` in the two branch-likely delay slots,
   `bgez` looping back with `addiu $a0,$a0,2` in its own slot); a `char *` iterator with `it += 2`
   does not, and neither does a plain for/while. The gp word reaches $gp as `lw $a2,0x34EC($gp)`
   with `extern int D_L04_001B24DC __attribute__((sda))` in the -g8 sibling.

   The 8-byte gap is two `daddu` copies retail keeps and we drop: retail holds the loaded tag in
   $v0 and copies it to $v1 for the `sll` (`daddu $v1,$v0,$zero` in the beq delay slot), and
   copies the table entry to $a0 (`daddu $a0,$v0,$zero`); we load the tag straight into $v1 and
   use $a1 as the iterator, which is one instruction shorter. Tried and did not move it: swapping
   the compare to `0xFF == tag`. Register allocation, the wall already paid. */

/* Second attempt (wave 24, worker 15): the whole INSTRUCTION SEQUENCE is now
   retail's, word for word - only the register allocation differs.
   check.py (04_barlow), with the source below:
     04_barlow: instruction at +0x0 differs
     003E5298  lbu    $v1, 0x21($a0)   |  lbu    $v0, 0x21($a0)
     003E529C  addiu  $v0, $zero, 0xFF |  addiu  $v1, $zero, 0xFF
   Every opcode, every offset and the order are right, including the two
   branch-likely exits and the three copies of the `lh` in the delay slots; the
   eight bytes the earlier draft was short of are the two `daddu` copies, which
   this source keeps (the tag is copied for the `sll`, the table entry for
   the walk).  What still differs is only which register each value lands in:
   retail has the tag in $v0, the 0xFF in $v1, the $gp base in $a2, the 0x8BA
   in $t0, the 1 in $a3 and the entry address in $a1, where this cc1 puts
   them in $v1, $v0, $a1, $a3, $a2 and $v1.
   The body needs the -G8 profile (the base is reached through $gp), so it
   belongs in L04_003AB458-g8.c.
   Tried and all identical: the 0xFF constant in a named local; the constants
   assigned after the two early exits instead of initialised at the top (an
   initialiser pulls them into the entry block); the base and the constants in
   the other order; -G0 (there the $gp load is not possible at all).
   */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef int s32;

extern s32 D_L04_001B24DC __attribute__((sda));
extern char D_L04_001FB1E0[];

void func_L04_003E5298(s32 a0) {
    s32 v0 = *(u8 *)(a0 + 0x21);
    s32 v1;
    s32 a1;
    s32 a2;
    s32 t0;
    s32 a3;

    if (v0 == 0xFF)
        return;
    v1 = *(s32 *)(D_L04_001FB1E0 + v0 * 4);
    if (v1 == 0)
        return;
    a2 = D_L04_001B24DC;
    a0 = v1;
    t0 = 0x8BA;
    a3 = 1;
    for (;;) {
        v0 = *(u16 *)a0 & 0x7FFF;
        a1 = a2 + (v0 << 8);
        if (*(s8 *)(a1 + 0x20) >= 0) {
            if (*(s16 *)(a1 + 0xAA) == t0) {
                v0 = *(s32 *)(a1 + 0x68);
                *(u16 *)(v0 + 0x2A6) = a3;
            }
        }
        v0 = *(s16 *)a0;
        a0 += 2;
        if (v0 < 0)
            break;
    }
}
