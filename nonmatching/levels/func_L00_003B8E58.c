/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 772 / 788 bytes; size equality is not a match.
 * us: 0/27 placements; 772/788 bytes.
 * us2: 0/27 placements; 772/788 bytes.
 * pal: 0/27 placements; 772/788 bytes.
 * Residual: 772 bytes versus 788. Complete prioritised/fallback object filtering is retained, including all five FP and three wrapper GPR inputs, twenty output slots and the full eight-GPR enumerator call.
 * Reopening condition: A qualified global-root layout and wrapper/caller-input lifetime remedy; do not invent ignored parameters.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete unmatched manual reconstruction, 2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections.
 * Final checks: us: 0/27 exit 1, us2: 0/27 exit 1, pal: 0/27 exit 1.
 * 772 bytes versus 788. Complete prioritised/fallback object filtering is retained, including
 * all five FP and three wrapper GPR inputs, twenty output slots and the full eight-GPR
 * enumerator call.
 * Behavior and linked-image equality remain unverified. Reopen: A qualified global-root
 * layout and wrapper/caller-input lifetime remedy; do not invent ignored parameters.
 * The following historical screening comment is superseded by this manual attempt. In
 * particular, por/mult/madd alone are not evidence of handwritten assembly. No ASM_FUNC
 * classification or C credit is claimed.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

extern char D_00189E20[];
extern unsigned int D_00138320[];
extern int func_002AB1F0(unsigned char *);
extern unsigned char *func_002AF580(void *,void *,int *,unsigned char **,int,int,int,void *,float,float,float,float,float);
extern float func_00282E80(void *,void *);
#define P(p,o) (*(unsigned char **)((char *)(p)+(o)))
#define I(p,o) (*(int *)((char *)(p)+(o)))
#define H(p,o) (*(short *)((char *)(p)+(o)))
#define F(p,o) (*(float *)((char *)(p)+(o)))
unsigned char *func_L00_003B8E58(void *origin,void *direction,unsigned char *preferred,
    float a,float b,float c,float d,float e)
{
    unsigned char *candidates[20];
    int count[4];
    unsigned char *current,*descriptor,*candidate,*context;
    unsigned char **scan;
    int i;
    current=P(D_00189E20,0x1450);
    if(current && current[0x20]!=0xFE && current[0x20]!=0xFD) {
        descriptor=(unsigned char *)func_002AB1F0(current);
        if(descriptor && F(descriptor,0)>0.0f) return P(D_00189E20,0x1450);
    }
    func_002AF580(origin,direction,count,candidates,20,0,0,0,a,b,c,d,e);
    if(I(D_00189E20,0x340) && !H(D_00189E20,0x34E) &&
        (D_00138320[0] & *(unsigned int *)(D_00189E20+0x1230)) &&
        preferred && preferred[0x20]!=0xFE && preferred[0x20]!=0xFD) {
        scan=candidates;
        for(i=0;i<count[0];++i,++scan) {
            candidate=*scan;
            if(candidate && candidate[0x20]!=0xFE && candidate[0x20]!=0xFD &&
                candidate==preferred && H(candidate,0xAA)==0xEE1) {
                context=P(candidate,0x68);
                if((context[0x3B1]&0x80) && F(context,0x20)>0.0f) {
                    if(F(context,0x3E4)==0.0f) return candidate;
                    if(func_00282E80(origin,candidate+0x10)<F(context,0x3E4)) return candidate;
                }
            }
        }
    }
    scan=candidates;
    for(i=0;i<count[0];++i,++scan) {
        candidate=*scan;
        if(candidate && candidate[0x20]!=0xFE && candidate[0x20]!=0xFD && H(candidate,0xAA)==0xEE1) {
            context=P(candidate,0x68);
            if((context[0x3B1]&0x80) && F(context,0x20)>0.0f) {
                if(F(context,0x3E4)==0.0f) return candidate;
                if(func_00282E80(origin,candidate+0x10)<F(context,0x3E4)) return candidate;
            }
        }
    }
    return 0;
}
