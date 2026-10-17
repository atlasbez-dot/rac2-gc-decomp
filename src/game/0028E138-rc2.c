
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

extern s32 func_0028E2A8();
extern s32 func_0028B4D8();
extern s8 D_00255330[];

s32 func_0028E138(s32 arg0) {
    s32 var_s1;
    s32 var_s0;
    s32 temp_s3;
    s32 temp_v0;
    s32 temp_v1;
    void (*temp_fn)(s32);

    var_s1 = 0;
    func_0028E2A8();
    var_s0 = (s32) D_00255330;
    temp_s3 = var_s0 + 0x750;
    do {
        temp_v0 = *(s32 *)(var_s0 + 4);
        if (((temp_v0 & 0x10) != 0) || (*(s32 *)0x1B1874 != 0)) {
            if (*(s32 *)(var_s0 + 0x7C) < 10) {
                *(s32 *)(var_s0 + 0x7C) = 10;
            }
        }
        temp_v0 = *(s32 *)(var_s0 + 0x7C);
        if (temp_v0 > 0) {
            temp_v0 = temp_v0 - 1;
            *(s32 *)(var_s0 + 0x7C) = temp_v0;
        }
        if (temp_v0 > 0) {
            temp_v1 = *(s32 *)(var_s0 + 0x6C);
            var_s1 += 1;
            if (temp_v1 < 0x1E) {
                *(s32 *)(var_s0 + 0x6C) = temp_v1 + 1;
            }
        } else {
            temp_v1 = *(s32 *)(var_s0 + 0x6C);
            if (temp_v1 >= -5) {
                *(s32 *)(var_s0 + 0x6C) = temp_v1 - 1;
            }
        }
        temp_v0 = *(s32 *)(var_s0 + 0x68);
        if (temp_v0 != 0 && *(s32 *)(var_s0 + 0x6C) == -6) {
            func_0028B4D8(var_s0);
        }
        if (arg0 != 0) {
            temp_fn = (void (*)(s32)) *(s32 *)(var_s0 + 0x14);
            if (temp_fn != 0) {
                temp_fn(var_s0);
            }
        }
        var_s0 += 0x90;
    } while (var_s0 < temp_s3);
    return var_s1;
}
