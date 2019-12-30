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

    sfVector2i get_rotated_point(sfVector2i point, sfVector2i center,
                                float angle);
    sfVector2i *get_rotated_points(sfIntRect hitbox, float angle);
    sfIntRect get_bounding_box_of_rotated(sfIntRect const hitbox, float angle);

    sfBool pos_match(sfVector2f, sfVector2f);
    sfBool pos_are_near(sfVector2f, sfVector2f, float const threshold);
    sfBool boundary_contains_pos(sfIntRect const boundary,sfVector2f const pos);
    sfBool boundary_overlaps(sfIntRect const boundary, sfIntRect const other);
    sfBool boundary_is_in_circle(sfIntRect const rect, sfVector2f circle_center,
                        unsigned int circle_radius);
#endif