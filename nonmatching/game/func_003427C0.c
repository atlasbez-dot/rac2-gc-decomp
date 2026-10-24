/*
 * Measured near miss: 284 bytes, 0/28 placements in USA v1.01, PAL, and USA v2.00.
 * The remaining differences are the branch displacement at +0x88 and the final
 * floating-point multiply/conversion destinations near +0xF0.
 */
extern double func_001234F0(float);
extern int func_00123028(double, double);
extern double func_00122A98(double, double);
extern double func_00122B00(double, double);
extern float func_00123298(double);

int func_003427C0(void *unused, int limit, float start, float offset, float end, float scale)
{
    double width = func_001234F0(end - offset);
    float scaled;
    float ratio;
    double value;
    int result;

    if (func_00123028(width, 0.0) < 0)
        width = func_00122A98(0.0, width);
    scaled = func_00123298(func_00122B00(width, func_001234F0(scale)));

    ratio = end - start;
    if (ratio < scaled)
        scaled = ratio;
    value = func_001234F0(scaled / ratio);
    if (func_00123028(value, 0.0) < 0)
        value = func_00122A98(0.0, value);
    ratio = func_00123298(value);

    result = (int)((1.0f - ratio) * 255.0f);
    return limit < result ? limit : result;
}
