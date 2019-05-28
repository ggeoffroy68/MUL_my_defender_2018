/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <stdarg.h>

#ifndef MY_H
    #define MY_H

typedef struct print_s {
    char type;
    int (*function)();
}print_t;

/**number.c**/
int my_getnbr(char const *);
char *int_to_str(int);
int get_int_size(int);

/**str_to_array.c**/
char **str_to_array(char *, char);

/**sttr_utils.c**/
char *my_strcpy(char *, char const *);
int my_strlen(char const *);
char *my_revstr(char *);
int my_strcmp(char const *, char const *);
char *my_strcat(char *, char *);

/**math.c**/
int my_pow(int, int);
int my_sqrt(int);

/***cfsml_utils.c***/
sfSprite *create_sprite(sfTexture *texture, float);
sfText *create_text(char *string, int size, sfFont *font);
void draw_sprite(sfSprite *sprite, sfVector2f, sfRenderWindow *window);
void draw_text(sfText *text, sfVector2f, sfRenderWindow *window);
sfIntRect create_rec(int top, int left, int width, int height);

#endif
