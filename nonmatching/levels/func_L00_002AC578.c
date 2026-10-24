/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 1128 / 1168 bytes; size equality is not a match.
 * us: 0/27 placements; 1128/1168 bytes.
 * us2: 0/27 placements; 1128/1168 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Qualified copies produce 1128/1168 bytes, with a 0x80 frame versus retail 0x90. Allocation, base materialization and common rejection tails differ. Raw unordered comparisons and the 0.5 contact-height path are preserved.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Readable manual reconstruction, measured 2026-10-23.
 * Retained profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0 of 27 places match; exit 1.
 * us2: 0 of 27 places match; exit 1.
 * pal: absent from both catalogues (exit 1).
 * Qualified copies produce 1128/1168 bytes, with a 0x80 frame versus retail 0x90. Allocation, base materialization and common rejection tails differ. Raw unordered comparisons and the 0.5 contact-height path are preserved.
 * 2 bounded source/profile trials; no exact-C credit is claimed.
 * Live helper inputs and consumed return banks were checked against retail and
 * current definitions. Original scalar-return intent remains unqualified for
 * procedural ASM callees whose results this body does not consume.
 * Reopen with independent layout/lifetime, table-extent or scheduling evidence;
 * no source barriers, register pins, invented aliases or padding were used.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef int V4_F6a70b950 __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct { float x; float y; float z; } FamilyC94396F4Vector_Fc94396f4;
extern unsigned char D_00189E20[];
extern unsigned char D_L00_001BF200[];
extern float func_L00_002D3B00(char *);
extern void func_L00_002D3B58(V4_F6a70b950 *, V4_F6a70b950 *, float);
extern void func_L00_002D3BD8(char *, int, float);
extern void func_L00_002D3778(FamilyC94396F4Vector_Fc94396f4 *, FamilyC94396F4Vector_Fc94396f4 *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_L00_002ACF88(void *, void *, void *);
extern int func_L00_002AB108(float *, float, float);
extern int func_002AD0B0(unsigned char *);
extern void func_L00_002D3638(float *, int, float, float, float);
extern int func_002761F8(void *, void *, unsigned int, void *, void *);
extern int func_00278E78(void);
extern float func_L00_002D3EA8(void *);
extern void func_002830C0(void *, void *, void *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_00282E80(void *, void *);
#define REAL(o) (*(float *)(player + (o)))
#define WORD(o) (*(int *)(player + (o)))
#define SHORT(o) (*(short *)(player + (o)))

/* Predict the next ledge contact, then validate the two obstruction probes. */
void func_L00_002AC578(void) {
    Vector predicted, probeEnd, localNormal;
    unsigned char *player = D_00189E20;
    unsigned char *hit = D_L00_001BF200;
    unsigned char *state;
    int contact;
    float height, distance, angle, limit;
    if (REAL(0x31C) < 0.4f) return;
    if (func_L00_002D3B00((char *)player + 0xF0) < -0.3333333432674408f || player[0x22C3]) return;
    if (WORD(0x578)) { WORD(0x1D4) = 0; return; }
    predicted.q = *(Quadword *)(player + 0x80);
    probeEnd.q = *(Quadword *)(player + 0x110);
    func_L00_002D3B58(&probeEnd.q, &probeEnd.q, 0.0f);
    func_L00_002D3BD8((char *)&probeEnd, (int)&probeEnd, 20.0f);
    func_00282CC0(&predicted, &predicted, &probeEnd);
    distance = func_L00_002D3B00((char *)player + 0xF0);
    distance = distance * 20.0f - REAL(0x520) * 20.0f * 20.0f * 0.5f;
    func_L00_002D3778((FamilyC94396F4Vector_Fc94396f4 *)&predicted,
                     (FamilyC94396F4Vector_Fc94396f4 *)&predicted, distance);
    if (func_L00_002ACF88(&predicted, player + 0x90, 0)) {
        WORD(0x1D4) = 0; SHORT(0x210) = 0x16; return;
    }
    if (!func_L00_002AB108(0, 0.3f, 1.0f)) return;
    state = 0;
    if (*(unsigned char **)(hit + 0x18)) state = (unsigned char *)func_002AD0B0(*(unsigned char **)(hit + 0x18));
    height = 1.7f;
    if (state && (*(unsigned int *)(state + 0x3C) & 0x20)) height = 0.5f;
    else if (WORD(0x2294) != 0x11 && (!player[0x285] || player[0x284])) height = 3.0f;
    func_L00_002D3638(predicted.f, 1, 0.0f, 0.0f, height);
    func_L00_002D3638(probeEnd.f, 1, REAL(0x264) + 1.4f, 0.0f, height);
    if (!func_002761F8(&predicted, &probeEnd, 2, 0, 0)) return;
    contact = func_00278E78();
    if (contact == 10 || contact == 12) return;
    *(unsigned char **)(player + 0x294) = *(unsigned char **)(hit + 0x18);
    angle = func_L00_002D3EA8(hit + 0x40);
    if (angle < 1.3089970350265503f) return;
    func_002830C0(&localNormal, hit + 0x40, player + 0x40);
    angle = func_00283248(localNormal.f[0], localNormal.f[1]);
    angle = func_00283C80(angle, 3.1415927410125732f);
    if (0.8726646900177002f < angle) return;
    limit = WORD(0x2294) == 0x11 ? 0.95f : 0.72f;
    func_L00_002D3638(predicted.f, 1, 0.0f, 0.0f, 0.2f);
    func_L00_002D3638(probeEnd.f, 1, REAL(0x264) + 1.4f, 0.0f, 0.2f);
    if (!func_002761F8(&predicted, &probeEnd, 2, 0, 0)) return;
    distance = func_00282E80(hit + 0x20, &predicted);
    if (limit < distance) return;
    *(Quadword *)(player + 0x4E0) = *(Quadword *)(hit + 0x40);
    REAL(0x4EC) = func_00283248(*(float *)(hit + 0x40), *(float *)(hit + 0x44));
    if (WORD(0x229C) != 4 && WORD(0x22A4) != 4 && WORD(0x22B0) != 4) return;
    if (SHORT(0x24D8) && func_00283C80(REAL(0x4FC), REAL(0x4EC)) < 2.96705961227417f) return;
    player[0x24DA] = 0;
    if (contact == 15) player[0x24DA] = 1;
    else if (player[0x24DB]) return;
    WORD(0x1D4) = WORD(0x2294) == 0x11 ? 7 : 6;
}
