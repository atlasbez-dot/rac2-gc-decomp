/* Bounded manual reconstruction; not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 1188/1180 bytes; us: 0/27 places; us2: absent from catalogue; pal: absent from catalogue.
 * Full controller and three-shot path preserves current helper interfaces, timer return banks
 * and resident identities. Raw resident globals produce different address sharing and register
 * allocation; retail 0xc0 frame agrees. Reopen with a typed resident player state and a matching
 * controller allocation witness.
 */
typedef int ShotWord128 __attribute__((mode(TI)));
typedef union { ShotWord128 word; float f[4]; } ShotVector;
typedef struct { char prefix[0x50]; float speed, cooldown; char suffix[0xE0-0x58]; } ShotTuning;
extern ShotTuning D_L00_00262570[] __attribute__((nosda));
extern char *D_0018C0B0 __attribute__((nosda));
extern int D_0018C0B4 __attribute__((nosda));
extern char *D_0018B270 __attribute__((nosda));
extern char *D_0018AA18 __attribute__((nosda));
extern int D_0018C354 __attribute__((nosda));
extern unsigned int D_00138320 __attribute__((nosda));
extern unsigned int D_00138324 __attribute__((nosda));
extern unsigned int D_0018B050 __attribute__((nosda));
extern unsigned char D_0018C0DC __attribute__((nosda));
extern int D_0018B060 __attribute__((nosda));
extern unsigned char D_00139580 __attribute__((nosda));
extern short D_0018C30C __attribute__((nosda));
extern int D_0018B320 __attribute__((nosda));
extern short D_0018A168 __attribute__((nosda));
extern ShotVector D_0018A580 __attribute__((nosda));
extern float D_L00_001B08F8 __attribute__((sda));
extern float D_L00_0025C64C __attribute__((nosda));
extern void func_L00_0037E000(void *);
extern void func_002A75E0(void *, int, int, int, int);
extern void func_L00_002C42E0(int, int);
extern void func_00273318(void *, unsigned int, int, int, int, int, float, float, float);
extern int func_00282948(void *);
extern int func_002829D8(void *);
extern int func_L00_002D3F30(int, int);
extern int func_L00_002D4040(int);
extern void func_0029FCC0(char *, int, char *);
extern int func_002E5CF8(int, int, char *);
extern void func_00282F20(void *, void *, float);
extern void func_L00_0037FA90(char *, char *, float, float, float);
extern void func_L00_0032A1A8(char *, char *, char *, float);
extern char *func_L00_003AA4C8(void *, void *, void *, void *);
extern void func_002AFFD8(char *, char *, int);
extern void func_002AB668(void *, int, float);
extern void func_002ACDE8(void *, void *, void *);

void func_L00_003F3D70(unsigned char *object) {
    char *state = *(char **)(object + 0x68);
    ShotVector aim, velocity, position, direction, rotation, rotated;
    char *spawn, *target;
    unsigned int color;
    int allowed = 1;
    float speed;
    if (object[0x20] == 0)
        object[0x20] = 1;
    func_L00_0037E000(D_0018C0B0);
    if (object[0x42] == object[0x43] && (object[0x60] & 2))
        func_002A75E0(object, 1, 0, 2, 0);
    *(float *)(object + 0x2C) = *(float *)(*(char **)(object + 0x24) + 0x24) * D_L00_001B08F8;
    D_L00_0025C64C = 0.1f;
    if (D_0018C0B4 == 1)
        func_L00_002C42E0(0x1D, 1);
    if (D_0018C0B4 == 0x1D) {
        color = 0x600FFF0F;
        if (*(float *)state > 0.0f && func_L00_002D4040(-1))
            color = 0x600000FF;
        func_00273318(object, color, 0, 0x27, -1, 4, 2.0f, 0.0f, 90.0f);
    }
    if (D_0018B270)
        D_0018AA18 = D_0018B270;
    if (D_0018C0B4 == 0x1D)
        allowed = func_00282948(&D_0018C354) != 0;
    else
        D_0018C354 = 0x28;
    if (func_002829D8(state) && !D_0018C0DC && D_0018B060 > 22 && allowed) {
        if ((D_00138320 & D_0018B050) && func_L00_002D3F30(-1, 1)) {
            func_0029FCC0((char *)object, 0, (char *)&aim);
            func_002E5CF8(0, 0, (char *)object);
            func_002A75E0(object, 2, 0, 2, 0);
            speed = D_L00_00262570[D_00139580].speed * 0.016666668f;
            if (D_0018C30C == 1) {
                func_00282F20(&velocity, object + 0xD0, -speed);
                position.word = aim.word;
            } else {
                func_00282F20(&velocity, &D_0018A580, speed);
                position.word = aim.word;
                if (D_0018B320)
                    func_L00_0037FA90((char *)&velocity, (char *)&position, speed, 32.0f, 0.6981318f);
            }
            target = 0;
            if (D_0018AA18) {
                func_L00_0032A1A8(D_0018AA18, (char *)&position, (char *)&velocity, speed);
                target = D_0018AA18;
            }
            spawn = func_L00_003AA4C8(&position, &velocity, object, target);
            if (spawn)
                *(unsigned char **)(spawn + 0xB8) = object;
            if (D_0018A168 == 0)
                func_002AFFD8((char *)object + 0x10, (char *)&direction, 1);
            else
                direction.word = *(ShotWord128 *)(D_0018C0B0 + 0xE0);
            func_002AB668(&rotation, (int)&direction, -0.122173056f);
            func_002ACDE8(&rotated, &velocity, &rotation);
            spawn = func_L00_003AA4C8(&position, &rotated, object, target);
            if (spawn)
                *(unsigned char **)(spawn + 0xB8) = object;
            func_002AB668(&rotation, (int)&direction, 0.122173056f);
            func_002ACDE8(&rotated, &velocity, &rotation);
            spawn = func_L00_003AA4C8(&position, &rotated, object, target);
            if (spawn)
                *(unsigned char **)(spawn + 0xB8) = object;
            *(float *)state = 1.0f / D_L00_00262570[D_00139580].cooldown;
        } else if ((D_00138324 & D_0018B050) && !func_L00_002D4040(-1) && !D_0018C0DC) {
            func_002E5CF8(0, 0, (char *)object);
        }
    }
}
