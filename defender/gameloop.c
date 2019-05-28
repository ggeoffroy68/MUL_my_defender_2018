/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"


int gameloop(defender_t *game)
{
    FRAME = 60;
    sfMusic_play(game->music->back[0]);
    while (sfRenderWindow_isOpen(WIN)) {
        sfRenderWindow_setFramerateLimit(WIN, FRAME);
        sfRenderWindow_clear(WIN, sfBlack);
        sfMusic_setVolume(game->music->back[0], GSOUND);
        do_event(game);
        scene_manager(game);
        sfRenderWindow_display(WIN);
    }
    return (SUCCESS);
}
