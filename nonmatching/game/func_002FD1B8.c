/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: default -O2 -G8 -ffunction-sections.
 * Prior worker coverage: US 0/28; US2 0/28; PAL 0/28.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 * Reopen with independent evidence for scalar lifetimes and register reuse in the grid/neighbor
 * propagation while preserving global page reloads and unordered squared-distance behavior. The
 * retained 1692/1644-byte and 0x130/0x150-frame residual is not a new measurement.
 */

/* Manual retained reconstruction. Profile: default -O2 -G8 -ffunction-sections.
   1692/1644; frame130 vs150. Typed1190-byte record, three5C0-byte planes, 16x16 scan and edge/corner propagation. Initial1648-byte trial cached the page across stores; final draft preserves fresh-global loads and unordered squared-distance branch. -g1700bytes was worse.
   Final checks: no matching placement in US/US2/PAL carrying releases.
   Not an exact match or a proof of native behavior. */
/* Screened, not matched in wave 13 (worker g3): 3 call(s), 13 $gp-relative small-data access(es), MMI words [20 pairs] (the lq/sq family, which mode(TI) reaches), float constants [none]. The body is straight-line code
   whose register allocation and the materialisation of its constant addresses have to be
   reproduced word for word; no C was written in this wave. */

typedef unsigned char u8;
typedef struct {
    float x, y;
    u8 header08[4];
    u8 neighbor[8];
    u8 header14[0x50-0x14];
    float samples[3][368];
} SurfacePatch;
extern float D_001AD5C8, D_001AD5CC, D_001AD5D0, D_001AD5D4;
extern int D_001AD5A4 __attribute__((sda)), D_001AD5AC __attribute__((sda));
extern float func_00282C10(float);
extern float func_00282C48(float);

void func_002FD1B8(SurfacePatch *patch, int count, int mode,
                   float x, float y, float radius, float strength)
{
    SurfacePatch *patches = patch;
    int n;
    for (n=0; n<count; n++,patch++) {
        float centerY=patch->y+D_001AD5CC;
        float centerX=patch->x+D_001AD5C8;
        float gridY=(y-centerY)/D_001AD5D4;
        float gridX=(x-centerX)/D_001AD5D0;
        int firstY=(int)(gridY-radius);
        int lastY=(int)(gridY+radius);
        int firstX=(int)(gridX-radius);
        int lastX=(int)(gridX+radius);
        int row, column;
        float rowY, columnX;
        if(firstY<0) firstY=0;
        if(lastY>15) lastY=15;
        if(firstX<0) firstX=0;
        if(lastX>15) lastX=15;
        rowY=centerY+D_001AD5D4*(float)firstY;
        for(row=firstY; row<=lastY; row++,rowY+=D_001AD5D4) {
            float dy=y-rowY;
            float squaredY=dy*dy;
            columnX=patch->x+D_001AD5C8+D_001AD5D0*(float)firstX;
            for(column=firstX; column<=lastX; column++,columnX+=D_001AD5D0) {
                float dx=x-columnX;
                float distanceSquared=dx*dx+squaredY;
                float impulse=strength;
                int page;
                if(distanceSquared<1.0f) impulse=strength;
                else impulse=strength/func_00282C10(distanceSquared);
                if(mode==0) {
                    if(func_00282C48(impulse)<func_00282C48(patch->samples[D_001AD5A4][row*16+column]))
                        impulse=patch->samples[D_001AD5A4][row*16+column];
                } else impulse+=patch->samples[D_001AD5AC][row*16+column];
                page=D_001AD5A4;
                patch->samples[D_001AD5A4][row*16+column]=impulse;
                if(row<2 && patch->neighbor[0]!=255) {
                    if(row==0) patches[patch->neighbor[0]].samples[page][288+column]=patch->samples[page][row*16+column];
                    else patches[patch->neighbor[0]].samples[page][320+column]=impulse;
                }
                if(column<2 && patch->neighbor[1]!=255) {
                    if(column==0) patches[patch->neighbor[1]].samples[D_001AD5A4][304+row]=patch->samples[D_001AD5A4][row*16+column];
                    else patches[patch->neighbor[1]].samples[D_001AD5A4][336+row]=patch->samples[D_001AD5A4][row*16+column];
                }
                if(row==15 && patch->neighbor[2]!=255)
                    patches[patch->neighbor[2]].samples[D_001AD5A4][256+column]=patch->samples[D_001AD5A4][row*16+column];
                if(column==15 && patch->neighbor[3]!=255)
                    patches[patch->neighbor[3]].samples[D_001AD5A4][272+row]=patch->samples[D_001AD5A4][row*16+column];
                if(patch->neighbor[4]!=255) {
                    if(column==0 && row==0) patches[patch->neighbor[4]].samples[D_001AD5A4][355]=patch->samples[D_001AD5A4][0];
                    if(column==1 && row==0) patches[patch->neighbor[4]].samples[D_001AD5A4][356]=patch->samples[D_001AD5A4][1];
                    if(column==0 && row==1) patches[patch->neighbor[4]].samples[D_001AD5A4][357]=patch->samples[D_001AD5A4][16];
                }
                if(patch->neighbor[5]!=255 && column==15 && row==0)
                    patches[patch->neighbor[5]].samples[D_001AD5A4][354]=patch->samples[D_001AD5A4][15];
                if(patch->neighbor[6]!=255 && column==0 && row==15)
                    patches[patch->neighbor[6]].samples[D_001AD5A4][353]=patch->samples[D_001AD5A4][240];
                if(patch->neighbor[7]!=255 && column==15 && row==column)
                    patches[patch->neighbor[7]].samples[D_001AD5A4][352]=patch->samples[D_001AD5A4][255];
            }
        }
    }
}
