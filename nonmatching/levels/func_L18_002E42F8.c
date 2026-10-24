/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections.
 * Prior worker coverage: US 0/3; US2 0/3; PAL 0/3.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Historical analysis (summary).
 * Historical screening catalogued calls, vector operations and data addressing without a
 * complete manual reconstruction. Its generated call/address lists and decoded instruction
 * header remain private. The dated manual reconstruction and recorded worker profile below
 * supersede that screening; no unsupported impossibility or handwritten classification is
 * carried forward.
 */

/* Wave4 manual reconstruction, 2026-10-23. Nonmatching; historical screening above
   is summarized; generated listings and unsupported classifications remain private.
   Trial source: src/levels/shared/L18_002E42F8-g8.c
   Profile: -O2 -G8 -ffunction-sections
   Shared callee varying by placement uses scoped reference to actual two-GPR level state handler. Export removes an unreachable block; no fabricated branch to pad size.
   us: func_L18_002E42F8: 0 of 3 places match (src/levels/shared/L18_002E42F8-g8.c), exit 1; us2: func_L18_002E42F8: 0 of 3 places match (src/levels/shared/L18_002E42F8-g8.c), exit 1; pal: func_L18_002E42F8: 0 of 3 places match (src/levels/shared/L18_002E42F8-g8.c), exit 1
*/
#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
extern char D_00189E20[];
extern int D_001A79F0 __attribute__((nosda));
extern int D_L18_001B2348 __attribute__((sda));
extern float D_L18_001BFC28 __attribute__((nosda));
extern float func_00282C48(float);
extern int ref_L18_002E42F8_00(int,int);
extern void func_L00_002B47A8(void *,void *,int,float,float);
extern int func_002761F8(void *,void *,int,void *,void *);
extern int func_00278E78(void);
extern int func_L00_002B9B88(int,int);
int func_L18_002E42F8(void)
{
    Vector128 start[1],end[1];
    char *player=D_00189E20;
    int detected=0;
    float allowance;
    short material;
    float distance;
    if(*(int *)(player+0x2294)==0x74 || *(int *)(player+0x2294)==0x67) return 0;
    if(*(unsigned char *)(player+0x1494)!=0) {
        if(*(int *)(player+0x229c)==17) {
            if(*(int *)(player+0x2298)!=1 && *(float *)(player+0x118)>0.0f && *(float *)(player+0x88)>*(float *)(player+0x330)-0.4f) detected=1;
        } else if(*(int *)(player+0x229c)!=18 && *(int *)(player+0x229c)!=3) {
            allowance=0.2f;
            if(func_00282C48(*(float *)(player+0xf8))+0.07f>0.2f) allowance=func_00282C48(*(float *)(player+0xf8))+0.07f;
            if(func_00282C48(*(float *)(player+0x330)-(*(float *)(player+0x88)+0.45f))<allowance && (*(int *)(player+0x229c)!=4 || *(unsigned char *)(player+0x49e)!=0) && *(float *)(player+0x24c4)>0.8f && *(float *)(player+0x118)<0.0f) detected=1;
            if(*(float *)(player+0x88)<*(float *)(player+0x330)-0.8f && (*(int *)(player+0x229c)!=4 || *(unsigned char *)(player+0x49e)!=0)) detected=1;
        }
    }
    if(func_00282C48(*(float *)(player+0xf8))+0.07f>0.27f) func_00282C48(*(float *)(player+0xf8));
    if(*(int *)(player+0x2294)==0x12 && *(unsigned char *)(player+0x49e)!=0 && *(float *)(player+0x88)<*(float *)(player+0x330)-0.7f) detected=1;
    if(*(unsigned char *)(player+0x22b4)==4) {
        if(detected!=0) { *(int *)(player+0x24cc)=0; ref_L18_002E42F8_00(0x91,1); return 1; }
        return 0;
    }
    if(D_001A79F0!=12 && (unsigned int)(*(int *)(player+0x229c)-17)>1 && *(int *)(player+0x229c)!=7 && *(int *)(player+0x2294)!=0x12 && (D_L18_001B2348&15)==0) {
        distance=4.0f;
        if(D_L18_001B2348%63==0) distance=16.0f;
        func_L00_002B47A8(start,end,0,distance,1.3f);
        if(func_002761F8(start,end,2,*(void **)(player+0x2290),0)!=0) {
            material=(short)func_00278E78();
            *(short *)(player+0x1490)=material;
            if(material==0) {
                ((float *)start)[2]=D_L18_001BFC28-0.01f;
                if(func_002761F8(start,end,2,*(void **)(player+0x2290),0)==0) {
                    if(*(int *)(player+0x229c)!=20 && *(int *)(player+0x24cc)!=0) ref_L18_002E42F8_00(0x33,1);
                    else ref_L18_002E42F8_00(0x67,1);
                    return 1;
                }
            }
        }
    }
    if(detected==0) return 0;
    if(*(int *)(player+0x229c)==20 || *(int *)(player+0x24cc)==0) ref_L18_002E42F8_00(0x67,1);
    else ref_L18_002E42F8_00(0x36,1);
    func_L00_002B9B88(3,0);
    return detected;
}
