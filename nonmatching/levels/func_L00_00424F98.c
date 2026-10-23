/* Nonmatching: 396 bytes versus 380; USA 0/27 placements.
 * Profile: -O2 -G0 -ffunction-sections.
 * +0x4: state-pointer allocation, resident scalar GP/absolute access and counter updates differ. Default split addresses improved 408 to 396 bytes. Reopen with the complete resident counter layout. */

extern float D_00138280,D_00138284;
extern int D_001A7BA8,D_001A7BA4,D_001A79F0;
extern unsigned int D_001A7390;
extern float D_L00_001A8904 __attribute__((sda)),D_L00_001B14C4 __attribute__((sda));
extern int D_L00_001B1580 __attribute__((sda)),D_L00_001B1584 __attribute__((sda));
typedef struct { char pad[0x60]; unsigned short count; unsigned short pad62; unsigned int best,flags; } Counter;
extern Counter D_0018C750;
void func_L00_00424F98(char *object,float *x,float *y)
{
    char *state=*(char **)(object+0x70)+0x1C0;
    if(*(unsigned int *)(state+0x10)&1) *x=0.0f;
    else { *x=D_00138280; if(D_001A7BA8==0) *x=-*x; }
    if(*x==0.0f) {
        D_L00_001B1580=0; D_L00_001B1584=0;
        if(*(float *)(state+0x1C)!=0.0f) *x=*(float *)(state+0x1C);
    } else {
        *(float *)(state+0x14)=D_L00_001A8904;
        if(D_0018C750.count<3) {
            D_L00_001B1580++;
            if(D_L00_001B1584==0 && D_L00_001B1580>=61) {
                unsigned int limit=D_001A7390;
                if(D_0018C750.count!=65535) { D_0018C750.count++; limit=D_001A7390; }
                if(D_0018C750.best<limit) D_0018C750.best=limit;
                D_L00_001B1584=1;
                D_0018C750.flags|=(1U<<D_001A79F0)|0x80000000U;
            }
        }
    }
    if(*(unsigned int *)(state+0x10)&2) *y=0.0f;
    else { *y=-D_00138284; if(D_001A7BA4==0) *y=D_00138284; }
    if(*y==0.0f) *y=*(float *)(state+0x24)/D_L00_001B14C4;
}
