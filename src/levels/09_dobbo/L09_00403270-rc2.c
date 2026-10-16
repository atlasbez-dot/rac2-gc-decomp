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

extern float ref_L09_00403270_00(void *, void *);
extern void ref_L09_00403270_01(void *);
extern int ref_L09_00403270_02(void *, int, int);
extern void ref_L09_00403270_03(void *, int, int, int, float, float);
extern int ref_L09_00403270_04(int);
extern void ref_L09_00403270_05(void);
extern void ref_L09_00403270_06(void *, int);
extern int ref_L09_00403270_07 __attribute__((sda));
extern int ref_L09_00403270_08 __attribute__((sda));
extern unsigned char ref_L09_00403270_09[];

void func_L09_00403270(void *arg0) {
    short temp_a0;
    int call_result ;
    void *temp_s1;

    temp_s1 = (*(void **)((s8 *)(arg0) + (0x68)));
    if ((*(unsigned char *)((s8 *)(arg0) + (0x20))) == 0) {
        ref_L09_00403270_05();
    }
    if ((*(unsigned char *)((s8 *)(arg0) + (0x31))) != 0) {
        if (ref_L09_00403270_00((unsigned char *)arg0 + 0x10, ref_L09_00403270_09) < 48.0f) {
            ref_L09_00403270_01(arg0);
            (*(signed char *)((s8 *)(arg0) + (0x6F))) = 0x2D;
        }
    }
    call_result = ref_L09_00403270_02(arg0, (unsigned char *)temp_s1 + 0x50, 0);
    if (*(int *)0x1A79F0 == 9) {
        temp_a0 = (*(signed short *)((s8 *)(temp_s1) + (0xC0)));
        if (temp_a0 != -1) {
            if (ref_L09_00403270_04(ref_L09_00403270_08 + ((int)temp_a0 << 8)) == 0) {
                ref_L09_00403270_07 = 0;
            }
            (*(signed short *)((s8 *)(temp_s1) + (0xC0))) = -1;
        }
    }
    ref_L09_00403270_06(arg0, call_result);
    ref_L09_00403270_03(arg0, (*(int *)((s8 *)(temp_s1) + (0x28C))), 0, 0, (*(float *)((s8 *)(temp_s1) + (0x24C))), 0.0f);
}
