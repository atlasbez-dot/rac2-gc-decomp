/* GNU game -O2 -G0, 1748/1796 bytes, us/us2/pal each 0/2 places.
 * One complete readable ribbon-strip reconstruction; default copy lowering,
 * float allocation and the 0x240/0x270 frame remain different. No compiler
 * profile search was attempted. Reopen with a qualified quad-copy profile
 * and the original strip/quad types established.
 */
typedef struct { float x, y, z, w; } RibbonVector;
typedef struct { RibbonVector vertices[4]; int colors[4]; float uv[8]; unsigned long long flags; float extra[2]; } RibbonQuad;
extern void func_L03_0038B390(void *, int, int, int);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DF0(void *);
extern float func_00282C48(float);
extern int func_00283D38(float, int, int);
extern float func_002AA140(float, float, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00280B90(void *, int, int);
extern void func_002FC560(int, int);
extern RibbonVector D_L03_00237F50;
extern RibbonVector D_L03_001B9980;

void func_L03_0038AB30(float innerA, float innerB, float outerA, float outerB, float extension,
                      unsigned char *object, RibbonVector *points, int count,
                      int colorA, int colorB, int glowA, int glowB) {
    unsigned char *state = *(unsigned char **)(object + 0x68);
    RibbonVector view, direction, side, origin, offset;
    RibbonQuad outer, inner;
    float phase = 0.0f;
    float startBlend, endBlend, delta, distance, width, length;
    float startInner, endInner, startOuter, endOuter;
    int startColor, endColor, startGlow, endGlow;
    RibbonVector *current = points;
    int i, j;
    func_L03_0038B390(&inner, *(int *)(state + 0x9C), 1, colorA);
    inner.flags = 0;
    for (j = 3; j >= 0; j--)
        inner.uv[(3-j)*2] += *(float *)(state + 0x84);
    func_L03_0038B390(&outer, *(int *)(state + 0x80), 1, glowA);
    outer.flags = 0;
    origin = *(RibbonVector *)(object + 0x10);
    origin.z += 1.1f;
    if (object[0x20] == 3) {
        width = *(float *)(state + 0xCC);
        phase = (width + width + 1.0f) * (1.0f - (float)*(int *)(state + 0x24) / (float)*(int *)(state + 0x1C)) - width;
        if (1.0f - width < phase && (*(int *)(state + 0x3C) & 2)) {
            func_00282F20(&offset, &D_L03_00237F50, *(float *)(state + 0xD0));
            func_00282CC0(object + 0x10, state, &offset);
        }
    }
    for (i = 0; i < count - 1; i++, current++) {
        startBlend = 0.0f;
        endBlend = 0.0f;
        if (object[0x20] == 3) {
            func_00282CF0(&offset, &origin, current);
            delta = phase - func_00282DF0(&offset) * 0.9090909f;
            if (func_00282C48(delta) < *(float *)(state + 0xCC))
                startBlend = 1.0f - func_00282C48(delta) / *(float *)(state + 0xCC);
            func_00282CF0(&offset, &origin, current + 1);
            delta = phase - func_00282DF0(&offset) * 0.9090909f;
            if (func_00282C48(delta) < *(float *)(state + 0xCC))
                endBlend = 1.0f - func_00282C48(delta) / *(float *)(state + 0xCC);
        } else if (object[0x20] == 2) {
            func_00282CF0(&offset, &origin, current);
            distance = func_00282DF0(&offset);
            if (distance * 0.9090909f < *(float *)(state + 0xCC))
                startBlend = (1.0f - distance * 0.9090909f / *(float *)(state + 0xCC)) *
                             (1.0f - (float)*(int *)(state + 0x24) / (float)*(int *)(state + 0x18));
            func_00282CF0(&offset, &origin, current + 1);
            distance = func_00282DF0(&offset);
            if (distance * 0.9090909f < *(float *)(state + 0xCC))
                endBlend = 1.0f - distance * 0.9090909f / *(float *)(state + 0xCC);
        }
        width = 1.0f;
        startColor = func_00283D38(startBlend, colorA, colorB);
        startGlow = func_00283D38(startBlend, glowA, glowB);
        startInner = func_002AA140(innerA, innerB, startBlend);
        startOuter = func_002AA140(outerA, outerB, startBlend);
        endColor = func_00283D38(endBlend, colorA, colorB);
        endGlow = func_00283D38(endBlend, glowA, glowB);
        endInner = func_002AA140(innerA, innerB, endBlend);
        endOuter = func_002AA140(outerA, outerB, endBlend);
        if (*(int *)(state + 0x3C) & 4) {
            func_00282CF0(&direction, current, &origin);
            distance = func_00282DF0(&direction);
            if (distance < *(float *)(state + 0xB0))
                width = *(float *)(state + 0xAC) * (1.0f - distance / *(float *)(state + 0xB0)) + 1.0f;
        }
        func_00282CF0(&view, current, &D_L03_001B9980);
        func_00282CF0(&direction, current + 1, current);
        length = func_00282DF0(&direction);
        func_00282DD8(&side, &direction, &view);
        inner.colors[0] = inner.colors[3] = inner.colors[2] = inner.colors[1] = startColor;
        func_00282F20(&side, &side, width * startInner * length);
        func_00282CC0(&inner.vertices[0], current, &side);
        func_00282CF0(&inner.vertices[1], current, &side);
        inner.colors[0] = inner.colors[3] = inner.colors[2] = inner.colors[1] = endColor;
        func_00282F20(&side, &side, width * endInner * length);
        func_00282CC0(&inner.vertices[2], current + 1, &side);
        func_00282CF0(&inner.vertices[3], current + 1, &side);
        func_00280B90(&inner, 0, 0);
        outer.colors[0] = outer.colors[3] = outer.colors[2] = outer.colors[1] = startGlow;
        func_00282F20(&side, &side, width * startOuter * length);
        func_00282CC0(&outer.vertices[0], current, &side);
        func_00282CF0(&outer.vertices[1], current, &side);
        outer.colors[0] = outer.colors[3] = outer.colors[2] = outer.colors[1] = endGlow;
        func_00282F20(&side, &side, width * endOuter * length);
        func_00282CC0(&outer.vertices[2], current + 1, &side);
        func_00282CF0(&outer.vertices[3], current + 1, &side);
        func_00282D30(&direction, &direction, extension);
        func_00282CF0(&outer.vertices[0], &outer.vertices[0], &direction);
        func_00282CF0(&outer.vertices[1], &outer.vertices[1], &direction);
        func_00282CC0(&outer.vertices[2], &outer.vertices[2], &direction);
        func_00282CC0(&outer.vertices[3], &outer.vertices[3], &direction);
        func_00280B90(&outer, 0, 0);
    }
    func_002FC560(0x47, 0x5360B);
}
