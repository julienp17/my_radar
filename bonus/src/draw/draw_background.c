/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** Source file for drawing the background
*/

#include <SFML/Graphics.h>
#include "window.h"
#include "timelapse.h"
#include "utils.h"
#include "math.h"

void move_timeframe(window_t *window, sprite_t *sprite);

void draw_background(window_t *window, sfSprite *background,
                    timelapse_t *timelapse)
{
    unsigned int night_sprite_len = 0;
    unsigned int trans_sprite_len = 0;

    night_sprite_len = get_percentage(window->width, 40);
    trans_sprite_len = get_percentage(window->width, 10);
    sfRenderWindow_drawSprite(window->render, background, NULL);
    for (unsigned int i = 0 ; i < night_sprite_len ; i++) {
        move_timeframe(window, timelapse->night[i]->frame);
        sfRenderWindow_drawSprite(window->render, timelapse->night[i]->frame,
                                    NULL);
    }
    for (unsigned int i = 0 ; i < trans_sprite_len ; i++) {
        move_timeframe(window, timelapse->dusk[i]->frame);
        move_timeframe(window, timelapse->dawn[i]->frame);
        sfRenderWindow_drawSprite(window->render, timelapse->dusk[i]->frame,
                                    NULL);
        sfRenderWindow_drawSprite(window->render, timelapse->dawn[i]->frame,
                                    NULL);
    }
}

void move_timeframe(window_t *window, sprite_t *sprite)
{
    sfIntRect rect;

    rect = sfSprite_getTextureRect(sprite);
    if (rect.left >= (int)window->width) {
        rect.left = 0;
        sfSprite_setPosition(sprite, (sfVector2f) {0.0, 0.0});
    } else {
        rect.left += 1;
        sfSprite_move(sprite, (sfVector2f) {1.0, 0.0});
    }
    sfSprite_setTextureRect(sprite, rect);
}