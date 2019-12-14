/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for airplane structure
*/

#ifndef AIRPLANE_H_
    #define AIRPLANE_H_

    #include <SFML/Graphics.h>

    #define PLANE_SYMBOL            'A'
    #define PLANE_TEXTURE_PATH      "assets/textures/plane2_small.png"

    typedef struct plane {
        sfVector2f pos;
        sfVector2f end;
        unsigned int speed;
        unsigned int delay;
        sfVector2f step;
        sfTexture *texture;
        sfSprite *sprite;
    } plane_t;

    plane_t *plane_create(sfVector2f departure, sfVector2f arrival,
                    unsigned int speed, unsigned int delay);
    void plane_update_pos(plane_t *plane);
    sfVector2f get_step_offset(sfVector2f point_a, sfVector2f point_b);
    float get_angle_from_coordinate(sfVector2f point_a, sfVector2f point_b);
#endif