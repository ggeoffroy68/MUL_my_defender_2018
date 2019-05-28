/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

/**static const struct**/
typedef struct ressource_s {
    char *name;
    sfVector2f pos;
    sfIntRect rec;
    int size;
}ressource_t;

typedef struct rec_s {
    sfIntRect rec;
}rec_t;

typedef struct scene_s {
    int scene;
    void (*function)();
}scene_t;

/**reusable struct**/
typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *health;
    sfSprite *health_bar;
    sfTexture *texture;
    sfCircleShape *range;
    sfVector2f pos;
    sfIntRect rec;
    sfVector2f scale;
    int status;
    int *statistic;
    struct sprite_s *next;
} sprite_t;

typedef struct text_s {
    sfText *text;
    sfVector2f pos;
    sfColor color;
    int size;
    struct text_s *next;
} text_t;

/**used struct**/

typedef struct info_s {
    sfRenderWindow *win;
    sfClock *clock;
    sfFont *font;
    unsigned short int scene;
    unsigned short int *clock_counter;
    unsigned short int last_scene;
    char **map;
} info_t;

typedef struct menu_s {
    text_t **button;
} menu_t;

typedef struct option_s {
    text_t **button;
    sprite_t **other;
    float global_sound;
    unsigned int framerate;
} option_t;

typedef struct selection_s {
    sfFont *font;
    sprite_t **tower;
    sprite_t *coin;
    text_t **price;
    unsigned short int money;
    sfTexture *rec;
    sfSprite *rec_sp;
} selection_t;

typedef struct game_s {
    int base_hp;
    unsigned short int wave;
    text_t **print_wave;
    sprite_t *map;
    sprite_t *entities;
    selection_t *selection;
    sprite_t **map_tower;
    sprite_t *projectiles;
    sprite_t *soldier;
    sprite_t *rocket;
} game_t;

typedef struct music_s {
    sfMusic **back;
}music_t;

typedef struct help_s {
    game_t *defender;
    sprite_t **click;
    int step;
} help_t;

typedef struct pause_s {
    text_t **button;
    sprite_t *other;
} pause_t;

typedef struct defender_s {
    info_t *info;
    menu_t *menu;
    option_t *option;
    pause_t *pause;
    music_t *music;
    help_t *help;
    game_t *defender;
    sprite_t **back;
} defender_t;
#endif
