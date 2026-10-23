#include "include_asm.h"
#include "common.h"

extern char *D_L06_001B281C __attribute__((sda));

extern u8 *D_L06_001FB3A0[];

void func_L06_0041F798(u8 *arg0)
{
    char *a2;
    u8 *p;
    u8 *list;

    if (arg0[0x21] == 0xFF)
        return;
    list = D_L06_001FB3A0[arg0[0x21]];
    if (list == 0)
        return;
    p = list;
    a2 = D_L06_001B281C;
    for (;;) {
        char *q = a2 + ((*(unsigned short *)p & 0x7FFF) << 8);

        if (*(signed char *)(q + 0x20) >= 0) {
            if (*(short *)(q + 0xAA) == 0xBBA) {
                *(int *)(*(char **)(q + 0x68) + 0x258) = 1;
            }
        }
        if (*(short *)p < 0)
            break;
        p += 2;
    }
}

void func_L06_00443E88(u8 *arg0)
{
    char *a2;
    u8 *p;
    u8 *list;

    if (arg0[0x21] == 0xFF)
        return;
    list = D_L06_001FB3A0[arg0[0x21]];
    if (list == 0)
        return;
    p = list;
    a2 = D_L06_001B281C;
    for (;;) {
        char *q = a2 + ((*(unsigned short *)p & 0x7FFF) << 8);

        if (*(signed char *)(q + 0x20) >= 0) {
            if (*(short *)(q + 0xAA) == 0xDB0) {
                *(short *)(*(int *)(q + 0x68) + 0x316) = 1;
            }
        }
        if (*(signed char *)(q + 0x20) >= 0) {
            if (*(short *)(q + 0xAA) == 0xBBA) {
                *(int *)(*(char **)(q + 0x68) + 0x258) = 1;
            }
        }
        if (*(short *)p < 0)
            break;
        p += 2;
    }
}

/* The id-list walks below read D_L06_001B281C as a bare symbol (a second name for the 4-byte
   `sda` pointer above, declared as a 12-byte array so the assembler keeps its loads absolute),
   while D_L06_001B2838 is a plain int: its `.extern` comes last in the file, which leaves a load
   in a branch delay slot on $gp and every other load on `lui`/`lw`. */
extern unsigned char *D_L06_001B281C_base[3] __asm__("D_L06_001B281C") __attribute__((sda));
extern int D_L06_001B2838;
extern int D_L06_001B2348;

/* Overlays for an owner (L06Obj) and the state block it points to (L06Cfg); only the fields the
   next two functions touch are named. */
typedef struct {
    char pad0[0x220];
    float vec[4];
    char pad1[0x324 - 0x230];
    float scale;
    float angle;
    float blend;
    int stamp;
} L06Cfg;

typedef struct {
    char pad0[0x20];
    unsigned char kind;
    unsigned char group;
    char pad1[0x31 - 0x22];
    unsigned char live;
    char pad2[0x68 - 0x32];
    L06Cfg *cfg;
    char pad3[0x78 - 0x6C];
    int tint;
    char pad4[0xAA - 0x7C];
    short cls;
} L06Obj;

typedef struct {
    int a;
    int b;
} L06ColorPair;

extern void func_L06_00444300(L06Obj *);
extern L06ColorPair D_L06_001B1098[];
extern float func_00283B98(float, float);
extern float func_00283198(float);
extern int func_00283D38(int, int, float);
extern void func_0029FC20(void *moby, int joint, void *out);
extern void func_L00_002E6CF0(void *, void *);

/* Advances the owner's pulse (the angle, then the blend it gives), tints the owner with the
   colour pair and, when its stamp is not the current one, refreshes every live class-0xDB0
   entity of its group (joint 0 position into +0x220, then the stamp) and queues
   func_L06_00444300 for the owner. */
void func_L06_00444168(L06Obj *self)
{
    L06Cfg *state = self->cfg;
    L06ColorPair colors = D_L06_001B1098[0];
    unsigned short *p;
    L06Obj *e;
    L06Cfg *s0;
    float angle;
    float blend;

    angle = func_00283B98(state->angle, 0.20943954f);
    state->angle = angle;
    blend = func_00283198(angle) * 0.5f + 0.5f;
    state->blend = blend;
    self->tint = func_00283D38(colors.a, colors.b, blend);
    if (state->stamp != D_L06_001B2348) {
        for (p = (unsigned short *)D_L06_001FB3A0[self->group];
             self->group != 0xFF && self->group <= D_L06_001B2838 && p != 0 &&
             ((p != 0 && (short)p[-1] >= 0) || p == (unsigned short *)D_L06_001FB3A0[self->group]);
             p++) {
            e = (L06Obj *)(D_L06_001B281C_base[0] + ((*p & 0x7FFF) << 8));
            if (e == 0)
                break;
            if (e->live != 0) {
                if (e->cls == 0xDB0) {
                    /* two tests, as retail has them: `!= 0xFE && != 0xFD` is folded into one */
                    if (e->kind != 0xFE) {
                        if (e->kind != 0xFD) {
                            s0 = e->cfg;
                            func_0029FC20(e, 0, &s0->vec);
                            s0->stamp = D_L06_001B2348;
                        }
                    }
                }
            }
        }
        func_L00_002E6CF0((void *)func_L06_00444300, self);
    }
}

/* D_L06_001B10A0 is only used for its address, taken through $gp. D_L06_001B10B0 is one 8-byte
   object: its first word is loaded in a branch delay slot (so on $gp), its second as a bare
   symbol, which is how retail loads the two colours. */
extern int D_L06_001B10A0 __attribute__((sda));
extern int D_L06_001B10B0[2];
extern void func_00282D30(void *out, void *in, float scale);
extern void func_002830C0(void *a, void *b, void *c);
extern void func_L00_00325AE8(void *buf, int color, float f12, float f13);

/* For every live class-0xDB0 entity in the owner's group, builds the marker's vector from the
   entity's size and stored position and hands it to func_L00_00325AE8 with the colour pair
   blended by the entity's pulse. */
void func_L06_00444300(L06Obj *self)
{
    unsigned short *p;
    unsigned short *q;
    L06Obj *e;
    L06Cfg *s0;
    float buf[4];

    if (self->group == 0xFF)
        return;
    q = (unsigned short *)D_L06_001FB3A0[self->group];
    if (q == 0)
        return;
    for (p = q; self->group != 0xFF && self->group <= D_L06_001B2838 && p != 0 &&
                ((p != 0 && (short)p[-1] >= 0) || p == (unsigned short *)D_L06_001FB3A0[self->group]);
         p++) {
        e = (L06Obj *)(D_L06_001B281C_base[0] + ((*p & 0x7FFF) << 8));
        if (e == 0)
            break;
        if (e->live != 0) {
            if (e->cls == 0xDB0) {
                if (e->kind != 0xFE) {
                    if (e->kind != 0xFD) {
                        s0 = e->cfg;
                        func_00282D30(buf, &D_L06_001B10A0, s0->scale);
                        func_002830C0(buf, buf, &s0->vec);
                        func_L00_00325AE8(buf,
                                          func_00283D38(D_L06_001B10B0[0], D_L06_001B10B0[1],
                                                        s0->blend),
                                          s0->scale * 0.2f, 0.08f);
                    }
                }
            }
        }
    }
}

/* The level's three turn angles, in degrees (37, 41 and 70); the step below turns them into
   radians per frame. The first one is read through $gp, the other two absolutely. */
extern float D_L06_001B18D0 __attribute__((sda));
extern float D_L06_001B18D4;
extern float D_L06_001B18D8;

extern float func_32E5D0(float, float);
extern void func_32DE28(void *, void *);
extern void func_32DA88(void *, void *, void *);
extern void func_32D650(char *, char *, float);
extern void func_32D5C8(char *, char *, char *);
extern void func_L03_0042B868(u8 *, void *, void *);

/* Turns the owner's three angles by the level's step, then walks the owner's eight records:
   each gets a fresh object, scaled and blended against the owner's own axes. `axes` is the
   scratch area func_32DE28 fills; its first vector is the one the objects are given. */
void func_L06_004577B0(char *a0)
{
    float axes[12];
    float v0[4];
    float v1[4];
    char *s0 = *(char **)(a0 + 0x68);
    char *s3 = s0 + 0xA0;
    char *s2 = s0 + 0x80;
    char *s4 = a0 + 0x10;
    float step = 0.000290888245f;
    float one = 1.0f;
    float two = 2.0f;
    int i;

    *(float *)(s0 + 0x120) = func_32E5D0(*(float *)(s0 + 0x120), D_L06_001B18D0 * step);
    *(float *)(s0 + 0x124) = func_32E5D0(*(float *)(s0 + 0x124), D_L06_001B18D4 * step);
    *(float *)(s0 + 0x128) = func_32E5D0(*(float *)(s0 + 0x128), D_L06_001B18D8 * step);
    func_32DE28(axes, s0 + 0x120);
    for (i = 7; i >= 0; i--) {
        func_32DA88(v0, s3, axes);
        s3 += 0x10;
        func_32D650((char *)v0, (char *)v0, 3.0f);
        func_32D650((char *)v1, (char *)v0, 3.3333335f);
        func_32D5C8((char *)v0, (char *)v0, s4);
        func_32D5C8((char *)v1, (char *)v1, s4);
        v0[3] = one;
        v1[3] = two;
        func_L03_0042B868(*(u8 **)s2, v0, v1);
        s2 += 4;
    }
}
