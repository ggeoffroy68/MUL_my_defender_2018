/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "lib.h"
#include "define.h"
#include "prototype.h"

static const rec_t ROAD[3][3] = {
    {{{192, 0, 64, 64}}, {{64, 128, 64, 64}}, {{256, 0, 64, 64}}},
    {{{128, 64, 64, 64}}, {{64, 256, 64, 64}}, {{0, 64, 64, 64}}},
    {{{192, 64, 64, 64}}, {{64, 0, 64, 64}}, {{256, 64, 64, 64}}},
};

static const rec_t CORNER[2][2] = {
    {{{128, 128, 64, 64}}, {{0, 128, 64, 64}}},
    {{{128, 0, 64, 64}}, {{0, 0, 64, 64}}}
};

sfIntRect check_corner(char **map, int i, int j)
{
    sfIntRect returned = {64, 256, 64, 64};

    for (int k = - 1, u = 0; k < 2; k += 2, u++)
        for (int z = - 1, p = 0; z < 2; z += 2, p++)
            returned = (map[i + k][j + z] != '1' && map[i + k][j + z] != '*')
            ? CORNER[u][p].rec: returned;
    return (returned);
}

sfIntRect check(char **map, int i, int j)
{
    int height = 0;
    int width = 0;

    for (int k = -1; k < 2; k++)
        if (map[i + k][j] != '1' && map[i + k][j] != '*')
            height += k;
    for (int k = -1; k < 2; k++)
        if (map[i][j + k] != '1' && map[i][j + k] != '*')
            width += k;
    if (width == 0 && height == 0)
        return (check_corner(map, i, j));
    return (ROAD[height + 1][width + 1].rec);
}

void choose_which(char **map, int i, int j, sprite_t *object)
{
    sfIntRect craftable = {1024, 64, 64, 64};
    sfIntRect grass = {64, 64, 64, 64};

    if (map[i][j] == '1')
        sfSprite_setTextureRect(object->sprite, check(map, i , j));
    else if (map[i][j] == '2')
        sfSprite_setTextureRect(object->sprite, craftable);
    else
        sfSprite_setTextureRect(object->sprite, grass);
}

void if_mouse(sprite_t *object, char **map, sfRenderWindow *window,
int *counter)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2u win = sfRenderWindow_getSize(window);
    sfVector2f pos;
    float x = (float)win.x / (float)1280;
    float y = (float)win.y / (float)720;

    pos.x = (counter[1] - 1) * 64;
    pos.y = (counter[0] - 1) * 64;
    if (mouse.x <= (counter[1] - 1) * 64 * x + 64 * x
    && mouse.x >= (counter[1] - 1) * 64 * x
    && mouse.y <= (counter[0] - 1) * 64 * y + 64 * y
    && mouse.y >= (counter[0] - 1) * 64 * y) {
        choose_which(map, counter[0], counter[1], object->next);
        draw_sprite(object->next->sprite, pos, window);
    } else {
        choose_which(map, counter[0], counter[1], object);
        draw_sprite(object->sprite, pos, window);
    }
}

int print_map(sprite_t *object, char **map, sfRenderWindow *window)
{
    int *counter = malloc(sizeof(int) * 2);

    if (!counter)
        return (ERROR);
    for (int i = 1; map[i]; i++)
        for (int j = 1; map[i][j]; j++) {
            counter[0] = i;
            counter[1] = j;
            if_mouse(object, map, window, counter);
        }
    free(counter);
    return (SUCCESS);
}