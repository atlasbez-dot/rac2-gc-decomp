/* Bounded manual reconstruction, 2026-10-23; not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: func_L16_004051A8: 0 of 2 places match (src/levels/shared/L16_004051A8-g8-qcopy.c); us2: func_L16_004051A8: 0 of 2 places match (src/levels/shared/L16_004051A8-g8-qcopy.c); pal: func_L16_004051A8: 0 of 2 places match (src/levels/shared/L16_004051A8-g8-qcopy.c)
 * 724/736 bytes; collision-branch merge and request/vector scheduling differ. The 48-byte aligned request includes its real active word; callback identity is function-scoped for varying placements. Reopen with original collision request control flow and declaration evidence.
 * Historical screening note below predates this C reconstruction.
 */
/* func_L16_004051A8 - 736 bytes, 2 place(s), level 16_snivelak, retail at
   0x004051a8. Screened with tools/w10_screen.py: 18 call(s)
   [func_002A8C28@0040520C, func_002A7750@0040521C, func_00282CC0@0040524C,
   func_002A8C00@0040526C, func_002761F8@0040528C, func_00277258@004052B0,
   func_00282D30@00405304, func_002A8C00@00405340, func_00277F48@00405374,
   func_002A7750@00405384, func_00282D30@004053AC, func_00282C88@004053B4,
   func_L16_00406080@004053F0, func_002E5CF8@00405400,
   func_0029F338@00405408, func_002ACEC0@00405434, func_002ACEC0@0040544C,
   func_L00_002E6EF8@0040545C]; data addresses materialised [0x3f190000,
   0x10000, 0x1c0000, 0x3e990000, 0x1c0000, 0x45af0000, 0x10000, 0x3f190000,
   0x3c8e0000, 0x400000]; float constants [0x3fc00000, 0x40400000,
   0x3f800000, 0xbf000000, 0x3e800000]; $gp-relative small data: no   saves:
   -; callee-saved registers saved [-]; words plain C cannot emit [LQ/SQ
   7A620000@0x0130, LQ/SQ 7E020000@0x0134, LQ/SQ 7A620000@0x0148, LQ/SQ
   7E020000@0x014c, LQ/SQ 78620000@0x01f0, LQ/SQ 7E820000@0x01f4]. Head:
   addiu $sp, $sp, -0xD0 ; sd $s2, 0xA0($sp) ; sd $s0, 0x90($sp) ; daddu
   $s2, $a0, $zero ; sd $s1, 0x98($sp) ; sd $s4, 0xB0($sp). Not matched in
   this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C reaches it
   only through a `mode(TI)` local, and this cc1 folds the destination
   offset into the `sq` where retail materialises the pointer first. What
   would unblock it: the exact source expression tree, so this cc1 picks the
   same registers in the same order. */

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
extern void func_002A7750(unsigned char *,unsigned char,int);
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
            if (D_L16_001BFF58==0 || D_L16_001BFF58!=*(char **)(state+0x10)) {
                *(Vector128 *)&local.direction=*(Vector128 *)state;
                if (D_L16_001BFF58==0) scale=3.0f; else scale=1.5f;
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
        *(Vector128 *)(object+0x10)=*(Vector128 *)&local.next;
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
