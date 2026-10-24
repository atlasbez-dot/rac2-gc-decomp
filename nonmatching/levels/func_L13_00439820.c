/* func_L13_00439820 - 588 bytes, 3 place(s), level 13_boldan, retail at
   0x00439820. Screened with tools/w10_screen.py: 8 call(s)
   [func_00282E48@00439904, func_L00_00341FA8@00439990,
   func_00282CF0@004399D0, func_00282DF0@004399D8, func_00282F20@004399FC,
   func_00282CF0@00439A10, func_00282DB0@00439A1C,
   func_L13_004388C8@00439A38]; data addresses materialised [0x1b0000,
   0x1c0000, 0x200000, 0x200000, 0x190000]; float constants [0x3f800000,
   0x41a00000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [LQ/SQ 78820000@0x0054,
   LQ/SQ 7CC20000@0x0058, LQ/SQ 78A20000@0x005c, LQ/SQ 7E620000@0x0060,
   LQ/SQ 78620000@0x006c, LQ/SQ 7C820000@0x0070, LQ/SQ 78A20000@0x007c,
   LQ/SQ 7C620000@0x0080, LQ/SQ 7A620000@0x0088, LQ/SQ 7C820000@0x008c].
   Head: addiu $sp, $sp, -0x90 ; lui $a3, 0x1B ; lw $a3, 0x22C4($a3) ; sd
   $s3, 0x58($sp) ; lui $v0, 0x1C ; sd $s0, 0x40($sp). Not matched in this
   wave: the 128-bit copy needs an `lq`/`sq` pair; plain C reaches it only
   through a `mode(TI)` local, and this cc1 folds the destination offset
   into the `sq` where retail materialises the pointer first. What would
   unblock it: the exact source expression tree, so this cc1 picks the same
   registers in the same order. */

/* Manual C reconstruction, retained after bounded retail comparison.
 * This body supersedes the historical screening conclusions above.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Measured text: 588 bytes; retail: 588 bytes. US/US2/PAL: 0/3 placements in each carrying
 * release.
 * 2 distinct measured forms. Equal size; first difference +0x8: global pointer and
 * saved-register allocation. -mno-split-addresses produced 584 bytes and was reverted.
 * Reopen with a new real source-lifetime/address-expression hypothesis.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

typedef int Quad __attribute__((mode(TI)));
/* Sixteen-byte path header; vector records follow with a runtime count. */
typedef struct { int count; int reserved[3]; float point[0][4]; } CameraPath;
extern char *D_L13_001B22C4;
extern char *D_L13_001B9914;
extern CameraPath *D_L13_001FE580[];
extern float D_00189EA0[4];
extern float func_00282E48(void *, void *);
extern int func_L00_00341FA8(void *, void *, void *, int *, float *, int, float, float, float);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_00282F20(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern void func_L13_004388C8(char *);

void func_L13_00439820(char *camera) {
    float projected[4];
    float tangent[4];
    float difference[4];
    int segment;
    float fraction;
    char *source = D_L13_001B9914;
    char *settings = *(char **)(D_L13_001B22C4 + *(short *)(camera + 0x84) * 32 + 0x1C);
    CameraPath *path;
    int i;
    int next;
    *(Quad *)(camera + 0x30) = *(Quad *)(source + 0x30);
    *(Quad *)camera = *(Quad *)source;
    *(Quad *)(camera + 0x10) = *(Quad *)(source + 0x10);
    *(Quad *)(camera + 0x20) = *(Quad *)(source + 0x20);
    *(Quad *)(camera + 0x40) = *(Quad *)camera;
    if (*(int *)(settings + 0x20) >= 0) {
        path = D_L13_001FE580[*(int *)(settings + 0x20)];
        for (i = 0; i < path->count; i++) {
            next = (i + 1) % path->count;
            path->point[i][3] = func_00282E48(path->point[i], path->point[next]);
        }
    }
    *(short *)(settings + 0x36) = 0;
    if (*(int *)(settings + 0x30) == 3) {
        path = D_L13_001FE580[*(int *)(settings + 0x20)];
        segment = 0;
        fraction = 0.0f;
        if (func_L00_00341FA8(path, D_00189EA0, projected, &segment, &fraction, 0, 20.0f, 1.0f, 0.0f)) {
            next = segment + 1;
            if (next >= path->count) next = path->count - 1;
            func_00282CF0(tangent, path->point[next], path->point[segment]);
            if (func_00282DF0(tangent) != 0.0f && next != segment) {
                func_00282F20(tangent, tangent, 1.0f);
                func_00282CF0(difference, camera + 0x30, D_00189EA0);
                if (func_00282DB0(difference, tangent) > 0.0f)
                    *(short *)(settings + 0x36) = 1;
            }
        }
    }
    func_L13_004388C8(camera);
}
