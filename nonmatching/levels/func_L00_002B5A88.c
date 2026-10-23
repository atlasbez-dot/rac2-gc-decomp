/* func_L00_002B5A88 (212 bytes, 27 places) -- NEAR MISS, not integrated.
   Wave 8 w8-10: 204 bytes (51 instructions) against 212 (53). The loop shape is now
   the retail's: the producer call sits at the top of the body, its `== 1` test is the
   exit, and the counter test is the back edge. Two instructions still differ.

   What was measured:
   - The `for` form is ROTATED by this cc1 (the call moves to the bottom and the break
     test becomes the back-edge test); the `do { ... } while (i < 16);` form is NOT
     rotated and reproduces the retail's block order exactly. That alone is the win of
     this rewrite (the previous for-form draft was 200 bytes with a rotated body).
   - The resident block must be reached through a struct with `int i23C4` at 0x23C4 and
     `int i23C8` at 0x23C8: the `%hi` of D_00189E20 then stays in $s3 and the base is
     re-materialised with `addiu $a1,$s3,-0x61E0` at every access, exactly like the
     retail. A `char *` base gives the same reloads but moves the base into $s0 and
     reshuffles the whole prologue (204 bytes as well, wrong registers).
   - The retail's `bnel $v0,$zero` with a DEAD load of 0x23C4 in its delay slot is the
     last structural difference: this cc1 emits a plain `bnez` and puts the useful load
     of 0x23C4 in the slot, so the retail's body carries one load more (0x23C4 is read
     at +0x5C, +0x60 and +0x8C, this draft reads it twice).
   - The `(x + 31) % 32` sequence (slt/addiu/movn/sra/sll/subu) matches exactly, and so
     do the lq/sq quadword copy, the ring base `$s1 + 0x1D10` and the six callee-saved
     registers ($s0 counter, $s1 table, $s2 -1, $s3 %hi, $s4 ring, $s5 1).
   - What would unblock it: the source shape that makes this cc1 pick the branch-likely
     form and keep a dead load in the slot (a `bnel` whose slot is annulled on the
     fall-through path). */
extern int func_L00_002B55F0_1(int);

typedef unsigned char u8;
typedef float f32;
typedef int V4_Fa012328c __attribute__((mode(TI)));

typedef struct { f32 x, y, z, w; } V4_F6b9e759f;

typedef struct {
    u8 pad[0x23C4];
    int i23C4;
    int i23C8;
} Resident;

extern Resident D_00189E20;
extern V4_F6b9e759f D_00189EA0_1[];

void func_L00_002B5A88(void)
{
    V4_F6b9e759f *tbl = D_00189EA0_1;
    V4_F6b9e759f *ring = tbl + 465;
    int i;

    i = 0;
    do {
        if (func_L00_002B55F0_1(i) == 1)
            break;
        if (D_00189E20.i23C8 >= 2) {
            D_00189E20.i23C8 = D_00189E20.i23C8 - 1;
            D_00189E20.i23C4 = (D_00189E20.i23C4 + 31) % 32;
        }
        *(V4_Fa012328c *)tbl = *(V4_Fa012328c *)&ring[D_00189E20.i23C4];
        i++;
    } while (i < 16);
}
