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

    void draw_background(sfRenderWindow *window, sfSprite *background);
    void draw_timer(sfRenderWindow *window, text_t *timer_text, uint c_time);
    void draw_plane(sfRenderWindow *render, plane_t *plane, states_t *states);
    void draw_towers(sfRenderWindow *window, tower_t **, states_t *states);
#endif