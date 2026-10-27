/* func_L00_003AA708 (27 levels, 3,196 bytes): homing projectile update (acquire a target from a
 * 32-entry candidate list, four flight states, wall/bounds checks, explode on contact).
 * Opus draft (big38), 2026-10-26; not linked.
 * Profile: -O2 -G0 -ffunction-sections -g as its own unit. 791/799 words emitted, ~50 opcode
 * differences left (scorer); first difference near the search call.
 * Found: the candidate list (char *[32]) with its count/found ints sits in a block nested inside the
 * if-body so the later vectors share its frame slots (retail frame 0x100, count at sp+0x90);
 * func_002AF580 takes (pos, state, &count, 2 floats, list, 0x20, 0, 3 floats, 0, 0);
 * func_002AA3A8 here is (float *, float, float *, float, float, float); case 3's target test must
 * be separate statements (an && chain folds into a range test).
 * Blocker: in cases 3 and 1 retail pads div.s with two nops right after a jal whose delay slot is
 * filled (noreorder). Our GNU as model suppresses the SDK 3.01 floor after a noreorder slot
 * (pad_div_erratum_nops.py: "SDK 3.01 pads ordinary noreorder cases too"), so those 4 words
 * cannot come out until the assembler model pads that case.
 * Left besides that: moby+0xC0/0xD0/0xE0 in fp/s1/s6 (retail compute-then-copy into fp), which
 * pushes hitPlayer to the stack (sp+0x98) in retail; one extra callee-saved float (f22) in ours;
 * order of the search-call setup and the found=0 store.
 */
#include "common.h"
typedef float Vector[4] __attribute__((aligned(16)));
typedef struct {
    u8 pad0[0x18];
    char *moby;
    s32 count;
    f32 pos[4];
    f32 normal[4];
} CollResult;
typedef struct { u8 pad[0x74]; u8 active; u8 pad75[0x13]; char *owner; u8 pad8C[0x70 - 0x8C + 0x70]; } SoundSlot;

extern char D_00189E20[];
extern CollResult D_L00_001BF200 __attribute__((aligned(16)));
extern u8 D_00188660[];

extern void func_00300190(void *, void *);
extern void func_00282A88(void *, int);
extern int func_00282948(void *);
extern int func_00282978(void *);
extern char *func_002AF580(void *, void *, int *, float, float, void *, int, int, float, float, float, int, int);
extern char *func_L00_0037DEF8(char *, char **, int, int *, int);
extern void func_L00_0037DD18(char *, char *, int);
extern void func_002A7470(void *, int, int, int);
extern void func_002AFFD8(void *, void *, int);
extern void func_002FEE70(int, void *, int);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282F20(void *, void *, float);
extern float func_00282DF0(void *);
extern float func_00282DB0(void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern float func_00282E48(void *, void *);
extern float func_00282C48(float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern void func_002AA3A8(float *, float, float *, float, float, float);
extern int func_002E59B0(void *, int);
extern int func_002E5CF8(int, int, void *);
extern void func_002E59F8(int);
extern void func_L00_003AB388(char *, char *, void *);
extern void func_L00_003AB618(void *, char *, char *, void *, int, float, float, float);
extern void func_L00_003AB6F0(char *, void *);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern float func_002A7C00(float, float, float);
extern float *func_002AB1F0(char *);
extern float func_00283B98(float, float);
extern float func_00283198(float);
extern void func_002AEF28(char *, char *, char *, float, float, float);
extern void func_002AB668(void *, void *, float);
extern void func_002ACDE8(void *, void *, void *);
extern void func_002A9288(char *, float);
extern void func_L00_0031BDC0(void *, void *, void *, void *);
extern int func_00277258(void *, int, void *, float);
extern void func_002FEE50(int);
extern void func_0029F338(void *);

#define HERO_PLAYER (*(char **)(D_00189E20 + 0x2290))
#define F(p, o) (*(float *)((char *)(p) + (o)))
#define I(p, o) (*(int *)((char *)(p) + (o)))
#define H(p, o) (*(short *)((char *)(p) + (o)))
#define P(p, o) (*(char **)((char *)(p) + (o)))
#define B(p, o) (*(u8 *)((char *)(p) + (o)))

void func_L00_003AA708(char *moby)
{
    Vector saved;
    char *state = P(moby, 0x68);

    func_00300190(moby + 0x10, moby + 0x10);
    qcopy(saved, moby + 0x10);
    {
        if (!P(state, 0x14)) {
            char *list[32];
            int count;
            int found;
            count = 0;
            func_00282A88(list, 0x80);
            if (P(state, 0x74)) {
                if (func_00282948(state + 0x78)) {
                    P(state, 0x14) = P(state, 0x74);
                    P(state, 0x74) = 0;
                }
            } else {
                char *target;
                func_002AF580(moby + 0x10, state, &count, 3.14159298f, 3.14159298f, list, 0x20, 0, 8.0f, 0.0f, 0.0f, 0, 0);
                found = 0;
                target = func_L00_0037DEF8(HERO_PLAYER, list, count, &found, -1);
                P(state, 0x14) = target;
                if (target && found)
                    func_L00_0037DD18(HERO_PLAYER, target, 0x14);
            }
            if (P(state, 0x14)) {
                B(moby, 0x20) = 1;
                func_002A7470(moby, 0, 0, 10);
                qcopy(state + 0x40, state);
                H(state, 0x54) = 20;
            }
        }
    }
    {
        Vector dir;
        Vector a, b, c, d, e;
        char *pos = moby + 0x10;
        int moved, hitPlayer;

        func_002AFFD8(pos, dir, 1);
        func_002FEE70(I(state, 0x70), state, 0);
        switch (B(moby, 0x20)) {
        case 0: {
            float step;
            func_00282CC0(pos, pos, state);
            qcopy(a, pos);
            moved = 0;
            func_00282D30(b, dir, 0.5f);
            func_00282CF0(c, pos, b);
            if (func_002761F8(a, c, 0x12, HERO_PLAYER, 0)) {
                func_00282CF0(d, pos, D_L00_001BF200.pos);
                step = 0.5f - func_00282DF0(d);
                if (step > 0.06666667f)
                    step = 0.06666667f;
                if (F(state, 0x7C) < step) {
                    moved = 1;
                    func_00282D30(b, b, step + step);
                    func_00282CC0(pos, pos, b);
                    F(state, 0x7C) = step;
                }
            }
            if (!moved && F(state, 0x7C) != 0.0f) {
                func_00282D30(d, dir, F(state, 0x7C));
                func_00282CC0(pos, pos, d);
                func_002AA3A8((float *)(state + 0x7C), 0.0f, (float *)(state + 0x58), 0.02f, 0.2f, 0.0f);
                if (F(state, 0x7C) < 0.001f)
                    F(state, 0x7C) = 0.0f;
            }
            if (!func_002E59B0(moby, I(state, 0x5C)))
                I(state, 0x5C) = func_002E5CF8(0, 4, moby);
            if (func_00282978(state + 0x18)) {
                D_L00_001BF200.moby = 0;
                func_L00_003AB388(moby, state, pos);
                func_002FEE50(I(state, 0x70));
                func_0029F338(moby);
                return;
            }
            break;
        }
        case 3: {
            char *target;
            if (func_00282978(state + 0x54)) {
                D_L00_001BF200.moby = 0;
                func_L00_003AB388(moby, state, pos);
                func_002FEE50(I(state, 0x70));
                func_0029F338(moby);
                return;
            }
            {
                float now = func_00283CE0(H(state, 0x54));
                float total = func_00283CE0(10);
                F(state, 0x50) = func_002A7C00(0.5f, 1.5f, now / total);
            }
            target = P(state, 0x14);
            if (target) {
                u8 kind = B(target, 0x20);
                if (kind == 0xFE)
                    goto drift;
                if (kind == 0xFD)
                    goto drift;
                if (!I(target, 0x98))
                    goto drift;
            }
            func_L00_003AB618(pos, state, target, state + 0x30, 1, 0.02f, 0.3f, 0.0f);
        drift:
            func_00282CC0(pos, pos, state);
            break;
        }
        case 1:
            if (func_00282978(state + 0x54)) {
                B(moby, 0x20) = 2;
                H(state, 0x56) = 10;
            }
            func_L00_003AB618(pos, state, P(state, 0x14), state + 0x30, 0, 0.04f, 0.3f, 0.0f);
            func_00282D30(state + 0x40, state + 0x40, 0.85f);
            func_00282CC0(pos, pos, state + 0x40);
            {
                float now = func_00283CE0(H(state, 0x54));
                float total = func_00283CE0(20);
                F(state, 0x50) = func_002A7C00(1.5f, 0.5f, now / total);
            }
            if (P(state, 0x14)) {
                func_00282CF0(a, pos, P(state, 0x14) + 0x10);
                func_00282F20(a, a, 0.083333336f);
                func_00282CC0(pos, pos, a);
            }
            break;
        case 2: {
            float half = func_00283CE0(10) * 0.5f;
            float t = func_00283CE0(H(state, 0x56)) - half;
            float scale;
            t /= half;
            if (t < 0.0f)
                t = 0.0f;
            scale = t * 0.083333336f;
            if (P(state, 0x14)) {
                func_00282CF0(a, pos, P(state, 0x14) + 0x10);
                func_00282F20(a, a, scale);
                func_00282CC0(pos, pos, a);
            }
            if (func_00282978(state + 0x56)) {
                B(moby, 0x20) = 3;
                func_00282F20(state, state, 1.0f);
                if (P(state, 0x14)) {
                    func_002AFFD8(pos, a, 1);
                    func_00282D30(b, a, func_002AB1F0(P(state, 0x14))[4]);
                    func_00282CC0(c, P(state, 0x14) + 0x10, b);
                    H(state, 0x54) = func_00283CF0(func_00282E48(c, pos) + 5.0f);
                } else {
                    H(state, 0x54) = 10;
                }
                if (I(state, 0x5C) != -1) {
                    u8 *slot = D_00188660 + I(state, 0x5C) * 0x70;
                    if (*(char **)(slot + 0x88) == moby && slot[0x74])
                        func_002E59F8(I(state, 0x5C));
                }
                I(state, 0x5C) = -1;
                func_002E5CF8(1, 0, moby);
            }
            break;
        }
        }
        if (F(moby, 0x10) < 2.0f || F(moby, 0x10) > 1021.0f || F(moby, 0x14) < 2.0f || F(moby, 0x14) > 1021.0f
            || F(moby, 0x18) < 2.0f || F(moby, 0x18) > 1021.0f) {
            func_002FEE50(I(state, 0x70));
            func_0029F338(moby);
            return;
        }
        qcopy(a, pos);
        func_00282D30(b, dir, -2.0f);
        func_00282CC0(b, pos, b);
        if (func_002761F8(a, b, 0x12, moby, 0)) {
            float length, limit;
            func_00282CF0(c, a, D_L00_001BF200.pos);
            length = func_00282DF0(c);
            if (length < 0.0001f) {
                D_L00_001BF200.moby = 0;
                func_L00_003AB388(moby, state, pos);
                func_002FEE50(I(state, 0x70));
                func_0029F338(moby);
                return;
            }
            limit = 0.025000002f;
            func_00282D30(c, c, 1.0f / length);
            func_00282CC0(d, D_L00_001BF200.pos, c);
            func_00282CF0(e, d, pos);
            if (func_00282DB0(e, dir) > 0.0f) {
                float distance = func_00282DF0(e);
                if (distance > limit)
                    func_00282D30(e, e, limit / distance);
                func_00282CC0(pos, pos, e);
            }
        }
        func_00282F20(moby + 0xC0, state, 1.0f);
        func_00282DD8(moby + 0xD0, moby + 0xC0, dir);
        func_00282F20(moby + 0xD0, moby + 0xD0, 1.0f);
        func_00282DD8(moby + 0xE0, moby + 0xD0, moby + 0xC0);
        F(state, 0x20) = func_00283B98(F(state, 0x20), 0.06f);
        func_00282D30(c, dir, F(state, 0x24));
        func_00282CF0(pos, pos, c);
        F(state, 0x24) = func_00283198(F(state, 0x20)) * 0.15f;
        func_00282D30(c, dir, F(state, 0x24));
        func_00282CC0(pos, pos, c);
        func_002AEF28(moby, state + 0x28, state + 0x2C, 0.5f, 0.1f, 0.05f);
        if (func_00282C48(F(moby, 0xF0)) > 0.00001f) {
            func_002AB668(c, moby + 0xC0, F(moby, 0xF0));
            func_002ACDE8(moby + 0xD0, moby + 0xD0, c);
            func_002ACDE8(moby + 0xE0, moby + 0xE0, c);
        }
        if (func_00282C48(F(moby, 0xF4)) > 0.00001f) {
            func_002AB668(c, moby + 0xD0, F(moby, 0xF4));
            func_002ACDE8(moby + 0xC0, moby + 0xC0, c);
            func_002ACDE8(moby + 0xE0, moby + 0xE0, c);
        }
        hitPlayer = 0;
        moved = 0;
        func_002A9288(moby, 0.2f);
        if (func_002761F8(saved, pos, 0x10, HERO_PLAYER, 0)) {
            hitPlayer = 1;
        } else if (B(moby, 0x20) == 3) {
            func_00282D30(c, dir, func_002AB1F0(P(state, 0x14))[4]);
            func_00282CC0(d, P(state, 0x14) + 0x10, c);
            func_L00_0031BDC0(e, saved, pos, d);
            if (func_00282E48(e, d) <= 0.5f) {
                moved = 1;
                qcopy(pos, e);
                D_L00_001BF200.moby = P(state, 0x14);
            }
        } else if (func_00277258(pos, 0x10, HERO_PLAYER, 0.2f)) {
            moved = 1;
            qcopy(pos, D_L00_001BF200.normal);
        }
        if (moved || hitPlayer) {
            func_L00_003AB388(moby, state, pos);
            func_002FEE50(I(state, 0x70));
            func_0029F338(moby);
            return;
        }
        if (F(moby, 0x10) < 2.0f || F(moby, 0x10) > 1021.0f || F(moby, 0x14) < 2.0f || F(moby, 0x14) > 1021.0f
            || F(moby, 0x18) < 2.0f || F(moby, 0x18) > 1021.0f) {
            func_002FEE50(I(state, 0x70));
            func_0029F338(moby);
            return;
        }
        func_00282D30(c, dir, -0.25f);
        func_00282CC0(c, c, pos);
        func_L00_003AB6F0(moby, c);
    }
}
