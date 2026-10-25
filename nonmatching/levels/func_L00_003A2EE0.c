/* Retained nonmatching C; measured 25 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses.
 * Final check.py coverage: us 0/27, us2 0/27, pal catalogue absent.
 * 3112/3188 bytes with the retained unsplit profile. Availability scoped to its real case is byte-neutral. A resident-base view with split addressing produced3008bytes and was discarded, not a match.
 * Reopen: Obtain independent field ownership and actual mixed GP/absolute state-base lowering evidence, plus scope/sound/light CFG constraints; preserve the failed resident-base alternative privately.
 * Shared EE transfer helpers are approved; their use is not matching evidence.
 * Earlier complete drafts and all trial sources/logs are preserved privately.
 */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
struct Rac2Native_5f824a0e369ccf7b_src_record { u8 b0,b1,b2,b3; u16 s4,s6,s8,s10,s12; u8 e,f; };
extern struct Rac2Native_5f824a0e369ccf7b_src_record D_L00_00294800[];
extern int D_0018B064 NOT_SDA,D_0018B320 NOT_SDA,D_0018B270 NOT_SDA,D_0018C0B4 NOT_SDA,D_0018C354 NOT_SDA;
extern char *D_0018C0B0 NOT_SDA,*D_0018AA18 NOT_SDA;
extern u8 D_0018C0DC NOT_SDA,D_0018C0D8 NOT_SDA,D_0013957F NOT_SDA;
extern short D_0018C30C NOT_SDA;
extern u16 D_0018CCD0 NOT_SDA;
extern unsigned int D_00138320 NOT_SDA,D_00138324 NOT_SDA,D_0018B050 NOT_SDA;
extern int D_L00_001AA0F8 __attribute__((sda));
extern unsigned int D_L00_001B19C8 __attribute__((sda));
extern float D_L00_001AF614 __attribute__((sda)),D_L00_001AF618 __attribute__((sda));
extern int D_L00_001AF61C __attribute__((sda));
extern float D_L00_001AF620 __attribute__((sda));
/* These separately accessed scalar settings do not establish a whole-record extent. */
extern float D_L00_001B15CC __attribute__((sda));
extern float D_L00_001B15D0 NOT_SDA;
extern float D_L00_001B15D4 __attribute__((sda));
extern int D_L00_001B15D8 NOT_SDA;
extern float D_L00_001BD370 NOT_SDA;
extern float D_L00_001B8DC0[4] NOT_SDA,D_L00_001B8FF0[4] NOT_SDA,D_0018A580[4] NOT_SDA;
extern char *D_L00_001BF218 NOT_SDA;
extern char D_00188660[];
typedef struct { char prefix[0x54]; float rate; char tail[0x88]; } WeaponEntry;
extern WeaponEntry D_L00_00262570[];
typedef struct { float radius,spread,power,reserved; float position[4]; } MuzzleLight;
extern MuzzleLight D_L00_001C6F40[];
extern void func_0026FF08(int,int,int,float,float,float);
extern void func_00291450(int),func_L00_00368F58(int);
extern void func_002A75E0(void *,int,int,int,int),func_002A7470(void *,int,int,int);
extern void func_00282F20(void *,void *,float),func_00282CC0(void *,void *,void *);
extern int func_002761F8(void *,void *,int,void *,void *);
extern int func_002AB1F0(u8 *),func_002ABB78(char *);
extern int func_L00_002D4040(int),func_L00_002D3F30(int,int);
extern void func_00273318(void *,unsigned int,void *,int,int,int,float,float,float);
extern float func_00283248(float,float),func_00283CE0(int);
extern int func_L00_00329E90(void *,int,void *);
extern char *func_L00_0032A088(int,int);
extern int *func_L00_0032A0B8(int,int);
extern int func_L00_00329FF0(int);
extern void func_L00_003A8508(char *),func_L00_002C42E0(int,int);
extern int func_00282948(void *),func_00282978(void *),func_002829D8(void *);
extern int func_002E5CF8(int,int,char *);
extern void func_002E59F8(int),func_L00_002AF568(void),func_L00_002D6B70(void);
extern int func_L00_002D6998(struct Rac2Native_5f824a0e369ccf7b_src_record *);
extern void func_L00_003A3B58(char *);
extern int func_00288E18(int,int),func_00291308(int,void *,unsigned int,float);
extern void func_0029FCC0(char *,int,char *);

/* Manage scope zoom, target confirmation, firing and the muzzle-light lifetime. */
void func_L00_003A2EE0(char *moby)
{
    char *state = *(char **)(moby + 0x68);
    float point[4],offset[4];
    int query[4],ready,handle;
    if (D_0018B064 == 3) {
        if (*(u8 *)(moby + 0x20) == 0)
            return;
        D_L00_001B15D0 = D_L00_001AF614;
        D_L00_001B15D4 = D_L00_001AF618;
        D_L00_001B15D8 = D_L00_001AF61C;
        D_L00_001B15CC = D_L00_001AF620;
        func_0026FF08(0,0,3,1.12434113f,0.005f,0.2f);
        if (*(int *)(state + 0x10) >= 0)
            func_00291450(*(int *)(state + 0x10));
        *(int *)(state + 0x10) = -1;
        D_L00_001AA0F8 = 0xE0;
        func_L00_00368F58(1);
        return;
    }
    if (D_0018C0B4 == 111) {
        if (*(u8 *)(moby + 0x20) == 4)
            return;
        *(u8 *)(moby + 0x20) = 4;
        if (*(int *)(state + 0x10) >= 0)
            func_00291450(*(int *)(state + 0x10));
        *(int *)(state + 0x10) = -1;
        D_L00_001B15D0 = D_L00_001AF614;
        D_L00_001B15D4 = D_L00_001AF618;
        D_L00_001B15D8 = D_L00_001AF61C;
        D_L00_001B15CC = D_L00_001AF620;
        func_0026FF08(0,0,3,1.12434113f,0.005f,0.2f);
        func_L00_00368F58(1);
        return;
    }
    if (*(u8 *)(moby + 0x20) == 4)
        *(u8 *)(moby + 0x20) = 1;
    if (*(u8 *)(moby + 0x42) == *(u8 *)(moby + 0x43) && (*(u8 *)(moby + 0x60) & 2))
        func_002A75E0(moby,1,0,2,0);
    if (D_0018B320 && *(u8 *)(moby + 0x20)) {
        if (D_L00_001B19C8 & 4) {
            *(int *)(state + 0x30) = 0;
            *(short *)(state + 0x2C) = 0;
            func_00282F20(point,D_L00_001B8FF0,128.0f);
            func_00282CC0(point,point,D_L00_001B8DC0);
            if (func_002761F8(D_L00_001B8DC0,point,0x10,D_0018C0B0,0) &&
                D_L00_001BF218 && *(u8 *)(D_L00_001BF218 + 0x31)) {
                char *hit = D_L00_001BF218;
                float *component = (float *)func_002AB1F0((u8 *)hit);
                char *model = *(char **)(hit + 0x24);
                if (func_002ABB78(hit) || (component && *component > 0.0f && model && *(short *)(model + 0x46) == 5)) {
                    *(char **)(state + 0x30) = hit;
                    *(short *)(state + 0x2C) = 1;
                }
            }
        }
        if (!D_0018C354) {
            if (*(short *)(state + 0x2C)) {
                (*(short *)(state + 0x2E))++;
                if (*(short *)(state + 0x2E) > 20)
                    *(short *)(state + 0x2E) = 0;
                if (*(float *)(state + 4) <= 0.0f && func_L00_002D4040(-1) && *(short *)(state + 0x2E) >= 11)
                    func_00273318(moby,0x400000FF,0,0x20,-1,4,1.5f,0.0f,90.0f);
            }
            {
                unsigned int color = 0x600FFF0F;
                if (*(float *)(state + 4) > 0.0f && func_L00_002D4040(-1))
                    color = 0x600000FF;
                func_00273318(moby,color,0,0x27,-1,4,2.0f,0.0f,90.0f);
            }
        }
    }
    switch (*(u8 *)(moby + 0x20)) {
    case 0: {
        float maximum;
        int id;
        *(short *)state = 0;
        *(float *)(state + 4) = 0.3666666746f;
        *(u8 *)(moby + 0x20) = 3;
        maximum = func_00283248(1.0f,D_L00_001BD370);
        D_L00_001AF61C = D_L00_001B15D8;
        D_L00_001AF618 = D_L00_001B15D4;
        D_L00_001AF614 = D_L00_001B15D0;
        D_L00_001AF620 = D_L00_001B15CC;
        maximum += maximum;
        *(float *)(state + 8) = maximum;
        *(float *)(state + 0xC) = maximum + (0.17453295f - maximum) * 0.25f;
        *(int *)(state + 0x14) = 0;
        *(int *)(state + 0x2C) = 0;
        *(int *)(state + 0x30) = 0;
        *(int *)(state + 0x24) = -1;
        *(int *)(state + 0x10) = -1;
        *(int *)(state + 0x20) = -1;
        id = func_L00_00329E90(moby,0,query);
        *(int *)(state + 0x18) = id;
        if (query[0] == 0) {
            char *record = func_L00_0032A088(*(short *)(moby + 0xAA),id);
            int *size = func_L00_0032A0B8(*(short *)(moby + 0xAA),id);
            *(char **)(state + 0x1C) = record;
            *size = func_L00_00329FF0((int)record + 0x2300) - (int)record;
        }
        if (*(int *)(state + 0x18) >= 0)
            func_L00_003A8508((char *)*(int *)(state + 0x18));
        break;
    }
    case 1: {
        float fov,amount;
        ready = 1;
        if (D_0018C0B4 == 1)
            func_L00_002C42E0(29,1);
        if (!D_0018B320) {
            D_0018C354 = 40;
        } else {
            ready = func_00282948(&D_0018C354) != 0;
            if (*(short *)state == 0)
                D_L00_001AA0F8 = 0;
            *(short *)state = 1;
        }
        if (D_0018B270)
            D_0018AA18 = (char *)D_0018B270;
        if (!D_0018B320) {
            handle = *(int *)(state + 0x20);
            if (handle != -1) {
                char *sound = D_00188660 + handle * 0x70;
                if (*(char **)(sound + 0x88) == moby && *(u8 *)(sound + 0x74))
                    func_002E59F8(handle);
            }
            *(int *)(state + 0x20) = -1;
            if (*(short *)state) {
                fov = *(float *)(state + 8);
                *(float *)(state + 0xC) = fov + (0.17453295f - fov) * 0.25f;
                func_0026FF08(0,0,3,fov,0.005f,0.2f);
                *(short *)state = 0;
                D_L00_001AA0F8 = 0xE0;
                func_L00_00368F58(1);
            }
        } else {
            int moving = 0;
            if ((D_00138320 & 8) && *(float *)(state + 0xC) > 0.17453295f) {
                char *sound = D_00188660 + *(int *)(state + 0x20) * 0x70;
                if (*(char **)(sound + 0x88) != moby || !*(u8 *)(sound + 0x74))
                    *(int *)(state + 0x20) = func_002E5CF8(2,4,moby);
                D_0018CCD0 = 0xFFFF;
                *(float *)(state + 0xC) -= 0.01f;
                moving = 1;
            } else if ((D_00138320 & 2) && *(float *)(state + 0xC) < *(float *)(state + 8)) {
                char *sound = D_00188660 + *(int *)(state + 0x20) * 0x70;
                if (*(char **)(sound + 0x88) != moby || !*(u8 *)(sound + 0x74))
                    *(int *)(state + 0x20) = func_002E5CF8(3,4,moby);
                D_0018CCD0 = 0xFFFF;
                *(float *)(state + 0xC) += 0.01f;
                moving = 1;
            }
            if (!moving) {
                handle = *(int *)(state + 0x20);
                if (handle != -1) {
                    char *sound = D_00188660 + handle * 0x70;
                    if (*(char **)(sound + 0x88) == moby && *(u8 *)(sound + 0x74))
                        func_002E59F8(handle);
                }
                *(int *)(state + 0x20) = -1;
            }
            if (*(float *)(state + 0xC) > *(float *)(state + 8))
                *(float *)(state + 0xC) = *(float *)(state + 8);
            else if (*(float *)(state + 0xC) < 0.17453295f)
                *(float *)(state + 0xC) = 0.17453295f;
            func_0026FF08(0,0,3,*(float *)(state + 0xC),0.02f,0.2f);
            func_L00_00368F58(0);
        }
        fov = *(float *)(state + 0xC);
        amount = (fov - 0.17453295f) / (*(float *)(state + 8) - 0.17453295f);
        D_L00_001B15D0 = (D_L00_001AF614 - 0.03f) * amount + 0.03f;
        D_L00_001B15CC = (D_L00_001AF620 - 0.010471977f) * amount + 0.010471977f;
        D_L00_001B15D4 = (D_L00_001AF618 - 0.4f) * amount + 0.4f;
        if (!D_0018C0DC && (D_00138324 & D_0018B050) && ready) {
            if (func_L00_002D3F30(-1,1)) {
                func_L00_002AF568();
                *(int *)(state + 0x24) = func_L00_002D6998(D_L00_00294800);
                *(short *)(state + 2) = 2;
                *(u8 *)(moby + 0x20) = 2;
                func_002A7470(moby,2,0,0);
            } else {
                func_002E5CF8(1,0,moby);
            }
        }
        if (!((D_00138320 & D_0018B050) && func_L00_002D4040(-1) && D_0018C0D8) && *(int *)(state + 0x24) >= 0) {
            func_L00_002D6B70();
            *(int *)(state + 0x24) = -1;
        }
        break;
    }
    case 2:
        if (D_0018B270)
            D_0018AA18 = (char *)D_0018B270;
        if (func_00282978(state + 2) || *(short *)state) {
            handle = *(int *)(state + 0x20);
            if (handle != -1) {
                char *sound = D_00188660 + handle * 0x70;
                if (*(char **)(sound + 0x88) == moby && *(u8 *)(sound + 0x74))
                    func_002E59F8(handle);
            }
            *(int *)(state + 0x20) = -1;
            func_002E5CF8(0,0,moby);
            func_L00_003A3B58(moby);
            *(float *)(state + 4) = 1.0f / D_L00_00262570[D_0013957F].rate;
            *(u8 *)(moby + 0x20) = 3;
            (*(int *)(state + 0x28))++;
            if (*(int *)(state + 0x28) == 5)
                func_00288E18(0x9F3,0x4A);
        }
        break;
    case 3:
        if (func_002829D8(state + 4))
            *(u8 *)(moby + 0x20) = 1;
        break;
    }
    if (*(int *)(state + 0x14)) {
        if (!func_00282948(state + 0x14)) {
            int index = *(int *)(state + 0x10);
            if (index == -1) {
                index = func_00291308(0,moby + 0x10,0x7F608060,15.0f);
                *(int *)(state + 0x10) = index;
            }
            if (index >= 0) {
                float value,total;
                MuzzleLight *light = &D_L00_001C6F40[index];
                func_0029FCC0(moby,0,(char *)point);
                if (D_0018C30C == 1)
                    func_00282F20(offset,moby + 0xD0,-1.5f);
                else
                    func_00282F20(offset,D_0018A580,1.5f);
                func_00282CC0(light->position,point,offset);
                light->position[3] = 15.0f;
                value = func_00283CE0(*(int *)(state + 0x14));
                total = func_00283CE0(30);
                light->spread = value / total;
                light->radius = (value / total) * 0.75f;
                light->power = light->radius;
            }
        } else {
            if (*(int *)(state + 0x10) >= 0)
                func_00291450(*(int *)(state + 0x10));
            *(int *)(state + 0x10) = -1;
        }
    }
}
