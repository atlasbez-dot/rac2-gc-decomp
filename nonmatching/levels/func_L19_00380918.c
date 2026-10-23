/* func_L19_00380918 (348 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 340 bytes, the second half byte for byte identical to retail; the first half
   (the state == 0 branch and its loop) differs in scheduling and register allocation.
   check.py (19_grelbin), with the source below:
     0038092C  addiu $v0, $zero, 0x1        |  lui   $v0, 0x0        <- ours
     00380930  addiu $t4, $zero, 0xFE       |  addiu $v1, $zero, 0x1
     00380934  sb    $v0, 0x20($a0)         |  lw    $t2, 0x0($v0)
     00380938  addiu $t3, $zero, 0xFD       |  addiu $t0, $t1, 0x10
     0038093C  addiu $t2, $zero, -0x1       |  sb    $v1, 0x20($a0)
   The state == 0 block's preamble (the constant 1, the 0xFE/0xFD/-1 constants, the
   pool load and the three pointers) is emitted in another order and another registers,
   and the last comparison of the first loop is inverted (ours branches with `bnel` and
   keeps the `lh` in the delay slot, retail branches with `beql` and keeps the store
   there).  Everything from 0x3809D0 on -- the second loop, the counter, the call to
   func_0029F338 -- is identical.

   What is measured and right:
   - the loop bounds are compared as signed integers: retail uses `slt $v0, $a1, $a3`
     where a pointer comparison would give `sltu`, so the source walks the level's
     struct with an int offset (i = 0x30; i < 0x50; i += 4) and the compiler
     strength-reduces that into the slot pointer, the id pointer and the end pointer.
   - the level's table is read through D_L19_001B2A1C[0] (the word at 0x1B2A1C) and
     indexed with id << 8: retail's `lui $t1, 0x1B; lw $t1, 0x2A1C($t1)`.
   - the counter of the second loop is a 32 bit int initialised in the block
     (`daddu $t2, $zero, $zero` is what this compiler emits for it there).
   - the moby handle list is eight ids at t0+0x10 and eight slots at t0+0x30, and the
     walk stops at t0+0x50; retail compares the slot pointer with that end pointer.
   Tried and not enough: the id pointer before the slot pointer and the other way
   round; the pool assignment before and after the state store; the pool as
   D_L19_001B2A1C[0] and as a char * variable; the slot and the id pointer as
   function locals and as block locals; the 0xFE/0xFD tests as one range test
   (that gives `addu; andi; sltu` instead of retail's two `beql`s) and as two tests.
   Next idea: the preamble's order and the `beql` of the last test are one scheduling
   decision; a source that pins the order of the four constants (1, 0xFE, 0xFD, -1)
   and of the three pointers may be what is left. */

extern char *D_L19_001B2A1C;
extern void func_0029F338(char *);

void func_L19_00380918(char *a0)
{
    char *s0 = *(char **)(a0 + 0x68);
    unsigned char state = *(unsigned char *)(a0 + 0x20);
    int i;
    int *idp;
    int *slot;
    char *m;

    if (state == 0) {
        char *pool;

        *(unsigned char *)(a0 + 0x20) = 1;
        pool = D_L19_001B2A1C;
        idp = (int *)(s0 + 0x10);
        for (i = 0x30; i < 0x50; i += 4, idp++) {
            slot = (int *)(s0 + i);
            m = pool + (*idp << 8);
            if (m == 0) {
                *slot = -1;
                continue;
            }
            if (*(unsigned char *)(m + 0x20) == 0xFE) {
                *slot = -1;
                continue;
            }
            if (*(unsigned char *)(m + 0x20) == 0xFD) {
                *slot = -1;
                continue;
            }
            *slot = *(short *)(m + 0xAA);
        }
        if (*(int *)s0 == 0) {
            *(unsigned char *)(a0 + 0x20) = 2;
            *(unsigned short *)(a0 + 0x34) |= 2;
            return;
        }
    } else if (state != 1) {
        return;
    }
    {
        char *pool = D_L19_001B2A1C;
        int n = 0;
        int id;
        int cur;

        idp = (int *)(s0 + 0x10);
        for (i = 0x30; i < 0x50; i += 4, idp++) {
            slot = (int *)(s0 + i);
            id = *idp;
            if (id == -1) {
                *slot = -1;
                continue;
            }
            cur = *slot;
            if (cur == -1) {
                *slot = -1;
                continue;
            }
            m = pool + (id << 8);
            if (m == 0) {
                *slot = -1;
                continue;
            }
            if (*(short *)(m + 0xAA) != cur) {
                *slot = -1;
                continue;
            }
            if (*(unsigned char *)(m + 0x20) == 0xFE) {
                *slot = -1;
                continue;
            }
            if (*(unsigned char *)(m + 0x20) == 0xFD) {
                *slot = -1;
                continue;
            }
            n++;
        }
        if (n < *(int *)s0)
            func_0029F338(a0);
    }
}
