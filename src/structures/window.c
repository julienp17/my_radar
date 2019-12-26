/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for window structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"

window_t *window_create(unsigned int width, unsigned int height,
                        char const *title)
{
    window_t *window = malloc(sizeof(*window));
    sfVideoMode mode = {width, height, W_BPP};

    window->window = sfRenderWindow_create(mode, title,
                                        sfClose | sfFullscreen, NULL);
    window->area = (sfIntRect) {0, 0, width, height};
    window->center = (sfVector2f) {(float)width / 2.0, (float)height / 2.0};
    window->background_texture = sfTexture_createFromFile(BACKGROUND_PATH,
                                                        &(window->area));
    window->background_sprite = sfSprite_create();
    sfSprite_setTexture(window->background_sprite, window->background_texture,
                        sfTrue);
    sfRenderWindow_setFramerateLimit(window->window, W_MAX_FPS);
    return (window);
}

void window_destroy(window_t *window)
{
    sfRenderWindow_destroy(window->window);
    sfTexture_destroy(window->background_texture);
    sfSprite_destroy(window->background_sprite);
    free(window);
}

void window_poll_quit(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.key.code == sfKeyEscape || event.key.code == sfKeyQ)
            sfRenderWindow_close(window);
    }
}