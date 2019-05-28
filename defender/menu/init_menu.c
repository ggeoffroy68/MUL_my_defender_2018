/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "prototype.h"
#include "lib.h"

static const ressource_t RES[4] = {
    {"PLAY", {560, 300}, {0, 0, 0, 0}, 100},
    {"OPTIONS", {10, 0}, {0, 0, 0, 0}, 100},
    {"HOW TO PLAY", {10, 590}, {0, 0, 0, 0}, 100},
    {"QUIT", {1070, 590}, {0, 0, 0, 0}, 100}
};

text_t **init_menu_button(sfFont *font)
{
    text_t **button = malloc(sizeof(text_t *) * 5);

    if (!button)
        return (NULL);
    button[4] = NULL;
    for (int i = 0; i < 4; i++) {
        button[i] = malloc(sizeof(text_t));
        if (!button[i])
            return (NULL);
        button[i]->text = create_text(RES[i].name, RES[i].size, font);
        button[i]->pos = RES[i].pos;
        button[i]->size = RES[i].size;
        button[i]->color = sfBlack;
        sfText_setColor(button[i]->text, sfBlack);
    }
    return (button);
}

menu_t *init_menu(sfFont *font)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (!menu)
        return (NULL);
    menu->button = init_menu_button(font);
    if (!menu->button)
        return (NULL);
    return (menu);
}