/* 0 of 1 places match - last line: 05_feltzin_system: 572 bytes, expected 568
   143 instructions against 142: the extra one is a duplicate `lw $v1,0x274($s2)` before
   the `sw ... 0x11C($s3)` store. Retail loads +0x274 once (into $a0, in the `bnel` delay
   slot) and stores it; here the absolute table pointer takes $a0 for its address temporary
   (`lui $a0,%hi ; lw $v1,%lo($a0)`), which clobbers that value, so the store reloads it.
   The same sub-form as func_L05_004155A0: retail keeps the load destination as the address
   register (`lui $v1,%hi ; lw $v1,%lo($v1)`), this cc1 does not.
   Everything else matches instruction for instruction, including the inlined 128-record
   clear (the body of func_L05_00415D70, written out again here) once its initialisers are
   assigned after the func_379E60 call instead of in their declarations.
   Also tried: the table load assigned to a local first, the record base computed from
   `idx * 0x70 + D` (commuted), nested ifs instead of `&&` for the two guard words.
   Notes: `int one = 1;` reaches the retail $s0 shape (see func_L05_004155A0).
   func_379E60 takes the address of func_L05_00415D70 as its second argument; the tail
   callback func_416610 is func_L00_003BAAD0. */

#include "include_asm.h"

extern char D_00188660[];
extern char D_L05_002659E0[];
extern char *D_L05_001B251C;

extern int func_379860(char *object);
extern char *func_379CA0(char *object);
extern void func_379E60(char *object, char *a1, int a2, int a3);
extern void func_37C160(char *object);
extern void func_37B538(char *object, int a1, int a2, int a3);
extern void func_37B948(char *object, int a1, float a2);
extern int func_37B888(char *object);
extern void func_37B6D0(char *object);
extern int func_3719A8(int a0, int a1, char *object, int a3);
extern void func_3065F8(char *block);
extern void func_3062A0(char *block);
extern void func_2FF698(void *fn, char *object);
extern void func_415DA8(char *object);
extern void func_415F18(char *object);
extern void func_415FD0(char *object);
extern void func_4161B0(char *object);
extern char *func_416D68(char *a0, int a1);
extern void func_415D70(void);
extern void func_416610(void);

void func_L05_00415B38(char *object)
{
    char *state = *(char **)(object + 0x68);
    char *r;
    char *rec;
    char *table;
    char buf[0x10];
    int st;

    if (*(unsigned char *)(object + 0x20) == 0) {
        *(unsigned char *)(object + 0x30) = 0xFF;
        if (func_379860(object) == 0)
            return;
        func_415DA8(object);
        func_3065F8(buf);
        if (*(int *)(state + 0x264) != 0) {
            char *base;
            int *p;
            int i;

            func_379E60(object, (char *)func_415D70, 0, 0);
            base = D_L05_002659E0;
            p = (int *)(base + 0x27F0);
            i = 0x7F;
            do {
                *p = 0;
                p -= 0x14;
                i--;
            } while (i >= 0);
        }
        return;
    }
    r = func_379CA0(object);
    if (*(int *)(r + 0x110) == 0)
        return;
    if (*(int *)(state + 0x26C) == 0) {
        if (*(int *)(state + 0x270) == 0) {
            *(int *)(state + 0x26C) = (int)func_416D68(object, 0);
            *(int *)(state + 0x270) = (int)func_416D68(object, 1);
        }
    }
    *(float *)(*(int *)(state + 0x26C) + 0x2C) = *(float *)(object + 0x2C);
    *(float *)(*(int *)(state + 0x270) + 0x2C) = *(float *)(object + 0x2C);
    {
    int one = 1;
    func_37C160(object);
    func_37B538(object, 0, 0, 0);
    func_37B948(object, one, 32.0f);
    st = *(int *)(r + 0x110);
    if (st == one) {
        if (*(int *)(state + 0x260) != -1) {
            *(int *)(r + 0x11C) = *(int *)(state + 0x274);
            table = D_L05_001B251C;
            *(int *)(r + 0x120) = (int)(table + *(int *)(state + 0x260) * 256);
        }
        if (*(int *)(r + 0x108) != 0 && *(int *)(r + 0x104) != 0)
            func_415F18(object);
        if (func_37B888(object) != 0)
            func_37B6D0(object);
        func_3062A0(state + 0x268);
        func_415FD0(object);
    }
    }
    rec = D_00188660 + *(int *)(state + 0x274) * 0x70;
    if (*(char **)(rec + 0x88) != object || *(unsigned char *)(rec + 0x74) == 0)
        *(int *)(state + 0x274) = func_3719A8(1, 6, object, 0xF76);
    func_4161B0(object);
    func_2FF698(func_416610, object);
}
