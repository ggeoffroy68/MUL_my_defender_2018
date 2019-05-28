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

static const ressource_t RES[3] = {
    {"ressource/ambiance.ogg", {0, 0}, {0, 0, 0, 0}, 0},
    {"ressource/canon.ogg", {0, 0}, {0, 0, 0, 0}, 0},
    {"ressource/aie.ogg", {0, 0}, {0, 0, 0, 0}, 0},

};

music_t *init_music(void)
{
    music_t *music = malloc(sizeof(music_t));

    music->back = malloc(sizeof(sfMusic *) * 4);
    if (!music || !music->back)
        return (NULL);
    music->back[3] = NULL;
    for (int i = 0; i < 3; i++)
        music->back[i] = sfMusic_createFromFile(RES[i].name);
    sfMusic_setLoop(music->back[0], sfTrue);
    return (music);
}
