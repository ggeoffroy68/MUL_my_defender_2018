/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdio.h>
#include "prototype.h"
#include "define.h"
#include "lib.h"

int display_life(sprite_t *soldier, sfRenderWindow *win)
{
    float max_life = 0;
    float life = 0;
    float life_percent = 0;
    float bar_purcent = 0;

    if (soldier == NULL)
        return (0);
    for (; soldier; soldier = soldier->next) {
        if (soldier->status == UNSPAWN)
            continue;
        life = soldier->statistic[0];
        max_life = soldier->statistic[1];
        life_percent = (life / max_life) * 100;
        bar_purcent = (49.0 / 100) * (int)life_percent;
        sfSprite_setTextureRect(soldier->health_bar,
        (sfIntRect){0, 0, (int)bar_purcent, 17});
        draw_sprite(soldier->health_bar,
        (sfVector2f) {soldier->pos.x, soldier->pos.y - 20}, win);
    }
    return (0);
}
