/* Near miss: func_L14_003CB868 (src/levels/14_aranos_prison/L14_00304190.c), 952 bytes against
   retail's 960; 199 of retail's 240 words line up (relocations ignored). It needs this unit's
   -G0 flags (the globals are `sda` externs: bare lui/lw outside a delay slot, $gp in the
   delay slot of the walk's tests).

   What is right, up to register names: the id-list walk of the state's group word at +0x64 (the
   unrotated form with the second `p != 0`; entity base D_L14_001B259C, count D_L14_001B25B8,
   as in func_L14_003DF200), the test inside it (func_00282CF0 offset of the entity, func_002AFDD8
   into the owner's frame, off[3] = 1.0f, off[0] += 2.0f stored back, then fabs < 1.0 on both
   lanes as a flag set by a branch-likely) with its two calls, the condition on the hero struct
   `(D_00189E20[0x33C] == self && D_00189E20[0x340] != 0) || D_00189E20 float 0x31C < 0.5f`, and
   the second block, which repeats the test against D_00189EA0 and then does by hand what
   func_L14_003C96E0 does for an entity. The hi half of D_00189E20 is kept in $s7 from before the
   walk and the lo half is added at each block (set after the first call of the second block).

   What differs, in three places:
   1. The walk's two callee-saved registers are swapped: retail keeps the id pointer in $s1 and
      the entity in $s2, this build the opposite ($s1 = entity). global.c orders the pseudos by
      floor_log2(refs) * refs / live_length, and here the entity (10 weighted references over
      48 insns) comes before the id pointer (13 over 83); retail's order is the reverse. None of
      these changes it: separate or shared names for the two pointers and for the two hero
      pointers, a while loop, the flag as a char or set by nested ifs, the order of the two
      declarations, a copy of the entity for the call, the operands of the sum before the last
      call in the other order. Extra tests on the id pointer inside the walk (artificial: they
      add code) do swap them, so it is the reference counts that decide.
   2. The second block's three local pointers (sp+0x50, sp+0x60 and the hero base) are in
      retail $s2, $s0 and $s1; this build gives $s0, $s2 and $s1 (the sched1 order defines
      `sp+0x60` early here). The mtc1 of the constant 1/180 comes before the call of
      func_002830C0 here and after it in retail.
   3. The 128-bit copy wall of docs/COMPILER-NOTES.md: retail copies the result vector with
        addiu s1,s1,0xF0 ; lq v0,0(s0) ; sq v0,0(s1)
      ($s0 = sp+0x60 held in a register since three calls take it, $s1 the hero base) where this
      compiler folds both offsets, `lq v0,0x60(sp) ; sq v0,0xF0(s1)`. The destination written
      as a symbol (`D_00189E20 + 0xF0`) gets a materialised address, but with its own lui/addiu
      pair instead of an `addiu` on the shared register, and the size then reaches 960 with the
      wrong words.

   Would unblock it: the compiler-side tie-break of find_best_addr for TImode (the copy wall);
   after that the pseudo order of item 1, which only a source with fewer references to the
   entity (or more to the id pointer) than this C would change. */

typedef unsigned short u16;
typedef int TI128 __attribute__((mode(TI)));

extern void func_00283698(void *dst, void *src);
extern void func_00282CF0(void *dst, void *a, void *b);
extern void func_002AFDD8(void *a, void *b, void *c, void *d);
extern float func_00282C48(float a);
extern void func_002830C0(void *dst, void *a, void *b);
extern float func_002A7878(float a, float b);
extern float func_00282C10(float a);
extern void func_00282D30(void *dst, void *src, float s);
extern void func_L14_003C96E0(char *e, void *v, float a, float b, float c);
extern void func_L00_002C42E0(int a0, int a1);
extern unsigned short *D_L14_001FB060[];
extern unsigned char *D_L14_001B259C __attribute__((sda));
extern int D_L14_001B25B8 __attribute__((sda));
extern char *D_L14_001B268C __attribute__((sda));
extern char D_00189E20[];
extern char D_00189EA0[];

void func_L14_003CB868(char *self) {
    float mtx[16];
    float off[4];
    float tmp[4];
    float vec[4];
    char *state = *(char **)(self + 0x68);
    unsigned short *p;
    unsigned char *e;
    char *hero;
    char *hero2;
    int inside;
    float a;
    float b;
    float c;

    func_00283698(mtx, self + 0xC0);
    for (p = D_L14_001FB060[*(int *)(state + 0x64)];
         (*(int *)(state + 0x64) & 0xFF) != 0xFF && *(int *)(state + 0x64) <= D_L14_001B25B8 &&
         p != 0 && ((p != 0 && (short)p[-1] >= 0) || p == D_L14_001FB060[*(int *)(state + 0x64)]);
         p++) {
        e = D_L14_001B259C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (e[0x20] != 0xFE) {
            if (e[0x20] != 0xFD) {
                func_00282CF0(off, e + 0x10, self + 0x10);
                func_002AFDD8(self, off, off, mtx);
                off[3] = 1.0f;
                off[0] = off[0] + 2.0f;
                inside = func_00282C48(off[0]) < 1.0f && func_00282C48(off[1]) < 1.0f;
                if (inside) {
                    func_002830C0(tmp, off, D_L14_001B268C + (*(int *)(state + 0x60) << 7));
                    func_L14_003C96E0((char *)e, tmp,
                                      *(float *)(D_L14_001B268C + (*(int *)(state + 0x60) << 7) + 0x38) +
                                          func_002A7878(1.0f, 2.0f),
                                      0.0055555557f, 0.0055555557f);
                }
            }
        }
    }
    hero = D_00189E20;
    if ((*(char **)(hero + 0x33C) == self && *(int *)(hero + 0x340) != 0) ||
        *(float *)(hero + 0x31C) < 0.5f) {
        func_00282CF0(off, D_00189EA0, self + 0x10);
        func_002AFDD8(self, off, off, mtx);
        off[3] = 1.0f;
        off[0] = off[0] + 2.0f;
        inside = func_00282C48(off[0]) < 1.0f && func_00282C48(off[1]) < 1.0f;
        if (inside) {
            func_002830C0(tmp, off, D_L14_001B268C + (*(int *)(state + 0x60) << 7));
            hero2 = D_00189E20;
            a = *(float *)(D_L14_001B268C + (*(int *)(state + 0x60) << 7) + 0x38) + 1.5f;
            b = (a - *(float *)(hero2 + 0x88)) * 2.0f;
            c = (a - tmp[2]) * 2.0f;
            func_00282CF0(vec, tmp, hero2 + 0x80);
            func_00282D30(vec, vec, 1.0f / (func_00282C10(b / 0.0055555557f) + func_00282C10(c / 0.0055555557f)));
            vec[2] = func_00282C10(b * 0.0055555557f);
            func_L00_002C42E0(0x44, 1);
            *(TI128 *)(D_00189E20 + 0xF0) = *(TI128 *)vec;
        }
    }
}
