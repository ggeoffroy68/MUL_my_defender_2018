/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef DEFINE_H
    #define DEFINE_H
    #define FONT game->info->font
    #define WIN game->info->win
    #define CLOCK game->info->clock
    #define XSCENE game->info->scene
    #define GSOUND game->option->global_sound
    #define FRAME game->option->framerate
    #define MAP game->info->map
    #define MONEY game->defender->selection->money
    #define MAP_TOWER game->defender->map_tower
    #define PRICE selection->price[i]
    #define COORD_P projectiles->pos
    enum action {
        SUCCESS,
        FAIL,
        FREE,
        NONFREE,
        ERROR = 84,
    };
    enum movement {
        RIGHT,
        UP,
        DOWN,
        UNSPAWN
    };
#endif
