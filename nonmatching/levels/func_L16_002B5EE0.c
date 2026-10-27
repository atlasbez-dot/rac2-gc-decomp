/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections.
 * Compiled 1428 bytes; retail 1456 bytes.
 * us: 0/2 placements match (exit 1).
 * us2: 0/2 placements match (exit 1).
 * pal: canonical name absent; no check credit.
 * Remaining: The 0x80-byte frame agrees. Shared qcopy does not close resident-base
 * materialization, floating expressions or division padding. The resident source-pointer
 * argument of func_L00_002D3BD8 is now a real char pointer, matching its current qualified
 * interface.
 * Reopen: A matching resident-state motion witness and independently measured division-label
 * remedy.
 */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
#define F(offset) (*(float *)(D_00189E20+(offset)))
#define I(offset) (*(int *)(D_00189E20+(offset)))
#define V(offset) (D_00189E20+(offset))
extern char D_00189E20[];
extern void func_L00_002D4140(int,void *,void *);
extern float func_L00_002D3A58(char *);
extern float func_L00_002D3B00(char *);
extern void func_L00_002D3BD8(char *,char *,float);
extern void func_L00_002D3B58(Quad *,Quad *,float);
extern float func_00282E20(void *);
extern void func_00282F70(void *,void *,float);
extern float func_00282DF0(void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282C88(Quad *);
extern float func_00282DB0(void *,void *);
extern void func_00282D30(void *,void *,float);
extern void func_L00_002B5A88(void);
extern void func_L09_002B7238(void);
extern void func_L00_002B5250(void);
extern void func_L00_002D3960(char *,char *);
extern float func_L00_002B5590(void *);
void func_L16_002B5EE0(void)
{
    float oldPosition[4],horizontal[4],vertical[4];
    float value,limit,saved;
    qcopy(oldPosition,V(0x80));
    func_L00_002D4140(I(0x588),V(0x100),V(0x90));
    if (I(0x2294)==0x14 || I(0x2294)==0x5B || I(0x2294)==0x58 || I(0x2294)==0x81) {
        if (*(s16 *)V(0x1F0)==0 && func_L00_002D3A58(V(0xF0))>F(0x264)-0.02f)
            func_L00_002D3BD8(V(0xF0),V(0xF0),F(0x264)-0.02f);
        if (func_L00_002D3B00(V(0xF0)) < -F(0x31C)) {
            limit=-F(0x31C)-0.02f;
            if (limit>0.0f) limit=0.0f;
            func_L00_002D3B58((Quad *)V(0xF0),(Quad *)V(0xF0),limit);
        }
    } else if (I(0x229C)==15) {
        if (*(s16 *)V(0x1F0)==0 && func_00282E20(V(0xF0))>F(0x264)-0.02f)
            func_00282F70(V(0xF0),V(0xF0),F(0x264)-0.02f);
    } else if (I(0x229C)!=13 && I(0x229C)!=14 && *(s16 *)V(0x1F0)==0 && func_00282DF0(V(0xF0))>F(0x264)-0.02f) {
        func_00282F20(V(0xF0),V(0xF0),F(0x264)-0.02f);
    }
    func_00282CC0(V(0x80),V(0x80),V(0xF0));
    func_00282CC0(V(0x80),V(0x80),V(0xA60));
    func_00282C88((Quad *)V(0xA60));
    I(0x26C)=0;
    *(u8 *)V(0x287)=0;
    if (func_00282DF0(V(0x100))<=0.0001f) {
        func_L00_002B5A88();
        func_L09_002B7238();
        func_00282CF0(V(0x110),V(0x80),oldPosition);
        func_L00_002B5250();
    } else func_L09_002B7238();
    func_00282CF0(V(0x120),V(0x80),oldPosition);
    qcopy(V(0x130),V(0x120));
    qcopy(V(0x140),V(0x120));
    func_00282F20(V(0x120),V(0x120),1.0f);
    value=func_00282DB0(V(0x120),V(0xF0));
    if (value<0.0f) value=0.0f;
    func_00282F20(V(0x120),V(0xF0),value);
    qcopy(horizontal,V(0xF0));
    func_L00_002D3960((char *)horizontal,(char *)horizontal);
    func_L00_002D3960(V(0x140),V(0x140));
    func_00282F20(V(0x140),V(0x140),1.0f);
    value=func_00282DB0(V(0x140),horizontal);
    if (value<0.0f) value=0.0f;
    func_00282F20(V(0x140),horizontal,value);
    qcopy(vertical,V(0xF0));
    func_L00_002D3BD8((char *)vertical,(char *)vertical,0.0f);
    func_L00_002D3BD8(V(0x130),V(0x130),0.0f);
    func_00282F20(V(0x130),V(0x130),1.0f);
    value=func_00282DB0(V(0x130),vertical);
    if (value<0.0f) value=0.0f;
    func_00282F20(V(0x130),vertical,value);
    F(0x170)=func_00282DF0(V(0x120));
    F(0x174)=func_L00_002D3A58(V(0x120));
    qcopy(horizontal,V(0x120));
    F(0x178)=func_L00_002B5590(horizontal);
    F(0x180)=func_L00_002D3B00(V(0x120));
    value=0.0f;
    if (F(0x178)>=0.0f) value=F(0x178);
    F(0x178)=value;
    qcopy(horizontal,V(0x80));
    if (func_00282DF0(V(0x100))>0.0001f) {
        func_00282CC0(V(0x80),V(0x80),V(0x100));
        saved=F(0x10C);
        func_00282C88((Quad *)V(0x100));
        F(0x10C)=saved;
        func_L00_002B5A88();
        func_L09_002B7238();
        func_00282CF0(V(0x110),V(0x80),oldPosition);
        func_L00_002B5250();
    }
    func_00282CF0(V(0x150),V(0x80),horizontal);
    F(0x184)=func_00282DF0(V(0x150));
    F(0x15C)=F(0x10C);
    F(0x10C)=0.0f;
    func_00282CF0(V(0x110),V(0x80),oldPosition);
    F(0x17C)=0.0f;
    if (F(0x174)>0.004f) {
        F(0x17C)=F(0x118)/F(0x174);
        if (F(0x17C)>0.5f) F(0x17C)=0.5f;
        else if (F(0x17C)<-0.5f) F(0x17C)=-0.5f;
    }
    if (F(0x170)>0.86666673f) {
        func_00282D30(V(0x110),V(0x110),0.86666673f/F(0x170));
        F(0x170)=0.86666673f;
    }
}
