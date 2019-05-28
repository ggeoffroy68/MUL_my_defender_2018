/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

void restart_counter(info_t *info)
{
    if (!info)
        return;
    for (int i = 0; i < 2; i++)
        info->clock_counter[i] = 1;
}

int clock_restart(info_t *info, int nb)
{
    if (info->clock
    && sfClock_getElapsedTime(info->clock).microseconds > nb) {
        sfClock_restart(info->clock);
        restart_counter(info);
        return (SUCCESS);
    }
    return (1);
}
