/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for window structure
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include <SFML/Graphics.h>

    #define W_WIDTH         2560
    #define W_HEIGHT        1440
    #define W_BPP           32
    #define W_MAX_FPS       30
    #define W_TITLE         "my_radar"
    #define BACKGROUND_PATH "assets/backgrounds/real_world_map_small.png"

    typedef struct window {
        sfRenderWindow *window;
        sfIntRect area;
        sfVector2f center;
        sfTexture *bg_texture;
        sfSprite *bg_sprite;
    } window_t;

    window_t *window_create(unsigned int width, unsigned int height,
                            char const *title, char const *bg_img_path);
    void window_poll_quit(sfRenderWindow *window);
    void window_destroy(window_t *window);
#endif