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

void destroy_background(sprite_t **back)
{
    sprite_t *tmp;

    for (int i = 0; back[i]; i++) {
        for (; back[i]; back[i] = tmp) {
            tmp = back[i]->next;
            sfSprite_destroy(back[i]->sprite);
            sfTexture_destroy(back[i]->texture);
            free(back[i]);
        }
    }
    free(back);
}