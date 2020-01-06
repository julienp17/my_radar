/*
** EPITECH PROJECT, 2020
** MUL_my_radar_2019
** File description:
** start_menu_poll_events
*/

#include <SFML/Graphics.h>
#include "events.h"

void start_menu_poll_events(sfRenderWindow *render, int *exit_code)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(render, &event)) {
        check_window_quit(&event, render);
        if (event.key.code == sfKeyS)
            *exit_code = 1;
    }
}