#include "ANSI_colors.h"
#include "Input.h"
#include "Output.h"
#include "Process_data.h"
#include "Process_cmd.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    printf(ANSI_LIGHT_BLUE "# (c) BAIDIUSENOV TIMUR, 2023\n\n" ANSI_DEFAULT_COLOR);

    CMD_INPUT_DATA cmd_data = { false, nullptr, false, nullptr, false };
    input_cmd(argc, argv, &cmd_data);

    if (cmd_data.is_help)
        print_help();

    DATA data = {};
    create_data(&data);

    print_data(data);

    if (cmd_data.is_sort_on)
        sort(cmd_data, data);

    printf(ANSI_LIGHT_BLUE "Bye\n" ANSI_DEFAULT_COLOR);

    return 0;
}
