/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections.
 * Reported final C / retail: 888 / 936 bytes; size equality is not a match.
 * us: 0/9 placements; 888/936 bytes.
 * us2: 0/9 placements; 888/936 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 888 bytes versus 936. The packed progress-nibble update retains its distinct initial unsigned and later signed halfword index interpretation, plus both path-point cleanup paths.
 * Reopening condition: A demonstrated control-flow and table-address source-shape remedy.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete unmatched manual reconstruction, 2026-10-23.
 * Profile: -O2 -G8 -ffunction-sections.
 * Final checks: us: 0/9 exit 1, us2: 0/9 exit 1.
 * No canonical catalogue entry: pal; absence is not a match.
 * 888 bytes versus 936. The packed progress-nibble update retains its distinct initial
 * unsigned and later signed halfword index interpretation, plus both path-point cleanup
 * paths.
 * Behavior and linked-image equality remain unverified. Reopen: A demonstrated control-flow
 * and table-address source-shape remedy.
 * The following historical screening comment is superseded by this manual attempt. In
 * particular, por/mult/madd alone are not evidence of handwritten assembly. No ASM_FUNC
 * classification or C credit is claimed.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

typedef unsigned int u32;
extern unsigned char D_L00_0021E214[],D_0019B4A8[],D_0019B2E8[];
extern int D_001A79F0[] __attribute__((sda));
extern char *D_L00_001FDA80[];
typedef struct {unsigned char reserved[0x33C];unsigned char *owner;unsigned char middle[0x34E - 0x340];short paused;} PartialRoot;
extern PartialRoot D_00189E20;
extern float func_002A7940(void),func_00283B98(float,float),func_00283198(float);
extern int func_00283CF0(float),func_002E5CF8(int,int,char *);
#define F(p,o) (*(float *)((char *)(p)+(o)))
#define I(p,o) (*(int *)((char *)(p)+(o)))
#define U(p,o) (*(unsigned short *)((char *)(p)+(o)))
void func_L00_003B79A0(unsigned char *object)
{
    char *context=*(char **)(object+0x68),*path;
    unsigned char *packed;
    unsigned int bits,color;
    int i,intensity;
    unsigned short id;
    if(object[0x20]==0) {
        F(context,0x0C)=func_002A7940();
        id=U(object,0xB2);F(object,0x18)-=0.35f;
        if(!D_L00_0021E214[id]) {
            bits=D_0019B4A8[(id>>1)+D_001A79F0[0]*0x400];
            if(id&1)bits>>=4;
            if(!(bits&7) && (!I(context,8) || !(D_0019B2E8[object[0xB0]+D_001A79F0[0]*16]&0x80))) {
                object[0x20]=1;return;
            }
        }
        object[0x20]=2;*(u32 *)(object+0x78)=0x80208020;object[0xBC]=2;
        if(I(context,0)==-1)return;
        for(i=0;i<I(D_L00_001FDA80[I(context,0)],0);++i) {
            path=D_L00_001FDA80[I(context,0)]+i*16;
            if(F(path,0x1C)==F(context,4))F(path,0x1C)=0.0f;
        }
        return;
    }
    if(object[0x20]!=1)return;
    F(context,0x0C)=func_00283B98(F(context,0x0C),0.10471977f);
    intensity=func_00283CF0((func_00283198(F(context,0x0C))*4.0f-3.0f)*128.0f);
    if(intensity>128)intensity=128;else if(intensity<32)intensity=32;
    color=(u32)intensity;
    *(u32 *)(object+0x78)=(color<<16)|(color<<8)|0x80000000|color;
    if(D_00189E20.owner!=object || D_00189E20.paused) {
        if(!I(context,8))return;
        if(!(D_0019B2E8[object[0xB0]+D_001A79F0[0]*16]&0x80))return;
    }
    id=U(object,0xB2);
    packed=&D_0019B4A8[((short)id>>1)+D_001A79F0[0]*0x400];
    if(!(id&1)) {if((*packed&7)!=7)++*packed;}
    else {if(((*packed>>4)&7)!=7)*packed+=0x10;}
    object[0xBC]=1;object[0x20]=2;*(u32 *)(object+0x78)=0x80208020;
    func_002E5CF8(0,0,(char *)object);
    if(I(context,0)!=-1)for(i=0;i<I(D_L00_001FDA80[I(context,0)],0);++i) {
        path=D_L00_001FDA80[I(context,0)]+i*16;
        if(F(path,0x1C)==F(context,4))F(path,0x1C)=0.0f;
    }
}
