/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <math.h>
#include <stdlib.h>
#include "prototype.h"
#include "define.h"
#include "lib.h"

sfCircleShape *create_shape(int length, sfVector2f pos)
{
    sfCircleShape *range = sfCircleShape_create();

    pos.x += 32;
    pos.y += 32;
    sfCircleShape_setOrigin(range, (sfVector2f){length, length});
    sfCircleShape_setOutlineColor(range, sfRed);
    sfCircleShape_setRadius(range, length);
    sfCircleShape_setOutlineThickness(range, 6);
    sfCircleShape_setFillColor(range, sfTransparent);
    sfCircleShape_setPosition(range, pos);
    return (range);
}

void add_stat_to_tower(defender_t *game, int value)
{
    int pow_value = (4 - value - 1 < 0) ? 1: 4 - value - 1;

    sfSprite_setScale(MAP_TOWER[2]->sprite, (sfVector2f){0.1, 0.1});
    sfSprite_setScale(MAP_TOWER[3]->sprite, (sfVector2f){0.05, 0.05});
    sfSprite_setOrigin(MAP_TOWER[0]->sprite, (sfVector2f){32, 32});
    MAP_TOWER[0]->status = value;
    MAP_TOWER[0]->statistic = malloc(sizeof(int) * 3);
    MAP_TOWER[0]->statistic[0] = 175 + 25 * (4 - value + 1);
    MAP_TOWER[0]->statistic[1] = 50 * pow(2, pow_value);
    MAP_TOWER[1]->range = create_shape(MAP_TOWER[0]->statistic[0],
    MAP_TOWER[1]->pos);
}

int get_selectionned_tower(sprite_t *tower)
{
    int i = 0;

    for (; tower && tower->status != 1; tower = tower->next, i++);
    return ((i == 5) ? -1 : i);
}

void add_the_tower(defender_t *game, int value, sfVector2f pos)
{
    sprite_t *tower = game->defender->selection->tower[0];
    sprite_t *support = game->defender->selection->tower[1];
    int prices[5] = {2000, 1000, 500, 300, 150};
    int i = 0;
    sfIntRect rec;

    for (; i < value; tower = tower->next, support = support->next, i++);
    game->defender->selection->money -= prices[i];
    rec = sfSprite_getTextureRect(tower->sprite);
    MAP_TOWER[0] = add_block("ressource/all.png", MAP_TOWER[0], rec,
    (sfVector2f) {pos.x + 32, pos.y + 32});
    rec = sfSprite_getTextureRect(support->sprite);
    MAP_TOWER[1] = add_block("ressource/all.png", MAP_TOWER[1], rec, pos);
    rec = (sfIntRect){0, 0, 160, 160};
    pos = (sfVector2f) {pos.x - 8, pos.y - 8};
    MAP_TOWER[2] = add_block("ressource/cross.png", MAP_TOWER[2], rec, pos);
    rec = (sfIntRect){0, 0, 512, 512};
    MAP_TOWER[3] = add_block("ressource/upgrade.png", MAP_TOWER[3], rec,
    (sfVector2f){pos.x + 48, pos.y});
    add_stat_to_tower(game, value);
}

int add_map_tower(defender_t *game, sfVector2i mouse)
{
    sprite_t *tower = game->defender->selection->tower[0];
    int value = get_selectionned_tower(tower);
    sfVector2u size = sfRenderWindow_getSize(WIN);
    float s_x = (float)size.x / 1280;
    float s_y = (float)size.y / 720;
    int x = 0;
    int y = 0;

    for (; (x + 1) * 64 * s_x < mouse.x; x++);
    for (; (y + 1) * 64 * s_y < mouse.y; y++);
    sfVector2f pos = {x * 64, y * 64};
    if (value == -1 || MAP[y + 1][x + 1] != '2')
        return (1);
    add_the_tower(game, value, pos);
    return (SUCCESS);
}
