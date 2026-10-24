/* 644/632; us/us2/pal 0/2 each.
 * Profile: -O2 -G8 -ffunction-sections.
 * The 144-byte effect quad and full 64-byte transform are explicit. Camera-base lifetime, scalar packet initialization and helper argument scheduling differ. Both auxiliary draws preserve four GPR and three FP inputs. Reopen with original packet initializer/source lifetimes.
 */
typedef unsigned int u32;
typedef unsigned long u64;
struct EffectQuad { float position[4][4]; u32 color[4]; float uv[4][2]; u64 clear, texture, giftag, flags; };
extern float D_L11_001BA780[];
extern int D_L11_001B1CE4 __attribute__((sda));
extern u32 D_L11_001B1CE8 __attribute__((sda));
extern u32 D_L11_001B1CEC __attribute__((sda));
extern float D_L11_001B1CF0 __attribute__((sda));
extern float D_L11_001B1CF4 __attribute__((sda));
extern int D_L11_001B1CF8 __attribute__((sda));
extern int D_L11_001B1CFC __attribute__((sda));
extern float D_L11_001B1D00 __attribute__((sda));
extern void func_L11_004506C0(char *);
extern long long func_0027C878(int);
extern float func_00283248(float, float);
extern float func_00282E80(char *, float *);
extern void func_00283410(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_L11_00450748(char *, float);
extern void func_00280B90(void *, void *, int);
extern void func_00282CC0(void *, void *, void *);
extern void func_00281EB8(void *, u32, int, int, float, float, float);

void func_L11_004507B0(void *position, u32 color, float size, int alpha, float roll, int texture, int flags, float offset, void *owner) {
    struct EffectQuad quad;
    float matrix[16], rotation[4], toward[4], light[4];
    char *object = owner;
    char *data = *(char **)(object + 0x68);
    float *point = position;
    float *camera = D_L11_001BA780 + 0x50;
    u32 packed;
    func_L11_004506C0((char *)&quad);
    quad.texture = func_0027C878(texture);
    quad.flags = ((u64)flags << 2) | 0x8000000040ULL;
    quad.giftag = 0xFF9000000260ULL;
    quad.clear = 0;
    packed = color + (alpha << 24);
    quad.color[0] = packed;
    quad.color[1] = packed;
    quad.color[2] = packed;
    quad.color[3] = packed;
    rotation[3] = 0.0f;
    rotation[2] = func_00283248(camera[0] - point[0], camera[1] - point[1]);
    rotation[1] = -func_00283248(func_00282E80(position, camera), camera[2] - point[2]);
    rotation[0] = roll;
    func_00283410(matrix, rotation);
    func_00282CF0(toward, camera, position);
    func_00282F20(toward, toward, offset);
    matrix[12] = point[0] + toward[0];
    matrix[13] = point[1] + toward[1];
    matrix[14] = point[2] + toward[2];
    matrix[15] = 1.0f;
    func_L11_00450748((char *)&quad, size);
    func_00280B90(&quad, matrix, 0);
    if (D_L11_001B1CE4 == 0) {
        func_00282F20(light, data, D_L11_001B1D00);
        func_00282CC0(light, object + 0x10, light);
        func_00281EB8(light, D_L11_001B1CE8, D_L11_001B1CF8, 1, D_L11_001B1CF0, 0.08f, 0.0f);
        func_00282F20(light, data, -0.03f);
        func_00282CC0(light, object + 0x10, light);
        func_00281EB8(light, D_L11_001B1CEC, D_L11_001B1CFC, 1, D_L11_001B1CF4, 0.08f, 0.0f);
    }
}
