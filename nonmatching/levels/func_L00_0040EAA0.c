/* Re-measured 26 October 2026 (fam5to9) under the TImode/2.95.3-gcse compiler: 1540/1540 bytes
 * at -O2 -G0 (365/385 opcodes; -G8 gives 1528). Frame is still 0x60 vs retail 0x50. New: the
 * unlock==-1 test in case 0 is now beq where retail has beql (reload of object[0xb0] in the
 * likely slot). Retail loads D_001A79F0 once into $a3 and the speech index into $a2 before the
 * speech loop and re-reads both at the loop bottom into $t1/$t0 (the error call's 4th/5th
 * arguments), with the bitset address/shift-one rematerialised inside the !force arm.
 */
/* Sonnet pass 2 (family seed F7): 1532 vs 1540 bytes now, frame still 0x60 vs 0x50. Findings: (1) func_0026FEB8 must be declared (const char *,...); the K&R () declaration added a 0x10 outgoing-arg area. (2) Assigning the mask to a local inside the condition, bit=1u<<(entry&31), stops fold-const turning (x&(1<<n)) into (x>>n)&1 and gives the retail sllv/and. (3) Still different: retail keeps the constant 1 and the bitset address inside the !force arm (not hoisted) and hoists the D_L00_001BEFC0 high part into $fp, with empty/complete in $s5/$s6; mine spills empty and hoists 1 into $fp. Retail's error call also reloads level/index through $t1/$t0 copies. Needs loop.c invariant-motion research or the permuter. Earlier header: 1540 bytes, retail 1540; six bounded C variants. Frame 0x60 vs retail 0x50: invariant bitset base or shift-one is retained across calls and the empty flag spills. Bit-mask lowering and branch-likely scheduling differ. Not linked. */
typedef struct { char pad[0x2290]; unsigned char *moby; int state; char pad2[0x234]; int count; } InteractionPlayer;
extern InteractionPlayer D_00189E20;
extern char D_00189EA0[];
extern int func_002ACBC8(void *,int);
/* Scripted interaction state machine: validate speech, grant rewards and release the trigger. */
typedef union {
    unsigned int word;
    struct { signed char speech; unsigned char force, unused, played; } flags;
} InteractionFlags;
typedef struct {
    int trigger, camera;
    unsigned char speech_index;
    signed char unlock;
    unsigned char activated;
    signed char sound;
    InteractionFlags tail;
} InteractionVars;
extern unsigned char D_001A7BC8[], D_0019B2E8[];
extern int D_001A79F0 __attribute__((sda));
extern int D_L00_001A8F00 __attribute__((sda));
extern int D_L00_001B19C8 __attribute__((sda));
extern char *D_L00_001B1F8C __attribute__((sda));
extern short **D_L00_0029FC60[];
extern unsigned int D_00139768[];
extern char D_L00_001BEFC0[], D_L00_001B1210[], D_L00_002A2CC0[];
extern void func_0029F338(void *),func_002A7750(void *,int,int);
extern int func_002B38B8(void *),func_002F5D10(void),func_00288AA0(void *,int);
extern void func_0026FEB8(const char *,...);
extern void func_00288BE8(void *,int),func_002F5CC8(void);
extern void func_L00_002B9D60(void *,void *,int,int);
extern void func_002AD7B8(int),func_002AF0A8(int),func_002A0430(int);
extern void func_002DF3F8(void *,void *),func_00288CB0(int,int),func_0029B3E0(int,int);
void func_L00_0040EAA0(unsigned char *object) {
    InteractionVars *vars=*(InteractionVars **)(object+0x68);
    int complete, empty, changed, i, entry; unsigned int bit;

    switch(object[0x20]) {
    case 0:
        if ((vars->unlock!=-1 && D_001A7BC8[vars->unlock]) ||
            (object[0xb0]!=255 && (D_0019B2E8[object[0xb0]+(D_001A79F0<<4)]&0x80))) {
            func_0029F338(object); return;
        }
        func_002A7750(object,1,-1);
        /* Fall through: initialization can activate the trigger immediately. */
    case 1:
        if(!vars->activated && !func_002B38B8(object) && !object[0xbc]) return;
        vars->activated=1;
        func_002A7750(object,2,-1);
        /* Fall through. */
    case 2:
        if(!vars->activated) { func_002A7750(object,1,-1); break; }
        if(D_00189E20.state==28 || D_00189E20.count<1 || D_L00_001A8F00) return;
        if(vars->trigger!=-1 && !func_002ACBC8((char *)&D_00189E20+0x80,vars->trigger)) return;
        complete=1; empty=1;
        if(D_L00_0029FC60[D_001A79F0] && D_L00_0029FC60[D_001A79F0][vars->speech_index]) {
            i=0;
            if(D_L00_0029FC60[D_001A79F0][vars->speech_index][i]!=-1) {
                empty=0;
                do {
                    entry=D_L00_0029FC60[D_001A79F0][vars->speech_index][i];
                    if(vars->tail.flags.force || !(D_00139768[(unsigned int)entry>>2]&(bit=1u<<(entry&31)))) {
                        if(!func_00288AA0(D_L00_001BEFC0,entry) && i==0) {
                            func_0026FEB8(D_L00_002A2CC0,*(short *)(object+0xaa),*(short *)(object+0xb2),D_001A79F0,vars->speech_index,entry);
                            return;
                        }
                        complete=0;
                    }
                    ++i;
                } while(D_L00_0029FC60[D_001A79F0][vars->speech_index][i]!=-1);
            }
        }
        if(empty) func_0026FEB8(D_L00_001B1210,D_001A79F0,vars->speech_index);
        if(complete) { vars->tail.flags.played=0; func_002A7750(object,4,-1); }
        else {
            vars->tail.flags.played=1;
            func_00288BE8(D_L00_001BEFC0,4);
            if(D_L00_001B19C8<5 || (D_001A79F0==6 && vars->speech_index==0)) func_002F5CC8();
            func_002A7750(object,3,-1);
        }
        break;
    case 3:
        if(!func_002F5D10()) {
            if(vars->camera!=-1) { char *camera;
                camera=D_L00_001B1F8C+(vars->camera<<7);
                func_L00_002B9D60(camera+0x30,camera+0x70,0,1);
            }
            func_002A7750(object,4,-1);
        }
        if(D_001A79F0 || vars->unlock==-1 || func_002F5D10()) return;
        changed=0;
        if(vars->unlock!=-1) {
            func_002AD7B8(vars->unlock); changed=1;
            if(vars->unlock!=24) func_002AF0A8(vars->unlock);
        }
        if(object[0xb0]!=255 && !(D_0019B2E8[object[0xb0]+(D_001A79F0<<4)]&0x80)) {
            changed=1;func_002A0430(object[0xb0]);
        }
        if(vars->sound && (vars->tail.word&0xffff0000U)) {
            if(vars->camera!=-1) { char *camera;
                camera=D_L00_001B1F8C+(vars->camera<<7);
                func_002DF3F8(camera+0x30,camera+0x70);
            } else func_002DF3F8(object+0x10,object+0xf0);
        }
        if(vars->tail.flags.speech!=-1) func_00288CB0(vars->tail.flags.speech,1);
        else if(changed || vars->tail.flags.played) func_0029B3E0(0,-1);
        break;
    case 4: {
        int changed=0;
        if(vars->unlock!=-1) {
            func_002AD7B8(vars->unlock); changed=1;
            if(vars->unlock!=24) func_002AF0A8(vars->unlock);
        }
        if(object[0xb0]!=255 && !(D_0019B2E8[object[0xb0]+(D_001A79F0<<4)]&0x80)) {
            changed=1;func_002A0430(object[0xb0]);
        }
        if(vars->sound>0 && (vars->tail.word&0xffff0000U)) {
            if(vars->camera!=-1) { char *camera;
                camera=D_L00_001B1F8C+(vars->camera<<7);
                func_002DF3F8(camera+0x30,camera+0x70);
            } else func_002DF3F8(D_00189EA0,D_00189EA0+0x10);
        }
        if(vars->tail.flags.speech!=-1) func_00288CB0(vars->tail.flags.speech,1);
        else if((changed || vars->tail.flags.played) && vars->sound!=-1) func_0029B3E0(0,-1);
        func_0029F338(object);
        break;
    }
    }
}
