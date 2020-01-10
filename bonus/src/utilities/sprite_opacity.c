/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** Change the opacity of a sprite
*/

#include <SFML/Graphics.h>

unsigned char get_sprite_opacity(sfSprite *sprite)
{
    sfColor color;

    color = sfSprite_getColor(sprite);
    return (color.a);
}

void set_sprite_opacity(sfSprite *sprite, unsigned char opacity)
{
    sfColor color;

    color = sfSprite_getColor(sprite);
    color.a = opacity;
    sfSprite_setColor(sprite, color);
}

