
/* SPDX-License-Identifier: MIT
 * MIT License
 * 
 * Copyright (c) 2026 RC2 decomp contributions
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "common.h"

extern f32 ref_L00_003F59F0_00 __attribute__((sda));
extern f32 ref_L00_003F59F0_01 __attribute__((sda));
f32 ref_L00_003F59F0_02(f32, f32);
void ref_L00_003F59F0_03(void *, s32);
s32 ref_L00_003F59F0_04(void *);
s32 ref_L00_003F59F0_05(s32, s16);

s32 func_L00_003F59F0(void *arg0) {
    void *temp_s4;
    void *temp_s2;
    void *var_s0;
    s16 temp_s3;
    s32 var_s1;
    s32 tb;
    f32 temp_f1;

    var_s1 = 0;
    temp_s4 = (*(void **)((char *)(arg0) + (0x68)));
    tb = ref_L00_003F59F0_05(0xC04, (*(s16 *)((char *)(temp_s4) + (0x1A))));
    temp_s3 = (*(s16 *)((char *)(temp_s4) + (0x20)));
    temp_s2 = (void *)*(s32 *)(((*(s16 *)((char *)(temp_s4) + (0x18))) * 4) + tb);
    if (temp_s3 > 0) {
        var_s0 = temp_s2;
        do {
            (*(f32 *)((char *)(var_s0) + (0x20))) = ref_L00_003F59F0_02((*(f32 *)((char *)(var_s0) + (0x20))), (*(f32 *)((char *)(var_s0) + (0x28))));
            ref_L00_003F59F0_03(temp_s2, var_s1);
            var_s1 += 1;
            var_s0 = (s8 *)var_s0 + 0x30;
        } while (var_s1 < temp_s3);
    }
    if ((ref_L00_003F59F0_00 > 7.0f) || (ref_L00_003F59F0_00 < -7.0f)) {
        ref_L00_003F59F0_00 = 0.0f;
    }
    temp_f1 = ref_L00_003F59F0_00 - ref_L00_003F59F0_01;
    ref_L00_003F59F0_00 = temp_f1;
    if (temp_f1 <= -4.0f) {
        ref_L00_003F59F0_00 = temp_f1 + 4.0f;
    }
    return ref_L00_003F59F0_04((s8 *)temp_s4 + 0x22) == 0;
}
