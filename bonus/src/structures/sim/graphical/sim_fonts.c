/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** Source file for structure sim_fonts
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "sim_fonts.h"

sim_fonts_t *sim_fonts_create(void)
{
    sim_fonts_t *fonts = malloc(sizeof(sim_fonts_t));

    if (!fonts)
        return (NULL);
    fonts->skyfont = sfFont_createFromFile(SKYFONT_FONT_PATH);
    fonts->falling_sky = sfFont_createFromFile(FALLING_SKY_FONT_PATH);
    if (!(fonts->skyfont) || !(fonts->falling_sky))
        return (NULL);
    return (fonts);
}

void sim_fonts_destroy(sim_fonts_t *fonts)
{
    if (fonts->skyfont)
        sfFont_destroy(fonts->skyfont);
    if (fonts->falling_sky)
        sfFont_destroy(fonts->falling_sky);
    if (fonts)
        free(fonts);
}