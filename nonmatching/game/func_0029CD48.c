/* func_0029CD48 - near miss (worker 3, wave 3).
 *
 * The candidate is the right size (240 bytes) and most of it matches: the frame
 * (0x10), the call to func_00115484 with its three arguments and the load of
 * state+0x80 in the delay slot, the twelve zero stores into D_00138180
 * (+0x1A0..+0x1CC, the last one in the call's delay slot), the call to
 * func_0029CD20 with D_001A7B90[0], the calls to func_336DA8 and func_34E5C0
 * and the two callback slots at +0x734C and +0x7350 of the level object.
 *
 * What still differs (all in the tail, plus one register):
 *
 *  1. The third call's argument order.  The retail sets the second argument up
 *     first and leaves the first argument (the move of the previous call's
 *     result) in the delay slot:
 *         lui $a1,0x4 ; jal func_34E5C0 ; daddu $a0,$v0,$zero
 *     this compiler emits the move first and puts the constant in the delay
 *     slot.  Measured: the same order only appears when another call follows
 *     the call in the source (a `jal` after it), which the retail has not.
 *  2. The tail.  The retail reads D_001A79F0 first and stores it to D_001A8CFC
 *     in the branch's delay slot:
 *         lui $v1,0x1A ; lw $v1,0x79F0($v1) ; addiu $v0,$zero,0x1F5 ;
 *         bne $v1,$v0 ; sw $a1,-0x62F4($gp)
 *     this compiler moves the store in front of the load (the alias pass
 *     reorders them: they are different objects, so the load may sink below
 *     the store) and leaves the delay slot to the branch target's first
 *     instruction.  The store is then not $gp-relative either: with the
 *     symbol's size unknown the assembler expands `sw $5,D_001A8CFC` into
 *     lui+sw, and only a delay slot or a known size (.extern SYM,4, which the
 *     sda attribute gives) produces the gp-relative form.
 *  3. The base register of the twelve zero stores is $v0 here and $v1 in the
 *     retail, and the constant 0x1F5 and the loaded value take $v1/$v0 there
 *     and $v1/$a0 here.
 *
 * What was tried: the store order of the twelve zero stores (ascending source
 * order is the one that matches), D_001A79F0 as a plain extern, as an array,
 * with NOT_SDA (section .data, needed for the non-$gp access) and volatile;
 * D_001A8CFC as a plain extern, as an sda array and as a volatile pointer;
 * the source order of the load and the store (both orders, and the store after
 * the if/else); the load in a variable, in a volatile variable and in the
 * comparison's right operand (0x1F5 + (D_001A8CFC = obj, 0)); the third call
 * as a nested call and with the result in a variable, and with 32-bit and
 * 64-bit argument types; -fno-schedule-insns (the tail's branch and the
 * registers then match, but the store order of the zeros and the sizes do not).
 *
 * What would unblock it: a source shape that keeps the store to D_001A8CFC
 * behind the load of D_001A79F0 and lets the branch's delay slot take it (the
 * store has to be the last instruction of the block, and it has to be
 * $gp-relative), and one that makes this compiler set the third call's second
 * argument up before the first.
 */

extern char D_001BAEC0[];
extern int D_00138180[];
extern int D_001A79F0 __attribute__((section(".data")));
extern char *D_001A8CFC;
extern int D_001A7B90[];

extern void func_00115484(void *, int, int);
extern void func_0029CD20(int);
extern int func_336DA8(int, int);
extern int func_34E5C0(int, int);
extern void func_0029C0D0(void);
extern void func_0029C108(void);
extern void func_0029C0D8(void);
extern void func_0029CD18(void);

/* The level object's callback table: the two slots at +0x734C and +0x7350. */
typedef struct { char pad[0x734C]; void *cb1; void *cb2; } SubBf;

void func_0029CD48(void)
{
    char *state = D_001BAEC0;
    char *obj;
    int mode;

    func_00115484(*(int *)(state + 0x80), 0xCD, 0x40000);
    D_00138180[104] = 0;
    D_00138180[105] = 0;
    D_00138180[106] = 0;
    D_00138180[107] = 0;
    D_00138180[108] = 0;
    D_00138180[109] = 0;
    D_00138180[110] = 0;
    D_00138180[111] = 0;
    D_00138180[112] = 0;
    D_00138180[113] = 0;
    D_00138180[114] = 0;
    D_00138180[115] = 0;
    func_0029CD20(D_001A7B90[0]);
    mode = func_336DA8(0x3F490, *(int *)(state + 0x80));
    obj = (char *)func_34E5C0(mode, 0x40000);
    mode = D_001A79F0;
    D_001A8CFC = obj;
    if (mode == 0x1F5) {
        ((SubBf *)(obj + 0x38000))->cb1 = func_0029C0D0;
        ((SubBf *)(obj + 0x38000))->cb2 = func_0029CD18;
    } else {
        ((SubBf *)(obj + 0x38000))->cb1 = func_0029C108;
        ((SubBf *)(obj + 0x38000))->cb2 = func_0029C0D8;
    }
}
