/* Nonmatching reconstruction checked 23 October 2026.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/27, us2 0/27; no candidate.
 * Manual two-stage blast/ray fan:2504/2516; -g trial remained 2504 and was discarded. The actual quaternion input is 16 bytes, verified by callee lqc2; final compiler and GNU assembler both use G16.
 * Remaining: State/control flow, short timers, hit-array/workspace register allocation and ray-call scheduling differ.
 * Reopen with typed weapon-state and timer/hit-loop source-lifetime evidence; review ASM-only helper interfaces.
 * Historical screening below is preserved, not treated as acceptance evidence.
 */

/* func_L00_003A53E8 - 2516 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003a53e8. Screened with tools/w10_screen.py: 61 call(s)
   [func_00282978@003A5454, func_002E5CF8@003A5468, func_002A75E0@003A54A4,
   func_L00_002C42E0@003A54C4, func_002829D8@003A54CC,
   func_L00_002D4040@003A5500, func_00273318@003A5544,
   func_00282948@003A5570, func_L00_002D3F30@003A55FC,
   func_L00_002AF568@003A5688, func_L00_002D6998@003A569C,
   func_002A7940@003A56AC, func_002A7470@003A56C4, func_00283CE0@003A56CC,
   func_00283CE0@003A56DC, func_002A7940@003A56E8, func_002A7940@003A56F0,
   func_00283CE0@003A5704, func_002E5CF8@003A573C,
   func_L00_002D4040@003A5764, func_L00_002D6B70@003A578C,
   func_00282978@003A57A8, func_00282978@003A57B0, func_00282948@003A57B8,
   func_L00_002E6EF8@003A57D0, func_00282978@003A57EC,
   func_L00_0032A1A8@003A5818, func_0029FCC0@003A5850,
   func_L00_003A5FC0@003A585C, func_L00_002E6EF8@003A587C,
   func_002E5CF8@003A588C, func_00282D30@003A595C, func_00282CC0@003A596C,
   func_00282D30@003A5988, func_00282CC0@003A5998, func_00277F48@003A59B4,
   func_00282D30@003A5A58, func_002A8E20@003A5A68, func_0032D758@003A5A78,
   func_00283410@003A5A90, func_00283678@003A5A9C, func_0029FCC0@003A5AAC,
   func_00282D30@003A5ADC, func_00282D30@003A5AEC, func_00282D30@003A5B04,
   func_00283738@003A5B14, func_00282D30@003A5B4C, func_00283738@003A5B5C,
   func_002A7878@003A5C00, func_002AB668@003A5C10, func_002ACDE8@003A5C20,
   func_002ACDE8@003A5C30, func_002A7878@003A5C4C, func_00283B98@003A5C58,
   func_002AB668@003A5C6C, func_002ACDE8@003A5C7C, func_002ACDE8@003A5C8C,
   func_00282D30@003A5CA0, func_00282CC0@003A5CB0, func_00282CC0@003A5CC0,
   func_L00_003A5DC0@003A5CD4]; data addresses materialised [0x190000,
   0x190000, 0x190000, 0x600f0000, 0x60000000, 0x600f0000, 0x3fa60000,
   0x190000, 0x190000, 0x140000, 0x140000, 0x260000, 0x290000, 0x190000,
   0x190000, 0x3a0000, 0x3a0000, 0x3d750000, 0x1c0000, 0x3df50000, 0x140000,
   0x260000, 0xbfac0000, 0x3e8c0000, 0x1c0000, 0x45af0000, 0x190000,
   0x3dcc0000, 0xbdcc0000, 0x3f860000, 0x3ea70000, 0x3c230000, 0x140000,
   0x260000]; float constants [0x42b40000, 0x3f800000, 0x190000, 0x3f800000,
   0x10000, 0x3fc00000, 0xbfc00000, 0xbf800000, 0x3f000000, 0x3fc00000,
   0x42000000, 0x3f800000]; $gp-relative small data: no   saves: -; callee-
   saved registers saved [-]; words plain C cannot emit [LQ/SQ
   7A020000@0x043c, LQ/SQ 7C620000@0x0440, LQ/SQ 78820000@0x0484, LQ/SQ
   7C620000@0x0488, LQ/SQ 7A020000@0x073c, LQ/SQ 7EA20000@0x0740, LQ/SQ
   78620000@0x074c, LQ/SQ 7C820000@0x0750, LQ/SQ 7AA20000@0x0780, LQ/SQ
   7C620000@0x0784]. Head: addiu $sp, $sp, -0x2C0 ; sd $s4, 0x280($sp) ; sd
   $s0, 0x260($sp) ; daddu $s4, $a0, $zero ; sd $s1, 0x268($sp) ; sd $s2,
   0x270($sp). Not matched in this wave: the 128-bit copy needs an `lq`/`sq`
   pair; plain C reaches it only through a `mode(TI)` local, and this cc1
   folds the destination offset into the `sq` where retail materialises the
   pointer first. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
struct Rac2Native_5f824a0e369ccf7b_src_record { u8 b0,b1,b2,b3; u16 s4,s6,s8,s10,s12; u8 e,f; };
extern struct Rac2Native_5f824a0e369ccf7b_src_record D_L00_00294900[];
extern int D_0018C0B4 NOT_SDA, D_0018C0BC NOT_SDA, D_0018C354 NOT_SDA;
extern char *D_0018C0B0 NOT_SDA, *D_0018AA18 NOT_SDA;
extern int D_0018B270 NOT_SDA, D_0018B060 NOT_SDA;
extern u8 D_0018C0DC NOT_SDA, D_0018C0D8 NOT_SDA, D_00139582 NOT_SDA;
extern unsigned int D_00138320 NOT_SDA,D_00138324 NOT_SDA,D_0018B050 NOT_SDA;
extern short D_0018C30C NOT_SDA;
extern float D_0018A550[4] NOT_SDA,D_0018A560[4] NOT_SDA,D_0018A570[4] NOT_SDA,D_0018A580[4] NOT_SDA;
extern float D_L00_001AF670[4] __attribute__((sda));
extern unsigned int D_L00_001AF680 __attribute__((sda));
extern unsigned int D_L00_001AF684 __attribute__((sda));
extern unsigned int D_L00_001AF688 __attribute__((sda));
extern unsigned int D_L00_001AF68C __attribute__((sda));
extern unsigned int D_L00_001AF690 __attribute__((sda));
extern int D_L00_001AF6B4 __attribute__((sda));
/* Only this measured prefix of the level's pulse-curve state is used here. */
typedef struct { float start; int reserved,ticks,mode; float next; int reserved2,nextTicks; } PulseCurvePrefix;
extern PulseCurvePrefix D_L00_001B8DE0 NOT_SDA;
typedef struct { char p0[0x28]; unsigned int animation; char p1[0x28]; float rate; char p2[0x18]; float power; char tail[0x6C]; } WeaponEntry;
extern WeaponEntry D_L00_00262570[];
extern char *D_L00_001C3280[];
extern int func_00282978(void *),func_00282948(void *),func_002829D8(void *);
extern int func_002E5CF8(int,int,char *);
extern void func_002A75E0(void *,int,int,int,int),func_002A7470(void *,int,int,int);
extern void func_L00_002C42E0(int,int);
extern int func_L00_002D4040(int),func_L00_002D3F30(int,int);
extern void func_00273318(void *,unsigned int,void *,int,int,int,float,float,float);
extern void func_L00_002AF568(void),func_L00_002D6B70(void);
extern int func_L00_002D6998(struct Rac2Native_5f824a0e369ccf7b_src_record *);
extern float func_002A7940(void),func_00283CE0(int),func_002A7878(float,float),func_00283B98(float,float);
extern void func_L00_003A6538(void *);
extern void func_L00_002E6EF8(void (*)(void *),void *);
extern void func_L00_0032A1A8(char *,char *,char *,float);
extern void func_0029FCC0(char *,int,char *),func_L00_003A5FC0(void *,void *);
extern void func_00282D30(void *,void *,float),func_00282CC0(void *,void *,void *);
extern int func_00277F48(void *,int,void *,int,float);
extern void func_002A8E20(void *,void *),func_0032D758(void *,int,void *);
extern void func_00283410(void *,void *),func_00283678(void *,void *),func_00283738(void *,void *,void *);
extern void func_002AB668(void *,int,float),func_002ACDE8(void *,void *,void *);
extern char *func_L00_003A5DC0(void *,void *,void *,void *);

/* Control the two-stage blast and trace its individual fan rays. */
void func_L00_003A53E8(char *moby)
{
    char *state = *(char **)(moby + 0x68);
    char damage[0x30];
    float probe[4], side[4], forward[4], up[4], bias[4];
    float frame[3][4], orientation[3][4], matrix[4][4];
    float origin[4], rotatedBias[4], rotation[4], ray[4], start[4], end[4];
    char *hits[20]; int masks[20];
    int ready = 1, count, i;
    if (*(u8 *)(moby + 0x20) == 0) {
        *(u8 *)(moby + 0x20) = 1;
        *(int *)(state + 0x4C) = -1;
        *(short *)(state + 8) = 0;
        *(short *)(state + 10) = 0;
    }
    if (*(u8 *)(moby + 0x20) == 6 && func_00282978(state + 4)) {
        func_002E5CF8(2,0,moby);
        *(u8 *)(moby + 0x20) = 1;
    }
    if (*(u8 *)(moby + 0x42) == *(u8 *)(moby + 0x43) && (*(u8 *)(moby + 0x60) & 2))
        func_002A75E0(moby,1,0,2,0);
    if (D_0018C0B4 == 1)
        func_L00_002C42E0(29,1);
    func_002829D8(state);
    if (D_0018C0B4 == 29) {
        unsigned int color = 0x600FFF0F;
        if (*(float *)state > 0.0f && func_L00_002D4040(-1))
            color = 0x600000FF;
        func_00273318(moby,color,0,0x21,-1,4,1.3f,0.0f,90.0f);
    }
    if (D_0018B270)
        D_0018AA18 = (char *)D_0018B270;
    if (D_0018C0B4 == 29)
        ready = func_00282948(&D_0018C354) != 0;
    else
        D_0018C354 = 40;
    if (*(u8 *)(moby + 0x20) == 1 && !D_0018C0DC && *(float *)state == 0.0f &&
        D_0018B060 >= 23 && ready) {
        if ((D_00138320 & D_0018B050) && func_L00_002D3F30(-1,1)) {
            if (*(u8 *)(D_0018C0B0 + 0x43) == D_L00_00262570[D_00139582].animation ||
                D_0018C0BC || D_0018C30C) {
                *(short *)(state + 6) = (unsigned short)D_L00_001AF680;
                *(short *)(state + 8) = (unsigned short)D_L00_001AF688;
                *(short *)(state + 10) = (unsigned short)D_L00_001AF690;
                *(int *)(state + 0x48) = 1;
            } else {
                *(short *)(state + 6) = 2;
                *(short *)(state + 8) = (unsigned short)D_L00_001AF684;
                *(short *)(state + 10) = (unsigned short)D_L00_001AF68C;
                *(int *)(state + 0x48) = 0;
            }
            func_L00_002AF568();
            *(int *)(state + 0x4C) = func_L00_002D6998(D_L00_00294900);
            *(u8 *)(moby + 0x20) = 2;
            *(float *)(state + 0xC) = func_002A7940();
            func_002A7470(moby,2,0,0);
            *(float *)(state + 0x20) = 1.0f / func_00283CE0(*(short *)(state + 8));
            *(float *)(state + 0x24) = 1.0f / func_00283CE0(*(short *)(state + 10));
            *(float *)(state + 0x28) = func_002A7940();
            *(float *)(state + 0x2C) = func_002A7940();
            *(int *)(state + 0x40) = D_L00_001AF6B4;
            *(float *)(state + 0x44) = 1.0f / func_00283CE0(D_L00_001AF6B4);
        } else if (D_00138324 & D_0018B050) {
            func_002E5CF8(4,0,moby);
        }
        if (!((D_00138320 & D_0018B050) && func_L00_002D4040(-1) && D_0018C0D8) &&
            *(int *)(state + 0x4C) >= 0) {
            func_L00_002D6B70();
            *(int *)(state + 0x4C) = -1;
        }
    }
    if (*(short *)(state + 6) == 0) {
        func_00282978(state + 10);
        func_00282978(state + 8);
        func_00282948(state + 0x40);
        if (*(int *)(state + 8))
            func_L00_002E6EF8(func_L00_003A6538,moby);
    }
    if ((unsigned int)(*(u8 *)(moby + 0x20) - 2) >= 2 || !func_00282978(state + 6))
        return;
    if (D_0018AA18) {
        func_L00_0032A1A8(D_0018AA18,state + 0x10,(char *)D_0018A580,1.0f);
        *(VectorBits *)D_0018A550 = *(VectorBits *)D_0018A580;
    }
    if (*(u8 *)(moby + 0x20) == 2) {
        *(u8 *)(moby + 0x20) = 3;
        func_0029FCC0(moby,0,state + 0x10);
        func_L00_003A5FC0(moby,state + 0x10);
        *(VectorBits *)(state + 0x30) = *(VectorBits *)D_0018A580;
        func_L00_002E6EF8(func_L00_003A6538,moby);
        func_002E5CF8(0,0,moby);
        D_L00_001B8DE0.start = 0.06f;
        if (*(int *)(state + 0x48))
            D_L00_001B8DE0.start = 0.12f;
        D_L00_001B8DE0.nextTicks = 30;
        D_L00_001B8DE0.mode = 0;
        D_L00_001B8DE0.ticks = 30;
        D_L00_001B8DE0.next = D_L00_001B8DE0.start;
        return;
    }
    *(u8 *)(moby + 0x20) = 6;
    *(short *)(state + 4) = 28;
    *(short *)(damage + 0x1A) = *(short *)(moby + 0xAA);
    *(float *)(damage + 0x1C) = D_L00_00262570[D_00139582].power;
    *(int *)(damage + 0x14) = 0x10000;
    *(int *)(damage + 0x20) = 1;
    *(u8 *)(damage + 0x18) = 3;
    *(u8 *)(damage + 0x19) = 2;
    *(char **)(damage + 0x10) = moby;
    func_00282D30(probe,moby + 0xD0,-1.35f);
    func_00282CC0(probe,probe,moby + 0x10);
    func_00282D30(side,moby + 0xC0,0.275f);
    func_00282CC0(probe,probe,side);
    count = func_00277F48(probe,1,D_0018C0B0,0,1.5f);
    for (i = 0; i < count; i++) {
        char *hit = D_L00_001C3280[i];
        if (hit != D_0018C0B0) {
            func_00282D30(damage,moby + 0xD0,-1.5f);
            *(float *)(damage + 0xC) = 5627.9248046875f;
            func_002A8E20(hit,damage);
            func_0032D758(hit,26,moby);
        }
    }
    func_00283410(matrix,D_L00_001AF670);
    func_00283678(orientation,matrix);
    func_0029FCC0(moby,0,(char *)origin);
    if (D_0018C30C == 1) {
        func_00282D30(forward,moby + 0xD0,-1.0f);
        func_00282D30(up,moby + 0xC0,-1.0f);
        func_00282D30(bias,moby + 0xE0,0.1f);
        func_00283738(frame,moby + 0xC0,orientation);
    } else {
        *(VectorBits *)forward = *(VectorBits *)D_0018A550;
        *(VectorBits *)up = *(VectorBits *)D_0018A560;
        func_00282D30(bias,D_0018A570,-0.1f);
        func_00283738(frame,D_0018A550,orientation);
    }
    *(VectorBits *)(state + 0x30) = *(VectorBits *)forward;
    count = 0;
    for (i = 0; i < 20; i++) { hits[i] = 0; masks[i] = 0; }
    {
        float angle = 0.0f;
        for (i = 19; i >= 0; i--) {
            char *hit;
            float spread = func_002A7878(0.01f,0.3272492588f);
            func_002AB668(rotation,(int)up,spread);
            func_002ACDE8(ray,forward,rotation);
            func_002ACDE8(rotatedBias,bias,rotation);
            angle = func_00283B98(func_002A7878(1.0471977f * 0.5f,1.0471977f * 1.5f),angle);
            func_002AB668(rotation,(int)forward,angle);
            func_002ACDE8(ray,ray,rotation);
            func_002ACDE8(rotatedBias,rotatedBias,rotation);
            func_00282D30(ray,ray,32.0f);
            func_00282CC0(start,origin,rotatedBias);
            func_00282CC0(end,start,ray);
            hit = func_L00_003A5DC0(moby,start,end,damage);
            if (hit) {
                masks[count] = *(int *)(hit + 0x98);
                hits[count++] = hit;
                *(int *)(hit + 0x98) = 0;
            }
        }
    }
    for (i = 0; i < count; i++)
        *(int *)(hits[i] + 0x98) = masks[i];
    *(float *)state = 1.0f / D_L00_00262570[D_00139582].rate;
}
