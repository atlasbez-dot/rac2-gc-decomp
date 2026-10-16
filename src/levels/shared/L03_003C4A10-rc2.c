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

typedef struct { f32 x, y, z, pad; } FloatScratch;
typedef struct { FloatScratch first; FloatScratch second; u8 pad[0x30]; } WorkFrame;

void ref_L03_003C4A10_00(void *, void *, void *);
void ref_L03_003C4A10_01(void *, void *);
void ref_L03_003C4A10_02(void *, void *, void *);
f32 ref_L03_003C4A10_03(f32, f32);
f32 ref_L03_003C4A10_04(void *);
extern f32 ref_L03_003C4A10_05 __attribute__((sda));
extern f32 ref_L03_003C4A10_06 __attribute__((sda));
extern f32 ref_L03_003C4A10_07 __attribute__((sda));
extern f32 ref_L03_003C4A10_08 __attribute__((sda));

void func_L03_003C4A10(void *arg0) {

    WorkFrame frame;
    void *temp_s1  = arg0;
    s32 temp_s3  = 0x93C;
    void *temp_s0 ;
    void *temp_s2 ;    void *call_arg0 ;
    void *incoming_a1 ;
    f32 temp_f20 ;
    f32 temp_f0;
    f32 temp_f1;


    if (*((s16 *)((u8 *)temp_s1 + 0xAA)) == temp_s3 &&
        *((u8 *)temp_s1 + 0x43) == 1) {
        return;
    }

    temp_s2 = *(void **)((u8 *)temp_s1 + 0x68);
    call_arg0 = &frame.first;    ref_L03_003C4A10_00(call_arg0, (void *)incoming_a1, (u8 *)temp_s1 + 0x10);
    temp_s0 = &frame.second;
    ref_L03_003C4A10_01(temp_s0, (u8 *)temp_s1 + 0xC0);
    call_arg0 = &frame.first;    ref_L03_003C4A10_02(call_arg0, &frame.first, temp_s0);
    {
        s32 temp_a0  = *((s16 *)((u8 *)temp_s1 + 0xAA));
        if (temp_a0 == 0x940) {
            goto mode_940;
        }
        if (temp_a0 < 0x941) {
            if (temp_a0 == temp_s3) {
                goto mode_93c;
            }
        } else {
            if (temp_a0 == 0x964) {
                goto mode_964;
            }
            if (temp_a0 == 0xA59) {
                goto mode_a59;
            }
        }
        goto after_adjust;
mode_964:
        temp_f0 = frame.first.z;
        temp_f1 = ref_L03_003C4A10_05;
        goto adjust_angle;
mode_93c:
        temp_f0 = frame.first.z;
        temp_f1 = ref_L03_003C4A10_06;
        goto adjust_angle;
mode_940:
        temp_f0 = frame.first.z;
        temp_f1 = ref_L03_003C4A10_07;
        goto adjust_angle;
mode_a59:
        temp_f0 = frame.first.z;
        temp_f1 = ref_L03_003C4A10_08;
    }adjust_angle:
    frame.first.z = temp_f0 - temp_f1;
after_adjust:
    temp_f20 = ref_L03_003C4A10_03(frame.first.x, frame.first.y);
    temp_f0 = ref_L03_003C4A10_04(&frame.first);
    temp_f1 = -ref_L03_003C4A10_03(temp_f0, frame.first.z);
    if (temp_f20 > 1.5707964f) {
        temp_f20 = 1.5707964f;
    } else if (temp_f20 < -1.5707964f) {
        temp_f20 = -1.5707964f;
    }
    if (temp_f1 > 0.7853982f) {
        temp_f1 = 0.7853982f;
    } else if (temp_f1 < -0.7853982f) {
        temp_f1 = -0.7853982f;
    }
    temp_f1 *= 0.5f;
    temp_f20 *= 0.5f;
    *(volatile f32 *)((u8 *)temp_s2 + 0x324) = temp_f1;
    *(volatile f32 *)((u8 *)temp_s2 + 0x328) = temp_f20;
    *(volatile f32 *)((u8 *)temp_s2 + 0x2A8) = temp_f20;
    *(volatile f32 *)((u8 *)temp_s2 + 0x2A4) = temp_f1;
}
