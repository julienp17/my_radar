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

sfVector2f get_rotated_point(sfVector2f point, sfVector2f center, float angle)
{
    sfVector2f rotated_point;

    angle = angle * (M_PI / 180);
    rotated_point.x = cos(angle) * (point.x - center.x)
                        - sin(angle) * (point.y - center.y) + center.x;
    rotated_point.y = sin(angle) * (point.x - center.x)
                        + cos(angle) * (point.y - center.y) + center.y;
    return (rotated_point);
}

sfVector2f *get_corners(sfFloatRect rect)
{
    sfVector2f *corners = malloc(sizeof(sfVector2f) * 4);

    if (!corners)
        return (NULL);
    corners[0] = (sfVector2f) {rect.left, rect.top};
    corners[1] = (sfVector2f) {rect.left + rect.width, rect.top};
    corners[2] = (sfVector2f) {rect.left, rect.top + rect.height};
    corners[3] = (sfVector2f) {rect.left + rect.width,
                                rect.top + rect.height};
    return (corners);
}

sfVector2f *get_rotated_corners(sfFloatRect hitbox, float angle)
{
    sfVector2f center = {hitbox.left + hitbox.width / 2.0,
                        hitbox.top + hitbox.height / 2.0};
    sfVector2f *corners = get_corners(hitbox);

    if (!corners)
        return (NULL);
    for (unsigned int i = 0 ; i < 4 ; i++)
        corners[i] = get_rotated_point(corners[i], center, angle);
    return (corners);
}

sfFloatRect get_bounding_box_of_rotated(sfFloatRect const hitbox, float angle)
{
    sfVector2f *rotated_corners = get_rotated_corners(hitbox, angle);
    float min_x = rotated_corners[0].x;
    float max_x = rotated_corners[0].x;
    float min_y = rotated_corners[0].y;
    float max_y = rotated_corners[0].y;

    for (unsigned int i = 1 ; i < 4 ; i++) {
        if (rotated_corners[i].x < min_x)
            min_x = rotated_corners[i].x;
        if (rotated_corners[i].x > max_x)
            max_x = rotated_corners[i].x;
        if (rotated_corners[i].y < min_y)
            min_y = rotated_corners[i].y;
        if (rotated_corners[i].y > max_y)
            max_y = rotated_corners[i].y;
    }
    free(rotated_corners);
    return ((sfFloatRect) {min_x, min_y, max_x - min_x, max_y - min_y});
}