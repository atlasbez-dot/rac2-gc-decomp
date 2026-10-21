/* func_L02_003C9D78 (340 bytes, 18 places) -- SCREENED, not matched.
   The unit reads a float through $gp (`lwc1 $f0, 0xFC8($gp)`, the level symbol at 0x1AFDB8),
   so it needs a -g8.c source unit of its own (AGENTS.md); the shared unit cannot carry it.

   What the retail does, as far as it is decoded here:
   - the kind byte at a0+0x20 picks the work: 0 calls func_002A7750(a0, 1, -1) and leaves;
     1 goes straight to the sub-object's flag check; anything else reads the float at
     sub+0x8 and, when it is below 1.0f, replaces it with the $gp constant, then reads
     the float at sub+0xC and, when that is below 1.0f too, takes the list at sub+0x10.
   - when the sub-object's word at +4 is clear, it is set to the kind byte and
     func_L02_003CA0A8 and func_L02_003C9ED0 are called on a0.
   - func_002AA2E8 is called with sub+0xC, 1.0f and the float at 0x1AFBC times 1/60
     (this cc1 folds `1.0f/60.0f` to the 0x3C888889 retail holds).
   - a three-iteration loop walks the list at sub+0x10: for every entry it copies the
     halfword at (sub+0x30 + 4*k - 0x10) to the entry's halfword at +0x34 and calls
     func_002AEC18(entry, the word at sub+0x30 + 4*k).
   - func_0029F338 is called on a0 and func_L00_002E6CF0 gets the result minus 0x5D80
     and a0 (the same shape as func_L02_003CEA28's last call).

   The draft below is that decode; it does not match yet. It differs from retail in the
   branch structure around the kind tests (retail branches on the kind byte with
   `beqz`/`beql` and keeps the sub-object pointer in $s0), in the register roles (retail
   holds the object in $s3, the sub-object in $s0 and the list in $s1) and in the float
   handling (retail keeps 1.0f in $f20 and the two tested floats in $f0). */

#include "include_asm.h"
#include "common.h"

extern void func_002A7750(unsigned char *, unsigned char, int);
extern void func_L02_003CA0A8(char *);
extern void func_L02_003C9ED0(char *);
extern float func_002AA2E8(float *, float, float);
extern void func_002AEC18(void *, int);
extern void *func_0029F338(void *);
extern void func_L00_002E6CF0(void *, void *);
extern float D_L02_001AFDBC;
extern float D_L02_001AFBC;

void func_L02_003C9D78(char *a0)
{
    unsigned char kind;
    char *sub;
    char *list;
    float f;

    kind = *(unsigned char *)(a0 + 0x20);
    if (kind == 0) {
        func_002A7750((unsigned char *)a0, 1, -1);
    } else {
        sub = *(char **)(a0 + 0x68);
        f = *(float *)(sub + 0x8);
        if (kind != 1) {
            if (f < 1.0f)
                f = D_L02_001AFDBC;
            f = *(float *)(sub + 0xC);
            if (f < 1.0f)
                list = (char *)sub + 0x10;
        }
        if (*(int *)(sub + 4) == 0) {
            *(int *)(sub + 4) = kind;
            func_L02_003CA0A8(a0);
            func_L02_003C9ED0(a0);
        }
        func_002AA2E8((float *)(sub + 0xC), 1.0f, D_L02_001AFBC * (1.0f / 60.0f));
        for (f = 3.0f; f > 0.0f; f -= 1.0f) {
            char *entry = *(char **)list;

            if (entry != 0) {
                *(unsigned short *)(entry + 0x34) = *(unsigned short *)(sub + 0x20 + (int)f * 4);
                func_002AEC18(entry, *(int *)(sub + 0x30 + (int)f * 4));
            }
        }
        func_L00_002E6CF0((char *)func_0029F338(a0) - 0x5D80, a0);
    }
}
