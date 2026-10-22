/* func_L02_003C4848 (344 bytes, 8 places) -- NEAR MISS, not integrated.
   state: the three loops match retail word for word, except that cc1 hoists the second
   and third loop's counter increment into the loop header, so two instructions per loop
   differ and the body is 340 bytes against retail's 344:

     003C48E4  addiu       $t0, $t0, 0x1    | lw          $a0, 0x68($v0)   <- ours
     003C4920  addiu       $t0, $t0, 0x1    | addiu       $t0, $t0, 0x1   <- retail

   The first loop (which holds a branch) keeps retail's bottom increment; the two loops
   without a branch get the header increment. What is left is a source spelling that
   keeps the increment at the bottom of the second and third loop.

   What is measured and right:
   - the 128-bit copy is retail's `lq`/`sq` pair with register addresses (the address is
     computed with `addiu` into a register and the lq/sq use offset 0). This cc1 emits
     the displacement form (`lq $v0,0x10($a0)`) unless the unit is built with
     -frac2-qcopy, the grouped copy the project's compiler adds for that (see
     tools/compiler/transformers/qcopy_pattern.py and the -frac2-qcopy unit
     src/levels/20_yeedil/L20_0039E158.c). This unit therefore needs -frac2-qcopy, and
     since the flag is per file it needs a unit of its own (the shared file also holds
     func_L02_003D1820, whose retail copies use the displacement form).
   - the constants are 1/60 (0x3C888889) for the second loop and 1/30 (0x3D088889) for
     the third: this cc1 folds `1.0f/60.0f` and `1.0f/30.0f` to exactly those bits.
   - the reload of the list element (`lw $v1,0x0($a2)`) before the copy's `sq` comes
     from reading the array element again in the source, not from a local pointer:
     `*(TI128 *)((char *)parent->f20[j] + 0x10) = *(TI128 *)((char *)sub->f18 + 0x10);`
     with the array element read again gives retail's reload and its register choice.

   Tried and not enough: three loop variables instead of two (the second and third loop
   share one, as retail does); the increment at the end of the body instead of in the
   for statement; the angle computed first, last or in place; the copy with the
   destination through a local pointer instead of the array element; -fno-schedule-insns
   (which changes the register allocation and does not restore the increment);
   -fno-schedule-insns2 (the same). */

typedef int TI128 __attribute__((mode(TI)));

struct L02ListObj {
    char pad0[0x34];
    unsigned short f34;
    char pad1[0x32];
    void *f68;
};

struct L02ListSub {
    char pad0[4];
    int f04;
    int f08;
    char pad1[8];
    int f14;
    int f18;
    struct L02ListObj *f1C;
};

struct L02TurnSub {
    char pad0[0x0C];
    float f0C;
    float f10;
    int f14;
    void *f18;
};

struct L02TurnObj {
    char pad0[0x10];
    char pad1[0x58];
    struct L02TurnSub *f68;
};

struct L02SpinSub {
    char pad0[4];
    float f04;
    int f08;
    float f0C;
    void *f10;
};

struct L02SpinObj {
    char pad0[0x10];
    char pad1[0x58];
    struct L02SpinSub *f68;
};

struct L02Parent {
    char pad0[8];
    int f08;
    char pad1[0x14];
    struct L02TurnObj *f20[20];
    struct L02SpinObj *f70[20];
    struct L02ListObj *fC0[20];
    int f110;
    int f114;
    int f118;
    int f11C;
    char pad2[0x10];
    int f130;
};

struct L02Arg {
    char pad0[0x68];
    struct L02Parent *f68;
};

void func_L02_003C4848(struct L02Arg *arg)
{
    struct L02Parent *parent = arg->f68;
    int i;
    int j;

    parent->f130 = 0x3C;
    for (i = 0; i < parent->f118; i++) {
        struct L02ListObj *obj = parent->fC0[i];
        struct L02ListSub *sub = obj->f68;

        sub->f04 = 0;
        sub->f14 = sub->f18;
        sub->f08 = 0;
        if (sub->f1C != 0)
            sub->f1C->f34 |= 0x41;
        parent->fC0[i]->f34 &= 0xFFBE;
    }
    for (j = 0; j < parent->f110; j++) {
        struct L02TurnObj *obj = parent->f20[j];
        struct L02TurnSub *sub = obj->f68;
        float angle;

        sub->f14 = 0;
        parent->f11C = 0;
        angle = (float)parent->f08 * (1.0f / 60.0f);
        sub->f0C = -1.0f;
        sub->f10 = angle;
        *(TI128 *)((char *)parent->f20[j] + 0x10) = *(TI128 *)((char *)sub->f18 + 0x10);
    }
    for (j = 0; j < parent->f114; j++) {
        struct L02SpinObj *obj = parent->f70[j];
        struct L02SpinSub *sub = obj->f68;

        sub->f08 = 0;
        sub->f04 = 1.0f / 30.0f;
        sub->f0C = -1.0f;
        *(TI128 *)((char *)parent->f70[j] + 0x10) = *(TI128 *)((char *)sub->f10 + 0x10);
    }
}
