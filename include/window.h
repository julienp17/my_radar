/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for window structure
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include <SFML/Graphics.h>

    #define W_WIDTH         1366
    #define W_HEIGHT        768
    #define W_BPP           32
    #define W_MAX_FPS       30
    #define W_TITLE         "my_radar"
    #define BACKGROUND_PATH "assets/backgrounds/world_map_smaller.png"

    typedef struct window {
        sfRenderWindow *window;
        sfIntRect area;
        sfVector2f center;
        sfTexture *background_texture;
        sfSprite *background_sprite;
    } window_t;

    window_t *window_create(unsigned int width, unsigned int height,
                            char const *title);
    void window_destroy(window_t *window);
#endif