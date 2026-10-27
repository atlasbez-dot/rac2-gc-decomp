/* Near miss (M5): 628/632 B at both places (02, 11). Retail tests the child pointer in
   cases 2 and 3 as `bnel child, then` plus `b` to the shared func_002A7750(object, 4, -1)
   tail (cross-jumped after threading), one instruction more each than this cc1's `beqz`
   to the shared tail; if/else, early-return and goto spellings all give the beqz. Solved:
   the reset tail (func_002A7750(object, 1, -1) and the animation reset) sits inside case 4
   with case 0 jumping to it, as in retail's layout, and case 1 after it. */
#include "include_asm.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 *child; float speed,turn,height; } CaptureState;
extern int func_00312B58(void *);
extern int func_002B3868(void *);
extern void func_002A7470(void *, int, int, int);
extern void func_002A7750(u8 *,u8,int);
extern float func_00283B98(float,float);

/* Advance the captured child's rising and settling states. */
void func_L02_004164A8(u8 *object)
{
    CaptureState *state=*(CaptureState **)(object+0x68);
    if (state->child && func_00312B58(state->child)) {
        state->child=0;
        state->speed=0;
    }
    switch (object[0x20]) {
    case 0:
        state->speed=0;
        state->child=0;
        goto reset;
    case 2:
        if (func_002B3868(object)) {
            if(object[0x43]!=1) func_002A7470(object,1,0,7);
            *(float *)(object+0x48)=1;
        }
        if (!state->child) {
            func_002A7750(object,4,-1);
            return;
        }
        *(float *)(state->child+0x18)+=state->speed;
        *(float *)(state->child+0xF8)=func_00283B98(*(float *)(state->child+0xF8),state->turn);
        if (!(object[0x60]&2)) return;
        func_002A7750(object,3,-1);
        return;
    case 3:
        if (func_002B3868(object)) *(float *)(object+0x48)=0;
        if (state->child) {
            u8 *data=*(u8 **)(state->child+0x68);
            *(float *)(state->child+0x18)+=state->speed;
            *(float *)(state->child+0xF8)=func_00283B98(*(float *)(state->child+0xF8),state->turn);
            *(int *)(data+0xAC)=2;
            if (!(*(float *)(state->child+0x18)>*(float *)(object+0x18)+0.2f)) return;
            *(int *)(data+0xAC)=8;
        }
        func_002A7750(object,4,-1);
        return;
    case 4:
        if (func_002B3868(object)) {
            if(object[0x43]!=2) func_002A7470(object,2,0,7);
            *(float *)(object+0x48)=1;
        }
        if (!(object[0x60]&2)) return;
        if (state->child) state->height=*(float *)(state->child+0x18);
    reset:
        func_002A7750(object,1,-1);
        if(object[0x43]) func_002A7470(object,0,0,7);
        return;
    case 1:
        if (!state->child) return;
        if (*(float *)(state->child+0x18)!=state->height) {
            state->height=*(float *)(state->child+0x18);
            return;
        }
        *(int *)(*(u8 **)(state->child+0x68)+0xAC)=2;
        return;
    }
}
