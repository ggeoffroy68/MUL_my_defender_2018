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

void free_entities(sprite_t *entity)
{
    sprite_t *tmp;

    for (; entity != NULL; entity = tmp) {
        sfTexture_destroy(entity->texture);
        sfSprite_destroy(entity->sprite);
        tmp = entity->next;
        free(entity);
    }
    free(entity);
}

void destroy_map_tower(game_t *defender)
{
    sprite_t *next;

    for (int i = 0; i < 4; i++)
        for (; defender->map_tower[i]; defender->map_tower[i] = next) {
            next = defender->map_tower[i]->next;
            free_the_tower(defender->map_tower[i]);
        }
    free(defender->map_tower);
}

void destroy_projectiles(sprite_t * projectiles)
{
    sprite_t *tmp;

    for (; projectiles; projectiles = tmp) {
        tmp = projectiles->next;
        free(projectiles->statistic);
        sfTexture_destroy(projectiles->texture);
        sfSprite_destroy(projectiles->sprite);
        free(projectiles);
    }
}

void destroy_game(game_t *defender)
{
    sprite_t *tmp = NULL;

    for (; defender->map; defender->map = tmp) {
        tmp = defender->map->next;
        sfTexture_destroy(defender->map->texture);
        sfSprite_destroy(defender->map->sprite);
        free(defender->map);
    }
    destroy_selection(defender->selection);
    free_soldier(defender->soldier);
    destroy_map_tower(defender);
    for (int i = 0; defender->print_wave[i]; i++) {
        sfText_destroy(defender->print_wave[i]->text);
        free(defender->print_wave[i]);
    }
    destroy_projectiles(defender->projectiles);
    free(defender->print_wave);
    free_entities(defender->entities);
    free(defender);
}
