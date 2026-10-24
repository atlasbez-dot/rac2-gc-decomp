/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections.
 * Reported final C / retail: 2352 / 2584 bytes; size equality is not a match.
 * us: 0/1 placements; 2352/2584 bytes.
 * us2: 0/1 placements; 2352/2584 bytes.
 * pal: 0/1 placements; 2352/2584 bytes.
 * Residual: See the retained source comment for the measured residual.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Unmatched manual reconstruction: -O2 -G8 -ffunction-sections.
 * 2352 bytes versus 2584, 0/1 placements in US, US2, and PAL. First mismatch +0:
 * frame 0x1E0 versus retail 0x1F0, followed by register/source-shape differences.
 * -frac2-qcopy did not change this result. One flag at 001A8A48 is loaded
 * absolutely first, then through gp in retail; this C keeps a single truthful
 * declaration, rather than manufacturing a second alias to choose addressing.
 * RenderScales is a measured partial view; the full object extent is unknown.
 * Vertex/UV arrays intentionally retain unknown complete extents.
 * 00282A28 is a real retail assertion (teq zero,zero), not a geometry flush.
 * Helper input banks and the 64-bit texture/GS values were audited in retail.
 * Behavior and linked-image equality remain unverified. Reopen with a qualified
 * enclosing data layout and matching vector/loop register-lifetime source shape.
 */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned int Quadword __attribute__((mode(TI)));
typedef union { float v[4]; Quadword q; } Vector;
typedef struct {
    u32 color0, color1, color2, color3, color4;
    float threshold, spacing;
    int texture;
    u32 unused;
    float altitude, depth;
} GridSettings;
typedef struct {
    Vector points[4];
    u32 colors[4];
    u32 zero[8];
    u64 state[4];
} SurfacePacket;
extern char D_00189E20[];
extern int D_L01_001A8A48 __attribute__((sda));
typedef struct { unsigned char prefix[0x228]; float scale0, scale1; } RenderScales;
extern RenderScales D_L01_001BD9C0;
extern float D_L01_001B96F0[16], D_L01_001B94C0[4];
extern float D_L01_001AFE18 __attribute__((sda));
extern float D_L01_001AFDF0[2] __attribute__((sda));
extern float D_L01_001B2FD0[2][2];
extern float D_L01_00240260[][3], D_L01_00240660[][3];
extern u32 D_L01_00240560[], D_L01_00240960[];
extern float D_L01_00240A60[][2], D_L01_00240C60[][2];
extern void func_002FC560(u32, u64);
extern u64 func_0027C878(int);
extern void func_00280328(void);
extern void func_00283098(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern float func_00283CE0(int);
extern int func_00283D38(float, int, int);
extern void func_00281810(int, void *, void *, void *, int);
extern void func_00280B90(void *, int, int);
extern float func_00282E20(void *);
extern void func_00282A28(void);
void func_L01_003BAFB8(char *object)
{
    Vector point, scratch, right, up;
    Vector corners[4], along_left, along_right;
    SurfacePacket packet;
    GridSettings *settings = *(GridSettings **)(object + 0x68);
    float saved0 = D_L01_001BD9C0.scale0, saved1 = D_L01_001BD9C0.scale1;
    float x, y, t, factor, origin_x, origin_y, scale, offset_x, offset_y;
    int i, layer, count, start, j;
    u32 color, lower_color, upper_color;
    if ((*(int *)(D_00189E20 + 0x2294)) != 28 && D_L01_001A8A48 == 0) {
        D_L01_001BD9C0.scale0 = 255.0f;
        D_L01_001BD9C0.scale1 = 249.9f;
    }
    func_002FC560(0x42, 0x3200000044ULL);
    func_002FC560(8, 0);
    func_002FC560(0x14, 0xFF9000000260ULL);
    func_002FC560(0x47, 0x513F1);
    func_002FC560(6, func_0027C878(0x16));
    func_00280328();
    right.v[0] = 1.0f; right.v[1] = 0.0f;
    right.v[2] = 0.0f; right.v[3] = 1.0f;
    func_00283098(&right, &right, D_L01_001B96F0);
    up.v[0] = 0.0f; up.v[1] = 1.0f;
    up.v[2] = 0.0f; up.v[3] = 1.0f;
    func_00283098(&up, &up, D_L01_001B96F0);
    right.v[2] = 0.0f;
    func_00282F20(&right, &right, 1.0f);
    up.v[2] = 0.0f;
    func_00282F20(&up, &up, 1.0f);
    func_00282F20(&point, &right, -75.0f);
    func_00282F20(&scratch, &up, -87.0f);
    func_00282CC0(&corners[0], &point, &scratch);
    func_00282F20(&scratch, &up, 87.0f);
    func_00282CC0(&corners[2], &point, &scratch);
    func_00282F20(&point, &right, settings->depth);
    func_00282F20(&scratch, &up, -750.0f);
    func_00282CC0(&corners[1], &point, &scratch);
    func_00282F20(&scratch, &up, 750.0f);
    func_00282CC0(&corners[3], &point, &scratch);
    for (i = 0; i < 4; ++i) {
        func_00282CC0(&corners[i], &corners[i], D_L01_001B94C0);
        corners[i].v[2] = D_L01_001AFE18;
    }
    func_00282CF0(&along_left, &corners[1], &corners[0]);
    func_00282CF0(&along_right, &corners[3], &corners[2]);
    for (i = 0; i < 12; i += 2) {
        t = func_00283CE0(i) * 0.1f;
        factor = func_00283CE0(i);
        color = func_00283D38(factor / 10.0f, settings->color0, settings->color1);
        func_00282D30(&point, &along_left, t);
        D_L01_00240560[i] = color;
        D_L01_00240A60[i][0] = D_L01_00240A60[i][1] = 0.0f;
        func_00282CC0(&point, &point, &corners[0]);
        D_L01_00240260[i][0] = point.v[0];
        D_L01_00240260[i][1] = point.v[1];
        D_L01_00240260[i][2] = point.v[2];
        func_00282D30(&point, &along_right, t);
        D_L01_00240560[i+1] = color;
        D_L01_00240A60[i+1][0] = D_L01_00240A60[i+1][1] = 0.0f;
        func_00282CC0(&point, &point, &corners[2]);
        D_L01_00240260[i+1][0] = point.v[0];
        D_L01_00240260[i+1][1] = point.v[1];
        D_L01_00240260[i+1][2] = point.v[2];
    }
    func_00281810(12, D_L01_00240260, D_L01_00240560, D_L01_00240A60, 1);
    packet.state[1] = func_0027C878(0x16);
    packet.state[2] = 0xFF9000000260ULL;
    packet.state[3] = 0x8000000044ULL;
    packet.state[0] = 0;
    if (settings->threshold < D_L01_001B94C0[2] - settings->altitude &&
        (*(int *)(D_00189E20 + 0x2294)) != 28 && D_L01_001A8A48 == 0) {
        for (i = 0; i < 8; ++i) packet.zero[i] = 0;
        packet.colors[0] = packet.colors[2] = settings->color1;
        packet.colors[1] = packet.colors[3] = settings->color2;
        packet.points[0].q = packet.points[1].q = corners[1].q;
        packet.points[2].q = packet.points[3].q = corners[3].q;
        packet.points[1].v[2] = D_L01_001B94C0[2] - settings->altitude;
        packet.points[3].v[2] = D_L01_001B94C0[2] - settings->altitude;
        func_00280B90(&packet, 0, 0);
    }
    func_002FC560(0x42, 0x8000000048ULL);
    func_002FC560(8, 0);
    func_002FC560(0x14, 0xFF9000000260ULL);
    func_002FC560(0x47, 0x513F0);
    lower_color = func_00283D38(1.0f, 0, settings->color3);
    upper_color = func_00283D38(1.0f, 0, settings->color4);
    for (layer = 0; layer < 2; ++layer) {
        func_002FC560(6, func_0027C878(settings->texture + layer + 0x3F));
        for (y = settings->spacing * -2.0f; y < settings->spacing + settings->spacing;
             y += settings->spacing) {
            count = 0;
            for (x = settings->spacing * -2.0f; x < settings->spacing + settings->spacing;
                 x += settings->spacing) {
                scale = D_L01_001AFDF0[layer];
                offset_x = D_L01_001B2FD0[layer][0];
                offset_y = D_L01_001B2FD0[layer][1];
                origin_x = D_L01_001B94C0[0]; origin_y = D_L01_001B94C0[1];
                start = count;
                D_L01_00240C60[count][0] = x / (settings->spacing + settings->spacing) * scale + offset_x;
                D_L01_00240660[count][0] = x + origin_x + 1.0f;
                D_L01_00240660[count][1] = y + origin_y + 1.0f;
                D_L01_00240660[count][2] = D_L01_001AFE18;
                D_L01_00240C60[count][1] = y / (settings->spacing + settings->spacing) * scale + offset_y;
                D_L01_00240C60[count+1][0] = x / (settings->spacing + settings->spacing) * scale + offset_x;
                D_L01_00240660[count+1][0] = x + origin_x + 1.0f;
                D_L01_00240C60[count+1][1] = (y + settings->spacing) / (settings->spacing + settings->spacing) * scale + offset_y;
                D_L01_00240660[count+1][1] = y + settings->spacing + origin_y + 1.0f;
                D_L01_00240660[count+1][2] = D_L01_001AFE18;
                D_L01_00240C60[count+2][0] = (x + settings->spacing) / (settings->spacing + settings->spacing) * scale + offset_x;
                D_L01_00240C60[count+2][1] = y / (settings->spacing + settings->spacing) * scale + offset_y;
                D_L01_00240660[count+2][0] = x + settings->spacing + origin_x + 1.0f;
                D_L01_00240660[count+2][1] = y + origin_y + 1.0f;
                D_L01_00240660[count+2][2] = D_L01_001AFE18;
                D_L01_00240C60[count+3][0] = (x + settings->spacing) / (settings->spacing + settings->spacing) * scale + offset_x;
                D_L01_00240C60[count+3][1] = (y + settings->spacing) / (settings->spacing + settings->spacing) * scale + offset_y;
                D_L01_00240660[count+3][0] = x + settings->spacing + origin_x + 1.0f;
                D_L01_00240660[count+3][1] = y + settings->spacing + origin_y + 1.0f;
                D_L01_00240660[count+3][2] = D_L01_001AFE18;
                count += 4;
                for (j = start; j < count; ++j) {
                    point.v[0] = D_L01_00240660[j][0] - D_L01_001B94C0[0];
                    point.v[1] = D_L01_00240660[j][1] - D_L01_001B94C0[1];
                    point.v[2] = D_L01_00240660[j][2] - D_L01_001B94C0[2];
                    point.v[3] = 1.0f;
                    factor = func_00282E20(&point) / (settings->spacing + settings->spacing);
                    if (factor > 1.0f) factor = 1.0f;
                    D_L01_00240960[j] = func_00283D38(factor, lower_color, upper_color);
                }
                if (count >= 64) func_00282A28();
            }
            func_00281810(count, D_L01_00240660, D_L01_00240960, D_L01_00240C60, 1);
        }
    }
    D_L01_001BD9C0.scale0 = saved0; D_L01_001BD9C0.scale1 = saved1;
    func_002FC560(0x47, 0x5360A);
}
