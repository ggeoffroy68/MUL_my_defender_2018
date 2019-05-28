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

int end_of_wave(defender_t *game)
{
    sprite_t *rocket = game->defender->projectiles;
    sprite_t *next;

    for (; rocket; rocket = next) {
        next = rocket->next;
        sfTexture_destroy(rocket->texture);
        sfSprite_destroy(rocket->sprite);
        free(rocket->statistic);
        free(rocket);
    }
    game->defender->projectiles = NULL;
    free_soldier(game->defender->soldier);
    game->defender->wave++;
    game->defender->soldier =
    soldier_number_type(game->defender->soldier, MAP,
    game->defender->wave -1);
    return (SUCCESS);
}
