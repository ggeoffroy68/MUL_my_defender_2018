/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** struct.h
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

int check_init(defender_t *game, char **map)
{
    game->info = init_info();
    game->info->map = map;
    game->option = init_option(FONT);
    game->menu = init_menu(FONT);
    game->music = init_music();
    game->defender = init_game(map, FONT);
    game->pause = init_pause(FONT);
    game->help = init_help();
    game->back = init_background();
    if (!game->info || !game->menu || !game->option || !game->music ||
        !game->defender || !game->pause || !game->back)
        return (ERROR);
    WIN = create_win();
    return (SUCCESS);
}

int launch_game(defender_t *game, char *name)
{
    char **map = get_map(name);

    if (check_init(game, map) || gameloop(game))
        return (ERROR);
    destroy_menu(game->menu);
    destroy_option(game->option);
    destroy_game(game->defender);
    destroy_music(game->music);
    destroy_info(game->info);
    destroy_pause(game->pause);
    destroy_background(game->back);
    destroy_help(game->help);
    return (SUCCESS);
}
