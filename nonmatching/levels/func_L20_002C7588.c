/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 876 / 876 bytes; size equality is not a match.
 * us: 0/1 placements.
 * us2: 0/1 placements.
 * pal: absent from catalogue (not a match).
 * Residual: Three argument-register moves differ in second36E0 call; direct product/updated-height/distinct lowerHeight tie.
 * Reopening condition: New measured source-shape/scheduler or ABI remedy addressing the residual; do not repeat tied forms.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: Earlier mapping was superseded by a complete manual reconstruction. Player-block address lifetime and control-flow allocation remain experimental; the historical instruction listing is retained privately. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/* Near miss: 876 retail/compiled bytes, 0/1 USA placements.
 * Only argument scheduling for the second func_L00_002D36E0 call differs:
 * +0x114/+0x11c/+0x124 permute the a1=1 and f12/f13 zero moves.
 * Direct product, height*=0.3f, and distinct lowerHeight locals tie;
 * -G8 and -g also tie. Separate dot and angle locals are necessary to
 * avoid a surplus move at the final dot-product comparison (880 bytes).
 * Shared resident base+0xf0 avoids a sixth saved GPR (884 bytes).
 * Reopen with a qualified scheduler remedy; no linked build was run.
 */
#include "include_asm.h"
typedef int V4_F6a70b950 __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } Vec4;
typedef struct {
    unsigned char pad0[0x270]; int contact;
    unsigned char pad274[0x2290-0x274]; void *object;
    unsigned char pad2294[8]; int activity;
    unsigned char pad22a0[0x14]; unsigned char state;
} MotionView;
typedef struct {
    unsigned char pad0[0x18]; int contact; int count;
    unsigned char pad20[0x20]; Vec4 normal;
} ContactView;
extern unsigned char D_00189E20[];
#define VELOCITY ((char *)(D_00189E20 + 0xf0))
extern unsigned char D_L20_001C0400[];
#define PLAYER ((MotionView *)D_00189E20)
#define CONTACT ((ContactView *)D_L20_001C0400)
extern float func_L00_002D3A58(char *);
extern void func_L00_002D36E0(float *, int, float, float, float);
extern float func_00282E20(void *);
extern void func_00282F20(void *, void *, float);
extern void func_L00_002D3B58(V4_F6a70b950 *, V4_F6a70b950 *, float);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_002761F8(void *, void *, int, void *, void *);
extern int func_00278E78(void);
extern float func_L00_002D3EA8(char *);
extern float func_00282DB0(void *, void *);
void func_L20_002C7588(int force)
{
    Vec4 offset, start, lowerOffset, lowerStart;
    float height, radius, angle;
    float lowerHeight;
    int kind;
    if (func_L00_002D3A58(VELOCITY) < 0.0016666668f) return;
    height = 0.37f;
    radius = 0.5f;
    if ((unsigned int)(PLAYER->activity - 0x11) < 2) {
        height = 0.0f;
        radius = 0.7f;
    } else if (PLAYER->state == 1) {
        height = 0.35f;
        radius = 0.27f;
    } else if (PLAYER->state == 4) height = 0.35f;
    func_L00_002D36E0(&offset.x, 1, 0.0f, 0.0f, height);
    lowerHeight = height * 0.3f;
    func_L00_002D36E0(&lowerOffset.x, 1, 0.0f, 0.0f, lowerHeight);
    if (force || func_00282E20(VELOCITY) < 0.01f) {
        func_00282F20(&start, D_00189E20, radius);
        func_00282F20(&lowerStart, D_00189E20, radius * 1.4f);
    } else {
        func_L00_002D3B58((V4_F6a70b950 *)&start, (V4_F6a70b950 *)VELOCITY, 0.0f);
        func_00282F20(&start, &start, radius);
        func_00282D30(&lowerStart, &start, 1.4f);
    }
    kind = -1;
    func_00282CC0(&start, &start, &offset);
    func_00282CC0(&lowerStart, &lowerStart, &lowerOffset);
    if (func_002761F8(&lowerOffset, &lowerStart, 2, PLAYER->object, 0) && CONTACT->count > 0)
        kind = func_00278E78();
    angle = 0.0f;
    if (func_002761F8(&offset, &start, 2, PLAYER->object, 0) && CONTACT->count > 0)
        angle = func_L00_002D3EA8((char *)&CONTACT->normal);
    if (angle >= 0.8726647f || kind == 8 || kind == 12) {
        float dot;
        PLAYER->contact = CONTACT->contact;
        func_L00_002D3B58((V4_F6a70b950 *)&CONTACT->normal, (V4_F6a70b950 *)&CONTACT->normal, 0.0f);
        func_00282F20(&CONTACT->normal, &CONTACT->normal, 1.0f);
        dot = func_00282DB0(&CONTACT->normal, VELOCITY);
        if (dot < 0.0f) {
            func_00282D30(&CONTACT->normal, &CONTACT->normal, -dot);
            func_00282CC0(VELOCITY, VELOCITY, &CONTACT->normal);
        }
    }
}
