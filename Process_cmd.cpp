#include "Process_cmd.h"

void input_cmd(int argc, const char *argv[], CMD_INPUT_DATA *cmd_data)
{
	assert(argv);
    assert(cmd_data);

    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < COUNT_OPTIONS; j++) {
            if (strcmp(argv[i], options[j].name) == 0) {
                (*options[j].callback)(&argv[i], cmd_data);
                i += options[j].n_args;
            }

        }
    }
}

void sort_direction_callback(const char* argv[], CMD_INPUT_DATA* data)
{
    data->is_direction_sort_on = true;
    data->direction_sort = argv[1];
}

void sort_on_callback(const char* argv[], CMD_INPUT_DATA* data)
{
    data->is_sort_on = true;
    data->name_sort = argv[1];
}

void help_callback(const char* [], CMD_INPUT_DATA* data)
{
    data->is_help = true;
}

void print_help()
{
    for (int i = 0; i < COUNT_OPTIONS; i++)
        printf(ANSI_LIGHT_GREEN "%s\t\t%s\n" ANSI_DEFAULT_COLOR, options[i].name, options[i].description);
}
