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
        sfVector2i pos;
        unsigned int radius;
    } tower_t;

    tower_t *tower_create(sfVector2i pos, unsigned int radius);
    tower_t **get_towers_from_file(char const *file_path);
#endif