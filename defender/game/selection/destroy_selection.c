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

void free_selection_tower(selection_t *selection)
{
    sprite_t *tmp;

    for (int i = 0; selection->tower[i]; i++)
        for (; selection->tower[i]; selection->tower[i] = tmp) {
            tmp = selection->tower[i]->next;
            sfSprite_destroy(selection->tower[i]->sprite);
            sfTexture_destroy(selection->tower[i]->texture);
            free(selection->tower[i]);
        }
    free(selection->tower);
}

void destroy_selection(selection_t *selection)
{
    sfFont_destroy(selection->font);
    free_selection_tower(selection);
    for (int i = 0; selection->price[i]; i++) {
        sfText_destroy(selection->price[i]->text);
        free(selection->price[i]);
    }
    free(selection->price);
    sfTexture_destroy(selection->rec);
    sfSprite_destroy(selection->rec_sp);
    sfTexture_destroy(selection->coin->texture);
    sfSprite_destroy(selection->coin->sprite);
    free(selection->coin);
    free(selection);
}