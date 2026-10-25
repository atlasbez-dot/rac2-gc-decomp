/*
 * func_L00_003D2A00 - near miss, 508 bytes, 27 places.
 *
 * What the body is: it copies and scales the caller's vector into the output record, stamps it
 * with the level's far distance, asks func_2DE4B0 whether the pair is worth drawing, and when it
 * is, builds the local aim vector, runs it through func_3FCA40 and picks a distance-faded alpha
 * (unfaded below 10, then x0.75 below 14, x0.5 below 20, x0.125 beyond) from the per-index entry
 * of the 0xE0-stride table at 0x262570 before handing the object to func_31C100/func_3F8AD0.
 *
 * State layout measured from the retail code: one record at 0x1BF200 whose +0x18 word is both the
 * "has object" test and the value returned on every path, and whose +0x20 vector is the level aim
 * vector.  D_00139582 (boot) indexes the 0xE0-byte entries; D_0018C0B0 is the fourth argument of
 * func_2DE4B0.
 *
 * Measured result: 508/508 bytes and every instruction and relocation agrees except one register
 * pair in the fade block: retail loads the +0x18 test word into $v1 and puts the return value's
 * %hi in $v0, while this source (and every variant tried) gets the opposite assignment, which
 * also moves the table index from $v0 to $v1 and the final `daddu` from $v0 to $v1.
 *
 * Tried and measured: the if/else-if chain versus a single `out` variable (same); implicit truth
 * test; swapped local declaration order; a typed pointer to the table entry; `-fno-gcse`
 * (500 bytes); an inner `return` merged with the outer one (496 bytes, no cross-jumping).
 *
 * Reopen: a source shape that makes the return-value address pseudo outrank the test load in
 * local-alloc, or evidence that the original read the field through a second symbol.
 */
typedef struct {
    unsigned char pad_000[0x18];
    int object_18;
    unsigned char pad_01C[4];
    float vector_20[4];
} L00AimState;

typedef struct {
    unsigned char pad_000[0x70];
    float value_70;
    unsigned char pad_074[0x6C];
} L00AimEntry;

extern void func_2EE138(char *, char *, char *);
extern void func_2EE3D0(char *, char *, float);
extern int func_2DE4B0(char *, char *, int, int, int);
extern float func_2EE2B0(char *, char *);
extern void func_3FCA40(char *, char *, char *, int);
extern void func_31C100(int, char *);
extern void func_3F8AD0(int, int, char *);
extern int D_0018C0B0;
extern unsigned char D_00139582;
extern L00AimState D_L00_1BF200;
extern L00AimEntry D_L00_262570[];

int func_L00_003D2A00(char *a0, char *a1, char *a2, char *a3)
{
    char local[16];
    float distance;
    float saved;

    func_2EE138(a3, a2, a1);
    func_2EE3D0(a3, a3, 1.5f);
    *(float *)(a3 + 0xC) = 5627.9248046875f;
    if (func_2DE4B0(a1, a2, 0x10, D_0018C0B0, 0) != 0) {
        func_2EE138(local, a2, a1);
        func_2EE3D0(local, local, 1.0f);
        func_2EE138(local, (char *)D_L00_1BF200.vector_20, a1);
        func_3FCA40(a1, local, (char *)D_L00_1BF200.vector_20, 1);
        if (D_L00_1BF200.object_18 != 0) {
            saved = D_L00_262570[D_00139582].value_70;
            distance = func_2EE2B0((char *)D_L00_1BF200.vector_20, a1);
            if (distance < 10.0f) {
                *(float *)(a3 + 0x1C) = saved;
            } else if (distance < 14.0f) {
                *(float *)(a3 + 0x1C) = saved * 0.75f;
            } else if (distance < 20.0f) {
                *(float *)(a3 + 0x1C) = saved * 0.5f;
            } else {
                *(float *)(a3 + 0x1C) = saved * 0.125f;
            }
            func_31C100(D_L00_1BF200.object_18, a3);
            func_3F8AD0(D_L00_1BF200.object_18, 0x44, a0);
        }
        return D_L00_1BF200.object_18;
    }
    func_2EE138(local, a2, a1);
    func_3FCA40(a1, local, a2, 0);
    return 0;
}
