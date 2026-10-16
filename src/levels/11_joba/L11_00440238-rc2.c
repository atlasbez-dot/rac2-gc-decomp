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

extern s8 g_001FC420[];
extern s32 ref_L11_00440238_00;
extern s8 D_00189E20[];


void func_L11_00440238(void *arg0) {
    u8 *data ;
    s32 base ;
    u16 *table_v0 ;
    s32 key;
    u16 *list ;

    u16 id;
    u8 *object;
    u8 status;
    s16 type;
    u8 *objectData;

    data = (u8 *)*(void **)((u8 *)arg0 + 0x68);
    key = *(s32 *)(data + 0xC0);
    *(s32 *)(data + 0x140) = 0;
    *(f32 *)(data + 0x144) = 0.0f;
    if (key != 0xFF) {
        table_v0 = *(u16 **)((u8 *)g_001FC420 + key * 4);
        if (table_v0 != 0) {
            list = table_v0;
            base = ref_L11_00440238_00;
            {
                s32 status_fe  = 0xFE;
                s32 status_fd  = 0xFD;
                s32 status_one  = 1;
                s32 type_d98  = 0xD98;
                s32 type_dcf  = 0xDCF;
                s32 type_df4  = 0xDF4;
                s32 type_df7  = 0xDF7;
                s32 type_df9  = 0xDF9;
                s32 type_d37  = 0xD37;
                s32 type_d4a  = 0xD4A;
                s32 type_b3a  = 0xB3A;
                do {
                id = *list;
                object = (u8 *)(base + ((id & 0x7FFF) << 8));
                if (object != 0) {
                    status = *(u8 *)(object + 0x20);
                    if (status != status_fe && status != status_fd && status != status_one) {
                        type = *(s16 *)(object + 0xAA);
                        if (type == type_d98 || type == type_dcf || type == type_df4 ||
                            type == type_df7 || type == type_df9 || type == type_d37 ||
                            type == type_d4a || type == type_b3a) {
                            *(s32 *)(data + 0x140) = *(s32 *)(data + 0x140) + 1;
                            objectData = *(u8 **)(object + 0x68);
                            *(f32 *)(data + 0x144) =
                                *(f32 *)(data + 0x144) + *(f32 *)(objectData + 0x20);
                        }
                    }
                }
            } while ((s16)*list++ >= 0);
            }
            table_v0 = (u16 *)D_00189E20;

            *(f32 *)(data + 0x148) = (f32)*(s32 *)((u8 *)table_v0 + 0x24CC);
        }
    }
}
