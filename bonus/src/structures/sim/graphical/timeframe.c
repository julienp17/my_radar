/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** Source file for structure timeframe
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "timeframe.h"
#include "sim_textures.h"

timeframe_t *timeframe_create(texture_t *texture, sfIntRect rect)
{
    timeframe_t *timeframe = malloc(sizeof(timeframe_t));

    if (!timeframe)
        return (NULL);
    timeframe->frame = sfSprite_create();
    timeframe->day_to_night = sfTrue;
    if (!(timeframe->frame))
        return (NULL);
    sfSprite_setTexture(timeframe->frame, texture, sfTrue);
    sfSprite_setTextureRect(timeframe->frame, rect);
    return (timeframe);
}

void timeframe_destroy(timeframe_t *timeframe)
{
    sfSprite_destroy(timeframe->frame);
    if (timeframe)
        free(timeframe);
}