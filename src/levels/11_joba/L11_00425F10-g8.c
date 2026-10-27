#include "common.h"

extern void *D_L11_001FC420[];

/* Reached with `lw $a2,0x45AC($gp)`, so this unit is built -G8. */
extern u8 *D_L11_001B359C;

/* Flags every record of the id list whose class halfword is 0xD07. */
void func_L11_00431DB0(u8 *arg0) {
    void *list;
    u16 *p;
    u8 *base;

    if (arg0[0x21] == 0xFF)
        return;
    list = D_L11_001FC420[arg0[0x21]];
    if (list == 0)
        return;
    p = list;
    base = D_L11_001B359C;
    do {
        u8 *e = base + ((*p & 0x7FFF) << 8);

        if (*(s8 *)(e + 0x20) >= 0 && *(s16 *)(e + 0xAA) == 0xD07)
            *(s16 *)(*(u8 **)(e + 0x68) + 0x276) = 1;
    } while (*(s16 *)p++ >= 0);
}

typedef int TI128 __attribute__((mode(TI)));

/* The flat quad the effect submits: four positions, four colours, four uv
   pairs and the four GS words (primitive, texture, mode, registers). */
typedef struct {
    TI128 position[4];
    u32 color[4];
    float uv[4][2];
    unsigned long primitive, texture, mode, registers;
} EffectQuad;

typedef struct {
    TI128 saved;
    EffectQuad quad;
    float a[4];
    float b[4];
    float c[4];
    TI128 corner;
} EffectQuadFrame;

extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern unsigned long func_0027C878(int);
extern void func_00280B90(void *, void *, int);
extern char D_L11_001BA8C0[];
/* The two uv columns: macro-addressed tables, so each base is one la. */
extern float D_L11_001B1138[] __attribute__((sda));
extern float D_L11_001B113C[] __attribute__((sda));

/* The quad between the two end points at +0x230 and +0x240: each side
   is pulled a tenth of the way toward the level's anchor, then the four
   corners are crossed out from the span and submitted. */
void func_L11_00431EE8(char *obj, void *q)
{
    EffectQuadFrame f;
    char *st;
    int i;

    f.saved = *(TI128 *)q;
    st = *(char **)(obj + 0x68);
    func_00282CF0(f.c, st + 0x230, st + 0x240);
    func_00282CF0(f.a, st + 0x230, D_L11_001BA8C0);
    func_00282CF0(f.b, st + 0x240, D_L11_001BA8C0);
    func_00282DD8(f.a, f.a, f.c);
    func_00282F20(f.a, f.a, 0.1f);
    func_00282DD8(f.b, f.b, f.c);
    func_00282F20(f.b, f.b, 0.1f);
    f.quad.texture = func_0027C878(7);
    f.quad.mode = 0x0000ff9000000260UL;
    f.quad.registers = 0x7000000048UL;
    f.quad.primitive = 0;
    f.quad.color[0] = f.quad.color[1] = f.quad.color[2] = f.quad.color[3] = 0x2F0000FF;
    for (i = 0; i < 4; i++) {
        f.quad.uv[i][0] = D_L11_001B1138[i * 2];
        f.quad.uv[i][1] = D_L11_001B113C[i * 2];
    }
    func_00282CF0(&f.corner, st + 0x230, f.a);
    f.quad.position[0] = f.corner;
    func_00282CC0(&f.corner, st + 0x230, f.a);
    f.quad.position[1] = f.corner;
    func_00282CF0(&f.corner, st + 0x240, f.b);
    f.quad.position[2] = f.corner;
    func_00282CC0(&f.corner, st + 0x240, f.b);
    f.quad.position[3] = f.corner;
    func_00280B90(&f.quad, 0, 0);
}

extern char D_L11_001BA8C0[];
/* The two uv columns: macro-addressed tables, so each base is one la. */
extern float D_L11_001B1138[] __attribute__((sda));
extern float D_L11_001B113C[] __attribute__((sda));

/* The quad between the two end points at +0x230 and +0x240: each side
   is pulled a twentieth of the way toward the level's anchor, then the four
   corners are crossed out from the span and submitted (then drawn again as the overlay). */
void func_L11_004320F8(char *obj, void *q)
{
    EffectQuadFrame f;
    char *st;
    int i;

    f.saved = *(TI128 *)q;
    st = *(char **)(obj + 0x68);
    func_00282CF0(f.c, st + 0x230, st + 0x240);
    func_00282CF0(f.a, st + 0x230, D_L11_001BA8C0);
    func_00282CF0(f.b, st + 0x240, D_L11_001BA8C0);
    func_00282DD8(f.a, f.a, f.c);
    func_00282F20(f.a, f.a, 0.05f);
    func_00282DD8(f.b, f.b, f.c);
    func_00282F20(f.b, f.b, 0.05f);
    f.quad.texture = func_0027C878(0x13);
    f.quad.mode = 0x0000ff9000000260UL;
    f.quad.registers = 0x8000000048UL;
    f.quad.primitive = 0;
    f.quad.color[0] = f.quad.color[1] = f.quad.color[2] = f.quad.color[3] = 0x2FFFFFFF;
    for (i = 0; i < 4; i++) {
        f.quad.uv[i][0] = D_L11_001B1138[i * 2];
        f.quad.uv[i][1] = D_L11_001B113C[i * 2];
    }
    func_00282CF0(&f.corner, st + 0x230, f.a);
    f.quad.position[0] = f.corner;
    func_00282CC0(&f.corner, st + 0x230, f.a);
    f.quad.position[1] = f.corner;
    func_00282CF0(&f.corner, st + 0x240, f.b);
    f.quad.position[2] = f.corner;
    func_00282CC0(&f.corner, st + 0x240, f.b);
    f.quad.position[3] = f.corner;
    func_00280B90(&f.quad, 0, 0);
    f.quad.texture = func_0027C878(0x10);
    f.quad.mode = 0x0000ff9000000260UL;
    f.quad.registers = 0x8000000048UL;
    f.quad.primitive = 0;
    func_00280B90(&f.quad, 0, 0);
}
