#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_00282CC0(char *, char *, char *);

extern void func_002A8C00(char *, int, int, void *, float);

extern int func_002761F8(void *, void *, int, int, void *);

extern int func_00282948(void *);

extern void func_002E5DA0(int, int, void *, int);

extern void func_L00_002E6EF8(void *, int);

extern void func_L20_0039C5D0(char *);

extern void func_L20_0039C8C8(char *, int, int);

extern void func_L20_0039CC10(void);

extern void func_0029F338(int);

extern char D_L20_001C0420[];

/* Near miss from src/levels/20_yeedil/L20_0039C448.c: 248 bytes; 248-byte candidate; 0/1.
    (Replaces an earlier draft from commit adcbd51, which used the inline-assembly `qcopy`
    helper that AGENTS.md's "Plain C" rule forbids; that draft is in that commit.)
    The whole body matches - the frame (0x60), the call sequence, the branch, the local buffer
    and the register allocation - except for two instructions:
      - the 128-bit load: retail keeps the source pointer in $s0 and loads from it
        (`addiu $s0,$s2,0x10; lq $v0,0($s0)`) while this cc1 folds the constant offset back
        into the load (`lq $v0,0x10($s2)`).  The store side is fine (a plain register address
        needs no offset).  Measured again in this wave with about twenty spellings: a TI128
        pointer variable, a struct member, an array index, a volatile load, two C names for the
        same pointer, a pointer used twice and a pointer kept across a call - all fold the
        offset.  A `short` truncation keeps the address in a register but costs `sll`/`sra`.
      - the order of the two saves: retail emits `sd $s0,0x30($sp); sd $s2,0x40($sp);
        sd $s1,0x38($sp)`, this cc1 `sd $s0,0x30($sp); sd $s1,0x38($sp); sd $s2,0x40($sp)`
        (the "the order of the two save registers sometimes rotates" wall).
    Every callee name in the draft was checked against the level-20 catalogue and is right. */
void func_L20_0039C448(char *arg0) {
    char *s0 = arg0 + 0x10;
    char *s3 = *(char **)(arg0 + 0x68);
    char *s1;
    char buf[0x30];

    *(TI128 *)s3 = *(TI128 *)s0;
    s1 = s3 + 0x10;
    func_00282CC0(s0, s0, s1);
    func_002A8C00(buf, (int)arg0, 0x10001, s1, *(float *)(s3 + 0x2C));
    if (func_002761F8(s3, s0, 0, *(int *)(arg0 + 0xB8), buf) != 0
        || func_00282948(s3 + 0x20) != 0) {
        func_L20_0039C8C8(D_L20_001C0420, 0x14, 1);
        func_002E5DA0(2, 0, arg0, 0x12EF);
        func_0029F338((int)arg0);
    } else {
        func_L20_0039C5D0(arg0);
        func_L00_002E6EF8(func_L20_0039CC10, (int)arg0);
    }
}
