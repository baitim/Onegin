#ifndef PROCESS_CMD_H
#define PROCESS_CMD_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ANSI_colors.h"

struct CMD_INPUT_DATA {
    bool is_sort_on;
    const char *name_sort;
    bool is_direction_sort_on;
    const char *direction_sort;
    bool is_help;
};

struct CMD_LINE_OPTION {
    const char *name;
    const char *description;
    int n_args;
    void (*callback)(const char* argv[], CMD_INPUT_DATA* data);
};

void sort_direction_callback(const char* argv[], CMD_INPUT_DATA* data);

void sort_on_callback(const char* argv[], CMD_INPUT_DATA* data);

void help_callback(const char* argv[], CMD_INPUT_DATA* data);

const CMD_LINE_OPTION options[] = {
    {"--direction_sort_on", "Choose direction of sort.",    1, sort_direction_callback},
    {"--sort_on",           "Choose sort.",                 1, sort_on_callback},
    {"--help",              "Dispay help.",                 0, help_callback}
};
const int COUNT_OPTIONS = sizeof(options) / sizeof(CMD_LINE_OPTION);

void print_help();

void input_cmd(int argc, const char *argv[], CMD_INPUT_DATA *cmd_data);

#endif //PROCESS_CMD_H
