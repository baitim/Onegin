#include "Output.h"
#include "Process_cmd.h"

void print_help()
{
        for (int i = 0; i < count_options; i++)
                printf(ANSI_LIGHT_GREEN "%s\t\t%s\n" ANSI_DEFAULT_COLOR, options[i].name, options[i].description);
}

void print_data(Data data)
{
	printf(ANSI_LIGHT_BLUE "TEXT: \n" ANSI_DEFAULT_COLOR);
	
	printf(ANSI_LIGHT_CYAN);

	for (int i = 0; i < data.lines_count; i++)
		puts(data.pointers[i]);

	printf(ANSI_DEFAULT_COLOR);
}
