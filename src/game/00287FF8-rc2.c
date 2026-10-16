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

extern s32 func_00287F60();
extern s8 D_00139568[];
extern s8 D_00239BA0[];

s32 func_00287FF8(s32 arg0, s32 arg1) {
    s32 var_a1;
    s32 var_s2;
    s32 var_s0;
    s32 tmp0;
    s32 tmp1;
    s32 tmp2;

    var_s2 = 0;
    var_s0 = arg0;
    if (func_00287F60(var_s0) >= arg1) {
        tmp0 = (var_s0 * 0xE0) + ((s32)D_00239BA0);
        if ((*(s16 *)((s8 *)(tmp0) + (0x4C))) != 0) {
            do {
                tmp1 = (var_s0 * 0xE0) + ((s32)D_00239BA0);
                var_s0 = (*(s16 *)((s8 *)(tmp1) + (0x4C)));
                tmp2 = (var_s0 * 0xE0) + ((s32)D_00239BA0);
            } while ((*(s16 *)((s8 *)(tmp2) + (0x4C))) != 0);
        }
        if (arg1 > 0) {
            var_a1 = arg1;
            do {
                var_a1 -= 1;
                tmp0 = (var_s0 * 0xE0) + ((s32)D_00239BA0);
                var_s0 = (*(s16 *)((s8 *)(tmp0) + (0x4A)));
            } while (var_a1 != 0);
        }
        var_s2 = 1;
        *(s8 *)(arg0 + ((s32)D_00139568)) = var_s0;
    }
    return var_s2;
}
