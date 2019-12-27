/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Contains functions for the menu
*/

#include <SFML/Graphics.h>
#include "window.h"
#include "my_radar.h"
#include "usage.h"
#include "image.h"

int menu(void)
{
    window_t *window = window_create(W_WIDTH, W_HEIGHT, W_TITLE,
                                    MENU_BG_IMG_PATH);
    int exit_code = 1;

    if (!window)
        return (MY_EXIT_FAILURE);
    while (sfRenderWindow_isOpen(window->window) && exit_code == 0) {
        window_poll_quit(window->window);
        sfRenderWindow_clear(window->window, sfWhite);
        sfRenderWindow_drawSprite(window->window, window->bg_sprite, NULL);
        sfRenderWindow_display(window->window);
    }
    window_destroy(window);
    return (exit_code);
}