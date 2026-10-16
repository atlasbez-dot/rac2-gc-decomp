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

extern f32 ref_L02_003D1698_00(void *, void *, f32);
extern f32 ref_L02_003D1698_01(f32, f32);
extern f32 ref_L02_003D1698_02(f32, f32);
extern void ref_L02_003D1698_03(void *, s32, s32, s32);
extern void ref_L02_003D1698_04(void *, s32, s32);
extern s32 ref_L02_003D1698_05(s32);
extern s32 ref_L02_003D1698_06(void);

s32 func_L02_003D1698(void *arg0) {
    s8 *actor ;
    f32 var_f12;
    f32 var_f20;
    void *temp_a1;
    s8 *state ;
    void *temp_v0;

    actor = (s8 *)arg0;

    state = *(void **)(actor + 0x68);
    if (ref_L02_003D1698_06() != 0) {
        return 0;
    }
    temp_a1 = *(void **)((s8 *)state + 0x2E0);
    var_f20 = 100.0f;
    var_f12 = 1.0f;
    if (temp_a1 != 0) {
        var_f20 = ref_L02_003D1698_00((s8 *)actor + 0x10, (s8 *)temp_a1 + 0x10, 1.0f);
        temp_v0 = *(void **)((s8 *)state + 0x2E0);
        var_f12 = ref_L02_003D1698_01(*(f32 *)((s8 *)temp_v0 + 0x10) - *(f32 *)((s8 *)actor + 0x10),
                                *(f32 *)((s8 *)temp_v0 + 0x14) - *(f32 *)((s8 *)actor + 0x14));
    }
    if (!(var_f20 < 4.0f)) {
        return 0;
    }
    if (!(ref_L02_003D1698_02(var_f12, *(f32 *)((s8 *)actor + 0xF8)) < 0.26179942f)) {
        return 0;
    }
    if (ref_L02_003D1698_05(5) == 0) {
        ref_L02_003D1698_04(actor, 0xC, 5);
        if (*(u8 *)((s8 *)actor + 0x43) != 7) {
            ref_L02_003D1698_03(actor, 7, 0, 0xA);
        }
    } else {
        if (*(s32 *)((s8 *)state + 0x2E4) != 0) {
            ref_L02_003D1698_04(actor, 0x12, 6);
            if (*(u8 *)((s8 *)actor + 0x43) != 0xD) {
                ref_L02_003D1698_03(actor, 0xD, 8, 0xF);
            }
        } else {
            ref_L02_003D1698_04(actor, 0xF, 6);
            if (*(u8 *)((s8 *)actor + 0x43) != 0xA) {
                ref_L02_003D1698_03(actor, 0xA, 8, 0xF);
            }
        }
    }
    return 1;
}
