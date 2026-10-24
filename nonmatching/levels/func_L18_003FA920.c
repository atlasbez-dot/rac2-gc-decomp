/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections.
 * Prior worker coverage: US 0/3; US2 0/3; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Historical analysis (summary).
 * Historical screening catalogued calls, vector operations and data addressing without a
 * complete manual reconstruction. Its generated call/address lists and decoded instruction
 * header remain private. The dated manual reconstruction and recorded worker profile below
 * supersede that screening; no unsupported impossibility or handwritten classification is
 * carried forward.
 */

/* Wave4 manual reconstruction, 2026-10-23. Nonmatching; historical screening above
   is summarized; generated listings and unsupported classifications remain private.
   Trial source: src/levels/shared/L18_003FA920-groups.c
   Profile: -O2 -G0 -ffunction-sections
   Four group scans retained with real table entries and15-bit IDs; helper third pointer argument retains canonical signature via explicit32-bit group conversion.
   us: func_L18_003FA920: 0 of 3 places match (src/levels/shared/L18_003FA920-groups.c), exit 1; us2: func_L18_003FA920: 0 of 3 places match (src/levels/shared/L18_003FA920-groups.c), exit 1; pal: absent_from_catalogue, exit 1
*/
#include "common.h"
extern void *func_00115484(void *,int,unsigned int);
extern unsigned short *D_L18_001FB320[];
extern char *D_L18_001B281C;
extern int D_L18_001B2838;
extern float D_00189EA0[4];
extern float func_L02_002F21C0(void *,void *);
extern int func_L02_004127F8(unsigned char *);
extern void func_L18_003F8D28(void *,void *,void *);
extern void func_L18_003F7818(unsigned char *,unsigned char *,int);
extern int func_L18_003FB500(unsigned char *,int);
int func_L18_003FA920(char *owner,int slot)
{
    char *secondary[2];
    char *state=*(char **)(owner+0x68);
    char *source=0;
    char *selected=0;
    char *entity=0;
    unsigned short *entry;
    unsigned int group;
    int *id;
    func_00115484(secondary,0,8);
    id=(int *)(state+slot*4);
    group=*id;
    entry=D_L18_001FB320[group];
    while((group&0xff)!=0xff && (int)group<=D_L18_001B2838 && entry!=0 && ((short)entry[-1]>=0 || entry==D_L18_001FB320[*id])) {
        entity=D_L18_001B281C+(*entry&0x7fff)*0x100;
        if(entity==0) break;
        if(*(unsigned char *)(entity+0x20)!=0xfe && *(unsigned char *)(entity+0x20)!=0xfd && (*(unsigned short *)(entity+0x34)&1)!=0) { source=entity; break; }
        group=*id;
        entry++;
    }
    if(source==0) return 0;
    id=(int *)(state+0x20+slot*4);
    group=*id;
    entry=D_L18_001FB320[group];
    while((group&0xff)!=0xff && (int)group<=D_L18_001B2838 && entry!=0 && ((short)entry[-1]>=0 || entry==D_L18_001FB320[*id])) {
        entity=D_L18_001B281C+(*entry&0x7fff)*0x100;
        if(entity==0) break;
        if(entity!=secondary[0] && entity!=0 && *(unsigned char *)(entity+0x20)!=0xfe && *(unsigned char *)(entity+0x20)!=0xfd && (*(unsigned short *)(entity+0x34)&1)!=0) { secondary[0]=entity; break; }
        group=*id;
        entry++;
    }
    if(secondary[0]==0) return 0;
    id=(int *)(state+0x10+slot*4);
    group=*id;
    entry=D_L18_001FB320[group];
    while((group&0xff)!=0xff && (int)group<=D_L18_001B2838 && entry!=0 && ((short)entry[-1]>=0 || entry==D_L18_001FB320[*id])) {
        entity=D_L18_001B281C+(*entry&0x7fff)*0x100;
        if(entity==0) break;
        if(*(unsigned char *)(entity+0x31)!=0 && func_L02_002F21C0(D_00189EA0,entity+0x10)>16.0f && func_L02_004127F8((unsigned char *)entity)==0) { selected=entity; break; }
        group=*id;
        entry++;
    }
    if(selected==0) {
        group=*id;
        entry=D_L18_001FB320[group];
        while((group&0xff)!=0xff && (int)group<=D_L18_001B2838 && entry!=0 && ((short)entry[-1]>=0 || entry==D_L18_001FB320[*id])) {
            entity=D_L18_001B281C+(*entry&0x7fff)*0x100;
            if(entity==0) break;
            if(func_L02_004127F8((unsigned char *)entity)==0) { selected=entity; break; }
            group=*id;
            entry++;
        }
        if(selected==0) return 0;
    }
    func_L18_003F8D28(source,entity,(void *)*id);
    func_L18_003F7818((unsigned char *)secondary[0],(unsigned char *)source,0);
    func_L18_003FB500((unsigned char *)selected,1);
    return 1;
}
