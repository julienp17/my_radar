/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Handle events for my_radar
*/

#include <SFML/Graphics.h>
#include "events.h"
#include "draw.h"
#include "sim.h"
#include <stdio.h>

void sim_poll_events(sim_t *sim)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sim->window->window, &event)) {
        check_window_quit(&event, sim->window->window);
        if (event.key.code == sfKeySpace)
            pause_sim(sim);
    }
}

void check_window_quit(sfEvent *event, sfRenderWindow *window)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->key.code == sfKeyEscape || event->key.code == sfKeyQ)
        sfRenderWindow_close(window);
}