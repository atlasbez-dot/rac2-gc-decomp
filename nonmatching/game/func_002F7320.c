typedef struct {
    int key;
    int values[3];
} Func_002F7320Row;

extern Func_002F7320Row ref_L00_002F7320_00[];

int func_002F7320(int value, int key, int field)
{
    Func_002F7320Row *table = ref_L00_002F7320_00;
    int result = 0;
    int index = 0;
    int first = table[0].key;

    if (first != 0) {
        if (key != first) {
            int *entry = &table[1].key;

            for (;;) {
                int entry_key = *entry;

                if (entry_key == 0)
                    goto done;
                index++;
                if (index >= 56)
                    break;
                if (key == entry_key)
                    break;
                entry += 4;
            }
        }
        if (table[index].key != 0)
            result = table[index].values[field] == value;
    }
done:
    return result;
}
