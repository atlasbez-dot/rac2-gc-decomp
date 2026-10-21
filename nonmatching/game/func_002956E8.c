/* func_002956E8 - 160 bytes, 28 places (the boot and every level).

   Near miss: the structure is right (the early return, the two table tests,
   the scan loop over the five slots and the call to func_00295788), but three
   details differ:

   1. the early return uses the branch-likely form here (`bnel $s0,$zero`) where
      the retail uses a plain `bnez $s0`;
   2. the retail keeps the *high* half of D_001C4FA0 in $a2 (`daddu $a2,$v1,$zero`)
      and rematerialises the base inside the loop (`addiu $a1,$a2,0x4FA0`), while
      this C keeps the whole address in one register and lets the compiler
      strength-reduce the loop's pointer into `addiu $v1,$v1,4`;
   3. with the strength reduction gone the loop's back edge and the null test
      come out with the opposite branch polarity.

   Measured: -fno-strength-reduce removes the strength reduction and gives the
   retail's loop shape, but the base is then kept in $a0 instead of being
   rematerialised from %hi, and the early return is still branch-likely.  No
   source spelling tried reaches the retail bytes.

   What would unblock it: a source shape that keeps %hi(D_001C4FA0) in a
   register (so the compiler rematerialises the base per iteration) while the
   pointer arithmetic is still strength-reduced, and a plain branch for the
   early return.

   The five slots of the resident table are at byte offsets 0x288 (in use),
   0x28C, 0x29C (the "busy" flag) and 0x2A0 (the same flag of the parent).
*/

extern int D_001C4FA0[];
extern int func_00295680(int);
extern void func_00295788(int, int);

int func_002956E8(void)
{
    int slot = func_00295680(1);
    int *p;

    if (slot != 0)
        return slot;
    if ((D_001C4FA0[0xA8] & 0x1000) == 0) {
        slot = 1;
        if (D_001C4FA0[0xA3] != 0)
            goto call;
        slot = 2;
    }
    while (slot < 5) {
        p = D_001C4FA0 + slot;
        if (p[0xA7] & 0x1000) {
            slot++;
            continue;
        }
        if (p[0xA2] == 0) {
            slot++;
            continue;
        }
        break;
    }
call:
    func_00295788(0, slot);
    return slot;
}
