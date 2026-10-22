/* func_L14_00304190 (236 bytes, 1 place: 14_aranos_prison) -- NEAR MISS, not integrated.
   state: 240 bytes, the frame is 0x30 against retail's 0x20 and three callee-saved
   registers are saved against retail's one; the body is otherwise the retail one.
   check.py (14_aranos_prison), with the source below:
     00304190  addiu $sp,$sp,-0x30  | addiu $sp,$sp,-0x20
     00304194  lui $at,0x3F80       | por $v0,$zero,$zero
     003041B0  sq $zero,0x0($sp)    | sq $v0,0x0($sp)
   The one real difference is the zero quadword: retail materialises it in $v0 and
   stores the register, this cc1 folds the store to the architectural zero and
   emits `sq $zero`.  The fold only fires when the materialised register is dead
   after the store, and the register here is live (retail's own `lui $v0,0x28`
   follows the store), so the source has to keep the zero in a variable: a TI128
   local assigned from another TI128 local reaches the materialisation (the
   matched func_L00_003ACC88 in src/levels/shared/L00_003A8E28-g8.c is the
   witness), but this unit needs a second 16-byte object for the compiler to keep
   the register form, and the retail frame has room for only one.
   The rest that is measured and right:
   - the 10-element copy loop: the source array is D_L14_00284690 (12-byte records,
     the float at +8), the destination is D_L14_00284708, and D_L14_001B23D0 takes
     the destination's address;
   - the dot product is func_00282DB0 (the level's 0x2F5D40) and the scalar it
     returns is what the loop multiplies the records by;
   - the second loop reads the count from *(short *)(*(int *)D_L14_001B2B20 + 6)
     and runs func_002E3478 (0x3673D0) and func_002E3940 (0x367898) for i < 10 and
     func_00283388 (0x2F6430) after that.
   Tried and not enough: the zero as a literal, as a TI128 local, through a union,
     through a float pointer cast, as a static and as a pointed-to variable; the
     records as a struct, as a char array with casts, and as two arrays; the copy
     loop with and without a separate counter; the count read before and inside
     the loop.
   Next idea: a source that keeps two 16-byte objects alive without growing the
   frame (a callee-saved vector register pair would do). */

extern int D_L14_001B23D0;
extern int *D_L14_001B2B20;
extern int D_L14_001B2B50[];
extern int D_L14_001B9730[];
extern char D_L14_00284690[];
extern char D_L14_00284708[];

extern float func_00282DB0(float *a, float *b);
extern void func_00283388(void *a);
extern void func_002E3478(int a);
extern void func_002E3940(int a);

/* A 16-byte vector: the compiler reaches lq/sq only through TImode. */
typedef int TI128 __attribute__((mode(TI)));

/* The 12-byte record the two arrays hold: two words and a float. */
typedef struct {
    int x;
    int y;
    float z;
} L14_00304190_rec;

void func_L14_00304190(void) {
    float local[4];
    TI128 zero = 0;
    L14_00304190_rec *src = (L14_00304190_rec *)D_L14_00284690;
    L14_00304190_rec *dst = (L14_00304190_rec *)D_L14_00284708;
    float r;
    int i;

    *(TI128 *)local = zero;
    local[0] = 1.0f;
    D_L14_001B23D0 = (int)D_L14_00284708;
    r = func_00282DB0((float *)D_L14_001B9730, local);
    for (i = 0; i < 10; i++) {
        dst[i].z = src[i].z * -r;
    }
    for (i = 0; i < *(short *)((char *)D_L14_001B2B20 + 6); i++) {
        if (i < 10) {
            func_002E3478(i);
            func_002E3940(i);
        } else {
            func_00283388(D_L14_001B2B50);
        }
    }
}
