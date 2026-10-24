/* Signature/interface follow-up, 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * USA v1.01: 1140/1136 bytes, 0/1 carrying placements.
 * USA v2.00: 1140/1136 bytes, 0/1 carrying placements.
 * PAL: canonical name absent from the catalogue.
 * The ignored func_L01_003377C8 result is declared float.
 * This follows the current linked C contract; it does not independently prove the original
 * source declaration.
 * The retained C remains nonmatching. Earlier sizes and residual offsets below are
 * historical and superseded by this measurement; their reopening hypotheses remain
 * unqualified. No linked build was run for this follow-up.
 */

/* Historical measurements, superseded where inconsistent with the follow-up above. */
/* Measured with -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. US: 01_oozla: 1140
   bytes, expected 1136; 0/1 placements. US2: 0/1 placements. PAL: canonical function absent. Four
   source/profile trials. Initialization and paths reconstructed. Explicit positive-height predicate
   preserves NaN behavior; float compare scheduling and global-address lifetimes still differ. No-
   split-addresses did not improve size. Reopen with an exact initialization witness.
 */

#include "common.h"
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
#define I(p,o) (*(int *)((u8 *)(p)+(o)))
#define P(p,o) (*(int **)((u8 *)(p)+(o)))
typedef int OozlaQuad __attribute__((mode(TI)));
extern int D_L01_001B2088 NOT_SDA;
extern void *D_L01_001FE180[];
extern float D_L01_001AFDB4 __attribute__((sda));
extern float D_L01_001AFDB8 __attribute__((sda));
extern float D_L01_001AFDC0 __attribute__((sda));
extern float D_L01_001AFDC4 __attribute__((sda));
extern float D_L01_001AFDC8 __attribute__((sda));
extern float D_L01_001AFDD0 __attribute__((sda));
extern float func_L01_003BAFB0(void);
extern int func_00283CF0(float);
extern int func_002A7820(int,int);
extern void func_002B60B0(void *,float,float,float,float);
extern float func_L01_003377C8(unsigned char *);
extern void func_002A7750(void *,int,int);
extern void func_002A7470(void *,int,int,int);
extern float func_002A89A8(void *,int,float);
extern void func_L01_003A6280(void *,void *,int,float,float);
void func_L01_003B4C58(u8 *object)
{
    u8 *state = *(u8 **)(object+0x68);
    float height, scale;
    int index;
    if (D_L01_001B2088 == 0 && object[0x21] != 255) *P(state,0x33C) = 0;
    height = func_L01_003BAFB0();
    if (height > 0.0f) F(state,0x34C) = height;
    if (!(height > 0.0f) && D_L01_001B2088 < 4) return;
    I(state,0x378) = 0;
    if (object[0x21] != 255) {
        *P(state,0x368) = 0;
        *P(state,0x36C) = -1;
        *P(state,0x370) = -1;
    }
    *(OozlaQuad *)(state+0x2D0) = *(OozlaQuad *)(object+0x10);
    state[0x48] = func_00283CF0(10.0f);
    state[0x4A] = func_00283CF0(8.0f);
    I(state,0xA8) = 5;
    F(state,0x9C) = 0.4f;
    state[0x79] = 1;
    state[0x70] = 0;
    F(state,0x90) = 0.5f;
    F(state,0x94) = 0.5f;
    if (F(state,0x37C) == 0.0f) F(state,0x37C) = 1.0f;
    state[0x2A] = 6;
    state[0x28] = 3;
    F(state,0x30) = 0.5f;
    F(state,0x210) = 1.0f;
    F(state,0x21C) = 5.0f;
    F(state,0x220) = 6.0f;
    F(state,0x218) = D_L01_001AFDD0 * 0.00029088825f;
    F(state,0x214) = D_L01_001AFDC0 * 0.016666668f;
    I(state,0x32C) = func_002A7820(120,0);
    F(state,0x110) = 1.0f;
    F(state,0x114) = 0.2f;
    F(state,0x11C) = 0.25f;
    F(state,0x140) = 0.52359885f;
    F(state,0x13C) = 0.005f;
    F(state,0x118) = 0.25f;
    F(state,0x120) = 0.52359885f;
    scale = F(state,0x37C);
    func_002B60B0(object,D_L01_001AFDB4*scale*0.00027777778f,D_L01_001AFDB8*scale*0.016666668f,D_L01_001AFDC4*scale*0.0000048481375f,D_L01_001AFDC8*scale*0.00029088825f);
    if (I(state,0x30C) != -1) func_L01_003377C8(D_L01_001FE180[I(state,0x30C)]);
    if (I(state,0x364) != -1) func_L01_003377C8(D_L01_001FE180[I(state,0x364)]);
    if (I(state,0x308) != -1) {
        func_L01_003377C8(D_L01_001FE180[I(state,0x308)]);
        I(state,0x14C) = I(state,0x308);
        func_002A7750(object,1,1);
        F(object,0x18) = F(state,0x34C);
    } else if (I(state,0x374) == 0) {
        F(object,0x18) = func_002A89A8(object+0x10,0,0.5f);
        index = I(state,0x364);
        if (index == -1) index = I(state,0x30C);
        I(state,0x14C) = index;
        object[0xBC] = 0;
        I(state,0x398) = I(state,0x394);
        I(state,0x39C) = I(state,0x388);
        func_002A7750(object,1,3);
        if (object[0x43] != 0) func_002A7470(object,0,0,2);
        goto next;
    }
    if (I(state,0x374) != 0) {
        func_002A7750(object,5,1);
        F(object,0x18) = F(state,0x34C) - 2.0f;
    }
    I(object,0x98) = 0;
    if (object[0x43] != 4) func_002A7470(object,4,0,2);
next:
    if (I(state,0x380) != -1) {
        if (object[0x43] != 20) func_002A7470(object,20,0,2);
        I(state,0x14C) = I(state,0x30C);
        I(state,0x398) = I(state,0x390);
        I(state,0x39C) = I(state,0x388);
        func_002A7750(object,6,3);
    }
    *(OozlaQuad *)(state+0x200) = *(OozlaQuad *)(object+0x10);
    func_L01_003A6280(object,object+0x10,5,0.2f,2.0f);
    I(state,0x39C) = 0;
    I(state,0x398) = I(state,0x390);
}
