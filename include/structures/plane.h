/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for airplane structure
*/

#ifndef AIRPLANE_H_
    #define AIRPLANE_H_

    #include <SFML/Graphics.h>
    #include "tower.h"
    #include "path.h"

    #define PLANE_SYMBOL            'A'

    typedef struct plane {
        path_t *path;
        unsigned int delay;
        sfRectangleShape *hitbox;
    } plane_t;

    plane_t *plane_create(path_t *path, sfTexture *texture, unsigned int delay);
    void plane_destroy(plane_t *plane);
    void plane_move(plane_t *plane, sfVector2f const offset);
    void plane_reset_random(plane_t *plane, tower_t **towers, sfClock *clock);
    float get_angle_from_coordinate(sfVector2f point_a, sfVector2f point_b);
#endif