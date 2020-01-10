/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** Source file for structure timeframe
*/

#include <stdio.h>
#include <stdlib.h>
#include "window.h"
#include "sim_textures.h"
#include "math.h"
#include "timelapse.h"
#include "utils.h"

static timeframe_t **set_timeframes(window_t *window, texture_t *texture,
                                    tw_state_t twilight_state);
static unsigned int get_tw_sprite_opacity(unsigned int i,
                            unsigned int trans_sprite_len, tw_state_t twilight);

timelapse_t *timelapse_create(window_t *window, texture_t *night_texture)
{
    timelapse_t *timelapse = malloc(sizeof(timelapse_t));
    tw_state_t twilight_state = DUSK;

    if (!timelapse)
        return (NULL);
    timelapse->dusk = set_timeframes(window, night_texture, twilight_state);
    twilight_state = NIGHT;
    timelapse->night = set_timeframes(window, night_texture, twilight_state);
    twilight_state = DAWN;
    timelapse->dawn = set_timeframes(window, night_texture, twilight_state);
    if (!(timelapse->dusk) || !(timelapse->night) || !(timelapse->dawn))
        return (NULL);
    return (timelapse);
}

void timelapse_destroy(timelapse_t *timelapse)
{
    for (unsigned int i = 0 ; timelapse->dawn[i] ; i++) {
        timeframe_destroy(timelapse->dawn[i]);
        timeframe_destroy(timelapse->dusk[i]);
    }
    for (unsigned int i = 0 ; timelapse->night[i] ; i++)
        timeframe_destroy(timelapse->night[i]);
    if (timelapse)
        free(timelapse);
}

static timeframe_t **set_timeframes(window_t *window, texture_t *texture,
                                    tw_state_t twilight_state)
{
    timeframe_t **timelapse = NULL;
    unsigned int nb_sprites = 0;
    unsigned int offset = 0;
    unsigned int night_sprite_len = get_percentage(window->width, 40);
    unsigned int trans_sprite_len = get_percentage(window->width, 10);
    unsigned int i = 0;

    nb_sprites = (twilight_state == NIGHT) ?night_sprite_len : trans_sprite_len;
    if (!(timelapse = malloc(sizeof(timeframe_t *) * (nb_sprites + 1))))
        return (NULL);
    if (twilight_state == NIGHT)
        offset = trans_sprite_len;
    else if (twilight_state == DAWN)
        offset = night_sprite_len + trans_sprite_len;
    while (i < nb_sprites) {
        timelapse[i] = timeframe_create(texture, (sfIntRect)
                {i + offset, 0, 1, window->height});
        sfSprite_move(timelapse[i]->frame, (sfVector2f)
                {i + offset, 0});
        set_sprite_opacity(timelapse[i]->frame,
                    get_tw_sprite_opacity(i, trans_sprite_len, twilight_state));
        i++;
    }
    timelapse[i] = NULL;
    return (timelapse);
}

static unsigned int get_tw_sprite_opacity(unsigned int i,
                            unsigned int trans_sprite_len, tw_state_t twilight)
{
    int opacity = (int)(ceil(255.0 / trans_sprite_len) * i);

    if (twilight == DUSK)
        return (opacity > 255) ? 255 : opacity;
    else if (twilight == DAWN)
        return (255 - opacity < 0 ? 0 : 255 - opacity);
    return (255);
}