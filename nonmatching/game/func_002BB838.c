/* func_002BB838 (236 bytes, 28 places) - near miss.
 *
 * The body is recovered: the frame, the six callee-saved registers, every
 * branch, every store, both 16-byte copies, the division and the epilogue are
 * the retail's, in the retail's order.  Two things are left.
 *
 * 1. The 16-byte copy needs the retail's materialised destination
 *    (`addiu $v1,$s1,0x10 ; lq $v0,0($s0) ; sq $v0,0($v1)`).  Plain C folds the
 *    offset into the `sq`; `-frac2-qcopy` gives the retail's form.
 * 2. With that flag, this cc1 hoists the 4.0f of the `func_00283CF0(4.0f)`
 *    call to the top of the basic block, before the copy:
 *
 *      ours:   lui $at,0x4080 ; mtc1 $at,$f12 ; lq ; sq ; sw ; jal ; addiu
 *      retail: lq ; sq ; lui $at,0x4080 ; mtc1 $at,$f12 ; addiu ; jal ; sw
 *
 *    The load is not scheduled there (it is already at the top of the block
 *    with -fno-schedule-insns): the reload puts a float constant at the start
 *    of the block.  Measured: the same source with an integer constant store
 *    in the block keeps the float constant at the use point, so the trigger is
 *    the reload's constant placement, not the scheduler.
 *
 * The flags used: -O2 -G0 -ffunction-sections -frac2-qcopy.
 * Last check line: "boot: instruction at +0x54 differs" (0 of 28 places).
 */
extern void *func_002B9030(int kind);
extern int func_00283CF0(float f);
extern float func_00283CE0(int n);
extern unsigned char *D_001F2560;

typedef int TI128_002BB838 __attribute__((mode(TI)));

void func_002BB838(void *a0, void *a1, int a2, int a3, int a4, float f)
{
    void *p;
    char *q;
    int v;
    float w;

    if (a4 == 0)
        return;
    p = func_002B9030(8);
    if (p == 0)
        return;
    *(TI128_002BB838 *)((char *)p + 0x10) = *(TI128_002BB838 *)a0;
    *(int *)((char *)p + 4) = a2;
    v = func_00283CF0(4.0f);
    q = (char *)p + 0x20;
    *(unsigned char *)((char *)p + 9) = (unsigned char)(v - 0x60);
    *(unsigned char *)((char *)p + 3) = 0x48;
    *(unsigned char *)((char *)p + 1) = 0;
    *(int *)((char *)p + 0xC) = 0;
    *(unsigned char *)((char *)p + 8) = 0;
    *(unsigned char *)((char *)p + 2) = *D_001F2560;
    *(TI128_002BB838 *)q = *(TI128_002BB838 *)a1;
    *(short *)((char *)p + 0xA) = a4;
    *(int *)(q + 0x18) = a4;
    w = f / func_00283CE0(a4);
    *(int *)(q + 0x14) = a3;
    *(int *)(q + 0x10) = a2;
    *(float *)(q + 0x1C) = w;
}
