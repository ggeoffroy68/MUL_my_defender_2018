/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** main.c
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

static const scene_t SCENE[5] = {
    {0, &click_menu}, {1, &click_game}, {2, &click_option},
    {3, &click_game}, {4, &click_pause}
};

void select_scene(defender_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(WIN);

    for (int i = 0; i < 5; i++) {
        if (SCENE[i].scene == XSCENE)
            return (SCENE[i].function(game, mouse));
    }
}

int do_event(defender_t *game)
{
    sfEvent event;
    sfVector2u size = sfRenderWindow_getSize(WIN);

    size.x = (size.x > 1280) ? 1280: 1920;
    size.y = (size.y > 720) ? 720: 1080;
    while (sfRenderWindow_pollEvent(WIN, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ))
            sfRenderWindow_close(WIN);
        else if (event.type == sfEvtMouseButtonReleased
            && event.mouseButton.button == sfMouseLeft)
            select_scene(game);
        else if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape
        && (XSCENE == 1|| XSCENE == 4 || XSCENE == 3)) {
            game->info->last_scene =
            (XSCENE != 4) ? XSCENE: game->info->last_scene;
            XSCENE = (XSCENE == 4) ? game->info->last_scene: 4;
        }
        else if (event.type == sfEvtKeyReleased && event.key.code == sfKeyR)
            sfRenderWindow_setSize(WIN, size);
    }
    return (SUCCESS);
}
