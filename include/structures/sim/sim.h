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
    #include "sim_textures.h"

    typedef struct simulation {
        window_t *window;
        quadtree_t *quadtree;
        plane_t **planes;
        tower_t **towers;
        sim_textures_t *textures;
        sfClock *clock;
        sfBool is_paused;
    } sim_t;

    sim_t *sim_create_from_script(char const *filepath);
    void sim_destroy(sim_t *sim);
#endif