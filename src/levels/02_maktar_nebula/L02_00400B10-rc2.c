
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

extern void ref_L02_00400B10_00(void *);
extern void ref_L02_00400B10_01(void *);
extern void ref_L02_00400B10_02(void *);
extern void ref_L02_00400B10_03(void *);
extern void ref_L02_00400B10_04(void *);
extern void ref_L02_00400B10_05(void *);
extern void ref_L02_00400B10_06(void *);
extern void ref_L02_00400B10_07(void *);
extern void ref_L02_00400B10_08(void *);
extern s8 *ref_L02_00400B10_09;

void func_L02_00400B10(void) {
    s8 *s0;
    s32 v1;

    s0 = ref_L02_00400B10_09;
    while (s0 != 0) {
        v1 = *(s16 *)(s0 + 0xAA);
        switch (v1) {
        case 0xE7D:
            ref_L02_00400B10_00(s0);
            break;
        case 0xEB0:
            ref_L02_00400B10_01(s0);
            break;
        case 0xCB2:
            ref_L02_00400B10_02(s0);
            break;
        case 0xB02:
            ref_L02_00400B10_03(s0);
            break;
        case 0x1366:
            ref_L02_00400B10_04(s0);
            break;
        case 0x1367:
            ref_L02_00400B10_05(s0);
            break;
        case 0x326:
            ref_L02_00400B10_06(s0);
            break;
        case 0xA5C:
        case 0x1192:
            ref_L02_00400B10_07(s0);
            break;
        case 0xAE0: case 0xAE1: case 0xAE2: case 0xAEC: case 0xB06: case 0xB09:
        case 0xCC0: case 0xCC1: case 0xCC2: case 0xCC3: case 0xCC4: case 0xCC5:
        case 0xCC6: case 0xCC7: case 0xCC8: case 0xCC9: case 0xCDB:
            ref_L02_00400B10_08(s0);
            break;
        default:
            break;
        }
        s0 = *(s8 **)(s0 + 0x28);
    }
}
