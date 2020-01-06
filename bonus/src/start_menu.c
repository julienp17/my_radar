/*
** EPITECH PROJECT, 2020
** MUL_my_radar_2019
** File description:
** Start menu of my_radar
*/

#include <SFML/Graphics.h>
#include "window.h"
#include "sim_textures.h"
#include "events.h"
#include "my.h"
#include "usage.h"

int start_menu(window_t *window)
{
    sfTexture *bg_texture = NULL;
    int exit_code = 0;

    bg_texture = sfTexture_createFromFile(S_MENU_BG_TEXTURE_PATH, NULL);
    if (bg_texture == NULL) {
        my_puterr("my_radar: Couldn't create start menu background texture\n");
        return (MY_EXIT_FAILURE);
    }
    window_set_background(window, bg_texture);
    sfRenderWindow_drawSprite(window->render, window->background, NULL);
    sfRenderWindow_display(window->render);
    while (sfRenderWindow_isOpen(window->render) && exit_code == 0)
        start_menu_poll_events(window->render, &exit_code);
    sfTexture_destroy(bg_texture);
    return (exit_code);
}