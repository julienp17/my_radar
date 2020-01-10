/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for drawing to the screen
*/

#ifndef DRAW_H_
    #define DRAW_H_

    #include <SFML/Graphics.h>
    #include "utils.h"
    #include "window.h"
    #include "plane.h"
    #include "tower.h"
    #include "timeframe.h"

    void draw_sim(sim_t *sim);

    void draw_background(window_t *window, sfSprite *background,
                        timelapse_t *timelapse);
    void draw_timer(sfRenderWindow *window, text_t *timer_text, uint c_time);
    void draw_plane(sfRenderWindow *render, plane_t *plane, states_t *states);
    void draw_towers(sfRenderWindow *window, tower_t **, states_t *states);
    void draw_pause_menu(window_t *window);
    void draw_quadtree(sfRenderWindow *window, quadtree_t *quadtree,
                        states_t *states);
    void draw_info(sfRenderWindow *render,texts_t *texts, states_t *states);
#endif