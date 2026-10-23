/* Retained C reconstruction, 2026-10-23. Not linked or counted.
   Profile: -O2 -G8 -ffunction-sections
   USA: 336/328 bytes, 0/27 placements; size differs from retail.
   us: 0/27, pal: 0/27, us2: 0/27.
   Revisit descriptor stack layout and linked-list guard placement.
*/
typedef struct { float point[3]; float radius; char *source; int flags; unsigned char kind,unknown; unsigned short type; int result; int extra; } Collision;
extern int D_L00_001B19C8;
extern float D_L00_001AF8C0 __attribute__((sda));
extern int D_0018C0B0;
extern char *D_L00_001B1EA8 __attribute__((sda));
extern void func_00282C88(void *);
extern void func_00277F48(void *,int,int,void *,float);
extern float func_00282E48(void *,void *);
extern void func_L00_00381F78(char *,char *);

void func_L00_003B3AF8(char *object)
{
    Collision collision;
    float *position=(float *)(object+0x10);
    if(D_L00_001B19C8&1) {
        char *node;
        collision.source=object;
        collision.type=*(unsigned short *)(object+0xaa);
        collision.kind=8;
        collision.flags=0x10000;
        collision.unknown=0;
        collision.result=0;
        func_00282C88(collision.point);
        collision.radius=5627.9248046875f;
        collision.extra=0;
        func_00277F48(position,0,D_0018C0B0,&collision,D_L00_001AF8C0);
        if(D_L00_001B19C8&1) {
            node=D_L00_001B1EA8;
            while(node) {
                unsigned char kind=(unsigned char)node[0x20];
                if(kind==254 || kind==253) break;
                if(node && *(char **)(node+0x24) && *(short *)(*(char **)(node+0x24)+0x46)==19) {
                    if(func_00282E48(node+0x10,position)<D_L00_001AF8C0) func_L00_00381F78(node,object);
                }
                node=*(char **)(node+0x28);
            }
        }
    }
}
