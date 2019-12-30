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

    void sim_poll_events(sim_t *sim);
    void start_menu_poll_events(sfRenderWindow *window, int *exit_code);
    void check_quit_window(sfEvent *event, sfRenderWindow *window);
    void pause_sim(sim_t *sim);
#endif