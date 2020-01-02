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

    void draw_towers(sfRenderWindow *window, tower_t **towers);
    void draw_quadtree(sfRenderWindow *window, quadtree_t *quadtree);
    void draw_pause_menu(window_t *window);
    void draw_timer(sfRenderWindow *window, text_t *timer_text, uint c_time);
#endif