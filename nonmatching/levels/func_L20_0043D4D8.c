/* Readable C reconstruction, measured2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/1, us2: 0/1, pal: not carried.
 * 948 versus960 bytes; state dispatch, pointer lifetimes and float scheduling differ.
 * Tried: Readable moving-platform state machine with measured clone, pool, motion and timer APIs.
 * Reopen: A verified control-flow or saved-register lifetime remedy.
 * Historical notes below are preserved; their copy-wall claims are superseded
 * by the current qualified copy profiles. No handwritten-assembly inference.
 */

/* Not matched (worker 07, level-20 wave of 2026-10-21): the 128-bit copy wall.
 *
 * THE WALL.  This body has FOUR 128-bit accesses and every one of them is
 * MATERIALISED into a register with a ZERO displacement:
 *
 *      0043D4EC  addiu $v1, $s2, 0x10
 *      0043D504  lq    $v0, 0x0($v1)
 *      0043D508  sq    $v0, 0x0($sp)        ; a stack slot at offset 0
 *      0043D50C  addiu $a0, $sp, 0x10
 *      0043D510  addiu $v1, $s2, 0xF0
 *      0043D514  lq    $v0, 0x0($v1)
 *      0043D518  sq    $v0, 0x0($a0)       ; a stack slot at +0x10
 *      ...
 *      0043D7CC  addiu $s4, $s2, 0xF0
 *      0043D820  lq    $v0, 0x0($s4)
 *      0043D824  sq    $v0, 0x0($v1)
 *
 * Plain C folds every one of them (the front end builds the address as
 * plus(reg,const) and the RELOAD accepts that for TImode while the offset is
 * inside [-32768, 32751]), so the copies come out as
 * `lq $v0,0x10($s2) ; sq $v0,0x0($sp)`, `lq $v0,0xF0($s2) ; sq $v0,0x10($sp)`
 * and so on.  The escapes do not apply: the bases are runtime pointers (not
 * plain pointers, not symbols) and the stack slots are at offsets 0x10 and
 * above (the stack-slot escape only gives a zero displacement for a slot at
 * offset 0).  This is the compiler-side wall of wave 4, not a source shape.
 *
 * THE STRUCTURE (for whoever picks it up after the wall is solved).
 *   - the frame is 0x80 with $s1..$s5 and $ra saved; $s2 = the argument,
 *     $s1 = the object (arg0 + 0x68);
 *   - the two copies at the top load the argument's 16-byte blocks at +0x10
 *     and +0xF0 into two stack buffers (at sp+0 and sp+0x10);
 *   - the body calls func_0029EFD0, func_002B37E8, func_002B3868,
 *     func_002A0F48, func_00282948, func_00282CC0, func_00282CF0,
 *     func_00282D30, func_00283B98, func_0029F338, func_002A7750,
 *     func_L20_0043D470, func_002E59F8, func_002E5CF8, func_002AD6F0,
 *     func_L00_00324120, func_L01_003208D0, func_L00_002D70A0 and
 *     func_L00_002D7140;
 *   - the copy at 0x0043D820 is the third 128-bit access.
 *
 * This body belongs in the `-G8` unit?  No: it reaches no global through
 * `$gp`.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct PoolRecord64 PoolRecord64;
extern Vector D_00189EA0;
extern unsigned char D_00188660[];
extern void func_002A7750(unsigned char *, unsigned char, int);
extern unsigned char *func_0029EFD0(int);
extern void func_002B37E8(void *, void *);
extern int func_002B3868(unsigned char *);
extern int func_00282948(int *);
extern float func_00283B98(float, float);
extern int func_002E5CF8(int, int, char *);
extern void func_002E59F8(int);
extern int func_L00_00324120(int);
extern PoolRecord64 *func_L00_002D70A0(int);
extern void func_L00_002D7140(unsigned char *);
extern void func_L20_0043D470(char *);
extern void func_00282CF0(void *, const void *, const void *);
extern void func_002AD6F0(void *, const void *, const void *, const void *);
extern void func_L01_003208D0(void *, float *, int);
extern void func_0029F338(void *);
extern void func_00282D30(void *, const void *, float);
extern void func_00282CC0(void *, const void *, const void *);
extern void func_002A0F48(void *);
extern Vector D_L20_001B9FC0;

void func_L20_0043D4D8(unsigned char *object) {
    Vector oldPosition, oldRotation, delta, offset;
    unsigned char *state = *(unsigned char **)(object + 0x68);
    unsigned char *child;
    unsigned char *slot;
    int index;
    oldPosition.q = *(Quadword *)(object + 0x10);
    oldRotation.q = *(Quadword *)(object + 0xF0);
    switch (object[0x20]) {
    case 0:
        *(int *)(state + 0x5C) |= 1;
        *(float *)(state + 0x70) = 6.2831854820251465f;
        *(float *)(state + 0x74) *= 0.017453294f;
        *(int *)(state + 0x60) = 0;
        *(int *)(state + 0x68) = 0;
        *(int *)(state + 0x80) = 0;
        *(unsigned int *)(state + 0x7C) = object[0xBC];
        *(float *)(state + 0x6C) = 1.0f;
        *(float *)(state + 0x64) = 1.0f;
        func_002A7750(object, 1, -1);
        break;
    case 1:
        if ((unsigned)object[0xBC] != *(unsigned int *)(state + 0x7C)) {
            if (!*(unsigned char **)(state + 0x88))
                *(unsigned char **)(state + 0x88) = func_0029EFD0(*(unsigned short *)(object + 0xAA));
            child = *(unsigned char **)(state + 0x88);
            if (child) {
                func_002B37E8(child, 0);
                *(unsigned short *)(child + 0x34) |= 2;
                *(int *)(child + 0x98) = 0;
                child[0x23] = 0;
            }
            if (D_00189EA0.f[1] <= *(float *)(object + 0x14)) *(float *)(state + 0x64) = 1.0f;
            else *(float *)(state + 0x64) = -1.0f;
            func_002A7750(object, 2, -1);
        }
        break;
    case 2:
        if (func_002B3868(object)) *(int *)(state + 0x78) = (int)(*(float *)(state + 0x70) / *(float *)(state + 0x74));
        if (func_00282948((int *)(state + 0x78))) {
            object[0xBC] = *(unsigned char *)(state + 0x7C);
            func_002A7750(object, 1, -1);
            index = *(int *)(state + 0x90);
            slot = D_00188660 + index * 0x70;
            if (index != -1 && *(unsigned char **)(slot + 0x88) == object && slot[0x74]) func_002E59F8(index);
            *(int *)(state + 0x90) = -1;
        } else {
            *(float *)(object + 0xF8) = func_00283B98(*(float *)(object + 0xF8), *(float *)(state + 0x74));
            slot = D_00188660 + *(int *)(state + 0x90) * 0x70;
            if (*(unsigned char **)(slot + 0x88) != object || !slot[0x74])
                *(int *)(state + 0x90) = func_002E5CF8(1, 4, (char *)object);
        }
        break;
    }
    if (func_L00_00324120((int)object) && !*(int *)(state + 0x80)) {
        *(PoolRecord64 **)(state + 0x84) = func_L00_002D70A0(5);
        *(int *)(state + 0x80) = 1;
        func_L20_0043D470((char *)object);
    } else if (!func_L00_00324120((int)object) && *(int *)(state + 0x80)) {
        func_L00_002D7140(*(unsigned char **)(state + 0x84));
        *(int *)(state + 0x80) = 0;
    }
    func_00282CF0(&delta, object + 0x10, &oldPosition);
    func_002AD6F0(state + 0x20, &delta, &oldRotation, object + 0xF0);
    child = *(unsigned char **)(state + 0x88);
    if (child) {
        func_L01_003208D0(child, (float *)(state + 0x8C), object[0x20] == 2);
        child = *(unsigned char **)(state + 0x88);
        if (!child[0x23]) {
            func_0029F338(child);
            *(unsigned char **)(state + 0x88) = 0;
        } else {
            *(Quadword *)(child + 0xF0) = *(Quadword *)(object + 0xF0);
            func_00282CF0(&offset, &D_L20_001B9FC0, object + 0x10);
            func_00282D30(&offset, &offset, 0.01f);
            func_00282CC0(*(unsigned char **)(state + 0x88) + 0x10, &offset, object + 0x10);
            func_002A0F48(*(unsigned char **)(state + 0x88));
        }
    }
}
