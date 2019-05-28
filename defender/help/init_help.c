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

static const ressource_t RES[4] = {
    {NULL, {1000, 50}, {0, 0, 312, 312}, 1},
    {NULL, {200, 400}, {0, 0, 312, 312}, 1},
    {NULL, {200, 300}, {0, 0, 312, 312}, 1},
    {NULL, {300, 300}, {0, 0, 312, 312}, 1},
};

help_t *init_help(void)
{
    help_t *help = malloc(sizeof(help_t));

    if (!help)
        return (NULL);
    help->click = malloc(sizeof(sprite_t *) * 4);
    if (!help->click)
        return (NULL);
    for (int i = 0; i < 4; i++) {
        help->click[i] = add_block("ressource/click.png", NULL,
        RES[i].rec, RES[i].pos);
        if (!help->click[i])
            return (NULL);
        sfSprite_setScale(help->click[i]->sprite, (sfVector2f){0.5, 0.5});
        help->click[i] = add_block("ressource/no_click.png", help->click[i],
        RES[i].rec, RES[i].pos);
        sfSprite_setScale(help->click[i]->sprite, (sfVector2f){0.5, 0.5});
    }
    help->step = 0;
    return (help);
}
