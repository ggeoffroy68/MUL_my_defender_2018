/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "prototype.h"
#include "lib.h"

void destroy_text(text_t **object)
{
    for (int i = 0; object[i]; i++) {
        sfText_destroy(object[i]->text);
        free(object[i]);
    }
    free(object);
}

void destroy_menu(menu_t *menu)
{
    destroy_text(menu->button);
    free(menu);
}