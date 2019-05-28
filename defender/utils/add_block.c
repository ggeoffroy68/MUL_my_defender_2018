/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "define.h"
#include "lib.h"
#include "prototype.h"

sprite_t *add_block(char *res, sprite_t *list, sfIntRect rec, sfVector2f pos)
{
    sprite_t *new = malloc(sizeof(sprite_t));

    if (!new)
        return (NULL);
    new->texture = sfTexture_createFromFile(res, NULL);
    new->sprite = create_sprite(new->texture, 1);
    new->rec = rec;
    new->pos = pos;
    new->scale = sfSprite_getScale(new->sprite);
    new->status = 0;
    new->range = NULL;
    new->statistic = NULL;
    sfSprite_setTextureRect(new->sprite, new->rec);
    if (!list)
        new->next = NULL;
    else
        new->next = list;
    list = new;
    return (list);
}

static const rec_t SOLDIER[4] = {
    {{965, 640, 64, 64}},
    {{1024, 640, 64, 64}},
    {{1088, 640, 64, 64}},
    {{1152, 640, 64, 64}}
};

sprite_t *add_soldier_block(sprite_t *list, sprite_t *tmp, int type,
sfVector2f pos)
{
    sprite_t *new = malloc(sizeof(sprite_t));

    if (!new || !(new->statistic = malloc(sizeof(int) * 3)))
        return (NULL);
    new->texture = sfTexture_createFromFile("ressource/all.png", NULL);
    new->sprite = create_sprite(new->texture, 1);
    sfSprite_setTextureRect(new->sprite, SOLDIER[type].rec);
    new->health = sfTexture_createFromFile("ressource/health_bar.png", NULL);
    new->health_bar = create_sprite(new->health, 1);
    new->pos = pos;
    new->status = RIGHT;
    new->statistic[0] = (type + 1) * 150;
    new->statistic[1] = (type + 1) * 150;
    if (!list)
        tmp = new;
    else {
        for (; list->next; list = list->next);
        list->next = new;
    }
    return (new->next = NULL, tmp);
}
