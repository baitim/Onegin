#ifndef PROCESS_CMD_H
#define PROCESS_CMD_H

struct cmd_input_data {
    bool is_sort_on;
    const char *name_sort;
    bool is_direction_sort_on;
    const char *direction_sort;
    bool is_help;
};

const int count_options = 3;

struct cmd_line_option {
    const char *name;
    const char *description;
    int n_args;
    void (*callback)(const char* argv[], cmd_input_data* data);
};

void sort_direction_callback(const char* argv[], cmd_input_data* data);

void sort_on_callback(const char* argv[], cmd_input_data* data);

void help_callback(const char* argv[], cmd_input_data* data);

const cmd_line_option options[] = {
    {"-direction_sort_on", "include direction of sort", 1, sort_direction_callback},
    {"-sort_on", "include sort", 1, sort_on_callback},
    {"--help", "help", 0, help_callback}
};

void print_help();

void input_cmd(int argc, const char *argv[], cmd_input_data *cmd_data);

#endif //PROCESS_CMD_H
