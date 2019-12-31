/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Functions to draw on the screen
*/

#include <SFML/Graphics.h>
#include "window.h"
#include "tower.h"
#include "plane.h"
#include "quadtree.h"
#include "my.h"

void draw_towers(sfRenderWindow *window, tower_t **towers)
{
    for (unsigned int i = 0 ; towers[i] ; i++) {
        sfRenderWindow_drawSprite(window, towers[i]->sprite, NULL);
        sfRenderWindow_drawCircleShape(window, towers[i]->control_area, NULL);
    }
}

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