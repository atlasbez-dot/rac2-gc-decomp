/* func_L02_003CEFD8 (476 bytes, 3 places) -- NEAR MISS, not integrated; needs -fno-gcse.
   state with the default flags (-O2 -G0): 468 bytes, 45 words differ: GCSE folds the walk's
   `p = table[g]` into the guard's load (`daddu $s1,$v0,$zero`, retail has a real `lw $s1`
   after the vector setup) and the loop enters with `b`.
   state with -fno-gcse added (it is not in config/cflags.txt for this file): 476 bytes, the
   same as retail's, and from the `beq $a0,$a2` (the copied `g != 0xFF`) to the epilogue
   every word is retail's (loop body, the four callees' argument setup, `p++` in the `jal`
   slot, the bottom chain). The three differences left:
   - `por $v0,$zero,$zero` (retail, in the delay slot of the `q == 0` guard) feeding
     `sq $v0,0($sp)`: this cc1 folds a TI zero that has one store into `sq $zero,0($sp)`
     (tools/compiler/transformers/fold_zero_ti_store.py keeps the register form only when
     the zero feeds several stores, and the retail's zero here feeds one); the missing `por`
     also reorders the first block (`lbu`, the three `li.s` constants, `daddu $s4,$a1,$zero`,
     the `swc1` stores)
   - the dead `lh $v0,-0x2($s1)` after the first iteration's `beql $s1,$zero` (the same wall
     as func_L02_003CD4A8: see its note; here it is +4 bytes that the missing `por` hides in
     the size)
   - relocation-only lines
   Why -fno-gcse: retail reloads the group byte and the table entry after the vector setup
   (`lbu $a0,0x21($s3)`, `lw $s1,0($v0)` with E' `beql $s1,$zero` kept at the loop entry).
   With GCSE on, the stores to the stack vector and to the 8-byte local (`ldl/ldr/sdl/sdr`)
   do not kill the group-byte/table loads in its view and the reload folds away; with it
   off cse1 keeps them (measured with the vector as a `struct`, as an array and as a
   `TI128` cleared local; GCSE also hoists the byte reload above the stores).
   The rest, measured: `D_L02_001B00C8` copied as an 8-byte struct (ldl/ldr/sdl/sdr), the
   16-byte vector cleared with one TI store and three float member stores (`float v[4] = {..}`
   makes cc1 copy a rodata block instead; `= {0}` calls memset), the callees
   func_00282D30(dst, src, scale), func_002830C0(dst, src, m + 0x220),
   func_00283D38(a, b, scale) and func_L00_00325AE8(dst, r, scale * 0.2f, 0.08f). Float
   constants 0.25f, 0.1f, 1.0f, 0.2f, 0.08f encode retail's words as written.
   What would unblock it: -fno-gcse for this function (its own file in config/cflags.txt) and
   a source that makes the compiler keep the `por` (a TI zero with a second reader), plus the
   dead-`lh` wall of func_L02_003CD4A8. */

typedef int TI128 __attribute__((mode(TI)));

extern char *D_L02_001B359C __attribute__((sda));
extern char *D_L02_001FC060[];
extern int D_L02_001B35B8 __attribute__((sda));

struct L02PairWordB {
    int a;
    int b;
};

extern struct L02PairWordB D_L02_001B00C8;

extern void func_00282D30(void *, void *, float);
extern void func_002830C0(void *, void *, void *);
extern int func_00283D38(int, int, float);
extern void func_L00_00325AE8(void *, int, float, float);

struct L02Vec4 {
    float x, y, z, w;
};

struct L02PushBlock {
    char pad0[0x220];
    char m[0x104];
    float f324;
    char pad1[4];
    float f32C;
};

struct L02PushEntity {
    char pad0[0x20];
    unsigned char state;
    char pad1[0x10];
    unsigned char f31;
    char pad2[0x36];
    struct L02PushBlock *obj;
    char pad3[0x3E];
    short type;
};

struct L02PushObject {
    char pad[0x21];
    unsigned char group;
};

/* For every live entity of kind 0xA4E in the object's group (not in state 0xFE/0xFD), builds
   a vector from the unit scaled by the entity's block, transforms it by the block's matrix
   and hands it, with the block's random word, to the shared emitter. */
void func_L02_003CEFD8(struct L02PushObject *a0)
{
    struct L02Vec4 vec;
    struct L02PairWordB k;
    float tmp[4];
    unsigned short *q;
    unsigned short *p;
    struct L02PushEntity *e;
    struct L02PushBlock *o;
    int r;

    if (a0->group == 0xFF)
        return;
    q = (unsigned short *)D_L02_001FC060[a0->group];
    if (q == 0)
        return;
    *(TI128 *)&vec = 0;
    vec.x = 0.25f;
    vec.z = 0.1f;
    vec.w = 1.0f;
    k = D_L02_001B00C8;
    p = (unsigned short *)D_L02_001FC060[a0->group];
    while (a0->group != 0xFF && a0->group <= D_L02_001B35B8 && p != 0 &&
           ((p != 0 && (short)p[-1] >= 0) || p == (unsigned short *)D_L02_001FC060[a0->group])) {
        e = (struct L02PushEntity *)(D_L02_001B359C + ((*p & 0x7FFF) << 8));
        if (e == 0)
            break;
        if (e->f31 != 0 && e->type == 0xA4E && e->state != 0xFE && e->state != 0xFD) {
            o = e->obj;
            func_00282D30(tmp, &vec, o->f324);
            func_002830C0(tmp, tmp, (char *)o + 0x220);
            r = func_00283D38(k.a, k.b, o->f32C);
            func_L00_00325AE8(tmp, r, o->f324 * 0.2f, 0.08f);
        }
        p++;
    }
}
