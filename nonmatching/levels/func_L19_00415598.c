/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por -g.
 * Reported final C / retail: 2820 / 2824 bytes; size equality is not a match.
 * us: 0/2 placements; 2820/2824 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: First instruction +0xc; actor/context register swap, joins and scheduling; a prior equal-size draft was not exact.
 * Reopening condition: An allocation witness with the complete twelve-GPR/seven-FP ABBB8 ABI.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained plain C reconstruction, 23 October 2026; not matched or linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por -g
 * USA final: 2820/2824 bytes; zero placements match.
 * Actor/context registers are exchanged; control-flow and scheduling differ despite equal-size first draft.
 * Reopen on independently supported source/address-lifetime evidence.
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
extern u8 *D_L19_001B2A1C __attribute__((sda));
extern u8 *D_L19_001B2B0C;
extern int D_001A79F0 __attribute__((sda));
extern u8 D_0019B2E8[], D_0019B4A8[];
extern u8 D_L19_0021EE94[];
extern int D_L19_001B9D00;
extern u8 *D_0018C0B0, *D_0018AA38, *D_0018A15C, *D_0018A3A8;
extern u8 D_0018C0D4;
extern short D_0018A16E;
extern int D_0018A398;
extern Vector D_00189EA0, D_00189EB0, D_00189F20;
extern float D_00189F28;
extern float D_L19_001B1BD0 __attribute__((sda));
extern float D_L19_001B1BE0 __attribute__((sda));
extern float D_L19_001B1BE4 __attribute__((sda));
extern float D_L19_001B1BE8 __attribute__((sda));
extern float D_L19_001B1BEC __attribute__((sda));
extern float D_L19_001B1BF0 __attribute__((sda));
extern float D_L19_001B1BF4 __attribute__((sda));
extern float func_002A7940(void);
extern void func_002A7750(u8 *, u8, int);
extern int func_002B38B8(u8 *);
extern void func_002A0430(unsigned int);
extern void *func_002A9640(void *, u32, int);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282F20(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_00283B98(float, float);
extern float func_002AA150(float, float, float);
extern float func_002AA898(float *, float *, int, float, float, float, float);
extern void func_002AEF28(float *, float *, float *, float, float, float);
extern void func_L01_00316C48(void *, void *, void *, void *, void *);
extern void func_002AD6F0(void *, void *, void *, void *);
extern void func_L18_002CFF48(int);
extern void func_002DF3F8(void *, void *);
extern void func_002B0A68(char *, int, int, u8, float, float, float, float);
/* Seven FP inputs and twelve GPR/stack inputs are live at this call. */
extern void func_002ABBB8(void *, void *, void *, int, int, int, int, int,
    int, void *, u8, int, float, float, float, float, float, float, float);

#define I(p, o) (*(int *)((u8 *)(p) + (o)))
#define F(p, o) (*(float *)((u8 *)(p) + (o)))
#define H(p, o) (*(short *)((u8 *)(p) + (o)))
#define Q(p, o) (*(Quad *)((u8 *)(p) + (o)))
#define UPDATE_GATE() do { \
    if (actor[0xb0] != 0xff && state[0xb3]) { \
        id = *(unsigned short *)(actor + 0xb2); \
        gate = D_0019B4A8 + ((int)(id << 16) >> 17) + D_001A79F0 * 0x400; \
        if (!(id & 1)) { if ((*gate & 7) != 7) ++*gate; } \
        else { if (((*gate >> 4) & 7) != 7) *gate += 0x10; } \
    } \
} while (0)

void func_L19_00415598(u8 *actor)
{
    Vector old_position, old_rotation, temp, origin, rotation, point;
    u8 *state = *(u8 **)(actor + 0x68);
    u8 *gate;
    u8 *entry;
    u8 *saved_player;
    u8 saved_mode;
    unsigned int id;
    int index, inactive;
    float progress, blend, height, x, y, old_z;
    old_position.q = Q(actor, 0x10);
    old_rotation.q = Q(actor, 0xf0);
    switch (actor[0x20]) {
    case 0:
        Q(state, 0x80) = Q(actor, 0xf0);
        Q(state, 0x90) = 0;
        F(state, 0xc8) = func_002A7940();
        if (I(state, 0xa0) == -1) {
            *(unsigned short *)(actor + 0x34) |= 2;
            return;
        }
        F(state, 0xa8) = 0.0f;
        I(state, 0x5c) |= 1;
        Q(state, 0x60) = Q(actor, 0x10);
        Q(state, 0x70) = Q(actor, 0xf0);
        inactive = 1;
        if (I(state, 0xd0) && actor[0xb0] != 0xff &&
                (D_0019B2E8[actor[0xb0] + D_001A79F0 * 16] & 0x80))
            inactive = 0;
        else if (D_L19_0021EE94[I(state, 0xac)])
            inactive = 0;
        else if (state[0xb3]) {
            id = *(unsigned short *)(actor + 0xb2);
            if (D_L19_0021EE94[(short)id])
                inactive = 0;
            else {
                index = D_0019B4A8[((int)(id << 16) >> 17) + D_001A79F0 * 0x400];
                if ((id & 1) ? ((index >> 4) & 7) : (index & 7))
                    inactive = 0;
            }
        }
        if (inactive)
            func_002A7750(actor, 1, -1);
        else {
            UPDATE_GATE();
            entry = D_L19_001B2B0C + I(state, 0xa0) * 0x80;
            Q(actor, 0x10) = Q(entry, 0x30);
            Q(actor, 0xf0) = Q(entry, 0x70);
            func_002A7750(actor, 4, -1);
        }
        F(state, 0xb8) = 0.0f;
        F(state, 0xbc) = F(actor, 0x18);
        break;
    case 1:
        if (actor[0xbc] || func_002B38B8(actor) || I(state, 0xac) == -1 ||
                (D_L19_001B2A1C[I(state, 0xac) * 0x100 + 0x20] == 0xfe) ||
                (D_L19_001B2A1C[I(state, 0xac) * 0x100 + 0x20] == 0xfd)) {
            if (I(state, 0xb4) != -1)
                D_L19_001B2A1C[I(state, 0xb4) * 0x100 + 0xbc] = 1;
            UPDATE_GATE();
            if (actor[0xb0] != 0xff && state[0xb3] && I(state, 0xd0))
                func_002A0430(actor[0xb0]);
            func_002A7750(actor, 2, -1);
        }
        if (!state[0xb1] && func_002A9640(actor, 0x40000, 0)) {
            if (I(state, 0xb4) != -1)
                D_L19_001B2A1C[I(state, 0xb4) * 0x100 + 0xbc] = 1;
            func_00282CC0(&temp, actor + 0xd0, actor + 0xe0);
            func_00282F20(&temp, &temp, 1.0f / 12.0f);
            func_00282CC0(&origin, (actor + 0x10), actor + 0xe0);
            func_002ABBB8(actor, &temp, &origin, 10, 3, 16, -1, 1,
                1, (actor + 0x10), 0, 0x810001, 0.0f, 0.0f, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f);
            func_002B0A68((char *)actor, 31, (int)&temp, 255, 3.0f, 6.0f, 3.0f, 6.0f);
            actor[0x31] = 0;
            *(unsigned short *)(actor + 0x34) |= 1;
            I(actor, 0x98) = 0;
            UPDATE_GATE();
            if (actor[0xb0] != 0xff && state[0xb3] && I(state, 0xd0))
                func_002A0430(actor[0xb0]);
            func_002A7750(actor, 2, -1);
        }
        actor[0xa8] = 0xff;
        break;
    case 2:
        progress = F(state, 0xa8) + 1.0f / F(state, 0xa4);
        F(state, 0xa8) = progress;
        if (progress > 1.0f)
            F(state, 0xa8) = 1.0f;
        blend = (1.0f - func_00283180(F(state, 0xa8) * 3.1415927f)) * 0.5f;
        func_00282CF0(&temp, D_L19_001B2B0C + I(state, 0xa0) * 0x80 + 0x30, state + 0x60);
        func_00282D30(&temp, &temp, blend);
        old_z = F(actor, 0x18);
        func_00282CC0((actor + 0x10), state + 0x60, &temp);
        F(state, 0xbc) = F(actor, 0x18);
        F(actor, 0x18) = old_z;
        F(actor, 0xf8) = func_002AA150(F(state, 0x78), F(D_L19_001B2B0C + I(state, 0xa0) * 0x80, 0x78), blend);
        F(actor, 0xf4) = func_002AA150(F(state, 0x74), F(D_L19_001B2B0C + I(state, 0xa0) * 0x80, 0x74), blend);
        F(actor, 0xf0) = func_002AA150(F(state, 0x70), F(D_L19_001B2B0C + I(state, 0xa0) * 0x80, 0x70), blend);
        if (F(state, 0xa8) >= 1.0f) {
            func_002A7750(actor, 3, -1);
            goto finish_transition;
        }
        break;
    case 3:
finish_transition:
        if (I(state, 0xb4) == -1 || !D_L19_001B2A1C[I(state, 0xb4) * 0x100 + 0xbc]) {
            if (state[0xb0]) {
                D_L19_001B9D00 = 0;
                func_L18_002CFF48(0);
            }
            saved_mode = D_0018C0D4;
            saved_player = D_0018C0B0;
            if (I(state, 0xd0)) {
                if (!D_0018C0D4)
                    func_002DF3F8(&D_00189EA0, &D_00189EB0);
                else {
                    D_0018C0D4 = 0;
                    D_0018C0B0 = D_0018AA38;
                    func_002DF3F8(D_0018AA38 + 0x10, D_0018AA38 + 0xf0);
                    D_0018C0B0 = saved_player;
                    D_0018C0D4 = saved_mode;
                }
            }
            func_002A7750(actor, 4, -1);
        }
        break;
    }
    height = F(state, 0xbc);
    if (actor[0x20] != 2) {
        height += func_00283198(F(state, 0xc8)) * 0.1f;
        F(state, 0xc8) = func_00283B98(F(state, 0xc8), 0.01745329611003399f);
    }
    if (state[0xb2])
        height -= 0.2f;
    F(state, 0xb8) = (F(state, 0xb8) + (height - F(actor, 0x18)) * 0.005f) * 0.98f;
    F(actor, 0x18) += F(state, 0xb8);
    if (actor[0x20]) {
        if ((!D_0018A16E && D_0018A15C == actor) || (D_0018A398 && D_0018A3A8 == actor)) {
            if (!state[0xb2])
                F(state, 0xb8) -= 1.0f / 60.0f;
            state[0xb2] = 1;
            func_00282CF0(&temp, &D_00189EA0, (actor + 0x10));
            x = func_00282DB0(&temp, actor + 0xc0);
            y = func_00282DB0(&temp, actor + 0xd0);
            rotation.q = Q(state, 0x80);
            point.q = Q(actor, 0x10);
            x *= D_L19_001B1BD0;
            func_002AA898((float *)(state + 0x80), (float *)(state + 0x90), 0, -D_L19_001B1BD0 * y,
                D_L19_001B1BE0, D_L19_001B1BE4, D_L19_001B1BE8);
            func_002AA898((float *)(state + 0x84), (float *)(state + 0x94), 0, x,
                D_L19_001B1BE0, D_L19_001B1BE4, D_L19_001B1BE8);
            func_L01_00316C48(&D_00189EA0, &temp, (actor + 0x10), &rotation, state + 0x80);
            func_00282CF0(&D_00189F20, &temp, &D_00189EA0);
            D_00189F28 += F(actor, 0x18) - point.f[2];
        } else {
            state[0xb2] = 0;
            func_002AA898((float *)(state + 0x80), (float *)(state + 0x90), 0, 0.0f,
                D_L19_001B1BEC, D_L19_001B1BF0, D_L19_001B1BF4);
            func_002AA898((float *)(state + 0x84), (float *)(state + 0x94), 0, 0.0f,
                D_L19_001B1BEC, D_L19_001B1BF0, D_L19_001B1BF4);
        }
        func_002AEF28((float *)actor, (float *)(state + 0xc0), (float *)(state + 0xc4),
            0.02007128857076168f, 0.007272206246852875f, 0.009017535485327244f);
        F(actor, 0xf0) = func_00283B98(F(state, 0x80), F(actor, 0xf0));
        F(actor, 0xf4) = func_00283B98(F(state, 0x84), F(actor, 0xf4));
    }
    func_00282CF0(&temp, (actor + 0x10), &old_position);
    func_002AD6F0(state + 0x20, &temp, &old_rotation, (actor + 0xf0));
}
