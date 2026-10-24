/* Retained manual C reconstruction; not linked and not matching.
 * Profile: -O2 -G8 -ffunction-sections
 * Local tools/check.py measurements: us: 1040 compiled bytes, 0/1 placements, exit 1; us2: 1040 compiled bytes, 0/1 placements, exit 1; pal: catalogue absent (exit 1).
 * Retail extent: 1040 bytes. No exact-C credit and no full build performed.
 * Residual: Equal 1040-byte extent, 0x50 frame; first difference +0x8 in saved registers. State pointer allocation, copied-header count-down loop, repeated object-base loads and phase-loop scheduling differ. Qcopy/pointer-local trial grew to 1076 bytes.
 * Reopen: Reopen after a measured non-countdown copy-loop or state-pointer allocation hypothesis; preserve the 16-byte vectors and all state transitions.
 * Arrays with unknown total extent remain incomplete. Pointer-offset views do
 * not establish the full sizes or ownership of game records.
 */
/* Animates the selected polygon and its two cycling texture phases. */
typedef unsigned char u8;
typedef int Quad __attribute__((mode(TI)));
#define S16(p,o) (*(short *)((p)+(o)))
#define U16(p,o) (*(unsigned short *)((p)+(o)))
#define I32(p,o) (*(int *)((p)+(o)))
#define F32(p,o) (*(float *)((p)+(o)))
extern u8 *D_L11_001B359C;
extern u8 *D_L11_001FF580[];
extern float D_L11_001B187C __attribute__((sda)), D_L11_001B1880 __attribute__((sda));
extern float D_L11_001B1884 __attribute__((sda)), D_L11_001B1888 __attribute__((sda));
extern void func_00283360(void *);
extern float func_002AA2E8(float *,float,float);
extern float func_00282C48(float);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern float func_002A7878(float,float);
void func_L11_004461E8(u8 *object)
{
    u8 *state = *(u8 **)(object+0x68);
    float previous = F32(state,0x1bc);
    float vector[4] __attribute__((aligned(16)));
    int i, count;
    u8 *dst,*src,*vertex;
    switch (S16(state,0x1fa)) {
    case 1:
        func_00283360(D_L11_001B359C+(I32(state,0x1b8)<<8)+0xc0);
        previous=1.0f;
        dst=D_L11_001FF580[I32(state,0x1c8)];
        src=D_L11_001FF580[I32(state,0x1cc)];
        count=I32(dst,0);
        for(i=0;i<count;i++) ((Quad *)(dst+16))[i]=((Quad *)(src+16))[i];
        U16(D_L11_001B359C+(I32(state,0x1b8)<<8),0x34)&=0xfffe;
        D_L11_001B359C[(I32(state,0x1b8)<<8)+0x31]=1;
        U16(D_L11_001B359C+(I32(state,0x1b8)<<8),0x32)=255;
        F32(state,0x1bc)=D_L11_001B187C;
        F32(state,0xd4)=0.5f;
        S16(state,0x1fa)=2;
        I32(state,0xd0)=0;
        /* Initialization deliberately advances the new animation immediately. */
    case 2:
        func_002AA2E8((float *)(state+0x1bc),D_L11_001B1880,D_L11_001B1884);
        if (func_00282C48(F32(state,0x1bc)-D_L11_001B1880)<0.01f) S16(state,0x1fa)=3;
        break;
    case 4:
        func_002AA2E8((float *)(state+0x1bc),D_L11_001B187C,D_L11_001B1884);
        if (!(func_00282C48(F32(state,0x1bc)-D_L11_001B187C)<0.01f)) break;
        goto finish;
    case 5:
        F32(state,0x1bc)=D_L11_001B187C;
finish:
        U16(D_L11_001B359C+(I32(state,0x1b8)<<8),0x34)|=1;
        D_L11_001B359C[(I32(state,0x1b8)<<8)+0x31]=0;
        S16(state,0x1fa)=0;
        break;
    }
    if (previous != F32(state,0x1bc)) {
        dst=D_L11_001FF580[I32(state,0x1c8)];
        for (i=0;i<I32(dst,0);i++) {
            vertex=dst+16+i*16;
            func_00282CF0(vector,vertex,D_L11_001B359C+(I32(state,0x1b8)<<8)+16);
            func_00282D30(vector,vector,F32(state,0x1bc)/previous);
            func_00282CC0(vertex,D_L11_001B359C+(I32(state,0x1b8)<<8)+16,vector);
            F32(vertex,8)=F32(D_L11_001B359C+(I32(state,0x1b8)<<8),0x18);
        }
        func_00282F20(D_L11_001B359C+(I32(state,0x1b8)<<8)+0xc0,D_L11_001B359C+(I32(state,0x1b8)<<8)+0xc0,F32(state,0x1bc));
        func_00282F20(D_L11_001B359C+(I32(state,0x1b8)<<8)+0xd0,D_L11_001B359C+(I32(state,0x1b8)<<8)+0xd0,F32(state,0x1bc));
    }
    if (S16(state,0x1fa)==2) {
        for(i=0;i<2;i++) {
            F32(state,0xd0+i*4)+=D_L11_001B1888*0.01666666753590107f;
            if (F32(state,0xd0+i*4)>1.0f) {
                F32(state,0xd0+i*4)-=1.0f;
                F32(state,0xd8+i*4)=F32(state,0xd8+((i+1)&1)*4)+func_002A7878(0.3330000042915344f,0.6660000085830688f);
                if(F32(state,0xd8+i*4)>1.0f) F32(state,0xd8+i*4)-=1.0f;
            }
        }
    }
}
