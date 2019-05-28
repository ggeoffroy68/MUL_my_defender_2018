/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** struct.h
*/

#ifndef PROTOTYPE_H
    #define PROTOTYPE_H
    #include "struct.h"
/**info**/
info_t *init_info(void);
void destroy_info(info_t *);

/**init_random.c**/
int init_random(void);

/**launch_game.c**/
int launch_game(defender_t *, char *);

/**get_map.c**/
char **get_map(char *);

sfRenderWindow *create_win(void);
sfFloatRect mouse_resize(sfRenderWindow *, sfFloatRect);
sprite_t *add_block(char *, sprite_t *, sfIntRect, sfVector2f);
sprite_t *add_soldier_block(sprite_t *, sprite_t *, int,
sfVector2f);
void draw_many_text(text_t **, sfRenderWindow *, sfVector2i, int);
int tab_size(char **);

int gameloop(defender_t *);
void scene_manager(defender_t *);
int do_event(defender_t *);

int add_map_tower(defender_t *, sfVector2i);
sprite_t *free_tower(sprite_t *, int);
void free_the_tower(sprite_t *);
void focus_on_enemys(game_t *);
sprite_t **init_projectiles(void);
int detect_ennemy(sprite_t **, game_t *, info_t *, music_t *);
int pythagor(sfSprite *, sfSprite *, int);

void check_if_alone(selection_t *, int);
void display_game_part(defender_t *, sfVector2i, int);
void click_menu(defender_t *, sfVector2i);
void click_game(defender_t *, sfVector2i);
void click_help(defender_t *, sfVector2i);
void click_option(defender_t *, sfVector2i);
void click_pause(defender_t *, sfVector2i);

sfVector2i step1(defender_t *, sfVector2i, float coeff[2]);
sfVector2i step2(defender_t *, sfVector2i, float coeff[2]);
sfVector2i step3(defender_t *, sfVector2i, float coeff[2]);
sfVector2i step4(defender_t *, sfVector2i, float coeff[2]);
sfVector2i step5(defender_t *, sfVector2i, float coeff[2]);
sfVector2i move_mouse(sfVector2i, sfVector2f);

sprite_t **init_background(void);
void display_back(sprite_t **, sfRenderWindow *, sfClock *);
void destroy_background(sprite_t **);

game_t *init_game(char **, sfFont *);
text_t **init_wave(sfFont *);
void display_game(defender_t *, sfVector2i);
void display_wave(text_t **, int, sfRenderWindow *, sfFont *);
void display_map_tower(sprite_t **, sfRenderWindow *);
int clock_restart(info_t *, int);
void destroy_game(game_t *);

selection_t *init_selection(void);

sprite_t *setup_randomly_entities(char **);
int print_map(sprite_t *, char **, sfRenderWindow *);

sprite_t *soldier_number_type(sprite_t *, char **, int);
void move_soldier(sprite_t *, info_t *, game_t *, sfFont *);
void soldier(sprite_t *, sfRenderWindow *);
int check_number_of_soldier(sprite_t *, info_t *);
int get_number_of_soldier(sprite_t *);
void free_soldier(sprite_t *);

int end_of_wave(defender_t *);

void display_selection(selection_t *, info_t *, sprite_t *,
sfVector2i);
menu_t *init_menu(sfFont *);
void display_menu(defender_t *game, sfVector2i);
void destroy_menu(menu_t *);

option_t *init_option(sfFont *);
void display_option(defender_t *, sfVector2i);
void destroy_option(option_t *);

pause_t *init_pause(sfFont *);
void display_pause(defender_t *, sfVector2i);
void destroy_pause(pause_t *);

music_t *init_music(void);
void destroy_music(music_t *);

int display_life(sprite_t *, sfRenderWindow *);
sprite_t *launch_projectile(sprite_t *, int, int, sprite_t *);
void display_projectiles(sprite_t *, sprite_t *, sfRenderWindow *, music_t *);

help_t *init_help(void);
void display_help(defender_t *, sfVector2i);
void destroy_help(help_t *);

void destroy_selection(selection_t *);

#endif
