/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy.
 * Reported final C / retail: 1148 / 1124 bytes; size equality is not a match.
 * us: 0/1 placements; 1148/1124 bytes.
 * us2: 0/1 placements; 1148/1124 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Quad address formation, previous/offset stack lifetimes, clamp branches and loop layout.
 * Reopening condition: New measured source-shape/scheduler or ABI remedy addressing the residual; do not repeat tied forms.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained full body: 1148 compiled/1124 retail bytes under -O2 -G0
 * -ffunction-sections -frac2-qcopy, 0/1 USA placements. Typed player views
 * correct frame size from0xa0 to0x90 (byte-offset version1176 bytes).
 * Quad scalar previous local gives1140 bytes but local stack slots differ;
 * aligned Vec previous gives1148; unaligned Vec expands to1164 bytes.
 * qcopy-barrier ties. Collision record uses its true aligned base001bfdd0,
 * with contact+8, normal+16, position+32 and response+48. The bool predicate
 * for dot>-0.92 preserves retail's comparison including NaNs.
 * Remaining differences: quad address formation, initial copies, loop layout
 * and final component clamp branch scheduling. No linked build was run.
 */
#include "include_asm.h"
typedef int V4_Fe23fe324 __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } Vec __attribute__((aligned(16)));
typedef struct { unsigned char pad0[8]; int contact; unsigned char padc[4]; V4_Fe23fe324 normal, position, response; } CollisionView;
extern unsigned char D_00189E20[];
extern unsigned char D_L03_001BFDD0[];
#define HIT ((CollisionView *)D_L03_001BFDD0)
typedef struct {
    unsigned char pad_0[0x20];
    Vec basis;
    unsigned char pad_30[0x50];
    V4_Fe23fe324 position;
    unsigned char pad_90[0x156];
    short locked;
    unsigned char pad_1e8[0x8];
    short disabled;
    unsigned char pad_1f2[0x26];
    short timer;
    unsigned char pad_21a[0x16];
    V4_Fe23fe324 response;
    V4_Fe23fe324 normal;
    float height;
    float offset;
    unsigned char pad_258[0xc];
    float radius;
    unsigned char pad_268[0x4];
    int contact;
    unsigned char pad_270[0x17];
    unsigned char hit;
    unsigned char pad_288[0x38];
    Vec up;
    unsigned char pad_2d0[0x1fc0];
    char * object;
    unsigned char pad_2294[0x8];
    int activity;
    unsigned char pad_22a0[0x14];
    unsigned char state;
    unsigned char pad_22b5[0xe];
    unsigned char transformed;
    unsigned char pad_22c4[0x23a];
    short reset;
} PlayerView;
#define PLAYER ((PlayerView *)D_00189E20)
extern int D_L03_001A8FF0 __attribute__((sda));
extern void func_00282C88(void *);
extern void func_L00_002D49F0(void *);
extern float func_00282DB0(void *,void *);
extern void func_00283098(void *,void *,void *);
extern void func_L00_002D38A0(V4_Fe23fe324 *,V4_Fe23fe324 *,float);
extern void func_L00_002D36E0(float *,int,float,float,float);
extern void func_00282CC0(void *,void *,void *);
extern int func_00277258(void *,int,void *,float);
extern int func_L00_002E0200(void *,int,void *,float,float);
extern int func_00278870(void *,float);
extern void func_00282CF0(void *,void *,void *);
extern float func_00282DF0(void *);
extern void func_00282F20(void *,void *,float);
int func_L03_002BAEA0(int mode)
{
    Vec previous;
    Vec offset, displacement;
    float amount;
    int facingUp, iteration, hit;
    if (PLAYER->disabled) return 1;
    previous = *(Vec *)&PLAYER->position;
    func_00282C88(&offset);
    if (PLAYER->reset) {
        func_L00_002D49F0(D_00189E20 + 0x20);
        PLAYER->reset = 0;
    }
    facingUp = func_00282DB0(D_00189E20 + 0x20,D_00189E20 + 0x2c0) > -0.92f;
    if (PLAYER->activity == 15) {
        func_00282C88(&offset);
        offset.z = 0.8f;
        func_00283098(&offset,&offset,PLAYER->object + 0xc0);
    } else if (PLAYER->activity == 17) {
    } else if (!PLAYER->transformed && !PLAYER->timer && !facingUp) {
        offset.z = PLAYER->offset;
    } else if (PLAYER->state == 2) {
        func_L00_002D38A0((V4_Fe23fe324 *)&offset,(V4_Fe23fe324 *)&offset,5.0f);
    } else if (PLAYER->transformed == 1 || PLAYER->timer) {
        func_L00_002D36E0(&offset.x,0,0.0f,0.0f,0.6f);
    } else if (D_L03_001A8FF0) {
        func_L00_002D38A0((V4_Fe23fe324 *)&offset,(V4_Fe23fe324 *)&offset,0.77f);
    } else {
        func_L00_002D36E0(&offset.x,0,0.0f,0.0f,PLAYER->offset);
    }
    func_00282CC0(D_00189E20 + 0x80,D_00189E20 + 0x80,&offset);
    for (iteration=0;iteration<8;++iteration) {
        if (PLAYER->activity == 15) {
            hit = func_00277258(D_00189E20 + 0x80,0xd24,PLAYER->object,0.45f);
        } else {
            if (PLAYER->transformed || facingUp)
                hit = func_00277258(D_00189E20 + 0x80,0xd24,PLAYER->object,PLAYER->radius);
            else {
                amount = PLAYER->height-PLAYER->offset;
                if (amount<0.05f) amount=0.05f;
                hit = func_L00_002E0200(D_00189E20 + 0x80,0xd24,PLAYER->object,PLAYER->radius,amount);
            }
            if (!PLAYER->locked)
                hit |= func_00278870(D_00189E20 + 0x80,PLAYER->radius);
        }
        if (!hit) break;
        PLAYER->position = HIT->position;
        PLAYER->response = HIT->response;
        PLAYER->normal = HIT->normal;
        PLAYER->contact = HIT->contact;
        PLAYER->hit = 1;
    }
    func_00282CF0(D_00189E20 + 0x80,D_00189E20 + 0x80,&offset);
    func_00282CF0(&displacement,D_00189E20 + 0x80,&previous);
    if (func_00282DF0(&displacement) <= PLAYER->radius*1.5f) return 1;
    if (mode!=15) return -1;
    if (displacement.x>512.0f) displacement.x=512.0f;
    else if (displacement.x<-512.0f) displacement.x=-512.0f;
    if (displacement.y>512.0f) displacement.y=512.0f;
    else if (displacement.y<-512.0f) displacement.y=-512.0f;
    if (displacement.z>512.0f) displacement.z=512.0f;
    else if (displacement.z<-512.0f) displacement.z=-512.0f;
    func_00282F20(&displacement,&displacement,PLAYER->radius);
    func_00282CC0(D_00189E20 + 0x80,&previous,&displacement);
    return -1;
}
