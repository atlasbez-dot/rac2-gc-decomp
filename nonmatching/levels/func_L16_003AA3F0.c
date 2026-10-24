/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 1616 / 1676 bytes; size equality is not a match.
 * us: 0/1 placements; 1616/1676 bytes.
 * us2: 0/1 placements; 1616/1676 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 1616 bytes versus1676; frame500 versus510, pointer induction and allocation differ.
 * Reopening condition: Qualify original pointer induction/local aggregate layout and remaining helper return contracts before another measured trial.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Manual reconstruction retained after measured nonmatching checks.
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   1616 bytes versus1676; frame500 versus510, pointer induction and allocation differ.
   Reopen: Qualify original pointer induction/local aggregate layout and remaining helper return contracts before another measured trial.
   This is an unqualified draft, not an exact match or native behavior proof.
*/
typedef unsigned char u8;
typedef unsigned int u32;
typedef int VectorWord __attribute__((mode(TI)));
typedef union { VectorWord q; float f[4]; } Vector;
extern int D_001A79F0 __attribute__((sda));
extern int D_L16_001AF884 __attribute__((sda)), D_L16_001AF888 __attribute__((sda));
extern float D_L16_001AF908 __attribute__((sda)), D_L16_001AF90C __attribute__((sda)), D_L16_001AF920 __attribute__((sda));
extern int D_L16_001AF914 __attribute__((sda)), D_L16_001AF918 __attribute__((sda));
extern int D_L16_001AF928 __attribute__((sda)), D_L16_001AF92C __attribute__((sda));
extern char *D_L16_001B2C0C __attribute__((sda));
extern float D_L16_001B9B00[4];
extern int func_002A7820(int,int);
extern float func_002A7878(float,float);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern void func_002A7A00(float *,float,float);
extern void func_00282C88(void *);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern float func_00282E80(void *,void *);
extern float func_002A7940(void);
extern void func_00283410(void *,void *);
extern void func_002830C0(void *,void *,void *);
extern int func_002A77E0(int);
extern void *func_002BAA28(void *,void *,void *,int,int,int,int,int,int);

void func_L16_003AA3F0(char *object)
{
    char *vars = *(char **)(object + 0x68);
    Vector positions[32], velocities[32], scratch, jitter;
    float transform[16];
    float spread;
    int i, j, selected;
    short lifetime;
    *(float *)(object + 0x1c) = 1.0f;
    lifetime = func_002A7820(D_L16_001AF884, D_L16_001AF888);
    *(short *)(vars + 0x12) = lifetime;
    *(int *)(vars + 0x620) = lifetime;
    if (D_001A79F0 == 0xd5 || D_001A79F0 == 16)
        spread = func_002A7878(40.0f, 45.0f);
    else spread = func_002A7878(4.0f, 8.0f);
    for (i = 0; i < 32; i++) {
        float height = (0.5f - func_00283CE0(i) / func_00283CE0(31)) * spread;
        if ((unsigned)(i - 3) < 26) {
            func_002A7A00(positions[i].f, 0.0f, D_L16_001AF908);
            if (D_001A79F0 == 16 || D_001A79F0 == 0xd5)
                func_002A7A00(velocities[i].f, 0.0f, 0.20000001788139343f);
            else func_002A7A00(velocities[i].f, 0.0f, D_L16_001AF90C * 0.01666666753590107f);
        } else {
            func_00282C88(&positions[i]);
            func_00282C88(&velocities[i]);
        }
        positions[i].f[3] = 1.0f;
        positions[i].f[1] += height;
    }
    for (i = 0; i < 32; i++) {
        if (i == 0 || i == 31) {
            *(VectorWord *)(vars + 0x20 + i * 16) = positions[i].q;
            *(VectorWord *)(vars + 0x220 + i * 16) = velocities[i].q;
        } else {
            func_00282CC0(&scratch, &positions[i-1], &positions[i]);
            func_00282CC0(&scratch, &scratch, &positions[i+1]);
            func_00282D30(vars + 0x20 + i * 16, &scratch, 0.333f);
            func_00282CC0(&scratch, &velocities[i-1], &velocities[i]);
            func_00282CC0(&scratch, &scratch, &velocities[i+1]);
            func_00282D30(vars + 0x220 + i * 16, &scratch, 0.333f);
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_001A79F0 == 0xd5 || D_001A79F0 == 16)
            func_002A7A00(scratch.f, 1.0f, 1.0f);
        else func_002A7A00(scratch.f, D_L16_001AF908, D_L16_001AF908);
        selected = func_00283CF0(func_002A7878((float)i * 6.0f, (float)(i + 1) * 6.0f)) + 4;
        vars[0x18 + i] = selected;
        *(VectorWord *)(vars + 0x420 + i * 16) = *(VectorWord *)(vars + 0x20 + selected * 16);
        *(VectorWord *)(vars + 0x520 + i * 16) = *(VectorWord *)(vars + 0x220 + selected * 16);
        for (j = 0; j < 3; j++) {
            func_002A7A00(jitter.f, 0.1f, 0.1f);
            if (D_001A79F0 == 0xd5 || D_001A79F0 == 16)
                func_002A7A00((float *)(vars + 0x560 + i * 16 + j * 64), 0.0f, 0.20000001788139343f);
            else func_002A7A00((float *)(vars + 0x560 + i * 16 + j * 64), 0.0f, D_L16_001AF90C * 0.01666666753590107f);
            func_00282CC0(vars + 0x460 + i * 16 + j * 64, vars + 0x420 + i * 16 + j * 64, &scratch);
            func_00282CC0(vars + 0x460 + i * 16 + j * 64, vars + 0x460 + i * 16 + j * 64, &jitter);
        }
    }
    if (func_00282E80(object + 0x10, D_L16_001B9B00) >= 4.0f) {
        char *definition = D_L16_001B2C0C + *(int *)vars * 128;
        *(int *)(vars + 0x658) = *(int *)(definition + 0x78);
        *(int *)(vars + 0x654) = *(int *)(definition + 0x74);
        *(float *)(vars + 0x650) = func_002A7940();
        func_00283410(transform, vars + 0x650);
        *(VectorWord *)(transform + 12) = *(VectorWord *)(object + 0x10);
        for (i = 0; i < 32; i += 8) {
            int color, duration;
            func_002830C0(&scratch, vars + 0x20 + i * 16, transform);
            jitter.q = *(VectorWord *)(vars + 0x220 + i * 16);
            jitter.f[3] = D_L16_001AF920;
            color = func_002A77E0(2) ? D_L16_001AF928 : D_L16_001AF92C;
            duration = func_002A77E0(10);
            func_002BAA28(&scratch, &jitter, &jitter, D_L16_001AF914, D_L16_001AF918, i >> 1, 15, duration + 20, color);
        }
        for (i = 0; i < 2; i++) {
            int duration;
            func_002830C0(&scratch, vars + 0x4e0 + i * 16, transform);
            jitter.q = *(VectorWord *)(vars + 0x5e0 + i * 16);
            jitter.f[3] = D_L16_001AF920;
            func_002A77E0(2);
            duration = func_002A77E0(10);
            func_002BAA28(&scratch, &jitter, &jitter, D_L16_001AF914, D_L16_001AF918, (u8)vars[0x18+i] >> 1, 15, duration + 20, D_L16_001AF92C);
        }
    }
}
