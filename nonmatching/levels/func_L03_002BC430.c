/* Signature/interface follow-up, 23 October 2026.
 * Profile: -O2 -G0 -ffunction-sections.
 * USA v1.01: 2280/2088 bytes, 0/2 carrying placements.
 * USA v2.00: 2280/2088 bytes, 0/2 carrying placements.
 * PAL: canonical name absent from the catalogue.
 * The ignored func_002AA2E8 result is declared float. func_L00_002D3A58 follows the one-
 * pointer current C interface; its removed extra float expression was a constant. The
 * earlier camera return-bank repair is preserved.
 * This follows the current linked C contract; it does not independently prove the original
 * source declaration.
 * The retained C remains nonmatching. Earlier sizes and residual offsets below are
 * historical and superseded by this measurement; their reopening hypotheses remain
 * unqualified. No linked build was run for this follow-up.
 */

/* Historical measurements, superseded where inconsistent with the follow-up above. */
/* GNU game -O2 -G0, 2280/2088 bytes, us/us2 each 0/2 places; absent from PAL.
 * ABI repair: func_L00_002B54F8 takes two floats; func_002AA898 takes
 * position/velocity pointers and returns a float, stored as float at +0x1a8.
 * The earlier 2268-byte measurement used incorrect prototypes and is superseded.
 * Camera-state branches are reconstructed; raw player accesses still produce
 * different address anchors, vector copies and allocation. Reopen with typed
 * player state and a qualified vector-copy profile.
 */
typedef struct { float x, y, z, w; } CameraVector;
extern unsigned char D_L03_00189E20[];
extern int D_L03_001A8FF0;
extern float D_L03_001A7DC0;
extern float D_L03_001B9998;
extern CameraVector D_L03_001B9BB0;
extern void func_L00_002B54F8(float, float);
extern float func_002AA2E8(float *, float, float);
extern void func_L00_002B41B8(float, float);
extern void func_L00_002D3BD8(float, void *, void *);
extern void func_L00_002D3798(float, void *, void *);
extern void func_L00_002B3EF8(float, float, float, int);
extern void func_L01_002B6948(float);
extern float func_00282DB0(void *, void *);
extern void func_00283098(void *, void *, void *);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_L00_002D3B58(float, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern float func_00283C80(float, float);
extern void func_00282F20(void *, void *, float);
extern float func_002AA898(float *, float *, int, float, float, float, float);
extern float func_00283BE0(float, float);
extern void func_L00_002AA0F0(float, float, float);
extern float func_L00_002D3A58(char *);
#define CF(o) (*(float *)(D_L03_00189E20 + (o)))
#define CI(o) (*(int *)(D_L03_00189E20 + (o)))
#define CS(o) (*(short *)(D_L03_00189E20 + (o)))
#define CB(o) (D_L03_00189E20[(o)])
#define CV(o) (*(CameraVector *)(D_L03_00189E20 + (o)))

void func_L03_002BC430(void) {
    CameraVector saved, temp;
    float angle, step, scale;
    float oldAngle = CF(0x1A0);
    if (CI(0x2294) == 10) {
        func_L00_002B54F8(0.7f, 0.0f);
        CV(0x160) = CV(0xA60);
        CF(0x1B4) = CF(0x174);
        return;
    }
    if (CI(0x2294) == 0x10) {
        angle = CF(0x454);
        if (CI(0x1B8) > 0x36) {
            func_002AA2E8((float *)(D_L03_00189E20 + 0x520), 0.0069444444961845875f, 0.0019444444915279746f);
            angle = CF(0x454);
            if (CI(0x1B8) > 0x36)
                angle = 0.05833333730697632f;
        }
        CF(0x1B0) = angle;
        func_L00_002B41B8(0.012222222983837128f, 0.0125f);
        func_L00_002D3BD8(0.0f, D_L03_00189E20 + 0xF0, D_L03_00189E20 + 0xF0);
        func_L00_002D3798(CF(0x1B4), D_L03_00189E20 + 0xF0, D_L03_00189E20 + 0xF0);
        return;
    }
    if (CI(0x2294) == 0x1B || CI(0x2294) == 0x48) {
        if (CI(0x2294) == 0x1B) {
            if (CI(0x1B8) > 0x28) {
                func_L00_002B3EF8(0.04f, 0.2f, 0.2501639127731323f, 0);
                func_L01_002B6948(0.0055555556900799274f);
            }
            if (CF(0xC38) >= 13.0f && CF(0xC38) <= 30.0f)
                func_002AA2E8((float *)(D_L03_00189E20 + 0x4BC), CF(0xC38) > 27.0f ? 0.0f : 0.03333333507180214f, 0.002222222276031971f);
        } else {
            if (CF(0xC38) >= 5.0f && CF(0xC38) <= 18.0f)
                func_002AA2E8((float *)(D_L03_00189E20 + 0x4BC), CF(0xC38) > 15.0f ? 0.0f : 0.02083333395421505f, 0.002222222276031971f);
        }
        temp.x = CF(0x4BC);
        temp.y = 0.0f;
        temp.z = func_00282DB0(D_L03_00189E20 + 0xF0, D_L03_00189E20 + 0x20);
        func_00283098(D_L03_00189E20 + 0xF0, &temp, D_L03_00189E20);
        return;
    }
    if (CI(0x2294) == 0xB) {
        CF(0x1A0) = CF(0x4C4);
        CV(0x190) = CV(0x480);
        func_L00_002B3EF8(0.04f, 0.2f, 0.116355299949646f, 0);
        CF(0x1B4) = CI(0x4D4) == 3 ? 0.0f : CF(0x4D8);
        if (!CB(0x52D)) {
            func_002AA2E8((float *)(D_L03_00189E20 + 0x4DC), !CB(0x49E) || CS(0x4AE) > 11 ? 0.07f : 0.0f, 0.002222222276031971f);
        } else {
            step = CF(0x24B8) * 0.0833333358168602f;
            if (step < 0.03333333507180214f)
                step = 0.03333333507180214f;
            func_002AA2E8((float *)(D_L03_00189E20 + 0x4DC), step, 0.010277777910232544f);
            CF(0x1B4) = CF(0x174);
        }
        if (!CB(0x22C3)) {
            CF(0xF0) = func_00283180(CF(0x4C0));
            CF(0xF0) *= CF(0x4DC);
            CF(0xF4) = func_00283198(CF(0x4C0));
            CF(0xF4) *= CF(0x4DC);
        } else {
            func_L00_002D3BD8(CF(0x4DC), &temp, D_L03_00189E20 + 0x470);
            func_L00_002D3B58(0.0f, &temp, &temp);
            func_L00_002D3BD8(0.0f, D_L03_00189E20 + 0xF0, D_L03_00189E20 + 0xF0);
            func_00282CC0(D_L03_00189E20 + 0xF0, D_L03_00189E20 + 0xF0, &temp);
        }
        if (!CB(0x22C3) && !CB(0x52D)) {
            scale = func_00283198(func_00283C80(CF(0x4C4), CF(0x4C0))) * CF(0x4D8);
            CF(0xF0) += func_00283180(CF(0x4C4)) * scale;
            CF(0xF4) += func_00283198(CF(0x4C4)) * scale;
        }
        func_L00_002B54F8(0.7f, 0.0f);
        CV(0x160) = CV(0xA60);
        return;
    }
    if (CI(0x2294) == 0x11) {
        CF(0x1A0) = CF(0x4FC);
        CV(0x190) = CV(0x4F0);
        if (CI(0x1B8) > 9)
            func_L00_002B3EF8(0.041999999433755875f, 0.2f, 0.1978040188550949f, -1);
        if (CI(0x1B8) > 8) {
            if (!CS(0x348)) {
                CF(0xF0) = func_00283180(CF(0x1A0)) * 0.08166667073965073f;
                CF(0xF4) = func_00283198(CF(0x1A0)) * 0.08166667073965073f;
            } else {
                func_L00_002D3BD8(0.0f, D_L03_00189E20 + 0xF0, D_L03_00189E20 + 0xF0);
                func_00282F20(&temp, D_L03_00189E20 + 0x190, 0.08166667073965073f);
                func_00282CC0(D_L03_00189E20 + 0xF0, D_L03_00189E20 + 0xF0, &temp);
            }
        }
        CF(0x1B4) = CF(0x174);
        return;
    }
    if (CI(0x2294) == 0x81 && !D_L03_001A8FF0) {
        func_L00_002B3EF8(0.04f, 0.2f, CF(0x494), 0);
        CF(0x1B4) = 0.0f;
        return;
    }
    if (CI(0x2294) == 0x2C) {
        angle = CF(0x98);
        CF(0x1A8) = func_002AA898(&angle, (float *)(D_L03_00189E20 + 0x1A4), 0,
                                 CF(0x1A0), 0.017999999225139618f, 0.2f, 0.12217307090759277f);
        func_L00_002AA0F0(0.0f, 0.0f, func_00283BE0(angle, CF(0x98)));
    } else {
        saved = CV(0x190);
        if (CS(0x1454)) {
            CF(0x1A0) = D_L03_001B9998;
            CV(0x190) = D_L03_001B9BB0;
        }
        func_L00_002B3EF8(0.04f, 0.2f, CF(0x494), 0);
        if (CS(0x1454)) {
            CF(0x1458) = oldAngle;
            CV(0x190) = saved;
            CF(0x1A0) = oldAngle;
            CV(0x1440) = CV(0x190);
        }
    }
    func_L00_002B54F8(0.7f, 0.0f);
    CV(0x160) = CV(0xA60);
    step = 0.0055555556900799274f;
    if (CF(0x1B0) < D_L03_001A7DC0 * 0.0033333336468786f) {
        if (CI(0x229C) == 2) {
            angle = func_L00_002D3A58((char *)D_L03_00189E20 + 0xF0);
            func_002AA2E8(&angle, 0.0f, CF(0xA84));
            func_L00_002D3BD8(angle, D_L03_00189E20 + 0xF0, D_L03_00189E20 + 0xF0);
            return;
        }
        if (CS(0x34A))
            step = 0.003055555745959282f;
        else
            step = CS(0x524) ? 0.0005555555690079927f : 0.002222222276031971f;
    }
    func_L01_002B6948(step);
}
