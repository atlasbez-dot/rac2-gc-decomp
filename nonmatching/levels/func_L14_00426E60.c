/* Near miss from src/levels/14_aranos_prison/L14_003F4F98-g8.c: the build refuses this body at its
   place — instruction at +0x30 differs. Kept as a starting point;
   not linked, not counted. */

/* Standalone declarations recovered from src/levels/14_aranos_prison/L14_003F4F98-g8.c. */
extern float D_L14_001B17B8 __attribute__((sda));

extern float D_L14_001B17BC __attribute__((sda));

extern char D_00189EA0[];

extern int func_00282948(void *table);

extern void *func_L00_002D70A0(int size);

extern void func_L00_002D7140(void *block);

/* --- worker 08, wave 24: a much closer spelling, and what is left. ---
 *
 * The loop, the branch-likely forms, the condition check and the epilogue come
 * out as the retail has them, and the size is right (196 bytes):
 *
 *   retail                                this build
 *   beql $a1, $s4, .L00426EE0             beql $a1, $s4, .L00426EE0
 *   addiu $s2, $s2, 0x1  (delay slot)     addiu $s2, $s2, 0x1  (delay slot)
 *   jal f_00327F98                        jal func_002ACBC8
 *   beqz $v0, .L00426EE0                  beqz $v0, .L00426EE0
 *   addiu $s2, $s2, 0x1  (delay slot)     addiu $s2, $s2, 0x1  (delay slot)
 *   ...
 *   slti $v0, $s2, 0x4                    slti $v0, $s2, 0x4
 *   bnez $v0, .L00426E90                  bnez $v0, .L00426E90
 *   addiu $s0, $s0, 0x4  (delay slot)     addiu $s1, $s1, 0x4  (delay slot)
 *
 * The C below replaces the one above, which was a different loop shape (it
 * indexed the slots with a counter instead of walking a pointer) and failed
 * earlier, at +0x30.
 *
 * What is still different:
 *
 * 1. The register allocation of the two pointers.  The retail gives the slot
 *    pointer $s0 and the owner block $s1; this build gives the owner block
 *    $s0 and the slot pointer $s1.  The count is $s2 in both, and $s3/$s4 hold
 *    D_00189EA0 and -1 in both.  The allocation is the reload pass's, and it
 *    is the same in every spelling tried: the owner block declared first or
 *    second, the slot pointer computed from the owner block or from a0, both
 *    as int*, char* or void*, and with a temporary for the owner block.
 *
 * 2. The store of the two floats.  The retail reads the owner block's slot
 *    pointer four times (the test, the delay slot of a branch-likely, the
 *    reload after the store, and the reload for the second store) and keeps
 *    the branch-likely form; this build reads it three times and uses a plain
 *    `bnez`, so the float load lands in the delay slot instead of the reload.
 *
 * 3. The last test, `if (*(void **)(state + 0x14) != 0)`, is a branch-likely
 *    here and a plain `beqz` in the retail.
 */
extern int func_002ACBC8(char *, int);

void func_L14_00426E60(char *a0)
{
    char *state = *(char **)(a0 + 0x68);
    int *p = (int *)(state + 0x20);
    int count;

    for (count = 0; count < 4; p++) {
        if (*p == -1) {
            count++;
            continue;
        }
        if (func_002ACBC8(D_00189EA0, *p) != 0) {
            if (*(void **)(state + 0x14) == 0) {
                *(void **)(state + 0x14) = func_L00_002D70A0(5);
            }
            *(float *)*(void **)(state + 0x14) = D_L14_001B17B8;
            *(float *)((char *)*(void **)(state + 0x14) + 4) = D_L14_001B17BC;
            return;
        }
        count++;
    }

    if (*(void **)(state + 0x14) != 0) {
        func_L00_002D7140(*(void **)(state + 0x14));
        *(void **)(state + 0x14) = 0;
    }
}
