/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "define.h"
#include "prototype.h"
#include "lib.h"

static const ressource_t RES[13] = {
    {"RESUME", {950, 590}, {0, 0, 0, 0}, 100},
    {"SOUND:", {510, -5}, {0, 0, 0, 0}, 100},
    {"FRAMERATE:", {440, 250}, {0, 0, 0, 0}, 100},
    {"50", {600, 100}, {0, 0, 0, 0}, 100},
    {"60", {600, 350}, {0, 0, 0, 0}, 100},
    {"ressource/button.png", {480, 110}, {1 * 16, 160, 16, 16}, 6},
    {"ressource/button.png", {720, 110}, {0 * 16, 160, 16, 16}, 6},
    {"ressource/button.png", {575, 460}, {1 * 16, 16 * 11, 16, 16}, 6},
    {"ressource/button.png", {720, 360}, {1 * 16, 16 * 11, 16, 16}, 6},
    {"ressource/button_grey.png", {455, 105}, {1 * 16, 160, 16, 16}, 8},
    {"ressource/button_grey.png", {710, 105}, {0 * 16, 160, 16, 16}, 8},
    {"ressource/button_grey.png", {575, 490}, {1 * 16, 16 * 11, 16, 16}, 8},
    {"ressource/button_grey.png", {710, 360}, {1 * 16, 16 * 11, 16, 16}, 8}
};

text_t **init_option_button(sfFont *font)
{
    text_t **button = malloc(sizeof(text_t *) * 6);

    if (!button)
        return (NULL);
    button[5] = NULL;
    for (int i = 0; i < 5; i++) {
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

int add_linked(sprite_t *object, int value)
{
    object->next = malloc(sizeof(sprite_t));
    if (!object->next)
        return (ERROR);
    object->next->next = NULL;
    object->texture = sfTexture_createFromFile(RES[5 + value].name, NULL);
    object->sprite = create_sprite(object->texture, RES[5 + value].size);
    object->pos = RES[5 + value].pos;
    object->rec = RES[5 + value].rec;
    object->scale.x = RES[5 + value].size;
    object->scale.y = RES[5 + value].size;
    object->next->texture = sfTexture_createFromFile(RES[9 + value].name,
    NULL);
    object->next->sprite = create_sprite(object->next->texture,
    RES[9 + value].size);
    object->next->pos = RES[9 + value].pos;
    object->next->rec = RES[9 + value].rec;
    object->next->scale.x = RES[9 + value].size;
    object->next->scale.y = RES[9 + value].size;
    return (SUCCESS);
}

sprite_t **init_other(void)
{
    sprite_t **other = malloc(sizeof(sprite_t *) * 5);

    if (!other)
        return (NULL);
    other[4] = NULL;
    for (int i = 0; i < 4; i++) {
        other[i] = malloc(sizeof(sprite_t));
        if (!other[i] || add_linked(other[i], i))
            return (NULL);
        if (i == 2) {
            sfSprite_setRotation(other[i]->sprite, 180);
            sfSprite_setRotation(other[i]->next->sprite, 180);
        }
    }
    return (other);
}

option_t *init_option(sfFont *font)
{
    option_t *option = malloc(sizeof(option_t));

    if (!option)
        return (NULL);
    option->global_sound = 50.0;
    option->button = init_option_button(font);
    option->other = init_other();
    if (!option->button || !option->other)
        return (NULL);
    return (option);
}