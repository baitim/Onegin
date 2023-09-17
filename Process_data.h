#ifndef PROCESS_DATA_H
#define PROCESS_DATA_H

#include <stdio.h>
#include <string.h>

#include "ANSI_colors.h"
#include "Input.h"
#include "Output.h"
#include "Process_cmd.h"

void sort(CMD_INPUT_DATA cmd_data, DATA data);

void bubble_sort(DATA data, int (*comp)(char *, char *));

void q_sort(char** pointers, int count, int size, int (*comp)(char *, char *));

void partition(char **pointers, int *left, int *right, int (*comp)(char *, char *));

int comp_forward(char *s1, char *s2);

int forward_strcmp(char *s, char *t);

int reverse_strcmp(char *s, char *t);

void swap(char **ch1, char **ch2);

#endif // PROCESS_DATA_H
