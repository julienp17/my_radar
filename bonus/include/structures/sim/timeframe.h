/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for structure timeframe
*/

#ifndef TIMEFRAME_H_
    #define TIMEFRAME_H_

    #include <SFML/Graphics.h>
    #include "sim_textures.h"

    typedef sfSprite sprite_t;
    typedef sfBool Bool;

    typedef struct timeframe {
        sprite_t *frame;
        Bool day_to_night;
    } timeframe_t;

    timeframe_t *timeframe_create(texture_t *texture, sfIntRect rect);
    void timeframe_destroy(timeframe_t *);
#endif