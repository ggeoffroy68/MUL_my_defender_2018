/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "define.h"
#include "prototype.h"
#include "lib.h"

void destroy_pause(pause_t *pause)
{
    for (int i = 0; pause->button[i]; i++) {
        sfText_destroy(pause->button[i]->text);
        free(pause->button[i]);
    }
    free(pause->button);
    free(pause);
}