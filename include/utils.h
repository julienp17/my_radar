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

    sfVector2f get_rotated_point(sfVector2f point, sfVector2f center,
                                float angle);
    sfVector2f *get_corners(sfFloatRect rect);
    sfVector2f *get_rotated_corners(sfFloatRect hitbox, float angle);
    sfFloatRect get_bounding_box_of_rotated(sfFloatRect const hitbox,float angle);

    sfBool pos_match(sfVector2f, sfVector2f);
    sfBool pos_are_near(sfVector2f, sfVector2f, float const threshold);
    sfBool boundary_contains_pos(sfIntRect const boundary,sfVector2f const pos);
    sfBool boundary_overlaps(sfIntRect const boundary, sfIntRect const other);
    sfBool boundary_is_in_circle(sfFloatRect const frect,
                        sfVector2f circle_center, unsigned int circle_radius);
#endif