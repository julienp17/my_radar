/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for drawing to the screen
*/

#ifndef DRAW_H_
    #define DRAW_H_

    #include "plane.h"
    #include "tower.h"

    void draw_towers(sfRenderWindow *window, tower_t **towers);
    void draw_planes(sfRenderWindow *window, plane_t **planes, sfClock *clock);
#endif