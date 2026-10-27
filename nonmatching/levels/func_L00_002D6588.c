/* func_L00_002D6588, 00_aranos_tutorial (+26 shared places), 392 bytes.
   Semantics fully decoded: zero-guard on the cruise zoom (base 0x151C -> 1.5f,
   c = 1.5f or 0.75f when *(int*)(base+0x2294) == 4), the three-record euler
   update (func_31DB00, func_2EE3D0, func_2EE108), the conditional cap store
   (*(int*)(base+0x229C) == 0x19 || *(int*)(base+0x2294) == 0x66 -> if
   *(float*)(base+0x14D8) < cap) and the tail: two 16-byte copies from
   D_0018B2F0/D_0018B2F0+0x10 into D_L00_001B8DC0/D_L00_001B8DC0+0x230
   (the level-bound D_L00_001B8FF0), then two func_2EE220/2EE3D0 pairs on the
   out+0x240 and out+0x250 buffers with 1.0f scale. func_2EE220 is really
   3-arg in this call shape: retail leaves its fourth register untouched and
   the C prototype (void*, void*, void*) matches.

   Best measured state (this deposit, via per-file flags
   `-O2 -G8 -ffunction-sections -frac2-qcopy -fno-schedule-insns -fno-gcse`):
   392/392 bytes, every instruction present, zero places matching - the residue
   is word-for-word intra-block scheduling of five independent address/argument
   instructions in the tail:

   retail                                          this cc1
   addiu v1 = a2 + 0x10   (after copy 1)           hoisted before copy 1
   addiu s1 = s0 + 0x240  (after copy 2)           hoisted before copy 1
   addiu a2 = a2 - 0x14B0 (before daddu a0)        after daddu a0/a1
   lui at,0x3F80/mtc1 f20 (after daddu a0)         before daddu a0
   jal 2EE220: delay daddu a1=s2                  delay: addiu s0=s0+0x250

   Flags measured independent:
   - without -fno-gcse the shared 1.0f is rematerialised per func_2EE3D0 site
     (lui/mtc1 f12 twice) where retail keeps it once in callee-saved $f20
     (prologue swc1 0x20, epilogue lwc1, mov.s f12,f20 at both sites) and the
     body is 2 instructions short;
   - with -fno-schedule-insns2 the two grouped copies come out copy2-first and
     the zero-guard allocates f1=load/f0=zero where retail wants f0=load/f1=zero
     (guard needs sched1 as it is);
   - without -frac2-qcopy the TImode copies fold displacement addressing where
     retail materialises both addresses (documented blocker-09 family).
   Not tried: source shapes that create artificial scheduling dependencies
   (this is plain-C territory), -fno-gcse on the caller file, and per-file
   -frac3-style sched controls if any land later. */
void func_L00_002D6588(void)
{
    extern void func_2EE3D0(void *out, void *in, float scale);
    extern void func_2EE108(void *out, void *in, char *angles);
    extern void func_2EE220(void *a0, void *a1, void *a2);
    extern void func_31DB00(char *a0, char *a1, float c, float rate, float rate2, float arg6);
    extern char D_L00_001B8DC0[];
    extern char D_0018B2F0[];

    typedef int TI128 __attribute__((mode(TI)));
    char *base = D_00189E20;
    char *out;
    float rate = 0.004444444552063942f;
    float one;
    float c;

    if (*(float *)(base + 0x151C) == 0.0f)
        *(float *)(base + 0x151C) = 1.5f;
    c = 1.5f;
    if (*(int *)(base + 0x2294) == 4)
        c = 0.75f;
    func_31DB00(base + 0x151C, base + 0x1520, c, rate, rate, 0.5333333611488342f);
    func_2EE3D0(base + 0x14D0, base + 0x20, *(float *)(base + 0x151C));
    func_2EE108(base + 0x14D0, base + 0x14D0, base + 0x80);
    if (*(int *)(base + 0x229C) == 0x19 || *(int *)(base + 0x2294) == 0x66) {
        float cap = *(float *)(base + 0x334) + 0.75f;

        if (*(float *)(base + 0x14D8) < cap)
            *(float *)(base + 0x14D8) = cap;
    }
    out = D_L00_001B8DC0;
    *(TI128 *)out = *(TI128 *)D_0018B2F0;
    *(TI128 *)(out + 0x230) = *(TI128 *)(D_0018B2F0 + 0x10);
    one = 1.0f;
    func_2EE220(out + 0x240, out + 0x230, D_0018B2F0 - 0x14B0);
    func_2EE3D0(out + 0x240, out + 0x240, one);
    func_2EE220(out + 0x250, out + 0x240, out + 0x230);
    func_2EE3D0(out + 0x250, out + 0x250, one);
}
