#include "Output.h"
#include "Process_cmd.h"

void print_data(DATA data)
{
	printf(ANSI_LIGHT_BLUE "TEXT: \n" ANSI_DEFAULT_COLOR);
	
	printf(ANSI_LIGHT_CYAN);

	for (int i = 0; i < data.lines_count; i++)
		puts(data.pointers[i]);

	printf(ANSI_DEFAULT_COLOR);
}

void write_data(DATA data)
{
	FILE *stream = fopen("Output_text.txt", "w");

	for (int i = 0; i < data.lines_count; i++) {
 		fwrite(data.pointers[i], sizeof(data.pointers[i][0]), strlen(data.pointers[i]), stream);
		fwrite("\n", 1, 1, stream);
	}
}