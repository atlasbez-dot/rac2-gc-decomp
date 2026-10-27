/* M33 2026-10-26: 464 -> 468/468 B, 97 -> 4 words, order only. Profile -O2 -G64 -Wa,-G64 -ffunction-sections (the 64-byte input table D_L00_001A93E0 is $gp-addressed in retail: sized sda; D_001A79F0 an incomplete sda array read [0] for its tied lui/lw). The context block is read directly as D_L00_001BCAC0.field (retail keeps its %hi in $s5 and adds %lo per use), the window test is written in-range-first with out = 0 in the else, and the do-while has its own counter. Left: the loop preheader order (retail: found+0x10, out, found+0xC0, %hi(D_L00_001B8DC0), in, n; here in and n come before found+0xC0): the probe-loop preheader family. In the permuter. */
/* Medium-tier attempt: 464 bytes versus468; base lifetime, hoisted count and register allocation differ; G8 address loop. */
typedef struct {
    char pad0[0x30]; int state, timer; char pad38[12]; short count; char pad46[10]; char *out; char pad54[0x138]; char *objects[1];
} Context;
extern int D_001A79F0[] __attribute__((sda));
extern char D_L00_001A93E0[64] __attribute__((sda));
extern char D_L00_001B8DC0[];
extern Context D_L00_001BCAC0;
extern char D_L00_0027E600[];
extern char D_L00_0027E620[];
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00283098(void *, void *, void *);

void func_L00_002FC7A8(void) {
    char temp[16];
    int low, high, which, i, n;
    char *found;
    char *out, *in;
    if (D_001A79F0[0] != 0) return;
    low=-1; high=9999; which=0;
    if (D_L00_001BCAC0.state == 0) { low = 220; high = 370; which = 1; }
    if (low == -1) return;
    if (D_L00_001BCAC0.timer >= low && D_L00_001BCAC0.timer <= high) {
        D_L00_001BCAC0.out = D_L00_0027E600;
        found=0;
        for (i=0; i < D_L00_001BCAC0.count; i++) {
            char *obj = D_L00_001BCAC0.objects[i];
            if (*(short *)(obj+0xAA) == 0xD54) { found = obj; break; }
        }
        if (found) {
            out = D_L00_0027E620; in = D_L00_001A93E0; n = 3;
            do {
                func_00283098(out,in,found+0xC0);
                func_00282CC0(out,out,found+0x10);
                func_00282CF0(temp,D_L00_001B8DC0,out);
                func_00282F20(temp,temp,0.15f);
                func_00282CC0(out,out,temp);
                in+=16; out+=16;
            } while (--n >= 0);
        }
        *(char **)(D_L00_001BCAC0.out+0x68)=D_L00_001BCAC0.objects[which];
    } else {
        D_L00_001BCAC0.out = 0;
    }
}
