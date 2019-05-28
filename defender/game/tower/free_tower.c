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

void free_the_tower(sprite_t *original)
{
    sfTexture_destroy(original->texture);
    sfSprite_destroy(original->sprite);
    if (original->range)
        sfCircleShape_destroy(original->range);
    if (original->statistic)
        free(original->statistic);
    free(original);
}

sprite_t *free_tower(sprite_t *original, int i)
{
    sprite_t *to_delete = original;

    for (int k = 0; k < i && to_delete; k++, to_delete = to_delete->next);
    to_delete->status = UNSPAWN;
    return (original);
}
