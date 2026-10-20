
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

/* The resident table already holds the retail label addresses. The unused
 * label list keeps each C branch available; it is not read by the program. */
extern void *D_L14_002AA360[];

extern void ref_L14_00423B30_00(s8 *, f32);
extern void ref_L14_00423B30_01(s8 *);
extern void ref_L14_00423B30_02(s8 *, f32, s8 *);
extern void ref_L14_00423B30_03(s8 *, f32, s8 *);

void func_L14_00423B30(s8 *arg0) {
    s8 *temp_a1;

    temp_a1 = (*(s8 **)((char *)(arg0) + (0x68)));
    {
    static void *volatile rc2_labels[] = {&&rc2_case_1, &&rc2_case_2, &&rc2_case_3, &&rc2_case_4, &&rc2_case_5, &&rc2_case_6, &&rc2_case_7, &&rc2_case_8, &&rc2_case_9, &&rc2_case_10, &&rc2_case_11, &&rc2_case_12, &&rc2_case_13, &&rc2_case_14, &&rc2_case_15, &&rc2_case_16, &&rc2_case_17, &&rc2_case_18, &&rc2_case_19};
    u32 rc2_selector = (u32)((*(u8 *)((char *)(arg0) + (0x42)))) - 1;
    if (rc2_selector > 18U) goto rc2_default;
goto *D_L14_002AA360[rc2_selector];

    rc2_case_1:
    rc2_case_2:
    rc2_case_3:
    rc2_case_4:
    rc2_case_5:
    rc2_case_10:
    rc2_case_11:
    rc2_case_12:
    rc2_case_13:
        if ((*(s16 *)((char *)(temp_a1) + (0x776))) != 0) {
            ref_L14_00423B30_00(arg0, (*(f32 *)((char *)(temp_a1) + (0x744))));
        } else {
            ref_L14_00423B30_01(arg0);
        }
        goto rc2_switch_end;
    rc2_case_6:
    rc2_case_7:
    rc2_case_8:
    rc2_case_9:
    rc2_case_14:
    rc2_case_15:
        if ((*(s16 *)((char *)(temp_a1) + (0x77A))) != 0) {
            ref_L14_00423B30_02(arg0, (*(f32 *)((char *)(temp_a1) + (0x768))), temp_a1 + 0x700);
        } else {
            ref_L14_00423B30_03(arg0, (*(f32 *)((char *)(temp_a1) + (0x740))), temp_a1 + 0x700);
        }
        goto rc2_switch_end;
    rc2_case_16:
    rc2_case_17:
    rc2_case_18:
    rc2_case_19:
        goto rc2_switch_end;
    rc2_default:
        goto rc2_switch_end;
    
rc2_switch_end: ;
}
}
