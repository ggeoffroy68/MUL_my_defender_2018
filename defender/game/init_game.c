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

sprite_t *init_map(void)
{
    sprite_t *map = malloc(sizeof(sprite_t));

    map->next = malloc(sizeof(sprite_t));
    map->next->next = NULL;
    if (!map || !map->next)
        return (NULL);
    map->texture = sfTexture_createFromFile("ressource/all.png", NULL);
    map->next->texture = sfTexture_createFromFile("ressource/all_grey.png",
    NULL);
    map->sprite = create_sprite(map->texture, 1);
    map->next->sprite = create_sprite(map->next->texture, 1);
    return (map);
}

text_t **init_wave(sfFont *font)
{
    text_t **print_wave = malloc(sizeof(text_t *) * 3);

    if (!print_wave)
        return (NULL);
    for (int i = 0; i < 2; i++) {
        print_wave[i] = malloc(sizeof(text_t));
        print_wave[i]->text = create_text(i == 0 ? "WAVE:": "0", 50, font);
        sfText_setColor(print_wave[i]->text, sfWhite);
        print_wave[i]->pos = (sfVector2f) {900 + (i * 150), 660};
    }
    print_wave[2] = NULL;
    return (print_wave);
}

game_t *init_game(char **map, sfFont *font)
{
    game_t *defender = malloc(sizeof(game_t));

    defender->map = init_map();
    defender->projectiles = NULL;
    defender->entities = setup_randomly_entities(map);
    defender->selection = init_selection();
    defender->print_wave = init_wave(font);
    defender->map_tower = malloc(sizeof(sprite_t *) * 5);
    for (int i = 0; i < 5; i++)
        defender->map_tower[i] = NULL;
    defender->soldier = soldier_number_type(defender->soldier, map, 0);
    if (!defender || !defender->map || !defender->selection ||
        !defender->map_tower ||
        !defender->print_wave)
        return (NULL);
    defender->wave = 1;
    defender->base_hp = 20;
    return (defender);
}
