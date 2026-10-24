/* Measured near miss: 292 bytes versus 280; 0/28 placements in each release. */
typedef struct {
    unsigned long long words[2];
} __attribute__((aligned(16))) ParserScratch;

extern unsigned char ref_L00_00291640_00[];
extern unsigned char ref_L00_00291640_01[];
extern unsigned char *func_002F4FA0(unsigned char *, unsigned char *, int, ParserScratch *, ParserScratch);
extern unsigned char *func_002E31E8(unsigned char *, unsigned char *, int, ParserScratch *, ParserScratch);
extern unsigned char *func_002F0B78(unsigned char *, unsigned char *, int, ParserScratch *, ParserScratch);

void func_00291640(int index)
{
    unsigned char *record = ref_L00_00291640_01 + index * 0x30;
    unsigned char *start = *(unsigned char **)(record + 0xC);
    unsigned char *end = start + 0x400;
    unsigned char *position;
    ParserScratch *scratch = (ParserScratch *)(ref_L00_00291640_00 + (index << 5) + 0x10);
    ParserScratch scratchCopy = *scratch;

    if (start < end) {
        *(short *)record = 0;
        position = func_002F4FA0(start, end, index, scratch, scratchCopy);
        *(short *)(record + 2) = (position - *(unsigned char **)(record + 0xC)) >> 1;
        if (position < end) {
            *(short *)(record + 4) = (position - *(unsigned char **)(record + 0xC)) >> 1;
            position = func_002E31E8(position, end, index, scratch, scratchCopy);
            *(short *)(record + 6) = ((position - *(unsigned char **)(record + 0xC)) >> 1) - *(unsigned short *)(record + 4);
            if (position < end) {
                *(short *)(record + 8) = (position - *(unsigned char **)(record + 0xC)) >> 1;
                position = func_002F0B78(position, end, index, scratch, scratchCopy);
                *(short *)(record + 0xA) = ((position - *(unsigned char **)(record + 0xC)) >> 1) - *(unsigned short *)(record + 8);
            }
        }
    }
}
