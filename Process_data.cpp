#include "Process_data.h"

void sort(CMD_INPUT_DATA cmd_data, DATA data)
{
    int (*comp)(char *, char *);

    char *dir_sort = strdup("forward");
    char *type_sort = strdup("q_sort");

    if (cmd_data.is_direction_sort_on) {
        if (strcmp(cmd_data.direction_sort, "forward") == 0)
            comp = forward_strcmp;

        if (strcmp(cmd_data.direction_sort, "reverse") == 0) {
            comp = reverse_strcmp;
            dir_sort = strdup("reverse");
        }
    }

    if (cmd_data.name_sort) {
        if (strcmp(cmd_data.name_sort, "bubble") == 0) {
            bubble_sort(data, comp);
            type_sort = strdup("bubble");
        }

        if (strcmp(cmd_data.name_sort, "q_sort") == 0)
            q_sort(data.pointers, data.lines_count, 1, comp);
    } else {
        q_sort(data.pointers, data.lines_count, 1, comp);
    }

    printf(ANSI_LIGHT_BLUE "Sorted by " ANSI_LIGHT_GREEN "%s" ANSI_LIGHT_BLUE " with " ANSI_LIGHT_YELLOW
               "%s" ANSI_LIGHT_BLUE " direction\n" ANSI_DEFAULT_COLOR, type_sort, dir_sort);
	print_data(data);
    write_data(data);
}

void bubble_sort(DATA data, int (*comp)(char *, char *))
{
    for (int i = 0; i < data.lines_count; i++) {
        for (int j = i; j < data.lines_count; j++) {
            if ((*comp)(data.pointers[i], data.pointers[j]) > 0) {
                swap(&(data.pointers[i]), &(data.pointers[j]));
            }
        }
    }
}

void q_sort(char** pointers, int count, int size, int (*comp)(char *, char *))
{
    if (count <= 1)
        return ;
    int i = 0;
    int j = count - 1;
    partition(pointers, &i, &j, comp);

    if (0 < j + 1)
        q_sort(&(pointers[0]), j + 1, 1, comp);

    if (i < count - 1)
        q_sort(&(pointers[i]), count - i, 1, comp);
}

void partition(char **pointers, int *i, int *j, int (*comp)(char *, char *))
{
    char *x = pointers[(*i + *j) / 2];
    char *mid = (char *)calloc(strlen(x), sizeof(char));
    for (int k = 0; k < (int)strlen(x); k++)
        mid[k] = x[k];

    while (*i < *j) {
        while ((*comp)(pointers[*i], mid) < 0) (*i)++;
        while ((*comp)(pointers[*j], mid) > 0) (*j)--;

        if (*i <= *j) {
            if ((*comp)(pointers[*i], pointers[*j]) > 0) swap(&(pointers[*i]), &(pointers[*j]));
            (*i)++;
            (*j)--;
        }
    }
    free(mid);
}

int forward_strcmp(char *s, char *t)
{
    assert(s);
    assert(t);

    return strcmp(s, t);
}

int reverse_strcmp(char *s, char *t)
{
    assert(s);
    assert(t);

    const int len_s = (int)strlen(s);
    const int len_t = (int)strlen(t);

    int i = len_s - 1;
    int j = len_t - 1;

    while (i >= 0 && j >= 0) {
        if (s[i] < t[j]) 
            return -1;
        if (s[i] > t[j])
            return 1;
        i--;
        j--;
    }
    if (i >= 0)
        return 1;
    if (j >= 0)
        return -1;
    return 0;
}

void swap(char **ch1, char **ch2)
{
    char* t = *ch1;
    *ch1 = *ch2;
    *ch2 = t;
}
