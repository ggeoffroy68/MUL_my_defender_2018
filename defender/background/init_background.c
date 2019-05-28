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

static const ressource_t RES[5] = {
    {"ressource/back.png", {0, 0}, {0, 0, 1024, 1024}, 1},
    {"ressource/plateform.png", {0, 9 * 64}, {0, 0, 64, 64}, 1},
    {"ressource/plateform.png", {0, 10 * 64}, {3 * 64, 0, 64, 64}, 1},
    {"ressource/tanks.png", {0, 8 * 64}, {0, 0, 94, 70}, 1.75},
    {"ressource/icon.png", {1080, -50}, {0, 0, 200, 200}, 1},
};

sprite_t *init_back(void)
{
    sprite_t *new = malloc(sizeof(sprite_t));

    if (!new)
        return (NULL);
    new->texture = sfTexture_createFromFile(RES[0].name, NULL);
    new->sprite = create_sprite(new->texture, 1);
    sfSprite_setScale(new->sprite, (sfVector2f){1.25, 0.70});
    new->pos = (sfVector2f){RES[0].pos.x + 1280, RES[0].pos.y};
    new->next = NULL;
    return (new);
}

sprite_t ** malloc_back(void)
{
    sprite_t **back = malloc(sizeof(sprite_t *) * 6);

    if (!back)
        return (NULL);
    for (int i = 0; i < 5; i++) {
        back[i] = malloc(sizeof(sprite_t));
        if (!back[i])
            return (NULL);
        back[i]->texture = sfTexture_createFromFile(RES[i].name, NULL);
        back[i]->sprite = create_sprite(back[i]->texture, RES[i].size);
        back[i]->pos = RES[i].pos;
        back[i]->next = NULL;
        sfSprite_setTextureRect(back[i]->sprite, RES[i].rec);
    }
    back[5] = NULL;
    return (back);
}

sprite_t **init_background(void)
{
    sprite_t **back = malloc_back();
    sfIntRect rec;

    if (!back)
        return (NULL);
    sfSprite_setScale(back[0]->sprite, (sfVector2f){1.25, 0.70});
    back[0]->next = init_back();
    for (int i = 0; i < 7; i++) {
        rec = RES[3].rec;
        rec.top = (rand() % 2 == 0) ? 142:0;
        back[3] = add_block(RES[3].name, back[3], rec,
        (sfVector2f){RES[3].pos.x + i * 200, RES[3].pos.y});
    }
    return (back);
}
