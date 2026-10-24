/* Bounded manual reconstruction, 2026-10-23; not linked.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: func_L16_00395D30: 0 of 2 places match (src/levels/shared/L16_00395D30-g16-qcopy.c); us2: func_L16_00395D30: 0 of 2 places match (src/levels/shared/L16_00395D30-g16-qcopy.c); pal: func_L16_00395D30: 0 of 2 places match (src/levels/shared/L16_00395D30-g16-qcopy.c)
 * 412/412 bytes; camera/target/inverse register allocation and absolute-address materialization differ. Tried direct global expressions and explicit camera pointers. The GP direction retains its real 16-byte extent under G16. Reopen with source-layout evidence; do not shrink the vector.
 * Historical screening note below predates this C reconstruction.
 */
/* func_L16_00395D30 - 412 bytes, 2 place(s), level 16_snivelak, retail at
   0x00395d30. Screened with tools/w10_screen.py: 15 call(s)
   [func_00335438@00395D90, func_002833F0@00395DA4, func_00283698@00395DB4,
   func_002A91F0@00395DC4, func_00282CF0@00395DD8, func_00283098@00395DEC,
   func_00282F20@00395E04, func_00282CC0@00395E14, func_00282CF0@00395E28,
   func_00282F20@00395E3C, func_00282DD8@00395E58, func_00283098@00395E6C,
   func_00283098@00395E80, func_002AB6D8@00395E90, func_002A91F0@00395EA0];
   data addresses materialised [0x1c0000, 0x1b0000]; float constants
   [0x1b0000, 0x1b0000, 0x1b0000, 0x40400000, 0x3f800000, 0x1b0000,
   0x1b0000, 0x1b0000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [LQ/SQ 78620000@0x011c,
   LQ/SQ 7CC20000@0x0120]. Head: addiu $sp, $sp, -0x100 ; addiu $v0, $zero,
   -0x1 ; sd $s5, 0xE8($sp) ; sd $s0, 0xC0($sp) ; daddu $s5, $a0, $zero ; sd
   $s1, 0xC8($sp). Not matched in this wave: the 128-bit copy needs an
   `lq`/`sq` pair; plain C reaches it only through a `mode(TI)` local, and
   this cc1 folds the destination offset into the `sq` where retail
   materialises the pointer first. What would unblock it: the exact source
   expression tree, so this cc1 picks the same registers in the same order. */

#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
typedef struct { Vector128 rotation[3], inverse[4], axes[3], point, angles; } AimWorkspace;
extern char *D_L16_001B2B1C __attribute__((nosda));
extern char D_L16_001B9B00[];
extern Vector128 D_L16_001B3490 __attribute__((nosda));
extern Vector128 D_L16_001B34A0 __attribute__((nosda));
extern Vector128 D_L16_001B34B0 __attribute__((nosda));
extern Vector128 D_L16_001B34C0 __attribute__((nosda));
extern Vector128 D_L16_001AF440 __attribute__((sda));
extern void func_00335438(void *,void *,int,int,int);
extern void func_002833F0(void *,void *);
extern void func_00283698(void *,void *);
extern void func_002A91F0(void *,float *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00283098(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282DD8(void *,void *,void *);
extern void func_002AB6D8(float *,float *);
void func_L16_00395D30(char *object)
{
    AimWorkspace local;
    char *state=*(char **)(object+0x68);
    char *camera=D_L16_001B9B00;
    char *cameraPosition=camera+0x10;
    char *target;
    if (*(int *)(state+4)==-1) return;
    target=D_L16_001B2B1C+*(int *)(state+4)*0x100;
    func_00335438(camera,cameraPosition,1,0,0);
    *(int *)(state+0x4c)=0; *(int *)(state+0x50)=0;
    func_002833F0(local.rotation,state+0x20);
    func_00283698(local.inverse,local.rotation);
    func_002A91F0(&D_L16_001B3490,(float *)cameraPosition);
    func_00282CF0(&D_L16_001B34B0,camera,state+0x10);
    func_00283098(&D_L16_001B34B0,&D_L16_001B34B0,local.inverse);
    func_00282F20(&local.point,target+0xe0,3.0f);
    func_00282CC0(&local.point,&local.point,target+0x10);
    func_00282CF0(&local.axes[0],&local.point,object+0x10);
    func_00282F20(&local.axes[0],&local.axes[0],1.0f);
    *(Vector128 *)&local.axes[2]=*(Vector128 *)&local.rotation[2];
    func_00282DD8(&local.axes[1],&local.axes[0],&local.axes[2]);
    func_00283098(&D_L16_001B34C0,&D_L16_001AF440,local.axes);
    func_00283098(&D_L16_001B34C0,&D_L16_001B34C0,local.inverse);
    func_002AB6D8((float *)local.axes,(float *)&local.angles);
    func_002A91F0(&D_L16_001B34A0,(float *)&local.angles);
}
