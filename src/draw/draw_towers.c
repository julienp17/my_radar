/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Functions to draw on the screen
*/

#include <SFML/Graphics.h>
#include "window.h"
#include "tower.h"
#include "my.h"

void draw_towers(sfRenderWindow *window, tower_t **towers)
{
    for (unsigned int i = 0 ; towers[i] ; i++) {
        sfRenderWindow_drawSprite(window, towers[i]->sprite, NULL);
        sfRenderWindow_drawCircleShape(window, towers[i]->control_area, NULL);
    }
}