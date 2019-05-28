/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <math.h>
#include "define.h"
#include "prototype.h"
#include "lib.h"

void make_rotate(sprite_t *soldier, sprite_t *tower)
{
    sfFloatRect t_rec = sfSprite_getGlobalBounds(tower->sprite);
    sfFloatRect s_rec = sfSprite_getGlobalBounds(soldier->sprite);
    float top = t_rec.top + 32 - s_rec.top;
    float left = t_rec.left + 32 - s_rec.left;
    float angle = sfSprite_getRotation(tower->sprite);

    top *= (top < 0) ? -1: 1;
    left *= (top < 0) ? -1: 1;
    if (s_rec.top < t_rec.top + 32 && s_rec.left < t_rec.left + 32)
        angle = 270 + (atan(top/left) * 180.0 /M_PI);
    else if (s_rec.top < t_rec.top + 32 && s_rec.left > t_rec.left + 32)
        angle = 90 + (atan(top/left) * 180.0 /M_PI);
    else if (s_rec.top > t_rec.top + 32 && s_rec.left < t_rec.left + 32)
        angle = 270 + (atan(top/left) * 180.0 /M_PI);
    else if (s_rec.top > t_rec.top + 32 && s_rec.left > t_rec.left + 32)
        angle = 90 + (atan(top/left) * 180.0 /M_PI);
    sfSprite_setRotation(tower->sprite, angle);
}

void check_each_soldier(sprite_t *soldier, sprite_t *tower)
{
    for (; soldier; soldier = soldier->next)
        if (soldier->status != UNSPAWN && pythagor(soldier->sprite,
            tower->sprite, tower->statistic[0] + 25))
            return ((void)make_rotate(soldier, tower));
}

void focus_on_enemys(game_t *defender)
{
    sprite_t *tower = defender->map_tower[0];
    sprite_t *soldier = defender->soldier;

    for (; tower; tower = tower->next)
        check_each_soldier(soldier, tower);
}