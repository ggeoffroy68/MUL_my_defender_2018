/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

void draw_many_text(text_t **object, sfRenderWindow *win, sfVector2i mouse,
int repetition)
{
    sfFloatRect rec;
    sfVector2f pos;

    for (int i = 0; i < repetition; i++) {
        rec = sfText_getGlobalBounds(object[i]->text);
        pos = object[i]->pos;
        rec = mouse_resize(win, rec);
        if (sfFloatRect_contains(&rec, mouse.x, mouse.y)) {
            sfText_setCharacterSize(object[i]->text, object[i]->size * 1.2);
            pos.x *= 0.95;
            pos.y *= 0.95;
        } else
            sfText_setCharacterSize(object[i]->text, object[i]->size);
        draw_text(object[i]->text, pos, win);
    }
}