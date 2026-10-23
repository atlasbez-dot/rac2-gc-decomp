#include "include_asm.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern unsigned char *D_L00_001B1E9C[] __attribute__((sda));
extern unsigned char *D_L00_001B1EA4[] __attribute__((sda));
extern unsigned char *D_L00_001B26B8[] __attribute__((sda));


void func_L00_0037FF98(void)
{
    unsigned char *cursor=D_L00_001B1E9C[0];
    int count=0;
    if ((unsigned int)cursor <= (unsigned int)D_L00_001B1EA4[0]) {
        do {
            if (*(short *)(cursor+0xAA)==0x135F) {
                D_L00_001B26B8[count++]=cursor;
                if(count>=16) break;
            }
            cursor+=0x100;
        } while ((unsigned int)cursor <= (unsigned int)D_L00_001B1EA4[0]);
    }
    while(count<16) D_L00_001B26B8[count++]=0;
}
