/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for button structure
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #include <SFML/Graphics.h>

    #define BUTTON_DEFAULT_FONT_PATH    "assets/fonts/falling_sky.otf"

    typedef struct button {
        sfRectangleShape *rect;
        sfText *text;
        sfFont *font;
    } button_t;

    button_t *button_create(char *text, char const *font_path,
                            sfVector2f pos, sfVector2f size);
    void button_destroy(button_t *button);
#endif