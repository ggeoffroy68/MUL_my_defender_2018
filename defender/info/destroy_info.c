/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "prototype.h"
#include "lib.h"

void destroy_info(info_t *info)
{
    sfClock_destroy(info->clock);
    sfFont_destroy(info->font);
    sfRenderWindow_destroy(info->win);
    free(info->clock_counter);
    for (int i = 0; info->map[i]; i++)
        free(info->map[i]);
    free(info->map);
    free(info);
}