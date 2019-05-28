/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "prototype.h"
#include "define.h"
#include "lib.h"

void destroy_music(music_t *music)
{
    for (int i = 0; music->back[i]; i++) {
        sfMusic_stop(music->back[i]);
        sfMusic_destroy(music->back[i]);
    }
    free(music->back);
    free(music);
}