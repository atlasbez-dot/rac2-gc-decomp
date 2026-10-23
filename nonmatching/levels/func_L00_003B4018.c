/* Retained C reconstruction, 2026-10-23. Not linked or counted.
   Profile: -O2 -G8 -ffunction-sections
   USA: 344/380 bytes, 0/27 placements; size differs from retail.
   us: 0/27, pal: absent, us2: 0/27.
   Revisit reset-loop scheduling and the free-event scan.
*/
typedef struct { int time; short counter,delay,active,pad; } Event;
extern Event D_L00_0023D960[10];
extern int D_L00_001AF8F0 __attribute__((sda));
extern int D_L00_001AF8F4 __attribute__((sda));
extern float D_L00_001AF8F8 __attribute__((sda));
extern float D_L00_001AF934 __attribute__((sda));
extern short D_L00_001AF938 __attribute__((sda));
extern int D_L00_001B28A0 __attribute__((sda));
extern int D_L00_001B28A4;
extern int D_L00_001B28A8 __attribute__((sda));
extern float D_L00_001B28AC;

extern int func_00283CF0(float);
extern float func_00283CE0(int);
extern int func_00282948(int *);
extern int func_00282978(void *);

void func_L00_003B4018(void)
{
    Event *event;
    if(D_L00_001AF8F0) {
        int i;
        short *active=(short *)((char *)D_L00_0023D960+0x74);
        for(i=9;i>=0;i--,active-=6) *active=0;
        D_L00_001AF8F0=0;
        D_L00_001B28A0=0;
        D_L00_001B28A8=func_00283CF0(D_L00_001AF8F8/(D_L00_001AF934*(1.0f/60.0f)));
        D_L00_001B28AC=1.0f/func_00283CE0(D_L00_001B28A8);
    }
    if(!D_L00_001B28A4 && func_00282948(&D_L00_001B28A0)) {
        int next=D_L00_001B28A0;
        short delay=D_L00_001AF938,counter=*(short *)&D_L00_001B28A8;
        int time=D_L00_001AF8F4;
        for(event=D_L00_0023D960;event<D_L00_0023D960+10;event++) {
            if(!event->active) {
                event->delay=delay;
                event->active=1;
                event->counter=counter;
                next=time;
                break;
            }
        }
        D_L00_001B28A0=next;
    }
    event=D_L00_0023D960;
    do {
        if(event->active && func_00282978(&event->counter)) event->active=0;
        event++;
    }while(event<D_L00_0023D960+10);
}
