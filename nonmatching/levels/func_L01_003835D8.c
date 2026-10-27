/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por.
 * 1040/1044 bytes; 0/1 USA v1.01 and USA v2.00 places.
 * The canonical function is absent from the PAL catalogue.
 * Remaining: The full vector transfers and initial clears now agree. The hit owner is set
 * before its direction copy as in retail, keeping all four copied components.
 * Damage table addressing, hit scalar-store allocation and collision branch
 * sharing remain different. The resident pointer is NOT_SDA because its actual
 * address is outside signed GP reach.
 * Reopen with: Independent hit-record/store scheduling and shared collision-tail
 * evidence; real helpers alone do not close this body.
 */

#include "common.h"
typedef int OozlaQuad __attribute__((mode(TI)));
typedef struct {
    float direction[4];
    void *owner;
    int flags;
    u8 type, active;
    u16 oclass;
    float damage;
    int enabled;
} OozlaHit;
extern u8 D_00139574;
typedef struct { u8 pad[0x70]; float damage; u8 tail[0x6C]; } OozlaDamage;
extern OozlaDamage D_L01_002637A0[];
typedef struct { u8 pad[0x18]; u8 *other; int count; OozlaQuad position; u8 pad2[0x10]; float normal[4]; } OozlaCollision;
extern OozlaCollision D_L01_001BF900;
extern char *D_0018C0B0 NOT_SDA;
extern void *D_L01_001AC810;
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
extern int D_L01_001B2CF0 __attribute__((sda));
extern int D_L01_001B2CF8 __attribute__((sda));
extern void func_002FEE70(int,void *,int);
extern void func_00300190(void *,void *);
extern void func_00300248(int,int);
extern void func_002FE880(void *,void *,float);
extern void func_L00_0038F178(void *);
extern int func_00278E78(void);
extern void func_002FD1B8(int,int,int,float,float,float,float);
extern void func_00282C88(void *);
extern u8 *func_00312D58(void *,float);
extern float func_002A7940(void);
extern float func_002A7878(float,float);
extern float func_00283180(float);
extern float func_00283198(float);
extern int func_002A7820(int,int);
extern int func_002A77E0(int);
extern void func_002BFB38(void *,void *,int,int);
void func_L01_003835D8(u8 *object)
{
    float previous[4], movement[4], rotation[4];
    OozlaHit hit;
    float position[4], velocity[4];
    u8 *state;
    u8 *effect;
    u8 *other;
    float angle,radius;
    int i,type,lifetime;
    *(OozlaQuad *)movement = 0;
    state = *(u8 **)(object+0x68);
    *(OozlaQuad *)rotation = 0;
    movement[2] = 0.033333335f;
    rotation[2] = 1.0f;
    qcopy(previous, (object+0x10));
    func_00282CC0(object+0x10,state,object+0x10);
    func_002FEE70(*(int *)(state+0x1C),state,0);
    func_00300190(object+0x10,object+0x10);
    func_00300248((int)state,(int)state);
    func_002FE880(object+0x10,state,0.0030555557f);
    func_L00_0038F178(object);
    hit.owner = object;
    hit.flags = 0x830000;
    if (*(int *)(state+0x18) < 290) hit.flags = 0x830001;
    hit.enabled = 1;
    hit.damage = D_L01_002637A0[D_00139574].damage;
    qcopy(hit.direction, state);
    func_00282F70(hit.direction,hit.direction,1.0f);
    hit.oclass = *(u16 *)(object+0xAA);
    hit.direction[2] = 1.0f;
    hit.direction[3] = 5627.9248046875f;
    hit.type = 2;
    hit.active = 1;
    if (func_002761F8(previous,object+0x10,16,object,&hit)) {
        if (func_00278E78() == 0 && *(float *)(state+8) < 0.0f) {
            func_002FD1B8(D_L01_001B2CF0,D_L01_001B2CF8,1,*(float *)(object+0x10),*(float *)(object+0x14),0.5f,-0.35f);
            *(int *)(state+0x14) = 1;
            func_00282C88(state);
            *(float *)(state+8) = -0.025000002f;
            position[0] = *(float *)(object+0x10);
            position[1] = *(float *)(object+0x14);
            position[2] = ((float *)&D_L01_001BF900.position)[2];
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
        other = D_L01_001BF900.other;
        if (other) {
            if ((other == (u8 *)D_0018C0B0 || *(short *)(other+0xAA) == 0xC0) && *(int *)(state+0x18) >= 290) goto finished;
            if (*(void **)(other+0x64) == D_L01_001AC810 && *(short *)(other+0xAA) != 0x336) goto finished;
        } else if (D_L01_001BF900.count <= 0) goto finished;
        object[0xBC] = 1;
        qcopy(object + 0x10, &D_L01_001BF900.position);
        func_00283028(movement,state,D_L01_001BF900.normal);
        func_00282F20(movement,movement,0.033333335f);
        func_00282F20(rotation,D_L01_001BF900.normal,1.0f);
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
