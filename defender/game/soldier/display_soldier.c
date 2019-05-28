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

void soldier(sprite_t *soldier, sfRenderWindow *win)
{
    sfVector2f pos;

    for (; soldier; soldier = soldier->next)
        if (soldier->status != UNSPAWN) {
            pos = soldier->pos;
            pos.y += (soldier->status == UP) ? 64: 0;
            pos.x += (soldier->status == DOWN) ? 64: 0;
            draw_sprite(soldier->sprite, pos, win);
        }
}

void check_pos_in_map(char **map, sprite_t *soldier)
{
    int posx = (soldier->pos.x + 64) / 64;
    int posy = (soldier->pos.y + 64) / 64;
    int size = tab_size(map);

    posy += (soldier->status == UP) ? 1: 0;
    if (posy - 1 >= 0 && posy + 1 < size && posx + 2 < my_strlen(map[posy + 1])
    && posx + 2 < my_strlen(map[posy - 1]) && posx > 0
    && map[posy - 1][posx + 2] == '1' && map[posy + 1][posx + 2] == '1') {
        soldier->status = RIGHT;
        sfSprite_setRotation(soldier->sprite, 0);
    } else if (posy + 2 < size && posx - 1 >= 0
    && posx + 1 < my_strlen(map[posy + 2]) && map[posy + 2][posx - 1] == '1'
    && map[posy + 2][posx + 1] == '1' && soldier->status != UP) {
        soldier->status = DOWN;
        sfSprite_setRotation(soldier->sprite, 90);
    } else if (posy - 2 >= 0 && posx + 1 < my_strlen(map[posy - 2]) &&
    posx - 1 >= 0 && map[posy - 2][posx - 1] == '1'
    && map[posy - 2][posx + 1] == '1' && soldier->status != DOWN) {
        soldier->status = UP;
        sfSprite_setRotation(soldier->sprite, -90);
    }
}

int check_map_move(sprite_t *soldier, info_t *info)
{
    if (soldier->status == UNSPAWN)
        return (SUCCESS);
    check_pos_in_map(info->map, soldier);
    if (info->clock && sfClock_getElapsedTime(info->clock).microseconds
    / info->clock_counter[0] > 0.01) {
        if (soldier->status == RIGHT)
            soldier->pos.x += 1;
        else if (soldier->status == DOWN)
            soldier->pos.y += 1;
        else
            soldier->pos.y -= 1;
        info->clock_counter[0]++;
    }
    return (SUCCESS);
}

void move_soldier(sprite_t *soldier, info_t *info, game_t *defender,
sfFont *font)
{
    sfText *base_hp = NULL;
    sfVector2u win = sfRenderWindow_getSize(info->win);
    float x = (float)win.x / (float)1280;
    char *str = my_revstr(int_to_str(defender->base_hp));

    if (!str)
        return;
    for (; soldier; soldier = soldier->next) {
        defender->base_hp -=
        soldier->pos.x > 1200 * x && soldier->status != UNSPAWN ? 1: 0;
        soldier->status =
        (soldier->pos.x > 1200 * x) ? UNSPAWN : soldier->status;
        if (soldier->pos.x < 1280 * x)
            check_map_move(soldier, info);
    }
    base_hp = create_text(str, 90, font);
    sfText_setColor(base_hp, sfWhite);
    draw_text(base_hp, (sfVector2f) {1020, -5}, info->win);
    free(str);
    sfText_destroy(base_hp);
}
