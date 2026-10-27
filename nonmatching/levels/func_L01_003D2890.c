/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 940/932 bytes; us: 0/1 placements; us2: 0/1 placements; pal: absent from catalogue.
 * The complete launch-point/target captures use qcopy and the real pool field clear uses qzero. The
 * fifth spawn input, both validation lists, timer widths and all 64-byte pool-record writes are
 * preserved. Two cursor/state live ranges and reload scheduling still differ.
 * Reopen with actual validation-list and pool/state lifetime evidence, preserving every record
 * field and real allocation return.
 * Original variants, retail context and allocator diagnostics remain private.
 * No exact-C, linked-build or runtime credit is claimed.
 */
#include "common.h"


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
            qcopy(&point, D_L01_001B264C + i * 128 + 0x30);
            qcopy(&target, D_L01_001B264C + i * 128 + 0x70);
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
            qzero((unsigned char *)POOL + 0x20);
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
