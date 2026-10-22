/* func_00350378 - 228 bytes, 28 places (the boot and every level).

   Near miss: the shape is right (the four outputs of func_0034F960 in a
   16-byte stack array, the clamps, the two calls and the return test), but the
   register allocation differs: the retail puts the object pointer in $s3 and
   the constant 0xD9100 in $s4, this C puts the object pointer in $s4 and the
   constant in $s3, and the two reads of the caller's structure come out in the
   opposite order.

   The argument order of the two calls matches the retail
   (func_0034F960(ring, out, out+1, out+2, out+3) and
   func_00350460(out[0], out[1], out[2], out[3], s2, s0, object, s1)).

   Measured: the declaration order, the order of the two structure reads, the
   use of a named local for the 0xD9100 constant and the for-init order all
   leave the allocation unchanged.

   Note: the retail's func_0034FA30 leaves its last value in $v0 and the
   caller reads it, so the original prototype of func_0034FA30 returned an int
   even though src/game/0034CEA0.c declares it void.  Declaring it int leaves
   its own body byte-identical, but the change is not taken here because this
   function is not matched.
*/

extern char *D_001B23CC[] __attribute__((sda));
extern int func_00350460(int, int, int, int, int, int, int, int);
extern int func_0034FA30(int *, int);

int func_00350378(void *unused, int *a1, void *a2)
{
    int out[4];
    int v1 = *(int *)((char *)a2 + 0x50008);
    unsigned int ring = 0xD9100;
    unsigned int s2 = (unsigned int)a1[2] + 4;
    int s1 = a1[3] - 4;
    int s0 = (int)((char *)a2 + v1);
    unsigned int t;

    t = s2 - (unsigned int)v1;
    s2 = (s2 < (unsigned int)s0) ? s2 : t;
    s0 = s0 - (int)s2;
    s0 = (s1 < s0) ? s1 : s0;
    func_0034F960((int *)((char *)D_001B23CC[0] + ring), out, out + 1, out + 2, out + 3);
    s1 = s1 - s0;
    func_00350460(out[0], out[1], out[2], out[3], (int)s2, s0, (int)a2, s1);
    s0 = func_0034FA30((int *)((char *)D_001B23CC[0] + ring), out[0]);
    return s0 > 0;
}
