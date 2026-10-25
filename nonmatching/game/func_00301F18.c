/* Retained manual C reconstruction; not linked and not credited as exact.
 * Checked source: src/game/00301F18-copy.c
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Retail US size: 900 bytes.
 * Final checks: us: 0/28, exit 1, 896 compiled bytes; us2: 0/28, exit 1, 896 compiled bytes; pal: 0/28, exit 1, 896 compiled bytes.
 * Residual: 896/900 bytes with the correct 0x110 frame, actual 48-byte rotation matrices, terminal sixteen-byte copies and unsigned state loads. Position/angle address pseudos occupy s7/fp in the opposite order; parent-state tests fold into a range check and one branch-copy shape remains different. Initial helper-only source was 872 bytes with a 0x100 frame. Named pointer aliases regressed to 860 bytes; terminal qcopy_nc tied and was reverted.
 * Reopen only with: A measured lifetime/control-flow policy explaining the address-pseudo allocation and parent-state branch chain, without false prototypes, fake extents or artificial dependencies.
 * Reviewed EE helpers follow the source-method policy in AGENTS.md.
 * No complete linked build or native runtime validation was performed here.
 */
#include "common.h"

typedef int ParticleWord __attribute__((mode(TI)));
typedef union { ParticleWord word; float f[4]; } ParticleVector;
typedef struct { int a,b,c,d; } __attribute__((aligned(16))) Quad16;
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern int func_00277258(void *, int, void *, float);
extern char ref_00305798_00[];

extern int func_002AD470(void *, void *, void *, void *, void *, void *);
extern s32 func_002AD0B0(u8 *);
extern void func_00282C88(ParticleWord *);
extern float func_00283B98(float, float);
extern float func_00283BE0(float, float);
extern void func_002833F0(void *, void *);
extern void func_00283738(void *, void *, void *);
extern void func_00282D30(void *, void *, float);

/* Update the pickup's anchor, turn it, and compose the visible orientation. */
void func_00301F18(u8 *object, void *outPosition, void *outAngles)
{
    char *state=*(char **)(object+0x68);
    ParticleVector spinMatrix[3], anchorMatrix[3];
    ParticleVector rotation, offset, position, angles;
    char *parent;
    float step, tilt, radius, lift;
    int detach;
    if (*(char **)(state+0x5c)) {
        func_002AD470(object,*(char **)(state+0x5c),state,state+0x10,&position,&angles);
    } else {
        qcopy(&position, state);
        qcopy(&angles, state+0x10);
    }
    if (object[0x20]==3 && *(char **)(state+0x5c)) {
        parent=*(char **)(state+0x5c);
        detach=*(u8 *)(parent+0x20)==254 || *(u8 *)(parent+0x20)==253;
        if (!detach) detach=!func_00277258(object+0x10,0x22,object,0.25f);
        if (detach) {
            object[0x20]=1;
            func_00282C88((ParticleWord *)(state+0x30));
            *(float *)(state+0x3c)=1.0f;
            parent=(char *)func_002AD0B0((u8 *)*(char **)(state+0x5c));
            if (!parent) {
                func_00282C88((ParticleWord *)(state+0x20));
                *(char **)(state+0x5c)=0;
            } else {
                qcopy(state+0x20, parent+0x10);
                *(char **)(state+0x5c)=0;
            }
        }
    }
    switch (*(short *)(object+0xaa)) {
    case 13: step=0.04f; tilt=-0.25f; radius=0.04875f; lift=0.325f; break;
    case 14: step=0.03f; tilt=-0.5f; radius=0.0245f; lift=0.35f; break;
    case 15: step=0.025f; tilt=-0.4f; radius=0.05625f; lift=0.375f; break;
    default: step=0.0175f; tilt=-0.35f; radius=0.135f; lift=0.3f; break;
    }
    if (*(u8 *)(state+0x55)&1) {
        *(float *)(state+0x50)=func_00283B98(*(float *)(state+0x50),step);
        *(float *)(state+0x58)=func_00283B98(*(float *)(state+0x58),-0.0125f);
    } else {
        *(float *)(state+0x50)=func_00283BE0(*(float *)(state+0x50),step);
        *(float *)(state+0x58)=func_00283BE0(*(float *)(state+0x58),-0.0125f);
    }
    qcopy(&rotation, state+0x50);
    rotation.f[1]=tilt;
    func_002833F0(spinMatrix,&rotation);
    func_002833F0(anchorMatrix,&angles);
    func_00283738(object+0xc0,anchorMatrix,spinMatrix);
    func_00282D30(object+0x10,&anchorMatrix[2],radius);
    func_00282D30(&offset,object+0xc0,lift);
    func_00282CC0(object+0x10,object+0x10,&offset);
    func_00282CC0(object+0x10,object+0x10,&position);
    if (outPosition) qcopy(outPosition, &position);
    if (outAngles) qcopy(outAngles, &angles);
}
