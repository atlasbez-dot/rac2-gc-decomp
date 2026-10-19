#include "include_asm.h"

/* ---- shared declarations ---- */

extern int func_002ED688(unsigned char *owner);
extern void func_L05_0037AEC0(char *object, int flag);
extern void func_L05_00379C68(int arg0, int value);
extern void func_L00_002E6DB8(void *, void *);
extern void func_L00_002E6CF0(void *a0, void *a1);
extern void func_L00_002E6EF8(void *, int);
extern void func_L15_00438238(void);
extern void func_L15_00438260(void);
extern void func_L15_00438518(void);

INCLUDE_ASM("asm/levels", func_L15_004328E8);

INCLUDE_ASM("asm/levels", func_L15_00432A60);

INCLUDE_ASM("asm/levels", func_L15_00434100);

INCLUDE_ASM("asm/levels", func_L15_00434610);

INCLUDE_ASM("asm/levels", func_L15_00434D28);

INCLUDE_ASM("asm/levels", func_L15_00434F90);

typedef struct GornEffectCamera {
    char pad00[0x140];
    float position[4];
} GornEffectCamera;
extern GornEffectCamera D_L15_001B9680;
extern unsigned char *D_L15_001FF4AC;
extern void func_0029FCC0(void *, int, void *);
extern float func_00283248(float, float);
extern float func_002A78D8(float, float);
extern float func_002A7878(float, float);
extern float func_00283B98(float, float);
extern void func_002AF000(void *, float, float, float);
extern unsigned char *func_002BDCE8(float, float, float, float,
                                   void *, int, void *, int, int);
extern int func_002A7820(int, int);
extern int func_00283CF0(float);
extern float func_00283CE0(int);



void func_L15_004351E0(char *object, int joint, float radius) {
    float initial[4], point[4], velocity[4];
    float heading, speed, tilt, yaw;
    unsigned char *particle;
    unsigned char *data;

    func_0029FCC0(object, joint, initial);
    heading = func_00283248(D_L15_001B9680.position[0] - *(float *)(object + 0x10),
                            D_L15_001B9680.position[1] - *(float *)(object + 0x14));
    point[0] = initial[0] + func_002A78D8(0, radius);
    point[1] = initial[1] + func_002A78D8(0, radius);
    point[2] = initial[2] + func_002A78D8(0, radius);
    speed = func_002A7878(radius * 0.008333333767950535f,
                          radius * 0.01666666753590107f);
    tilt = func_002A78D8(0, 1.396263599395752f);
    yaw = func_00283B98(heading, func_002A78D8(0, 1.5707964897155762f));
    func_002AF000(velocity, speed, yaw, tilt);
    particle = func_002BDCE8(0, 1.0f, 1.01f, radius * 210000.0f,
                            point, -1, velocity, 0x307F7F7F, 0);
    if (particle != 0) {
        particle[3] = 0x48;
        *(short *)(particle + 0xA) = func_002A7820(40, 70);
        particle[9] = func_00283CF0(4.0f) + 0x60;
        data = particle + 0x20;
        *(float *)(data + 0x1C) = func_00283CE0(func_002A7820(1, 10));
        *(int *)(data + 4) = 3;
        data[0xA] = 0x7F;
        data[0xB] = particle[0xA];
        particle[2] = *D_L15_001FF4AC;
    }
}

INCLUDE_ASM("asm/levels", func_L15_004353E8);

INCLUDE_ASM("asm/levels", func_L15_00435838);

INCLUDE_ASM("asm/levels", func_L15_00435E80);

void func_L15_00436090(char *a0) {
    char *v1 = *(char **)(a0 + 0x68);

    *(int *)(v1 + 0x270) = 1;
    *(int *)(v1 + 0x274) = 0x1E0;
    *(char *)(a0 + 0x23) = 0x20;
    *(char *)(a0 + 0x20) = 2;
    *(unsigned short *)(a0 + 0x34) |= 8;
    *(float *)(v1 + 0x180) = 450.0f;
    *(int *)(a0 + 0x98) = 0;
}

INCLUDE_ASM("asm/levels", func_L15_004360D8);


INCLUDE_ASM("asm/levels", func_L15_004363C8);

INCLUDE_ASM("asm/levels", func_L15_00436990);

void func_L15_00436BA8(char *a0) {
    char *s0 = a0;
    char *s1 = *(char **)(s0 + 0x68);
    char *s2 = (char *)func_002ED688((unsigned char *)a0);

    *(int *)(s2 + 0x148) = 100;
    func_L05_0037AEC0(s0, 1);
    *(float *)(s1 + 0x180) = 100.0f;
    *(unsigned char *)(s0 + 0x20) = 1;
    *(unsigned char *)(s0 + 0x30) = 0xFF;
    *(unsigned short *)(s0 + 0x32) = 0x1FF;
    *(unsigned short *)(s0 + 0x34) |= 0x100;
    *(float *)(s0 + 0x2C) = 0.20000000298023224f;
    *(float *)(s1 + 0x278) = 10.0f;
    *(int *)(s1 + 0x26C) = 0;
    *(int *)(s1 + 0x270) = 0;
    *(int *)(s1 + 0x274) = 0;
    *(int *)(s2 + 0x154) = (int)(s1 + 0x278);
    func_L05_00379C68((int)s0, 0xFFFF);
}

INCLUDE_ASM("asm/levels", func_L15_00436C68);

void func_L15_00437B18(void *a0) {
    func_L00_002E6DB8((void *)func_L15_00438238, a0);
    func_L00_002E6CF0((void *)func_L15_00438260, a0);
    func_L00_002E6EF8((void *)func_L15_00438518, a0);
}

INCLUDE_ASM("asm/levels", func_L15_00437B68);

INCLUDE_ASM("asm/levels", func_L15_00438260);

INCLUDE_ASM("asm/levels", func_L15_00438518);

INCLUDE_ASM("asm/levels", func_L15_00438B00);

INCLUDE_ASM("asm/levels", func_L15_004390A0);
