/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "prototype.h"
#include "lib.h"

void destroy_block(sprite_t *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
    free(sprite);
}

void destroy_help(help_t *help)
{
    for (int i = 0; i < 4; i++) {
        destroy_block(help->click[i]->next);
        destroy_block(help->click[i]);
    }
    free(help->click);
    free(help);
}
