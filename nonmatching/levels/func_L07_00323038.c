/* func_L07_00323038 - 584 bytes, 4 place(s), level 07_siberius, retail at
   0x00323038. Screened with tools/w10_screen.py: 7 call(s)
   [func_L00_0032C638@00323064, func_00283248@0032308C,
   func_L01_00322288@00323098, func_002B5BC0@003230AC,
   func_0029F530@003230B4, func_L07_00321D68@00323100,
   func_002A88A0@00323174]; data addresses materialised [-]; float constants
   [0x42800000, 0xbf000000, 0x44160000, 0x42700000, 0x3f800000, 0x40a00000,
   0x3f800000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [LQ/SQ 7C400000@0x021c].
   Head: addiu $sp, $sp, -0x50 ; sd $s0, 0x10($sp) ; swc1 $f23, 0x48($sp) ;
   daddu $s0, $a0, $zero ; swc1 $f22, 0x40($sp) ; mov.s $f23, $f13. Not
   matched in this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C
   reaches it only through a `mode(TI)` local, and this cc1 folds the
   destination offset into the `sq` where retail materialises the pointer
   first. What would unblock it: the exact source expression tree, so this
   cc1 picks the same registers in the same order. */

/* Fresh reconstruction, 23 October 2026; supersedes the historical MMI
   screening above. Game -O2 -G8 -ffunction-sections -frac2-zero-ti-barrier
   -frac2-qcopy -frac2-qcopy-barrier -g: 584/584 bytes, 0/4 USA v1.01 and
   0/4 USA v2.00 placements; absent from PAL. Only two nonrelocation words
   differ: at +0x214/+0x21c C emits a por zero plus offset sq, while retail
   materializes control +0xa0 then stores architectural zero at offset zero.
   Separate division statements with -g reproduce retail's hazard padding;
   reusing the remaining-height variable recovers the f13 duration register.
   Six bounded legal trials included pointer-form and builtin memset clears;
   memset grew to 592 bytes. No artificial barriers or volatile are retained.
   Reopen with an independently supported zero-store address formulation or
   qualified compiler model, keeping the measured quadratic-helper ABI. */
#include "include_asm.h"
typedef int Quad __attribute__((mode(TI)));
extern unsigned int func_L00_0032C638(unsigned int);
extern float func_00283248(float, float);
extern int func_L01_00322288(int, float);
extern void func_002B5BC0(void *, void *, float);
extern float func_0029F530(char *);
extern int func_L07_00321D68(char *, void *);
extern int func_002A88A0(float *, float *, float, float, float);
extern int D_L07_001B1E08 __attribute__((sda));

int func_L07_00323038(unsigned char *object, float lower, float target, float upper)
{
    float roots[2];
    char *control = (char *)func_L00_0032C638((unsigned int)object);
    float current;
    if (!control)
        return 0;
    *(int *)(control + 0xbc) = D_L07_001B1E08;
    if (!(*(int *)(control + 0x38) & 0x10))
        func_L01_00322288((int)object, func_00283248(*(float *)(control + 0xa0), *(float *)(control + 0xa4)));
    func_002B5BC0(object, control, 64.0f);
    current = func_0029F530((char *)object);
    if (object[0x42] == object[0x43] && lower <= current && current <= upper) {
        float remaining;
        *(float *)(control + 0xa8) -= *(float *)(control + 0x2c);
        func_L07_00321D68((char *)object, control + 0xa0);
        remaining = *(float *)(control + 0xa8);
        if (remaining > 0.0f) {
            float frames = remaining / *(float *)(control + 0x2c);
            float change = target - current;
            change += change;
            change /= frames;
            *(float *)(object + 0x48) = change;
        } else if (*(float *)(object + 0x18) > *(float *)(control + 0x90)) {
            float gravity = *(float *)(control + 0x2c) * -0.5f;
            int count = func_002A88A0(roots, roots + 1, gravity,
                        remaining - gravity,
                        *(float *)(object + 0x18) - *(float *)(control + 0x90));
            float change;
            remaining = 600.0f;
            if (count > 0 && roots[0] > 0.0f && roots[0] < 60.0f)
                remaining = roots[0];
            change = upper - current;
            change += change;
            change /= remaining;
            *(float *)(object + 0x48) = change;
        } else {
            *(float *)(object + 0x18) = *(float *)(control + 0x90);
            *(float *)(object + 0x48) = 1.0f;
        }
        if (*(float *)(object + 0x48) > 5.0f)
            *(float *)(object + 0x48) = 5.0f;
        else if (*(float *)(object + 0x48) < 0.0f)
            *(float *)(object + 0x48) = 0.0f;
    } else {
        *(float *)(object + 0x48) = 1.0f;
    }
    if (object[0x60] & 2) {
        Quad *motion = (Quad *)(control + 0xa0);
        *(float *)(object + 0x18) = *(float *)(control + 0x90);
        *motion = 0;
        return 1;
    }
    return 0;
}
