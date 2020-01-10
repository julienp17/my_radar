/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** Header file for struct graphical
*/

#ifndef GRAPHICAL_H_
    #define GRAPHICAL_H_

    #include "window.h"
    #include "sim_fonts.h"
    #include "sim_texts.h"
    #include "sim_textures.h"
    #include "timelapse.h"

    typedef struct graphical {
        window_t *window;
        timelapse_t *timelapse;
        textures_t *textures;
        fonts_t *fonts;
        texts_t *texts;
    } graphical_t;
    typedef graphical_t gl_t;

    gl_t *gl_create(window_t *window);
    void gl_destroy(gl_t *gl);
#endif