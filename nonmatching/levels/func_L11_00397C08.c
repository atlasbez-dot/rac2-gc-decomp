/* 472/472; us/us2/pal 0/4 each.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * The curve and interior jitter are reconstructed. First call setup, copy scheduling and division labels differ. A pure TImode-local variant produced 464 bytes; the union-vector draft is retained. Reopen with local aggregate/argument-lifetime evidence.
 */
typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } CurveVector;
extern void func_00282CC0(void *, void *, void *);
extern float func_00283CE0(int);
extern void func_L00_003A2018(void *, void *, void *, void *, void *, float);
extern float func_002A7878(float, float);
extern void func_00282F20(void *, void *, float);
extern void func_00282CF0(void *, void *, void *);

void func_L11_00397C08(CurveVector *points, int count, CurveVector *control, float noise) {
    CurveVector first, second, jitter;
    float inverse;
    int i;
    first.q = control[2].q;
    func_00282CC0(&first, &first, &control[0]);
    second.q = control[3].q;
    func_00282CC0(&second, &second, &control[1]);
    inverse = 1.0f / func_00283CE0(count - 2);
    for (i = 0; i < count - 1; i++) {
        func_L00_003A2018(&points[i], &control[0], &control[1], &first, &second, func_00283CE0(i) * inverse);
        if (i > 0 && i < count - 2) {
            jitter.f[3] = 0.0f;
            jitter.f[0] = func_002A7878(-1.0f, 1.0f);
            jitter.f[1] = func_002A7878(-1.0f, 1.0f);
            jitter.f[2] = func_002A7878(-1.0f, 1.0f);
            func_00282F20(&jitter, &jitter, noise);
            func_00282CC0(&points[i], &points[i], &jitter);
        }
    }
    func_00282CF0(&jitter, &points[count - 2], &points[count - 3]);
    func_00282CC0(&points[count - 1], &points[count - 2], &jitter);
}
