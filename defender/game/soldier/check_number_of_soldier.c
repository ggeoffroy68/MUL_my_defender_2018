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

int get_number_of_soldier(sprite_t *soldier)
{
    sprite_t *tmp = soldier;
    int nb = 0;

    for (; tmp; tmp = tmp->next)
        nb += (tmp->status != UNSPAWN) ? 1: 0;
    return (nb);
}

int check_number_of_soldier(sprite_t *soldier, info_t *info)
{
    sprite_t *tmp = soldier;
    char *str = NULL;
    sfText *text;
    int nb = get_number_of_soldier(tmp);

    str = my_revstr(int_to_str(nb));
    if (!str)
        return (ERROR);
    text = create_text(str, 75, info->font);
    sfText_setColor(text, sfWhite);
    draw_text(text, (sfVector2f) {10, 10}, info->win);
    sfText_destroy(text);
    free(str);
    return (SUCCESS);
}
