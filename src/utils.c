/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Utilities file for my_radar
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "tower.h"

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

sfBool pos_match(sfVector2f pos_1, sfVector2f pos_2)
{
    return (pos_1.x == pos_2.x && pos_1.y == pos_2.x);
}

sfBool pos_are_near(sfVector2f pos_1, sfVector2f pos_2, float const threshold)
{
    float x_diff = fabs(pos_2.x - pos_1.x);
    float y_diff = fabs(pos_2.y - pos_1.y);

    return (x_diff <= threshold && y_diff <= threshold);
}