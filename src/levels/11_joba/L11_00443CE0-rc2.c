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

extern s32 ref_L11_00443CE0_00[];

s32 func_L11_00443CE0(s32 arg0) {
    static void *jt[] = {
        &&L_c0, &&L_c1, &&L_c2, &&L_c3, &&L_c4, &&L_c5, &&L_c6,
        &&L_c7, &&L_c8, &&L_c9, &&L_c10, &&L_c11, &&L_c12,
    };
    void *h ;

    if (0) {
        h = jt[0];
    }
    if ((u32)arg0 >= 13) {
        goto L_def;
    }
    h = (void *)ref_L11_00443CE0_00[arg0];
    goto *h;
L_c0:
    return 0x2F66;
L_c1:
    return 0x2F67;
L_c2:
    return 0x2F68;
L_c3:
    return 0x2F69;
L_c4:
    return 0x2F6A;
L_c5:
    return 0x2F6B;
L_c6:
    return 0x2F6C;
L_c7:
    return 0x2F6D;
L_c8:
    return 0x2F70;
L_c9:
    return 0x2F71;
L_c10:
    return 0x3243;
L_c11:
    return 0x3244;
L_c12:
    return 0x3245;
L_def:
    return 0x2F66;
}
