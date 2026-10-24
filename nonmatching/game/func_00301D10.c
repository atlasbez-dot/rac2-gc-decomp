/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections (reported default game profile).
 * Reported final C / retail: 512 / 520 bytes; size equality is not a match.
 * us: 0/28 placements; 512/520 bytes.
 * us2: 0/28 placements; 512/520 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Two missing register copies around random direction; isolated -fno-gcse tied.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching denomination collection. Four bounded trials, 2026-10-23.
 * Default -O2 -G0 -ffunction-sections:512/520 bytes, correct 0x50 frame;
 * US and US2 each 0/28, exit 1; absent from PAL catalogue (not a match).
 * The random-direction selection lacks two retail register-copy instructions.
 * Qualified isolated -fno-gcse produced the same bytes. Reopen only with new
 * measured scalar snapshot/allocation evidence. The seven GPR plus three FP inputs
 * and explicit pointer return of C2210 were verified from its whole retail body.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_00282CC0(void *, void *, void *);
extern int D_001A79F8 __attribute__((sda));
extern int D_001A79F0 __attribute__((sda));
extern int D_0018D208[];
extern int ref_00301D10_00 __attribute__((sda));
extern char *ref_00301D10_01 __attribute__((sda));
extern void func_0029B698(int);
extern void func_002A7A00(float *, float, float);
extern void func_00282D30(void *, void *, float);
extern int func_002A77E0(int);
extern float func_002A7878(float, float);
extern void *func_002C2210(void *, int, unsigned int, int, int, void *, int,
                         float, float, float);

/* Credit the collected denomination, then emit its paired particle trails. */
void func_00301D10(char *object)
{
    float velocity[4], position[4];
    int amount;
    int spin;
    int random;
    float size;
    switch ((short)(*(short *)(object + 0xaa) - 13)) {
    default: case 0: amount = 1; break;
    case 1: amount = 5; break;
    case 2: amount = 20; break;
    case 3: amount = 50; break;
    case 4: amount = 100; break;
    case 5: amount = 500; break;
    case 6: amount = 1000; break;
    }
    D_001A79F8 += amount;
    if (*(u8 *)(*(char **)(object + 0x68) + 0x40) ||
        (ref_00301D10_00 && (u32)object < (u32)ref_00301D10_01))
        D_0018D208[D_001A79F0] += amount;
    func_0029B698(180);
    func_002A7A00(velocity, 0.011666667f, 0.016666668f);
    func_00282D30(position, velocity, 10.0f);
    func_00282CC0(position, position, object + 0x10);
    random = func_002A77E0(2);
    spin = random - 1;
    if (random) spin = random;
    size = func_002A7878(0.4f, 0.5f);
    func_002C2210(position, 25, 0x7f207f7f, 0, spin, velocity, 0,
                 size * 0.2f, size, 0.0f);
    func_002C2210(position, 25, 0x7f7f7f7f, 1, -spin, velocity, 0,
                 size * 0.14f, size * 0.7f, 0.0f);
}
