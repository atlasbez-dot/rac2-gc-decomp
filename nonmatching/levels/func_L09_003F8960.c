/* func_L09_003F8960, 380 bytes, 2 places (09_dobbo, 20_yeedil).
 * NOT ATTEMPTED - the shape is decoded, nothing was compiled.
 *
 * The function reads the run's frame (the caller's object + 0x68), takes the frame's other
 * object (frame + 0x2F8) and works only when that object is of kind 0xD0E and its state
 * byte (other + 0x20) is neither 0xFE nor 0xFD; otherwise it returns without a word.
 *
 * The normal case copies the caller's position (a 16-byte lq/sq) to the stack, asks
 * func_002A7878 for a distance (0.0f and 1.0f), adds the result to the copied word's
 * third float, hands the frame's other object to func_00282F20 (at other + 0xC0) and the
 * frame's 0x1F0 field to func_00282CC0.
 *
 * The 0xFE/0xFD case reads the frame's word at 0x200 and compares it with the resident
 * hero pointer D_0018C0B0 (the base is D_00189E20 + 0x2290); when they are equal it asks
 * func_00282E80 for a distance and compares it with the level's word D_L09_001B0F5C (read
 * through $gp), then copies one of the two 16-byte blocks at D_00189E20 + 0xD0 or + 0xE0
 * (chosen by the comparison) into the frame's 0x1F0 field.  The word D_0018C0BC (the
 * resident's mode) decides the 0.2f, 0.4f and 0.8f the angle is stepped by, and the
 * result is added to the frame's 0x1F8 float.
 *
 * The two 16-byte copies need the grouped lq/sq pattern and the level's word needs a
 * -G8 unit, so this function wants a source unit of its own with both flags.
 */

#include "include_asm.h"
