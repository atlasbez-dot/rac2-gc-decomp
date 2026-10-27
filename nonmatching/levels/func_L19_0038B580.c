/* M33 2026-10-26: 1036 -> 1044/1044 B, 90 -> 16 lines. contact->hit is re-read at each use (not a local), D_L19_001AC790 is NOT_SDA (retail lui/lw), and the contact pointer is set again before the second hit test: retail rebuilds &D_L19_001BFE80 from the kept %hi on each path (addiu s1,a0,-0x180 in two slots). That second assignment may stand for an inlined helper; judge before landing. Left: registers in the D_00139574 weapon-record read, the i/&spread setup order before the spread loop, and a0/a1 for the hit vs the %hi in the contact tests. In the permuter. The twin func_L26_0038BB28 (same size) should take the same spellings. */
/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * 1036/1044 bytes. us: 0/1 places; us2: 0/1 places; pal: absent.
 * Remaining: Old-position, request vector and collision-result transfers use real qcopy.
 * The complete aligned 48-byte request retains all later component/tag writes,
 * actor ownership and sixteen impact emissions. Factory-result and hit views
 * are scoped to their actual branches, with the real int32 timer pointer and
 * pointer-valued owner comparison. The 0xE0 frame agrees, but request scalar
 * stores, weapon-table temporaries and collision-base scheduling differ.
 * Reopen with: Independent request/owner or collision-base lifetime evidence. Ordinary
 * store permutations and equal object size do not establish a match.
 * Review correction: The particle factory 002BFB38 correctly returns pointer/null; its four GPR arguments are retained and this caller still discards the result. Changing only the return declaration preserves the entire 4540-byte object (SHA256 80e60097b90239eb28ef7b86b2887c6f8f1f9c330a7518fa2065280512db2951).
 */

#include "common.h"

typedef unsigned int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vec;
extern unsigned char D_00139574;
extern char *D_0018C0B0 NOT_SDA;
extern void *D_L19_001AC790 NOT_SDA;
typedef struct { char pad[0x18]; char *hit; int count; Vec point; char gap[0x10]; Vec normal; } Collision;
extern Collision D_L19_001BFE80;
typedef struct { char prefix[0x70]; float material; char tail[0x6c]; } WeaponRecord;
extern WeaponRecord D_L19_00265870[];
extern int D_L19_001B31B0 __attribute__((sda)),D_L19_001B31B8 __attribute__((sda));
extern void func_00282CC0(void *,void *,void *);
extern void func_002FEE70(int,void *,int);
extern void func_00300190(void *,void *);
extern void func_00300248(int,int);
extern void func_002FE880(void *,float *,float);
extern void func_L00_0038F178(void *);
extern void func_00282F70(void *,void *,float);
extern int func_002761F8(void *,void *,int,void *,void *);
extern int func_00282948(int *);
extern int func_00278E78(void);
extern void func_002FD1B8(int,int,int,float,float,float,float);
extern void func_00282C88(void *);
extern char *func_00312D58(void *,float);
extern float func_002A7940(void);
extern float func_002A7878(float,float);
extern float func_00283180(float);
extern float func_00283198(float);
extern int func_002A7820(int,int);
extern int func_002A77E0(int);
extern void *func_002BFB38(void *,void *,int,int);
extern void func_00283028(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_002FEE50(int);
extern void func_L00_0038DE70(void *,void *,void *);
void func_L19_0038B580(unsigned char *obj) {
    struct { Vec old,velocity,normal;
        struct { Vec vector; char *moby; int flags; unsigned char kind,active; unsigned short class_id; float material; int enabled; } packet;
        Vec position,spread;
    } frame;
    char *ctx, *position;
    int i,lifetime;
    unsigned short class_id;
    float angle,speed;
    frame.velocity.q=0;
    ctx=*(char **)(obj+0x68); position=(char *)obj+0x10;
    frame.velocity.f[2]=0.033333335f;
    frame.normal.q=0; frame.normal.f[2]=1.0f;
    qcopy(&frame.old, position);
    func_00282CC0(position,ctx,position);
    func_002FEE70(*(int *)(ctx+0x1C),ctx,0);
    func_00300190(position,position);
    func_00300248((int)ctx,(int)ctx);
    func_002FE880(position,(float *)ctx,0.0030555557f);
    func_L00_0038F178(obj);
    frame.packet.moby=obj; frame.packet.flags=0x830000;
    if(*(int *)(ctx+0x18)<0x122) frame.packet.flags=0x830001;
    frame.packet.enabled=1;
    frame.packet.material=D_L19_00265870[D_00139574].material;
    qcopy(&frame.packet.vector, ctx);
    func_00282F70(&frame.packet.vector,&frame.packet.vector,1.0f);
    class_id=*(unsigned short *)(obj+0xAA);
    frame.packet.vector.f[2]=1.0f; frame.packet.vector.f[3]=5627.925f;
    frame.packet.kind=2; frame.packet.class_id=class_id; frame.packet.active=1;
    if(func_002761F8(&frame.old,position,0x10,obj,&frame.packet)) {
        if(!func_00278E78() && *(float *)(ctx+8)<0.0f) {
            char *effect;
            func_002FD1B8(D_L19_001B31B0,D_L19_001B31B8,1,*(float *)(obj+0x10),*(float *)(obj+0x14),0.5f,-0.35f);
            *(int *)(ctx+0x14)=1;
            func_00282C88(ctx);
            *(float *)(ctx+8)=-0.025000002f;
            frame.position.f[0]=*(float *)(obj+0x10); frame.position.f[1]=*(float *)(obj+0x14);
            frame.position.f[2]=D_L19_001BFE80.point.f[2];
            effect=func_00312D58(&frame.position,2.0f);
            if(effect) effect[0x23]=0x70;
            i=15;
            do {
                --i; angle=func_002A7940(); speed=func_002A7878(0.0f,0.050000004f);
                frame.spread.f[0]=func_00283180(angle)*speed;
                frame.spread.f[1]=func_00283198(angle)*speed;
                frame.spread.f[2]=func_002A7878(0.050000004f,0.10833334f);
                lifetime=func_002A7820(90,120);
                func_002BFB38(&frame.position,&frame.spread,func_002A77E0(2),lifetime);
            } while(i>=0);
        } else {
            Collision *contact = &D_L19_001BFE80;
            if(contact->hit) {
                if((contact->hit==D_0018C0B0 || *(short *)(contact->hit+0xAA)==0xC0) && *(int *)(ctx+0x18)>0x121) goto finish;
                contact = &D_L19_001BFE80;
                if(*(void **)(contact->hit+0x64)==D_L19_001AC790 && *(short *)(contact->hit+0xAA)!=0x336) goto finish;
            } else if(contact->count<1) goto finish;
            obj[0xBC]=1;
            qcopy((obj+0x10), &contact->point);
            func_00283028(&frame.velocity,ctx,&contact->normal);
            func_00282F20(&frame.velocity,&frame.velocity,0.033333335f);
            func_00282F20(&frame.normal,&contact->normal,1.0f);
        }
    } else if(func_00282948((int *)(ctx+0x18))) {
        obj[0xBC]=1; func_00282CC0(&frame.velocity,&frame.velocity,ctx);
    }
finish:
    if((unsigned char)obj[0xBC]) { func_002FEE50(*(int *)(ctx+0x1C)); func_L00_0038DE70(obj,&frame.velocity,&frame.normal); }
}
