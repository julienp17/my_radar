/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for structure sim_texts
*/

#ifndef TEXTS_H_
    #define TEXTS_H_

    #include <SFML/Graphics.h>
    #include "window.h"
    #include "sim_fonts.h"

    typedef sfText text_t;

    typedef struct sim_texts {
        text_t *timer;
    } sim_texts_t;
    typedef sim_texts_t texts_t;

    sim_texts_t *sim_texts_create(sim_fonts_t *fonts, window_t *window);
    void sim_texts_destroy(sim_texts_t *);
#endif