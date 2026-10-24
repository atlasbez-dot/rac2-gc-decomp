/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-por.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 * Corrected only the known 32-bit pointer return of func_002BFB38. Retail saves the allocator
 * pointer in s0 and returns it in v0 on both the null and successful paths; the four input
 * categories are unchanged. The original 1044/1044 measurement predates this declaration edit;
 * this corrected source has not been recompiled.
 */

/* Nonmatching manual reconstruction.
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por
   1044 bytes, expected 1044, US and US2 first instruction mismatch at +0x18.
   A scalar float-vector aggregate initialization trial grew to 1096 bytes.
   Reopen with a new explanation for zero-vector scheduling and saved registers.
*/
/* Collision/particle family reconstructed against the assigned retail body;
   the retained Oozla draft supplies the same readable vector/hit views. */
#include "common.h"
typedef int DamoselQuad __attribute__((mode(TI)));
typedef struct {
    float direction[4];
    void *owner;
    int flags;
    u8 type, active;
    u16 oclass;
    float damage;
    int enabled;
} DamoselHit;
extern u8 D_00139574;
typedef struct { u8 pad[0x70]; float damage; u8 tail[0x6C]; } DamoselDamage;
extern DamoselDamage D_L23_00266A70[];
typedef struct { u8 pad[0x18]; u8 *other; int count; DamoselQuad position; u8 pad2[0x10]; float normal[4]; } DamoselCollision;
extern DamoselCollision D_L23_001C0A80;
extern char *D_0018C0B0;
extern void *D_L23_001AC790;
extern void func_00282CC0(void *, void *, void *);
extern void func_002AFFD8(void *, void *, int);
extern void func_00282D30(void *, void *, float);
extern void func_L00_0038F3D8(void *);
extern void func_00282F70(void *, void *, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern void func_00283028(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern int func_00282948(void *);
extern void func_002FEE50(int);
extern void func_L00_0038DE70(void *, void *, void *);
extern void func_L00_0038E880(void *, void *, void *);
extern int D_L23_001B2F30 __attribute__((sda));
extern int D_L23_001B2F38 __attribute__((sda));
extern void func_002FEE70(int,void *,int);
extern void func_00300190(void *,void *);
extern void func_00300248(int,int);
extern void func_002FE880(void *,float *,float);
extern void func_L00_0038F178(char *);
extern int func_00278E78(void);
extern void func_002FD1B8(int,int,int,float,float,float,float);
extern void func_00282C88(DamoselQuad *);
extern u8 *func_00312D58(void *,float);
extern float func_002A7940(void);
extern float func_002A7878(float,float);
extern float func_00283180(float);
extern float func_00283198(float);
extern int func_002A7820(int,int);
extern int func_002A77E0(int);
extern unsigned char *func_002BFB38(void *,void *,int,int);
void func_L23_00394218(u8 *object)
{
    float previous[4], movement[4], rotation[4];
    DamoselHit hit;
    float position[4], velocity[4];
    u8 *state;
    u8 *effect;
    u8 *other;
    float angle,radius;
    int i,type,lifetime;
    *(DamoselQuad *)movement = 0;
    state = *(u8 **)(object+0x68);
    *(DamoselQuad *)rotation = 0;
    movement[2] = 0.033333335f;
    rotation[2] = 1.0f;
    *(DamoselQuad *)previous = *(DamoselQuad *)(object+0x10);
    func_00282CC0(object+0x10,state,object+0x10);
    func_002FEE70(*(int *)(state+0x1C),state,0);
    func_00300190(object+0x10,object+0x10);
    func_00300248((int)state,(int)state);
    func_002FE880(object+0x10,(float *)state,0.0030555557f);
    func_L00_0038F178((char *)object);
    hit.flags = 0x830000;
    if (*(int *)(state+0x18) < 290) hit.flags = 0x830001;
    hit.enabled = 1;
    hit.damage = D_L23_00266A70[D_00139574].damage;
    *(DamoselQuad *)hit.direction = *(DamoselQuad *)state;
    hit.owner = object;
    func_00282F70(hit.direction,hit.direction,1.0f);
    hit.oclass = *(u16 *)(object+0xAA);
    hit.direction[2] = 1.0f;
    hit.direction[3] = 5627.9248046875f;
    hit.type = 2;
    hit.active = 1;
    if (func_002761F8(previous,object+0x10,16,object,&hit)) {
        if (func_00278E78() == 0 && *(float *)(state+8) < 0.0f) {
            func_002FD1B8(D_L23_001B2F30,D_L23_001B2F38,1,*(float *)(object+0x10),*(float *)(object+0x14),0.5f,-0.35f);
            *(int *)(state+0x14) = 1;
            func_00282C88((DamoselQuad *)state);
            *(float *)(state+8) = -0.025000002f;
            position[0] = *(float *)(object+0x10);
            position[1] = *(float *)(object+0x14);
            position[2] = ((float *)&D_L23_001C0A80.position)[2];
            effect = func_00312D58(position,2.0f);
            if (effect) effect[0x23] = 0x70;
            for (i=15;i>=0;--i) {
                angle = func_002A7940();
                radius = func_002A7878(0.0f,0.0500000045f);
                velocity[0] = func_00283180(angle)*radius;
                velocity[1] = func_00283198(angle)*radius;
                velocity[2] = func_002A7878(0.0500000045f,0.10833334f);
                lifetime = func_002A7820(90,120);
                type = func_002A77E0(2);
                func_002BFB38(position,velocity,type,lifetime);
            }
            goto finished;
        }
        other = D_L23_001C0A80.other;
        if (other) {
            if ((other == (u8 *)D_0018C0B0 || *(short *)(other+0xAA) == 0xC0) && *(int *)(state+0x18) >= 290) goto finished;
            if (*(void **)(other+0x64) == D_L23_001AC790 && *(short *)(other+0xAA) != 0x336) goto finished;
        } else if (D_L23_001C0A80.count <= 0) goto finished;
        object[0xBC] = 1;
        *(DamoselQuad *)(object+0x10) = D_L23_001C0A80.position;
        func_00283028(movement,state,D_L23_001C0A80.normal);
        func_00282F20(movement,movement,0.033333335f);
        func_00282F20(rotation,D_L23_001C0A80.normal,1.0f);
    } else if (func_00282948(state+0x18)) {
        object[0xBC] = 1;
        func_00282CC0(movement,movement,state);
    }
finished:
    if (object[0xBC]) {
        func_002FEE50(*(int *)(state+0x1C));
        func_L00_0038DE70(object,movement,rotation);
    }
}
