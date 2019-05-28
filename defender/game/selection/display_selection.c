/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <math.h>
#include <stdlib.h>
#include "prototype.h"
#include "define.h"
#include "lib.h"

void display_coin(sprite_t *coin, info_t *info,
unsigned short int *money, sprite_t *soldier)
{
    static int pair = 0;

    if (info->clock && sfClock_getElapsedTime(info->clock).microseconds /
    info->clock_counter[1] > 75000 && get_number_of_soldier(soldier)) {
        if (pair == 0)
            (*money)++;
        pair = (pair == 0) ? 1: 0;
        if (coin->rec.left < 320)
            coin->rec.left += 64;
        else
            coin->rec.left = 0;
        info->clock_counter[1] += 2;
    }
    sfSprite_setTextureRect(coin->sprite, coin->rec);
    draw_sprite(coin->sprite, coin->pos, info->win);
}

void draw_the_rec(sprite_t **sprite, sfRenderWindow *win, sfVector2i mouse)
{
    sfFloatRect frec;
    sfIntRect irec = {80, 0, 80, 80};
    sprite_t *rec = sprite[2];

    for (; rec; rec = rec->next) {
        frec = sfSprite_getGlobalBounds(rec->sprite);
        frec = mouse_resize(win, frec);
        if (sfFloatRect_contains(&frec, mouse.x, mouse.y))
            sfSprite_setTextureRect(rec->sprite, irec);
        else if (rec->status) {
            irec.left = 160;
            sfSprite_setTextureRect(rec->sprite, irec);
        } else
            sfSprite_setTextureRect(rec->sprite, rec->rec);
        draw_sprite(rec->sprite, rec->pos, win);
    }
}

void display_prices(selection_t *selection, info_t *info, sfVector2i mouse)
{
    char *coin = my_revstr(int_to_str(selection->money));
    sfVector2f pos = selection->price[0]->pos;
    sfFloatRect rec;

    sfText_destroy(selection->price[0]->text);
    selection->price[0]->text = create_text(coin, 50, selection->font);
    sfText_setColor(selection->price[0]->text, sfBlack);
    sfText_setCharacterSize(selection->price[0]->text, 75 * pow(0.87,
    my_strlen(coin)));
    for (int i = 1; PRICE; i++) {
        rec = sfText_getGlobalBounds(PRICE->text);
        rec = mouse_resize(info->win, rec);
        if (i == 6 && sfFloatRect_contains(&rec, mouse.x, mouse.y))
            sfText_setCharacterSize(PRICE->text, 22);
        else
            sfText_setCharacterSize(PRICE->text, PRICE->size);
        draw_text(PRICE->text, PRICE->pos, info->win);
    }
    draw_text(selection->price[0]->text, pos, info->win);
    free(coin);
}

void draw_the_tower(sprite_t **sprite, sfRenderWindow *win, int money)
{
    int prices[5] = {2000, 1000, 500, 300, 150};
    sprite_t *tower = sprite[0];
    sprite_t *sup = sprite[1];
    sprite_t *tower_grey = sprite[3];
    sprite_t *sup_grey = sprite[4];

    for (int i = 0; sup; sup = sup->next, sup_grey = sup_grey->next, i++)
        if (money < prices[i])
            draw_sprite(sup_grey->sprite, sup_grey->pos, win);
        else
            draw_sprite(sup->sprite, sup->pos, win);
    for (int i = 0; tower; tower = tower->next,
        tower_grey = tower_grey->next, i++)
        if (money < prices[i])
            draw_sprite(tower_grey->sprite, tower_grey->pos, win);
        else
            draw_sprite(tower->sprite, tower->pos, win);
}

void display_selection(selection_t *selection, info_t *info, sprite_t *soldier,
sfVector2i mouse)
{
    sfVector2f pos = {1150, 0};

    draw_sprite(selection->rec_sp, pos, info->win);
    draw_the_rec(selection->tower, info->win, mouse);
    draw_the_tower(selection->tower, info->win, selection->money);
    display_coin(selection->coin, info, &selection->money, soldier);
    display_prices(selection, info, mouse);
}
