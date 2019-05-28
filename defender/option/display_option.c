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

int change_text(option_t *option, sfFont *font, sfRenderWindow *win)
{
    char *str = my_revstr(int_to_str(option->global_sound));
    char *frame = my_revstr(int_to_str(option->framerate));
    sfVector2f pos_f = option->button[4]->pos;
    sfVector2f pos = option->button[3]->pos;

    if (!str || !frame)
        return (ERROR);
    for (int i = 3; i < 5; i++)
        sfText_destroy(option->button[i]->text);
    pos.x *= (my_strlen(str) == 3) ? 0.97: (my_strlen(str) == 1) ? 1.03: 1;
    pos_f.x *= (my_strlen(frame) > 2) ? 0.97: (my_strlen(frame) == 1) ? 1.03: 1;
    option->button[3]->text = create_text(str, option->button[3]->size, font);
    option->button[4]->text = create_text(frame, option->button[4]->size, font);
    free(str);
    free(frame);
    draw_text(option->button[3]->text, pos, win);
    draw_text(option->button[4]->text, pos_f, win);
    return (SUCCESS);
}

void display_option_sprite(option_t *option, sfRenderWindow *win,
sfVector2i mouse)
{
    sfFloatRect rec;
    static int k = 0;
    sprite_t **save = option->other;

    for (int i = 0; save[i]; i++) {
        rec = sfSprite_getGlobalBounds(save[i]->sprite);
        rec = mouse_resize(win, rec);
        if (sfFloatRect_contains(&rec, mouse.x, mouse.y) && k > 1) {
            sfSprite_setTextureRect(save[i]->next->sprite, save[i]->next->rec);
            draw_sprite(save[i]->next->sprite, save[i]->next->pos, win);
        } else {
            sfSprite_setTextureRect(save[i]->sprite, save[i]->rec);
            draw_sprite(save[i]->sprite, save[i]->pos, win);
        }
    }
    k++;
}

void display_option(defender_t *game, sfVector2i mouse)
{
    display_back(game->back, WIN, CLOCK);
    change_text(game->option, FONT, WIN);
    draw_many_text(game->option->button, WIN, mouse, 1);
    for (int i = 1; i < 3; i++)
        draw_text(game->option->button[i]->text,
        game->option->button[i]->pos, WIN);
    display_option_sprite(game->option, WIN, mouse);
}