/* Builds a direction for the object from a vector: with the resident flag clear the vector's
   own length is used; otherwise the vector is resolved against the object (or blended with
   its pair) first. The result goes to the shared rotation helper with the third component. */
extern int ref_L02_00329410_00;
extern void ref_L02_00329410_01(char *, float *, int);
extern float func_002F20E8(float *);
extern void func_002F2270(float *, float *, float);
extern float func_002F2078(float *, float *);
extern float func_002F1E78(float);
extern void func_002F2450(float *, float *);
extern void func_002F2648(float, float);

void func_L02_00329410(char *obj, float *a, int flag) {
    float v[4] __attribute__((aligned(16)));
    float w[4] __attribute__((aligned(16)));
    float x;
    float r;
    float t;

    if (ref_L02_00329410_00 == 0) {
        r = func_002F20E8(a);
        x = a[2];
    } else if (flag == 0) {
        ref_L02_00329410_01(obj + 0x10, w, 1);
        func_002F2270(v, a, 1.0f);
        t = func_002F2078(v, w);
        r = func_002F1E78(1.0f - t);
        x = t;
    } else {
        func_002F2450(v, a);
        r = func_002F20E8(v);
        x = v[2];
    }
    func_002F2648(x, r);
}
