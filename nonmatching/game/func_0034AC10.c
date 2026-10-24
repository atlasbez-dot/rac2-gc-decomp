/*
 * 256-byte plain-C draft. tools/check.py reports 0/28 in USA v1.01, PAL,
 * and USA v2.00. The first diff is at +0x18: the draft loads the position
 * pointer into $a0, while retail loads it into $v1. The helper/timer tail
 * matches in the instruction diff. `nosda` on the four external floats did
 * not change the generated code.
 */
extern float *func_00335E10(char *);
extern void func_0034AA30(char *);
extern void func_00349680(char *, int);
extern float ref_L00_001AEAC8_00;
extern float ref_L00_001AEACC_00;
extern float ref_L00_001AEAD0_00;
extern float ref_L00_001AEAD4_00;
extern void func_00349630(char *, int);

void func_0034AC10(char *self)
{
    float *out = func_00335E10(self + 0x5C);

    out[0] = ref_L00_001AEAC8_00 + (*(float **)(self + 8))[0];
    out[1] = ref_L00_001AEACC_00 + (*(float **)(self + 8))[1];

    out = func_00335E10(self + 0xA8);
    out[0] = ref_L00_001AEAD0_00 + (*(float **)(self + 8))[0];
    out[1] = ref_L00_001AEAD4_00 + (*(float **)(self + 8))[1];

    func_0034AA30(self);
    func_00349680(self + 0x140, 1);

    if (*(int *)(self + 0x3F4) != 0) {
        int remaining = *(int *)(self + 0x3F4) - 1;
        *(int *)(self + 0x3F4) = remaining;
        if (remaining == 0) {
            *(int *)(self + 0x0C) = 0;
            *(int *)(self + 0x3F8) = 0;
            *(int *)(self + 0x400) = 1;
            func_00349630(self + 0x1D4, -1);
            func_00349630(self + 0x25C, -1);
            func_00349630(self + 0x2E4, -1);
            func_00349630(self + 0x36C, -1);
        }
    }
}
