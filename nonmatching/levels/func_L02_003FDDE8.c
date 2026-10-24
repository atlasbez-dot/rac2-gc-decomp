/* Retained manual C reconstruction; not linked and not matching.
 * Profile: -O2 -G8 -ffunction-sections
 * Local tools/check.py measurements: us: 948 compiled bytes, 0/1 placements, exit 1; us2: 948 compiled bytes, 0/1 placements, exit 1; pal: 948 compiled bytes, 0/1 placements, exit 1.
 * Retail extent: 964 bytes. No exact-C credit and no full build performed.
 * Residual: 948 versus 964 bytes (-16), 0x60 frame. GP coordinate/color objects are explicit; source omits a retail saved register and schedules FP setup and selection gates differently. Both special entries are handled.
 * Reopen: Reopen with a qualified layout for the selection table and a measured register-lifetime hypothesis for the pulse/selection loop.
 * Arrays with unknown total extent remain incomplete. Pointer-offset views do
 * not establish the full sizes or ownership of game records.
 */
/* Draws the contextual selection help and locates the next available entry. */
typedef unsigned char u8;
extern u8 *D_L02_001A904C;
extern float D_L02_001B3E04;
extern int D_L02_001B30C8;
extern u8 D_001395B8[], D_00139568[], D_00138180[];
extern u8 D_L02_00264A70[];
extern u8 *D_L02_001B1190[] __attribute__((sda));
extern void func_L00_0037B7B0(void);
extern int func_00336D50(u8 *, int);
extern void func_00300A00(char *, int, float, float, float, float, float);
extern unsigned int func_00283D38(unsigned int, unsigned int, float);
extern int func_L02_003F9B70(int);
extern int func_00288D58(void);
extern void func_002FC560(unsigned int, unsigned long long);
extern float D_L02_001B1260 __attribute__((sda));
extern int D_L02_001B1264 __attribute__((sda));
extern int D_L02_001B1268 __attribute__((sda));
extern int D_L02_001B126C __attribute__((sda));
extern int D_L02_001B1270 __attribute__((sda));
extern int D_L02_001B1274 __attribute__((sda));
extern int D_L02_001B1278 __attribute__((sda));
extern unsigned int D_L02_001B127C __attribute__((sda));
extern unsigned int D_L02_001B1280 __attribute__((sda));
extern unsigned int D_L02_001B1288 __attribute__((sda));
extern unsigned int D_L02_001B128C __attribute__((sda));
void func_L02_003FDDE8(u8 *object, int enabled)
{
    u8 *state;
    int label, phase, i;
    unsigned int color;
    float pulse;
    if (D_L02_001A904C == 0) return;
    func_L00_0037B7B0();
    state = *(u8 **)(object + 0x68);
    label = func_00336D50(D_L02_001A904C + 0x8710, 0x49);
    func_00300A00((char *)label, D_L02_001B1280, (float)D_L02_001B1264,
        (float)(int)((float)D_L02_001B1268 * D_L02_001B3E04 + 0.5f), D_L02_001B1260, 1.0f, 0.0f);
    label = func_00336D50(D_L02_001A904C + 0x8710, 0x48);
    func_00300A00((char *)label, D_L02_001B127C, (float)D_L02_001B1264,
        (float)(int)((float)D_L02_001B1268 * D_L02_001B3E04 + 0.5f), D_L02_001B1260, 1.0f, 0.0f);
    phase = D_L02_001B30C8 % 50;
    if (phase >= 25) pulse = 1.0f - (float)(phase - 25) * 0.04f;
    else pulse = (float)phase * 0.04f;
    color = func_00283D38(D_L02_001B127C, D_L02_001B1280, pulse);
    if (enabled) {
        if (*(short *)(state + 0x118) != 0) {
            label = func_00336D50(D_L02_001A904C + 0x8710, 0x4b);
            func_00300A00((char *)label, (*(unsigned int *)(D_00138180 + 0x1a0) & 0x8000) ? D_L02_001B1288 : color,
                (float)D_L02_001B126C, (float)(int)((float)D_L02_001B1270 * D_L02_001B3E04 + 0.5f), D_L02_001B1260, 1.0f, 0.0f);
        }
        for (i = *(short *)(state + 0x118) + 1; i < 14; i++) {
            if (D_001395B8[func_L02_003F9B70(*(int *)(D_L02_001B1190[i] + 8))] == 0) continue;
            if (i >= 12 && !func_00288D58()) continue;
            if (i == 7 && D_L02_00264A70[D_00139568[0x1e] * 0xe0 + 4] == 0) continue;
            if (i == 8 && D_L02_00264A70[D_00139568[0x2a] * 0xe0 + 4] == 0) continue;
            label = func_00336D50(D_L02_001A904C + 0x8710, 0x4a);
            func_00300A00((char *)label, (*(unsigned int *)(D_00138180 + 0x1a0) & 0x2000) ? D_L02_001B128C : color,
                (float)D_L02_001B1274, (float)(int)((float)D_L02_001B1278 * D_L02_001B3E04 + 0.5f), D_L02_001B1260, 1.0f, 0.0f);
            break;
        }
    }
    func_002FC560(0x47, 0x5360b);
}
