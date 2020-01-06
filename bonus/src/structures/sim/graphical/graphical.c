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
    gl->texts = sim_texts_create(gl->fonts, window);
    gl->textures = sim_textures_create();
    if (!(gl->window) || !(gl->fonts) || !(gl->texts) || !(gl->textures))
        return (NULL);
    return (gl);
}

void gl_destroy(graphical_t *graphical)
{
    sim_fonts_destroy(graphical->fonts);
    sim_textures_destroy(graphical->textures);
    sim_texts_destroy(graphical->texts);
    window_destroy(graphical->window);
    if (graphical)
        free(graphical);
}