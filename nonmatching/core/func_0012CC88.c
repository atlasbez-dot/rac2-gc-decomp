/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: SDK EE-GCC 2.9-ee-991111-01.
 * Profile: sdk -O2 -G2 -ffunction-sections.
 * Reported final C / retail: 284 / 296 bytes; size equality is not a match.
 * us: 0/1 placements.
 * us2: not run: US candidate failed.
 * pal: not run: US candidate failed.
 * Residual: Retained readable eleven-callback extension dispatcher. Three 284-byte tied forms; u64 index 292/296 with extra sign extension; bound/register allocation unresolved.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* from src/core/0012C9C8.c: an MPEG header dispatcher. It copies 0x2C bytes (11 words) of
   a read-only table at 0x13BBC8 onto the stack with an unaligned ldl/ldr copy, calls
   func_12C9C8(s), reads a two-bit code, then calls through the copied table with
   `jalr` - `table[code > 10 ? 0 : code](s)` - before a func_12C788/func_12C680 loop that
   compares the result against 0x1B5 and 0x1B2. The copy-to-stack of an 11-pointer local
   array with initializers is the shape to reproduce first. */

/* Expanded screening: sdk -O2 -G2 -ffunction-sections.
 * Four forms: three equivalent 284/296-byte bodies (32-bit index and sizeof-bound forms tie), one 292/296 unsigned-long index body with extra sign extension. Retail saves the bound 10 in s2 and uses sltu/movn; C emits immediate sltiu/movz and one fewer saved register. Reopen with a truthful bit-reader return-width or loop-bound hypothesis.
 * tools/check.py func_0012CC88 --diff --version us: 0 of 1 places; exit 1.
 */
extern void func_00130890(void *);
extern void func_001309C0(void *);
extern void func_00130A50(void *);
extern void func_00130A60(void *);
extern void func_00130A70(void *);
extern void func_00130A80(void *);
extern void func_0012D100(void *);
extern void func_0012D1C8(void *);
extern void func_0012D2C0(void *);
extern void func_0012CDB0(void *);

/* MPEG extension and user-data start-code dispatch. */
void func_0012CC88(void *state) {
    void (*handlers[11])(void *) = {
        func_00130A60, func_00130890, func_001309C0, func_0012D100,
        func_0012D2C0, func_00130A50, func_00130A60, func_0012D1C8,
        func_0012CDB0, func_00130A70, func_00130A80
    };
    int code;
    unsigned int extension;
    func_0012C9C8(state);
    while ((code = func_0012C680(state, 32)) == 0x1B5 || code == 0x1B2) {
        if (code == 0x1B5) {
            func_0012C788(state, 32);
            extension = func_0012C878(state, 4);
            if (extension >= sizeof(handlers) / sizeof(handlers[0])) extension = 0;
            handlers[extension](state);
            func_0012C9C8(state);
        } else {
            func_0012C788(state, 32);
            func_0012C9C8(state);
        }
    }
}
