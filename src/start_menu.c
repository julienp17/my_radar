/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Start menu for my_radar
*/

#include <SFML/Graphics.h>
#include "window.h"
#include "start_menu.h"
#include "events.h"
#include "my.h"

int start_menu(void)
{
    start_menu_t *menu = start_menu_create();
    int exit_code = 0;

    if (!menu) {
        my_puterr("Menu couldn't be created");
        return (84);
    }
    draw_start_menu(menu);
    while (sfRenderWindow_isOpen(menu->window->window))
        start_menu_poll_events(menu->window->window, &exit_code);
    start_menu_destroy(menu);
    return (exit_code);
}

void draw_start_menu(start_menu_t *menu)
{
    sfRenderWindow_drawSprite(menu->window->window,
                            menu->window->bg_sprite, NULL);
    sfRenderWindow_drawRectangleShape(menu->window->window,
                                    menu->start->rect, NULL);
    sfRenderWindow_drawRectangleShape(menu->window->window,
                                    menu->quit->rect, NULL);
    sfRenderWindow_drawText(menu->window->window,
                            menu->start->text, NULL);
    sfRenderWindow_drawText(menu->window->window,
                            menu->quit->text, NULL);
    sfRenderWindow_display(menu->window->window);
}