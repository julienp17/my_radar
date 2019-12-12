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
    #define TOWER_TEXTURE_PATH      "assets/textures/tower_small.png"

    typedef struct tower {
        sfVector2f pos;
        sfTexture *texture;
        sfSprite *sprite;
        sfCircleShape *control_area;
    } tower_t;

    tower_t *tower_create(sfVector2f pos, unsigned int radius);
    void tower_destroy(tower_t *tower);
#endif