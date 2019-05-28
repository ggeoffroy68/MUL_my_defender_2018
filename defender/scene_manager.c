/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "define.h"
#include "prototype.h"
#include "lib.h"

static const scene_t SCENE[5] = {
    {0, &display_menu}, {1, &display_game}, {2, &display_option},
    {3, &display_help}, {4, &display_pause}
};

void scene_manager(defender_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(WIN);

    for (int i = 0; i < 5; i++) {
        if (SCENE[i].scene == XSCENE)
            return (SCENE[i].function(game, mouse));
    }
}
