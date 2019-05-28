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

static const ressource_t RES[4] = {
    {"MENU", {530, 0}, {0, 0, 0, 0}, 100},
    {"RESUME", {490, 175}, {0, 0, 0, 0}, 100},
    {"OPTIONS", {470, 350}, {0, 0, 0, 0}, 100},
    {"QUIT", {535, 525}, {0, 0, 0, 0}, 100},
};

text_t **init_pause_button(sfFont *font)
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
        button[i]->color = sfWhite;
    }
    return (button);
}

pause_t *init_pause(sfFont *font)
{
    pause_t *pause = malloc(sizeof(pause_t));

    pause->button = init_pause_button(font);
    if (!pause || !pause->button)
        return (NULL);
    return (pause);
}