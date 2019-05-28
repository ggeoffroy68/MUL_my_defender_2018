/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

void display_pause(defender_t *game, sfVector2i mouse)
{
    int i = 0;

    display_back(game->back, WIN, CLOCK);
    for (; game->pause->button[i]; i++);
    draw_many_text(game->pause->button, WIN, mouse, i);
}