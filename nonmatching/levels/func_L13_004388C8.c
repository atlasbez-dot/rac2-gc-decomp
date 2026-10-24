/* func_L13_004388C8 - 1212 bytes, 3 place(s), level 13_boldan, retail at
   0x004388c8. Screened with tools/w10_screen.py: 10 call(s)
   [func_00282C88@004389D0, func_00282C88@00438A08, func_00282C88@00438A18,
   func_00282C88@00438A20, func_L00_00341FA8@00438B2C,
   func_00283CF0@00438B78, func_00283CF0@00438B88,
   func_L00_00341FA8@00438C5C, func_00283CF0@00438CA8,
   func_00283CF0@00438CB8]; data addresses materialised [0x3e560000,
   0x3a030000, 0x3e330000, 0x3c230000, 0x3e4c0000, 0x3e990000, 0x3b440000,
   0x3dcc0000, 0x200000, 0x1b0000]; float constants [0x3fc00000, 0x1b0000,
   0x3f000000, 0x40c00000, 0x3f000000, 0x40000000, 0x40400000, 0x41a00000,
   0x40a00000, 0x41a00000, 0x40a00000]; $gp-relative small data: no   saves:
   -; callee-saved registers saved [-]; words plain C cannot emit [COP1
   46800860@0x027c, COP1 46800860@0x03ac]. Head: addiu $sp, $sp, -0x80 ; lui
   $at, 0x3FC0 ; mtc1 $at, $f0 ; sd $s2, 0x30($sp) ; addiu $a1, $zero, 0x3 ;
   sd $s0, 0x20($sp). Not matched in this wave: the float code has to come
   out of the same expression tree to keep the FPU registers. What would
   unblock it: the exact source expression tree, so this cc1 picks the same
   registers in the same order. */

/* Manual C reconstruction, retained after bounded retail comparison.
 * This body supersedes the historical screening conclusions above.
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses
 * Measured text: 1212 bytes; retail: 1212 bytes. US/US2/PAL: 0/3 placements in each
 * carrying release.
 * 3 distinct measured forms. Equal size with -mno-split-addresses; first difference +0xC,
 * private/settings base allocation and scalar constant scheduling differ. Default
 * addressing gave 1224 bytes, then 1204 after moving previous-index initialization to the
 * loop preheader. Reopen with a new private-base/lifetime hypothesis.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

typedef int Quad __attribute__((mode(TI)));
/* A fixed sixteen-byte header followed by a variable number of vector records. */
typedef struct { int count; int reserved[3]; float point[0][4]; } CameraPath;
extern char *D_L13_001B22C4;
extern char *D_L13_001B2140;
extern CameraPath *D_L13_001FE580[];
extern void func_00282C88(Quad *);
extern int func_L00_00341FA8(void *, void *, void *, int *, float *, int, float, float, float);
extern int func_00283CF0(float);

void func_L13_004388C8(char *camera) {
    float projected[4];
    int segment;
    float fraction;
    char *private = *(char **)(camera + 0x70);
    char *settings = *(char **)(D_L13_001B22C4 + *(short *)(camera + 0x84) * 32 + 0x1C);
    CameraPath *first;
    CameraPath *route;
    CameraPath *other;
    CameraPath *other_route;
    int i;
    int j;
    int previous;
    int previous_index;
    int current;
    int steps;
    float distance;
    *(float *)(private + 0xCC) = 1.5f;
    *(int *)(private + 0xC0) = 0;
    if (*(int *)(settings + 0x30) == 3) *(float *)(private + 0xCC) = 0.5f;
    *(float *)(private + 0xC8) = 0.20943953f;
    private = *(char **)(camera + 0x70);
    *(float *)(private + 0xE0) = 6.0f;
    *(float *)(private + 0xE4) = 0.5f;
    *(float *)(private + 0xF0) = 2.0f;
    private = *(char **)(camera + 0x70);
    *(float *)(private + 0x20) = 0.0005f;
    *(float *)(private + 0x14) = 0.175f;
    *(float *)(private + 0x10) = 0.01f;
    *(int *)(private + 0x18) = 0;
    *(short *)(private + 0x1C) = 0;
    *(int *)(private + 0x24) = 0;
    func_00282C88((Quad *)private);
    private = *(char **)(camera + 0x70);
    *(float *)(private + 0x54) = 0.3f;
    *(float *)(private + 0x50) = 0.01f;
    *(float *)(private + 0x58) = 0.2f;
    *(short *)(private + 0x5C) = 0;
    func_00282C88((Quad *)(private + 0x30));
    private = *(char **)(camera + 0x70);
    func_00282C88((Quad *)(private + 0x100));
    func_00282C88((Quad *)(private + 0x120));
    *(float *)(private + 0x140) = 3.0f;
    *(float *)(private + 0x130) = 0.003f;
    *(float *)(private + 0x134) = 0.1f;
    *(float *)(private + 0x138) = 0.2f;
    *(int *)(private + 0x13C) = 0;
    private = *(char **)(camera + 0x70);
    *(int *)(private + 0x150) = 0;
    *(int *)(private + 0x160) = 1;
    *(int *)(private + 0x154) = 0;
    *(int *)(private + 0x158) = 0;
    *(int *)(private + 0x15C) = 0;
    if (*(int *)(settings + 0x30) == 2 && *(short *)(settings + 0x34) == 0) {
        first = D_L13_001FE580[*(int *)(settings + 0x28)];
        route = D_L13_001FE580[*(int *)(settings + 0x20)];
        other_route = *(CameraPath **)(D_L13_001B2140 + *(int *)(settings + 0x24) * 32 + 0x10);
        other = D_L13_001FE580[*(int *)(settings + 0x2C)];
        *(short *)(settings + 0x34) = 1;
        for (i = 0; i < first->count; i++) {
            func_L00_00341FA8(route, first->point[i], projected, &segment, &fraction, 0, 20.0f, 5.0f, 0.0f);
            first->point[i][0] = first->point[i][3];
            first->point[i][3] = (float)segment;
        }
        previous_index = first->count - 1;
        for (i = 0; i < first->count; i++) {
            previous = func_00283CF0(first->point[previous_index][3]);
            current = func_00283CF0(first->point[i][3]);
            steps = current - previous;
            if (steps < 0) steps += route->count;
            distance = 0.0f;
            for (j = 0; j < steps; j++)
                distance += route->point[(previous + j) % route->count][3];
            first->point[i][1] = distance;
            previous_index = i;
        }
        for (i = 0; i < other->count; i++) {
            func_L00_00341FA8(other_route, other->point[i], projected, &segment, &fraction, 0, 20.0f, 5.0f, 0.0f);
            other->point[i][0] = other->point[i][3];
            other->point[i][3] = (float)segment;
        }
        previous_index = other->count - 1;
        for (i = 0; i < other->count; i++) {
            previous = func_00283CF0(other->point[previous_index][3]);
            current = func_00283CF0(other->point[i][3]);
            steps = current - previous;
            if (steps < 0) steps += other_route->count;
            distance = 0.0f;
            for (j = 0; j < steps; j++)
                distance += other_route->point[(previous + j) % other_route->count][3];
            other->point[i][1] = distance;
            previous_index = i;
        }
    }
    *(short *)(camera + 0x7E) = 0;
}
