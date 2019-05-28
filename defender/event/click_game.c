/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

void check_if_alone(selection_t *selection, int value)
{
    sprite_t *rec = selection->tower[2];
    sprite_t *tower = selection->tower[0];
    sprite_t *support = selection->tower[1];

    for (int i = 0; rec; rec = rec->next, i++,
        tower = tower->next, support = support->next)
        if (rec->status && i != value) {
            rec->status = 0;
            tower->status = 0;
            support->status = 0;
        }
}

void check_end_of_wave(defender_t *game, sfVector2i mouse, sfFloatRect frec)
{
    sprite_t *tmp = game->defender->soldier;
    int nb = get_number_of_soldier(tmp);
    sfVector2u win = sfRenderWindow_getSize(WIN);
    float coeff[2] = {(float)win.x / (float)1280, (float)win.y / (float)720};
    sfVector2f pos = {5 * 64 * coeff[0], 6 * 64 * coeff[1]};

    for (; tmp; tmp = tmp->next)
        nb += (tmp->status != UNSPAWN) ? 1: 0;
    if (XSCENE == 3 && mouse.x >= pos.x && mouse.x <= pos.x + 64
        && mouse.y >= pos.y && mouse.y <= pos.y + 64)
        game->help->step = game->help->step == 1 ? 2: game->help->step;
    frec = sfText_getGlobalBounds(game->defender->selection->price[6]->text);
    frec = mouse_resize(WIN, frec);
    if (sfFloatRect_contains(&frec, mouse.x, mouse.y) && !nb) {
        if (XSCENE == 3) {
            XSCENE = 0;
            destroy_game(game->defender);
            game->defender = init_game(MAP, FONT);
        } else
            end_of_wave(game);
    }
}

void click_third_game(defender_t *game, sfVector2i mouse)
{
    sfFloatRect frec;
    sprite_t *tower = MAP_TOWER[0];
    sprite_t *upgrade = MAP_TOWER[3];

    for (; upgrade; upgrade = upgrade->next, tower = tower->next) {
        frec = sfSprite_getGlobalBounds(upgrade->sprite);
        frec = mouse_resize(WIN, frec);
        if (sfFloatRect_contains(&frec, mouse.x, mouse.y) &&
        game->defender->selection->money > 100) {
            sfSprite_setColor(tower->sprite, sfBlue);
            game->help->step = game->help->step == 2 ? 3: game->help->step;
            upgrade->status = 1;
            game->defender->selection->money -= 100;
            tower->statistic[1] += 25;
            return;
        }
    }
    check_end_of_wave(game, mouse, frec);
}

void click_second_game(defender_t *game, sfVector2i mouse)
{
    sfFloatRect frec;
    int sale[5] = {1000, 500, 250, 150, 75};
    sprite_t *cross = MAP_TOWER[2];

    if (mouse.x < 1150 && !add_map_tower(game, mouse))
        check_if_alone(game->defender->selection, 8);
    for (int i = 0; cross; cross = cross->next, i++) {
        frec = sfSprite_getGlobalBounds(cross->sprite);
        frec = mouse_resize(WIN, frec);
        if (sfFloatRect_contains(&frec, mouse.x, mouse.y)) {
            game->defender->selection->money += sale[MAP_TOWER[0]->status];
            MAP_TOWER[3] = free_tower(MAP_TOWER[3], i);
            MAP_TOWER[2] = free_tower(MAP_TOWER[2], i);
            MAP_TOWER[1] = free_tower(MAP_TOWER[1], i);
            MAP_TOWER[0] = free_tower(MAP_TOWER[0], i);
            game->help->step = game->help->step == 3 ? 4: game->help->step;
            return;
        }
    }
    click_third_game(game, mouse);
}

void click_game(defender_t *game, sfVector2i mouse)
{
    sfFloatRect frec;
    int prices[5] = {2000, 1000, 500, 300, 150};
    sprite_t *rec = game->defender->selection->tower[2];
    sprite_t *tower = game->defender->selection->tower[0];
    sprite_t *support = game->defender->selection->tower[1];

    for (int i = 0; rec; rec = rec->next, tower = tower->next,
    support = support->next, i++) {
        frec = sfSprite_getGlobalBounds(rec->sprite);
        frec = mouse_resize(WIN, frec);
        if (sfFloatRect_contains(&frec, mouse.x, mouse.y) &&MONEY > prices[i]) {
            check_if_alone(game->defender->selection, i);
            rec->status = (rec->status) ? 0: 1;
            tower->status = (tower->status) ? 0: 1;
            support->status = (support->status) ? 0: 1;
            game->help->step = game->help->step == 0
            && XSCENE == 3 ? 1: game->help->step;
        }
    }
    click_second_game(game, mouse);
}
