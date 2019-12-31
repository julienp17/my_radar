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
    #include "utils.h"

    #define PLANE_SYMBOL            'A'
    #define PLANE_SPRITE_SIZE       20.0

    typedef struct plane {
        path_t *path;
        unsigned int delay;
        float angle;
        sfFloatRect hitbox;
        sfSprite *sprite;
        sfRectangleShape *outline;
    } plane_t;

    plane_t *plane_create(path_t *path, sfTexture *texture, uint delay,
                            uint w_width);
    plane_t *plane_init(plane_t *plane, path_t *path, uint delay, uint w_width);
    void plane_destroy(plane_t *plane);
    void plane_move(plane_t *plane, sfVector2f const offset, uint w_width);
    void plane_reset_random(plane_t *plane, tower_t **towers,
                            uint c_time, uint w_width);
#endif