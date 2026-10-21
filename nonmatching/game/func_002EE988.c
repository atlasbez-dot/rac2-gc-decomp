/* func_002EE988 (boot function, 372 bytes; 28 places): near miss. Built alone (src/game/002EE988.c) with
   `-O2 -G0 -ffunction-sections -frac2-qcopy` it is retail's 372 bytes and 9 of its 93 words differ, at every
   place; all nine are in the block of the first copy (`*pd = D_001BAFA0`). Both profiles together
   (`-frac2-zero-ti-barrier` too) give the same bytes. The first 50 and the last 32 words, the other two copies
   (`*(V4 *)pos = *pe` and `= D_001BAFB0`) and every call are exact; the table pointer (`D_001B1C54` as `sda`
   gives `lui $s0` / `lw $s0,%lo($s0)`), the saves, the stack slots (five float[4] arrays declared in order,
   `d` at 0x30 and `e` at 0x40) and the pointers to d and e kept in $s2 and $s0 all match. The dead
   `object = 0;` of the earlier attempt is not needed with the profile (same 9 words without it).

   What differs (the first copy, then the call of func_00282D30):
     retail: beqz (slot: lui $a1,hi) / addiu $s2,$sp,0x30 / addiu $a1,$a1,lo / lq $v0,0($a1) / sq $v0,0($s2) /
             addiu $s0,$sp,0x10 / lui,ori,mtc1 $f12 / daddu $a0,$s0 / jal (slot: addiu $a1,$a1,0x20)
     here:   beqz (slot: lui $v1,hi) / addiu $s0,$sp,0x10 / addiu $s2,$sp,0x30 / addiu $v1,$v1,lo / lui,ori,mtc1 $f12 /
             addiu $a1,$v1,0x20 / lq $v0,0($v1) / sq $v0,0($s2) / jal (slot: daddu $a0,$s0)

   Cause (measured with -dS -dR -fsched-verbose-5): retail's copy is a scheduling barrier and the grouped copy is an
   ordinary insn. It has unit none, cost 1 and priority 9, so both schedulers issue it last: the f12 constant
   (priority 10), the address of `b` (10) and `$a1 = addr + 0x20` (9, with more dependents) all go first. The
   copy then still needs the address register when `$a1` is set, so the allocator puts the address in $v1; in retail
   the copy comes first, the address dies in the add and takes $a1. Check: the same C with
   `__asm__ __volatile__("" ::: "memory");` after the first copy (scratch only, never for src/) is `boot: OK`, 0 of
   93 words different. Without the barrier nothing measured changes the order.

   Tried without effect (about 40 compiles): the source in a pointer variable (`ps = &D_001BAFA0`, `*pd = *ps`,
   `(char *)ps + 0x20` or `(char *)(ps + 2)` for the argument); callee parameter orders of func_00282D30 (float first,
   float second); an explicit TI temporary (`V4 t = D_001BAFA0; *pd = t;` is two separate insns and the store folds to
   `sq $v0,0x30($sp)`); -fno-schedule-insns (368 bytes), -fno-schedule-insns2 (15 words), both together; the flag
   pair. What would unblock it: the grouped copy given the dependences of a volatile asm in the scheduler, as
   `-frac2-zero-ti-barrier` gives them to `sq $zero` (func_002B5E48 and func_002B50E0 are blocked by the same thing).
*/
typedef int V4 __attribute__((mode(TI)));
extern int func_002ED688(unsigned char *owner);
extern unsigned int func_002ED870(void);
extern void func_00282CF0(void *a0, void *a1, void *a2);
extern float func_00282DF0(char *a0);
extern void func_00282D30(char *a0, char *a1, float f);
extern void func_00282F20_10(V4 *, char *, float);
extern void func_00282CC0_26(char *, V4 *, char *);
extern int func_002761F8(char *a0, char *a1, int mode, char *self, int flag);
extern int func_00277258(char *a0, int mode, char *self, float scale);
extern V4 D_001BAFA0;
extern V4 D_001BAFB0;
extern char *D_001B1C54 __attribute__((sda));
extern int D_00214F90[];

void func_002EE988(char *owner)
{
    float a[4];
    float b[4];
    float c[4];
    float d[4];
    float e[4];
    char *object;
    char *pos;
    char *table;
    float len;

    if (func_002ED870() != 0)
        return;
    object = (char *)func_002ED688((unsigned char *)owner);
    if (object == 0)
        return;
    pos = object + 0x60;
    table = D_001B1C54 + D_00214F90[0] * 128;
    func_00282CF0(a, pos, table + 0x30);
    len = func_00282DF0((char *)a);
    if (*(float *)table < len) {
        func_00282F20_10((V4 *)a, (char *)a, len - (len - *(float *)table));
        func_00282CC0_26(pos, (V4 *)a, table + 0x30);
    }
    if (func_002761F8(owner + 0x10, pos, 2, owner, 0)) {
        V4 *pd = (V4 *)d;
        V4 *pe;
        *pd = D_001BAFA0;
        func_00282D30((char *)b, (char *)&D_001BAFA0 + 0x20, 0.00097656f);
        func_00282F20_10((V4 *)c, (char *)b, 5.0f);
        pe = (V4 *)e;
        func_00282CC0_26((char *)pe, pd, (char *)c);
        *(V4 *)pos = *pe;
    }
    if (func_00277258(pos, 2, owner, 5.0f)) {
        *(V4 *)pos = D_001BAFB0;
    }
}
