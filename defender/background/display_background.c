/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

void check_pos(sprite_t *sprite, int value, int restart)
{
    if (value <= 0) {
        if (sprite->pos.x <= value)
            sprite->pos.x = restart;
    } else {
        if (sprite->pos.x >= value)
            sprite->pos.x = restart;
    }
}

void move_back(sprite_t *background, sprite_t *tank, sfClock *gclock)
{
    if (sfClock_getElapsedTime(gclock).microseconds > 1000) {
        background->pos.x -= 2;
        background->next->pos.x -= 2;
        for (; tank; tank = tank->next) {
            tank->pos.x += 2;
            check_pos(tank, 1370, -70);
        }
        check_pos(background, -1280, 0);
        check_pos(background->next, 0, 1280);
    }
}

void display_back(sprite_t **back, sfRenderWindow *win, sfClock *gclock)
{
    sprite_t *background = back[0];
    sprite_t *tank = back[3];

    move_back(background, tank, gclock);
    for (; background; background = background->next)
        draw_sprite(background->sprite, background->pos, win);
    for (int i = 0; i < 20; i++) {
        draw_sprite(back[1]->sprite, (sfVector2f) {i * 64, back[1]->pos.y},
        win);
        draw_sprite(back[2]->sprite, (sfVector2f) {i * 64, back[2]->pos.y},
        win);
        draw_sprite(back[2]->sprite, (sfVector2f) {i * 64, back[2]->pos.y + 64},
        win);
    }
    for (; tank; tank = tank->next)
        draw_sprite(tank->sprite, tank->pos, win);
    draw_sprite(back[4]->sprite, back[4]->pos, win);
}