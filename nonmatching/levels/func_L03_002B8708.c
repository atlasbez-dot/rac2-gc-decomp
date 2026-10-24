/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-keep-block-order.
 * Reported final C / retail: 988 / 1012 bytes; size equality is not a match.
 * us: 0/1 placements; 988/1012 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: Guard tail merging, quad motion, interaction state blocks.
 * Reopening condition: New measured source-shape/scheduler or ABI remedy addressing the residual; do not repeat tied forms.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained interaction reconstruction: 988 compiled/1012 retail bytes under
 * -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-keep-block-order; 0/1 USA placements. Plain qcopy is984 bytes;
 * -fno-gcse gives1000 bytes with a smaller frame. Typed resident field
 * views restore the retail saved-register frame; byte-offset macros fold
 * base offsets and give992 bytes/0x40 frame. Unsigned interaction byte at
 * +0x68e was corrected to the retail short store. Remaining differences
 * include initial guard tail merging, quad-copy motion, and state blocks.
 * Reopen with a matching interaction/sentinel state machine source shape.
 */
#include "include_asm.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct {
    unsigned char pad0[0x10]; Quad delta; char *object;
    unsigned int flags; unsigned char kind; unsigned char pad29[3];
    float time; unsigned int status; unsigned char pad34[4];
    char *owner; unsigned char pad3c[4];
} Interaction;
extern Interaction D_L03_001C4040[];
extern unsigned char D_00189E20[];
extern int D_L03_001A8F00;
extern unsigned char D_001A7A32 __attribute__((sda));
extern unsigned char D_001A7A33 __attribute__((sda));
typedef struct {
    unsigned char pad_0[0x1dc];
    short lock;
    unsigned char pad_1de[0x3e];
    short timer;
    unsigned char pad_21e[0x470];
    short interaction;
    unsigned char pad_690[0x34];
    Interaction * contact;
    unsigned char pad_6c8[0xdcf];
    unsigned char pressed;
    unsigned char pad_1498[0x68];
    int specialMode;
    unsigned char pad_1504[0xd8c];
    char * object;
    int mode;
    unsigned char pad_2298[0x4];
    int activity;
    unsigned char pad_22a0[0x14];
    unsigned char state;
    unsigned char pad_22b5[0x1e7];
    char * other;
    unsigned char pad_24a0[0x2c];
    int busy;
} PlayerView;
#define PLAYER ((PlayerView *)D_00189E20)
extern float func_L00_0037E668(void);
extern float func_L00_0037E5F0(float);
extern void func_L00_002A6708(void);
extern void func_00282CF0(void *, void *, void *);
extern void func_L00_002D36E0(float *, int, float, float, float);
extern int func_L03_002C6F08(int, int);
extern void *func_002A9640(void *, unsigned int, int);
extern int func_00283CF0(float);
extern void func_L00_002A4EF8(int);
extern int func_L00_002B9B88(int, int);
extern void func_L00_002B2C58(int, int, float, float);
extern void func_L00_002D3C68(char *, char *, float);
extern void func_00282CC0(void *, void *, void *);
int func_L03_002B8708(int activate)
{
    Quad displacement;
    Interaction *contact;
    char *object;
    char *other;
    int special;
    float first;
    if (PLAYER->activity == 20 || PLAYER->activity == 7 || PLAYER->mode == 0x31) return 0;
    if (PLAYER->lock) return 0;
    if (D_L03_001A8F00) return 0;
    PLAYER->other = 0;
    object = PLAYER->object;
    if (*(unsigned char *)(object + 0xa8) == 0xff) return 0;
    contact = &D_L03_001C4040[*(unsigned char *)(object + 0xa8)];
    if (contact->owner != object) return 0;
    if (!(contact->flags & 9)) return 0;
    if (contact->time != 0.0f) { D_001A7A33 = 0; D_001A7A32 = 1; }
    if (func_L00_0037E668() != 0.0f && PLAYER->state == 0) {
        contact->time = func_L00_0037E5F0(contact->time);
        if (contact->time == 0.0f) return 0;
    }
    PLAYER->other = contact->object;
    if (PLAYER->activity == 15) {
        PLAYER->interaction = 1;
        PLAYER->contact = contact;
        return 0;
    }
    if (!activate) return 1;
    special = 0;
    func_L00_002A6708();
    if (contact->status & 1) {
        displacement = contact->delta;
        if (((float *)&contact->delta)[3] == 5627.925f) special = 1;
    } else if (contact->object) {
        func_00282CF0(&displacement, D_00189E20 + 0x80, contact->object + 0x10);
    } else {
        func_L00_002D36E0((float *)&displacement, 0, -1.0f, 0.0f, 0.0f);
    }
    if (PLAYER->state) {
        if (PLAYER->state == 1) {
            func_L03_002C6F08(0x42, 1);
            func_L00_002B2C58((int)&displacement, special, 0.083333336f, 0.050000004f);
        }
        goto apply;
    }
    other = PLAYER->other;
    if (other && (*(short *)(other + 0xaa) == 0x4eb || *(short *)(other + 0xaa) == 0x558)) {
        func_L03_002C6F08(0x7d,1); return 1;
    }
    if (PLAYER->mode == 1 || PLAYER->mode == 0x1d || PLAYER->specialMode) {
        if (!(contact->flags & 8)) {
            other = func_002A9640(PLAYER->object, 1, 0);
            if (other) func_L00_002A4EF8(func_00283CF0(*(float *)(other + 0x2c)));
            if (!PLAYER->busy) func_L03_002C6F08(0x16,1);
            PLAYER->lock = 0x4d;
            if (!PLAYER->timer) PLAYER->timer = 0x12;
            func_L00_002B9B88(0x14,0);
            return 0;
        }
        func_L03_002C6F08(0x8c,1);
    } else {
        if (contact->flags & 8) func_L03_002C6F08(0x8c,1);
        else func_L03_002C6F08(0x16,1);
    }
    if (PLAYER->mode == 0x8c) displacement = 0;
    else {
        first = 0.055f;
        if (PLAYER->pressed) first = 0.0f;
        func_L00_002B2C58((int)&displacement,special,first,0.028333336f);
        if (special && contact->kind == 4)
            func_L00_002D3C68((char *)&displacement,(char *)&displacement,2.0f);
    }
apply:
    func_00282CC0(D_00189E20 + 0xf0,D_00189E20 + 0xf0,&displacement);
    func_00282CC0(D_00189E20 + 0x110,D_00189E20 + 0x110,&displacement);
    return 1;
}
