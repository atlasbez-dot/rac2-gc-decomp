
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

s32 ref_L01_0035F640_00(s32, s32, s32, s32, s32);
extern s32 ref_L01_0035F640_01 __attribute__((sda));
extern s8 D_00188660[];
extern s32 ref_L01_0035F640_02;

s32 func_L00_0035F640(s32 arg0, s32 ignored_arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    void *temp_v1;

    if ((arg0 >= ref_L01_0035F640_02) || (arg0 == 0xFFFFFFFF)) {
        return -1;
    }
    temp_v0 = ref_L01_0035F640_00(ref_L01_0035F640_01 + (arg0 << 5), ignored_arg1, 0, arg2 + 0x40, arg3);
    if (temp_v0 >= 0) {
        temp_v1 = D_00188660 + (temp_v0 * 0x70);
        (*(s32 *)((char *)(temp_v1) + (0x8C))) = arg2;
        (*(s16 *)((char *)(temp_v1) + (0x7E))) = arg0;
    }
    return temp_v0;
}
