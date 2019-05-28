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

void click_menu(defender_t *game, sfVector2i mouse)
{
    sfFloatRect rec;
    int i = 0;

    for (; game->menu->button[i]; i++) {
        rec = sfText_getGlobalBounds(game->menu->button[i]->text);
        rec = mouse_resize(WIN, rec);
        if (sfFloatRect_contains(&rec, mouse.x, mouse.y) && i == 3)
            sfRenderWindow_close(WIN);
        if (sfFloatRect_contains(&rec, mouse.x, mouse.y)) {
            game->info->last_scene = XSCENE;
            XSCENE = i + 1;
        }
    }
}

void click_option(defender_t *game, sfVector2i mouse)
{
    sfFloatRect rec = sfText_getGlobalBounds(game->option->button[0]->text);
    int scene = XSCENE;

    rec = mouse_resize(WIN, rec);
    if (sfFloatRect_contains(&rec, mouse.x, mouse.y)) {
        XSCENE = game->info->last_scene;
        game->info->last_scene = scene;
    }
    for (int i = 0; game->option->other[i]; i++) {
        rec = sfSprite_getGlobalBounds(game->option->other[i]->sprite);
        rec = mouse_resize(WIN, rec);
        if (sfFloatRect_contains(&rec, mouse.x, mouse.y) && i < 2)
            GSOUND += (i == 0) ? -25: 25;
        if (sfFloatRect_contains(&rec, mouse.x, mouse.y) && i >= 2)
            FRAME += (i == 2) ? -1: 1;
    }
    GSOUND = (GSOUND < 0) ? 0: GSOUND;
    GSOUND = (GSOUND > 100) ? 100: GSOUND;
    FRAME = (FRAME > 144) ? 144: FRAME;
}

void click_pause(defender_t *game, sfVector2i mouse)
{
    sfFloatRect rec;

    for (int i = 0; game->pause->button[i]; i++) {
        rec = sfText_getGlobalBounds(game->pause->button[i]->text);
        rec = mouse_resize(WIN, rec);
        if (sfFloatRect_contains(&rec, mouse.x, mouse.y) && i == 3)
            sfRenderWindow_close(WIN);
        else if (sfFloatRect_contains(&rec, mouse.x, mouse.y) && i != 0) {
            game->info->last_scene = XSCENE;
            XSCENE = i;
        }
        else if (sfFloatRect_contains(&rec, mouse.x, mouse.y) && i == 0) {
            game->info->last_scene = XSCENE;
            XSCENE = i;
            destroy_game(game->defender);
            game->defender = init_game(MAP, FONT);
        }
    }
}
