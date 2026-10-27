/* 0 of 1 places match - last line: 01_oozla: instruction at +0x1f4 differs
   (580 bytes, the same size as retail). Four-state handler of an object whose
   state block is at +0x68. State 0 starts a timer (func_002A7750 with 1, -1) and
   bumps the counter at D_L01_001AEC38; state 1 tests func_002A9640(self, 0x4010000)
   and an empty state word, decrements the counter and goes to state 2, then stores
   0xFF at +0xA8 and returns; state 2 scales the +0xD0 vector by -0.10000001f and,
   when +0x31 is set and both $gp floats (D_L01_001B2090, D_L01_001B208C) are below
   0.9f and D_L01_001B3468 < D_L01_001B15E0, calls func_002B0A68 with 0x3FF rather
   than 0xF, then func_L00_00326110(self, 0.0f, 4), func_002E5CF8(0, 0, self) and
   state 3; state 3 flags +0x34 bit 0, clears +0x31/+0x98, bumps the counter and
   writes 0x78 at [0x68]+4 when func_002B3868 succeeds, and drops the counter and
   calls func_0029F338 when func_00282948([0x68]+4) succeeds.
   Remaining difference: everything matches except the state-3 store block. Retail's
   order there is lhu +0x34, sb +0x31, ori, sw +0x98, load D_L01_001B3468, sh +0x34,
   sw [0x68]+4, addiu, sw D_L01_001B3468; this cc1 keeps the sh +0x34 before the
   counter load (four measured statement orders of that block all end 4 or 8 bytes
   off or permute the block). Next: find the statement order that lets the counter
   load sit between sw +0x98 and the sh. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

extern int D_L01_001AEC38 __attribute__((sda));
extern float D_L01_001B208C __attribute__((sda));
extern float D_L01_001B2090 __attribute__((sda));
extern int D_L01_001B15E0 __attribute__((sda));
extern int D_L01_001B3468 __attribute__((sda));
extern void func_002A7750(char *, int, int);
extern int func_002A9640(char *, int, int);
extern void func_00282D30(char *, char *, float);
extern void func_002B0A68(char *, int, void *, float, float, float, float, int);
extern void func_L00_00326110(char *, float, int);
extern int func_002E5CF8(int, int, char *);
extern int func_002B3868(char *);
extern int func_0029F338(char *);

void func_L01_0040EED0(char *a0)
{
    char *s0 = a0;
    char *s1 = *(char **)(a0 + 0x68);
    float buf[4];

    switch (*(u8 *)(s0 + 0x20)) {
    case 0:
        D_L01_001AEC38 = D_L01_001AEC38 + 1;
        func_002A7750(s0, 1, -1);
        return;
    case 1:
        if (func_002A9640(s0, 0x4010000, 0) != 0 && *(int *)s1 == 0) {
            D_L01_001AEC38 = D_L01_001AEC38 - 1;
            func_002A7750(s0, 2, -1);
        }
        *(u8 *)(s0 + 0xA8) = 0xFF;
        return;
    case 2:
        func_00282D30((char *)buf, s0 + 0xD0, -0.10000001f);
        if (*(u8 *)(s0 + 0x31) != 0 && D_L01_001B2090 < 0.9f &&
            D_L01_001B208C < 0.9f && D_L01_001B15E0 > D_L01_001B3468) {
            func_002B0A68(s0, 0x3FF, buf, 1.0f, 3.0f, 2.0f, 4.0f, 0xFF);
        } else {
            func_002B0A68(s0, 0xF, buf, 1.0f, 3.0f, 2.0f, 4.0f, 0xFF);
        }
        func_L00_00326110(s0, 0.0f, 4);
        func_002E5CF8(0, 0, s0);
        func_002A7750(s0, 3, -1);
        return;
    case 3:
        if (func_002B3868(s0) != 0) {
            *(u16 *)(s0 + 0x34) |= 1;
            *(u8 *)(s0 + 0x31) = 0;
            *(int *)(s0 + 0x98) = 0;
            D_L01_001B3468 = D_L01_001B3468 + 1;
            *(int *)(s1 + 4) = 0x78;
        }
        if (func_00282948(s1 + 4) != 0) {
            D_L01_001B3468 = D_L01_001B3468 - 1;
            func_0029F338(s0);
        }
        return;
    }
}

