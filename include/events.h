/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for events
*/

#ifndef EVENTS_H_
    #define EVENTS_H_

    #include <SFML/Graphics.h>
    #include "sim.h"

    void start_menu_poll_events(sfRenderWindow *render, int *exit_code);

    void sim_poll_events(sfRenderWindow *render, states_t *state);
    void check_window_quit(sfEvent *event, sfRenderWindow *window);
    void switch_pressed_key(sfEvent *event, states_t *states);
#endif