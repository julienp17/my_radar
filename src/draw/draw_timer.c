/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for drawing timer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "my.h"

static char *get_str_timer(unsigned int c_time);

void draw_timer(window_t *window, unsigned int c_time)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/skyfont.otf");
    sfVector2f pos = {window->width - 250, 0};

    sfText_setCharacterSize(text, 100);
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, get_str_timer(c_time));
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window->render, text, NULL);
}

static char *get_str_timer(unsigned int c_time)
{
    char *string = malloc(sizeof(char) * 6);
    unsigned int minutes = c_time / 60;
    unsigned int seconds = c_time % 60;

    string[0] = '\0';
    if (minutes < 10)
        string = my_strcat(string, "0");
    string = my_strcat(string, my_int_to_strnum(minutes));
    string = my_strcat(string, ":");
    if (seconds < 10)
        string = my_strcat(string, "0");
    string = my_strcat(string, my_int_to_strnum(seconds));
    return (string);
}