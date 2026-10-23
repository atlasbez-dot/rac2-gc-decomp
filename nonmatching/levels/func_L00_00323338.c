/* func_L00_00323338 - 272 bytes, 15 place(s), level 00_aranos_tutorial,
   retail at 0x00323338. Measured with tools/check.py --diff in the private
   checker root (2026-10-22): 268 of 272 bytes in the compiled object, the
   body matches the retail instruction for instruction except for the
   register allocation, one 16-bit copy and one missing copy.

   What the retail does (level 04_barlow, 0x003456D0):
     - frame 0xC0; locals: two 16-byte vectors at sp+0 and sp+0x10, a
       0x40-byte buffer at sp+0x20; $f20 holds the running minimum;
     - the loop walks the records of the array at $a1 (0x40 bytes each),
       measuring the vector at +0x30 of every record with func_00282E48
       (&local, record+0x30) and keeping the smallest distance; the
       distance limit is the constant 9999.0f (retail word 0x461C3C00);
     - the best record is copied with func_00283698 into the local buffer,
       handed to func_00283678 with the last argument, and its vector at
       +0x30 is copied to *($t1);
     - the return value is the index of the best record (the caller stores
       it as a byte, see 0x003459CC / 0x00345B28 in 04_barlow).

   What this cc1 does with the C below:
     - 9999.0f calibrates to the retail word 0x461C3C00; 9992.0f does not
       (it gives 0x461C2000);
     - the two vectors and the buffer have to be one 0x60-byte local, and
       the address of that local has to be kept in a register (a `void *`
       variable holding &local does that: retail `daddu $s4,$sp,$zero` and
       `daddu $a0,$s4,$zero`; without it cc1 rematerialises `daddu
       $a0,$sp,$zero`);
     - the last 16-byte copy is folded into the lq by cc1 (`lq $v1,
       0x30($s0)`) where retail materialises the address first (`addiu
       $s0,$s0,0x30 ; lq $v0,0x0($s0) ; sq $v0,0x0($fp)`). The
       -frac2-qcopy profile produces retail's three instructions exactly,
       but it also groups the two local vector copies (`lq ; sq` adjacent)
       where retail keeps them apart, so the profile cannot be used for
       this unit as a whole (blocker 09);
     - retail copies the first argument into $s0 (`daddu $s0,$a0,$zero`)
       although the argument is never read. Every spelling tried here
       (`char *p = a0;` with p overwritten later, the same with p assigned
       in the `if` branch, the same with the parameter itself assigned) has
       its copy removed by cc1's dead-store pass; the copy only survives
       when the parameter stays live after the `if` (`p` used after it),
       which changes what the function does when count is zero. The
       missing copy also shifts the whole allocation: retail has
       $s0=a0/p, $s1=index, $s2=best, $s3=count, $s4=&local, $s5=buffer,
       $s6=records, $s7=context, $fp=destination, while this C gives
       $s0=p, $s1=index, $s2=buffer, $s3=count, $s4=best, $s5=&local,
       $s6=records, $s7=context, $fp=destination.

   What would unblock it: the source spelling that keeps the copy of the
   unused first argument (which also fixes the allocation), and the one
   that makes cc1 materialise the address of the last 16-byte copy
   without grouping the two local ones. */

extern float func_00282E48(void *, void *);

extern void func_00283698(void *, void *);

extern void func_00283678(void *, void *);

#ifndef RAC2_T_V4TI_F36D8A248
#define RAC2_T_V4TI_F36D8A248
typedef int V4TI_F36d8a248 __attribute__((mode(TI)));
#endif

int func_L00_00323338(void *a0, void *records, int count, void *src0, void *src1,
                      void *dst, void *ctx)
{
    struct {
        V4TI_F36d8a248 v0;
        V4TI_F36d8a248 v1;
        char buf[0x40];
    } local;
    void *lp = &local;
    char *p;
    int i = 0;
    int best = 0;
    float bestf = 9999.0f;

    local.v0 = *(V4TI_F36d8a248 *)src0;
    local.v1 = *(V4TI_F36d8a248 *)src1;
    if (count > 0) {
        p = (char *)records + 0x30;
        do {
            float f = func_00282E48(lp, p);
            if (f < bestf) {
                bestf = f;
                best = i;
            }
            i++;
            p += 0x40;
        } while (i < count);
    }
    p = (char *)records + (best << 6);
    func_00283698(local.buf, p);
    func_00283678(ctx, local.buf);
    p += 0x30;
    *(V4TI_F36d8a248 *)dst = *(V4TI_F36d8a248 *)p;
    return best;
}
