#include "Process_cmd.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_cmd(int argc, const char *argv[], cmd_input_data *cmd_data)
{
	assert(argv);
    assert(cmd_data);

    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < count_options; j++) {
            if (strcmp(argv[i], options[j].name) == 0) {
                (*options[j].callback)(&argv[i], cmd_data);
                i += options[j].n_args;
            }

        }
    }
}

void sort_direction_callback(const char* argv[], cmd_input_data* data)
{
    data->is_direction_sort_on = true;
    data->direction_sort = argv[1];
}

void sort_on_callback(const char* argv[], cmd_input_data* data)
{
    data->is_sort_on = true;
    data->name_sort = argv[1];
}

void help_callback(const char* [], cmd_input_data* data)
{
    data->is_help = true;
}
