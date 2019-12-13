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
    #define PLANE_TEXTURE_PATH      "assets/textures/plane_small.png"

    typedef struct plane {
        sfIntRect rect;
        sfVector2f pos;
        sfVector2f end;
        unsigned int speed;
        unsigned int delay;
        sfTexture *texture;
        sfSprite *sprite;
    } plane_t;

    plane_t *plane_create(sfVector2f departure, sfVector2f arrival,
                    unsigned int speed, unsigned int delay);
    plane_t **get_planes_from_file(char const *file_path);
#endif