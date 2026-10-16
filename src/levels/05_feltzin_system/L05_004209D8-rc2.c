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

extern void ref_L05_004209D8_00(s32);
extern s32 ref_L05_004209D8_01(void *);
extern s32 ref_L05_004209D8_02(s32);
extern void ref_L05_004209D8_03(s32, s32);
extern void ref_L05_004209D8_04();
extern void ref_L05_004209D8_05(void *);
extern s32 ref_L05_004209D8_06 __attribute__((sda));

void func_L05_004209D8(void *arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = *(void **)((s8 *)arg0 + 0x68);
    if (ref_L05_004209D8_01((s8 *)temp_s0 + 0x48) == 0) {
        if (arg1 == 1) {
            ref_L05_004209D8_03(ref_L05_004209D8_02(0x31C9), -1);
        } else if (arg1 == 3) {
            ref_L05_004209D8_03(ref_L05_004209D8_02(0x31DE), -1);
        }
    } else {
        (*(s32 *)((s8 *)(temp_s0) + (0x48))) = 0x96;
        (*(s32 *)((s8 *)(temp_s0) + (0x44))) = 0x1C20;
        ref_L05_004209D8_00(0x1E);
        ref_L05_004209D8_05(arg0);
        ref_L05_004209D8_04();
        ref_L05_004209D8_06 = 0;
    }
}
