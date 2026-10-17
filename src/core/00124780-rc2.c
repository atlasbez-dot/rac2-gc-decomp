
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

extern s32 func_0011AC20(s32 *);

extern volatile s32 D_001363A8;
extern volatile s32 D_001363AC;
extern volatile s32 D_001363A0;
extern volatile s32 D_001363B0;

void func_00124780(void) {
    s32 sp[8];

    if (D_001363A8 != -1) {
        if (D_001363AC != -1) {
            return;
        }
    }
    sp[5] = 0;
    sp[2] = 1;
    sp[1] = 1;
    D_001363A8 = func_0011AC20(sp);
    D_001363AC = func_0011AC20(sp);
    sp[2] = 0;
    D_001363A0 = func_0011AC20(sp);
    D_001363B0 = 0;
}
