/* Nonmatching: 300/292 bytes.
 * Profile: -O2 -G8 -ffunction-sections.
 * Final placement checks: US: 0/1; US2: 0/1; PAL: 0/1.
 * 300/292 bytes. The genuine two 144-byte packets, 64-byte matrix and 48-byte rotation produce frame 0x1d0; retail reserves 0x260, an extra unqualified 144-byte range. The UV global address also differs.
 * Reopen only with independent evidence qualifying the extra local range and complete UV object extent/addressing; no third packet or artificial padding is introduced.
 */
#include "common.h"
typedef unsigned int Quad5070 __attribute__((mode(TI)));
typedef struct DrawPacket5070 {
    Quad5070 position[4];
    u32 rgba[4];
    float uv[4][2];
    u64 state[4];
} DrawPacket5070;
extern int D_L07_001B0A80 __attribute__((sda));
extern int D_L07_001B0A84 __attribute__((nosda));
extern float D_L07_001B0A60[][2] __attribute__((sda));
extern float D_L07_0029F5B0[][4];
extern void func_00283658(void *, void *);
extern void func_002833F0(void *, void *);
extern int func_L01_0031BC68(int, int, float);
extern int func_00283D38(float, int, int);
extern void func_L02_002EF968(DrawPacket5070 *, int, int, void *, void *, int);
extern void func_L01_002E1510(DrawPacket5070 *, int, void *, int, void *);
/* Build the two packets demanded by the draw protocol. Retail also reserves an
 * unqualified extra 144-byte local range; it is not fabricated here as padding. */
void func_L07_003E5070(char *actor)
{
    DrawPacket5070 packets[2];
    float rotation[12] __attribute__((aligned(16)));
    float world[16] __attribute__((aligned(16)));
    float angle[4] __attribute__((aligned(16)));
    char *state = *(char **)(actor + 0x68);
    int colour;
    func_00283658(world, actor + 0xc0);
    qcopy(world + 12, actor + 0x10);
    world[15] = 1.0f;
    *(Quad5070 *)angle = 0;
    angle[2] = 0.19634955f;
    func_002833F0(rotation, angle);
    colour = func_L01_0031BC68(D_L07_001B0A80, D_L07_001B0A84, *(float *)(state + 0x1c));
    colour = func_00283D38(*(float *)(state + 0x18), colour & 0xffffff, colour);
    func_L02_002EF968(&packets[0], 5, colour, D_L07_001B0A60, D_L07_0029F5B0[0], 1);
    func_L02_002EF968(&packets[1], 5, colour, D_L07_001B0A60, D_L07_0029F5B0[4], 1);
    func_L01_002E1510(packets, 2, rotation, 32, world);
}
