#include "include_asm.h"

extern float D_L02_001B1030 __attribute__((sda));

extern int D_L02_001AD410;

extern char D_L02_001B11D0[8] __attribute__((sda));

extern char D_L02_001B11E0[8] __attribute__((sda));

extern char D_L02_001B11F0[8] __attribute__((sda));

extern char D_L02_001B1200[8] __attribute__((sda));

extern int D_L02_001B1210 __attribute__((sda));

extern void func_00282C88(void *);

extern void func_00335438(char *, char *, int, int, int);

INCLUDE_ASM("asm/levels", func_L01_0042A6F0);

void func_L02_003F56C0(void) {
    int v0 = D_L02_001AD410;
    float *p = (float *)((char *)v0 + 0x74);
    float f;

    f = p[0] + D_L02_001B1030 * 1.6666667535901069641113281250e-02f;
    p[0] = f;
    if (f > 1.0f)
        p[0] = f - 1.0f;
}

extern int D_001A8FF0;

/* Four bytes: cc1 then emits the address as a single `la`, which gas expands to an adjacent
   lui/addiu pair (an array of unknown size is split by cc1 itself). */
extern char D_L02_001B3210[4];

extern void func_L02_002ED7B0(int, float);

extern float func_00282E48(void *, void *);

extern void func_L01_00323310(int, int);

typedef struct {
    char pad0[0x80];
    char pos[8];
    float f88;
    char pad1[0x2236];
    unsigned char b22C2;
    char pad2[0x22D];
    unsigned char b24F0;
} L02_003F5710_Hero;

extern L02_003F5710_Hero D_00189E20;

/* Watches the hero block's height (+0x88) against 420.0 and the copy of it the actor kept at
   +0x98. Crossing it downwards clears the byte at +0x24F0 and the global flag; crossing it upwards
   sets both when the flag is clear and the hero is within 150.0 of D_L02_001B3210, and clears
   both when the flag is set and the hero is farther away. While the flag is set the hero's byte
   at +0x22C2 is raised, and the first time the actor's word at +0xDC is set and handed its two
   words at +0x1C and +0x20. The height is then kept at +0x98.

   The flag is a plain extern int: the assembler decides each access at its use, a gp-relative one
   inside a delay slot and the absolute lui/lw pair elsewhere, as retail has them. */
void func_L02_003F5710(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    float d;

    if (D_00189E20.f88 < 420.0f && *(float *)(state + 0x98) >= 420.0f) {
        func_L02_002ED7B0(0, 420.0f);
        D_00189E20.b24F0 = 0;
        D_001A8FF0 = 0;
    } else if (D_00189E20.f88 > 420.0f && *(float *)(state + 0x98) <= 420.0f) {
        func_L02_002ED7B0(1, 420.0f);
        d = func_00282E48(D_00189E20.pos, D_L02_001B3210);
        if (D_001A8FF0 == 0 && d < 150.0f) {
            int on = 1;

            D_00189E20.b24F0 = on;
            D_001A8FF0 = on;
        } else if (D_001A8FF0 != 0 && d > 150.0f) {
            D_00189E20.b24F0 = 0;
            D_001A8FF0 = 0;
        }
    }
    if (D_001A8FF0 != 0) {
        D_00189E20.b22C2 = 1;
        if (*(int *)(state + 0xDC) == 0) {
            *(int *)(state + 0xDC) = 1;
            func_L01_00323310(*(int *)(state + 0x1C), *(int *)(state + 0x20));
        }
    }
    *(float *)(state + 0x98) = D_00189E20.f88;
}

void func_L02_003FD770(char *a0) {
    char buf[16];
    func_00282C88(buf);
    func_00335438(D_L02_001B11F0, D_L02_001B1200, 1, 0, 0);
    func_L01_0042A6F0(2, D_L02_001B1210);
    func_00335370(D_L02_001B11D0);
    func_003353C8(D_L02_001B11E0);
}

extern char D_L02_001BA500[];
extern int D_L02_001B32E8;
extern void func_002A7750(char *, int, int);

/* Raises the flag at 0x1B32E8. When the point at D_L02_001BA500 is within 0.0001 of the one at
   D_L02_001B11D0 the actor changes state by its kind (4 to 7, 5 to 6) and the two widgets are
   updated; otherwise func_L02_003FD770 runs unless the object's state half-word is 5. */
void func_L02_003FD7C8(char *a0) {
    D_L02_001B32E8 = 1;
    if (func_00282E48(D_L02_001BA500, D_L02_001B11D0) < 0.0001f) {
        if (*(unsigned char *)(a0 + 0x20) == 4)
            func_002A7750(a0, 7, -1);
        else if (*(unsigned char *)(a0 + 0x20) == 5)
            func_002A7750(a0, 6, -1);
        func_L01_0042A6F0(1, 0);
        func_00335370(D_L02_001B11D0);
        func_003353C8(D_L02_001B11E0);
    } else if (*(short *)(*(char **)(D_L02_001BA500 + 0x50) + 0x86) != 5) {
        func_L02_003FD770(a0);
    }
}

extern char *D_L02_001B1190[] __attribute__((sda));

/* Whether the pair of table entries the object names still agree with its own four words. */
INCLUDE_ASM("asm/levels", func_L02_003FCBF0);

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef float f32;

extern char *D_L02_001B1190[2] __attribute__((sda));
extern unsigned char *D_L02_001B359C[3] __attribute__((sda));
extern s32 D_L02_001B35B8[] __attribute__((sda));
extern u32 D_L02_001FC060[];
extern f32 D_L02_001B1258 __attribute__((sda));
extern f32 D_L02_001B125C __attribute__((sda));
extern s32 func_00312B58(char *);
extern s32 func_L02_00416800(char *);
extern s32 func_002A77E0(s32);
extern void func_L02_00416720(char *, char *, f32, f32);

#define GROUP(off) (*(s32 *)(state + (off)))
/* Leaves the function when the group is 0xFF or empty; the braces it opens close in END_IDS. */
#define FOR_EACH_ID(p, off) \
    if (GROUP(off) == 0xFF) \
        return; \
    { u16 *q = (u16 *)D_L02_001FC060[GROUP(off)]; \
    if (q == 0) \
        return; \
    for (p = q; (GROUP(off) & 0xFF) != 0xFF && GROUP(off) <= D_L02_001B35B8[0] && p != 0 && \
         ((p != 0 && (s16)p[-1] >= 0) || p == (u16 *)D_L02_001FC060[GROUP(off)]); \
         p++)
#define END_IDS }
/* One half: collect the entities of group OFF for which func_00312B58 holds (counting the
   others in m), then, up to 1000 passes over group 0xCC while m is below the record's limit,
   hand one collected entity at a time to func_L02_00416720 with an entity of 0xCC. */
#define HALF(limit, off) \
    { \
        s32 n, m, i, k; \
        if (*(s16 *)(rec + (limit)) != 0) { \
            m = 0; \
            n = 0; \
            for (k = 15; k >= 0; k--) \
                buf[k] = 0; \
            FOR_EACH_ID(p, off) { \
                e = (char *)D_L02_001B359C[0] + ((*p & 0x7FFF) << 8); \
                if (e == 0) \
                    break; \
                if (func_00312B58(e) == 0) { \
                    m++; \
                } else { \
                    buf[n] = e; \
                    n++; \
                } \
            } END_IDS \
            if (n != 0) { \
                for (i = 0; i < 1000 && m < *(s16 *)(rec + (limit)); i++) { \
                    FOR_EACH_ID(p, 0xCC) { \
                        e = (char *)D_L02_001B359C[0] + ((*p & 0x7FFF) << 8); \
                        if (e == 0) \
                            break; \
                        if (n <= 0) \
                            break; \
                        if (func_L02_00416800(e) != 0 && func_002A77E0(6) == 0) { \
                            n--; \
                            func_L02_00416720(e, buf[n], D_L02_001B1258 * 0.016666668f, \
                                              D_L02_001B125C * 2.908882452175021e-4f); \
                            m++; \
                            break; \
                        } \
                    } END_IDS \
                } \
            } \
        } \
    }

void func_L02_003FD228(char *a0) {
    char *state = *(char **)(a0 + 0x68);
    char *rec = *(char **)(D_L02_001B1190[*(s16 *)(state + 0x120)] + 4)
                + *(s16 *)(state + 0x122) * 0x14;
    char *buf[16];
    u16 *p;
    char *e;

    HALF(0xC, 0xC8)
    HALF(0xE, 0xC4)
}

extern unsigned char D_001395B8[0x100];

/* D_001A7A0C, written as the second word of an 8-byte object: cc1 then counts the store as two
   instructions and keeps it out of func_L02_003FCDF8's delay slot, and the assembler gives the
   absolute `lui $at ; sw`. */
extern int D_001A7A08[2];

extern int D_001A79F8;

extern int func_L02_003F9B70(int);

extern int func_L02_00400650(char *, int);

extern void func_00288308(int);

extern void func_002AD860(int);

extern int func_L02_003FCF08(int);

extern int func_L02_003FCDF8(int);

extern void func_L00_0030C7F8(int);

extern void func_0029B3E0(int, int);

/* With a1 == 0 and no count yet for func_L02_003F9B70(0), plays the hero's scene 7 with its
   word at +0x22C8 kept; otherwise picks the scene from a1 (6, 0xB or a random one), adds the
   two scores and starts func_L00_0030C7F8(0x168). Then counts the entry. The unit is built with
   -frac2-gcse-unsplit-edges and -frac2-keep-block-order (config/cflags.txt): the high half of
   D_001395B8 is computed in the entry block, and the switch keeps its `b default` with the
   default body last, as in retail. `+= 1` keeps the counter's address out of the call. */
void func_L02_003FCCA0(char *a0, int a1) {
    char *state = *(char **)(a0 + 0x68);
    int saved;
    char *hero;
    int v;

    if (a1 == 0 && D_001395B8[func_L02_003F9B70(0)] == 0) {
        hero = (char *)&D_00189E20;
        saved = *(int *)(hero + 0x22C8);
        func_L02_00400650(a0, 7);
        func_00288308(0x26);
        func_002AD860(0x26);
        *(int *)(hero + 0x22C8) = saved;
    } else {
        switch (a1) {
        case 6:
            func_L02_00400650(a0, 8);
            break;
        case 0xB:
            func_L02_00400650(a0, 9);
            break;
        default:
            func_L02_00400650(a0, func_002A77E0(5) + 2);
            break;
        }
        D_001A7A08[1] = D_001A7A08[1] + func_L02_003FCF08(a1);
        v = func_L02_003FCDF8(a1);
        *(int *)(state + 0x110) = v;
        D_001A79F8 = D_001A79F8 + v;
        func_L00_0030C7F8(0x168);
    }
    D_001395B8[func_L02_003F9B70(a1)] += 1;
    func_0029B3E0(0, -1);
}
