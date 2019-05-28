/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** utils.c
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include "lib.h"

sfSprite *create_sprite(sfTexture *texture, float size)
{
    sfSprite *sprite;
    sfVector2f scale = {size, size};

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

sfText *create_text(char *string, int size, sfFont *font)
{
    sfText *text;

    text = sfText_create();
    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, size);
    return (text);
}

void draw_sprite(sfSprite *sprite, sfVector2f pos, sfRenderWindow *window)
{
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window , sprite, NULL);
}

void draw_text(sfText *text, sfVector2f pos, sfRenderWindow *window)
{
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
}

sfIntRect create_rec(int top, int left, int width, int height)
{
    sfIntRect rec;

    rec.top = top;
    rec.left = left;
    rec.width = width;
    rec.height = height;
    return (rec);
}