/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for collisions
*/

#ifndef COLLISIONS_H_
    #define COLLISIONS_H_

    #include <SFML/Graphics.h>
    #include "sim.h"

    plane_t *get_collided_plane(plane_t *plane, tower_t **towers,
                                quadtree_t *quadtree);
    sfBool plane_is_in_control_area(sfFloatRect hitbox, tower_t **towers);
    plane_t *plane_check_collisions(plane_t *plane, quadtree_t *quadtree);
#endif
