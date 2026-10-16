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

extern s32 func_0026F7C8();
extern s32 func_0026F7D0();
extern s32 func_0026F7D8();
extern s32 func_0026F7E0();
extern s32 func_0026F7E8();
extern s32 func_0026F7F0();
extern s32 func_0029C168();
extern s32 func_002CB7D0();
extern s32 func_002CB820();
extern s32 func_002CB8A0();
extern s32 func_002CB950();
extern s32 func_002CBA58();
extern s32 func_002E5E58();
extern s32 D_00138344;

s32 func_002CD0E8(void) {
    s32 temp_s0;
    s32 var_s0;

    var_s0 = 0;
    if (D_00138344 & 0x910) {
        var_s0 = 1;
    } else if (D_00138344 & 0x40) {
        temp_s0 = func_0029C168(D_00138344);
        if ((func_0026F7C8() != 0) && (func_0026F7D0() != 0)) {
            var_s0 = func_002CB950(temp_s0);
        } else if (func_0026F7E0() != 0) {
            var_s0 = func_002CB820(temp_s0);
        } else if (func_0026F7D8() != 0) {
            var_s0 = func_002CBA58(temp_s0);
        } else if ((func_0026F7F0() == 0x31) || (func_0026F7E8() != 0) || (func_0026F7F0() == 0x1C)) {
            var_s0 = func_002CB7D0(temp_s0);
        } else {
            var_s0 = func_002CB8A0(temp_s0);
        }
    } else {
        func_0029C168(D_00138344);
    }
    if (var_s0 != 0) {
        func_002E5E58(0x12, 0, 0);
    }
    return var_s0;
}
