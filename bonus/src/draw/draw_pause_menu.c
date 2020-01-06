/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** Source file for drawing the pause menu
*/

#include <SFML/Graphics.h>
#include "window.h"

void draw_pause_menu(window_t *window)
{
    sfRectangleShape *pause_menu = sfRectangleShape_create();
    sfColor pause_color = (sfColor) {50, 50, 50, 125};
    sfVector2f window_size = (sfVector2f) {window->width, window->height};

    sfRectangleShape_setFillColor(pause_menu, pause_color);
    sfRectangleShape_setSize(pause_menu, window_size);
    sfRenderWindow_drawRectangleShape(window->render, pause_menu, NULL);
    sfRenderWindow_display(window->render);
    sfRectangleShape_destroy(pause_menu);
}