/* Bounded manual reconstruction; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * 1180/1180 bytes; us: 0/27 places; us2: 0/27 places; pal: absent from catalogue.
 * Full burst sequence preserves 9/10/50 emission loops and six-color copies. Four emitter APIs
 * were checked in retail: five/four/eight/eight GPR inputs, respectively, with 0/0/2/1 float
 * inputs and pointer results. Frame0xf0 differs from retail 0x110 and allocation/scheduling
 * remains different. Reopen with a matching array-copy/emitter lifetime witness.
 */
typedef int BurstWord128 __attribute__((mode(TI)));
typedef union { BurstWord128 word; float f[4]; } BurstVector;
typedef struct { unsigned int values[6]; } BurstColors;
extern BurstVector D_L00_001B8DC0 __attribute__((nosda));
extern BurstColors D_L00_001B0840 __attribute__((nosda));
extern BurstColors D_L00_001B0858 __attribute__((nosda));
extern unsigned char D_L00_0029AEF0[] __attribute__((nosda));
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DF0(void *);
extern float func_002A7878(float, float);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282FB8(void *, void *, float);
extern void func_00283098(void *, void *, void *);
extern int func_002A7820(int, int);
extern char *func_00308600(void *, void *, int, int, int);
extern float func_002A7940(void);
extern void func_002AF000(float *, float, float, float);
extern void func_00282C88(BurstWord128 *);
extern int func_002A77E0(int);
extern char *func_002BBCB0(void *, void *, unsigned int, unsigned int, int, int, int, int, float, float);
extern char *func_00312B70(void *, void *, int, int);
extern int func_002AAFA0(unsigned int, int);
extern char *func_002BCB00(void *, void *, int, int, int, int, int, int, float);

void func_L00_003EF560(char *object, BurstVector *position) {
    BurstVector delta, velocity, random;
    BurstColors colorsA, colorsB;
    float distance, pitch, yaw, speed;
    int i, a, b, lifetimeA, lifetimeB;
    int colorA, colorB;
    func_00282CF0(&delta, &D_L00_001B8DC0, position);
    distance = func_00282DF0(&delta);
    random.word = 0;
    random.f[0] = func_002A7878(-1.0f, 1.0f);
    random.f[1] = func_002A7878(-1.0f, 1.0f);
    random.f[2] = func_002A7878(-1.0f, 1.0f);
    delta.f[2] += distance * 0.5f;
    velocity.word = random.word;
    func_00282F20(&velocity, &velocity, distance * 0.0033333336468786f);
    func_00282F20(&delta, &delta, (distance + distance) * 0.016666668f);
    func_00282CC0(&velocity, &velocity, &delta);
    func_00282FB8(&velocity, &velocity, 0.1666666716337204f);
    func_00283098(&velocity, &velocity, object + 0xC0);
    lifetimeA = func_002A7820(60, 90);
    func_00308600(position, &velocity, lifetimeA, 0, 0);
    i = 8;
    do {
        i--;
        pitch = func_002A7878(0.4363323450088501f, 0.7853982448577881f);
        yaw = func_002A7940();
        speed = func_002A7878(13.0f, 20.0f);
        func_002AF000(random.f, speed * 0.016666668f, yaw, pitch);
        func_00283098(&random, &random, object + 0xC0);
        lifetimeA = func_002A7820(60, 90);
        func_00308600(position, &random, lifetimeA, 1, 0);
    } while (i >= 0);
    func_00282C88(&velocity.word);
    i = 9;
    do {
        i--;
        speed = func_002A7878(8.0f, 10.0f);
        colorsA = D_L00_001B0840;
        colorsB = D_L00_001B0858;
        a = func_002A77E0(6);
        b = func_002A77E0(6);
        lifetimeA = func_002A7820(20, 40);
        lifetimeB = func_002A7820(50, 70);
        func_002BBCB0(position, &velocity, colorsA.values[a], colorsB.values[b], lifetimeA, lifetimeB, 0, 0,
                     600000.0f, speed * 0.016666668f * 1.5f);
    } while (i >= 0);
    *(float *)(D_L00_0029AEF0 + 0x20) = 40.0f;
    *(float *)(D_L00_0029AEF0 + 0x24) = 40.0f;
    *(float *)(D_L00_0029AEF0 + 0x28) = 40.0f;
    func_00312B70(D_L00_0029AEF0, position, 0, 0);
    i = 49;
    do {
        i--;
        pitch = func_002A7878(0.13962635397911072f, 0.6108652949333191f);
        yaw = func_002A7940();
        speed = func_002A7878(16.0f, 30.0f);
        func_002AF000(random.f, speed * 0.016666668f, yaw, pitch);
        colorA = func_002AAFA0(0x4F007FFF, 0);
        colorB = func_002AAFA0(0x1F00007F, 0);
        func_00283098(&random, &random, object + 0xC0);
        lifetimeA = func_002A7820(60, 120);
        func_002BCB00(position, &random, colorA, colorB, lifetimeA - 10, 1, -1, -1, 40000.0f);
    } while (i >= 0);
}
