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

extern void ref_L04_0039FEF0_00(s32, void *);
extern void ref_L04_0039FEF0_01(s32, s32, s32, void *);
extern f32 ref_L04_0039FEF0_02 __attribute__((sda));
extern s32 ref_L04_0039FEF0_03 __attribute__((sda));
extern s32 ref_L04_0039FEF0_04 __attribute__((sda));
extern s32 ref_L04_0039FEF0_05 __attribute__((sda));


void func_L04_0039FEF0(void *arg0, s32 arg1) {
    s32 index;
    s32 temp;
    s32 temp2;
    s8 *record ;
    s32 one ;
    s32 stride ;
    f32 highRate ;
    f32 lowRate ;
    s32 offset ;

    index = 0;
    if (arg1 > 0) {
        highRate = 0.35f;
        one = 1;
        lowRate = 0.00625f;
        stride = 0x5C0;
        record = (s8 *)arg0;
        do {
            if (*(u16 *)(record + 0x1E) != 0) {
                if (*(s32 *)(record + 0x48) != 0) {
                    ref_L04_0039FEF0_03 = one;
                    ref_L04_0039FEF0_02 = highRate;
                } else {
                    ref_L04_0039FEF0_03 = 0;
                    ref_L04_0039FEF0_02 = lowRate;
                }
                offset = ref_L04_0039FEF0_04;
                offset = offset * stride;
                offset += 0x50;
                ref_L04_0039FEF0_00(0x70000000, record + offset);
                ref_L04_0039FEF0_01(0x70000000, index, ref_L04_0039FEF0_05, arg0);
            }
            index++;
            record += 0x1190;
        } while (index < arg1);
    }
    temp = ref_L04_0039FEF0_04;
    ref_L04_0039FEF0_04 = ref_L04_0039FEF0_05;
    ref_L04_0039FEF0_05 = temp;
    ref_L04_0039FEF0_02 = 0.00625f;
    ref_L04_0039FEF0_03 = 0;
}
