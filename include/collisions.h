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

    sfBool plane_collided(plane_t *plane, tower_t **towers,
                        quadtree_t *quadtree, unsigned int c_time);
    sfBool plane_is_in_control_area(sfIntRect hitbox, tower_t **towers);
    sfBool plane_check_collisions(plane_t *plane, tower_t **towers,
                            quadtree_t *quadtree, unsigned int c_time);
#endif
