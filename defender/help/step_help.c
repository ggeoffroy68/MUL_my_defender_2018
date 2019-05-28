/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

sfVector2i step1(defender_t *game, sfVector2i mouse, float coeff[2])
{
    sprite_t *tower = game->defender->selection->tower[2];
    static int counter = 0;
    sfFloatRect floatrec;

    display_game_part(game, mouse, 1);
    for (; tower->next; tower = tower->next);
    floatrec = sfSprite_getGlobalBounds(tower->sprite);
    if (sfClock_getElapsedTime(CLOCK).microseconds > 1500000) {
        counter = counter == 0 ? 1: 0;
        sfClock_restart(CLOCK);
    }
    if (sfFloatRect_contains(&floatrec, mouse.x, mouse.y)) {
        if (counter == 0)
            draw_sprite(game->help->click[0]->sprite,
            game->help->click[0]->pos, WIN);
        else
            draw_sprite(game->help->click[0]->next->sprite,
            game->help->click[0]->next->pos, WIN);
    }
    return (move_mouse(mouse,
    (sfVector2f) {tower->pos.x * coeff[0], tower->pos.y * coeff[1]}));
}

sfVector2i step2(defender_t *game, sfVector2i mouse, float coeff[2])
{
    static int counter = 0;
    sfVector2f pos = {5 * 64 * coeff[0], 6 * 64 * coeff[1]};

    display_game_part(game, mouse, 1);
    if (sfClock_getElapsedTime(CLOCK).microseconds > 1500000) {
        counter = counter == 0 ? 1: 0;
        sfClock_restart(CLOCK);
    }
    if (mouse.x >= pos.x && mouse.x <= pos.x + 64 && mouse.y >= pos.y
    && mouse.y <= pos.y + 64) {
        if (counter == 0)
            draw_sprite(game->help->click[1]->sprite,
            game->help->click[1]->pos, WIN);
        else
            draw_sprite(game->help->click[1]->next->sprite,
            game->help->click[1]->next->pos, WIN);
    }
    return (move_mouse(mouse, pos));
}

sfVector2i step3(defender_t *game, sfVector2i mouse, float coeff[2])
{
    int nb = get_number_of_soldier(game->defender->soldier);
    sprite_t *upgrade = MAP_TOWER[3];
    sfVector2f pos;

    display_game_part(game, mouse, 0);
    if (upgrade) {
        for (; upgrade->next; upgrade = upgrade->next);
        pos = upgrade->pos;
        pos.x *= coeff[0];
        pos.y *= coeff[1];
    }
    if (!nb) {
        pos.x -= 24 * coeff[0];
        pos.y -= 24 * coeff[1];
        mouse = move_mouse(mouse, pos);
    }
    return (mouse);
}

sfVector2i step4(defender_t *game, sfVector2i mouse, float coeff[2])
{
    sprite_t *cross = MAP_TOWER[2];
    sfVector2f pos;

    display_game_part(game, mouse, 0);
    if (cross) {
        for (; cross->next; cross = cross->next);
        pos = cross->pos;
        pos.x *= coeff[0];
        pos.y *= coeff[1];
        pos.x -= 24 * coeff[0];
        pos.y -= 24 * coeff[1];
        mouse = move_mouse(mouse, pos);
    }
    return (mouse);
}

sfVector2i step5(defender_t *game, sfVector2i mouse, float coeff[2])
{
    text_t *next = game->defender->selection->price[6];
    sfVector2f pos = next->pos;

    display_game_part(game, mouse, 0);
    pos.x *= coeff[0];
    pos.y *= coeff[1];
    pos.x += 40 * coeff[0];
    pos.y -= 15 * coeff[1];
    return (move_mouse(mouse, pos));
}
