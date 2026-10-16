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

extern float ref_L09_003EAA18_00(void *, void *);
extern void ref_L09_003EAA18_01(void *, int, int);
extern void ref_L09_003EAA18_02(void *);
extern int ref_L09_003EAA18_03(void *, int, int);
extern void ref_L09_003EAA18_04(void *, int, int, int, float, float);
extern int ref_L09_003EAA18_05(int);
extern void ref_L09_003EAA18_06(void);
extern int D_001A79F0 __attribute__((sda));
extern int ref_L09_003EAA18_07 __attribute__((sda));
extern int ref_L09_003EAA18_08 __attribute__((sda));
extern unsigned char ref_L09_003EAA18_09[];

void func_L09_003EAA18(void *arg0) {
    short temp_a0;
    void *temp_s1;

    temp_s1 = (*(void **)((s8 *)(arg0) + (0x68)));
    if ((*(unsigned char *)((s8 *)(arg0) + (0x95))) == 0) {
        ref_L09_003EAA18_06();
    }
    if ((*(unsigned char *)((s8 *)(arg0) + (0x31))) != 0) {
        if (ref_L09_003EAA18_00((unsigned char *)arg0 + 0x10, ref_L09_003EAA18_09) < 32.0f) {
            ref_L09_003EAA18_02(arg0);
            (*(signed char *)((s8 *)(arg0) + (0x6F))) = 0x1E;
        }
    }
    if (ref_L09_003EAA18_03(arg0, (unsigned char *)temp_s1 + 0x180, 0) >= 4) {
        if (D_001A79F0 == 9) {
            temp_a0 = (*(short *)((s8 *)(temp_s1) + (0x1F0)));
            if (temp_a0 != -1) {
                if (ref_L09_003EAA18_05(ref_L09_003EAA18_08 + ((int)temp_a0 << 8)) == 0) {
                    ref_L09_003EAA18_07 = 0;
                }
                (*(short *)((s8 *)(temp_s1) + (0x1F0))) = -1;
            }
        }
        ref_L09_003EAA18_01(arg0, 6, -1);
    }
    ref_L09_003EAA18_04(arg0, (*(int *)((s8 *)(temp_s1) + (0x354))), 0, 0, 0.0f, 0.0f);
}
