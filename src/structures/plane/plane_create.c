/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for airplane structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_radar.h"
#include "plane.h"

plane_t *plane_create(path_t *path, sfTexture *texture, uint delay,uint w_width)
{
    plane_t *plane = malloc(sizeof(*plane));
    sfVector2f sprite_center = {PLANE_SPRITE_SIZE / 2, PLANE_SPRITE_SIZE / 2};

    if (!plane)
        return (NULL);
    plane->sprite = sfSprite_create();
    plane->outline = sfRectangleShape_create();
    if (!(plane->sprite) || !(plane->outline))
        return (NULL);
    sfSprite_setTexture(plane->sprite, texture, sfTrue);
    sfSprite_setOrigin(plane->sprite, sprite_center);
    sfRectangleShape_setFillColor(plane->outline, sfTransparent);
    sfRectangleShape_setOutlineColor(plane->outline, sfYellow);
    sfRectangleShape_setOutlineThickness(plane->outline, 2.0);
    return (plane_init(plane, path, delay, w_width));
}

void plane_destroy(plane_t *plane)
{
    if (plane->path)
        free(plane->path);
    if (plane->sprite)
        sfSprite_destroy(plane->sprite);
    if (plane->outline)
        sfRectangleShape_destroy(plane->outline);
    if (plane)
        free(plane);
}