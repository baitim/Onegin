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

    cmd_input_data cmd_data = { false, nullptr, false, nullptr, false };
    input_cmd(argc, argv, &cmd_data);

    if (cmd_data.is_help)
        print_help();

    Data data = {};
    input_data(&data);

    print_data(data);

    if (cmd_data.is_sort_on) {
		sort(cmd_data, data);
		printf(ANSI_LIGHT_BLUE "Sorted by " ANSI_LIGHT_GREEN "%s" ANSI_LIGHT_BLUE " with " ANSI_LIGHT_YELLOW
               "%s" ANSI_LIGHT_BLUE " direction\n" ANSI_DEFAULT_COLOR, cmd_data.name_sort,
               cmd_data.direction_sort);
		print_data(data);
	}
    printf(ANSI_LIGHT_BLUE "Bye\n" ANSI_DEFAULT_COLOR);

    return 0;
}
