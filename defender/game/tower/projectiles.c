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
    {"ressource/all.png", {0, 0}, {19 * 64, 11 * 64, 64, 64}, 1},
    {"ressource/all.png", {0, 0}, {20 * 64, 11 * 64, 64, 64}, 1},
    {"ressource/all.png", {0, 0}, {21 * 64, 12 * 64, 64, 64}, 1},
    {"ressource/all.png", {0, 0}, {21 * 64, 10 * 64, 64, 64}, 1},
    {"ressource/all.png", {0, 0}, {21 * 64, 10 * 64, 64, 64}, 1},
};

sprite_t *launch_projectile(sprite_t *projectiles, int nb, int soldier,
sprite_t *tower)
{
    sprite_t *new = malloc(sizeof(sprite_t));
    sprite_t *tmp = projectiles;
    sfVector2f pos = tower->pos;

    if (!new)
        return (NULL);
    pos.x -= 32;
    pos.y -= 32;
    new->statistic = malloc(sizeof(int) * 1);
    if (!new->statistic)
        return (NULL);
    new->statistic[0] = tower->statistic[1];
    new->texture = sfTexture_createFromFile(RES[nb].name, NULL);
    new->sprite = create_sprite(new->texture, 1);
    sfSprite_setTextureRect(new->sprite, RES[nb].rec);
    new->status = soldier;
    new->pos = pos;
    new->next = NULL;
    if (!projectiles)
        return (new);
    else {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = new;
    }
    return (projectiles);
}

void follow_soldier(sprite_t *projectiles, sprite_t *tmp, sfRenderWindow *win,
music_t *music)
{
    sfFloatRect rec;

    for (int i = 0; i < projectiles->status && tmp; tmp = tmp->next, i++);
    if (projectiles->status == -1 || !tmp)
        return;
    rec = sfSprite_getGlobalBounds(tmp->sprite);
    if (sfFloatRect_contains(&rec, COORD_P.x + 32, COORD_P.y + 32)) {
        tmp->statistic[0] -= projectiles->statistic[0];
        projectiles->status = -1;
        if (tmp->statistic[0] <= 0) {
            tmp->status = UNSPAWN;
            sfMusic_stop(music->back[2]);
            sfMusic_play(music->back[2]);
        }
    }
    COORD_P.x += (COORD_P.x < tmp->pos.x) ? 3: 0;
    COORD_P.x -= (COORD_P.x > tmp->pos.x) ? 3: 0;
    COORD_P.y += (COORD_P.y < tmp->pos.y) ? 3: 0;
    COORD_P.y -= (COORD_P.y > tmp->pos.y) ? 3: 0;
    draw_sprite(projectiles->sprite, COORD_P, win);
}

void display_projectiles(sprite_t *projectiles, sprite_t *soldier,
sfRenderWindow *win, music_t *music)
{
    if (!projectiles)
        return;
    for (; projectiles; projectiles = projectiles->next)
        follow_soldier(projectiles, soldier, win, music);
}
