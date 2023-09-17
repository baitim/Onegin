#include "Input.h"

void input_data(Data *data)
{
    FILE *stream = fopen("Text.txt", "r");

    data->size_file = fsize("Text.txt") + 1;
    data->text = (char *) calloc(data->size_file, sizeof(char));
    assert(data->text);
    get_data(*data, stream);

    data->lines_count = count_pointers(data->text) + 1;
    data->pointers = (char **) calloc(data->lines_count, sizeof(char *));
    assert(data->pointers);
    write_pointers(*data);
}

off_t fsize(const char *filename) {
    struct stat st = {};

    if (stat(filename, &st) == 0)
        return st.st_size;

    return -1;
}

void get_data(Data data, FILE *stream)
{
    assert(data.text);
    assert(stream);

    const int SIZE = 1;

    fread(data.text, data.size_file, SIZE, stream);

    data.text[data.size_file - 1] = '\0';
}

int count_pointers(const char *text)
{
    assert(text);

    int i = 0;
    int count = 0;

    while (text[i] != '\0') {
        if (text[i] == '\n')
            count++;
        i++;
    }

    return count;
}

void write_pointers(Data data)
{
    assert(data.pointers);
    assert(data.text);

    int i = 0;
    int count = 1;

    data.pointers[0] = data.text;

    while (data.text[i] != '\0') {
        if (data.text[i] == '\n') {
            data.text[i] = '\0';
            data.pointers[count] = data.text + i + 1;
            count++;
        }
        i++;
    }
}
