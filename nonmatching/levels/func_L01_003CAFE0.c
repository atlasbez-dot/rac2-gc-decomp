/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 1316/1372 bytes; us: 0/1 placements; us2: 0/1 placements; pal: 0/1 placements.
 * The full two-frame interpolation, 64-byte matrix and packet work remain, with real header-copy
 * helpers and unsigned 32-bit color shifts. Complete16-byte GP constants use G16/assemblerG16.
 * Retail uses both absolute and GP forms for the same real packet cursor; the current single
 * declaration and global-field bases do not recover those address/lifetime forms. The targeted
 * unsplit-address trial was negative.
 * Reopen with independent containing-object and real alias/address-use evidence; do not invent a
 * second identity, undersized extent or artificial reload.
 * Original variants, retail context and allocator diagnostics remain private.
 * No exact-C, linked-build or runtime credit is claimed.
 */
#include "common.h"


typedef unsigned int Quad __attribute__((mode(TI)));
extern unsigned char D_L01_001BD9C0[], D_L01_001BE0C0[];
extern unsigned char D_L01_00297B50[], D_L01_0026A050[], D_L01_001AC740[];
extern unsigned char D_L01_001A8EF0[], D_L01_001B0270[], D_L01_001B0240[];
extern float D_L01_001B94C0[4], D_L01_001B93C0[16];
extern unsigned char *D_L01_001B2004, *D_L01_001B2CC8 __attribute__((sda));
extern int D_L01_001B2054, D_L01_001B2088, D_L01_001B209C;
extern float D_L01_001B31D4, D_L01_001B31D8, D_L01_001B31DC;
extern float D_L01_001B31E0 __attribute__((sda));
extern float D_L01_001B0330 __attribute__((sda)), D_L01_001B0334 __attribute__((sda));
extern float D_L01_001B0338 __attribute__((sda)), D_L01_001B033C __attribute__((sda));
extern int D_L01_001B0340 __attribute__((sda)), D_L01_001B0344 __attribute__((sda)), D_L01_001B0348 __attribute__((sda));
extern int D_L01_001B034C __attribute__((sda)), D_L01_001B0350 __attribute__((sda)), D_L01_001B0354 __attribute__((sda));
extern int D_L01_001B0358 __attribute__((sda)), D_L01_001B0360 __attribute__((sda)), D_L01_001B0364 __attribute__((sda));
extern int D_L01_001B0368 __attribute__((sda));
extern unsigned char *D_L01_001B035C __attribute__((sda)), *D_L01_001B036C __attribute__((sda));
extern Quad D_L01_001B02E0 __attribute__((sda)), D_L01_001B02F0 __attribute__((sda));
extern unsigned char D_L01_001B0300[] __attribute__((sda));
extern int D_001A72D0;
extern unsigned short D_0010FFB0;
extern unsigned char D_0010FFC0[];
extern void func_0027AB40(void), func_00279D18(void);
extern void func_00282AB0(void *, void *, int), func_00282B50(void *, void *, int);
extern void func_002FC410(unsigned int, unsigned int);
extern void func_00283388(float *);
extern void func_00282D30(float *, float *, float);
extern void func_00283788(float *, float *, float *);
extern void func_L01_003042AC(unsigned char *, unsigned char *, unsigned char *, unsigned char *, unsigned char *, int, float);
#define CONTEXT_FLOAT(offset) (*(float *)(D_L01_001BD9C0 + (offset)))
#define CONTEXT_INT(offset) (*(int *)(D_L01_001BD9C0 + (offset)))
#define PACKET_LONG(ptr,offset) (*(u64 *)((ptr) + (offset)))
void func_L01_003CAFE0(void)
{
    float matrix[16] __attribute__((aligned(16)));
    unsigned char *packet, *entry0, *entry1;
    int frame;
    float fraction;
    D_L01_001B31D4 = CONTEXT_FLOAT(0x218);
    D_L01_001B31D8 = CONTEXT_FLOAT(0x21c);
    D_L01_001B31DC = CONTEXT_FLOAT(0x228);
    D_L01_001B31E0 = CONTEXT_FLOAT(0x22c);
    if (D_L01_001B2054 != 1) {
        CONTEXT_FLOAT(0x218) = D_L01_001B0330;
        CONTEXT_FLOAT(0x21c) = D_L01_001B0334;
        CONTEXT_FLOAT(0x228) = D_L01_001B0338;
        CONTEXT_FLOAT(0x22c) = D_L01_001B033C;
    }
    func_0027AB40();
    func_00279D18();
    qcopy(D_L01_001B2CC8, &D_L01_001B02E0);
    packet = D_L01_001B2CC8 + 0x10;
    D_L01_001B2CC8 = packet;
    func_00282AB0(packet, D_L01_00297B50, 0xa0);
    D_L01_001B2CC8 += 0xa0;
    PACKET_LONG(packet,0x20) = ((u64)D_L01_001B034C << 32) | 100;
    PACKET_LONG(packet,0x30) = (u64)((D_001A72D0 >> 8) | 0x18100000) | 0x580000000UL;
    PACKET_LONG(packet,0x40) = (u32)D_L01_001B0340 | ((u32)D_L01_001B0344 << 8) | ((u32)D_L01_001B0348 << 16);
    if (D_L01_001B2054 == 1)
        PACKET_LONG(packet,0x40) = (u32)CONTEXT_INT(0x230) | ((u32)CONTEXT_INT(0x234) << 8) | ((u32)CONTEXT_INT(0x238) << 16);
    PACKET_LONG(packet,0x50) = ((u64)((long)D_001A72D0 >> 8) << 32) | 0x1000000000000UL;
    PACKET_LONG(packet,0x90) = 0x5360a;
    if (D_L01_001B034C < 97) PACKET_LONG(packet,0x90) = 0x5370b;
    frame = D_L01_001B2088 / D_L01_001B0350;
    fraction = (float)D_L01_001B2088 / (float)D_L01_001B0350 - (float)frame;
    entry0 = D_L01_001BE0C0 + (D_L01_001B0354 + frame % D_L01_001B0358) * 16;
    entry1 = D_L01_001BE0C0 + (D_L01_001B0354 + (frame + 1) % D_L01_001B0358) * 16;
    PACKET_LONG(D_L01_001B035C,0) = 0x8000000000400UL;
    PACKET_LONG(D_L01_001B035C,8) = 0;
    func_L01_003042AC(D_L01_001B035C + 0x10,
        D_L01_001B2004 + *(unsigned short *)(entry0 + 8) * 16,
        D_L01_001B2004 + *(unsigned short *)(entry0 + 10) * 16,
        D_L01_001B2004 + *(unsigned short *)(entry1 + 8) * 16,
        D_L01_001B2004 + *(unsigned short *)(entry1 + 10) * 16, 4096, fraction);
    frame = D_L01_001B2088 / D_L01_001B0360;
    fraction = (float)D_L01_001B2088 / (float)D_L01_001B0360 - (float)frame;
    D_001A72D0 += 0x4000;
    entry0 = D_L01_001BE0C0 + (D_L01_001B0364 + frame % D_L01_001B0368) * 16;
    entry1 = D_L01_001BE0C0 + (D_L01_001B0364 + (frame + 1) % D_L01_001B0368) * 16;
    PACKET_LONG(D_L01_001B035C,0) = 0x8000000000400UL;
    PACKET_LONG(D_L01_001B035C,8) = 0;
    func_L01_003042AC(D_L01_001B036C,
        D_L01_001B2004 + *(unsigned short *)(entry0 + 8) * 16,
        D_L01_001B2004 + *(unsigned short *)(entry0 + 10) * 16,
        D_L01_001B2004 + *(unsigned short *)(entry1 + 8) * 16,
        D_L01_001B2004 + *(unsigned short *)(entry1 + 10) * 16, 4096, fraction);
    qcopy(D_L01_001B2CC8, &D_L01_001B02F0);
    *(unsigned char **)(D_L01_001B2CC8 + 4) = D_L01_001B035C;
    D_L01_001B2CC8 += 0x10;
    func_00282B50(D_L01_001B2CC8, D_L01_001B0300, 0x30);
    D_L01_001B2CC8 += 0x30;
    if (D_L01_001B209C != 6) {
        func_002FC410((unsigned int)D_0010FFC0, D_0010FFB0);
        D_L01_001B209C = 6;
    }
    packet = D_L01_001B2CC8;
    *(unsigned char **)(D_L01_0026A050 + 4) = D_L01_001AC740;
    func_00282B50(packet, D_L01_0026A050, 0x50);
    D_L01_001B2CC8 += 0x50;
    *(unsigned char **)(packet + 0x24) = D_L01_001B2CC8;
    *(unsigned char **)(packet + 0x34) = D_L01_001B2CC8;
    *(unsigned char **)(packet + 0x44) = D_L01_001B2CC8 + 0x60;
    func_00282B50(D_L01_001B2CC8, D_L01_001BD9C0, 0x60);
    D_L01_001B2CC8 += 0x60;
    func_00283388(matrix);
    func_00282D30(matrix + 12, D_L01_001B94C0, -1024.0f);
    matrix[15] = 1.0f;
    func_00283788(matrix, D_L01_001B93C0, matrix);
    func_00282B50(D_L01_001B2CC8, D_L01_001A8EF0, 0x20);
    *(unsigned char **)(D_L01_001B2CC8 + 4) = D_L01_001B2CC8 + 0x20;
    func_00282B50(D_L01_001B2CC8 + 0x20, matrix, 0x40);
    D_L01_001B2CC8 += 0x60;
    func_00282AB0(D_L01_001B2CC8, D_L01_001B0270, 0x20);
    D_L01_001B2CC8 += 0x20;
    func_00282AB0(D_L01_001B2CC8, D_L01_001B0240, 0x20);
    D_L01_001B2CC8 += 0x20;
}
