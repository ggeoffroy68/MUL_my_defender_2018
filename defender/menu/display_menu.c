/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

void display_menu(defender_t *game, sfVector2i mouse)
{
    int i = 0;

    display_back(game->back, WIN, CLOCK);
    for (; game->menu->button[i]; i++);
    draw_many_text(game->menu->button, WIN, mouse, i);
}