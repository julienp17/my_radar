/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Utilities file for my_radar
*/

#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "plane.h"

float get_angle_from_coordinate(sfVector2f point_a, sfVector2f point_b)
{
    float dx = point_b.x - point_a.x;
    float dy = point_b.y - point_a.y;
    float radians = atan2f(dx, dy);

    if (radians < 0.0)
        radians = fabs(radians);
    else
        radians = 2 * M_PI - radians;
    return (180.0 / M_PI * radians);
}

sfVector2i get_rotated_point(sfVector2i point, sfVector2i center, float angle)
{
    sfVector2i rotated_point;

    angle = angle * (M_PI / 180);
    rotated_point.x = cos(angle) * (point.x - center.x)
                        - sin(angle) * (point.y - center.y) + center.x;
    rotated_point.y = sin(angle) * (point.x - center.x)
                        + cos(angle) * (point.y - center.y) + center.y;
    return (rotated_point);
}

sfVector2i *get_rotated_points(sfIntRect hitbox, float angle)
{
    sfVector2i center = {hitbox.left + hitbox.width / 2,
                        hitbox.top + hitbox.height / 2};
    sfVector2i *corners = malloc(sizeof(sfVector2i) * 4);

    corners[0] = (sfVector2i) {hitbox.left, hitbox.top};
    corners[1] = (sfVector2i) {hitbox.left + hitbox.width, hitbox.top};
    corners[2] = (sfVector2i) {hitbox.left, hitbox.top + hitbox.height};
    corners[3] = (sfVector2i) {hitbox.left + hitbox.width,
                                hitbox.top + hitbox.height};
    for (unsigned int i = 0 ; i < 4 ; i++)
        corners[i] = get_rotated_point(corners[i], center, angle);
    return (corners);
}

sfIntRect get_bounding_box_of_rotated(sfIntRect const hitbox, float angle)
{
    sfVector2i *corners = get_rotated_points(hitbox, angle);
    int min_x = corners[0].x;
    int max_x = corners[0].x;
    int min_y = corners[0].y;
    int max_y = corners[0].y;

    for (unsigned int i = 1 ; i < 4 ; i++) {
        if (corners[i].x < min_x)
            min_x = corners[i].x;
        if (corners[i].x > max_x)
            max_x = corners[i].x;
        if (corners[i].y < min_y)
            min_y = corners[i].y;
        if (corners[i].y > max_y)
            max_y = corners[i].y;
    }
    free(corners);
    return ((sfIntRect) {min_x, min_y, max_x - min_x, max_y - min_y});
}