/* Complete retained reconstruction; not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Tested as src/levels/shared/L16_004051A8.c.
 * us: 0/2 placements, exit 1.
 * us2: 0/2 placements, exit 1.
 * pal: 0/2 placements, exit 1.
 * USA compiled 748 / retail 736 bytes.
 * Residual: The two collision branches and their qcopies are explicit, but request/direction pointer joins and header stores still differ; retained748 versus736 bytes.
 * Reopen with: A measured direction/request pointer lifetime that shares the branch copy destination in retail register order without artificial dependencies or omitted stores.
 */

#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
typedef struct { int a,b,c,d; } __attribute__((aligned(16))) Quad16;
typedef struct {
    Quad16 vector;
    int owner,flags;
    unsigned char enabled,kind;
    unsigned short id;
    float distance;
    int active;
} CollisionRequest;
typedef struct { Vector128 next; CollisionRequest move; Vector128 direction; CollisionRequest area; } ProjectileWorkspace;
extern int func_002A8C28(void *,float,float *,int,float,float,int,int,int);
extern void func_002A7750(unsigned char *,int,int);
extern void func_00282CC0(void *,void *,void *);
extern void func_002A8C00(char *,int,int,float,Quad16 *);
extern int func_002761F8(void *,void *,int,void *,void *);
extern int func_00277258(void *,int,void *,float);
extern void func_00282D30(void *,void *,float);
extern int func_00277F48(void *,int,void *,void *,float);
extern void func_00282C88(Vector128 *);
extern char *func_L16_00406080(float,char *,int,int,int,int,int,int,int,int,int);
extern int func_002E5CF8(int,int,char *);
extern void func_0029F338(void *);
extern void func_002ACEC0(void *,void *,void *,float);
extern void func_L00_002E6EF8(void (*)(void *),void *);
extern void ref_L16_004051A8_00(void *);
extern char *D_L16_001BFF58 __attribute__((nosda));
extern float D_L16_001B145C __attribute__((sda));
void func_L16_004051A8(char *object)
{
    ProjectileWorkspace local;
    char *state=*(char **)(object+0x68);
    float scale;
    (*(int *)(state+0x24))++;
    if (*(int *)(state+0x24)>240) {
        func_002A8C28(object,0.6f,(float *)(object+0x10),0x10003,*(float *)(state+0x14),0.0f,0,1,0);
        func_002A7750((unsigned char *)object,1,-1);
    }
    switch (*(unsigned char *)(object+0x20)) {
    case 0:
        func_00282CC0(&local.next,object+0x10,state);
        func_002A8C00((char *)&local.move,(int)object,3,*(float *)(state+0x14),(Quad16 *)state);
        local.move.id=*(unsigned short *)(object+0xaa);
        if (func_002761F8(object+0x10,&local.next,0,object,&local.move)!=0 || func_00277258(object+0x10,0,object,0.3f)!=0) {
            if (D_L16_001BFF58!=0 && D_L16_001BFF58==*(char **)(state+0x10)) goto continueMovement;
            {
                if (D_L16_001BFF58!=0) { qcopy(&local.direction,state); scale=1.5f; }
                else { qcopy(&local.direction,state); scale=3.0f; }
                func_00282D30(&local.direction,&local.direction,scale);
                ((float *)&local.direction)[2]=1.0f;
                ((float *)&local.direction)[3]=5627.9248f;
                func_002A8C00((char *)&local.area,(int)object,0x10003,*(float *)(state+0x14),(Quad16 *)&local.direction);
                local.area.id=*(unsigned short *)(object+0xaa);
                local.area.kind=1;
                local.area.enabled=0;
                func_00277F48(object+0x10,0,object,&local.area,0.6f);
                func_002A7750((unsigned char *)object,1,-1);
                return;
            }
        }
continueMovement:
        qcopy(object+0x10,&local.next);
        func_00282D30(&local.direction,state,-0.5f);
        func_00282C88((Vector128 *)&local.area);
        break;
    case 1:
        func_L16_00406080(0.25f,object+0x10,0,25,20,20,20,0,0,1,0);
        func_002E5CF8(0,0,object);
        func_0029F338(object);
        return;
    }
    func_002ACEC0(object+0xe0,object+0xe0,object+0xd0,D_L16_001B145C*0.017453294f);
    func_002ACEC0(object+0xc0,object+0xc0,object+0xd0,D_L16_001B145C*0.017453294f);
    func_L00_002E6EF8(ref_L16_004051A8_00,object);
}
