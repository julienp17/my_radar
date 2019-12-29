/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Boolean functions for positions, represented by sfVector2f
*/

#include <math.h>
#include <SFML/Graphics.h>

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