/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for structure sim_fonts
*/

#ifndef fonts_H_
    #define fonts_H_

    #include <SFML/Graphics.h>

    #define SKYFONT_FONT_PATH       "assets/fonts/skyfont.otf"
    #define FALLING_SKY_FONT_PATH   "assets/fonts/falling_sky.otf"

    typedef sfFont font_t;

    typedef struct sim_fonts {
        font_t *skyfont;
        font_t *falling_sky;
    } sim_fonts_t;

    sim_fonts_t *sim_fonts_create(void);
    void sim_fonts_destroy(sim_fonts_t *);
#endif