/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for menu structure
*/

#include <stdlib.h>
#include "start_menu.h"

static void start_menu_init_buttons(start_menu_t *menu);

start_menu_t *start_menu_create(void)
{
    start_menu_t *menu = malloc(sizeof(start_menu_t));

    if (!menu)
        return (NULL);
    menu->window = window_create(W_WIDTH, W_HEIGHT, W_TITLE, MENU_BG_IMG_PATH);
    start_menu_init_buttons(menu);
    if (!(menu->window) || !(menu->start) || !(menu->quit))
        return (NULL);
    return (menu);
}

static void start_menu_init_buttons(start_menu_t *menu)
{
    sfVector2f start_pos = (sfVector2f) {menu->window->width / 8,
                                        menu->window->height / 8};
    sfVector2f quit_pos = (sfVector2f) {menu->window->width / 8,
                                        menu->window->height / 3};
    sfVector2f button_size = (sfVector2f) {600, 200};

    menu->start = button_create("Press S to start simulation",
                            BUTTON_DEFAULT_FONT_PATH, start_pos, button_size);
    menu->quit = button_create("Press Q to quit", BUTTON_DEFAULT_FONT_PATH,
                                quit_pos, button_size);
}

void start_menu_destroy(start_menu_t *menu)
{
    window_destroy(menu->window);
    button_destroy(menu->start);
    button_destroy(menu->quit);
    if (menu)
        free(menu);
}