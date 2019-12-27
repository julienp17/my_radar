/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for tower struct
*/

#ifndef TOWER_H_
    #define TOWER_H_

    #include <SFML/Graphics.h>

    #define TOWER_SYMBOL            'T'

    typedef struct tower {
        sfVector2f pos;
        sfSprite *sprite;
        sfCircleShape *control_area;
    } tower_t;

    tower_t *tower_create(sfVector2f pos, sfTexture *texture,
                        unsigned int radius);
    void tower_destroy(tower_t *tower);
#endif