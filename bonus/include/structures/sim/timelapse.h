/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for structure timelapse
*/

#ifndef TIMELAPSE_H_
    #define TIMELAPSE_H_

    #include <SFML/Graphics.h>
    #include "window.h"
    #include "timeframe.h"
    #include "sim_textures.h"

    typedef sfSprite sprite_t;
    typedef sfBool Bool;

    typedef enum TWILIGHT_STATE {
        DUSK,
        NIGHT,
        DAWN
    } tw_state_t;

    typedef struct timelapse {
        timeframe_t **dusk;
        timeframe_t **night;
        timeframe_t **dawn;
    } timelapse_t;

    timelapse_t *timelapse_create(window_t *window, texture_t *texture);
    void timelapse_destroy(timelapse_t *);
#endif