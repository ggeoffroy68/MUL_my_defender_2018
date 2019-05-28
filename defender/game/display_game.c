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

void display_map_tower(sprite_t **map_tower, sfRenderWindow *win)
{
    sprite_t *tower = map_tower[0];
    sprite_t *support = map_tower[1];

    if (!map_tower[0] || !map_tower[1] || !map_tower[2])
        return;
    for (; tower && support; tower = tower->next, support = support->next) {
        if (tower->status != UNSPAWN) {
            draw_sprite(support->sprite, support->pos, win);
            draw_sprite(tower->sprite, tower->pos, win);
        }
    }
}

void display_wave(text_t **wave, int nb_wave, sfRenderWindow *win, sfFont *f)
{
    char *str = my_revstr(int_to_str(nb_wave));

    sfText_destroy(wave[1]->text);
    wave[1]->text = create_text(str, 50, f);
    sfText_setColor(wave[1]->text, sfWhite);
    for (int i = 0; wave[i]; i++)
        draw_text(wave[i]->text, wave[i]->pos, win);
    free(str);
}

void display_game(defender_t *game, sfVector2i mouse)
{
    sprite_t *save = game->defender->entities;

    if (!MAP_TOWER[0])
        clock_restart(game->info, 1000000);
    print_map(game->defender->map, MAP, WIN);
    for (; save; save = save->next)
        draw_sprite(save->sprite, save->pos, WIN);
    soldier(game->defender->soldier, WIN);
    move_soldier(game->defender->soldier, game->info, game->defender,
    game->defender->selection->font);
    display_projectiles(game->defender->projectiles,
    game->defender->soldier, WIN, game->music);
    display_map_tower(MAP_TOWER, WIN);
    focus_on_enemys(game->defender);
    detect_ennemy(MAP_TOWER, game->defender, game->info, game->music);
    display_life(game->defender->soldier, WIN);
    display_selection(game->defender->selection, game->info,
    game->defender->soldier, mouse);
    check_number_of_soldier(game->defender->soldier, game->info);
    display_wave(game->defender->print_wave, game->defender->wave, WIN, FONT);
}
