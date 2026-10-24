/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 564 / 600 bytes; size equality is not a match.
 * us: 0/27 placements; 564/600 bytes.
 * us2: 0/27 placements; 564/600 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Register allocation, the resident/table address materialization and ordinary scheduling differ. The unordered floating comparison behavior is preserved.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Readable manual reconstruction, measured 2026-10-23.
 * Retained profile: -O2 -G0 -ffunction-sections.
 * us: 0 of 27 places match; exit 1.
 * us2: 0 of 27 places match; exit 1.
 * pal: absent from both catalogues (exit 1).
 * Register allocation, the resident/table address materialization and ordinary scheduling differ. The unordered floating comparison behavior is preserved.
 * 2 bounded source/profile trials; no exact-C credit is claimed.
 * Live helper inputs and consumed return banks were checked against retail and
 * current definitions. Original scalar-return intent remains unqualified for
 * procedural ASM callees whose results this body does not consume.
 * Reopen with independent layout/lifetime, table-extent or scheduling evidence;
 * no source barriers, register pins, invented aliases or padding were used.
 */

extern unsigned char D_00189E20[];
extern unsigned char D_L00_0025BE74[];
extern int func_00282948(int *);
extern float func_002A78D8(float, float);
extern float func_002A7878(float, float);
extern int func_002A7820(int, int);

/* Refresh four idle articulation targets when their individual timers expire. */
void func_L00_002AB948(void) {
    unsigned char *player = D_00189E20;
    unsigned char *slot;
    int *timer;
    int index;
    float old, value;
    if (*(int *)(player + 0x2294) != 0 || (*(unsigned char **)(player + 0x2290))[0x43] != 0) return;
    slot = player;
    timer = (int *)(player + 0x11F0);
    for (index = 0; index < 4; ++index) {
        if (func_00282948(timer)) {
            if (index == 0) {
                *(float *)(player + 0x11B8) = func_002A78D8(0.174532949924469f, 0.523598849773407f);
                *(int *)(player + 0x11F0) = func_002A7820(70, 150);
            } else if (index == 1) {
                *(float *)(player + 0x11C8) = func_002A78D8(0.174532949924469f, 0.523598849773407f);
                *(int *)(player + 0x11F4) = func_002A7820(40, 90);
            } else if (index == 2) {
                *(float *)(player + 0x11D8) = func_002A78D8(0.2617994248867035f, 0.8726646900177002f);
                *(int *)(player + 0x11F8) = func_002A7820(40, 90);
            } else {
                *(float *)(slot + 0x11B4) = func_002A7878(-0.0872664749622345f, 0.523598849773407f);
                old = *(float *)(slot + 0x11B8);
                value = func_002A78D8(0.349065899848938f, 0.9599311947822571f);
                *(float *)(slot + 0x11B8) = value;
                if (!(old > 0.0f || value > 0.0f) || (old >= 0.0f && value >= 0.0f))
                    *(float *)(slot + 0x11B8) = -*(float *)(slot + 0x11B8);
                *timer = func_002A7820(35, 70);
            }
        }
        *(unsigned int *)(D_L00_0025BE74 + (index + 13) * 0xB0) = *(unsigned int *)(slot + 0x11B4);
        *(unsigned int *)(D_L00_0025BE74 + (index + 13) * 0xB0 + 4) = *(unsigned int *)(slot + 0x11B8);
        slot += 0x10;
        ++timer;
    }
}
