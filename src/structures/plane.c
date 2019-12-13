/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for airplane structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "plane.h"

plane_t *plane_create(sfVector2f departure, sfVector2f arrival,
                    unsigned int speed, unsigned int delay)
{
    plane_t *plane   = malloc(sizeof(*plane));

    plane->pos       = departure;
    plane->end       = arrival;
    plane->rect      = (sfIntRect) {departure.x, departure.y, 20, 20};
    plane->speed     = speed;
    plane->delay     = delay;
    plane->texture   = sfTexture_createFromFile(PLANE_TEXTURE_PATH,
                                                &(plane->rect));
    plane->sprite    = sfSprite_create();
    sfSprite_setTexture(plane->sprite, plane->texture, sfTrue);
    return (plane);
}