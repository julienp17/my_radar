/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Boolean functions for boundaries, represented by sfIntRect
*/

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