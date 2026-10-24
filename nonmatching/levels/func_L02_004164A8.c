/* Readable C reconstruction, 23 October 2026. Profile: -O2 -G0 -ffunction-sections.
 * us: 628/632 bytes, 0/2 carrying placements.
 * us2: canonical name absent.
 * pal: canonical name absent.
 * Three bounded source forms, including an explicit dispatch table, retain 628 bytes versus 632.
 * The ordinary switch is retained. The case-3 ordered height predicate preserves the retail
 * NaN behavior; block layout and state-transition scheduling remain. Reopen with a measured
 * state-selector/control-flow witness.
 * The historical screening below predates this C and is superseded; por/quadword instructions
 * alone are not evidence of handwritten assembly. No linked qualification was run.
 */

/* Superseded historical screen, retained for provenance. */
/* func_L02_004164A8 - 632 bytes, 2 place(s), level 02_maktar_nebula, retail
   at 0x004164a8. Screened with tools/w10_screen.py: 11 call(s)
   [func_00312B58@004164D0, func_002B3868@00416520, func_002A7470@00416544,
   func_00283B98@00416584, func_002B3868@004165AC, func_00283B98@004165E8,
   func_002A7750@00416638, func_002B3868@00416648, func_002A7470@0041666C,
   func_002A7750@004166AC, func_002A7470@004166C8]; data addresses
   materialised [0x2a0000, 0x3e4c0000]; float constants [0x3f800000,
   0x3f800000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [-]. Head: addiu $sp, $sp,
   -0x20 ; sd $s1, 0x8($sp) ; sd $s2, 0x10($sp) ; daddu $s1, $a0, $zero ; sd
   $ra, 0x18($sp) ; sd $s0, 0x0($sp). Not matched in this wave: the body is
   straight-line code whose register allocation and the materialisation of
   its constant addresses have to be reproduced word for word. What would
   unblock it: the exact source expression tree, so this cc1 picks the same
   registers in the same order. */

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
        break;
    case 2:
        if (func_002B3868(object)) {
            if(object[0x43]!=1) func_002A7470(object,1,0,7);
            *(float *)(object+0x48)=1;
        }
        if (state->child) {
            *(float *)(state->child+0x18)+=state->speed;
            *(float *)(state->child+0xF8)=func_00283B98(*(float *)(state->child+0xF8),state->turn);
            if (!(object[0x60]&2)) return;
            func_002A7750(object,3,-1);
        } else func_002A7750(object,4,-1);
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
        break;
    case 1:
        if (!state->child) return;
        if (*(float *)(state->child+0x18)!=state->height) {
            state->height=*(float *)(state->child+0x18);
            return;
        }
        *(int *)(*(u8 **)(state->child+0x68)+0xAC)=2;
        return;
    default:
        return;
    }
    func_002A7750(object,1,-1);
    if(object[0x43]) func_002A7470(object,0,0,7);
}
