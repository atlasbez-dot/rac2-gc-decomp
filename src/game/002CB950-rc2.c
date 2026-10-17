
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

struct S18A000 {
    s16 a;
    s8 pad[10];
};
extern struct S18A000 D_0018A000;
extern s32 D_001AA420;
extern s32 D_001AA428;
extern s8 D_0025BA90[];
extern void func_0028B338(s32);
extern void func_002B49C0(s32);
extern s32 func_002B49E0(s32, s32, s32, s32, s32);
extern s32 func_002D5B38(s32, s8 *);

s32 func_002CB950(s32 arg0) {
    s32 r;

    r = 0;
    switch (arg0) {
    case 0:
        D_0018A000.a = 10;
        r = 1;
        break;
    case 1:
        r = 1;
        D_0018A000.a = 10;
        if (D_001AA420 != 0) {
            func_0028B338(0);
            ((void (*)(s32))D_001AA420)(0);
            func_0028B338(1);
        }
        break;
    case 2:
        r = 1;
        D_0018A000.a = 10;
        if (D_001AA428 != 0) {
            func_0028B338(0);
            ((void (*)(s32))D_001AA428)(0);
            func_0028B338(1);
        }
        break;
    case 3:
        r = func_002D5B38(3, D_0025BA90);
        break;
    case 4:
        if (func_002B49E0(4, 2, 8, 4, 0) == 0) {
            func_002B49C0(3);
            r = 1;
        }
        break;
    }
    return r;
}
