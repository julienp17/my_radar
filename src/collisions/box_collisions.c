/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Boolean functions for boundaries, represented by sfIntRect
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "utils.h"

sfBool boundary_contains_pos(sfIntRect const boundary, sfVector2f const pos)
{
    return (pos.x >= boundary.left &&
            pos.x < boundary.left + boundary.width &&
            pos.y >= boundary.top &&
            pos.y < boundary.top + boundary.height
    );
}

sfBool boundary_overlaps(sfIntRect const boundary, sfIntRect const other)
{
    return !(
        other.left > boundary.left + boundary.width ||
        other.left + other.width < boundary.left ||
        other.top  > boundary.top + boundary.height ||
        other.top + other.height < boundary.top
    );
}

sfBool boundary_is_in_circle(sfFloatRect const frect, sfVector2f circle_center,
                        unsigned int circle_radius)
{
    sfVector2f *frect_corners = get_corners(frect);
    sfBool in_circle = sfFalse;

    for (unsigned int i = 0 ; i < 4 && !in_circle ; i++)
        if (point_is_in_circle(frect_corners[i], circle_center, circle_radius))
            in_circle = sfTrue;
    free(frect_corners);
    return (in_circle);
}

sfBool point_is_in_circle(sfVector2f point, sfVector2f circle_center,
                            unsigned int circle_radius)
{
    float x = point.x - circle_center.x;
    float y = point.y - circle_center.y;

    return (pow(x, 2) + pow(y, 2) <= pow(circle_radius, 2));
}