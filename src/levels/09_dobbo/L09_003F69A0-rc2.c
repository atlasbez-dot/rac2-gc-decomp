
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

typedef struct {
    u8 pad0[4];
    f32 f4;
    u8 pad8[8];
    u8 f10[0x40];
} Work_003F69A0;
typedef struct { u8 pad[0x18]; f32 f18; } Inner_003F69A0;
typedef struct {
    u8 pad20[0x20];
    Inner_003F69A0 *f20;
    u8 pad24[4];
    f32 f28;
} State_003F69A0;
typedef struct {
    u8 pad0[0x10];
    u8 f10[8];
    f32 f18;
    u8 pad1c[0x4C];
    State_003F69A0 *f68;
} Actor_003F69A0;

extern void ref_L09_003F69A0_00(void *, void *, void *);
extern void ref_L09_003F69A0_01(void *, void *);
extern void ref_L09_003F69A0_02(void *, void *, void *);
extern f32 ref_L09_003F69A0_03(f32);
extern void ref_L09_003F69A0_04(void *, void *, void *);
extern void ref_L09_003F69A0_05(void *, void *, void *);
extern f32 ref_L09_003F69A0_06 __attribute__((sda));

void func_L09_003F69A0(Actor_003F69A0 *arg0, f32 fparg0) {
    Work_003F69A0 work;
    State_003F69A0 *state = arg0->f68;
    f32 temp_f20;
    f32 temp_f1;
    f32 old_f18;

    ref_L09_003F69A0_00(&work, &arg0->f10, (u8 *)state->f20 + 0x10);
    ref_L09_003F69A0_01(&work.f10, (u8 *)state->f20 + 0xC0);
    ref_L09_003F69A0_02(&work, &work, &work.f10);
    temp_f20 = ref_L09_003F69A0_03(work.f4);
    temp_f1 = ref_L09_003F69A0_03(work.f4);
    work.f4 += (work.f4 / temp_f20) * (state->f28 - temp_f1) * fparg0;
    ref_L09_003F69A0_04(&work, &work, (u8 *)state->f20 + 0xC0);
    ref_L09_003F69A0_05(&arg0->f10, &work, (u8 *)state->f20 + 0x10);
    old_f18 = arg0->f18;
    arg0->f18 = old_f18 + ((state->f20->f18 + ref_L09_003F69A0_06) - old_f18) * fparg0;
}
