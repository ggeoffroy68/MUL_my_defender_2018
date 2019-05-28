/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <math.h>
#include <stdlib.h>
#include "define.h"
#include "prototype.h"
#include "lib.h"

void display_upgrade(sprite_t *upgrade, sfRenderWindow *win)
{
    if (!upgrade->status)
        draw_sprite(upgrade->sprite, upgrade->pos, win);
}

void display_range(sprite_t *map_tower, sprite_t *cross, sprite_t *upgrade,
sfRenderWindow *win)
{
    sfFloatRect tower_range = sfSprite_getGlobalBounds(map_tower->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);

    for (; map_tower; map_tower = map_tower->next, cross = cross->next,
    upgrade = upgrade->next) {
        tower_range = sfSprite_getGlobalBounds(map_tower->sprite);
        tower_range = mouse_resize(win, tower_range);
        if (map_tower->status != UNSPAWN
        && sfFloatRect_contains(&tower_range, mouse_pos.x, mouse_pos.y)) {
            sfRenderWindow_drawCircleShape(win, map_tower->range, NULL);
            draw_sprite(cross->sprite, cross->pos, win);
            display_upgrade(upgrade, win);
        }
    }
}

int pythagor(sfSprite *soldier, sfSprite *tower, int range)
{
    sfVector2f pos_soldier = sfSprite_getPosition(soldier);
    sfVector2f pos_tower = sfSprite_getPosition(tower);
    double x_pos = pow(pos_tower.x - pos_soldier.x, 2);
    double y_pos = pow(pos_tower.y - pos_soldier.y, 2);
    double dist = sqrt(x_pos + y_pos);

    if (dist < 0)
        dist = dist * -1;
    if (dist <= range)
        return (1);
    return (SUCCESS);
}

void hit_enemy(sprite_t *tower, game_t *game, int value, music_t *music)
{
    sprite_t *soldier = game->soldier;
    int pyt = 0;

    for (int i = 0; soldier; soldier = soldier->next, i++) {
        pyt = pythagor(soldier->sprite, tower->sprite, tower->statistic[0]);
        if (!value && soldier->status != UNSPAWN && pyt) {
            game->projectiles = launch_projectile(game->projectiles, 0, i,
            tower);
            sfMusic_stop(music->back[1]);
            sfMusic_play(music->back[1]);
            return;
        }
    }
}

int detect_ennemy(sprite_t **map_tower, game_t *defender, info_t *info,
music_t *music)
{
    sprite_t *support = map_tower[1];
    sprite_t *tower = map_tower[0];
    int value;

    if (!tower || !support)
        return (SUCCESS);
    value = clock_restart(info, 1000000);
    display_range(support, map_tower[2], map_tower[3], info->win);
    for (int i = 0; tower; tower = tower->next, i++) {
        if (tower->status != UNSPAWN)
            hit_enemy(tower, defender, value, music);
    }
    return (SUCCESS);
}
