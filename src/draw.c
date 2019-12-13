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

void draw_planes(sfRenderWindow *window, plane_t **planes)
{
    for (unsigned int i = 0 ; planes[i] ; i++) {
        plane_update_pos(planes[i]);
        sfRenderWindow_drawSprite(window, planes[i]->sprite, NULL);
    }
}