/* func_L05_00426E70 (540 bytes, 4 places) -- NEAR MISS, not integrated.
   The same body serves func_L05_00426E70; they differ only in the two `ori`
   immediates of the colour call (0x7FFF here, 0x4FFF in the sibling).

   The body, as read from the retail bytes:
   - the object's own 16-byte record (object + 0x10) is copied into a stack
     buffer (lq/sq pair, 0x78820010 / 0x7FA20020), its third float gets 0.25f
     added, and the buffer is blended with the level's own table by
     func_00282CF0; then func_00282F20 twice (with -0.3f and 0.1f) and
     func_00282CC0.
   - a four-step walk over the four records of the state's own block: the first
     float of each is turned by the float 0x10 further on, wrapped into
     0..255, the record's id is written back as 255 when func_00282948 says the
     record is live, the blended colour is handed to func_00283D38 with the
     level's 0x50204FFF/0x10204FFF pair, and the level's own spawner
     func_002C2FD8 gets the record.

   Measured: 540 bytes against 540 (the size is right) but the bytes differ.
   What is left, measured:
   - the frame is 0x90 in both, but this candidate needs NINE callee-saved
     registers (it spills $fp) where retail has eight.  Retail keeps the state
     base ($s4) and the end of the first float array ($s5) in registers of their
     own and has no register at all for the base of the int array: it
     re-materialises it with `addiu $v1,$s4,0x20` in the loop and adds the
     offset to it (`addu $v0,$v1,$s2 ; sw $s6,0x0($v0)`).  Here the same base is
     a local (`b20`), so this compiler keeps it in a callee-saved register and
     folds the 0x20 into the store's offset instead (`sw $s7,0x20($s0)`).
     Measured and rejected: writing the address inline as
     `(int)base + 0x20 + off` folds the constant into the memory offset;
     writing it as `(int)(base + 0x20) + off` gives the same fold; a separate
     `char *` base (base + 0x20) is strength-reduced into a new induction
     variable; and giving the int array the induction variable and the call the
     fresh address produces retail's two instructions but then merges the float
     and the int induction variables into one register.
   - the 0.0f of the `f <= 0.0f` test lands in $f2 here (this compiler hoists
     the constant out of the loop into a callee-saved FPR) and in $f0 in retail,
     which materialises it in the branch that guards it.
   - the float at base + 0x30 + off: retail computes `addu $v1,$s4,$s2` and
     folds the 0x30 into the load (`lwc1 $f12,0x30($v1)`); here the sum comes
     out with the operands the other way round.
   - the loop head: retail puts a `nop` in front of it, this compiler one
     instruction later.

   What was measured on the way: the 128-bit copy needs a `mode(TI)` local
   (three of them in one array, so the frame is laid out 0x00/0x10/0x20 and the
   copy's `sq` carries the 0x20 offset); the level's own table address has to
   be an absolute `extern` (no sda), retail materialises it with
   `lui $a1,0x1C ; addiu $a1,$a1,-0x6940`; the second call's constant is
   -0.3f (0xBE99999A), not -0.2f; and func_00283CE0 returns a float.  The
   float multiply is 1/255 (0x3B808081), the colour pair 0x50204FFF and
   0x10204FFF.
*/
typedef int TI128 __attribute__((mode(TI)));

extern int ref_L05_00426E70_00[];

extern void func_00282CF0(void *, void *, void *);

extern void func_00282F20(void *, void *, float);

extern void func_00282CC0(char *dst, char *src, char *src2);

extern int func_00282948(void *);

extern float func_00283CE0(int);

extern int func_00283CF0(float);

extern float func_00282C48(float);

extern void func_00283D38(int, int, float);

extern void *func_002C2FD8(void *, void *, int, int, int, int, int, float);

void func_L05_00426E70(char *a0)
{
    TI128 buf[3];
    char *base;
    char *r;
    float *fp;
    char *ip;
    int b20;
    int off;
    float f;
    int n;
    int m;
    void *ptr;

    buf[2] = *(TI128 *)(a0 + 0x10);
    base = *(char **)(a0 + 0x68);
    r = base + 0x10;
    b20 = (int)base + 0x20;
    ((float *)&buf[2])[2] += 0.25f;
    func_00282CF0(&buf[0], ref_L05_00426E70_00, &buf[2]);
    func_00282F20(&buf[0], &buf[0], -0.3f);
    func_00282F20(&buf[1], &buf[0], 0.1f);
    func_00282CC0((char *)&buf[0], (char *)&buf[0], (char *)&buf[2]);
    fp = (float *)base;
    ip = base + 0x20;
    off = 0;
    do {
        f = *fp + *(float *)(r + off);
        *fp = f;
        if (f >= 255.0f)
            *fp = f - 255.0f;
        else if (f <= 0.0f)
            *fp = f + 255.0f;
        if (func_00282948((void *)ip) != 0)
            *(int *)(b20 + off) = 255;
        f = func_00283CE0(255 - *(int *)(b20 + off));
        f = f * (1.0f / 255.0f);
        func_00283D38(0x50204FFF, 0x10204FFF, func_00282C48(0.5f - f));
        n = func_00283CF0(*fp);
        ptr = func_002C2FD8(&buf[0], (void *)n, n & 0xFF, 0x35, 1, 2, 0,
                            *(float *)((int)base + 0x30 + off));
        if (ptr != 0) {
            m = func_00283CF0(1.0f);
            *(char *)(ptr + 0x9) = (char)(m + 0x60);
        }
        func_00282CC0((char *)&buf[0], (char *)&buf[0], (char *)&buf[1]);
        off += 4;
        fp++;
        ip += 4;
    } while ((int)fp < (int)r);
}
