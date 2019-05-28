/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

sfFloatRect mouse_resize(sfRenderWindow *window, sfFloatRect pos)
{
    sfVector2u win = sfRenderWindow_getSize(window);
    float x = (float)win.x / (float)1280;
    float y = (float)win.y / (float)720;

    pos.width *= x;
    pos.height *= y;
    pos.top *= y;
    pos.left *= x;
    return (pos);
}