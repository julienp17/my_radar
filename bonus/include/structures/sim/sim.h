/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for simulation structure
*/

#ifndef SIM_H_
    #define SIM_H_

    #include <SFML/Graphics.h>
    #include "window.h"
    #include "quadtree.h"
    #include "plane.h"
    #include "tower.h"
    #include "graphical.h"
    #include "sim_states.h"

    typedef struct simulation {
        graphical_t *gl;
        quadtree_t *quadtree;
        plane_t **planes;
        tower_t **towers;
        states_t *state;
        sfClock *clock;
    } sim_t;

    sim_t *sim_create(window_t *window);
    sim_t *sim_create_from_script(window_t *window, char const *filepath);
    void sim_destroy(sim_t *sim);
#endif