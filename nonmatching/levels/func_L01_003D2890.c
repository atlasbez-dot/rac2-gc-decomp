/* Retained manual C reconstruction; not linked and not credited as matching.
 * Checked source: src/levels/01_oozla/L01_003D2890.c
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Retail US extent: 932 bytes.
 * us: 0/1 (exit 1, 940 compiled bytes); us2: 0/1 (exit 1, 940 compiled bytes); pal: catalogue absent (exit 1).
 * Residual: 940/932 bytes. The frame is 0x70. Two list cursors improve the frame but alter allocation and common-field reloads. The fifth argument to the spawn helper is preserved.
 * Reopen only with: A measured source type/lifetime model for the two validation lists and current state data; retain the complete pool-record writes and helper index ABI.
 * No complete linked build was run for this candidate.
 */
#include "include_asm.h"
typedef unsigned int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float value[4]; } LaunchVector;
typedef struct {
    float f0, f4, f8, f12, f16, f20;
    unsigned char f24, f25; short f26;
    unsigned char f28, f29, f30, f31;
    unsigned char pad32[16];
    short f48, f50; int f52, f56, f60;
} PoolRecord64;
extern void func_0026FEB8(const char *, ...);
extern void func_002A7750(unsigned char *, int, int);
extern void func_002A8598(int, int);
extern int func_002ACBC8(void *, int);
extern int func_00282948(int *);
extern PoolRecord64 *func_L00_002D70A0(int);
extern void func_L00_002D7140(unsigned char *);
extern void func_L01_003D25B8(unsigned char *, LaunchVector *, LaunchVector *, int, int);
extern unsigned char *D_L01_001B255C __attribute__((sda));
extern unsigned char *D_L01_001B264C;
extern char D_L01_001B0548[], D_L01_001B0580[];
extern int D_L01_00297BF0[];
extern unsigned char D_00189EA0[];
#define FIELD(o) (*(int *)(data + (o)))
#define HALF(o) (*(short *)(data + (o)))
#define POOL (*(PoolRecord64 **)(data + 0x34))
void func_L01_003D2890(unsigned char *self)
{
    unsigned char *data = *(unsigned char **)(self + 0x68);
    LaunchVector point, target;
    int i, command;
    int *firstIDs, *secondIDs;
    switch (self[0x20]) {
    case 0:
        POOL = 0;
        firstIDs = (int *)(data + 0x10);
        secondIDs = (int *)(data + 0x18);
        for (i = 0; i < 2; i++, firstIDs++, secondIDs++) {
            if (*firstIDs == -1) {
                func_0026FEB8(D_L01_001B0548, *(short *)(self + 0xaa), *(short *)(self + 0xb2), i);
                func_002A7750(self, 4, -1);
            }
            if (*secondIDs == -1) {
                func_0026FEB8(D_L01_001B0580, *(short *)(self + 0xaa), *(short *)(self + 0xb2), i);
                func_002A7750(self, 4, -1);
            }
        }
        if (self[0x20] == 0) func_002A7750(self, 1, -1);
        break;
    case 1:
        if (self[0xbc]) {
            D_L01_001B255C[FIELD(4) * 256 + 0xbc] = 1;
            FIELD(0x28) = 0;
            self[0xbc] = 0;
            FIELD(0x3c) = 0;
            FIELD(0x2c) = FIELD(0x24);
            func_002A7750(self, 2, -1);
        }
        break;
    case 2:
        if (func_00282948((int *)(data + 0x28))) {
            command = D_L01_00297BF0[FIELD(0x3c)];
            switch (command) {
            case 0: HALF(0x30) = 0; HALF(0x32) = 0; break;
            case 1: HALF(0x32) = 1; HALF(0x30) = 1; break;
            case 2: HALF(0x32) = 1; HALF(0x30) = 0; break;
            }
            FIELD(0x3c)++;
            i = ((int *)(data + 0x18))[HALF(0x30)];
            point = *(LaunchVector *)(D_L01_001B264C + i * 128 + 0x30);
            target = *(LaunchVector *)(D_L01_001B264C + i * 128 + 0x70);
            func_L01_003D25B8(self, &point, &target, HALF(0x32) + 0xa9e, HALF(0x30));
            FIELD(0x28) = FIELD(0);
            D_L01_001B255C[FIELD(8) * 256 + 0xbc] = 1;
        }
        if (FIELD(0x28) < FIELD(0) - 40)
            D_L01_001B255C[FIELD(8) * 256 + 0xbc] = 0;
        if (func_00282948((int *)(data + 0x2c))) func_002A7750(self, 3, -1);
        break;
    case 3:
        D_L01_001B255C[FIELD(4) * 256 + 0xbc] = 0;
        func_002A8598(self[0x21], 0);
        func_002A7750(self, 1, -1);
        break;
    }
    if (self[0x20] == 2 && FIELD(0x38) != -1 && func_002ACBC8(D_00189EA0, FIELD(0x38))) {
        if (POOL == 0) {
            POOL = func_L00_002D70A0(5);
            *(Quad *)((unsigned char *)POOL + 0x20) = 0;
            *(float *)((unsigned char *)POOL + 0x20) = -1.0f;
            POOL->f24 = 1;
            POOL->f4 = 6.0f;
            POOL->f26 = 1;
            POOL->f30 = 1;
        }
    } else if (POOL) {
        func_L00_002D7140((unsigned char *)POOL);
        POOL = 0;
    }
}
