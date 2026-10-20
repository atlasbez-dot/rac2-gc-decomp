
/* SPDX-License-Identifier: MIT
 * MIT License
 * 
 * Copyright (c) 2026 Forja contributors
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

extern void ref_L05_00443C18_00(s32 *, void *, f32);
extern void ref_L05_00443C18_01(s32 *, s32 *, s32 *);

void func_L05_00443C18(void *arg0, void *arg1) {
    s32 sp[8];
    void *temp_s0;
    void *temp_v0;

    temp_s0 = *(void **)((s8 *)arg1 + 0x68);
    temp_v0 = *(void **)((s8 *)arg0 + 0x70) + 0x50;
    *(f32 *)((s8 *)temp_s0 + 0x0) = (*(f32 *)((s8 *)temp_v0 + 0x68) / (*(f32 *)((s8 *)temp_v0 + 0x78) * 0.017453294f)) * *(f32 *)((s8 *)temp_s0 + 0x244);
    *(f32 *)((s8 *)temp_s0 + 0x4) = (-*(f32 *)((s8 *)temp_v0 + 0x64) / (*(f32 *)((s8 *)temp_v0 + 0x74) * 0.017453294f)) * *(f32 *)((s8 *)temp_s0 + 0x248);
    ref_L05_00443C18_00(sp, arg0, *(f32 *)((s8 *)temp_s0 + 0x240));
    ref_L05_00443C18_01(sp, (s32 *)((s8 *)arg0 + 0x30), sp);
    ref_L05_00443C18_00(&sp[4], (s8 *)arg0 + 0x10, *(f32 *)((s8 *)temp_s0 + 0x0));
    ref_L05_00443C18_01(sp, sp, &sp[4]);
    ref_L05_00443C18_00(&sp[4], (s8 *)arg0 + 0x20, *(f32 *)((s8 *)temp_s0 + 0x4));
    ref_L05_00443C18_01((s32 *)((s8 *)temp_s0 + 0x20), sp, &sp[4]);
}
