/* Nonmatching reconstruction checked 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses.
 * Final check.py coverage: us 0/27, us2 0/27; no candidate.
 * Manual target-acquisition/fire/light update 2556/2708 default; unsplit addresses 2608/2708 retained. Current helpers use actual pointer returns and explicit light indices.
 * Remaining: Player/target state addresses, acquisition/control flow, GPR/FPR allocation and muzzle-light scheduling differ.
 * Reopen with measured target-state aggregates and an equivalent acquisition CFG; qualify remaining ASM APIs before port use.
 * Historical screening below is preserved, not treated as acceptance evidence.
 */

/* func_L00_003A48D0 - 2708 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003a48d0. Screened with tools/w10_screen.py: 56 call(s)
   [func_L00_003A41F0@003A4948, func_002829D8@003A4950,
   func_L00_002C42E0@003A4974, func_002A75E0@003A49A8,
   func_L00_002D4040@003A4A28, func_00273318@003A4A68,
   func_00282D30@003A4ACC, func_00282D30@003A4B04, func_00282CC0@003A4B18,
   func_L00_00324D18@003A4B40, func_002AB1F0@003A4B54,
   func_00282948@003A4BD4, func_00282E48@003A4BFC, func_002AB1F0@003A4C14,
   func_00282D30@003A4C40, func_00282CC0@003A4C50, func_00282C48@003A4C74,
   func_00273318@003A4CA4, func_00282948@003A4CC8, func_002AB1F0@003A4CE0,
   func_00282948@003A4D30, func_002A7470@003A4DE0,
   func_L00_002D3F30@003A4DEC, func_00282D30@003A4E14,
   func_00282CC0@003A4E24, func_00282D30@003A4E40, func_00282CC0@003A4E50,
   func_00277F48@003A4E6C, func_002AB1F0@003A4EA4, func_002ABB78@003A4F14,
   func_002E5CF8@003A4F64, func_L00_003A4480@003A4F74,
   func_L00_003A5370@003A4F7C, func_L00_002D2168@003A4FD4,
   func_L00_002AF568@003A4FE4, func_002A7470@003A4FF8,
   func_L00_002D6998@003A5004, func_002E5CF8@003A507C,
   func_L00_002D4040@003A50B0, func_L00_002D6B70@003A50D8,
   func_00283CE0@003A510C, func_00283CE0@003A512C, func_00283CE0@003A513C,
   func_00283CE0@003A5160, func_00283CE0@003A517C, func_00283CE0@003A5188,
   func_00283CE0@003A51A4, func_00282D30@003A51E0, func_0029FCC0@003A520C,
   func_00282CC0@003A5220, func_00282D30@003A5248, func_00282CC0@003A5258,
   func_L00_002FCF18@003A5288, func_00282978@003A52C8,
   func_00291450@003A52E8, func_00291450@003A5318]; data addresses
   materialised [0x190000, 0x190000, 0x190000, 0x3d8e0000, 0x60000000,
   0x600f0000, 0x190000, 0x3ea00000, 0x3e970000, 0x190000, 0x190000,
   0x190000, 0x190000, 0x1c0000, 0x3bda0000, 0x3dcc0000, 0x3f260000,
   0x3f660000, 0x3dcc0000, 0x190000, 0x1b0000, 0x190000, 0x140000,
   0x3e8c0000, 0x1c0000, 0x1c0000, 0x190000, 0x3f330000, 0x290000, 0x140000,
   0x1b0000, 0x140000, 0x1b0000, 0x140000, 0x190000, 0x3f4c0000, 0x3f4c0000,
   0x190000, 0x190000, 0x3e990000, 0x1c0000]; float constants [0x3fa00000,
   0x42b40000, 0x3f400000, 0x190000, 0xbf800000, 0x3f400000, 0x42960000,
   0xff0f0000, 0x42b40000, 0x190000, 0xbf800000, 0x3f800000, 0x1c0000,
   0x41200000, 0x260000, 0x3f800000, 0x3f800000, 0x3f800000, 0x3f000000,
   0xbf800000, 0x41000000, 0x41000000]; $gp-relative small data: yes
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [LQ/SQ 7A020000@0x01a8, LQ/SQ 7FA20000@0x01ac, LQ/SQ 78620000@0x0210,
   LQ/SQ 7FA20000@0x0214, LQ/SQ 78620000@0x0928, LQ/SQ 7E220000@0x092c,
   LQ/SQ 7A620000@0x09d8, LQ/SQ 7C820000@0x09dc]. Head: addiu $sp, $sp,
   -0xD0 ; sd $s4, 0x80($sp) ; sd $s0, 0x60($sp) ; daddu $s4, $a0, $zero ;
   sd $s1, 0x68($sp) ; sd $s2, 0x70($sp). Not matched in this wave: the
   128-bit copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
struct Rac2Native_5f824a0e369ccf7b_src_record { u8 b0,b1,b2,b3; u16 s4,s6,s8,s10,s12; u8 e,f; };
extern struct Rac2Native_5f824a0e369ccf7b_src_record D_L00_00294880[];
extern int D_0018C0B4 NOT_SDA,D_0018C0BC NOT_SDA,D_0018C354 NOT_SDA,D_0018B270 NOT_SDA,D_0018B060 NOT_SDA;
extern char *D_0018C0B0 NOT_SDA,*D_0018AA18 NOT_SDA;
extern u8 D_0018C0DC NOT_SDA,D_0018C0D8 NOT_SDA,D_00139583 NOT_SDA;
extern short D_0018C30C NOT_SDA;
extern float D_0018C2D8 NOT_SDA;
extern unsigned int D_00138320 NOT_SDA,D_00138324 NOT_SDA,D_0018B050 NOT_SDA;
extern int D_L00_001A8F00 NOT_SDA;
extern int D_L00_001B2864 __attribute__((sda));
extern char *D_L00_001BF218 NOT_SDA,*D_L00_001C3280[];
extern float D_00189EA0[4],D_0018A580[4],D_L00_001B8DC0[4];
typedef struct { char prefix[0x54]; float rate; char tail[0x88]; } WeaponEntry;
extern WeaponEntry D_L00_00262570[];
typedef struct { float radius,spread,power,reserved; float position[4]; } MuzzleLight;
extern MuzzleLight D_L00_001C6F40[];
extern void func_L00_003A41F0(void *);
extern int func_002829D8(void *),func_00282948(void *),func_00282978(void *);
extern void func_L00_002C42E0(int,int);
extern void func_002A75E0(void *,int,int,int,int),func_002A7470(void *,int,int,int);
extern int func_L00_002D4040(int),func_L00_002D3F30(int,int);
extern void func_00273318(void *,unsigned int,void *,int,int,int,float,float,float);
extern void func_00282D30(void *,void *,float),func_00282CC0(void *,void *,void *);
extern char *func_L00_00324D18(void *,void *,int,float,float,float,float,float);
extern int func_002AB1F0(u8 *),func_002ABB78(char *);
extern float func_00282E48(void *,void *),func_00282C48(float),func_00283CE0(int);
extern int func_002E5CF8(int,int,char *);
extern int func_00277F48(void *,int,void *,int,float);
extern void func_L00_003A4480(void *),func_L00_003A5370(int);
extern void func_L00_002D2168(int,int,float),func_L00_002AF568(void),func_L00_002D6B70(void);
extern int func_L00_002D6998(struct Rac2Native_5f824a0e369ccf7b_src_record *);
extern void func_0029FCC0(char *,int,char *);
extern int func_L00_002FCF18(void *,float,float,float,float,float);
extern void func_00291450(int);

/* Acquire a stable target, fire the weapon and update its short muzzle light. */
void func_L00_003A48D0(char *moby)
{
    char *state = *(char **)(moby + 0x68);
    float direction[4], playerPoint[4], targetPoint[4], muzzle[4], offset[4], lift[4];
    char *candidate, *locked;
    float horizontal,vertical;
    int ready = 1;
    if (*(u8 *)(moby + 0x20) == 0) {
        *(u8 *)(moby + 0x20) = 1;
        *(short *)(state + 0x1C) = -1;
        *(int *)(state + 0x24) = 5;
        *(int *)(state + 0x2C) = -1;
        *(short *)(state + 0x1E) = 0;
        *(int *)(state + 0x10) = 0;
        *(int *)(state + 0x20) = 0;
        *(int *)(state + 0x28) = 0;
    }
    func_L00_003A41F0(moby);
    func_002829D8(state);
    if (D_0018C0B4 == 1)
        func_L00_002C42E0(29,1);
    if (*(u8 *)(moby + 0x42) == *(u8 *)(moby + 0x43) && (*(u8 *)(moby + 0x60) & 2))
        func_002A75E0(moby,1,0,2,0);
    if (D_0018B270)
        D_0018AA18 = (char *)D_0018B270;
    if (D_0018C0B4 == 29 && (*(u16 *)(D_0018C0B0 + 0x34) & 1)) {
        unsigned int color = 0x600FFF0F;
        if (!*(int *)(state + 0x28)) {
            *(int *)(state + 0x10) = 0;
            *(int *)(state + 0x24) = 5;
        }
        *(int *)(state + 0x28) = 1;
        horizontal = vertical = 0.06981317699f;
        if (*(float *)state > 0.0f && func_L00_002D4040(-1))
            color = 0x600000FF;
        func_00273318(moby,color,0,0x27,-1,4,1.25f,0.0f,90.0f);
        *(VectorBits *)direction = *(VectorBits *)D_0018A580;
    } else {
        *(int *)(state + 0x28) = 0;
        horizontal = 0.3141593039f;
        vertical = 0.2967059910f;
        if (D_0018C30C == 0)
            *(VectorBits *)direction = *(VectorBits *)D_0018A580;
        else
            func_00282D30(direction,moby + 0xD0,-1.0f);
    }
    func_00282D30(playerPoint,D_0018C0B0 + 0xE0,0.75f);
    func_00282CC0(playerPoint,D_00189EA0,playerPoint);
    candidate = func_L00_00324D18(playerPoint,direction,1,horizontal,vertical,75.0f,horizontal,horizontal);
    locked = *(char **)(state + 0x10);
    if (!locked) {
        if (candidate == *(char **)(state + 0x20) && func_00282948(state + 0x24)) {
            float *component;
            *(char **)(state + 0x10) = candidate;
            *(int *)(state + 0x14) = 5;
            component = (float *)func_002AB1F0((u8 *)candidate);
            *(float *)(state + 0x18) = component ? *(float *)((char *)component + 0x10) : 0.1f;
        } else if (candidate != *(char **)(state + 0x20)) {
            *(int *)(state + 0x24) = 5;
        }
    } else {
        float *component = (float *)func_002AB1F0((u8 *)locked);
        if (*(u8 *)(locked + 0x20) == 0xFE || *(u8 *)(locked + 0x20) == 0xFD ||
            (component && *component <= 0.0f) || !*(u8 *)(locked + 0x31) || D_0018C30C) {
            *(int *)(state + 0x10) = 0;
            *(int *)(state + 0x24) = 5;
        } else if (candidate == locked) {
            float distance = func_00282E48(D_L00_001B8DC0,locked + 0x10);
            *(int *)(state + 0x14) = 5;
            component = (float *)func_002AB1F0((u8 *)candidate);
            *(float *)(state + 0x18) = component ? *(float *)((char *)component + 0x10) : 0.1f;
            func_00282D30(targetPoint,candidate + 0xE0,*(float *)(state + 0x18));
            func_00282CC0(targetPoint,candidate + 0x10,targetPoint);
            func_00273318(moby,0xFF0FFF0F,targetPoint,0x26,-1,4,
                          func_00282C48(0.9f - distance * 0.006666667f * 0.65f),0.0f,90.0f);
            D_0018AA18 = candidate;
        } else if (func_00282948(state + 0x14)) {
            *(int *)(state + 0x10) = 0;
            *(int *)(state + 0x24) = 5;
        }
    }
    *(char **)(state + 0x20) = candidate;
    locked = *(char **)(state + 0x10);
    if (D_0018C0B4 == 29)
        ready = func_00282948(&D_0018C354) != 0;
    else
        D_0018C354 = 40;
    if (D_L00_001A8F00 != 2 && *(float *)state == 0.0f && !D_0018C0DC &&
        *(u8 *)(moby + 0x42) <= 1 && (D_00138320 & D_0018B050) && D_0018B060 >= 23 && ready) {
        if (*(u8 *)(moby + 0x43) == 0)
            func_002A7470(moby,1,0,4);
        if (func_L00_002D3F30(-1,1)) {
            D_L00_001B2864 = 1;
            if (!locked) {
                int count,i;
                func_00282D30(muzzle,moby + 0xD0,-1.0f);
                func_00282CC0(muzzle,muzzle,moby + 0x10);
                func_00282D30(offset,moby + 0xC0,0.275f);
                func_00282CC0(muzzle,muzzle,offset);
                count = func_00277F48(muzzle,1,D_0018C0B0,0,1.0f);
                for (i = 0; i < count; i++) {
                    char *hit = D_L00_001C3280[i];
                    float *component = (float *)func_002AB1F0((u8 *)hit);
                    char *model;
                    if (!*(u8 *)(hit + 0x31) || *(short *)(hit + 0x32) <= 0 ||
                        *(u8 *)(hit + 0x20) == 0xFE || *(u8 *)(hit + 0x20) == 0xFD ||
                        *(short *)(hit + 0xAA) == 0xC87 || *(short *)(hit + 0xAA) == 0xECC || !component)
                        continue;
                    if (*component <= 0.0f && !func_002ABB78(hit))
                        continue;
                    model = *(char **)(hit + 0x24);
                    if (!model || *(short *)(model + 0x46) != 5) {
                        *(char **)(state + 0x10) = D_L00_001BF218;
                        break;
                    }
                }
            }
            func_002E5CF8(0,0,moby);
            *(short *)(state + 0x1E) = 15;
            func_L00_003A4480(moby);
            func_L00_003A5370((int)moby);
            if (!D_0018C0BC || (D_0018C0B4 == 2 && D_0018C2D8 < 0.7f))
                func_L00_002D2168(0x36,1,10.0f);
            else
                func_L00_002AF568();
            func_002A7470(moby,2,0,0);
            *(int *)(state + 0x2C) = func_L00_002D6998(D_L00_00294880);
            *(float *)state = 1.0f / D_L00_00262570[D_00139583].rate;
        } else if ((D_00138324 & D_0018B050) || D_L00_001B2864 == 1) {
            func_002E5CF8(1,0,moby);
            D_L00_001B2864 = 0;
        }
        if (!((D_00138320 & D_0018B050) && func_L00_002D4040(-1) && D_0018C0D8) && *(int *)(state + 0x2C) >= 0) {
            func_L00_002D6B70();
            *(int *)(state + 0x2C) = -1;
        }
    }
    if (*(u8 *)(moby + 0x42) != 2 && *(short *)(state + 0x1E) > 0) {
        float reciprocal,alpha,width,power;
        int frames;
        if (*(short *)(state + 0x1E) < 13) {
            reciprocal = 1.0f / func_00283CE0(12);
            frames = *(short *)(state + 0x1E);
        } else {
            reciprocal = 1.0f / func_00283CE0(3);
            frames = 15 - *(short *)(state + 0x1E);
        }
        alpha = func_00283CE0(frames) * reciprocal;
        width = func_00283CE0(frames) * reciprocal * 0.8f;
        power = func_00283CE0(frames) * reciprocal * 0.5f;
        if (D_0018C30C == 0)
            *(VectorBits *)offset = *(VectorBits *)D_0018A580;
        else
            func_00282D30(offset,moby + 0xD0,-1.0f);
        func_0029FCC0(moby,0,(char *)muzzle);
        func_00282CC0(muzzle,muzzle,offset);
        func_00282D30(lift,D_0018C0B0 + 0xE0,0.3f);
        func_00282CC0(muzzle,muzzle,lift);
        if (*(short *)(state + 0x1C) == -1) {
            *(short *)(state + 0x1C) = func_L00_002FCF18(muzzle,8.0f,0.0f,alpha,width,power);
        } else {
            MuzzleLight *light = &D_L00_001C6F40[*(short *)(state + 0x1C)];
            *(VectorBits *)light->position = *(VectorBits *)muzzle;
            light->power = power;
            light->position[3] = 8.0f;
            light->radius = alpha;
            light->spread = width;
        }
        func_00282978(state + 0x1E);
    } else if (*(short *)(state + 0x1C) != -1) {
        func_00291450(*(short *)(state + 0x1C));
        *(short *)(state + 0x1C) = -1;
        *(short *)(state + 0x1E) = 0;
    }
    if (*(u8 *)(moby + 0x43) == 2) {
        if (*(short *)(state + 0x1C) != -1)
            func_00291450(*(short *)(state + 0x1C));
        *(short *)(state + 0x1C) = -1;
        *(short *)(state + 0x1E) = 0;
    }
}
