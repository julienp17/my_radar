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

    typedef struct plane {
        sfVector2i departure;
        sfVector2i arrival;
        unsigned int speed;
        unsigned int delay;
    } plane_t;

    plane_t *plane_create(sfVector2i departure, sfVector2i arrival,
                    unsigned int speed, unsigned int delay);
    plane_t **get_planes_from_file(char const *file_path);
#endif