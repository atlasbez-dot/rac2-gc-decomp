/* Bounded manual reconstruction; not linked.
 * Profile: -O2 -G8 -ffunction-sections.
 * 1036/1060 bytes; us: 0/27 places; us2: 0/27 places; pal: absent from catalogue.
 * Twenty-byte query configuration and all five float/eight GPR query inputs are preserved;
 * current source interfaces are used for the timer and record helpers. Pointer lifetimes,
 * SDA/absolute uses and allocation differ, with the retail 0xa0 frame. Reopen with a typed
 * player/query layout and a matching controller witness.
 */
typedef int AimWord128 __attribute__((mode(TI)));
typedef union { AimWord128 word; float f[4]; } AimVector;
typedef struct { unsigned int words[5]; } AimQueryConfig;
typedef struct { char prefix[0x54]; float cooldown; char suffix[0xE0-0x58]; } AimTuning;
struct Rac2Native_5f824a0e369ccf7b_src_record {
    unsigned char b0,b1,b2,b3;
    unsigned short s4,s6,s8,s10,s12;
    unsigned char e,f;
};
extern AimQueryConfig D_L00_001B0810 __attribute__((nosda));
extern AimTuning D_L00_00262570[] __attribute__((nosda));
extern struct Rac2Native_5f824a0e369ccf7b_src_record D_L00_0029AE70[] __attribute__((nosda));
extern unsigned char *D_0018B270 __attribute__((nosda));
extern int D_0018C0B4 __attribute__((nosda));
extern int D_0018C354 __attribute__((nosda));
extern int D_00189FF8 __attribute__((nosda));
extern unsigned char D_0018C0DC __attribute__((nosda));
extern unsigned char D_0018C0D8 __attribute__((nosda));
extern int D_0018B060 __attribute__((nosda));
extern unsigned int D_00138320 __attribute__((nosda));
extern unsigned int D_00138324 __attribute__((nosda));
extern unsigned int D_0018B050 __attribute__((nosda));
extern unsigned char D_00139592 __attribute__((nosda));
extern AimVector D_0018A580 __attribute__((nosda));
extern float D_L00_001B0800 __attribute__((sda));
extern float D_L00_001B0804 __attribute__((sda));
extern float D_L00_001B0808 __attribute__((sda));
extern float D_L00_001B080C __attribute__((sda));
extern int D_L00_001B2BB0 __attribute__((sda));
extern void func_0029FCC0(char *, int, char *);
extern void func_002A75E0(void *, int, int, int, int);
extern int func_002AB1F0(unsigned char *);
extern int func_00282948(void *);
extern unsigned char *func_002AF580(void *, void *, void *, int, int, int, int, AimQueryConfig *, float, float, float, float, float);
extern void func_002FDF40(void *, void *, void *, int, float, float, float, float);
extern int func_002FE5A0(void *, void *, void *, void *, void *, int, int, float);
extern void func_L00_002AF7D0(void);
extern int func_L00_002D3F30(int, int);
extern void func_L00_002AF568(void);
extern int func_L00_002D6998(struct Rac2Native_5f824a0e369ccf7b_src_record *);
extern int func_002E5CF8(int, int, char *);
extern char *func_L00_003EED10(int, char *, char *);
extern int func_L00_002D4040(int);
extern void func_L00_002D6B70(void);
extern int func_002829D8(void *);
extern void func_L00_003EE8E8(void *);
extern void func_L00_002E6EF8(void (*)(void *), void *);

void func_L00_003EE4C0(unsigned char *object) {
    unsigned char *state = *(unsigned char **)(object + 0x68);
    unsigned char *target = 0;
    char *info;
    AimVector position, scratch, direction;
    AimQueryConfig config;
    int allowed = 1;
    func_0029FCC0((char *)object, 0, (char *)&position);
    if (object[0x42] == object[0x43] && (object[0x60] & 2))
        func_002A75E0(object, 1, 0, 2, 0);
    if (D_0018B270 && D_0018B270[0x20] != 0xFE && D_0018B270[0x20] != 0xFD) {
        info = (char *)func_002AB1F0(D_0018B270);
        if (info && *(float *)info > 0.0f)
            target = D_0018B270;
    }
    if (D_0018C0B4 == 0x1D || D_0018C0B4 == 1) {
        allowed = func_00282948(&D_0018C354) != 0;
    } else {
        D_0018C354 = 0x28;
        if (!target) {
            config = D_L00_001B0810;
            target = func_002AF580(&position, &D_0018A580, &scratch, 0, 0, 0, 0, &config,
                                  0.392699093f, 0.785398185f, 11.1f, 0.0f, 0.0f);
        }
    }
    func_002FDF40(&config, &position, target, 0, D_L00_001B0804, D_L00_001B0800,
                   D_L00_001B080C * 0.016666668f, D_L00_001B0808 * 0.00027777778f);
    *(int *)(state + 0x24) = func_002FE5A0(&position, &config, state, state + 0x10, object, 0, 0,
                                          D_L00_001B0808 * 0.00027777778f);
    if (object[0x20] == 0) {
        object[0x20] = 1;
        *(int *)(state + 0x2C) = -1;
        *(float *)(state + 0x20) = 0.0f;
    } else if (object[0x20] != 1) {
        goto finish;
    }
    if (D_00189FF8 >= 21)
        func_L00_002AF7D0();
    if (*(float *)(state + 0x20) == 0.0f && !D_0018C0DC && (D_00138320 & D_0018B050) && allowed && D_0018B060 >= 23) {
        if (func_L00_002D3F30(-1, 1)) {
            D_L00_001B2BB0 = 1;
            func_L00_002AF568();
            *(int *)(state + 0x2C) = func_L00_002D6998(D_L00_0029AE70);
            func_002A75E0(object, 2, 0, 2, 0);
            func_L00_003EED10((int)object, (char *)&position, (char *)&config);
            func_002E5CF8(0, 0, (char *)object);
            *(float *)(state + 0x20) = 1.0f / D_L00_00262570[D_00139592].cooldown;
        } else if ((D_00138324 & D_0018B050) || D_L00_001B2BB0 == 1) {
            func_002E5CF8(1, 0, (char *)object);
            D_L00_001B2BB0 = 0;
        }
        if (!(D_00138320 & D_0018B050) || !func_L00_002D4040(-1) || !D_0018C0D8) {
            if (*(int *)(state + 0x2C) >= 0) {
                func_L00_002D6B70();
                *(int *)(state + 0x2C) = -1;
            }
        }
        object[0x20] = 1;
    }
finish:
    func_002829D8(state + 0x20);
    func_L00_002E6EF8(func_L00_003EE8E8, object);
}
