/* func_L00_003E51C0 - 356 bytes, 27 places, level 00_aranos_tutorial, retail at
   0x003E51C0.  NEAR MISS, not integrated.

   The candidate below is 380 bytes against retail's 356.  The body is read:
   it allocates a 0xC06-byte object, writes the 0xFF/0xFF header and the
   0x100 flag, copies two 16-byte vectors into the object and into the
   sub-object at +0x68, then runs the engine's vector helpers over a 0x60-byte
   local, and finally publishes the object in the global at 0x1B05DC (through
   $gp) after func_0029F338.

   What is measured and right: the call sequence (func_002833F0 with the
   resident word at 0x18C0B0 + 0xF0, func_002AFFD8, func_00282F20 with 1.0,
   func_00282DD8, func_00282DB0 times 0.5, func_00283198, func_00282D30,
   func_00283180, func_00283958, func_00283738), the 0x60-byte local with the
   four 16-byte vectors at +0, +0x10, +0x20 and +0x30 and the float at +0x0C,
   the saved registers at +0x60 and the two `lq`/`sq` copies (the first one
   needs the `mode(TI)` type and the `-frac2-qcopy` file profile).

   What is left: the frame comes out 0xB0 against retail's 0xA0, because this
   build keeps one value too many alive (it saves $s5 where retail reuses
   $s0 and $s2), the two calls that read the object at +0x68 and the resident
   word at 0x18C0B0 are not hoisted into the branch delay slot the way
   retail's are, and the last branch (the global at 0x1B05DC) comes out as a
   plain `beqz` where retail has a branch-likely `beql` with the store of the
   object in the delay slot.

   Tried: the local as a struct with 0x20 bytes of padding (the frame and the
   saved registers then land where retail's do), the null check as an early
   return and as a branch to the common exit, the global test with one store
   and with two.  The FPR and GPR allocation of the tail is what stays out of
   reach. */

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    TI128 v0;
    TI128 v1;
    TI128 v2;
    TI128 v3;
    char pad[0x20];
} Local51C0;

extern char *func_0029EFD0(int size);

extern void func_002833F0(char *a, char *b);

extern int func_002AFFD8(char *a, char *b, int c);

extern void func_00282F20(char *a, char *b, float c);

extern void func_00282DD8(char *a, char *b, char *c);

extern float func_00282DB0(char *a, char *b);

extern float func_00283198(float x);

extern void func_00282D30(char *a, char *b, float c);

extern float func_00283180(float x);

extern void func_00283958(char *a, char *b);

extern void func_00283738(char *a, char *b, char *c);

extern void func_0029F338(void);

extern int D_L00_001B05DC_1 __attribute__((sda));

extern int D_0018C0B0;

char *func_L00_003E51C0(char *a0, TI128 *a1)
{
    Local51C0 local;
    char *p;
    char *q;
    char *r;
    float f;

    p = func_0029EFD0(0xC06);
    if (p == 0)
        return p;
    *(char *)(p + 0x30) = 0xFF;
    *(short *)(p + 0x32) = 0xFF;
    *(unsigned short *)(p + 0x34) |= 0x100;
    *(char *)(p + 0x20) = 0;
    *(TI128 *)(p + 0x10) = *(TI128 *)a0;
    *(TI128 *)(*(char **)(p + 0x68)) = *(TI128 *)a1;
    q = p + 0xC0;
    r = p + 0xE0;
    func_002833F0(q, (char *)(D_0018C0B0 + 0xF0));
    func_002AFFD8(p + 0x10, (char *)&local.v2, 1);
    func_00282F20((char *)&local.v2, (char *)&local.v2, 1.0f);
    func_00282DD8((char *)&local.v1, r, (char *)&local.v2);
    f = func_00282DB0(r, (char *)&local.v2) * 0.5f;
    f = func_00283198(f);
    func_00282D30((char *)&local.v0, (char *)&local.v1, f);
    *(float *)((char *)&local.v0 + 12) = func_00283180(f);
    func_00283958((char *)&local.v0, (char *)&local.v3);
    func_00283738(q, (char *)&local.v3, q);
    if (D_L00_001B05DC_1 != 0) {
        D_L00_001B05DC_1 = p;
        func_0029F338();
        D_L00_001B05DC_1 = p;
        return p;
    }
}
