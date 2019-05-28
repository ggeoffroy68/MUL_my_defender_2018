/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "lib.h"
#include "prototype.h"

void destroy_option(option_t *option)
{
    sprite_t *tmp;

    for (int i = 0; option->other[i]; i++) {
        for (; option->other[i]; option->other[i] = tmp) {
            tmp = option->other[i]->next;
            sfTexture_destroy(option->other[i]->texture);
            sfSprite_destroy(option->other[i]->sprite);
            free(option->other[i]);
        }
    }
    free(option->other);
    for (int i = 0; option->button[i]; i++) {
        sfText_destroy(option->button[i]->text);
        free(option->button[i]);
    }
    free(option->button);
    free(option);
}