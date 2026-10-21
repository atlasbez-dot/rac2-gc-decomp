/* Near miss: 272 bytes, the retail size, and the body matches instruction for
   instruction except for the placement of two induction-variable updates.

   The retail body at 0x003830D8 (level 30) opens with

       lwc1 $f1,-0x428($gp)  /  addiu $sp,$sp,-0x30  /  lui $at,0x3F73  /  ori $at,$at,0x3333
       mtc1 $at,$f0  /  c.le.s $f0,$f1  /  bc1f ...

   and branches into a two-armed body: with the level's blend factor at or above 0.95 it
   resets the factor, calls func_L30_00382FB8 and copies two of the level's indices; below
   0.95 it clears the two indices and rewrites the whole 24x24 table at 0x00233A60, one
   cell at a time, as func_L30_00382EF0(f12, f13, factor) over the two neighbouring rows.
   The factor then grows by the second $gp word.

   Everything is in the retail order here: the loads, the stores, the two loops, the
   address arithmetic (D_001AEBBC * 0x900 + off, then the table) and the inner loop's
   countdown. What differs is where the two derived induction variables are updated: the
   retail computes the row base (sll $s0,$v1,2) before the outer counter
   (addiu $s4,$v1,0x1) and again in the back branch's delay slot, while this cc1 emits
   the counter first and the base second. Both spellings of the outer loop (for, do-while,
   while, the base computed at the top of the body or at its end, the base as an int or a
   pointer) give one order or the other, never retail's: with the base at the top of the
   body this cc1 keeps the base in $s0 and the counter in $s4 like retail, and the swap
   is the only difference left.

   It needs the -g8 sibling of the level unit: D_001AEBC8, D_001AEBCC, D_001AEBC0,
   D_001AEBC4, D_001AEBBC and D_001AEBB8 are small data below the boot's $gp (0x1AEFF0),
   so the unit is built with -G8 and the globals carry the sda attribute. */

extern float D_001AEBC8 __attribute__((sda));
extern float D_001AEBCC __attribute__((sda));
extern int D_001AEBC0 __attribute__((sda));
extern int D_001AEBC4 __attribute__((sda));
extern int D_001AEBBC __attribute__((sda));
extern int D_001AEBB8 __attribute__((sda));
extern char D_00233A60[];

extern void func_L30_00382FB8(void);
extern float func_L30_00382EF0(float, float, float);

void func_L30_003830D8(void) {
    if (0.95f <= D_001AEBC8) {
        D_001AEBC8 = D_001AEBCC;
        func_L30_00382FB8();
        D_001AEBC0 = D_001AEBBC;
        D_001AEBC4 = D_001AEBB8;
    } else {
        int i;
        int off;

        D_001AEBC4 = 2;
        D_001AEBC0 = 2;
        for (i = 0; i < 24; i++) {
            int j;

            off = i * 4;
            for (j = 23; j >= 0; j--) {
                float f12 = *(float *)(D_00233A60 + (D_001AEBBC * 0x900 + off));
                float f13 = *(float *)(D_00233A60 + (D_001AEBB8 * 0x900 + off));
                float f0 = func_L30_00382EF0(f12, f13, D_001AEBC8);

                *(float *)(D_00233A60 + (D_001AEBC0 * 0x900 + off)) = f0;
                off += 0x60;
            }
        }
    }
    D_001AEBC8 = D_001AEBC8 + D_001AEBCC;
}
