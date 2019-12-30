/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Boolean functions for boundaries, represented by sfIntRect
*/

#include <math.h>
#include <SFML/Graphics.h>

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
    sfVector2f rect_center = {frect.left + frect.width / 2,
                            frect.top + frect.height / 2};
    int x = rect_center.x - circle_center.x;
    int y = rect_center.y - circle_center.y;

    return (pow(x, 2) + pow(y, 2) <= pow(circle_radius, 2));
}