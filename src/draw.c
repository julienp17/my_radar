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

void draw_towers(sfRenderWindow *window, tower_t **towers)
{
    for (unsigned int i = 0 ; towers[i] ; i++) {
        sfRenderWindow_drawSprite(window, towers[i]->sprite, NULL);
        sfRenderWindow_drawCircleShape(window, towers[i]->control_area, NULL);
    }
}

void draw_planes(sfRenderWindow *window, plane_t **planes, sfClock *clock)
{
    for (unsigned int i = 0 ; planes[i] ; i++) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > planes[i]->delay){
            plane_update_pos(planes[i]);
            sfRenderWindow_drawRectangleShape(window, planes[i]->hitbox, NULL);
        }
    }
}

void draw_pause_menu(window_t *window)
{
    sfRectangleShape *pause_menu = sfRectangleShape_create();
    sfColor pause_color = (sfColor) {50, 50, 50, 125};
    sfVector2f window_size = (sfVector2f) {window->width, window->height};

    sfRectangleShape_setFillColor(pause_menu, pause_color);
    sfRectangleShape_setSize(pause_menu, window_size);
    sfRenderWindow_drawRectangleShape(window->window, pause_menu, NULL);
    sfRenderWindow_display(window->window);
    sfRectangleShape_destroy(pause_menu);
}