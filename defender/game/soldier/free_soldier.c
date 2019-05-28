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

void free_soldier(sprite_t *soldier)
{
    sprite_t *tmp;

    for (; soldier; soldier = tmp) {
        tmp = soldier->next;
        sfTexture_destroy(soldier->texture);
        sfTexture_destroy(soldier->health);
        sfSprite_destroy(soldier->sprite);
        sfSprite_destroy(soldier->health_bar);
        free(soldier->statistic);
        free(soldier);
    }
}