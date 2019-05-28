/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "prototype.h"
#include "define.h"
#include "lib.h"

char **get_map(char *file)
{
    FILE *fd = fopen(file, "r");
    int readed = 0;
    char *line = NULL;
    char *str = NULL;
    char **array = NULL;
    size_t length = 0;

    if (!fd)
        return (write(2, "Error opening\n", 14), NULL);
    while ((readed = getline(&line, &length, fd)) != -1)
        str = my_strcat(line, str);
    fclose(fd);
    array = str_to_array(str, '\n');
    free(str);
    free(line);
    return (array);
}