/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** Source file for drawing the background
*/

#include <SFML/Graphics.h>

void draw_background(sfRenderWindow *window, sfSprite *background)
{
    sfRenderWindow_drawSprite(window, background, NULL);
}