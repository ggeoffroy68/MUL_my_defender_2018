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

static const ressource_t RES[10] = {
    {"ressource/all.png", {1185, 40}, {19 * 64, 640, 64, 64}, 150},
    {"ressource/all.png", {1185, 140}, {20 * 64, 640, 64, 64}, 300},
    {"ressource/all.png", {1185, 240}, {19 * 64, 64 * 8, 64, 64}, 500},
    {"ressource/all.png", {1185, 350}, {20 * 64, 64 * 8, 64, 64}, 1000},
    {"ressource/all.png", {1185, 450}, {21 * 64, 64 * 8, 64, 64}, 2000},
    {"ressource/all.png", {1185, 50}, {19 * 64, 64 * 7, 64, 64}, 150},
    {"ressource/all.png", {1185, 150}, {19 * 64, 64 * 7, 64, 64}, 300},
    {"ressource/all.png", {1185, 250}, {20 * 64, 64 * 7, 64, 64}, 500},
    {"ressource/all.png", {1185, 350}, {20 * 64, 64 * 7, 64, 64}, 1000},
    {"ressource/all.png", {1185, 450}, {21 * 64, 64 * 7, 64, 64}, 2000}
};

static const ressource_t RE[10] = {
    {"ressource/all_grey.png", {1185, 40}, {19 * 64, 640, 64, 64}, 0},
    {"ressource/all_grey.png", {1185, 140}, {20 * 64, 640, 64, 64}, 0},
    {"ressource/all_grey.png", {1185, 240}, {19 * 64, 64 * 8, 64, 64}, 0},
    {"ressource/all_grey.png", {1185, 350}, {20 * 64, 64 * 8, 64, 64}, 0},
    {"ressource/all_grey.png", {1185, 450}, {21 * 64, 64 * 8, 64, 64}, 0},
    {"ressource/all_grey.png", {1185, 50}, {19 * 64, 64 * 7, 64, 64}, 0},
    {"ressource/all_grey.png", {1185, 150}, {19 * 64, 64 * 7, 64, 64}, 0},
    {"ressource/all_grey.png", {1185, 250}, {20 * 64, 64 * 7, 64, 64}, 0},
    {"ressource/all_grey.png", {1185, 350}, {20 * 64, 64 * 7, 64, 64}, 0},
    {"ressource/all_grey.png", {1185, 450}, {21 * 64, 64 * 7, 64, 64}, 0}
};

static const ressource_t REC[5] = {
    {"ressource/support_sheet.png", {1177, 24 + 12}, {0, 0, 80, 80}, 0},
    {"ressource/support_sheet.png", {1177, 124 + 12}, {0, 0, 80, 80}, 0},
    {"ressource/support_sheet.png", {1177, 234 + 8}, {0, 0, 80, 80}, 0},
    {"ressource/support_sheet.png", {1177, 334 + 8}, {0, 0, 80, 80}, 0},
    {"ressource/support_sheet.png", {1177, 434 + 8}, {0, 0, 80, 80}, 0},
};

static const ressource_t PRICES[7] = {
    {"200", {1170, 600}, {0, 0, 80, 80}, 50},
    {"150", {1215, 86}, {0, 0, 80, 80}, 25},
    {"300", {1210, 186}, {0, 0, 80, 80}, 25},
    {"500", {1210, 291}, {0, 0, 80, 80}, 25},
    {"1000", {1200, 391}, {0, 0, 80, 80}, 25},
    {"2000", {1198, 491}, {0, 0, 80, 80}, 25},
    {"NEXT WAVE", {1160, 670}, {0, 0, 80, 80}, 20},
};
sprite_t **init_selection_sprite(void)
{
    sprite_t **tower = malloc(sizeof(sprite_t *) * 6);

    if (!tower)
        return (NULL);
    for (int i = 0; i < 6; i++)
        tower[i] = NULL;
    for (int i = 0; i < 5; i++) {
        tower[0] = add_block(RES[i].name, tower[0], RES[i].rec, RES[i].pos);
        tower[1] = add_block(RES[i + 5].name, tower[1], RES[i + 5].rec,
        RES[i + 5].pos);
        tower[2] = add_block(REC[i].name, tower[2], REC[i].rec, REC[i].pos);
        tower[3] = add_block(RE[i].name, tower[3], RE[i].rec, RE[i].pos);
        tower[4] = add_block(RE[i + 5].name, tower[4], RE[i + 5].rec,
        RE[i + 5].pos);
    }
    return (tower);
}

text_t **init_price(sfFont *font)
{
    text_t **price = malloc(sizeof(text_t) * 8);

    if (!price)
        return (NULL);
    for (int i = 0; i < 7; i++) {
        price[i] = malloc(sizeof(text_t));
        price[i]->text = create_text(PRICES[i].name, PRICES[i].size, font);
        sfText_setColor(price[i]->text, sfBlack);
        price[i]->pos = PRICES[i].pos;
        price[i]->size = PRICES[i].size;
    }
    price[7] = NULL;
    return (price);
}

selection_t *init_selection(void)
{
    selection_t *selection = malloc(sizeof(selection_t));
    sfIntRect rec = {0, 0, 64, 66};
    sfVector2f coin = {1185, 530};

    selection->font = sfFont_createFromFile("ressource/urbandefendertitle.ttf");
    selection->tower = init_selection_sprite();
    selection->money = 300;
    selection->coin = malloc(sizeof(sprite_t));
    if (!selection || !selection->tower || !selection->coin)
        return (NULL);
    selection->rec = sfTexture_createFromFile("ressource/rec.png", NULL);
    selection->rec_sp = create_sprite(selection->rec, 1);
    selection->coin->texture =
    sfTexture_createFromFile("ressource/coin2.png", NULL);
    selection->coin->sprite = create_sprite(selection->coin->texture, 1);
    selection->coin->rec = rec;
    selection->coin->pos = coin;
    selection->price = init_price(selection->font);
    return (selection);
}