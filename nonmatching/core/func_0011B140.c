/* from src/core/0011A830.c: store 4 to 0x1000F000, `sync`, poll bit 2 there until it is
   set or the caller's sp+0 flag turns non-zero, call func_0011F5E0 (and func_0011F628
   when it reports non-zero), store 4 to 0x1000F000 again with a second `sync`, and return
   the 8-byte value func_0011AF90 left at sp+8. The two `sync` barriers are in the retail
   bytes and this cc1 emits none from C, so the 164 bytes cannot match. The body below is
   the behaviour (for the port), not a candidate. */
extern void func_0011AF90(int *, long long *);

extern int func_0011F5E0(void);

extern void func_0011F628(void);

long long func_0011B140(void) {
    int flag = 0;
    long long value;
    volatile unsigned int *d = (volatile unsigned int *)0x1000F000;
    int r;

    func_0011AF90(&flag, &value);
    r = func_0011F5E0();
    *d = 4;
    if (r != 0)
        func_0011F628();
    while ((*d & 4) == 0 && flag == 0)
        ;
    r = func_0011F5E0();
    *d = 4;
    if (r != 0)
        func_0011F628();
    return value;
}

/* Wave 24 (worker 05): the `sync` wall confirmed, and the rest of the body
   measured.  Neither the game's cc1 nor the SDK's cc1 can emit `sync`: the
   reconstructed compiler has no pattern for it (no "\tsync" in
   build/compiler/tools/cc1 and none in build/compiler/sdk/cc1), so the
   instruction can only come from an inline asm statement, which src/
   forbids.  With the attempt below check.py (boot) reports "152 bytes,
   expected 164" - the twelve bytes are the two syncs (8) and the position of
   the `sd $ra`.

   What is measured and right:
   - the two stack objects are an int flag at 0x00 (retail `sw $zero,0x0($sp)`)
     and a 64-bit result at 0x08 (retail `ld $v0,0x8($sp)`), so the result is
     an unsigned long long: a signed one costs the sign extension
     (`dsll32`/`dsra32`) that retail does not have.
   - the flag is read inside the loop, so it is volatile (retail reloads
     `lw $v0,0x0($sp)` every pass); the loop is a do-while, the register's
     bit-2 test comes first and the flag's test is the back edge.
   - the two calls to func_0011F5E0 are two separate calls: the first one's
     result is tested right after the first store (retail `beqz $v0`), the
     second one's after the second store, so the value is not kept in a
     callee-saved register (that would add the $s0 save retail does not
     have).
   - the second store goes to the same address as the first one, 0x1000F000:
     retail's `lui $at,0x1001` + `sw $v1,-0x1000($at)` is %hi(0x1000F000) and
     %lo(0x1000F000); the address 0x10010000 would give an offset of 0.
   - the first address is used again in the loop, so it is materialised with
     lui+ori; the second one is used once, so it is lui+%lo.  */
extern int func_0011AF90(void *, void *);
extern int func_0011F5E0(void);
extern int func_0011F628(void);

unsigned long long func_0011B140_w24(void) {
    volatile int flag = 0;
    unsigned long long result;
    int v;

    func_0011AF90(&flag, &result);
    v = func_0011F5E0();
    *(volatile int *)0x1000F000 = 4;
    if (v != 0) {
        func_0011F628();
    }
    do {
        if ((*(volatile int *)0x1000F000 & 4) != 0) {
            break;
        }
    } while (flag == 0);
    v = func_0011F5E0();
    *(volatile int *)0x1000F000 = 4;
    if (v != 0) {
        func_0011F628();
    }
    return result;
}
