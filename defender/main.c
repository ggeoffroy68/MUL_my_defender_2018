/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** main.c
*/

#include <stdlib.h>
#include "define.h"
#include "prototype.h"
#include "lib.h"

int main(int ac, char **av)
{
    char *name = (ac == 2) ? av[1]: "map.txt";
    defender_t *game = malloc(sizeof(defender_t));

    if (ac > 3 || init_random() || !game || launch_game(game, name))
        return (ERROR);
    free(game);
    return (SUCCESS);
}
