/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** main.c
*/

#include <stdlib.h>
#include "prototype.h"
#include "define.h"
#include "lib.h"

static const rec_t REC[8] = {
    {{960, 320, 64, 64}}, {{1024, 320, 64, 64}}, {{1088, 320, 64, 64}},
    {{1152, 320, 64, 64}}, {{1216, 320, 64, 64}}, {{1280, 320, 64, 64}},
    {{1344, 320, 64, 64}}, {{1408, 320, 64, 64}}
};

int check_if_free(int height, int width, sprite_t *entity)
{
    if (!entity)
        return (FREE);
    for (; entity; entity = entity->next)
        if (height == (int)(entity->pos.y / 64) && width ==
            (int)(entity->pos.x / 64))
            return (NONFREE);
    return (FREE);
}

int check_if_possible(char **map, int *height, int *width, int i)
{
    for (int z = -1; z < 2; z++)
        if (map [*height + i][*width + z] == '1'
            || map[*height + i][*width + z] == '2')
            return (NONFREE);
    return (FREE);
}

int get_random(char **map, int *height, int *width, sprite_t *entity)
{
    static int counter = 0;

    counter++;
    *height = rand() % 10 + 1;
    *width = rand() % 17 + 1;
    if (counter == 1500)
        return (counter = 0, ERROR);
    if (*height == 0 || *width == 0)
        return (get_random(map, height, width, entity));
    for (int i = -1; i < 2; i++)
        if (check_if_possible(map, height, width, i) == NONFREE)
            return (get_random(map, height, width, entity));
    if (check_if_free(*height, *width, entity) == NONFREE)
        return (get_random(map, height, width, entity));
    counter = 0;
    return (SUCCESS);
}

sprite_t *setup_randomly_entities(char **map)
{
    int number = 0;
    int height = 0;
    int width = 0;
    int value;
    sprite_t *entity = NULL;
    sfVector2f pos;

    number = rand() % 30;
    for (int i = 0; i < number; i++) {
        value = get_random(map, &height, &width, entity);
        if (!value) {
            pos.x = width * 64;
            pos.y = height * 64;
            entity = add_block("ressource/all.png", entity,
            REC[rand() % 8].rec, pos);
        }
        if (!entity && !value)
            return (NULL);
    }
    return (entity);
}
