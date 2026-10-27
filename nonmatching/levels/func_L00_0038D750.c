/* Retained near miss, 26 October 2026 (fam5to9, F9 seed). Not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier (own unit).
 * 1044/1044 bytes, frame 0xE0, 259/261 opcodes; every block, branch and the collision tail
 * now equal. What closed the gap: qcopy+barrier (register-address lq/sq and the col->normal
 * pointer in $s1), the material table as an array of 0xE0-byte records read through a pointer,
 * the packet vector copied through a pointer, packet stores in retail order, `col` reassigned
 * after the `||` (the reassignment is stolen into both branch delay slots), for (i<16) loop.
 * Residual: (1) entry: retail sched1 keeps the velocity zero store (sq 0x10) ahead of the ctx
 * load; here sched1 hoists the load (same with every statement order; -fno-schedule-insns
 * gives the retail entry, so it is a sched1 priority/dependence difference). (2) else arm:
 * hit/hi-part copy in $a1/$a0 swapped and the L_second loads use v0/a0/a1 where retail uses
 * v1/a0/v0 (local allocation after sched1).
 */
/* Collision response attempt; ordinary TI vector copies. */
typedef unsigned int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vec;
extern unsigned char D_00139574;
extern char *D_0018C0B0;
extern int D_L00_001AC850;
typedef struct { char pad[0x18]; char *hit; int count; Vec point; char gap[0x10]; Vec normal; } Collision;
extern Collision D_L00_001BF200;
typedef struct { char pad[0x70]; float material; char pad2[0x6C]; } Material;
extern Material D_L00_00262570[];
extern int D_L00_001B2630 __attribute__((sda)),D_L00_001B2638 __attribute__((sda));
extern void func_00282CC0(void *,void *,void *);
extern void func_002FEE70(int,void *,int);
extern void func_00300190(void *,void *);
extern void func_00300248(void *,void *);
extern void func_002FE880(void *,void *,float);
extern void func_L00_0038F178(void *);
extern void func_00282F70(void *,void *,float);
extern int func_002761F8(void *,void *,int,void *,void *);
extern int func_00282948(void *);
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
extern void func_002BFB38(void *,void *,int,int);
extern void func_00283028(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_002FEE50(int);
extern void func_L00_0038DE70(void *,void *,void *);
void func_L00_0038D750(unsigned char *obj) {
    struct { Vec old,velocity,normal;
        struct { Vec vector; char *moby; int flags; unsigned char kind,active; unsigned short class_id; float material; int enabled; } packet;
        Vec position,spread;
    } frame;
    char *ctx=*(char **)(obj+0x68), *position=(char *)obj+0x10, *hit;
    int i,lifetime;
    float angle,speed;
    frame.velocity.q=0; frame.velocity.f[2]=0.033333335f;
    frame.normal.q=0; frame.normal.f[2]=1.0f;
    frame.old.q=*(Quad *)position;
    func_00282CC0(position,ctx,position);
    func_002FEE70(*(int *)(ctx+0x1C),ctx,0);
    func_00300190(position,position);
    func_00300248(ctx,ctx);
    func_002FE880(position,ctx,0.0030555557f);
    func_L00_0038F178(obj);
    frame.packet.moby=obj; frame.packet.flags=0x830000;
    if(*(int *)(ctx+0x18)<0x122) frame.packet.flags=0x830001;
    frame.packet.enabled=1;
    { Material *mt=&D_L00_00262570[D_00139574]; frame.packet.material=mt->material; }
    { Vec *v=&frame.packet.vector;
    v->q=*(Quad *)ctx;
    func_00282F70(v,v,1.0f); }
    frame.packet.vector.f[2]=1.0f; frame.packet.vector.f[3]=5627.925f;
    frame.packet.kind=2;
    frame.packet.class_id=*(unsigned short *)(obj+0xAA);
    frame.packet.active=1;
    if(func_002761F8(&frame.old,position,0x10,obj,&frame.packet)) {
        if(!func_00278E78() && *(float *)(ctx+8)<0.0f) {
            func_002FD1B8(D_L00_001B2630,D_L00_001B2638,1,*(float *)(obj+0x10),*(float *)(obj+0x14),0.5f,-0.35f);
            *(int *)(ctx+0x14)=1;
            func_00282C88(ctx);
            *(float *)(ctx+8)=-0.025000002f;
            frame.position.f[0]=*(float *)(obj+0x10); frame.position.f[1]=*(float *)(obj+0x14);
            frame.position.f[2]=D_L00_001BF200.point.f[2];
            hit=func_00312D58(&frame.position,2.0f);
            if(hit) hit[0x23]=0x70;
            for(i=0;i<16;i++) { angle=func_002A7940(); speed=func_002A7878(0.0f,0.050000004f);
                frame.spread.f[0]=func_00283180(angle)*speed;
                frame.spread.f[1]=func_00283198(angle)*speed;
                frame.spread.f[2]=func_002A7878(0.050000004f,0.10833334f);
                lifetime=func_002A7820(90,120);
                func_002BFB38(&frame.position,&frame.spread,func_002A77E0(2),lifetime);
            }
        } else {
            { Collision *col=&D_L00_001BF200;
            if(col->hit) {
                if((col->hit==D_0018C0B0 || *(short *)(col->hit+0xAA)==0xC0) && *(int *)(ctx+0x18)>0x121) goto finish;
                col=&D_L00_001BF200;
                if(*(int *)(col->hit+0x64)==D_L00_001AC850 && *(short *)(col->hit+0xAA)!=0x336) goto finish;
            } else if(col->count<1) goto finish;
            obj[0xBC]=1;
            *(Quad *)(obj+0x10)=col->point.q;
            func_00283028(&frame.velocity,ctx,&col->normal);
            func_00282F20(&frame.velocity,&frame.velocity,0.033333335f);
            func_00282F20(&frame.normal,&col->normal,1.0f); }
        }
    } else if(func_00282948(ctx+0x18)) {
        obj[0xBC]=1; func_00282CC0(&frame.velocity,&frame.velocity,ctx);
    }
finish:
    if((unsigned char)obj[0xBC]) { func_002FEE50(*(int *)(ctx+0x1C)); func_L00_0038DE70(obj,&frame.velocity,&frame.normal); }
}
