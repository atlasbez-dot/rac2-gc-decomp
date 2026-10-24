/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 868 / 900 bytes; size equality is not a match.
 * us: 0/28 placements; 868/900 bytes.
 * us2: 0/28 placements; 868/900 bytes.
 * pal: 0/28 placements; 868/900 bytes.
 * Residual: Snapshot/copy allocation; real 48-byte three-row rotation matrices.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching manual reconstruction, 2026-10-23.
 * 00301F18: 868 bytes versus retail 900; frame 0x100 (retail 0x110).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * All carrying US/US2/PAL checks returned zero matches and exit 1;
 * catalogue absence is recorded separately and never counted as success.
 * The actual three-row rotation matrices are 48 bytes. Snapshot lifetimes, conditional copies and allocation still differ; qualified copies improved the initial844-byte draft.
 * Reopen only with new measured source/type/scheduling evidence. No artificial
 * barriers, register pins, generated decompiler C or omitted behavior were used.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
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
void func_00301F18(char *object, void *outPosition, void *outAngles)
{
    char *state=*(char **)(object+0x68);
    ParticleVector position, angles, rotation, offset;
    ParticleVector spinMatrix[3], anchorMatrix[3];
    char *parent;
    float step, tilt, radius, lift;
    int detach;
    if (!*(char **)(state+0x5c)) {
        position.word=*(ParticleWord *)state;
        angles.word=*(ParticleWord *)(state+0x10);
    } else func_002AD470(object,*(char **)(state+0x5c),state,state+0x10,&position,&angles);
    if (object[0x20]==3 && *(char **)(state+0x5c)) {
        parent=*(char **)(state+0x5c);
        detach=*(signed char *)(parent+0x20)==-2 || *(signed char *)(parent+0x20)==-3;
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
                *(ParticleWord *)(state+0x20)=*(ParticleWord *)(parent+0x10);
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
    rotation.word=*(ParticleWord *)(state+0x50);
    rotation.f[1]=tilt;
    func_002833F0(spinMatrix,&rotation);
    func_002833F0(anchorMatrix,&angles);
    func_00283738(object+0xc0,anchorMatrix,spinMatrix);
    func_00282D30(object+0x10,&anchorMatrix[2],radius);
    func_00282D30(&offset,object+0xc0,lift);
    func_00282CC0(object+0x10,object+0x10,&offset);
    func_00282CC0(object+0x10,object+0x10,&position);
    if (outPosition) *(ParticleWord *)outPosition=position.word;
    if (outAngles) *(ParticleWord *)outAngles=angles.word;
}
