/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

void display_game_part(defender_t *game, sfVector2i mouse, int nb)
{
    sprite_t *save = game->defender->entities;

    print_map(game->defender->map, MAP, WIN);
    for (; save; save = save->next)
        draw_sprite(save->sprite, save->pos, WIN);
    soldier(game->defender->soldier, WIN);
    if (!nb)
        move_soldier(game->defender->soldier, game->info, game->defender,
        game->defender->selection->font);
    display_projectiles(game->defender->projectiles, game->defender->soldier,
    WIN, game->music);
    display_map_tower(MAP_TOWER, WIN);
    focus_on_enemys(game->defender);
    detect_ennemy(MAP_TOWER, game->defender, game->info, game->music);
    display_life(game->defender->soldier, WIN);
    display_selection(game->defender->selection, game->info,
    game->defender->soldier, mouse);
    check_number_of_soldier(game->defender->soldier, game->info);
    display_wave(game->defender->print_wave, game->defender->wave, WIN, FONT);
}

sfVector2i move_mouse(sfVector2i mouse, sfVector2f rec)
{
    mouse.x += rec.x + 32 < mouse.x ? -3: 0;
    mouse.y += rec.y + 32 < mouse.y ? -3: 0;
    mouse.x += rec.x + 32 > mouse.x ? 3: 0;
    mouse.y += rec.y + 32 > mouse.y ? 3: 0;
    return (mouse);
}

void display_help(defender_t *game, sfVector2i mouse)
{
    int step = game->help->step;
    sfVector2i save = mouse;
    sfVector2u win = sfRenderWindow_getSize(WIN);
    float coeff[2] = {(float)win.x / (float)1280, (float)win.y / (float)720};

    if (step == 0)
        mouse = step1(game, mouse, coeff);
    else if (step == 1)
        mouse = step2(game, mouse, coeff);
    else if (step == 2)
        mouse = step3(game, mouse, coeff);
    else if (step == 3)
        mouse = step4(game, mouse, coeff);
    else if (step == 4)
        mouse = step5(game, mouse, coeff);
    if (save.x != mouse.x || save.y != mouse.y)
        sfMouse_setPositionRenderWindow(mouse, WIN);
}
