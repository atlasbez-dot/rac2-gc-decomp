/* func_00335798: near miss (worker 5, 22 October 2026).
 *
 * The whole call chain is recovered: the object comes from func_00270280(0x1B), the
 * table pointer from D_001B1504, the entry index from the short at +0x84 of the object,
 * the entry at table + index * 32 + 0x1C, its +0x20 field takes the third argument and
 * its +0x1D byte is set to 1; then four 16-byte copies (the two arguments, the two
 * quadwords at D_001B5340 and D_001B5350) go to the stack and func_00270598 is called
 * with the object, &stack[3] and 1.
 *
 * Measured with the compiler profile
 *     -O2 -G0 -ffunction-sections -frac2-qcopy -fno-schedule-insns -mno-split-addresses
 * (168 bytes, the retail's size) it still differs in eight instructions:
 *   - the prologue emits "sd $ra,0x58($sp)" before "daddu $s2,$a1,$zero", the retail
 *     has the move before the save;
 *   - the constant 1 (the byte stored at +0x1D and the third argument of the call) is
 *     in $a1/$a2 at two places, the retail keeps one $a2 from before the store to the
 *     call;
 *   - the address of D_001B5340 is materialised (lui/addiu) before the copies, the
 *     retail materialises it just before the copy that uses it;
 *   - the three stack destinations are in $v1/$a1/$a1, the retail uses $a1 for all three.
 *
 * What was tried: the plain profile (-O2 -G0 -ffunction-sections) folds the destination
 * offset into the sq (156 bytes) and drops the three copies' addresses; without
 * -frac2-qcopy the destination is "sq $v0,0x10($sp)" instead of the retail's
 * "addiu $a1,$sp,0x10 ; sq $v0,0($a1)"; two separate symbols (D_001B5340 and
 * D_001B5350) give 172 bytes, one pointer plus 0x10 gives the retail's
 * "addiu $v1,$v1,0x5340 ; ... ; addiu $v1,$v1,0x10"; -fno-schedule-insns2 and -O1 are
 * worse.  The order of the parameter copies in the prologue follows the order the
 * parameters are first used in the source, so that part is reachable.
 *
 * To unblock: an allocation/scheduling policy that keeps the materialised 128-bit
 * destination in one register ($a1) and emits the constant and the symbol address at
 * their retail places.
 */

typedef int TI128 __attribute__((mode(TI)));

extern void *func_00270280(int);
extern void func_00270598(void *, void *, int);
extern int D_001B1504;
extern char D_001B5340[];

void func_00335798(TI128 *p0, TI128 *p1, void *p2)
{
    TI128 v[4];
    char *obj = (char *)func_00270280(0x1B);
    char *table = (char *)D_001B1504;
    short idx = *(short *)(obj + 0x84);
    char *e = *(char **)(table + idx * 32 + 0x1C);
    char *c;
    int one = 1;

    *(void **)(e + 0x20) = p2;
    *(unsigned char *)(e + 0x1D) = one;
    v[0] = *p0;
    v[1] = *p1;
    c = (char *)D_001B5340;
    v[2] = *(TI128 *)c;
    v[3] = *(TI128 *)(c + 0x10);
    func_00270598(obj, &v[3], one);
}
