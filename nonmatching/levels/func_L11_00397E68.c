/* 1176/1156; us/us2/pal 0/4 each.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * Both camera-facing ribbon layers and complete 144-byte packets are reconstructed. Packet/template initialization and live pointer allocation differ. The old SPECIAL2-only ASM inference is withdrawn: the cited word is a por clear reachable through TImode. Reopen with packet source layout/lifetimes.
 */
typedef unsigned int u32;
typedef unsigned long u64;
typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } RibbonVector;
struct RibbonQuad { RibbonVector position[4]; u32 color[4]; float uv[4][2]; u64 clear, texture, giftag, flags; };
extern float D_L11_001BA8C0[4];
extern float D_L11_001AECFC __attribute__((sda));
extern long long func_0027C878(int);
extern void func_L00_003B2900(char *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_002830C0(void *, void *, void *);
extern void func_00280B90(void *, void *, int);
extern float func_00283CE0(int);

void func_L11_00397E68(RibbonVector *points, int count, int flags, u32 color0, u32 color1, float width, float scale) {
    RibbonVector basis[4], template0, template1;
    struct RibbonQuad mainQuad, innerQuad;
    float u, nextU;
    int i;
    mainQuad.texture = func_0027C878(0x2B);
    mainQuad.flags = ((u64)(u32)flags << 32) | 0x68;
    mainQuad.giftag = 0xFF9000000260ULL;
    mainQuad.clear = 0;
    mainQuad.color[0] = color0;
    mainQuad.color[1] = color0;
    mainQuad.color[2] = color0;
    mainQuad.color[3] = color0;
    func_L00_003B2900((char *)&mainQuad);
    mainQuad.uv[0][0] = 0.0f; mainQuad.uv[0][1] = 0.0f;
    mainQuad.uv[1][0] = 0.0f; mainQuad.uv[1][1] = 1.0f;
    mainQuad.uv[2][0] = D_L11_001AECFC; mainQuad.uv[2][1] = 0.0f;
    mainQuad.uv[3][0] = D_L11_001AECFC; mainQuad.uv[3][1] = 1.0f;
    innerQuad.texture = func_0027C878(0x2B);
    innerQuad.flags = ((u64)(long)(flags / 3) << 32) | 0x68;
    innerQuad.giftag = 0xFF9000000260ULL;
    innerQuad.clear = 0;
    innerQuad.color[0] = color1;
    innerQuad.color[1] = color1;
    innerQuad.color[2] = color1;
    innerQuad.color[3] = color1;
    func_L00_003B2900((char *)&innerQuad);
    innerQuad.uv[0][0] = 0.0f; innerQuad.uv[0][1] = 0.0f;
    innerQuad.uv[1][0] = 0.0f; innerQuad.uv[1][1] = 1.0f;
    innerQuad.uv[2][0] = D_L11_001AECFC; innerQuad.uv[2][1] = 0.0f;
    innerQuad.uv[3][0] = D_L11_001AECFC; innerQuad.uv[3][1] = 1.0f;
    template0.q = 0;
    template0.f[2] = width;
    template0.f[3] = 1.0f;
    template1.q = 0;
    template1.f[2] = width * scale;
    template1.f[3] = 1.0f;
    func_00282CF0(&basis[0], &points[1], &points[0]);
    func_00282F20(&basis[0], &basis[0], 1.0f);
    func_00282CF0(&basis[1], D_L11_001BA8C0, &points[0]);
    func_00282DD8(&basis[2], &basis[1], &basis[0]);
    func_00282F20(&basis[2], &basis[2], 1.0f);
    func_00282DD8(&basis[1], &basis[0], &basis[2]);
    basis[3].q = points[0].q;
    mainQuad.position[0].q = template0.q;
    func_00282D30(&mainQuad.position[1], &mainQuad.position[0], -1.0f);
    func_002830C0(&mainQuad.position[0], &mainQuad.position[0], basis);
    func_002830C0(&mainQuad.position[1], &mainQuad.position[1], basis);
    innerQuad.position[0].q = template1.q;
    func_00282D30(&innerQuad.position[1], &innerQuad.position[0], -1.0f);
    func_002830C0(&innerQuad.position[0], &innerQuad.position[0], basis);
    func_002830C0(&innerQuad.position[1], &innerQuad.position[1], basis);
    for (i = 1; i < count - 1; i++) {
        mainQuad.position[2].q = template0.q;
        func_00282D30(&mainQuad.position[3], &mainQuad.position[2], -1.0f);
        innerQuad.position[2].q = template1.q;
        func_00282D30(&innerQuad.position[3], &innerQuad.position[2], -1.0f);
        func_00282CF0(&basis[0], &points[i + 1], &points[i]);
        func_00282F20(&basis[0], &basis[0], 1.0f);
        func_00282CF0(&basis[1], D_L11_001BA8C0, &points[i]);
        func_00282DD8(&basis[2], &basis[1], &basis[0]);
        func_00282F20(&basis[2], &basis[2], 1.0f);
        func_00282DD8(&basis[1], &basis[0], &basis[2]);
        basis[3].q = points[i].q;
        func_002830C0(&mainQuad.position[2], &mainQuad.position[2], basis);
        func_002830C0(&mainQuad.position[3], &mainQuad.position[3], basis);
        func_002830C0(&innerQuad.position[2], &innerQuad.position[2], basis);
        func_002830C0(&innerQuad.position[3], &innerQuad.position[3], basis);
        if (i == count - 2) {
            mainQuad.color[2] = 0; mainQuad.color[3] = 0;
            innerQuad.color[2] = 0; innerQuad.color[3] = 0;
        }
        func_00280B90(&mainQuad, 0, 0);
        func_00280B90(&innerQuad, 0, 0);
        u = D_L11_001AECFC * func_00283CE0(i);
        nextU = u + D_L11_001AECFC;
        if (u >= 1.0f) {
            u -= 1.0f;
            nextU -= 1.0f;
        }
        mainQuad.position[0].q = mainQuad.position[2].q;
        mainQuad.position[1].q = mainQuad.position[3].q;
        innerQuad.position[0].q = innerQuad.position[2].q;
        innerQuad.position[1].q = innerQuad.position[3].q;
        mainQuad.uv[0][0] = u; mainQuad.uv[1][0] = u;
        mainQuad.uv[2][0] = nextU; mainQuad.uv[3][0] = nextU;
        innerQuad.uv[0][0] = u; innerQuad.uv[1][0] = u;
        innerQuad.uv[2][0] = nextU; innerQuad.uv[3][0] = nextU;
    }
}
