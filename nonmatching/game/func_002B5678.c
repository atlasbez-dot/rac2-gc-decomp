/* func_002B5678 (432 bytes, boot + 20 levels): near miss. Built alone (src/game/002B5678.c) with
   `-O2 -G0 -ffunction-sections -frac2-qcopy -frac2-zero-ti-barrier` this C is retail's 432 bytes and 6 of its 108 words
   differ, at every place (qcopy alone: 8 words; zero-ti-barrier alone: 18). The previous C, with a plain TI local
   `saved`, grouped nothing and folded `lq $v0,0x10($s2)`; the lever that made the copy apply is `saved` as a UNION with
   a TI member (`Vec4Q_002B5678`): a TI scalar local is expanded as a register load plus a store to an `addressof` slot,
   so cse folds the load's address (+0x10) before combine can group the pair, while a union is memory from the start
   and the copy is one mem-to-mem move. With it `position` (= self + 0x10) stays in $s0 across the first call
   (`addiu $s0,$s2,0x10 / daddu $a0,$s0 / daddu $a1,$s0 / jal / lq $v0,0($s0) / sq $v0,0($sp)`), as retail, and the rest
   of the function (the loop, the float tests, the last call) is exact.
   What is left:
     (a) the 16-byte clear (2 words). Retail: addiu $v0,$s1,0x60 / sq $zero,0($v0). Here: por $v0,$zero,$zero /
         sq $v0,0x60($s1). Spelled as the member (`ctl->q60 = 0`), through `(Quad *)((char *)ctl + 0x60)`, through a
         `Quad *` or a `char *` variable, or relative to another member (`out70 - 1`), the output is the same: cse folds the
         +0x60 into the store and the zero fold keeps the `por` for a displaced address (it needs a plain register address, so
         that `sq $zero` and the barrier of `-frac2-zero-ti-barrier` appear).
     (b) 4 words of the prologue order: retail `sd $s2 / sd $s0 / daddu $s2,$a0 / sd $s1 / addiu $s0,$s2,0x10 ... daddu $a0,$s0 /
         sd $ra / daddu $a1,$s0 / jal`; here `daddu $s2,$a0` before `sd $s0`, and `sd $ra` after `daddu $a1,$s0`. These follow from (a):
         with the clear written as `asm volatile ("sq $0,0(%0)" : : "r" ((char *)ctl + 0x60) : "memory")` (scratch only, never
         for src/) the prologue is exact, and only 3 words of the delay-slot order of `sw $zero,0x84($s1)` against the
         address add are left.
   What would unblock it: a way to keep the clear's address in a register (`addiu $v0,$s1,0x60` first) so that the clear
   is `sq $zero,0($v0)`: the same cse tie that folded the copies, which the grouped pattern removes for copies only.
*/
typedef int Quad_002B5678 __attribute__((mode(TI)));
typedef union { Quad_002B5678 q; float f[4]; } Vec4Q_002B5678;

typedef struct {
    char pad0[0x10];
    float pos[3];                       /* 0x10 */
} Self_002B5678;

typedef struct {
    char pad0[0x28];
    float f28;                          /* 0x28 */
    char pad1[0x60 - 0x2C];
    Quad_002B5678 q60;                  /* 0x60: cleared */
    char out70[0x10];                   /* 0x70: movement of this step (func_00282CF0 output) */
    int w80;                            /* 0x80 */
    int w84;                            /* 0x84: cleared */
    char pad2[0x90 - 0x88];
    float f90;                          /* 0x90 */
    char pad3[0xA0 - 0x94];
    float vel[3];                       /* 0xA0 */
    char pad4[0xB0 - 0xAC];
    float speed;                        /* 0xB0 */
} Ctl_002B5678;

extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282E20(void *);
extern void func_00282F70(void *, void *, float);
extern int func_00282948(void *);
extern int func_002B5D38(void *, void *);
extern int func_002B5E48(void *, void *);

void func_002B5678(Self_002B5678 *self, Ctl_002B5678 *ctl, float *target)
{
    Vec4Q_002B5678 saved;
    Quad_002B5678 *position = (Quad_002B5678 *)self->pos;
    int changed, i, r;
    float len;

    func_00282CC0(position, position, ctl->vel);
    saved.q = *position;
    ctl->w84 = 0;
    ctl->q60 = 0;
    changed = 0;
    for (i = 0; i < 8; i++) {
        r = func_002B5D38(self, ctl);
        r |= func_002B5E48(self, ctl);
        changed |= r;
        if (r == 0)
            break;
    }
    if (changed) {
        func_00282CF0(ctl->vel, self->pos, target);
        len = func_00282E20(ctl->vel);
        if (ctl->speed < len)
            func_00282F70(ctl->vel, ctl->vel, ctl->speed);
        else
            ctl->speed = len;
        if (self->pos[2] <= ctl->f90) {
            if (self->pos[2] < target[2])
                self->pos[2] = target[2];
            if (ctl->vel[2] < 0.0f)
                ctl->vel[2] = 0.0f;
        }
        if (ctl->speed < ctl->f28 * 0.5f)
            ctl->w80 += 1;
        else
            func_00282948(&ctl->w80);
    } else {
        func_00282948(&ctl->w80);
    }
    func_00282CF0(ctl->out70, self->pos, &saved);
}
