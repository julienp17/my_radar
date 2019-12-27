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
    void simulation_loop(sim_t *sim);
#endif