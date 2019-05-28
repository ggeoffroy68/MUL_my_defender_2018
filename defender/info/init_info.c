/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** struct.h
*/

#include "prototype.h"
#include <stdlib.h>

sfRenderWindow *create_win(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1280, 720, 64};
    sfImage *image = sfImage_createFromFile("ressource/icon.png");
    const sfUint8 *pixel = sfImage_getPixelsPtr(image);

    window =
    sfRenderWindow_create(video_mode, "My Defender", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, 200, 200, pixel);
    sfImage_destroy(image);
    return (window);
}

info_t *init_info(void)
{
    info_t *info = malloc(sizeof(info_t));

    info->clock_counter = malloc(sizeof(unsigned short int) * 2);
    if (!info || !info->clock_counter)
        return (NULL);
    for (int i = 0; i < 2; i++)
        info->clock_counter[i] = 1;
    info->scene = 0;
    info->clock = sfClock_create();
    info->font = sfFont_createFromFile("ressource/urbandefenderlaser.ttf");
    info->last_scene = 0;
    return (info);
}