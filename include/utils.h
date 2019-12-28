/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for utilities
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include <SFML/Graphics.h>

    float get_angle_from_coordinate(sfVector2f point_a, sfVector2f point_b);
    sfBool pos_match(sfVector2f, sfVector2f);
    sfBool pos_are_near(sfVector2f, sfVector2f, float const threshold);
#endif