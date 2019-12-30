/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for my_radar core functions
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_

    #include <SFML/Graphics.h>
    #include "sim.h"

    int my_radar(char const *script_path);
    void simulation_loop(sim_t *sim, sfSprite *sprite);
    void plane_loop(plane_t *plane, sim_t *sim, unsigned int c_time);
    void insert_planes_in_quadtree(plane_t **planes, quadtree_t *quadtree,
                                unsigned int c_time);
#endif