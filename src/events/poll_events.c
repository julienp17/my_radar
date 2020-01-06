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

void sim_poll_events(sfRenderWindow *render, states_t *state)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(render, &event)) {
        check_window_quit(&event, render);
        if (event.type == sfEvtKeyReleased)
            switch_pressed_key(&event, state);
    }
}

void check_window_quit(sfEvent *event, sfRenderWindow *window)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->key.code == sfKeyEscape || event->key.code == sfKeyQ)
        sfRenderWindow_close(window);
}

void switch_pressed_key(sfEvent *event, states_t *states)
{
    switch (event->key.code) {
    case sfKeyL:
        states->show_hitbox = (states->show_hitbox) ? sfFalse : sfTrue;
        break;
    case sfKeyS:
        states->show_sprites = (states->show_sprites) ? sfFalse : sfTrue;
        break;
    default:
        break;
    }
}