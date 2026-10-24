/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 1032 / 1068 bytes; size equality is not a match.
 * us: 0/1 placements; 1032/1068 bytes.
 * us2: 0/1 placements; 1032/1068 bytes.
 * pal: 0/1 placements; 1032/1068 bytes.
 * Residual: Double-ribbon field/store allocation; full manual body and true packet/basis extents.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching ribbon reconstruction, 2026-10-23; 2 bounded meaningful trials.
 * Profile:-O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * US/US2/PAL each:1032/1068 bytes, 0/1, check.py exit 1.
 * The measured frame is 0x210. Real packet extents, quadword copies and
 * width-clears are preserved. Remaining differences concern field/store order,
 * scalar lifetimes and allocation; no barrier or false prototype was added.
 * Reopen with measured constructor/store-scheduling evidence. The three packet
 * helpers matched separately; their 64-bit texture handles stay intact.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int EffectWord __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } EffectVector __attribute__((aligned(16)));
typedef struct {
    EffectVector position[4];
    u32 color[4];
    float uv[4][2];
    unsigned long primitive, texture, mode, registers;
} EffectPacket;
typedef struct { u8 prefix[0x140]; EffectVector position; } EffectCameraView;
extern unsigned long func_0027C878(int);
extern float func_002A7878(float, float);
extern int func_001163B0(void);
extern void func_00305838(char *);
extern void func_00307C30(char *);
extern void func_00306040(void *, float *);
extern void func_00305910(void *, float *);
extern void func_00307CC0(void *, float *);
extern void func_0029FCC0(char *, int, char *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00283098(void *, void *, void *);
extern void func_002830C0(void *, void *, void *);
extern void func_00280B90(void *, void *, int);
#define EFFECT_COPY(destination, source) (*(EffectWord *)(destination) = *(EffectWord *)(source))

extern EffectCameraView ref_00307FC0_00;

/* Construct two camera-facing ribbons with independently sized end caps. */
void func_00307FC0(char *owner)
{
    EffectPacket narrow, wide;
    EffectVector basis[4];
    EffectVector startPoint, endPoint;
    EffectVector thinWidth, wideWidth;
    EffectVector joint;
    char *state = *(char **)(owner + 0x68);
    float size;
    func_0029FCC0(owner, 1, (char *)&joint);
    EFFECT_COPY(&startPoint,&joint);
    size = func_002A7878(2.0f,4.0f);
    func_00282F20(&endPoint,state+0x30,size);
    func_00283098(&endPoint,&endPoint,owner+0xc0);
    func_00282CC0(&endPoint,&endPoint,&joint);
    func_00307CC0(owner,(float *)&startPoint);
    narrow.texture = func_0027C878(23);
    narrow.mode = 0x0000ff9000000260UL;
    narrow.registers = 0x0000008000000048UL;
    narrow.color[0] = narrow.color[1] = 0x7f103080;
    narrow.primitive = 0;
    narrow.color[2] = narrow.color[3] = 0x00103080;
    wide.texture = func_0027C878(23);
    wide.mode = 0x0000ff9000000260UL;
    wide.registers = 0x0000008000000048UL;
    wide.color[0] = wide.color[1] = 0x3f103080;
    wide.primitive = 0;
    wide.color[2] = wide.color[3] = 0x00103080;
    *(EffectWord *)&thinWidth = 0;
    *(EffectWord *)&wideWidth = 0;
    thinWidth.w=1.0f; wideWidth.w=1.0f;
    thinWidth.z=func_002A7878(0.1f,0.3f);
    wideWidth.z=thinWidth.z+thinWidth.z;
    func_00307C30((char *)&narrow);
    func_00307C30((char *)&wide);
    if (!(func_001163B0() & 1)) {
        narrow.uv[0][1]=0; narrow.uv[1][1]=1.0f;
        narrow.uv[2][1]=0; narrow.uv[3][1]=1.0f;
        wide.uv[0][1]=0; wide.uv[1][1]=1.0f;
        wide.uv[2][1]=0; wide.uv[3][1]=1.0f;
    } else {
        narrow.uv[0][1]=1.0f; narrow.uv[1][1]=0;
        narrow.uv[2][1]=1.0f; narrow.uv[3][1]=0;
        wide.uv[0][1]=1.0f; wide.uv[1][1]=0;
        wide.uv[2][1]=1.0f; wide.uv[3][1]=0;
    }
    narrow.uv[0][0]=0; narrow.uv[1][0]=0;
    narrow.uv[2][0]=1.0f; narrow.uv[3][0]=1.0f;
    wide.uv[0][0]=0; wide.uv[1][0]=0;
    wide.uv[2][0]=1.0f; wide.uv[3][0]=1.0f;
    func_00282CF0(&basis[0],&endPoint,&startPoint);
    func_00282F20(&basis[0],&basis[0],1.0f);
    func_00282CF0(&basis[1],&ref_00307FC0_00.position,&startPoint);
    func_00282DD8(&basis[2],&basis[1],&basis[0]);
    func_00282F20(&basis[2],&basis[2],1.0f);
    func_00282DD8(&basis[1],&basis[0],&basis[2]);
    EFFECT_COPY(&basis[3],&startPoint);
    EFFECT_COPY(&narrow.position[0],&thinWidth);
    EFFECT_COPY(&wide.position[0],&wideWidth);
    func_00282D30(&narrow.position[1],&narrow.position[0],-1.0f);
    func_00282D30(&wide.position[1],&wide.position[0],-1.0f);
    func_002830C0(&narrow.position[0],&narrow.position[0],basis);
    func_002830C0(&narrow.position[1],&narrow.position[1],basis);
    func_002830C0(&wide.position[0],&wide.position[0],basis);
    func_002830C0(&wide.position[1],&wide.position[1],basis);
    EFFECT_COPY(&basis[3],&endPoint);
    thinWidth.z *= 0.15f;
    wideWidth.z = thinWidth.z+thinWidth.z;
    EFFECT_COPY(&narrow.position[2],&thinWidth);
    EFFECT_COPY(&wide.position[2],&wideWidth);
    func_00282D30(&narrow.position[3],&narrow.position[2],-1.0f);
    func_00282D30(&wide.position[3],&wide.position[2],-1.0f);
    func_002830C0(&narrow.position[2],&narrow.position[2],basis);
    func_002830C0(&narrow.position[3],&narrow.position[3],basis);
    func_002830C0(&wide.position[2],&wide.position[2],basis);
    func_002830C0(&wide.position[3],&wide.position[3],basis);
    func_00280B90(&narrow,0,0);
    func_00280B90(&wide,0,0);
}
