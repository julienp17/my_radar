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

void poll_events(sim_t *sim)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sim->window->window, &event)) {
        poll_quit(&event, sim->window->window);
        if (event.key.code == sfKeySpace)
            pause_sim(sim);
    }
}

void poll_quit(sfEvent *event, sfRenderWindow *window)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->key.code == sfKeyEscape || event->key.code == sfKeyQ)
        sfRenderWindow_close(window);
}

void pause_sim(sim_t *sim)
{
    sfInt32 c_time = sfTime_asMilliseconds(sfClock_getElapsedTime(sim->clock));
    sfInt32 delay = c_time + 500;

    printf("You pressed it !\n");
    if (sim->is_paused) {
        sim->is_paused = sfFalse;
    } else {
        draw_pause_menu(sim->window->window);
        sim->is_paused = sfTrue;
    }
    while (c_time < delay)
        c_time = sfTime_asMilliseconds(sfClock_getElapsedTime(sim->clock));
}