/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for structure sim_graphical
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graphical.h"

graphical_t *gl_create(window_t *window)
{
    graphical_t *gl = malloc(sizeof(graphical_t));

    if (!gl)
        return (NULL);
    gl->window = window;
    gl->fonts = sim_fonts_create();
    gl->texts = sim_texts_create(window, gl->fonts);
    gl->textures = sim_textures_create();
    gl->timelapse = timelapse_create(window, gl->textures->sim_bg_night);
    if (!(gl->timelapse) || !(gl->fonts) || !(gl->texts) || !(gl->textures))
        return (NULL);
    return (gl);
}

void gl_destroy(graphical_t *gl)
{
    timelapse_destroy(gl->timelapse);
    sim_fonts_destroy(gl->fonts);
    sim_textures_destroy(gl->textures);
    sim_texts_destroy(gl->texts);
    window_destroy(gl->window);
    if (gl)
        free(gl);
}