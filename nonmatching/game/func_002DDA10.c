/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -mno-split-addresses.
 * Reported final C / retail: 1156 / 1184 bytes; size equality is not a match.
 * us: 0/28 placements; 1156/1184 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: The0xA0 frame matches. All four records, time/score/date formatting branches and real promoted variadic inputs are retained. Mixed GP/absolute UI coefficients and long-lived record/context allocation differ.
 * Reopening condition: Recover the original save-record pointer scopes and exact GP coefficient declarations; do not reproduce decompiler HI-register artifacts.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched. boot: 1156 bytes, expected 1184.
 * Profile: -O2 -G8 -ffunction-sections -mno-split-addresses
 * The0xA0 frame matches. All four records, time/score/date formatting branches and real promoted variadic inputs are retained. Mixed GP/absolute UI coefficients and long-lived record/context allocation differ.
 * Reopen: Recover the original save-record pointer scopes and exact GP coefficient declarations; do not reproduce decompiler HI-register artifacts.
 * US placement check: 0/28. No linked-build or runtime claim.
 */
#include "common.h"
extern int D_001A7420;
extern u8 D_001393E0[];
extern u8 D_001F2840[];
extern int D_001ABBF0 __attribute__((sda)),D_001ABBF4 __attribute__((sda)),D_001ABBF8 __attribute__((sda)),D_001ABBFC __attribute__((sda));
extern int D_001ABC00 __attribute__((sda)),D_001ABC04 __attribute__((sda)),D_001ABC08 __attribute__((sda));
extern int D_001ABC10 __attribute__((sda)),D_001ABC14 __attribute__((nosda)),D_001ABC18 __attribute__((sda)),D_001ABC1C __attribute__((nosda)),D_001ABC20 __attribute__((sda));
extern char D_001ABC28[] __attribute__((sda)),D_001ABAF0[] __attribute__((sda)),D_001ABB20[] __attribute__((sda)),D_001ABC38[] __attribute__((sda)),D_001ABC48[] __attribute__((sda));
extern void func_0027C540(int),func_0027C660(void),func_0028E868(int,int,int,int,int,int),func_0027F5B8(int,int,int,u8 *,int);
extern int func_0028E588(int,int),func_00288FB8(int),func_0027FB40(int,int,int,u8 *,int),func_00115DA8(char *,char *,...);
int func_002DDA10(u8 *menu)
{
    char text[80];
    u8 *record;
    int y,hours,minutes,score,extra,color,i;
    if (D_001A7420==10) return 2;
    y=*(int *)(menu+0x1c);func_0027C540(0);
    func_0028E868(func_0028E588(0xeaa9,0),D_001ABC10,D_001ABC14,D_001ABC18,D_001ABC1C,D_001ABC20);
    for(i=0;i<4;i++) {
        record=D_001393E0+0x30+i*28;
        if ((*(int *)(D_001393E0+0x15c))<3 && (*(int *)(D_001393E0+0x164))<0 && *(int *)(D_001F2840+0x164)>10 && (*(int *)(D_001393E0+8))==2) {
            if (*(int *)record!=-1) {
                hours=*(int *)(record+12)/216000;minutes=*(int *)(record+12)/3600-hours*60;
                color=0x80f0f0f0;if (*(int *)(menu+0x40)==i) color=0x70fffeed;
                if (hours>99) {hours=99;minutes=59;}
                func_00115DA8(text,D_001ABC28,hours,minutes);
                func_0028E868(func_0028E588(0xe99d,3),D_001ABC04+4,y+D_001ABC08,D_001ABBF8,D_001ABBFC,128);
                func_0027F5B8(D_001ABC04+D_001ABBFC+6,y+D_001ABC08,color,(u8 *)text,-1);
                if (*(int *)(record+8)) {
                    func_0028E868(func_0028E588(0xe99d,4),D_001ABC04+D_001ABC00,y+D_001ABC08,D_001ABBF8,D_001ABBFC,128);
                    extra=*(int *)(record+8);if (extra>99) extra=99;
                    func_00115DA8(text,D_001ABAF0,extra);
                    func_0027F5B8(D_001ABC04+D_001ABBFC+2+D_001ABC00,y+D_001ABC08,color,(u8 *)text,-1);
                }
                score=*(int *)(record+4);if (score>9999999) score=9999999;y+=D_001ABBF0;
                if (score<1000) func_00115DA8(text,D_001ABAF0,score);
                else if (score<1000000) func_00115DA8(text,D_001ABB20,score/1000,score%1000);
                else func_00115DA8(text,D_001ABC38,score/1000000,(score%1000000)/1000,score%1000);
                func_0028E868(func_0028E588(0x7567,0),D_001ABC04+4,y+D_001ABC08,D_001ABBF8,D_001ABBFC,128);
                func_0027F5B8(D_001ABC04+D_001ABBFC+6,y+D_001ABC08,color,(u8 *)text,-1);
                y+=D_001ABBF0;
                func_00115DA8(text,D_001ABC48,record[0x16],record[0x15],record[0x17]);
                func_0028E868(func_0028E588(0xe99d,2),D_001ABC04+4,y+D_001ABC08,D_001ABBF8,D_001ABBFC,128);
                func_0027F5B8(D_001ABC04+D_001ABBFC+6,y+D_001ABC08,color,(u8 *)text,-1);
                y+=D_001ABBF0;
            } else {
                y+=D_001ABBF0;
                func_0027FB40(*(int *)(menu+0x18)+*(int *)(menu+0x20)/2,y+D_001ABC08,0x80f0f0f0,(u8 *)func_00288FB8(0x2f14),-1);
                y+=D_001ABBF0*2;
            }
        } else y+=D_001ABBF0*3;
        y+=D_001ABBF4;
    }
    func_0027C660();return 2;
}
