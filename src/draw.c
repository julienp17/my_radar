/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Functions to draw on the screen
*/

#include <SFML/Graphics.h>
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

void draw_pause_menu(sfRenderWindow *window)
{
    sfRectangleShape *pause_menu = sfRectangleShape_create();
    sfColor pause_color = (sfColor) {50, 50, 50, 125};

    sfRectangleShape_setFillColor(pause_menu, pause_color);
    sfRectangleShape_setSize(pause_menu, (sfVector2f) {2560, 1440});
    sfRenderWindow_drawRectangleShape(window, pause_menu, NULL);
    sfRenderWindow_display(window);
    sfRectangleShape_destroy(pause_menu);
}