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
                        char const *title, char const *bg_img_path)
{
    window_t *window = malloc(sizeof(*window));
    sfVideoMode mode = {width, height, W_BPP};

    if (!window)
        return (NULL);
    window->window = sfRenderWindow_create(mode, title, sfClose | sfFullscreen,
                                            NULL);
    window->bg_texture = sfTexture_createFromFile(bg_img_path, NULL);
    window->bg_sprite = sfSprite_create();
    sfSprite_setTexture(window->bg_sprite, window->bg_texture, sfTrue);
    sfRenderWindow_setFramerateLimit(window->window, W_MAX_FPS);
    return (window);
}

void window_destroy(window_t *window)
{
    sfRenderWindow_destroy(window->window);
    sfTexture_destroy(window->bg_texture);
    sfSprite_destroy(window->bg_sprite);
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