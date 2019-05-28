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

sfVector2f get_road_debut(char **map)
{
    int counter = 0;
    int pos = 0;
    sfVector2f vector = {32, 32};

    for (int i = 1; map[1][i]; i++) {
        counter += (map[1][i] == '1') ? 1: 0;
        pos = (map[1][i] == '1') ? i * 64: pos;
    }
    if (counter > 0)
        return (vector.x = pos - (counter / 2) * 64, vector);
    for (int i = 1; map[i]; i++) {
        counter += (map[i][1] == '1') ? 1: 0;
        pos = (map[i][1] == '1') ? i * 64: pos;
    }
    if (counter > 0)
        vector.y = pos - (counter * 64 / 2) - 32;
    return (vector);
}

sprite_t *soldier_number_type(sprite_t *soldier, char **map, int wave)
{
    sfVector2f pos = get_road_debut(map);
    int nb = 0;

    if (wave > 0)
        nb = (rand() % 3 * wave) + 3;
    else
        nb = 1;
    soldier = NULL;
    for (int i = 0; i < nb; i++) {
        soldier = add_soldier_block(soldier, soldier, rand() % 4, pos);
        if (!soldier || !soldier->statistic)
            return (NULL);
        pos.x -= 64;
    }
    return (soldier);
}
